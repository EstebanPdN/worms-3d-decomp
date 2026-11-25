#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "auto_802bd360.c"
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


M2C_UNK fn_802BD354(Ptr32<void>);                        /* extern */
M2C_UNK fn_802BD8CC(Ptr32<void>);                        /* extern */
M2C_UNK fn_802BD4FC();                              /* extern */
M2C_UNK fn_802BFC64();                              /* extern */
s16 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
M2C_UNK fn_80162024(Ptr32<void>, Ptr32<s16>, Ptr32<void>);               /* extern */
M2C_UNK fn_802C68BC();                              /* extern */
M2C_UNK fn_802C76E8(Ptr32<void>);                        /* extern */
M2C_UNK fn_802C7A98(Ptr32<void>);                        /* extern */
M2C_UNK fn_802C7D24(Ptr32<void>);                        /* extern */
M2C_UNK fn_802C7C1C();                              /* extern */
M2C_UNK fn_802C7E20(Ptr32<void>);                        /* extern */
M2C_UNK fn_802CCBFC(u32);                           /* extern */
s32 fn_802EF9C0(Ptr32<void>);                               /* extern */
s32 fn_802DDBD8();                                  /* extern */
M2C_UNK fn_802DDCC0(s32, s32);                      /* extern */
M2C_UNK fn_801FE1D8(M2C_UNK);                       /* extern */
M2C_UNK fn_802E0238();                              /* extern */

void w3d_auto_802bd360(Ptr32<void> arg0, f32 farg0, f32 farg1) {
    s32 var_r0;

    var_r0 = 0;
    if (M2C_FIELD(arg0, f32 *, 0x3C) != farg0) {
        M2C_FIELD(arg0, f32 *, 0x3C) = farg0;
        var_r0 = 1;
    }
    if (M2C_FIELD(arg0, f32 *, 0x40) != farg1) {
        M2C_FIELD(arg0, f32 *, 0x40) = farg1;
        var_r0 = 1;
    }
    if (var_r0 == 1) {
        fn_802BD8CC(arg0);
    }
    fn_802BD354(arg0);
}

void w3d_auto_802bfb2c(Ptr32<void> arg0, s32 arg1) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x20) != arg1) {
        M2C_FIELD(arg0, s32 *, 0x20) = arg1;
        if ((s32) M2C_FIELD(arg0, s32 *, 0x14) != 0) {
            fn_802BD4FC();
        }
    }
}

void w3d_auto_802bfb68(Ptr32<void> arg0, f32 farg0) {
    if (M2C_FIELD(arg0, f32 *, 0x24) != farg0) {
        M2C_FIELD(arg0, f32 *, 0x24) = farg0;
        if ((s32) M2C_FIELD(arg0, s32 *, 0x14) != 0) {
            fn_802BD4FC();
        }
    }
}

void w3d_auto_802c0cb4(Ptr32<void> arg0, s32 arg1) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x80) != arg1) {
        M2C_FIELD(arg0, s32 *, 0x80) = arg1;
        if ((s32) M2C_FIELD(arg0, s32 *, 0x14) != 0) {
            fn_802BFC64();
        }
    }
}

extern M2C_UNK lbl_804B1070;
extern M2C_UNK lbl_804B1078;
extern M2C_UNK lbl_804B1080;
extern M2C_UNK lbl_804B1088;
extern M2C_UNK lbl_804B1090;
extern M2C_UNK lbl_804B1098;

void w3d_auto_802c37e4(s32 arg0) {
    s16 sp8;
    s16 spA;
    s16 spC;
    s16 spE;
    s16 sp10;
    s16 sp12;

    sp8 = fn_8015F5A0(&lbl_804B1070, 1);
    fn_80162024(w3d::G(arg0), &sp8, w3d::G(arg0 + 0x154));
    spA = fn_8015F5A0(&lbl_804B1078, 1);
    fn_80162024(w3d::G(arg0), &spA, w3d::G(arg0 + 0x158));
    spC = fn_8015F5A0(&lbl_804B1080, 1);
    fn_80162024(w3d::G(arg0), &spC, w3d::G(arg0 + 0x15C));
    spE = fn_8015F5A0(&lbl_804B1088, 1);
    fn_80162024(w3d::G(arg0), &spE, w3d::G(arg0 + 0x160));
    sp10 = fn_8015F5A0(&lbl_804B1090, 1);
    fn_80162024(w3d::G(arg0), &sp10, w3d::G(arg0 + 0x164));
    sp12 = fn_8015F5A0(&lbl_804B1098, 1);
    fn_80162024(w3d::G(arg0), &sp12, w3d::G(arg0 + 0x168));
}

