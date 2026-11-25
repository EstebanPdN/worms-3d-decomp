#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autof_80119aa8.c"
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

M2C_UNK fn_800FC230(Ptr32<Ptr32<M2C_UNK>>, Ptr32<s32>);             /* extern */
s16 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
Ptr32<void> fn_801613F0(Ptr32<void>, M2C_UNK);                    /* extern */
M2C_UNK fn_8016239C(Ptr32<void>);                        /* extern */
s32 fn_8012609C();                                  /* extern */
M2C_UNK fn_8020EE9C(Ptr32<M2C_UNK>);                     void fn_80128080(s32);                           void fn_80128084(s32);                           /* extern */
M2C_UNK fn_8015BCB0(Ptr32<void>, Ptr32<u16>);                    /* extern */
M2C_UNK fn_8015BD08(Ptr32<void>, s32, s32, s32, s32, s32, s32);                           /* extern */
M2C_UNK fn_8015F518(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_802097EC(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK fn_8013B3B8(s32, Ptr32<void>, Ptr32<void>, Ptr32<void>);                 /* extern */
M2C_UNK fn_8013BD0C(Ptr32<void>, Ptr32<M2C_UNK>);                /* extern */
s32 fn_80162C20();                                  /* extern */
Ptr32<void> fn_800FC6DC(s32);                             /* extern */
M2C_UNK fn_801359EC(Ptr32<void>, s32, s32, Ptr32<void>, f32, f32, f32); /* extern */
s32 fn_80181CCC(Ptr32<void>, s32);                          /* extern */
M2C_UNK fn_801817E0(Ptr32<void>, M2C_UNK);                  /* extern */

extern M2C_UNK lbl_8039ABC4[];
extern M2C_UNK lbl_8039ABD8[];
extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804AF354;
extern s32 lbl_804B1754;

s32 w3d_auto_80119aa8(void) {
    Ptr32<M2C_UNK> sp8;
    s32 spC;
    Ptr32<M2C_UNK> sp10;
    s32 sp14;
    s32 var_r3;
    Ptr32<void> temp_r30;

    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AF354, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    sp8 = &(*lbl_8039ABC4);
    fn_800FC230(&sp8, &spC);
    sp10 = &(*lbl_8039ABD8);
    fn_800FC230(&sp10, &sp14);
    var_r3 = 0;
    if (spC == 0) {
        goto block_3;
    }
    if (sp14 == 2) {
        goto block_3;
    }
    var_r3 = 1;
block_3:
    return var_r3;
}

extern M2C_UNK lbl_8044FAD4[];
extern s32 lbl_804AF5A0;

void w3d_auto_80126100(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_8044FAD4));
    lbl_804AF5A0 = fn_8012609C();
block_3:
    return;
}

extern M2C_UNK lbl_8040DB38[];
extern s32 lbl_804AB4A0;
extern M2C_UNK lbl_804AF5C4;
extern M2C_UNK lbl_804AF5CC;
extern s32 lbl_804B1754;

void w3d_auto_80127708(s32 arg0, Ptr32<u16> arg1) {
    u16 temp_r0;
    Ptr32<void> temp_r30;
    Ptr32<void> temp_r30_2;

    temp_r0 = *arg1;
    if ((s32) temp_r0 == 0x103) {
        goto block_3;
    }
    if ((s32) temp_r0 == 0x104) {
        goto block_5;
    }
    goto block_7;
block_3:
    fn_80128084(arg0);
    if ((s32) lbl_804AB4A0 == 0) {
        goto block_7;
    }
    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AF5C4, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    goto block_7;
block_5:
    fn_80128080(arg0);
    if ((s32) lbl_804AB4A0 == 0) {
        goto block_7;
    }
    temp_r30_2 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30_2, s16 *, 0) = fn_8015F5A0(&lbl_804AF5CC, 1);
    M2C_FIELD(temp_r30_2, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30_2);
block_7:
    fn_8015BCB0(w3d::G(arg0), arg1);
    return;
}

void w3d_auto_80128088(Ptr32<void> arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_r9;

    temp_r9 = M2C_FIELD(arg0, s32 *, 0xBC) & 0x40000;
    if (temp_r9 == 0) {
        goto block_2;
    }
    fn_8015BD08(arg0, arg1, arg2, arg3, arg4, arg5, temp_r9);
block_2:
    return;
}

