#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autoz_800e8a08.c"
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

M2C_UNK fn_800E903C(Ptr32<void>, s32);                   /* extern */
M2C_UNK fn_801265EC(Ptr32<void>, Ptr32<void>);                        /* extern */
M2C_UNK fn_801797B4();                              /* extern */
M2C_UNK fn_80341584(s32);                           /* extern */
M2C_UNK fn_801FE1F8(Ptr32<s32>);                         /* extern */
M2C_UNK fn_802134FC(Ptr32<void>);                              /* extern */
M2C_UNK fn_801FE240(s32);                              /* extern */
M2C_UNK fn_800FDECC(Ptr32<void>);                              /* extern */
extern s32 lbl_804AAF64;
Ptr32<void> fn_800FC6DC(s32);                             /* extern */
M2C_UNK fn_800E5BB8(s32);                              void fn_8030BE54(s32, s32);                           /* extern */
extern s32 lbl_8045CCAC[];
extern s32 lbl_804AB744;
M2C_UNK fn_801A1CF0(Ptr32<void>, M2C_UNK);                       /* extern */
extern s32 lbl_804AB74C;
extern s32 lbl_804AB8D0;

void w3d_auto_800e8a08(Ptr32<void> arg0, s32 arg1) {
    s32 temp_r4;
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r30;

    temp_r30 = arg0 + 0x3C;
    fn_80341584(M2C_FIELD(arg0, s32 *, 0x1C));
    fn_801797B4();
    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x20);
    M2C_FIELD(*temp_r3, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, Ptr32<void>, M2C_UNK)> *, 0x4C)(temp_r3, temp_r30, 0);
    if ((s32) M2C_FIELD(arg0, s32 *, 0xD4) == 0) {
        goto block_2;
    }
    fn_801265EC(w3d::G(M2C_FIELD(arg0, s32 *, 0xD4)), temp_r30);
block_2:
    temp_r4 = M2C_FIELD(arg0, s32 *, 0xA4);
    M2C_FIELD(arg0, s32 *, 0xA4) = arg1;
    fn_800E903C(arg0, arg1 - temp_r4);
    return;
}

void w3d_auto_800f14a8(Ptr32<s32> arg0, s32 arg1) {
    if ((s32) *arg0 == 0) {
        goto block_2;
    }
    fn_802134FC(w3d::G(*arg0));
block_2:
    if (!(arg1 & 1)) {
        goto block_4;
    }
    fn_801FE1F8(arg0);
block_4:
    return;
}

void w3d_auto_800f895c(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x1B4) == 0) {
        goto block_2;
    }
    fn_801FE240(M2C_FIELD(arg0, s32 *, 0x1B4));
block_2:
    M2C_FIELD(arg0, s32 *, 0x1B4) = 0;
    return;
}

void w3d_auto_800fde38(void) {
    if ((s32) lbl_804AAF64 == 0) {
        goto block_2;
    }
    fn_800FDECC(w3d::G(lbl_804AAF64));
block_2:
    return;
}

void w3d_auto_8013bb70(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r11;

    M2C_FIELD(arg0, f32 *, 0x44) = (f32) M2C_FIELD(fn_800FC6DC(M2C_FIELD(arg0, s32 *, 0x70)), f32 *, 0x48);
    temp_r11 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x1C);
    M2C_FIELD(*temp_r11, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, Ptr32<void>, M2C_UNK)> *, 0x50)(temp_r11, arg0 + 0x40, 0);
    return;
}

void w3d_auto_8013f08c(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x238) == 0) {
        goto block_2;
    }
    fn_800E5BB8(M2C_FIELD(arg0, s32 *, 0x238));
    M2C_FIELD(arg0, s32 *, 0x238) = 0;
block_2:
    return;
}

void w3d_auto_8016aec0(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 4) == 0) {
        goto block_2;
    }
    fn_8030BE54(M2C_FIELD(arg0, s32 *, 0xC), M2C_FIELD(arg0, s32 *, 4));
block_2:
    return;
}

void w3d_auto_801993c8(void) {
    if ((s32) (*lbl_8045CCAC) == 0) {
        goto block_2;
    }
    fn_802134FC(w3d::G((*lbl_8045CCAC)));
block_2:
    return;
}

s32 w3d_auto_801a1220(void) {
    if ((s32) lbl_804AB744 == 0) {
        goto block_2;
    }
    fn_801FE240(lbl_804AB744);
block_2:
    return 0;
}

s32 w3d_auto_801a18bc(void) {
    if ((s32) lbl_804AB74C == 0) {
        goto block_2;
    }
    fn_801A1CF0(w3d::G(lbl_804AB74C), 3);
block_2:
    lbl_804AB74C = 0;
    return 0;
}

void w3d_auto_801e6f0c(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 4) == 0) {
        goto block_2;
    }
    fn_801FE240(M2C_FIELD(arg0, s32 *, 4));
block_2:
    M2C_FIELD(arg0, s32 *, 0) = 0;
    return;
}

s32 w3d_auto_801f3fbc(void) {
    if ((s32) lbl_804AB8D0 == 0) {
        goto block_2;
    }
    fn_801FE240(lbl_804AB8D0);
block_2:
    return 0;
}

}
