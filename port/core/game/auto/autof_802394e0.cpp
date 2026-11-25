#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autof_802394e0.c"
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

M2C_UNK fn_801E8D9C(s32);                           /* extern */
M2C_UNK fn_801EBBB8(s32, Ptr32<M2C_UNK>);                     /* extern */
M2C_UNK fn_80238D88();                              /* extern */
M2C_UNK fn_801EBF38(s32, Ptr32<M2C_UNK>);                     /* extern */
M2C_UNK fn_80239D60();                              /* extern */
Ptr32<void> fn_80165254();                                /* extern */
M2C_UNK fn_80240BD4(Ptr32<void>, s32);                   /* extern */
M2C_UNK fn_8023B59C();                              /* extern */
M2C_UNK fn_801ECC6C(s32, Ptr32<M2C_UNK>);                     /* extern */
M2C_UNK fn_801B5404();                              /* extern */
M2C_UNK fn_8015F518(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
Ptr32<Ptr32<void>> fn_8020B680(Ptr32<M2C_UNK>);                      /* extern */
M2C_UNK fn_8020EE9C(Ptr32<M2C_UNK>);                     /* extern */
s32 fn_8025D61C();                                  /* extern */
f32 fn_80178DF0(Ptr32<void>);                              /* extern */
M2C_UNK fn_802683B8(Ptr32<void>, f32);                        /* extern */
Ptr32<void> fn_80342A74(s32);                           /* extern */
M2C_UNK fn_8015FEF0();                              /* extern */
M2C_UNK fn_802AFB20(Ptr32<void>);                           /* extern */
s16 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
Ptr32<void> fn_801613F0(Ptr32<void>, M2C_UNK);                    /* extern */
M2C_UNK fn_8016239C(Ptr32<void>);                        /* extern */
M2C_UNK fn_800FC330(Ptr32<s32>, Ptr32<s32>);                  /* extern */
M2C_UNK fn_801EA4C8(Ptr32<void>, Ptr32<void>);                      /* extern */
s32 fn_802A3D64();                                  void fn_8020C5C0(Ptr32<s32>);                         /* extern */
s32 fn_802AA5F0(Ptr32<void>, Ptr32<s32>);                     /* extern */
s32 fn_802AB378(Ptr32<void>, M2C_UNK, s32);              /* extern */
Ptr32<u16> fn_80341884(Ptr32<s32>);                            /* extern */
M2C_UNK fn_802BA818(Ptr32<void>);                           /* extern */
M2C_UNK fn_8020BF2C(Ptr32<void>, Ptr32<M2C_UNK>);                /* extern */
M2C_UNK fn_802CC0AC();                              /* extern */
M2C_UNK fn_802CC264();                              /* extern */
M2C_UNK fn_802CC2D8();                              /* extern */
M2C_UNK fn_802CC354();                              /* extern */
M2C_UNK fn_800DC604(Ptr32<void>);                        /* extern */
M2C_UNK fn_800DE70C(Ptr32<void>, M2C_UNK);               /* extern */
M2C_UNK fn_800DE900(Ptr32<void>);                        /* extern */
M2C_UNK fn_800E6780(Ptr32<void>, M2C_UNK);               /* extern */
M2C_UNK fn_800DC674(Ptr32<void>, M2C_UNK);               /* extern */

extern M2C_UNK lbl_803BB280[];

s32 w3d_auto_802394e0(s32 arg0) {
    fn_801EBBB8(arg0, &(*lbl_803BB280));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_8041AFE0[];

Ptr32<void> w3d_auto_80239740(Ptr32<void> arg0) {
    fn_80238D88();
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8041AFE0);
    return arg0;
}

extern M2C_UNK lbl_803BB2CC[];

s32 w3d_auto_802397d4(s32 arg0) {
    fn_801EBF38(arg0, &(*lbl_803BB2CC));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_8041AFB8[];

Ptr32<void> w3d_auto_802398cc(Ptr32<void> arg0) {
    fn_80238D88();
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8041AFB8);
    return arg0;
}

extern M2C_UNK lbl_803BB304[];

s32 w3d_auto_80239960(s32 arg0) {
    fn_801EBF38(arg0, &(*lbl_803BB304));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_8041AEF0[];

Ptr32<void> w3d_auto_8023a150(Ptr32<void> arg0) {
    fn_80239D60();
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8041AEF0);
    return arg0;
}

extern M2C_UNK lbl_803BB4D4[];

s32 w3d_auto_8023a1e4(s32 arg0) {
    fn_801EBF38(arg0, &(*lbl_803BB4D4));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_8041AEC8[];

Ptr32<void> w3d_auto_8023a2dc(Ptr32<void> arg0) {
    fn_80239D60();
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8041AEC8);
    return arg0;
}

extern M2C_UNK lbl_803BB520[];

s32 w3d_auto_8023a370(s32 arg0) {
    fn_801EBF38(arg0, &(*lbl_803BB520));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_8041AE78[];

Ptr32<void> w3d_auto_8023a6cc(Ptr32<void> arg0) {
    fn_80239D60();
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8041AE78);
    return arg0;
}

extern M2C_UNK lbl_803BB59C[];

s32 w3d_auto_8023a760(s32 arg0) {
    fn_801EBF38(arg0, &(*lbl_803BB59C));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_8041ADB0[];

Ptr32<void> w3d_auto_8023b59c(Ptr32<void> arg0) {
    fn_80238D88();
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8041ADB0);
    fn_80240BD4(arg0, M2C_FIELD(fn_80165254(), s32 *, 0x34));
    return arg0;
}

extern M2C_UNK lbl_803BBD88[];

s32 w3d_auto_8023b640(s32 arg0) {
    fn_801EBF38(arg0, &(*lbl_803BBD88));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_8041AC70[];

Ptr32<void> w3d_auto_8023c8fc(Ptr32<void> arg0) {
    fn_8023B59C();
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8041AC70);
    return arg0;
}

extern M2C_UNK lbl_803BBEA0[];

s32 w3d_auto_8023c9b0(s32 arg0) {
    fn_801ECC6C(arg0, &(*lbl_803BBEA0));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_8041B820[];

Ptr32<void> w3d_auto_8024d93c(Ptr32<void> arg0) {
    fn_801B5404();
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8041B820);
    return arg0;
}

extern M2C_UNK lbl_803C50E8[];

s32 w3d_auto_8024d9d0(s32 arg0) {
    fn_801EBF38(arg0, &(*lbl_803C50E8));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_803CA820[];
extern M2C_UNK lbl_804B090C;

void w3d_auto_8025d518(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804B090C, &(*lbl_803CA820));
block_3:
    return;
}

extern M2C_UNK lbl_8041A638[];

void w3d_auto_8025d5a8(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r31;
    Ptr32<Ptr32<void>> temp_r3;

    temp_r3 = fn_8020B680(&(*lbl_8041A638));
    temp_r31 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x14);
    M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x14) = temp_r3;
    if (temp_r3 == NULL) {
        goto block_2;
    }
    M2C_FIELD(*temp_r3, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0xC)(temp_r3);
