#define _GNU_SOURCE
#include "plasm.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>

#include <sys/mman.h>

// this is used to accelerate instruction lookup
int instruction_support[MAX_MNEMONIC] = {INT_MAX};

static void prepare_instructions();

void plasm_init(plasm *as, size_t size) {
    if(instruction_support[0] == INT_MAX) {
        prepare_instructions();
    }
    as->size = size;
    as->position = 0;
    as->buffer = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}

void plasm_protect(plasm *as, int protect) {
    mprotect(as->buffer, as->size, (protect?PROT_EXEC:PROT_WRITE) | PROT_READ);
}

void plasm_free(plasm *as) {
    munmap(as->buffer, as->size);
}

uint8_t* plasm_get_current_ptr(plasm *as) {
    return as->buffer + as->position;
}

size_t plasm_get_pos(plasm *as) {
    return as->position;
}

size_t plasm_get_size(plasm *as) {
    return as->size;
}

int plasm_put_byte(plasm *as, uint8_t value) {
    if(as->position<as->size) {
        as->buffer[as->position++] = value;
        return 1;
    } else {
        return 0;
    }
}

int plasm_put_word(plasm *as, uint16_t value) {
    return plasm_put_byte(as, value&0xFFu) && plasm_put_byte(as, (value>>8u)&0xFFu);
}

int plasm_put_dword(plasm *as, uint32_t value) {
    return  plasm_put_byte(as, value&0xFFu) &&
            plasm_put_byte(as, (value>>8u)&0xFFu) &&
            plasm_put_byte(as, (value>>16u)&0xFFu) &&
            plasm_put_byte(as, (value>>24u)&0xFFu);
}

int plasm_put_qword(plasm *as, uint64_t value) {
    return  plasm_put_byte(as, value&0xFFu) &&
            plasm_put_byte(as, (value>>8u)&0xFFu) &&
            plasm_put_byte(as, (value>>16u)&0xFFu) &&
            plasm_put_byte(as, (value>>24u)&0xFFu) &&
            plasm_put_byte(as, (value>>32u)&0xFFu) &&
            plasm_put_byte(as, (value>>40u)&0xFFu) &&
            plasm_put_byte(as, (value>>48u)&0xFFu) &&
            plasm_put_byte(as, (value>>56u)&0xFFu);
}

opspec_t REGISTER_OP(optype_t type) {
    opspec_t result;
    result.type = type;
    result.position = NULL;
    return result;
}

// require exact register match
#define EXACT_FLAG (0x01ull<<7ull)

#define EXACT_AL  (OP_REG8  | EXACT_FLAG)
#define EXACT_AX  (OP_REG16 | EXACT_FLAG)
#define EXACT_EAX (OP_REG32 | EXACT_FLAG)
#define EXACT_RAX (OP_REG64 | EXACT_FLAG)

#define OP_TYPE(op) (op & 7ull)
#define OP_WIDTH(op) (op & (7ull<<3ull))
#define OP_TYPE_WIDTH(op) (op & 63ull)
#define REGISTER_INDEX(op) (op >> 16ull)
#define IS_EXACT(op) (op & EXACT_FLAG)
#define NO_REX 0xFFu

static opspec_t MEM_IDX_impl(optype_t type, uint8_t scale, optype_t index, optype_t base, int32_t disp) {
    opspec_t result;
    optype_t regidx = REGISTER_INDEX(index);
    optype_t regbase = REGISTER_INDEX(base);
    scale = ((scale&10u)?1u:0u)+((scale&12u)?2u:0u);

    result.type = type;
    result.data.memory.size_override = OP_WIDTH(index)==OP_BIT32?0x67u:0x00;
    result.data.memory.rex = (regidx&8u) >> 2u | (regbase&8u) >> 3u;
    result.data.memory.modrm = 0x04;

    if((disp == (int8_t)disp && disp != 0) || (regidx&7u) == 5u) {
        result.data.memory.disp.disp8 = disp;
        result.data.memory.modrm |= 0x40u;
    } else if(disp != 0) {
        result.data.memory.disp.disp32 = disp;
        result.data.memory.modrm |= 0x80u;
    }

    result.data.memory.sib = scale<<6u | (regidx&7u)<<3u | (regbase&7u);

    result.position = NULL;
    return result;
}

opspec_t MEM_IDX(optype_t type, uint8_t scale, opspec_t index, opspec_t base, int32_t disp) {
    return MEM_IDX_impl(type, scale, index.type, base.type, disp);
}

