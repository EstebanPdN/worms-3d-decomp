#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "auto_80158f68.c"
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
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)(w3d::bytes(expr) + (offset)))

/* Bitwise (reinterpret) cast */
#define M2C_BITWISE(type, expr) ((w3d::slot_t<type>)(expr))

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


Ptr32<void> fn_800FC7F8(u32);                             /* extern */
M2C_UNK fn_802CC5E0();                              /* extern */
M2C_UNK fn_802CC8EC();                              /* extern */
M2C_UNK fn_802CCBB4();                              /* extern */
M2C_UNK fn_802CD010();                              /* extern */
M2C_UNK fn_802CAFD0();                              /* extern */
M2C_UNK fn_8015B78C(Ptr32<void>);                           /* extern */
M2C_UNK fn_8015B904();                              /* extern */
M2C_UNK fn_8015B9D0();                              /* extern */
M2C_UNK fn_8015CED4();                              /* extern */
M2C_UNK fn_8015CF14(Ptr32<void>, M2C_UNK);                  /* extern */
s32 fn_801FE45C();                                  /* extern */
M2C_UNK fn_8015E900();                              /* extern */
M2C_UNK fn_8016EED0(Ptr32<void>);                           void fn_8015F4C8();                              /* extern */
M2C_UNK fn_801FE1F8(Ptr32<void>);                        /* extern */
M2C_UNK fn_80163754(s32, s32);                      /* extern */
M2C_UNK fn_80164AA8(Ptr32<void>, s32);                      /* extern */
M2C_UNK fn_80162C20();                              void fn_80162C40();                              /* extern */
M2C_UNK fn_80162BA8();                              void fn_80162BC8();                              /* extern */
s32 fn_801625DC(Ptr32<void>, Ptr32<void>);                       /* extern */
M2C_UNK fn_8015FB34();                              /* extern */
M2C_UNK fn_8034B6D8(Ptr32<void>, M2C_UNK);                  /* extern */
M2C_UNK fn_8034BA50(s32);                           /* extern */

s32 w3d_auto_80158f68(void) {
    s32 var_r30;
    u32 var_r31;

    var_r30 = 0;
    var_r31 = 0U;
    do {
        if ((s32) M2C_FIELD(fn_800FC7F8(var_r31), s32 *, 0x48) != 0) {
            var_r30 += 1;
        }
        var_r31 += 1;
    } while (var_r31 <= 3U);
    return var_r30;
}

void w3d_auto_8015ab2c(Ptr32<void> arg0, s32 arg1) {
    if (arg1 != 0) {
        M2C_FIELD(arg0, s32 *, 0x34) = (s32) (M2C_FIELD(arg0, s32 *, 0x34) - 1);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) (M2C_FIELD(arg0, s32 *, 0x34) + 1);
}

s32 w3d_auto_8015b178(void) {
    fn_802CC8EC();
    fn_802CC5E0();
    fn_802CCBB4();
    fn_802CD010();
    return 0x64;
}

void w3d_auto_8015b1a8(void) {
    fn_802CAFD0();
}

s32 w3d_auto_8015b410(Ptr32<Ptr32<s32>> arg0, s32 arg1) {
    return **arg0 + (arg1 * 4);
}

s32 w3d_auto_8015b424(Ptr32<Ptr32<void>> arg0) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg0;
    return (s32) (M2C_FIELD(temp_r9, s32 *, 4) - M2C_FIELD(temp_r9, s32 *, 0)) >> 2;
}

s32 w3d_auto_8015b72c(s32 arg0) {
    fn_8015B904();
    fn_8015B78C(w3d::G(arg0));
    return 0;
}

s32 w3d_auto_8015b764(void) {
    fn_8015B9D0();
    return 0;
}

extern s32 lbl_804B005C;

s32 w3d_auto_8015c3ec(void) {
    return lbl_804B005C;
}

extern s32 lbl_804B005C;

void w3d_auto_8015c3f4(s32 arg0) {
    lbl_804B005C = arg0;
}

s32 w3d_auto_8015cdec(s32 arg0) {
    fn_8015CED4();
    fn_8015CF14(w3d::G(arg0), 0x64);
    return arg0;
}

