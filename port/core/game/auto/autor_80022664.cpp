#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autor_80022664.c"
/* Decompiled automatically by m2c (ppc-gcc-c), recompiled with the NULL-defining
 * prelude by tools/m2c_repair.py, and verified identical to the original after
 * linking. Types and names are m2c placeholders pending review. */
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

#define NULL ((void *)0)

Ptr32<void> fn_80165254();                                /* extern */
Ptr32<void> fn_80164FC8(s32);                             /* extern */
M2C_UNK fn_80182410(Ptr32<void>, s32);                      /* extern */
M2C_UNK fn_802EEE50(Ptr32<void>, Ptr32<void>, u32);                 /* extern */
s32 fn_802E4D04(s32, s32, M2C_UNK);                 /* extern */
M2C_UNK fn_802134FC(Ptr32<void>);                        /* extern */

void w3d_auto_80022664(Ptr32<void> arg0) {
    Ptr32<s32> temp_r9_2;
    s32 temp_r0;
    s32 temp_r9_3;
    Ptr32<void> temp_r11;
    Ptr32<void> temp_r9;

    temp_r11 = arg0 + 0x1C;
    if ((s32) M2C_FIELD(arg0, s32 *, 0x1C) == (s32) M2C_FIELD(temp_r11, s32 *, 4)) {
        goto block_9;
    }
loop_1:
    temp_r9 = *M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x1C);
    temp_r0 = M2C_FIELD(temp_r9, s32 *, 0xC);
    if (temp_r0 == 5) {
        goto block_4;
    }
    if (temp_r0 != 0x11) {
        goto block_6;
    }
    return;
block_4:
    temp_r9_2 = *M2C_FIELD(temp_r9, Ptr32<Ptr32<s32>> *, 0x14);
    if (temp_r9_2 == NULL) {
        goto block_6;
    }
    if ((s32) *temp_r9_2 == 0xB) {
        goto block_9;
    }
block_6:
    temp_r9_3 = M2C_FIELD(temp_r11, s32 *, 4) - 4;
    M2C_FIELD(temp_r11, s32 *, 4) = temp_r9_3;
    if ((s32) M2C_FIELD(arg0, s32 *, 0x1C) != temp_r9_3) {
        goto loop_1;
    }
    return;
block_9:
    return;
}

void w3d_auto_8006f0dc(Ptr32<void> arg0) {
    u32 temp_r30;
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<Ptr32<void>> temp_r3_2;
    Ptr32<Ptr32<void>> temp_r3_3;

    if ((void **) M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x100) == NULL) {
        goto block_6;
    }
    temp_r30 = M2C_FIELD(fn_80165254(), u32 *, 0x34);
    if (temp_r30 <= (u32) M2C_FIELD(arg0, u32 *, 0x104)) {
        goto block_6;
    }
    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x100);
    if (M2C_FIELD(*temp_r3, Ptr32<s32 (Ptr32<Ptr32<void>>)> *, 0x70)(temp_r3) == 0) {
        goto block_4;
    }
    temp_r3_2 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x100);
    M2C_FIELD(*temp_r3_2, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, M2C_UNK)> *, 0x58)(temp_r3_2, 0);
    goto block_5;
block_4:
    temp_r3_3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x100);
    M2C_FIELD(*temp_r3_3, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, M2C_UNK)> *, 0x58)(temp_r3_3, 1);
block_5:
    M2C_FIELD(arg0, u32 *, 0x104) = (u32) (temp_r30 + 0x2EE);
block_6:
    return;
}

void w3d_auto_801399b4(Ptr32<void> arg0, s32 arg1) {
    Ptr32<void> temp_r3;

    temp_r3 = fn_80164FC8(arg1);
    if (temp_r3 == NULL) {
        goto block_2;
    }
    fn_80182410(w3d::G(M2C_FIELD(temp_r3, s32 *, 0x60)), M2C_FIELD(arg0, s32 *, 0x258));
    fn_80182410(w3d::G(M2C_FIELD(temp_r3, s32 *, 0x64)), M2C_FIELD(arg0, s32 *, 0x254));
block_2:
    return;
}