opspec_t MEM(optype_t type, opspec_t reg, int32_t disp) {
    opspec_t result;
    optype_t regidx = REGISTER_INDEX(reg.type);
    if(regidx == 4u) {
        return MEM_IDX_impl(type, 1, reg.type, reg.type, disp);
    } else if(regidx == 12u) {
        return MEM_IDX_impl(type, 1, reg.type&(~0x80000ull), reg.type, disp);
    } else if(reg.type == 0) {
        result = MEM_IDX_impl(type, 1, OP_REG64 | 0x04ull<<16ull, OP_REG64 | 0x05ull<<16ull, disp);
        result.data.memory.modrm = 4u;
        return result;
    }
    result.type = type;
    result.data.memory.size_override = OP_WIDTH(reg.type)==OP_BIT32?0x67u:0x00;
    result.data.memory.rex = (regidx&8u) >> 3u;
    result.data.memory.modrm = (regidx&7u);
    if((disp == (int8_t)disp && disp != 0) || (regidx&7u) == 5u) {
        result.data.memory.disp.disp8 = disp;
        result.data.memory.modrm |= 0x40u;
    } else if(disp != 0) {
        result.data.memory.disp.disp32 = disp;
        result.data.memory.modrm |= 0x80u;
    }
    result.data.memory.sib = 0u;

    result.position = NULL;
    return result;
}

// displacement only adressing for memory operands
opspec_t DISP(optype_t type, int32_t disp) {
    opspec_t result;
    result.type = type;
    result.data.memory.rex = 0;
    result.data.memory.modrm = 4u;
    result.data.memory.sib = 4u<<3u | 5u;
    result.data.memory.disp.disp32 = disp;
    result.position = NULL;
    return result;
}

// RIP (relative) adressing for memory operands
opspec_t DISP_RIP(optype_t type, int32_t disp) {
    opspec_t result;
    result.type = type;
    result.data.memory.rex = 0;
    result.data.memory.modrm = 5u;
    result.data.memory.sib = 0;
    result.data.memory.disp.disp32 = disp;
    result.position = NULL;
    return result;
}

static opspec_t MOFF(optype_t type, uint64_t offset) {
    opspec_t result;
    result.type = type;
    result.data.moffset = offset;
    result.position = NULL;
    return result;
}

// signed relative offsets for jump instructions
opspec_t REL8(int8_t offset) {
    opspec_t result;
    result.type = OP_REL8OFF;
    result.data.rel8off = offset;
    result.position = NULL;
    return result;
}
opspec_t REL16(int16_t offset) {
    opspec_t result;
    result.type = OP_REL16OFF;
    result.data.rel16off = offset;
    result.position = NULL;
    return result;
}
opspec_t REL32(int32_t offset) {
    opspec_t result;
    result.type = OP_REL32OFF;
    result.data.rel32off = offset;
    result.position = NULL;
    return result;
}

// 64bit memory offset operands only valid for mov instruction
opspec_t MOFF8(uint64_t offset) {
    return MOFF(OP_MOFFSET8, offset);
}
opspec_t MOFF16(uint64_t offset) {
    return MOFF(OP_MOFFSET16, offset);
}
opspec_t MOFF32(uint64_t offset) {
    return MOFF(OP_MOFFSET32, offset);
}
opspec_t MOFF64(uint64_t offset) {
    return MOFF(OP_MOFFSET64, offset);
}

// memory access:
//      displacement
opspec_t DISP8(int32_t disp) {
    return DISP(OP_MEM8, disp);
}
opspec_t DISP16(int32_t disp) {
    return DISP(OP_MEM16, disp);
}
opspec_t DISP32(int32_t disp) {
    return DISP(OP_MEM32, disp);
}
opspec_t DISP64(int32_t disp) {
    return DISP(OP_MEM64, disp);
}
opspec_t DISP128(int32_t disp) {
    return DISP(OP_MEM128, disp);
}

// memory access:
//      displacement
opspec_t DISP_RIP8(int32_t disp) {
    return DISP_RIP(OP_MEM8, disp);
}
opspec_t DISP_RIP16(int32_t disp) {
    return DISP_RIP(OP_MEM16, disp);
}
opspec_t DISP_RIP32(int32_t disp) {
    return DISP_RIP(OP_MEM32, disp);
}
opspec_t DISP_RIP64(int32_t disp) {
    return DISP_RIP(OP_MEM64, disp);
}
opspec_t DISP_RIP128(int32_t disp) {
    return DISP_RIP(OP_MEM128, disp);
}


