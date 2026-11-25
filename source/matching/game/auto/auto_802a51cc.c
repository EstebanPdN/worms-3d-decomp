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


M2C_UNK fn_802B15E0(void *, float, float);                        /* extern */
M2C_UNK fn_80316270();                              /* extern */
M2C_UNK fn_802B0668(void *);                           /* extern */
M2C_UNK fn_802B0FEC(void *);                           /* extern */
M2C_UNK fn_8015FD1C();                              /* extern */
M2C_UNK fn_802B1F98(void *);                           /* extern */
M2C_UNK fn_802B16C4(void *, M2C_UNK);                  /* extern */
M2C_UNK fn_802B222C();                              /* extern */
M2C_UNK fn_802B38D4();                              /* extern */
M2C_UNK fn_802B1BD0(void *, void *);                           /* extern */
M2C_UNK fn_802B2344(void *, int);                           /* extern */
M2C_UNK fn_802B4E10(void *);                           /* extern */
M2C_UNK fn_802B9DE4(void *);                           /* extern */
M2C_UNK fn_802B0990(void *, void *);                           /* extern */
M2C_UNK fn_802BC5AC();                              /* extern */
M2C_UNK fn_802BC600(void *);                           void fn_802BC1D0();                              /* extern */
M2C_UNK fn_802BC1D4(void *);                        /* extern */
M2C_UNK fn_802BC570();                              /* extern */
M2C_UNK fn_802BD354();                              /* extern */
M2C_UNK fn_802BDD24(s32 *);                         /* extern */
M2C_UNK fn_802BFC64();                              /* extern */

void w3d_auto_802a51cc(void *arg0, float arg_f1, float arg_f2) {
    s32 temp_r29;

    temp_r29 = M2C_FIELD(arg0, s32 *, 0x8C);
    M2C_FIELD(arg0, s32 *, 0x8C) = 1;
    fn_802B15E0(arg0 + 0x1C, arg_f1, arg_f2);
    M2C_FIELD(arg0, s32 *, 0x8C) = temp_r29;
}

s32 w3d_auto_802ab5c0(void *arg0, f32 farg0, f32 farg1) {
    s32 var_ctr;
    void *var_r3;

    var_ctr = 0xB;
    var_r3 = arg0 + 0x10C;
loop_1:
    if (!(farg0 < M2C_FIELD(var_r3, f32 *, 4)) && !(farg0 > M2C_FIELD(var_r3, f32 *, 0xC)) && !(farg1 < M2C_FIELD(var_r3, f32 *, 8)) && !(farg1 > M2C_FIELD(var_r3, f32 *, 0x10)) && (((s32) M2C_FIELD(arg0, s32 *, 0x8C) != 0) || ((s32) M2C_FIELD(var_r3, s32 *, 0x40) != 0))) {
        return M2C_FIELD(var_r3, s32 *, 0);
    }
    var_r3 += 0x48;
    var_ctr -= 1;
    if (var_ctr == 0) {
        return 0;
    }
    goto loop_1;
}

void w3d_auto_802aba0c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0xA8) = 1;
}

s32 w3d_auto_802aba18(void *arg0, s32 arg1) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x14) != 0) {
        return 0;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 4) != 0xA1) {
        M2C_FIELD(arg0, s32 *, 4) = 0xA0;
    }
    M2C_FIELD(arg0, s32 *, 0x14) = arg1;
    if ((arg1 == 3) && ((s32) M2C_FIELD(arg0, s32 *, 4) != 0xA1)) {
        M2C_FIELD(arg0, s32 *, 4) = 0xA2;
    }
    return 1;
}

void w3d_auto_802abfdc(void) {
    fn_80316270();
}

s32 w3d_auto_802af848(void *arg0) {
    fn_802B0668(arg0 + 0x1C);
    M2C_FIELD(arg0, s32 *, 0xD4) = 1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), s32 *, 0x10) = 1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), s32 *, 0x10) = 1;
    return 0;
}

void w3d_auto_802af924(s32 arg0) {
    fn_802B0FEC(arg0 + 0x1C);
}

void w3d_auto_802af948(s32 arg0, s32 arg1) {
    if (arg1 == 1) {
        fn_8015FD1C();
        return;
    }
    fn_802B1F98(arg0 + 0x1C);
}

void w3d_auto_802af984(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x2C), s32 *, 0x10) = 1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 *, 0x10) = 1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), s32 *, 0x10) = 1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), s32 *, 0x10) = 1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), s32 *, 0x10) = 1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), s32 *, 0x10) = 1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s32 *, 0x10) = 1;
}

