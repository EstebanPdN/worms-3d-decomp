#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autof_800aa374.c"
/* Decompiled automatically by m2c with mechanical corrections (tools/m2c_fixups.py:
 * far globals as unknown-size arrays, dropped leading parameters, forwarded
 * arguments); verified identical to the original after linking. Types and
 * names are m2c placeholders pending review. */
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

M2C_UNK fn_800AAF5C(Ptr32<void>);                        /* extern */
M2C_UNK fn_800AB944(Ptr32<void>);                        /* extern */
M2C_UNK fn_800ABA08(Ptr32<void>);                        /* extern */
M2C_UNK fn_800AC278(Ptr32<void>);                        /* extern */
M2C_UNK fn_800FDE64(M2C_UNK);                       /* extern */
s16 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
s32 fn_8015F65C(u16, Ptr32<M2C_UNK>);                    /* extern */
s32 fn_8015FB34(Ptr32<void>, Ptr32<u16>);                     /* extern */
M2C_UNK fn_8015FD1C(Ptr32<void>);                        /* extern */
Ptr32<void> fn_801613F0(Ptr32<void>, M2C_UNK);                    /* extern */
M2C_UNK fn_8016239C(Ptr32<void>);                        /* extern */
s32 fn_800AC0F4(Ptr32<void>);                            /* extern */
M2C_UNK fn_800AC11C(Ptr32<void>, s32);                   /* extern */
Ptr32<void> fn_80165254();                                /* extern */
f32 fn_80178DF0(Ptr32<void>);                               /* extern */
M2C_UNK fn_8015F518(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_800520F4(Ptr32<void>, s32, M2C_UNK);                       void fn_8020C5C4(s32);                           /* extern */
M2C_UNK fn_80341588(Ptr32<void>);                           /* extern */
M2C_UNK fn_800C6F20(Ptr32<M2C_UNK>, M2C_UNK);            /* extern */

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804AE330;
extern M2C_UNK lbl_804AE338;
extern M2C_UNK lbl_804AE340;
extern M2C_UNK lbl_804AE348;
extern M2C_UNK lbl_804AE350;
extern M2C_UNK lbl_804AE358;
extern M2C_UNK lbl_804AE360;
extern M2C_UNK lbl_804AE368;
extern M2C_UNK lbl_804AE370;
extern M2C_UNK lbl_804AE378;
extern M2C_UNK lbl_804AE3A0;
extern s32 lbl_804B1754;

s32 w3d_auto_800aa374(Ptr32<void> arg0, Ptr32<u16> arg1) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    u16 temp_r30;
    Ptr32<void> temp_r30_2;
    Ptr32<void> temp_r30_3;

    temp_r30 = *arg1;
    if ((s32) temp_r30 == 0x40) {
        goto block_3;
    }
    if ((s32) temp_r30 == 0x42) {
        goto block_6;
    }
    goto block_7;
block_3:
    if (fn_8015FB34(arg0, arg1) < 0) {
        goto block_5;
    }
    fn_800AAF5C(arg0);
    goto block_30;
block_5:
    return 0x80004005;
block_6:
    fn_800AB944(arg0);
    goto block_28;
block_7:
    if (fn_8015F65C(temp_r30, &lbl_804AE330) == 0) {
        goto block_9;
    }
    fn_800AC278(arg0);
    goto block_30;
block_9:
    if (fn_8015F65C(temp_r30, &lbl_804AE338) == 0) {
        goto block_11;
    }
    fn_800ABA08(arg0);
    goto block_30;
block_11:
    temp_r3 = fn_8015F65C(temp_r30, &lbl_804AE350);
    if (temp_r3 == 0) {
        goto block_13;
    }
    M2C_FIELD(arg0, s32 *, 0x50) = 1;
    return 0;
block_13:
    if (fn_8015F65C(temp_r30, &lbl_804AE358) == 0) {
        goto block_15;
    }
    M2C_FIELD(arg0, s32 *, 0x50) = temp_r3;
    goto block_30;
block_15:
    temp_r3_2 = fn_8015F65C(temp_r30, &lbl_804AE360);
    if (temp_r3_2 == 0) {
        goto block_17;
    }
    M2C_FIELD(arg0, s32 *, 0x54) = 1;
    return 0;
block_17:
    if (fn_8015F65C(temp_r30, &lbl_804AE368) == 0) {
        goto block_19;
    }
    M2C_FIELD(arg0, s32 *, 0x54) = temp_r3_2;
    goto block_30;
block_19:
    temp_r3_3 = fn_8015F65C(temp_r30, &lbl_804AE340);
    if (temp_r3_3 == 0) {
        goto block_21;
    }
    M2C_FIELD(arg0, s32 *, 0x4C) = 1;
    return 0;
block_21:
    if (fn_8015F65C(temp_r30, &lbl_804AE348) == 0) {
        goto block_23;
    }
    M2C_FIELD(arg0, s32 *, 0x4C) = temp_r3_3;
    goto block_30;
block_23:
    if (fn_8015F65C(temp_r30, &lbl_804AE378) == 0) {
        goto block_27;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x48) == 0) {
        goto block_26;
    }
    fn_800FDE64(-1);
block_26:
    temp_r30_2 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30_2, s16 *, 0) = fn_8015F5A0(&lbl_804AE3A0, 1);
    M2C_FIELD(temp_r30_2, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30_2);
    fn_8015FD1C(arg0);
    goto block_30;
