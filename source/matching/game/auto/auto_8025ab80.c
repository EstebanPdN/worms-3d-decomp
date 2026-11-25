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


s32 fn_8025CBE0(void *, u32);                          /* extern */
M2C_UNK fn_8025D020(void *, u32, s8);                  /* extern */
s16 fn_8015F5A0(M2C_UNK *, M2C_UNK);                /* extern */
M2C_UNK fn_80162024(void *, s16 *, void *);         /* extern */
void *fn_80165254();                                /* extern */
M2C_UNK fn_802B0668(void *);                           /* extern */
M2C_UNK fn_802B0FEC(void *);                           /* extern */
M2C_UNK fn_802B1BD0(void *, void *);                           /* extern */
M2C_UNK fn_8015FD1C();                              /* extern */
M2C_UNK fn_802B1F98(void *);                           /* extern */
M2C_UNK fn_8026026C(void *);                        /* extern */
M2C_UNK fn_802B2344(void *, int);                           /* extern */
M2C_UNK fn_8026857C(void *);                           /* extern */
s32 fn_802B15E0(void *, float, float);                            /* extern */

s8 w3d_auto_8025ab80(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x39);
}

s8 w3d_auto_8025ab94(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x38);
}

s8 w3d_auto_8025aba8(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x37);
}

s8 w3d_auto_8025abbc(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x36);
}

s8 w3d_auto_8025abd0(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x35);
}

s8 w3d_auto_8025abe4(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x26);
}

s8 w3d_auto_8025abf8(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x33);
}

s8 w3d_auto_8025ac0c(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x32);
}

s8 w3d_auto_8025ac20(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x31);
}

s8 w3d_auto_8025ac34(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x30);
}

s8 w3d_auto_8025ac48(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x2F);
}

s8 w3d_auto_8025ac5c(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x3A);
}

void w3d_auto_8025cb4c(s32 arg0, s32 arg1) {
    s32 temp_r31;
    s32 temp_r3;
    u32 var_r30;

    if (arg1 != 0) {
        var_r30 = 0U;
        do {
            temp_r31 = fn_8025CBE0(arg1, var_r30);
            temp_r3 = fn_8025CBE0(arg0, var_r30);
            if ((temp_r31 == -1) || (temp_r3 == -1)) {
                fn_8025D020(arg0, var_r30, -1);
            } else {
                fn_8025D020(arg0, var_r30, (s8) (temp_r31 + temp_r3));
            }
            var_r30 += 1;
        } while (var_r30 <= 0x3AU);
    }
}

s32 w3d_auto_8025d588(void *arg0) {
    void *temp_r9;

    temp_r9 = M2C_FIELD(arg0, void **, 0x3C);
    if ((s32) M2C_FIELD(temp_r9, s32 *, 0x18) != 0) {
        return M2C_FIELD(temp_r9, s32 *, 0x20);
    }
    return 0;
}

extern M2C_UNK lbl_804B0918;
extern M2C_UNK lbl_804B0920;
extern M2C_UNK lbl_804B0928;
extern M2C_UNK lbl_804B0930;
extern M2C_UNK lbl_804B0938;
extern M2C_UNK lbl_804B0940;
extern M2C_UNK lbl_804B0948;
extern M2C_UNK lbl_804B0950;

