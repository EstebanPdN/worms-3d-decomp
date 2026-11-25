#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "auto_801e5f24.c"
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


M2C_UNK fn_801E44AC(s32, s32);                      /* extern */
s32 fn_801E5FD4(Ptr32<void>);                            /* extern */
M2C_UNK fn_801E4548(s32, s32);                      /* extern */
M2C_UNK fn_801E8D9C();                              /* extern */
M2C_UNK fn_801EDC5C();                              void fn_802098B4(Ptr32<M2C_UNK>, s32, M2C_UNK);       /* extern */
s32 fn_8020B208();                                  /* extern */
M2C_UNK fn_801FE288(s32);                           /* extern */
M2C_UNK fn_80209920(Ptr32<M2C_UNK>, Ptr32<void>);                     /* extern */
M2C_UNK fn_801F3A00(Ptr32<void>, u32, s32, u16);         /* extern */
M2C_UNK fn_801F606C();                              /* extern */
s32 fn_801F65F0();                                  /* extern */
M2C_UNK fn_80302104(s32, M2C_UNK);                  /* extern */

extern s32 lbl_804AB85C;

void w3d_auto_801e5f24(Ptr32<void> arg0) {
    s32 temp_r9;
    s32 var_r0;

    temp_r9 = M2C_FIELD(arg0, s32 *, 0x30);
    if (temp_r9 > 0) {
        var_r0 = temp_r9 + 1;
        goto block_4;
    }
    if (fn_801E5FD4(arg0) != 0) {
        fn_801E44AC(lbl_804AB85C, M2C_FIELD(arg0, s32 *, 0x38));
        var_r0 = 1;
block_4:
        M2C_FIELD(arg0, s32 *, 0x30) = var_r0;
    }
}

extern s32 lbl_804AB85C;

void w3d_auto_801e5f84(Ptr32<void> arg0) {
    s32 temp_r0;
    s32 temp_r9;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x1C) != -1) {
        temp_r9 = M2C_FIELD(arg0, s32 *, 0x30);
        if (temp_r9 > 0) {
            temp_r0 = temp_r9 - 1;
            M2C_FIELD(arg0, s32 *, 0x30) = temp_r0;
            if (temp_r0 == 0) {
                fn_801E4548(lbl_804AB85C, M2C_FIELD(arg0, s32 *, 0x38));
            }
        }
    }
}

s32 w3d_auto_801ea44c(void) {
    fn_801E8D9C();
    return 0;
}

void w3d_auto_801ea57c(void) {
    fn_801EDC5C();
}

extern M2C_UNK lbl_804B0580;

s32 w3d_auto_801ea6d0(void) {
    fn_802098B4(&lbl_804B0580, fn_8020B208(), 0);
    return 0;
}

extern M2C_UNK lbl_804B0580;

Ptr32<M2C_UNK> w3d_auto_801ea704(void) {
    return &lbl_804B0580;
}

s32 w3d_auto_801ea8c4(Ptr32<void> arg0) {
    return (s32) (M2C_FIELD(arg0, s32 *, 0x34) - M2C_FIELD(arg0, s32 *, 0x30)) >> 2;
}

s32 w3d_auto_801ea904(void) {
    return 0x80004005;
}

s32 w3d_auto_801eb29c(Ptr32<Ptr32<void>> arg0) {
    return M2C_FIELD(*arg0, s32 *, 0x10);
}

s32 w3d_auto_801eb318(Ptr32<Ptr32<void>> arg0, s32 arg1) {
    return arg1 + M2C_FIELD(*arg0, u16 *, 4);
}

s32 w3d_auto_801eb328(Ptr32<Ptr32<void>> arg0, s32 arg1) {
    return arg1 + M2C_FIELD(*arg0, u16 *, 4);
}

extern s32 lbl_804B05A8;
extern s32 lbl_804B05AC;
extern s32 lbl_804B05B0;
extern s32 lbl_804B05B4;

