#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "auto_800155ac.c"
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


Ptr32<void> fn_800FC6DC();                                /* extern */
M2C_UNK fn_80015EB0();                              /* extern */
M2C_UNK fn_80015EF0();                              /* extern */
M2C_UNK fn_80015F14();                              /* extern */
M2C_UNK fn_80342730(Ptr32<void>);                           /* extern */
M2C_UNK fn_8000756C();                              /* extern */
M2C_UNK fn_800172E4();                              /* extern */
M2C_UNK fn_80017444();                              /* extern */
M2C_UNK fn_800174CC();                              /* extern */
M2C_UNK fn_80017380();                              /* extern */
M2C_UNK fn_80017A04();                              /* extern */
s32 fn_800041E0();                                  /* extern */
M2C_UNK fn_8001523C(M2C_UNK);                       /* extern */
M2C_UNK fn_8001CAC4();                              /* extern */
M2C_UNK fn_8001EA34(Ptr32<void>);                        /* extern */
s32 fn_8006E71C();                                  /* extern */
s16 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
M2C_UNK fn_80162024(Ptr32<void>, Ptr32<s16>, Ptr32<void>);               /* extern */
M2C_UNK fn_80022634(Ptr32<void>);                           void fn_800152CC();                              /* extern */
Ptr32<void> fn_80165254();                                /* extern */

u16 w3d_auto_800155ac(void) {
    return M2C_FIELD(fn_800FC6DC(), u16 *, 0xAA);
}

extern s32 lbl_804AA6F8;
extern s32 lbl_804AA6FC;
extern s32 lbl_804AA700;

void w3d_auto_80015e64(void) {
    if ((s32) lbl_804AA6F8 != 0) {
        fn_80015EB0();
    }
    if ((s32) lbl_804AA6FC != 0) {
        fn_80015EF0();
    }
    if ((s32) lbl_804AA700 != 0) {
        fn_80015F14();
    }
}

extern s32 lbl_804AA6FC;

void w3d_auto_80015ef0(void) {
    fn_80342730(w3d::G(lbl_804AA6FC));
}

extern s32 lbl_804AA700;

void w3d_auto_80015f14(void) {
    fn_80342730(w3d::G(lbl_804AA700));
}

extern s32 lbl_804AA70C;

s32 w3d_auto_80016be4(void) {
    return lbl_804AA70C;
}

extern s32 lbl_804AA710;

s32 w3d_auto_80016d04(void) {
    return lbl_804AA710;
}

extern s32 lbl_804AA714;

s32 w3d_auto_80017038(void) {
    return lbl_804AA714;
}

extern s32 lbl_804AA718;

s32 w3d_auto_800171a8(void) {
    return lbl_804AA718;
}

extern s32 lbl_804AA71C;

s32 w3d_auto_800172dc(void) {
    return lbl_804AA71C;
}

void w3d_auto_800172e4(void) {
    fn_8000756C();
}

extern s32 lbl_804AA720;

s32 w3d_auto_80017500(void) {
    return lbl_804AA720;
}

void w3d_auto_8001750c(void) {
    fn_800172E4();
}

void w3d_auto_80017664(void) {
    fn_80017444();
}

void w3d_auto_8001781c(void) {
    fn_800174CC();
}

extern s32 lbl_804AA724;

s32 w3d_auto_8001783c(void) {
    return lbl_804AA724;
}

void w3d_auto_80017848(void) {
    fn_80017380();
}

extern s32 lbl_804AA728;

s32 w3d_auto_80017868(void) {
    return lbl_804AA728;
}

extern s32 lbl_804AA72C;

s32 w3d_auto_800178a8(void) {
    return lbl_804AA72C;
}

extern s32 lbl_804AA730;

s32 w3d_auto_800179fc(void) {
    return lbl_804AA730;
}

extern Ptr32<void> lbl_804AA6D8;

void w3d_auto_80017a04(Ptr32<void> arg0) {
    M2C_FIELD(arg0, f32 *, 4) = (f32) (M2C_FIELD(arg0, f32 *, 4) + M2C_FIELD(lbl_804AA6D8, f32 *, 0xA8));
}

