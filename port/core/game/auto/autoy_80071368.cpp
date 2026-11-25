#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autoy_80071368.c"
/* Decompiled automatically by m2c; statement order or callee return width
 * adjusted by tools/m2c_reorder.py and verified identical to the original
 * after linking. Types and names are m2c placeholders pending review. */
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
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)(w3d::bytes(expr) + (offset)))

/* Bitwise (reinterpret) cast */
#define M2C_BITWISE(type, expr) ((w3d::slot_t<type>)(expr))

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

M2C_UNK fn_8010A8E0(Ptr32<void>, u16, Ptr32<M2C_UNK>);           /* extern */
s32 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
s32 fn_801613F0(Ptr32<void>, M2C_UNK);                      /* extern */
M2C_UNK fn_8016239C();                              /* extern */
extern M2C_UNK lbl_8037CA78[];
extern M2C_UNK lbl_804AD934;
extern s32 lbl_804B1754;
M2C_UNK fn_8015A6B8(Ptr32<void>, s32);                      /* extern */
extern M2C_UNK lbl_8037CCCC[];
extern M2C_UNK lbl_8037CCDC[];
extern M2C_UNK lbl_8037CCF4[];
extern M2C_UNK lbl_8037CCFC[];
extern M2C_UNK lbl_8037CD04[];
extern M2C_UNK lbl_8037CD10[];
extern M2C_UNK lbl_8037CD1C[];
extern M2C_UNK lbl_8037CD28[];
extern M2C_UNK lbl_804AD954;
M2C_UNK fn_800D308C(Ptr32<void>, Ptr32<void>);                      /* extern */
extern M2C_UNK lbl_8037E910[];
extern M2C_UNK lbl_8037E920[];
extern M2C_UNK lbl_8037E928[];
extern M2C_UNK lbl_8037E938[];
extern M2C_UNK lbl_8037E944[];
extern M2C_UNK lbl_8037E95C[];
extern M2C_UNK lbl_8037E968[];
extern M2C_UNK lbl_8037E974[];
extern M2C_UNK lbl_804ADE10;
extern M2C_UNK lbl_804ADE18;
M2C_UNK fn_80098F24(Ptr32<void>);                        /* extern */
M2C_UNK fn_80099AA8(Ptr32<void>, u8);                    void fn_80099DBC(Ptr32<void>, s32);                   /* extern */
s32 fn_802CBA50(s32);                               /* extern */
s32 fn_802CBACC(s32);                               /* extern */
s32 fn_802CBB5C(s32);                               /* extern */
s32 fn_802CBC68(s32);                                /* extern */
s32 fn_802CCB40(s32);                               /* extern */
M2C_UNK fn_802CD2E0(s32, M2C_UNK);                  /* extern */
M2C_UNK fn_800A7BB4(Ptr32<void>, u16, s32);              /* extern */
M2C_UNK fn_800A7FDC(Ptr32<void>);                        /* extern */
extern M2C_UNK lbl_804AE288;
M2C_UNK fn_8015FEF0();                              /* extern */
extern M2C_UNK lbl_8040FCC8[];
M2C_UNK fn_801190B4(Ptr32<void>, u16, s32);                 /* extern */
extern M2C_UNK lbl_804AEA70;
M2C_UNK fn_800A82F0(Ptr32<void>, u16, s32);                 /* extern */
extern M2C_UNK lbl_804AEBEC;
Ptr32<void> fn_80165254();                                /* extern */
M2C_UNK fn_800E6738();                              /* extern */
extern M2C_UNK lbl_8040FEB8[];
M2C_UNK fn_80125FDC(Ptr32<void>, u16, s32);                 /* extern */
extern M2C_UNK lbl_804AEDAC;
extern M2C_UNK lbl_804AEDCC;
extern M2C_UNK lbl_804AEDD4;
M2C_UNK fn_800EA530(Ptr32<void>);                        /* extern */
M2C_UNK fn_800EB064(Ptr32<void>);                        /* extern */
M2C_UNK fn_800ECB20(Ptr32<void>);                        /* extern */
s32 fn_8010A8FC(Ptr32<u16>);                             /* extern */
s32 fn_8015F65C(u16, Ptr32<M2C_UNK>);                    /* extern */
s32 fn_8015FB34(Ptr32<void>, Ptr32<u16>);                     /* extern */
s32 fn_802EF234(Ptr32<void>, Ptr32<void>);                          /* extern */
extern M2C_UNK lbl_804AEF20;
extern M2C_UNK lbl_804AEF50;
extern M2C_UNK lbl_804AEF30;
M2C_UNK fn_80161014();                              /* extern */
extern M2C_UNK lbl_80410268[];
extern Ptr32<void> lbl_804AAF04;
M2C_UNK fn_80181814(s32, s32, f32, f32);            /* extern */
extern f32 lbl_8039F8E8[];
extern f32 lbl_8039F8EC[];
extern f32 lbl_8039F8F0[];
extern s32 lbl_804AB31C;
extern s32 lbl_804AB320;
s32 fn_801FE2A8(s32, M2C_UNK);                      /* extern */
s32 fn_8017B348();                                  /* extern */
extern s32 lbl_804AB59C;
M2C_UNK fn_8018E26C();                              /* extern */
extern f32 lbl_803A8048[];
extern M2C_UNK lbl_80413138[];
M2C_UNK fn_801EA0EC();                              /* extern */
extern M2C_UNK lbl_80413508[];
M2C_UNK fn_801CB41C();                              /* extern */
extern f32 lbl_803AE3A0[];
extern M2C_UNK lbl_80416050[];
extern f32 lbl_803AE3E4[];
extern M2C_UNK lbl_80416028[];
Ptr32<void> fn_801FE1D8(M2C_UNK);                         /* extern */
s32 fn_801FE220(s32);                               /* extern */
extern M2C_UNK lbl_803B31B8[];
M2C_UNK fn_80207FEC(Ptr32<void>);                        /* extern */
M2C_UNK fn_8021CBC8();                              /* extern */
extern M2C_UNK lbl_80419C68[];
extern s32 lbl_804ABAB4;
extern Ptr32<void> lbl_804ABAC0;
extern M2C_UNK lbl_8041A190[];
M2C_UNK fn_80238D88();                              /* extern */
extern M2C_UNK lbl_8041AF90[];
M2C_UNK fn_800A4ED0(Ptr32<void>, u16, M2C_UNK, s32, s32, s32); /* extern */
extern M2C_UNK lbl_804B090C;
M2C_UNK fn_8026CC60(Ptr32<void>);                        /* extern */

