#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autof_80029258.c"
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

M2C_UNK fn_801628B0();                              /* extern */
M2C_UNK fn_800FC4C8(Ptr32<Ptr32<M2C_UNK>>, f32);               /* extern */
s16 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
Ptr32<void> fn_801613F0(Ptr32<void>, M2C_UNK);                    /* extern */
M2C_UNK fn_80162024(Ptr32<void>, Ptr32<s16>, Ptr32<void>);               /* extern */
M2C_UNK fn_8016239C(Ptr32<void>);                        /* extern */
s32 fn_800FCEA0();                                  /* extern */
M2C_UNK fn_8015FEF0();                              /* extern */
M2C_UNK fn_80035714(Ptr32<void>, Ptr32<M2C_UNK>, f32);           /* extern */
s32 fn_8015F65C(u16, Ptr32<M2C_UNK>);                    /* extern */
M2C_UNK fn_8015F518(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_80178D28(Ptr32<void>, Ptr32<s32>);                    /* extern */
M2C_UNK fn_801FE1F8();                              /* extern */
M2C_UNK fn_802EEFE0(Ptr32<void>, M2C_UNK, M2C_UNK);      /* extern */
f32 fn_801610A0();                                  /* extern */
M2C_UNK fn_8015FD1C(Ptr32<void>);                        /* extern */
f32 fn_80178DF0(Ptr32<void>);                               /* extern */
M2C_UNK fn_800FC230(Ptr32<Ptr32<M2C_UNK>>, Ptr32<s32>);             /* extern */
M2C_UNK fn_800FC3B0(Ptr32<Ptr32<M2C_UNK>>, u8);                /* extern */
M2C_UNK fn_800FC43C(Ptr32<Ptr32<M2C_UNK>>, s32);               /* extern */
Ptr32<void> fn_800FC7F8(s32);                             /* extern */
M2C_UNK fn_8004D23C();                              /* extern */
M2C_UNK fn_800FC550(Ptr32<Ptr32<M2C_UNK>>, Ptr32<M2C_UNK>);         /* extern */

extern M2C_UNK lbl_8040E248[];
extern Ptr32<Ptr32<M2C_UNK>> lbl_804AA828;

Ptr32<Ptr32<M2C_UNK>> w3d_auto_80029258(Ptr32<Ptr32<M2C_UNK>> arg0) {
    fn_801628B0();
    *arg0 = &(*lbl_8040E248);
    lbl_804AA828 = arg0;
    return arg0;
}

extern M2C_UNK lbl_8040E288[];
extern Ptr32<void> lbl_804AA860;

Ptr32<void> w3d_auto_80029514(Ptr32<void> arg0) {
    fn_801628B0();
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8040E288);
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    lbl_804AA860 = arg0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0x9C4;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    return arg0;
}

extern M2C_UNK lbl_803723C4[];
extern M2C_UNK lbl_803723D8[];
extern f32 lbl_803723EC[];
extern f32 lbl_803723F0[];
extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804ACC14;
extern M2C_UNK lbl_804ACC1C;
extern M2C_UNK lbl_804ACC2C;
extern s32 lbl_804B1754;

void w3d_auto_8002a5b4(s32 arg0) {
    s16 sp8;
    s16 spA;
    Ptr32<M2C_UNK> spC;
    Ptr32<M2C_UNK> sp10;
    Ptr32<void> temp_r30;

    sp8 = fn_8015F5A0(&lbl_804ACC14, 1);
    fn_80162024(w3d::G(arg0), &sp8, w3d::G(arg0 + 0x1C));
    spA = fn_8015F5A0(&lbl_804ACC1C, 1);
    fn_80162024(w3d::G(arg0), &spA, w3d::G(arg0 + 0x20));
    spC = &(*lbl_803723C4);
    fn_800FC4C8(&spC, (*lbl_803723EC));
    sp10 = &(*lbl_803723D8);
    fn_800FC4C8(&sp10, (*lbl_803723F0));
    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804ACC2C, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    return;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804ACC24;
extern s32 lbl_804B1754;

void w3d_auto_8002a6cc(void) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804ACC24, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    return;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804ACC34;
extern s32 lbl_804B1754;

void w3d_auto_8002ad24(void) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804ACC34, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    return;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804ACC64;
extern s32 lbl_804B1754;

void w3d_auto_8002af78(void) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804ACC64, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    return;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804ACC34;
extern M2C_UNK lbl_804ACC44;
extern s32 lbl_804B1754;

void w3d_auto_8002afd0(Ptr32<void> arg0) {
    Ptr32<void> temp_r30;
    Ptr32<void> temp_r30_2;

    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804ACC44, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    if (fn_800FCEA0() != 0) {
        goto block_2;
    }
    temp_r30_2 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30_2, s16 *, 0) = fn_8015F5A0(&lbl_804ACC34, 1);
    M2C_FIELD(temp_r30_2, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30_2);
block_2:
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    return;
}

