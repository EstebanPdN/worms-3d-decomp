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




s8 w3d_auto_802498ec(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x111);
}

s8 w3d_auto_80249900(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0xE0);
}

s8 w3d_auto_80249914(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0xFC);
}

s8 w3d_auto_80249928(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x10E);
}

s8 w3d_auto_8024993c(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x10D);
}

s8 w3d_auto_80249950(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x10C);
}

s8 w3d_auto_80249964(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x10B);
}

s8 w3d_auto_80249978(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0xF1);
}

s8 w3d_auto_8024998c(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x109);
}

s8 w3d_auto_802499a0(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x108);
}

s8 w3d_auto_8024a328(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x1AA);
}

s8 w3d_auto_8024a33c(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x1EC);
}

void w3d_auto_8024af00(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) *arg1;
}

void w3d_auto_8024b164(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x60) = (s32) *arg1;
}

void w3d_auto_8024b178(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x54) = (s32) *arg1;
}

void w3d_auto_8024b18c(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x50) = (s32) *arg1;
}

void w3d_auto_8024b1a0(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x4C) = (s32) *arg1;
}

void w3d_auto_8024b1b4(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x48) = (s32) *arg1;
}

void w3d_auto_8024b1c8(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) *arg1;
}

void w3d_auto_8024b1dc(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) *arg1;
}

void w3d_auto_8024b1f0(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x3C) = (s32) *arg1;
}

void w3d_auto_8024b204(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) *arg1;
}

void w3d_auto_8024b218(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) *arg1;
}

void w3d_auto_8024b22c(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) *arg1;
}

void w3d_auto_8024b240(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) *arg1;
}

void w3d_auto_8024b254(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) *arg1;
}

void w3d_auto_8024b268(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) *arg1;
}

void w3d_auto_8024b27c(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x20) = (s32) *arg1;
}

void w3d_auto_8024b290(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) *arg1;
}

void w3d_auto_8024b2a4(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) *arg1;
}

void w3d_auto_8024b2b8(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) *arg1;
}

void w3d_auto_8024b2cc(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x5C) = (s32) *arg1;
}

void w3d_auto_8024b2e0(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0xA0) = (s32) *arg1;
}

void w3d_auto_8024b2f4(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x9C) = (s32) *arg1;
}

void w3d_auto_8024b308(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x98) = (s32) *arg1;
}

void w3d_auto_8024b31c(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x94) = (s32) *arg1;
}

void w3d_auto_8024b330(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x90) = (s32) *arg1;
}

void w3d_auto_8024b344(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x8C) = (s32) *arg1;
}

void w3d_auto_8024b518(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x78) = (s32) *arg1;
}

void w3d_auto_802511f0(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x1A8) = (s32) *arg1;
}