void w3d_auto_80071368(void) {
    s32 temp_r30;

    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30), fn_8015F5A0(&lbl_804AD934, 1), &(*lbl_8037CA78));
    fn_8016239C();
    return;
}

void w3d_auto_80072a14(s32 arg0, s32 arg1) {
    s32 temp_r30;
    s32 temp_r30_2;
    s32 temp_r30_3;
    s32 temp_r30_4;
    s32 temp_r30_5;
    s32 temp_r30_6;
    s32 temp_r30_7;
    s32 temp_r30_8;

    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30), fn_8015F5A0(&lbl_804AD954, 1), &(*lbl_8037CCCC));
    fn_8016239C();
    temp_r30_2 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30_2), fn_8015F5A0(&lbl_804AD954, 1), &(*lbl_8037CCDC));
    fn_8016239C();
    temp_r30_3 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30_3), fn_8015F5A0(&lbl_804AD954, 1), &(*lbl_8037CCF4));
    fn_8016239C();
    temp_r30_4 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30_4), fn_8015F5A0(&lbl_804AD954, 1), &(*lbl_8037CCFC));
    fn_8016239C();
    temp_r30_5 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30_5), fn_8015F5A0(&lbl_804AD954, 1), &(*lbl_8037CD04));
    fn_8016239C();
    temp_r30_6 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30_6), fn_8015F5A0(&lbl_804AD954, 1), &(*lbl_8037CD10));
    fn_8016239C();
    temp_r30_7 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30_7), fn_8015F5A0(&lbl_804AD954, 1), &(*lbl_8037CD1C));
    fn_8016239C();
    temp_r30_8 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30_8), fn_8015F5A0(&lbl_804AD954, 1), &(*lbl_8037CD28));
    fn_8016239C();
    fn_8015A6B8(w3d::G(arg0), arg1);
    return;
}

