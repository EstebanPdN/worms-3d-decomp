#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autof_8004def0.c"
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

s32 fn_8004E324(Ptr32<void>);                            /* extern */
M2C_UNK fn_800FC1B0(Ptr32<Ptr32<M2C_UNK>>, Ptr32<void>);            /* extern */
s16 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
M2C_UNK fn_80162024(Ptr32<void>, Ptr32<s16>, Ptr32<void>);         /* extern */
M2C_UNK fn_8015F518(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
s32 fn_802CC4F0(Ptr32<M2C_UNK>);                         /* extern */
M2C_UNK fn_80035714(s32, Ptr32<M2C_UNK>, f32);           /* extern */
s32 fn_8015F65C(u16, Ptr32<M2C_UNK>);                    /* extern */
M2C_UNK fn_800FC5DC(Ptr32<Ptr32<M2C_UNK>>, Ptr32<void>);            void fn_8020C5C4(Ptr32<s32>);                         /* extern */
s32 fn_802EF234(Ptr32<void>, Ptr32<void>);                          /* extern */
M2C_UNK fn_80341588(Ptr32<s32>);                         /* extern */
s32 fn_8002AA48(Ptr32<void>, Ptr32<u16>);                     /* extern */
M2C_UNK fn_8002AE70(Ptr32<void>);                        /* extern */
M2C_UNK fn_800621C8(Ptr32<void>);                        /* extern */
M2C_UNK fn_80062228(Ptr32<void>);                        /* extern */
M2C_UNK fn_80062884(Ptr32<void>);                        /* extern */
Ptr32<void> fn_801613F0(Ptr32<void>, M2C_UNK);                    /* extern */
M2C_UNK fn_8016239C(Ptr32<void>);                        /* extern */
M2C_UNK fn_80062390(Ptr32<void>);                        /* extern */
M2C_UNK fn_800627A4(Ptr32<void>, Ptr32<void>);                              /* extern */
s32 fn_8006E71C();                                  /* extern */

extern M2C_UNK lbl_80377788[];
extern M2C_UNK lbl_8037779C[];
extern M2C_UNK lbl_804AD424;
extern M2C_UNK lbl_804AD43C;
extern M2C_UNK lbl_804AD444;

void w3d_auto_8004def0(Ptr32<void> arg0) {
    s16 sp8;
    s16 spA;
    s16 spC;
    Ptr32<M2C_UNK> sp10;
    Ptr32<M2C_UNK> sp14;
    s32 temp_r3;

    sp8 = fn_8015F5A0(&lbl_804AD43C, 1);
    fn_80162024(arg0, &sp8, arg0 + 0x24);
    spA = fn_8015F5A0(&lbl_804AD424, 1);
    fn_80162024(arg0, &spA, arg0 + 0x28);
    spC = fn_8015F5A0(&lbl_804AD444, 1);
    fn_80162024(arg0, &spC, arg0 + 0x2C);
    sp10 = &(*lbl_80377788);
    fn_800FC1B0(&sp10, arg0 + 0x34);
    sp14 = &(*lbl_8037779C);
    fn_800FC1B0(&sp14, arg0 + 0x30);
    M2C_FIELD(M2C_FIELD(arg0, Ptr32<void> *, 0), Ptr32<M2C_UNK (Ptr32<void>)> *, 0x28)(arg0);
    temp_r3 = fn_8004E324(arg0);
    if (temp_r3 == 0) {
        goto block_2;
    }
    M2C_FIELD(arg0, s32 *, 0x50) = 1;
    M2C_FIELD(M2C_FIELD(arg0, Ptr32<void> *, 0), Ptr32<M2C_UNK (Ptr32<void>)> *, 0x2C)(arg0);
    return;
block_2:
    M2C_FIELD(arg0, s32 *, 0x50) = temp_r3;
    M2C_FIELD(M2C_FIELD(arg0, Ptr32<void> *, 0), Ptr32<M2C_UNK (Ptr32<void>)> *, 0x30)(arg0);
    return;
}

extern M2C_UNK lbl_803778B4[];
extern M2C_UNK lbl_804AD460;

void w3d_auto_8004ef24(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804AD460, &(*lbl_803778B4));
block_3:
    return;
}

extern M2C_UNK lbl_80377F30[];

void w3d_auto_8004fd6c(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 0x1C) = fn_802CC4F0(&(*lbl_80377F30));
    return;
}

extern f32 lbl_80378194[];

f32 w3d_auto_80051a18(void) {
    return (*lbl_80378194);
}

extern M2C_UNK lbl_803782D4[];
extern M2C_UNK lbl_803782DC[];
extern f32 lbl_803782E4[];
extern s32 lbl_804AA8C8;
extern M2C_UNK lbl_804AD4C0;
extern M2C_UNK lbl_804AD4C8;

extern M2C_UNK lbl_803791B0[];
extern M2C_UNK lbl_803791C0[];
extern u32 lbl_804B17E4;
extern u32 lbl_804B17E8;

void w3d_auto_800608d4(Ptr32<void> arg0, Ptr32<s32> arg1) {
    Ptr32<M2C_UNK> sp8;
    Ptr32<M2C_UNK> spC;
    u32 temp_r9;

    if (fn_802EF234(w3d::G(M2C_FIELD(arg0, s32 *, 0x3C)), w3d::G(*arg1)) != 0) {
        goto block_4;
    }
    temp_r9 = lbl_804B17E4 + 1;
    lbl_804B17E4 = temp_r9;
    if (temp_r9 > (u32) lbl_804B17E8) {
        goto block_3;
    }
    sp8 = &(*lbl_803791B0);
    fn_800FC5DC(&sp8, arg0 + 4);
block_3:
    spC = &(*lbl_803791C0);
    fn_800FC5DC(&spC, arg0 + 0x1C);
block_4:
    return;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804AD510;
extern M2C_UNK lbl_804AD518;
extern s32 lbl_804B1754;

s32 w3d_auto_80062074(Ptr32<void> arg0, Ptr32<u16> arg1) {
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
    if (fn_8002AA48(arg0, arg1) < 0) {
        goto block_5;
    }
    fn_800621C8(arg0);
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_80062228(arg0);
    goto block_9;
block_7:
    if (fn_8015F65C(*arg1, &lbl_804AD510) == 0) {
        goto block_9;
    }
    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AD518, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    fn_8002AE70(arg0);
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    fn_80062884(arg0);
block_9:
    return fn_8002AA48(arg0, arg1);
}

s32 w3d_auto_80062160(Ptr32<void> arg0, u32 arg1) {
    fn_800627A4(arg0, (Ptr32<void>)w3d::G(arg1));
    if (fn_8006E71C() != 0) {
        goto block_4;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x3C) != 1) {
        goto block_4;
    }
    if (arg1 <= (u32) M2C_FIELD(arg0, u32 *, 0x48)) {
        goto block_4;
    }
    M2C_FIELD(arg0, s32 *, 0x3C) = 2;
    fn_80062390(arg0);
block_4:
    return 0x14;
}

}
