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
s32 fn_8015FB34(void *, u16 *);                     /* extern */
M2C_UNK fn_802C1248(void *);                        /* extern */
M2C_UNK fn_802C1398(void *);                        /* extern */
M2C_UNK fn_802C1C90(void *);                        /* extern */
extern f32 lbl_803D84C0[];
extern f32 lbl_803D84C4[];
extern s32 lbl_804ABB5C;
extern M2C_UNK lbl_804B1068;

s32 w3d_auto_802c1030(void *arg0, u16 *arg1) {
    f32 temp_f13;
    f32 var_f0;
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
    fn_802C1248(arg0);
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_802C1398(arg0);
    goto block_14;
block_7:
    if ((s32) lbl_804ABB5C != (s32) M2C_FIELD(arg0, s32 *, 0x48)) {
        goto block_14;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x4C) == 1) {
        goto block_14;
    }
    if (fn_8015F65C(*arg1, &lbl_804B1068) == 0) {
        goto block_14;
    }
    fn_802C1C90(arg0);
    temp_f13 = M2C_FIELD(arg0, f32 *, 0x28);
    if (temp_f13 == (*lbl_803D84C0)) {
        goto block_12;
    }
    M2C_FIELD(arg0, f32 *, 0x28) = -temp_f13;
    goto block_13;
block_12:
    M2C_FIELD(arg0, f32 *, 0x28) = (*lbl_803D84C4);
block_13:
    M2C_FIELD(arg0, s32 *, 0x4C) = 1;
block_14:
    return fn_8015FB34(arg0, arg1);
}
