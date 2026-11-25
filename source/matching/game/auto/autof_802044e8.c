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

M2C_UNK fn_802047E0(void *, s32, s32);                           /* extern */
M2C_UNK fn_8020FCB4(M2C_UNK *);                     /* extern */
M2C_UNK fn_801FE2D4(s32, s32, s32, M2C_UNK *, M2C_UNK);            /* extern */
M2C_UNK fn_80209B04(M2C_UNK *, M2C_UNK);            /* extern */
M2C_UNK fn_801FE1F8();                              /* extern */
s32 fn_8020B354();                                  /* extern */
M2C_UNK fn_8020EE9C(M2C_UNK *);                     /* extern */
M2C_UNK fn_8020B680(M2C_UNK *);                     /* extern */
M2C_UNK fn_8020FBD0(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK fn_80210AFC(M2C_UNK *);                     /* extern */
M2C_UNK fn_8035D27C(M2C_UNK *, M2C_UNK);            /* extern */
M2C_UNK fn_8020BB54(void *, M2C_UNK *);                     /* extern */
s32 fn_8021048C(s32, M2C_UNK);                      /* extern */
M2C_UNK fn_80218300();                              /* extern */
M2C_UNK fn_802E4CD4();                              /* extern */
M2C_UNK fn_802F565C();                              /* extern */
M2C_UNK fn_800C56B8(s32);                           /* extern */
s16 fn_8015F5A0(M2C_UNK *, M2C_UNK);                /* extern */
void *fn_801613F0(void *, M2C_UNK);                    /* extern */
M2C_UNK fn_8016239C(void *);                        /* extern */
s32 fn_8021D024();                                  /* extern */
M2C_UNK fn_801298CC(void *);                           /* extern */
M2C_UNK fn_8015F518(M2C_UNK *, M2C_UNK *);          /* extern */
M2C_UNK fn_8021EF08();                              /* extern */
M2C_UNK fn_801E8D9C(s32);                           /* extern */
M2C_UNK fn_801ECE2C(s32, M2C_UNK *);                     /* extern */
M2C_UNK fn_801EBF38(s32, M2C_UNK *);                /* extern */
M2C_UNK fn_801EF174(s32, M2C_UNK, M2C_UNK, void *);         /* extern */
M2C_UNK fn_801ECC6C(s32, M2C_UNK *);                     /* extern */
M2C_UNK fn_80236120();                              /* extern */
M2C_UNK fn_801EA0EC();                              /* extern */
M2C_UNK fn_801EBBB8(s32, M2C_UNK *);                     /* extern */
M2C_UNK fn_80238D88();                              /* extern */

void w3d_auto_802044e8(s32 arg0, s32 arg1, s32 arg2) {
    fn_802047E0(arg0, arg1, arg2 * 8);
    return;
}

void w3d_auto_8020450c(s32 arg0, s32 arg1, s32 arg2) {
    fn_802047E0(arg0, arg1, arg2 * 8);
    return;
}

void w3d_auto_80204550(s32 arg0, s32 arg1, s32 arg2) {
    fn_802047E0(arg0, arg1, arg2 * 8);
    return;
}

extern M2C_UNK lbl_8045EDF4[];

void w3d_auto_8020593c(void) {
    fn_8020FCB4(&(*lbl_8045EDF4));
    return;
}

extern M2C_UNK lbl_8045EE24[];

void w3d_auto_80206de4(void) {
    fn_8020FCB4(&(*lbl_8045EE24));
    return;
}

extern M2C_UNK lbl_803B2E98[];

void w3d_auto_8020908c(s32 arg0, s32 arg1, s32 arg2) {
    fn_801FE2D4(arg0, arg1, arg2, &(*lbl_803B2E98), 0x82);
    return;
}

extern M2C_UNK lbl_80462E90[];

void w3d_auto_80209a44(void) {
    fn_80209B04(&(*lbl_80462E90), 2);
    return;
}

void w3d_auto_80209b04(s32 arg0, s32 arg1) {
    if (!(arg1 & 1)) {
        goto block_2;
    }
    fn_801FE1F8();
block_2:
    return;
}

s32 w3d_auto_8020b104(s32 arg0, s32 arg1, s32 arg2, s32 *arg3) {
    if (arg3 == NULL) {
        goto block_2;
    }
    *arg3 = arg2;
block_2:
    return 0;
}

s32 w3d_auto_8020b118(s32 arg0, s32 arg1, s32 arg2, s32 *arg3) {
    if (arg3 == NULL) {
        goto block_2;
    }
    *arg3 = 0;
block_2:
    return 0;
}

extern M2C_UNK lbl_804632F4[];
extern s32 lbl_804B0694;

void w3d_auto_8020b5d4(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_804632F4));
    lbl_804B0694 = fn_8020B354();
