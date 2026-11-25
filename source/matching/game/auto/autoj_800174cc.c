/* Decompiled automatically by m2c; statement order, callee return width or a
 * guarded call argument adjusted by tools/m2c_reorder.py and verified identical
 * to the original after linking. Types and names are m2c placeholders pending
 * review. */
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

M2C_UNK fn_80008C44(M2C_UNK);                              /* extern */
M2C_UNK fn_80009984(void *, M2C_UNK);                  /* extern */
M2C_UNK fn_80181640(M2C_UNK, s32, void *, M2C_UNK, f32, f32, f32); /* extern */
M2C_UNK fn_80343584(s32);                           /* extern */
extern f32 lbl_8037446C[];
extern f32 lbl_80374470[];
extern f32 lbl_80374474[];
extern s32 lbl_804AA92C;
extern f32 lbl_80374478[];
extern f32 lbl_8037447C[];
extern f32 lbl_80374480[];
extern s32 lbl_804AA930;
extern f32 lbl_80380908[];
extern f32 lbl_8038090C[];
extern f32 lbl_80380910[];
extern s32 lbl_804AAC1C;
extern f32 lbl_80380914[];
extern f32 lbl_80380918[];
extern f32 lbl_8038091C[];
extern f32 lbl_80380920[];
extern f32 lbl_80380924[];
extern f32 lbl_80380928[];
extern s32 lbl_804AAC20;

void w3d_auto_800174cc(s32 arg0) {
    fn_80008C44(fn_80009984(arg0 + 0x20, 1));
    return;
}

void w3d_auto_8003ce84(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x60) == 0) {
        goto block_2;
    }
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    fn_80181640(fn_80343584(M2C_FIELD(arg0, s32 *, 0x1C)), lbl_804AA92C, arg0 + 0x20, 0, (*lbl_8037446C), (*lbl_80374470), (*lbl_80374474));
block_2:
    return;
}

void w3d_auto_8003cef0(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x60) != 0) {
        goto block_2;
    }
    M2C_FIELD(arg0, s32 *, 0x60) = 1;
    fn_80181640(fn_80343584(M2C_FIELD(arg0, s32 *, 0x1C)), lbl_804AA930, arg0 + 0x20, 0, (*lbl_80374478), (*lbl_8037447C), (*lbl_80374480));
block_2:
    return;
}

void w3d_auto_800a1380(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x54) == 0) {
        goto block_2;
    }
    fn_80181640(fn_80343584(M2C_FIELD(arg0, s32 *, 0x1C)), lbl_804AAC1C, arg0 + 0x20, 0, (*lbl_80380908), (*lbl_8038090C), (*lbl_80380910));
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
block_2:
    return;
}

void w3d_auto_800a13ec(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x5C) == 0) {
        goto block_2;
    }
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    fn_80181640(fn_80343584(M2C_FIELD(arg0, s32 *, 0x1C)), lbl_804AAC1C, arg0 + 0x20, 0, (*lbl_80380914), (*lbl_80380918), (*lbl_8038091C));
block_2:
    return;
}

void w3d_auto_800a1458(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x5C) != 0) {
        goto block_2;
    }
    M2C_FIELD(arg0, s32 *, 0x5C) = 1;
    fn_80181640(fn_80343584(M2C_FIELD(arg0, s32 *, 0x1C)), lbl_804AAC20, arg0 + 0x20, 0, (*lbl_80380920), (*lbl_80380924), (*lbl_80380928));
block_2:
    return;
}
