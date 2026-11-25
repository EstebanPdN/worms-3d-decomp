#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "auto_80348758.c"
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


M2C_UNK fn_80210AFC(Ptr32<void>);                           /* extern */
M2C_UNK fn_801A360C(Ptr32<void>, Ptr32<void>);                           /* extern */
M2C_UNK fn_801A2360(Ptr32<void>);                           /* extern */
M2C_UNK fn_801A1E48(Ptr32<void>, s32);                           /* extern */
M2C_UNK fn_801EDE8C();                              /* extern */

s32 w3d_auto_80348758(Ptr32<void> arg0) {
    return ((u32) M2C_FIELD(arg0, u32 *, 0x30) >> 0x1EU) & 1;
}

s32 w3d_auto_80348bbc(Ptr32<void> arg0) {
    return (s32) (M2C_FIELD(arg0, s32 *, 0x1C) - M2C_FIELD(arg0, s32 *, 0x18)) >> 5;
}

s32 w3d_auto_80348cf0(Ptr32<void> arg0, s32 arg1) {
    return M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x18) + (arg1 << 5)), s32 *, 4);
}

s32 w3d_auto_80348e08(Ptr32<void> arg0, s32 arg1) {
    return M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x18) + (arg1 << 5)), s32 *, 8);
}

s32 w3d_auto_803499e4(void) {
    return 0x80004001;
}

s32 w3d_auto_80349a3c(Ptr32<void> arg0) {
    return ((u32) M2C_FIELD(arg0, u32 *, 0x30) >> 0x1EU) & 1;
}

s32 w3d_auto_80349eb0(Ptr32<void> arg0) {
    return (s32) (M2C_FIELD(arg0, s32 *, 0x1C) - M2C_FIELD(arg0, s32 *, 0x18)) >> 5;
}

s32 w3d_auto_80349fe4(Ptr32<void> arg0, s32 arg1) {
    return M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x18) + (arg1 << 5)), s32 *, 4);
}

s32 w3d_auto_8034a0fc(Ptr32<void> arg0, s32 arg1) {
    return M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x18) + (arg1 << 5)), s32 *, 8);
}

void w3d_auto_8034ba50(s32 arg0) {
    fn_80210AFC(w3d::G(arg0 + 0x4C));
}

s32 w3d_auto_8034bb30(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x70) = arg1;
    return 0;
}

s32 w3d_auto_8034bc58(Ptr32<void> arg0, Ptr32<s32> arg1) {
    *arg1 = M2C_FIELD(arg0, s32 *, 0x88);
    return M2C_FIELD(arg0, s32 *, 0x90);
}

void w3d_auto_8034be2c(Ptr32<void> arg0, Ptr32<void> arg_r4) {
    fn_801A360C(w3d::G(M2C_FIELD(arg0, s32 *, 0x74)), arg_r4);
}

s32 w3d_auto_8034be50(Ptr32<void> arg0, f32 farg0) {
    M2C_FIELD(arg0, f32 *, 0x28) = farg0;
    return 0;
}

s32 w3d_auto_8034be64(void) {
    return 0x80004001;
}

void w3d_auto_8034cb20(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s16 *, 4) = -1;
}

void w3d_auto_803515a0(Ptr32<s8> arg0) {
    *arg0 = 0;
}

extern s32 lbl_804AB74C;

void w3d_auto_80352868(void) {
    fn_801A2360(w3d::G(lbl_804AB74C));
}

extern s32 lbl_804AB74C;

void w3d_auto_8035288c(Ptr32<void> arg0, s32 arg1) {
    fn_801A1E48(w3d::G(lbl_804AB74C), arg1);
}

void w3d_auto_80356370(Ptr32<void> arg0, Ptr32<void> arg1) {
    M2C_FIELD(arg0, u8 *, 0) = (u8) M2C_FIELD(arg1, u8 *, 0);
    M2C_FIELD(arg0, u8 *, 1) = (u8) M2C_FIELD(arg1, u8 *, 1);
    M2C_FIELD(arg0, u8 *, 2) = (u8) M2C_FIELD(arg1, u8 *, 2);
    M2C_FIELD(arg0, u8 *, 3) = (u8) M2C_FIELD(arg1, u8 *, 3);
}

void w3d_auto_80356394(Ptr32<void> arg0, Ptr32<void> arg1) {
    M2C_FIELD(arg1, u8 *, 0) = (u8) M2C_FIELD(arg0, u8 *, 0);
    M2C_FIELD(arg1, u8 *, 1) = (u8) M2C_FIELD(arg0, u8 *, 1);
    M2C_FIELD(arg1, u8 *, 2) = (u8) M2C_FIELD(arg0, u8 *, 2);
    M2C_FIELD(arg1, u8 *, 3) = (u8) M2C_FIELD(arg0, u8 *, 3);
}

void w3d_auto_803563dc(Ptr32<void> arg0, Ptr32<void> arg1) {
    M2C_FIELD(arg1, u8 *, 0) = (u8) M2C_FIELD(arg0, u8 *, 0);
    M2C_FIELD(arg1, u8 *, 1) = (u8) M2C_FIELD(arg0, u8 *, 1);
    M2C_FIELD(arg1, u8 *, 2) = (u8) M2C_FIELD(arg0, u8 *, 2);
}

void w3d_auto_803563f8(Ptr32<void> arg0, Ptr32<s16> arg1) {
    *arg1 = ((M2C_FIELD(arg0, u8 *, 3) << 8) & 0x8000) | (((u8) M2C_FIELD(arg0, u8 *, 0) >> 3U) | ((M2C_FIELD(arg0, u8 *, 1) * 4) & 0x3E0) | ((M2C_FIELD(arg0, u8 *, 2) << 7) & 0x7C00));
}

void w3d_auto_803580b8(void) {
    fn_801EDE8C();
}

void w3d_auto_803580d8(void) {
    fn_801EDE8C();
}

void w3d_auto_803580f8(void) {
    fn_801EDE8C();
}

s32 w3d_auto_8035a1f8(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 8) = -1;
    return 0;
}

s32 w3d_auto_8035a220(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 4) = -1;
    return 0;
}

void w3d_auto_8035c4c4(Ptr32<s8> arg0) {
    *arg0 = 0;
}

}
