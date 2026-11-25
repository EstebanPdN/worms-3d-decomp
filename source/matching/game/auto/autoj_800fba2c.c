/* Decompiled automatically by m2c; statement order, callee return width or a
 * guarded call argument adjusted by tools/m2c_reorder.py and verified identical
 * to the original after linking. Types and names are m2c placeholders pending
 * review. */
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

M2C_UNK fn_800A82F0(void *, u16, s32);                      /* extern */
M2C_UNK fn_801613F0(void *, M2C_UNK);                  /* extern */
extern s32 lbl_804B1754;
M2C_UNK fn_800A8314(void *, u16, s32, s32);                 /* extern */
M2C_UNK fn_8010A8E0(void *, u16, s32);                      /* extern */
M2C_UNK fn_80069A0C(void *, u16, f32);                      /* extern */
M2C_UNK fn_80069A30(void *, u16, f32, f32);                 /* extern */
M2C_UNK fn_8019FE48();                              /* extern */
M2C_UNK fn_802CE30C(void *, M2C_UNK, s32);                  /* extern */
M2C_UNK fn_801EA704();                              /* extern */
M2C_UNK fn_802098D8(void *, s32);                           /* extern */
M2C_UNK fn_80209920(void *, s32);                           /* extern */
M2C_UNK fn_801F9DF8(void *, s32);                           /* extern */
M2C_UNK fn_801FAC4C();                              /* extern */
M2C_UNK fn_801F9F2C(void *, s32);                           /* extern */
s32 fn_80178C48();                                  /* extern */
M2C_UNK fn_80178C54(void *, s32 *);                         /* extern */
M2C_UNK fn_803426B4(s32);                           /* extern */

void w3d_auto_800fba2c(void *arg0) {
    fn_800A82F0(fn_801613F0(lbl_804B1754, 0xC), M2C_FIELD(arg0, u16 *, 0), M2C_FIELD(arg0, s32 *, 0xC));
    return;
}

void w3d_auto_800fba6c(void *arg0) {
    fn_800A8314(fn_801613F0(lbl_804B1754, 0x10), M2C_FIELD(arg0, u16 *, 0), M2C_FIELD(arg0, s32 *, 0xC), M2C_FIELD(arg0, s32 *, 0x10));
    return;
}

void w3d_auto_800fbab0(void *arg0) {
    fn_8010A8E0(fn_801613F0(lbl_804B1754, 0xC), M2C_FIELD(arg0, u16 *, 0), M2C_FIELD(arg0, s32 *, 0xC));
    return;
}

void w3d_auto_800fbaf0(void *arg0) {
    fn_80069A0C(fn_801613F0(lbl_804B1754, 0xC), M2C_FIELD(arg0, u16 *, 0), M2C_FIELD(arg0, f32 *, 0xC));
    return;
}

void w3d_auto_800fbb30(void *arg0) {
    fn_80069A30(fn_801613F0(lbl_804B1754, 0x10), M2C_FIELD(arg0, u16 *, 0), M2C_FIELD(arg0, f32 *, 0xC), M2C_FIELD(arg0, f32 *, 0x10));
    return;
}

void w3d_auto_8019fdd8(void *arg0) {
    fn_802CE30C(fn_8019FE48(), -0x2710, M2C_FIELD(arg0, s32 *, 0x18));
    return;
}

void w3d_auto_8019fe10(void *arg0) {
    fn_802CE30C(fn_8019FE48(), -0x2710, M2C_FIELD(arg0, s32 *, 0x1C));
    return;
}

void w3d_auto_801ea70c(s32 arg0) {
    fn_802098D8(fn_801EA704(), arg0);
    return;
}

void w3d_auto_801ea740(s32 arg0) {
    fn_80209920(fn_801EA704(), arg0);
    return;
}

void w3d_auto_801fa654(s32 arg0, s32 arg1) {
    fn_801F9DF8(fn_801FAC4C(), arg1);
    return;
}

void w3d_auto_801fa688(s32 arg0, s32 arg1) {
    fn_801F9F2C(fn_801FAC4C(), arg1);
    return;
}

void w3d_auto_802aff04(void *arg0) {
    s32 sp8;

    fn_803426B4(M2C_FIELD(arg0, s32 *, 0xB0));
    sp8 = fn_80178C48() + 1;
    fn_80178C54(fn_803426B4(M2C_FIELD(arg0, s32 *, 0xB0)), &sp8);
    return;
}

void w3d_auto_802aff50(void *arg0) {
    s32 sp8;

    fn_803426B4(M2C_FIELD(arg0, s32 *, 0xB0));
    sp8 = fn_80178C48() - 1;
    fn_80178C54(fn_803426B4(M2C_FIELD(arg0, s32 *, 0xB0)), &sp8);
    return;
}
