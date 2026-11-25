#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s11descriptors_80257110.c"
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
M2C_UNK fn_801EB9F8(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
extern M2C_UNK lbl_803C90D0[];
extern M2C_UNK lbl_803C9100[];
extern M2C_UNK lbl_803C9138[];
extern M2C_UNK lbl_803C916C[];
extern M2C_UNK lbl_803C91A0[];
extern M2C_UNK lbl_803C91D8[];
extern M2C_UNK lbl_803C920C[];
extern M2C_UNK lbl_803C9240[];
extern M2C_UNK lbl_803C9270[];
extern M2C_UNK lbl_803C929C[];
extern M2C_UNK lbl_803C92D0[];
extern M2C_UNK lbl_803C9300[];
extern M2C_UNK lbl_803C9334[];
extern M2C_UNK lbl_803C9368[];
extern M2C_UNK lbl_803C93A0[];
extern M2C_UNK lbl_803C93D0[];
extern M2C_UNK lbl_803C9408[];
extern M2C_UNK lbl_803C943C[];
extern M2C_UNK lbl_803C946C[];
extern M2C_UNK lbl_803C94A0[];
extern M2C_UNK lbl_803C94D4[];
extern M2C_UNK lbl_803C9508[];
extern M2C_UNK lbl_803C953C[];
extern M2C_UNK lbl_803C956C[];
extern M2C_UNK lbl_803C95A0[];
extern M2C_UNK lbl_803C95D8[];
extern M2C_UNK lbl_803C960C[];
extern M2C_UNK lbl_803C9640[];
extern M2C_UNK lbl_803C9674[];
extern M2C_UNK lbl_803C96A8[];
extern M2C_UNK lbl_803C96D8[];
extern M2C_UNK lbl_803C970C[];
extern M2C_UNK lbl_803C9740[];
extern M2C_UNK lbl_803C9774[];
extern M2C_UNK lbl_803C97AC[];
extern M2C_UNK lbl_803C97E0[];
extern M2C_UNK lbl_803C9814[];
extern M2C_UNK lbl_803C9848[];
extern M2C_UNK lbl_803C987C[];
extern M2C_UNK lbl_803C98AC[];
extern M2C_UNK lbl_803C98DC[];
extern M2C_UNK lbl_803C9910[];
extern M2C_UNK lbl_803C9944[];
extern M2C_UNK lbl_803C9974[];
extern M2C_UNK lbl_803C99A8[];
extern M2C_UNK lbl_803C99E0[];
extern M2C_UNK lbl_803C9A18[];
extern M2C_UNK lbl_803C9A4C[];
extern M2C_UNK lbl_803C9A80[];
extern M2C_UNK lbl_803C9AB4[];
extern M2C_UNK lbl_803C9AE4[];

s32 w3d_auto_80257110(Ptr32<M2C_UNK> arg0) {
    fn_801EB9F8(arg0, &(*lbl_803C90D0));
    fn_801EB9F8(arg0, &(*lbl_803C9100));
    fn_801EB9F8(arg0, &(*lbl_803C9138));
    fn_801EB9F8(arg0, &(*lbl_803C916C));
    fn_801EB9F8(arg0, &(*lbl_803C91A0));
    fn_801EB9F8(arg0, &(*lbl_803C91D8));
    fn_801EB9F8(arg0, &(*lbl_803C920C));
    fn_801EB9F8(arg0, &(*lbl_803C9240));
    fn_801EB9F8(arg0, &(*lbl_803C9270));
    fn_801EB9F8(arg0, &(*lbl_803C929C));
    fn_801EB9F8(arg0, &(*lbl_803C92D0));
    fn_801EB9F8(arg0, &(*lbl_803C9300));
    fn_801EB9F8(arg0, &(*lbl_803C9334));
    fn_801EB9F8(arg0, &(*lbl_803C9368));
    fn_801EB9F8(arg0, &(*lbl_803C93A0));
    fn_801EB9F8(arg0, &(*lbl_803C93D0));
    fn_801EB9F8(arg0, &(*lbl_803C9408));
    fn_801EB9F8(arg0, &(*lbl_803C943C));
    fn_801EB9F8(arg0, &(*lbl_803C946C));
    fn_801EB9F8(arg0, &(*lbl_803C94A0));
    fn_801EB9F8(arg0, &(*lbl_803C94D4));
    fn_801EB9F8(arg0, &(*lbl_803C9508));
    fn_801EB9F8(arg0, &(*lbl_803C953C));
    fn_801EB9F8(arg0, &(*lbl_803C956C));
    fn_801EB9F8(arg0, &(*lbl_803C95A0));
    fn_801EB9F8(arg0, &(*lbl_803C95D8));
    fn_801EB9F8(arg0, &(*lbl_803C960C));
    fn_801EB9F8(arg0, &(*lbl_803C9640));
    fn_801EB9F8(arg0, &(*lbl_803C9674));
    fn_801EB9F8(arg0, &(*lbl_803C96A8));
    fn_801EB9F8(arg0, &(*lbl_803C96D8));
    fn_801EB9F8(arg0, &(*lbl_803C970C));
    fn_801EB9F8(arg0, &(*lbl_803C9740));
    fn_801EB9F8(arg0, &(*lbl_803C9774));
    fn_801EB9F8(arg0, &(*lbl_803C97AC));
    fn_801EB9F8(arg0, &(*lbl_803C97E0));
    fn_801EB9F8(arg0, &(*lbl_803C9814));
    fn_801EB9F8(arg0, &(*lbl_803C9848));
    fn_801EB9F8(arg0, &(*lbl_803C987C));
    fn_801EB9F8(arg0, &(*lbl_803C98AC));
    fn_801EB9F8(arg0, &(*lbl_803C98DC));
    fn_801EB9F8(arg0, &(*lbl_803C9910));
    fn_801EB9F8(arg0, &(*lbl_803C9944));
    fn_801EB9F8(arg0, &(*lbl_803C9974));
    fn_801EB9F8(arg0, &(*lbl_803C99A8));
    fn_801EB9F8(arg0, &(*lbl_803C99E0));
    fn_801EB9F8(arg0, &(*lbl_803C9A18));
    fn_801EB9F8(arg0, &(*lbl_803C9A4C));
    fn_801EB9F8(arg0, &(*lbl_803C9A80));
    fn_801EB9F8(arg0, &(*lbl_803C9AB4));
    fn_801EB9F8(arg0, &(*lbl_803C9AE4));
    fn_801E8D9C(arg0);
    return 0;
}

}
