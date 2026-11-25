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


M2C_UNK fn_8011AE58(void **);                       /* extern */
M2C_UNK fn_8011AF40(void **);                       /* extern */
s32 fn_8015F65C(u16, M2C_UNK *);                    /* extern */
s32 fn_8015FB34(void **, u16 *);                    /* extern */
void *fn_800FC6DC(s32);                             /* extern */
M2C_UNK fn_8021A768(void *, u16 *);                    /* extern */
M2C_UNK fn_8021A9DC(void *);                           void fn_8021B00C(s32);                           /* extern */
s32 fn_8021CC78(s32, u16 *);                        /* extern */
M2C_UNK fn_8021D928(void *);                           /* extern */
M2C_UNK fn_8021DD04(void *);                           /* extern */
s32 fn_8025D588(void *);                               /* extern */

extern M2C_UNK lbl_804AF3A8;

s32 w3d_auto_8011ab68(void **arg0, u16 *arg1) {
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
    fn_8011AE58(arg0);
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_8011AF40(arg0);
    goto block_9;
block_7:
    if (fn_8015F65C(*arg1, &lbl_804AF3A8) == 0) {
        goto block_9;
    }
    M2C_FIELD(*arg0, M2C_UNK (**)(void **), 0x38)(arg0);
block_9:
    return fn_8015FB34(arg0, arg1);
}

s32 w3d_auto_8013fecc(void *arg0) {
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0x1F0);
    if (temp_r0 == 0xD) {
        goto block_14;
    }
    if (temp_r0 > 0xD) {
        goto block_8;
    }
    if (temp_r0 == 6) {
        goto block_14;
    }
    if (temp_r0 > 6) {
        goto block_6;
    }
    if (temp_r0 == 3) {
        goto block_14;
    }
    goto block_15;
block_6:
    if (temp_r0 == 8) {
        goto block_14;
    }
    goto block_15;
block_8:
    if (temp_r0 == 0x21) {
        goto block_14;
    }
    if (temp_r0 > 0x21) {
        goto block_12;
    }
    if (temp_r0 == 0x1A) {
        goto block_14;
    }
    goto block_15;
block_12:
    if (temp_r0 == 0x24) {
        goto block_14;
    }
    if (temp_r0 != 0x26) {
        goto block_15;
    }
block_14:
    return 0;
block_15:
    return M2C_FIELD(fn_800FC6DC(M2C_FIELD(arg0, s32 *, 0x70)), s32 *, 0x100);
}

s32 w3d_auto_8015fb34(void *arg0, void *arg1) {
    u16 temp_r0;

    temp_r0 = M2C_FIELD(arg1, u16 *, 0);
    if ((s32) temp_r0 == 0x40) {
        goto block_3;
    }
    if ((s32) temp_r0 == 0x41) {
        goto block_4;
    }
    goto block_5;
block_3:
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) (M2C_FIELD(arg1, s32 *, 8) & 0x7FFFFFFF);
    goto block_5;
block_4:
    M2C_FIELD(arg1, s32 *, 0xC) = 1;
block_5:
    return 0;
}

s32 w3d_auto_8021b010(s32 arg0, u16 *arg1) {
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
    if (fn_8021CC78(arg0, arg1) < 0) {
        goto block_5;
    }
    fn_8021A9DC(arg0);
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_8021B00C(arg0);
    goto block_8;
block_7:
    fn_8021A768(arg0, arg1);
block_8:
    return fn_8021CC78(arg0, arg1);
}

void w3d_auto_8025bb98(void *arg0, void *arg1) {
    s32 temp_r3;
    s32 temp_r3_2;

    temp_r3 = fn_8025D588(M2C_FIELD(arg1, s32 *, 0x38));
    if (temp_r3 == 0) {
        goto block_6;
    }
    temp_r3_2 = M2C_FIELD(arg0, s32 *, 0x28);
    if (temp_r3_2 == 0) {
        goto block_4;
    }
    if (temp_r3_2 == 1) {
        goto block_5;
    }
    return;
block_4:
    fn_8021D928(temp_r3);
    return;
block_5:
    fn_8021DD04(temp_r3);
block_6:
    return;
}
