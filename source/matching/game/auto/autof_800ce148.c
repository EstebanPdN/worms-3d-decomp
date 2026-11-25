/* Decompiled automatically by m2c with mechanical corrections (tools/m2c_fixups.py:
 * far globals as unknown-size arrays, dropped leading parameters, forwarded
 * arguments); verified identical to the original after linking. Types and
 * names are m2c placeholders pending review. */
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

f32 fn_80069A28(u16 *);                             /* extern */
M2C_UNK fn_800CE48C(void *);                        /* extern */
M2C_UNK fn_800CEF44(void *);                        /* extern */
M2C_UNK fn_800CF010(void *);                        /* extern */
M2C_UNK fn_800CF028(void *);                        /* extern */
M2C_UNK fn_800D0D6C(void *);                        /* extern */
M2C_UNK fn_800D0FA0(void *);                        /* extern */
s32 fn_8015F65C(u16, M2C_UNK *);                    /* extern */
s32 fn_8015FB34(void *, u16 *);                     /* extern */
M2C_UNK fn_8015FD1C(void *);                        /* extern */
M2C_UNK fn_80035714(void *, M2C_UNK *, f32);           /* extern */
s32 fn_80178D1C(void *);                               /* extern */
M2C_UNK fn_801FE1F8();                              /* extern */
M2C_UNK fn_800DC604();                              /* extern */

extern f32 lbl_80387EF4[];
extern f32 lbl_80387EF8[];
extern f32 lbl_80387EFC[];
extern M2C_UNK lbl_804AE8B0;
extern M2C_UNK lbl_804AE8B8;
extern M2C_UNK lbl_804AE8C8;
extern M2C_UNK lbl_804AE8D8;
extern M2C_UNK lbl_804AE8E0;
extern M2C_UNK lbl_804AE8E8;
extern M2C_UNK lbl_804AE8F0;
extern M2C_UNK lbl_804AE8F8;
extern M2C_UNK lbl_804AE900;
extern M2C_UNK lbl_804AE908;
extern M2C_UNK lbl_804AE910;
extern M2C_UNK lbl_804AE918;
extern M2C_UNK lbl_804AE920;
extern M2C_UNK lbl_804AE928;
extern M2C_UNK lbl_804AE930;
extern M2C_UNK lbl_804AE980;
extern M2C_UNK lbl_804AE988;

s32 w3d_auto_800ce148(void *arg0, u16 *arg1) {
    s32 temp_r3;
    s32 temp_r3_2;
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
    fn_800CE48C(arg0);
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_800CEF44(arg0);
    goto block_43;
block_7:
    if (fn_8015F65C(temp_r31, &lbl_804AE8B0) == 0) {
        goto block_9;
    }
    fn_800CF028(arg0);
    return 0;
block_9:
    if (fn_8015F65C(temp_r31, &lbl_804AE8B8) == 0) {
        goto block_11;
    }
    fn_800CF010(arg0);
    goto block_17;
block_11:
    if (fn_8015F65C(temp_r31, &lbl_804AE8C8) == 0) {
        goto block_17;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x78) == 0) {
        goto block_16;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x2C) != 2) {
        goto block_15;
    }
    fn_800D0FA0(arg0);
block_15:
    fn_800D0D6C(arg0);
block_16:
    fn_8015FD1C(arg0);
    return 0;
block_17:
    if ((s32) M2C_FIELD(arg0, s32 *, 0x2C) != 2) {
        goto block_43;
    }
    temp_r3 = fn_8015F65C(temp_r31, &lbl_804AE8D8);
    if (temp_r3 == 0) {
        goto block_20;
    }
    M2C_FIELD(arg0, s32 *, 0x58) = 1;
    return 0;
block_20:
    if (fn_8015F65C(temp_r31, &lbl_804AE8E0) == 0) {
        goto block_22;
    }
    M2C_FIELD(arg0, s32 *, 0x58) = temp_r3;
    return 0;
block_22:
    temp_r3_2 = fn_8015F65C(temp_r31, &lbl_804AE8E8);
    if (temp_r3_2 == 0) {
        goto block_24;
    }
    M2C_FIELD(arg0, s32 *, 0x5C) = 1;
    return 0;