// memory access:
//      register + displacement
opspec_t MEM8(opspec_t reg, int32_t disp) {
    return MEM(OP_MEM8, reg, disp);
}
opspec_t MEM16(opspec_t reg, int32_t disp) {
    return MEM(OP_MEM16, reg, disp);
}
opspec_t MEM32(opspec_t reg, int32_t disp) {
    return MEM(OP_MEM32, reg, disp);
}
opspec_t MEM64(opspec_t reg, int32_t disp) {
    return MEM(OP_MEM64, reg, disp);
}
opspec_t MEM128(opspec_t reg, int32_t disp) {
    return MEM(OP_MEM128, reg, disp);
}

// index memory access (SIB) valid scaler values are 1,2,4 and 8
// address is calculated as:
//      scaler*index_register + base_register + displacement
opspec_t MEM_IDX8(uint8_t scale, opspec_t index, opspec_t base, int32_t disp) {
    return MEM_IDX(OP_MEM8, scale, index, base, disp);
}
opspec_t MEM_IDX16(uint8_t scale, opspec_t index, opspec_t base, int32_t disp) {
    return MEM_IDX(OP_MEM16, scale, index, base, disp);
}
opspec_t MEM_IDX32(uint8_t scale, opspec_t index, opspec_t base, int32_t disp) {
    return MEM_IDX(OP_MEM32, scale, index, base, disp);
}
opspec_t MEM_IDX64(uint8_t scale, opspec_t index, opspec_t base, int32_t disp) {
    return MEM_IDX(OP_MEM64, scale, index, base, disp);
}
opspec_t MEM_IDX128(uint8_t scale, opspec_t index, opspec_t base, int32_t disp) {
    return MEM_IDX(OP_MEM128, scale, index, base, disp);
}

// immediate operands
opspec_t IMM8(uint8_t value) {
    opspec_t result;
    result.type = OP_IMM8;
    result.data.immediate8 = value;
    result.position = NULL;
    return result;
}
opspec_t IMM16(uint16_t value) {
    opspec_t result;
    result.type = OP_IMM16;
    result.data.immediate16 = value;
    result.position = NULL;
    return result;
}
opspec_t IMM32(uint32_t value) {
    opspec_t result;
    result.type = OP_IMM32;
    result.data.immediate32 = value;
    result.position = NULL;
    return result;
}
opspec_t IMM64(uint64_t value) {
    opspec_t result;
    result.type = OP_IMM64;
    result.data.immediate64 = value;
    result.position = NULL;
    return result;
}

// passing a operand with an immediate value through this allows
// setting the values later on through the pointer pointed to by ptr
opspec_t VALUE_PTR(opspec_t op, void *ptr) {
    op.position = ptr;
    return op;
}

#include "instruction_table.h"

// mod and rm fields of modrm
static uint8_t calc_modrm_modrm(opspec_t op) {
    if(OP_TYPE(op.type) == OP_REG) {
        return 0xC0u | (REGISTER_INDEX(op.type)&7u);
    } else {
        return op.data.memory.modrm;
    }
}

// reg field of modrm
static uint8_t calc_modrm_reg(opspec_t op) {
    return (REGISTER_INDEX(op.type)&7u) << 3u;
}

// rex bits of rm field
static uint8_t calc_modrm_modrm_rex(opspec_t op) {
    if((op.type == 0) || (op.type & OP_IMM)) {
        return 0u;
    }
    if(OP_TYPE(op.type) == OP_REG) {
        return (REGISTER_INDEX(op.type)&8u)>>3u;
    } else {
        return op.data.memory.rex;
    }
}

// rex bits of reg field
static uint8_t calc_modrm_reg_rex(opspec_t op) {
    if((op.type == 0) || (op.type & OP_IMM)) {
        return 0u;
    }
    return (REGISTER_INDEX(op.type)&8u)>>1u;
}

// operand type comparison functions
static int type_width_match(optype_t a, optype_t b) {
    if(OP_WIDTH(a) != OP_WIDTH(b)) {
        return 0;
    }
    if((a & OP_IMM) || (b & OP_IMM)) {
        return a == b;
    } else {
        return OP_TYPE(a & b);
    }
}

