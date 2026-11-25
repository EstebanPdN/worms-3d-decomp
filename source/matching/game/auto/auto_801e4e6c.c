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


s32 fn_801E4FCC(void *);                            /* extern */
s32 fn_801E507C(void *);                            /* extern */
M2C_UNK fn_80322838(s32, M2C_UNK, M2C_UNK);         /* extern */
M2C_UNK fn_801E43C8(s32, s32);                      /* extern */
M2C_UNK fn_801E45F0(s32, s32);                      /* extern */
s32 fn_801E5FD4();                                  /* extern */
M2C_UNK fn_801E6BBC(void *);                        /* extern */

s32 w3d_auto_801e4e6c(void *arg0) {
    s32 temp_r9;

    temp_r9 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_r9 > 0) {
        M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_r9 + 1);
        return 1;
    }
    if ((fn_801E4FCC(arg0) != 0) && (fn_801E507C(arg0) == 0)) {
        M2C_FIELD(arg0, s32 *, 8) = 1;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C), M2C_UNK (**)(void *), 0xC)(arg0);
        return 1;
    }
    if ((fn_801E4FCC(arg0) != 0) && (fn_801E507C(arg0) != 0)) {
        M2C_FIELD(arg0, s32 *, 8) = 1;
        fn_80322838(M2C_FIELD(arg0, s32 *, 0x10), 7, 0);
        return 1;
    }
    return 0;
}

extern s32 lbl_804AB85C;

void w3d_auto_801e5dfc(void *arg0) {
    s32 temp_r30;

    if (fn_801E5FD4() == 0) {
        fn_801E6BBC(arg0);
        return;
    }
    temp_r30 = lbl_804AB85C;
    fn_801E45F0(temp_r30, M2C_FIELD(arg0, s32 *, 0x38));
    fn_801E43C8(temp_r30, M2C_FIELD(arg0, s32 *, 0x38));
    fn_801E6BBC(arg0);
    M2C_FIELD(arg0, s32 *, 0x38) = -1;
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) & 0xFFBFFFFF);
}