s32 w3d_auto_80178ad4(Ptr32<void> arg0, Ptr32<void> arg1) {
    Ptr32<void> temp_r0;
    Ptr32<void> var_r10;
    Ptr32<void> var_r11;

    temp_r0 = M2C_FIELD(arg0, Ptr32<void> *, 0xC);
    if (temp_r0 != NULL) {
        goto block_2;
    }
    return 0x80004005;
block_2:
    if (temp_r0 != arg1) {
        goto block_5;
    }
    M2C_FIELD(arg0, Ptr32<void> *, 0xC) = (void *) M2C_FIELD(arg1, Ptr32<void> *, 0xC);
    M2C_FIELD(arg1, Ptr32<void> *, 0xC) = NULL;
    return 0;
block_4:
    M2C_FIELD(var_r10, Ptr32<void> *, 0xC) = (void *) M2C_FIELD(var_r11, Ptr32<void> *, 0xC);
    M2C_FIELD(var_r11, Ptr32<void> *, 0xC) = NULL;
    return 0;
block_5:
    var_r10 = temp_r0;
    var_r11 = M2C_FIELD(var_r10, Ptr32<void> *, 0xC);
    if (var_r11 == NULL) {
        goto block_8;
    }
loop_6:
    if (var_r11 == arg1) {
        goto block_4;
    }
    var_r10 = var_r11;
    var_r11 = M2C_FIELD(var_r11, Ptr32<void> *, 0xC);
    if (var_r11 != NULL) {
        goto loop_6;
    }
block_8:
    return 0x80004005;
}

s32 w3d_auto_80178b5c(Ptr32<void> arg0) {
    s32 temp_r3;
    s32 var_r29;
    Ptr32<void> var_r31;

    var_r29 = 0;
    var_r31 = M2C_FIELD(arg0, Ptr32<void> *, 0xC);
    if (var_r31 == NULL) {
        goto block_4;
    }
loop_1:
    temp_r3 = M2C_FIELD(var_r31, Ptr32<s32 (Ptr32<void>, s32)> *, 4)(arg0, M2C_FIELD(var_r31, s32 *, 0x10));
    if (temp_r3 >= 0) {
        goto block_3;
    }
    var_r29 = temp_r3;
block_3:
    var_r31 = M2C_FIELD(var_r31, Ptr32<void> *, 0xC);
    if (var_r31 != NULL) {
        goto loop_1;
    }
block_4:
    return var_r29;
}

extern Ptr32<M2C_UNK> lbl_804B05D8;

void w3d_auto_801fc86c(Ptr32<M2C_UNK> arg0) {
    Ptr32<M2C_UNK> var_r9;

    var_r9 = arg0;
    if (arg0 == NULL) {
        goto block_4;
    }
    if (w3d::G((s32) *arg0) == NULL) {
        goto block_4;
    }
loop_2:
    var_r9 = w3d::G(*var_r9);
    if (var_r9 == NULL) {
        goto block_4;
    }
    if (w3d::G((s32) *var_r9) != NULL) {
        goto loop_2;
    }
block_4:
    *var_r9 = w3d::H(lbl_804B05D8);
    lbl_804B05D8 = arg0;
    return;
}

s32 w3d_auto_80208d30(Ptr32<void> arg0, s32 arg1, u32 arg2, Ptr32<u32> arg3) {
    s32 temp_r9;
    u32 temp_r0;
    u32 var_r30;

    var_r30 = arg2;
    temp_r9 = M2C_FIELD(arg0, s32 *, 0x1C);
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x20) - temp_r9;
    if (var_r30 <= temp_r0) {
        goto block_2;
    }
    var_r30 = temp_r0;
block_2:
    fn_802EEE50(w3d::G(arg1), w3d::G(M2C_FIELD(arg0, s32 *, 0x14) + temp_r9), var_r30);
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) (M2C_FIELD(arg0, s32 *, 0x1C) + var_r30);
    if (arg3 == NULL) {
        goto block_4;
    }
    *arg3 = var_r30;
block_4:
    return 0;
}

void w3d_auto_80209720(Ptr32<Ptr32<void>> arg0) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg0;
    if (temp_r9 == NULL) {
        goto block_2;
    }
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<void>)> *, 0x14)(temp_r9);
block_2:
    return;
}

void w3d_auto_80209de4(Ptr32<void> arg0) {
    Ptr32<void> var_r9;

    var_r9 = M2C_FIELD(arg0, Ptr32<void> *, 4);
    if (var_r9 == NULL) {
        goto block_4;
    }
loop_1:
    M2C_FIELD(var_r9, s32 *, 0xC) = (s32) M2C_FIELD(var_r9, s32 *, 4);
    var_r9 = M2C_FIELD(var_r9, Ptr32<void> *, 0);
    if (var_r9 != NULL) {
        goto loop_1;
    }
    return;
block_4:
    return;
}