s32 w3d_auto_801edbd4(void) {
    fn_801FE288(lbl_804B05A8);
    fn_801FE288(lbl_804B05AC);
    fn_801FE288(lbl_804B05B0);
    fn_801FE288(lbl_804B05B4);
    lbl_804B05B4 = 0;
    lbl_804B05A8 = 0;
    lbl_804B05AC = 0;
    lbl_804B05B0 = 0;
    return 0;
}

extern M2C_UNK lbl_804B05A0;

s32 w3d_auto_801edc28(void) {
    fn_802098B4(&lbl_804B05A0, fn_8020B208(), 0);
    return 0;
}

extern M2C_UNK lbl_804B05A0;

void w3d_auto_801edf00(Ptr32<void> arg0, Ptr32<void> arg1) {
    fn_80209920(&lbl_804B05A0, arg1);
}

extern s32 lbl_804B05A8;

s32 w3d_auto_801edf24(void) {
    return lbl_804B05A8;
}

extern s32 lbl_804B05AC;

s32 w3d_auto_801edf80(void) {
    return lbl_804B05AC;
}

extern s32 lbl_804B05B4;

s32 w3d_auto_801ee180(void) {
    return lbl_804B05B4;
}

extern s32 lbl_804B05B0;

s32 w3d_auto_801ee1dc(void) {
    return lbl_804B05B0;
}

s32 w3d_auto_801ee244(void) {
    return 0x80004001;
}

extern M2C_UNK lbl_804B0590;

Ptr32<M2C_UNK> w3d_auto_801ee2f0(void) {
    return &lbl_804B0590;
}

extern M2C_UNK lbl_804B0594;

Ptr32<M2C_UNK> w3d_auto_801ee464(void) {
    return &lbl_804B0594;
}

extern M2C_UNK lbl_804B059C;

Ptr32<M2C_UNK> w3d_auto_801ee830(void) {
    return &lbl_804B059C;
}

extern M2C_UNK lbl_804B0598;

Ptr32<M2C_UNK> w3d_auto_801eebfc(void) {
    return &lbl_804B0598;
}

void w3d_auto_801f39a0(Ptr32<void> arg0) {
    s32 temp_r29;
    s32 temp_r5;
    u16 temp_r6;
    u32 temp_r4;
    Ptr32<void> var_r31;

    temp_r29 = M2C_FIELD(arg0, s32 *, 0x2C);
    var_r31 = M2C_FIELD(arg0, Ptr32<void> *, 0x28);
    if (var_r31 != w3d::G(temp_r29)) {
        do {
            temp_r5 = M2C_FIELD(var_r31, s32 *, 4);
            temp_r6 = M2C_FIELD(var_r31, u16 *, 8);
            temp_r4 = (u32) M2C_FIELD(M2C_FIELD(var_r31, Ptr32<void> *, 0), u32 *, 0x20) >> 0x16U;
            var_r31 += 0xC;
            fn_801F3A00(arg0, temp_r4, temp_r5, temp_r6);
        } while (var_r31 != w3d::G(temp_r29));
    }
}

void w3d_auto_801f6298(Ptr32<void> arg0, f32 farg0, f32 farg1, f32 farg2) {
    s32 var_ctr;
    Ptr32<void> var_r3;

    var_r3 = arg0;
    var_ctr = 3;
    do {
        M2C_FIELD(var_r3, f32 *, 0) = (f32) (M2C_FIELD(var_r3, f32 *, 0) * farg0);
        M2C_FIELD(var_r3, f32 *, 4) = (f32) (M2C_FIELD(var_r3, f32 *, 4) * farg1);
        M2C_FIELD(var_r3, f32 *, 8) = (f32) (M2C_FIELD(var_r3, f32 *, 8) * farg2);
        var_r3 += 0xC;
        var_ctr -= 1;
    } while (var_ctr != 0);
}

void w3d_auto_801f6448(Ptr32<void> arg0, f32 farg0, f32 farg1, f32 farg2) {
    s32 var_ctr;
    Ptr32<void> var_r3;

    var_r3 = arg0;
    var_ctr = 3;
    do {
        M2C_FIELD(var_r3, f32 *, 0) = (f32) (M2C_FIELD(var_r3, f32 *, 0) * farg0);
        M2C_FIELD(var_r3, f32 *, 0xC) = (f32) (M2C_FIELD(var_r3, f32 *, 0xC) * farg1);
        M2C_FIELD(var_r3, f32 *, 0x18) = (f32) (M2C_FIELD(var_r3, f32 *, 0x18) * farg2);
        var_r3 += 4;
        var_ctr -= 1;
    } while (var_ctr != 0);
}

