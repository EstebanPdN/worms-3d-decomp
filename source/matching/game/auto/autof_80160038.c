/* Decompiled automatically by m2c with mechanical corrections (tools/m2c_fixups.py:
 * far globals as unknown-size arrays, dropped leading parameters, forwarded
 * arguments); verified identical to the original after linking. Types and
 * names are m2c placeholders pending review. */
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
/* m2c helper macros (MIT license, see tools/m2c/LICENSE) */
/*
 * This header contains macros emitted by m2c in "valid syntax" mode,
 * which can be enabled by passing `--valid-syntax` on the command line.
 *
 * In this mode, unhandled types and expressions are emitted as macros so
 * that the output is compilable without human intervention.
 */


/* Unknown types */
typedef s32 M2C_UNK;
typedef s8  M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;

/* Unknown field access, like `*(type_ptr) &expr->unk_offset` */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

/* Bitwise (reinterpret) cast */
#define M2C_BITWISE(type, expr) ((type)(expr))

/* Unaligned reads */
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)

/* Unhandled instructions */
#define M2C_ERROR(desc) (0)
#define M2C_TRAP_IF(cond) (0)
#define M2C_BREAK() (0)
#define M2C_SYNC() (0)

#define GLUE_F64(a, b) (0.0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#define DMULT_HI(a, b) (0)
#define DMULTU_HI(a, b) (0)
#define CLZ(x) (0)
#define REVERSE_BITS(x) (0)
#define ROTATE_RIGHT(x, shift) (0)
#define ARM_RRX(x, carry) (0)
#define BSWAP32(x) (0)
#define BSWAP16(x) (0)
#define BSWAP16X2(x) (0)

/* Carry/overflow bits from partially-implemented instructions */
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)

/* Memcpy patterns */
#define M2C_MEMCPY_ALIGNED memcpy
#define M2C_MEMCPY_UNALIGNED memcpy
#define M2C_STRUCT_COPY memcpy

#define NULL ((void *)0)

M2C_UNK fn_8020FBD0();                              /* extern */
M2C_UNK fn_80160430(void *);                              /* extern */
M2C_UNK fn_8016293C(s32, u16 *);                    /* extern */
M2C_UNK fn_80160780(void *, s32, s32);                 /* extern */
M2C_UNK fn_80160828(void *, s32, s32);                 /* extern */
M2C_UNK fn_801608D0(void *, s32, s32, s32);            /* extern */
M2C_UNK fn_801613B8(void *);                              /* extern */
M2C_UNK fn_801FE1F8(s32);                           /* extern */
M2C_UNK fn_801628B0();                              /* extern */
s32 fn_801654B8();                                  /* extern */
M2C_UNK fn_8020EE9C(M2C_UNK *);                     /* extern */
M2C_UNK fn_8020FCB4(M2C_UNK *);                     /* extern */
M2C_UNK fn_8016803C(void *, M2C_UNK);                  /* extern */
M2C_UNK fn_8016804C(void *, M2C_UNK);                  /* extern */
M2C_UNK fn_8016E698(void *);                              void fn_80308FC0(s32 *, M2C_UNK);                /* extern */
s32 fn_8016F574();                                  /* extern */
s32 fn_801904C0();                                  /* extern */
M2C_UNK fn_801902E8();                              /* extern */
s32 fn_80190538();                                  /* extern */
s32 fn_80178958(void *, M2C_UNK);                           /* extern */
M2C_UNK fn_8020BD38(void *, M2C_UNK *);             /* extern */
s32 fn_8017E22C(s32, void *, M2C_UNK *);                         /* extern */
s32 fn_8018E0D8();                                  /* extern */
M2C_UNK fn_8018E26C();                              /* extern */
M2C_UNK fn_801E8D9C(s32);                           /* extern */
M2C_UNK fn_801EC0F8(s32, M2C_UNK *);                     /* extern */
M2C_UNK fn_801EBF38(s32, M2C_UNK *);                     /* extern */
M2C_UNK fn_801EC52C(s32, M2C_UNK *);                     /* extern */
M2C_UNK fn_801ECC6C(s32, M2C_UNK *);                     /* extern */
M2C_UNK fn_801EF174(s32, M2C_UNK, M2C_UNK, void *);         /* extern */