s32 w3d_auto_8020c5cc(Ptr32<Ptr32<u8>> arg0) {
    s32 var_r11;
    s32 var_r9;
    Ptr32<u8> temp_r3;

    temp_r3 = *arg0;
    var_r9 = 0;
    var_r11 = 0;
    if (temp_r3 != NULL) {
        goto block_2;
    }
    return 0;
block_2:
    if ((s32) *temp_r3 == 0) {
        goto block_6;
    }
loop_3:
    if ((s32) (*(temp_r3 + var_r9) & 0xC0) == 0x80) {
        goto block_5;
    }
    var_r11 += 1;
block_5:
    var_r9 += 1;
    if ((s32) *(temp_r3 + var_r9) != 0) {
        goto loop_3;
    }
block_6:
    return var_r11;
}

s32 w3d_auto_80215f2c(Ptr32<void> arg0, Ptr32<void> arg1) {
    s32 temp_r0;
    s32 var_r3;
    u32 temp_r10;
    Ptr32<void> temp_r7;
    Ptr32<void> var_r11;
    Ptr32<void> var_r8;

    temp_r7 = M2C_FIELD(arg0, Ptr32<void> *, 0x30);
    temp_r0 = M2C_FIELD(temp_r7, s32 *, 0);
    if (!(temp_r0 & 0x2000)) {
        goto block_2;
    }
    return -1;
block_2:
    var_r8 = M2C_FIELD(temp_r7, Ptr32<void> *, 0xC);
    M2C_FIELD(temp_r7, s32 *, 0) = (s32) (temp_r0 | 0x2000);
    var_r3 = -1;
    if (var_r8 == NULL) {
        goto block_11;
    }
loop_3:
    var_r11 = var_r8 + 0x20;
    temp_r10 = M2C_FIELD(var_r8, s32 *, 0x10) - 8;
    if (arg1 <= var_r11) {
        goto block_10;
    }
    if (arg1 >= w3d::G(temp_r10)) {
        goto block_10;
    }
    if (var_r11 >= w3d::G(temp_r10)) {
        goto block_10;
    }
loop_6:
    if (w3d::G((s32) w3d::H(arg1)) != (Ptr32<void>) (var_r11 + 0x18)) {
        goto block_9;
    }
    if ((s32) (M2C_FIELD(var_r11, s32 *, 4) & 5) != 1) {
        goto block_11;
    }
    var_r3 = M2C_FIELD(arg1, s32 *, -0xC);
    goto block_11;
block_9:
    var_r11 += (M2C_FIELD(var_r11, s32 *, 4) & 0xFFFFFFF8) + 8;
    if (var_r11 < w3d::G(temp_r10)) {
        goto loop_6;
    }
block_10:
    var_r8 = M2C_FIELD(var_r8, Ptr32<void> *, 4);
    if (var_r8 != NULL) {
        goto loop_3;
    }
block_11:
    M2C_FIELD(temp_r7, s32 *, 0) = (s32) (M2C_FIELD(temp_r7, s32 *, 0) & 0xFFFFDFFF);
    return var_r3;
}

s32 w3d_auto_802190d4(Ptr32<void> arg0, s32 arg1, s32 arg2, Ptr32<s32> arg3) {
    M2C_UNK var_r5;

    if (arg3 == NULL) {
        goto block_2;
    }
    *arg3 = fn_802E4D04(M2C_FIELD(arg0, s32 *, 0x18), 0, 1);
block_2:
    if (arg2 == 1) {
        goto block_8;
    }
    if (arg2 > 1) {
        goto block_6;
    }
    if (arg2 == 0) {
        goto block_10;
    }
    goto block_11;
block_6:
    if (arg2 == 2) {
        goto block_9;
    }
    goto block_11;
block_8:
    var_r5 = 1;
    goto block_12;
block_9:
    var_r5 = 2;
    goto block_12;
block_10:
    var_r5 = 0;
    goto block_12;
block_11:
    return 0x80070057;
block_12:
    fn_802E4D04(M2C_FIELD(arg0, s32 *, 0x18), arg1, var_r5);
    return 0;
}

