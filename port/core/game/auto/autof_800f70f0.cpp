#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autof_800f70f0.c"
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

M2C_UNK fn_8002AE70(Ptr32<void>);                        /* extern */
M2C_UNK fn_8002AF78();                              /* extern */
M2C_UNK fn_800FC230(Ptr32<Ptr32<M2C_UNK>>, Ptr32<void>);            /* extern */
M2C_UNK fn_800FC43C(Ptr32<Ptr32<M2C_UNK>>, s32);               /* extern */
s16 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
Ptr32<void> fn_801613F0(Ptr32<void>, M2C_UNK);                    /* extern */
M2C_UNK fn_8016239C(Ptr32<void>);                        /* extern */
M2C_UNK fn_802097EC(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK fn_8002A914();                              /* extern */
M2C_UNK fn_8002ADDC(Ptr32<void>);                        /* extern */
M2C_UNK fn_800C53A0(Ptr32<void>, s32);                   /* extern */
Ptr32<void> fn_80165254();                                /* extern */
s32 fn_800E082C(Ptr32<void>, Ptr32<u16>);                     /* extern */
M2C_UNK fn_801074F0(Ptr32<void>);                        /* extern */
M2C_UNK fn_80107A90(Ptr32<void>);                        /* extern */
s32 fn_80125FF8(Ptr32<u16>);                             /* extern */
s32 fn_8015F65C(u16, Ptr32<M2C_UNK>);                    /* extern */
Ptr32<void> fn_80164FC8(s32);                             /* extern */
Ptr32<void> fn_801797B4();                                /* extern */
M2C_UNK fn_80341584(s32);                           /* extern */

extern M2C_UNK lbl_8038C970[];
extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804AF0E8;
extern s32 lbl_804B1754;

void w3d_auto_800f70f0(Ptr32<void> arg0) {
    Ptr32<M2C_UNK> sp8;
    Ptr32<M2C_UNK> spC;
    Ptr32<void> temp_r30;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x30) != 0) {
        goto block_2;
    }
    M2C_FIELD(arg0, s32 *, 0x30) = 1;
    fn_8002AF78();
    M2C_FIELD(arg0, s32 *, 0x3C) = 2;
    sp8 = &(*lbl_8038C970);
    fn_800FC230(&sp8, arg0 + 0x40);
    spC = &(*lbl_8038C970);
    fn_800FC43C(&spC, M2C_FIELD(arg0, s32 *, 0x40) + 1);
    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AF0E8, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    fn_8002AE70(arg0);
block_2:
    return;
}

extern M2C_UNK lbl_8038CA68[];
extern M2C_UNK lbl_804AF100;

void w3d_auto_800f7530(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_802097EC(&lbl_804AF100, &(*lbl_8038CA68), 0, 0);
block_3:
    return;
}

extern M2C_UNK lbl_80410560[];

Ptr32<void> w3d_auto_800fe364(Ptr32<void> arg0) {
    fn_8002A914();
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_80410560);
    return arg0;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804AF144;
extern M2C_UNK lbl_804AF14C;
extern s32 lbl_804B1754;

void w3d_auto_800fe500(Ptr32<void> arg0) {
    s16 temp_r3;
    Ptr32<void> temp_r30;
    Ptr32<void> temp_r30_2;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x30) != 0) {
        goto block_2;
    }
    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AF144, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    temp_r30_2 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    temp_r3 = fn_8015F5A0(&lbl_804AF14C, 1);
    M2C_FIELD(temp_r30_2, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    M2C_FIELD(temp_r30_2, s16 *, 0) = temp_r3;
    fn_800C53A0(temp_r30_2, M2C_FIELD(fn_80165254(), s32 *, 0x34) + 0x1388);
    M2C_FIELD(arg0, s32 *, 0x30) = 1;
    fn_8002ADDC(arg0);
block_2:
    return;
}

extern M2C_UNK lbl_80399AC8[];
extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804AF218;
extern M2C_UNK lbl_804AF228;
extern M2C_UNK lbl_804AF230;
extern s32 lbl_804B1754;

s32 w3d_auto_80106d04(Ptr32<void> arg0, Ptr32<u16> arg1) {
    Ptr32<M2C_UNK> sp8;
    u16 temp_r0;
    Ptr32<void> temp_r30;
    Ptr32<void> temp_r3;

    temp_r0 = *arg1;
    if ((s32) temp_r0 == 0x40) {
        goto block_3;
    }
    if ((s32) temp_r0 == 0x42) {
        goto block_6;
    }
    goto block_7;
block_3:
    if (fn_800E082C(arg0, arg1) < 0) {
        goto block_5;
    }
    fn_801074F0(arg0);
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_80107A90(arg0);
    goto block_15;
block_7:
    if (fn_8015F65C(*arg1, &lbl_804AF218) == 0) {
        goto block_13;
    }
    if (fn_80125FF8(arg1) != (s32) M2C_FIELD(arg0, s32 *, 0x84)) {
        goto block_13;
    }
    M2C_FIELD(arg0, s32 *, 0xB0) = 3;
    M2C_FIELD(arg0, s32 *, 0x130) = (s32) (M2C_FIELD(arg0, s32 *, 0x130) | 1);
    fn_80341584(M2C_FIELD(arg0, s32 *, 0x9C));
    if ((s32) M2C_FIELD(fn_801797B4(), s32 *, 0x130) != 2) {
        goto block_13;
    }
    temp_r3 = fn_80164FC8(M2C_FIELD(arg0, s32 *, 0x168));
    if (temp_r3 == NULL) {
        goto block_12;
    }
    M2C_FIELD(temp_r3, s32 *, 0x414) = 1;
block_12:
    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AF228, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
block_13:
    if (fn_8015F65C(*arg1, &lbl_804AF230) == 0) {
        goto block_15;
    }
    sp8 = &(*lbl_80399AC8);
    fn_800FC230(&sp8, arg0 + 0x180);
block_15:
    return fn_800E082C(arg0, arg1);
}

}
