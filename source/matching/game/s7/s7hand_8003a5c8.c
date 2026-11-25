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
s32 fn_8003AF58(void *);                            /* extern */
s32 fn_8003AF60(void *);                            /* extern */
void *fn_80164FC8(s32);                             /* extern */
M2C_UNK fn_80181640(s32, M2C_UNK *, void *, f32, f32, f32, M2C_UNK); /* extern */
s32 fn_80181CCC(void *, s32);                                  /* extern */
s32 fn_80343584(void **);                           /* extern */
extern M2C_UNK lbl_80374234[];
extern M2C_UNK lbl_80374238[];
extern f32 lbl_80374240[];
extern f32 lbl_80374244[];
extern f32 lbl_80374248[];

s32 w3d_auto_8003a5c8(void *arg0) {
    s32 temp_r30_3;
    s32 temp_r3_2;
    void **temp_r29;
    void **temp_r29_2;
    void *temp_r30;
    void *temp_r30_2;
    void *temp_r3;

    temp_r3 = fn_80164FC8(M2C_FIELD(arg0, s32 *, 0x20));
    if (temp_r3 == NULL) {
        goto block_7;
    }
    temp_r29 = M2C_FIELD(arg0, void ***, 0x1C);
    temp_r30 = *temp_r29;
    M2C_FIELD(temp_r30, M2C_UNK (**)(void **, s32, M2C_UNK), 0x4C)(temp_r29, fn_8003AF58(temp_r3), 0);
    temp_r29_2 = M2C_FIELD(arg0, void ***, 0x1C);
    temp_r30_2 = *temp_r29_2;
    M2C_FIELD(temp_r30_2, M2C_UNK (**)(void **, s32, M2C_UNK), 0x50)(temp_r29_2, fn_8003AF60(temp_r3), 0);
    temp_r30_3 = fn_80343584(M2C_FIELD(arg0, void ***, 0x1C));
    if ((s32) M2C_FIELD(arg0, s32 *, 0x24) == -1) {
        goto block_3;
    }
    if (fn_80181CCC(temp_r30_3, M2C_FIELD(arg0, s32 *, 0x24)) == 0) {
        goto block_7;
    }
block_3:
    temp_r3_2 = M2C_FIELD(temp_r3, s32 *, 0x50);
    if (temp_r3_2 == 0) {
        goto block_6;
    }
    if (temp_r3_2 != 2) {
        goto block_7;
    }
    fn_80181640(temp_r30_3, &(*lbl_80374234), arg0 + 0x24, (*lbl_80374240), (*lbl_80374244), (*lbl_80374244), 0);
    goto block_7;
block_6:
    fn_80181640(temp_r30_3, &(*lbl_80374238), arg0 + 0x24, (*lbl_80374248), (*lbl_80374244), (*lbl_80374244), 0);
block_7:
    return 0;
}
