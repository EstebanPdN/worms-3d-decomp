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

void fn_802B0990(void *, s32);                   /* extern */
M2C_UNK fn_802B1258(void *);                           /* extern */
M2C_UNK fn_802B4D58(void *);                        /* extern */

void w3d_auto_802b4770(void *arg0, s32 arg1) {
    s32 temp_r9_2;
    void *temp_r9;

    if ((s32) M2C_FIELD(arg0, s32 *, 0xB0) == arg1) {
        goto block_8;
    }
    if (arg1 == 0) {
        goto block_7;
    }
    temp_r9 = M2C_FIELD(arg0, void **, 0x28);
    if ((s32) M2C_FIELD(M2C_FIELD(temp_r9, void **, 0x84), u16 *, -4) == 0) {
        goto block_6;
    }
    temp_r9_2 = (M2C_FIELD(temp_r9, u8 *, 0xB) ^ 4) & 4;
    if (temp_r9_2 == 0) {
        goto block_6;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x8C) == 0) {
        goto block_6;
    }
    fn_802B1258(M2C_FIELD(temp_r9, void **, 0x84));
block_6:
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x100), s32 *, 0x10) = 1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x104), s32 *, 0x10) = 1;
    goto block_8;
block_7:
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x100), s32 *, 0x10) = arg1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x104), s32 *, 0x10) = arg1;
block_8:
    fn_802B0990(arg0 + 0x1C, arg1);
    fn_802B4D58(arg0);
    return;
}
