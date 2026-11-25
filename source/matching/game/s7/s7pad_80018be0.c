/* Recovered from original instructions; inferred types and names. */
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
s32 fn_800153DC(s32);                               /* extern */
s32 fn_80015434(s32);                               /* extern */
f32 fn_802E8094(f32);                               /* extern */
f32 fn_802E83CC(f32);                               /* extern */
extern f32 lbl_8036A8D0[];
extern f64 lbl_8036A8D8[];
extern void *lbl_804AA6D8;
extern s32 lbl_804AA744;
extern s32 lbl_804AA748;
extern f32 lbl_804AA74C;

void w3d_auto_80018be0(void) {
    volatile char s7_frame_storage[1];
    f32 temp_f31;
    s32 var_r29;
    s32 var_r30;
    s32 var_r31;

    var_r30 = 0;
    var_r29 = 0;
    var_r31 = 0;
    do {
        if (fn_800153DC(var_r31) != 0) {
            if (fn_80015434(var_r31) != 0) {
                var_r30 += 1;
            } else {
                var_r29 += 1;
            }
        }
        var_r31 += 1;
    } while (var_r31 <= 0xF);
    if ((var_r30 == 0) || (var_r29 == 0)) {
        lbl_804AA748 = 1;
        lbl_804AA74C = (*lbl_8036A8D0);
        lbl_804AA744 = 1;
        return;
    }
    lbl_804AA748 = var_r30;
    lbl_804AA744 = var_r29;
    temp_f31 = M2C_FIELD(lbl_804AA6D8, f32 *, 0x70);
    lbl_804AA74C = fn_802E8094(temp_f31 * fn_802E83CC((f32) (f64) var_r30 / (f32) (f64) var_r29));
}
