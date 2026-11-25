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

M2C_UNK fn_801E8D9C(M2C_UNK *);                     /* extern */
M2C_UNK fn_801EB674(M2C_UNK *, M2C_UNK *);          /* extern */
M2C_UNK fn_801EBF38(M2C_UNK *, M2C_UNK *);          /* extern */
M2C_UNK fn_801EC52C(M2C_UNK *, M2C_UNK *);          /* extern */
extern M2C_UNK lbl_803C7DA0[];
extern M2C_UNK lbl_803C7DD8[];
extern M2C_UNK lbl_803C7E10[];
extern M2C_UNK lbl_803C7E48[];
extern M2C_UNK lbl_803C7E80[];
extern M2C_UNK lbl_803C7EBC[];
extern M2C_UNK lbl_803C7EF0[];
extern M2C_UNK lbl_803C7F38[];
extern M2C_UNK lbl_803C7F80[];
extern M2C_UNK lbl_803C7FC4[];
extern M2C_UNK lbl_803C8008[];

s32 w3d_auto_80255418(M2C_UNK *arg0) {
    fn_801EC52C(arg0, &(*lbl_803C7DA0));
    fn_801EBF38(arg0, &(*lbl_803C7DD8));
    fn_801EBF38(arg0, &(*lbl_803C7E10));
    fn_801EBF38(arg0, &(*lbl_803C7E48));
    fn_801EC52C(arg0, &(*lbl_803C7E80));
    fn_801EC52C(arg0, &(*lbl_803C7EBC));
    fn_801EB674(arg0, &(*lbl_803C7EF0));
    fn_801EC52C(arg0, &(*lbl_803C7F38));
    fn_801EC52C(arg0, &(*lbl_803C7F80));
    fn_801EC52C(arg0, &(*lbl_803C7FC4));
    fn_801EC52C(arg0, &(*lbl_803C8008));
    fn_801E8D9C(arg0);
    return 0;
}