block_2:
    if (temp_r31 == NULL) {
        goto block_4;
    }
    M2C_FIELD(*temp_r31, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x10)(temp_r31);
block_4:
    return;
}

extern M2C_UNK lbl_80465058[];
extern s32 lbl_804B0914;

void w3d_auto_8025d680(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_80465058));
    lbl_804B0914 = fn_8025D61C();
block_3:
    return;
}

extern M2C_UNK lbl_803CB08C[];
extern M2C_UNK lbl_803CB098[];
extern M2C_UNK lbl_803CB0A8[];
extern M2C_UNK lbl_803CB0B8[];

Ptr32<M2C_UNK> w3d_auto_80263bb8(s32 arg0) {
    if (arg0 == 3) {
        goto block_8;
    }
    if (arg0 > 3) {
        goto block_5;
    }
    if (arg0 == 1) {
        goto block_8;
    }
    if (arg0 == 2) {
        goto block_9;
    }
    goto block_12;
block_5:
    if (arg0 == 4) {
        goto block_10;
    }
    if (arg0 == 5) {
        goto block_11;
    }
    goto block_12;
block_8:
    return &(*lbl_803CB08C);
block_9:
    return &(*lbl_803CB098);
block_10:
    return &(*lbl_803CB0A8);
block_11:
    return &(*lbl_803CB0B8);
block_12:
    return NULL;
}