extern s32 lbl_804AA734;

s32 w3d_auto_80017a68(void) {
    return lbl_804AA734;
}

void w3d_auto_80017a70(void) {
    fn_80017A04();
}

extern s32 lbl_804AA738;

s32 w3d_auto_80017b58(void) {
    return lbl_804AA738;
}

void w3d_auto_80017b60(void) {
    fn_8000756C();
}

extern s32 lbl_804AA708;
extern s32 lbl_804AC8A0;
extern s32 lbl_804AC8B0;
extern s32 lbl_804AC8A8;
extern s32 lbl_804AC8AC;
extern s32 lbl_804AC8C0;
extern s32 lbl_804AC8B4;
extern s32 lbl_804AC8B8;
extern s32 lbl_804AC8BC;
extern s32 lbl_804AC8A4;

void w3d_auto_80017d8c(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        lbl_804AC8A0 = lbl_804AA708 + 0x4000;
        lbl_804AC8A8 = lbl_804AA708 + 0x2E0;
        lbl_804AC8AC = lbl_804AA708 + 0x3070;
        lbl_804AC8B4 = lbl_804AA708 + 0x3FF0;
        lbl_804AC8B8 = lbl_804AA708 + 0x3FB0;
        lbl_804AC8BC = lbl_804AA708 + 0x3F30;
        lbl_804AC8A4 = lbl_804AA708;
        lbl_804AC8B0 = lbl_804AA708;
        lbl_804AC8C0 = lbl_804AA708;
    }
}

extern s32 lbl_804AA740;
extern s32 lbl_804AC8C8;
extern s32 lbl_804AC8D8;
extern s32 lbl_804AC8D0;
extern s32 lbl_804AC8D4;
extern s32 lbl_804AC8E8;
extern s32 lbl_804AC8DC;
extern s32 lbl_804AC8E0;
extern s32 lbl_804AC8E4;
extern s32 lbl_804AC8CC;

void w3d_auto_8001a6d0(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        lbl_804AC8C8 = lbl_804AA740 + 0x4000;
        lbl_804AC8D0 = lbl_804AA740 + 0x2E0;
        lbl_804AC8D4 = lbl_804AA740 + 0x3070;
        lbl_804AC8DC = lbl_804AA740 + 0x3FF0;
        lbl_804AC8E0 = lbl_804AA740 + 0x3FB0;
        lbl_804AC8E4 = lbl_804AA740 + 0x3F30;
        lbl_804AC8CC = lbl_804AA740;
        lbl_804AC8D8 = lbl_804AA740;
        lbl_804AC8E8 = lbl_804AA740;
    }
}

extern s32 lbl_804AA788;
extern s32 lbl_804AA794;

void w3d_auto_8001cb40(Ptr32<void> arg0) {
    fn_8001CAC4();
    fn_8001523C(0x806C);
    M2C_FIELD(arg0, s32 *, 0x44) = fn_800041E0();
    lbl_804AA788 = 1;
    M2C_FIELD(arg0, s32 *, 0x94) = 1;
    lbl_804AA794 = 0;
}

s32 w3d_auto_8001ece8(Ptr32<void> arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, Ptr32<void> *, 0x44), s32 *, 0x8014);
}

s32 w3d_auto_8001ed48(Ptr32<void> arg0) {
    if ((fn_8006E71C() == 0) && ((s32) M2C_FIELD(arg0, s32 *, 0x48) != (s32) M2C_FIELD(arg0, s32 *, 0x4C))) {
        fn_8001EA34(arg0);
    }
    return 0xA;
}

extern M2C_UNK lbl_804AC93C;
extern M2C_UNK lbl_804AC944;

void w3d_auto_8001ed98(s32 arg0) {
    s16 sp8;
    s16 spA;

    sp8 = fn_8015F5A0(&lbl_804AC93C, 1);
    fn_80162024(w3d::G(arg0), &sp8, w3d::G(arg0 + 0xAC));
    spA = fn_8015F5A0(&lbl_804AC944, 1);
    fn_80162024(w3d::G(arg0), &spA, w3d::G(arg0 + 0xB0));
}

