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


void *fn_800FC6DC();                                /* extern */
M2C_UNK fn_80178C48();                              /* extern */
M2C_UNK fn_803426B4(s32);                           /* extern */
M2C_UNK fn_800261D4();                              /* extern */
M2C_UNK fn_800271EC(void *, s32);                   /* extern */
s32 fn_8006E71C();                                  /* extern */
f32 fn_80178DF0();                                  /* extern */
M2C_UNK fn_80342A74(s32);                           /* extern */
M2C_UNK fn_8015FD1C();                              /* extern */
M2C_UNK fn_8002A6CC();                              /* extern */
M2C_UNK fn_800FC1B0(s32 *, s32);                    /* extern */
M2C_UNK fn_8002AF78(void *);                        /* extern */

s32 w3d_auto_80024f64(void *arg0) {
    fn_803426B4(M2C_FIELD(arg0, s32 *, 0x1C));
    fn_80178C48();
    return M2C_FIELD(fn_800FC6DC(), s32 *, 0xD8);
}

s32 w3d_auto_800255e0(void *arg0) {
    fn_803426B4(M2C_FIELD(arg0, s32 *, 0x1C));
    fn_80178C48();
    return M2C_FIELD(fn_800FC6DC(), s32 *, 0x70);
}

s32 w3d_auto_80025b04(void *arg0) {
    fn_803426B4(M2C_FIELD(arg0, s32 *, 0x1C));
    fn_80178C48();
    return M2C_FIELD(fn_800FC6DC(), s32 *, 0x68);
}

s32 w3d_auto_80026034(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x5C) == 0) {
        fn_800261D4();
    }
    return 0;
}

s32 w3d_auto_80026e14(void *arg0, s32 arg1) {
    if ((fn_8006E71C() == 0) && (((s32) M2C_FIELD(arg0, s32 *, 0x4C) != 0) || ((s32) M2C_FIELD(arg0, s32 *, 0x50) != 0))) {
        fn_800271EC(arg0, arg1);
    }
    return 0x14;
}

extern M2C_UNK lbl_8036CB58;

f32 w3d_auto_80027114(void *arg0, s32 arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 var_f1;
    s32 temp_r30;
    s32 temp_r30_2;

    fn_80342A74(M2C_FIELD(arg0, s32 *, 0x20));
    temp_f12 = fn_80178DF0();
    temp_r30 = arg1 - M2C_FIELD(arg0, s32 *, 0x60);
    var_f1 = M2C_FIELD(arg0, f32 *, 0x54);
    temp_r30_2 = temp_r30 * temp_r30;
    if ((s32) M2C_FIELD(arg0, s32 *, 0x4C) != 0) {
        var_f1 += (f32) (f64) temp_r30_2 * temp_f12;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x50) != 0) {
        var_f1 -= (f32) (f64) temp_r30_2 * temp_f12;
    }
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x58);
    if (var_f1 > temp_f0) {
        var_f1 = temp_f0;
    }
    temp_f0_2 = M2C_FIELD(arg0, f32 *, 0x5C);
    if (var_f1 < temp_f0_2) {
        var_f1 = temp_f0_2;
    }
    return var_f1;
}

void w3d_auto_80027d20(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0xD0) = -1;
}

void w3d_auto_8002a68c(void) {
    fn_8015FD1C();
}

void w3d_auto_8002a6ac(void) {
    fn_8002A6CC();
}

void w3d_auto_8002ad7c(void) {
    fn_8015FD1C();
}

void w3d_auto_8002b070(s32 arg0, s32 arg1) {
    s32 sp8;

    sp8 = arg1;
    fn_800FC1B0(&sp8, arg0 + 0x2C);
}

void w3d_auto_8002c0bc(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x60) != 0) {
        if ((s32) M2C_FIELD(arg0, s32 *, 0x58) == 0) {
            M2C_FIELD(arg0, s32 *, 0x58) = 1;
        }
        if ((s32) M2C_FIELD(arg0, s32 *, 0x9C) == 0) {
            M2C_FIELD(arg0, s32 *, 0x9C) = 1;
            fn_8002AF78(arg0);
        }
    }
}
