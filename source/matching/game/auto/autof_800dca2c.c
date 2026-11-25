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

f32 fn_80162BC8();                                  /* extern */

extern M2C_UNK lbl_80389A38[];
extern f32 lbl_80389A40[];
extern f32 lbl_80389A44[];
extern u32 lbl_804AEC54;

void w3d_auto_800dca2c(void *arg0, void *arg1, void *arg2) {
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    u32 temp_r10;
    u32 temp_r10_2;
    u32 temp_r10_3;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x6C) == 0) {
        goto block_2;
    }
    var_f1 = fn_80162BC8();
    goto block_3;
block_2:
    temp_r10 = (lbl_804AEC54 * 0x41C64E6D) + 0x3039;
    lbl_804AEC54 = temp_r10;
    var_f1 = (f32) (f64) temp_r10 * (*lbl_80389A40);
block_3:
    M2C_FIELD(arg0, f32 *, 0) = (f32) ((2.0f * (var_f1 - (*lbl_80389A44)) * M2C_FIELD(arg2, f32 *, 0)) + M2C_FIELD(arg1, f32 *, 0));
    if ((s32) M2C_FIELD(arg0, s32 *, 0x6C) == 0) {
        goto block_5;
    }
    var_f1_2 = fn_80162BC8();
    goto block_6;
block_5:
    temp_r10_2 = (lbl_804AEC54 * 0x41C64E6D) + 0x3039;
    lbl_804AEC54 = temp_r10_2;
    var_f1_2 = (f32) (f64) temp_r10_2 * (*lbl_80389A40);
block_6:
    M2C_FIELD(arg0, f32 *, 4) = (f32) ((2.0f * (var_f1_2 - (*lbl_80389A44)) * M2C_FIELD(arg2, f32 *, 4)) + M2C_FIELD(arg1, f32 *, 4));
    if ((s32) M2C_FIELD(arg0, s32 *, 0x6C) == 0) {
        goto block_8;
    }
    var_f1_3 = fn_80162BC8();
    goto block_9;
block_8:
    temp_r10_3 = (lbl_804AEC54 * 0x41C64E6D) + 0x3039;
    lbl_804AEC54 = temp_r10_3;
    var_f1_3 = (f32) (f64) temp_r10_3 * (*lbl_80389A40);
block_9:
    M2C_FIELD(arg0, f32 *, 8) = (f32) ((2.0f * (var_f1_3 - (*lbl_80389A44)) * M2C_FIELD(arg2, f32 *, 8)) + M2C_FIELD(arg1, f32 *, 8));
    return;
}
