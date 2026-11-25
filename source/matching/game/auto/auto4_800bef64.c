/* Decompiled automatically by m2c (ppc-gcc-c) via tools/m2c_batch.py and verified identical
 * to the original after linking. Types and names are m2c placeholders pending review. */
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


M2C_UNK fn_800BF018(void *);                           /* extern */
M2C_UNK fn_800BF2D4(void *);                           /* extern */
M2C_UNK fn_800BF320(void *);                           /* extern */
s32 fn_8015F620(M2C_UNK *, u16);                    /* extern */
s32 fn_8015FB34(void *, u16 *);                        /* extern */
M2C_UNK fn_800C6640(void *);                        /* extern */
M2C_UNK fn_800C6698(void *, M2C_UNK);               /* extern */
M2C_UNK fn_800C67F0(void *);                        /* extern */
M2C_UNK fn_800C6A20(void *);                        /* extern */
M2C_UNK fn_800C6B50(void *);                        /* extern */
s32 fn_8010A8FC(u16 *);                             /* extern */
s32 fn_8015F65C(u16, M2C_UNK *);                    /* extern */
s32 fn_8016293C(void *, u16 *);                     /* extern */
M2C_UNK fn_8020BD38(s32, s32);                      void fn_8020C5C0(s32 *);                         void fn_8020C5C4(s32 *);                         /* extern */
M2C_UNK fn_80341588(s32 *);                         /* extern */
u16 *fn_80341884(s32 *);                            /* extern */
M2C_UNK fn_800F18BC(void *);                           void fn_800F1A6C(s32);                           /* extern */
M2C_UNK fn_800F1C60(void *);                           /* extern */

extern M2C_UNK lbl_804AE60C;

s32 w3d_auto_800bef64(s32 arg0, u16 *arg1) {
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
    fn_800BF018(arg0);
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_800BF2D4(arg0);
    goto block_9;
block_7:
    if (fn_8015F620(&lbl_804AE60C, *arg1) == 0) {
        goto block_9;
    }
    fn_800BF320(arg0);
block_9:
    return fn_8015FB34(arg0, arg1);
}

extern M2C_UNK lbl_804AE794;
extern M2C_UNK lbl_804AE79C;
extern M2C_UNK lbl_804AE7A4;
extern M2C_UNK lbl_804AE7AC;
extern M2C_UNK lbl_804AE7B4;
extern M2C_UNK lbl_804AE7D4;
extern M2C_UNK lbl_804AE7EC;

s32 w3d_auto_800c647c(void *arg0, u16 *arg1) {
    s32 sp8;
    u16 *temp_r3;
    u16 temp_r30;

    temp_r30 = *arg1;
    if ((s32) temp_r30 == 0x40) {
        goto block_3;
    }
    if ((s32) temp_r30 == 0x42) {
        goto block_6;
    }
    goto block_7;
block_3:
    if (fn_8016293C(arg0, arg1) < 0) {
        goto block_5;
    }
    fn_800C6A20(arg0);
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_800C6B50(arg0);
    goto block_21;
block_7:
    if (fn_8015F65C(temp_r30, &lbl_804AE7D4) == 0) {
        goto block_9;
    }
    fn_8020BD38(arg0 + 0x3C, fn_8010A8FC(arg1));
    fn_8020C5C0(&sp8);
    sp8 = M2C_FIELD(arg0, s32 *, 0x3C);
    temp_r3 = fn_80341884(&sp8);
    *temp_r3 += 1;
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
    goto block_21;
block_9:
    if (fn_8015F65C(temp_r30, &lbl_804AE7B4) == 0) {
        goto block_11;
    }
    fn_800C67F0(arg0);
    goto block_21;
block_11:
    if (fn_8015F65C(temp_r30, &lbl_804AE7EC) == 0) {
        goto block_13;
    }
    fn_800C6640(arg0);
    goto block_21;
block_13:
    if (fn_8015F65C(temp_r30, &lbl_804AE7A4) == 0) {
        goto block_15;
    }
    fn_800C6698(arg0, 1);
    goto block_21;
block_15:
    if (fn_8015F65C(temp_r30, &lbl_804AE79C) == 0) {
        goto block_17;
    }
    fn_800C6698(arg0, 0x1B);
    goto block_21;
block_17:
    if (fn_8015F65C(temp_r30, &lbl_804AE794) == 0) {
        goto block_19;
    }
    fn_800C6698(arg0, 0);
    goto block_21;
block_19:
    if (fn_8015F65C(temp_r30, &lbl_804AE7AC) == 0) {
        goto block_21;
    }
    fn_800C6698(arg0, 2);
block_21:
    return fn_8016293C(arg0, arg1);
}

extern M2C_UNK lbl_804AF098;

s32 w3d_auto_800f1814(s32 arg0, u16 *arg1) {
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
    fn_800F18BC(arg0);
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_800F1A6C(arg0);
    goto block_9;
block_7:
    if (fn_8015F65C(*arg1, &lbl_804AF098) == 0) {
        goto block_9;
    }
    fn_800F1C60(arg0);
block_9:
    return fn_8015FB34(arg0, arg1);
}
