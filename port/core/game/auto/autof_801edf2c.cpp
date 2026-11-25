#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autof_801edf2c.c"
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

M2C_UNK fn_801EE1E4();                              /* extern */
Ptr32<void> fn_802098FC(Ptr32<M2C_UNK>, s32, M2C_UNK);         /* extern */
M2C_UNK fn_801E8BC4(Ptr32<void>, Ptr32<void>);                   /* extern */
M2C_UNK fn_801EB058();                              /* extern */
M2C_UNK fn_801EB0A8(Ptr32<void>, s32);                   /* extern */
Ptr32<void> fn_801FE1D8(M2C_UNK);                         /* extern */
M2C_UNK fn_801F410C(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4148(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4184(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F41C0(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F41FC(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4238(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4274(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F42B0(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F42EC(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4328(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4364(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F43A0(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F43DC(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4418(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4454(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4490(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F44CC(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4508(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4544(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4580(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F45BC(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F45F8(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4634(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4670(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F46AC(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F46E8(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4724(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4760(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F479C(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F47D8(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4814(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4850(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F488C(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F48C8(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4904(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4940(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F497C(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F49B8(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F49F4(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4A30(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4A6C(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4AA8(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4AE4(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4B20(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4B5C(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4B98(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4BD4(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_801F4C10(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
s32 fn_801F5F58();                                  /* extern */
M2C_UNK fn_8020EE9C(Ptr32<M2C_UNK>);                     /* extern */
M2C_UNK fn_801F7620(s32, Ptr32<M2C_UNK>, float);                     /* extern */
M2C_UNK fn_8020FCB4(Ptr32<M2C_UNK>);                     /* extern */
s32 fn_801F8160();                                  /* extern */
s32 fn_801F87F0(Ptr32<void>);                               /* extern */
s16 fn_801F881C(Ptr32<void>);                               /* extern */
s8 fn_801F8830(Ptr32<void>);                                /* extern */
M2C_UNK fn_8020BD38(s32, Ptr32<M2C_UNK>);                /* extern */
s32 fn_801FBF64();                                  /* extern */

extern M2C_UNK lbl_804176D0[];
extern M2C_UNK lbl_804B05A0;

Ptr32<void> w3d_auto_801edf2c(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_802098FC(&lbl_804B05A0, arg1 + 0x20, 0x20);
    fn_801EE1E4();
    M2C_FIELD(temp_r30, s32 *, 0x14) = arg1;
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 0) = &(*lbl_804176D0);
    return temp_r30;
}

extern M2C_UNK lbl_804176A0[];
extern M2C_UNK lbl_804B05A0;

Ptr32<void> w3d_auto_801ee12c(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_802098FC(&lbl_804B05A0, arg1 + 0x20, 0x20);
    fn_801EE1E4();
    M2C_FIELD(temp_r30, s32 *, 0x14) = arg1;
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 0) = &(*lbl_804176A0);
    return temp_r30;
}

extern M2C_UNK lbl_80417670[];
extern M2C_UNK lbl_804B05A0;

Ptr32<void> w3d_auto_801ee188(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_802098FC(&lbl_804B05A0, arg1 + 0x20, 0x20);
    fn_801EE1E4();
    M2C_FIELD(temp_r30, s32 *, 0x14) = arg1;
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 0) = &(*lbl_80417670);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801efcd0(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801efd34(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801efd98(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801efdfc(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801efe60(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801efec4(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801eff28(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801eff8c(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801efff0(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801f209c(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801f2100(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801f2164(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801f21c8(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801f222c(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801f2290(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801f22f4(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801f2358(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801f23bc(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801f2420(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801f2484(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801f24e8(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801f254c(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801f25b0(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_80417790[];

Ptr32<void> w3d_auto_801f2614(s32 arg0, s32 arg1) {
    Ptr32<void> temp_r30;

    temp_r30 = fn_801FE1D8(8);
    fn_801EB058();
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417790);
    fn_801EB0A8(temp_r30, arg1);
    fn_801E8BC4(w3d::G(arg0), temp_r30);
    return temp_r30;
}

extern M2C_UNK lbl_803FFE68[];
extern M2C_UNK lbl_803FFE88[];
extern M2C_UNK lbl_803FFEA8[];
extern M2C_UNK lbl_803FFEC8[];
extern M2C_UNK lbl_803FFEE8[];
extern M2C_UNK lbl_803FFF08[];
extern M2C_UNK lbl_803FFF28[];
extern M2C_UNK lbl_803FFF48[];
extern M2C_UNK lbl_803FFF68[];
extern M2C_UNK lbl_803FFF88[];
extern M2C_UNK lbl_803FFFA8[];
extern M2C_UNK lbl_803FFFC8[];
extern M2C_UNK lbl_803FFFE8[];
extern M2C_UNK lbl_80400008[];
extern M2C_UNK lbl_80400028[];
extern M2C_UNK lbl_80400048[];
extern M2C_UNK lbl_80400068[];
extern M2C_UNK lbl_80400088[];
extern M2C_UNK lbl_804000A8[];
extern M2C_UNK lbl_804000C8[];
extern M2C_UNK lbl_804000E8[];
extern M2C_UNK lbl_80400108[];
extern M2C_UNK lbl_80400128[];
extern M2C_UNK lbl_80400148[];
extern M2C_UNK lbl_80400168[];
extern M2C_UNK lbl_80400188[];
extern M2C_UNK lbl_804001A8[];
extern M2C_UNK lbl_804001C8[];
extern M2C_UNK lbl_804001E8[];
extern M2C_UNK lbl_80400208[];
extern M2C_UNK lbl_80400228[];
extern M2C_UNK lbl_80400248[];
extern M2C_UNK lbl_80400268[];
extern M2C_UNK lbl_80400288[];
extern M2C_UNK lbl_804002A8[];
extern M2C_UNK lbl_804002C8[];
extern M2C_UNK lbl_804002E8[];
extern M2C_UNK lbl_80400308[];
extern M2C_UNK lbl_80400328[];
extern M2C_UNK lbl_80400348[];
extern M2C_UNK lbl_80400368[];
extern M2C_UNK lbl_80400388[];
extern M2C_UNK lbl_804003A8[];
extern M2C_UNK lbl_804003C8[];
extern M2C_UNK lbl_804003E8[];
extern M2C_UNK lbl_80400408[];
extern M2C_UNK lbl_80400428[];
extern M2C_UNK lbl_80400448[];
extern M2C_UNK lbl_8045E194[];
extern M2C_UNK lbl_8045E1AC[];
extern M2C_UNK lbl_8045E1C4[];
extern M2C_UNK lbl_8045E1DC[];
extern M2C_UNK lbl_8045E1F4[];
extern M2C_UNK lbl_8045E20C[];
extern M2C_UNK lbl_8045E224[];
extern M2C_UNK lbl_8045E23C[];
extern M2C_UNK lbl_8045E254[];
extern M2C_UNK lbl_8045E26C[];
extern M2C_UNK lbl_8045E284[];
extern M2C_UNK lbl_8045E29C[];
extern M2C_UNK lbl_8045E2B4[];
extern M2C_UNK lbl_8045E2CC[];
extern M2C_UNK lbl_8045E2E4[];
extern M2C_UNK lbl_8045E2FC[];
extern M2C_UNK lbl_8045E314[];
extern M2C_UNK lbl_8045E32C[];
extern M2C_UNK lbl_8045E344[];
extern M2C_UNK lbl_8045E35C[];
extern M2C_UNK lbl_8045E374[];
extern M2C_UNK lbl_8045E38C[];
extern M2C_UNK lbl_8045E3A4[];
extern M2C_UNK lbl_8045E3BC[];
extern M2C_UNK lbl_8045E3D4[];
extern M2C_UNK lbl_8045E3EC[];
extern M2C_UNK lbl_8045E404[];
extern M2C_UNK lbl_8045E41C[];
extern M2C_UNK lbl_8045E434[];
extern M2C_UNK lbl_8045E44C[];
extern M2C_UNK lbl_8045E464[];
extern M2C_UNK lbl_8045E47C[];
extern M2C_UNK lbl_8045E494[];
extern M2C_UNK lbl_8045E4AC[];
extern M2C_UNK lbl_8045E4C4[];
extern M2C_UNK lbl_8045E4DC[];
extern M2C_UNK lbl_8045E4F4[];
extern M2C_UNK lbl_8045E50C[];
extern M2C_UNK lbl_8045E524[];
extern M2C_UNK lbl_8045E53C[];
extern M2C_UNK lbl_8045E554[];
extern M2C_UNK lbl_8045E56C[];
extern M2C_UNK lbl_8045E584[];
extern M2C_UNK lbl_8045E59C[];
extern M2C_UNK lbl_8045E5B4[];
extern M2C_UNK lbl_8045E5CC[];
extern M2C_UNK lbl_8045E5E4[];
extern M2C_UNK lbl_8045E5FC[];

void w3d_auto_801f4c4c(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        fn_801F410C(&(*lbl_8045E194), &(*lbl_803FFE68));
        fn_801F4148(&(*lbl_8045E1AC), &(*lbl_803FFE88));
        fn_801F4184(&(*lbl_8045E1C4), &(*lbl_803FFEA8));
        fn_801F41C0(&(*lbl_8045E1DC), &(*lbl_803FFEC8));
        fn_801F41FC(&(*lbl_8045E1F4), &(*lbl_803FFEE8));
        fn_801F4238(&(*lbl_8045E20C), &(*lbl_803FFF08));
        fn_801F4274(&(*lbl_8045E224), &(*lbl_803FFF28));
        fn_801F42B0(&(*lbl_8045E23C), &(*lbl_803FFF48));
        fn_801F42EC(&(*lbl_8045E254), &(*lbl_803FFF68));
        fn_801F4328(&(*lbl_8045E26C), &(*lbl_803FFF88));
        fn_801F4364(&(*lbl_8045E284), &(*lbl_803FFFA8));
        fn_801F43A0(&(*lbl_8045E29C), &(*lbl_803FFFC8));
        fn_801F43DC(&(*lbl_8045E2B4), &(*lbl_803FFFE8));
        fn_801F4418(&(*lbl_8045E2CC), &(*lbl_80400008));
        fn_801F4454(&(*lbl_8045E2E4), &(*lbl_80400028));
        fn_801F4490(&(*lbl_8045E2FC), &(*lbl_80400048));
        fn_801F44CC(&(*lbl_8045E314), &(*lbl_80400068));
        fn_801F4508(&(*lbl_8045E32C), &(*lbl_80400088));
        fn_801F4544(&(*lbl_8045E344), &(*lbl_804000A8));
        fn_801F4580(&(*lbl_8045E35C), &(*lbl_804000C8));
        fn_801F45BC(&(*lbl_8045E374), &(*lbl_804000E8));
        fn_801F45F8(&(*lbl_8045E38C), &(*lbl_80400108));
        fn_801F4634(&(*lbl_8045E3A4), &(*lbl_80400128));
        fn_801F4670(&(*lbl_8045E3BC), &(*lbl_80400148));
        fn_801F46AC(&(*lbl_8045E3D4), &(*lbl_80400168));
        fn_801F46E8(&(*lbl_8045E3EC), &(*lbl_80400188));
        fn_801F4724(&(*lbl_8045E404), &(*lbl_804001A8));
        fn_801F4760(&(*lbl_8045E41C), &(*lbl_804001C8));
        fn_801F479C(&(*lbl_8045E434), &(*lbl_804001E8));
        fn_801F47D8(&(*lbl_8045E44C), &(*lbl_80400208));
        fn_801F4814(&(*lbl_8045E464), &(*lbl_80400228));
        fn_801F4850(&(*lbl_8045E47C), &(*lbl_80400248));
        fn_801F488C(&(*lbl_8045E494), &(*lbl_80400268));
        fn_801F48C8(&(*lbl_8045E4AC), &(*lbl_80400288));
        fn_801F4904(&(*lbl_8045E4C4), &(*lbl_804002A8));
        fn_801F4940(&(*lbl_8045E4DC), &(*lbl_804002C8));
        fn_801F497C(&(*lbl_8045E4F4), &(*lbl_804002E8));
        fn_801F49B8(&(*lbl_8045E50C), &(*lbl_80400308));
        fn_801F49F4(&(*lbl_8045E524), &(*lbl_80400328));
        fn_801F4A30(&(*lbl_8045E53C), &(*lbl_80400348));
        fn_801F4A6C(&(*lbl_8045E554), &(*lbl_80400368));
        fn_801F4AA8(&(*lbl_8045E56C), &(*lbl_80400388));
        fn_801F4AE4(&(*lbl_8045E584), &(*lbl_804003A8));
        fn_801F4B20(&(*lbl_8045E59C), &(*lbl_804003C8));
        fn_801F4B5C(&(*lbl_8045E5B4), &(*lbl_804003E8));
        fn_801F4B98(&(*lbl_8045E5CC), &(*lbl_80400408));
        fn_801F4BD4(&(*lbl_8045E5E4), &(*lbl_80400428));
        fn_801F4C10(&(*lbl_8045E5FC), &(*lbl_80400448));
    }
}

extern M2C_UNK lbl_8045E6A8[];
extern s32 lbl_804B05C0;

void w3d_auto_801f5fc0(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_8045E6A8));
    lbl_804B05C0 = fn_801F5F58();
block_3:
    return;
}

extern M2C_UNK lbl_8045E748[];

void w3d_auto_801f76b8(s32 arg0, float arg_f1) {
    fn_801F7620(arg0, &(*lbl_8045E748), arg_f1);
    return;
}

extern M2C_UNK lbl_8045E7B8[];

void w3d_auto_801f7be8(void) {
    fn_8020FCB4(&(*lbl_8045E7B8));
    return;
}

extern M2C_UNK lbl_8045E7E8[];
extern s32 lbl_804B05CC;

void w3d_auto_801f81c8(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_8045E7E8));
    lbl_804B05CC = fn_801F8160();
block_3:
    return;
}

s32 w3d_auto_801f8554(s32 arg0, s32 arg1, s32 arg2, Ptr32<s32> arg3) {
    *arg3 = 0;
    return 0x80004001;
}

s32 w3d_auto_801f86c4(s32 arg0, s32 arg1, s32 arg2, Ptr32<s32> arg3) {
    *arg3 = 0;
    return 0x80004001;
}

s32 w3d_auto_801f86d8(s32 arg0, s32 arg1, s32 arg2, Ptr32<s32> arg3) {
    *arg3 = 0;
    return 0x80004001;
}

s32 w3d_auto_801f8b7c(s32 arg0, Ptr32<void> arg1, s32 arg2) {
    M2C_FIELD(arg1, s32 *, 0) = fn_801F87F0(w3d::G(arg2));
    M2C_FIELD(arg1, s8 *, 6) = fn_801F8830(w3d::G(arg2 + 4));
    M2C_FIELD(arg1, s8 *, 0x4) = fn_801F8830(w3d::G(arg2 + 6));
    M2C_FIELD(arg1, s16 *, 8) = fn_801F881C(w3d::G(arg2 + 8));
    M2C_FIELD(arg1, s16 *, 0xA) = fn_801F881C(w3d::G(arg2 + 0xA));
    M2C_FIELD(arg1, s32 *, 0xC) = fn_801F87F0(w3d::G(arg2 + 0xC));
    M2C_FIELD(arg1, s32 *, 0x10) = fn_801F87F0(w3d::G(arg2 + 0x10));
    M2C_FIELD(arg1, s32 *, 0x14) = fn_801F87F0(w3d::G(arg2 + 0x14));
    M2C_FIELD(arg1, s32 *, 0x18) = fn_801F87F0(w3d::G(arg2 + 0x18));
    M2C_FIELD(arg1, s16 *, 0x1C) = fn_801F881C(w3d::G(arg2 + 0x1C));
    M2C_FIELD(arg1, s16 *, 0x1E) = fn_801F881C(w3d::G(arg2 + 0x1E));
    M2C_FIELD(arg1, s16 *, 0x20) = fn_801F881C(w3d::G(arg2 + 0x20));
    M2C_FIELD(arg1, s32 *, 0x2C) = fn_801F87F0(w3d::G(arg2 + 0x2A));
    return 0;
}

s32 w3d_auto_801f9634(s32 arg0, s32 arg1, s32 arg2, Ptr32<s32> arg3) {
    if (arg3 == NULL) {
        goto block_2;
    }
    *arg3 = 0;
block_2:
    return 0x80004001;
}

extern M2C_UNK lbl_803B1C04[];

s32 w3d_auto_801fb088(s32 arg0, s32 arg1) {
    fn_8020BD38(arg1, &(*lbl_803B1C04));
    return 0;
}

extern M2C_UNK lbl_8045E854[];
extern s32 lbl_804B05D0;

void w3d_auto_801fbfcc(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_8045E854));
    lbl_804B05D0 = fn_801FBF64();
block_3:
    return;
}

s32 w3d_auto_801fc4ac(s32 arg0, Ptr32<s32> arg1) {
    if (arg1 == NULL) {
        goto block_2;
    }
    *arg1 = 0;
block_2:
    return 0x80004001;
}

}