void w3d_auto_801f740c(Ptr32<void> arg0, Ptr32<void> arg1, Ptr32<void> arg2) {
    fn_801F606C();
    M2C_FIELD(arg0, f32 *, 0x24) = (f32) ((M2C_FIELD(arg1, f32 *, 0x2C) * M2C_FIELD(arg2, f32 *, 0x18)) + ((M2C_FIELD(arg1, f32 *, 0x24) * M2C_FIELD(arg2, f32 *, 0)) + (M2C_FIELD(arg1, f32 *, 0x28) * M2C_FIELD(arg2, f32 *, 0xC))) + M2C_FIELD(arg2, f32 *, 0x24));
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) ((M2C_FIELD(arg1, f32 *, 0x2C) * M2C_FIELD(arg2, f32 *, 0x1C)) + ((M2C_FIELD(arg1, f32 *, 0x24) * M2C_FIELD(arg2, f32 *, 4)) + (M2C_FIELD(arg1, f32 *, 0x28) * M2C_FIELD(arg2, f32 *, 0x10))) + M2C_FIELD(arg2, f32 *, 0x28));
    M2C_FIELD(arg0, f32 *, 0x2C) = (f32) ((M2C_FIELD(arg1, f32 *, 0x2C) * M2C_FIELD(arg2, f32 *, 0x20)) + ((M2C_FIELD(arg1, f32 *, 0x24) * M2C_FIELD(arg2, f32 *, 8)) + (M2C_FIELD(arg1, f32 *, 0x28) * M2C_FIELD(arg2, f32 *, 0x14))) + M2C_FIELD(arg2, f32 *, 0x2C));
}

s32 w3d_auto_801f76e0(Ptr32<void> arg0, Ptr32<void> arg1) {
    s32 var_r3;

    var_r3 = fn_801F65F0();
    if (var_r3 >= 0) {
        var_r3 = 0;
        M2C_FIELD(arg0, f32 *, 0x24) = (f32) -((M2C_FIELD(arg0, f32 *, 0x18) * M2C_FIELD(arg1, f32 *, 0x2C)) + ((M2C_FIELD(arg0, f32 *, 0) * M2C_FIELD(arg1, f32 *, 0x24)) + (M2C_FIELD(arg0, f32 *, 0xC) * M2C_FIELD(arg1, f32 *, 0x28))));
        M2C_FIELD(arg0, f32 *, 0x28) = (f32) -((M2C_FIELD(arg0, f32 *, 0x1C) * M2C_FIELD(arg1, f32 *, 0x2C)) + ((M2C_FIELD(arg0, f32 *, 4) * M2C_FIELD(arg1, f32 *, 0x24)) + (M2C_FIELD(arg0, f32 *, 0x10) * M2C_FIELD(arg1, f32 *, 0x28))));
        M2C_FIELD(arg0, f32 *, 0x2C) = (f32) -((M2C_FIELD(arg0, f32 *, 0x20) * M2C_FIELD(arg1, f32 *, 0x2C)) + ((M2C_FIELD(arg0, f32 *, 8) * M2C_FIELD(arg1, f32 *, 0x24)) + (M2C_FIELD(arg0, f32 *, 0x14) * M2C_FIELD(arg1, f32 *, 0x28))));
    }
    return var_r3;
}