void w3d_auto_80092f64(s32 arg0, s32 arg1) {
    s32 temp_r30;
    s32 temp_r30_2;
    s32 temp_r30_3;
    s32 temp_r30_4;
    s32 temp_r30_5;
    s32 temp_r30_6;
    s32 temp_r30_7;
    s32 temp_r30_8;

    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30), fn_8015F5A0(&lbl_804ADE18, 1), &(*lbl_8037E910));
    fn_8016239C();
    temp_r30_2 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30_2), fn_8015F5A0(&lbl_804ADE18, 1), &(*lbl_8037E920));
    fn_8016239C();
    temp_r30_3 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30_3), fn_8015F5A0(&lbl_804ADE10, 1), &(*lbl_8037E928));
    fn_8016239C();
    temp_r30_4 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30_4), fn_8015F5A0(&lbl_804ADE10, 1), &(*lbl_8037E938));
    fn_8016239C();
    temp_r30_5 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30_5), fn_8015F5A0(&lbl_804ADE10, 1), &(*lbl_8037E944));
    fn_8016239C();
    temp_r30_6 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30_6), fn_8015F5A0(&lbl_804ADE10, 1), &(*lbl_8037E95C));
    fn_8016239C();
    temp_r30_7 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30_7), fn_8015F5A0(&lbl_804ADE10, 1), &(*lbl_8037E968));
    fn_8016239C();
    temp_r30_8 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30_8), fn_8015F5A0(&lbl_804ADE10, 1), &(*lbl_8037E974));
    fn_8016239C();
    fn_800D308C(w3d::G(arg0), w3d::G(arg1));
    return;
}

s32 w3d_auto_80098cec(Ptr32<void> arg0) {
    if (fn_802CCB40(M2C_FIELD(arg0, s32 *, 0x20)) == 0) {
        goto block_2;
    }
    fn_802CD2E0(M2C_FIELD(arg0, s32 *, 0x20), 0);
    fn_80098F24(arg0);
block_2:
    if ((s32) M2C_FIELD(arg0, s32 *, 0x24) != 0) {
        goto block_5;
    }
    if (fn_802CBACC(M2C_FIELD(arg0, s32 *, 0x20)) == 0) {
        goto block_7;
    }
    fn_80099AA8(arg0, fn_802CBC68(M2C_FIELD(arg0, s32 *, 0x20)));
    goto block_7;
block_5:
    if (fn_802CBA50(M2C_FIELD(arg0, s32 *, 0x20)) == 0) {
        goto block_7;
    }
    fn_80099DBC(arg0, fn_802CBB5C(M2C_FIELD(arg0, s32 *, 0x20)));
block_7:
    return 0x64;
}

s32 w3d_auto_800a66b4(Ptr32<void> arg0, u32 arg1) {
    u32 temp_r9;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x38) == 0) {
        goto block_3;
    }
    if (arg1 < (u32) M2C_FIELD(arg0, u32 *, 0x40)) {
        goto block_3;
    }
loop_2:
    fn_800A7BB4(arg0, fn_8015F5A0(&lbl_804AE288, 1), M2C_FIELD(arg0, s32 *, 0x38));
    temp_r9 = M2C_FIELD(arg0, u32 *, 0x40) + 0x32;
    M2C_FIELD(arg0, u32 *, 0x40) = temp_r9;
    if (arg1 >= temp_r9) {
        goto loop_2;
    }
block_3:
    if (!(M2C_FIELD(arg0, s32 *, 0x60) & 0x800000)) {
        goto block_5;
    }
    fn_800A7FDC(arg0);
block_5:
    return 0xA;
}

Ptr32<void> w3d_auto_800d5364(Ptr32<void> arg0) {
    fn_8015FEF0();
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8040FCC8);
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    return arg0;
}

