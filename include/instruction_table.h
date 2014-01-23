typedef struct opcode_info_t {
    mnemonic_t mnemonic;
    optype_t operand1;
    optype_t operand2;
    optype_t operand3;
    optype_t opcode;
    unsigned char modrm;
    unsigned char norex;
} opcode_info;

opcode_info instructions[] = {
    {ADC, EXACT_AL,  OP_IMM8,  0, 0x14, ' ', 0},
    {ADC, EXACT_AX,  OP_IMM16, 0, 0x15, ' ', 0},
    {ADC, EXACT_EAX, OP_IMM32, 0, 0x15, ' ', 0},
    {ADC, EXACT_RAX, OP_IMM32, 0, 0x15, ' ', 0},

    {ADC, OP_RM8,  OP_IMM8,  0, 0x80, '2', 0},
    {ADC, OP_RM16, OP_IMM16, 0, 0x81, '2', 0},
    {ADC, OP_RM32, OP_IMM32, 0, 0x81, '2', 0},
    {ADC, OP_RM64, OP_IMM32, 0, 0x81, '2', 0},

    {ADC, OP_RM16, OP_IMM8,  0, 0x83, '2', 0},
    {ADC, OP_RM32, OP_IMM8,  0, 0x83, '2', 0},
    {ADC, OP_RM64, OP_IMM8,  0, 0x83, '2', 0},

    {ADC, OP_REG8,  OP_RM8,  0, 0x12, 'r', 0},
    {ADC, OP_REG16, OP_RM16, 0, 0x13, 'r', 0},
    {ADC, OP_REG32, OP_RM32, 0, 0x13, 'r', 0},
    {ADC, OP_REG64, OP_RM64, 0, 0x13, 'r', 0},

    {ADC, OP_RM8,  OP_REG8,  0, 0x10, 'r', 0},
    {ADC, OP_RM16, OP_REG16, 0, 0x11, 'r', 0},
    {ADC, OP_RM32, OP_REG32, 0, 0x11, 'r', 0},
    {ADC, OP_RM64, OP_REG64, 0, 0x11, 'r', 0},

    {ADD, EXACT_AL,  OP_IMM8,  0, 0x04, ' ', 0},
    {ADD, EXACT_AX,  OP_IMM16, 0, 0x05, ' ', 0},
    {ADD, EXACT_EAX, OP_IMM32, 0, 0x05, ' ', 0},
    {ADD, EXACT_RAX, OP_IMM32, 0, 0x05, ' ', 0},

    {ADD, OP_RM8,  OP_IMM8,  0, 0x80, '0', 0},
    {ADD, OP_RM16, OP_IMM16, 0, 0x81, '0', 0},
    {ADD, OP_RM32, OP_IMM32, 0, 0x81, '0', 0},
    {ADD, OP_RM64, OP_IMM32, 0, 0x81, '0', 0},

    {ADD, OP_RM16, OP_IMM8,  0, 0x83, '0', 0},
    {ADD, OP_RM32, OP_IMM8,  0, 0x83, '0', 0},
    {ADD, OP_RM64, OP_IMM8,  0, 0x83, '0', 0},

    {ADD, OP_REG8,  OP_RM8,  0, 0x02, 'r', 0},
    {ADD, OP_REG16, OP_RM16, 0, 0x03, 'r', 0},
    {ADD, OP_REG32, OP_RM32, 0, 0x03, 'r', 0},
    {ADD, OP_REG64, OP_RM64, 0, 0x03, 'r', 0},

    {ADD, OP_RM8,  OP_REG8,  0, 0x00, 'r', 0},
    {ADD, OP_RM16, OP_REG16, 0, 0x01, 'r', 0},
    {ADD, OP_RM32, OP_REG32, 0, 0x01, 'r', 0},
    {ADD, OP_RM64, OP_REG64, 0, 0x01, 'r', 0},

    {AND, EXACT_AL,  OP_IMM8,  0, 0x24, ' ', 0},
    {AND, EXACT_AX,  OP_IMM16, 0, 0x25, ' ', 0},
    {AND, EXACT_EAX, OP_IMM32, 0, 0x25, ' ', 0},
    {AND, EXACT_RAX, OP_IMM32, 0, 0x25, ' ', 0},

    {AND, OP_RM8,  OP_IMM8,  0, 0x80, '4', 0},
    {AND, OP_RM16, OP_IMM16, 0, 0x81, '4', 0},
    {AND, OP_RM32, OP_IMM32, 0, 0x81, '4', 0},
    {AND, OP_RM64, OP_IMM32, 0, 0x81, '4', 0},

    {AND, OP_RM16, OP_IMM8,  0, 0x83, '4', 0},
    {AND, OP_RM32, OP_IMM8,  0, 0x83, '4', 0},
    {AND, OP_RM64, OP_IMM8,  0, 0x83, '4', 0},

    {AND, OP_REG8,  OP_RM8,  0, 0x22, 'r', 0},
    {AND, OP_REG16, OP_RM16, 0, 0x23, 'r', 0},
    {AND, OP_REG32, OP_RM32, 0, 0x23, 'r', 0},
    {AND, OP_REG64, OP_RM64, 0, 0x23, 'r', 0},

    {AND, OP_RM8,  OP_REG8,  0, 0x20, 'r', 0},
    {AND, OP_RM16, OP_REG16, 0, 0x21, 'r', 0},
    {AND, OP_RM32, OP_REG32, 0, 0x21, 'r', 0},
    {AND, OP_RM64, OP_REG64, 0, 0x21, 'r', 0},

    {BSF, OP_REG16, OP_RM16, 0, 0xBC0F, 'r', 0},
    {BSF, OP_REG32, OP_RM32, 0, 0xBC0F, 'r', 0},
    {BSF, OP_REG64, OP_RM64, 0, 0xBC0F, 'r', 0},

    {BSR, OP_REG16, OP_RM16, 0, 0xBD0F, 'r', 0},
    {BSR, OP_REG32, OP_RM32, 0, 0xBD0F, 'r', 0},
    {BSR, OP_REG64, OP_RM64, 0, 0xBD0F, 'r', 0},

    {BSWAP, OP_REG32, 0, 0, 0xC80F, '+', 0},
    {BSWAP, OP_REG64, 0, 0, 0xC80F, '+', 0},

    {BT, OP_RM16, OP_REG16, 0, 0xA30F, 'r', 0},
    {BT, OP_RM32, OP_REG32, 0, 0xA30F, 'r', 0},
    {BT, OP_RM64, OP_REG64, 0, 0xA30F, 'r', 0},

    {BT, OP_RM16, OP_IMM8,  0, 0xBA0F, '4', 0},
    {BT, OP_RM32, OP_IMM8,  0, 0xBA0F, '4', 0},
    {BT, OP_RM64, OP_IMM8,  0, 0xBA0F, '4', 0},

    {BTC, OP_RM16, OP_REG16, 0, 0xBB0F, 'r', 0},
    {BTC, OP_RM32, OP_REG32, 0, 0xBB0F, 'r', 0},
    {BTC, OP_RM64, OP_REG64, 0, 0xBB0F, 'r', 0},

    {BTC, OP_RM16, OP_IMM8,  0, 0xBA0F, '7', 0},
    {BTC, OP_RM32, OP_IMM8,  0, 0xBA0F, '7', 0},
    {BTC, OP_RM64, OP_IMM8,  0, 0xBA0F, '7', 0},

    {BTR, OP_RM16, OP_REG16, 0, 0xB30F, 'r', 0},
    {BTR, OP_RM32, OP_REG32, 0, 0xB30F, 'r', 0},
    {BTR, OP_RM64, OP_REG64, 0, 0xB30F, 'r', 0},

    {BTR, OP_RM16, OP_IMM8,  0, 0xBA0F, '6', 0},
    {BTR, OP_RM32, OP_IMM8,  0, 0xBA0F, '6', 0},
    {BTR, OP_RM64, OP_IMM8,  0, 0xBA0F, '6', 0},

    {BTS, OP_RM16, OP_REG16, 0, 0xAB0F, 'r', 0},
    {BTS, OP_RM32, OP_REG32, 0, 0xAB0F, 'r', 0},
    {BTS, OP_RM64, OP_REG64, 0, 0xAB0F, 'r', 0},

    {BTS, OP_RM16, OP_IMM8,  0, 0xBA0F, '5', 0},
    {BTS, OP_RM32, OP_IMM8,  0, 0xBA0F, '5', 0},
    {BTS, OP_RM64, OP_IMM8,  0, 0xBA0F, '5', 0},

    {CALL, OP_REL32OFF, 0,  0, 0xE8, ' ', 0},
    {CALL, OP_RM64,  0,  0, 0xFF, '2', NO_REX},

    {CBW,  0,  0,  0, 0x9866, ' ', 0},
    {CWDE, 0,  0,  0, 0x98,   ' ', 0},
    {CDQE, 0,  0,  0, 0x9848, ' ', 0},

    {CWD, 0,  0,  0, 0x9966, ' ', 0},
    {CDQ, 0,  0,  0, 0x99,   ' ', 0},
    {CQO, 0,  0,  0, 0x9948, ' ', 0},

    {CLC, 0,  0,  0, 0xF8, ' ', 0},
    {CLD, 0,  0,  0, 0xFC, ' ', 0},

    {CLFLUSH, OP_MEM8,  0,  0, 0xAE0F, '7', 0},

    {CMC, 0,  0,  0, 0xF5, ' ', 0},

    {CMOVO,   OP_REG16, OP_RM16, 0, 0x400F, 'r', 0},
    {CMOVO,   OP_REG32, OP_RM32, 0, 0x400F, 'r', 0},
    {CMOVO,   OP_REG64, OP_RM64, 0, 0x400F, 'r', 0},

    {CMOVNO,  OP_REG16, OP_RM16, 0, 0x410F, 'r', 0},
    {CMOVNO,  OP_REG32, OP_RM32, 0, 0x410F, 'r', 0},
    {CMOVNO,  OP_REG64, OP_RM64, 0, 0x410F, 'r', 0},

    {CMOVB,   OP_REG16, OP_RM16, 0, 0x420F, 'r', 0},
    {CMOVB,   OP_REG32, OP_RM32, 0, 0x420F, 'r', 0},
    {CMOVB,   OP_REG64, OP_RM64, 0, 0x420F, 'r', 0},

    {CMOVC,   OP_REG16, OP_RM16, 0, 0x420F, 'r', 0},
    {CMOVC,   OP_REG32, OP_RM32, 0, 0x420F, 'r', 0},
    {CMOVC,   OP_REG64, OP_RM64, 0, 0x420F, 'r', 0},

    {CMOVNAE, OP_REG16, OP_RM16, 0, 0x420F, 'r', 0},
    {CMOVNAE, OP_REG32, OP_RM32, 0, 0x420F, 'r', 0},
    {CMOVNAE, OP_REG64, OP_RM64, 0, 0x420F, 'r', 0},

    {CMOVNB,  OP_REG16, OP_RM16, 0, 0x430F, 'r', 0},
    {CMOVNB,  OP_REG32, OP_RM32, 0, 0x430F, 'r', 0},
    {CMOVNB,  OP_REG64, OP_RM64, 0, 0x430F, 'r', 0},

    {CMOVNC,  OP_REG16, OP_RM16, 0, 0x430F, 'r', 0},
    {CMOVNC,  OP_REG32, OP_RM32, 0, 0x430F, 'r', 0},
    {CMOVNC,  OP_REG64, OP_RM64, 0, 0x430F, 'r', 0},

    {CMOVAE,  OP_REG16, OP_RM16, 0, 0x430F, 'r', 0},
    {CMOVAE,  OP_REG32, OP_RM32, 0, 0x430F, 'r', 0},
    {CMOVAE,  OP_REG64, OP_RM64, 0, 0x430F, 'r', 0},

    {CMOVZ,   OP_REG16, OP_RM16, 0, 0x440F, 'r', 0},
    {CMOVZ,   OP_REG32, OP_RM32, 0, 0x440F, 'r', 0},
    {CMOVZ,   OP_REG64, OP_RM64, 0, 0x440F, 'r', 0},

    {CMOVE,   OP_REG16, OP_RM16, 0, 0x440F, 'r', 0},
    {CMOVE,   OP_REG32, OP_RM32, 0, 0x440F, 'r', 0},
    {CMOVE,   OP_REG64, OP_RM64, 0, 0x440F, 'r', 0},

    {CMOVNZ,  OP_REG16, OP_RM16, 0, 0x450F, 'r', 0},
    {CMOVNZ,  OP_REG32, OP_RM32, 0, 0x450F, 'r', 0},
    {CMOVNZ,  OP_REG64, OP_RM64, 0, 0x450F, 'r', 0},

    {CMOVNE,  OP_REG16, OP_RM16, 0, 0x450F, 'r', 0},
    {CMOVNE,  OP_REG32, OP_RM32, 0, 0x450F, 'r', 0},
    {CMOVNE,  OP_REG64, OP_RM64, 0, 0x450F, 'r', 0},

    {CMOVBE,  OP_REG16, OP_RM16, 0, 0x460F, 'r', 0},
    {CMOVBE,  OP_REG32, OP_RM32, 0, 0x460F, 'r', 0},
    {CMOVBE,  OP_REG64, OP_RM64, 0, 0x460F, 'r', 0},

    {CMOVNA,  OP_REG16, OP_RM16, 0, 0x460F, 'r', 0},
    {CMOVNA,  OP_REG32, OP_RM32, 0, 0x460F, 'r', 0},
    {CMOVNA,  OP_REG64, OP_RM64, 0, 0x460F, 'r', 0},

    {CMOVNBE, OP_REG16, OP_RM16, 0, 0x470F, 'r', 0},
    {CMOVNBE, OP_REG32, OP_RM32, 0, 0x470F, 'r', 0},
    {CMOVNBE, OP_REG64, OP_RM64, 0, 0x470F, 'r', 0},

    {CMOVA,   OP_REG16, OP_RM16, 0, 0x470F, 'r', 0},
    {CMOVA,   OP_REG32, OP_RM32, 0, 0x470F, 'r', 0},
    {CMOVA,   OP_REG64, OP_RM64, 0, 0x470F, 'r', 0},

    {CMOVS,   OP_REG16, OP_RM16, 0, 0x480F, 'r', 0},
    {CMOVS,   OP_REG32, OP_RM32, 0, 0x480F, 'r', 0},
    {CMOVS,   OP_REG64, OP_RM64, 0, 0x480F, 'r', 0},

    {CMOVNS,  OP_REG16, OP_RM16, 0, 0x490F, 'r', 0},
    {CMOVNS,  OP_REG32, OP_RM32, 0, 0x490F, 'r', 0},
    {CMOVNS,  OP_REG64, OP_RM64, 0, 0x490F, 'r', 0},

    {CMOVP,   OP_REG16, OP_RM16, 0, 0x4A0F, 'r', 0},
    {CMOVP,   OP_REG32, OP_RM32, 0, 0x4A0F, 'r', 0},
    {CMOVP,   OP_REG64, OP_RM64, 0, 0x4A0F, 'r', 0},

    {CMOVPE,  OP_REG16, OP_RM16, 0, 0x4A0F, 'r', 0},
    {CMOVPE,  OP_REG32, OP_RM32, 0, 0x4A0F, 'r', 0},
    {CMOVPE,  OP_REG64, OP_RM64, 0, 0x4A0F, 'r', 0},

    {CMOVNP,  OP_REG16, OP_RM16, 0, 0x4B0F, 'r', 0},
    {CMOVNP,  OP_REG32, OP_RM32, 0, 0x4B0F, 'r', 0},
    {CMOVNP,  OP_REG64, OP_RM64, 0, 0x4B0F, 'r', 0},

    {CMOVPO,  OP_REG16, OP_RM16, 0, 0x4B0F, 'r', 0},
    {CMOVPO,  OP_REG32, OP_RM32, 0, 0x4B0F, 'r', 0},
    {CMOVPO,  OP_REG64, OP_RM64, 0, 0x4B0F, 'r', 0},

    {CMOVL,   OP_REG16, OP_RM16, 0, 0x4C0F, 'r', 0},
    {CMOVL,   OP_REG32, OP_RM32, 0, 0x4C0F, 'r', 0},
    {CMOVL,   OP_REG64, OP_RM64, 0, 0x4C0F, 'r', 0},

    {CMOVNGE, OP_REG16, OP_RM16, 0, 0x4C0F, 'r', 0},
    {CMOVNGE, OP_REG32, OP_RM32, 0, 0x4C0F, 'r', 0},
    {CMOVNGE, OP_REG64, OP_RM64, 0, 0x4C0F, 'r', 0},

    {CMOVNL,  OP_REG16, OP_RM16, 0, 0x4D0F, 'r', 0},
    {CMOVNL,  OP_REG32, OP_RM32, 0, 0x4D0F, 'r', 0},
    {CMOVNL,  OP_REG64, OP_RM64, 0, 0x4D0F, 'r', 0},

    {CMOVGE,  OP_REG16, OP_RM16, 0, 0x4D0F, 'r', 0},
    {CMOVGE,  OP_REG32, OP_RM32, 0, 0x4D0F, 'r', 0},
    {CMOVGE,  OP_REG64, OP_RM64, 0, 0x4D0F, 'r', 0},

    {CMOVLE,  OP_REG16, OP_RM16, 0, 0x4E0F, 'r', 0},
    {CMOVLE,  OP_REG32, OP_RM32, 0, 0x4E0F, 'r', 0},
    {CMOVLE,  OP_REG64, OP_RM64, 0, 0x4E0F, 'r', 0},

    {CMOVNG,  OP_REG16, OP_RM16, 0, 0x4E0F, 'r', 0},
    {CMOVNG,  OP_REG32, OP_RM32, 0, 0x4E0F, 'r', 0},
    {CMOVNG,  OP_REG64, OP_RM64, 0, 0x4E0F, 'r', 0},

    {CMOVNLE, OP_REG16, OP_RM16, 0, 0x4F0F, 'r', 0},
    {CMOVNLE, OP_REG32, OP_RM32, 0, 0x4F0F, 'r', 0},
    {CMOVNLE, OP_REG64, OP_RM64, 0, 0x4F0F, 'r', 0},

    {CMOVG,   OP_REG16, OP_RM16, 0, 0x4F0F, 'r', 0},
    {CMOVG,   OP_REG32, OP_RM32, 0, 0x4F0F, 'r', 0},
    {CMOVG,   OP_REG64, OP_RM64, 0, 0x4F0F, 'r', 0},

    {CMP, EXACT_AL,  OP_IMM8,  0, 0x3C, ' ', 0},
    {CMP, EXACT_AX,  OP_IMM16, 0, 0x3D, ' ', 0},
    {CMP, EXACT_EAX, OP_IMM32, 0, 0x3D, ' ', 0},
    {CMP, EXACT_RAX, OP_IMM32, 0, 0x3D, ' ', 0},

    {CMP, OP_RM8,  OP_IMM8,  0, 0x80, '7', 0},
    {CMP, OP_RM16, OP_IMM16, 0, 0x81, '7', 0},
    {CMP, OP_RM32, OP_IMM32, 0, 0x81, '7', 0},
    {CMP, OP_RM64, OP_IMM32, 0, 0x81, '7', 0},

    {CMP, OP_RM16, OP_IMM8,  0, 0x83, '7', 0},
    {CMP, OP_RM32, OP_IMM8,  0, 0x83, '7', 0},
    {CMP, OP_RM64, OP_IMM8,  0, 0x83, '7', 0},

    {CMP, OP_REG8,  OP_RM8,  0, 0x3A, 'r', 0},
    {CMP, OP_REG16, OP_RM16, 0, 0x3B, 'r', 0},
    {CMP, OP_REG32, OP_RM32, 0, 0x3B, 'r', 0},
    {CMP, OP_REG64, OP_RM64, 0, 0x3B, 'r', 0},

    {CMP, OP_RM8,  OP_REG8,  0, 0x38, 'r', 0},
    {CMP, OP_RM16, OP_REG16, 0, 0x39, 'r', 0},
    {CMP, OP_RM32, OP_REG32, 0, 0x39, 'r', 0},
    {CMP, OP_RM64, OP_REG64, 0, 0x39, 'r', 0},

    {CMPSB, 0, 0, 0, 0xA6,   ' ', 0},
    {CMPSW, 0, 0, 0, 0xA766, ' ', 0},
    {CMPSD, 0, 0, 0, 0xA7,   ' ', 0},
    {CMPSQ, 0, 0, 0, 0xA748, ' ', 0},

    {CMPXCHG, OP_RM8,  OP_REG8,  0, 0xB00F, 'r', 0},
    {CMPXCHG, OP_RM16, OP_REG16, 0, 0xB10F, 'r', 0},
    {CMPXCHG, OP_RM32, OP_REG32, 0, 0xB10F, 'r', 0},
    {CMPXCHG, OP_RM64, OP_REG64, 0, 0xB10F, 'r', 0},

    {CMPXCHG8B, OP_MEM64, 0, 0, 0xC70F, '1', NO_REX},
    {CMPXCHG16B, OP_MEM128, 0, 0, 0xC70F48, '1', NO_REX},

    {CPUID, 0, 0, 0, 0xA20F, ' ', 0},

    {DEC, OP_RM8,  0, 0, 0xFE, '1', 0},
    {DEC, OP_RM16, 0, 0, 0xFF, '1', 0},
    {DEC, OP_RM32, 0, 0, 0xFF, '1', 0},
    {DEC, OP_RM64, 0, 0, 0xFF, '1', 0},

    {DIV, OP_RM8,  0, 0, 0xF6, '6', 0},
    {DIV, OP_RM16, 0, 0, 0xF7, '6', 0},
    {DIV, OP_RM32, 0, 0, 0xF7, '6', 0},
    {DIV, OP_RM64, 0, 0, 0xF7, '6', 0},

    {ENTER, OP_IMM16, OP_IMM8, 0, 0xC8, ' ', 0},

    {IDIV, OP_RM8,  0, 0, 0xF6, '7', 0},
    {IDIV, OP_RM16, 0, 0, 0xF7, '7', 0},
    {IDIV, OP_RM32, 0, 0, 0xF7, '7', 0},
    {IDIV, OP_RM64, 0, 0, 0xF7, '7', 0},

    {IMUL, OP_RM8, 0, 0, 0xF6, '5', 0},
    {IMUL, OP_RM16, 0, 0, 0xF7, '5', 0},
    {IMUL, OP_RM32, 0, 0, 0xF7, '5', 0},
    {IMUL, OP_RM64, 0, 0, 0xF7, '5', 0},
    {IMUL, OP_REG16, OP_RM16, 0, 0xAF0F, 'r', 0},
    {IMUL, OP_REG32, OP_RM32, 0, 0xAF0F, 'r', 0},
    {IMUL, OP_REG64, OP_RM64, 0, 0xAF0F, 'r', 0},
    {IMUL, OP_REG16, OP_RM16, OP_IMM8, 0x6B, 'r', 0},
    {IMUL, OP_REG32, OP_RM32, OP_IMM8, 0x6B, 'r', 0},
    {IMUL, OP_REG64, OP_RM64, OP_IMM8, 0x6B, 'r', 0},
    {IMUL, OP_REG16, OP_RM16, OP_IMM16, 0x69, 'r', 0},
    {IMUL, OP_REG32, OP_RM32, OP_IMM32, 0x69, 'r', 0},
    {IMUL, OP_REG64, OP_RM64, OP_IMM32, 0x69, 'r', 0},

    {INC, OP_RM8,  0, 0, 0xFE, '0', 0},
    {INC, OP_RM16, 0, 0, 0xFF, '0', 0},
    {INC, OP_RM32, 0, 0, 0xFF, '0', 0},
    {INC, OP_RM64, 0, 0, 0xFF, '0', 0},

    {INT, OP_IMM8, 0, 0, 0xCD, ' ', 0},

    {INTO, 0, 0, 0, 0xCE, ' ', 0},

    {JO,   OP_REL32OFF, 0, 0, 0x800F, ' ', 0},
    {JNO,  OP_REL32OFF, 0, 0, 0x810F, ' ', 0},
    {JB,   OP_REL32OFF, 0, 0, 0x820F, ' ', 0},
    {JC,   OP_REL32OFF, 0, 0, 0x820F, ' ', 0},
    {JNAE, OP_REL32OFF, 0, 0, 0x820F, ' ', 0},
    {JNB,  OP_REL32OFF, 0, 0, 0x830F, ' ', 0},
    {JNC,  OP_REL32OFF, 0, 0, 0x830F, ' ', 0},
    {JAE,  OP_REL32OFF, 0, 0, 0x830F, ' ', 0},
    {JZ,   OP_REL32OFF, 0, 0, 0x840F, ' ', 0},
    {JE,   OP_REL32OFF, 0, 0, 0x840F, ' ', 0},
    {JNZ,  OP_REL32OFF, 0, 0, 0x850F, ' ', 0},
    {JNE,  OP_REL32OFF, 0, 0, 0x850F, ' ', 0},
    {JBE,  OP_REL32OFF, 0, 0, 0x860F, ' ', 0},
    {JNA,  OP_REL32OFF, 0, 0, 0x860F, ' ', 0},
    {JNBE, OP_REL32OFF, 0, 0, 0x870F, ' ', 0},
    {JA,   OP_REL32OFF, 0, 0, 0x870F, ' ', 0},
    {JS,   OP_REL32OFF, 0, 0, 0x880F, ' ', 0},
    {JNS,  OP_REL32OFF, 0, 0, 0x890F, ' ', 0},
    {JP,   OP_REL32OFF, 0, 0, 0x8A0F, ' ', 0},
    {JPE,  OP_REL32OFF, 0, 0, 0x8A0F, ' ', 0},
    {JNP,  OP_REL32OFF, 0, 0, 0x8B0F, ' ', 0},
    {JPO,  OP_REL32OFF, 0, 0, 0x8B0F, ' ', 0},
    {JL,   OP_REL32OFF, 0, 0, 0x8C0F, ' ', 0},
    {JNGE, OP_REL32OFF, 0, 0, 0x8C0F, ' ', 0},
    {JNL,  OP_REL32OFF, 0, 0, 0x8D0F, ' ', 0},
    {JGE,  OP_REL32OFF, 0, 0, 0x8D0F, ' ', 0},
    {JLE,  OP_REL32OFF, 0, 0, 0x8E0F, ' ', 0},
    {JNG,  OP_REL32OFF, 0, 0, 0x8E0F, ' ', 0},
    {JNLE, OP_REL32OFF, 0, 0, 0x8F0F, ' ', 0},
    {JG,   OP_REL32OFF, 0, 0, 0x8F0F, ' ', 0},

    {JO,   OP_REL8OFF, 0, 0, 0x70, ' ', 0},
    {JNO,  OP_REL8OFF, 0, 0, 0x71, ' ', 0},
    {JB,   OP_REL8OFF, 0, 0, 0x72, ' ', 0},
    {JC,   OP_REL8OFF, 0, 0, 0x72, ' ', 0},
    {JNAE, OP_REL8OFF, 0, 0, 0x72, ' ', 0},
    {JNB,  OP_REL8OFF, 0, 0, 0x73, ' ', 0},
    {JNC,  OP_REL8OFF, 0, 0, 0x73, ' ', 0},
    {JAE,  OP_REL8OFF, 0, 0, 0x73, ' ', 0},
    {JZ,   OP_REL8OFF, 0, 0, 0x74, ' ', 0},
    {JE,   OP_REL8OFF, 0, 0, 0x74, ' ', 0},
    {JNZ,  OP_REL8OFF, 0, 0, 0x75, ' ', 0},
    {JNE,  OP_REL8OFF, 0, 0, 0x75, ' ', 0},
    {JBE,  OP_REL8OFF, 0, 0, 0x76, ' ', 0},
    {JNA,  OP_REL8OFF, 0, 0, 0x76, ' ', 0},
    {JNBE, OP_REL8OFF, 0, 0, 0x77, ' ', 0},
    {JA,   OP_REL8OFF, 0, 0, 0x77, ' ', 0},
    {JS,   OP_REL8OFF, 0, 0, 0x78, ' ', 0},
    {JNS,  OP_REL8OFF, 0, 0, 0x79, ' ', 0},
    {JP,   OP_REL8OFF, 0, 0, 0x7A, ' ', 0},
    {JPE,  OP_REL8OFF, 0, 0, 0x7A, ' ', 0},
    {JNP,  OP_REL8OFF, 0, 0, 0x7B, ' ', 0},
    {JPO,  OP_REL8OFF, 0, 0, 0x7B, ' ', 0},
    {JL,   OP_REL8OFF, 0, 0, 0x7C, ' ', 0},
    {JNGE, OP_REL8OFF, 0, 0, 0x7C, ' ', 0},
    {JNL,  OP_REL8OFF, 0, 0, 0x7D, ' ', 0},
    {JGE,  OP_REL8OFF, 0, 0, 0x7D, ' ', 0},
    {JLE,  OP_REL8OFF, 0, 0, 0x7E, ' ', 0},
    {JNG,  OP_REL8OFF, 0, 0, 0x7E, ' ', 0},
    {JNLE, OP_REL8OFF, 0, 0, 0x7F, ' ', 0},
    {JG,   OP_REL8OFF, 0, 0, 0x7F, ' ', 0},

    {JRCXZ, OP_REL8OFF, 0, 0, 0xE3, ' ', 0},

    {JMP, OP_REL8OFF, 0, 0, 0xEB, ' ', 0},
    {JMP, OP_REL32OFF, 0, 0, 0xE9, ' ', 0},
    {JMP, OP_RM64, 0, 0, 0xFF, '4', NO_REX},

    {LAHF, 0, 0, 0, 0x9F, ' ', 0},

    {LEA, OP_REG16, OP_MEM16, 0, 0x8D, 'r', 0},
    {LEA, OP_REG32, OP_MEM32, 0, 0x8D, 'r', 0},
    {LEA, OP_REG64, OP_MEM64, 0, 0x8D, 'r', 0},

    {LEAVE, 0, 0, 0, 0xC9, ' ', 0},

    {LFENCE, 0, 0, 0, 0xE8AE0F, ' ', 0},

    {LODSB, 0, 0, 0, 0xAC, ' ', 0},
    {LODSW, 0, 0, 0, 0xAD66, ' ', 0},
    {LODSD, 0, 0, 0, 0xAD, ' ', 0},
    {LODSQ, 0, 0, 0, 0xAD48, ' ', 0},

    {LOOP, OP_REL8OFF, 0, 0, 0xE2, ' ', 0},
    {LOOPE, OP_REL8OFF, 0, 0, 0xE1, ' ', 0},
    {LOOPZ, OP_REL8OFF, 0, 0, 0xE1, ' ', 0},
    {LOOPNE, OP_REL8OFF, 0, 0, 0xE0, ' ', 0},
    {LOOPNZ, OP_REL8OFF, 0, 0, 0xE0, ' ', 0},

    {LZCNT, OP_REG16, OP_RM16, 0, 0xBD0FF3, 'r', 0},
    {LZCNT, OP_REG32, OP_RM32, 0, 0xBD0FF3, 'r', 0},
    {LZCNT, OP_REG64, OP_RM64, 0, 0xBD0FF3, 'r', 0},

    {MFENCE, 0, 0, 0, 0xF0AE0F, ' ', 0},

    {MOV, OP_RM8, OP_REG8, 0, 0x88, 'r', 0},
    {MOV, OP_RM16, OP_REG16, 0, 0x89, 'r', 0},
    {MOV, OP_RM32, OP_REG32, 0, 0x89, 'r', 0},
    {MOV, OP_RM64, OP_REG64, 0, 0x89, 'r', 0},

    {MOV, OP_REG8, OP_RM8, 0, 0x8A, 'r', 0},
    {MOV, OP_REG16, OP_RM16, 0, 0x8B, 'r', 0},
    {MOV, OP_REG32, OP_RM32, 0, 0x8B, 'r', 0},
    {MOV, OP_REG64, OP_RM64, 0, 0x8B, 'r', 0},

    {MOV, EXACT_AL,  OP_MOFFSET8,  0, 0xA0, ' ', 0},
    {MOV, EXACT_AX,  OP_MOFFSET16, 0, 0xA1, ' ', 0},
    {MOV, EXACT_EAX, OP_MOFFSET32, 0, 0xA1, ' ', 0},
    {MOV, EXACT_RAX, OP_MOFFSET64, 0, 0xA1, ' ', 0},

    {MOV, OP_MOFFSET8, EXACT_AL, 0, 0xA2, ' ', 0},
    {MOV, OP_MOFFSET16, EXACT_AX, 0, 0xA3, ' ', 0},
    {MOV, OP_MOFFSET32, EXACT_EAX, 0, 0xA3, ' ', 0},
    {MOV, OP_MOFFSET64, EXACT_RAX, 0, 0xA3, ' ', 0},

    {MOV, OP_REG8, OP_IMM8, 0, 0xB0, '+', 0},
    {MOV, OP_REG16, OP_IMM16, 0, 0xB8, '+', 0},
    {MOV, OP_REG32, OP_IMM32, 0, 0xB8, '+', 0},
    {MOV, OP_REG64, OP_IMM64, 0, 0xB8, '+', 0},

    {MOV, OP_RM8, OP_IMM8, 0, 0xC6, '0', 0},
    {MOV, OP_RM16, OP_IMM16, 0, 0xC7, '0', 0},
    {MOV, OP_RM32, OP_IMM32, 0, 0xC7, '0', 0},
    {MOV, OP_RM64, OP_IMM32, 0, 0xC7, '0', 0},

    {MOVBE, OP_REG16, OP_MEM16, 0, 0xF0380F, 'r', 0},
    {MOVBE, OP_REG32, OP_MEM32, 0, 0xF0380F, 'r', 0},
    {MOVBE, OP_REG64, OP_MEM64, 0, 0xF0380F, 'r', 0},
    {MOVBE, OP_MEM16, OP_REG16, 0, 0xF1380F, 'r', 0},
    {MOVBE, OP_MEM32, OP_REG32, 0, 0xF1380F, 'r', 0},
    {MOVBE, OP_MEM64, OP_REG64, 0, 0xF1380F, 'r', 0},

    {MOVD, OP_XMM0, OP_RM32, 0, 0x6E0F66, 'r', 0},
    {MOVQ, OP_XMM0, OP_RM64, 0, 0x6E0F66, 'r', 0},
    {MOVD, OP_RM32, OP_XMM0, 0, 0x7E0F66, 'r', 0},
    {MOVQ, OP_RM64, OP_XMM0, 0, 0x7E0F66, 'r', 0},

    {MOVMSKPD, OP_REG32, OP_XMM0, 0, 0x500F66, 'r', 0},
    {MOVMSKPS, OP_REG32, OP_XMM0, 0, 0x500F, 'r', 0},

    {MOVNTI, OP_MEM32, OP_REG32, 0, 0xC30F, 'r', 0},
    {MOVNTI, OP_MEM64, OP_REG64, 0, 0xC30F, 'r', 0},

    {MOVSB, 0, 0, 0, 0xA4, ' ', 0},
    {MOVSW, 0, 0, 0, 0xA5, ' ', 0},
    {MOVSD, 0, 0, 0, 0xA5, ' ', 0},
    {MOVSQ, 0, 0, 0, 0xA5, ' ', 0},

    {MOVSX, OP_REG16, OP_RM8, 0, 0xBE0F, 'r', 0},
    {MOVSX, OP_REG32, OP_RM8, 0, 0xBE0F, 'r', 0},
    {MOVSX, OP_REG64, OP_RM8, 0, 0xBE0F, 'r', 0},
    //~ {MOVSX, OP_REG32, OP_RM16, 0, 0xBF0F, 'r', 0},
    {MOVSX, OP_REG64, OP_RM16, 0, 0xBF0F, 'r', 0},

    {MOVSXD, OP_REG64, OP_RM32, 0, 0x63, 'r', 0},

    {MOVZX, OP_REG16, OP_RM8, 0, 0xB60F, 'r', 0},
    {MOVZX, OP_REG32, OP_RM8, 0, 0xB60F, 'r', 0},
    {MOVZX, OP_REG64, OP_RM8, 0, 0xB60F, 'r', 0},

    {MUL, OP_RM8, 0, 0, 0xF6, '4', 0},
    {MUL, OP_RM16, 0, 0, 0xF7, '4', 0},
    {MUL, OP_RM32, 0, 0, 0xF7, '4', 0},
    {MUL, OP_RM64, 0, 0, 0xF7, '4', 0},

    {NEG, OP_RM8, 0, 0, 0xF6, '3', 0},
    {NEG, OP_RM16, 0, 0, 0xF7, '3', 0},
    {NEG, OP_RM32, 0, 0, 0xF7, '3', 0},
    {NEG, OP_RM64, 0, 0, 0xF7, '3', 0},

    {NOP, 0, 0, 0, 0x90, ' ', 0},

    {NOT, OP_RM8, 0, 0, 0xF6, '2', 0},
    {NOT, OP_RM16, 0, 0, 0xF7, '2', 0},
    {NOT, OP_RM32, 0, 0, 0xF7, '2', 0},
    {NOT, OP_RM64, 0, 0, 0xF7, '2', 0},

    {OR, EXACT_AL,  OP_IMM8,  0, 0x0C, ' ', 0},
    {OR, EXACT_AX,  OP_IMM16, 0, 0x0D, ' ', 0},
    {OR, EXACT_EAX, OP_IMM32, 0, 0x0D, ' ', 0},
    {OR, EXACT_RAX, OP_IMM32, 0, 0x0D, ' ', 0},

    {OR, OP_RM8,  OP_IMM8,  0, 0x80, '1', 0},
    {OR, OP_RM16, OP_IMM16, 0, 0x81, '1', 0},
    {OR, OP_RM32, OP_IMM32, 0, 0x81, '1', 0},
    {OR, OP_RM64, OP_IMM32, 0, 0x81, '1', 0},

    {OR, OP_RM16, OP_IMM8,  0, 0x83, '1', 0},
    {OR, OP_RM32, OP_IMM8,  0, 0x83, '1', 0},
    {OR, OP_RM64, OP_IMM8,  0, 0x83, '1', 0},

    {OR, OP_REG8,  OP_RM8,  0, 0x0A, 'r', 0},
    {OR, OP_REG16, OP_RM16, 0, 0x0B, 'r', 0},
    {OR, OP_REG32, OP_RM32, 0, 0x0B, 'r', 0},
    {OR, OP_REG64, OP_RM64, 0, 0x0B, 'r', 0},

    {OR, OP_RM8,  OP_REG8,  0, 0x08, 'r', 0},
    {OR, OP_RM16, OP_REG16, 0, 0x09, 'r', 0},
    {OR, OP_RM32, OP_REG32, 0, 0x09, 'r', 0},
    {OR, OP_RM64, OP_REG64, 0, 0x09, 'r', 0},

    {PAUSE, 0, 0, 0, 0x90F3, ' ', 0},

    {POP, OP_REG16, 0, 0, 0x58, '+', NO_REX},
    {POP, OP_REG64, 0, 0, 0x58, '+', NO_REX},

    {POP, OP_RM16, 0, 0, 0x8F, '0', NO_REX},
    {POP, OP_RM64, 0, 0, 0x8F, '0', NO_REX},

    {POPCNT, OP_REG16, OP_RM16, 0, 0xB80FF3, 'r', 0},
    {POPCNT, OP_REG32, OP_RM32, 0, 0xB80FF3, 'r', 0},
    {POPCNT, OP_REG64, OP_RM64, 0, 0xB80FF3, 'r', 0},

    {POPF, 0, 0, 0, 0x9D, ' ', 0},

    {PREFETCH, OP_MEM8, 0, 0, 0x0D0F, '0', 0},
    {PREFETCHW, OP_MEM8, 0, 0, 0x0D0F, '1', 0},

    {PREFETCHNTA, OP_MEM8, 0, 0, 0x180F, '0', 0},
    {PREFETCH0, OP_MEM8, 0, 0, 0x180F, '1', 0},
    {PREFETCH1, OP_MEM8, 0, 0, 0x180F, '2', 0},
    {PREFETCH2, OP_MEM8, 0, 0, 0x180F, '3', 0},

    {PUSH, OP_REG16, 0, 0, 0x50, '+', NO_REX},
    {PUSH, OP_REG64, 0, 0, 0x50, '+', NO_REX},

    {PUSH, OP_RM16, 0, 0, 0xFF, '6', NO_REX},
    {PUSH, OP_RM64, 0, 0, 0xFF, '6', NO_REX},

    {PUSH, OP_IMM8, 0, 0, 0x6A, ' ', NO_REX},
    {PUSH, OP_IMM16, 0, 0, 0x68, ' ', NO_REX},
    {PUSH, OP_IMM32, 0, 0, 0x68, ' ', NO_REX},

    {PUSHF, 0, 0, 0, 0x9C, ' ', 0},

    {RCL, OP_RM8, 0, 0, 0xD0, '2', 0},
    {RCL, OP_RM8, 0, 0, 0xD2, '2', 0},
    {RCL, OP_RM8, OP_IMM8, 0, 0xC0, '2', 0},

    {RCL, OP_RM16, 0, 0, 0xD1, '2', 0},
    {RCL, OP_RM16, 0, 0, 0xD3, '2', 0},
    {RCL, OP_RM16, OP_IMM8, 0, 0xC1, '2', 0},

    {RCL, OP_RM32, 0, 0, 0xD1, '2', 0},
    {RCL, OP_RM32, 0, 0, 0xD3, '2', 0},
    {RCL, OP_RM32, OP_IMM8, 0, 0xC1, '2', 0},

    {RCL, OP_RM64, 0, 0, 0xD1, '2', 0},
    {RCL, OP_RM64, 0, 0, 0xD3, '2', 0},
    {RCL, OP_RM64, OP_IMM8, 0, 0xC1, '2', 0},

    {RCR, OP_RM8, 0, 0, 0xD0, '3', 0},
    {RCR, OP_RM8, 0, 0, 0xD2, '3', 0},
    {RCR, OP_RM8, OP_IMM8, 0, 0xC0, '3', 0},

    {RCR, OP_RM16, 0, 0, 0xD1, '3', 0},
    {RCR, OP_RM16, 0, 0, 0xD3, '3', 0},
    {RCR, OP_RM16, OP_IMM8, 0, 0xC1, '3', 0},

    {RCR, OP_RM32, 0, 0, 0xD1, '3', 0},
    {RCR, OP_RM32, 0, 0, 0xD3, '3', 0},
    {RCR, OP_RM32, OP_IMM8, 0, 0xC1, '3', 0},

    {RCR, OP_RM64, 0, 0, 0xD1, '3', 0},
    {RCR, OP_RM64, 0, 0, 0xD3, '3', 0},
    {RCR, OP_RM64, OP_IMM8, 0, 0xC1, '3', 0},

    {RET, OP_IMM16, 0, 0, 0xC2, ' ', 0},
    {RET, 0, 0, 0, 0xC3, ' ', 0},

    {ROL, OP_RM8, 0, 0, 0xD0, '0', 0},
    {ROL, OP_RM8, 0, 0, 0xD2, '0', 0},
    {ROL, OP_RM8, OP_IMM8, 0, 0xC0, '0', 0},

    {ROL, OP_RM16, 0, 0, 0xD1, '0', 0},
    {ROL, OP_RM16, 0, 0, 0xD3, '0', 0},
    {ROL, OP_RM16, OP_IMM8, 0, 0xC1, '0', 0},

    {ROL, OP_RM32, 0, 0, 0xD1, '0', 0},
    {ROL, OP_RM32, 0, 0, 0xD3, '0', 0},
    {ROL, OP_RM32, OP_IMM8, 0, 0xC1, '0', 0},

    {ROL, OP_RM64, 0, 0, 0xD1, '0', 0},
    {ROL, OP_RM64, 0, 0, 0xD3, '0', 0},
    {ROL, OP_RM64, OP_IMM8, 0, 0xC1, '0', 0},

    {ROR, OP_RM8, 0, 0, 0xD0, '1', 0},
    {ROR, OP_RM8, 0, 0, 0xD2, '1', 0},
    {ROR, OP_RM8, OP_IMM8, 0, 0xC0, '1', 0},

    {ROR, OP_RM16, 0, 0, 0xD1, '1', 0},
    {ROR, OP_RM16, 0, 0, 0xD3, '1', 0},
    {ROR, OP_RM16, OP_IMM8, 0, 0xC1, '1', 0},

    {ROR, OP_RM32, 0, 0, 0xD1, '1', 0},
    {ROR, OP_RM32, 0, 0, 0xD3, '1', 0},
    {ROR, OP_RM32, OP_IMM8, 0, 0xC1, '1', 0},

    {ROR, OP_RM64, 0, 0, 0xD1, '1', 0},
    {ROR, OP_RM64, 0, 0, 0xD3, '1', 0},
    {ROR, OP_RM64, OP_IMM8, 0, 0xC1, '1', 0},

    {SAHF, 0, 0, 0, 0x9E, ' ', 0},

    {SHL, OP_RM8, 0, 0, 0xD0, '4', 0},
    {SHL, OP_RM8, 0, 0, 0xD2, '4', 0},
    {SHL, OP_RM8, OP_IMM8, 0, 0xC0, '4', 0},

    {SHL, OP_RM16, 0, 0, 0xD1, '4', 0},
    {SHL, OP_RM16, 0, 0, 0xD3, '4', 0},
    {SHL, OP_RM16, OP_IMM8, 0, 0xC1, '4', 0},

    {SHL, OP_RM32, 0, 0, 0xD1, '4', 0},
    {SHL, OP_RM32, 0, 0, 0xD3, '4', 0},
    {SHL, OP_RM32, OP_IMM8, 0, 0xC1, '4', 0},

    {SHL, OP_RM64, 0, 0, 0xD1, '4', 0},
    {SHL, OP_RM64, 0, 0, 0xD3, '4', 0},
    {SHL, OP_RM64, OP_IMM8, 0, 0xC1, '4', 0},

    {SAR, OP_RM8, 0, 0, 0xD0, '7', 0},
    {SAR, OP_RM8, 0, 0, 0xD2, '7', 0},
    {SAR, OP_RM8, OP_IMM8, 0, 0xC0, '7', 0},

    {SAR, OP_RM16, 0, 0, 0xD1, '7', 0},
    {SAR, OP_RM16, 0, 0, 0xD3, '7', 0},
    {SAR, OP_RM16, OP_IMM8, 0, 0xC1, '7', 0},

    {SAR, OP_RM32, 0, 0, 0xD1, '7', 0},
    {SAR, OP_RM32, 0, 0, 0xD3, '7', 0},
    {SAR, OP_RM32, OP_IMM8, 0, 0xC1, '7', 0},

    {SAR, OP_RM64, 0, 0, 0xD1, '7', 0},
    {SAR, OP_RM64, 0, 0, 0xD3, '7', 0},
    {SAR, OP_RM64, OP_IMM8, 0, 0xC1, '7', 0},

    {SBB, EXACT_AL,  OP_IMM8,  0, 0x1C, ' ', 0},
    {SBB, EXACT_AX,  OP_IMM16, 0, 0x1D, ' ', 0},
    {SBB, EXACT_EAX, OP_IMM32, 0, 0x1D, ' ', 0},
    {SBB, EXACT_RAX, OP_IMM32, 0, 0x1D, ' ', 0},

    {SBB, OP_RM8,  OP_IMM8,  0, 0x80, '3', 0},
    {SBB, OP_RM16, OP_IMM16, 0, 0x81, '3', 0},
    {SBB, OP_RM32, OP_IMM32, 0, 0x81, '3', 0},
    {SBB, OP_RM64, OP_IMM32, 0, 0x81, '3', 0},

    {SBB, OP_RM16, OP_IMM8,  0, 0x83, '3', 0},
    {SBB, OP_RM32, OP_IMM8,  0, 0x83, '3', 0},
    {SBB, OP_RM64, OP_IMM8,  0, 0x83, '3', 0},

    {SBB, OP_REG8,  OP_RM8,  0, 0x1A, 'r', 0},
    {SBB, OP_REG16, OP_RM16, 0, 0x1B, 'r', 0},
    {SBB, OP_REG32, OP_RM32, 0, 0x1B, 'r', 0},
    {SBB, OP_REG64, OP_RM64, 0, 0x1B, 'r', 0},

    {SBB, OP_RM8,  OP_REG8,  0, 0x18, 'r', 0},
    {SBB, OP_RM16, OP_REG16, 0, 0x19, 'r', 0},
    {SBB, OP_RM32, OP_REG32, 0, 0x19, 'r', 0},
    {SBB, OP_RM64, OP_REG64, 0, 0x19, 'r', 0},

    {SCASB, 0, 0, 0, 0xAE, ' ', 0},
    {SCASW, 0, 0, 0, 0xAF66, ' ', 0},
    {SCASD, 0, 0, 0, 0xAF, ' ', 0},
    {SCASQ, 0, 0, 0, 0xAF48, ' ', 0},

    {SETO,   OP_RM8, 0, 0, 0x900F, '0', 0},
    {SETNO,  OP_RM8, 0, 0, 0x910F, '0', 0},
    {SETB,   OP_RM8, 0, 0, 0x920F, '0', 0},
    {SETC,   OP_RM8, 0, 0, 0x920F, '0', 0},
    {SETNAE, OP_RM8, 0, 0, 0x920F, '0', 0},
    {SETNB,  OP_RM8, 0, 0, 0x930F, '0', 0},
    {SETNC,  OP_RM8, 0, 0, 0x930F, '0', 0},
    {SETAE,  OP_RM8, 0, 0, 0x930F, '0', 0},
    {SETZ,   OP_RM8, 0, 0, 0x940F, '0', 0},
    {SETE,   OP_RM8, 0, 0, 0x940F, '0', 0},
    {SETNZ,  OP_RM8, 0, 0, 0x950F, '0', 0},
    {SETNE,  OP_RM8, 0, 0, 0x950F, '0', 0},
    {SETBE,  OP_RM8, 0, 0, 0x960F, '0', 0},
    {SETNA,  OP_RM8, 0, 0, 0x960F, '0', 0},
    {SETNBE, OP_RM8, 0, 0, 0x970F, '0', 0},
    {SETA,   OP_RM8, 0, 0, 0x970F, '0', 0},
    {SETS,   OP_RM8, 0, 0, 0x980F, '0', 0},
    {SETNS,  OP_RM8, 0, 0, 0x990F, '0', 0},
    {SETP,   OP_RM8, 0, 0, 0x9A0F, '0', 0},
    {SETPE,  OP_RM8, 0, 0, 0x9A0F, '0', 0},
    {SETNP,  OP_RM8, 0, 0, 0x9B0F, '0', 0},
    {SETPO,  OP_RM8, 0, 0, 0x9B0F, '0', 0},
    {SETL,   OP_RM8, 0, 0, 0x9C0F, '0', 0},
    {SETNGE, OP_RM8, 0, 0, 0x9C0F, '0', 0},
    {SETNL,  OP_RM8, 0, 0, 0x9D0F, '0', 0},
    {SETGE,  OP_RM8, 0, 0, 0x9D0F, '0', 0},
    {SETLE,  OP_RM8, 0, 0, 0x9E0F, '0', 0},
    {SETNG,  OP_RM8, 0, 0, 0x9E0F, '0', 0},
    {SETNLE, OP_RM8, 0, 0, 0x9F0F, '0', 0},
    {SETG,   OP_RM8, 0, 0, 0x9F0F, '0', 0},

    {SFENCE, 0, 0, 0, 0xF8AE0F, ' ', 0},

    {SHLD, OP_RM16, OP_REG16, OP_IMM8,  0xA40F, 'r', 0},
    {SHLD, OP_RM16, OP_REG16, 0,  0xA50F, 'r', 0},

    {SHLD, OP_RM32, OP_REG32, OP_IMM8,  0xA40F, 'r', 0},
    {SHLD, OP_RM32, OP_REG32, 0,  0xA50F, 'r', 0},

    {SHLD, OP_RM64, OP_REG64, OP_IMM8,  0xA40F, 'r', 0},
    {SHLD, OP_RM64, OP_REG64, 0,  0xA50F, 'r', 0},

    {SHR, OP_RM8, 0, 0, 0xD0, '5', 0},
    {SHR, OP_RM8, 0, 0, 0xD2, '5', 0},
    {SHR, OP_RM8, OP_IMM8, 0, 0xC0, '5', 0},

    {SHR, OP_RM16, 0, 0, 0xD1, '5', 0},
    {SHR, OP_RM16, 0, 0, 0xD3, '5', 0},
    {SHR, OP_RM16, OP_IMM8, 0, 0xC1, '5', 0},

    {SHR, OP_RM32, 0, 0, 0xD1, '5', 0},
    {SHR, OP_RM32, 0, 0, 0xD3, '5', 0},
    {SHR, OP_RM32, OP_IMM8, 0, 0xC1, '5', 0},

    {SHR, OP_RM64, 0, 0, 0xD1, '5', 0},
    {SHR, OP_RM64, 0, 0, 0xD3, '5', 0},
    {SHR, OP_RM64, OP_IMM8, 0, 0xC1, '5', 0},

    {SHRD, OP_RM16, OP_REG16, OP_IMM8,  0xAC0F, 'r', 0},
    {SHRD, OP_RM16, OP_REG16, 0,  0xAD0F, 'r', 0},

    {SHRD, OP_RM32, OP_REG32, OP_IMM8,  0xAC0F, 'r', 0},
    {SHRD, OP_RM32, OP_REG32, 0,  0xAD0F, 'r', 0},

    {SHRD, OP_RM64, OP_REG64, OP_IMM8,  0xAC0F, 'r', 0},
    {SHRD, OP_RM64, OP_REG64, 0,  0xAD0F, 'r', 0},

    {STC, 0, 0, 0, 0xF9, ' ', 0},
    {STD, 0, 0, 0, 0xFD, ' ', 0},

    {STOSB, 0, 0, 0, 0xAA, ' ', 0},
    {STOSW, 0, 0, 0, 0xAB66, ' ', 0},
    {STOSD, 0, 0, 0, 0xAB, ' ', 0},
    {STOSQ, 0, 0, 0, 0xAB48, ' ', 0},

    {SUB, EXACT_AL,  OP_IMM8,  0, 0x2C, ' ', 0},
    {SUB, EXACT_AX,  OP_IMM16, 0, 0x2D, ' ', 0},
    {SUB, EXACT_EAX, OP_IMM32, 0, 0x2D, ' ', 0},
    {SUB, EXACT_RAX, OP_IMM32, 0, 0x2D, ' ', 0},

    {SUB, OP_RM8,  OP_IMM8,  0, 0x80, '5', 0},
    {SUB, OP_RM16, OP_IMM16, 0, 0x81, '5', 0},
    {SUB, OP_RM32, OP_IMM32, 0, 0x81, '5', 0},
    {SUB, OP_RM64, OP_IMM32, 0, 0x81, '5', 0},

    {SUB, OP_RM16, OP_IMM8,  0, 0x83, '5', 0},
    {SUB, OP_RM32, OP_IMM8,  0, 0x83, '5', 0},
    {SUB, OP_RM64, OP_IMM8,  0, 0x83, '5', 0},

    {SUB, OP_REG8,  OP_RM8,  0, 0x2A, 'r', 0},
    {SUB, OP_REG16, OP_RM16, 0, 0x2B, 'r', 0},
    {SUB, OP_REG32, OP_RM32, 0, 0x2B, 'r', 0},
    {SUB, OP_REG64, OP_RM64, 0, 0x2B, 'r', 0},

    {SUB, OP_RM8,  OP_REG8,  0, 0x28, 'r', 0},
    {SUB, OP_RM16, OP_REG16, 0, 0x29, 'r', 0},
    {SUB, OP_RM32, OP_REG32, 0, 0x29, 'r', 0},
    {SUB, OP_RM64, OP_REG64, 0, 0x29, 'r', 0},

    {TEST, EXACT_AL,  OP_IMM8,  0, 0xA8, ' ', 0},
    {TEST, EXACT_AX,  OP_IMM16, 0, 0xA9, ' ', 0},
    {TEST, EXACT_EAX, OP_IMM32, 0, 0xA9, ' ', 0},
    {TEST, EXACT_RAX, OP_IMM32, 0, 0xA9, ' ', 0},

    {TEST, OP_RM8,  OP_IMM8,  0, 0xF6, '0', 0},
    {TEST, OP_RM16, OP_IMM16, 0, 0xF7, '0', 0},
    {TEST, OP_RM32, OP_IMM32, 0, 0xF7, '0', 0},
    {TEST, OP_RM64, OP_IMM32, 0, 0xF7, '0', 0},

    {TEST, OP_RM8,  OP_REG8,  0, 0x84, 'r', 0},
    {TEST, OP_RM16, OP_REG16, 0, 0x85, 'r', 0},
    {TEST, OP_RM32, OP_REG32, 0, 0x85, 'r', 0},
    {TEST, OP_RM64, OP_REG32, 0, 0x85, 'r', 0},

    {TZCNT, OP_REG16, OP_RM16, 0, 0xBC0FF3, 'r', 0},
    {TZCNT, OP_REG32, OP_RM32, 0, 0xBC0FF3, 'r', 0},
    {TZCNT, OP_REG64, OP_RM64, 0, 0xBC0FF3, 'r', 0},

    {XADD, OP_RM8, OP_REG8, 0, 0xC00F, 'r', 0},
    {XADD, OP_RM16, OP_REG16, 0, 0xC10F, 'r', 0},
    {XADD, OP_RM32, OP_REG32, 0, 0xC10F, 'r', 0},
    {XADD, OP_RM64, OP_REG64, 0, 0xC10F, 'r', 0},

    {XCHG, EXACT_AX, OP_REG16, 0, 0x90, '+', 0},
    {XCHG, OP_REG16, EXACT_AX, 0, 0x90, '+', 0},
    {XCHG, EXACT_EAX, OP_REG32, 0, 0x90, '+', 0},
    {XCHG, OP_REG32, EXACT_EAX, 0, 0x90, '+', 0},
    {XCHG, EXACT_RAX, OP_REG64, 0, 0x90, '+', 0},
    {XCHG, OP_REG64, EXACT_RAX, 0, 0x90, '+', 0},

    {XCHG, OP_RM8  , OP_REG8 , 0, 0x86, 'r', 0},
    {XCHG, OP_RM16 , OP_REG16, 0, 0x87, 'r', 0},
    {XCHG, OP_RM32 , OP_REG32, 0, 0x87, 'r', 0},
    {XCHG, OP_RM64 , OP_REG64, 0, 0x87, 'r', 0},
    {XCHG, OP_REG8  , OP_RM8 , 0, 0x86, 'r', 0},
    {XCHG, OP_REG16 , OP_RM16, 0, 0x87, 'r', 0},
    {XCHG, OP_REG32 , OP_RM32, 0, 0x87, 'r', 0},
    {XCHG, OP_REG64 , OP_RM64, 0, 0x87, 'r', 0},

    {XLAT, 0, 0, 0, 0xD7, ' ', 0},

    {XOR, EXACT_AL,  OP_IMM8,  0, 0x34, ' ', 0},
    {XOR, EXACT_AX,  OP_IMM16, 0, 0x35, ' ', 0},
    {XOR, EXACT_EAX, OP_IMM32, 0, 0x35, ' ', 0},
    {XOR, EXACT_RAX, OP_IMM32, 0, 0x35, ' ', 0},

    {XOR, OP_RM8,  OP_IMM8,  0, 0x80, '6', 0},
    {XOR, OP_RM16, OP_IMM16, 0, 0x81, '6', 0},
    {XOR, OP_RM32, OP_IMM32, 0, 0x81, '6', 0},
    {XOR, OP_RM64, OP_IMM32, 0, 0x81, '6', 0},

    {XOR, OP_RM16, OP_IMM8,  0, 0x83, '6', 0},
    {XOR, OP_RM32, OP_IMM8,  0, 0x83, '6', 0},
    {XOR, OP_RM64, OP_IMM8,  0, 0x83, '6', 0},

    {XOR, OP_REG8,  OP_RM8,  0, 0x32, 'r', 0},
    {XOR, OP_REG16, OP_RM16, 0, 0x33, 'r', 0},
    {XOR, OP_REG32, OP_RM32, 0, 0x33, 'r', 0},
    {XOR, OP_REG64, OP_RM64, 0, 0x33, 'r', 0},

    {XOR, OP_RM8,  OP_REG8,  0, 0x30, 'r', 0},
    {XOR, OP_RM16, OP_REG16, 0, 0x31, 'r', 0},
    {XOR, OP_RM32, OP_REG32, 0, 0x31, 'r', 0},
    {XOR, OP_RM64, OP_REG64, 0, 0x31, 'r', 0},

    {RDTSC, 0, 0, 0, 0x310F, ' ', 0},

    {ADDPD, OP_XMM0, OP_RM128, 0, 0x580F66, 'r', 0},
    {ADDPS, OP_XMM0, OP_RM128, 0, 0x580F, 'r', 0},
    {ADDSD, OP_XMM0, OP_RM128, 0, 0x580FF2, 'r', 0},
    {ADDSS, OP_XMM0, OP_RM128, 0, 0x580FF3, 'r', 0},

    {ADDSUBPD, OP_XMM0, OP_RM128, 0, 0xD00F66, 'r', 0},
    {ADDSUBPS, OP_XMM0, OP_RM128, 0, 0xD00FF2, 'r', 0},

    {ANDNPD, OP_XMM0, OP_RM128, 0, 0x550F66, 'r', 0},
    {ANDNPS, OP_XMM0, OP_RM128, 0, 0x550F, 'r', 0},

    {ANDPD, OP_XMM0, OP_RM128, 0, 0x540F66, 'r', 0},
    {ANDPS, OP_XMM0, OP_RM128, 0, 0x540F, 'r', 0},

    {BLENDPD, OP_XMM0, OP_RM128, OP_IMM8, 0x0D3A0F66u, 'r', 0},
    {BLENDPS, OP_XMM0, OP_RM128, OP_IMM8, 0x0C3A0F66u, 'r', 0},

    {BLENDVPD, OP_XMM0, OP_RM128, 0, 0x15380F66, 'r', 0},
    {BLENDVPS, OP_XMM0, OP_RM128, 0, 0x14380F66, 'r', 0},

    {CMPPD, OP_XMM0, OP_RM128, OP_IMM8, 0xC20F66, 'r', 0},
    {CMPPS, OP_XMM0, OP_RM128, OP_IMM8, 0xC20F, 'r', 0},

    {CMPSD, OP_XMM0, OP_RM128, OP_IMM8, 0xC20FF2, 'r', 0},
    {CMPSS, OP_XMM0, OP_RM128, OP_IMM8, 0xC20FF3, 'r', 0},

    {COMISD, OP_XMM0, OP_RM128, 0, 0x2F0F66, 'r', 0},
    {COMISS, OP_XMM0, OP_RM128, 0, 0x2F0F, 'r', 0},

    {CVTDQ2PD, OP_XMM0, OP_RM128, 0, 0xE60FF3, 'r', 0},
    {CVTDQ2PS, OP_XMM0, OP_RM128, 0, 0x5B0F, 'r', 0},
    {CVTPD2DQ, OP_XMM0, OP_RM128, 0, 0xE60FF2, 'r', 0},
    {CVTPD2PS, OP_XMM0, OP_RM128, 0, 0x5A0F66, 'r', 0},
    {CVTPS2DQ, OP_XMM0, OP_RM128, 0, 0x5B0F66, 'r', 0},
    {CVTPS2PD, OP_XMM0, OP_RM128, 0, 0x5A0F, 'r', 0},
    {CVTSD2SI, OP_REG32, OP_RM128, 0, 0x2D0FF2, 'r', 0},
    {CVTSD2SI, OP_REG64, OP_RM128, 0, 0x2D0FF2, 'r', 0},
    {CVTSD2SS, OP_XMM0, OP_RM128, 0, 0x5A0FF2, 'r', 0},
    {CVTSI2SD, OP_XMM0, OP_RM32, 0, 0x2A0FF2, 'r', 0},
    {CVTSI2SD, OP_XMM0, OP_RM64, 0, 0x2A0FF2, 'r', 0},
    {CVTSI2SS, OP_XMM0, OP_RM32, 0, 0x2A0FF3, 'r', 0},
    {CVTSI2SS, OP_XMM0, OP_RM64, 0, 0x2A0FF3, 'r', 0},
    {CVTSS2SD, OP_XMM0, OP_RM128, 0, 0x5A0FF3, 'r', 0},
    {CVTSS2SI, OP_REG32, OP_RM128, 0, 0x2D0FF3, 'r', 0},
    {CVTSS2SI, OP_REG64, OP_RM128, 0, 0x2D0FF3, 'r', 0},

    {CVTTPD2DQ, OP_XMM0, OP_RM128, 0, 0xE60F66, 'r', 0},
    {CVTTPS2DQ, OP_XMM0, OP_RM128, 0, 0x5B0FF3, 'r', 0},
    {CVTTSD2SI, OP_REG32, OP_RM128, 0, 0x2C0FF2, 'r', 0},
    {CVTTSD2SI, OP_REG64, OP_RM128, 0, 0x2C0FF2, 'r', 0},
    {CVTTSS2SI, OP_REG32, OP_RM128, 0, 0x2C0FF3, 'r', 0},
    {CVTTSS2SI, OP_REG64, OP_RM128, 0, 0x2C0FF3, 'r', 0},

    {DIVPD, OP_XMM0, OP_RM128, 0, 0x5E0F66, 'r', 0},
    {DIVPS, OP_XMM0, OP_RM128, 0, 0x5E0F, 'r', 0},
    {DIVSD, OP_XMM0, OP_RM128, 0, 0x5E0FF2, 'r', 0},
    {DIVSS, OP_XMM0, OP_RM128, 0, 0x5E0FF3, 'r', 0},

    {DPPD, OP_XMM0, OP_RM128, OP_IMM8, 0x413A0F66u, 'r', 0},
    {DPPS, OP_XMM0, OP_RM128, OP_IMM8, 0x403A0F66u, 'r', 0},

    {EXTRACTPS, OP_RM32, OP_XMM0, OP_IMM8, 0x173A0F66u, 'r', 0},

    {EXTRQ, OP_XMM0, OP_IMM8, OP_IMM8, 0x780F66, '0', 0},
    {EXTRQ, OP_XMM0, OP_XMM0, 0, 0x790F66, 'r', 0},

    {HADDPD, OP_XMM0, OP_RM128, 0, 0x7C0F66, 'r', 0},
    {HADDPS, OP_XMM0, OP_RM128, 0, 0x7C0FF2, 'r', 0},

    {HSUBPD, OP_XMM0, OP_RM128, 0, 0x7D0F66, 'r', 0},
    {HSUBPS, OP_XMM0, OP_RM128, 0, 0x7D0FF2, 'r', 0},

    {INSERTPS, OP_XMM0, OP_RM128, OP_IMM8, 0x213A0F66u, 'r', 0},

    {INSERTQ, OP_XMM0, OP_XMM0, OP_IMM8, 0x780FF2, 'r', 0},
    {INSERTQ, OP_XMM0, OP_XMM0, 0, 0x790FF2, 'r', 0},

    {LDDQU, OP_XMM0, OP_RM128, 0, 0xF00FF2, 'r', 0},

    {MASKMOVDQU, OP_XMM0, OP_XMM0, 0, 0xF70F66, 'r', 0},

    {MAXPD, OP_XMM0, OP_RM128, 0, 0x5F0F66, 'r', 0},
    {MAXPS, OP_XMM0, OP_RM128, 0, 0x5F0F, 'r', 0},
    {MAXSD, OP_XMM0, OP_RM128, 0, 0x5F0FF2, 'r', 0},
    {MAXSS, OP_XMM0, OP_RM128, 0, 0x5F0FF3, 'r', 0},

    {MINPD, OP_XMM0, OP_RM128, 0, 0x5D0F66, 'r', 0},
    {MINPS, OP_XMM0, OP_RM128, 0, 0x5D0F, 'r', 0},
    {MINSD, OP_XMM0, OP_RM128, 0, 0x5D0FF2, 'r', 0},
    {MINSS, OP_XMM0, OP_RM128, 0, 0x5D0FF3, 'r', 0},

    {MOVAPD, OP_XMM0, OP_RM128, 0, 0x280F66, 'r', 0},
    {MOVAPD, OP_RM128, OP_XMM0, 0, 0x290F66, 'r', 0},
    {MOVAPS, OP_XMM0, OP_RM128, 0, 0x280F66, 'r', 0},
    {MOVAPS, OP_RM128, OP_XMM0, 0, 0x290F66, 'r', 0},

    {MOVDDUP, OP_XMM0, OP_RM128, 0, 0x120FF2, 'r', 0},
    {MOVDQA, OP_XMM0, OP_RM128, 0, 0x6F0F66, 'r', 0},
    {MOVDQA, OP_RM128, OP_XMM0, 0, 0x7F0F66, 'r', 0},
    {MOVDQU, OP_XMM0, OP_RM128, 0, 0x6F0FF3, 'r', 0},
    {MOVDQU, OP_RM128, OP_XMM0, 0, 0x7F0FF3, 'r', 0},
    {MOVHLPS, OP_XMM0, OP_XMM0, 0, 0x120F, 'r', 0},
    {MOVHPD, OP_XMM0, OP_MEM64, 0, 0x160F66, 'r', 0},
    {MOVHPD, OP_MEM64, OP_XMM0, 0, 0x170F66, 'r', 0},
    {MOVHPS, OP_XMM0, OP_MEM64, 0, 0x160F, 'r', 0},
    {MOVHPS, OP_MEM64, OP_XMM0, 0, 0x170F, 'r', 0},
    {MOVLHPS, OP_XMM0, OP_XMM0, 0, 0x160F, 'r', 0},
    {MOVLPD, OP_XMM0, OP_MEM64, 0, 0x120F66, 'r', 0},
    {MOVHPD, OP_MEM64, OP_XMM0, 0, 0x130F66, 'r', 0},
    {MOVLPS, OP_XMM0, OP_MEM64, 0, 0x120F, 'r', 0},
    {MOVLPS, OP_MEM64, OP_XMM0, 0, 0x130F, 'r', 0},

    {MOVNTDQ, OP_MEM128, OP_XMM0, 0, 0xE70F66, 'r', 0},
    {MOVNTDQA, OP_MEM128, OP_XMM0, 0, 0x2A380F66u, 'r', 0},
    {MOVNTPD, OP_MEM128, OP_XMM0, 0, 0x2B0F66, 'r', 0},
    {MOVNTPS, OP_MEM128, OP_XMM0, 0, 0x2B0F, 'r', 0},
    {MOVNTSD, OP_MEM128, OP_XMM0, 0, 0x2B0FF2, 'r', 0},
    {MOVNTSS, OP_MEM128, OP_XMM0, 0, 0x2B0FF3, 'r', 0},
    {MOVSD, OP_XMM0, OP_RM128, 0, 0x100FF2, 'r', 0},
    {MOVSD, OP_RM128, OP_XMM0, 0, 0x110FF2, 'r', 0},
    {MOVSHDUP, OP_XMM0, OP_RM128, 0, 0x160FF3, 'r', 0},
    {MOVSLDUP, OP_XMM0, OP_RM128, 0, 0x120FF3, 'r', 0},
    {MOVSS, OP_XMM0, OP_RM128, 0, 0x100FF3, 'r', 0},
    {MOVSS, OP_RM128, OP_XMM0, 0, 0x110FF3, 'r', 0},
    {MOVUPD, OP_XMM0, OP_RM128, 0, 0x100F66, 'r', 0},
    {MOVUPD, OP_RM128, OP_XMM0, 0, 0x110F66, 'r', 0},
    {MOVUPS, OP_XMM0, OP_RM128, 0, 0x100F, 'r', 0},
    {MOVUPS, OP_RM128, OP_XMM0, 0, 0x110F, 'r', 0},

    {MPSADBW, OP_XMM0, OP_RM128, OP_IMM8, 0x423A0F66u, 'r', 0},

    {MULPD, OP_XMM0, OP_RM128, 0, 0x590F66, 'r', 0},
    {MULPS, OP_XMM0, OP_RM128, 0, 0x590F, 'r', 0},
    {MULSD, OP_XMM0, OP_RM128, 0, 0x590FF2, 'r', 0},
    {MULSS, OP_XMM0, OP_RM128, 0, 0x590FF3, 'r', 0},

    {ORPD, OP_XMM0, OP_RM128, 0, 0x560F66, 'r', 0},
    {ORPS, OP_XMM0, OP_RM128, 0, 0x560F, 'r', 0},

    {PABSB, OP_XMM0, OP_RM128, 0, 0x1C380F, 'r', 0},
    {PABSW, OP_XMM0, OP_RM128, 0, 0x1D380F, 'r', 0},
    {PABSD, OP_XMM0, OP_RM128, 0, 0x1E380F, 'r', 0},

    {PACKSSDW, OP_XMM0, OP_RM128, 0, 0x6B0F66, 'r', 0},
    {PACKSSWB, OP_XMM0, OP_RM128, 0, 0x630F66, 'r', 0},
    {PACKUSDW, OP_XMM0, OP_RM128, 0, 0x2B380F66u, 'r', 0},
    {PACKUSWB, OP_XMM0, OP_RM128, 0, 0x670F66, 'r', 0},

    {PADDB, OP_XMM0, OP_RM128, 0, 0xFC0F66, 'r', 0},
    {PADDW, OP_XMM0, OP_RM128, 0, 0xFD0F66, 'r', 0},
    {PADDD, OP_XMM0, OP_RM128, 0, 0xFE0F66, 'r', 0},
    {PADDQ, OP_XMM0, OP_RM128, 0, 0xD40F66, 'r', 0},
    {PADDSB, OP_XMM0, OP_RM128, 0, 0xEC0F66, 'r', 0},
    {PADDSW, OP_XMM0, OP_RM128, 0, 0xED0F66, 'r', 0},
    {PADDUSB, OP_XMM0, OP_RM128, 0, 0xDC0F66, 'r', 0},
    {PADDUSW, OP_XMM0, OP_RM128, 0, 0xDD0F66, 'r', 0},

    {PALIGNR, OP_XMM0, OP_RM128, OP_IMM8, 0x0F3A0F66u, 'r', 0},

    {PAND, OP_XMM0, OP_RM128, 0, 0xDB0F66u, 'r', 0},
    {PANDN, OP_XMM0, OP_RM128, 0, 0xDF0F66u, 'r', 0},
    {PAVGB, OP_XMM0, OP_RM128, 0, 0xE00F66u, 'r', 0},
    {PAVGW, OP_XMM0, OP_RM128, 0, 0xE30F66u, 'r', 0},

    {PBLENDVB, OP_XMM0, OP_RM128, 0, 0x10380F66u, 'r', 0},
    {PBLENDW, OP_XMM0, OP_RM128, OP_IMM8, 0x0E3A0F66u, 'r', 0},

    {PCLMULQDQ, OP_XMM0, OP_RM128, OP_IMM8, 0x443A0F66u, 'r', 0},

    {PCMPEQB, OP_XMM0, OP_RM128, 0, 0x740F66u, 'r', 0},
    {PCMPEQD, OP_XMM0, OP_RM128, 0, 0x760F66u, 'r', 0},
    {PCMPEQW, OP_XMM0, OP_RM128, 0, 0x750F66u, 'r', 0},
    {PCMPEQQ, OP_XMM0, OP_RM128, 0, 0x29380F66u, 'r', 0},
    {PCMPESTRI, OP_XMM0, OP_RM128, OP_IMM8, 0x613A0F66u, 'r', 0},
    {PCMPESTRM, OP_XMM0, OP_RM128, OP_IMM8, 0x603A0F66u, 'r', 0},
    {PCMPGTB, OP_XMM0, OP_RM128, 0, 0x640F66u, 'r', 0},
    {PCMPGTD, OP_XMM0, OP_RM128, 0, 0x660F66u, 'r', 0},
    {PCMPGTW, OP_XMM0, OP_RM128, 0, 0x650F66u, 'r', 0},
    {PCMPGTQ, OP_XMM0, OP_RM128, 0, 0x37380F66u, 'r', 0},
    {PCMPISTRI, OP_XMM0, OP_RM128, OP_IMM8, 0x633A0F66u, 'r', 0},
    {PCMPISTRM, OP_XMM0, OP_RM128, OP_IMM8, 0x623A0F66u, 'r', 0},

    {PEXTRB, OP_RM8, OP_XMM0, OP_IMM8, 0x143A0F66u, 'r', 0},
    {PEXTRW, OP_RM16, OP_XMM0, OP_IMM8, 0x153A0F66u, 'r', 0},
    {PEXTRD, OP_RM32, OP_XMM0, OP_IMM8, 0x163A0F66u, 'r', 0},
    {PEXTRQ, OP_RM64, OP_XMM0, OP_IMM8, 0x163A0F66u, 'r', 0},

    {PHADDD, OP_XMM0, OP_RM128, 0, 0x02380F66u, 'r', 0},
    {PHADDSW, OP_XMM0, OP_RM128, 0, 0x03380F66u, 'r', 0},
    {PHADDW, OP_XMM0, OP_RM128, 0, 0x01380F66u, 'r', 0},

    {PHMINPOSUW, OP_XMM0, OP_RM128, 0, 0x41380F66u, 'r', 0},

    {PHSUBD, OP_XMM0, OP_RM128, 0, 0x06380F66u, 'r', 0},
    {PHSUBSW, OP_XMM0, OP_RM128, 0, 0x07380F66u, 'r', 0},
    {PHSUBW, OP_XMM0, OP_RM128, 0, 0x05380F66u, 'r', 0},

    {PINSRB, OP_XMM0, OP_RM8, OP_IMM8, 0x203A0F66u, 'r', 0},
    {PINSRW, OP_XMM0, OP_RM16, OP_IMM8, 0xC40F66u, 'r', 0},
    {PINSRD, OP_XMM0, OP_RM32, OP_IMM8, 0x223A0F66u, 'r', 0},
    {PINSRQ, OP_XMM0, OP_RM64, OP_IMM8, 0x223A0F66u, 'r', 0},

    {PMADDUBSW, OP_XMM0, OP_RM128, 0, 0x04380F66u, 'r', 0},
    {PMADDWD, OP_XMM0, OP_RM128, 0, 0xF50F66u, 'r', 0},

    {PMAXSB, OP_XMM0, OP_RM128, 0, 0x3C380F66u, 'r', 0},
    {PMAXSD, OP_XMM0, OP_RM128, 0, 0x3D380F66u, 'r', 0},
    {PMAXSW, OP_XMM0, OP_RM128, 0, 0xEE0F66u, 'r', 0},
    {PMAXSUB, OP_XMM0, OP_RM128, 0, 0xDE0F66u, 'r', 0},
    {PMAXSUD, OP_XMM0, OP_RM128, 0, 0x3F380F66u, 'r', 0},
    {PMAXSUW, OP_XMM0, OP_RM128, 0, 0x3E0F66u, 'r', 0},

    {PMINSB, OP_XMM0, OP_RM128, 0, 0x38380F66u, 'r', 0},
    {PMINSD, OP_XMM0, OP_RM128, 0, 0x39380F66u, 'r', 0},
    {PMINSW, OP_XMM0, OP_RM128, 0, 0xEA0F66u, 'r', 0},
    {PMINUB, OP_XMM0, OP_RM128, 0, 0xDA0F66u, 'r', 0},
    {PMINUD, OP_XMM0, OP_RM128, 0, 0x3B380F66u, 'r', 0},
    {PMINUW, OP_XMM0, OP_RM128, 0, 0x3A380F66u, 'r', 0},

    {PMOVMSKB, OP_REG32, OP_XMM0, 0, 0xD70F66u, 'r', 0},

    {PMOVSXBD, OP_XMM0, OP_RM128, 0, 0x21380F66u, 'r', 0},
    {PMOVSXBQ, OP_XMM0, OP_RM128, 0, 0x22380F66u, 'r', 0},
    {PMOVSXBW, OP_XMM0, OP_RM128, 0, 0x20380F66u, 'r', 0},
    {PMOVSXDQ, OP_XMM0, OP_RM128, 0, 0x25380F66u, 'r', 0},
    {PMOVSXWD, OP_XMM0, OP_RM128, 0, 0x23380F66u, 'r', 0},
    {PMOVSXWQ, OP_XMM0, OP_RM128, 0, 0x24380F66u, 'r', 0},
    {PMOVZXBD, OP_XMM0, OP_RM128, 0, 0x31380F66u, 'r', 0},
    {PMOVZXBQ, OP_XMM0, OP_RM128, 0, 0x32380F66u, 'r', 0},
    {PMOVZXBW, OP_XMM0, OP_RM128, 0, 0x30380F66u, 'r', 0},
    {PMOVZXDQ, OP_XMM0, OP_RM128, 0, 0x35380F66u, 'r', 0},
    {PMOVZXWD, OP_XMM0, OP_RM128, 0, 0x33380F66u, 'r', 0},
    {PMOVZXWQ, OP_XMM0, OP_RM128, 0, 0x34380F66u, 'r', 0},

    {PMULDQ, OP_XMM0, OP_RM128, 0, 0x28380F66u, 'r', 0},
    {PMULHRSW, OP_XMM0, OP_RM128, 0, 0x0B380F66u, 'r', 0},
    {PMULHUW, OP_XMM0, OP_RM128, 0, 0xE40F66u, 'r', 0},
    {PMULHW, OP_XMM0, OP_RM128, 0, 0xE50F66u, 'r', 0},
    {PMULLD, OP_XMM0, OP_RM128, 0, 0x40380F66u, 'r', 0},
    {PMULLW, OP_XMM0, OP_RM128, 0, 0xD50F66u, 'r', 0},
    {PMULUDQ, OP_XMM0, OP_RM128, 0, 0xF40F66u, 'r', 0},

    {POR, OP_XMM0, OP_RM128, 0, 0xEB0F66u, 'r', 0},
    {PSADBW, OP_XMM0, OP_RM128, 0, 0xF60F66u, 'r', 0},
    {PSHUFB, OP_XMM0, OP_RM128, 0, 0x00380F66u, 'r', 0},

    {PSHUFD, OP_XMM0, OP_RM128, OP_IMM8, 0x700F66u, 'r', 0},
    {PSHUFD, OP_XMM0, OP_RM128, OP_IMM8, 0x700F66u, 'r', 0},
    {PSHUFLW, OP_XMM0, OP_RM128, OP_IMM8, 0x700FF2u, 'r', 0},

    {PSIGNB, OP_XMM0, OP_RM128, 0, 0x08380F66u, 'r', 0},
    {PSIGND, OP_XMM0, OP_RM128, 0, 0x0A380F66u, 'r', 0},
    {PSIGNW, OP_XMM0, OP_RM128, 0, 0x09380F66u, 'r', 0},

    {PSLLD, OP_XMM0, OP_RM128, 0, 0xF20F66u, 'r', 0},
    {PSLLD, OP_XMM0, OP_IMM8, 0, 0x720F66u, '6', 0},
    {PSLLDQ, OP_XMM0, OP_IMM8, 0, 0x730F66u, '7', 0},
    {PSLLQ, OP_XMM0, OP_RM128, 0, 0xF30F66u, 'r', 0},
    {PSLLQ, OP_XMM0, OP_IMM8, 0, 0x730F66u, '6', 0},
    {PSLLW, OP_XMM0, OP_RM128, 0, 0xF10F66u, 'r', 0},
    {PSLLW, OP_XMM0, OP_IMM8, 0, 0x710F66u, '6', 0},

    {PSRAD, OP_XMM0, OP_RM128, 0, 0xE20F66u, 'r', 0},
    {PSRAD, OP_XMM0, OP_IMM8, 0, 0x720F66u, '4', 0},
    {PSRAW, OP_XMM0, OP_RM128, 0, 0xE10F66u, 'r', 0},
    {PSRAW, OP_XMM0, OP_IMM8, 0, 0x710F66u, '4', 0},

    {PSRLD, OP_XMM0, OP_RM128, 0, 0xD20F66u, 'r', 0},
    {PSRLD, OP_XMM0, OP_IMM8, 0, 0x720F66u, '2', 0},
    {PSRLDQ, OP_XMM0, OP_IMM8, 0, 0x730F66u, '3', 0},
    {PSRLQ, OP_XMM0, OP_RM128, 0, 0xD30F66u, 'r', 0},
    {PSRLQ, OP_XMM0, OP_IMM8, 0, 0x730F66u, '2', 0},
    {PSRLW, OP_XMM0, OP_RM128, 0, 0xD10F66u, 'r', 0},
    {PSRLW, OP_XMM0, OP_IMM8, 0, 0x710F66u, '2', 0},

    {PSUBB, OP_XMM0, OP_RM128, 0, 0xF80F66u, 'r', 0},
    {PSUBD, OP_XMM0, OP_RM128, 0, 0xFA0F66u, 'r', 0},
    {PSUBW, OP_XMM0, OP_RM128, 0, 0xF90F66u, 'r', 0},
    {PSUBQ, OP_XMM0, OP_RM128, 0, 0xFB0F66u, 'r', 0},
    {PSUBSW, OP_XMM0, OP_RM128, 0, 0xE90F66u, 'r', 0},
    {PSUBUSB, OP_XMM0, OP_RM128, 0, 0xD80F66u, 'r', 0},
    {PSUBUSW, OP_XMM0, OP_RM128, 0, 0xD90F66u, 'r', 0},

    {PTEST, OP_XMM0, OP_RM128, 0, 0x17380F66u, 'r', 0},

    {PUNPCKHBW, OP_XMM0, OP_RM128, 0, 0x680F66u, 'r', 0},
    {PUNPCKHDQ, OP_XMM0, OP_RM128, 0, 0x6A0F66u, 'r', 0},
    {PUNPCKHQDQ, OP_XMM0, OP_RM128, 0, 0x6D0F66u, 'r', 0},
    {PUNPCKHWD, OP_XMM0, OP_RM128, 0, 0x690F66u, 'r', 0},
    {PUNPCKLBW, OP_XMM0, OP_RM128, 0, 0x600F66u, 'r', 0},
    {PUNPCKLDQ, OP_XMM0, OP_RM128, 0, 0x620F66u, 'r', 0},
    {PUNPCKLQDQ, OP_XMM0, OP_RM128, 0, 0x6C0F66u, 'r', 0},
    {PUNPCKLWD, OP_XMM0, OP_RM128, 0, 0x610F66u, 'r', 0},

    {PXOR, OP_XMM0, OP_RM128, 0, 0xEF0F66u, 'r', 0},

    {RCPPS, OP_XMM0, OP_RM128, 0, 0x530Fu, 'r', 0},
    {RCPSS, OP_XMM0, OP_RM128, 0, 0x530FF3u, 'r', 0},

    {ROUNDPD, OP_XMM0, OP_RM128, OP_IMM8, 0x093A0F66u, 'r', 0},
    {ROUNDPS, OP_XMM0, OP_RM128, OP_IMM8, 0x083A0F66u, 'r', 0},
    {ROUNDSD, OP_XMM0, OP_RM128, OP_IMM8, 0x0B3A0F66u, 'r', 0},
    {ROUNDSS, OP_XMM0, OP_RM128, OP_IMM8, 0x0A3A0F66u, 'r', 0},

    {RSQRTPS, OP_XMM0, OP_RM128, 0, 0x520Fu, 'r', 0},
    {RSQRTSS, OP_XMM0, OP_RM128, 0, 0x520FF3u, 'r', 0},

    {SHUFPD, OP_XMM0, OP_RM128, OP_IMM8, 0xC60F66u, 'r', 0},
    {SHUFPS, OP_XMM0, OP_RM128, OP_IMM8, 0xC60Fu, 'r', 0},

    {SQRTPD, OP_XMM0, OP_RM128, 0, 0x510F66u, 'r', 0},
    {SQRTPS, OP_XMM0, OP_RM128, 0, 0x510Fu, 'r', 0},
    {SQRTSD, OP_XMM0, OP_RM128, 0, 0x510FF2u, 'r', 0},
    {SQRTSS, OP_XMM0, OP_RM128, 0, 0x510FF3u, 'r', 0},

    {SUBPD, OP_XMM0, OP_RM128, 0, 0x5C0F66u, 'r', 0},
    {SUBPS, OP_XMM0, OP_RM128, 0, 0x5C0Fu, 'r', 0},
    {SUBSD, OP_XMM0, OP_RM128, 0, 0x5C0FF2u, 'r', 0},
    {SUBSS, OP_XMM0, OP_RM128, 0, 0x5C0FF3u, 'r', 0},

    {UCOMISD, OP_XMM0, OP_RM128, 0, 0x2E0F66u, 'r', 0},
    {UCOMISS, OP_XMM0, OP_RM128, 0, 0x2E0Fu, 'r', 0},

    {UNPCKHPD, OP_XMM0, OP_RM128, 0, 0x150F66u, 'r', 0},
    {UNPCKHPS, OP_XMM0, OP_RM128, 0, 0x150Fu, 'r', 0},
    {UNPCKLPD, OP_XMM0, OP_RM128, 0, 0x140F66u, 'r', 0},
    {UNPCKLPS, OP_XMM0, OP_RM128, 0, 0x140Fu, 'r', 0},

    {XORPD, OP_XMM0, OP_RM128, 0, 0x570F66, 'r', 0},
    {XORPS, OP_XMM0, OP_RM128, 0, 0x570F, 'r', 0},

    {UNKNOWN, 0, 0, 0, 0, ' ', 0},
};