extern M2C_UNK lbl_80411608[];
extern M2C_UNK lbl_80411630[];

void *w3d_auto_80160038(void *arg0) {
    fn_8020FBD0();
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &(*lbl_80411608);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_80411630);
    return arg0;
}

void w3d_auto_801603e8(s32 arg0, u16 *arg1) {
    if ((s32) *arg1 != 0x40) {
        goto block_2;
    }
    fn_80160430(arg0);
block_2:
    fn_8016293C(arg0, arg1);
    return;
}

extern s32 lbl_804B17F0;

s32 w3d_auto_80160da8(s32 arg0, void *arg1) {
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg1, s32 *, 4);
    if (temp_r0 == 0) {
        goto block_3;
    }
    if (temp_r0 == 2) {
        goto block_6;
    }
    goto block_7;
block_3:
    if ((s32) M2C_FIELD(arg1, s32 *, 0x10) != 1) {
        goto block_5;
    }
    fn_80160780(lbl_804B17F0, M2C_FIELD(arg1, s32 *, 8), M2C_FIELD(arg1, s32 *, 0xC));
    goto block_7;
block_5:
    fn_80160828(lbl_804B17F0, M2C_FIELD(arg1, s32 *, 8), M2C_FIELD(arg1, s32 *, 0xC));
    goto block_7;
block_6:
    fn_801608D0(lbl_804B17F0, M2C_FIELD(arg1, s32 *, 8), M2C_FIELD(arg1, s32 *, 0xC), M2C_FIELD(arg1, s32 *, 0x10));
block_7:
    return 0;
}

extern M2C_UNK lbl_80411728[];
extern M2C_UNK lbl_80411750[];

void *w3d_auto_8016115c(void *arg0) {
    fn_8020FBD0();
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &(*lbl_80411728);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_80411750);
    return arg0;
}

void w3d_auto_8016132c(s32 arg0, s32 arg1) {
    fn_801613B8(arg0);
    if (!(arg1 & 1)) {
        goto block_2;
    }
    fn_801FE1F8(arg0);
block_2:
    return;
}

s32 w3d_auto_8016274c(s32 arg0, s32 arg1, s32 *arg2) {
    *arg2 = 0;
    return 0x80004005;
}

extern M2C_UNK lbl_80411868[];
extern M2C_UNK lbl_80411890[];

void *w3d_auto_801629f8(void *arg0) {
    fn_8020FBD0();
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &(*lbl_80411868);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_80411890);
    return arg0;
}

extern M2C_UNK lbl_80411970[];
extern s32 lbl_804B188C;

M2C_UNK **w3d_auto_801653ac(M2C_UNK **arg0) {
    fn_801628B0();
    *arg0 = &(*lbl_80411970);
    lbl_804B188C = 0;
    return arg0;
}

extern s32 lbl_804B188C;

s32 w3d_auto_80165420(s32 arg0, s32 arg1) {
    lbl_804B188C = arg1;
    return 0;
}

extern M2C_UNK lbl_80455274[];
extern s32 lbl_804B00CC;

void w3d_auto_80165520(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_80455274));
    lbl_804B00CC = fn_801654B8();
block_3:
    return;
}

extern M2C_UNK lbl_804552B0[];

void w3d_auto_8016568c(void) {
    fn_8020FCB4(&(*lbl_804552B0));
    return;
}

extern s32 lbl_804B1884;

void w3d_auto_8016a438(s32 arg0, void *arg1) {
    if ((s32) M2C_FIELD(arg1, s32 *, 0x18) == 0) {
        goto block_2;
    }
    fn_8016803C(lbl_804B1884, 0x40);
    return;
block_2:
    fn_8016804C(lbl_804B1884, 0x40);
    return;
}

void w3d_auto_8016df8c(s32 arg0, s32 arg1) {
    fn_8016E698(arg0);
    if (!(arg1 & 1)) {
        goto block_2;
    }
    fn_801FE1F8(arg0);
block_2:
    return;
}

void w3d_auto_8016ee10(s32 arg0, s32 *arg1) {
    s32 sp8;

    sp8 = *arg1;
    fn_80308FC0(&sp8, 0xFFFFFF);
    return;
}