void w3d_auto_800d5f98(Ptr32<void> arg0) {
    s32 temp_r30;

    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_801190B4(w3d::G(temp_r30), fn_8015F5A0(&lbl_804AEA70, 1), M2C_FIELD(arg0, s32 *, 0x14));
    fn_8016239C();
    return;
}

void w3d_auto_800dafa4(Ptr32<void> arg0) {
    s32 temp_r30;

    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_800A82F0(w3d::G(temp_r30), fn_8015F5A0(&lbl_804AEBEC, 1), M2C_FIELD(arg0, s32 *, 0xA4));
    fn_8016239C();
    return;
}

void w3d_auto_800dc6a8(Ptr32<void> arg0, s32 arg1) {
    s32 var_r0;

    M2C_FIELD(arg0, s8 *, 0x68) = 0;
    if (arg1 == 0) {
        goto block_2;
    }
    var_r0 = M2C_FIELD(fn_80165254(), s32 *, 0x34);
    goto block_3;
block_2:
    var_r0 = M2C_FIELD(fn_80165254(), s32 *, 0x30);
block_3:
    M2C_FIELD(arg0, s32 *, 0x6C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x64) = var_r0;
    return;
}

Ptr32<void> w3d_auto_800de6c4(Ptr32<void> arg0) {
    fn_800E6738();
    M2C_FIELD(arg0, s32 *, 0xB0) = -1;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0x70) = &(*lbl_8040FEB8);
    M2C_FIELD(arg0, s32 *, 0xB4) = -1;
    return arg0;
}

void w3d_auto_800e5bb8(s32 arg0) {
    s32 temp_r30;

    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_80125FDC(w3d::G(temp_r30), fn_8015F5A0(&lbl_804AEDAC, 1), arg0);
    fn_8016239C();
    return;
}

void w3d_auto_800e5c10(s32 arg0, s32 arg1) {
    s32 temp_r30;
    s32 temp_r30_2;

    if (arg1 == 0) {
        goto block_2;
    }
    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_80125FDC(w3d::G(temp_r30), fn_8015F5A0(&lbl_804AEDCC, 1), arg0);
    fn_8016239C();
    return;
block_2:
    temp_r30_2 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_80125FDC(w3d::G(temp_r30_2), fn_8015F5A0(&lbl_804AEDD4, 1), arg0);
    fn_8016239C();
    return;
}

void w3d_auto_800e7238(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xA8) = arg1;
    M2C_FIELD(arg0, s32 *, 0x64) = arg1;
    return;
}

s32 w3d_auto_800ea62c(Ptr32<void> arg0, Ptr32<u16> arg1) {
    s32 temp_r30_2;
    u16 temp_r30;
    Ptr32<Ptr32<void>> temp_r9;

    temp_r30 = *arg1;
    if ((s32) temp_r30 == 0x40) {
        goto block_3;
    }
    if ((s32) temp_r30 == 0x42) {
        goto block_6;
    }
    goto block_7;
block_3:
    if (fn_8015FB34(arg0, arg1) < 0) {
        goto block_5;
    }
    fn_800EB064(arg0);
    goto block_14;
block_5:
    return 0x80004005;
block_6:
    fn_800EA530(arg0);
    goto block_11;
block_7:
    if (fn_8015F65C(temp_r30, &lbl_804AEF20) == 0) {
        goto block_10;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x58) == 0) {
        goto block_10;
    }
    M2C_FIELD(M2C_FIELD(arg0, Ptr32<void> *, 0), Ptr32<M2C_UNK (Ptr32<void>)> *, 0x44)(arg0);
    goto block_14;
block_10:
    if (fn_8015F65C(temp_r30, &lbl_804AEF50) != 0) {
        goto block_12;
    }
block_11:
    return fn_8015FB34(arg0, arg1);
block_12:
    temp_r30_2 = fn_8010A8FC(arg1);
    temp_r9 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0xC0);
    if (fn_802EF234(w3d::G(temp_r30_2), w3d::G(M2C_FIELD(*temp_r9, Ptr32<s32 (Ptr32<Ptr32<void>>)> *, 0x20)(temp_r9))) != 0) {
        goto block_14;
    }
    fn_800ECB20(arg0);
block_14:
    return 0;
}

