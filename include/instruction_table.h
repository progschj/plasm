typedef struct opcode_info_t {
    mnemonic_t mnemonic;
    optype_t operand1;
    optype_t operand2;
    optype_t operand3;
    optype_t operand4;
    optype_t opcode;
    unsigned char modrm;
} opcode_info;

opcode_info instructions[] = {
    {ADC, EXACT_AL,  OP_IMM8,  0, 0, 0x14, ' '},
    {ADC, EXACT_AX,  OP_IMM16, 0, 0, 0x1566, ' '},
    {ADC, EXACT_EAX, OP_IMM32, 0, 0, 0x15, ' '},
    {ADC, EXACT_RAX, OP_IMM32, 0, 0, 0x1548, ' '},

    {ADC, OP_RM8,  OP_IMM8,  0, 0, 0x80, '2'},
    {ADC, OP_RM16, OP_IMM16, 0, 0, 0x8166, '2'},
    {ADC, OP_RM32, OP_IMM32, 0, 0, 0x81, '2'},
    {ADC, OP_RM64, OP_IMM32, 0, 0, 0x8148, '2'},

    {ADC, OP_RM16, OP_IMM8,  0, 0, 0x8366, '2'},
    {ADC, OP_RM32, OP_IMM8,  0, 0, 0x83, '2'},
    {ADC, OP_RM64, OP_IMM8,  0, 0, 0x8348, '2'},

    {ADC, OP_REG8,  OP_RM8,  0, 0, 0x12, 'r'},
    {ADC, OP_REG16, OP_RM16, 0, 0, 0x1366, 'r'},
    {ADC, OP_REG32, OP_RM32, 0, 0, 0x13, 'r'},
    {ADC, OP_REG64, OP_RM64, 0, 0, 0x1348, 'r'},

    {ADC, OP_RM8,  OP_REG8,  0, 0, 0x10, 'r'},
    {ADC, OP_RM16, OP_REG16, 0, 0, 0x1166, 'r'},
    {ADC, OP_RM32, OP_REG32, 0, 0, 0x11, 'r'},
    {ADC, OP_RM64, OP_REG64, 0, 0, 0x1148, 'r'},

    {ADD, EXACT_AL,  OP_IMM8,  0, 0, 0x04, ' '},
    {ADD, EXACT_AX,  OP_IMM16, 0, 0, 0x0566, ' '},
    {ADD, EXACT_EAX, OP_IMM32, 0, 0, 0x05, ' '},
    {ADD, EXACT_RAX, OP_IMM32, 0, 0, 0x0548, ' '},

    {ADD, OP_RM8,  OP_IMM8,  0, 0, 0x80, '0'},
    {ADD, OP_RM16, OP_IMM16, 0, 0, 0x8166, '0'},
    {ADD, OP_RM32, OP_IMM32, 0, 0, 0x81, '0'},
    {ADD, OP_RM64, OP_IMM32, 0, 0, 0x8148, '0'},

    {ADD, OP_RM16, OP_IMM8,  0, 0, 0x8366, '0'},
    {ADD, OP_RM32, OP_IMM8,  0, 0, 0x83, '0'},
    {ADD, OP_RM64, OP_IMM8,  0, 0, 0x8348, '0'},

    {ADD, OP_REG8,  OP_RM8,  0, 0, 0x02, 'r'},
    {ADD, OP_REG16, OP_RM16, 0, 0, 0x0366, 'r'},
    {ADD, OP_REG32, OP_RM32, 0, 0, 0x03, 'r'},
    {ADD, OP_REG64, OP_RM64, 0, 0, 0x0348, 'r'},

    {ADD, OP_RM8,  OP_REG8,  0, 0, 0x00, 'r'},
    {ADD, OP_RM16, OP_REG16, 0, 0, 0x0166, 'r'},
    {ADD, OP_RM32, OP_REG32, 0, 0, 0x01, 'r'},
    {ADD, OP_RM64, OP_REG64, 0, 0, 0x0148, 'r'},

    {AND, EXACT_AL,  OP_IMM8,  0, 0, 0x24, ' '},
    {AND, EXACT_AX,  OP_IMM16, 0, 0, 0x2566, ' '},
    {AND, EXACT_EAX, OP_IMM32, 0, 0, 0x25, ' '},
    {AND, EXACT_RAX, OP_IMM32, 0, 0, 0x2548, ' '},

    {AND, OP_RM8,  OP_IMM8,  0, 0, 0x80, '4'},
    {AND, OP_RM16, OP_IMM16, 0, 0, 0x8166, '4'},
    {AND, OP_RM32, OP_IMM32, 0, 0, 0x81, '4'},
    {AND, OP_RM64, OP_IMM32, 0, 0, 0x8148, '4'},

    {AND, OP_RM16, OP_IMM8,  0, 0, 0x8366, '4'},
    {AND, OP_RM32, OP_IMM8,  0, 0, 0x83, '4'},
    {AND, OP_RM64, OP_IMM8,  0, 0, 0x8348, '4'},

    {AND, OP_REG8,  OP_RM8,  0, 0, 0x22, 'r'},
    {AND, OP_REG16, OP_RM16, 0, 0, 0x2366, 'r'},
    {AND, OP_REG32, OP_RM32, 0, 0, 0x23, 'r'},
    {AND, OP_REG64, OP_RM64, 0, 0, 0x2348, 'r'},

    {AND, OP_RM8,  OP_REG8,  0, 0, 0x20, 'r'},
    {AND, OP_RM16, OP_REG16, 0, 0, 0x2166, 'r'},
    {AND, OP_RM32, OP_REG32, 0, 0, 0x21, 'r'},
    {AND, OP_RM64, OP_REG64, 0, 0, 0x2148, 'r'},

    {BSF, OP_REG16, OP_RM16, 0, 0, 0xBC0F66, 'r'},
    {BSF, OP_REG32, OP_RM32, 0, 0, 0xBC0F, 'r'},
    {BSF, OP_REG64, OP_RM64, 0, 0, 0xBC0F48, 'r'},

    {BSR, OP_REG16, OP_RM16, 0, 0, 0xBD0F66, 'r'},
    {BSR, OP_REG32, OP_RM32, 0, 0, 0xBD0F, 'r'},
    {BSR, OP_REG64, OP_RM64, 0, 0, 0xBD0F48, 'r'},

    {BSWAP, OP_REG32, 0, 0, 0, 0xC80F, '+'},
    {BSWAP, OP_REG64, 0, 0, 0, 0xC80F48, '+'},

    {BT, OP_RM16, OP_REG16, 0, 0, 0xA30F66, 'r'},
    {BT, OP_RM32, OP_REG32, 0, 0, 0xA30F, 'r'},
    {BT, OP_RM64, OP_REG64, 0, 0, 0xA30F48, 'r'},

    {BT, OP_RM16, OP_IMM8,  0, 0, 0xBA0F66, '4'},
    {BT, OP_RM32, OP_IMM8,  0, 0, 0xBA0F, '4'},
    {BT, OP_RM64, OP_IMM8,  0, 0, 0xBA0F48, '4'},

    {BTC, OP_RM16, OP_REG16, 0, 0, 0xBB0F66, 'r'},
    {BTC, OP_RM32, OP_REG32, 0, 0, 0xBB0F, 'r'},
    {BTC, OP_RM64, OP_REG64, 0, 0, 0xBB0F64, 'r'},

    {BTC, OP_RM16, OP_IMM8,  0, 0, 0xBA0F66, '7'},
    {BTC, OP_RM32, OP_IMM8,  0, 0, 0xBA0F, '7'},
    {BTC, OP_RM64, OP_IMM8,  0, 0, 0xBA0F48, '7'},

    {BTR, OP_RM16, OP_REG16, 0, 0, 0xB30F66, 'r'},
    {BTR, OP_RM32, OP_REG32, 0, 0, 0xB30F, 'r'},
    {BTR, OP_RM64, OP_REG64, 0, 0, 0xB30F48, 'r'},

    {BTR, OP_RM16, OP_IMM8,  0, 0, 0xBA0F66, '6'},
    {BTR, OP_RM32, OP_IMM8,  0, 0, 0xBA0F, '6'},
    {BTR, OP_RM64, OP_IMM8,  0, 0, 0xBA0F48, '6'},

    {BTS, OP_RM16, OP_REG16, 0, 0, 0xAB0F66, 'r'},
    {BTS, OP_RM32, OP_REG32, 0, 0, 0xAB0F, 'r'},
    {BTS, OP_RM64, OP_REG64, 0, 0, 0xAB0F48, 'r'},

    {BTS, OP_RM16, OP_IMM8,  0, 0, 0xBA0F66, '5'},
    {BTS, OP_RM32, OP_IMM8,  0, 0, 0xBA0F, '5'},
    {BTS, OP_RM64, OP_IMM8,  0, 0, 0xBA0F48, '5'},

    {CALL, OP_REL32OFF, 0,  0, 0, 0xE8, ' '},
    {CALL, OP_RM64,  0,  0, 0, 0xFF, '2'},

    {CBW,  0,  0,  0, 0, 0x9866, ' '},
    {CWDE, 0,  0,  0, 0, 0x98,   ' '},
    {CDQE, 0,  0,  0, 0, 0x9848, ' '},

    {CWD, 0,  0,  0, 0, 0x9966, ' '},
    {CDQ, 0,  0,  0, 0, 0x99,   ' '},
    {CQO, 0,  0,  0, 0, 0x9948, ' '},

    {CLC, 0,  0,  0, 0, 0xF8, ' '},
    {CLD, 0,  0,  0, 0, 0xFC, ' '},

    {CLFLUSH, OP_MEM8,  0,  0, 0, 0xAE0F, '7'},

    {CMC, 0,  0,  0, 0, 0xF5, ' '},

    {CMOVO,   OP_REG16, OP_RM16, 0, 0, 0x400F66, 'r'},
    {CMOVO,   OP_REG32, OP_RM32, 0, 0, 0x400F, 'r'},
    {CMOVO,   OP_REG64, OP_RM64, 0, 0, 0x400F48, 'r'},

    {CMOVNO,  OP_REG16, OP_RM16, 0, 0, 0x410F66, 'r'},
    {CMOVNO,  OP_REG32, OP_RM32, 0, 0, 0x410F, 'r'},
    {CMOVNO,  OP_REG64, OP_RM64, 0, 0, 0x410F48, 'r'},

    {CMOVB,   OP_REG16, OP_RM16, 0, 0, 0x420F66, 'r'},
    {CMOVB,   OP_REG32, OP_RM32, 0, 0, 0x420F, 'r'},
    {CMOVB,   OP_REG64, OP_RM64, 0, 0, 0x420F48, 'r'},

    {CMOVC,   OP_REG16, OP_RM16, 0, 0, 0x420F66, 'r'},
    {CMOVC,   OP_REG32, OP_RM32, 0, 0, 0x420F, 'r'},
    {CMOVC,   OP_REG64, OP_RM64, 0, 0, 0x420F48, 'r'},

    {CMOVNAE, OP_REG16, OP_RM16, 0, 0, 0x420F66, 'r'},
    {CMOVNAE, OP_REG32, OP_RM32, 0, 0, 0x420F, 'r'},
    {CMOVNAE, OP_REG64, OP_RM64, 0, 0, 0x420F48, 'r'},

    {CMOVNB,  OP_REG16, OP_RM16, 0, 0, 0x430F66, 'r'},
    {CMOVNB,  OP_REG32, OP_RM32, 0, 0, 0x430F, 'r'},
    {CMOVNB,  OP_REG64, OP_RM64, 0, 0, 0x430F48, 'r'},

    {CMOVNC,  OP_REG16, OP_RM16, 0, 0, 0x430F66, 'r'},
    {CMOVNC,  OP_REG32, OP_RM32, 0, 0, 0x430F, 'r'},
    {CMOVNC,  OP_REG64, OP_RM64, 0, 0, 0x430F48, 'r'},

    {CMOVAE,  OP_REG16, OP_RM16, 0, 0, 0x430F66, 'r'},
    {CMOVAE,  OP_REG32, OP_RM32, 0, 0, 0x430F, 'r'},
    {CMOVAE,  OP_REG64, OP_RM64, 0, 0, 0x430F48, 'r'},

    {CMOVZ,   OP_REG16, OP_RM16, 0, 0, 0x440F66, 'r'},
    {CMOVZ,   OP_REG32, OP_RM32, 0, 0, 0x440F, 'r'},
    {CMOVZ,   OP_REG64, OP_RM64, 0, 0, 0x440F48, 'r'},

    {CMOVE,   OP_REG16, OP_RM16, 0, 0, 0x440F66, 'r'},
    {CMOVE,   OP_REG32, OP_RM32, 0, 0, 0x440F, 'r'},
    {CMOVE,   OP_REG64, OP_RM64, 0, 0, 0x440F48, 'r'},

    {CMOVNZ,  OP_REG16, OP_RM16, 0, 0, 0x450F66, 'r'},
    {CMOVNZ,  OP_REG32, OP_RM32, 0, 0, 0x450F, 'r'},
    {CMOVNZ,  OP_REG64, OP_RM64, 0, 0, 0x450F48, 'r'},

    {CMOVNE,  OP_REG16, OP_RM16, 0, 0, 0x450F66, 'r'},
    {CMOVNE,  OP_REG32, OP_RM32, 0, 0, 0x450F, 'r'},
    {CMOVNE,  OP_REG64, OP_RM64, 0, 0, 0x450F48, 'r'},

    {CMOVBE,  OP_REG16, OP_RM16, 0, 0, 0x460F66, 'r'},
    {CMOVBE,  OP_REG32, OP_RM32, 0, 0, 0x460F, 'r'},
    {CMOVBE,  OP_REG64, OP_RM64, 0, 0, 0x460F48, 'r'},

    {CMOVNA,  OP_REG16, OP_RM16, 0, 0, 0x460F66, 'r'},
    {CMOVNA,  OP_REG32, OP_RM32, 0, 0, 0x460F, 'r'},
    {CMOVNA,  OP_REG64, OP_RM64, 0, 0, 0x460F48, 'r'},

    {CMOVNBE, OP_REG16, OP_RM16, 0, 0, 0x470F66, 'r'},
    {CMOVNBE, OP_REG32, OP_RM32, 0, 0, 0x470F, 'r'},
    {CMOVNBE, OP_REG64, OP_RM64, 0, 0, 0x470F48, 'r'},

    {CMOVA,   OP_REG16, OP_RM16, 0, 0, 0x470F66, 'r'},
    {CMOVA,   OP_REG32, OP_RM32, 0, 0, 0x470F, 'r'},
    {CMOVA,   OP_REG64, OP_RM64, 0, 0, 0x470F48, 'r'},

    {CMOVS,   OP_REG16, OP_RM16, 0, 0, 0x480F66, 'r'},
    {CMOVS,   OP_REG32, OP_RM32, 0, 0, 0x480F, 'r'},
    {CMOVS,   OP_REG64, OP_RM64, 0, 0, 0x480F48, 'r'},

    {CMOVNS,  OP_REG16, OP_RM16, 0, 0, 0x490F66, 'r'},
    {CMOVNS,  OP_REG32, OP_RM32, 0, 0, 0x490F, 'r'},
    {CMOVNS,  OP_REG64, OP_RM64, 0, 0, 0x490F48, 'r'},

    {CMOVP,   OP_REG16, OP_RM16, 0, 0, 0x4A0F66, 'r'},
    {CMOVP,   OP_REG32, OP_RM32, 0, 0, 0x4A0F, 'r'},
    {CMOVP,   OP_REG64, OP_RM64, 0, 0, 0x4A0F48, 'r'},

    {CMOVPE,  OP_REG16, OP_RM16, 0, 0, 0x4A0F66, 'r'},
    {CMOVPE,  OP_REG32, OP_RM32, 0, 0, 0x4A0F, 'r'},
    {CMOVPE,  OP_REG64, OP_RM64, 0, 0, 0x4A0F48, 'r'},

    {CMOVNP,  OP_REG16, OP_RM16, 0, 0, 0x4B0F66, 'r'},
    {CMOVNP,  OP_REG32, OP_RM32, 0, 0, 0x4B0F, 'r'},
    {CMOVNP,  OP_REG64, OP_RM64, 0, 0, 0x4B0F48, 'r'},

    {CMOVPO,  OP_REG16, OP_RM16, 0, 0, 0x4B0F66, 'r'},
    {CMOVPO,  OP_REG32, OP_RM32, 0, 0, 0x4B0F, 'r'},
    {CMOVPO,  OP_REG64, OP_RM64, 0, 0, 0x4B0F48, 'r'},

    {CMOVL,   OP_REG16, OP_RM16, 0, 0, 0x4C0F66, 'r'},
    {CMOVL,   OP_REG32, OP_RM32, 0, 0, 0x4C0F, 'r'},
    {CMOVL,   OP_REG64, OP_RM64, 0, 0, 0x4C0F48, 'r'},

    {CMOVNGE, OP_REG16, OP_RM16, 0, 0, 0x4C0F66, 'r'},
    {CMOVNGE, OP_REG32, OP_RM32, 0, 0, 0x4C0F, 'r'},
    {CMOVNGE, OP_REG64, OP_RM64, 0, 0, 0x4C0F48, 'r'},

    {CMOVNL,  OP_REG16, OP_RM16, 0, 0, 0x4D0F66, 'r'},
    {CMOVNL,  OP_REG32, OP_RM32, 0, 0, 0x4D0F, 'r'},
    {CMOVNL,  OP_REG64, OP_RM64, 0, 0, 0x4D0F48, 'r'},

    {CMOVGE,  OP_REG16, OP_RM16, 0, 0, 0x4D0F66, 'r'},
    {CMOVGE,  OP_REG32, OP_RM32, 0, 0, 0x4D0F, 'r'},
    {CMOVGE,  OP_REG64, OP_RM64, 0, 0, 0x4D0F48, 'r'},

    {CMOVLE,  OP_REG16, OP_RM16, 0, 0, 0x4E0F66, 'r'},
    {CMOVLE,  OP_REG32, OP_RM32, 0, 0, 0x4E0F, 'r'},
    {CMOVLE,  OP_REG64, OP_RM64, 0, 0, 0x4E0F48, 'r'},

    {CMOVNG,  OP_REG16, OP_RM16, 0, 0, 0x4E0F66, 'r'},
    {CMOVNG,  OP_REG32, OP_RM32, 0, 0, 0x4E0F, 'r'},
    {CMOVNG,  OP_REG64, OP_RM64, 0, 0, 0x4E0F48, 'r'},

    {CMOVNLE, OP_REG16, OP_RM16, 0, 0, 0x4F0F66, 'r'},
    {CMOVNLE, OP_REG32, OP_RM32, 0, 0, 0x4F0F, 'r'},
    {CMOVNLE, OP_REG64, OP_RM64, 0, 0, 0x4F0F48, 'r'},

    {CMOVG,   OP_REG16, OP_RM16, 0, 0, 0x4F0F66, 'r'},
    {CMOVG,   OP_REG32, OP_RM32, 0, 0, 0x4F0F, 'r'},
    {CMOVG,   OP_REG64, OP_RM64, 0, 0, 0x4F0F48, 'r'},

    {CMP, EXACT_AL,  OP_IMM8,  0, 0, 0x3C, ' '},
    {CMP, EXACT_AX,  OP_IMM16, 0, 0, 0x3D66, ' '},
    {CMP, EXACT_EAX, OP_IMM32, 0, 0, 0x3D, ' '},
    {CMP, EXACT_RAX, OP_IMM32, 0, 0, 0x3D48, ' '},

    {CMP, OP_RM8,  OP_IMM8,  0, 0, 0x80, '7'},
    {CMP, OP_RM16, OP_IMM16, 0, 0, 0x8166, '7'},
    {CMP, OP_RM32, OP_IMM32, 0, 0, 0x81, '7'},
    {CMP, OP_RM64, OP_IMM32, 0, 0, 0x8148, '7'},

    {CMP, OP_RM16, OP_IMM8,  0, 0, 0x8366, '7'},
    {CMP, OP_RM32, OP_IMM8,  0, 0, 0x83, '7'},
    {CMP, OP_RM64, OP_IMM8,  0, 0, 0x8348, '7'},

    {CMP, OP_REG8,  OP_RM8,  0, 0, 0x3A, 'r'},
    {CMP, OP_REG16, OP_RM16, 0, 0, 0x3B66, 'r'},
    {CMP, OP_REG32, OP_RM32, 0, 0, 0x3B, 'r'},
    {CMP, OP_REG64, OP_RM64, 0, 0, 0x3B48, 'r'},

    {CMP, OP_RM8,  OP_REG8,  0, 0, 0x38, 'r'},
    {CMP, OP_RM16, OP_REG16, 0, 0, 0x3966, 'r'},
    {CMP, OP_RM32, OP_REG32, 0, 0, 0x39, 'r'},
    {CMP, OP_RM64, OP_REG64, 0, 0, 0x3948, 'r'},

    {CMPSB, 0, 0, 0, 0, 0xA6,   ' '},
    {CMPSW, 0, 0, 0, 0, 0xA766, ' '},
    {CMPSD, 0, 0, 0, 0, 0xA7,   ' '},
    {CMPSQ, 0, 0, 0, 0, 0xA748, ' '},

    {CMPXCHG, OP_RM8,  OP_REG8,  0, 0, 0xB00F, 'r'},
    {CMPXCHG, OP_RM16, OP_REG16, 0, 0, 0xB10F66, 'r'},
    {CMPXCHG, OP_RM32, OP_REG32, 0, 0, 0xB10F, 'r'},
    {CMPXCHG, OP_RM64, OP_REG64, 0, 0, 0xB10F48, 'r'},

    {CMPXCHG8B, OP_MEM64, 0, 0, 0, 0xC70F, '1'},
    {CMPXCHG16B, OP_MEM128, 0, 0, 0, 0xC70F48, '1'},

    {CPUID, 0, 0, 0, 0, 0xA20F, ' '},

    {DEC, OP_RM8,  0, 0, 0, 0xFE, '1'},
    {DEC, OP_RM16, 0, 0, 0, 0xFF66, '1'},
    {DEC, OP_RM32, 0, 0, 0, 0xFF, '1'},
    {DEC, OP_RM64, 0, 0, 0, 0xFF48, '1'},

    {DIV, OP_RM8,  0, 0, 0, 0xF6, '6'},
    {DIV, OP_RM16, 0, 0, 0, 0xF766, '6'},
    {DIV, OP_RM32, 0, 0, 0, 0xF7, '6'},
    {DIV, OP_RM64, 0, 0, 0, 0xF748, '6'},

    {ENTER, OP_IMM16, OP_IMM8, 0, 0, 0xC8, ' '},

    {IDIV, OP_RM8,  0, 0, 0, 0xF6, '7'},
    {IDIV, OP_RM16, 0, 0, 0, 0xF766, '7'},
    {IDIV, OP_RM32, 0, 0, 0, 0xF7, '7'},
    {IDIV, OP_RM64, 0, 0, 0, 0xF748, '7'},

    {IMUL, OP_RM8, 0, 0, 0, 0xF6, '5'},
    {IMUL, OP_RM16, 0, 0, 0, 0xF766, '5'},
    {IMUL, OP_RM32, 0, 0, 0, 0xF7, '5'},
    {IMUL, OP_RM64, 0, 0, 0, 0xF748, '5'},
    {IMUL, OP_REG16, OP_RM16, 0, 0, 0xAF0F66, 'r'},
    {IMUL, OP_REG32, OP_RM32, 0, 0, 0xAF0F, 'r'},
    {IMUL, OP_REG64, OP_RM64, 0, 0, 0xAF0F48, 'r'},
    {IMUL, OP_REG16, OP_RM16, OP_IMM8, 0, 0x6B66, 'r'},
    {IMUL, OP_REG32, OP_RM32, OP_IMM8, 0, 0x6B, 'r'},
    {IMUL, OP_REG64, OP_RM64, OP_IMM8, 0, 0x6B48, 'r'},
    {IMUL, OP_REG16, OP_RM16, OP_IMM16, 0, 0x6966, 'r'},
    {IMUL, OP_REG32, OP_RM32, OP_IMM32, 0, 0x69, 'r'},
    {IMUL, OP_REG64, OP_RM64, OP_IMM32, 0, 0x6948, 'r'},

    {INC, OP_RM8,  0, 0, 0, 0xFE, '0'},
    {INC, OP_RM16, 0, 0, 0, 0xFF66, '0'},
    {INC, OP_RM32, 0, 0, 0, 0xFF, '0'},
    {INC, OP_RM64, 0, 0, 0, 0xFF48, '0'},

    {INT, OP_IMM8, 0, 0, 0, 0xCD, ' '},

    {INTO, 0, 0, 0, 0, 0xCE, ' '},

    {JO,   OP_REL32OFF, 0, 0, 0, 0x800F, ' '},
    {JNO,  OP_REL32OFF, 0, 0, 0, 0x810F, ' '},
    {JB,   OP_REL32OFF, 0, 0, 0, 0x820F, ' '},
    {JC,   OP_REL32OFF, 0, 0, 0, 0x820F, ' '},
    {JNAE, OP_REL32OFF, 0, 0, 0, 0x820F, ' '},
    {JNB,  OP_REL32OFF, 0, 0, 0, 0x830F, ' '},
    {JNC,  OP_REL32OFF, 0, 0, 0, 0x830F, ' '},
    {JAE,  OP_REL32OFF, 0, 0, 0, 0x830F, ' '},
    {JZ,   OP_REL32OFF, 0, 0, 0, 0x840F, ' '},
    {JE,   OP_REL32OFF, 0, 0, 0, 0x840F, ' '},
    {JNZ,  OP_REL32OFF, 0, 0, 0, 0x850F, ' '},
    {JNE,  OP_REL32OFF, 0, 0, 0, 0x850F, ' '},
    {JBE,  OP_REL32OFF, 0, 0, 0, 0x860F, ' '},
    {JNA,  OP_REL32OFF, 0, 0, 0, 0x860F, ' '},
    {JNBE, OP_REL32OFF, 0, 0, 0, 0x870F, ' '},
    {JA,   OP_REL32OFF, 0, 0, 0, 0x870F, ' '},
    {JS,   OP_REL32OFF, 0, 0, 0, 0x880F, ' '},
    {JNS,  OP_REL32OFF, 0, 0, 0, 0x890F, ' '},
    {JP,   OP_REL32OFF, 0, 0, 0, 0x8A0F, ' '},
    {JPE,  OP_REL32OFF, 0, 0, 0, 0x8A0F, ' '},
    {JNP,  OP_REL32OFF, 0, 0, 0, 0x8B0F, ' '},
    {JPO,  OP_REL32OFF, 0, 0, 0, 0x8B0F, ' '},
    {JL,   OP_REL32OFF, 0, 0, 0, 0x8C0F, ' '},
    {JNGE, OP_REL32OFF, 0, 0, 0, 0x8C0F, ' '},
    {JNL,  OP_REL32OFF, 0, 0, 0, 0x8D0F, ' '},
    {JGE,  OP_REL32OFF, 0, 0, 0, 0x8D0F, ' '},
    {JLE,  OP_REL32OFF, 0, 0, 0, 0x8E0F, ' '},
    {JNG,  OP_REL32OFF, 0, 0, 0, 0x8E0F, ' '},
    {JNLE, OP_REL32OFF, 0, 0, 0, 0x8F0F, ' '},
    {JG,   OP_REL32OFF, 0, 0, 0, 0x8F0F, ' '},

    {JO,   OP_REL8OFF, 0, 0, 0, 0x70, ' '},
    {JNO,  OP_REL8OFF, 0, 0, 0, 0x71, ' '},
    {JB,   OP_REL8OFF, 0, 0, 0, 0x72, ' '},
    {JC,   OP_REL8OFF, 0, 0, 0, 0x72, ' '},
    {JNAE, OP_REL8OFF, 0, 0, 0, 0x72, ' '},
    {JNB,  OP_REL8OFF, 0, 0, 0, 0x73, ' '},
    {JNC,  OP_REL8OFF, 0, 0, 0, 0x73, ' '},
    {JAE,  OP_REL8OFF, 0, 0, 0, 0x73, ' '},
    {JZ,   OP_REL8OFF, 0, 0, 0, 0x74, ' '},
    {JE,   OP_REL8OFF, 0, 0, 0, 0x74, ' '},
    {JNZ,  OP_REL8OFF, 0, 0, 0, 0x75, ' '},
    {JNE,  OP_REL8OFF, 0, 0, 0, 0x75, ' '},
    {JBE,  OP_REL8OFF, 0, 0, 0, 0x76, ' '},
    {JNA,  OP_REL8OFF, 0, 0, 0, 0x76, ' '},
    {JNBE, OP_REL8OFF, 0, 0, 0, 0x77, ' '},
    {JA,   OP_REL8OFF, 0, 0, 0, 0x77, ' '},
    {JS,   OP_REL8OFF, 0, 0, 0, 0x78, ' '},
    {JNS,  OP_REL8OFF, 0, 0, 0, 0x79, ' '},
    {JP,   OP_REL8OFF, 0, 0, 0, 0x7A, ' '},
    {JPE,  OP_REL8OFF, 0, 0, 0, 0x7A, ' '},
    {JNP,  OP_REL8OFF, 0, 0, 0, 0x7B, ' '},
    {JPO,  OP_REL8OFF, 0, 0, 0, 0x7B, ' '},
    {JL,   OP_REL8OFF, 0, 0, 0, 0x7C, ' '},
    {JNGE, OP_REL8OFF, 0, 0, 0, 0x7C, ' '},
    {JNL,  OP_REL8OFF, 0, 0, 0, 0x7D, ' '},
    {JGE,  OP_REL8OFF, 0, 0, 0, 0x7D, ' '},
    {JLE,  OP_REL8OFF, 0, 0, 0, 0x7E, ' '},
    {JNG,  OP_REL8OFF, 0, 0, 0, 0x7E, ' '},
    {JNLE, OP_REL8OFF, 0, 0, 0, 0x7F, ' '},
    {JG,   OP_REL8OFF, 0, 0, 0, 0x7F, ' '},

    {JRCXZ, OP_REL8OFF, 0, 0, 0, 0xE3, ' '},

    {JMP, OP_REL8OFF, 0, 0, 0, 0xEB, ' '},
    {JMP, OP_REL32OFF, 0, 0, 0, 0xE9, ' '},
    {JMP, OP_RM64, 0, 0, 0, 0xFF, '4'},

    {LAHF, 0, 0, 0, 0, 0x9F, ' '},

    {LEA, OP_REG16, OP_MEM16, 0, 0, 0x8D66, 'r'},
    {LEA, OP_REG32, OP_MEM32, 0, 0, 0x8D, 'r'},
    {LEA, OP_REG64, OP_MEM64, 0, 0, 0x8D48, 'r'},

    {LEAVE, 0, 0, 0, 0, 0xC9, ' '},

    {LFENCE, 0, 0, 0, 0, 0xE8AE0F, ' '},

    {LODSB, 0, 0, 0, 0, 0xAC, ' '},
    {LODSW, 0, 0, 0, 0, 0xAD66, ' '},
    {LODSD, 0, 0, 0, 0, 0xAD, ' '},
    {LODSQ, 0, 0, 0, 0, 0xAD48, ' '},

    {LOOP, OP_REL8OFF, 0, 0, 0, 0xE2, ' '},
    {LOOPE, OP_REL8OFF, 0, 0, 0, 0xE1, ' '},
    {LOOPZ, OP_REL8OFF, 0, 0, 0, 0xE1, ' '},
    {LOOPNE, OP_REL8OFF, 0, 0, 0, 0xE0, ' '},
    {LOOPNZ, OP_REL8OFF, 0, 0, 0, 0xE0, ' '},

    {LZCNT, OP_REG16, OP_RM16, 0, 0, 0xBD0FF366, 'r'},
    {LZCNT, OP_REG32, OP_RM32, 0, 0, 0xBD0FF3, 'r'},
    {LZCNT, OP_REG64, OP_RM64, 0, 0, 0xBD0F48F3, 'r'},

    {MFENCE, 0, 0, 0, 0, 0xF0AE0F, ' '},

    {MOV, OP_RM8, OP_REG8, 0, 0, 0x88, 'r'},
    {MOV, OP_RM16, OP_REG16, 0, 0, 0x8966, 'r'},
    {MOV, OP_RM32, OP_REG32, 0, 0, 0x89, 'r'},
    {MOV, OP_RM64, OP_REG64, 0, 0, 0x8948, 'r'},

    {MOV, OP_REG8, OP_RM8, 0, 0, 0x8A, 'r'},
    {MOV, OP_REG16, OP_RM16, 0, 0, 0x8B66, 'r'},
    {MOV, OP_REG32, OP_RM32, 0, 0, 0x8B, 'r'},
    {MOV, OP_REG64, OP_RM64, 0, 0, 0x8B48, 'r'},

    {MOV, EXACT_AL,  OP_MOFFSET8,  0, 0, 0xA0, ' '},
    {MOV, EXACT_AX,  OP_MOFFSET16, 0, 0, 0xA166, ' '},
    {MOV, EXACT_EAX, OP_MOFFSET32, 0, 0, 0xA1, ' '},
    {MOV, EXACT_RAX, OP_MOFFSET64, 0, 0, 0xA148, ' '},

    {MOV, OP_MOFFSET8, EXACT_AL, 0, 0, 0xA2, ' '},
    {MOV, OP_MOFFSET16, EXACT_AX, 0, 0, 0xA366, ' '},
    {MOV, OP_MOFFSET32, EXACT_EAX, 0, 0, 0xA3, ' '},
    {MOV, OP_MOFFSET64, EXACT_RAX, 0, 0, 0xA348, ' '},

    {MOV, OP_REG8, OP_IMM8, 0, 0, 0xB0, '+'},
    {MOV, OP_REG16, OP_IMM16, 0, 0, 0xB866, '+'},
    {MOV, OP_REG32, OP_IMM32, 0, 0, 0xB8, '+'},
    {MOV, OP_REG64, OP_IMM64, 0, 0, 0xB848, '+'},

    {MOV, OP_RM8, OP_IMM8, 0, 0, 0xC6, '0'},
    {MOV, OP_RM16, OP_IMM16, 0, 0, 0xC766, '0'},
    {MOV, OP_RM32, OP_IMM32, 0, 0, 0xC7, '0'},
    {MOV, OP_RM64, OP_IMM32, 0, 0, 0xC748, '0'},

    {MOVBE, OP_REG16, OP_MEM16, 0, 0, 0xF0380F66u, 'r'},
    {MOVBE, OP_REG32, OP_MEM32, 0, 0, 0xF0380Fu, 'r'},
    {MOVBE, OP_REG64, OP_MEM64, 0, 0, 0xF0380F48u, 'r'},
    {MOVBE, OP_MEM16, OP_REG16, 0, 0, 0xF1380F66u, 'r'},
    {MOVBE, OP_MEM32, OP_REG32, 0, 0, 0xF1380Fu, 'r'},
    {MOVBE, OP_MEM64, OP_REG64, 0, 0, 0xF1380F48u, 'r'},

    {MOVD, OP_XMM0, OP_RM32, 0, 0, 0x6E0F66, 'r'},
    {MOVQ, OP_XMM0, OP_RM64, 0, 0, 0x6E0F4866, 'r'},
    {MOVD, OP_RM32, OP_XMM0, 0, 0, 0x7E0F66, 'r'},
    {MOVQ, OP_RM64, OP_XMM0, 0, 0, 0x7E0F4866, 'r'},

    {MOVMSKPD, OP_REG32, OP_XMM0, 0, 0, 0x500F66, 'r'},
    {MOVMSKPS, OP_REG32, OP_XMM0, 0, 0, 0x500F, 'r'},

    {MOVNTI, OP_MEM32, OP_REG32, 0, 0, 0xC30F, 'r'},
    {MOVNTI, OP_MEM64, OP_REG64, 0, 0, 0xC30F48, 'r'},

    {MOVSB, 0, 0, 0, 0, 0xA4, ' '},
    {MOVSW, 0, 0, 0, 0, 0xA5, ' '},
    {MOVSD, 0, 0, 0, 0, 0xA5, ' '},
    {MOVSQ, 0, 0, 0, 0, 0xA548, ' '},

    {MOVSX, OP_REG16, OP_RM8, 0, 0, 0xBE0F66, 'r'},
    {MOVSX, OP_REG32, OP_RM8, 0, 0, 0xBE0F, 'r'},
    {MOVSX, OP_REG64, OP_RM8, 0, 0, 0xBE0F48, 'r'},
    //~ {MOVSX, OP_REG32, OP_RM16, 0, 0, 0xBF0F, 'r'},
    {MOVSX, OP_REG64, OP_RM16, 0, 0, 0xBF0F4866u, 'r'},

    {MOVSXD, OP_REG64, OP_RM32, 0, 0, 0x63, 'r'},

    {MOVZX, OP_REG16, OP_RM8, 0, 0, 0xB60F66, 'r'},
    {MOVZX, OP_REG32, OP_RM8, 0, 0, 0xB60F, 'r'},
    {MOVZX, OP_REG64, OP_RM8, 0, 0, 0xB60F48, 'r'},

    {MUL, OP_RM8, 0, 0, 0, 0xF6, '4'},
    {MUL, OP_RM16, 0, 0, 0, 0xF766, '4'},
    {MUL, OP_RM32, 0, 0, 0, 0xF7, '4'},
    {MUL, OP_RM64, 0, 0, 0, 0xF748, '4'},

    {NEG, OP_RM8, 0, 0, 0, 0xF6, '3'},
    {NEG, OP_RM16, 0, 0, 0, 0xF766, '3'},
    {NEG, OP_RM32, 0, 0, 0, 0xF7, '3'},
    {NEG, OP_RM64, 0, 0, 0, 0xF748, '3'},

    {NOP, 0, 0, 0, 0, 0x90, ' '},

    {NOT, OP_RM8, 0, 0, 0, 0xF6, '2'},
    {NOT, OP_RM16, 0, 0, 0, 0xF766, '2'},
    {NOT, OP_RM32, 0, 0, 0, 0xF7, '2'},
    {NOT, OP_RM64, 0, 0, 0, 0xF748, '2'},

    {OR, EXACT_AL,  OP_IMM8,  0, 0, 0x0C, ' '},
    {OR, EXACT_AX,  OP_IMM16, 0, 0, 0x0D66, ' '},
    {OR, EXACT_EAX, OP_IMM32, 0, 0, 0x0D, ' '},
    {OR, EXACT_RAX, OP_IMM32, 0, 0, 0x0D48, ' '},

    {OR, OP_RM8,  OP_IMM8,  0, 0, 0x80, '1'},
    {OR, OP_RM16, OP_IMM16, 0, 0, 0x8166, '1'},
    {OR, OP_RM32, OP_IMM32, 0, 0, 0x81, '1'},
    {OR, OP_RM64, OP_IMM32, 0, 0, 0x8148, '1'},

    {OR, OP_RM16, OP_IMM8,  0, 0, 0x8366, '1'},
    {OR, OP_RM32, OP_IMM8,  0, 0, 0x83, '1'},
    {OR, OP_RM64, OP_IMM8,  0, 0, 0x8348, '1'},

    {OR, OP_REG8,  OP_RM8,  0, 0, 0x0A, 'r'},
    {OR, OP_REG16, OP_RM16, 0, 0, 0x0B66, 'r'},
    {OR, OP_REG32, OP_RM32, 0, 0, 0x0B, 'r'},
    {OR, OP_REG64, OP_RM64, 0, 0, 0x0B48, 'r'},

    {OR, OP_RM8,  OP_REG8,  0, 0, 0x08, 'r'},
    {OR, OP_RM16, OP_REG16, 0, 0, 0x0966, 'r'},
    {OR, OP_RM32, OP_REG32, 0, 0, 0x09, 'r'},
    {OR, OP_RM64, OP_REG64, 0, 0, 0x0948, 'r'},

    {PAUSE, 0, 0, 0, 0, 0x90F3, ' '},

    {POP, OP_REG16, 0, 0, 0, 0x5866, '+'},
    {POP, OP_REG64, 0, 0, 0, 0x58, '+'},

    {POP, OP_RM16, 0, 0, 0, 0x8F66, '0'},
    {POP, OP_RM64, 0, 0, 0, 0x8F, '0'},

    {POPCNT, OP_REG16, OP_RM16, 0, 0, 0xB80FF366u, 'r'},
    {POPCNT, OP_REG32, OP_RM32, 0, 0, 0xB80FF3u, 'r'},
    {POPCNT, OP_REG64, OP_RM64, 0, 0, 0xB80FF348u, 'r'},

    {POPF, 0, 0, 0, 0, 0x9D, ' '},

    {PREFETCH, OP_MEM8, 0, 0, 0, 0x0D0F, '0'},
    {PREFETCHW, OP_MEM8, 0, 0, 0, 0x0D0F, '1'},

    {PREFETCHNTA, OP_MEM8, 0, 0, 0, 0x180F, '0'},
    {PREFETCH0, OP_MEM8, 0, 0, 0, 0x180F, '1'},
    {PREFETCH1, OP_MEM8, 0, 0, 0, 0x180F, '2'},
    {PREFETCH2, OP_MEM8, 0, 0, 0, 0x180F, '3'},

    {PUSH, OP_REG16, 0, 0, 0, 0x5066, '+'},
    {PUSH, OP_REG64, 0, 0, 0, 0x50, '+'},

    {PUSH, OP_RM16, 0, 0, 0, 0xFF66, '6'},
    {PUSH, OP_RM64, 0, 0, 0, 0xFF, '6'},

    {PUSH, OP_IMM8, 0, 0, 0, 0x6A, ' '},
    {PUSH, OP_IMM16, 0, 0, 0, 0x6866, ' '},
    {PUSH, OP_IMM32, 0, 0, 0, 0x68, ' '},

    {PUSHF, 0, 0, 0, 0, 0x9C, ' '},

    {RCL, OP_RM8, 0, 0, 0, 0xD0, '2'},
    {RCL, OP_RM8, 0, 0, 0, 0xD2, '2'},
    {RCL, OP_RM8, OP_IMM8, 0, 0, 0xC0, '2'},

    {RCL, OP_RM16, 0, 0, 0, 0xD166, '2'},
    {RCL, OP_RM16, 0, 0, 0, 0xD366, '2'},
    {RCL, OP_RM16, OP_IMM8, 0, 0, 0xC166, '2'},

    {RCL, OP_RM32, 0, 0, 0, 0xD1, '2'},
    {RCL, OP_RM32, 0, 0, 0, 0xD3, '2'},
    {RCL, OP_RM32, OP_IMM8, 0, 0, 0xC1, '2'},

    {RCL, OP_RM64, 0, 0, 0, 0xD148, '2'},
    {RCL, OP_RM64, 0, 0, 0, 0xD348, '2'},
    {RCL, OP_RM64, OP_IMM8, 0, 0, 0xC148, '2'},

    {RCR, OP_RM8, 0, 0, 0, 0xD0, '3'},
    {RCR, OP_RM8, 0, 0, 0, 0xD2, '3'},
    {RCR, OP_RM8, OP_IMM8, 0, 0, 0xC0, '3'},

    {RCR, OP_RM16, 0, 0, 0, 0xD166, '3'},
    {RCR, OP_RM16, 0, 0, 0, 0xD366, '3'},
    {RCR, OP_RM16, OP_IMM8, 0, 0, 0xC166, '3'},

    {RCR, OP_RM32, 0, 0, 0, 0xD1, '3'},
    {RCR, OP_RM32, 0, 0, 0, 0xD3, '3'},
    {RCR, OP_RM32, OP_IMM8, 0, 0, 0xC1, '3'},

    {RCR, OP_RM64, 0, 0, 0, 0xD148, '3'},
    {RCR, OP_RM64, 0, 0, 0, 0xD348, '3'},
    {RCR, OP_RM64, OP_IMM8, 0, 0, 0xC148, '3'},

    {RET, OP_IMM16, 0, 0, 0, 0xC2, ' '},
    {RET, 0, 0, 0, 0, 0xC3, ' '},

    {ROL, OP_RM8, 0, 0, 0, 0xD0, '0'},
    {ROL, OP_RM8, 0, 0, 0, 0xD2, '0'},
    {ROL, OP_RM8, OP_IMM8, 0, 0, 0xC0, '0'},

    {ROL, OP_RM16, 0, 0, 0, 0xD166, '0'},
    {ROL, OP_RM16, 0, 0, 0, 0xD366, '0'},
    {ROL, OP_RM16, OP_IMM8, 0, 0, 0xC166, '0'},

    {ROL, OP_RM32, 0, 0, 0, 0xD1, '0'},
    {ROL, OP_RM32, 0, 0, 0, 0xD3, '0'},
    {ROL, OP_RM32, OP_IMM8, 0, 0, 0xC1, '0'},

    {ROL, OP_RM64, 0, 0, 0, 0xD148, '0'},
    {ROL, OP_RM64, 0, 0, 0, 0xD348, '0'},
    {ROL, OP_RM64, OP_IMM8, 0, 0, 0xC148, '0'},

    {ROR, OP_RM8, 0, 0, 0, 0xD0, '1'},
    {ROR, OP_RM8, 0, 0, 0, 0xD2, '1'},
    {ROR, OP_RM8, OP_IMM8, 0, 0, 0xC0, '1'},

    {ROR, OP_RM16, 0, 0, 0, 0xD166, '1'},
    {ROR, OP_RM16, 0, 0, 0, 0xD366, '1'},
    {ROR, OP_RM16, OP_IMM8, 0, 0, 0xC166, '1'},

    {ROR, OP_RM32, 0, 0, 0, 0xD1, '1'},
    {ROR, OP_RM32, 0, 0, 0, 0xD3, '1'},
    {ROR, OP_RM32, OP_IMM8, 0, 0, 0xC1, '1'},

    {ROR, OP_RM64, 0, 0, 0, 0xD148, '1'},
    {ROR, OP_RM64, 0, 0, 0, 0xD348, '1'},
    {ROR, OP_RM64, OP_IMM8, 0, 0, 0xC148, '1'},

    {SAHF, 0, 0, 0, 0, 0x9E, ' '},

    {SHL, OP_RM8, 0, 0, 0, 0xD0, '4'},
    {SHL, OP_RM8, 0, 0, 0, 0xD2, '4'},
    {SHL, OP_RM8, OP_IMM8, 0, 0, 0xC0, '4'},

    {SHL, OP_RM16, 0, 0, 0, 0xD166, '4'},
    {SHL, OP_RM16, 0, 0, 0, 0xD366, '4'},
    {SHL, OP_RM16, OP_IMM8, 0, 0, 0xC166, '4'},

    {SHL, OP_RM32, 0, 0, 0, 0xD1, '4'},
    {SHL, OP_RM32, 0, 0, 0, 0xD3, '4'},
    {SHL, OP_RM32, OP_IMM8, 0, 0, 0xC1, '4'},

    {SHL, OP_RM64, 0, 0, 0, 0xD148, '4'},
    {SHL, OP_RM64, 0, 0, 0, 0xD348, '4'},
    {SHL, OP_RM64, OP_IMM8, 0, 0, 0xC148, '4'},

    {SAR, OP_RM8, 0, 0, 0, 0xD0, '7'},
    {SAR, OP_RM8, 0, 0, 0, 0xD2, '7'},
    {SAR, OP_RM8, OP_IMM8, 0, 0, 0xC0, '7'},

    {SAR, OP_RM16, 0, 0, 0, 0xD166, '7'},
    {SAR, OP_RM16, 0, 0, 0, 0xD366, '7'},
    {SAR, OP_RM16, OP_IMM8, 0, 0, 0xC166, '7'},

    {SAR, OP_RM32, 0, 0, 0, 0xD1, '7'},
    {SAR, OP_RM32, 0, 0, 0, 0xD3, '7'},
    {SAR, OP_RM32, OP_IMM8, 0, 0, 0xC1, '7'},

    {SAR, OP_RM64, 0, 0, 0, 0xD148, '7'},
    {SAR, OP_RM64, 0, 0, 0, 0xD348, '7'},
    {SAR, OP_RM64, OP_IMM8, 0, 0, 0xC148, '7'},

    {SBB, EXACT_AL,  OP_IMM8,  0, 0, 0x1C, ' '},
    {SBB, EXACT_AX,  OP_IMM16, 0, 0, 0x1D66, ' '},
    {SBB, EXACT_EAX, OP_IMM32, 0, 0, 0x1D, ' '},
    {SBB, EXACT_RAX, OP_IMM32, 0, 0, 0x1D48, ' '},

    {SBB, OP_RM8,  OP_IMM8,  0, 0, 0x80, '3'},
    {SBB, OP_RM16, OP_IMM16, 0, 0, 0x8166, '3'},
    {SBB, OP_RM32, OP_IMM32, 0, 0, 0x81, '3'},
    {SBB, OP_RM64, OP_IMM32, 0, 0, 0x8148, '3'},

    {SBB, OP_RM16, OP_IMM8,  0, 0, 0x8366, '3'},
    {SBB, OP_RM32, OP_IMM8,  0, 0, 0x83, '3'},
    {SBB, OP_RM64, OP_IMM8,  0, 0, 0x8348, '3'},

    {SBB, OP_REG8,  OP_RM8,  0, 0, 0x1A, 'r'},
    {SBB, OP_REG16, OP_RM16, 0, 0, 0x1B66, 'r'},
    {SBB, OP_REG32, OP_RM32, 0, 0, 0x1B, 'r'},
    {SBB, OP_REG64, OP_RM64, 0, 0, 0x1B48, 'r'},

    {SBB, OP_RM8,  OP_REG8,  0, 0, 0x18, 'r'},
    {SBB, OP_RM16, OP_REG16, 0, 0, 0x1966, 'r'},
    {SBB, OP_RM32, OP_REG32, 0, 0, 0x19, 'r'},
    {SBB, OP_RM64, OP_REG64, 0, 0, 0x1948, 'r'},

    {SCASB, 0, 0, 0, 0, 0xAE, ' '},
    {SCASW, 0, 0, 0, 0, 0xAF66, ' '},
    {SCASD, 0, 0, 0, 0, 0xAF, ' '},
    {SCASQ, 0, 0, 0, 0, 0xAF48, ' '},

    {SETO,   OP_RM8, 0, 0, 0, 0x900F, '0'},
    {SETNO,  OP_RM8, 0, 0, 0, 0x910F, '0'},
    {SETB,   OP_RM8, 0, 0, 0, 0x920F, '0'},
    {SETC,   OP_RM8, 0, 0, 0, 0x920F, '0'},
    {SETNAE, OP_RM8, 0, 0, 0, 0x920F, '0'},
    {SETNB,  OP_RM8, 0, 0, 0, 0x930F, '0'},
    {SETNC,  OP_RM8, 0, 0, 0, 0x930F, '0'},
    {SETAE,  OP_RM8, 0, 0, 0, 0x930F, '0'},
    {SETZ,   OP_RM8, 0, 0, 0, 0x940F, '0'},
    {SETE,   OP_RM8, 0, 0, 0, 0x940F, '0'},
    {SETNZ,  OP_RM8, 0, 0, 0, 0x950F, '0'},
    {SETNE,  OP_RM8, 0, 0, 0, 0x950F, '0'},
    {SETBE,  OP_RM8, 0, 0, 0, 0x960F, '0'},
    {SETNA,  OP_RM8, 0, 0, 0, 0x960F, '0'},
    {SETNBE, OP_RM8, 0, 0, 0, 0x970F, '0'},
    {SETA,   OP_RM8, 0, 0, 0, 0x970F, '0'},
    {SETS,   OP_RM8, 0, 0, 0, 0x980F, '0'},
    {SETNS,  OP_RM8, 0, 0, 0, 0x990F, '0'},
    {SETP,   OP_RM8, 0, 0, 0, 0x9A0F, '0'},
    {SETPE,  OP_RM8, 0, 0, 0, 0x9A0F, '0'},
    {SETNP,  OP_RM8, 0, 0, 0, 0x9B0F, '0'},
    {SETPO,  OP_RM8, 0, 0, 0, 0x9B0F, '0'},
    {SETL,   OP_RM8, 0, 0, 0, 0x9C0F, '0'},
    {SETNGE, OP_RM8, 0, 0, 0, 0x9C0F, '0'},
    {SETNL,  OP_RM8, 0, 0, 0, 0x9D0F, '0'},
    {SETGE,  OP_RM8, 0, 0, 0, 0x9D0F, '0'},
    {SETLE,  OP_RM8, 0, 0, 0, 0x9E0F, '0'},
    {SETNG,  OP_RM8, 0, 0, 0, 0x9E0F, '0'},
    {SETNLE, OP_RM8, 0, 0, 0, 0x9F0F, '0'},
    {SETG,   OP_RM8, 0, 0, 0, 0x9F0F, '0'},

    {SFENCE, 0, 0, 0, 0, 0xF8AE0F, ' '},

    {SHLD, OP_RM16, OP_REG16, OP_IMM8,  0xA40F66, 'r'},
    {SHLD, OP_RM16, OP_REG16, 0,  0xA50F66, 'r'},

    {SHLD, OP_RM32, OP_REG32, OP_IMM8,  0xA40F, 'r'},
    {SHLD, OP_RM32, OP_REG32, 0,  0xA50F, 'r'},

    {SHLD, OP_RM64, OP_REG64, OP_IMM8,  0xA40F48, 'r'},
    {SHLD, OP_RM64, OP_REG64, 0,  0xA50F48, 'r'},

    {SHR, OP_RM8, 0, 0, 0, 0xD0, '5'},
    {SHR, OP_RM8, 0, 0, 0, 0xD2, '5'},
    {SHR, OP_RM8, OP_IMM8, 0, 0, 0xC0, '5'},

    {SHR, OP_RM16, 0, 0, 0, 0xD166, '5'},
    {SHR, OP_RM16, 0, 0, 0, 0xD366, '5'},
    {SHR, OP_RM16, OP_IMM8, 0, 0, 0xC166, '5'},

    {SHR, OP_RM32, 0, 0, 0, 0xD1, '5'},
    {SHR, OP_RM32, 0, 0, 0, 0xD3, '5'},
    {SHR, OP_RM32, OP_IMM8, 0, 0, 0xC1, '5'},

    {SHR, OP_RM64, 0, 0, 0, 0xD148, '5'},
    {SHR, OP_RM64, 0, 0, 0, 0xD348, '5'},
    {SHR, OP_RM64, OP_IMM8, 0, 0, 0xC148, '5'},

    {SHRD, OP_RM16, OP_REG16, OP_IMM8,  0xAC0F66, 'r'},
    {SHRD, OP_RM16, OP_REG16, 0,  0xAD0F66, 'r'},

    {SHRD, OP_RM32, OP_REG32, OP_IMM8,  0xAC0F, 'r'},
    {SHRD, OP_RM32, OP_REG32, 0,  0xAD0F, 'r'},

    {SHRD, OP_RM64, OP_REG64, OP_IMM8,  0xAC0F48, 'r'},
    {SHRD, OP_RM64, OP_REG64, 0,  0xAD0F48, 'r'},

    {STC, 0, 0, 0, 0, 0xF9, ' '},
    {STD, 0, 0, 0, 0, 0xFD, ' '},

    {STOSB, 0, 0, 0, 0, 0xAA, ' '},
    {STOSW, 0, 0, 0, 0, 0xAB66, ' '},
    {STOSD, 0, 0, 0, 0, 0xAB, ' '},
    {STOSQ, 0, 0, 0, 0, 0xAB48, ' '},

    {SUB, EXACT_AL,  OP_IMM8,  0, 0, 0x2C, ' '},
    {SUB, EXACT_AX,  OP_IMM16, 0, 0, 0x2D66, ' '},
    {SUB, EXACT_EAX, OP_IMM32, 0, 0, 0x2D, ' '},
    {SUB, EXACT_RAX, OP_IMM32, 0, 0, 0x2D48, ' '},

    {SUB, OP_RM8,  OP_IMM8,  0, 0, 0x80, '5'},
    {SUB, OP_RM16, OP_IMM16, 0, 0, 0x8166, '5'},
    {SUB, OP_RM32, OP_IMM32, 0, 0, 0x81, '5'},
    {SUB, OP_RM64, OP_IMM32, 0, 0, 0x8148, '5'},

    {SUB, OP_RM16, OP_IMM8,  0, 0, 0x8366, '5'},
    {SUB, OP_RM32, OP_IMM8,  0, 0, 0x83, '5'},
    {SUB, OP_RM64, OP_IMM8,  0, 0, 0x8348, '5'},

    {SUB, OP_REG8,  OP_RM8,  0, 0, 0x2A, 'r'},
    {SUB, OP_REG16, OP_RM16, 0, 0, 0x2B66, 'r'},
    {SUB, OP_REG32, OP_RM32, 0, 0, 0x2B, 'r'},
    {SUB, OP_REG64, OP_RM64, 0, 0, 0x2B48, 'r'},

    {SUB, OP_RM8,  OP_REG8,  0, 0, 0x28, 'r'},
    {SUB, OP_RM16, OP_REG16, 0, 0, 0x2966, 'r'},
    {SUB, OP_RM32, OP_REG32, 0, 0, 0x29, 'r'},
    {SUB, OP_RM64, OP_REG64, 0, 0, 0x2948, 'r'},

    {TEST, EXACT_AL,  OP_IMM8,  0, 0, 0xA8, ' '},
    {TEST, EXACT_AX,  OP_IMM16, 0, 0, 0xA966, ' '},
    {TEST, EXACT_EAX, OP_IMM32, 0, 0, 0xA9, ' '},
    {TEST, EXACT_RAX, OP_IMM32, 0, 0, 0xA948, ' '},

    {TEST, OP_RM8,  OP_IMM8,  0, 0, 0xF6, '0'},
    {TEST, OP_RM16, OP_IMM16, 0, 0, 0xF766, '0'},
    {TEST, OP_RM32, OP_IMM32, 0, 0, 0xF7, '0'},
    {TEST, OP_RM64, OP_IMM32, 0, 0, 0xF748, '0'},

    {TEST, OP_RM8,  OP_REG8,  0, 0, 0x84, 'r'},
    {TEST, OP_RM16, OP_REG16, 0, 0, 0x8566, 'r'},
    {TEST, OP_RM32, OP_REG32, 0, 0, 0x85, 'r'},
    {TEST, OP_RM64, OP_REG32, 0, 0, 0x8548, 'r'},

    {TZCNT, OP_REG16, OP_RM16, 0, 0, 0xBC0FF366, 'r'},
    {TZCNT, OP_REG32, OP_RM32, 0, 0, 0xBC0FF3, 'r'},
    {TZCNT, OP_REG64, OP_RM64, 0, 0, 0xBC0FF348, 'r'},

    {XADD, OP_RM8, OP_REG8, 0, 0, 0xC00F, 'r'},
    {XADD, OP_RM16, OP_REG16, 0, 0, 0xC10F66, 'r'},
    {XADD, OP_RM32, OP_REG32, 0, 0, 0xC10F, 'r'},
    {XADD, OP_RM64, OP_REG64, 0, 0, 0xC10F48, 'r'},

    {XCHG, EXACT_AX, OP_REG16, 0, 0, 0x9066, '+'},
    {XCHG, OP_REG16, EXACT_AX, 0, 0, 0x9066, '+'},
    {XCHG, EXACT_EAX, OP_REG32, 0, 0, 0x90, '+'},
    {XCHG, OP_REG32, EXACT_EAX, 0, 0, 0x90, '+'},
    {XCHG, EXACT_RAX, OP_REG64, 0, 0, 0x9048, '+'},
    {XCHG, OP_REG64, EXACT_RAX, 0, 0, 0x9048, '+'},

    {XCHG, OP_RM8  , OP_REG8 , 0, 0, 0x86, 'r'},
    {XCHG, OP_RM16 , OP_REG16, 0, 0, 0x8766, 'r'},
    {XCHG, OP_RM32 , OP_REG32, 0, 0, 0x87, 'r'},
    {XCHG, OP_RM64 , OP_REG64, 0, 0, 0x8748, 'r'},
    {XCHG, OP_REG8  , OP_RM8 , 0, 0, 0x86, 'r'},
    {XCHG, OP_REG16 , OP_RM16, 0, 0, 0x8766, 'r'},
    {XCHG, OP_REG32 , OP_RM32, 0, 0, 0x87, 'r'},
    {XCHG, OP_REG64 , OP_RM64, 0, 0, 0x8748, 'r'},

    {XLAT, 0, 0, 0, 0, 0xD7, ' '},

    {XOR, EXACT_AL,  OP_IMM8,  0, 0, 0x34, ' '},
    {XOR, EXACT_AX,  OP_IMM16, 0, 0, 0x3566, ' '},
    {XOR, EXACT_EAX, OP_IMM32, 0, 0, 0x35, ' '},
    {XOR, EXACT_RAX, OP_IMM32, 0, 0, 0x3548, ' '},

    {XOR, OP_RM8,  OP_IMM8,  0, 0, 0x80, '6'},
    {XOR, OP_RM16, OP_IMM16, 0, 0, 0x8166, '6'},
    {XOR, OP_RM32, OP_IMM32, 0, 0, 0x81, '6'},
    {XOR, OP_RM64, OP_IMM32, 0, 0, 0x8148, '6'},

    {XOR, OP_RM16, OP_IMM8,  0, 0, 0x8366, '6'},
    {XOR, OP_RM32, OP_IMM8,  0, 0, 0x83, '6'},
    {XOR, OP_RM64, OP_IMM8,  0, 0, 0x8348, '6'},

    {XOR, OP_REG8,  OP_RM8,  0, 0, 0x32, 'r'},
    {XOR, OP_REG16, OP_RM16, 0, 0, 0x3366, 'r'},
    {XOR, OP_REG32, OP_RM32, 0, 0, 0x33, 'r'},
    {XOR, OP_REG64, OP_RM64, 0, 0, 0x3348, 'r'},

    {XOR, OP_RM8,  OP_REG8,  0, 0, 0x30, 'r'},
    {XOR, OP_RM16, OP_REG16, 0, 0, 0x3166, 'r'},
    {XOR, OP_RM32, OP_REG32, 0, 0, 0x31, 'r'},
    {XOR, OP_RM64, OP_REG64, 0, 0, 0x3148, 'r'},

    {RDTSC, 0, 0, 0, 0, 0x310F, ' '},

    {ADDPD, OP_XMM0, OP_RM128, 0, 0, 0x580F66, 'r'},
    {ADDPS, OP_XMM0, OP_RM128, 0, 0, 0x580F, 'r'},
    {ADDSD, OP_XMM0, OP_RM128, 0, 0, 0x580FF2, 'r'},
    {ADDSS, OP_XMM0, OP_RM128, 0, 0, 0x580FF3, 'r'},

    {ADDSUBPD, OP_XMM0, OP_RM128, 0, 0, 0xD00F66, 'r'},
    {ADDSUBPS, OP_XMM0, OP_RM128, 0, 0, 0xD00FF2, 'r'},

    {ANDNPD, OP_XMM0, OP_RM128, 0, 0, 0x550F66, 'r'},
    {ANDNPS, OP_XMM0, OP_RM128, 0, 0, 0x550F, 'r'},

    {ANDPD, OP_XMM0, OP_RM128, 0, 0, 0x540F66, 'r'},
    {ANDPS, OP_XMM0, OP_RM128, 0, 0, 0x540F, 'r'},

    {BLENDPD, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x0D3A0F66u, 'r'},
    {BLENDPS, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x0C3A0F66u, 'r'},

    {BLENDVPD, OP_XMM0, OP_RM128, 0, 0, 0x15380F66, 'r'},
    {BLENDVPS, OP_XMM0, OP_RM128, 0, 0, 0x14380F66, 'r'},

    {CMPPD, OP_XMM0, OP_RM128, OP_IMM8, 0, 0xC20F66, 'r'},
    {CMPPS, OP_XMM0, OP_RM128, OP_IMM8, 0, 0xC20F, 'r'},

    {CMPSD, OP_XMM0, OP_RM128, OP_IMM8, 0, 0xC20FF2, 'r'},
    {CMPSS, OP_XMM0, OP_RM128, OP_IMM8, 0, 0xC20FF3, 'r'},

    {COMISD, OP_XMM0, OP_RM128, 0, 0, 0x2F0F66, 'r'},
    {COMISS, OP_XMM0, OP_RM128, 0, 0, 0x2F0F, 'r'},

    {CVTDQ2PD, OP_XMM0, OP_RM128, 0, 0, 0xE60FF3, 'r'},
    {CVTDQ2PS, OP_XMM0, OP_RM128, 0, 0, 0x5B0F, 'r'},
    {CVTPD2DQ, OP_XMM0, OP_RM128, 0, 0, 0xE60FF2, 'r'},
    {CVTPD2PS, OP_XMM0, OP_RM128, 0, 0, 0x5A0F66, 'r'},
    {CVTPS2DQ, OP_XMM0, OP_RM128, 0, 0, 0x5B0F66, 'r'},
    {CVTPS2PD, OP_XMM0, OP_RM128, 0, 0, 0x5A0F, 'r'},
    {CVTSD2SI, OP_REG32, OP_RM128, 0, 0, 0x2D0FF2, 'r'},
    {CVTSD2SI, OP_REG64, OP_RM128, 0, 0, 0x2D0F48F2u, 'r'},
    {CVTSD2SS, OP_XMM0, OP_RM128, 0, 0, 0x5A0FF2u, 'r'},
    {CVTSI2SD, OP_XMM0, OP_RM32, 0, 0, 0x2A0FF2, 'r'},
    {CVTSI2SD, OP_XMM0, OP_RM64, 0, 0, 0x2A0F48F2u, 'r'},
    {CVTSI2SS, OP_XMM0, OP_RM32, 0, 0, 0x2A0FF3, 'r'},
    {CVTSI2SS, OP_XMM0, OP_RM64, 0, 0, 0x2A0F48F3u, 'r'},
    {CVTSS2SD, OP_XMM0, OP_RM128, 0, 0, 0x5A0FF3, 'r'},
    {CVTSS2SI, OP_REG32, OP_RM128, 0, 0, 0x2D0FF3, 'r'},
    {CVTSS2SI, OP_REG64, OP_RM128, 0, 0, 0x2D0F48F3u, 'r'},

    {CVTTPD2DQ, OP_XMM0, OP_RM128, 0, 0, 0xE60F66, 'r'},
    {CVTTPS2DQ, OP_XMM0, OP_RM128, 0, 0, 0x5B0FF3, 'r'},
    {CVTTSD2SI, OP_REG32, OP_RM128, 0, 0, 0x2C0FF2, 'r'},
    {CVTTSD2SI, OP_REG64, OP_RM128, 0, 0, 0x2C0F48F2u, 'r'},
    {CVTTSS2SI, OP_REG32, OP_RM128, 0, 0, 0x2C0FF3, 'r'},
    {CVTTSS2SI, OP_REG64, OP_RM128, 0, 0, 0x2C0F48F3u, 'r'},

    {DIVPD, OP_XMM0, OP_RM128, 0, 0, 0x5E0F66, 'r'},
    {DIVPS, OP_XMM0, OP_RM128, 0, 0, 0x5E0F, 'r'},
    {DIVSD, OP_XMM0, OP_RM128, 0, 0, 0x5E0FF2, 'r'},
    {DIVSS, OP_XMM0, OP_RM128, 0, 0, 0x5E0FF3, 'r'},

    {DPPD, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x413A0F66u, 'r'},
    {DPPS, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x403A0F66u, 'r'},

    {EXTRACTPS, OP_RM32, OP_XMM0, OP_IMM8, 0, 0x173A0F66u, 'r'},

    {EXTRQ, OP_XMM0, OP_IMM8, OP_IMM8, 0, 0x780F66, '0'},
    {EXTRQ, OP_XMM0, OP_XMM0, 0, 0, 0x790F66, 'r'},

    {HADDPD, OP_XMM0, OP_RM128, 0, 0, 0x7C0F66, 'r'},
    {HADDPS, OP_XMM0, OP_RM128, 0, 0, 0x7C0FF2, 'r'},

    {HSUBPD, OP_XMM0, OP_RM128, 0, 0, 0x7D0F66, 'r'},
    {HSUBPS, OP_XMM0, OP_RM128, 0, 0, 0x7D0FF2, 'r'},

    {INSERTPS, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x213A0F66u, 'r'},

    {INSERTQ, OP_XMM0, OP_XMM0, OP_IMM8, 0, 0x780FF2, 'r'},
    {INSERTQ, OP_XMM0, OP_XMM0, 0, 0, 0x790FF2, 'r'},

    {LDDQU, OP_XMM0, OP_RM128, 0, 0, 0xF00FF2, 'r'},

    {MASKMOVDQU, OP_XMM0, OP_XMM0, 0, 0, 0xF70F66, 'r'},

    {MAXPD, OP_XMM0, OP_RM128, 0, 0, 0x5F0F66, 'r'},
    {MAXPS, OP_XMM0, OP_RM128, 0, 0, 0x5F0F, 'r'},
    {MAXSD, OP_XMM0, OP_RM128, 0, 0, 0x5F0FF2, 'r'},
    {MAXSS, OP_XMM0, OP_RM128, 0, 0, 0x5F0FF3, 'r'},

    {MINPD, OP_XMM0, OP_RM128, 0, 0, 0x5D0F66, 'r'},
    {MINPS, OP_XMM0, OP_RM128, 0, 0, 0x5D0F, 'r'},
    {MINSD, OP_XMM0, OP_RM128, 0, 0, 0x5D0FF2, 'r'},
    {MINSS, OP_XMM0, OP_RM128, 0, 0, 0x5D0FF3, 'r'},

    {MOVAPD, OP_XMM0, OP_RM128, 0, 0, 0x280F66, 'r'},
    {MOVAPD, OP_RM128, OP_XMM0, 0, 0, 0x290F66, 'r'},
    {MOVAPS, OP_XMM0, OP_RM128, 0, 0, 0x280F66, 'r'},
    {MOVAPS, OP_RM128, OP_XMM0, 0, 0, 0x290F66, 'r'},

    {MOVDDUP, OP_XMM0, OP_RM128, 0, 0, 0x120FF2, 'r'},
    {MOVDQA, OP_XMM0, OP_RM128, 0, 0, 0x6F0F66, 'r'},
    {MOVDQA, OP_RM128, OP_XMM0, 0, 0, 0x7F0F66, 'r'},
    {MOVDQU, OP_XMM0, OP_RM128, 0, 0, 0x6F0FF3, 'r'},
    {MOVDQU, OP_RM128, OP_XMM0, 0, 0, 0x7F0FF3, 'r'},
    {MOVHLPS, OP_XMM0, OP_XMM0, 0, 0, 0x120F, 'r'},
    {MOVHPD, OP_XMM0, OP_MEM64, 0, 0, 0x160F66u, 'r'},
    {MOVHPD, OP_MEM64, OP_XMM0, 0, 0, 0x170F66u, 'r'},
    {MOVHPS, OP_XMM0, OP_MEM64, 0, 0, 0x160F48, 'r'},
    {MOVHPS, OP_MEM64, OP_XMM0, 0, 0, 0x170F48, 'r'},
    {MOVLHPS, OP_XMM0, OP_XMM0, 0, 0, 0x160F, 'r'},
    {MOVLPD, OP_XMM0, OP_MEM64, 0, 0, 0x120F66u, 'r'},
    {MOVLPD, OP_MEM64, OP_XMM0, 0, 0, 0x130F66u, 'r'},
    {MOVLPS, OP_XMM0, OP_MEM64, 0, 0, 0x120F48, 'r'},
    {MOVLPS, OP_MEM64, OP_XMM0, 0, 0, 0x130F48, 'r'},

    {MOVNTDQ, OP_MEM128, OP_XMM0, 0, 0, 0xE70F66, 'r'},
    {MOVNTDQA, OP_MEM128, OP_XMM0, 0, 0, 0x2A380F66u, 'r'},
    {MOVNTPD, OP_MEM128, OP_XMM0, 0, 0, 0x2B0F66, 'r'},
    {MOVNTPS, OP_MEM128, OP_XMM0, 0, 0, 0x2B0F, 'r'},
    {MOVNTSD, OP_MEM128, OP_XMM0, 0, 0, 0x2B0FF2, 'r'},
    {MOVNTSS, OP_MEM128, OP_XMM0, 0, 0, 0x2B0FF3, 'r'},
    {MOVSD, OP_XMM0, OP_RM128, 0, 0, 0x100FF2, 'r'},
    {MOVSD, OP_RM128, OP_XMM0, 0, 0, 0x110FF2, 'r'},
    {MOVSHDUP, OP_XMM0, OP_RM128, 0, 0, 0x160FF3, 'r'},
    {MOVSLDUP, OP_XMM0, OP_RM128, 0, 0, 0x120FF3, 'r'},
    {MOVSS, OP_XMM0, OP_RM128, 0, 0, 0x100FF3, 'r'},
    {MOVSS, OP_RM128, OP_XMM0, 0, 0, 0x110FF3, 'r'},
    {MOVUPD, OP_XMM0, OP_RM128, 0, 0, 0x100F66, 'r'},
    {MOVUPD, OP_RM128, OP_XMM0, 0, 0, 0x110F66, 'r'},
    {MOVUPS, OP_XMM0, OP_RM128, 0, 0, 0x100F, 'r'},
    {MOVUPS, OP_RM128, OP_XMM0, 0, 0, 0x110F, 'r'},

    {MPSADBW, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x423A0F66u, 'r'},

    {MULPD, OP_XMM0, OP_RM128, 0, 0, 0x590F66, 'r'},
    {MULPS, OP_XMM0, OP_RM128, 0, 0, 0x590F, 'r'},
    {MULSD, OP_XMM0, OP_RM128, 0, 0, 0x590FF2, 'r'},
    {MULSS, OP_XMM0, OP_RM128, 0, 0, 0x590FF3, 'r'},

    {ORPD, OP_XMM0, OP_RM128, 0, 0, 0x560F66, 'r'},
    {ORPS, OP_XMM0, OP_RM128, 0, 0, 0x560F, 'r'},

    {PABSB, OP_XMM0, OP_RM128, 0, 0, 0x1C380F, 'r'},
    {PABSW, OP_XMM0, OP_RM128, 0, 0, 0x1D380F, 'r'},
    {PABSD, OP_XMM0, OP_RM128, 0, 0, 0x1E380F, 'r'},

    {PACKSSDW, OP_XMM0, OP_RM128, 0, 0, 0x6B0F66, 'r'},
    {PACKSSWB, OP_XMM0, OP_RM128, 0, 0, 0x630F66, 'r'},
    {PACKUSDW, OP_XMM0, OP_RM128, 0, 0, 0x2B380F66u, 'r'},
    {PACKUSWB, OP_XMM0, OP_RM128, 0, 0, 0x670F66, 'r'},

    {PADDB, OP_XMM0, OP_RM128, 0, 0, 0xFC0F66, 'r'},
    {PADDW, OP_XMM0, OP_RM128, 0, 0, 0xFD0F66, 'r'},
    {PADDD, OP_XMM0, OP_RM128, 0, 0, 0xFE0F66, 'r'},
    {PADDQ, OP_XMM0, OP_RM128, 0, 0, 0xD40F66, 'r'},
    {PADDSB, OP_XMM0, OP_RM128, 0, 0, 0xEC0F66, 'r'},
    {PADDSW, OP_XMM0, OP_RM128, 0, 0, 0xED0F66, 'r'},
    {PADDUSB, OP_XMM0, OP_RM128, 0, 0, 0xDC0F66, 'r'},
    {PADDUSW, OP_XMM0, OP_RM128, 0, 0, 0xDD0F66, 'r'},

    {PALIGNR, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x0F3A0F66u, 'r'},

    {PAND, OP_XMM0, OP_RM128, 0, 0, 0xDB0F66u, 'r'},
    {PANDN, OP_XMM0, OP_RM128, 0, 0, 0xDF0F66u, 'r'},
    {PAVGB, OP_XMM0, OP_RM128, 0, 0, 0xE00F66u, 'r'},
    {PAVGW, OP_XMM0, OP_RM128, 0, 0, 0xE30F66u, 'r'},

    {PBLENDVB, OP_XMM0, OP_RM128, 0, 0, 0x10380F66u, 'r'},
    {PBLENDW, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x0E3A0F66u, 'r'},

    {PCLMULQDQ, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x443A0F66u, 'r'},

    {PCMPEQB, OP_XMM0, OP_RM128, 0, 0, 0x740F66u, 'r'},
    {PCMPEQD, OP_XMM0, OP_RM128, 0, 0, 0x760F66u, 'r'},
    {PCMPEQW, OP_XMM0, OP_RM128, 0, 0, 0x750F66u, 'r'},
    {PCMPEQQ, OP_XMM0, OP_RM128, 0, 0, 0x29380F66u, 'r'},
    {PCMPESTRI, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x613A0F66u, 'r'},
    {PCMPESTRM, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x603A0F66u, 'r'},
    {PCMPGTB, OP_XMM0, OP_RM128, 0, 0, 0x640F66u, 'r'},
    {PCMPGTD, OP_XMM0, OP_RM128, 0, 0, 0x660F66u, 'r'},
    {PCMPGTW, OP_XMM0, OP_RM128, 0, 0, 0x650F66u, 'r'},
    {PCMPGTQ, OP_XMM0, OP_RM128, 0, 0, 0x37380F66u, 'r'},
    {PCMPISTRI, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x633A0F66u, 'r'},
    {PCMPISTRM, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x623A0F66u, 'r'},

    {PEXTRB, OP_RM8, OP_XMM0, OP_IMM8, 0, 0x143A0F66u, 'r'},
    {PEXTRW, OP_RM16, OP_XMM0, OP_IMM8, 0, 0x153A0F66u, 'r'},
    {PEXTRD, OP_RM32, OP_XMM0, OP_IMM8, 0, 0x163A0F66u, 'r'},
    {PEXTRQ, OP_RM64, OP_XMM0, OP_IMM8, 0, 0x163A0F4866ull, 'r'},

    {PHADDD, OP_XMM0, OP_RM128, 0, 0, 0x02380F66u, 'r'},
    {PHADDSW, OP_XMM0, OP_RM128, 0, 0, 0x03380F66u, 'r'},
    {PHADDW, OP_XMM0, OP_RM128, 0, 0, 0x01380F66u, 'r'},

    {PHMINPOSUW, OP_XMM0, OP_RM128, 0, 0, 0x41380F66u, 'r'},

    {PHSUBD, OP_XMM0, OP_RM128, 0, 0, 0x06380F66u, 'r'},
    {PHSUBSW, OP_XMM0, OP_RM128, 0, 0, 0x07380F66u, 'r'},
    {PHSUBW, OP_XMM0, OP_RM128, 0, 0, 0x05380F66u, 'r'},

    {PINSRB, OP_XMM0, OP_RM8, OP_IMM8, 0, 0x203A0F66u, 'r'},
    {PINSRW, OP_XMM0, OP_RM16, OP_IMM8, 0, 0xC40F66u, 'r'},
    {PINSRD, OP_XMM0, OP_RM32, OP_IMM8, 0, 0x223A0F66u, 'r'},
    {PINSRQ, OP_XMM0, OP_RM64, OP_IMM8, 0, 0x223A0F4866ull, 'r'},

    {PMADDUBSW, OP_XMM0, OP_RM128, 0, 0, 0x04380F66u, 'r'},
    {PMADDWD, OP_XMM0, OP_RM128, 0, 0, 0xF50F66u, 'r'},

    {PMAXSB, OP_XMM0, OP_RM128, 0, 0, 0x3C380F66u, 'r'},
    {PMAXSD, OP_XMM0, OP_RM128, 0, 0, 0x3D380F66u, 'r'},
    {PMAXSW, OP_XMM0, OP_RM128, 0, 0, 0xEE0F66u, 'r'},
    {PMAXSUB, OP_XMM0, OP_RM128, 0, 0, 0xDE0F66u, 'r'},
    {PMAXSUD, OP_XMM0, OP_RM128, 0, 0, 0x3F380F66u, 'r'},
    {PMAXSUW, OP_XMM0, OP_RM128, 0, 0, 0x3E0F66u, 'r'},

    {PMINSB, OP_XMM0, OP_RM128, 0, 0, 0x38380F66u, 'r'},
    {PMINSD, OP_XMM0, OP_RM128, 0, 0, 0x39380F66u, 'r'},
    {PMINSW, OP_XMM0, OP_RM128, 0, 0, 0xEA0F66u, 'r'},
    {PMINUB, OP_XMM0, OP_RM128, 0, 0, 0xDA0F66u, 'r'},
    {PMINUD, OP_XMM0, OP_RM128, 0, 0, 0x3B380F66u, 'r'},
    {PMINUW, OP_XMM0, OP_RM128, 0, 0, 0x3A380F66u, 'r'},

    {PMOVMSKB, OP_REG32, OP_XMM0, 0, 0, 0xD70F66u, 'r'},

    {PMOVSXBD, OP_XMM0, OP_RM128, 0, 0, 0x21380F66u, 'r'},
    {PMOVSXBQ, OP_XMM0, OP_RM128, 0, 0, 0x22380F66u, 'r'},
    {PMOVSXBW, OP_XMM0, OP_RM128, 0, 0, 0x20380F66u, 'r'},
    {PMOVSXDQ, OP_XMM0, OP_RM128, 0, 0, 0x25380F66u, 'r'},
    {PMOVSXWD, OP_XMM0, OP_RM128, 0, 0, 0x23380F66u, 'r'},
    {PMOVSXWQ, OP_XMM0, OP_RM128, 0, 0, 0x24380F66u, 'r'},
    {PMOVZXBD, OP_XMM0, OP_RM128, 0, 0, 0x31380F66u, 'r'},
    {PMOVZXBQ, OP_XMM0, OP_RM128, 0, 0, 0x32380F66u, 'r'},
    {PMOVZXBW, OP_XMM0, OP_RM128, 0, 0, 0x30380F66u, 'r'},
    {PMOVZXDQ, OP_XMM0, OP_RM128, 0, 0, 0x35380F66u, 'r'},
    {PMOVZXWD, OP_XMM0, OP_RM128, 0, 0, 0x33380F66u, 'r'},
    {PMOVZXWQ, OP_XMM0, OP_RM128, 0, 0, 0x34380F66u, 'r'},

    {PMULDQ, OP_XMM0, OP_RM128, 0, 0, 0x28380F66u, 'r'},
    {PMULHRSW, OP_XMM0, OP_RM128, 0, 0, 0x0B380F66u, 'r'},
    {PMULHUW, OP_XMM0, OP_RM128, 0, 0, 0xE40F66u, 'r'},
    {PMULHW, OP_XMM0, OP_RM128, 0, 0, 0xE50F66u, 'r'},
    {PMULLD, OP_XMM0, OP_RM128, 0, 0, 0x40380F66u, 'r'},
    {PMULLW, OP_XMM0, OP_RM128, 0, 0, 0xD50F66u, 'r'},
    {PMULUDQ, OP_XMM0, OP_RM128, 0, 0, 0xF40F66u, 'r'},

    {POR, OP_XMM0, OP_RM128, 0, 0, 0xEB0F66u, 'r'},
    {PSADBW, OP_XMM0, OP_RM128, 0, 0, 0xF60F66u, 'r'},
    {PSHUFB, OP_XMM0, OP_RM128, 0, 0, 0x00380F66u, 'r'},

    {PSHUFD, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x700F66u, 'r'},
    {PSHUFD, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x700F66u, 'r'},
    {PSHUFLW, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x700FF2u, 'r'},

    {PSIGNB, OP_XMM0, OP_RM128, 0, 0, 0x08380F66u, 'r'},
    {PSIGND, OP_XMM0, OP_RM128, 0, 0, 0x0A380F66u, 'r'},
    {PSIGNW, OP_XMM0, OP_RM128, 0, 0, 0x09380F66u, 'r'},

    {PSLLD, OP_XMM0, OP_RM128, 0, 0, 0xF20F66u, 'r'},
    {PSLLD, OP_XMM0, OP_IMM8, 0, 0, 0x720F66u, '6'},
    {PSLLDQ, OP_XMM0, OP_IMM8, 0, 0, 0x730F66u, '7'},
    {PSLLQ, OP_XMM0, OP_RM128, 0, 0, 0xF30F66u, 'r'},
    {PSLLQ, OP_XMM0, OP_IMM8, 0, 0, 0x730F66u, '6'},
    {PSLLW, OP_XMM0, OP_RM128, 0, 0, 0xF10F66u, 'r'},
    {PSLLW, OP_XMM0, OP_IMM8, 0, 0, 0x710F66u, '6'},

    {PSRAD, OP_XMM0, OP_RM128, 0, 0, 0xE20F66u, 'r'},
    {PSRAD, OP_XMM0, OP_IMM8, 0, 0, 0x720F66u, '4'},
    {PSRAW, OP_XMM0, OP_RM128, 0, 0, 0xE10F66u, 'r'},
    {PSRAW, OP_XMM0, OP_IMM8, 0, 0, 0x710F66u, '4'},

    {PSRLD, OP_XMM0, OP_RM128, 0, 0, 0xD20F66u, 'r'},
    {PSRLD, OP_XMM0, OP_IMM8, 0, 0, 0x720F66u, '2'},
    {PSRLDQ, OP_XMM0, OP_IMM8, 0, 0, 0x730F66u, '3'},
    {PSRLQ, OP_XMM0, OP_RM128, 0, 0, 0xD30F66u, 'r'},
    {PSRLQ, OP_XMM0, OP_IMM8, 0, 0, 0x730F66u, '2'},
    {PSRLW, OP_XMM0, OP_RM128, 0, 0, 0xD10F66u, 'r'},
    {PSRLW, OP_XMM0, OP_IMM8, 0, 0, 0x710F66u, '2'},

    {PSUBB, OP_XMM0, OP_RM128, 0, 0, 0xF80F66u, 'r'},
    {PSUBD, OP_XMM0, OP_RM128, 0, 0, 0xFA0F66u, 'r'},
    {PSUBW, OP_XMM0, OP_RM128, 0, 0, 0xF90F66u, 'r'},
    {PSUBQ, OP_XMM0, OP_RM128, 0, 0, 0xFB0F66u, 'r'},
    {PSUBSW, OP_XMM0, OP_RM128, 0, 0, 0xE90F66u, 'r'},
    {PSUBUSB, OP_XMM0, OP_RM128, 0, 0, 0xD80F66u, 'r'},
    {PSUBUSW, OP_XMM0, OP_RM128, 0, 0, 0xD90F66u, 'r'},

    {PTEST, OP_XMM0, OP_RM128, 0, 0, 0x17380F66u, 'r'},

    {PUNPCKHBW, OP_XMM0, OP_RM128, 0, 0, 0x680F66u, 'r'},
    {PUNPCKHDQ, OP_XMM0, OP_RM128, 0, 0, 0x6A0F66u, 'r'},
    {PUNPCKHQDQ, OP_XMM0, OP_RM128, 0, 0, 0x6D0F66u, 'r'},
    {PUNPCKHWD, OP_XMM0, OP_RM128, 0, 0, 0x690F66u, 'r'},
    {PUNPCKLBW, OP_XMM0, OP_RM128, 0, 0, 0x600F66u, 'r'},
    {PUNPCKLDQ, OP_XMM0, OP_RM128, 0, 0, 0x620F66u, 'r'},
    {PUNPCKLQDQ, OP_XMM0, OP_RM128, 0, 0, 0x6C0F66u, 'r'},
    {PUNPCKLWD, OP_XMM0, OP_RM128, 0, 0, 0x610F66u, 'r'},

    {PXOR, OP_XMM0, OP_RM128, 0, 0, 0xEF0F66u, 'r'},

    {RCPPS, OP_XMM0, OP_RM128, 0, 0, 0x530Fu, 'r'},
    {RCPSS, OP_XMM0, OP_RM128, 0, 0, 0x530FF3u, 'r'},

    {ROUNDPD, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x093A0F66u, 'r'},
    {ROUNDPS, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x083A0F66u, 'r'},
    {ROUNDSD, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x0B3A0F66u, 'r'},
    {ROUNDSS, OP_XMM0, OP_RM128, OP_IMM8, 0, 0x0A3A0F66u, 'r'},

    {RSQRTPS, OP_XMM0, OP_RM128, 0, 0, 0x520Fu, 'r'},
    {RSQRTSS, OP_XMM0, OP_RM128, 0, 0, 0x520FF3u, 'r'},

    {SHUFPD, OP_XMM0, OP_RM128, OP_IMM8, 0, 0xC60F66u, 'r'},
    {SHUFPS, OP_XMM0, OP_RM128, OP_IMM8, 0, 0xC60Fu, 'r'},

    {SQRTPD, OP_XMM0, OP_RM128, 0, 0, 0x510F66u, 'r'},
    {SQRTPS, OP_XMM0, OP_RM128, 0, 0, 0x510Fu, 'r'},
    {SQRTSD, OP_XMM0, OP_RM128, 0, 0, 0x510FF2u, 'r'},
    {SQRTSS, OP_XMM0, OP_RM128, 0, 0, 0x510FF3u, 'r'},

    {SUBPD, OP_XMM0, OP_RM128, 0, 0, 0x5C0F66u, 'r'},
    {SUBPS, OP_XMM0, OP_RM128, 0, 0, 0x5C0Fu, 'r'},
    {SUBSD, OP_XMM0, OP_RM128, 0, 0, 0x5C0FF2u, 'r'},
    {SUBSS, OP_XMM0, OP_RM128, 0, 0, 0x5C0FF3u, 'r'},

    {UCOMISD, OP_XMM0, OP_RM128, 0, 0, 0x2E0F66u, 'r'},
    {UCOMISS, OP_XMM0, OP_RM128, 0, 0, 0x2E0Fu, 'r'},

    {UNPCKHPD, OP_XMM0, OP_RM128, 0, 0, 0x150F66u, 'r'},
    {UNPCKHPS, OP_XMM0, OP_RM128, 0, 0, 0x150Fu, 'r'},
    {UNPCKLPD, OP_XMM0, OP_RM128, 0, 0, 0x140F66u, 'r'},
    {UNPCKLPS, OP_XMM0, OP_RM128, 0, 0, 0x140Fu, 'r'},

    {XORPD, OP_XMM0, OP_RM128, 0, 0, 0x570F66, 'r'},
    {XORPS, OP_XMM0, OP_RM128, 0, 0, 0x570F, 'r'},

    {UNKNOWN, 0, 0, 0, 0, ' '},
};
