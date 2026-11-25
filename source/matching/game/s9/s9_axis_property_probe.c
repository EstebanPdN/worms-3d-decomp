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
f32 fn_800AE9AC(s32);                           /* extern */
f32 fn_800AE9B4(s32);                           /* extern */
s32 fn_80164FC8(s32);                                  /* extern */
M2C_UNK fn_80181814(s32, s32, f32, f32);                 /* extern */
extern f32 lbl_8039F6EC[];
extern s32 lbl_804AB17C;
extern s32 lbl_804AB180;

void s9_update_axis_properties_8013a048(void *arg0, s32 arg1) {


    s32 temp_r30;
    s32 temp_r30_2;
    s32 temp_r3;
    f32 first_value,second_value;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x90) == -1) {
        goto block_4;
    }
    temp_r3 = fn_80164FC8((s32)(M2C_FIELD((void *)(arg0), s32 *, 144)));
    if (temp_r3 != 0) {
        goto block_3;
    }
    M2C_FIELD(arg0, s32 *, 0x90) = -1;
    return;
block_3:
    temp_r30 = lbl_804AB180;
    first_value=fn_800AE9AC(temp_r3);
    fn_80181814(arg1, temp_r30,first_value, (*lbl_8039F6EC));
    temp_r30_2 = lbl_804AB17C;
    second_value=fn_800AE9B4(temp_r3);
    fn_80181814(arg1, temp_r30_2,second_value, (*lbl_8039F6EC));
block_4:
    return;
}
