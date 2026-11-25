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

M2C_UNK fn_800FC43C(M2C_UNK **, u16);               /* extern */
M2C_UNK fn_802EEFE0(void *, M2C_UNK, M2C_UNK);      /* extern */
M2C_UNK fn_803426B8();                              /* extern */
extern M2C_UNK lbl_803CBB70[];
extern M2C_UNK lbl_803CBB78[];
extern M2C_UNK lbl_803CBB84[];
extern M2C_UNK lbl_803CBB8C[];
extern M2C_UNK lbl_803CBB98[];
extern M2C_UNK lbl_803CBBA4[];
extern M2C_UNK lbl_803CBBB0[];
extern M2C_UNK lbl_803CBBBC[];
extern M2C_UNK lbl_803CBBC8[];
extern M2C_UNK lbl_803CBCB0[];

void *w3d_auto_8026c714(void *arg0) {
    M2C_UNK *sp8;
    M2C_UNK *spC;
    M2C_UNK *sp10;
    M2C_UNK *sp14;
    M2C_UNK *sp18;
    M2C_UNK *sp1C;
    M2C_UNK *sp20;
    M2C_UNK *sp24;
    M2C_UNK *sp28;

    fn_803426B8();
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = 1;
    fn_802EEFE0(arg0 + 0x38, 0, 0x28);
    sp8 = &(*lbl_803CBB70);
    fn_800FC43C(&sp8, M2C_FIELD(&(*lbl_803CBCB0), u16 *, 0));
    spC = &(*lbl_803CBB78);
    fn_800FC43C(&spC, M2C_FIELD(&(*lbl_803CBCB0), u16 *, 2));
    sp10 = &(*lbl_803CBB84);
    fn_800FC43C(&sp10, M2C_FIELD(&(*lbl_803CBCB0), u16 *, 4));
    sp14 = &(*lbl_803CBB8C);
    fn_800FC43C(&sp14, M2C_FIELD(&(*lbl_803CBCB0), u16 *, 6));
    sp18 = &(*lbl_803CBB98);
    fn_800FC43C(&sp18, M2C_FIELD(&(*lbl_803CBCB0), u16 *, 8));
    sp1C = &(*lbl_803CBBA4);
    fn_800FC43C(&sp1C, M2C_FIELD(&(*lbl_803CBCB0), u16 *, 0xA));
    sp20 = &(*lbl_803CBBB0);
    fn_800FC43C(&sp20, M2C_FIELD(&(*lbl_803CBCB0), u16 *, 0xC));
    sp24 = &(*lbl_803CBBBC);
    fn_800FC43C(&sp24, M2C_FIELD(&(*lbl_803CBCB0), u16 *, 0xE));
    sp28 = &(*lbl_803CBBC8);
    fn_800FC43C(&sp28, M2C_FIELD(&(*lbl_803CBCB0), u16 *, 0x10));
    return arg0;
}
