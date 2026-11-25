#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "auto_80207ed8.c"
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


s32 fn_801FE45C();                                  /* extern */
M2C_UNK fn_80207B30(s32, u16, Ptr32<s32>, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK fn_802178B8(Ptr32<void>, M2C_UNK, M2C_UNK);         /* extern */
M2C_UNK fn_802092C8(Ptr32<void>);                           void fn_802095D8(s32);                           /* extern */
M2C_UNK fn_80209638(Ptr32<void>, Ptr32<void>, Ptr32<void>);                           /* extern */
M2C_UNK fn_80209720(Ptr32<void>);                           /* extern */
M2C_UNK fn_802097AC(Ptr32<void>, Ptr32<void>);                           /* extern */
M2C_UNK fn_8020926C(Ptr32<void>, Ptr32<void>);                           /* extern */
M2C_UNK fn_802092B8(Ptr32<void>);                           /* extern */
M2C_UNK fn_802095EC(Ptr32<void>, s32);                   /* extern */
M2C_UNK fn_802095DC(Ptr32<void>);                           /* extern */
M2C_UNK fn_80209A70();                              /* extern */
M2C_UNK fn_80209B2C();                              /* extern */
M2C_UNK fn_801FC8AC();                              /* extern */
s32 fn_80200B54();                                  /* extern */
M2C_UNK fn_802069A4();                              /* extern */
s32 fn_8020FF44();                                  void fn_80212BCC();                              /* extern */
M2C_UNK fn_80200BFC(Ptr32<void>);                       /* extern */
M2C_UNK fn_802069E0();                              void fn_8020C5C8();                              /* extern */
M2C_UNK fn_80210010();                              /* extern */
M2C_UNK fn_801FE1D8(M2C_UNK);                       /* extern */
M2C_UNK fn_802110CC();                              void fn_802098B4(Ptr32<M2C_UNK>, s32, M2C_UNK);       /* extern */
s32 fn_8020B208();                                  /* extern */
M2C_UNK fn_8020DC54();                              /* extern */
M2C_UNK fn_8021202C();                              /* extern */
M2C_UNK fn_802E4CEC(s32);                           /* extern */
M2C_UNK fn_802F5320(Ptr32<void>);                        /* extern */

extern s32 lbl_804AB9B4;
extern s32 lbl_804AB9B8;
extern u16 lbl_804B065A;
extern s32 lbl_804B18F4;

void w3d_auto_80207ed8(void) {
    s32 sp8;

    if ((s32) lbl_804B18F4 != 0) {
        sp8 = fn_801FE45C();
        fn_80207B30(lbl_804B18F4, lbl_804B065A, &sp8, 4, 0);
        lbl_804AB9B4 = 0x64;
        lbl_804AB9B8 = sp8;
    }
}

s32 w3d_auto_80208f2c(Ptr32<void> arg0, Ptr32<void> arg1) {
    M2C_FIELD(arg1, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0x14);
    M2C_FIELD(arg1, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
    return 0;
}

void w3d_auto_8020926c(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x14) = arg1;
    if (arg1 & 4) {
        fn_802178B8(w3d::G(M2C_FIELD(arg0, s32 *, 0)), 0x10, 1);
        return;
    }
    fn_802178B8(w3d::G(M2C_FIELD(arg0, s32 *, 0)), 0x10, 0);
}

s32 w3d_auto_802095dc(Ptr32<void> arg0) {
    return M2C_FIELD(arg0, s32 *, 8) - M2C_FIELD(arg0, s32 *, 0xC);
}

void w3d_auto_80209890(Ptr32<s32> arg0) {
    fn_802092C8(w3d::G(*arg0));
}

void w3d_auto_802098b4(Ptr32<s32> arg0) {
    fn_802095D8(*arg0);
}

void w3d_auto_802098fc(Ptr32<s32> arg0, Ptr32<void> arg_r4, Ptr32<void> arg_r5) {
    fn_80209638(w3d::G(*arg0), arg_r4, arg_r5);
}

void w3d_auto_80209968(Ptr32<s32> arg0) {
    fn_80209720(w3d::G(*arg0));
}

void w3d_auto_8020998c(Ptr32<s32> arg0, Ptr32<void> arg_r4) {
    fn_802097AC(w3d::G(*arg0), arg_r4);
}

void w3d_auto_802099b0(Ptr32<s32> arg0, Ptr32<void> arg_r4) {
    fn_8020926C(w3d::G(*arg0), arg_r4);
}

void w3d_auto_802099d4(Ptr32<s32> arg0) {
    fn_802092B8(w3d::G(*arg0));
}

void w3d_auto_802099f8(Ptr32<Ptr32<void>> arg0) {
    Ptr32<void> temp_r3;

    temp_r3 = *arg0;
    fn_802095EC(temp_r3, M2C_FIELD(temp_r3, s32 *, 0x28));
}

void w3d_auto_80209a20(Ptr32<s32> arg0) {
    fn_802095DC(w3d::G(*arg0));
}

void w3d_auto_80209ac0(void) {
    fn_80209A70();
    fn_80209B2C();
}

s32 w3d_auto_8020a45c(void) {
    return 0x80004001;
}

s32 w3d_auto_8020a468(void) {
    return 0x80004001;
}

s32 w3d_auto_8020a7e4(Ptr32<void> arg0) {
    return (s32) (M2C_FIELD(arg0, s32 *, 0x18) - M2C_FIELD(arg0, s32 *, 0x14)) >> 2;
}

s32 w3d_auto_8020ada4(void) {
    return 0x80004001;
}

s32 w3d_auto_8020ae34(void) {
    return 0x80004001;
}

s32 w3d_auto_8020ae40(void) {
    return 0x80004001;
}

s32 w3d_auto_8020ae4c(void) {
    return 0x80004001;
}

s32 w3d_auto_8020b0f8(void) {
    return 0x80004001;
}

extern s32 lbl_804ABA00;
extern s32 lbl_804ABA04;

s32 w3d_auto_8020b3bc(s32 arg0) {
    s32 var_r3;

    if (arg0 & 1) {
        lbl_804ABA00 = 1;
    }
    fn_80209A70();
    fn_80209B2C();
    fn_802069A4();
    var_r3 = fn_8020FF44();
    if (var_r3 >= 0) {
        fn_80212BCC();
        fn_801FC8AC();
        var_r3 = fn_80200B54();
        lbl_804ABA04 = 1;
    }
    return var_r3;
}

extern s32 lbl_804ABA04;
extern s32 lbl_804ABA08;

s32 w3d_auto_8020b414(void) {
    fn_80200BFC(0);
    fn_80210010();
    fn_802069E0();
    fn_8020C5C8();
    lbl_804ABA04 = 0;
    lbl_804ABA08 = 1;
    return 0;
}

extern s32 lbl_804ABA04;

s32 w3d_auto_8020b458(void) {
    return lbl_804ABA04;
}

extern s32 lbl_804B18FC;

s32 w3d_auto_8020b648(void) {
    if ((s32) lbl_804B18FC == 0) {
        fn_801FE1D8(0x114);
        fn_802110CC();
    }
    return lbl_804B18FC;
}

extern s32 lbl_804B069C;

void w3d_auto_8020b85c(s32 arg0) {
    if (arg0 != 0) {
        lbl_804B069C += 1;
        return;
    }
    lbl_804B069C -= 1;
}

extern M2C_UNK lbl_804B06A4;

s32 w3d_auto_8020bab4(void) {
    fn_802098B4(&lbl_804B06A4, fn_8020B208(), 0);
    return 0;
}

s32 w3d_auto_8020ddc0(s32 arg0) {
    fn_8020DC54();
    return arg0;
}

extern s32 lbl_804ABA34;

s32 w3d_auto_8020df00(void) {
    return lbl_804ABA34;
}

extern s32 lbl_804ABA34;

void w3d_auto_8020df08(void) {
    lbl_804ABA34 = 0;
}

s32 w3d_auto_8020fe30(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x24) = arg1;
    return 0;
}

