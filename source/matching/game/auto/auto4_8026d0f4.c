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


s32 fn_8015F65C(u16, M2C_UNK *);                    /* extern */
s32 fn_8015FB34(void *, u16 *);                        /* extern */
M2C_UNK fn_8026D2D8(s32);                           /* extern */
M2C_UNK fn_8026D328(void *);                           /* extern */
M2C_UNK fn_8026DA58(void *);                           /* extern */
s32 fn_800A830C(u16 *);                             /* extern */
M2C_UNK fn_801298CC(void *);                           /* extern */
s32 fn_8016293C(void *, u16 *);                     /* extern */
M2C_UNK fn_80287760(void *);                        void fn_80287830(void *);                        /* extern */
s32 fn_802ACA28(void *);                               /* extern */
s32 fn_802ABFFC(void *);                               /* extern */

extern M2C_UNK lbl_804B0AD8;

s32 w3d_auto_8026d0f4(s32 arg0, u16 *arg1) {
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
    fn_8026D2D8(arg0);
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_8026D328(arg0);
    goto block_9;
block_7:
    if (fn_8015F65C(*arg1, &lbl_804B0AD8) == 0) {
        goto block_9;
    }
    fn_8026DA58(arg0);
block_9:
    return fn_8015FB34(arg0, arg1);
}

extern M2C_UNK lbl_804B0BCC;
extern M2C_UNK lbl_804B0BF4;
extern M2C_UNK lbl_804B0BFC;
extern M2C_UNK lbl_804B0C04;
extern s32 lbl_804B1788;

s32 w3d_auto_802874dc(void *arg0, u16 *arg1) {
    s32 temp_r3;
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
    fn_80287760(arg0);
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_80287830(arg0);
    goto block_16;
block_7:
    if (fn_8015F65C(*arg1, &lbl_804B0BFC) == 0) {
        goto block_9;
    }
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) (M2C_FIELD(arg0, s32 *, 0x38) | 0x40000000);
    goto block_16;
block_9:
    temp_r3 = fn_8015F65C(*arg1, &lbl_804B0C04);
    if (temp_r3 == 0) {
        goto block_11;
    }
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) (M2C_FIELD(arg0, s32 *, 0x38) & 0xBFFFFFFF);
    goto block_16;
block_11:
    if (fn_8015F65C(*arg1, &lbl_804B0BCC) == 0) {
        goto block_14;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x1C) != 1) {
        goto block_14;
    }
    fn_801298CC(lbl_804B1788);
    M2C_FIELD(arg0, s32 *, 0x1C) = temp_r3;
    goto block_16;
block_14:
    if (fn_8015F65C(*arg1, &lbl_804B0BF4) == 0) {
        goto block_16;
    }
    M2C_FIELD(arg0, s32 *, 0x34) = fn_800A830C(arg1);
block_16:
    return fn_8016293C(arg0, arg1);
}

void w3d_auto_802abedc(void *arg0) {
    s32 temp_r3;

    temp_r3 = fn_802ACA28(arg0 + 0xB0);
    M2C_FIELD(arg0, s32 *, 8) = temp_r3;
    if (temp_r3 == 0) {
        goto block_7;
    }
    if (temp_r3 > 0) {
        goto block_4;
    }
    if (temp_r3 == -1) {
        goto block_8;
    }
    return;
block_4:
    if (temp_r3 == 1) {
        goto block_9;
    }
    if (temp_r3 == 2) {
        goto block_9;
    }
    return;
block_7:
    M2C_FIELD(arg0, s32 *, 4) = 0xA1;
    return;
block_8:
    M2C_FIELD(arg0, s32 *, 4) = 0xA3;
    return;
block_9:
    M2C_FIELD(arg0, s32 *, 4) = temp_r3;
    return;
}

void w3d_auto_802abf58(void *arg0) {
    s32 temp_r3;

    temp_r3 = fn_802ABFFC(arg0 + 0x1A0);
    M2C_FIELD(arg0, s32 *, 8) = temp_r3;
    if (temp_r3 == 1) {
        goto block_10;
    }
    if (temp_r3 > 1) {
        goto block_5;
    }
    if (temp_r3 == -1) {
        goto block_9;
    }
    if (temp_r3 == 0) {
        goto block_8;
    }
    return;
block_5:
    if (temp_r3 == 2) {
        goto block_10;
    }
    if (temp_r3 != 3) {
        goto block_11;
    }
    goto block_10;
block_8:
    M2C_FIELD(arg0, s32 *, 4) = 0xA1;
    return;
block_9:
    M2C_FIELD(arg0, s32 *, 4) = 0xA4;
    return;
block_10:
    M2C_FIELD(arg0, s32 *, 4) = temp_r3;
block_11:
    return;
}
