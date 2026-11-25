#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8contextfix_800ac278.c"
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
/* Inferred prototypes supported by existing matched callers and original register use. */
Ptr32<void> fn_80341584(Ptr32<void>);
Ptr32<void> fn_80343584(Ptr32<void>);
Ptr32<void> fn_803426B4(Ptr32<void>);
Ptr32<void> fn_80343744(Ptr32<void>);
Ptr32<void> fn_80179598(Ptr32<void>,int);
Ptr32<void> fn_801797B4(Ptr32<void>);
int fn_80178C48(Ptr32<void>);
Ptr32<void> fn_801613F0(Ptr32<void>,int);
int fn_8016239C(Ptr32<void>);
int fn_8015FC58(Ptr32<void>,Ptr32<void>);
Ptr32<void> fn_800C1620(Ptr32<void>,Ptr32<int>);
Ptr32<void> fn_80125FDC(Ptr32<void>,unsigned short,int);
unsigned fn_8015F5A0(Ptr32<void>,int);
int fn_80162024(Ptr32<void>,Ptr32<unsigned short>,Ptr32<void>);
int fn_8016115C(Ptr32<void>,Ptr32<void>,Ptr32<void>,Ptr32<void (void)>,int,int);
int fn_801629F8(Ptr32<void>,Ptr32<void>,Ptr32<void>,Ptr32<void (void)>,int,int);
int fn_8015F518(Ptr32<void>,Ptr32<const char>);
int fn_802EEE50(Ptr32<void>,Ptr32<const void>,unsigned,...);
int fn_802EF234(Ptr32<const char>,Ptr32<const char>);
Ptr32<void> fn_8020BB54(Ptr32<void>,Ptr32<const char>);
int fn_8020C5C4(Ptr32<void>);
int fn_80341588(Ptr32<void>);
Ptr32<void> fn_80212FD4(unsigned);
void fn_802134FC(Ptr32<void>);
Ptr32<void> fn_80164FC8(Ptr32<void>);
int fn_80181640(Ptr32<void>,int,Ptr32<void>,int,float,float,float);
int fn_80181CCC(Ptr32<void>,int);
int fn_801817E0(Ptr32<void>,int);
extern Ptr32<void> lbl_804B1754;
extern Ptr32<void> lbl_804B1788;
extern char lbl_8040DB38[];

s32 fn_800AC0F4(Ptr32<void>);                            /* extern */
M2C_UNK fn_800AC14C(Ptr32<void>, M2C_UNK);                       /* extern */
M2C_UNK fn_800FDD80(M2C_UNK, M2C_UNK, Ptr32<M2C_UNK>, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK fn_8011AFAC(Ptr32<void>, M2C_UNK);                  /* extern */
Ptr32<void> fn_80165254();                                /* extern */
extern M2C_UNK lbl_8045E788[];
extern M2C_UNK lbl_804AE398;
extern M2C_UNK lbl_804AE3A8;
extern M2C_UNK lbl_804AE3C0;

void s8_activate_and_post_800ac278(Ptr32<void> arg0) {
    Ptr32<void> temp_r30;
    Ptr32<void> temp_r30_2;
    Ptr32<void> temp_r30_3;

    if (((s32) M2C_FIELD(arg0, s32 *, 0xA8) == 0) && ((s32) M2C_FIELD(arg0, s32 *, 0xAC) == 0)) {
        fn_800AC14C(arg0,1);
    }
    if (((s32) M2C_FIELD(arg0, s32 *, 0x48) == 0) && (fn_800AC0F4(arg0) > 0)) {
        { Ptr32<void> manager=lbl_804B1754;
        M2C_FIELD(arg0, s32 *, 0x48) = 1;
        M2C_FIELD(arg0, s32 *, 0xA8) = 1;
        temp_r30 = fn_801613F0(manager, 8);
        M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AE398, 1);
        M2C_FIELD(temp_r30, Ptr32<s8> *, 4) = lbl_8040DB38;
        fn_8016239C(temp_r30); }
        M2C_FIELD(arg0, s32 *, 0x70) = (s32) M2C_FIELD(fn_80165254(), s32 *, 0x34);
        fn_800FDD80(0x64, 0, &(*lbl_8045E788), -1, 1);
        if ((s32) M2C_FIELD(arg0, s32 *, 0xA4) == 0) {
            M2C_FIELD(arg0, s32 *, 0xA4) = 1;
            temp_r30_2 = fn_801613F0(lbl_804B1754, 0xC);
            fn_8016239C(fn_80125FDC(temp_r30_2, (u32) fn_8015F5A0(&lbl_804AE3A8, 1), 0x30));
            temp_r30_3 = fn_801613F0(lbl_804B1754, 8);
            M2C_FIELD(temp_r30_3, s16 *, 0) = fn_8015F5A0(&lbl_804AE3C0, 1);
            M2C_FIELD(temp_r30_3, Ptr32<s8> *, 4) = lbl_8040DB38;
            fn_8016239C(temp_r30_3);
            fn_8011AFAC(w3d::G(M2C_FIELD(arg0, s32 *, 0x78)), 1);
        }
    }
}

}
