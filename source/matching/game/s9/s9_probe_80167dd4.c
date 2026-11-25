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
M2C_UNK fn_8016857C(void *, M2C_UNK);               /* extern */
M2C_UNK fn_8016A1E8(void *, M2C_UNK);               /* extern */
M2C_UNK fn_803080A4(M2C_UNK);                       /* extern */
M2C_UNK fn_8030990C(M2C_UNK);                       /* extern */
M2C_UNK fn_80309948(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK fn_8030B058(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK fn_8030B4AC(M2C_UNK, s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK fn_8030B648(M2C_UNK);                       /* extern */

void s9_probe_80167dd4(void *arg0, s32 arg1) {
    M2C_UNK var_r25;
    M2C_UNK var_r26;
    M2C_UNK var_r27;
    M2C_UNK var_r29;
    s32 temp_r0;
    s32 temp_r11;
    s32 temp_r9;
    s32 var_r24;
    s32 var_r28;
    void *var_r30;

    temp_r11 = M2C_FIELD(arg0, s32 *, 0x1494);
    if (temp_r11 & 0x20000000) {
        goto block_2;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0xF4) == (s32) M2C_FIELD(arg0, s32 *, 0xEC)) {
        goto block_26;
    }
block_2:
    temp_r9 = M2C_FIELD(arg0, s32 *, 0xEC);
    M2C_FIELD(arg0, s32 *, 0x1494) = (s32) (temp_r11 & 0xDFFFFFFF);
    var_r25 = 0;
    M2C_FIELD(arg0, s32 *, 0xF4) = temp_r9;
    var_r24 = 0;
    var_r30 = arg1 ? (void *)(arg1 - 4) : NULL;
block_4:
    var_r27 = 0xFF;
    var_r26 = 1;
    if (!(temp_r9 & 4)) {
        goto block_6;
    }
    fn_8016857C(arg0, 0);
    var_r27 = 0;
    var_r26 = 0;
    var_r24 = 1;
    goto block_10;
block_6:
    if (!(temp_r9 & 0x10)) {
        goto block_8;
    }
    var_r27 = 4;
    var_r26 = 0;
    goto block_10;
block_8:
    if (!(temp_r9 & 8)) {
        goto block_11;
    }
    var_r27 = 4;
block_10:
    var_r25 = 1;
block_11:
    temp_r0 = M2C_FIELD(arg0, s32 *, 0xEC);
    if (!(temp_r0 & 0x20)) {
        goto block_20;
    }
    var_r28 = var_r30 ? M2C_FIELD(var_r30, s32 *, 0x130) : 0;
block_14:
    var_r29 = 0;
    if (temp_r0 & 0x40) {
        goto block_18;
    }
    if (!(temp_r0 & 0x80)) {
        goto block_17;
    }
    fn_8030B058(0, 7, 7, 7, 5);
    M2C_FIELD(arg0, s32 *, 0xF4) = 0;
    M2C_FIELD(arg0, s32 *, 0xEC) = (s32) (M2C_FIELD(arg0, s32 *, 0xEC) & 0xFFFFFF7F);
    goto block_23;
block_17:
    if (!(temp_r0 & 4)) {
        goto block_19;
    }
block_18:
    fn_8030B058(0, 7, 7, 7, 4);
    goto block_23;
block_19:
    fn_8030B058(0, 7, 4, 5, 7);
    goto block_23;
block_20:
    var_r28 = 0xFF;
    fn_803080A4(0);
    var_r29 = 0xFF;
    fn_8030B648(1);
    if (var_r30 == NULL) {
        goto block_22;
    }
    fn_8016A1E8(var_r30, 4);
block_22:
    fn_8030B058(0, 7, 7, 7, 5);
block_23:
    fn_8030B4AC(0, var_r28, var_r29, var_r27);
    if (var_r24 == 0) {
        goto block_25;
    }
    fn_80309948(0, 1, var_r26, var_r26, 1, 2, 2);
    fn_8030990C(var_r25);
    return;
block_25:
    fn_80309948(4, 0, var_r26, var_r26, 0, 0, 2);
    fn_8030990C(var_r25);
block_26:
    return;
}
