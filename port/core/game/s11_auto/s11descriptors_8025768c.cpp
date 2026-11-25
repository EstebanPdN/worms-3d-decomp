#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s11descriptors_8025768c.c"
/* Range-isolated m2c recovery by worker s11. Types and names are provisional. */
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

M2C_UNK fn_801E8D9C(Ptr32<M2C_UNK>);                     /* extern */
M2C_UNK fn_801EB834(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
extern M2C_UNK lbl_803C9B1C[];
extern M2C_UNK lbl_803C9B44[];
extern M2C_UNK lbl_803C9B6C[];
extern M2C_UNK lbl_803C9B94[];
extern M2C_UNK lbl_803C9BBC[];
extern M2C_UNK lbl_803C9BE4[];
extern M2C_UNK lbl_803C9C0C[];
extern M2C_UNK lbl_803C9C34[];
extern M2C_UNK lbl_803C9C5C[];
extern M2C_UNK lbl_803C9C84[];
extern M2C_UNK lbl_803C9CAC[];
extern M2C_UNK lbl_803C9CD4[];
extern M2C_UNK lbl_803C9CFC[];
extern M2C_UNK lbl_803C9D24[];
extern M2C_UNK lbl_803C9D4C[];
extern M2C_UNK lbl_803C9D74[];
extern M2C_UNK lbl_803C9D9C[];
extern M2C_UNK lbl_803C9DC4[];
extern M2C_UNK lbl_803C9DEC[];
extern M2C_UNK lbl_803C9E14[];
extern M2C_UNK lbl_803C9E3C[];
extern M2C_UNK lbl_803C9E64[];
extern M2C_UNK lbl_803C9E8C[];
extern M2C_UNK lbl_803C9EB4[];
extern M2C_UNK lbl_803C9EDC[];
extern M2C_UNK lbl_803C9F04[];
extern M2C_UNK lbl_803C9F2C[];
extern M2C_UNK lbl_803C9F54[];
extern M2C_UNK lbl_803C9F7C[];
extern M2C_UNK lbl_803C9FA4[];
extern M2C_UNK lbl_803C9FCC[];
extern M2C_UNK lbl_803C9FF4[];
extern M2C_UNK lbl_803CA01C[];
extern M2C_UNK lbl_803CA044[];
extern M2C_UNK lbl_803CA06C[];
extern M2C_UNK lbl_803CA094[];
extern M2C_UNK lbl_803CA0BC[];
extern M2C_UNK lbl_803CA0E4[];
extern M2C_UNK lbl_803CA10C[];
extern M2C_UNK lbl_803CA134[];
extern M2C_UNK lbl_803CA15C[];
extern M2C_UNK lbl_803CA184[];
extern M2C_UNK lbl_803CA1AC[];
extern M2C_UNK lbl_803CA1D4[];
extern M2C_UNK lbl_803CA1FC[];
extern M2C_UNK lbl_803CA224[];
extern M2C_UNK lbl_803CA24C[];
extern M2C_UNK lbl_803CA274[];
extern M2C_UNK lbl_803CA29C[];
extern M2C_UNK lbl_803CA2C4[];
extern M2C_UNK lbl_803CA2EC[];

s32 w3d_auto_8025768c(Ptr32<M2C_UNK> arg0) {
    fn_801EB834(arg0, &(*lbl_803C9B1C));
    fn_801EB834(arg0, &(*lbl_803C9B44));
    fn_801EB834(arg0, &(*lbl_803C9B6C));
    fn_801EB834(arg0, &(*lbl_803C9B94));
    fn_801EB834(arg0, &(*lbl_803C9BBC));
    fn_801EB834(arg0, &(*lbl_803C9BE4));
    fn_801EB834(arg0, &(*lbl_803C9C0C));
    fn_801EB834(arg0, &(*lbl_803C9C34));
    fn_801EB834(arg0, &(*lbl_803C9C5C));
    fn_801EB834(arg0, &(*lbl_803C9C84));
    fn_801EB834(arg0, &(*lbl_803C9CAC));
    fn_801EB834(arg0, &(*lbl_803C9CD4));
    fn_801EB834(arg0, &(*lbl_803C9CFC));
    fn_801EB834(arg0, &(*lbl_803C9D24));
    fn_801EB834(arg0, &(*lbl_803C9D4C));
    fn_801EB834(arg0, &(*lbl_803C9D74));
    fn_801EB834(arg0, &(*lbl_803C9D9C));
    fn_801EB834(arg0, &(*lbl_803C9DC4));
    fn_801EB834(arg0, &(*lbl_803C9DEC));
    fn_801EB834(arg0, &(*lbl_803C9E14));
    fn_801EB834(arg0, &(*lbl_803C9E3C));
    fn_801EB834(arg0, &(*lbl_803C9E64));
    fn_801EB834(arg0, &(*lbl_803C9E8C));
    fn_801EB834(arg0, &(*lbl_803C9EB4));
    fn_801EB834(arg0, &(*lbl_803C9EDC));
    fn_801EB834(arg0, &(*lbl_803C9F04));
    fn_801EB834(arg0, &(*lbl_803C9F2C));
    fn_801EB834(arg0, &(*lbl_803C9F54));
    fn_801EB834(arg0, &(*lbl_803C9F7C));
    fn_801EB834(arg0, &(*lbl_803C9FA4));
    fn_801EB834(arg0, &(*lbl_803C9FCC));
    fn_801EB834(arg0, &(*lbl_803C9FF4));
    fn_801EB834(arg0, &(*lbl_803CA01C));
    fn_801EB834(arg0, &(*lbl_803CA044));
    fn_801EB834(arg0, &(*lbl_803CA06C));
    fn_801EB834(arg0, &(*lbl_803CA094));
    fn_801EB834(arg0, &(*lbl_803CA0BC));
    fn_801EB834(arg0, &(*lbl_803CA0E4));
    fn_801EB834(arg0, &(*lbl_803CA10C));
    fn_801EB834(arg0, &(*lbl_803CA134));
    fn_801EB834(arg0, &(*lbl_803CA15C));
    fn_801EB834(arg0, &(*lbl_803CA184));
    fn_801EB834(arg0, &(*lbl_803CA1AC));
    fn_801EB834(arg0, &(*lbl_803CA1D4));
    fn_801EB834(arg0, &(*lbl_803CA1FC));
    fn_801EB834(arg0, &(*lbl_803CA224));
    fn_801EB834(arg0, &(*lbl_803CA24C));
    fn_801EB834(arg0, &(*lbl_803CA274));
    fn_801EB834(arg0, &(*lbl_803CA29C));
    fn_801EB834(arg0, &(*lbl_803CA2C4));
    fn_801EB834(arg0, &(*lbl_803CA2EC));
    fn_801E8D9C(arg0);
    return 0;
}

}
