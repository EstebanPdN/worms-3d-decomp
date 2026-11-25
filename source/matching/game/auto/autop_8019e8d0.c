/* Decompiled automatically by m2c, with arguments the original forwards unchanged
 * made explicit (tools/m2c_fixups.py); verified identical to the original
 * after linking. Types and names are m2c placeholders pending review. */
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
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

/* Bitwise (reinterpret) cast */
#define M2C_BITWISE(type, expr) ((type)(expr))

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

M2C_UNK fn_801EF380(s32, u16, u8, s32, s32);        /* extern */
s32 fn_802CD7F4(void *);                               /* extern */
s32 *fn_802CDE08(s32, M2C_UNK);                          /* extern */
f32 fn_802DD10C(s32, M2C_UNK);                      /* extern */
M2C_UNK fn_801D25EC(s32, void *, s32, s32, s32, void *);                           /* extern */
M2C_UNK fn_801D2AAC(s32, s32, s32, void *);                           /* extern */
M2C_UNK fn_801E6F0C(void *);                              /* extern */
M2C_UNK fn_801FE1F8(s32);                           /* extern */
M2C_UNK fn_801F2798(void *);                              /* extern */
M2C_UNK fn_8020863C(void *, s32, s32, M2C_UNK);                       /* extern */
M2C_UNK fn_80209E64(void *);                              /* extern */
M2C_UNK fn_8020BF2C(void *, s16 *);                         /* extern */
M2C_UNK fn_80210AFC(void *);                              void fn_8020C5C4(s32);                              /* extern */
M2C_UNK fn_80341588(void *);                           /* extern */
M2C_UNK fn_80271518(void *, M2C_UNK);                       /* extern */
M2C_UNK fn_802B88B0(void *, M2C_UNK);                       /* extern */
f32 fn_802BC93C(void *, s32, s32);                     /* extern */

extern void **lbl_804AB728;

s32 w3d_auto_8019e8d0(s32 arg0) {
    s32 temp_r29;
    s32 temp_r30;
    s32 var_r28;
    void *temp_r9;

    var_r28 = 1;
    temp_r29 = *fn_802CDE08(arg0, 1);
    temp_r30 = (s32) fn_802DD10C(arg0, 2);
    if (fn_802CD7F4(arg0) <= 2) {
        goto block_2;
    }
    var_r28 = (s32) fn_802DD10C(arg0, 3);
block_2:
    temp_r9 = *lbl_804AB728;
    fn_801EF380(temp_r29, M2C_FIELD(temp_r9, u16 *, 4), M2C_FIELD(temp_r9, u8 *, 6), temp_r30, var_r28);
    return 0;
}

void w3d_auto_801d1fd4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    fn_801D25EC(arg0, arg1, arg2, arg3, arg4, arg0 + 0x24);
    return;
}

void w3d_auto_801d1ff8(s32 arg0, s32 arg1, s32 arg2) {
    fn_801D2AAC(arg0, arg1, arg2, arg0 + 0x24);
    return;
}

void w3d_auto_801d2138(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    fn_801D25EC(arg0, arg1, arg2, arg3, arg4, arg0 + 0x14);
    return;
}

void w3d_auto_801d215c(s32 arg0, s32 arg1, s32 arg2) {
    fn_801D2AAC(arg0, arg1, arg2, arg0 + 0x14);
    return;
}

void w3d_auto_801d229c(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    fn_801D25EC(arg0, arg1, arg2, arg3, arg4, arg0 + 0x34);
    return;
}

void w3d_auto_801d22c0(s32 arg0, s32 arg1, s32 arg2) {
    fn_801D2AAC(arg0, arg1, arg2, arg0 + 0x34);
    return;
}

void w3d_auto_801e6ec4(s32 arg0, s32 arg1) {
    fn_801E6F0C(arg0);
    if (!(arg1 & 1)) {
        goto block_2;
    }
    fn_801FE1F8(arg0);
block_2:
    return;
}

void w3d_auto_801f2758(s32 arg0, s32 arg1) {
    fn_801F2798(arg0);
    if (!(arg1 & 1)) {
        goto block_2;
    }
    fn_801FE1F8(arg0);
block_2:
    return;
}

void w3d_auto_80208a88(s32 arg0, s32 arg1, s32 arg2) {
    fn_8020863C(arg0, arg1, arg2, 0);
    return;
}

void w3d_auto_80209d10(s32 arg0, s32 arg1) {
    fn_80209E64(arg0);
    if (!(arg1 & 1)) {
        goto block_2;
    }
    fn_801FE1F8(arg0);
block_2:
    return;
}

s32 w3d_auto_8020c00c(s32 arg0, s32 arg1) {
    s16 sp8;

    sp8 = arg1 << 8;
    fn_8020BF2C(arg0, &sp8);
    return arg0;
}

void w3d_auto_80210abc(s32 arg0, s32 arg1) {
    fn_80210AFC(arg0);
    if (!(arg1 & 1)) {
        goto block_2;
    }
    fn_801FE1F8(arg0);
block_2:
    return;
}

void w3d_auto_8026c860(s32 arg0, s32 arg1) {
    fn_8020C5C4(arg0);
    fn_80341588(arg0);
    if (!(arg1 & 1)) {
        goto block_2;
    }
    fn_801FE1F8(arg0);
block_2:
    return;
}

void w3d_auto_80276e04(s32 arg0) {
    fn_80271518(arg0, 0);
    return;
}

void w3d_auto_802b83ac(void *arg0, s32 arg1, s32 arg2) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x124) == 0) {
        goto block_5;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x11C) == 0) {
        goto block_5;
    }
    if (arg1 == -1) {
        goto block_4;
    }
    fn_802B88B0(arg0, 0);
block_4:
    M2C_FIELD(arg0, f32 *, 0x134) = fn_802BC93C(M2C_FIELD(arg0, s32 *, 0x11C), arg1, arg2);
block_5:
    return;
}