static int operand_match(optype_t a, optype_t b) {
    if(!(a && b)) {
        return a == b;
    }
    if(type_width_match(a, b)) {
        if(IS_EXACT(a) || IS_EXACT(b)) {
            return REGISTER_INDEX(a) == REGISTER_INDEX(b);
        }else {
            return 1;
        }
    } else {
        return 0;
    }
}

// simple insertion sort. we are not using qsort since we need stable sorting.
// performance of this is not critical since it is only done once to sort
// about 1k elements that are already almost sorted.
static void sort_instructions(opcode_info *array) {
    for(int i = 1;array[i].mnemonic != UNKNOWN;++i) {
        opcode_info tmp = array[i];
        int j = i-1;
        for(;j>=0 && array[j].mnemonic>tmp.mnemonic;--j) {
            array[j+1] = array[j];
        }
        array[j+1] = tmp;
    }
}

// prepare a support structure for faster instruction lookup
// this sets up the instruction_support array such that
// instruction_support[mnemonic] is the index of the first
// appearence of mnemonic in the instruction table.
static void prepare_instructions() {
    sort_instructions(instructions);
    unsigned int j = 0;
    for(unsigned int i = 0;i<MAX_MNEMONIC;++i) {
        while(
            instructions[j].mnemonic != UNKNOWN &&
            instructions[j].mnemonic < i
        ) {
            ++j;
        }
        instruction_support[i] = j;
    }
}

// find a instruction fitting the mnemonic and operand combination
// return -1 in case no instruction is found.
static int find_instruction(mnemonic_t mnemonic, opspec_t op1, opspec_t op2, opspec_t op3) {
    for(int i = instruction_support[mnemonic];instructions[i].mnemonic == mnemonic;++i) {
        if(
            instructions[i].mnemonic == mnemonic &&
            operand_match(instructions[i].operand1, op1.type) &&
            operand_match(instructions[i].operand2, op2.type) &&
            operand_match(instructions[i].operand3, op3.type)
        ) {
            return i;
        }
    }
    return -1;
}

// write the various types of immediate values
static int plasm_put_immediate(plasm *as, opspec_t op) {
    // remember stream position if requested
    if(op.position!=NULL) {
        *op.position = plasm_get_current_ptr(as);
    }
    if(op.type & OP_IMM) {
        switch(OP_TYPE_WIDTH(op.type)) {
            // MOFFSET operands are always 64bit immediates (only accepted by mov)
            // the number indicates the size of the pointed to operand
            case OP_MOFFSET8:
            case OP_MOFFSET16:
            case OP_MOFFSET32:
            case OP_MOFFSET64: return plasm_put_qword(as, op.data.moffset);

            // for immediate values the number actually indicates the size
            // of the immediate itself
            case OP_IMM8:  return plasm_put_byte(as, op.data.immediate8);
            case OP_IMM16: return plasm_put_word(as, op.data.immediate16);
            case OP_IMM32: return plasm_put_dword(as, op.data.immediate32);
            case OP_IMM64: return plasm_put_qword(as, op.data.immediate64);

            // signed relative offsets are used by jump instructions
            case OP_REL8OFF:  return plasm_put_byte(as, op.data.rel8off);
            case OP_REL16OFF: return plasm_put_word(as, op.data.rel16off);
            case OP_REL32OFF: return plasm_put_dword(as, op.data.rel32off);
            default: return 0;
        }
    } else if((OP_TYPE(op.type) == OP_MEM)) {
        // memory operands can contain a 8 or 32 bit displacement
        // which is also handled through the immediate mechanism
        if(op.data.memory.modrm>>6u == 1u) {
            return plasm_put_byte(as, op.data.memory.disp.disp8);
        } else if(op.data.memory.modrm>>6u == 2u) {
            return plasm_put_dword(as, op.data.memory.disp.disp32);
        } else if(op.data.memory.modrm == 5 ||
            (op.data.memory.modrm == 4 && op.data.memory.sib == (4u<<3u | 5u))) {
            return plasm_put_dword(as, op.data.memory.disp.disp32);
        }
    }
    return 1;
}

// extract and write mandatory prefixes included in the opcode table
static int plasm_put_mandatory_prefixes(plasm *as, optype_t *opcode) {
    for(;;) {
        switch(*opcode&0xFFu) {
            case 0x66u:
            case 0x67u:
            case 0xF3u:
            case 0xF2u: break;
            default: return 1;
        }
        if(!plasm_put_byte(as, *opcode)) return 0;
        *opcode>>=8u;
    }
}

