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


M2C_UNK fn_80061A80(void *);                           /* extern */
M2C_UNK fn_80061CD4(void *);                           /* extern */
s32 fn_8015F65C(u16, M2C_UNK *);                    /* extern */
s32 fn_8015FB34(void *, u16 *);                        /* extern */
M2C_UNK fn_8015FD1C(void *);                           /* extern */
M2C_UNK fn_800681D4(s32);                           void fn_8006823C(s32);                           /* extern */
M2C_UNK fn_80068240(void *);                           /* extern */
M2C_UNK fn_80072FE4(s32);                           void fn_8007304C(s32);                           /* extern */
M2C_UNK fn_80073050(void *);                           /* extern */
M2C_UNK fn_80096C30(s32);                           void fn_80096DA8(s32);                           /* extern */
M2C_UNK fn_80096DB4(void *, u16 *);                    /* extern */
M2C_UNK fn_8009723C(void *, u16 *);                    /* extern */
s32 fn_8015F620(M2C_UNK *, u16);                    /* extern */
s32 fn_8016293C(s32, u16 *);                        /* extern */

extern M2C_UNK lbl_804AD4F4;

s32 w3d_auto_8006193c(s32 arg0, u16 *arg1) {
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
    fn_80061A80(arg0);
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_80061CD4(arg0);
    goto block_9;
block_7:
    if (fn_8015F65C(*arg1, &lbl_804AD4F4) == 0) {
        goto block_9;
    }
    fn_8015FD1C(arg0);
block_9:
    return fn_8015FB34(arg0, arg1);
}

extern M2C_UNK lbl_804AD5F8;
extern M2C_UNK lbl_804AD600;

s32 w3d_auto_80068100(s32 arg0, u16 *arg1) {
    u16 temp_r31;

    temp_r31 = *arg1;
    if ((s32) temp_r31 == 0x40) {
        goto block_3;
    }
    if ((s32) temp_r31 == 0x42) {
        goto block_6;
    }
    goto block_7;
block_3:
    if (fn_8015FB34(arg0, arg1) < 0) {
        goto block_5;
    }
    fn_800681D4(arg0);
    goto block_12;
block_5:
    return 0x80004005;
block_6:
    fn_8006823C(arg0);
    goto block_10;
block_7:
    if (fn_8015F65C(temp_r31, &lbl_804AD5F8) == 0) {
        goto block_9;
    }
    fn_8015FD1C(arg0);
    goto block_12;
block_9:
    if (fn_8015F65C(temp_r31, &lbl_804AD600) != 0) {
        goto block_11;
    }
block_10:
    return fn_8015FB34(arg0, arg1);
block_11:
    fn_80068240(arg0);
block_12:
    return 0;
}

extern M2C_UNK lbl_804AD964;
extern M2C_UNK lbl_804AD96C;

s32 w3d_auto_80072f10(s32 arg0, u16 *arg1) {
    u16 temp_r31;

    temp_r31 = *arg1;
    if ((s32) temp_r31 == 0x40) {
        goto block_3;
    }
    if ((s32) temp_r31 == 0x42) {
        goto block_6;
    }
    goto block_7;
block_3:
    if (fn_8015FB34(arg0, arg1) < 0) {
        goto block_5;
    }
    fn_80072FE4(arg0);
    goto block_12;
block_5:
    return 0x80004005;
block_6:
    fn_8007304C(arg0);
    goto block_10;
block_7:
    if (fn_8015F65C(temp_r31, &lbl_804AD96C) == 0) {
        goto block_9;
    }
    fn_80073050(arg0);
    goto block_12;
block_9:
    if (fn_8015F65C(temp_r31, &lbl_804AD964) != 0) {
        goto block_11;
    }
block_10:
    return fn_8015FB34(arg0, arg1);
block_11:
    fn_8015FD1C(arg0);
block_12:
    return 0;
}

extern M2C_UNK lbl_804ADF54;

s32 w3d_auto_80096b6c(s32 arg0, u16 *arg1) {
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
    if (fn_8016293C(arg0, arg1) < 0) {
        goto block_5;
    }
    fn_80096C30(arg0);
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_80096DA8(arg0);
    goto block_10;
block_7:
    if (fn_8015F620(&lbl_804ADF54, *arg1) == 0) {
        goto block_9;
    }
    fn_80096DB4(arg0, arg1);
    goto block_10;
block_9:
    fn_8009723C(arg0, arg1);
block_10:
    return fn_8016293C(arg0, arg1);
}
