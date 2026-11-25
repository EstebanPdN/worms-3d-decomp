#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "auto_8000d278.c"
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


s32 fn_8000A7AC();                                  /* extern */
M2C_UNK fn_8000B6BC(Ptr32<void>, s32);                      /* extern */
s32 fn_8000A800();                                  /* extern */
M2C_UNK fn_8000E0EC();                              /* extern */
M2C_UNK fn_80010630();                              /* extern */

void w3d_auto_8000d278(s32 arg0) {
    fn_8000B6BC(w3d::G(arg0), fn_8000A7AC());
}

extern s32 lbl_804AA5EC;

s32 w3d_auto_8000d2bc(void) {
    return lbl_804AA5EC;
}

extern s32 lbl_804AA5F0;

s32 w3d_auto_8000d314(void) {
    return lbl_804AA5F0;
}

extern s32 lbl_804AA5F4;

s32 w3d_auto_8000d31c(void) {
    return lbl_804AA5F4;
}

extern s32 lbl_804AA5F8;

s32 w3d_auto_8000d368(void) {
    return lbl_804AA5F8;
}

extern s32 lbl_804AA5FC;

s32 w3d_auto_8000d560(void) {
    return lbl_804AA5FC;
}

extern s32 lbl_804AA600;

s32 w3d_auto_8000da84(void) {
    return lbl_804AA600;
}

void w3d_auto_8000db9c(s32 arg0) {
    fn_8000B6BC(w3d::G(arg0), fn_8000A800());
}

extern s32 lbl_804AA604;

s32 w3d_auto_8000dca4(void) {
    return lbl_804AA604;
}

extern s32 lbl_804AA608;

s32 w3d_auto_8000dcb0(void) {
    return lbl_804AA608;
}

extern s32 lbl_804AA60C;

s32 w3d_auto_8000dce8(void) {
    return lbl_804AA60C;
}

extern s32 lbl_804AA610;

s32 w3d_auto_8000dcfc(void) {
    return lbl_804AA610;
}

extern s32 lbl_804AA614;

s32 w3d_auto_8000e0e4(void) {
    return lbl_804AA614;
}

extern s32 lbl_804AA618;

s32 w3d_auto_8000eaec(void) {
    return lbl_804AA618;
}

extern s32 lbl_804AA61C;

s32 w3d_auto_8000eaf8(void) {
    return lbl_804AA61C;
}

extern s32 lbl_804AA620;

s32 w3d_auto_8000eb04(void) {
    return lbl_804AA620;
}

extern s32 lbl_804AA624;

s32 w3d_auto_8000eb10(void) {
    return lbl_804AA624;
}

extern Ptr32<void> lbl_804AA6D8;

void w3d_auto_8000eb1c(Ptr32<void> arg0) {
    fn_8000E0EC();
    M2C_FIELD(arg0, f32 *, 4) = (f32) (M2C_FIELD(arg0, f32 *, 4) * M2C_FIELD(lbl_804AA6D8, f32 *, 0x54));
}

extern s32 lbl_804AA628;

s32 w3d_auto_8000eb5c(void) {
    return lbl_804AA628;
}

extern s32 lbl_804AA62C;

s32 w3d_auto_800102f4(void) {
    return lbl_804AA62C;
}

extern s32 lbl_804AA630;

s32 w3d_auto_80010440(void) {
    return lbl_804AA630;
}

extern s32 lbl_804AA634;

s32 w3d_auto_8001044c(void) {
    return lbl_804AA634;
}

extern s32 lbl_804AA638;

s32 w3d_auto_80010458(void) {
    return lbl_804AA638;
}

extern s32 lbl_804AA63C;

s32 w3d_auto_80010578(void) {
    return lbl_804AA63C;
}

extern s32 lbl_804AA640;

s32 w3d_auto_800105c4(void) {
    return lbl_804AA640;
}

extern s32 lbl_804AA644;

s32 w3d_auto_80010878(void) {
    return lbl_804AA644;
}

extern s32 lbl_804AA648;

s32 w3d_auto_80010884(void) {
    return lbl_804AA648;
}

extern s32 lbl_804AA64C;

s32 w3d_auto_80010890(void) {
    return lbl_804AA64C;
}

void w3d_auto_80010898(void) {
    fn_80010630();
}

extern s32 lbl_804AA650;

s32 w3d_auto_800108e8(void) {
    return lbl_804AA650;
}

extern s32 lbl_804AA654;

s32 w3d_auto_800108f4(void) {
    return lbl_804AA654;
}

extern s32 lbl_804AA658;

s32 w3d_auto_80010900(void) {
    return lbl_804AA658;
}

extern s32 lbl_804AA65C;

s32 w3d_auto_8001090c(void) {
    return lbl_804AA65C;
}

extern s32 lbl_804AA660;

s32 w3d_auto_80010918(void) {
    return lbl_804AA660;
}

extern s32 lbl_804AA664;

s32 w3d_auto_80010e6c(void) {
    return lbl_804AA664;
}

extern s32 lbl_804AA668;

s32 w3d_auto_80010fec(void) {
    return lbl_804AA668;
}

extern s32 lbl_804AA66C;

s32 w3d_auto_8001104c(void) {
    return lbl_804AA66C;
}

extern s32 lbl_804AA670;

s32 w3d_auto_800110a0(void) {
    return lbl_804AA670;
}

extern s32 lbl_804AA674;

s32 w3d_auto_800110f4(void) {
    return lbl_804AA674;
}

extern s32 lbl_804AA678;

s32 w3d_auto_800113a8(void) {
    return lbl_804AA678;
}

}