// write sib byte if present
static int plasm_put_sib(plasm *as, opspec_t op) {
    if(OP_TYPE(op.type) == OP_MEM && (op.data.memory.modrm&7u) == 4u) {
        return plasm_put_byte(as, op.data.memory.sib);
    }
    return 1;
}

static int plasm_put_opcode(plasm *as, optype_t opcode, optype_t addition) {
    // escape first level
    if((opcode&0xFFu) == 0x0Fu) {
        if(!plasm_put_byte(as, opcode)) return 0;
        opcode>>=8u;
        // escape second level
        if((opcode&0xFFu) == 0x0Fu || (opcode&0xFFu) == 0x38u || (opcode&0xFFu) == 0x3Au) {
            if(!plasm_put_byte(as, opcode)) return 0;
            opcode>>=8u;
        }
    }
    // actual opcode
    if(!plasm_put_byte(as, opcode+addition)) return 0;
    return 1;
}

int plasm_put_op_fun(plasm *as, mnemonic_t mnemonic, opspec_t op1, opspec_t op2, opspec_t op3, ...) {
    int idx = find_instruction(mnemonic, op1, op2, op3);

    // exit if no fitting instruction is found
    if(idx<0) {
        return 0;
    }

    // if the first two operands are a Register&RM pair make sure RM
    // is in operand 1
    if((OP_TYPE(instructions[idx].operand1) == OP_REG) && (OP_TYPE(instructions[idx].operand2) == OP_RM)) {
        opspec_t tmp = op1; op1 = op2; op2 = tmp;
    }

    // obtain opcode
    optype_t opcode = instructions[idx].opcode;

    // write out any mandatory prefixes included in the opcode
    if(!plasm_put_mandatory_prefixes(as, &opcode)) return 0;

    // 16bit operand size override
    if(OP_WIDTH(op1.type)==OP_BIT16 || OP_WIDTH(op2.type)==OP_BIT16) {
        if(!plasm_put_byte(as, 0x66u)) return 0;
    }

    // address size override prefix (0x67)
    if(OP_TYPE(op1.type)==OP_MEM && op1.data.memory.size_override) {
        if(!plasm_put_byte(as, op1.data.memory.size_override)) return 0;
    }

    // build rex prefix
    uint8_t rex = 0;
    // see if opcode already contains rex prefix
    if((opcode&0xF0u) == 0x40u) {
        rex = opcode&0xFFu;
        opcode >>= 8u;
    }
    // 64bit operand size override
    if(instructions[idx].norex!=NO_REX && (OP_WIDTH(op1.type)==OP_BIT64 || OP_WIDTH(op2.type)==OP_BIT64)) {
        rex |= 0x08u;
    }
    // rex flags from operands
    rex |= calc_modrm_modrm_rex(op1) | calc_modrm_reg_rex(op2);

    // if any of the rex bits have been set, emit the rex prefix
    if(rex) {
        if(!plasm_put_byte(as, 0x40u | rex)) return 0;
    }

    switch(instructions[idx].modrm) {
        // ModRM encoded operand
        case 'r':
            if(!plasm_put_opcode(as, opcode, 0)) return 0;
            if(!plasm_put_byte(as, calc_modrm_modrm(op1) | calc_modrm_reg(op2))) return 0;
            if(!plasm_put_sib(as, op1)) return 0;
            break;
        // ModRM with opcode extension in REG field
        case '0': case '1': case '2': case '3':
        case '4': case '5': case '6': case '7':
            if(!plasm_put_opcode(as, opcode, 0)) return 0;
            if(!plasm_put_byte(as, calc_modrm_modrm(op1) | (instructions[idx].modrm-'0')<<3)) return 0;
            if(!plasm_put_sib(as, op1)) return 0;
            break;
        // additive single byte opcode
        case '+':
            if(!plasm_put_opcode(as, opcode, REGISTER_INDEX(op1.type)&7u)) return 0;
            break;
        // implicit or no register/memory operands
        case ' ':
            if(!plasm_put_opcode(as, opcode, 0)) return 0;
            break;
    }

    //write immediate/moffset/reloff values if present
    if(!plasm_put_immediate(as, op1)) return 0;
    if(!plasm_put_immediate(as, op2)) return 0;
    if(!plasm_put_immediate(as, op3)) return 0;
    return 1;
}

