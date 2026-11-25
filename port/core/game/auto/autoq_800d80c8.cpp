#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autoq_800d80c8.c"
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

M2C_UNK fn_800D8B4C(Ptr32<void>);                        /* extern */
s32 fn_800D98A4(Ptr32<void>);                            /* extern */
M2C_UNK fn_800ED090(Ptr32<void>);                        /* extern */
s16 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
M2C_UNK fn_80162024(Ptr32<void>, Ptr32<s16>, Ptr32<void>);         /* extern */
Ptr32<void> fn_80165254();                                /* extern */
M2C_UNK fn_801797B4();                              /* extern */
M2C_UNK fn_80341584(s32);                           /* extern */
extern M2C_UNK lbl_804AEAF0;
extern M2C_UNK lbl_804AEAF8;
extern M2C_UNK lbl_804AEB00;
extern M2C_UNK lbl_804AEB08;
extern M2C_UNK lbl_804AEB10;
extern M2C_UNK lbl_804AEB18;
extern M2C_UNK lbl_804AEB20;
extern M2C_UNK lbl_804AEB38;
extern M2C_UNK lbl_804AEB40;
extern M2C_UNK lbl_804AEB58;
extern M2C_UNK lbl_804AEB70;
extern M2C_UNK lbl_804AEB78;

void w3d_auto_800d80c8(Ptr32<void> arg0) {
    s16 sp8;
    s16 spA;
    s16 spC;
    s16 spE;
    s16 sp10;
    s16 sp12;
    s16 sp14;
    s16 sp16;
    s16 sp18;
    s16 sp1A;
    s16 sp1C;
    s16 sp1E;
    s32 var_r3;

    fn_80341584(M2C_FIELD(arg0, s32 *, 0xC0));
    fn_801797B4();
    sp8 = fn_8015F5A0(&lbl_804AEAF0, 1);
    fn_80162024(arg0, &sp8, arg0 + 0x138);
    spA = fn_8015F5A0(&lbl_804AEAF8, 1);
    fn_80162024(arg0, &spA, arg0 + 0x13C);
    spC = fn_8015F5A0(&lbl_804AEB00, 1);
    fn_80162024(arg0, &spC, arg0 + 0x140);
    spE = fn_8015F5A0(&lbl_804AEB08, 1);
    fn_80162024(arg0, &spE, arg0 + 0x144);
    sp10 = fn_8015F5A0(&lbl_804AEB10, 1);
    fn_80162024(arg0, &sp10, arg0 + 0x148);
    sp12 = fn_8015F5A0(&lbl_804AEB18, 1);
    fn_80162024(arg0, &sp12, arg0 + 0x14C);
    sp14 = fn_8015F5A0(&lbl_804AEB20, 1);
    fn_80162024(arg0, &sp14, arg0 + 0x150);
    sp16 = fn_8015F5A0(&lbl_804AEB38, 1);
    fn_80162024(arg0, &sp16, arg0 + 0x154);
    sp18 = fn_8015F5A0(&lbl_804AEB40, 1);
    fn_80162024(arg0, &sp18, arg0 + 0x158);
    sp1A = fn_8015F5A0(&lbl_804AEB58, 1);
    fn_80162024(arg0, &sp1A, arg0 + 0x15C);
    sp1C = fn_8015F5A0(&lbl_804AEB70, 1);
    fn_80162024(arg0, &sp1C, arg0 + 0x160);
    sp1E = fn_8015F5A0(&lbl_804AEB78, 1);
    fn_80162024(arg0, &sp1E, arg0 + 0x164);
    M2C_FIELD(arg0, s32 *, 0x170) = (s32) M2C_FIELD(fn_80165254(), s32 *, 0x34);
    var_r3 = 0;
    if ((s32) M2C_FIELD(arg0, s32 *, 0x134) == 0) {
        goto block_2;
    }
    var_r3 = fn_800D98A4(arg0);
block_2:
    if (var_r3 != 0) {
        goto block_4;
    }
    fn_800D8B4C(arg0);
block_4:
    fn_800ED090(arg0);
    M2C_FIELD(M2C_FIELD(arg0, Ptr32<void> *, 0), Ptr32<M2C_UNK (Ptr32<void>)> *, 0x58)(arg0);
    return;
}

}
