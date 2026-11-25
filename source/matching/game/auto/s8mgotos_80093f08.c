/* s8 range recovery: ordinary C, compiled against the reference ProDG route. */
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

s32 fn_8002AA48(void *, u16 *);                     /* extern */
M2C_UNK fn_8002AD9C(void *);                        /* extern */
M2C_UNK fn_8002AE70(void *);                        /* extern */
M2C_UNK fn_80035714(void *, M2C_UNK *, f32);           /* extern */
M2C_UNK fn_80094E08(void *);                        /* extern */
M2C_UNK fn_800953E8(void *);                        /* extern */
M2C_UNK fn_80095648(void *);                        /* extern */
M2C_UNK fn_800A7E14(M2C_UNK, M2C_UNK *);            /* extern */
s16 fn_8015F5A0(M2C_UNK *, M2C_UNK);                /* extern */
s32 fn_8015F65C(u16, M2C_UNK *);                    /* extern */
void *fn_801613F0(void *, M2C_UNK);                    /* extern */
M2C_UNK fn_8016239C(void *);                        /* extern */
extern M2C_UNK lbl_8037EA14[];
extern M2C_UNK lbl_8037EA24[];
extern f32 lbl_8037EA30[];
extern M2C_UNK lbl_8040DB38[];
extern s32 lbl_804AA8C8;
extern M2C_UNK lbl_804ADE50;
extern M2C_UNK lbl_804ADE58;
extern M2C_UNK lbl_804ADE60;
extern M2C_UNK lbl_804ADE68;
extern M2C_UNK lbl_804ADE70;
extern M2C_UNK lbl_804ADE78;
extern M2C_UNK lbl_804ADE80;
extern M2C_UNK lbl_804ADE88;
extern M2C_UNK lbl_804ADE90;
extern M2C_UNK lbl_804ADE98;
extern M2C_UNK lbl_804ADEA0;
extern M2C_UNK lbl_804ADEA8;
extern M2C_UNK lbl_804ADEB0;
extern M2C_UNK lbl_804ADEB8;
extern M2C_UNK lbl_804ADEC0;
extern M2C_UNK lbl_804ADEC8;
extern M2C_UNK lbl_804ADED0;
extern M2C_UNK lbl_804ADED8;
extern M2C_UNK lbl_804ADEE0;
extern M2C_UNK lbl_804ADEE8;
extern M2C_UNK lbl_804ADEF0;
extern M2C_UNK lbl_804ADEF8;
extern M2C_UNK lbl_804ADF00;
extern M2C_UNK lbl_804ADF10;
extern M2C_UNK lbl_804ADF30;
extern M2C_UNK lbl_804ADF38;
extern M2C_UNK lbl_804ADF40;
extern s32 lbl_804B1754;

s32 s8_recovered_80093f08(void *arg0, u16 *arg1) {
    s32 temp_r9;
    u16 temp_r30;
    void *temp_r30_2;
    void *temp_r30_3;

    temp_r30 = *arg1;
    if ((s32) temp_r30 == 0x40) {
        goto block_3;
    }
    if ((s32) temp_r30 == 0x42) {
        goto block_6;
    }
    goto block_7;
block_3:
    if (fn_8002AA48(arg0, arg1) < 0) {
        goto block_5;
    }
    fn_80094E08(arg0);
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_800953E8(arg0);
    goto block_63;
block_7:
    if (fn_8015F65C(temp_r30, &lbl_804ADE50) == 0) {
        goto block_9;
    }
    fn_80095648(arg0);
    goto block_63;
block_9:
    if (fn_8015F65C(temp_r30, &lbl_804ADE78) == 0) {
        goto block_11;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) | 0x800);
    goto block_63;
block_11:
    if (fn_8015F65C(temp_r30, &lbl_804ADE80) == 0) {
        goto block_13;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) & 0xFFFFF7FF);
    goto block_63;
block_13:
    if (fn_8015F65C(temp_r30, &lbl_804ADE58) == 0) {
        goto block_15;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) | 0x20);
    goto block_63;
block_15:
    if (fn_8015F65C(temp_r30, &lbl_804ADE60) == 0) {
        goto block_17;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) & 0xFFFFFFDF);
    goto block_63;
block_17:
    if (fn_8015F65C(temp_r30, &lbl_804ADE68) == 0) {
        goto block_19;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) | 0x10);
    goto block_63;
block_19:
    if (fn_8015F65C(temp_r30, &lbl_804ADE70) == 0) {
        goto block_21;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) & 0xFFFFFFEF);
    goto block_63;
block_21:
    if (fn_8015F65C(temp_r30, &lbl_804ADE88) == 0) {
        goto block_23;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) | 1);
    goto block_63;
