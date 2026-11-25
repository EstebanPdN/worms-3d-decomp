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
M2C_UNK fn_801FE1D8(M2C_UNK);                       /* extern */
M2C_UNK fn_8020BD38(void **, M2C_UNK *);            /* extern */
M2C_UNK fn_8020BF2C(void **, M2C_UNK *);            /* extern */
M2C_UNK fn_8020C5C0(void **);                       /* extern */
M2C_UNK fn_8020C5C4(void **);                       /* extern */
M2C_UNK fn_80218194(void **);                       /* extern */
void **fn_802187DC();                               /* extern */
s32 fn_80218C50(void **, void *, s32);              /* extern */
M2C_UNK fn_80218D78(void **, void *);               /* extern */
void **fn_80218EC4();                               /* extern */
s32 fn_80219184(void **, void *, s32);              /* extern */
M2C_UNK fn_802192B8(void **, void *);               /* extern */
s32 fn_802EEDC0(void *, M2C_UNK *, M2C_UNK);        /* extern */
M2C_UNK fn_80341588(void **);                       /* extern */
u16 *fn_80341884(void **);                          /* extern */
extern M2C_UNK lbl_803B387C[];
extern M2C_UNK lbl_803B3880[];

extern "C" s32 w3d_s12_open_resource_8021840c(void *arg0, M2C_UNK *arg1, s32 arg2, void ***arg3) {
    void *sp8;
    s32 var_r31;
    s32 var_r3;
    u16 *temp_r3;
    u16 temp_r9;
    u8 temp_r9_2;
    void **temp_r3_2;
    void **var_r30;
    void *temp_r9_3;

    fn_8020C5C0(&sp8);
    sp8 = M2C_FIELD(arg0, void **, 0x18);
    temp_r3 = fn_80341884(&sp8);
    *temp_r3 += 1;
    temp_r9 = M2C_FIELD(sp8, u16 *, -4);
    if ((s32) temp_r9 != 0) {
        temp_r9_2 = M2C_FIELD(((char *)sp8 + temp_r9), u8 *, -1);
        if (((s32) temp_r9_2 != 0x2F) && ((s32) temp_r9_2 != 0x5C) && ((s32) temp_r9_2 != 0x3A)) {
            fn_8020BF2C(&sp8, &(*lbl_803B387C));
        }
    }
    if (arg2 & 2) {
        fn_8020BD38(&sp8, arg1);
    } else {
        fn_8020BF2C(&sp8, arg1);
    }
    fn_80218194(&sp8);
    if (fn_802EEDC0(sp8, &(*lbl_803B3880), 5) == 0) {
        fn_801FE1D8(0x1C);
        var_r30 = fn_80218EC4();
        if (var_r30 != NULL) {
            M2C_FIELD(*var_r30, M2C_UNK (**)(void **), 0xC)(var_r30);
            fn_802192B8(var_r30, arg0);
            var_r3 = fn_80219184(var_r30, (char *)sp8 + 5, arg2);
            goto block_13;
        }
        goto block_15;
    }
    fn_801FE1D8(0x70);
    var_r30 = fn_802187DC();
    if (var_r30 != NULL) {
        M2C_FIELD(*var_r30, M2C_UNK (**)(void **), 0xC)(var_r30);
        fn_80218D78(var_r30, arg0);
        var_r3 = fn_80218C50(var_r30, sp8, arg2);
block_13:
        var_r31 = var_r3;
        if (var_r31 < 0) {
            temp_r9_3 = *var_r30;
            temp_r3_2 = var_r30;
            var_r30 = 0;
            M2C_FIELD(temp_r9_3, M2C_UNK (**)(void **), 0x10)(temp_r3_2);
        }
    } else {
block_15:
        var_r31 = 0x80004005;
    }
    *arg3 = var_r30;
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
    return var_r31;
}