extern M2C_UNK lbl_8040E368[];

Ptr32<void> w3d_auto_8002b354(Ptr32<void> arg0) {
    fn_8015FEF0();
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8040E368);
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = -1;
    return arg0;
}

extern M2C_UNK lbl_803729E0[];
extern f32 lbl_803729E8[];
extern s32 lbl_804AA8C8;
extern M2C_UNK lbl_804ACCE4;

void w3d_auto_8002d650(s32 arg0, Ptr32<u16> arg1) {
    if (fn_8015F65C(*arg1, &lbl_804ACCE4) == 0) {
        goto block_2;
    }
    fn_80035714(w3d::G(lbl_804AA8C8), &(*lbl_803729E0), (*lbl_803729E8));
block_2:
    return;
}

extern M2C_UNK lbl_803729EC[];
extern M2C_UNK lbl_80372A00[];
extern M2C_UNK lbl_80372A14[];
extern M2C_UNK lbl_804ACCD4;
extern M2C_UNK lbl_804ACCDC;
extern M2C_UNK lbl_804ACCE4;

void w3d_auto_8002d698(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804ACCD4, &(*lbl_803729EC));
    fn_8015F518(&lbl_804ACCDC, &(*lbl_80372A00));
    fn_8015F518(&lbl_804ACCE4, &(*lbl_80372A14));
block_3:
    return;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804AD004;
extern s32 lbl_804B1754;

void w3d_auto_80032bb0(Ptr32<void> arg0, s32 arg1) {
    s32 sp8;
    Ptr32<void> temp_r30;

    sp8 = arg1;
    fn_80178D28(w3d::G(M2C_FIELD(arg0, s32 *, 0x310)), &sp8);
    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AD004, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    return;
}

void w3d_auto_80036a94(s32 arg0, s32 arg1) {
    if (!(arg1 & 1)) {
        goto block_2;
    }
    fn_801FE1F8();
block_2:
    return;
}

extern M2C_UNK lbl_8040E5E8[];

Ptr32<void> w3d_auto_80036e08(Ptr32<void> arg0) {
    fn_801628B0();
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8040E5E8);
    fn_802EEFE0(arg0 + 0x24, 0, 0x28);
    M2C_FIELD(arg0, s32 *, 0x4C) = 0;
    return arg0;
}

extern M2C_UNK lbl_80373E64[];
extern M2C_UNK lbl_80373E78[];
extern M2C_UNK lbl_80373E8C[];
extern M2C_UNK lbl_80373EA0[];
extern M2C_UNK lbl_804AD030;
extern M2C_UNK lbl_804AD038;
extern M2C_UNK lbl_804AD040;
extern M2C_UNK lbl_804AD048;

void w3d_auto_800377c4(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804AD030, &(*lbl_80373E64));
    fn_8015F518(&lbl_804AD038, &(*lbl_80373E78));
    fn_8015F518(&lbl_804AD040, &(*lbl_80373E8C));
    fn_8015F518(&lbl_804AD048, &(*lbl_80373EA0));
block_3:
    return;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804AD0FC;
extern s32 lbl_804B1798;
extern s32 lbl_804B179C;

Ptr32<void> w3d_auto_8003a264(Ptr32<void> arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s16 *, 0) = fn_8015F5A0(&lbl_804AD0FC, 1);
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    lbl_804B1798 = arg1;
    lbl_804B179C = arg2;
    return arg0;
}

