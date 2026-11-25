/* Range-isolated m2c recovery by worker s11. Types and names are provisional. */
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

M2C_UNK fn_801EA0EC();                              /* extern */
M2C_UNK fn_8025C2D8(void *);                        /* extern */
extern M2C_UNK lbl_8041B978[];

void *w3d_auto_80257528(void *arg0) {
    fn_801EA0EC();
    M2C_FIELD(arg0, s8 *, 0x14) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_8041B978);
    M2C_FIELD(arg0, s8 *, 0x15) = 0;
    M2C_FIELD(arg0, s8 *, 0x16) = 0;
    M2C_FIELD(arg0, s8 *, 0x17) = 0;
    M2C_FIELD(arg0, s8 *, 0x18) = 0;
    M2C_FIELD(arg0, s8 *, 0x19) = 0;
    M2C_FIELD(arg0, s8 *, 0x1A) = 0;
    M2C_FIELD(arg0, s8 *, 0x1B) = 0;
    M2C_FIELD(arg0, s8 *, 0x1C) = 0;
    M2C_FIELD(arg0, s8 *, 0x1D) = 0;
    M2C_FIELD(arg0, s8 *, 0x1E) = 0;
    M2C_FIELD(arg0, s8 *, 0x1F) = 0;
    M2C_FIELD(arg0, s8 *, 0x20) = 0;
    M2C_FIELD(arg0, s8 *, 0x21) = 0;
    M2C_FIELD(arg0, s8 *, 0x22) = 0;
    M2C_FIELD(arg0, s8 *, 0x23) = 0;
    M2C_FIELD(arg0, s8 *, 0x24) = 0;
    M2C_FIELD(arg0, s8 *, 0x25) = 0;
    M2C_FIELD(arg0, s8 *, 0x26) = 0;
    M2C_FIELD(arg0, s8 *, 0x27) = 0;
    M2C_FIELD(arg0, s8 *, 0x28) = 0;
    M2C_FIELD(arg0, s8 *, 0x29) = 0;
    M2C_FIELD(arg0, s8 *, 0x2A) = 0;
    M2C_FIELD(arg0, s8 *, 0x2B) = 0;
    M2C_FIELD(arg0, s8 *, 0x2C) = 0;
    M2C_FIELD(arg0, s8 *, 0x2D) = 0;
    M2C_FIELD(arg0, s8 *, 0x2E) = 0;
    M2C_FIELD(arg0, s8 *, 0x2F) = 0;
    M2C_FIELD(arg0, s8 *, 0x30) = 0;
    M2C_FIELD(arg0, s8 *, 0x31) = 0;
    M2C_FIELD(arg0, s8 *, 0x32) = 0;
    M2C_FIELD(arg0, s8 *, 0x33) = 0;
    M2C_FIELD(arg0, s8 *, 0x34) = 0;
    M2C_FIELD(arg0, s8 *, 0x35) = 0;
    M2C_FIELD(arg0, s8 *, 0x36) = 0;
    M2C_FIELD(arg0, s8 *, 0x37) = 0;
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    M2C_FIELD(arg0, s8 *, 0x39) = 0;
    M2C_FIELD(arg0, s8 *, 0x3A) = 0;
    M2C_FIELD(arg0, s8 *, 0x3B) = 0;
    M2C_FIELD(arg0, s8 *, 0x3C) = 0;
    M2C_FIELD(arg0, s8 *, 0x3D) = 0;
    M2C_FIELD(arg0, s8 *, 0x3E) = 0;
    M2C_FIELD(arg0, s8 *, 0x3F) = 0;
    M2C_FIELD(arg0, s8 *, 0x40) = 0;
    M2C_FIELD(arg0, s8 *, 0x41) = 0;
    M2C_FIELD(arg0, s8 *, 0x42) = 0;
    M2C_FIELD(arg0, s8 *, 0x43) = 0;
    M2C_FIELD(arg0, s8 *, 0x44) = 0;
    M2C_FIELD(arg0, s8 *, 0x45) = 0;
    M2C_FIELD(arg0, s8 *, 0x46) = 0;
    fn_8025C2D8(arg0);
    return arg0;
}
