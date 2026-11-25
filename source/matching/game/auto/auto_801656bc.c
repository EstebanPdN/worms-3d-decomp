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


M2C_UNK fn_8016703C();                              /* extern */
M2C_UNK fn_80209968(M2C_UNK *);                     void fn_8030BA64(M2C_UNK, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK fn_8030BFF4(void *, M2C_UNK);                  /* extern */
M2C_UNK fn_8030C094(M2C_UNK);                       /* extern */
M2C_UNK fn_8030C044(void *, M2C_UNK);                  /* extern */
M2C_UNK fn_801A38C8();                              void fn_801686A0(s32);                           void fn_8030AF88(M2C_UNK, int);                       /* extern */
M2C_UNK fn_8016804C(void *, M2C_UNK);                  /* extern */
M2C_UNK fn_801A314C(void *, M2C_UNK);                  /* extern */
M2C_UNK fn_801A3164(void *, M2C_UNK);                  void fn_8016EE44(s32);                           /* extern */
M2C_UNK fn_801D4544(void *, void *);                      /* extern */
s32 fn_801720FC();                                  /* extern */
void *fn_80174074();                                /* extern */
void *fn_8034BF48(s32);                             /* extern */

extern s32 lbl_804AB4EC;

void w3d_auto_801656bc(void) {
    lbl_804AB4EC = 0;
}

s32 w3d_auto_801669d8(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x38) = arg1;
    return 0;
}

s32 w3d_auto_801669ec(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x34) = arg1;
    return 0;
}

void w3d_auto_80166ff8(void) {
    fn_8016703C();
}

extern M2C_UNK lbl_804B00DC;

void w3d_auto_80167018(void) {
    fn_80209968(&lbl_804B00DC);
}

void w3d_auto_8016710c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x1488) = 0;
}

s32 w3d_auto_80167578(void) {
    fn_8030BA64(0, 7, 1);
    return 0;
}

s32 w3d_auto_801675b0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x104) = arg1;
    return 0;
}

s32 w3d_auto_801676b8(void *arg0, f32 farg0) {
    M2C_FIELD(arg0, f32 *, 0x2C) = farg0;
    return 0;
}

s32 w3d_auto_801676cc(void) {
    return 0x80004001;
}

s32 w3d_auto_801676fc(void *arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    *arg1 = (s32) M2C_FIELD(arg0, u16 *, 0xB0);
    *arg2 = (s32) M2C_FIELD(arg0, u16 *, 0xB2);
    *arg3 = (s32) M2C_FIELD(arg0, u16 *, 0xB4);
    *arg4 = (s32) M2C_FIELD(arg0, u16 *, 0xB6);
    return 0;
}

void w3d_auto_8016803c(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xEC) = (s32) (M2C_FIELD(arg0, s32 *, 0xEC) | arg1);
}

void w3d_auto_8016804c(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xEC) = (s32) (M2C_FIELD(arg0, s32 *, 0xEC) & ~arg1);
}

void w3d_auto_8016805c(s32 arg0) {
    fn_8030BFF4(arg0 + 0x458, 0);
    fn_8030C094(0);
}

void w3d_auto_8016808c(s32 arg0) {
    fn_8030C044(arg0 + 0x458, 0);
}

void w3d_auto_801689a0(void) {
    fn_801A38C8();
}

extern s32 lbl_804B1884;

void w3d_auto_801689c0(void) {
    fn_801686A0(lbl_804B1884);
}

void w3d_auto_8016a194(s32 arg0) {
    fn_8030BFF4(arg0 + 0xEC, 0);
}

extern s32 lbl_804B1884;

void w3d_auto_8016a1bc(void) {
    fn_8030BFF4(lbl_804B1884 + 0x458, 0);
}

void w3d_auto_8016a1e8(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x134) = arg1;
    fn_8030AF88(0, (void *)arg1);
}

s32 w3d_auto_8016a210(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xE8) = arg1;
    return 0;
}

extern s32 lbl_804B1884;

void w3d_auto_8016c1f4(void *arg0) {
    fn_801A314C(M2C_FIELD(arg0, s32 *, 0x74), 0);
    fn_801A3164(M2C_FIELD(arg0, s32 *, 0x74), 0);
    fn_8016804C(lbl_804B1884, 0x20);
}

void w3d_auto_8016e5fc(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x228) = 0;
}

s32 w3d_auto_8016ede8(void) {
    return 0x80004001;
}

s32 w3d_auto_8016ee04(void) {
    return 0x80004001;
}