extern M2C_UNK lbl_803CB100[];
extern M2C_UNK lbl_803CB110[];
extern M2C_UNK lbl_803CB120[];
extern M2C_UNK lbl_803CB134[];

Ptr32<M2C_UNK> w3d_auto_80263c24(s32 arg0) {
    if (arg0 == 3) {
        goto block_8;
    }
    if (arg0 > 3) {
        goto block_5;
    }
    if (arg0 == 1) {
        goto block_8;
    }
    if (arg0 == 2) {
        goto block_9;
    }
    goto block_12;
block_5:
    if (arg0 == 4) {
        goto block_10;
    }
    if (arg0 == 5) {
        goto block_11;
    }
    goto block_12;
block_8:
    return &(*lbl_803CB100);
block_9:
    return &(*lbl_803CB110);
block_10:
    return &(*lbl_803CB120);
block_11:
    return &(*lbl_803CB134);
block_12:
    return NULL;
}

extern M2C_UNK lbl_803CB178[];
extern M2C_UNK lbl_803CB18C[];
extern M2C_UNK lbl_803CB1A0[];
extern M2C_UNK lbl_803CB1B4[];

Ptr32<M2C_UNK> w3d_auto_80263c90(s32 arg0) {
    if (arg0 == 3) {
        goto block_8;
    }
    if (arg0 > 3) {
        goto block_5;
    }
    if (arg0 == 1) {
        goto block_8;
    }
    if (arg0 == 2) {
        goto block_9;
    }
    goto block_12;
block_5:
    if (arg0 == 4) {
        goto block_10;
    }
    if (arg0 == 5) {
        goto block_11;
    }
    goto block_12;
block_8:
    return &(*lbl_803CB178);
block_9:
    return &(*lbl_803CB18C);
block_10:
    return &(*lbl_803CB1A0);
block_11:
    return &(*lbl_803CB1B4);
block_12:
    return NULL;
}

s32 w3d_auto_8026836c(s32 arg0, Ptr32<void> arg1) {
    if ((s32) M2C_FIELD(arg1, s32 *, 0x23C) != 0) {
        goto block_2;
    }
    fn_802683B8(arg1, fn_80178DF0(fn_80342A74(M2C_FIELD(arg1, s32 *, 0x2DC))));
block_2:
    return 0;
}

extern M2C_UNK lbl_8041BDF0[];
extern M2C_UNK lbl_8041BE40[];

Ptr32<void> w3d_auto_80270640(Ptr32<void> arg0) {
    fn_8015FEF0();
    fn_802AFB20(arg0 + 0x1C);
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0xD0) = &(*lbl_8041BDF0);
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8041BE40);
    M2C_FIELD(arg0, s32 *, 0xD4) = 0;
    return arg0;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804B0B2C;
extern s32 lbl_804B1754;

void w3d_auto_8027a98c(void) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804B0B2C, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    return;
}

void w3d_auto_8028fa34(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp8;
    s32 spC;

    sp8 = arg2;
    if (arg1 == 0) {
        goto block_2;
    }
    fn_800FC330(&sp8, &spC);
    fn_801EA4C8(w3d::G(arg1), w3d::G(spC));
block_2:
    return;
}

extern M2C_UNK lbl_80471130[];
extern s32 lbl_804B0EB0;

void w3d_auto_802a3dc8(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_80471130));
    lbl_804B0EB0 = fn_802A3D64();
block_3:
    return;
}

