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
M2C_UNK fn_80162024(void *, s16 *, void *);         /* extern */
M2C_UNK fn_80287D30();                              /* extern */
M2C_UNK fn_8028A3FC();                              /* extern */
M2C_UNK fn_802B1BD0(void *, void *);                           /* extern */
M2C_UNK fn_8015FD1C();                              /* extern */
M2C_UNK fn_802B1F98(void *);                           /* extern */
void *fn_80165254();                                /* extern */
M2C_UNK fn_8028D34C(void *);                        /* extern */
M2C_UNK fn_8028D3B8(void *);                        /* extern */
M2C_UNK fn_802B0B84(void *, void *, s32);              /* extern */
M2C_UNK fn_802B0FEC(void *);                           /* extern */
M2C_UNK fn_802B0990(void *, void *);                           /* extern */
M2C_UNK fn_802B15E0(void *, float, float);                           /* extern */

extern M2C_UNK lbl_804B0BCC;
extern M2C_UNK lbl_804B0BEC;
extern M2C_UNK lbl_804B0BF4;
extern M2C_UNK lbl_804B0BFC;
extern M2C_UNK lbl_804B0C04;

void w3d_auto_80287760(void *arg0) {
    s16 sp8;
    s16 spA;
    s16 spC;
    s16 spE;
    s16 sp10;

    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    sp8 = fn_8015F5A0(&lbl_804B0BCC, 1);
    fn_80162024(arg0, &sp8, arg0 + 0x20);
    spA = fn_8015F5A0(&lbl_804B0BF4, 1);
    fn_80162024(arg0, &spA, arg0 + 0x24);
    spC = fn_8015F5A0(&lbl_804B0BEC, 1);
    fn_80162024(arg0, &spC, arg0 + 0x28);
    spE = fn_8015F5A0(&lbl_804B0BFC, 1);
    fn_80162024(arg0, &spE, arg0 + 0x2C);
    sp10 = fn_8015F5A0(&lbl_804B0C04, 1);
    fn_80162024(arg0, &sp10, arg0 + 0x30);
}

s32 w3d_auto_80287c38(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        if ((s32) M2C_FIELD(arg0, s32 *, 0x120) >= 0) {
            fn_80287D30();
        }
        M2C_FIELD(arg0, s32 *, 0x120) = (s32) (M2C_FIELD(arg0, s32 *, 0x120) & 0x7FFFFFFF);
    }
    return 0;
}

void w3d_auto_80289a08(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x3C0) != 0) {
        fn_8028A3FC();
    }
}

void w3d_auto_8028b7c0(s32 arg0, void * arg_r4) {
    fn_802B1BD0(arg0 + 0x1C, arg_r4);
}

void w3d_auto_8028b7e4(s32 arg0, s32 arg1) {
    if (arg1 == 1) {
        fn_8015FD1C();
        return;
    }
    fn_802B1F98(arg0 + 0x1C);
}

void w3d_auto_8028d1e4(void *arg0) {
    void *temp_r11;

    fn_802B0B84(arg0 + 0x1C, arg0, M2C_FIELD(fn_80165254(), s32 *, 0x34));
    temp_r11 = M2C_FIELD(arg0, void **, 0x28);
    if (((s32) M2C_FIELD(M2C_FIELD(temp_r11, void **, 0x78), u16 *, -4) != 0) && ((s32) M2C_FIELD(M2C_FIELD(temp_r11, void **, 0x74), u16 *, -4) != 0)) {
        M2C_FIELD(arg0, s32 *, 0xE8) = 1;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0xE8) == 0) {
        M2C_FIELD(arg0, s32 *, 0xE0) = 2;
    }
    fn_8028D3B8(arg0);
    fn_8028D34C(arg0);
}

void w3d_auto_8028d274(void *arg0) {
    fn_802B0FEC(arg0 + 0x1C);
    M2C_FIELD(arg0, s32 *, 0xE0) = 2;
}

void w3d_auto_8028d2ac(s32 arg0, void * arg_r4) {
    fn_802B1BD0(arg0 + 0x1C, arg_r4);
}

void w3d_auto_8028d2d0(s32 arg0, void * arg_r4) {
    fn_802B0990(arg0 + 0x1C, arg_r4);
}

void w3d_auto_8028d2f4(s32 arg0, s32 arg1) {
    if (arg1 == 1) {
        fn_8015FD1C();
        return;
    }
    fn_802B1F98(arg0 + 0x1C);
}

void w3d_auto_8028d328(s32 arg0, float arg_f1, float arg_f2) {
    fn_802B15E0(arg0 + 0x1C, arg_f1, arg_f2);
}
