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


M2C_UNK fn_8003E030(void *);                        void fn_8003E1F4(void *);                        /* extern */
s32 fn_8003EF88(void *);                            /* extern */
s32 fn_8015F65C(u16, M2C_UNK *);                    /* extern */
s32 fn_8015FB34(void *, u16 *);                     /* extern */
M2C_UNK fn_8003E3A4(void *);                        /* extern */
M2C_UNK fn_8003E5F0(void *);                        /* extern */
M2C_UNK fn_8003EFD8(void *);                        /* extern */
M2C_UNK fn_800438D4(void *, s32);                        /* extern */
M2C_UNK fn_80043B74(void *, s32);                        /* extern */
M2C_UNK fn_80043E38(void *, s32);                        /* extern */
M2C_UNK fn_80043F00(void *, s32);                        /* extern */
M2C_UNK fn_800441C0(void *);                        /* extern */
M2C_UNK fn_80049D48(void *);                        /* extern */
M2C_UNK fn_8004A38C(void *);                        /* extern */
s32 fn_8004B908(void *);                            /* extern */
M2C_UNK fn_8004CA00(void *, u16 *);                 /* extern */
M2C_UNK fn_8004CE38(void *);                        /* extern */
M2C_UNK fn_8004D044(void *, u16 *);                 /* extern */
M2C_UNK fn_8004D35C(void *);                        /* extern */
M2C_UNK fn_8004D428(void *);                        /* extern */
s32 fn_800A830C(u16 *);                             /* extern */

extern M2C_UNK lbl_804AD1B4;

s32 w3d_auto_8003df40(void *arg0, u16 *arg1) {
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
    fn_8003E030(arg0);
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_8003E1F4(arg0);
    goto block_10;
block_7:
    if (fn_8015F65C(*arg1, &lbl_804AD1B4) == 0) {
        goto block_10;
    }
    if (fn_8003EF88(arg0) == 0) {
        goto block_10;
    }
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
block_10:
    return fn_8015FB34(arg0, arg1);
}

void w3d_auto_8003e314(void *arg0) {
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0x54);
    if (temp_r0 == 0) {
        goto block_3;
    }
    if (temp_r0 == 1) {
        goto block_4;
    }
    goto block_5;
block_3:
    fn_8003E3A4(arg0);
    goto block_5;
block_4:
    fn_8003E5F0(arg0);
block_5:
    fn_8003EFD8(arg0);
    return;
}

s32 w3d_auto_800433e0(void *arg0, s32 arg1) {
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0x40);
    if (temp_r0 == 2) {
        goto block_9;
    }
    if (temp_r0 > 2) {
        goto block_5;
    }
    if (temp_r0 == 0) {
        goto block_7;
    }
    if (temp_r0 == 1) {
        goto block_8;
    }
    goto block_11;
block_5:
    if (temp_r0 == 3) {
        goto block_10;
    }
    goto block_11;
block_7:
    fn_800438D4(arg0, arg1);
    goto block_11;
block_8:
    fn_80043B74(arg0, arg1);
    goto block_11;
block_9:
    fn_80043E38(arg0, arg1);
    goto block_11;
block_10:
    fn_80043F00(arg0, arg1);
block_11:
    fn_800441C0(arg0);
    return 0;
}

extern M2C_UNK lbl_804AD370;
extern M2C_UNK lbl_804AD388;
extern M2C_UNK lbl_804AD390;
extern M2C_UNK lbl_804AD3A8;
extern M2C_UNK lbl_804AD3C0;
extern M2C_UNK lbl_804AD3D0;
extern M2C_UNK lbl_804AD3D8;
extern M2C_UNK lbl_804AD3E0;
extern M2C_UNK lbl_804AD3E8;

s32 w3d_auto_800499f0(void *arg0, u16 *arg1) {
    s32 temp_r0;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r9;
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
    if (fn_8015FB34(arg0, arg1) < 0) {
        goto block_5;
    }
    fn_80049D48(arg0);
    goto block_36;
block_5:
    return 0x80004005;
block_6:
    fn_8004A38C(arg0);
    goto block_34;
block_7:
    if ((s32) M2C_FIELD(arg0, s32 *, 0x64) == 0) {
        goto block_12;
    }
    if (fn_8015F65C(temp_r30, &lbl_804AD388) == 0) {
        goto block_12;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x6C) == 0) {
        goto block_12;
    }
    if (fn_8004B908(arg0) == 0) {
        goto block_12;
    }
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
    goto block_36;
block_12:
    if (fn_8015F65C(temp_r30, &lbl_804AD390) == 0) {
        goto block_15;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x60) != 0) {
        goto block_15;
    }
    fn_8004CA00(arg0, arg1);
    goto block_36;
block_15:
    if (fn_8015F65C(temp_r30, &lbl_804AD3A8) == 0) {
        goto block_19;
    }
    temp_r9 = M2C_FIELD(arg0, s32 *, 0x4C);
    M2C_FIELD(arg0, s32 *, 0x90) = 0;
    if (temp_r9 == -1) {
        goto block_36;
    }
    temp_r0 = temp_r9 - 1;
    M2C_FIELD(arg0, s32 *, 0x4C) = temp_r0;
    if (temp_r0 != 0) {
        goto block_36;
    }
    fn_8004CE38(arg0);
    goto block_36;
block_19:
    if (fn_8015F65C(temp_r30, &lbl_804AD3C0) == 0) {
        goto block_21;
    }
    fn_8004D044(arg0, arg1);
    goto block_36;
block_21:
    temp_r3 = fn_8015F65C(temp_r30, &lbl_804AD3D8);
    if (temp_r3 == 0) {
        goto block_24;
    }
    if (fn_800A830C(arg1) != (s32) M2C_FIELD(arg0, s32 *, 0x20)) {
        goto block_36;
    }
    M2C_FIELD(arg0, s32 *, 0xA4) = 1;
    goto block_36;
block_24:
    temp_r3_2 = fn_8015F65C(temp_r30, &lbl_804AD3E0);
    if (temp_r3_2 == 0) {
        goto block_27;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0xFC) == 0) {
        goto block_36;
    }
    M2C_FIELD(arg0, s32 *, 0x70) = temp_r3;
    goto block_36;
block_27:
    if (fn_8015F65C(temp_r30, &lbl_804AD3D0) == 0) {
        goto block_30;
    }
    if (fn_800A830C(arg1) != (s32) M2C_FIELD(arg0, s32 *, 0x20)) {
        goto block_36;
    }
    M2C_FIELD(arg0, s32 *, 0xA4) = temp_r3_2;
    goto block_36;
block_30:
    if (fn_8015F65C(temp_r30, &lbl_804AD370) == 0) {
        goto block_33;
    }
    if (fn_800A830C(arg1) != (s32) M2C_FIELD(arg0, s32 *, 0x20)) {
        goto block_36;
    }
    fn_8004D35C(arg0);
    goto block_36;
block_33:
    if (fn_8015F65C(temp_r30, &lbl_804AD3E8) != 0) {
        goto block_35;
    }
block_34:
    return fn_8015FB34(arg0, arg1);
block_35:
    fn_8004D428(arg0);
block_36:
    return 0;
}
