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

s32 fn_8015F65C(u16, M2C_UNK *); /* extern */
M2C_UNK fn_80035714(void *, M2C_UNK *, f32); /* extern */
extern M2C_UNK lbl_80380630[];
extern f32 lbl_80380638[];
extern s32 lbl_804AA8C8;
extern M2C_UNK lbl_804AE0D0;
extern M2C_UNK lbl_804AE0D8;
M2C_UNK fn_8015F518(M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK lbl_8038063C[];
extern M2C_UNK lbl_80380650[];
extern M2C_UNK lbl_80380664[];
extern M2C_UNK lbl_80380680[];
extern M2C_UNK lbl_804AE0C0;
extern M2C_UNK lbl_804AE0C8;
s16 fn_8015F5A0(M2C_UNK *, M2C_UNK); /* extern */
void *fn_801613F0(void *, M2C_UNK); /* extern */
M2C_UNK fn_8016239C(void *); /* extern */
extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804AE120;
extern s32 lbl_804B1754;

void w3d_auto_8009e930(s32 arg0, u16 *arg1) {
    u16 temp_r31;

    temp_r31 = *arg1;
    if (fn_8015F65C(temp_r31, &lbl_804AE0D0) != 0) {
        goto block_2;
    }
    if (fn_8015F65C(temp_r31, &lbl_804AE0D8) == 0) {
        goto block_3;
    }
block_2:
    fn_80035714(lbl_804AA8C8, &(*lbl_80380630), (*lbl_80380638));
block_3:
    return;
}

void w3d_auto_8009e998(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804AE0C0, &(*lbl_8038063C));
    fn_8015F518(&lbl_804AE0C8, &(*lbl_80380650));
    fn_8015F518(&lbl_804AE0D0, &(*lbl_80380664));
    fn_8015F518(&lbl_804AE0D8, &(*lbl_80380680));
block_3:
    return;
}

void w3d_auto_8009f464(void) {
    void *temp_r30;

    temp_r30 = fn_801613F0(lbl_804B1754, 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AE120, 1);
    M2C_FIELD(temp_r30, M2C_UNK **, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    return;
}

void w3d_auto_800a2098(s32 arg0, s32 *arg1) {
    s32 var_r10;

    var_r10 = *arg1 / 1000;
    if ((s32) *arg1 == (s32) (var_r10 * 0x3E8)) {
        goto block_2;
    }
    var_r10 += 1;
block_2:
    *arg1 = var_r10;
    return;
}