void w3d_auto_800edbbc(Ptr32<void> arg0) {
    s32 temp_r30;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x110) == 0) {
        goto block_2;
    }
    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_80125FDC(w3d::G(temp_r30), fn_8015F5A0(&lbl_804AEF30, 1), M2C_FIELD(arg0, s32 *, 0x110));
    fn_8016239C();
    M2C_FIELD(arg0, s32 *, 0x110) = 0;
block_2:
    return;
}

Ptr32<void> w3d_auto_800ee274(Ptr32<void> arg0) {
    fn_80161014();
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_80410268);
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    lbl_804AAF04 = arg0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    return arg0;
}

void w3d_auto_8013c54c(Ptr32<void> arg0, s32 arg1) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x294) == 0) {
        goto block_2;
    }
    fn_80181814(arg1, lbl_804AB31C, (*lbl_8039F8E8), (*lbl_8039F8EC));
    fn_80181814(arg1, lbl_804AB320, (*lbl_8039F8E8), (*lbl_8039F8EC));
    fn_80181814(arg1, lbl_804AB31C, (*lbl_8039F8E8), (*lbl_8039F8F0));
    fn_80181814(arg1, lbl_804AB320, (*lbl_8039F8E8), (*lbl_8039F8F0));
    M2C_FIELD(arg0, f32 *, 0x298) = (f32) (*lbl_8039F8F0);
    M2C_FIELD(arg0, s32 *, 0x294) = 0;
block_2:
    return;
}

void w3d_auto_8016136c(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0) = fn_801FE2A8(arg1, 0x40);
    M2C_FIELD(arg0, s32 *, 8) = arg1;
    M2C_FIELD(arg0, s32 *, 0xC) = arg1;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    return;
}

s32 w3d_auto_8016f43c(Ptr32<void> arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x18) = arg1;
    M2C_FIELD(arg0, s16 *, 0x1A) = arg2;
    return 0;
}

s32 w3d_auto_8016f46c(Ptr32<void> arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x14) = arg1;
    M2C_FIELD(arg0, s16 *, 0x16) = arg2;
    return 0;
}

s32 w3d_auto_80175078(Ptr32<void> arg0) {
    s32 temp_r29;
    Ptr32<Ptr32<void>> temp_r11;

    temp_r29 = fn_8017B348();
    temp_r11 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x74);
    M2C_FIELD(*temp_r11, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, Ptr32<void>)> *, 0x3C)(temp_r11, arg0);
    lbl_804AB59C -= 1;
    return temp_r29;
}

Ptr32<void> w3d_auto_8018ea2c(Ptr32<void> arg0) {
    fn_8018E26C();
    M2C_FIELD(arg0, f32 *, 0x1C) = (f32) (*lbl_803A8048);
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_80413138);
    return arg0;
}

Ptr32<void> w3d_auto_8019bbb4(Ptr32<void> arg0) {
    fn_801EA0EC();
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_80413508);
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    return arg0;
}

s32 w3d_auto_801a6654(Ptr32<void> arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x34) = arg1;
    M2C_FIELD(arg0, s32 *, 0x38) = arg2;
    return 0;
}

Ptr32<void> w3d_auto_801cc9b0(Ptr32<void> arg0) {
    fn_801CB41C();
    M2C_FIELD(arg0, f32 *, 0x18) = (f32) (*lbl_803AE3A0);
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_80416050);
    return arg0;
}

Ptr32<void> w3d_auto_801ccb40(Ptr32<void> arg0) {
    fn_801CB41C();
    M2C_FIELD(arg0, f32 *, 0x18) = (f32) (*lbl_803AE3E4);
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_80416028);
    return arg0;
}

s32 w3d_auto_801d3388(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, s32 *, 0x4C) = (s32) M2C_FIELD(arg0, s32 *, 0x48);
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    return 0;
}

void w3d_auto_801df1e4(Ptr32<void> arg0, f32 farg0, f32 farg1) {
    M2C_FIELD(arg0, f32 *, 0x30) = farg0;
    M2C_FIELD(arg0, f32 *, 0x34) = farg1;
    return;
}

