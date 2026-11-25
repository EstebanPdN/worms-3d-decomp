#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s11cleanup_802b0fec.c"
/* Range-isolated m2c recovery by worker s11. Types and names are provisional. */
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

s32 fn_80178D1C();                                  /* extern */
M2C_UNK fn_80178D28(Ptr32<void>, Ptr32<s32>);                    /* extern */
M2C_UNK fn_80264658(s32, M2C_UNK, s32);                  /* extern */
M2C_UNK fn_802AFF50();                              /* extern */
M2C_UNK fn_802B1CEC(Ptr32<void>);                        /* extern */
s32 fn_80342A78(s32);                               /* extern */
extern s32 lbl_804ABB44;
extern s32 lbl_804ABC68;

void w3d_auto_802b0fec(Ptr32<void> arg0) {
    s32 sp8;
    s32 selected;
    s32 temp_r29;
    s32 temp_r30;
    Ptr32<Ptr32<void>> temp_r30_2;
    Ptr32<Ptr32<void>> temp_r30_3;
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<Ptr32<void>> temp_r3_2;
    Ptr32<Ptr32<void>> temp_r3_3;
    Ptr32<Ptr32<void>> temp_r3_4;
    Ptr32<Ptr32<void>> temp_r3_5;
    Ptr32<Ptr32<void>> temp_r3_6;
    Ptr32<Ptr32<void>> temp_r3_7;
    Ptr32<void> temp_r29_2;
    Ptr32<void> temp_r29_3;

    fn_802AFF50();
    temp_r29 = fn_80342A78(M2C_FIELD(arg0, s32 *, 0x48));
    temp_r30 = fn_80178D1C();
    if (temp_r30 != M2C_FIELD(M2C_FIELD(arg0, Ptr32<void> *, 0xB4), Ptr32<s32 (Ptr32<void>)> *, 0x40)(arg0)) {
        goto block_2;
    }
    sp8 = 0;
    fn_80178D28(w3d::G(temp_r29), &sp8);
block_2:
    if ((void **) M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x54) == NULL) {
        goto block_9;
    }
    goto loop_5;
block_4:
    temp_r30_2 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x54);
    temp_r29_2 = *temp_r30_2;
    M2C_FIELD(temp_r29_2, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32)> *, 0x60)(temp_r30_2, M2C_FIELD(temp_r29_2, Ptr32<s32 (Ptr32<Ptr32<void>>, M2C_UNK)> *, 0x74)(temp_r30_2, 0));
loop_5:
    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x54);
    temp_r3_2 = M2C_FIELD(*temp_r3, Ptr32<Ptr32<Ptr32<void>> (Ptr32<Ptr32<void>>)> *, 0x78)(temp_r3);
    if (temp_r3_2 != NULL) {
        goto block_4;
    }
    temp_r3_3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x54);
    if (temp_r3_3 == NULL) {
        goto block_8;
    }
    M2C_FIELD(*temp_r3_3, Ptr32<M2C_UNK (Ptr32<void>)> *, 0x10)(temp_r3_3);
block_8:
    M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x54) = temp_r3_2;
block_9:
    if ((void **) M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x58) == NULL) {
        goto block_16;
    }
    fn_802B1CEC(arg0);
    goto loop_12;
block_11:
    temp_r30_3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x58);
    temp_r29_3 = *temp_r30_3;
    M2C_FIELD(temp_r29_3, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32)> *, 0x60)(temp_r30_3, M2C_FIELD(temp_r29_3, Ptr32<s32 (Ptr32<Ptr32<void>>, M2C_UNK)> *, 0x74)(temp_r30_3, 0));
loop_12:
    temp_r3_4 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x58);
    temp_r3_5 = M2C_FIELD(*temp_r3_4, Ptr32<Ptr32<Ptr32<void>> (Ptr32<Ptr32<void>>)> *, 0x78)(temp_r3_4);
    if (temp_r3_5 != NULL) {
        goto block_11;
    }
    temp_r3_6 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x58);
    if (temp_r3_6 == NULL) {
        goto block_15;
    }
    M2C_FIELD(*temp_r3_6, Ptr32<M2C_UNK (Ptr32<void>)> *, 0x10)(temp_r3_6);
block_15:
    M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x58) = temp_r3_5;
block_16:
    temp_r3_7 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 8);
    if (temp_r3_7 == NULL) {
        goto block_18;
    }
    M2C_FIELD(*temp_r3_7, Ptr32<M2C_UNK (Ptr32<void>)> *, 0x10)(temp_r3_7);
block_18:
    selected=lbl_804ABC68;
    M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 8) = NULL;
    if (selected == -1) {
        goto block_21;
    }
    if ((s32) lbl_804ABC68 != M2C_FIELD(M2C_FIELD(arg0, Ptr32<void> *, 0xB4), Ptr32<s32 (Ptr32<void>)> *, 0x40)(arg0)) {
        goto block_21;
    }
    lbl_804ABC68 = -1;
block_21:
    if ((s32) M2C_FIELD(arg0, s32 *, 0xA0) != 1) {
        goto block_24;
    }
    if ((s32) lbl_804ABB44 == 0) {
        goto block_24;
    }
    fn_80264658(lbl_804ABB44, 0, M2C_FIELD(arg0, s32 *, 0));
block_24:
    return;
}

}
