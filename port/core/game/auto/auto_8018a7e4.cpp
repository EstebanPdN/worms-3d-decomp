#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "auto_8018a7e4.c"
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


M2C_UNK fn_801B14E8(Ptr32<void>, Ptr32<void>);                      /* extern */
s32 fn_8018A864(Ptr32<void>);                               /* extern */
s32 fn_8018C60C(Ptr32<void>, Ptr32<void>);                          /* extern */
M2C_UNK fn_801FE160(s32);                           /* extern */
M2C_UNK fn_802098D8(Ptr32<M2C_UNK>, s32);                /* extern */
M2C_UNK fn_80209920(Ptr32<M2C_UNK>, s32);                /* extern */
M2C_UNK fn_80209968(Ptr32<M2C_UNK>);                     /* extern */
M2C_UNK fn_80198FC4(Ptr32<void>);                        /* extern */
M2C_UNK fn_801990B8();                              /* extern */
M2C_UNK fn_801993F8(Ptr32<void>);                        /* extern */
M2C_UNK fn_8019980C(Ptr32<void>);                        /* extern */
M2C_UNK fn_801998D8(Ptr32<void>);                        /* extern */
M2C_UNK fn_8019A2A8();                              /* extern */
Ptr32<void> fn_802D5B00();                                /* extern */
M2C_UNK fn_802CD7F4(Ptr32<void>);                           /* extern */
M2C_UNK fn_802CE368();                              /* extern */
M2C_UNK fn_801A0338(s32, s32, s32);                 /* extern */
M2C_UNK fn_801A0384(s32, s32, s32, s32);            void fn_801A1008();                              /* extern */
s32 fn_801A1A40();                                  /* extern */
M2C_UNK fn_801FE1D8(M2C_UNK);                       /* extern */
M2C_UNK fn_801A2350();                              /* extern */

extern u16 lbl_804B18AC;

u16 w3d_auto_8018a7e4(void) {
    return lbl_804B18AC;
}

extern u16 lbl_804B18AC;
extern u16 lbl_804B18B8;

u16 w3d_auto_8018a7ec(void) {
    return (u16) (lbl_804B18AC - lbl_804B18B8);
}

extern s32 lbl_804B0254;
extern s32 lbl_804B0258;

s32 w3d_auto_8018b134(Ptr32<void> arg0, s32 arg1) {
    u16 var_r0;

    if (arg1 == 0) {
        fn_801B14E8(w3d::G(M2C_FIELD(arg0, s32 *, 0x24)), w3d::G(lbl_804B0254));
        var_r0 = M2C_FIELD(arg0, u16 *, 0x3C) & 0xFFFE;
    } else {
        fn_801B14E8(w3d::G(M2C_FIELD(arg0, s32 *, 0x24)), w3d::G(lbl_804B0258));
        var_r0 = M2C_FIELD(arg0, u16 *, 0x3C) | 1;
    }
    M2C_FIELD(arg0, u16 *, 0x3C) = var_r0;
    return 0;
}

extern s32 lbl_804B0238;
extern s32 lbl_804B023C;

s32 w3d_auto_8018b198(Ptr32<void> arg0, s32 arg1) {
    u16 var_r0;

    if (arg1 == 0) {
        fn_801B14E8(w3d::G(M2C_FIELD(arg0, s32 *, 0x24)), w3d::G(lbl_804B023C));
        var_r0 = M2C_FIELD(arg0, u16 *, 0x3C) & 0xFFFD;
    } else {
        fn_801B14E8(w3d::G(M2C_FIELD(arg0, s32 *, 0x24)), w3d::G(lbl_804B0238));
        var_r0 = M2C_FIELD(arg0, u16 *, 0x3C) | 2;
    }
    M2C_FIELD(arg0, u16 *, 0x3C) = var_r0;
    return 0;
}

extern s32 lbl_804B0248;
extern s32 lbl_804B024C;

s32 w3d_auto_8018b1fc(Ptr32<void> arg0, s32 arg1) {
    u16 var_r0;

    if (arg1 == 0) {
        fn_801B14E8(w3d::G(M2C_FIELD(arg0, s32 *, 0x24)), w3d::G(lbl_804B0248));
        var_r0 = M2C_FIELD(arg0, u16 *, 0x3C) & 0xFFEF;
    } else {
        fn_801B14E8(w3d::G(M2C_FIELD(arg0, s32 *, 0x24)), w3d::G(lbl_804B024C));
        var_r0 = M2C_FIELD(arg0, u16 *, 0x3C) | 0x10;
    }
    M2C_FIELD(arg0, u16 *, 0x3C) = var_r0;
    return 0;
}