void w3d_auto_801df1f0(Ptr32<void> arg0, f32 farg0, f32 farg1) {
    M2C_FIELD(arg0, f32 *, 0x3C) = farg0;
    M2C_FIELD(arg0, f32 *, 0x38) = farg1;
    return;
}

s32 w3d_auto_801f96c8(Ptr32<void> arg0, Ptr32<void> arg1) {
    M2C_FIELD(arg1, s32 *, 8) = 2;
    M2C_FIELD(arg1, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg1, s32 *, 4) = 0;
    return 0;
}

void w3d_auto_80209e08(Ptr32<void> arg0, s32 arg1) {
    s32 temp_r3_2;
    Ptr32<void> temp_r3;

    temp_r3 = fn_801FE1D8(0x10);
    M2C_FIELD(temp_r3, Ptr32<void> *, 0) = (void *) M2C_FIELD(arg0, Ptr32<void> *, 4);
    temp_r3_2 = fn_801FE220(arg1);
    M2C_FIELD(arg0, Ptr32<void> *, 4) = temp_r3;
    M2C_FIELD(temp_r3, s32 *, 4) = temp_r3_2;
    M2C_FIELD(temp_r3, s32 *, 8) = (s32) (temp_r3_2 + arg1);
    M2C_FIELD(temp_r3, s32 *, 0xC) = temp_r3_2;
    return;
}

s32 w3d_auto_8020d584(Ptr32<void> arg0, Ptr32<void> arg1) {
    M2C_FIELD(arg1, s32 *, 0) = (s32) M2C_FIELD(*M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x14), u16 *, -4);
    M2C_FIELD(arg1, Ptr32<M2C_UNK> *, 4) = &(*lbl_803B31B8);
    return 0;
}

Ptr32<void> w3d_auto_8021a4a0(Ptr32<void> arg0) {
    fn_8021CBC8();
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    M2C_FIELD(arg0, s32 *, 0x48) = 0;
    M2C_FIELD(arg0, s32 *, 0x4C) = 0;
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
    M2C_FIELD(arg0, s32 *, 0x80) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_80419C68);
    fn_80207FEC(arg0 + 0x84);
    lbl_804ABAC0 = arg0;
    M2C_FIELD(arg0, s32 *, 0x74) = 0x64;
    M2C_FIELD(arg0, s32 *, 0x6C) = 0;
    M2C_FIELD(arg0, s32 *, 0x70) = 0;
    M2C_FIELD(arg0, s32 *, 0xA0) = 0;
    lbl_804ABAB4 = 0;
    M2C_FIELD(arg0, s32 *, 0x78) = 0;
    M2C_FIELD(arg0, s32 *, 0x9C) = 0;
    return arg0;
}

Ptr32<void> w3d_auto_802271f8(Ptr32<void> arg0) {
    fn_801EA0EC();
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8041A190);
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    return arg0;
}

Ptr32<void> w3d_auto_80239a58(Ptr32<void> arg0) {
    fn_80238D88();
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8041AF90);
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    return arg0;
}

void w3d_auto_8025d44c(Ptr32<void> arg0) {
    s32 temp_r29;

    temp_r29 = fn_801613F0(w3d::G(lbl_804B1754), 0x18);
    fn_800A4ED0(w3d::G(temp_r29), fn_8015F5A0(&lbl_804B090C, 1), 1, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x1C), M2C_FIELD(arg0, s32 *, 0x20));
    fn_8016239C();
    return;
}

void w3d_auto_8026cac0(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 0x3C) = arg1;
    fn_8026CC60(arg0);
    return;
}

void w3d_auto_8026caec(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x10) = arg1;
    M2C_FIELD(arg0, s32 *, 0x44) = arg1;
    fn_8026CC60(arg0);
    return;
}

void w3d_auto_8026cb18(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x14) = arg1;
    M2C_FIELD(arg0, s32 *, 0x48) = arg1;
    fn_8026CC60(arg0);
    return;
}

void w3d_auto_8026cb44(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x18) = arg1;
    M2C_FIELD(arg0, s32 *, 0x4C) = arg1;
    fn_8026CC60(arg0);
    return;
}

}
