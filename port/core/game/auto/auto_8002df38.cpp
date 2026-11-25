#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "auto_8002df38.c"
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


M2C_UNK fn_8002E59C(Ptr32<void>);                        /* extern */
M2C_UNK fn_8002E670();                              /* extern */
M2C_UNK fn_8015FD1C(Ptr32<void>);                        /* extern */
s32 fn_80181CCC(Ptr32<void>, s32);                          /* extern */
M2C_UNK fn_800306A4();                              /* extern */
M2C_UNK fn_80036540(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void>, float);                           /* extern */
f32 fn_80178DF0(Ptr32<void>);                               /* extern */
Ptr32<void> fn_80165254();                                /* extern */
s16 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
M2C_UNK fn_80162024(Ptr32<void>, Ptr32<s16>, Ptr32<void>);               /* extern */
M2C_UNK fn_8003D0A0(Ptr32<void>);                        /* extern */
M2C_UNK fn_8003E314();                              /* extern */
M2C_UNK fn_8003E370(Ptr32<void>);                           /* extern */
M2C_UNK fn_8012632C(Ptr32<void>, Ptr32<void>);                           /* extern */
M2C_UNK fn_801262E4(Ptr32<void>, Ptr32<void>);                           /* extern */
M2C_UNK fn_80044954(Ptr32<void>, M2C_UNK);               /* extern */
s32 fn_801248CC(Ptr32<void>);                               /* extern */
M2C_UNK fn_80045FA4(Ptr32<void>, s32);                      /* extern */
Ptr32<void> fn_800FC6DC(u32);                             /* extern */
M2C_UNK fn_800490BC();                              /* extern */

s32 w3d_auto_8002df38(Ptr32<void> arg0) {
    fn_8002E670();
    fn_8002E59C(arg0);
    if (fn_80181CCC(w3d::G(M2C_FIELD(arg0, s32 *, 0x2C)), M2C_FIELD(arg0, s32 *, 0x30)) != 0) {
        fn_8015FD1C(arg0);
    }
    return 0;
}

s32 w3d_auto_8002fc88(Ptr32<void> arg0, u32 arg1) {
    if (((s32) M2C_FIELD(arg0, s32 *, 0x44) != 0) && ((s32) M2C_FIELD(arg0, s32 *, 0x48) != 0) && (arg1 >= (u32) M2C_FIELD(arg0, u32 *, 0x4C))) {
        fn_800306A4();
    }
    return 0;
}

void w3d_auto_800359e4(Ptr32<void> arg0, Ptr32<void> arg1, Ptr32<void> arg_r5, Ptr32<void> arg_r6, float arg_f1) {
    f32 temp_f1;

    fn_80036540(arg0 + 0x33C, (Ptr32<void>)arg1, arg_r5, arg_r6, arg_f1);
    temp_f1 = fn_80178DF0(w3d::G(M2C_FIELD(arg0, s32 *, 0x314)));
    if (M2C_FIELD(arg1, f32 *, 4) < temp_f1) {
        M2C_FIELD(arg1, f32 *, 4) = temp_f1;
    }
}

void w3d_auto_80036abc(Ptr32<void> arg0, s32 arg1, s32 arg2, f32 farg0) {
    M2C_FIELD(arg0, s32 *, 0xC) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = arg2;
    M2C_FIELD(arg0, f32 *, 0) = farg0;
    M2C_FIELD(arg0, s32 *, 4) = (s32) M2C_FIELD(fn_80165254(), s32 *, 0x34);
}

