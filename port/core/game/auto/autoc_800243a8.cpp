#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autoc_800243a8.c"
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

M2C_UNK fn_80181640(s32, s32, Ptr32<M2C_UNK>, M2C_UNK, f32, f32, f32); /* extern */
M2C_UNK fn_8018179C(Ptr32<void>, s32, M2C_UNK);             /* extern */
extern f32 lbl_803777B0[];
extern f32 lbl_803777B4[];
Ptr32<s8> fn_80189704(Ptr32<Ptr32<void>>);                           /* extern */
extern Ptr32<void> lbl_804B1788;
M2C_UNK fn_802CD808(Ptr32<void>, M2C_UNK);                  /* extern */
M2C_UNK fn_802DF784();                              /* extern */
M2C_UNK fn_802E0168();                              /* extern */
s32 fn_801F3138(Ptr32<void>);                            /* extern */

void w3d_auto_800243a8(Ptr32<void> arg0, s32 arg1) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<Ptr32<void>> temp_r3_2;
    Ptr32<Ptr32<void>> temp_r3_3;
    Ptr32<Ptr32<void>> temp_r3_4;
    Ptr32<Ptr32<void>> temp_r3_5;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x1C);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x58)(temp_r3);
    temp_r3_2 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x24);
    M2C_FIELD(*temp_r3_2, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32)> *, 0x58)(temp_r3_2, arg1);
    temp_r3_3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x20);
    M2C_FIELD(*temp_r3_3, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32)> *, 0x58)(temp_r3_3, arg1);
    temp_r3_4 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x28);
    M2C_FIELD(*temp_r3_4, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32)> *, 0x58)(temp_r3_4, arg1);
    temp_r3_5 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x2C);
    M2C_FIELD(*temp_r3_5, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32)> *, 0x58)(temp_r3_5, arg1);
    return;
}

void w3d_auto_8002900c(Ptr32<void> arg0, s32 arg1) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<Ptr32<void>> temp_r3_2;
    Ptr32<void> temp_r9;

    M2C_FIELD(arg0, s32 *, 0x54) = arg1;
    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x28);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x58)(temp_r3);
    temp_r3_2 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x2C);
    M2C_FIELD(*temp_r3_2, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32)> *, 0x58)(temp_r3_2, arg1);
    return;
}

void w3d_auto_8003cf5c(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x24);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x58)(temp_r3);
    return;
}

void w3d_auto_8004e460(Ptr32<void> arg0) {
    M2C_UNK sp8;
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x20);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, M2C_UNK)> *, 0x58)(temp_r3, 1);
    fn_80181640(M2C_FIELD(arg0, s32 *, 0x1C), M2C_FIELD(arg0, s32 *, 0x40), &sp8, 0, (*lbl_803777B0), (*lbl_803777B4), (*lbl_803777B4));
    fn_80181640(M2C_FIELD(arg0, s32 *, 0x1C), M2C_FIELD(arg0, s32 *, 0x44), arg0 + 0x54, 1, (*lbl_803777B0), M2C_FIELD(arg0, f32 *, 0x4C), (*lbl_803777B4));
    fn_8018179C(w3d::G(M2C_FIELD(arg0, s32 *, 0x1C)), M2C_FIELD(arg0, s32 *, 0x54), 1);
    return;
}

void w3d_auto_800a14c4(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x24);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x58)(temp_r3);
    return;
}

void w3d_auto_800f0984(Ptr32<void> arg0, s8 arg1) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x1C);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x58)(temp_r3);
    *fn_80189704(M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x1C)) = arg1;
    return;
}

void w3d_auto_800f0c20(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x1C);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x58)(temp_r3);
    *fn_80189704(M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x1C)) = 0;
    return;
}

void w3d_auto_800fc1f0(s32 arg0, s32 arg1) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(lbl_804B1788, Ptr32<Ptr32<void>> *, 0x64);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x84)(temp_r3, arg0, arg1);
    return;
}

void w3d_auto_800fc230(s32 arg0, s32 arg1) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(lbl_804B1788, Ptr32<Ptr32<void>> *, 0x64);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x88)(temp_r3, arg0, arg1);
    return;
}

void w3d_auto_800fc270(s32 arg0, s32 arg1) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(lbl_804B1788, Ptr32<Ptr32<void>> *, 0x64);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x8C)(temp_r3, arg0, arg1);
    return;
}

void w3d_auto_800fc2b0(s32 arg0, s32 arg1) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(lbl_804B1788, Ptr32<Ptr32<void>> *, 0x64);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x94)(temp_r3, arg0, arg1);
    return;
}

