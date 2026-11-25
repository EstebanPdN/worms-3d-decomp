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


M2C_UNK fn_80295CEC(void *);                        /* extern */
M2C_UNK fn_80296498();                              /* extern */
M2C_UNK fn_802958D8();                              /* extern */
M2C_UNK fn_80296598(void *, M2C_UNK);               /* extern */
s16 fn_8015F5A0(M2C_UNK *, M2C_UNK);                /* extern */
M2C_UNK fn_80162024(void *, s16 *, void *);               /* extern */
M2C_UNK fn_8029D07C();                              /* extern */
M2C_UNK fn_8029D578();                              /* extern */
M2C_UNK fn_802B1BD0(void *, void *);                           /* extern */
M2C_UNK fn_8015FD1C();                              /* extern */
M2C_UNK fn_802B1F98(void *);                           /* extern */
s32 fn_802B15E0(void *, float, float);                            /* extern */
M2C_UNK fn_80173F88(void *, s8 *);                     /* extern */
u32 fn_80178D1C(void *);                               /* extern */
M2C_UNK fn_8029E194();                              /* extern */
M2C_UNK fn_802A0C48();                              /* extern */
M2C_UNK fn_802A21EC(void *);                           /* extern */

void w3d_auto_8029623c(void *arg0, s32 arg1) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0xAC) != arg1) {
        M2C_FIELD(arg0, s32 *, 0xAC) = arg1;
        fn_80296498();
        if (((s32) M2C_FIELD(arg0, s32 *, 0x38) == 1) && ((s32) M2C_FIELD(arg0, s32 *, 0x48) == 0)) {
            fn_80295CEC(arg0);
        }
    }
}

void w3d_auto_80296298(void *arg0, s32 arg1) {
    s32 var_r11;
    s32 var_r9;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x40) != arg1) {
        var_r11 = 1;
        M2C_FIELD(arg0, s32 *, 0x40) = arg1;
        if ((s32) M2C_FIELD(arg0, s32 *, 0x3C) == 0) {
            var_r11 = 0;
        }
        var_r9 = 1;
        if ((s32) M2C_FIELD(arg0, s32 *, 0x38) == 0) {
            var_r9 = 0;
        }
        if (var_r11 & var_r9) {
            fn_802958D8();
        }
    }
}

void w3d_auto_80296378(void *arg0, f32 farg0, f32 farg1, f32 farg2) {
    s32 var_r0;
    s32 var_r11;
    s32 var_r9;

    var_r0 = 0;
    if (farg0 != M2C_FIELD(arg0, f32 *, 0x50)) {
        M2C_FIELD(arg0, f32 *, 0x50) = farg0;
        var_r0 = 1;
    }
    if (farg1 != M2C_FIELD(arg0, f32 *, 0x54)) {
        M2C_FIELD(arg0, f32 *, 0x54) = farg1;
        var_r0 = 1;
    }
    if (farg2 != M2C_FIELD(arg0, f32 *, 0x58)) {
        M2C_FIELD(arg0, f32 *, 0x58) = farg2;
        var_r0 = 1;
    }
    if (var_r0 == 1) {
        var_r11 = 1;
        if ((s32) M2C_FIELD(arg0, s32 *, 0x3C) == 0) {
            var_r11 = 0;
        }
        var_r9 = 1;
        if ((s32) M2C_FIELD(arg0, s32 *, 0x38) == 0) {
            var_r9 = 0;
        }
        if (var_r11 & var_r9) {
            fn_802958D8();
        }
    }
}

void w3d_auto_80296410(void *arg0, f32 farg0) {
    f32 temp_f0;
    f32 temp_f13;
    f32 var_f1;
    s32 var_r11;
    s32 var_r9;

    var_f1 = farg0;
    temp_f13 = M2C_FIELD(arg0, f32 *, 0x54) - M2C_FIELD(arg0, f32 *, 0x58);
    if (var_f1 > temp_f13) {
        var_f1 = temp_f13;
    }
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x50);
    if (var_f1 < temp_f0) {
        var_f1 = temp_f0;
    }
    if (var_f1 != M2C_FIELD(arg0, f32 *, 0x5C)) {
        var_r11 = 1;
        M2C_FIELD(arg0, f32 *, 0x5C) = var_f1;
        if ((s32) M2C_FIELD(arg0, s32 *, 0x3C) == 0) {
            var_r11 = 0;
        }
        var_r9 = 1;
        if ((s32) M2C_FIELD(arg0, s32 *, 0x38) == 0) {
            var_r9 = 0;
        }
        if (var_r11 & var_r9) {
            fn_802958D8();
        }
    }
}

