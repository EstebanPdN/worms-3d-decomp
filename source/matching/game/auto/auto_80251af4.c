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




void w3d_auto_80251af4(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0xB0) = (s32) *arg1;
}

s8 w3d_auto_8025a874(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x20);
}

s8 w3d_auto_8025a888(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x2B);
}

s8 w3d_auto_8025a89c(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x2A);
}

s8 w3d_auto_8025a8b0(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x29);
}

s8 w3d_auto_8025a8c4(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x28);
}

s8 w3d_auto_8025a8d8(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x27);
}

s8 w3d_auto_8025a8ec(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x34);
}

s8 w3d_auto_8025a900(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x25);
}

s8 w3d_auto_8025a914(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x24);
}

s8 w3d_auto_8025a928(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x23);
}

s8 w3d_auto_8025a93c(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x22);
}

s8 w3d_auto_8025a950(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x21);
}

s8 w3d_auto_8025a964(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x2C);
}

s8 w3d_auto_8025a978(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x1F);
}

s8 w3d_auto_8025a98c(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x1E);
}

s8 w3d_auto_8025a9a0(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x1D);
}

s8 w3d_auto_8025a9b4(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x1C);
}

s8 w3d_auto_8025a9c8(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x1B);
}

s8 w3d_auto_8025a9dc(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x1A);
}

s8 w3d_auto_8025a9f0(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x41);
}

s8 w3d_auto_8025aa04(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x18);
}

s8 w3d_auto_8025aa18(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x17);
}

s8 w3d_auto_8025aa2c(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x16);
}

s8 w3d_auto_8025aa40(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x15);
}

s8 w3d_auto_8025aa54(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x14);
}

s8 w3d_auto_8025aa68(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x2D);
}

s8 w3d_auto_8025aa7c(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x46);
}

s8 w3d_auto_8025aa90(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x45);
}

s8 w3d_auto_8025aaa4(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x44);
}

s8 w3d_auto_8025aab8(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x43);
}

s8 w3d_auto_8025aacc(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x42);
}

s8 w3d_auto_8025aae0(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x19);
}

s8 w3d_auto_8025aaf4(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x40);
}

s8 w3d_auto_8025ab08(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x3F);
}

s8 w3d_auto_8025ab1c(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x3E);
}

s8 w3d_auto_8025ab30(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x3D);
}

s8 w3d_auto_8025ab44(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x3C);
}

s8 w3d_auto_8025ab58(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x3B);
}

s8 w3d_auto_8025ab6c(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x2E);
}