void w3d_auto_8025ddb8(void *arg0) {
    s16 sp8;
    s16 spA;
    s16 spC;
    s16 spE;
    s16 sp10;
    s16 sp12;
    s16 sp14;
    s16 sp16;

    sp8 = fn_8015F5A0(&lbl_804B0928, 1);
    fn_80162024(arg0, &sp8, arg0 + 0x1C);
    spA = fn_8015F5A0(&lbl_804B0948, 1);
    fn_80162024(arg0, &spA, arg0 + 0x20);
    spC = fn_8015F5A0(&lbl_804B0950, 1);
    fn_80162024(arg0, &spC, arg0 + 0x24);
    spE = fn_8015F5A0(&lbl_804B0930, 1);
    fn_80162024(arg0, &spE, arg0 + 0x28);
    sp10 = fn_8015F5A0(&lbl_804B0918, 1);
    fn_80162024(arg0, &sp10, arg0 + 0x2C);
    sp12 = fn_8015F5A0(&lbl_804B0938, 1);
    fn_80162024(arg0, &sp12, arg0 + 0x30);
    sp14 = fn_8015F5A0(&lbl_804B0940, 1);
    fn_80162024(arg0, &sp14, arg0 + 0x34);
    sp16 = fn_8015F5A0(&lbl_804B0920, 1);
    fn_80162024(arg0, &sp16, arg0 + 0x38);
    M2C_FIELD(arg0, s32 *, 0x3C) = (s32) M2C_FIELD(fn_80165254(), s32 *, 0x34);
}

s32 w3d_auto_8025f524(s32 arg0) {
    fn_802B0668(arg0 + 0x1C);
    return 0;
}

void w3d_auto_8025fa40(s32 arg0) {
    fn_802B0FEC(arg0 + 0x1C);
}

void w3d_auto_8025fa64(s32 arg0, void * arg_r4) {
    fn_802B1BD0(arg0 + 0x1C, arg_r4);
}

void w3d_auto_8025fbb4(s32 arg0, s32 arg1) {
    if (arg1 == 1) {
        fn_8015FD1C();
        return;
    }
    fn_802B1F98(arg0 + 0x1C);
}

void w3d_auto_802600e8(void *arg0, void * arg_r4) {
    s32 temp_r30;

    temp_r30 = arg0 + 0x1C;
    fn_802B2344(temp_r30, arg_r4);
    fn_8026026C(arg0);
    if ((s32) M2C_FIELD(arg0, s32 *, 0xB0) != 0) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0xD0), M2C_UNK (**)(s32), 0x38)(temp_r30);
    }
}

void w3d_auto_80266154(s32 arg0, void * arg_r4) {
    fn_802B1BD0(arg0 + 0x1C, arg_r4);
}

void w3d_auto_80266178(s32 arg0, s32 arg1) {
    if (arg1 == 1) {
        fn_8015FD1C();
        return;
    }
    fn_802B1F98(arg0 + 0x1C);
}

void w3d_auto_802670d4(s32 arg0, void * arg_r4) {
    fn_802B2344(arg0 + 0x1C, arg_r4);
    fn_8026857C(arg0);
}

void w3d_auto_80268568(void *arg0, s32 arg1) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x2B8), s32 *, 0x10) = arg1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x2BC), s32 *, 0x10) = arg1;
}

void w3d_auto_80269860(s32 arg0, void * arg_r4) {
    fn_802B1BD0(arg0 + 0x1C, arg_r4);
}

s32 w3d_auto_8026992c(void *arg0, float arg_f1, float arg_f2) {
    void *temp_r11;

    if (((s32) M2C_FIELD(arg0, s32 *, 0x8C) == 0) || ((s32) M2C_FIELD(arg0, s32 *, 0x1F4) == 0) || ((temp_r11 = M2C_FIELD(arg0, void **, 0x28), (((s32) M2C_FIELD(M2C_FIELD(temp_r11, void **, 0x94), u16 *, -4) == 0) != 0)) && ((s32) M2C_FIELD(M2C_FIELD(temp_r11, void **, 0x98), u16 *, -4) == 0))) {
        return 0;
    }
    return fn_802B15E0(arg0 + 0x1C, arg_f1, arg_f2);
}

extern void *lbl_804B1788;

s32 w3d_auto_8026ce4c(void *arg0) {
    s32 temp_r0;

    temp_r0 = M2C_FIELD(lbl_804B1788, s32 *, 0xAC);
    if (temp_r0 != 0) {
        M2C_FIELD(arg0, s32 *, 0x34) = temp_r0;
    }
    return M2C_FIELD(arg0, s32 *, 0x34);
}