void w3d_auto_800fc2f0(s32 arg0, s32 arg1) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(lbl_804B1788, Ptr32<Ptr32<void>> *, 0x64);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x90)(temp_r3, arg0, arg1);
    return;
}

void w3d_auto_800fc330(s32 arg0, s32 arg1) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(lbl_804B1788, Ptr32<Ptr32<void>> *, 0x64);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x98)(temp_r3, arg0, arg1);
    return;
}

void w3d_auto_800fc370(s32 arg0, s32 arg1) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(lbl_804B1788, Ptr32<Ptr32<void>> *, 0x64);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0xA0)(temp_r3, arg0, arg1);
    return;
}

void w3d_auto_800fc69c(s32 arg0, s32 arg1) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(lbl_804B1788, Ptr32<Ptr32<void>> *, 0x64);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x74)(temp_r3, arg0, arg1);
    return;
}

void w3d_auto_800fd488(s32 arg0, s32 arg1) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(lbl_804B1788, Ptr32<Ptr32<void>> *, 0x64);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0xAC)(temp_r3, arg0, arg1);
    return;
}

void w3d_auto_800fd5f4(s32 arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(lbl_804B1788, Ptr32<Ptr32<void>> *, 0x64);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32)> *, 0xB8)(temp_r3, arg0);
    return;
}

void w3d_auto_800ff634(Ptr32<void> arg0, s32 arg1) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<Ptr32<void>> temp_r3_2;
    Ptr32<Ptr32<void>> temp_r3_3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x20);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x58)(temp_r3);
    temp_r3_2 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x1C);
    M2C_FIELD(*temp_r3_2, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32)> *, 0x58)(temp_r3_2, arg1);
    temp_r3_3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x24);
    M2C_FIELD(*temp_r3_3, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32)> *, 0x58)(temp_r3_3, arg1);
    return;
}

void w3d_auto_80160e34(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x1C);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x44)(temp_r3);
    return;
}

void w3d_auto_8016ece0(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x20);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x14)(temp_r3);
    return;
}

s32 w3d_auto_8019d82c(s32 arg0, Ptr32<Ptr32<void>> arg1) {
    s32 temp_r30;
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    temp_r30 = M2C_FIELD(temp_r9, Ptr32<s32 (Ptr32<Ptr32<void>>)> *, 0x24)(arg1);
    fn_802DF784();
    fn_802CD808(w3d::G(temp_r30), -2);
    return 0;
}

void w3d_auto_8019fe48(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x14);
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0x24)(temp_r3);
    return;
}

s32 w3d_auto_801a0118(s32 arg0, Ptr32<Ptr32<void>> arg1) {
    s32 temp_r30;
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    temp_r30 = M2C_FIELD(temp_r9, Ptr32<s32 (Ptr32<Ptr32<void>>)> *, 0x24)(arg1);
    fn_802E0168();
    fn_802CD808(w3d::G(temp_r30), -2);
    return 0;
}

s32 w3d_auto_801f30c0(Ptr32<void> arg0) {
    s32 temp_r0;
    s32 temp_r3_2;
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0x20);
    if (temp_r0 >= 0) {
        goto block_5;
    }
    if (temp_r0 & 0x40000000) {
        goto block_3;
    }
    if (temp_r0 & 0x20000000) {
        goto block_4;
    }
block_3:
    return M2C_FIELD(arg0, s32 *, 0x14);
block_4:
    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x24);
    temp_r9 = *temp_r3;
    return M2C_FIELD(temp_r9, Ptr32<s32 (Ptr32<Ptr32<void>>)> *, 0x28)(temp_r3);
block_5:
    temp_r3_2 = fn_801F3138(arg0);
    M2C_FIELD(arg0, s32 *, 0x20) = (s32) (M2C_FIELD(arg0, s32 *, 0x20) | 0x80000000);
    return temp_r3_2;
}

void w3d_auto_801fe708(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x2C)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801fe740(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x34)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801fe824(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x3C)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801fe85c(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x3C)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801fe948(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x38)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801fe980(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x38)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801fea64(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x4C)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801fea9c(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x44)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801feb80(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x48)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801febb8(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x40)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801fec9c(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x5C)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801fecd4(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x4C)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801fedb8(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x58)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801fedf0(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x48)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801feee8(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x6C)(arg1, arg2, arg4);
    return;
}

void w3d_auto_801fef20(s32 arg0, Ptr32<Ptr32<void>> arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ptr32<void> temp_r9;

    temp_r9 = *arg1;
    M2C_FIELD(temp_r9, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, s32)> *, 0x54)(arg1, arg2, arg4);
    return;
}

}
