#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "auto_800490bc.c"
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


s32 fn_8015FD1C();                                  /* extern */
s32 fn_80164FC8();                                  /* extern */
Ptr32<void> fn_800FC6DC(s32);                             /* extern */
M2C_UNK fn_8004C51C();                              /* extern */
M2C_UNK fn_8004CDA4(Ptr32<void>, s32);                      /* extern */
M2C_UNK fn_8004C850();                              /* extern */
M2C_UNK fn_801817E0(Ptr32<void>, M2C_UNK);                  void fn_80052008(s32);                           /* extern */
s16 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
M2C_UNK fn_80162024(Ptr32<void>, Ptr32<s16>, Ptr32<void>);               /* extern */
M2C_UNK fn_800D5028();                              /* extern */
M2C_UNK fn_80064D20();                              /* extern */
M2C_UNK fn_800697AC();                              /* extern */
M2C_UNK fn_800FC330(Ptr32<s32>, Ptr32<Ptr32<void>>);                /* extern */
Ptr32<f32> fn_80343BB4(s32, M2C_UNK);                     /* extern */
M2C_UNK fn_80091EE0();                              /* extern */
M2C_UNK fn_8002AD7C(Ptr32<void>);                        /* extern */
M2C_UNK fn_8002AF78();                              /* extern */
M2C_UNK fn_8003DFF8();                              /* extern */
M2C_UNK fn_80098388(Ptr32<void>, s32);                   /* extern */
M2C_UNK fn_800FC1B0(Ptr32<s32>, s32);                    /* extern */

s32 w3d_auto_800490bc(Ptr32<void> arg0) {
    s32 var_r3;

    var_r3 = M2C_FIELD(arg0, s32 *, 0x44);
    if (var_r3 != 0) {
        var_r3 = fn_80164FC8();
        if (var_r3 != 0) {
            var_r3 = fn_8015FD1C();
        }
        M2C_FIELD(arg0, s32 *, 0x44) = 0;
    }
    return var_r3;
}

void w3d_auto_8004c2f0(Ptr32<void> arg0, s32 arg1) {
    s32 temp_r9;
    Ptr32<void> temp_r3;

    temp_r3 = fn_800FC6DC(arg1);
    temp_r9 = M2C_FIELD(arg0, s32 *, 0x88);
    if ((temp_r9 == -1) || (temp_r9 == (s32) M2C_FIELD(temp_r3, u8 *, 0xD5))) {
        if ((s32) M2C_FIELD(arg0, s32 *, 0x78) != 0) {
            M2C_FIELD(arg0, s32 *, 0xA0) = 1;
            return;
        }
        if (((s32) M2C_FIELD(arg0, s32 *, 0x84) == 0) && ((s32) M2C_FIELD(arg0, s32 *, 0x9C) == 0)) {
            M2C_FIELD(arg0, s32 *, 0x50) = arg1;
            M2C_FIELD(arg0, s32 *, 0x9C) = 1;
        }
    }
}

void w3d_auto_8004c814(s32 arg0, s32 arg1) {
    fn_8004C51C();
    fn_8004CDA4(w3d::G(arg0), arg1);
}

void w3d_auto_8004ce38(void) {
    fn_8004C850();
}

void w3d_auto_8004e4f8(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;

    fn_801817E0(w3d::G(M2C_FIELD(arg0, s32 *, 0x1C)), -1);
    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x20);
    M2C_FIELD(*temp_r3, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, M2C_UNK)> *, 0x58)(temp_r3, 0);
}

extern M2C_UNK lbl_804AD478;
extern M2C_UNK lbl_804AD480;

void w3d_auto_80051f94(s32 arg0) {
    s16 sp8;
    s16 spA;

    sp8 = fn_8015F5A0(&lbl_804AD478, 1);
    fn_80162024(w3d::G(arg0), &sp8, w3d::G(arg0 + 0x48));
    spA = fn_8015F5A0(&lbl_804AD480, 1);
    fn_80162024(w3d::G(arg0), &spA, w3d::G(arg0 + 0x4C));
    fn_80052008(arg0);
}

void w3d_auto_80052340(void) {
    fn_800D5028();
}

void w3d_auto_80064d88(Ptr32<void> arg0, s32 arg1) {
    if ((arg1 == 0) && ((s32) M2C_FIELD(arg0, s32 *, 0x58) != 0)) {
        fn_80064D20();
    }
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
}

