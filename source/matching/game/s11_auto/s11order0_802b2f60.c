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

M2C_UNK fn_802AE5A0(void *, M2C_UNK);                       /* extern */

void w3d_auto_802b2f60(void *arg0) {
    void **temp_r30;
    void **temp_r3;
    void **temp_r3_2;
    void **temp_r3_3;
    void *temp_r29;

    if ((void **) M2C_FIELD(arg0, void ***, 0x1C) == NULL) {
        goto block_7;
    }
    goto loop_3;
block_2:
    temp_r30 = M2C_FIELD(arg0, void ***, 0x1C);
    temp_r29 = *temp_r30;
    M2C_FIELD(temp_r29, M2C_UNK (**)(void **, s32), 0x60)(temp_r30, M2C_FIELD(temp_r29, s32 (**)(void **, M2C_UNK), 0x74)(temp_r30, 0));
loop_3:
    temp_r3 = M2C_FIELD(arg0, void ***, 0x1C);
    temp_r3_2 = M2C_FIELD(*temp_r3, void **(**)(void **), 0x78)(temp_r3);
    if (temp_r3_2 != NULL) {
        goto block_2;
    }
    temp_r3_3 = M2C_FIELD(arg0, void ***, 0x1C);
    if (temp_r3_3 == NULL) {
        goto block_6;
    }
    M2C_FIELD(*temp_r3_3, M2C_UNK (**)(void *), 0x10)(temp_r3_3);
block_6:
    M2C_FIELD(arg0, void ***, 0x1C) = temp_r3_2;
block_7:
    if ((s32) M2C_FIELD(arg0, s32 *, 0x64) == 0) {
        goto block_9;
    }
    fn_802AE5A0(M2C_FIELD(arg0, s32 *, 0x64), 3);
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
block_9:
    return;
}
