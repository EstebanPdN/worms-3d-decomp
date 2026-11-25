#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "auto_8011d6d8.c"
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


M2C_UNK fn_80178C48(Ptr32<void>);                           /* extern */
M2C_UNK fn_80178C54(Ptr32<void>, Ptr32<s32>);                    /* extern */
M2C_UNK fn_80178D28(Ptr32<void>, Ptr32<s32>);                    /* extern */
Ptr32<void> fn_80165254();                                /* extern */
M2C_UNK fn_801817E0(Ptr32<void>, s32);                      /* extern */
s32 fn_80181CCC(Ptr32<void>, s32);                          /* extern */
M2C_UNK fn_8013E3D4();                              /* extern */
M2C_UNK fn_8013C9AC(Ptr32<void>);                        /* extern */

void w3d_auto_8011d6d8(Ptr32<void> arg0) {
    fn_80178C48(w3d::G(M2C_FIELD(arg0, s32 *, 0x88)));
}

void w3d_auto_8011d6fc(Ptr32<void> arg0) {
    fn_80178C48(w3d::G(M2C_FIELD(arg0, s32 *, 0x8C)));
}

void w3d_auto_8011d720(Ptr32<void> arg0) {
    fn_80178C48(w3d::G(M2C_FIELD(arg0, s32 *, 0x90)));
}

void w3d_auto_8011d744(Ptr32<void> arg0) {
    fn_80178C48(w3d::G(M2C_FIELD(arg0, s32 *, 0x94)));
}

void w3d_auto_8011d768(Ptr32<void> arg0) {
    fn_80178C48(w3d::G(M2C_FIELD(arg0, s32 *, 0x98)));
}

void w3d_auto_8011d78c(Ptr32<void> arg0, s32 arg1) {
    s32 sp8;
    s32 spC;

    sp8 = arg1;
    fn_80178C54(w3d::G(M2C_FIELD(arg0, s32 *, 0xA0)), &sp8);
    spC = 2;
    fn_80178D28(w3d::G(M2C_FIELD(arg0, s32 *, 0xB4)), &spC);
}

void w3d_auto_8011d7d8(Ptr32<void> arg0, s32 arg1) {
    s32 sp8;

    sp8 = arg1;
    fn_80178C54(w3d::G(M2C_FIELD(arg0, s32 *, 0x9C)), &sp8);
}

void w3d_auto_8011d804(Ptr32<void> arg0, s32 arg1) {
    s32 sp8;
    s32 spC;

    sp8 = arg1;
    fn_80178C54(w3d::G(M2C_FIELD(arg0, s32 *, 0xA4)), &sp8);
    spC = 1;
    fn_80178D28(w3d::G(M2C_FIELD(arg0, s32 *, 0xB4)), &spC);
}

void w3d_auto_8011d850(Ptr32<void> arg0, s32 arg1) {
    s32 sp8;
    s32 spC;

    sp8 = arg1;
    fn_80178C54(w3d::G(M2C_FIELD(arg0, s32 *, 0xA8)), &sp8);
    spC = 0;
    fn_80178D28(w3d::G(M2C_FIELD(arg0, s32 *, 0xB4)), &spC);
}

void w3d_auto_8011d89c(Ptr32<void> arg0, s32 arg1) {
    s32 sp8;
    s32 spC;

    sp8 = arg1;
    fn_80178C54(w3d::G(M2C_FIELD(arg0, s32 *, 0xAC)), &sp8);
    spC = 0;
    fn_80178D28(w3d::G(M2C_FIELD(arg0, s32 *, 0xB4)), &spC);
}

extern u16 lbl_804AB078;
extern u16 lbl_804AB07A;
extern u16 lbl_804AB07C;
extern s32 lbl_804AF594;
extern s32 lbl_804AF598;
extern s32 lbl_804AF59C;

void w3d_auto_8012603c(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        lbl_804AF594 = (s32) lbl_804AB078;
        lbl_804AF598 = (s32) lbl_804AB07A;
        lbl_804AF59C = (s32) lbl_804AB07C;
    }
}

s32 w3d_auto_801359c8(void) {
    return M2C_FIELD(fn_80165254(), s32 *, 0x38);
}

void w3d_auto_80139454(Ptr32<void> arg0, s32 arg1) {
    if (((s32) M2C_FIELD(arg0, s32 *, 0x294) == 0) && (fn_80181CCC(w3d::G(arg1), M2C_FIELD(arg0, s32 *, 0x1DC)) == 0)) {
        fn_801817E0(w3d::G(arg1), M2C_FIELD(arg0, s32 *, 0x1DC));
    }
}

void w3d_auto_80139994(void) {
    fn_8013E3D4();
}

void w3d_auto_8013c938(Ptr32<void> arg0) {
    if (((s32) M2C_FIELD(arg0, s32 *, 0x1F0) == 0xA) && ((u32) M2C_FIELD(fn_80165254(), u32 *, 0x34) > (u32) M2C_FIELD(arg0, u32 *, 0x2B8))) {
        M2C_FIELD(arg0, s32 *, 0x2B0) = 1;
        return;
    }
    if (((s32) M2C_FIELD(arg0, s32 *, 0x2B4) != 0) && ((s32) M2C_FIELD(arg0, s32 *, 0x1F0) != 0xA)) {
        fn_8013C9AC(arg0);
    }
}

}
