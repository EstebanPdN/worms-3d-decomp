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


M2C_UNK fn_8028D34C(void *);                           /* extern */
M2C_UNK fn_802B2344(void *, int);                           /* extern */
M2C_UNK fn_800C4604(void *);                           /* extern */
M2C_UNK fn_8035EE24(void *);                           /* extern */
s32 fn_800C4660(void *);                            /* extern */
s32 fn_8015CCBC(void *);                               /* extern */
M2C_UNK fn_8028E9C0(void *);                        /* extern */
s16 fn_8015F5A0(M2C_UNK *, M2C_UNK);                /* extern */
M2C_UNK fn_80162024(void *, s16 *, void *);         /* extern */

void w3d_auto_8028dbf8(s32 arg0, void * arg_r4) {
    fn_802B2344(arg0 + 0x1C, arg_r4);
    fn_8028D34C(arg0);
}

void w3d_auto_8028e444(s32 arg0) {
    fn_800C4604(arg0 + 0x48);
    fn_800C4604(arg0 + 0x5C);
    fn_8035EE24(arg0 + 0x78);
}

extern void *lbl_804AAABC;
extern s32 lbl_804B1788;

s32 w3d_auto_8028e484(void *arg0) {
    if (((s32) M2C_FIELD(arg0, s32 *, 0x40) == 0) && (fn_800C4660(arg0 + 0x48) != 0) && (fn_8015CCBC(lbl_804B1788) == 0) && ((s32) M2C_FIELD(lbl_804AAABC, s32 *, 0xD0) == 7)) {
        fn_8028E9C0(arg0);
    }
    return 0x64;
}

extern M2C_UNK lbl_804B0CA4;
extern M2C_UNK lbl_804B0CAC;
extern M2C_UNK lbl_804B0CB4;
extern M2C_UNK lbl_804B0CBC;
extern M2C_UNK lbl_804B0CC4;
extern M2C_UNK lbl_804B0CCC;
extern M2C_UNK lbl_804B0CD4;
extern M2C_UNK lbl_804B0CE4;

void w3d_auto_8028e4f4(void *arg0) {
    s16 sp8;
    s16 spA;
    s16 spC;
    s16 spE;
    s16 sp10;
    s16 sp12;
    s16 sp14;
    s16 sp16;

    sp8 = fn_8015F5A0(&lbl_804B0CA4, 1);
    fn_80162024(arg0, &sp8, arg0 + 0x1C);
    spA = fn_8015F5A0(&lbl_804B0CAC, 1);
    fn_80162024(arg0, &spA, arg0 + 0x20);
    spC = fn_8015F5A0(&lbl_804B0CB4, 1);
    fn_80162024(arg0, &spC, arg0 + 0x24);
    spE = fn_8015F5A0(&lbl_804B0CBC, 1);
    fn_80162024(arg0, &spE, arg0 + 0x28);
    sp10 = fn_8015F5A0(&lbl_804B0CC4, 1);
    fn_80162024(arg0, &sp10, arg0 + 0x2C);
    sp12 = fn_8015F5A0(&lbl_804B0CCC, 1);
    fn_80162024(arg0, &sp12, arg0 + 0x30);
    sp14 = fn_8015F5A0(&lbl_804B0CD4, 1);
    fn_80162024(arg0, &sp14, arg0 + 0x34);
    sp16 = fn_8015F5A0(&lbl_804B0CE4, 1);
    fn_80162024(arg0, &sp16, arg0 + 0x38);
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
}

extern s32 lbl_804ABBF4;

void w3d_auto_8028e624(void) {
    lbl_804ABBF4 = 0;
}
