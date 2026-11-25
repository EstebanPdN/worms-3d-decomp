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
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

/* Bitwise (reinterpret) cast */
#define M2C_BITWISE(type, expr) ((type)(expr))

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

s32 fn_8015F65C(u16, M2C_UNK *);                    /* extern */
s32 fn_8015FB34(void *, u16 *);                        /* extern */
s32 fn_80162BA8();                                  /* extern */
M2C_UNK fn_802691FC(void *);                           /* extern */
M2C_UNK fn_80269694(void *);                           /* extern */
M2C_UNK fn_8026B3F0(void *);                           /* extern */
M2C_UNK fn_8026BDF0(void *);                           /* extern */
M2C_UNK fn_8026C008(void *, M2C_UNK);                  /* extern */
M2C_UNK fn_8026C54C(void *);                           /* extern */
M2C_UNK fn_8026CC20(void *, s32);                      /* extern */
M2C_UNK fn_8026D8A0(void *);                           /* extern */
M2C_UNK fn_802AFF9C(void *, u16 *);                    /* extern */
s32 fn_802B264C(void *);                               /* extern */
extern s32 lbl_804ABB7C;
extern M2C_UNK lbl_804B0AC4;
extern M2C_UNK lbl_804B0ACC;

s32 w3d_auto_80268f18(s32 arg0, u16 *arg1) {
    s32 temp_r3;
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
    if (fn_8015FB34(arg0, arg1) < 0) {
        goto block_5;
    }
    fn_802691FC(arg0);
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_80269694(arg0);
    goto block_13;
block_7:
    temp_r3 = arg0 + 0x1C;
    if (fn_802B264C(temp_r3) == 0) {
        goto block_13;
    }
    if (fn_8015F65C(*arg1, &lbl_804B0AC4) == 0) {
        goto block_10;
    }
    fn_8026CC20(arg0 + 0x138, fn_80162BA8());
    fn_8026C008(arg0, 1);
    fn_8026BDF0(arg0);
    fn_8026C54C(arg0);
    fn_8026B3F0(arg0);
    goto block_12;
block_10:
    if (fn_8015F65C(*arg1, &lbl_804B0ACC) == 0) {
        goto block_12;
    }
    fn_8026D8A0(lbl_804ABB7C);
block_12:
    fn_802AFF9C(arg0 + 0x1C, arg1);
block_13:
    return fn_8015FB34(arg0, arg1);
}