s32 w3d_auto_8020fe3c(void) {
    return 0x80004005;
}

extern Ptr32<void> lbl_804B1900;

void w3d_auto_8020fe54(Ptr32<void> arg0) {
    M2C_FIELD(arg0, Ptr32<void> *, 4) = (Ptr32<void>) lbl_804B1900;
    lbl_804B1900 = arg0;
}

extern s32 lbl_804B1908;

s32 w3d_auto_8020ff34(void) {
    return lbl_804B1908;
}

void w3d_auto_802112d8(void) {
    fn_8021202C();
}

s32 w3d_auto_80218d10(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x60) != 0) {
        fn_802F5320(arg0 + 0x18);
        M2C_FIELD(arg0, s32 *, 0x60) = 0;
    } else if ((s32) M2C_FIELD(arg0, s32 *, 0x64) != 0) {
        fn_802E4CEC(M2C_FIELD(arg0, s32 *, 0x6C));
        M2C_FIELD(arg0, s32 *, 0x6C) = -1;
    }
    return 0;
}

s32 w3d_auto_80218ddc(Ptr32<void> arg0, Ptr32<void> arg1) {
    M2C_FIELD(arg1, s32 *, 4) = 0;
    M2C_FIELD(arg1, s32 *, 8) = 2;
    M2C_FIELD(arg1, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0x4C);
    return 0;
}

s32 w3d_auto_80219178(void) {
    return 0x80004001;
}

void w3d_auto_802199b4(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
}

}
