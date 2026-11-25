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
M2C_UNK fn_80073290(void *, void *);                /* extern */
void fn_8007BB54(void *, void *);                /* extern */
void **fn_8007D0F8(void *, void *, M2C_UNK);        /* extern */
void **fn_8007E10C(void *, void *);                 /* extern */
M2C_UNK fn_80087128(void *, void *, M2C_UNK);       /* extern */
void **fn_800923F8(void *, void *);                 /* extern */
M2C_UNK fn_8009278C(void *, void *);                           /* extern */

void s8_attach_object_800927b4(void *arg0, void *arg1) {
    void **temp_r30;
    void **temp_r30_2;
    void **temp_r30_3;
    void **temp_r3;
    void **temp_r3_2;
    void **temp_r3_3;

    fn_8009278C(arg0, arg1 + 0x14);
    fn_8007BB54(arg0, arg1);
    fn_80087128(arg0, arg1, 0);
    temp_r3 = fn_8007D0F8(arg0, arg1, 0);
    temp_r30 = M2C_FIELD(arg1, void ***, 0x5C);
    M2C_FIELD(arg1, void ***, 0x5C) = temp_r3;
    if (temp_r3 == NULL) {
        goto block_2;
    }
    M2C_FIELD(*temp_r3, M2C_UNK (**)(), 0xC)();
block_2:
    if (temp_r30 == NULL) {
        goto block_4;
    }
    M2C_FIELD(*temp_r30, M2C_UNK (**)(void **), 0x10)(temp_r30);
block_4:
    M2C_FIELD(arg1, u16 *, 0x66) = (u16) M2C_FIELD(arg0, u16 *, 0x9AE);
    temp_r3_2 = fn_800923F8(arg0, arg1);
    temp_r30_2 = M2C_FIELD(arg1, void ***, 0x54);
    M2C_FIELD(arg1, void ***, 0x54) = temp_r3_2;
    if (temp_r3_2 == NULL) {
        goto block_6;
    }
    M2C_FIELD(*temp_r3_2, M2C_UNK (**)(), 0xC)();
block_6:
    if (temp_r30_2 == NULL) {
        goto block_8;
    }
    M2C_FIELD(*temp_r30_2, M2C_UNK (**)(void **), 0x10)(temp_r30_2);
block_8:
    fn_80073290(arg0, arg1);
    temp_r3_3 = fn_8007E10C(arg0, arg1);
    temp_r30_3 = M2C_FIELD(arg1, void ***, 0x58);
    M2C_FIELD(arg1, void ***, 0x58) = temp_r3_3;
    if (temp_r3_3 == NULL) {
        goto block_10;
    }
    M2C_FIELD(*temp_r3_3, M2C_UNK (**)(), 0xC)();
block_10:
    if (temp_r30_3 == NULL) {
        goto block_12;
    }
    M2C_FIELD(*temp_r30_3, M2C_UNK (**)(void **), 0x10)(temp_r30_3);
block_12:
    M2C_FIELD(arg1, s8 *, 0x6B) = 0;
    return;
}
