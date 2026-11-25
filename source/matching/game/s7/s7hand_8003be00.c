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
M2C_UNK fn_8003C3BC(void *, void *);                /* extern */
M2C_UNK fn_8003C938(void *, void *);                /* extern */
M2C_UNK fn_8003CDCC(void *);                        /* extern */
M2C_UNK fn_8003CE0C(void *);                        /* extern */
M2C_UNK fn_8003CF5C(void *, M2C_UNK);               /* extern */
s32 fn_8003CF8C(void *);                                  /* extern */
s32 fn_8003CFBC(void *);                            /* extern */
void *fn_800FC6DC(s32);                                /* extern */
void *fn_80165254();                                /* extern */
s32 fn_80178C48(void *);                               /* extern */
M2C_UNK fn_80181640(s32, s32, void *, f32, f32, f32, M2C_UNK); /* extern */
s32 fn_80181CCC(void *, s32);                               /* extern */
s32 fn_80343584(s32);                               /* extern */
extern f32 lbl_803743BC[];
extern f32 lbl_803743C0[];
extern s32 lbl_804AA928;
extern s32 lbl_804ABAB4;

s32 w3d_auto_8003be00(void *arg0, u32 arg1) {
    s32 temp_r30_2;
    void *temp_r30;
    void *temp_r3;
    s32 handle;

    if (arg1 <= (u32) (M2C_FIELD(arg0, s32 *, 0x54) + 0xDAC)) {
        goto block_7;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x58) != 0) {
        goto block_7;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x60) != 0) {
        goto block_7;
    }
    if (fn_8003CF8C(arg0) != 0) {
        goto block_7;
    }
    if (fn_8003CFBC(arg0) != 0) {
        goto block_7;
    }
    if ((s32) M2C_FIELD(fn_80165254(), s32 *, 0x38) != 0) {
        goto block_7;
    }
    fn_8003CE0C(arg0);
block_7:
    if ((handle = fn_80178C48(M2C_FIELD(arg0, s32 *, 0x28))) == -1) {
        goto block_11;
    }
    temp_r3 = fn_800FC6DC(handle);
    if ((s32) M2C_FIELD(temp_r3, s32 *, 0x80) == 0xA) {
        goto block_10;
    }
    fn_8003CDCC(arg0);
block_10:
    temp_r30 = temp_r3 + 0x50;
    fn_8003C3BC(arg0, temp_r30);
    fn_8003C938(arg0, temp_r30);
    goto block_12;
block_11:
    fn_8003CDCC(arg0);
block_12:
    if ((s32) M2C_FIELD(arg0, s32 *, 0x58) == 0) {
        goto block_16;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x60) != 0) {
        goto block_16;
    }
    temp_r30_2 = fn_80343584(M2C_FIELD(arg0, s32 *, 0x1C));
    if (fn_80181CCC(temp_r30_2, M2C_FIELD(arg0, s32 *, 0x20)) == 0) {
        goto block_16;
    }
    fn_80181640(temp_r30_2, lbl_804AA928, arg0 + 0x20, (*lbl_803743BC), (*lbl_803743C0), (*lbl_803743C0), 0);
block_16:
    if ((s32) M2C_FIELD(fn_80165254(), s32 *, 0x38) == 0) {
        goto block_19;
    }
    if ((s32) lbl_804ABAB4 != 0) {
        goto block_19;
    }
    fn_8003CF5C(arg0, 0);
    goto block_20;
block_19:
    fn_8003CF5C(arg0, 1);
block_20:
    return 0;
}