void w3d_auto_80296518(void *arg0, s32 arg1) {
    s32 var_r11;
    s32 var_r9;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x48) != arg1) {
        M2C_FIELD(arg0, s32 *, 0x48) = arg1;
        fn_80296498();
        var_r11 = 1;
        if ((s32) M2C_FIELD(arg0, s32 *, 0x3C) == 0) {
            var_r11 = 0;
        }
        var_r9 = 1;
        if ((s32) M2C_FIELD(arg0, s32 *, 0x38) == 0) {
            var_r9 = 0;
        }
        if (var_r11 & var_r9) {
            fn_80295CEC(arg0);
        }
        fn_80296598(arg0, 0);
    }
}

void w3d_auto_8029677c(void *arg0, s32 arg1) {
    s32 var_r11;
    s32 var_r9;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x4C) != arg1) {
        M2C_FIELD(arg0, s32 *, 0x4C) = arg1;
        fn_80296498();
        var_r11 = 1;
        if ((s32) M2C_FIELD(arg0, s32 *, 0x3C) == 0) {
            var_r11 = 0;
        }
        var_r9 = 1;
        if ((s32) M2C_FIELD(arg0, s32 *, 0x38) == 0) {
            var_r9 = 0;
        }
        if (var_r11 & var_r9) {
            fn_80295CEC(arg0);
        }
        fn_80296598(arg0, 0);
    }
}

extern M2C_UNK lbl_804B0D9C;
extern M2C_UNK lbl_804B0DA4;
extern M2C_UNK lbl_804B0DAC;
extern M2C_UNK lbl_804B0DB4;
extern M2C_UNK lbl_804B0DBC;
extern M2C_UNK lbl_804B0DC4;
extern M2C_UNK lbl_804B0DCC;
extern M2C_UNK lbl_804B0DD4;
extern M2C_UNK lbl_804B0DDC;
extern M2C_UNK lbl_804B0DE4;
extern M2C_UNK lbl_804B0DEC;
extern M2C_UNK lbl_804B0DF4;
extern M2C_UNK lbl_804B0DFC;
extern M2C_UNK lbl_804B0E04;
extern M2C_UNK lbl_804B0E0C;
extern M2C_UNK lbl_804B0E14;
extern M2C_UNK lbl_804B0E1C;
extern M2C_UNK lbl_804B0E24;
extern M2C_UNK lbl_804B0E2C;
extern M2C_UNK lbl_804B0E34;
extern M2C_UNK lbl_804B0E3C;
extern M2C_UNK lbl_804B0E44;
extern M2C_UNK lbl_804B0E4C;

