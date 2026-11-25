#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "auto4_80029688.c"
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


M2C_UNK fn_8002988C(Ptr32<void>);                           /* extern */
M2C_UNK fn_8002A040(Ptr32<void>);                           /* extern */
M2C_UNK fn_8002A0C0(Ptr32<void>, Ptr32<u16>);                    /* extern */
M2C_UNK fn_8002A12C(Ptr32<void>, M2C_UNK);                  /* extern */
s32 fn_8015F65C(u16, Ptr32<M2C_UNK>);                    /* extern */
s32 fn_8016293C(s32, Ptr32<u16>);                        /* extern */
M2C_UNK fn_8002A5B4(Ptr32<Ptr32<void>>);                       void fn_8002A688(Ptr32<Ptr32<void>>);                       /* extern */
s32 fn_8015FB34(Ptr32<Ptr32<void>>, Ptr32<u16>);                    /* extern */
M2C_UNK fn_8002C118();                              /* extern */
M2C_UNK fn_8002C17C();                              /* extern */
M2C_UNK fn_800382F4(Ptr32<void>);                        /* extern */
M2C_UNK fn_800383D8(Ptr32<void>);                        /* extern */
M2C_UNK fn_800385FC(Ptr32<void>);                        /* extern */
u32 fn_801FE45C();                                  /* extern */
M2C_UNK fn_8003AF68();                              void fn_8003B2EC();                              /* extern */
M2C_UNK fn_8003B330();                              /* extern */

extern M2C_UNK lbl_804ACBFC;
extern M2C_UNK lbl_804ACC04;
extern M2C_UNK lbl_804ACC0C;

s32 w3d_auto_80029688(s32 arg0, Ptr32<u16> arg1) {
    u16 temp_r0;

    temp_r0 = *arg1;
    if ((s32) temp_r0 == 0x40) {
        goto block_3;
    }
    if ((s32) temp_r0 == 0x42) {
        goto block_6;
    }
    goto block_7;
block_3:
    if (fn_8016293C(arg0, arg1) < 0) {
        goto block_5;
    }
    fn_8002988C(w3d::G(arg0));
    goto block_14;
block_5:
    return 0x80004005;
block_6:
    fn_8002A040(w3d::G(arg0));
    goto block_12;
block_7:
    if (fn_8015F65C(*arg1, &lbl_804ACBFC) == 0) {
        goto block_9;
    }
    fn_8002A0C0(w3d::G(arg0), arg1);
    goto block_14;
block_9:
    if (fn_8015F65C(*arg1, &lbl_804ACC04) == 0) {
        goto block_11;
    }
    fn_8002A12C(w3d::G(arg0), 1);
    goto block_14;
block_11:
    if (fn_8015F65C(*arg1, &lbl_804ACC0C) != 0) {
        goto block_13;
    }
block_12:
    return fn_8016293C(arg0, arg1);
block_13:
    fn_8002A12C(w3d::G(arg0), 0);
block_14:
    return 0;
}

extern M2C_UNK lbl_804ACC14;
extern M2C_UNK lbl_804ACC1C;

s32 w3d_auto_8002a4cc(Ptr32<Ptr32<void>> arg0, Ptr32<u16> arg1) {
    u16 temp_r31;

    temp_r31 = *arg1;
    if ((s32) temp_r31 == 0x40) {
        goto block_3;
    }
    if ((s32) temp_r31 == 0x42) {
        goto block_6;
    }
    goto block_7;
block_3:
    if (fn_8015FB34(arg0, arg1) < 0) {
        goto block_5;
    }
    fn_8002A5B4(arg0);
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_8002A688(arg0);
    goto block_11;
block_7:
    if (fn_8015F65C(temp_r31, &lbl_804ACC14) == 0) {
        goto block_9;
    }
    M2C_FIELD(*arg0, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x28)(arg0);
    goto block_11;
block_9:
    if (fn_8015F65C(temp_r31, &lbl_804ACC1C) == 0) {
        goto block_11;
    }
    M2C_FIELD(*arg0, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x2C)(arg0);
block_11:
    return fn_8015FB34(arg0, arg1);
}

s32 w3d_auto_8002bbd0(Ptr32<void> arg0) {
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0x58);
    if (temp_r0 == 1) {
        goto block_3;
    }
    if (temp_r0 == 2) {
        goto block_4;
    }
    goto block_5;
block_3:
    fn_8002C118();
    goto block_5;
block_4:
    fn_8002C17C();
block_5:
    return 0x14;
}

s32 w3d_auto_80037c78(Ptr32<void> arg0) {
    s32 temp_r0;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x58) == 0) {
        goto block_3;
    }
    if (fn_801FE45C() < (u32) M2C_FIELD(arg0, s32 *, 0x58)) {
        goto block_3;
    }
    fn_800382F4(arg0);
block_3:
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x5C);
    if (temp_r0 == 2) {
        goto block_9;
    }
    if (temp_r0 > 2) {
        goto block_7;
    }
    if (temp_r0 == 0) {
        goto block_10;
    }
    goto block_11;
block_7:
    if (temp_r0 != 3) {
        goto block_11;
    }
    fn_800383D8(arg0);
    goto block_11;
block_9:
    fn_800383D8(arg0);
    fn_800385FC(arg0);
    goto block_11;
block_10:
    fn_800385FC(arg0);
block_11:
    return 0;
}

s32 w3d_auto_8003aa90(Ptr32<void> arg0) {
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0x50);
    if (temp_r0 == 1) {
        goto block_7;
    }
    if (temp_r0 > 1) {
        goto block_4;
    }
    if (temp_r0 == 0) {
        goto block_6;
    }
    goto block_9;
block_4:
    if (temp_r0 == 2) {
        goto block_8;
    }
    goto block_9;
block_6:
    fn_8003AF68();
    goto block_9;
block_7:
    fn_8003B2EC();
    goto block_9;
block_8:
    fn_8003B330();
block_9:
    return 0x14;
}

}
