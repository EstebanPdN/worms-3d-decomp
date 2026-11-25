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


M2C_UNK fn_801AB05C();                              /* extern */
s32 fn_802EEDC0(void *, void *, M2C_UNK);                 /* extern */

s32 w3d_auto_801a9ab4(void *arg0) {
    return (s32) (M2C_FIELD(arg0, s32 *, 0x124) - M2C_FIELD(arg0, s32 *, 0x120)) >> 4;
}

void w3d_auto_801a9c9c(void *arg0) {
    void *temp_r11;

    temp_r11 = arg0 + 0x134;
    M2C_FIELD(arg0, u16 *, 0x130) = (u16) M2C_FIELD(M2C_FIELD(temp_r11, void **, 4), u16 *, -2);
    M2C_FIELD(temp_r11, void **, 4) = (void *) (M2C_FIELD(temp_r11, void **, 4) - 2);
}

s32 w3d_auto_801ab030(void *arg0, f32 farg0) {
    M2C_FIELD(arg0, f32 *, 0x28) = farg0;
    return 0;
}

void w3d_auto_801ab03c(void) {
    fn_801AB05C();
}

s32 w3d_auto_801ab5c8(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x30) = arg1;
    return 0;
}

s32 w3d_auto_801ab5dc(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x78) = arg1;
    return 0;
}

s32 w3d_auto_801ab734(void) {
    return 0x80004001;
}

s32 w3d_auto_801ab764(void) {
    return 0x80004001;
}

s32 w3d_auto_801ab770(void) {
    return 0x80004001;
}

s32 w3d_auto_801ab77c(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x34) = arg1;
    return 0;
}

s32 w3d_auto_801ab790(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x38) = arg1;
    return 0;
}

s32 w3d_auto_801ab7a4(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x3C) = arg1;
    return 0;
}

s32 w3d_auto_801ab7b8(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x40) = arg1;
    return 0;
}

s32 w3d_auto_801ab7cc(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x44) = arg1;
    return 0;
}

s32 w3d_auto_801ab7e0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x48) = arg1;
    return 0;
}

s32 w3d_auto_801ab7f4(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x4C) = arg1;
    return 0;
}

s32 w3d_auto_801ab808(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x50) = arg1;
    return 0;
}

s32 w3d_auto_801ab81c(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x54) = arg1;
    return 0;
}

s32 w3d_auto_801ab8a0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
    return 0;
}

s32 w3d_auto_801ab920(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x5C) = arg1;
    return 0;
}

s32 w3d_auto_801ab96c(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x70) = arg1;
    return 0;
}

s32 w3d_auto_801ab980(void *arg0, f32 farg0) {
    M2C_FIELD(arg0, f32 *, 0x74) = farg0;
    return 0;
}

s32 w3d_auto_801aba98(u32 arg0) {
    s32 var_r9;
    u32 var_r3;

    var_r9 = -1;
    var_r3 = arg0;
    if (var_r3 != 0) {
        do {
            var_r9 += 1;
            var_r3 = var_r3 >> 1U;
        } while (var_r3 != 0);
    }
    return var_r9;
}

s32 w3d_auto_801ac348(void) {
    return 0x80004001;
}

s32 w3d_auto_801ac354(void) {
    return 0x80004001;
}

s32 w3d_auto_801ac360(void) {
    return 0x80004001;
}

s32 w3d_auto_801ac36c(void) {
    return 0x80004001;
}

s32 w3d_auto_801acd58(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x54) = arg1;
    return 0;
}

s32 w3d_auto_801ad0e4(void *arg0) {
    s32 var_r11;

    var_r11 = 1;
    if (((u32) (M2C_FIELD(arg0, s32 *, 0x78) - M2C_FIELD(arg0, s32 *, 0x74)) >> 4U) == 0) {
        var_r11 = 0;
    }
    return var_r11;
}

s32 w3d_auto_801add34(void) {
    return 0x80004005;
}

s32 w3d_auto_801add40(void) {
    return 0x80004005;
}

s32 w3d_auto_801ae594(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x28) = arg1;
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) M2C_FIELD(arg0, s32 *, 0x30);
    return 0;
}

s32 w3d_auto_801af71c(void *arg0) {
    return (s32) ((M2C_FIELD(arg0, s32 *, 0x18) - M2C_FIELD(arg0, s32 *, 0x14)) * 0xAAAAAAAB) >> 3;
}

s32 w3d_auto_801af808(void *arg0, s32 arg1) {
    s32 temp_r30;
    s32 var_r29;
    s32 var_r31;

    temp_r30 = M2C_FIELD(arg0, s32 *, 0x18);
    var_r31 = M2C_FIELD(arg0, s32 *, 0x14);
    var_r29 = 0;
    if (var_r31 != temp_r30) {
        do {
            if (fn_802EEDC0(var_r31 + 4, arg1, 0x10) == 0) {
                var_r29 += 1;
            }
            var_r31 += 0x18;
        } while (var_r31 != temp_r30);
    }
    return var_r29;
}

s32 w3d_auto_801b1ba4(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x50) = arg1;
    return 0;
}

s32 w3d_auto_801b2514(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x2C) = arg1;
    return 0;
}

s32 w3d_auto_801b2528(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x30) = arg1;
    return 0;
}

s32 w3d_auto_801b253c(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x34) = arg1;
    return 0;
}

extern s32 lbl_804AB7A4;

s32 w3d_auto_801b2b70(void) {
    return lbl_804AB7A4;
}

extern s32 lbl_804AB7A4;

void w3d_auto_801b2b78(void) {
    lbl_804AB7A4 = 0;
}