void w3d_auto_801f7794(Ptr32<void> arg0, f32 farg0, f32 farg1, f32 farg2) {
    s32 var_ctr;
    Ptr32<void> var_r9;

    var_r9 = arg0;
    var_ctr = 3;
    do {
        M2C_FIELD(var_r9, f32 *, 0) = (f32) (M2C_FIELD(var_r9, f32 *, 0) * farg0);
        M2C_FIELD(var_r9, f32 *, 4) = (f32) (M2C_FIELD(var_r9, f32 *, 4) * farg1);
        M2C_FIELD(var_r9, f32 *, 8) = (f32) (M2C_FIELD(var_r9, f32 *, 8) * farg2);
        var_r9 += 0xC;
        var_ctr -= 1;
    } while (var_ctr != 0);
    M2C_FIELD(arg0, f32 *, 0x24) = (f32) (M2C_FIELD(arg0, f32 *, 0x24) * farg0);
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0x28) * farg1);
    M2C_FIELD(arg0, f32 *, 0x2C) = (f32) (M2C_FIELD(arg0, f32 *, 0x2C) * farg2);
}

void w3d_auto_801f77f4(Ptr32<void> arg0, f32 farg0, f32 farg1, f32 farg2) {
    M2C_FIELD(arg0, f32 *, 0x24) = (f32) (M2C_FIELD(arg0, f32 *, 0x24) + farg0);
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0x28) + farg1);
    M2C_FIELD(arg0, f32 *, 0x2C) = (f32) (M2C_FIELD(arg0, f32 *, 0x2C) + farg2);
}

void w3d_auto_801f781c(Ptr32<void> arg0, f32 farg0, f32 farg1, f32 farg2) {
    s32 var_ctr;
    Ptr32<void> var_r3;

    var_r3 = arg0;
    var_ctr = 3;
    do {
        M2C_FIELD(var_r3, f32 *, 0) = (f32) (M2C_FIELD(var_r3, f32 *, 0) * farg0);
        M2C_FIELD(var_r3, f32 *, 0xC) = (f32) (M2C_FIELD(var_r3, f32 *, 0xC) * farg1);
        M2C_FIELD(var_r3, f32 *, 0x18) = (f32) (M2C_FIELD(var_r3, f32 *, 0x18) * farg2);
        var_r3 += 4;
        var_ctr -= 1;
    } while (var_ctr != 0);
}

void w3d_auto_801f7854(Ptr32<void> arg0, f32 farg0, f32 farg1, f32 farg2) {
    s32 var_ctr;
    Ptr32<void> var_r3;

    var_r3 = arg0;
    var_ctr = 3;
    do {
        M2C_FIELD(var_r3, f32 *, 0x24) = (f32) (M2C_FIELD(var_r3, f32 *, 0x24) + ((farg2 * M2C_FIELD(var_r3, f32 *, 0x18)) + ((farg0 * M2C_FIELD(var_r3, f32 *, 0)) + (farg1 * M2C_FIELD(var_r3, f32 *, 0xC)))));
        var_r3 += 4;
        var_ctr -= 1;
    } while (var_ctr != 0);
}

extern s32 lbl_804AB8F8;

s32 w3d_auto_801f7c10(void) {
    return lbl_804AB8F8;
}

extern s32 lbl_804AB8F8;

void w3d_auto_801f7c18(void) {
    lbl_804AB8F8 = 0;
}

s32 w3d_auto_801f87f0(Ptr32<void> arg0) {
    return M2C_FIELD(arg0, u8 *, 0) | (M2C_FIELD(arg0, u8 *, 1) << 8) | (M2C_FIELD(arg0, u8 *, 2) << 0x10) | (M2C_FIELD(arg0, u8 *, 3) << 0x18);
}

s32 w3d_auto_801f881c(Ptr32<void> arg0) {
    return M2C_FIELD(arg0, u8 *, 0) | (M2C_FIELD(arg0, u8 *, 1) << 8);
}

s32 w3d_auto_801f9154(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    return 0;
}

s32 w3d_auto_801f96bc(void) {
    return 0x80004001;
}

s32 w3d_auto_801fb220(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x108) < 0) {
        fn_80302104(M2C_FIELD(arg0, s32 *, 0x80), 0);
    }
    M2C_FIELD(arg0, s32 *, 0x108) = (s32) (M2C_FIELD(arg0, s32 *, 0x108) & 0x7FFFFFFF);
    return 0;
}

s32 w3d_auto_801fc47c(void) {
    return 0x80004001;
}

}