s32 w3d_auto_802aa3ec(s32 arg0, Ptr32<void> arg1) {
    s32 sp8;
    s32 temp_r0;
    s32 temp_r3_2;
    s32 var_r3;
    Ptr32<u16> temp_r3;
    Ptr32<void> temp_r29;

    if ((s32) M2C_FIELD(arg1, s32 *, 0xE0) != 0) {
        goto block_4;
    }
    temp_r29 = M2C_FIELD(arg1, Ptr32<void> *, 0x28);
    fn_8020C5C0(&sp8);
    sp8 = M2C_FIELD(temp_r29, s32 *, 0x98);
    temp_r3 = fn_80341884(&sp8);
    *temp_r3 += 1;
    temp_r3_2 = fn_802AA5F0(arg1, &sp8);
    M2C_FIELD(arg1, s32 *, 0xE4) = temp_r3_2;
    var_r3 = fn_802AB378(arg1, 0, temp_r3_2);
    temp_r0 = M2C_FIELD(arg1, s32 *, 0x53C) & 0xFFFFDFFF;
    M2C_FIELD(arg1, s32 *, 0x53C) = temp_r0;
    if (var_r3 >= 0) {
        goto block_3;
    }
    var_r3 = 0;
block_3:
    M2C_FIELD(arg1, s32 *, 0x530) = var_r3;
    M2C_FIELD(arg1, s32 *, 0x53C) = (s32) (temp_r0 | 0x10000);
block_4:
    return 0;
}

s32 w3d_auto_802aa498(s32 arg0, Ptr32<void> arg1) {
    s32 sp8;
    s32 temp_r0;
    s32 temp_r3_2;
    s32 var_r3;
    Ptr32<u16> temp_r3;
    Ptr32<void> temp_r29;

    if ((s32) M2C_FIELD(arg1, s32 *, 0xE0) != 0) {
        goto block_4;
    }
    temp_r29 = M2C_FIELD(arg1, Ptr32<void> *, 0x28);
    fn_8020C5C0(&sp8);
    sp8 = M2C_FIELD(temp_r29, s32 *, 0x94);
    temp_r3 = fn_80341884(&sp8);
    *temp_r3 += 1;
    temp_r3_2 = fn_802AA5F0(arg1, &sp8);
    M2C_FIELD(arg1, s32 *, 0xE8) = temp_r3_2;
    var_r3 = fn_802AB378(arg1, 1, temp_r3_2);
    temp_r0 = M2C_FIELD(arg1, s32 *, 0x53C) & 0xFFFFDFFF;
    M2C_FIELD(arg1, s32 *, 0x53C) = temp_r0;
    if (var_r3 >= 0) {
        goto block_3;
    }
    var_r3 = 0;
block_3:
    M2C_FIELD(arg1, s32 *, 0x534) = var_r3;
    M2C_FIELD(arg1, s32 *, 0x53C) = (s32) (temp_r0 | 0x20000);
block_4:
    return 0;
}

s32 w3d_auto_802aa544(s32 arg0, Ptr32<void> arg1) {
    s32 sp8;
    s32 temp_r0;
    s32 temp_r3_2;
    s32 var_r3;
    Ptr32<u16> temp_r3;
    Ptr32<void> temp_r29;

    if ((s32) M2C_FIELD(arg1, s32 *, 0xE0) != 0) {
        goto block_4;
    }
    temp_r29 = M2C_FIELD(arg1, Ptr32<void> *, 0x28);
    fn_8020C5C0(&sp8);
    sp8 = M2C_FIELD(temp_r29, s32 *, 0x90);
    temp_r3 = fn_80341884(&sp8);
    *temp_r3 += 1;
    temp_r3_2 = fn_802AA5F0(arg1, &sp8);
    M2C_FIELD(arg1, s32 *, 0xEC) = temp_r3_2;
    var_r3 = fn_802AB378(arg1, 2, temp_r3_2);
    temp_r0 = M2C_FIELD(arg1, s32 *, 0x53C) & 0xFFFFDFFF;
    M2C_FIELD(arg1, s32 *, 0x53C) = temp_r0;
    if (var_r3 >= 0) {
        goto block_3;
    }
    var_r3 = 0;
block_3:
    M2C_FIELD(arg1, s32 *, 0x538) = var_r3;
    M2C_FIELD(arg1, s32 *, 0x53C) = (s32) (temp_r0 | 0x40000);
block_4:
    return 0;
}

