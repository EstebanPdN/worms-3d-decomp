#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autoc_801ff01c.c"
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

extern Ptr32<Ptr32<void>> lbl_804B0688;
s32 fn_80178C48();                                  /* extern */
s32 fn_80178D1C();                                  /* extern */
Ptr32<Ptr32<void>> fn_80179170();                               void fn_8020C5C0(Ptr32<Ptr32<void>>);                       void fn_8020C5C4(Ptr32<Ptr32<void>>);                       /* extern */
M2C_UNK fn_80341588(Ptr32<Ptr32<void>>);                       /* extern */
Ptr32<u16> fn_80341884(Ptr32<Ptr32<void>>);                          /* extern */
M2C_UNK fn_803426B4(Ptr32<Ptr32<void>>);                       /* extern */
M2C_UNK fn_80342A78(Ptr32<Ptr32<void>>);                       /* extern */
M2C_UNK fn_80343744(Ptr32<Ptr32<void>>);                       /* extern */

void w3d_auto_801ff01c(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x68)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801ff054(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x50)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801ff13c(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x74)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801ff174(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x58)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801ff258(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x7C)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801ff290(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x5C)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801ff39c(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x84)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801ff3d4(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x60)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801ff4b8(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x5C)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801ff4f0(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x4C)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801ff5e8(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x6C)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801ff620(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x54)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801ff7f8(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x24)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801ff924(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x4C)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801ffbac(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x5C)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801ffbe4(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x4C)(arg1, arg2, arg4);
    return;
}

void w3d_auto_80201368(Ptr32<void> arg0, Ptr32<s32> arg1) {
    u8 sp8;
    s32 var_r9;
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x14);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, Ptr32<u8>, M2C_UNK, M2C_UNK)> *, 0x14)(temp_r3, &sp8, 1, 0);
    var_r9 = 1;
    if ((s32) sp8 != 0) {
        goto block_2;
    }
    var_r9 = 0;
block_2:
    *arg1 = var_r9;
    return;
}

s32 w3d_auto_802024f4(Ptr32<void> arg0) {
    u8 sp8;
    s32 var_r30;
    s32 var_r31;
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<Ptr32<void>> temp_r3_2;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x14);
    temp_r9 = *temp_r3;
    if (M2C_FIELD(temp_r9, Ptr32<s32 (Ptr32<Ptr32<void>>, Ptr32<u8>, M2C_UNK, M2C_UNK)> *, 0x14)(temp_r3, &sp8, 1, 0) >= 0) {
        goto block_2;
    }
block_1:
    return 0;
block_2:
    var_r30 = 7;
    var_r31 = sp8 & 0x7F;
    if (!(sp8 & 0x80)) {
        goto block_5;
    }
loop_3:
    temp_r3_2 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x14);
    if (M2C_FIELD(*temp_r3_2, Ptr32<s32 (Ptr32<Ptr32<void>>, Ptr32<u8>, M2C_UNK, M2C_UNK)> *, 0x14)(temp_r3_2, &sp8, 1, 0) < 0) {
        goto block_1;
    }
    var_r31 |= (sp8 & 0x7F) << var_r30;
    var_r30 += 7;
    if (sp8 & 0x80) {
        goto loop_3;
    }
block_5:
    return var_r31;
}

void w3d_auto_80208168(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x14);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x1C)(temp_r3);
    return;
}

void w3d_auto_80208198(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x14);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x20)(temp_r3);
    return;
}

void w3d_auto_802081c8(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x14);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x24)(temp_r3);
    return;
}

void w3d_auto_80208298(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x14);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x14)(temp_r3);
    return;
}

void w3d_auto_802082c8(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x14);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x18)(temp_r3);
    return;
}

void w3d_auto_8020860c(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x1C);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x14)(temp_r3);
    return;
}

void w3d_auto_802088c4(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x14);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x14)(temp_r3);
    return;
}

s32 w3d_auto_80209758(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Ptr32<void> temp_r9;
    Ptr32<void> temp_r9_2;

    if (arg3 == 0) {
        goto block_2;
    }
    temp_r9 = *lbl_804B0688;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 8)(lbl_804B0688);
    goto block_3;
block_2:
    temp_r9_2 = *lbl_804B0688;
    M2C_FIELD(temp_r9_2, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0xC)(lbl_804B0688);
block_3:
    return 0;
}

