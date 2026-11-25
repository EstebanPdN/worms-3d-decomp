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
void *fn_801EF048(void *, s32, M2C_UNK, M2C_UNK);        /* extern */

void *w3d_auto_80189574(void *arg0) {
    s32 temp_r30;
    s32 temp_r4;
    void *temp_r11;
    void *temp_r11_2;
    void *temp_r31;
    void *var_r3;

    temp_r31 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xA8), void **, 0x30);
    temp_r11_2 = M2C_FIELD(temp_r31, void **, 0x58);
    temp_r30 = M2C_FIELD(temp_r11_2, s32 *, 0x18);
    if ((s32) M2C_FIELD(temp_r11_2, u16 *, 4) != 1) {
        goto block_2;
    }
    var_r3 = temp_r11_2 + 0x20;
    M2C_FIELD(temp_r11_2, u16 *, 0x1C) = (u16) (M2C_FIELD(temp_r11_2, u16 *, 0x1C) + 1);
    goto block_3;
block_2:
    var_r3 = fn_801EF048(temp_r31 + 0x58, temp_r30, 4, 2);
block_3:
    if (temp_r30 != 0) {
        goto block_10;
    }
    temp_r4 = M2C_FIELD(M2C_FIELD(temp_r31, void **, 0x60), s32 *, 0x18);
    if (temp_r4 != 0) {
        goto block_6;
    }
    return NULL;
block_6:
    temp_r11 = M2C_FIELD(temp_r31, void **, 0x58);
    if ((s32) M2C_FIELD(temp_r11, u16 *, 4) != 1) {
        goto block_9;
    }
    if (temp_r4 != (s32) M2C_FIELD(temp_r11, s32 *, 0x18)) {
        goto block_9;
    }
    M2C_FIELD(temp_r11, u16 *, 0x1C) = (u16) (M2C_FIELD(temp_r11, u16 *, 0x1C) + 1);
    return temp_r11 + 0x20;
block_9:
    var_r3 = fn_801EF048(temp_r31 + 0x58, temp_r4, 4, 0);
block_10:
    return var_r3;
}