void w3d_auto_80036afc(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

s32 w3d_auto_80036c8c(Ptr32<void> arg0) {
    s32 temp_r3;
    s32 var_r11;
    u32 temp_r9;

    temp_r9 = M2C_FIELD(fn_80165254(), u32 *, 0x34);
    var_r11 = 0;
    temp_r3 = M2C_FIELD(arg0, s32 *, 8);
    if ((temp_r3 == -1) || (temp_r9 < (u32) (M2C_FIELD(arg0, s32 *, 4) + temp_r3))) {
        var_r11 = 1;
    }
    return var_r11;
}

extern M2C_UNK lbl_804AD050;
extern M2C_UNK lbl_804AD058;

void w3d_auto_80038240(s32 arg0) {
    s16 sp8;
    s16 spA;

    sp8 = fn_8015F5A0(&lbl_804AD050, 1);
    fn_80162024(w3d::G(arg0), &sp8, w3d::G(arg0 + 0x64));
    spA = fn_8015F5A0(&lbl_804AD058, 1);
    fn_80162024(w3d::G(arg0), &spA, w3d::G(arg0 + 0x68));
}

extern s32 lbl_804AA900;

s32 w3d_auto_8003888c(void) {
    return lbl_804AA900;
}

extern M2C_UNK lbl_804AD060;
extern M2C_UNK lbl_804AD068;
extern M2C_UNK lbl_804AD070;
extern M2C_UNK lbl_804AD078;
extern M2C_UNK lbl_804AD080;
extern M2C_UNK lbl_804AD090;

void w3d_auto_80038d1c(s32 arg0) {
    s16 sp8;
    s16 spA;
    s16 spC;
    s16 spE;
    s16 sp10;
    s16 sp12;

    sp8 = fn_8015F5A0(&lbl_804AD060, 1);
    fn_80162024(w3d::G(arg0), &sp8, w3d::G(arg0 + 0x40));
    spA = fn_8015F5A0(&lbl_804AD070, 1);
    fn_80162024(w3d::G(arg0), &spA, w3d::G(arg0 + 0x44));
    spC = fn_8015F5A0(&lbl_804AD078, 1);
    fn_80162024(w3d::G(arg0), &spC, w3d::G(arg0 + 0x48));
    spE = fn_8015F5A0(&lbl_804AD080, 1);
    fn_80162024(w3d::G(arg0), &spE, w3d::G(arg0 + 0x4C));
    sp10 = fn_8015F5A0(&lbl_804AD068, 1);
    fn_80162024(w3d::G(arg0), &sp10, w3d::G(arg0 + 0x50));
    sp12 = fn_8015F5A0(&lbl_804AD090, 1);
    fn_80162024(w3d::G(arg0), &sp12, w3d::G(arg0 + 0x58));
}

void w3d_auto_8003cdcc(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 0x54) = (s32) (M2C_FIELD(fn_80165254(), s32 *, 0x34) - 0xDAC);
    fn_8003D0A0(arg0);
}

s32 w3d_auto_8003dff8(s32 arg0) {
    fn_8003E314();
    fn_8003E370(w3d::G(arg0));
    return 0x14;
}

void w3d_auto_8003e2bc(s32 arg0, Ptr32<void> arg_r4) {
    fn_8012632C(w3d::G(arg0 + 0x44), arg_r4);
}

void w3d_auto_8003e2e0(s32 arg0, Ptr32<void> arg_r4) {
    fn_801262E4(w3d::G(arg0 + 0x44), arg_r4);
}

extern s32 lbl_804AA958;

void w3d_auto_8003ffac(void) {
    lbl_804AA958 = 0;
}

extern s32 lbl_804AB044;

void w3d_auto_800441c0(Ptr32<void> arg0) {
    s32 var_r30;

    var_r30 = 0;
    if ((s32) lbl_804AB044 != 0) {
        var_r30 = fn_801248CC(w3d::G(lbl_804AB044));
    }
    if (((s32) M2C_FIELD(arg0, s32 *, 0x40) == 0) || ((s32) M2C_FIELD(fn_80165254(), s32 *, 0x38) != 0) || (var_r30 != 0)) {
        fn_80044954(arg0, 0);
        return;
    }
    fn_80044954(arg0, 1);
}

void w3d_auto_80046228(s32 arg0, s32 arg1) {
    u32 var_r31;
    Ptr32<void> temp_r3;

    var_r31 = 0U;
loop_1:
    temp_r3 = fn_800FC6DC(var_r31);
    if (((s32) M2C_FIELD(temp_r3, u8 *, 0xD5) != arg1) || ((s32) M2C_FIELD(temp_r3, s32 *, 0xDC) == 0)) {
        var_r31 += 1;
        if (var_r31 > 0xFU) {
            fn_80045FA4(w3d::G(arg0), arg1);
        } else {
            goto loop_1;
        }
    }
}

void w3d_auto_80048fac(void) {
    fn_800490BC();
}

}
