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


M2C_UNK fn_801A381C();                              /* extern */
M2C_UNK fn_801A3944();                              /* extern */
M2C_UNK fn_802134FC(void *);                        /* extern */

void w3d_auto_801d10a0(void *arg0, s8 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s8 *, 0x29) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d10c0(void *arg0, s8 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s8 *, 0x28) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d10e0(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x18) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1100(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x20) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1120(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x24) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1140(void *arg0, f32 farg0) {
    void *temp_r3;

    M2C_FIELD(arg0, f32 *, 0x1C) = farg0;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1160(void *arg0, f32 farg0) {
    void *temp_r3;

    M2C_FIELD(arg0, f32 *, 0x18) = farg0;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1180(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x18) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d11a0(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x18) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d11c0(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x18) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d11e0(void *arg0, f32 farg0) {
    void *temp_r3;

    M2C_FIELD(arg0, f32 *, 0x18) = farg0;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1200(void *arg0, f32 farg0) {
    void *temp_r3;

    M2C_FIELD(arg0, f32 *, 0x18) = farg0;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1220(void *arg0, s16 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s16 *, 0x1A) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1240(void *arg0, s16 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s16 *, 0x18) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1260(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x34) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1280(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x30) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d12a0(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x2C) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d12c0(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x28) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1320(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x38) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1340(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x34) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d13a0(void *arg0, f32 farg0) {
    void *temp_r3;

    M2C_FIELD(arg0, f32 *, 0x30) = farg0;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d13c0(void *arg0, f32 farg0) {
    void *temp_r3;

    M2C_FIELD(arg0, f32 *, 0x2C) = farg0;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d13e0(void *arg0, f32 farg0) {
    void *temp_r3;

    M2C_FIELD(arg0, f32 *, 0x28) = farg0;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1400(void *arg0, f32 farg0) {
    void *temp_r3;

    M2C_FIELD(arg0, f32 *, 0x1C) = farg0;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1420(void *arg0, f32 farg0) {
    void *temp_r3;

    M2C_FIELD(arg0, f32 *, 0x18) = farg0;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1440(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x1C) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d1460(void *arg0, s32 arg1) {
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x18) = arg1;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

void w3d_auto_801d17c4(void *arg0, f32 farg0) {
    void *temp_r3;

    M2C_FIELD(arg0, f32 *, 0x64) = farg0;
    temp_r3 = arg0 + 4;
    M2C_FIELD(temp_r3, u8 *, 7) = (u8) (M2C_FIELD(temp_r3, u8 *, 7) | 2);
}

s32 w3d_auto_801d388c(void *arg0, s32 *arg1) {
    *arg1 = (s32) (M2C_FIELD(arg0, s32 *, 0x4C) - M2C_FIELD(arg0, s32 *, 0x48)) >> 2;
    return M2C_FIELD(arg0, s32 *, 0x48);
}

s32 w3d_auto_801d5668(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x30) = arg1;
    return 0;
}

void w3d_auto_801d65a0(void) {
    fn_801A381C();
}

void w3d_auto_801d65c0(void) {
    fn_801A3944();
}

void w3d_auto_801d6850(void *arg0) {
    fn_802134FC(M2C_FIELD(arg0, void **, 8));
    fn_802134FC(arg0);
}

s32 w3d_auto_801d7908(void *arg0) {
    return ((u32) M2C_FIELD(arg0, u32 *, 0x58) >> 1U) & 3;
}

s32 w3d_auto_801d9c90(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x2C) = arg1;
    return 0;
}

s32 w3d_auto_801db8a8(void) {
    return 0x80004001;
}

s32 w3d_auto_801dbb94(void **arg0) {
    u32 temp_r4;
    u32 var_r31;

    var_r31 = 0U;
    do {
        temp_r4 = var_r31;
        var_r31 += 1;
        M2C_FIELD(*arg0, M2C_UNK (**)(void **, u32), 0x24)(arg0, temp_r4);
    } while (var_r31 <= 3U);
    return 0;
}

s32 w3d_auto_801dbbe8(void **arg0) {
    u32 temp_r4;
    u32 var_r31;

    var_r31 = 0U;
    do {
        temp_r4 = var_r31;
        var_r31 += 1;
        M2C_FIELD(*arg0, M2C_UNK (**)(void **, u32), 0x28)(arg0, temp_r4);
    } while (var_r31 <= 3U);
    return 0;
}

s32 w3d_auto_801dbea8(void) {
    return 0x80004001;
}

s32 w3d_auto_801dcbfc(void *arg0, f32 farg0) {
    M2C_FIELD(arg0, f32 *, 0x5C) = farg0;
    return 0;
}