extern M2C_UNK lbl_804AD5F8;
extern M2C_UNK lbl_804AD600;

void w3d_auto_800681d4(s32 arg0) {
    s16 sp8;
    s16 spA;

    sp8 = fn_8015F5A0(&lbl_804AD5F8, 1);
    fn_80162024(w3d::G(arg0), &sp8, w3d::G(arg0 + 0x20));
    spA = fn_8015F5A0(&lbl_804AD600, 1);
    fn_80162024(w3d::G(arg0), &spA, w3d::G(arg0 + 0x1C));
}

s32 w3d_auto_800689d0(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x70) == 0) {
        return -1;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x18C) != 0) {
        fn_800697AC();
    }
    return 0;
}

void w3d_auto_8006fc24(Ptr32<void> arg0, s32 arg1) {
    s32 sp8;
    Ptr32<void> spC;

    sp8 = arg1;
    fn_800FC330(&sp8, &spC);
    M2C_FIELD(arg0, f32 *, 0x50) = (f32) M2C_FIELD(spC, f32 *, 0x14);
    M2C_FIELD(arg0, f32 *, 0x54) = (f32) M2C_FIELD(spC, f32 *, 0x24);
    M2C_FIELD(arg0, f32 *, 0x58) = (f32) M2C_FIELD(spC, f32 *, 0x18);
    M2C_FIELD(arg0, f32 *, 0x60) = (f32) M2C_FIELD(spC, f32 *, 0x2C);
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) M2C_FIELD(spC, f32 *, 0x28);
    M2C_FIELD(arg0, f32 *, 0x64) = (f32) M2C_FIELD(spC, f32 *, 0x1C);
    M2C_FIELD(arg0, f32 *, 0x68) = (f32) M2C_FIELD(spC, f32 *, 0x20);
    M2C_FIELD(arg0, s32 *, 0x6C) = (s32) M2C_FIELD(spC, s32 *, 0x30);
}

extern M2C_UNK lbl_804AD964;
extern M2C_UNK lbl_804AD96C;

void w3d_auto_80072fe4(s32 arg0) {
    s16 sp8;
    s16 spA;

    sp8 = fn_8015F5A0(&lbl_804AD964, 1);
    fn_80162024(w3d::G(arg0), &sp8, w3d::G(arg0 + 0x20));
    spA = fn_8015F5A0(&lbl_804AD96C, 1);
    fn_80162024(w3d::G(arg0), &spA, w3d::G(arg0 + 0x24));
}

extern s32 lbl_804AAB04;
extern s32 lbl_804AD9B8;
extern s32 lbl_804AD9C8;
extern s32 lbl_804AD9C0;
extern s32 lbl_804AD9C4;
extern s32 lbl_804AD9D8;
extern s32 lbl_804AD9CC;
extern s32 lbl_804AD9D0;
extern s32 lbl_804AD9D4;
extern s32 lbl_804AD9BC;

void w3d_auto_8007bacc(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        lbl_804AD9B8 = lbl_804AAB04 + 0x4000;
        lbl_804AD9C0 = lbl_804AAB04 + 0x2E0;
        lbl_804AD9C4 = lbl_804AAB04 + 0x3070;
        lbl_804AD9CC = lbl_804AAB04 + 0x3FF0;
        lbl_804AD9D0 = lbl_804AAB04 + 0x3FB0;
        lbl_804AD9D4 = lbl_804AAB04 + 0x3F30;
        lbl_804AD9BC = lbl_804AAB04;
        lbl_804AD9C8 = lbl_804AAB04;
        lbl_804AD9D8 = lbl_804AAB04;
    }
}

extern s32 lbl_804AAB0C;
extern s32 lbl_804AD9DC;
extern s32 lbl_804AD9EC;
extern s32 lbl_804AD9E4;
extern s32 lbl_804AD9E8;
extern s32 lbl_804AD9FC;
extern s32 lbl_804AD9F0;
extern s32 lbl_804AD9F4;
extern s32 lbl_804AD9F8;
extern s32 lbl_804AD9E0;

void w3d_auto_8007e910(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        lbl_804AD9DC = lbl_804AAB0C + 0x4000;
        lbl_804AD9E4 = lbl_804AAB0C + 0x2E0;
        lbl_804AD9E8 = lbl_804AAB0C + 0x3070;
        lbl_804AD9F0 = lbl_804AAB0C + 0x3FF0;
        lbl_804AD9F4 = lbl_804AAB0C + 0x3FB0;
        lbl_804AD9F8 = lbl_804AAB0C + 0x3F30;
        lbl_804AD9E0 = lbl_804AAB0C;
        lbl_804AD9EC = lbl_804AAB0C;
        lbl_804AD9FC = lbl_804AAB0C;
    }
}

