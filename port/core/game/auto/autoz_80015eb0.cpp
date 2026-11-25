#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autoz_80015eb0.c"
/* Decompiled automatically by m2c; statement order, callee return width or a
 * guarded call argument adjusted by tools/m2c_reorder.py and verified identical
 * to the original after linking. Types and names are m2c placeholders pending
 * review. */
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

M2C_UNK fn_80015D18(s32, M2C_UNK);                       /* extern */
M2C_UNK fn_80342730(Ptr32<void>);                           /* extern */
extern s32 lbl_804AA6F4;
extern s32 lbl_804AA6F8;
M2C_UNK fn_800FC230(Ptr32<Ptr32<M2C_UNK>>, Ptr32<void>);            /* extern */
M2C_UNK fn_800FC4C8(Ptr32<Ptr32<M2C_UNK>>, f32);               /* extern */
s16 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
Ptr32<void> fn_801613F0(Ptr32<void>, M2C_UNK);                    /* extern */
M2C_UNK fn_80162024(Ptr32<void>, Ptr32<s16>, Ptr32<void>);         /* extern */
M2C_UNK fn_8016239C(Ptr32<void>);                        /* extern */
Ptr32<void> fn_801797B4();                                /* extern */
M2C_UNK fn_80341584(s32);                              /* extern */
extern M2C_UNK lbl_80372474[];
extern M2C_UNK lbl_80372488[];
extern M2C_UNK lbl_8037249C[];
extern f32 lbl_803724BC[];
extern f32 lbl_803724C0[];
extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804ACC34;
extern M2C_UNK lbl_804ACC4C;
extern M2C_UNK lbl_804ACC5C;
extern M2C_UNK lbl_804ACC6C;
extern s32 lbl_804B1754;
M2C_UNK fn_800C56B8(s32);                              /* extern */
M2C_UNK fn_801FE240(s32);                              /* extern */
M2C_UNK fn_80209920(Ptr32<M2C_UNK>, Ptr32<void>);             /* extern */
extern M2C_UNK lbl_804AF5BC;
M2C_UNK fn_80126230(Ptr32<void>, M2C_UNK);                       /* extern */
extern s32 lbl_804AAA9C;
M2C_UNK fn_80164CEC(Ptr32<void>, s32);                      /* extern */
M2C_UNK fn_8026DA58(Ptr32<void>);                              /* extern */
extern s32 lbl_804ABB7C;
extern s32 lbl_804B178C;
M2C_UNK fn_80035714(Ptr32<void>, Ptr32<M2C_UNK>, f32);           /* extern */
M2C_UNK fn_800A7E14(M2C_UNK, M2C_UNK);              /* extern */
extern M2C_UNK lbl_8037EB3C[];
extern f32 lbl_8037EB44[];
extern s32 lbl_804AA8C8;
M2C_UNK fn_800E5BB8(s32);                              /* extern */
M2C_UNK fn_800A5E04();                              /* extern */
M2C_UNK fn_802134FC(Ptr32<void>);                              /* extern */
extern M2C_UNK lbl_804AE280;
M2C_UNK fn_801265A4(Ptr32<void>, M2C_UNK);                       /* extern */
M2C_UNK fn_800E9DC8();                              /* extern */

void w3d_auto_80015eb0(void) {
    fn_80342730(w3d::G(lbl_804AA6F8));
    if ((s32) lbl_804AA6F4 == 0) {
        goto block_2;
    }
    fn_80015D18(lbl_804AA6F4, 3);
    lbl_804AA6F4 = 0;
block_2:
    return;
}

void w3d_auto_8002aba4(Ptr32<void> arg0) {
    s16 sp8;
    s16 spA;
    s16 spC;
    Ptr32<M2C_UNK> sp10;
    Ptr32<M2C_UNK> sp14;
    Ptr32<M2C_UNK> sp18;
    Ptr32<void> temp_r30;

    sp8 = fn_8015F5A0(&lbl_804ACC34, 1);
    fn_80162024(arg0, &sp8, arg0 + 0x1C);
    spA = fn_8015F5A0(&lbl_804ACC4C, 1);
    fn_80162024(arg0, &spA, arg0 + 0x20);
    spC = fn_8015F5A0(&lbl_804ACC5C, 1);
    fn_80162024(arg0, &spC, arg0 + 0x28);
    sp10 = &(*lbl_80372474);
    fn_800FC4C8(&sp10, (*lbl_803724BC));
    sp14 = &(*lbl_80372488);
    fn_800FC4C8(&sp14, (*lbl_803724C0));
    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804ACC6C, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    if ((s32) M2C_FIELD(arg0, s32 *, 0x2C) == 0) {
        goto block_2;
    }
    fn_80341584(M2C_FIELD(arg0, s32 *, 0x2C));
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) M2C_FIELD(fn_801797B4(), s32 *, 0x34);
    return;