extern M2C_UNK lbl_80455970[];
extern s32 lbl_804B0120;

void w3d_auto_8016f5dc(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_80455970));
    lbl_804B0120 = fn_8016F574();
block_3:
    return;
}

extern M2C_UNK lbl_803A6698[];
extern M2C_UNK lbl_803A66A8[];
extern M2C_UNK lbl_803A66B4[];

s32 w3d_auto_80171d3c(void *arg0, void **arg1) {
    s32 var_r3;

    var_r3 = fn_801904C0();
    if (var_r3 < 0) {
        goto block_2;
    }
    M2C_FIELD(*arg1, M2C_UNK (**)(void **, s32, M2C_UNK *), 0x20)(arg1, M2C_FIELD(arg0, s32 *, 0x4C), &(*lbl_803A6698));
    M2C_FIELD(*arg1, M2C_UNK (**)(void **, u16, M2C_UNK *, M2C_UNK), 0x44)(arg1, M2C_FIELD(arg0, u16 *, 0x2C), &(*lbl_803A66A8), 0);
    M2C_FIELD(*arg1, M2C_UNK (**)(void **, u16, M2C_UNK *, M2C_UNK), 0x44)(arg1, M2C_FIELD(arg0, u16 *, 0x2E), &(*lbl_803A66B4), 0);
    var_r3 = 0;
block_2:
    return var_r3;
}

extern M2C_UNK lbl_80412120[];

void *w3d_auto_80174230(void *arg0) {
    fn_801902E8();
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_80412120);
    return arg0;
}

extern M2C_UNK lbl_803A67AC[];

s32 w3d_auto_801749dc(void *arg0, void **arg1) {
    s32 var_r3;

    var_r3 = fn_801904C0();
    if (var_r3 < 0) {
        goto block_2;
    }
    M2C_FIELD(*arg1, M2C_UNK (**)(void **, u16, M2C_UNK *, M2C_UNK), 0x44)(arg1, M2C_FIELD(arg0, u16 *, 0x2C), &(*lbl_803A67AC), 0);
    var_r3 = 0;
block_2:
    return var_r3;
}

extern M2C_UNK lbl_803A67AC[];

s32 w3d_auto_80174a3c(s32 arg0, void **arg1) {
    s32 var_r3;

    var_r3 = fn_80190538();
    if (var_r3 < 0) {
        goto block_2;
    }
    M2C_FIELD(*arg1, M2C_UNK (**)(void **, s32, M2C_UNK *), 0x78)(arg1, arg0 + 0x2C, &(*lbl_803A67AC));
    var_r3 = 0;
block_2:
    return var_r3;
}

s32 w3d_auto_801788d0(s32 arg0, s32 arg1, s32 *arg2) {
    *arg2 = 0;
    return 0x80004005;
}

s32 w3d_auto_8017984c(s32 arg0, s32 arg1, s32 *arg2) {
    *arg2 = 0;
    return 0x80004005;
}

s32 w3d_auto_80179860(s32 arg0) {
    s32 var_r3;

    var_r3 = arg0;
    if (var_r3 == 0) {
        goto block_2;
    }
    var_r3 = fn_80178958(arg0, 3);
block_2:
    return var_r3;
}

extern M2C_UNK lbl_80457014[];

void w3d_auto_8017b8c4(void) {
    fn_8020FCB4(&(*lbl_80457014));
    return;
}

extern M2C_UNK lbl_803A7550[];
extern M2C_UNK lbl_803A755C[];

s32 w3d_auto_8017d55c(void *arg0, M2C_UNK *arg1, M2C_UNK *arg2, s32 arg3) {
    if (arg1 != NULL) {
        goto block_2;
    }
    fn_8020BD38(arg0 + 0x265C, &(*lbl_803A7550));
    goto block_3;
block_2:
    fn_8020BD38(arg0 + 0x265C, arg1);
block_3:
    if (arg2 != NULL) {
        goto block_5;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x2664) = arg2;
    fn_8020BD38(arg0 + 0x2660, &(*lbl_803A755C));
    goto block_6;
block_5:
    M2C_FIELD(arg0, M2C_UNK **, 0x2664) = (M2C_UNK *)1;
    fn_8020BD38(arg0 + 0x2660, arg2);
block_6:
    M2C_FIELD(arg0, s32 *, 0x2668) = arg3;
    if (arg3 == 0) {
        goto block_8;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x2664) = NULL;
block_8:
    return 0;
}

