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
M2C_UNK fn_800FC2B0(M2C_UNK **, s32 *);             /* extern */
M2C_UNK fn_8026B3F0(void *);                        /* extern */
void fn_8026C008(void *, M2C_UNK);               /* extern */
M2C_UNK fn_8026C54C(void *);                        /* extern */
M2C_UNK fn_8026CAC0(void *, M2C_UNK);               /* extern */
s32 fn_802EF234(void *, M2C_UNK *);                    /* extern */
extern M2C_UNK lbl_803CB80C[];
extern M2C_UNK lbl_803CB990[];
extern M2C_UNK lbl_803CB9A0[];
extern M2C_UNK lbl_803CB9B0[];
extern M2C_UNK lbl_803CB9BC[];
extern M2C_UNK lbl_803CB9CC[];
extern M2C_UNK lbl_803CB9DC[];

s32 w3d_auto_80269e34(s32 arg0, void *arg1) {
    M2C_UNK *sp8;
    s32 spC;

    if ((s32) M2C_FIELD(arg1, s32 *, 0x1F0) != 0) {
        return 0;
    }
    fn_8026C54C(arg1);
    sp8 = &(*lbl_803CB990);
    fn_800FC2B0(&sp8, &spC);
    if (fn_802EF234(spC, &(*lbl_803CB9A0)) != 0) {
        goto block_3;
    }
    fn_8026CAC0(arg1 + 0x138, 0);
    goto block_13;
block_3:
    if (fn_802EF234(spC, &(*lbl_803CB9B0)) != 0) {
        goto block_5;
    }
    fn_8026CAC0(arg1 + 0x138, 1);
    goto block_13;
block_5:
    if (fn_802EF234(spC, &(*lbl_803CB80C)) != 0) {
        goto block_7;
    }
    fn_8026CAC0(arg1 + 0x138, 2);
    goto block_13;
block_7:
    if (fn_802EF234(spC, &(*lbl_803CB9BC)) != 0) {
        goto block_9;
    }
    fn_8026CAC0(arg1 + 0x138, 3);
    goto block_13;
block_9:
    if (fn_802EF234(spC, &(*lbl_803CB9CC)) != 0) {
        goto block_11;
    }
    fn_8026CAC0(arg1 + 0x138, 4);
    goto block_13;
block_11:
    if (fn_802EF234(spC, &(*lbl_803CB9DC)) != 0) {
        goto block_13;
    }
    fn_8026CAC0(arg1 + 0x138, 5);
block_13:
    fn_8026C008(arg1, 1);
    fn_8026B3F0(arg1);
block_14:
    return 0;
}