block_3:
    return;
}

extern M2C_UNK lbl_80418DE0[];

void w3d_auto_8020b6c0(void) {
    fn_8020B680(&(*lbl_80418DE0));
    return;
}

extern M2C_UNK lbl_80463360[];

void w3d_auto_8020ded8(void) {
    fn_8020FCB4(&(*lbl_80463360));
    return;
}

extern M2C_UNK lbl_80365A18[];
extern M2C_UNK lbl_803EA29C[];

void w3d_auto_8020fd7c(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020FBD0(&(*lbl_80365A18), &(*lbl_803EA29C), &(*lbl_80365A18), 0, 4, 0);
block_3:
    return;
}

extern M2C_UNK lbl_80463BE0[];

s32 w3d_auto_80210344(void) {
    fn_80210AFC(&(*lbl_80463BE0));
    return 0;
}

extern M2C_UNK lbl_80463C04[];

void w3d_auto_802105e4(void) {
    fn_8035D27C(&(*lbl_80463C04), 2);
    return;
}

extern M2C_UNK lbl_803B35B8[];

s32 w3d_auto_80210958(s32 arg0) {
    fn_8020BB54(arg0, &(*lbl_803B35B8));
    return arg0;
}

s32 w3d_auto_80212aa4(s32 arg0, s32 arg1) {
    s32 var_r3;

    var_r3 = fn_8021048C(arg1, 0);
    if (var_r3 != 0) {
        goto block_2;
    }
    var_r3 = fn_8021048C(arg1, 0);
block_2:
    return var_r3;
}

extern M2C_UNK lbl_804197D8[];
extern M2C_UNK **lbl_804ABAA4;

M2C_UNK **w3d_auto_80218284(M2C_UNK **arg0) {
    fn_80218300();
    *arg0 = &(*lbl_804197D8);
    fn_802F565C();
    fn_802E4CD4();
    lbl_804ABAA4 = arg0;
    return arg0;
}

s32 w3d_auto_802185f8(s32 arg0, s32 arg1, s32 arg2, s32 *arg3) {
    *arg3 = 0;
    return 0;
}

s32 w3d_auto_8021875c(s32 arg0, s32 *arg1) {
    *arg1 = 0;
    return 0;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804B074C;
extern s32 lbl_804B1754;

void w3d_auto_8021a704(void *arg0) {
    void *temp_r30;

    temp_r30 = fn_801613F0(lbl_804B1754, 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804B074C, 1);
    M2C_FIELD(temp_r30, M2C_UNK **, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    fn_800C56B8(M2C_FIELD(arg0, s32 *, 0x58));
    return;
}

extern M2C_UNK lbl_804641DC[];
extern s32 lbl_804B0794;

void w3d_auto_8021d088(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_804641DC));
    lbl_804B0794 = fn_8021D024();
block_3:
    return;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804B079C;
extern s32 lbl_804B1754;

void w3d_auto_8021de00(void) {
    void *temp_r30;

    temp_r30 = fn_801613F0(lbl_804B1754, 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804B079C, 1);
    M2C_FIELD(temp_r30, M2C_UNK **, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    return;
}

extern void *lbl_804ABAC0;
extern s32 lbl_804B1788;

void w3d_auto_8021de58(s32 arg0, void *arg1) {
    void *temp_r30;

    temp_r30 = lbl_804ABAC0;
    M2C_FIELD(arg1, s32 *, 0x14) = 0;
    fn_801298CC(lbl_804B1788);
    M2C_FIELD(temp_r30, s32 *, 0xA0) = 1;
    return;
}

void w3d_auto_8021debc(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0x44) = 1;
    return;
}

extern M2C_UNK lbl_803B4F04[];
extern M2C_UNK lbl_803B4F18[];
extern M2C_UNK lbl_804B079C;
extern M2C_UNK lbl_804B07A4;

void w3d_auto_8021e8b0(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804B079C, &(*lbl_803B4F04));
    fn_8015F518(&lbl_804B07A4, &(*lbl_803B4F18));
block_3:
    return;
}

