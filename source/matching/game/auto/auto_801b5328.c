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


M2C_UNK fn_801E8D9C();                              /* extern */

s32 w3d_auto_801b5328(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801b6b40(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801b6ef4(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801b705c(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801b71c4(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801b7bbc(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801b7d24(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801b7e8c(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801b7ff4(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801b884c(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801b89b4(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801b8b1c(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801b8c84(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801b8dec(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801bd2a4(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801be070(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801bf0c4(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801bf3d8(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801c155c(void) {
    fn_801E8D9C();
    return 0;
}

void w3d_auto_801c8568(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x6C) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

s32 w3d_auto_801cb4b4(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801ce318(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_801ce8ec(void) {
    fn_801E8D9C();
    return 0;
}

void *w3d_auto_801d0858(void *arg0, s32 *arg1) {
    void *temp_r3;

    temp_r3 = M2C_FIELD(arg0, void **, 0x20);
    *arg1 = M2C_FIELD(temp_r3, s32 *, 0x18);
    return temp_r3 + 0x20;
}

void w3d_auto_801d0ea0(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x68) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d0ec0(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x64) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d0ee0(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x60) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d0f00(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x5C) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d0f20(void *arg0, f32 farg0) {
    void *temp_r3;

    M2C_FIELD(arg0, f32 *, 0x58) = farg0;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d0f40(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x20) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d0f60(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x1C) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d0f80(void *arg0, f32 farg0) {
    void *temp_r3;

    M2C_FIELD(arg0, f32 *, 0x18) = farg0;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d0fa0(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x18) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d0fc0(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x18) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d0fe0(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x18) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1000(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x2C) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1020(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x24) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1040(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x20) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1060(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x1C) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1080(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x18) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}
