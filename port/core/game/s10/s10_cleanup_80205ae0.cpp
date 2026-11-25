#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10_cleanup_80205ae0.c"
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
M2C_UNK fn_801FE1F8(Ptr32<void>);                        void fn_8020C5C4(s32);                           /* extern */
M2C_UNK fn_80210990(Ptr32<void>, M2C_UNK);               /* extern */
M2C_UNK fn_80210ABC(Ptr32<void>, M2C_UNK);               /* extern */
M2C_UNK fn_802134FC(Ptr32<void>);                              /* extern */
M2C_UNK fn_80341588(Ptr32<void>);                           /* extern */
extern M2C_UNK lbl_804190F0[];
extern M2C_UNK lbl_80419138[];

void w3d_s10_cleanup_80205ae0(Ptr32<void> arg0, s32 arg1) {
    s32 temp_r27;
    s32 temp_r29_2;
    s32 temp_r30;
    s32 temp_r31;
    s32 var_r30;
    Ptr32<Ptr32<Ptr32<void>>> var_r31;
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r26;
    Ptr32<void> temp_r29;

    temp_r29 = arg0 + 0x30;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_804190F0);
    var_r30 = M2C_FIELD(arg0, s32 *, 0x30);
    temp_r31 = M2C_FIELD(temp_r29, s32 *, 4);
    if (var_r30 == temp_r31) {
        goto block_2;
    }
loop_1:
    fn_8020C5C4(var_r30);
    fn_80341588(w3d::G(var_r30));
    var_r30 += 4;
    if (var_r30 != temp_r31) {
        goto loop_1;
    }
block_2:
    if ((s32) M2C_FIELD(temp_r29, s32 *, 0) == 0) {
        goto block_4;
    }
    fn_802134FC(w3d::G(M2C_FIELD(temp_r29, s32 *, 0)));
block_4:
    fn_80210ABC(arg0 + 0x24, 2);
    temp_r26 = arg0 + 0x14;
    temp_r27 = M2C_FIELD(temp_r26, s32 *, 4);
    var_r31 = M2C_FIELD(arg0, Ptr32<Ptr32<Ptr32<void>>> *, 0x14);
    if (var_r31 == w3d::G(temp_r27)) {
        goto block_8;
    }
loop_5:
    temp_r30 = (s32)w3d::H(((Ptr32<char>)var_r31 + 8));
    temp_r29_2 = (s32)w3d::H(((Ptr32<char>)var_r31 + 4));
    fn_8020C5C4(temp_r30);
    fn_80341588(w3d::G(temp_r30));
    fn_8020C5C4(temp_r29_2);
    fn_80341588(w3d::G(temp_r29_2));
    temp_r3 = *var_r31;
    if (temp_r3 == NULL) {
        goto block_7;
    }
    M2C_FIELD(*temp_r3, Ptr32<M2C_UNK (Ptr32<void>)> *, 0x10)(temp_r3);
block_7:
    var_r31 = (Ptr32<void>)((Ptr32<char>)var_r31 + 0xC);
    if (var_r31 != w3d::G(temp_r27)) {
        goto loop_5;
    }
block_8:
    if ((s32) M2C_FIELD(temp_r26, s32 *, 0) == 0) {
        goto block_10;
    }
    fn_802134FC(w3d::G(M2C_FIELD(temp_r26, s32 *, 0)));
block_10:
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_80419138);
    fn_80210990(arg0 + 4, 0);
    if (!(arg1 & 1)) {
        goto block_12;
    }
    fn_801FE1F8(arg0);
block_12:
    return;
}

}
