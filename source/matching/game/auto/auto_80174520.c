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


M2C_UNK fn_8034BF50();                              /* extern */
M2C_UNK fn_8034C148();                              /* extern */
M2C_UNK fn_8034C340();                              /* extern */
M2C_UNK fn_8034C538();                              /* extern */
M2C_UNK fn_8034C730();                              /* extern */
M2C_UNK fn_8034C928();                              /* extern */
M2C_UNK fn_80176814(void *, void *);                      /* extern */
M2C_UNK fn_801784E4(void *, void *);                   /* extern */
M2C_UNK fn_80185AF0();                              /* extern */

extern u16 lbl_804AB58C;

u16 w3d_auto_80174520(void) {
    return lbl_804AB58C;
}

extern u16 lbl_804AB58C;
extern u16 lbl_804AB594;

u16 w3d_auto_80174528(void) {
    return (u16) (lbl_804AB58C - lbl_804AB594);
}

s32 w3d_auto_801750d4(void *arg0) {
    void *temp_r9;

    temp_r9 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x78), void **, 0x2C);
    if ((s32) M2C_FIELD(temp_r9, s32 *, 0x18) != 0) {
        return M2C_FIELD(temp_r9, s32 *, 0x20);
    }
    return 0;
}

void w3d_auto_80175974(void) {
    fn_8034BF50();
}

void w3d_auto_80175994(void) {
    fn_8034C148();
}

void w3d_auto_801759b4(void) {
    fn_8034C340();
}

void w3d_auto_801759d4(void) {
    fn_8034C538();
}

void w3d_auto_801759f4(void) {
    fn_8034C730();
}

void w3d_auto_80175a14(void) {
    fn_8034C928();
}

s32 w3d_auto_80176584(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x844) - M2C_FIELD(arg0, s32 *, 0x82C);
}

extern s32 lbl_804AB5C4;

void w3d_auto_80178550(s32 arg0) {
    fn_80176814(lbl_804AB5C4, arg0);
}

void w3d_auto_801787ec(s32 arg0) {
    s32 var_ctr;
    void *var_r3;

    var_r3 = arg0 + 0x2C;
    var_ctr = 0x100;
    do {
        M2C_FIELD(var_r3, s32 *, 0) = 0;
        M2C_FIELD(var_r3, s16 *, 4) = -1;
        var_r3 += 8;
        var_ctr -= 1;
    } while (var_ctr != 0);
}

s32 w3d_auto_801789cc(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x18);
}

s32 w3d_auto_801789e0(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x14);
}

s32 w3d_auto_80178a74(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 8) = arg1;
    return 0;
}

s32 w3d_auto_80178a80(void *arg0, s32 arg1) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x14) = arg1;
    return 0;
}

s32 w3d_auto_80178c48(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x1C);
}

s32 w3d_auto_80178d1c(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x1C);
}

f32 w3d_auto_80178df0(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 4), f32 *, 0x1C);
}

s32 w3d_auto_80178ec4(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 4) + 0x1C;
}

s32 w3d_auto_80178f54(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 4) + 0x1C;
}

s32 w3d_auto_80179170(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 4) + 0x1C;
}

s32 w3d_auto_8017941c(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x1C);
}

s32 w3d_auto_80179598(void *arg0, s32 arg1) {
    fn_801784E4(arg1, arg0);
    return M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x1C);
}

s32 w3d_auto_801797b4(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x1C);
}

s32 w3d_auto_80179aec(void *arg0) {
    fn_80185AF0();
    M2C_FIELD(arg0, s32 *, 0xA4) = 1;
    return 0;
}

extern s32 lbl_804B0160;

void w3d_auto_8017b78c(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        lbl_804B0160 = 0;
    }
}

extern s32 lbl_804AB600;

s32 w3d_auto_8017b8ec(void) {
    return lbl_804AB600;
}

extern s32 lbl_804AB600;

void w3d_auto_8017b8f4(void) {
    lbl_804AB600 = 0;
}

s32 w3d_auto_8017d550(void) {
    return 0x80004001;
}

s32 w3d_auto_8017d5fc(void *arg0, s32 arg1) {
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0x264C);
    M2C_FIELD(arg0, s32 *, 0x264C) = arg1;
    return temp_r0;
}

extern u16 lbl_804AB610;

u16 w3d_auto_8017f524(void) {
    return lbl_804AB610;
}

extern u16 lbl_804AB610;
extern u16 lbl_804AB61C;

u16 w3d_auto_8017f52c(void) {
    return (u16) (lbl_804AB610 - lbl_804AB61C);
}

s32 w3d_auto_80186874(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x30) = arg1;
    return 0;
}

extern u16 lbl_804AB684;

u16 w3d_auto_8018774c(void) {
    return lbl_804AB684;
}

extern u16 lbl_804AB684;
extern u16 lbl_804AB690;

u16 w3d_auto_80187754(void) {
    return (u16) (lbl_804AB684 - lbl_804AB690);
}

s32 w3d_auto_80188a18(void *arg0) {
    return M2C_FIELD(arg0, u16 *, 0x38) & 1;
}

s32 w3d_auto_80188a24(void *arg0) {
    return ((u16) M2C_FIELD(arg0, u16 *, 0x38) >> 1U) & 1;
}

s32 w3d_auto_80188a30(void *arg0) {
    return ((u16) M2C_FIELD(arg0, u16 *, 0x38) >> 4U) & 1;
}

s32 w3d_auto_80189504(void *arg0) {
    return M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0xA8), void **, 0x34), void **, 0x28), s32 *, 0x18);
}
