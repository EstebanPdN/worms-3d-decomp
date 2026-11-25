#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "auto_801fc488.c"
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


M2C_UNK fn_8016E698();                              /* extern */
M2C_UNK fn_8035A3A8();                              /* extern */
Ptr32<s32> fn_8020017C();                                 /* extern */
Ptr32<void> fn_802001A8();                                /* extern */
Ptr32<void> fn_802001D4();                                /* extern */
Ptr32<void> fn_80200460();                                /* extern */
M2C_UNK fn_80204760();                              /* extern */
M2C_UNK fn_8020430C();                              /* extern */

s32 w3d_auto_801fc488(void) {
    return 0x80004001;
}

s32 w3d_auto_801fc494(void) {
    return 0x80004001;
}

s32 w3d_auto_801fc4a0(void) {
    return 0x80004001;
}

s32 w3d_auto_801fc4d0(void) {
    return 0x80004001;
}

s32 w3d_auto_801fc4dc(void) {
    return 0x80004001;
}

s32 w3d_auto_801fc4e8(void) {
    return 0x80004001;
}

s32 w3d_auto_801fc4f4(void) {
    return 0x80004001;
}

s32 w3d_auto_801fc500(void) {
    return 0x80004001;
}

s32 w3d_auto_801fc50c(void) {
    return 0x80004001;
}

s32 w3d_auto_801fc5b8(void) {
    return 0x80004001;
}

s32 w3d_auto_801fc5c4(void) {
    return 0x80004001;
}

s32 w3d_auto_801fc5d0(void) {
    return 0x80004001;
}

s32 w3d_auto_801fc5dc(void) {
    return 0x80004001;
}

s32 w3d_auto_801fc5e8(void) {
    return 0x80004001;
}

s32 w3d_auto_801fc688(void) {
    return 0x80004001;
}

s32 w3d_auto_801fc6a4(void) {
    return 0x80004001;
}

s32 w3d_auto_801fc6b0(void) {
    return 0x80004001;
}

s32 w3d_auto_801fc6bc(void) {
    return 0x80004001;
}

extern s32 lbl_804AB92C;

s32 w3d_auto_801fcd6c(void) {
    return lbl_804AB92C;
}

extern s32 lbl_804AB93C;

void w3d_auto_801fdb98(s32 arg0) {
    if (arg0 == -1) {
        lbl_804AB93C = arg0;
        return;
    }
    lbl_804AB93C = 1;
}

void w3d_auto_801fdbb4(Ptr32<void> arg0, s32 arg1) {
    fn_8035A3A8();
    fn_8016E698();
    M2C_FIELD(arg0, s32 *, 4) = arg1;
}

s32 w3d_auto_801ffe9c(void) {
    return 0x80004001;
}

s32 w3d_auto_801ffea8(void) {
    return *fn_8020017C();
}

u8 w3d_auto_801fff18(void) {
    return M2C_FIELD(fn_802001A8(), u8 *, 0x14);
}

s32 w3d_auto_801fff3c(void) {
    return M2C_FIELD(fn_802001A8(), s32 *, 8);
}

s32 w3d_auto_801fffc8(void) {
    return ((u16) M2C_FIELD(fn_802001A8(), u16 *, 4) >> 6U) & 0x1F;
}

u16 w3d_auto_80200050(void) {
    return M2C_FIELD(fn_802001A8(), u16 *, 6);
}

u8 w3d_auto_80200074(void) {
    return M2C_FIELD(fn_802001A8(), u8 *, 0x10);
}

u16 w3d_auto_80200134(void) {
    return M2C_FIELD(fn_802001D4(), u16 *, 6);
}

s32 w3d_auto_80200158(void) {
    return M2C_FIELD(fn_802001D4(), s32 *, 8);
}

u8 w3d_auto_8020043c(void) {
    return M2C_FIELD(fn_80200460(), u8 *, 0x11);
}

s32 w3d_auto_80202418(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x24) = arg1;
    return 0;
}

s32 w3d_auto_80202f28(void) {
    return 0x80004001;
}

void w3d_auto_80203fb8(void) {
    fn_80204760();
}

void w3d_auto_802042ec(void) {
    fn_8020430C();
}

}
