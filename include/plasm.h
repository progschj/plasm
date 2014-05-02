#ifndef PLASM_H
#define PLASM_H

#include <stdint.h>
#include <stddef.h>

#include "mnemonics.h"

typedef struct plasm_t {
    uint8_t *buffer;
    size_t position, size;
} plasm;

typedef uint64_t optype_t;
typedef struct {
    optype_t type;
    union {
        uint8_t immediate8;
        uint16_t immediate16;
        uint32_t immediate32;
        uint64_t immediate64;
        int8_t rel8off;
        int16_t rel16off;
        int32_t rel32off;
        uint64_t moffset;
        struct {
            uint8_t size_override;
            uint8_t rex;
            uint8_t modrm;
            uint8_t sib;
            union {
                int8_t disp8;
                int32_t disp32;
            } disp;
        } memory;
    } data;
    uint8_t **position;
} opspec_t;

// type 3 bits
#define OP_REG     0x01ull
#define OP_MEM     0x02ull
#define OP_RM      0x03ull
#define OP_IMM     0x04ull
#define OP_MOFFSET 0x05ull
#define OP_RELOFF  0x06ull

// width 3 bits
#define OP_BIT_ANY (0x00ull<<3ull)
#define OP_BIT8    (0x01ull<<3ull)
#define OP_BIT16   (0x02ull<<3ull)
#define OP_BIT32   (0x03ull<<3ull)
#define OP_BIT64   (0x04ull<<3ull)
#define OP_BIT128  (0x05ull<<3ull)
#define OP_BIT256  (0x06ull<<3ull)

// operand type definitions
#define OP_REG8     (OP_REG | OP_BIT8)
#define OP_REG16    (OP_REG | OP_BIT16)
#define OP_REG32    (OP_REG | OP_BIT32)
#define OP_REG64    (OP_REG | OP_BIT64)
#define OP_XMM0     (OP_REG | OP_BIT128)
#define OP_YMM0     (OP_REG | OP_BIT256)

#define OP_MEM_ANY  (OP_MEM | OP_BIT_ANY)
#define OP_MEM8     (OP_MEM | OP_BIT8)
#define OP_MEM16    (OP_MEM | OP_BIT16)
#define OP_MEM32    (OP_MEM | OP_BIT32)
#define OP_MEM64    (OP_MEM | OP_BIT64)
#define OP_MEM128   (OP_MEM | OP_BIT128)
#define OP_MEM256   (OP_MEM | OP_BIT256)

#define OP_RM8      (OP_RM  | OP_BIT8)
#define OP_RM16     (OP_RM  | OP_BIT16)
#define OP_RM32     (OP_RM  | OP_BIT32)
#define OP_RM64     (OP_RM  | OP_BIT64)
#define OP_RM128    (OP_RM  | OP_BIT128)
#define OP_RM256    (OP_RM  | OP_BIT256)

#define OP_IMM8     (OP_IMM | OP_BIT8)
#define OP_IMM16    (OP_IMM | OP_BIT16)
#define OP_IMM32    (OP_IMM | OP_BIT32)
#define OP_IMM64    (OP_IMM | OP_BIT64)

#define OP_MOFFSET8   (OP_MOFFSET | OP_BIT8)
#define OP_MOFFSET16  (OP_MOFFSET | OP_BIT16)
#define OP_MOFFSET32  (OP_MOFFSET | OP_BIT32)
#define OP_MOFFSET64  (OP_MOFFSET | OP_BIT64)

#define OP_REL8OFF   (OP_RELOFF | OP_BIT8)
#define OP_REL16OFF  (OP_RELOFF | OP_BIT16)
#define OP_REL32OFF  (OP_RELOFF | OP_BIT32)
#define OP_REL64OFF  (OP_RELOFF | OP_BIT64)

opspec_t REGISTER_OP(optype_t type);

// register definitions (b = byte, w = word, d = doubleword, q = quadword)
#define Rb(i)  REGISTER_OP(OP_REG8  | (i)<<16ull)
#define Rw(i)  REGISTER_OP(OP_REG16 | (i)<<16ull)
#define Rd(i)  REGISTER_OP(OP_REG32 | (i)<<16ull)
#define Rq(i)  REGISTER_OP(OP_REG64 | (i)<<16ull)
#define XMM(i) REGISTER_OP(OP_XMM0  | (i)<<16ull)
#define YMM(i) REGISTER_OP(OP_YMM0  | (i)<<16ull)