extern M2C_UNK lbl_803D7B28[];
extern M2C_UNK lbl_803D7B38[];
extern M2C_UNK lbl_803D7B4C[];
extern M2C_UNK lbl_803D7B5C[];
extern M2C_UNK lbl_803D7B6C[];
extern M2C_UNK lbl_803D7B80[];
extern M2C_UNK lbl_803D7B9C[];
extern M2C_UNK lbl_803D7BB0[];
extern M2C_UNK lbl_803D7BBC[];
extern M2C_UNK lbl_803D7BCC[];
extern M2C_UNK lbl_803D7BE0[];
extern M2C_UNK lbl_803D7BF4[];
extern M2C_UNK lbl_803D7C0C[];
extern M2C_UNK lbl_803D7C24[];
extern M2C_UNK lbl_803D7C3C[];
extern M2C_UNK lbl_804B0F80;
extern M2C_UNK lbl_804B0F88;
extern M2C_UNK lbl_804B0F90;
extern M2C_UNK lbl_804B0F98;
extern M2C_UNK lbl_804B0FA0;
extern M2C_UNK lbl_804B0FA8;
extern M2C_UNK lbl_804B0FB0;
extern M2C_UNK lbl_804B0FB8;
extern M2C_UNK lbl_804B0FC0;
extern M2C_UNK lbl_804B0FC8;
extern M2C_UNK lbl_804B0FD0;
extern M2C_UNK lbl_804B0FD8;
extern M2C_UNK lbl_804B0FE0;
extern M2C_UNK lbl_804B0FE8;
extern M2C_UNK lbl_804B0FF0;

void w3d_auto_802b2930(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804B0F80, &(*lbl_803D7B28));
    fn_8015F518(&lbl_804B0F88, &(*lbl_803D7B38));
    fn_8015F518(&lbl_804B0F90, &(*lbl_803D7B4C));
    fn_8015F518(&lbl_804B0F98, &(*lbl_803D7B5C));
    fn_8015F518(&lbl_804B0FA0, &(*lbl_803D7B6C));
    fn_8015F518(&lbl_804B0FA8, &(*lbl_803D7B80));
    fn_8015F518(&lbl_804B0FB0, &(*lbl_803D7B9C));
    fn_8015F518(&lbl_804B0FB8, &(*lbl_803D7BB0));
    fn_8015F518(&lbl_804B0FC0, &(*lbl_803D7BBC));
    fn_8015F518(&lbl_804B0FC8, &(*lbl_803D7BCC));
    fn_8015F518(&lbl_804B0FD0, &(*lbl_803D7BE0));
    fn_8015F518(&lbl_804B0FD8, &(*lbl_803D7BF4));
    fn_8015F518(&lbl_804B0FE0, &(*lbl_803D7C0C));
    fn_8015F518(&lbl_804B0FE8, &(*lbl_803D7C24));
    fn_8015F518(&lbl_804B0FF0, &(*lbl_803D7C3C));
block_3:
    return;
}

s32 w3d_auto_802baca0(s32 arg0, s32 arg1) {
    fn_802BA818(w3d::G(arg1));
    return 0;
}

extern M2C_UNK lbl_803D9448[];

void w3d_auto_802cbf2c(s32 arg0) {
    fn_802CC0AC();
    fn_8020BF2C(w3d::G(arg0), &(*lbl_803D9448));
    return;
}

extern M2C_UNK lbl_803D9448[];

void w3d_auto_802cbf68(s32 arg0) {
    fn_802CC264();
    fn_8020BF2C(w3d::G(arg0), &(*lbl_803D9448));
    return;
}

extern M2C_UNK lbl_803D9448[];

