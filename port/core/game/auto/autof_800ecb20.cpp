#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autof_800ecb20.c"
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

M2C_UNK fn_800ED9C8(Ptr32<void>, M2C_UNK, Ptr32<void>);          /* extern */
s16 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
M2C_UNK fn_8015FC58(Ptr32<void>, Ptr32<void>);                /* extern */
M2C_UNK fn_8015FD1C(Ptr32<void>);                        /* extern */
Ptr32<void> fn_801613F0(Ptr32<void>, M2C_UNK);                    /* extern */
s32 fn_801797B4();                                  /* extern */
M2C_UNK fn_80341584(s32);                           /* extern */
M2C_UNK fn_800EE720(Ptr32<void>);                           /* extern */
M2C_UNK fn_800FC43C(Ptr32<Ptr32<M2C_UNK>>, M2C_UNK);           /* extern */
M2C_UNK fn_80162024(Ptr32<void>, Ptr32<s16>, Ptr32<void>);               /* extern */
M2C_UNK fn_8016239C(Ptr32<void>);                        /* extern */
M2C_UNK fn_801628B0();                              /* extern */
M2C_UNK fn_801750F4(Ptr32<void>, s32);                           /* extern */
M2C_UNK fn_8002A914();                              /* extern */

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804AEF08;
extern s32 lbl_804B1754;

void w3d_auto_800ecb20(Ptr32<void> arg0) {
    Ptr32<void> temp_r30;

    fn_80341584(M2C_FIELD(arg0, s32 *, 0xC0));
    fn_800ED9C8(arg0, 0, w3d::G(fn_801797B4() + 0x174));
    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AEF08, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8015FC58(arg0, temp_r30);
    M2C_FIELD(arg0, s32 *, 0x54) = -1;
    fn_8015FD1C(arg0);
    return;
}

extern M2C_UNK lbl_8038BD60[];
extern M2C_UNK lbl_804AEF5C;
extern M2C_UNK lbl_804AEF64;
extern M2C_UNK lbl_804AEF6C;
extern M2C_UNK lbl_804AEFAC;
extern M2C_UNK lbl_804AEFF4;

void w3d_auto_800ee638(s32 arg0) {
    s16 sp8;
    s16 spA;
    s16 spC;
    s16 spE;
    s16 sp10;
    Ptr32<M2C_UNK> sp14;

    sp8 = fn_8015F5A0(&lbl_804AEF64, 1);
    fn_80162024(w3d::G(arg0), &sp8, w3d::G(arg0 + 0x20));
    spA = fn_8015F5A0(&lbl_804AEF5C, 1);
    fn_80162024(w3d::G(arg0), &spA, w3d::G(arg0 + 0x24));
    spC = fn_8015F5A0(&lbl_804AEF6C, 1);
    fn_80162024(w3d::G(arg0), &spC, w3d::G(arg0 + 0x28));
    spE = fn_8015F5A0(&lbl_804AEFAC, 1);
    fn_80162024(w3d::G(arg0), &spE, w3d::G(arg0 + 0x2C));
    sp10 = fn_8015F5A0(&lbl_804AEFF4, 1);
    fn_80162024(w3d::G(arg0), &sp10, w3d::G(arg0 + 0x30));
    sp14 = &(*lbl_8038BD60);
    fn_800FC43C(&sp14, 1);
    fn_800EE720(w3d::G(arg0));
    return;
}

extern M2C_UNK lbl_8040DB38[];
extern s32 lbl_804AAF04;
extern M2C_UNK lbl_804AEF7C;
extern s32 lbl_804B1754;

void w3d_auto_800ef614(Ptr32<void> arg0) {
    Ptr32<void> temp_r30;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x38) == 0) {
        goto block_2;
    }
    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AEF7C, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
block_2:
    lbl_804AAF04 = 0;
    return;
}

extern M2C_UNK lbl_804102A8[];

Ptr32<void> w3d_auto_800efb70(Ptr32<void> arg0) {
    fn_801628B0();
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_804102A8);
    return arg0;
}

extern s32 lbl_804B1860;

s32 w3d_auto_800f6a58(s32 arg0) {
    fn_801750F4(w3d::G(arg0), lbl_804B1860);
    return 0;
}

extern M2C_UNK lbl_80410428[];

Ptr32<void> w3d_auto_800f6fe4(Ptr32<void> arg0) {
    fn_8002A914();
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_80410428);
    return arg0;
}

}