extern M2C_UNK lbl_8039C9C4[];
extern M2C_UNK lbl_8039C9D4[];
extern M2C_UNK lbl_8039C9E4[];
extern M2C_UNK lbl_804AF5BC;
extern M2C_UNK lbl_804AF5C4;
extern M2C_UNK lbl_804AF5CC;

void w3d_auto_80129920(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_802097EC(&lbl_804AF5BC, &(*lbl_8039C9C4), 0, 0);
    fn_8015F518(&lbl_804AF5C4, &(*lbl_8039C9D4));
    fn_8015F518(&lbl_804AF5CC, &(*lbl_8039C9E4));
block_3:
    return;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804AF798;

Ptr32<void> w3d_auto_80131984(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0) = fn_8015F5A0(&lbl_804AF798, 1);
    M2C_FIELD(arg0, s32 *, 8) = arg1;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    return arg0;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804AF7A8;

Ptr32<void> w3d_auto_80131b50(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0) = fn_8015F5A0(&lbl_804AF7A8, 1);
    M2C_FIELD(arg0, s32 *, 8) = arg1;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    return arg0;
}

extern M2C_UNK lbl_8039E280[];
extern M2C_UNK lbl_8039E294[];
extern M2C_UNK lbl_804AF7A0;
extern M2C_UNK lbl_804AF7A8;

void w3d_auto_80131ba0(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804AF7A0, &(*lbl_8039E280));
    fn_8015F518(&lbl_804AF7A8, &(*lbl_8039E294));
block_3:
    return;
}

void w3d_auto_8013b91c(s32 arg0, s32 arg1) {
    fn_8013B3B8(arg0, w3d::G(arg0 + 0x34), w3d::G(arg0 + 0x40), w3d::G(arg1 + 0x50));
    return;
}

extern M2C_UNK lbl_8039FB70[];
extern M2C_UNK lbl_8039FB78[];

void w3d_auto_8013ddfc(s32 arg0) {
    if (fn_80162C20() & 1) {
        goto block_2;
    }
    fn_8013BD0C(w3d::G(arg0), &(*lbl_8039FB70));
    return;
block_2:
    fn_8013BD0C(w3d::G(arg0), &(*lbl_8039FB78));
    return;
}

extern f32 lbl_8039FBDC[];
extern f32 lbl_8039FBE0[];
extern s32 lbl_804AB1C4;

void w3d_auto_8013e0a0(Ptr32<void> arg0, s32 arg1) {
    if (fn_80181CCC(w3d::G(arg1), M2C_FIELD(arg0, s32 *, 0x1D8)) == 0) {
        goto block_4;
    }
    if (fn_80181CCC(w3d::G(arg1), M2C_FIELD(arg0, s32 *, 0x1EC)) == 0) {
        goto block_4;
    }
    if ((s32) M2C_FIELD(fn_800FC6DC(M2C_FIELD(arg0, s32 *, 0x70)), s32 *, 0xC8) == 0) {
        goto block_4;
    }
    fn_801359EC(arg0, arg1, lbl_804AB1C4, arg0 + 0x1D8, (*lbl_8039FBDC), (*lbl_8039FBE0), (*lbl_8039FBE0));
block_4:
    return;
}

extern f32 lbl_8039FBF8[];
extern f32 lbl_8039FBFC[];

f32 w3d_auto_8013e340(f32 farg0) {
    return (*lbl_8039FBFC) - ((farg0 * (*lbl_8039FBF8)) + (*lbl_8039FBF8));
}

extern f32 lbl_8039FC98[];
extern f32 lbl_8039FC9C[];
extern s32 lbl_804AB100;

void w3d_auto_8013e600(Ptr32<void> arg0) {
    fn_801817E0(w3d::G(M2C_FIELD(arg0, s32 *, 0x1C)), -1);
    fn_801359EC(arg0, M2C_FIELD(arg0, s32 *, 0x1C), lbl_804AB100, arg0 + 0x1EC, (*lbl_8039FC98), (*lbl_8039FC9C), (*lbl_8039FC9C));
    return;
}

}
