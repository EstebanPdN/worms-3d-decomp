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

M2C_UNK fn_800FC43C(M2C_UNK **, M2C_UNK);           /* extern */
s32 fn_8010A8E0(void *, u16, M2C_UNK *);           /* extern */
M2C_UNK fn_80129878(void *);                           /* extern */
s32 fn_8015F5A0(M2C_UNK *, M2C_UNK);                /* extern */
void **fn_80160E34(void *, M2C_UNK);                   /* extern */
s32 fn_801613F0(void *, M2C_UNK);                      /* extern */
M2C_UNK fn_8016239C(s32);                              /* extern */
extern M2C_UNK lbl_803CF594[];
extern M2C_UNK lbl_803CF5A4[];
extern M2C_UNK lbl_803CF5B0[];
extern M2C_UNK lbl_804B0BBC;
extern s32 lbl_804B1754;
extern s32 lbl_804B1788;
extern s32 lbl_804B17F0;

s32 w3d_auto_80287600(void *arg0) {
    M2C_UNK *sp8;
    M2C_UNK *spC;
    M2C_UNK *sp10;
    s32 temp_r30;
    s32 var_r0;
    s32 var_r29;
    void **temp_r3;

    var_r29 = 0;
    temp_r3 = fn_80160E34(lbl_804B17F0, 0);
    if (temp_r3 == NULL) {
        goto block_7;
    }
    if (M2C_FIELD(*temp_r3, s32 (**)(void **), 0x34)(temp_r3) == 0) {
        goto block_7;
    }
    var_r29 = 1;
    var_r0 = (M2C_FIELD(*temp_r3, s32 (**)(void **, M2C_UNK, M2C_UNK), 0x44)(temp_r3, 0, 0) != 0);

block_4:
    if (var_r0 == 0) {
        goto block_6;
    }
    sp8 = &(*lbl_803CF594);
    fn_800FC43C(&sp8, 0);
    goto block_7;
block_6:
    spC = &(*lbl_803CF594);
    fn_800FC43C(&spC, 1);
    sp10 = &(*lbl_803CF5A4);
    fn_800FC43C(&sp10, 0);
block_7:
    if (!(M2C_FIELD(arg0, s32 *, 0x38) & 0x40000000)) {
        goto block_13;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x1C) != 0) {
        goto block_13;
    }
    if (var_r29 != 0) {
        goto block_13;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x34) == 0) {
        goto block_12;
    }
    fn_80129878(lbl_804B1788);
    temp_r30 = fn_801613F0(lbl_804B1754, 0xC);
    fn_8016239C(fn_8010A8E0(temp_r30, fn_8015F5A0(&lbl_804B0BBC, 1), &(*lbl_803CF5B0)));
block_12:
    M2C_FIELD(arg0, s32 *, 0x1C) = 1;
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) (M2C_FIELD(arg0, s32 *, 0x38) | 0x80000000);
block_13:
    return 0x14;
}
