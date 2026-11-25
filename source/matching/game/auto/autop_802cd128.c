/* Decompiled automatically by m2c, with arguments the original forwards unchanged
 * made explicit (tools/m2c_fixups.py); verified identical to the original
 * after linking. Types and names are m2c placeholders pending review. */
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

M2C_UNK fn_8020BF2C(void *, s32);                           /* extern */
M2C_UNK fn_80209920(M2C_UNK *, s32);                /* extern */
M2C_UNK fn_80343DF8(void *, M2C_UNK);                       /* extern */
s32 fn_80212FD4(M2C_UNK);                           /* extern */
s32 fn_803413D8(M2C_UNK);                           /* extern */
M2C_UNK fn_803536D0(void *, M2C_UNK, M2C_UNK);              /* extern */
M2C_UNK fn_8035EF1C(void *, M2C_UNK, M2C_UNK);              /* extern */

extern s32 lbl_804ABCE0;

void w3d_auto_802cd128(s32 arg0) {
    fn_8020BF2C(arg0, lbl_804ABCE0);
    return;
}

extern M2C_UNK lbl_804B0044;

void w3d_auto_8034714c(s32 arg0, s32 arg1) {
    fn_80343DF8(arg0, 0);
    if (!(arg1 & 1)) {
        goto block_2;
    }
    fn_80209920(&lbl_804B0044, arg0);
block_2:
    return;
}

void w3d_auto_80353880(void *arg0, s32 *arg1) {
    s32 *temp_r9;
    s32 temp_r30;
    s32 temp_r9_2;
    s32 var_r3;
    void *temp_r11;
    void *temp_r8;

    temp_r30 = *arg1;
    if ((u32) (M2C_FIELD(arg0, s32 *, 0x2C) - ((s32) (M2C_FIELD(arg0, void **, 0x1C) - M2C_FIELD(arg0, s32 *, 0x24)) >> 2)) > 1U) {
        goto block_2;
    }
    fn_803536D0(arg0, 1, 0);
block_2:
    var_r3 = fn_80212FD4(0x80);
    if (var_r3 != 0) {
        goto block_4;
    }
    var_r3 = fn_803413D8(0x80);
block_4:
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C), s32 *, 4) = var_r3;
    temp_r9 = M2C_FIELD(arg0, s32 **, 0x10);
    if (temp_r9 == NULL) {
        goto block_6;
    }
    *temp_r9 = temp_r30;
block_6:
    temp_r8 = M2C_FIELD(arg0, void **, 0x1C);
    temp_r11 = arg0 + 0x10;
    M2C_FIELD(temp_r11, void **, 0xC) = (void *) (temp_r8 + 4);
    temp_r9_2 = M2C_FIELD(temp_r8, s32 *, 4);
    M2C_FIELD(temp_r11, s32 *, 4) = temp_r9_2;
    M2C_FIELD(temp_r11, s32 *, 8) = (s32) (temp_r9_2 + 0x80);
    M2C_FIELD(arg0, s32 **, 0x10) = (s32 *) M2C_FIELD(arg0, s32 **, 0x14);
    return;
}

void w3d_auto_8035f16c(void *arg0, s32 *arg1) {
    s32 *temp_r9;
    s32 temp_r30;
    s32 temp_r9_2;
    s32 var_r3;
    void *temp_r11;
    void *temp_r8;

    temp_r30 = *arg1;
    if ((u32) (M2C_FIELD(arg0, s32 *, 0x2C) - ((s32) (M2C_FIELD(arg0, void **, 0x1C) - M2C_FIELD(arg0, s32 *, 0x24)) >> 2)) > 1U) {
        goto block_2;
    }
    fn_8035EF1C(arg0, 1, 0);
block_2:
    var_r3 = fn_80212FD4(0x80);
    if (var_r3 != 0) {
        goto block_4;
    }
    var_r3 = fn_803413D8(0x80);
block_4:
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C), s32 *, 4) = var_r3;
    temp_r9 = M2C_FIELD(arg0, s32 **, 0x10);
    if (temp_r9 == NULL) {
        goto block_6;
    }
    *temp_r9 = temp_r30;
block_6:
    temp_r8 = M2C_FIELD(arg0, void **, 0x1C);
    temp_r11 = arg0 + 0x10;
    M2C_FIELD(temp_r11, void **, 0xC) = (void *) (temp_r8 + 4);
    temp_r9_2 = M2C_FIELD(temp_r8, s32 *, 4);
    M2C_FIELD(temp_r11, s32 *, 4) = temp_r9_2;
    M2C_FIELD(temp_r11, s32 *, 8) = (s32) (temp_r9_2 + 0x80);
    M2C_FIELD(arg0, s32 **, 0x10) = (s32 *) M2C_FIELD(arg0, s32 **, 0x14);
    return;
}