void w3d_auto_80351ea0(s32 arg0, Ptr32<void> arg1) {
    Ptr32<void> temp_r30;
    Ptr32<void> var_r31;

    var_r31 = arg1;
    if (var_r31 == NULL) {
        goto block_4;
    }
loop_1:
    w3d_auto_80351ea0(arg0, M2C_FIELD(var_r31, Ptr32<void> *, 0xC));
    temp_r30 = M2C_FIELD(var_r31, Ptr32<void> *, 8);
    if (var_r31 == NULL) {
        goto block_3;
    }
    fn_802134FC(var_r31);
block_3:
    var_r31 = temp_r30;
    if (var_r31 != NULL) {
        goto loop_1;
    }
block_4:
    return;
}

void w3d_auto_80351f50(Ptr32<void> arg0, Ptr32<Ptr32<void>> arg1) {
    Ptr32<void> temp_r11;
    Ptr32<void> temp_r9;
    Ptr32<void> temp_r9_2;

    temp_r11 = M2C_FIELD(arg0, Ptr32<void> *, 0xC);
    M2C_FIELD(arg0, Ptr32<void> *, 0xC) = (void *) M2C_FIELD(temp_r11, Ptr32<void> *, 8);
    temp_r9 = M2C_FIELD(temp_r11, Ptr32<void> *, 8);
    if (temp_r9 == NULL) {
        goto block_2;
    }
    M2C_FIELD(temp_r9, Ptr32<void> *, 4) = arg0;
block_2:
    M2C_FIELD(temp_r11, Ptr32<void> *, 4) = (void *) M2C_FIELD(arg0, Ptr32<void> *, 4);
    if (arg0 != (Ptr32<void>) *arg1) {
        goto block_4;
    }
    *arg1 = temp_r11;
    goto block_7;
block_4:
    temp_r9_2 = M2C_FIELD(arg0, Ptr32<void> *, 4);
    if (arg0 != (void *) M2C_FIELD(temp_r9_2, Ptr32<void> *, 8)) {
        goto block_6;
    }
    M2C_FIELD(temp_r9_2, Ptr32<void> *, 8) = temp_r11;
    goto block_7;
block_6:
    M2C_FIELD(temp_r9_2, Ptr32<void> *, 0xC) = temp_r11;
block_7:
    M2C_FIELD(temp_r11, Ptr32<void> *, 8) = arg0;
    M2C_FIELD(arg0, Ptr32<void> *, 4) = temp_r11;
    return;
}

void w3d_auto_80351fb0(Ptr32<void> arg0, Ptr32<Ptr32<void>> arg1) {
    Ptr32<void> temp_r11;
    Ptr32<void> temp_r9;
    Ptr32<void> temp_r9_2;

    temp_r11 = M2C_FIELD(arg0, Ptr32<void> *, 8);
    M2C_FIELD(arg0, Ptr32<void> *, 8) = (void *) M2C_FIELD(temp_r11, Ptr32<void> *, 0xC);
    temp_r9 = M2C_FIELD(temp_r11, Ptr32<void> *, 0xC);
    if (temp_r9 == NULL) {
        goto block_2;
    }
    M2C_FIELD(temp_r9, Ptr32<void> *, 4) = arg0;
block_2:
    M2C_FIELD(temp_r11, Ptr32<void> *, 4) = (void *) M2C_FIELD(arg0, Ptr32<void> *, 4);
    if (arg0 != (Ptr32<void>) *arg1) {
        goto block_4;
    }
    *arg1 = temp_r11;
    goto block_7;
block_4:
    temp_r9_2 = M2C_FIELD(arg0, Ptr32<void> *, 4);
    if (arg0 != (void *) M2C_FIELD(temp_r9_2, Ptr32<void> *, 0xC)) {
        goto block_6;
    }
    M2C_FIELD(temp_r9_2, Ptr32<void> *, 0xC) = temp_r11;
    goto block_7;
block_6:
    M2C_FIELD(temp_r9_2, Ptr32<void> *, 8) = temp_r11;
block_7:
    M2C_FIELD(temp_r11, Ptr32<void> *, 0xC) = arg0;
    M2C_FIELD(arg0, Ptr32<void> *, 4) = temp_r11;
    return;
}

