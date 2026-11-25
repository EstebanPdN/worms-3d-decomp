#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "auto_8009c850.c"
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


M2C_UNK fn_800FC6DC();                              /* extern */
M2C_UNK fn_80178C48();                              /* extern */
M2C_UNK fn_803426B4(s32);                           void fn_8009F778();                              void fn_8009F7CC(Ptr32<void>);                        /* extern */
M2C_UNK fn_800ED5F8(Ptr32<void>);                        void fn_8009F4DC(Ptr32<void>);                        void fn_8009F86C(Ptr32<void>);                        /* extern */
Ptr32<void> fn_801797B4();                                /* extern */
M2C_UNK fn_80341584(s32);                           /* extern */
M2C_UNK fn_800A1380(Ptr32<void>);                        /* extern */
Ptr32<void> fn_80165254();                                /* extern */
M2C_UNK fn_800A4DA4();                              /* extern */
s32 fn_8006E71C();                                  /* extern */
M2C_UNK fn_800ABA08(Ptr32<void>);                        /* extern */
M2C_UNK fn_800ABAF8(Ptr32<void>);                        /* extern */
s32 fn_800AC0F4(Ptr32<void>);                            /* extern */
M2C_UNK fn_800AC278();                              /* extern */
M2C_UNK fn_800AE220();                              /* extern */
M2C_UNK fn_8008ED18(M2C_UNK, M2C_UNK);              /* extern */
M2C_UNK fn_800CF5E0(Ptr32<void>);                        /* extern */
M2C_UNK fn_8002AFD0(Ptr32<void>);                        /* extern */
M2C_UNK fn_800FDE64(M2C_UNK);                       /* extern */
M2C_UNK fn_800FC1B0(Ptr32<s32>, s32);                    /* extern */
M2C_UNK fn_800D56BC();                              /* extern */
M2C_UNK fn_800DA750();                              /* extern */
M2C_UNK fn_80209920(Ptr32<M2C_UNK>, s32);                /* extern */
M2C_UNK fn_80209968(Ptr32<M2C_UNK>);                     /* extern */
u32 fn_80162BA8();                                  /* extern */
M2C_UNK fn_802098D8(Ptr32<M2C_UNK>, s32);                /* extern */

void w3d_auto_8009c850(Ptr32<void> arg0) {
    fn_803426B4(M2C_FIELD(arg0, s32 *, 0x20));
    fn_80178C48();
    fn_800FC6DC();
}

void w3d_auto_8009f250(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x150) == 2) {
        fn_8009F778();
    } else {
        fn_800ED5F8(arg0);
    }
    fn_8009F7CC(arg0);
}

void w3d_auto_8009f778(Ptr32<void> arg0) {
    Ptr32<void> temp_r30;

    fn_80341584(M2C_FIELD(arg0, s32 *, 0xC0));
    temp_r30 = fn_801797B4();
    fn_8009F4DC(arg0);
    if ((s32) M2C_FIELD(temp_r30, s32 *, 0x248) != 0) {
        fn_8009F86C(arg0);
    }
}

void w3d_auto_800a12c0(Ptr32<void> arg0) {
    M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(fn_80165254(), s32 *, 0x34);
    fn_800A1380(arg0);
}

void w3d_auto_800a4c50(void) {
    fn_800A4DA4();
}

void w3d_auto_800a8334(Ptr32<void> arg0, Ptr32<s32> arg1, Ptr32<s32> arg2) {
    *arg1 = M2C_FIELD(arg0, s32 *, 8);
    *arg2 = M2C_FIELD(arg0, s32 *, 0xC);
}

s32 w3d_auto_800aa5b4(Ptr32<void> arg0) {
    u32 temp_r30;

    if (fn_8006E71C() == 0) {
        if ((s32) M2C_FIELD(arg0, s32 *, 0x48) != 0) {
            temp_r30 = M2C_FIELD(fn_80165254(), u32 *, 0x34);
            if (temp_r30 > (u32) (M2C_FIELD(arg0, s32 *, 0x70) + fn_800AC0F4(arg0))) {
                fn_800ABA08(arg0);
            }
        }
        fn_800ABAF8(arg0);
    }
    return 0x14;
}

void w3d_auto_800ac0f4(Ptr32<void> arg0) {
    fn_803426B4(M2C_FIELD(arg0, s32 *, 0x80));
    fn_80178C48();
}

void w3d_auto_800ac238(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0xA8) == 0) {
        fn_800AC278();
        fn_800ABA08(arg0);
    }
}

void w3d_auto_800ae200(void) {
    fn_800AE220();
}

void w3d_auto_800ae9bc(Ptr32<void> arg0, Ptr32<void> arg1) {
    M2C_FIELD(arg0, f32 *, 0x50) = (f32) M2C_FIELD(arg1, f32 *, 0x98);
    M2C_FIELD(arg0, f32 *, 0x4C) = (f32) M2C_FIELD(arg1, f32 *, 0x9C);
}

extern s32 lbl_804AACC0;
extern s32 lbl_804AE468;
extern s32 lbl_804AE478;
extern s32 lbl_804AE470;
extern s32 lbl_804AE474;
extern s32 lbl_804AE488;
extern s32 lbl_804AE47C;
extern s32 lbl_804AE480;
extern s32 lbl_804AE484;
extern s32 lbl_804AE46C;

void w3d_auto_800b1240(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        lbl_804AE468 = lbl_804AACC0 + 0x4000;
        lbl_804AE470 = lbl_804AACC0 + 0x2E0;
        lbl_804AE474 = lbl_804AACC0 + 0x3070;
        lbl_804AE47C = lbl_804AACC0 + 0x3FF0;
        lbl_804AE480 = lbl_804AACC0 + 0x3FB0;
        lbl_804AE484 = lbl_804AACC0 + 0x3F30;
        lbl_804AE46C = lbl_804AACC0;
        lbl_804AE478 = lbl_804AACC0;
        lbl_804AE488 = lbl_804AACC0;
    }
}

