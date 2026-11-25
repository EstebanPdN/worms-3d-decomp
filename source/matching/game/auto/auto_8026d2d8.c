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


s16 fn_8015F5A0(M2C_UNK *, M2C_UNK);                /* extern */
M2C_UNK fn_80162024(void *, s16 *, void *);               /* extern */
M2C_UNK fn_8026DBE8(void *);                           /* extern */
M2C_UNK fn_8015FD1C();                              /* extern */
M2C_UNK fn_802B1F98(void *);                           /* extern */
M2C_UNK fn_802B1BD0(void *, void *);                           /* extern */
M2C_UNK fn_8027014C(void *);                           /* extern */
M2C_UNK fn_802B2344(void *, int);                           /* extern */
M2C_UNK fn_802B0FEC(void *);                           /* extern */
M2C_UNK fn_802CC58C(s32);                           /* extern */
M2C_UNK fn_80280370();                              /* extern */
M2C_UNK fn_802B0668(void *);                           /* extern */
M2C_UNK fn_802870FC(void *);                           /* extern */

extern M2C_UNK lbl_804B0AD8;

void w3d_auto_8026d2d8(s32 arg0) {
    s16 sp8;

    sp8 = fn_8015F5A0(&lbl_804B0AD8, 1);
    fn_80162024(arg0, &sp8, arg0 + 0x1C);
    fn_8026DBE8(arg0);
}

void w3d_auto_8026eca8(s32 arg0, s32 arg1) {
    if (arg1 == 1) {
        fn_8015FD1C();
        return;
    }
    fn_802B1F98(arg0 + 0x1C);
}

void w3d_auto_8026ecdc(s32 arg0, void * arg_r4) {
    fn_802B1BD0(arg0 + 0x1C, arg_r4);
}

void w3d_auto_802702c8(s32 arg0, void * arg_r4) {
    fn_802B2344(arg0 + 0x1C, arg_r4);
    fn_8027014C(arg0);
}

void w3d_auto_80270bdc(s32 arg0) {
    fn_802B0FEC(arg0 + 0x1C);
}

void w3d_auto_80270c04(s32 arg0, s32 arg1) {
    if (arg1 == 1) {
        fn_8015FD1C();
        return;
    }
    fn_802B1F98(arg0 + 0x1C);
}

void w3d_auto_80271118(void *arg0) {
    fn_802CC58C(M2C_FIELD(arg0, s32 *, 0x20));
}

extern M2C_UNK lbl_804B0B3C;
extern M2C_UNK lbl_804B0B44;
extern M2C_UNK lbl_804B0B4C;
extern M2C_UNK lbl_804B0B54;
extern M2C_UNK lbl_804B0B5C;
extern M2C_UNK lbl_804B0B64;
extern M2C_UNK lbl_804B0B6C;
extern M2C_UNK lbl_804B0B74;
extern M2C_UNK lbl_804B0B7C;
extern M2C_UNK lbl_804B0B84;

void w3d_auto_8027bd04(s32 arg0) {
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

    fn_80280370();
    sp8 = fn_8015F5A0(&lbl_804B0B3C, 1);
    fn_80162024(arg0, &sp8, arg0 + 0x78);
    spA = fn_8015F5A0(&lbl_804B0B4C, 1);
    fn_80162024(arg0, &spA, arg0 + 0x80);
    spC = fn_8015F5A0(&lbl_804B0B44, 1);
    fn_80162024(arg0, &spC, arg0 + 0x7C);
    spE = fn_8015F5A0(&lbl_804B0B54, 1);
    fn_80162024(arg0, &spE, arg0 + 0x84);
    sp10 = fn_8015F5A0(&lbl_804B0B5C, 1);
    fn_80162024(arg0, &sp10, arg0 + 0x88);
    sp12 = fn_8015F5A0(&lbl_804B0B64, 1);
    fn_80162024(arg0, &sp12, arg0 + 0x8C);
    sp14 = fn_8015F5A0(&lbl_804B0B6C, 1);
    fn_80162024(arg0, &sp14, arg0 + 0x90);
    sp16 = fn_8015F5A0(&lbl_804B0B74, 1);
    fn_80162024(arg0, &sp16, arg0 + 0x94);
    sp18 = fn_8015F5A0(&lbl_804B0B7C, 1);
    fn_80162024(arg0, &sp18, arg0 + 0x98);
    sp1A = fn_8015F5A0(&lbl_804B0B84, 1);
    fn_80162024(arg0, &sp1A, arg0 + 0x9C);
}

extern s32 lbl_804ABBAC;

void w3d_auto_8027be70(void) {
    lbl_804ABBAC = 0;
}

s32 w3d_auto_80285b00(s32 arg0) {
    fn_802B0668(arg0 + 0x1C);
    return 0;
}

void w3d_auto_80285cf8(s32 arg0, s32 arg1) {
    if (arg1 == 1) {
        fn_8015FD1C();
        return;
    }
    fn_802B1F98(arg0 + 0x1C);
}

void w3d_auto_80285d2c(s32 arg0, void * arg_r4) {
    fn_802B1BD0(arg0 + 0x1C, arg_r4);
}

void w3d_auto_802870c4(s32 arg0, void * arg_r4) {
    fn_802B2344(arg0 + 0x1C, arg_r4);
    fn_802870FC(arg0);
}