void w3d_auto_8001eee8(Ptr32<void> arg0) {
    s32 temp_r11;
    s32 temp_r9;
    s32 temp_r9_2;
    s32 temp_r9_3;

    temp_r11 = M2C_FIELD(arg0, s32 *, 0);
    if (temp_r11 == 0) {
        temp_r9 = M2C_FIELD(arg0, s32 *, 0x1C) + 1;
        M2C_FIELD(arg0, s32 *, 0x1C) = temp_r9;
        if (temp_r9 == 2) {
            temp_r9_2 = M2C_FIELD(arg0, s32 *, 0x14) + 1;
            M2C_FIELD(arg0, s32 *, 0x1C) = temp_r11;
            M2C_FIELD(arg0, s32 *, 0x14) = temp_r9_2;
            if (temp_r9_2 > (s32) M2C_FIELD(arg0, s32 *, 8)) {
                temp_r9_3 = M2C_FIELD(arg0, s32 *, 0x18) + 1;
                M2C_FIELD(arg0, s32 *, 0x14) = (s32) M2C_FIELD(arg0, s32 *, 4);
                M2C_FIELD(arg0, s32 *, 0x18) = temp_r9_3;
                if (temp_r9_3 > (s32) M2C_FIELD(arg0, s32 *, 0x10)) {
                    M2C_FIELD(arg0, s32 *, 0) = 1;
                }
            }
        }
    }
}

void w3d_auto_80020b20(Ptr32<void> arg0) {
    fn_80022634(w3d::G(M2C_FIELD(arg0, s32 *, 0x74)));
}

extern s32 lbl_804AA79C;

void w3d_auto_80021050(void) {
    if ((s32) lbl_804AA79C == 2) {
        fn_800152CC();
    }
}

void w3d_auto_800214a4(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 4) = 1;
}

s32 w3d_auto_80021840(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) M2C_FIELD(fn_80165254(), s32 *, 0x34);
    return 0;
}

void w3d_auto_80021878(Ptr32<void> arg0, u32 arg1) {
    if (arg1 > (u32) (M2C_FIELD(arg0, s32 *, 0x14) + M2C_FIELD(arg0, s32 *, 0x18))) {
        M2C_FIELD(arg0, s32 *, 4) = 1;
    }
}

s32 w3d_auto_80021e14(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) M2C_FIELD(fn_80165254(), s32 *, 0x34);
    return 0;
}

void w3d_auto_80022634(Ptr32<void> arg0) {
    s32 temp_r9;
    Ptr32<void> temp_r11;

    temp_r11 = arg0 + 0x1C;
    if ((s32) M2C_FIELD(arg0, s32 *, 0x1C) != (s32) M2C_FIELD(temp_r11, s32 *, 4)) {
        do {
            temp_r9 = M2C_FIELD(temp_r11, s32 *, 4) - 4;
            M2C_FIELD(temp_r11, s32 *, 4) = temp_r9;
        } while ((s32) M2C_FIELD(arg0, s32 *, 0x1C) != temp_r9);
    }
}

extern M2C_UNK lbl_804ACA28;
extern M2C_UNK lbl_804ACA30;
extern M2C_UNK lbl_804ACA38;

void w3d_auto_80022964(s32 arg0) {
    s16 sp8;
    s16 spA;
    s16 spC;

    sp8 = fn_8015F5A0(&lbl_804ACA28, 1);
    fn_80162024(w3d::G(arg0), &sp8, w3d::G(arg0 + 0x28));
    spA = fn_8015F5A0(&lbl_804ACA30, 1);
    fn_80162024(w3d::G(arg0), &spA, w3d::G(arg0 + 0x2C));
    spC = fn_8015F5A0(&lbl_804ACA38, 1);
    fn_80162024(w3d::G(arg0), &spC, w3d::G(arg0 + 0x30));
}

}