block_23:
    if (fn_8015F65C(temp_r30, &lbl_804ADE90) == 0) {
        goto block_25;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) & 0xFFFFFFFE);
    goto block_63;
block_25:
    if (fn_8015F65C(temp_r30, &lbl_804ADE98) == 0) {
        goto block_27;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) | 2);
    goto block_63;
block_27:
    if (fn_8015F65C(temp_r30, &lbl_804ADEA0) == 0) {
        goto block_29;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) & 0xFFFFFFFD);
    goto block_63;
block_29:
    if (fn_8015F65C(temp_r30, &lbl_804ADEA8) == 0) {
        goto block_31;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) | 4);
    goto block_63;
block_31:
    if (fn_8015F65C(temp_r30, &lbl_804ADEB0) == 0) {
        goto block_33;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) & 0xFFFFFFFB);
    goto block_63;
block_33:
    if (fn_8015F65C(temp_r30, &lbl_804ADEB8) == 0) {
        goto block_35;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) | 8);
    goto block_63;
block_35:
    if (fn_8015F65C(temp_r30, &lbl_804ADEC0) == 0) {
        goto block_37;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) & 0xFFFFFFF7);
    goto block_63;
block_37:
    if (fn_8015F65C(temp_r30, &lbl_804ADEC8) == 0) {
        goto block_39;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) | 0x40);
    goto block_63;
block_39:
    if (fn_8015F65C(temp_r30, &lbl_804ADED0) == 0) {
        goto block_41;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) & 0xFFFFFFBF);
    goto block_63;
block_41:
    if (fn_8015F65C(temp_r30, &lbl_804ADED8) == 0) {
        goto block_43;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) | 0x80);
    goto block_63;
block_43:
    if (fn_8015F65C(temp_r30, &lbl_804ADEE0) == 0) {
        goto block_45;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) & 0xFFFFFF7F);
    goto block_63;
block_45:
    if (fn_8015F65C(temp_r30, &lbl_804ADEE8) == 0) {
        goto block_47;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) | 0x200);
    goto block_63;
block_47:
    if (fn_8015F65C(temp_r30, &lbl_804ADEF0) == 0) {
        goto block_49;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) & 0xFFFFFDFF);
    goto block_63;
block_49:
    if (fn_8015F65C(temp_r30, &lbl_804ADEF8) == 0) {
        goto block_51;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) | 0x400);
    goto block_63;
block_51:
    if (fn_8015F65C(temp_r30, &lbl_804ADF00) == 0) {
        goto block_53;
    }
    M2C_FIELD(arg0, s32 *, 0x124) = (s32) (M2C_FIELD(arg0, s32 *, 0x124) & 0xFFFFFBFF);
    goto block_63;
block_53:
    if (fn_8015F65C(temp_r30, &lbl_804ADF30) == 0) {
        goto block_55;
    }
    fn_800A7E14(0, NULL);
    goto block_63;
block_55:
    if (fn_8015F65C(temp_r30, &lbl_804ADF38) == 0) {
        goto block_57;
    }
    fn_800A7E14(0, &(*lbl_8037EA14));
    fn_80035714(lbl_804AA8C8, &(*lbl_8037EA24), (*lbl_8037EA30));
    goto block_63;
block_57:
    if (fn_8015F65C(temp_r30, &lbl_804ADF40) == 0) {
        goto block_63;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x2E8) != 0) {
        goto block_60;
    }
    temp_r30_2 = fn_801613F0(lbl_804B1754, 8);
    M2C_FIELD(temp_r30_2, s16 *, 0) = fn_8015F5A0(&lbl_804ADF10, 1);
    M2C_FIELD(temp_r30_2, M2C_UNK **, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30_2);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), M2C_UNK (**)(void *), 0x3C)(arg0);
    goto block_63;
block_60:
    temp_r9 = M2C_FIELD(arg0, s32 *, 0x2E4);
    M2C_FIELD(arg0, s32 *, 0x2AC) = 6;
    M2C_FIELD(arg0, s32 *, 0x2E8) = temp_r9;
    if (temp_r9 == 0) {
        goto block_62;
    }
    temp_r30_3 = fn_801613F0(lbl_804B1754, 8);
    M2C_FIELD(temp_r30_3, s16 *, 0) = fn_8015F5A0(&lbl_804ADF10, 1);
    M2C_FIELD(temp_r30_3, M2C_UNK **, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30_3);
block_62:
    fn_8002AD9C(arg0);
    fn_8002AE70(arg0);
block_63:
    return fn_8002AA48(arg0, arg1);
}
