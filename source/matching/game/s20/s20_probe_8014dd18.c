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
s32 fn_800CFC98(void *);                            /* extern */
M2C_UNK fn_800CFE68(void *, void *, void *, void *); /* extern */
s16 fn_8015F5A0(M2C_UNK *, M2C_UNK);                /* extern */
void *fn_801613F0(s32, M2C_UNK);                    /* extern */
M2C_UNK fn_8016239C(void *);                        /* extern */
void *fn_80164FC8(s32 id);                                /* extern */
extern f32 lbl_803A1688[];
extern f32 lbl_803A168C[];
extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804AFBF8;
extern s32 lbl_804B1754;

s32 s9_probe_8014dd18(void *arg0) {
    s32 temp_r3;
    void *temp_r30;
    void *temp_r3_2;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x314) != -1) {
        goto block_2;
    }
    return 0;
block_2:
    temp_r3_2 = fn_80164FC8(M2C_FIELD(arg0, s32 *, 0x314));
    if (temp_r3_2 != NULL) {
        goto block_4;
    }
    M2C_FIELD(arg0, s32 *, 0x314) = -1;
    return 0;
block_4:
    temp_r3 = fn_800CFC98(temp_r3_2);
    if (temp_r3 == 0) {
        goto block_6;
    }
    fn_800CFE68(temp_r3_2, arg0 + 0x230, arg0 + 0x2A4, arg0 + 0x23C);
    goto block_11;
block_6:
    if ((s32) M2C_FIELD(arg0, s32 *, 0x2CC) != 0) {
        goto block_8;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x338) >= 0) {
        goto block_10;
    }
block_8:
    if ((s32) M2C_FIELD(temp_r3_2, s32 *, 0x78) == 0) {
        goto block_11;
    }
    temp_r30 = fn_801613F0(lbl_804B1754, 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AFBF8, 1);
    M2C_FIELD(temp_r30, M2C_UNK **, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    return 0;
block_10:
    M2C_FIELD(arg0, f32 *, 0x23C) = (f32) (M2C_FIELD(arg0, f32 *, 0x23C) + (M2C_FIELD(temp_r3_2, f32 *, 0x10C) * (*lbl_803A1688) * (*lbl_803A168C)));
block_11:
    return temp_r3;
}