block_27:
    if (fn_8015F65C(temp_r30, &lbl_804AE370) != 0) {
        goto block_29;
    }
block_28:
    return fn_8015FB34(arg0, arg1);
block_29:
    temp_r30_3 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30_3, s16 *, 0) = fn_8015F5A0(&lbl_804AE378, 1);
    M2C_FIELD(temp_r30_3, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30_3);
block_30:
    return 0;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804AE378;
extern M2C_UNK lbl_804AE3A0;
extern s32 lbl_804B1754;

void w3d_auto_800aba08(Ptr32<void> arg0) {
    s32 temp_r31;
    Ptr32<void> temp_r30;
    Ptr32<void> temp_r30_2;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x48) == 0) {
        goto block_4;
    }
    M2C_FIELD(arg0, s32 *, 0x48) = 0;
    fn_800FDE64(-1);
    temp_r31 = M2C_FIELD(fn_80165254(), s32 *, 0x34) - M2C_FIELD(arg0, s32 *, 0x70);
    if (temp_r31 <= fn_800AC0F4(arg0)) {
        goto block_3;
    }
    fn_800AC11C(arg0, 0);
    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AE378, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    goto block_4;
block_3:
    fn_800AC11C(arg0, fn_800AC0F4(arg0) - temp_r31);
block_4:
    temp_r30_2 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30_2, s16 *, 0) = fn_8015F5A0(&lbl_804AE3A0, 1);
    M2C_FIELD(temp_r30_2, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30_2);
    return;
}

extern f32 lbl_80381C40[];

void w3d_auto_800abfe0(Ptr32<void> arg0) {
    M2C_FIELD(arg0, f32 *, 0xA0) = (f32) (M2C_FIELD(arg0, f32 *, 0xA0) * fn_80178DF0(w3d::G(M2C_FIELD(arg0, s32 *, 0xD8))));
    if (!(M2C_FIELD(arg0, f32 *, 0xA0) < fn_80178DF0(w3d::G(M2C_FIELD(arg0, s32 *, 0xDC))))) {
        goto block_2;
    }
    M2C_FIELD(arg0, f32 *, 0xA0) = (f32) (*lbl_80381C40);
block_2:
    return;
}

extern M2C_UNK lbl_80382070[];
extern M2C_UNK lbl_80382084[];
extern M2C_UNK lbl_804AE3C8;
extern M2C_UNK lbl_804AE3D0;

void w3d_auto_800ad8b4(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804AE3C8, &(*lbl_80382070));
    fn_8015F518(&lbl_804AE3D0, &(*lbl_80382084));
block_3:
    return;
}

extern M2C_UNK lbl_8040F728[];

Ptr32<void> w3d_auto_800af1e0(Ptr32<void> arg0, s32 arg1) {
    fn_800520F4(arg0, arg1, 0x12);
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0x48) = &(*lbl_8040F728);
    return arg0;
}

extern M2C_UNK lbl_80382278[];
extern M2C_UNK lbl_8038228C[];
extern M2C_UNK lbl_804AE3EC;
extern M2C_UNK lbl_804AE3F4;

void w3d_auto_800af2b0(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804AE3EC, &(*lbl_80382278));
    fn_8015F518(&lbl_804AE3F4, &(*lbl_8038228C));
block_3:
    return;
}

extern M2C_UNK lbl_803826A0[];
extern M2C_UNK lbl_804AE510;

void w3d_auto_800b931c(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804AE510, &(*lbl_803826A0));
block_3:
    return;
}

s32 w3d_auto_800bc350(s32 arg0, s32 arg1) {
    return 0x80004001;
}

s32 w3d_auto_800bc390(s32 arg0, Ptr32<void> arg1, s32 arg2, s32 arg3) {
    if ((s32) M2C_FIELD(arg1, u8 *, 0x1C3) != 0) {
        goto block_2;
    }
    return 0;
block_2:
    if ((s32) M2C_FIELD(M2C_FIELD(arg1, Ptr32<void> *, 0x1D8), s32 *, 0x18) != 0) {
        goto block_10;
    }
    if ((s32) M2C_FIELD(M2C_FIELD(arg1, Ptr32<void> *, 0x2C), s32 *, 0x18) != 1) {
        goto block_10;
    }
    if ((u16) M2C_FIELD(arg1, u16 *, 0x1D4) > 0x7FU) {
        goto block_10;
    }
    if ((s32) M2C_FIELD(arg1, u16 *, 0x1D6) == arg2) {
        goto block_7;
    }
    if (arg2 != 0xFFFF) {
        goto block_10;
    }
block_7:
    if ((s32) M2C_FIELD(arg1, s32 *, 0x1A8) == arg3) {
        goto block_9;
    }
    if (arg3 != 0) {
        goto block_10;
    }
block_9:
    return 1;
block_10:
    return 0;
}

extern M2C_UNK lbl_80383008[];
extern M2C_UNK lbl_804AE678;

void w3d_auto_800c1674(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804AE678, &(*lbl_80383008));
block_3:
    return;
}

extern M2C_UNK lbl_8043E464[];

void w3d_auto_800c6cf4(void) {
    fn_800C6F20(&(*lbl_8043E464), 2);
    return;
}

}