void w3d_auto_80352f34(s32 arg0, Ptr32<void> arg1) {
    Ptr32<void> temp_r30;
    Ptr32<void> var_r31;

    var_r31 = arg1;
    if (var_r31 == NULL) {
        goto block_4;
    }
loop_1:
    w3d_auto_80352f34(arg0, M2C_FIELD(var_r31, Ptr32<void> *, 0xC));
    temp_r30 = M2C_FIELD(var_r31, Ptr32<void> *, 8);
    if (var_r31 == NULL) {
        goto block_3;
    }
    fn_802134FC(var_r31);
block_3:
    var_r31 = temp_r30;
    if (var_r31 != NULL) {
        goto loop_1;
    }
block_4:
    return;
}

void w3d_auto_80355800(s32 arg0, Ptr32<void> arg1) {
    Ptr32<void> temp_r30;
    Ptr32<void> var_r31;

    var_r31 = arg1;
    if (var_r31 == NULL) {
        goto block_4;
    }
loop_1:
    w3d_auto_80355800(arg0, M2C_FIELD(var_r31, Ptr32<void> *, 0xC));
    temp_r30 = M2C_FIELD(var_r31, Ptr32<void> *, 8);
    if (var_r31 == NULL) {
        goto block_3;
    }
    fn_802134FC(var_r31);
block_3:
    var_r31 = temp_r30;
    if (var_r31 != NULL) {
        goto loop_1;
    }
block_4:
    return;
}

void w3d_auto_8035b2d4(s32 arg0, Ptr32<void> arg1) {
    Ptr32<void> temp_r30;
    Ptr32<void> var_r31;

    var_r31 = arg1;
    if (var_r31 == NULL) {
        goto block_4;
    }
loop_1:
    w3d_auto_8035b2d4(arg0, M2C_FIELD(var_r31, Ptr32<void> *, 0xC));
    temp_r30 = M2C_FIELD(var_r31, Ptr32<void> *, 8);
    if (var_r31 == NULL) {
        goto block_3;
    }
    fn_802134FC(var_r31);
block_3:
    var_r31 = temp_r30;
    if (var_r31 != NULL) {
        goto loop_1;
    }
block_4:
    return;
}

void w3d_auto_8035b84c(s32 arg0, Ptr32<void> arg1) {
    Ptr32<void> temp_r30;
    Ptr32<void> var_r31;

    var_r31 = arg1;
    if (var_r31 == NULL) {
        goto block_4;
    }
loop_1:
    w3d_auto_8035b84c(arg0, M2C_FIELD(var_r31, Ptr32<void> *, 0xC));
    temp_r30 = M2C_FIELD(var_r31, Ptr32<void> *, 8);
    if (var_r31 == NULL) {
        goto block_3;
    }
    fn_802134FC(var_r31);
block_3:
    var_r31 = temp_r30;
    if (var_r31 != NULL) {
        goto loop_1;
    }
block_4:
    return;
}

void w3d_auto_8035b8a4(s32 arg0, Ptr32<void> arg1) {
    Ptr32<void> temp_r30;
    Ptr32<void> var_r31;

    var_r31 = arg1;
    if (var_r31 == NULL) {
        goto block_4;
    }
loop_1:
    w3d_auto_8035b8a4(arg0, M2C_FIELD(var_r31, Ptr32<void> *, 0xC));
    temp_r30 = M2C_FIELD(var_r31, Ptr32<void> *, 8);
    if (var_r31 == NULL) {
        goto block_3;
    }
    fn_802134FC(var_r31);
block_3:
    var_r31 = temp_r30;
    if (var_r31 != NULL) {
        goto loop_1;
    }
block_4:
    return;
}

void w3d_auto_8035cc1c(s32 arg0, Ptr32<void> arg1) {
    Ptr32<void> temp_r30;
    Ptr32<void> var_r31;

    var_r31 = arg1;
    if (var_r31 == NULL) {
        goto block_4;
    }
loop_1:
    w3d_auto_8035cc1c(arg0, M2C_FIELD(var_r31, Ptr32<void> *, 0xC));
    temp_r30 = M2C_FIELD(var_r31, Ptr32<void> *, 8);
    if (var_r31 == NULL) {
        goto block_3;
    }
    fn_802134FC(var_r31);
block_3:
    var_r31 = temp_r30;
    if (var_r31 != NULL) {
        goto loop_1;
    }
block_4:
    return;
}

}
