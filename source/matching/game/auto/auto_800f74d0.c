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


M2C_UNK fn_80209920(M2C_UNK *, s32);                /* extern */
M2C_UNK fn_800FCEC8(M2C_UNK, M2C_UNK);              /* extern */
s16 fn_8015F5A0(M2C_UNK *, M2C_UNK);                /* extern */
M2C_UNK fn_80162024(void *, s16 *, void *);               /* extern */
M2C_UNK fn_80101018();                              /* extern */
M2C_UNK fn_80102028();                              /* extern */
M2C_UNK fn_800E58FC(s32, M2C_UNK);                  /* extern */
M2C_UNK fn_800A8D00();                              /* extern */
s32 fn_8010BDC8(s32);                               /* extern */
M2C_UNK fn_8010BFB0(void *, s32, s32, s32);            /* extern */
M2C_UNK fn_8010C62C(void *, s32, s32, s32);            /* extern */
M2C_UNK fn_8010C494(void *, s32, s32, s32);            /* extern */
M2C_UNK fn_8010CA34(void *, s32, s32, s32);            /* extern */
s32 fn_8010BEBC(s32);                               /* extern */
M2C_UNK fn_8010CCAC(void *, s32, s32, s32);            /* extern */
M2C_UNK fn_8010D230(void *, s32, s32, s32);            /* extern */
M2C_UNK fn_8010D0A0(void *, s32, s32, s32);            /* extern */
M2C_UNK fn_8010D630(void *, s32, s32, s32);            /* extern */
M2C_UNK fn_800D776C();                              /* extern */
M2C_UNK fn_800D7788();                              /* extern */
M2C_UNK fn_800D77A8();                              /* extern */
M2C_UNK fn_8004E460();                              /* extern */
M2C_UNK fn_8004E4F8();                              /* extern */
s32 fn_80178C48(void *);                               /* extern */
M2C_UNK fn_80178C54(void *, s32 *);                    /* extern */

extern M2C_UNK lbl_804AF100;

void w3d_auto_800f74d0(s32 arg0, s32 arg1) {
    if (arg1 & 1) {
        fn_80209920(&lbl_804AF100, arg0);
    }
}

s32 w3d_auto_800f87f4(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

void w3d_auto_800fcea0(void) {
    fn_800FCEC8(-1, 0x3C);
}

extern M2C_UNK lbl_804AF13C;

void w3d_auto_800fdc34(s32 arg0) {
    s16 sp8;

    sp8 = fn_8015F5A0(&lbl_804AF13C, 1);
    fn_80162024(arg0, &sp8, arg0 + 0x1C);
}

void w3d_auto_800fde98(void *arg0, s32 arg1) {
    void *temp_r11;

    if (arg1 > 0) {
        temp_r11 = arg0 + 0x44;
        M2C_FIELD(temp_r11, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) + arg1);
        M2C_FIELD(temp_r11, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 0x44);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x5C) = (s32) (M2C_FIELD(arg0, s32 *, 0x5C) & 0xBFFFFFFF);
}

extern M2C_UNK lbl_804AF14C;

void w3d_auto_800fe4b4(s32 arg0) {
    s16 sp8;

    sp8 = fn_8015F5A0(&lbl_804AF14C, 1);
    fn_80162024(arg0, &sp8, arg0 + 0x40);
}

extern M2C_UNK lbl_804AF15C;

void w3d_auto_800ffb28(s32 arg0, s32 arg1) {
    if (arg1 & 1) {
        fn_80209920(&lbl_804AF15C, arg0);
    }
}

void w3d_auto_80102004(void) {
    fn_80101018();
    fn_80102028();
}

extern s32 lbl_804AAECC;

void w3d_auto_80107a90(void) {
    fn_800E58FC(lbl_804AAECC, 0);
}

void w3d_auto_80108224(void) {
    fn_800A8D00();
}

void w3d_auto_80109ab8(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        if (arg1 < 0) {
            M2C_FIELD(arg0, s32 *, 0x68) = (s32) (M2C_FIELD(arg0, s32 *, 0x68) - arg1);
            return;
        }
        M2C_FIELD(arg0, s32 *, 0x6C) = (s32) (M2C_FIELD(arg0, s32 *, 0x6C) + arg1);
    }
}

void w3d_auto_80109b0c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x70) = (s32) (M2C_FIELD(arg0, s32 *, 0x70) + 1);
}

void w3d_auto_80109bb4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x64) = (s32) (M2C_FIELD(arg0, s32 *, 0x64) + 1);
}

void w3d_auto_80109bc4(void *arg0, s32 arg1) {
    if (arg1 < 0) {
        M2C_FIELD(arg0, s32 *, 0x60) = (s32) (M2C_FIELD(arg0, s32 *, 0x60) - arg1);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x5C) = (s32) (M2C_FIELD(arg0, s32 *, 0x5C) + arg1);
}

void w3d_auto_8010a904(void *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = M2C_FIELD(arg0, s32 *, 8);
    *arg2 = M2C_FIELD(arg0, s32 *, 0xC);
}

void w3d_auto_8010cbcc(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (fn_8010BDC8(arg2) != 0) {
        fn_8010BFB0(arg0, arg1, arg2, arg3);
        return;
    }
    fn_8010C62C(arg0, arg1, arg2, arg3);
}

void w3d_auto_8010cc3c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (fn_8010BDC8(arg2) != 0) {
        fn_8010C494(arg0, arg1, arg2, arg3);
        return;
    }
    fn_8010CA34(arg0, arg1, arg2, arg3);
}

void w3d_auto_8010d7c4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (fn_8010BEBC(arg2) != 0) {
        fn_8010CCAC(arg0, arg1, arg2, arg3);
        return;
    }
    fn_8010D230(arg0, arg1, arg2, arg3);
}

void w3d_auto_8010d834(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (fn_8010BEBC(arg2) != 0) {
        fn_8010D0A0(arg0, arg1, arg2, arg3);
        return;
    }
    fn_8010D630(arg0, arg1, arg2, arg3);
}

void w3d_auto_80118230(void *arg0) {
    fn_800D776C();
    M2C_FIELD(arg0, u8 *, 0x28) = (u8) (M2C_FIELD(arg0, u8 *, 0x28) | 1);
}

void w3d_auto_80118268(void) {
    fn_800D7788();
}

void w3d_auto_80118288(void *arg0) {
    fn_800D77A8();
    M2C_FIELD(arg0, u8 *, 0x28) = (u8) (M2C_FIELD(arg0, u8 *, 0x28) | 4);
}

void w3d_auto_80118e54(void *arg0) {
    void **temp_r3;

    fn_8004E460();
    temp_r3 = M2C_FIELD(arg0, void ***, 0x5C);
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void **, M2C_UNK), 0x58)(temp_r3, 1);
}

void w3d_auto_80118e98(void *arg0) {
    void **temp_r3;

    fn_8004E4F8();
    temp_r3 = M2C_FIELD(arg0, void ***, 0x5C);
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void **, M2C_UNK), 0x58)(temp_r3, 0);
}

void w3d_auto_8011d470(void *arg0) {
    s32 sp8;
    s32 temp_r3;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x6C) != 0) {
        temp_r3 = fn_80178C48(M2C_FIELD(arg0, s32 *, 0xA0)) * 2;
        sp8 = temp_r3;
        if (temp_r3 > 0x182B8) {
            sp8 = 0x182B8;
        }
        fn_80178C54(M2C_FIELD(arg0, s32 *, 0xA0), &sp8);
    }
}