#define RAX REGISTER_OP(OP_REG64 | 0x00ull<<16ull)
#define RCX REGISTER_OP(OP_REG64 | 0x01ull<<16ull)
#define RDX REGISTER_OP(OP_REG64 | 0x02ull<<16ull)
#define RBX REGISTER_OP(OP_REG64 | 0x03ull<<16ull)
#define RSP REGISTER_OP(OP_REG64 | 0x04ull<<16ull)
#define RBP REGISTER_OP(OP_REG64 | 0x05ull<<16ull)
#define RSI REGISTER_OP(OP_REG64 | 0x06ull<<16ull)
#define RDI REGISTER_OP(OP_REG64 | 0x07ull<<16ull)
#define EAX REGISTER_OP(OP_REG32 | 0x00ull<<16ull)
#define ECX REGISTER_OP(OP_REG32 | 0x01ull<<16ull)
#define EDX REGISTER_OP(OP_REG32 | 0x02ull<<16ull)
#define EBX REGISTER_OP(OP_REG32 | 0x03ull<<16ull)
#define ESP REGISTER_OP(OP_REG32 | 0x04ull<<16ull)
#define EBP REGISTER_OP(OP_REG32 | 0x05ull<<16ull)
#define ESI REGISTER_OP(OP_REG32 | 0x06ull<<16ull)
#define EDI REGISTER_OP(OP_REG32 | 0x07ull<<16ull)
#define AX  REGISTER_OP(OP_REG16 | 0x00ull<<16ull)
#define CX  REGISTER_OP(OP_REG16 | 0x01ull<<16ull)
#define DX  REGISTER_OP(OP_REG16 | 0x02ull<<16ull)
#define BX  REGISTER_OP(OP_REG16 | 0x03ull<<16ull)
#define SP  REGISTER_OP(OP_REG16 | 0x04ull<<16ull)
#define BP  REGISTER_OP(OP_REG16 | 0x05ull<<16ull)
#define SI  REGISTER_OP(OP_REG16 | 0x06ull<<16ull)
#define DI  REGISTER_OP(OP_REG16 | 0x07ull<<16ull)
#define AL  REGISTER_OP(OP_REG8  | 0x00ull<<16ull)
#define CL  REGISTER_OP(OP_REG8  | 0x01ull<<16ull)
#define DL  REGISTER_OP(OP_REG8  | 0x02ull<<16ull)
#define BL  REGISTER_OP(OP_REG8  | 0x03ull<<16ull)
#define AH  REGISTER_OP(OP_REG8  | 0x04ull<<16ull)
#define CH  REGISTER_OP(OP_REG8  | 0x05ull<<16ull)
#define DH  REGISTER_OP(OP_REG8  | 0x06ull<<16ull)
#define BH  REGISTER_OP(OP_REG8  | 0x07ull<<16ull)

#define LOCK 0xF0u
#define BRANCH_NOT_TAKEN 0x2Eu
#define BRANCH_TAKEN 0x3Eu

// generic memory operands
opspec_t MEM_IDX(uint8_t scale, opspec_t index, opspec_t base, int32_t disp);
opspec_t MEM(opspec_t reg, int32_t disp);
opspec_t DISP(int32_t disp);
opspec_t DISP_RIP(int32_t disp);

// immediate operands
opspec_t IMM8(uint8_t value);
opspec_t IMM16(uint16_t value);
opspec_t IMM32(uint32_t value);
opspec_t IMM64(uint64_t value);

// relative offsets (for jump instructions)
opspec_t REL8(int8_t offset);
opspec_t REL16(int16_t offset);
opspec_t REL32(int32_t offset);

// 64bit memory offsets (valid for MOV instruction only)
opspec_t MOFF8(uint64_t offset);
opspec_t MOFF16(uint64_t offset);
opspec_t MOFF32(uint64_t offset);
opspec_t MOFF64(uint64_t offset);

// stores a pointer to a immediate value in the pointer pointed to by ptr
opspec_t VALUE_PTR(opspec_t op, void *ptr);

// init an instruction buffer. If buffer is NULL a buffer of
// size is allocated via mmap otherwise the provided buffer is used
// (in which case using plasm_protect and plasm_free is most likely
// unsafe)
void plasm_init(plasm *as, uint8_t *buffer, size_t size);

// protect = 0 buffer is writable but not executable
// protect = 1 buffer is executable but not writable
void plasm_protect(plasm *as, int protect);

// free the instruction buffer
void plasm_free(plasm *as);

// query position and size
size_t plasm_get_pos(plasm *as);
size_t plasm_get_size(plasm *as);

// get a pointer to the current insert position (pointer to the next
// inserted object)
uint8_t* plasm_get_current_ptr(plasm *as);

// insert raw data
int plasm_put_byte(plasm *as, uint8_t value);
int plasm_put_word(plasm *as, uint16_t value);
int plasm_put_dword(plasm *as, uint32_t value);
int plasm_put_qword(plasm *as, uint64_t value);

// encode and insert instruction
int plasm_put_op_fun(plasm *as, mnemonic_t mnemonic, opspec_t op1, opspec_t op2, opspec_t op3, opspec_t op4, ...);

// syntactic sugar
#define plasm_put_op(...) plasm_put_op_fun(__VA_ARGS__,REGISTER_OP(0),REGISTER_OP(0),REGISTER_OP(0),REGISTER_OP(0))

#endif