block_24:
    if (fn_8015F65C(temp_r31, &lbl_804AE8F0) == 0) {
        goto block_26;
    }
    M2C_FIELD(arg0, s32 *, 0x5C) = temp_r3_2;
    return 0;
block_26:
    if (fn_8015F65C(temp_r31, &lbl_804AE8F8) == 0) {
        goto block_28;
    }
    M2C_FIELD(arg0, f32 *, 0x64) = (f32) (*lbl_80387EF4);
    return 0;
block_28:
    if (fn_8015F65C(temp_r31, &lbl_804AE900) != 0) {
        goto block_32;
    }
    if (fn_8015F65C(temp_r31, &lbl_804AE908) == 0) {
        goto block_31;
    }
    M2C_FIELD(arg0, f32 *, 0x64) = (f32) (*lbl_80387EFC);
    return 0;
block_31:
    if (fn_8015F65C(temp_r31, &lbl_804AE910) == 0) {
        goto block_33;
    }
block_32:
    M2C_FIELD(arg0, f32 *, 0x64) = (f32) (*lbl_80387EF8);
    return 0;
block_33:
    if (fn_8015F65C(temp_r31, &lbl_804AE928) != 0) {
        goto block_36;
    }
    if (fn_8015F65C(temp_r31, &lbl_804AE930) != 0) {
        goto block_38;
    }
    if (fn_8015F65C(temp_r31, &lbl_804AE918) == 0) {
        goto block_37;
    }
block_36:
    M2C_FIELD(arg0, f32 *, 0x70) = (f32) (*lbl_80387EFC);
    return 0;
block_37:
    if (fn_8015F65C(temp_r31, &lbl_804AE920) == 0) {
        goto block_39;
    }
block_38:
    M2C_FIELD(arg0, f32 *, 0x70) = (f32) (*lbl_80387EF8);
    return 0;
block_39:
    if (fn_8015F65C(temp_r31, &lbl_804AE980) == 0) {
        goto block_41;
    }
    M2C_FIELD(arg0, f32 *, 0x128) = fn_80069A28(arg1);
    goto block_43;
block_41:
    if (fn_8015F65C(temp_r31, &lbl_804AE988) == 0) {
        goto block_43;
    }
    M2C_FIELD(arg0, f32 *, 0x130) = fn_80069A28(arg1);
block_43:
    return fn_8015FB34(arg0, arg1);
}

extern f32 lbl_80388140[];

void w3d_auto_800d00f0(void *arg0) {
    M2C_FIELD(arg0, f32 *, 0x10C) = (f32) ((*lbl_80388140) - M2C_FIELD(arg0, f32 *, 0x10C));
    return;
}

extern M2C_UNK lbl_80389144[];
extern f32 lbl_8038914C[];
extern s32 lbl_804AA8C8;
extern M2C_UNK lbl_804AEAC0;

void w3d_auto_800d72b4(void *arg0, u16 *arg1) {
    u16 temp_r31;

    temp_r31 = *arg1;
    if (fn_80178D1C(M2C_FIELD(arg0, s32 *, 0x58)) != 0) {
        goto block_3;
    }
    if (fn_8015F65C(temp_r31, &lbl_804AEAC0) == 0) {
        goto block_3;
    }
    fn_80035714(lbl_804AA8C8, &(*lbl_80389144), (*lbl_8038914C));
block_3:
    return;
}

extern M2C_UNK lbl_8040FD60[];

void w3d_auto_800d75bc(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x24) = &(*lbl_8040FD60);
    if (!(arg1 & 1)) {
        goto block_2;
    }
    fn_801FE1F8();
block_2:
    return;
}

extern f32 lbl_80389898[];

void w3d_auto_800dbd58(void *arg0, f32 farg0) {
    M2C_FIELD(arg0, f32 *, 0x8C) = (f32) (M2C_FIELD(arg0, f32 *, 0x8C) - (farg0 * (*lbl_80389898)));
    return;
}

extern M2C_UNK lbl_8040FE70[];

void w3d_auto_800dc674(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x70) = &(*lbl_8040FE70);
    if (!(arg1 & 1)) {
        goto block_2;
    }
    fn_800DC604();
block_2:
    return;
}
