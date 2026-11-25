#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autog_800621c8.c"
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

M2C_UNK fn_800FC3B0(Ptr32<Ptr32<M2C_UNK>>, M2C_UNK); /* extern */
s16 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK); /* extern */
M2C_UNK fn_80162024(Ptr32<void>, Ptr32<s16>, Ptr32<void>); /* extern */
extern M2C_UNK lbl_803799E4[];
extern M2C_UNK lbl_804AD510;
M2C_UNK fn_80063068(Ptr32<void>); /* extern */
M2C_UNK fn_80063434(Ptr32<void>); /* extern */
s32 fn_8015F65C(u16, Ptr32<M2C_UNK>); /* extern */
s32 fn_8015FB34(Ptr32<void>, Ptr32<u16>); /* extern */
Ptr32<void> fn_801613F0(Ptr32<void>, M2C_UNK); /* extern */
M2C_UNK fn_8016239C(Ptr32<void>); /* extern */
Ptr32<void> fn_80165254(); /* extern */
s32 fn_80178D1C(Ptr32<void>); /* extern */
extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804AD528;
extern M2C_UNK lbl_804AD550;
extern s32 lbl_804B1754;
Ptr32<void> fn_800FC7F8(s32); void fn_8020C5C0(Ptr32<s32>); void fn_8020C5C4(Ptr32<s32>); /* extern */
M2C_UNK fn_80341588(Ptr32<s32>); /* extern */
Ptr32<u16> fn_80341884(Ptr32<s32>); /* extern */
M2C_UNK fn_8015F518(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>); /* extern */
extern M2C_UNK lbl_8037A048[];
extern M2C_UNK lbl_804AD5A8;
M2C_UNK fn_800FC330(Ptr32<Ptr32<M2C_UNK>>, Ptr32<Ptr32<void>>); /* extern */
M2C_UNK fn_8015A0D4(Ptr32<void>, s32, M2C_UNK); /* extern */
extern M2C_UNK lbl_8037A110[];
extern M2C_UNK lbl_8040EEB0[];
M2C_UNK fn_800FC230(Ptr32<Ptr32<M2C_UNK>>, Ptr32<s32>); /* extern */
extern M2C_UNK lbl_8037A1A4[];
extern f32 lbl_8037A1B8[];
extern Ptr32<void> lbl_804AA8C8;
extern M2C_UNK lbl_804AD5F0;
extern M2C_UNK lbl_8037A1BC[];
extern M2C_UNK lbl_8037A1D0[];
extern M2C_UNK lbl_8037A1E4[];
extern M2C_UNK lbl_804AD5E0;
extern M2C_UNK lbl_804AD5E8;
M2C_UNK fn_8010A8E0(Ptr32<void>, int, Ptr32<void>); /* extern */
extern s32 lbl_804B17E4;
extern s32 lbl_804B17E8;
s32 fn_80069590(Ptr32<void>, s32); /* extern */
M2C_UNK fn_80069630(Ptr32<void>, M2C_UNK); /* extern */
extern M2C_UNK lbl_8040EFC8[];
extern M2C_UNK lbl_8037C958[];
extern f32 lbl_8037C96C[];
extern M2C_UNK lbl_804AD888;
extern M2C_UNK lbl_8037C978[];
extern M2C_UNK lbl_8037C98C[];
extern M2C_UNK lbl_8037C9A0[];
extern M2C_UNK lbl_804AD878;
extern M2C_UNK lbl_804AD880;
extern M2C_UNK lbl_8037CD80[];
extern M2C_UNK lbl_8037CD94[];
extern M2C_UNK lbl_804AD954;
extern M2C_UNK lbl_804AD95C;
extern M2C_UNK lbl_8037E97C[];
extern M2C_UNK lbl_8037E990[];
extern M2C_UNK lbl_804ADE10;
extern M2C_UNK lbl_804ADE18;
M2C_UNK fn_800FC1B0(Ptr32<Ptr32<M2C_UNK>>, s32); /* extern */
extern M2C_UNK lbl_8037F4D8[];
extern M2C_UNK lbl_8037F4F0[];
extern M2C_UNK lbl_804ADF4C;
extern M2C_UNK lbl_804ADF54;
extern M2C_UNK lbl_804ADF5C;
extern M2C_UNK lbl_804ADF64;
extern M2C_UNK lbl_804ADF6C;
extern M2C_UNK lbl_804ADF74;
extern M2C_UNK lbl_804ADF7C;
extern M2C_UNK lbl_804ADF84;
extern M2C_UNK lbl_804ADF8C;

void w3d_auto_800621c8(s32 arg0) {
    s16 sp8;
    Ptr32<M2C_UNK> spC;

    sp8 = fn_8015F5A0(&lbl_804AD510, 1);
    fn_80162024(w3d::G(arg0), &sp8, w3d::G(arg0 + 0x40));
    spC = &(*lbl_803799E4);
    fn_800FC3B0(&spC, 0);
    return;
}