void w3d_auto_802c4a60(Ptr32<void> arg0, s32 arg1) {
    if (arg1 != 0) {
        M2C_FIELD(arg0, s32 *, 0x16C) = arg1;
    }
}

void w3d_auto_802c688c(Ptr32<void> arg0, s32 arg1) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x28) != arg1) {
        M2C_FIELD(arg0, s32 *, 0x28) = arg1;
        fn_802C68BC();
    }
}

void w3d_auto_802c7278(Ptr32<void> arg0, f32 farg0, f32 farg1) {
    if ((M2C_FIELD(arg0, f32 *, 0x7C) != farg0) || (M2C_FIELD(arg0, f32 *, 0x80) != farg1)) {
        M2C_FIELD(arg0, f32 *, 0x7C) = farg0;
        M2C_FIELD(arg0, f32 *, 0x80) = farg1;
        if ((s32) M2C_FIELD(arg0, s32 *, 0x6C) == 1) {
            fn_802C76E8(arg0);
            fn_802C7A98(arg0);
            fn_802C7D24(arg0);
        }
    }
}

void w3d_auto_802c7bec(Ptr32<void> arg0, s32 arg1) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x68) != arg1) {
        M2C_FIELD(arg0, s32 *, 0x68) = arg1;
        fn_802C7C1C();
    }
}

void w3d_auto_802c7cec(Ptr32<void> arg0, s32 arg1, f32 farg0, f32 farg1) {
    M2C_FIELD(arg0, s32 *, 0x44) = 1;
    M2C_FIELD(arg0, f32 *, 0x48) = farg0;
    M2C_FIELD(arg0, f32 *, 0x4C) = farg1;
    M2C_FIELD(arg0, s32 *, 0x50) = arg1;
    fn_802C7E20(arg0);
}

void w3d_auto_802c813c(Ptr32<void> arg0, s32 arg1) {
    if (arg1 <= 1) {
        M2C_FIELD(arg0, s32 *, 0x54) = arg1;
    }
}

void w3d_auto_802c814c(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 0x58) = 5;
}

extern s32 lbl_804ABCE4;

void w3d_auto_802ccbb4(void) {
    u32 var_r31;

    if ((s32) lbl_804ABCE4 != 0) {
        var_r31 = 0U;
        do {
            fn_802CCBFC(var_r31);
            var_r31 += 1;
        } while (var_r31 <= 0xFU);
    }
}

extern s32 lbl_804ABCE0;
extern s32 lbl_804ABCE4;

void w3d_auto_802cd0c8(Ptr32<Ptr32<void>> arg0) {
    s32 temp_r30;
    Ptr32<void> temp_r29;

    if ((s32) lbl_804ABCE4 != 0) {
        temp_r30 = lbl_804ABCE0;
        temp_r29 = *arg0;
        M2C_FIELD(temp_r29, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32, M2C_UNK)> *, 0x18)(arg0, temp_r30, fn_802EF9C0(w3d::G(temp_r30)), 0);
    }
}

void w3d_auto_802ddd14(s32 arg0) {
    fn_802DDCC0(arg0, fn_802DDBD8());
}

void w3d_auto_802e0210(void) {
    fn_801FE1D8(0x58);
    fn_802E0238();
}

s32 w3d_auto_802e0f14(Ptr32<void> arg0) {
    Ptr32<void> temp_r9;

    temp_r9 = M2C_FIELD(arg0, Ptr32<void> *, 4);
    if ((s32) M2C_FIELD(temp_r9, s32 *, 0xA0) != 0) {
        return M2C_FIELD(temp_r9, s32 *, 0x50);
    }
    return 0;
}

