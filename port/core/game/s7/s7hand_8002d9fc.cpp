#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s7hand_8002d9fc.c"
/* Recovered from original instructions; inferred types and names. */
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
M2C_UNK fn_8004E460(Ptr32<void>);                              /* extern */
M2C_UNK fn_80181640(s32, Ptr32<M2C_UNK>, Ptr32<s32>, M2C_UNK, f32, f32, f32); /* extern */
M2C_UNK fn_8018179C(Ptr32<void>, s32, M2C_UNK);             /* extern */
extern M2C_UNK lbl_80372B14[];
extern f32 lbl_80372B20[];
extern f32 lbl_80372B24[];

void w3d_auto_8002d9fc(Ptr32<void> arg0) {
    s32 sp8;
    u32 var_r29;
    Ptr32<Ptr32<Ptr32<void>>> var_r31;
    Ptr32<Ptr32<void>> temp_r3;

    var_r29 = 0U;
    var_r31 = arg0 + 0x5C;
    fn_8004E460(arg0);
    fn_80181640(M2C_FIELD(arg0, s32 *, 0x1C), &(*lbl_80372B14), &sp8, 1, (*lbl_80372B20), M2C_FIELD(arg0, f32 *, 0x4C), (*lbl_80372B24));
    fn_8018179C(w3d::G(M2C_FIELD(arg0, s32 *, 0x1C)), sp8, 1);
loop_1:
    temp_r3 = *var_r31;
    var_r29 += 1;
    var_r31 += 1;
    M2C_FIELD(*temp_r3, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, M2C_UNK)> *, 0x58)(temp_r3, 1);
    if (var_r29 <= 4U) {
        goto loop_1;
    }
    return;
}

}