block_2:
    sp18 = &(*lbl_8037249C);
    fn_800FC230(&sp18, arg0 + 0x38);
    return;
}

void w3d_auto_8002acd0(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x34) == 0) {
        goto block_2;
    }
    fn_800C56B8(M2C_FIELD(arg0, s32 *, 0x34));
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(M2C_FIELD(arg0, Ptr32<void> *, 0), Ptr32<M2C_UNK (Ptr32<void>)> *, 0x30)(arg0);
block_2:
    return;
}

void w3d_auto_8002c490(Ptr32<void> arg0, s32 arg1) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0xC) != 0) {
        goto block_3;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 4) == 0) {
        goto block_3;
    }
    fn_801FE240(M2C_FIELD(arg0, s32 *, 4));
block_3:
    if (!(arg1 & 1)) {
        goto block_5;
    }
    fn_80209920(&lbl_804AF5BC, arg0);
block_5:
    return;
}

void w3d_auto_80069430(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x68) == 0) {
        goto block_2;
    }
    fn_80126230(w3d::G(M2C_FIELD(arg0, s32 *, 0x68)), 3);
    M2C_FIELD(arg0, s32 *, 0x68) = 0;
block_2:
    lbl_804AAA9C = 0;
    return;
}

void w3d_auto_8006ac40(Ptr32<void> arg0) {
    fn_80164CEC(w3d::G(lbl_804B178C), M2C_FIELD(arg0, s32 *, 0x14));
    if ((s32) lbl_804ABB7C == 0) {
        goto block_2;
    }
    fn_8026DA58(w3d::G(lbl_804ABB7C));
block_2:
    M2C_FIELD(arg0, s32 *, 0xF0) = (s32) (M2C_FIELD(arg0, s32 *, 0xF0) & 0xFEFFFFFF);
    return;
}

void w3d_auto_800953e8(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x2FC) == 0) {
        goto block_2;
    }
    fn_80126230(w3d::G(M2C_FIELD(arg0, s32 *, 0x2FC)), 3);
    M2C_FIELD(arg0, s32 *, 0x2FC) = 0;
block_2:
    fn_800A7E14(0, 0);
    fn_80035714(w3d::G(lbl_804AA8C8), &(*lbl_8037EB3C), (*lbl_8037EB44));
    return;
}

void w3d_auto_800a4da4(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x28) == 0) {
        goto block_2;
    }
    fn_800E5BB8(M2C_FIELD(arg0, s32 *, 0x28));
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
block_2:
    return;
}

void w3d_auto_800a5db0(Ptr32<void> arg0, s32 arg1) {
    fn_800A5E04();
    if ((s32) M2C_FIELD(arg0, s32 *, 0x24) == 0) {
        goto block_2;
    }
    fn_802134FC(w3d::G(M2C_FIELD(arg0, s32 *, 0x24)));
block_2:
    if (!(arg1 & 1)) {
        goto block_4;
    }
    fn_80209920(&lbl_804AE280, arg0);
block_4:
    return;
}

void w3d_auto_800d5678(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x30) == 0) {
        goto block_2;
    }
    fn_801265A4(w3d::G(M2C_FIELD(arg0, s32 *, 0x30)), 3);
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
block_2:
    return;
}

void w3d_auto_800d82cc(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x174) == 0xFFFF) {
        goto block_2;
    }
    fn_800C56B8(M2C_FIELD(arg0, s32 *, 0x174));
block_2:
    return;
}

void w3d_auto_800e88e0(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0xC4) == -1) {
        goto block_2;
    }
    fn_800E9DC8();
block_2:
    if ((s32) M2C_FIELD(arg0, s32 *, 0xD4) == 0) {
        goto block_4;
    }
    fn_801265A4(w3d::G(M2C_FIELD(arg0, s32 *, 0xD4)), 3);
    M2C_FIELD(arg0, s32 *, 0xD4) = 0;
block_4:
    return;
}

}