void w3d_auto_802cbfa4(s32 arg0) {
    fn_802CC2D8();
    fn_8020BF2C(w3d::G(arg0), &(*lbl_803D9448));
    return;
}

extern M2C_UNK lbl_803D9448[];

void w3d_auto_802cbfe0(s32 arg0) {
    fn_802CC354();
    fn_8020BF2C(w3d::G(arg0), &(*lbl_803D9448));
    return;
}

extern M2C_UNK lbl_8040FF08[];
extern M2C_UNK lbl_8040FF88[];

void w3d_auto_80344b04(Ptr32<void> arg0, s32 arg1) {
    Ptr32<void> temp_r11;
    Ptr32<void> var_r31;

    temp_r11 = M2C_FIELD(arg0, Ptr32<void> *, 4);
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8040FF08);
    if (temp_r11 == NULL) {
        goto block_4;
    }
    var_r31 = temp_r11 + (M2C_FIELD(temp_r11, s32 *, -8) * 0xB8);
    if (temp_r11 == var_r31) {
        goto block_3;
    }
loop_2:
    var_r31 -= 0xB8;
    fn_800DE70C(var_r31, 0);
    if ((void *) M2C_FIELD(arg0, Ptr32<void> *, 4) != var_r31) {
        goto loop_2;
    }
block_3:
    fn_800DC604(M2C_FIELD(arg0, Ptr32<void> *, 4) - 8);
block_4:
    M2C_FIELD(arg0, Ptr32<void> *, 4) = NULL;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8040FF88);
    if (!(arg1 & 1)) {
        goto block_6;
    }
    fn_800DE900(arg0);
block_6:
    return;
}

extern M2C_UNK lbl_8040FF28[];
extern M2C_UNK lbl_8040FF88[];

void w3d_auto_80344bc8(Ptr32<void> arg0, s32 arg1) {
    Ptr32<void> temp_r11;
    Ptr32<void> var_r31;

    temp_r11 = M2C_FIELD(arg0, Ptr32<void> *, 4);
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8040FF28);
    if (temp_r11 == NULL) {
        goto block_4;
    }
    var_r31 = temp_r11 + (M2C_FIELD(temp_r11, s32 *, -8) * 0xB0);
    if (temp_r11 == var_r31) {
        goto block_3;
    }
loop_2:
    var_r31 -= 0xB0;
    fn_800E6780(var_r31, 0);
    if ((void *) M2C_FIELD(arg0, Ptr32<void> *, 4) != var_r31) {
        goto loop_2;
    }
block_3:
    fn_800DC604(M2C_FIELD(arg0, Ptr32<void> *, 4) - 8);
block_4:
    M2C_FIELD(arg0, Ptr32<void> *, 4) = NULL;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8040FF88);
    if (!(arg1 & 1)) {
        goto block_6;
    }
    fn_800DE900(arg0);
block_6:
    return;
}

extern M2C_UNK lbl_8040FF48[];
extern M2C_UNK lbl_8040FF88[];

void w3d_auto_80344c8c(Ptr32<void> arg0, s32 arg1) {
    Ptr32<void> temp_r11;
    Ptr32<void> var_r31;

    temp_r11 = M2C_FIELD(arg0, Ptr32<void> *, 4);
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8040FF48);
    if (temp_r11 == NULL) {
        goto block_4;
    }
    var_r31 = temp_r11 + (M2C_FIELD(temp_r11, s32 *, -8) * 0x74);
    if (temp_r11 == var_r31) {
        goto block_3;
    }
loop_2:
    var_r31 -= 0x74;
    fn_800DC674(var_r31, 0);
    if ((void *) M2C_FIELD(arg0, Ptr32<void> *, 4) != var_r31) {
        goto loop_2;
    }
block_3:
    fn_800DC604(M2C_FIELD(arg0, Ptr32<void> *, 4) - 8);
block_4:
    M2C_FIELD(arg0, Ptr32<void> *, 4) = NULL;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8040FF88);
    if (!(arg1 & 1)) {
        goto block_6;
    }
    fn_800DE900(arg0);
block_6:
    return;
}

}