s32 w3d_auto_8016f450(void *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = (s32) M2C_FIELD(arg0, u16 *, 0x14);
    *arg2 = (s32) M2C_FIELD(arg0, u16 *, 0x16);
    return 0;
}

s32 w3d_auto_8016f480(void *arg0) {
    fn_8016EE44(M2C_FIELD(arg0, s32 *, 0x1C));
    return 0;
}

s32 w3d_auto_8016f4b8(void *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = (s32) M2C_FIELD(arg0, u16 *, 0x18);
    *arg2 = (s32) M2C_FIELD(arg0, u16 *, 0x1A);
    return 0;
}

s32 w3d_auto_8016f4d4(void) {
    return 0x80004001;
}

s32 w3d_auto_8016f4e0(void) {
    return 0x80004001;
}

s32 w3d_auto_8016f86c(void *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = (s32) M2C_FIELD(arg0, u16 *, 0x14);
    *arg2 = (s32) M2C_FIELD(arg0, u16 *, 0x16);
    return 0;
}

extern u16 lbl_804B18A4;

u16 w3d_auto_80170b10(void) {
    return lbl_804B18A4;
}

extern u16 lbl_804B18A4;
extern u16 lbl_804B18A6;

u16 w3d_auto_80170b18(void) {
    return (u16) (lbl_804B18A4 - lbl_804B18A6);
}

extern s32 lbl_804B0140;
extern s32 lbl_804B0144;

s32 w3d_auto_80171ab8(void *arg0, s32 arg1) {
    u16 var_r0;

    if (arg1 == 0) {
        fn_801D4544(M2C_FIELD(arg0, s32 *, 0x4C), lbl_804B0140);
        var_r0 = M2C_FIELD(arg0, u16 *, 0x32) & 0xFFFE;
    } else {
        fn_801D4544(M2C_FIELD(arg0, s32 *, 0x4C), lbl_804B0144);
        var_r0 = M2C_FIELD(arg0, u16 *, 0x32) | 1;
    }
    M2C_FIELD(arg0, u16 *, 0x32) = var_r0;
    return 0;
}

extern s32 lbl_804B0124;
extern s32 lbl_804B0128;

s32 w3d_auto_80171b1c(void *arg0, s32 arg1) {
    u16 var_r0;

    if (arg1 == 0) {
        fn_801D4544(M2C_FIELD(arg0, s32 *, 0x4C), lbl_804B0128);
        var_r0 = M2C_FIELD(arg0, u16 *, 0x32) & 0xFFFD;
    } else {
        fn_801D4544(M2C_FIELD(arg0, s32 *, 0x4C), lbl_804B0124);
        var_r0 = M2C_FIELD(arg0, u16 *, 0x32) | 2;
    }
    M2C_FIELD(arg0, u16 *, 0x32) = var_r0;
    return 0;
}

extern s32 lbl_804B0134;
extern s32 lbl_804B0138;

s32 w3d_auto_80171b80(void *arg0, s32 arg1) {
    u16 var_r0;

    if (arg1 == 1) {
        fn_801D4544(M2C_FIELD(arg0, s32 *, 0x4C), lbl_804B0138);
        var_r0 = M2C_FIELD(arg0, u16 *, 0x32) | 0x10;
    } else {
        fn_801D4544(M2C_FIELD(arg0, s32 *, 0x4C), lbl_804B0134);
        var_r0 = M2C_FIELD(arg0, u16 *, 0x32) & 0xFFEF;
    }
    M2C_FIELD(arg0, u16 *, 0x32) = var_r0;
    return 0;
}

s32 w3d_auto_80171f90(void *arg0) {
    return M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), void **, 0x28), s32 *, 0x18);
}

s32 w3d_auto_801720c0(void *arg0) {
    return *M2C_FIELD(arg0, s32 **, 0x50) + (fn_801720FC() * 0x10);
}

s32 w3d_auto_80174050(void) {
    return M2C_FIELD(fn_80174074(), s32 *, 0x3C);
}

void w3d_auto_801742ec(void *arg0, s32 arg1) {
    void *temp_r3;

    temp_r3 = fn_8034BF48(arg1);
    M2C_FIELD(arg0, s32 *, 0x20) = (s32) M2C_FIELD(temp_r3, s32 *, 0x20);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(temp_r3, s32 *, 0x24);
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) M2C_FIELD(temp_r3, s32 *, 0x30);
    M2C_FIELD(arg0, u8 *, 0x19) = (u8) M2C_FIELD(temp_r3, u8 *, 0x19);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), M2C_UNK (**)(void *), 0x2C)(arg0);
}