void w3d_auto_802e0f30(Ptr32<void> arg0, Ptr32<s32> arg1, Ptr32<s32> arg2) {
    s32 temp_r0;
    Ptr32<void> temp_r9;

    temp_r9 = M2C_FIELD(arg0, Ptr32<void> *, 4);
    temp_r0 = M2C_FIELD(temp_r9, s32 *, 0xA0);
    if (temp_r0 != 0) {
        *arg1 = M2C_FIELD(temp_r9, s32 *, 0x80);
        *arg2 = M2C_FIELD(M2C_FIELD(arg0, Ptr32<void> *, 4), s32 *, 0x84);
        return;
    }
    *arg1 = temp_r0;
    *arg2 = temp_r0;
}

void w3d_auto_802e1710(Ptr32<void> arg0) {
    M2C_FIELD(M2C_FIELD(arg0, Ptr32<void> *, 4), s32 *, 0xA8) = 1;
}

void w3d_auto_802e1720(Ptr32<void> arg0) {
    M2C_FIELD(M2C_FIELD(arg0, Ptr32<void> *, 4), s32 *, 0xA8) = 0;
}

void w3d_auto_802e220c(Ptr32<void> arg0) {
    s32 temp_r11;
    Ptr32<void> temp_r9;
    Ptr32<void> temp_r9_2;

    temp_r9 = M2C_FIELD(arg0, Ptr32<void> *, 4);
    temp_r11 = M2C_FIELD(temp_r9, s32 *, 0xDC);
    if (temp_r11 != 0) {
        M2C_FIELD(temp_r9, s32 *, 0xDC) = (s32) (temp_r11 - 1);
        temp_r9_2 = M2C_FIELD(arg0, Ptr32<void> *, 4);
        M2C_FIELD(temp_r9_2, f32 *, 0xD0) = (f32) (M2C_FIELD(temp_r9_2, f32 *, 0xD0) + M2C_FIELD(temp_r9_2, f32 *, 0xD8));
        return;
    }
    M2C_FIELD(temp_r9, f32 *, 0xD0) = (f32) M2C_FIELD(temp_r9, f32 *, 0xD4);
}

s32 w3d_auto_802e2d38(void) {
    return 0x80004001;
}

s32 w3d_auto_802e2d44(void) {
    return 0x80004001;
}

s32 w3d_auto_802e2d50(void) {
    return 0x80004001;
}

s32 w3d_auto_802e2d5c(void) {
    return 0x80004001;
}

s32 w3d_auto_802e2d70(void) {
    return 0x80004001;
}

s32 w3d_auto_802e2d7c(void) {
    return 0x80004001;
}

s32 w3d_auto_802e2d88(void) {
    return 0x80004001;
}

s32 w3d_auto_802e2d94(void) {
    return 0x80004001;
}

s32 w3d_auto_802e2da0(void) {
    return 0x80004001;
}

s32 w3d_auto_802e2dac(void) {
    return 0x80004001;
}

s32 w3d_auto_802e2db8(void) {
    return 0x80004001;
}

s32 w3d_auto_803446e0(s32 arg0) {
    return arg0 - 4;
}

s32 w3d_auto_80344ba8(Ptr32<void> arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 4) + (arg1 * 0xB8);
}

s32 w3d_auto_80344bb8(Ptr32<void> arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 4) + (arg1 * 0xB8);
}

s32 w3d_auto_80344c6c(Ptr32<void> arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 4) + (arg1 * 0xB0);
}

s32 w3d_auto_80344c7c(Ptr32<void> arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 4) + (arg1 * 0xB0);
}

s32 w3d_auto_80344d30(Ptr32<void> arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 4) + (arg1 * 0x74);
}

s32 w3d_auto_80344d40(Ptr32<void> arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 4) + (arg1 * 0x74);
}

s32 w3d_auto_80348700(void) {
    return 0x80004001;
}

}
