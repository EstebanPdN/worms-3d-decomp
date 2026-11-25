#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autof_80017cc4.c"
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

M2C_UNK fn_80007D58(M2C_UNK);                       /* extern */
M2C_UNK fn_80008098(Ptr32<void>);                           /* extern */
M2C_UNK fn_80008D84(s32);                           /* extern */
M2C_UNK fn_80009404();                              /* extern */
M2C_UNK fn_8000953C();                              /* extern */

extern f64 lbl_8036A830[];
extern f32 lbl_8036A838[];
extern f32 lbl_8036A83C[];
extern s32 lbl_804AA574;
extern s32 lbl_804AA58C;
extern s32 lbl_804AA5A0;
extern Ptr32<void> lbl_804AA6D8;

void w3d_auto_80017cc4(s32 arg0) {
    if ((s32) lbl_804AA5A0 == 0) {
        goto block_2;
    }
    fn_80008D84(0xBB8);
block_2:
    fn_80009404();
    if ((s32) lbl_804AA58C != 0) {
        goto block_4;
    }
    fn_80008D84((s32) ((M2C_FIELD(lbl_804AA6D8, f32 *, 0x30) - ((f32) (f64) lbl_804AA574 / (*lbl_8036A838))) * (*lbl_8036A83C)));
block_4:
    fn_80007D58(0x2F);
    fn_80008098(w3d::G(arg0 + 0x10));
    fn_80008D84(0x3E8);
    fn_8000953C();
    return;
}

}