void w3d_auto_802972f0(s32 arg0) {
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
    s16 sp1C;
    s16 sp1E;
    s16 sp20;
    s16 sp22;
    s16 sp24;
    s16 sp26;
    s16 sp28;
    s16 sp2A;
    s16 sp2C;
    s16 sp2E;
    s16 sp30;
    s16 sp32;
    s16 sp34;

    sp8 = fn_8015F5A0(&lbl_804B0D9C, 1);
    fn_80162024(arg0, &sp8, arg0 + 0x20);
    spA = fn_8015F5A0(&lbl_804B0DB4, 1);
    fn_80162024(arg0, &spA, arg0 + 0x2C);
    spC = fn_8015F5A0(&lbl_804B0DA4, 1);
    fn_80162024(arg0, &spC, arg0 + 0x24);
    spE = fn_8015F5A0(&lbl_804B0DAC, 1);
    fn_80162024(arg0, &spE, arg0 + 0x28);
    sp10 = fn_8015F5A0(&lbl_804B0DC4, 1);
    fn_80162024(arg0, &sp10, arg0 + 0x34);
    sp12 = fn_8015F5A0(&lbl_804B0DBC, 1);
    fn_80162024(arg0, &sp12, arg0 + 0x38);
    sp14 = fn_8015F5A0(&lbl_804B0DCC, 1);
    fn_80162024(arg0, &sp14, arg0 + 0x3C);
    sp16 = fn_8015F5A0(&lbl_804B0DD4, 1);
    fn_80162024(arg0, &sp16, arg0 + 0x30);
    sp18 = fn_8015F5A0(&lbl_804B0DDC, 1);
    fn_80162024(arg0, &sp18, arg0 + 0x40);
    sp1A = fn_8015F5A0(&lbl_804B0DE4, 1);
    fn_80162024(arg0, &sp1A, arg0 + 0x44);
    sp1C = fn_8015F5A0(&lbl_804B0DEC, 1);
    fn_80162024(arg0, &sp1C, arg0 + 0x48);
    sp1E = fn_8015F5A0(&lbl_804B0DF4, 1);
    fn_80162024(arg0, &sp1E, arg0 + 0x4C);
    sp20 = fn_8015F5A0(&lbl_804B0DFC, 1);
    fn_80162024(arg0, &sp20, arg0 + 0x50);
    sp22 = fn_8015F5A0(&lbl_804B0E14, 1);
    fn_80162024(arg0, &sp22, arg0 + 0x54);
    sp24 = fn_8015F5A0(&lbl_804B0E1C, 1);
    fn_80162024(arg0, &sp24, arg0 + 0x58);
    sp26 = fn_8015F5A0(&lbl_804B0E24, 1);
    fn_80162024(arg0, &sp26, arg0 + 0x5C);
    sp28 = fn_8015F5A0(&lbl_804B0E3C, 1);
    fn_80162024(arg0, &sp28, arg0 + 0x60);
    sp2A = fn_8015F5A0(&lbl_804B0E44, 1);
    fn_80162024(arg0, &sp2A, arg0 + 0x64);
    sp2C = fn_8015F5A0(&lbl_804B0E0C, 1);
    fn_80162024(arg0, &sp2C, arg0 + 0x6C);
    sp2E = fn_8015F5A0(&lbl_804B0E2C, 1);
    fn_80162024(arg0, &sp2E, arg0 + 0x70);
    sp30 = fn_8015F5A0(&lbl_804B0E34, 1);
    fn_80162024(arg0, &sp30, arg0 + 0x74);
    sp32 = fn_8015F5A0(&lbl_804B0E4C, 1);
    fn_80162024(arg0, &sp32, arg0 + 0x1C);
    sp34 = fn_8015F5A0(&lbl_804B0E04, 1);
    fn_80162024(arg0, &sp34, arg0 + 0x68);
}

extern s32 lbl_804ABC0C;

void w3d_auto_802975f8(void) {
    lbl_804ABC0C = 0;
    fn_8029D07C();
}

void w3d_auto_80299a74(void) {
    fn_8029D578();
}

void w3d_auto_8029eae0(s32 arg0, void * arg_r4) {
    fn_802B1BD0(arg0 + 0x1C, arg_r4);
}

void w3d_auto_8029eb08(s32 arg0, s32 arg1) {
    if (arg1 == 1) {
        fn_8015FD1C();
        return;
    }
    fn_802B1F98(arg0 + 0x1C);
}

s32 w3d_auto_802a0db4(void *arg0, float arg_f1, float arg_f2) {
    void *temp_r30;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x178) != 0) {
        return fn_802B15E0(arg0 + 0x1C, arg_f1, arg_f2);
    }
    temp_r30 = arg0 + 0x1C;
    if (fn_802B15E0(temp_r30, arg_f1, arg_f2) == 1) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0xD0), M2C_UNK (**)(void *), 0x38)(temp_r30);
    }
    return 0;
}

s32 w3d_auto_802a1a00(void *arg0, u32 arg1) {
    s8 sp8;
    s8 sp9;

    fn_8029E194();
    if ((s32) M2C_FIELD(arg0, s32 *, 0x1A8) != 0) {
        if ((arg1 / fn_80178D1C(M2C_FIELD(arg0, s32 *, 0x184))) & 1) {
            sp8 = 0;
            fn_80173F88(M2C_FIELD(arg0, s32 *, 0x188), &sp8);
        } else {
            sp9 = 1;
            fn_80173F88(M2C_FIELD(arg0, s32 *, 0x188), &sp9);
        }
    }
    return 0;
}

void w3d_auto_802a1bc0(s32 arg0, s32 arg1) {
    if (arg1 == 1) {
        fn_8015FD1C();
        return;
    }
    fn_802B1F98(arg0 + 0x1C);
}

void w3d_auto_802a27f8(s32 arg0) {
    fn_802A0C48();
    fn_802A21EC(arg0);
}