s32 w3d_auto_8018b628(Ptr32<u16> arg0, Ptr32<u16> arg1) {
    return *arg0 - *arg1;
}

s32 w3d_auto_8018c5b0(s32 arg0, s32 arg1) {
    s32 temp_r30;
    s32 temp_r3;
    s32 var_r3;

    temp_r3 = fn_8018A864(w3d::G(arg1));
    var_r3 = 0x80004005;
    if (temp_r3 != 0) {
        temp_r30 = fn_8018C60C(w3d::G(arg0), w3d::G(temp_r3));
        fn_801FE160(temp_r3);
        var_r3 = temp_r30;
    }
    return var_r3;
}

s32 w3d_auto_8018ca1c(Ptr32<void> arg0) {
    return (s32) (M2C_FIELD(arg0, s32 *, 0xB8) - M2C_FIELD(arg0, s32 *, 0xB4)) >> 1;
}

s32 w3d_auto_8018e0bc(Ptr32<void> arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 10) = arg1; /* PPC +8: mitad alta de la palabra de cuenta y etiqueta */
    return 0;
}

void w3d_auto_8018ff8c(Ptr32<void> arg0, Ptr32<s32> arg1) {
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) *arg1;
}

s32 w3d_auto_801903f8(void) {
    return 0x80004001;
}

s32 w3d_auto_80190418(void) {
    return 0x80004001;
}

s32 w3d_auto_8019042c(void) {
    return 0x80004001;
}

s32 w3d_auto_80190478(Ptr32<void> arg0) {
    return ((u32) M2C_FIELD(arg0, u32 *, 0x18) >> 0xFU) & 1;
}

u32 w3d_auto_8019049c(Ptr32<void> arg0) {
    return (u32) M2C_FIELD(arg0, u32 *, 0x1C) >> 0x11U;
}

extern M2C_UNK lbl_804B02B4;

void w3d_auto_801907a8(s32 arg0) {
    fn_802098D8(&lbl_804B02B4, arg0);
}

extern M2C_UNK lbl_804B02B4;

void w3d_auto_801907d0(s32 arg0) {
    fn_80209920(&lbl_804B02B4, arg0);
    fn_80209968(&lbl_804B02B4);
}

s32 w3d_auto_80191ff4(Ptr32<void> arg0, u32 arg1) {
    s32 temp_r11;

    temp_r11 = M2C_FIELD(arg0, s32 *, 0x24);
    if (arg1 < (u32) ((s32) ((M2C_FIELD(arg0, s32 *, 0x28) - temp_r11) * 0x3CF3CF3D) >> 2)) {
        return temp_r11 + (arg1 * 0x54);
    }
    return 0;
}

s32 w3d_auto_80192028(Ptr32<void> arg0, u32 arg1) {
    s32 temp_r9;

    temp_r9 = M2C_FIELD(arg0, s32 *, 0x34);
    if (arg1 < (u32) ((s32) (M2C_FIELD(arg0, s32 *, 0x38) - temp_r9) >> 4)) {
        return temp_r9 + (arg1 * 0x10);
    }
    return 0;
}

s32 w3d_auto_8019216c(Ptr32<void> arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 0x14) + (arg1 * 8);
}

s32 w3d_auto_80195cb0(Ptr32<void> arg0, f32 farg0) {
    M2C_FIELD(arg0, f32 *, 0x14) = farg0;
    return 0;
}

s32 w3d_auto_80195cc4(Ptr32<void> arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 0x28) + (arg1 * 0xC);
}

s32 w3d_auto_80195e80(Ptr32<void> arg0, s32 arg1, f32 farg0, f32 farg1) {
    s32 temp_r4;

    temp_r4 = arg1 * 0xC;
    M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x28) + temp_r4), f32 *, 4) = farg0;
    M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x28) + temp_r4), f32 *, 8) = farg1;
    return 0;
}