void w3d_auto_802af9c4(s32 arg0) {
    fn_802B16C4(arg0 + 0x1C, 1);
}

void w3d_auto_802b0970(void) {
    fn_802B222C();
}

void w3d_auto_802b30c0(void *arg0, f32 farg0, f32 farg1) {
    if ((M2C_FIELD(arg0, f32 *, 0x50) != farg0) || (M2C_FIELD(arg0, f32 *, 0x54) != farg1)) {
        M2C_FIELD(arg0, f32 *, 0x50) = farg0;
        M2C_FIELD(arg0, f32 *, 0x54) = farg1;
        if ((s32) M2C_FIELD(arg0, s32 *, 0x3C) == 1) {
            fn_802B38D4();
        }
    }
}

void w3d_auto_802b310c(void *arg0, f32 farg0) {
    if (farg0 != M2C_FIELD(arg0, f32 *, 0x40)) {
        M2C_FIELD(arg0, f32 *, 0x40) = farg0;
        if ((s32) M2C_FIELD(arg0, s32 *, 0x3C) == 1) {
            fn_802B38D4();
        }
    }
}

s32 w3d_auto_802b4378(s32 arg0) {
    fn_802B0668(arg0 + 0x1C);
    return 0;
}

void w3d_auto_802b46f4(s32 arg0) {
    fn_802B0FEC(arg0 + 0x1C);
}

void w3d_auto_802b4718(s32 arg0, s32 arg1) {
    if (arg1 == 1) {
        fn_8015FD1C();
        return;
    }
    fn_802B1F98(arg0 + 0x1C);
}

void w3d_auto_802b474c(s32 arg0, void * arg_r4) {
    fn_802B1BD0(arg0 + 0x1C, arg_r4);
}

void w3d_auto_802b4d20(s32 arg0, void * arg_r4) {
    fn_802B2344(arg0 + 0x1C, arg_r4);
    fn_802B4E10(arg0);
}

void w3d_auto_802b6798(s32 arg0, void * arg_r4) {
    fn_802B1BD0(arg0 + 0x1C, arg_r4);
}

void w3d_auto_802b67bc(s32 arg0, s32 arg1) {
    if (arg1 == 1) {
        fn_8015FD1C();
        return;
    }
    fn_802B1F98(arg0 + 0x1C);
}

void w3d_auto_802ba038(s32 arg0, void * arg_r4) {
    fn_802B2344(arg0 + 0x1C, arg_r4);
    fn_802B9DE4(arg0);
}

s32 w3d_auto_802ba59c(s32 arg0) {
    fn_802B0668(arg0 + 0x1C);
    return 0;
}

void w3d_auto_802ba6dc(s32 arg0, s32 arg1) {
    if (arg1 == 1) {
        fn_8015FD1C();
        return;
    }
    fn_802B1F98(arg0 + 0x1C);
}

void w3d_auto_802bad74(s32 arg0, void * arg_r4) {
    fn_802B1BD0(arg0 + 0x1C, arg_r4);
}

void w3d_auto_802bad98(s32 arg0, void * arg_r4) {
    fn_802B0990(arg0 + 0x1C, arg_r4);
}

void w3d_auto_802bc064(s32 arg0) {
    fn_802BC5AC();
    fn_802BC600(arg0);
}

void w3d_auto_802bc570(void *arg0) {
    fn_802BC1D0();
    fn_802BC1D4(arg0);
    M2C_FIELD(arg0, s32 *, 0x50) = 1;
}

void w3d_auto_802bc790(void *arg0, f32 farg0) {
    if (M2C_FIELD(arg0, f32 *, 0x44) != farg0) {
        M2C_FIELD(arg0, f32 *, 0x44) = farg0;
        fn_802BC570();
    }
}

void w3d_auto_802bd2c4(s32 *arg0, s32 arg1, s32 arg2) {
    fn_802BD354();
    if (((s32) *arg0 != arg1) || (arg2 == 1)) {
        *arg0 = arg1;
        fn_802BDD24(arg0);
    }
}

void w3d_auto_802bd318(void *arg0, s32 arg1) {
    if (arg1 != (s32) M2C_FIELD(arg0, s32 *, 0xC)) {
        M2C_FIELD(arg0, s32 *, 0xC) = arg1;
        fn_802BFC64();
    }
}

void w3d_auto_802bd348(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
}

void w3d_auto_802bd354(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 1;
}
