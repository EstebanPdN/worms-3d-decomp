/* Recovery worker s9: combinations of mechanically corrected m2c forms. */
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

void *fn_8034435C(s32);                             /* extern */

s32 s9_beam_8018a2c4(void *arg0, s32 arg1) {
    void **temp_r30;
    void **temp_r30_2;
    void **temp_r3_2;
    void **temp_r3_3;
    void *temp_r3;

    temp_r3 = fn_8034435C(arg1);
    M2C_FIELD(arg0, u8 *, 0x19) = (u8) M2C_FIELD(temp_r3, u8 *, 0x19);
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) (M2C_FIELD(arg0, s32 *, 0x18) | 0x8000);
    M2C_FIELD(arg0, u16 *, 0x3C) = (u16) M2C_FIELD(temp_r3, u16 *, 0x3C);
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) M2C_FIELD(temp_r3, s32 *, 0x40);
    temp_r30 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), void **, 0x2C), void ***, 0x20);
    if (temp_r30 == NULL) {
        goto block_2;
    }
    M2C_FIELD(M2C_FIELD(temp_r30, void **, 0), M2C_UNK (**)(void **), 0xC)(temp_r30);
block_2:
    temp_r3_2 = M2C_FIELD(arg0, void ***, 0x28);
    if (temp_r3_2 == NULL) {
        goto block_4;
    }
    M2C_FIELD(*temp_r3_2, M2C_UNK (**)(void *), 0x10)(temp_r3_2);
block_4:
    M2C_FIELD(arg0, void ***, 0x28) = temp_r30;
    temp_r30_2 = M2C_FIELD(temp_r30, void ***, 0x34);
    if (temp_r30_2 == NULL) {
        goto block_6;
    }
    M2C_FIELD(*temp_r30_2, M2C_UNK (**)(void **), 0xC)(temp_r30_2);
block_6:
    temp_r3_3 = M2C_FIELD(arg0, void ***, 0x24);
    if (temp_r3_3 == NULL) {
        goto block_8;
    }
    M2C_FIELD(*temp_r3_3, M2C_UNK (**)(void *), 0x10)(temp_r3_3);
block_8:
    M2C_FIELD(arg0, void ***, 0x24) = temp_r30_2;
    return 0;
}