s32 w3d_auto_8017df28(s32 arg0, s32 arg1) {
    M2C_UNK sp8;
    s32 var_r3;

    var_r3 = fn_8017E22C(arg0, arg1, &sp8);
    if (var_r3 < 0) {
        goto block_2;
    }
    var_r3 = 0x80004001;
block_2:
    return var_r3;
}

extern M2C_UNK lbl_803A7788[];
extern M2C_UNK lbl_803A7794[];

s32 w3d_auto_8017fa1c(void *arg0, void **arg1) {
    s32 var_r3;

    var_r3 = fn_801904C0();
    if (var_r3 < 0) {
        goto block_2;
    }
    M2C_FIELD(*arg1, M2C_UNK (**)(void **, s32, M2C_UNK *), 0x20)(arg1, M2C_FIELD(arg0, s32 *, 0x28), &(*lbl_803A7788));
    M2C_FIELD(*arg1, M2C_UNK (**)(void **, u16, M2C_UNK *, M2C_UNK), 0x44)(arg1, M2C_FIELD(arg0, u16 *, 0x24), &(*lbl_803A7794), 0);
    var_r3 = 0;
block_2:
    return var_r3;
}

extern M2C_UNK lbl_803A7B9C[];

s32 w3d_auto_80188818(void *arg0, void **arg1) {
    s32 var_r3;

    var_r3 = fn_801904C0();
    if (var_r3 < 0) {
        goto block_2;
    }
    M2C_FIELD(*arg1, M2C_UNK (**)(void **, s32, M2C_UNK *), 0x20)(arg1, M2C_FIELD(arg0, s32 *, 0x34), &(*lbl_803A7B9C));
    var_r3 = 0x80004001;
block_2:
    return var_r3;
}

extern M2C_UNK lbl_80459780[];
extern s32 lbl_804B0280;

void w3d_auto_8018e140(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_80459780));
    lbl_804B0280 = fn_8018E0D8();
block_3:
    return;
}

extern M2C_UNK lbl_804131B0[];

void *w3d_auto_8018e4cc(void *arg0) {
    fn_8018E26C();
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_804131B0);
    return arg0;
}

extern M2C_UNK lbl_803A7FD4[];

s32 w3d_auto_8018e560(s32 arg0) {
    fn_801EC0F8(arg0, &(*lbl_803A7FD4));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_80413188[];

void *w3d_auto_8018e658(void *arg0) {
    fn_8018E26C();
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_80413188);
    return arg0;
}

extern M2C_UNK lbl_803A7FFC[];

s32 w3d_auto_8018e6ec(s32 arg0) {
    fn_801EBF38(arg0, &(*lbl_803A7FFC));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_803A804C[];

s32 w3d_auto_8018eac4(s32 arg0) {
    fn_801EC52C(arg0, &(*lbl_803A804C));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_804130E8[];

void *w3d_auto_8018ed90(void *arg0) {
    fn_8018E26C();
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_804130E8);
    return arg0;
}

extern M2C_UNK lbl_803A80A0[];

s32 w3d_auto_8018ee44(s32 arg0) {
    fn_801ECC6C(arg0, &(*lbl_803A80A0));
    fn_801E8D9C(arg0);
    return 0;
}

void w3d_auto_8018ffb0(s32 arg0, s32 arg1) {
    fn_801EF174(arg0, 0x30, 1, arg1);
    return;
}

void w3d_auto_8018ffdc(s32 arg0, s32 arg1) {
    fn_801EF174(arg0, 0x2C, 2, arg1);
    return;
}

void w3d_auto_80190008(s32 arg0, s32 arg1) {
    fn_801EF174(arg0, 0x28, 3, arg1);
    return;
}

void w3d_auto_80190034(s32 arg0, s32 arg1) {
    fn_801EF174(arg0, 0x24, 4, arg1);
    return;
}

void w3d_auto_80190060(s32 arg0, s32 arg1) {
    fn_801EF174(arg0, 0x20, 5, arg1);
    return;
}