s32 w3d_auto_80062d9c(Ptr32<void> arg0, Ptr32<u16> arg1) {
    u16 temp_r0;
    Ptr32<void> temp_r30;

    temp_r0 = *arg1;
    if ((s32) temp_r0 == 0x40) {
        goto block_3;
    }
    if ((s32) temp_r0 == 0x42) {
        goto block_6;
    }
    goto block_7;
block_3:
    if (fn_8015FB34(arg0, arg1) < 0) {
        goto block_5;
    }
    fn_80063068(arg0);
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_80063434(arg0);
    goto block_8;
block_7:
    if (fn_8015F65C(*arg1, &lbl_804AD528) != 0) {
        goto block_9;
    }
block_8:
    return fn_8015FB34(arg0, arg1);
block_9:
    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AD550, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    M2C_FIELD(arg0, s32 *, 0x20) = 1;
    M2C_FIELD(arg0, s32 *, 0x3C) = fn_80178D1C(w3d::G(M2C_FIELD(arg0, s32 *, 0x34)));
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) (M2C_FIELD(fn_80165254(), s32 *, 0x30) + M2C_FIELD(arg0, s32 *, 0x3C));
    return 0;
}

Ptr32<s32> w3d_auto_80065b5c(Ptr32<s32> arg0, s32 arg1, s32 arg2) {
    s32 sp8;
    Ptr32<u16> temp_r3;
    Ptr32<u16> temp_r3_2;
    Ptr32<void> temp_r30;

    temp_r30 = fn_800FC7F8(arg2);
    fn_8020C5C0(&sp8);
    sp8 = M2C_FIELD(temp_r30, s32 *, 0x1C);
    temp_r3 = fn_80341884(&sp8);
    *temp_r3 += 1;
    fn_8020C5C0(arg0);
    *arg0 = sp8;
    temp_r3_2 = fn_80341884(arg0);
    *temp_r3_2 += 1;
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
    return arg0;
}

Ptr32<s32> w3d_auto_80065bf8(Ptr32<s32> arg0, s32 arg1, s32 arg2) {
    s32 sp8;
    Ptr32<u16> temp_r3;
    Ptr32<u16> temp_r3_2;
    Ptr32<void> temp_r30;

    temp_r30 = fn_800FC7F8(arg2);
    fn_8020C5C0(&sp8);
    sp8 = M2C_FIELD(temp_r30, s32 *, 0x14);
    temp_r3 = fn_80341884(&sp8);
    *temp_r3 += 1;
    fn_8020C5C0(arg0);
    *arg0 = sp8;
    temp_r3_2 = fn_80341884(arg0);
    *temp_r3_2 += 1;
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
    return arg0;
}

void w3d_auto_80066904(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804AD5A8, &(*lbl_8037A048));
block_3:
    return;
}

Ptr32<void> w3d_auto_80067978(Ptr32<void> arg0, s32 arg1) {
    Ptr32<M2C_UNK> sp8;
    Ptr32<void> spC;

    fn_8015A0D4(arg0, arg1, 7);
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0x48) = &(*lbl_8040EEB0);
    M2C_FIELD(arg0, s32 *, 0x30) = 7;
    M2C_FIELD(arg0, s32 *, 0x4C) = -1;
    sp8 = &(*lbl_8037A110);
    fn_800FC330(&sp8, &spC);
    M2C_FIELD(arg0, f32 *, 0x50) = (f32) M2C_FIELD(spC, f32 *, 0x24);
    M2C_FIELD(arg0, f32 *, 0x54) = (f32) M2C_FIELD(spC, f32 *, 0x18);
    M2C_FIELD(arg0, f32 *, 0x58) = (f32) M2C_FIELD(spC, f32 *, 0x1C);
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) M2C_FIELD(spC, f32 *, 0x20);
    return arg0;
}

void w3d_auto_80067e10(Ptr32<void> arg0, Ptr32<u16> arg1) {
    Ptr32<M2C_UNK> sp8;
    s32 spC;

    if (fn_8015F65C(*arg1, &lbl_804AD5F0) == 0) {
        goto block_3;
    }
    sp8 = &(*lbl_8037A1A4);
    fn_800FC230(&sp8, &spC);
    if (spC != (s32) M2C_FIELD(arg0, s32 *, 0x4C)) {
        goto block_3;
    }
    M2C_FIELD(lbl_804AA8C8, f32 *, 0x334) = (f32) (*lbl_8037A1B8);
block_3:
    return;
}

void w3d_auto_80067e84(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804AD5E0, &(*lbl_8037A1BC));
    fn_8015F518(&lbl_804AD5E8, &(*lbl_8037A1D0));
    fn_8015F518(&lbl_804AD5F0, &(*lbl_8037A1E4));
block_3:
    return;
}