extern s32 lbl_804AAB14;
extern s32 lbl_804ADA00;
extern s32 lbl_804ADA10;
extern s32 lbl_804ADA08;
extern s32 lbl_804ADA0C;
extern s32 lbl_804ADA20;
extern s32 lbl_804ADA14;
extern s32 lbl_804ADA18;
extern s32 lbl_804ADA1C;
extern s32 lbl_804ADA04;

void w3d_auto_8007ea44(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        lbl_804ADA00 = lbl_804AAB14 + 0x4000;
        lbl_804ADA08 = lbl_804AAB14 + 0x2E0;
        lbl_804ADA0C = lbl_804AAB14 + 0x3070;
        lbl_804ADA14 = lbl_804AAB14 + 0x3FF0;
        lbl_804ADA18 = lbl_804AAB14 + 0x3FB0;
        lbl_804ADA1C = lbl_804AAB14 + 0x3F30;
        lbl_804ADA04 = lbl_804AAB14;
        lbl_804ADA10 = lbl_804AAB14;
        lbl_804ADA20 = lbl_804AAB14;
    }
}

extern s32 lbl_804AAB1C;
extern s32 lbl_804ADA24;
extern s32 lbl_804ADA34;
extern s32 lbl_804ADA2C;
extern s32 lbl_804ADA30;
extern s32 lbl_804ADA44;
extern s32 lbl_804ADA38;
extern s32 lbl_804ADA3C;
extern s32 lbl_804ADA40;
extern s32 lbl_804ADA28;

void w3d_auto_8007eacc(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        lbl_804ADA24 = lbl_804AAB1C + 0x4000;
        lbl_804ADA2C = lbl_804AAB1C + 0x2E0;
        lbl_804ADA30 = lbl_804AAB1C + 0x3070;
        lbl_804ADA38 = lbl_804AAB1C + 0x3FF0;
        lbl_804ADA3C = lbl_804AAB1C + 0x3FB0;
        lbl_804ADA40 = lbl_804AAB1C + 0x3F30;
        lbl_804ADA28 = lbl_804AAB1C;
        lbl_804ADA34 = lbl_804AAB1C;
        lbl_804ADA44 = lbl_804AAB1C;
    }
}

extern s32 lbl_804AAB24;
extern s32 lbl_804ADA48;
extern s32 lbl_804ADA58;
extern s32 lbl_804ADA50;
extern s32 lbl_804ADA54;
extern s32 lbl_804ADA68;
extern s32 lbl_804ADA5C;
extern s32 lbl_804ADA60;
extern s32 lbl_804ADA64;
extern s32 lbl_804ADA4C;

void w3d_auto_8007f1f0(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        lbl_804ADA48 = lbl_804AAB24 + 0x4000;
        lbl_804ADA50 = lbl_804AAB24 + 0x2E0;
        lbl_804ADA54 = lbl_804AAB24 + 0x3070;
        lbl_804ADA5C = lbl_804AAB24 + 0x3FF0;
        lbl_804ADA60 = lbl_804AAB24 + 0x3FB0;
        lbl_804ADA64 = lbl_804AAB24 + 0x3F30;
        lbl_804ADA4C = lbl_804AAB24;
        lbl_804ADA58 = lbl_804AAB24;
        lbl_804ADA68 = lbl_804AAB24;
    }
}

extern s32 lbl_804AAB30;
extern s32 lbl_804ADB58;
extern s32 lbl_804ADB68;
extern s32 lbl_804ADB60;
extern s32 lbl_804ADB64;
extern s32 lbl_804ADB78;
extern s32 lbl_804ADB6C;
extern s32 lbl_804ADB70;
extern s32 lbl_804ADB74;
extern s32 lbl_804ADB5C;

void w3d_auto_80087730(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        lbl_804ADB58 = lbl_804AAB30 + 0x4000;
        lbl_804ADB60 = lbl_804AAB30 + 0x2E0;
        lbl_804ADB64 = lbl_804AAB30 + 0x3070;
        lbl_804ADB6C = lbl_804AAB30 + 0x3FF0;
        lbl_804ADB70 = lbl_804AAB30 + 0x3FB0;
        lbl_804ADB74 = lbl_804AAB30 + 0x3F30;
        lbl_804ADB5C = lbl_804AAB30;
        lbl_804ADB68 = lbl_804AAB30;
        lbl_804ADB78 = lbl_804AAB30;
    }
}