void w3d_auto_80219840(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x14);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x20)(temp_r3);
    return;
}

void w3d_auto_80219870(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x14);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x24)(temp_r3);
    return;
}

void w3d_auto_8025f064(Ptr32<Ptr32<Ptr32<void>>> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = *arg0;
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x58)(temp_r3);
    return;
}

Ptr32<Ptr32<Ptr32<void>>> w3d_auto_8026d850(Ptr32<Ptr32<Ptr32<void>>> arg0, Ptr32<void> arg1) {
    Ptr32<Ptr32<void>> temp_r11;
    Ptr32<void> temp_r9;

    temp_r11 = M2C_FIELD(arg1, Ptr32<Ptr32<void>> *, 0x4C);
    *arg0 = temp_r11;
    if (temp_r11 == NULL) {
        goto block_2;
    }
    temp_r9 = *temp_r11;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0xC)(temp_r11);
block_2:
    return arg0;
}

s32 w3d_auto_802707bc(Ptr32<void> arg0) {
    Ptr32<void> temp_r9;

    temp_r9 = M2C_FIELD(arg0, Ptr32<void> *, 0xD0);
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<void>)> *, 0xC)(arg0 + 0x1C);
    return 0;
}

s32 w3d_auto_802b2374(s32 arg0, Ptr32<void> arg1) {
    Ptr32<void> sp8;
    M2C_UNK var_r4;
    s32 temp_r3_2;
    s32 var_r3;
    Ptr32<u16> temp_r3_3;
    Ptr32<Ptr32<void>> temp_r29;
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;
    Ptr32<void> var_r30;

    temp_r3 = M2C_FIELD(arg1, Ptr32<Ptr32<void>> *, 0x4C);
    temp_r9 = *temp_r3;
    temp_r3_2 = M2C_FIELD(temp_r9, Ptr32<s32 (Ptr32<Ptr32<void>>)> *, 0x18)(temp_r3);
    if (temp_r3_2 == 1) {
        goto block_7;
    }
    if (temp_r3_2 > 1) {
        goto block_4;
    }
    if (temp_r3_2 == 0) {
        goto block_6;
    }
    goto block_16;
block_4:
    if (temp_r3_2 == 4) {
        goto block_11;
    }
    goto block_16;
block_6:
    var_r30 = M2C_FIELD(arg1, Ptr32<void> *, 0xB4);
    fn_803426B4(M2C_FIELD(arg1, Ptr32<Ptr32<void>> *, 0x4C));
    var_r3 = fn_80178C48();
    goto block_8;
block_7:
    var_r30 = M2C_FIELD(arg1, Ptr32<void> *, 0xB4);
    fn_80342A78(M2C_FIELD(arg1, Ptr32<Ptr32<void>> *, 0x4C));
    var_r3 = fn_80178D1C();
block_8:
    var_r4 = 1;
    if (var_r3 != 0) {
        goto block_10;
    }
    var_r4 = 0;
block_10:
    M2C_FIELD(var_r30, Ptr32<M2C_UNK (Ptr32<void>, M2C_UNK)> *, 0x44)(arg1, var_r4);
    goto block_16;
block_11:
    fn_80343744(M2C_FIELD(arg1, Ptr32<Ptr32<void>> *, 0x4C));
    temp_r29 = fn_80179170();
    fn_8020C5C0(&sp8);
    sp8 = *temp_r29;
    temp_r3_3 = fn_80341884(&sp8);
    *temp_r3_3 += 1;
    if ((s32) M2C_FIELD(sp8, u16 *, -4) == 0) {
        goto block_13;
    }
    if ((s32) M2C_FIELD(sp8, u8 *, 0) != 0x20) {
        goto block_14;
    }
block_13:
    M2C_FIELD(M2C_FIELD(arg1, Ptr32<void> *, 0xB4), Ptr32<M2C_UNK (Ptr32<void>, M2C_UNK)> *, 0x44)(arg1, 0);
    goto block_15;
block_14:
    M2C_FIELD(M2C_FIELD(arg1, Ptr32<void> *, 0xB4), Ptr32<M2C_UNK (Ptr32<void>, M2C_UNK)> *, 0x44)(arg1, 1);
block_15:
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
block_16:
    return 0;
}

void w3d_auto_80355a14(Ptr32<Ptr32<Ptr32<void>>> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = *arg0;
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x10)(temp_r3);
    return;
}

}