void w3d_auto_80198710(Ptr32<void> arg0, s32 arg1) {
    s32 var_ctr;
    Ptr32<void> var_r3;

    var_r3 = arg0;
    var_ctr = 0x50;
    do {
        if ((s32) M2C_FIELD(var_r3, s32 *, 4) == arg1) {
            M2C_FIELD(var_r3, s32 *, 4) = 0;
            M2C_FIELD(var_r3, s32 *, 0xC) = (s32) (M2C_FIELD(var_r3, s32 *, 0xC) & 0x7FFFFFFF);
        }
        var_r3 += 0x10;
        var_ctr -= 1;
    } while (var_ctr != 0);
}

void w3d_auto_80199b0c(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<Ptr32<void>> temp_r3_2;

    fn_801990B8();
    fn_80198FC4(arg0);
    fn_801993F8(arg0);
    fn_8019980C(arg0);
    fn_801998D8(arg0);
    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x14);
    M2C_FIELD(*temp_r3, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, f32)> *, 0x34)(temp_r3, M2C_FIELD(arg0, f32 *, 0x18));
    temp_r3_2 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x14);
    M2C_FIELD(*temp_r3_2, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x2C)(temp_r3_2);
}

void w3d_auto_80199ff0(void) {
    fn_8019A2A8();
}

s32 w3d_auto_8019c5a4(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x30) = arg1;
    return 0;
}

s32 w3d_auto_8019dbc4(Ptr32<void> arg0) {
    Ptr32<void> temp_r3;

    temp_r3 = fn_802D5B00();
    M2C_FIELD(arg0, Ptr32<void> *, 0x14) = temp_r3;
    M2C_FIELD(temp_r3, Ptr32<void> *, 0x58) = arg0;
    return 0;
}

void w3d_auto_801a0304(s32 arg0) {
    fn_802CE368();
    fn_802CD7F4(w3d::G(arg0));
}

void w3d_auto_801a03f0(s32 arg0, Ptr32<void> arg1, s32 arg2) {
    s32 temp_r4;
    s32 temp_r5;
    s32 var_r30;
    Ptr32<void> var_r31;

    if (arg2 > 0) {
        var_r31 = arg1;
        var_r30 = arg2;
        do {
            temp_r4 = M2C_FIELD(var_r31, s32 *, 0);
            temp_r5 = M2C_FIELD(var_r31, s32 *, 4);
            var_r31 += 8;
            fn_801A0338(arg0, temp_r4, temp_r5);
            var_r30 -= 1;
        } while (var_r30 != 0);
    }
}

void w3d_auto_801a0448(s32 arg0, Ptr32<void> arg1, s32 arg2, s32 arg3) {
    s32 temp_r4;
    s32 temp_r5;
    s32 var_r30;
    Ptr32<void> var_r31;

    if (arg2 > 0) {
        var_r31 = arg1;
        var_r30 = arg2;
        do {
            temp_r4 = M2C_FIELD(var_r31, s32 *, 0);
            temp_r5 = M2C_FIELD(var_r31, s32 *, 4);
            var_r31 += 8;
            fn_801A0384(arg0, temp_r4, temp_r5, arg3);
            var_r30 -= 1;
        } while (var_r30 != 0);
    }
}

Ptr32<void> w3d_auto_801a084c(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0xD4) != 0) {
        fn_801A1008();
        M2C_FIELD(arg0, s32 *, 0xD4) = 0;
    }
    return arg0 + 0x14;
}

extern s32 lbl_804AB74C;

s32 w3d_auto_801a188c(void) {
    fn_801FE1D8(0x24);
    lbl_804AB74C = fn_801A1A40();
    return 0;
}

s32 w3d_auto_801a360c(Ptr32<void> arg0, Ptr32<s32> arg1) {
    *arg1 = (s32) (M2C_FIELD(arg0, s32 *, 0x28) - M2C_FIELD(arg0, s32 *, 0x24)) >> 2;
    return M2C_FIELD(arg0, s32 *, 0x24);
}

void w3d_auto_801a3628(void) {
    fn_801A2350();
}

s32 w3d_auto_801a55d4(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
    return 0;
}

s32 w3d_auto_801a6440(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 0x48) = 1;
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    return 0;
}

s32 w3d_auto_801a6530(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x2C) = arg1;
    return 0;
}

s32 w3d_auto_801a766c(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x2C) = arg1;
    return 0;
}

s32 w3d_auto_801a91d8(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 0x11C) = 1;
    return 0;
}

}