extern M2C_UNK lbl_803B4FDC[];
extern M2C_UNK lbl_804B07AC;

void w3d_auto_8021ec9c(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804B07AC, &(*lbl_803B4FDC));
block_3:
    return;
}

extern M2C_UNK lbl_803B4FFC[];
extern M2C_UNK lbl_803B5008[];
extern M2C_UNK lbl_804B07B4;
extern M2C_UNK lbl_804B07BC;

void w3d_auto_8021ed1c(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804B07B4, &(*lbl_803B4FFC));
    fn_8015F518(&lbl_804B07BC, &(*lbl_803B5008));
block_3:
    return;
}

extern M2C_UNK lbl_803B5048[];
extern M2C_UNK lbl_803B5054[];
extern M2C_UNK lbl_804B07C4;
extern M2C_UNK lbl_804B07CC;

void w3d_auto_8021edd0(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804B07C4, &(*lbl_803B5048));
    fn_8015F518(&lbl_804B07CC, &(*lbl_803B5054));
block_3:
    return;
}

extern M2C_UNK lbl_8041A320[];

void *w3d_auto_802254cc(void *arg0) {
    fn_8021EF08();
    M2C_FIELD(arg0, s32 *, 0x74) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_8041A320);
    return arg0;
}

extern M2C_UNK lbl_803B7CC8[];

s32 w3d_auto_80225560(s32 arg0) {
    fn_801ECE2C(arg0, &(*lbl_803B7CC8));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_803B8140[];
extern M2C_UNK lbl_803B8170[];

s32 w3d_auto_80227290(s32 arg0) {
    fn_801ECE2C(arg0, &(*lbl_803B8140));
    fn_801EBF38(arg0, &(*lbl_803B8170));
    fn_801E8D9C(arg0);
    return 0;
}

void w3d_auto_80231fd0(s32 arg0, s32 arg1) {
    fn_801EF174(arg0, 0x34, 2, arg1);
    return;
}

extern M2C_UNK lbl_803BABA8[];

s32 w3d_auto_802361dc(s32 arg0) {
    fn_801ECC6C(arg0, &(*lbl_803BABA8));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_8041A860[];

void *w3d_auto_802362d4(void *arg0) {
    fn_80236120();
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_8041A860);
    return arg0;
}

extern M2C_UNK lbl_803BABD4[];

s32 w3d_auto_80236368(s32 arg0) {
    fn_801ECE2C(arg0, &(*lbl_803BABD4));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_8041B0A8[];

void *w3d_auto_80238d88(void *arg0) {
    fn_801EA0EC();
    M2C_FIELD(arg0, s16 *, 0x14) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_8041B0A8);
    return arg0;
}

extern M2C_UNK lbl_803BB1C0[];

s32 w3d_auto_80238e1c(s32 arg0) {
    fn_801EBBB8(arg0, &(*lbl_803BB1C0));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_8041B030[];

void *w3d_auto_8023944c(void *arg0) {
    fn_80238D88();
    M2C_FIELD(arg0, s16 *, 0x18) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_8041B030);
    return arg0;
}