void w3d_auto_8015ce28(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 0x18) = fn_801FE45C();
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
}

void w3d_auto_8015e0c0(void) {
    fn_8015E900();
}

extern s32 lbl_804B1888;

s32 w3d_auto_8015e564(void) {
    fn_8016EED0(w3d::G(lbl_804B1888));
    return 0;
}

s32 w3d_auto_8015e58c(void) {
    return 0x80004001;
}

s32 w3d_auto_8015f054(void) {
    return 0x80004001;
}

s32 w3d_auto_8015f060(void) {
    return 0x80004001;
}

s32 w3d_auto_8015f06c(void) {
    return 0x80004001;
}

s32 w3d_auto_8015f078(void) {
    return 0x80004001;
}

s32 w3d_auto_8015f084(void) {
    return 0x80004001;
}

void w3d_auto_8015f558(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    fn_8015F4C8();
    if (arg1 & 1) {
        fn_801FE1F8(arg0);
    }
}

s32 w3d_auto_8015fb14(void) {
    return 0x80004001;
}

s32 w3d_auto_8015fb20(void) {
    return 0x80004001;
}

void w3d_auto_8015fc58(Ptr32<void> arg0, s32 arg1) {
    fn_80163754(arg1, M2C_FIELD(arg0, s32 *, 0x14));
}

extern s32 lbl_804B188C;

s32 w3d_auto_8015fd14(void) {
    return lbl_804B188C;
}

extern s32 lbl_804B178C;

void w3d_auto_8015fd1c(Ptr32<void> arg0) {
    fn_80164AA8(w3d::G(lbl_804B178C), M2C_FIELD(arg0, s32 *, 0x14));
}

void w3d_auto_8015ff5c(void) {
    fn_80162C20();
}

void w3d_auto_8015ff7c(void) {
    fn_80162C40();
}

void w3d_auto_80161080(void) {
    fn_80162BA8();
}

void w3d_auto_801610a0(void) {
    fn_80162BC8();
}

extern s32 lbl_804AB4AC;
extern s32 lbl_804AB4B0;
extern s32 lbl_804AB4B4;
extern s32 lbl_804AB4B8;

s32 w3d_auto_80162310(Ptr32<void> arg0) {
    s32 temp_r30;
    s32 var_r3;

    temp_r30 = (M2C_FIELD(arg0, u16 *, 8) & 0xFFFF7FFF) * 0xC;
    var_r3 = fn_801625DC(w3d::G(lbl_804AB4B4 + temp_r30), arg0);
    if (var_r3 < 0) {
        var_r3 = fn_801625DC(w3d::G(lbl_804AB4B8 + temp_r30), arg0);
        if (var_r3 < 0) {
            var_r3 = fn_801625DC(w3d::G(lbl_804AB4AC + temp_r30), arg0);
            if (var_r3 < 0) {
                var_r3 = fn_801625DC(w3d::G(lbl_804AB4B0 + temp_r30), arg0);
            }
        }
    }
    return var_r3;
}

s32 w3d_auto_8016291c(void) {
    return 0x80004001;
}

s32 w3d_auto_80162928(void) {
    return 0x80004001;
}

void w3d_auto_8016293c(void) {
    fn_8015FB34();
}

s32 w3d_auto_801644f4(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 0x38) = 1;
    return 0;
}

s32 w3d_auto_80164504(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    return 0;
}

void w3d_auto_80164f88(Ptr32<void> arg0) {
    s32 temp_r30;

    temp_r30 = M2C_FIELD(arg0, s32 *, 0x1C);
    fn_8034B6D8(w3d::G(temp_r30), 0x0BABE000);
    fn_8034BA50(temp_r30);
}

extern s32 lbl_804B00D0;

void w3d_auto_80165594(s32 arg0) {
    lbl_804B00D0 = arg0;
}

extern s32 lbl_804B00D0;

s32 w3d_auto_8016559c(void) {
    return lbl_804B00D0;
}

extern s32 lbl_804AB4EC;

s32 w3d_auto_801656b4(void) {
    return lbl_804AB4EC;
}

}