Ptr32<void> w3d_auto_800683fc(Ptr32<void> arg0, s32 arg1, s32 arg2, s32 arg3) {
    fn_8010A8E0(arg0, w3d::H((Ptr32<void>)w3d::G(arg1)), (Ptr32<void>)w3d::G(arg2));
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    lbl_804B17E4 = 0;
    lbl_804B17E8 = arg3 + 1;
    return arg0;
}

void w3d_auto_800694f4(Ptr32<void> arg0) {
    if (fn_80069590(arg0, M2C_FIELD(arg0, s32 *, 0x70)) != 1) {
        goto block_9;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x70) != 1) {
        goto block_3;
    }
    fn_80069630(arg0, 6);
block_3:
    if ((s32) M2C_FIELD(arg0, s32 *, 0x70) != 3) {
        goto block_7;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x74) == 8) {
        goto block_6;
    }
    fn_80069630(arg0, 3);
    goto block_7;
block_6:
    fn_80069630(arg0, 5);
block_7:
    if ((s32) M2C_FIELD(arg0, s32 *, 0x70) != 6) {
        goto block_9;
    }
    fn_80069630(arg0, 6);
block_9:
    return;
}

Ptr32<void> w3d_auto_8006f5dc(Ptr32<void> arg0, s32 arg1) {
    fn_8015A0D4(arg0, arg1, 6);
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0x48) = &(*lbl_8040EFC8);
    M2C_FIELD(arg0, s32 *, 0x30) = 6;
    M2C_FIELD(arg0, s32 *, 0x4C) = -1;
    return arg0;
}

void w3d_auto_8006fbb0(Ptr32<void> arg0, Ptr32<u16> arg1) {
    Ptr32<M2C_UNK> sp8;
    s32 spC;

    if (fn_8015F65C(*arg1, &lbl_804AD888) == 0) {
        goto block_3;
    }
    sp8 = &(*lbl_8037C958);
    fn_800FC230(&sp8, &spC);
    if (spC != (s32) M2C_FIELD(arg0, s32 *, 0x4C)) {
        goto block_3;
    }
    M2C_FIELD(lbl_804AA8C8, f32 *, 0x334) = (f32) (*lbl_8037C96C);
block_3:
    return;
}

void w3d_auto_8006ff34(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804AD878, &(*lbl_8037C978));
    fn_8015F518(&lbl_804AD880, &(*lbl_8037C98C));
    fn_8015F518(&lbl_804AD888, &(*lbl_8037C9A0));
block_3:
    return;
}

void w3d_auto_80072ca4(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804AD954, &(*lbl_8037CD80));
    fn_8015F518(&lbl_804AD95C, &(*lbl_8037CD94));
block_3:
    return;
}

void w3d_auto_80093240(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804ADE10, &(*lbl_8037E97C));
    fn_8015F518(&lbl_804ADE18, &(*lbl_8037E990));
block_3:
    return;
}

void w3d_auto_80096c30(s32 arg0) {
    s16 sp8;
    s16 spA;
    s16 spC;
    s16 spE;
    s16 sp10;
    s16 sp12;
    s16 sp14;
    s16 sp16;
    s16 sp18;
    Ptr32<M2C_UNK> sp1C;
    Ptr32<M2C_UNK> sp20;

    sp8 = fn_8015F5A0(&lbl_804ADF54, 1);
    fn_80162024(w3d::G(arg0), &sp8, w3d::G(arg0 + 0x1C));
    spA = fn_8015F5A0(&lbl_804ADF4C, 1);
    fn_80162024(w3d::G(arg0), &spA, w3d::G(arg0 + 0x20));
    spC = fn_8015F5A0(&lbl_804ADF5C, 1);
    fn_80162024(w3d::G(arg0), &spC, w3d::G(arg0 + 0x24));
    spE = fn_8015F5A0(&lbl_804ADF64, 1);
    fn_80162024(w3d::G(arg0), &spE, w3d::G(arg0 + 0x28));
    sp10 = fn_8015F5A0(&lbl_804ADF6C, 1);
    fn_80162024(w3d::G(arg0), &sp10, w3d::G(arg0 + 0x2C));
    sp12 = fn_8015F5A0(&lbl_804ADF74, 1);
    fn_80162024(w3d::G(arg0), &sp12, w3d::G(arg0 + 0x30));
    sp14 = fn_8015F5A0(&lbl_804ADF7C, 1);
    fn_80162024(w3d::G(arg0), &sp14, w3d::G(arg0 + 0x34));
    sp16 = fn_8015F5A0(&lbl_804ADF84, 1);
    fn_80162024(w3d::G(arg0), &sp16, w3d::G(arg0 + 0x3C));
    sp18 = fn_8015F5A0(&lbl_804ADF8C, 1);
    fn_80162024(w3d::G(arg0), &sp18, w3d::G(arg0 + 0x38));
    sp1C = &(*lbl_8037F4D8);
    fn_800FC1B0(&sp1C, arg0 + 0x40);
    sp20 = &(*lbl_8037F4F0);
    fn_800FC1B0(&sp20, arg0 + 0x44);
    return;
}

}