s32 w3d_auto_80090dac(Ptr32<void> arg0) {
    Ptr32<f32> temp_r26;
    Ptr32<f32> temp_r26_2;
    Ptr32<f32> temp_r26_3;
    Ptr32<f32> temp_r29;
    Ptr32<f32> temp_r29_2;
    Ptr32<f32> temp_r29_3;
    s32 temp_r30;
    Ptr32<void> temp_r25;
    Ptr32<void> temp_r27;

    temp_r30 = w3d::H(arg0 + 0x110);
    temp_r27 = arg0 + 0xF8;
    temp_r25 = arg0 + 0x104;
    temp_r26 = fn_80343BB4(temp_r30, 0);
    temp_r29 = fn_80343BB4(temp_r30, 1);
    M2C_FIELD(arg0, f32 *, 0x104) = (f32) ((M2C_FIELD(temp_r27, f32 *, 8) * *fn_80343BB4(temp_r30, 2)) + ((M2C_FIELD(arg0, f32 *, 0xF8) * *temp_r26) + (M2C_FIELD(temp_r27, f32 *, 4) * *temp_r29)));
    temp_r26_2 = fn_80343BB4(temp_r30, 0);
    temp_r29_2 = fn_80343BB4(temp_r30, 1);
    M2C_FIELD(temp_r25, f32 *, 4) = (f32) ((M2C_FIELD(temp_r27, f32 *, 8) * M2C_FIELD(fn_80343BB4(temp_r30, 2), f32 *, 4)) + ((M2C_FIELD(arg0, f32 *, 0xF8) * M2C_FIELD(temp_r26_2, f32 *, 4)) + (M2C_FIELD(temp_r27, f32 *, 4) * M2C_FIELD(temp_r29_2, f32 *, 4))));
    temp_r26_3 = fn_80343BB4(temp_r30, 0);
    temp_r29_3 = fn_80343BB4(temp_r30, 1);
    M2C_FIELD(temp_r25, f32 *, 8) = (f32) ((M2C_FIELD(temp_r27, f32 *, 8) * M2C_FIELD(fn_80343BB4(temp_r30, 2), f32 *, 8)) + ((M2C_FIELD(arg0, f32 *, 0xF8) * M2C_FIELD(temp_r26_3, f32 *, 8)) + (M2C_FIELD(temp_r27, f32 *, 4) * M2C_FIELD(temp_r29_3, f32 *, 8))));
    return 0;
}

void w3d_auto_80092388(Ptr32<void> arg0, s32 arg1, s32 arg2, s32 arg3) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x218) != 0) {
        fn_80091EE0();
    }
    M2C_FIELD(arg0, s32 *, 0x1F8) = arg2;
    M2C_FIELD(arg0, s32 *, 0x1F4) = arg1;
    M2C_FIELD(arg0, s32 *, 0x1FC) = arg3;
    M2C_FIELD(arg0, s32 *, 0x1F0) = (s32) (M2C_FIELD(arg0, s32 *, 0x1E4) + (arg1 * 4) + (arg3 * M2C_FIELD(arg0, u8 *, 0x1EC) * 4));
}

void w3d_auto_80096518(Ptr32<void> arg0) {
    s32 temp_r9;

    temp_r9 = M2C_FIELD(arg0, s32 *, 0x2E8);
    if ((temp_r9 != 0) && ((u32) temp_r9 < (u32) M2C_FIELD(arg0, u32 *, 0x2E4))) {
        fn_8002AF78();
    }
    fn_8002AD7C(arg0);
}

extern s32 lbl_804AABA4;

void w3d_auto_80096da8(void) {
    lbl_804AABA4 = 0;
}

s32 w3d_auto_800981f4(Ptr32<void> arg0, s32 arg1) {
    fn_8003DFF8();
    if ((s32) M2C_FIELD(arg0, u8 *, 0x74) == 2) {
        fn_80098388(arg0, arg1);
    }
    return 0x14;
}

void w3d_auto_8009c820(s32 arg0, s32 arg1) {
    s32 sp8;

    sp8 = arg1;
    fn_800FC1B0(&sp8, arg0 + 0x1C);
}

}