extern f32 lbl_8037430C[];

void w3d_auto_8003b2ec(Ptr32<void> arg0) {
    if (!(fn_801610A0() < (*lbl_8037430C))) {
        goto block_2;
    }
    M2C_FIELD(arg0, s32 *, 0x50) = 2;
block_2:
    return;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804AD178;
extern s32 lbl_804B1754;

void w3d_auto_8003c364(void) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AD178, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    return;
}

extern M2C_UNK lbl_8040E878[];

Ptr32<void> w3d_auto_8003d37c(Ptr32<void> arg0) {
    s32 var_ctr;

    fn_8015FEF0();
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8040E878);
    var_ctr = 0x100;
loop_1:
    var_ctr -= 1;
    if (var_ctr != 0) {
        goto loop_1;
    }
    return arg0;
}

extern f32 lbl_80374698[];

void w3d_auto_8003efd8(Ptr32<void> arg0) {
    if (!(M2C_FIELD(arg0, f32 *, 0x20) < (fn_80178DF0(w3d::G(M2C_FIELD(arg0, s32 *, 0x68))) - (*lbl_80374698)))) {
        goto block_2;
    }
    fn_8015FD1C(arg0);
block_2:
    return;
}

extern s32 lbl_804273EC[];

s32 w3d_auto_8003f240(s32 arg0) {
    return (*lbl_804273EC) + (arg0 << 5);
}

extern s32 lbl_804273EC[];

void w3d_auto_8003fbd0(s32 arg0, s32 arg1) {
    M2C_FIELD(((*lbl_804273EC) + (arg0 << 5)), s32 *, 0x18) = arg1;
    return;
}

extern M2C_UNK lbl_80377318[];
extern M2C_UNK lbl_80377330[];
extern M2C_UNK lbl_8037734C[];

void w3d_auto_8004c7a0(s32 arg0, s32 arg1) {
    Ptr32<M2C_UNK> sp8;
    Ptr32<M2C_UNK> spC;
    s32 sp10;
    Ptr32<M2C_UNK> sp14;
    u8 temp_r4;

    temp_r4 = M2C_FIELD(fn_800FC7F8(arg1), u8 *, 0x3C);
    sp8 = &(*lbl_80377318);
    fn_800FC3B0(&sp8, temp_r4);
    spC = &(*lbl_80377330);
    sp10 = 0;
    fn_800FC230(&spC, &sp10);
    sp14 = &(*lbl_8037734C);
    fn_800FC43C(&sp14, sp10);
    return;
}

extern M2C_UNK lbl_80377434[];
extern M2C_UNK lbl_80377440[];
extern M2C_UNK lbl_80377454[];
extern M2C_UNK lbl_8037746C[];
extern f32 lbl_80377474[];
extern s32 lbl_804AA8C8;

void w3d_auto_8004d1c4(Ptr32<void> arg0) {
    Ptr32<M2C_UNK> sp8;
    Ptr32<M2C_UNK> spC;

    fn_8004D23C();
    sp8 = &(*lbl_80377434);
    fn_800FC550(&sp8, &(*lbl_80377440));
    spC = &(*lbl_80377454);
    fn_800FC43C(&spC, M2C_FIELD(arg0, s32 *, 0x14));
    fn_80035714(w3d::G(lbl_804AA8C8), &(*lbl_8037746C), (*lbl_80377474));
    return;
}

extern M2C_UNK lbl_803776E4[];
extern M2C_UNK lbl_804AD408;

void w3d_auto_8004d800(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804AD408, &(*lbl_803776E4));
block_3:
    return;
}

extern M2C_UNK lbl_803776F8[];
extern M2C_UNK lbl_804AD410;

void w3d_auto_8004d908(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804AD410, &(*lbl_803776F8));
block_3:
    return;
}

extern M2C_UNK lbl_8037770C[];
extern M2C_UNK lbl_804AD418;

void w3d_auto_8004d980(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804AD418, &(*lbl_8037770C));
block_3:
    return;
}

}
