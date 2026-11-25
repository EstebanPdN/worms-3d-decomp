#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "auto_800de930.c"
/* Decompiled automatically by m2c (ppc-gcc-c) via tools/m2c_batch.py and verified identical
 * to the original after linking. Types and names are m2c placeholders pending review. */
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


M2C_UNK fn_802098D8(Ptr32<void>, s32);                      /* extern */
M2C_UNK fn_80209920(Ptr32<void>, s32);                      /* extern */
M2C_UNK fn_80209968(Ptr32<void>);                           /* extern */
M2C_UNK fn_800E0400();                              /* extern */
M2C_UNK fn_8020BD38(s32, Ptr32<void>);                           /* extern */
M2C_UNK fn_800FC6DC();                              /* extern */
M2C_UNK fn_80178C48();                              /* extern */
M2C_UNK fn_803426B4(s32);                           /* extern */
M2C_UNK fn_800DFA00(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void>);                           /* extern */
s32 fn_800DC6FC(Ptr32<void>, s32, Ptr32<void>);                  /* extern */
M2C_UNK fn_800E68F0(Ptr32<void>, s32, Ptr32<void>);                        /* extern */
M2C_UNK fn_800DD334();                              /* extern */
M2C_UNK fn_800E73F0();                              /* extern */
M2C_UNK fn_800E7450(Ptr32<void>);                           float fn_800ECF4C();                              /* extern */
M2C_UNK fn_80164FC8(s32);                           /* extern */
M2C_UNK fn_80122AF8();                              /* extern */
Ptr32<void> fn_801797B4();                                /* extern */
M2C_UNK fn_80341584(s32);                           /* extern */
M2C_UNK fn_800FC1B0(Ptr32<s32>, s32);                    /* extern */
s32 fn_80162BA8();                                  /* extern */
M2C_UNK fn_80162C18(s32);                           /* extern */
M2C_UNK fn_802EEFE0(Ptr32<void>, M2C_UNK, M2C_UNK);         /* extern */

extern s32 lbl_804AB8B4;

void w3d_auto_800de930(s32 arg0) {
    fn_802098D8(w3d::G(lbl_804AB8B4), arg0);
}

extern s32 lbl_804AB8B4;

void w3d_auto_800de958(s32 arg0) {
    fn_80209920(w3d::G(lbl_804AB8B4), arg0);
    fn_80209968(w3d::G(lbl_804AB8B4));
}

void w3d_auto_800dec4c(Ptr32<void> arg0, Ptr32<void> arg1, Ptr32<void> arg2, f32 farg0) {
    f32 temp_f13;
    f32 temp_f13_2;
    f32 temp_f13_3;

    temp_f13 = M2C_FIELD(arg1, f32 *, 0);
    M2C_FIELD(arg0, f32 *, 0) = (f32) ((farg0 * (M2C_FIELD(arg2, f32 *, 0) - temp_f13)) + temp_f13);
    temp_f13_2 = M2C_FIELD(arg1, f32 *, 4);
    M2C_FIELD(arg0, f32 *, 4) = (f32) ((farg0 * (M2C_FIELD(arg2, f32 *, 4) - temp_f13_2)) + temp_f13_2);
    temp_f13_3 = M2C_FIELD(arg1, f32 *, 8);
    M2C_FIELD(arg0, f32 *, 8) = (f32) ((farg0 * (M2C_FIELD(arg2, f32 *, 8) - temp_f13_3)) + temp_f13_3);
}

void w3d_auto_800df684(void) {
    fn_800E0400();
}

void w3d_auto_800df6a4(s32 arg0, Ptr32<void> arg_r4) {
    fn_8020BD38(arg0 + 0x8C, arg_r4);
}

void w3d_auto_800dfddc(Ptr32<void> arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x28) = arg1;
    M2C_FIELD(arg0, s32 *, 0x74) = arg2;
    M2C_FIELD(arg0, s32 *, 0x98) = (s32) (M2C_FIELD(arg0, s32 *, 0x98) | 0x40);
}

void w3d_auto_800dfdf4(Ptr32<void> arg0) {
    fn_803426B4(M2C_FIELD(arg0, s32 *, 0x84));
    fn_80178C48();
    fn_800FC6DC();
}

void w3d_auto_800e2344(s32 arg0, Ptr32<void> arg_r4, Ptr32<void> arg_r5, Ptr32<void> arg_r6) {
    fn_800DFA00(w3d::G(arg0 + 0x1C), arg_r4, arg_r5, arg_r6);
}

void w3d_auto_800e45ac(s32 arg0, Ptr32<void> arg_r4, Ptr32<void> arg_r5, Ptr32<void> arg_r6) {
    fn_800DFA00(w3d::G(arg0 + 0x1C), arg_r4, arg_r5, arg_r6);
}

s32 w3d_auto_800e6898(Ptr32<void> arg0, s32 arg1, s32 arg2) {
    s32 var_r3;

    var_r3 = 0;
    if ((s32) M2C_FIELD(arg0, u8 *, 0x68) != 0) {
        fn_800E68F0(arg0, arg1, w3d::G(arg2));
        var_r3 = fn_800DC6FC(arg0, arg1, w3d::G(arg2));
    }
    return var_r3;
}

void w3d_auto_800e70e0(Ptr32<void> arg0) {
    fn_800DD334();
    M2C_FIELD(arg0, s32 *, 0xAC) = (s32) M2C_FIELD(arg0, s32 *, 0x5C);
}

void w3d_auto_800e73bc(s32 arg0) {
    fn_800E73F0();
    fn_800E7450(w3d::G(arg0));
}

void w3d_auto_800e9678(Ptr32<void> arg0) {
    fn_80164FC8(M2C_FIELD(arg0, s32 *, 0xC0));
    fn_800ECF4C();
}

void w3d_auto_800e9dc8(Ptr32<void> arg0) {
    fn_80164FC8(M2C_FIELD(arg0, s32 *, 0xC4));
    fn_80122AF8();
    M2C_FIELD(arg0, s32 *, 0xC4) = -1;
}

s32 w3d_auto_800edf7c(Ptr32<void> arg0) {
    fn_80341584(M2C_FIELD(arg0, s32 *, 0xC0));
    return M2C_FIELD(fn_801797B4(), s32 *, 0x1F4);
}

void w3d_auto_800ee904(s32 arg0, s32 arg1) {
    s32 sp8;

    sp8 = arg1;
    fn_800FC1B0(&sp8, arg0 + 0x1C);
}

s32 w3d_auto_800f15f0(Ptr32<void> arg0, Ptr32<s32> arg1) {
    *arg1 = (s32) (M2C_FIELD(arg0, s32 *, 4) - M2C_FIELD(arg0, s32 *, 0)) >> 2;
    return M2C_FIELD(arg0, s32 *, 0);
}

void w3d_auto_800f1c60(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 0x28) = 1;
}

void w3d_auto_800f2cec(Ptr32<void> arg0) {
    fn_80162C18(M2C_FIELD(arg0, s32 *, 0xBFC));
    M2C_FIELD(arg0, s32 *, 0xBFC) = fn_80162BA8();
}

void w3d_auto_800f2f14(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s8 *, 0xC68) = 0x1F;
    M2C_FIELD(arg0, s32 *, 0xC60) = 0;
}

void w3d_auto_800f34f8(s32 arg0) {
    fn_802EEFE0(w3d::G(arg0 + 0x3DC), 0, 0x5C);
}

}
