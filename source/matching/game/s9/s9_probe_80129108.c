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
M2C_UNK fn_8020BB54(M2C_UNK *, M2C_UNK *);          /* extern */
M2C_UNK fn_8020C5C4(M2C_UNK *);                     /* extern */
M2C_UNK fn_80341588(M2C_UNK *);                     /* extern */
extern M2C_UNK lbl_8039C89C[];
extern M2C_UNK lbl_8039C8A0[];
extern M2C_UNK lbl_8039C8A8[];
extern M2C_UNK lbl_8039C8B0[];
extern M2C_UNK lbl_8039C8C0[];
extern M2C_UNK lbl_8039C8D4[];
extern M2C_UNK lbl_8039C8DC[];
extern M2C_UNK lbl_8039C8E4[];
extern M2C_UNK lbl_8039C8EC[];

void s9_probe_80129108(void *arg0) {
    M2C_UNK sp8;
    s32 temp_r0;
    void *temp_r30;
    void *temp_r30_2;
    void *temp_r30_3;
    void *temp_r30_4;
    void *temp_r30_5;
    void *temp_r30_6;
    void *temp_r30_7;
    void *temp_r30_8;
    void *temp_r30_9;

    temp_r30 = M2C_FIELD(arg0, void **, 0);
    fn_8020BB54(&sp8, &(*lbl_8039C89C));
    M2C_FIELD(temp_r30, M2C_UNK (**)(void *, M2C_UNK *), 0x14)(arg0, &sp8);
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
    temp_r30_2 = M2C_FIELD(arg0, void **, 0);
    fn_8020BB54(&sp8, &(*lbl_8039C8A0));
    M2C_FIELD(temp_r30_2, M2C_UNK (**)(void *, M2C_UNK *), 0x14)(arg0, &sp8);
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
    temp_r30_3 = M2C_FIELD(arg0, void **, 0);
    fn_8020BB54(&sp8, &(*lbl_8039C8A8));
    M2C_FIELD(temp_r30_3, M2C_UNK (**)(void *, M2C_UNK *), 0x14)(arg0, &sp8);
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
    temp_r30_4 = M2C_FIELD(arg0, void **, 0);
    fn_8020BB54(&sp8, &(*lbl_8039C8B0));
    M2C_FIELD(temp_r30_4, M2C_UNK (**)(void *, M2C_UNK *), 0x14)(arg0, &sp8);
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
    temp_r30_5 = M2C_FIELD(arg0, void **, 0);
    fn_8020BB54(&sp8, &(*lbl_8039C8C0));
    M2C_FIELD(temp_r30_5, M2C_UNK (**)(void *, M2C_UNK *), 0x14)(arg0, &sp8);
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
    temp_r0 = M2C_FIELD(arg0, s32 *, 0xBC);
    if (!(temp_r0 & 0x20000000)) {
        goto block_2;
    }
    if (!(temp_r0 & 0x10000000)) {
        goto block_3;
    }
block_2:
    temp_r30_6 = M2C_FIELD(arg0, void **, 0);
    fn_8020BB54(&sp8, &(*lbl_8039C8D4));
    M2C_FIELD(temp_r30_6, M2C_UNK (**)(void *, M2C_UNK *), 0x14)(arg0, &sp8);
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
    temp_r30_7 = M2C_FIELD(arg0, void **, 0);
    fn_8020BB54(&sp8, &(*lbl_8039C8DC));
    M2C_FIELD(temp_r30_7, M2C_UNK (**)(void *, M2C_UNK *), 0x14)(arg0, &sp8);
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
    temp_r30_8 = M2C_FIELD(arg0, void **, 0);
    fn_8020BB54(&sp8, &(*lbl_8039C8E4));
    M2C_FIELD(temp_r30_8, M2C_UNK (**)(void *, M2C_UNK *), 0x14)(arg0, &sp8);
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
    temp_r30_9 = M2C_FIELD(arg0, void **, 0);
    fn_8020BB54(&sp8, &(*lbl_8039C8EC));
    M2C_FIELD(temp_r30_9, M2C_UNK (**)(void *, M2C_UNK *), 0x14)(arg0, &sp8);
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
block_3:
    return;
}