s32 w3d_auto_800b7ec4(Ptr32<void> arg0) {
    return M2C_FIELD(arg0, s32 *, 4) + 0x120;
}

s32 w3d_auto_800b9810(void) {
    fn_8008ED18(1, 0xA);
    return 0;
}

s32 w3d_auto_800bf00c(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x2C) = arg1;
    return 0;
}

s32 w3d_auto_800ce440(Ptr32<void> arg0) {
    if ((fn_8006E71C() == 0) && ((s32) M2C_FIELD(arg0, s32 *, 0x2C) == 1)) {
        fn_800CF5E0(arg0);
    }
    return 0x14;
}

void w3d_auto_800cf010(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
    }
}

s32 w3d_auto_800d0f54(Ptr32<void> arg0) {
    return (s32) ((M2C_FIELD(arg0, s32 *, 0x20) - M2C_FIELD(arg0, s32 *, 0x1C)) * 0xB6DB6DB7) >> 2;
}

void w3d_auto_800d2cd0(Ptr32<void> arg0) {
    fn_800FDE64(0x9C4);
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
    fn_8002AFD0(arg0);
}

void w3d_auto_800d31d8(s32 arg0, s32 arg1) {
    s32 sp8;

    sp8 = arg1;
    fn_800FC1B0(&sp8, arg0 + 0x88);
}

s32 w3d_auto_800d5494(void) {
    fn_800D56BC();
    return 0;
}

void w3d_auto_800da488(void) {
    fn_800DA750();
}

void w3d_auto_800daffc(Ptr32<void> arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x4C) != 0) {
        M2C_FIELD(arg0, s32 *, 0x4C) = 0;
    }
}

extern M2C_UNK lbl_804AECAC;

void w3d_auto_800dc604(s32 arg0) {
    fn_80209920(&lbl_804AECAC, arg0);
    fn_80209968(&lbl_804AECAC);
}

u8 w3d_auto_800dc6fc(Ptr32<void> arg0, u32 arg1, Ptr32<void> arg2) {
    if (((s32) M2C_FIELD(arg2, u16 *, 0x1A4) != 0xFFFF) && (arg1 >= (u32) (M2C_FIELD(arg0, s32 *, 0x64) + M2C_FIELD(arg0, s32 *, 0x5C)))) {
        M2C_FIELD(arg0, u8 *, 0x68) = 0U;
        return 0U;
    }
    return M2C_FIELD(arg0, u8 *, 0x68);
}

void w3d_auto_800dca14(Ptr32<void> arg0, s32 arg1) {
    s8 var_r0;

    var_r0 = 1;
    if (arg1 == 0) {
        var_r0 = 0;
    }
    M2C_FIELD(arg0, s8 *, 0x68) = var_r0;
}

void w3d_auto_800dcbc4(Ptr32<void> arg0, Ptr32<void> arg1) {
    M2C_FIELD(arg0, f32 *, 0) = (f32) M2C_FIELD(arg1, f32 *, 0);
    M2C_FIELD(arg0, f32 *, 4) = (f32) M2C_FIELD(arg1, f32 *, 4);
    M2C_FIELD(arg0, f32 *, 8) = (f32) M2C_FIELD(arg1, f32 *, 8);
}

extern u32 lbl_804AEC54;

void w3d_auto_800dd918(Ptr32<void> arg0, s8 arg1, u32 arg2) {
    u32 temp_r9;
    u32 var_r3;

    if (arg2 != 0) {
        if ((s32) M2C_FIELD(arg0, s32 *, 0x6C) != 0) {
            var_r3 = fn_80162BA8();
        } else {
            temp_r9 = (lbl_804AEC54 * 0x41C64E6D) + 0x3039;
            lbl_804AEC54 = temp_r9;
            var_r3 = temp_r9;
        }
        M2C_FIELD(arg0, s8 *, 0x69) = (s8) (arg1 + (var_r3 % arg2));
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x69) = arg1;
}

extern s32 lbl_804AAE94;
extern s32 lbl_804AEC58;
extern s32 lbl_804AEC68;
extern s32 lbl_804AEC60;
extern s32 lbl_804AEC64;
extern s32 lbl_804AEC78;
extern s32 lbl_804AEC6C;
extern s32 lbl_804AEC70;
extern s32 lbl_804AEC74;
extern s32 lbl_804AEC5C;

void w3d_auto_800de850(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        lbl_804AEC58 = lbl_804AAE94 + 0x4000;
        lbl_804AEC60 = lbl_804AAE94 + 0x2E0;
        lbl_804AEC64 = lbl_804AAE94 + 0x3070;
        lbl_804AEC6C = lbl_804AAE94 + 0x3FF0;
        lbl_804AEC70 = lbl_804AAE94 + 0x3FB0;
        lbl_804AEC74 = lbl_804AAE94 + 0x3F30;
        lbl_804AEC5C = lbl_804AAE94;
        lbl_804AEC68 = lbl_804AAE94;
        lbl_804AEC78 = lbl_804AAE94;
    }
}

extern M2C_UNK lbl_804AECA4;

void w3d_auto_800de8d8(s32 arg0) {
    fn_802098D8(&lbl_804AECA4, arg0);
}

extern M2C_UNK lbl_804AECA4;

void w3d_auto_800de900(s32 arg0) {
    fn_80209920(&lbl_804AECA4, arg0);
    fn_80209968(&lbl_804AECA4);
}

}
