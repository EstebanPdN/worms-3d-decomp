#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "auto_8028f338.c"
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


s16 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
M2C_UNK fn_80162024(Ptr32<void>, Ptr32<s16>, Ptr32<void>);               /* extern */
M2C_UNK fn_80296498(Ptr32<void>);                           /* extern */
M2C_UNK fn_80296598(Ptr32<void>, M2C_UNK);                  /* extern */
M2C_UNK fn_8029556C();                              /* extern */

extern M2C_UNK lbl_804B0CFC;
extern M2C_UNK lbl_804B0D04;
extern M2C_UNK lbl_804B0D0C;
extern M2C_UNK lbl_804B0D14;
extern M2C_UNK lbl_804B0D1C;
extern M2C_UNK lbl_804B0D24;
extern M2C_UNK lbl_804B0D2C;
extern M2C_UNK lbl_804B0D34;
extern M2C_UNK lbl_804B0D3C;
extern M2C_UNK lbl_804B0D44;

void w3d_auto_8028f338(s32 arg0) {
    s16 sp8;
    s16 spA;
    s16 spC;
    s16 spE;
    s16 sp10;
    s16 sp12;
    s16 sp14;
    s16 sp16;
    s16 sp18;
    s16 sp1A;

    sp8 = fn_8015F5A0(&lbl_804B0CFC, 1);
    fn_80162024(w3d::G(arg0), &sp8, w3d::G(arg0 + 0x1C));
    spA = fn_8015F5A0(&lbl_804B0D1C, 1);
    fn_80162024(w3d::G(arg0), &spA, w3d::G(arg0 + 0x30));
    spC = fn_8015F5A0(&lbl_804B0D04, 1);
    fn_80162024(w3d::G(arg0), &spC, w3d::G(arg0 + 0x24));
    spE = fn_8015F5A0(&lbl_804B0D0C, 1);
    fn_80162024(w3d::G(arg0), &spE, w3d::G(arg0 + 0x28));
    sp10 = fn_8015F5A0(&lbl_804B0D14, 1);
    fn_80162024(w3d::G(arg0), &sp10, w3d::G(arg0 + 0x2C));
    sp12 = fn_8015F5A0(&lbl_804B0D24, 1);
    fn_80162024(w3d::G(arg0), &sp12, w3d::G(arg0 + 0x34));
    sp14 = fn_8015F5A0(&lbl_804B0D44, 1);
    fn_80162024(w3d::G(arg0), &sp14, w3d::G(arg0 + 0x3C));
    sp16 = fn_8015F5A0(&lbl_804B0D2C, 1);
    fn_80162024(w3d::G(arg0), &sp16, w3d::G(arg0 + 0x40));
    sp18 = fn_8015F5A0(&lbl_804B0D34, 1);
    fn_80162024(w3d::G(arg0), &sp18, w3d::G(arg0 + 0x38));
    sp1A = fn_8015F5A0(&lbl_804B0D3C, 1);
    fn_80162024(w3d::G(arg0), &sp1A, w3d::G(arg0 + 0x20));
}

extern s32 lbl_804ABBFC;

void w3d_auto_8028f4a0(void) {
    lbl_804ABBFC = 0;
}

extern M2C_UNK lbl_804B0D5C;
extern M2C_UNK lbl_804B0D64;
extern M2C_UNK lbl_804B0D6C;
extern M2C_UNK lbl_804B0D74;
extern M2C_UNK lbl_804B0D7C;
extern M2C_UNK lbl_804B0D84;
extern M2C_UNK lbl_804B0D8C;
extern M2C_UNK lbl_804B0D94;

void w3d_auto_802950c8(s32 arg0) {
    s16 sp8;
    s16 spA;
    s16 spC;
    s16 spE;
    s16 sp10;
    s16 sp12;
    s16 sp14;
    s16 sp16;

    sp8 = fn_8015F5A0(&lbl_804B0D8C, 1);
    fn_80162024(w3d::G(arg0), &sp8, w3d::G(arg0 + 0xB8));
    spA = fn_8015F5A0(&lbl_804B0D6C, 1);
    fn_80162024(w3d::G(arg0), &spA, w3d::G(arg0 + 0xC0));
    spC = fn_8015F5A0(&lbl_804B0D74, 1);
    fn_80162024(w3d::G(arg0), &spC, w3d::G(arg0 + 0xC4));
    spE = fn_8015F5A0(&lbl_804B0D7C, 1);
    fn_80162024(w3d::G(arg0), &spE, w3d::G(arg0 + 0xC8));
    sp10 = fn_8015F5A0(&lbl_804B0D84, 1);
    fn_80162024(w3d::G(arg0), &sp10, w3d::G(arg0 + 0xCC));
    sp12 = fn_8015F5A0(&lbl_804B0D94, 1);
    fn_80162024(w3d::G(arg0), &sp12, w3d::G(arg0 + 0xBC));
    sp14 = fn_8015F5A0(&lbl_804B0D5C, 1);
    fn_80162024(w3d::G(arg0), &sp14, w3d::G(arg0 + 0xD0));
    sp16 = fn_8015F5A0(&lbl_804B0D64, 1);
    fn_80162024(w3d::G(arg0), &sp16, w3d::G(arg0 + 0xD4));
    fn_80296598(w3d::G(arg0), 0);
    fn_80296498(w3d::G(arg0));
}

void w3d_auto_8029550c(Ptr32<void> arg0, f32 farg0) {
    s32 var_r11;
    s32 var_r9;

    if (M2C_FIELD(arg0, f32 *, 0x30) != farg0) {
        var_r11 = 1;
        M2C_FIELD(arg0, f32 *, 0x30) = farg0;
        if ((s32) M2C_FIELD(arg0, s32 *, 0x3C) == 0) {
            var_r11 = 0;
        }
        var_r9 = 1;
        if ((s32) M2C_FIELD(arg0, s32 *, 0x38) == 0) {
            var_r9 = 0;
        }
        if (var_r11 & var_r9) {
            fn_8029556C();
        }
    }
}

}
