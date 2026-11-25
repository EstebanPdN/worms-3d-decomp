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


M2C_UNK fn_802098D8(M2C_UNK *, s32);                /* extern */
M2C_UNK fn_80209920(M2C_UNK *, s32);                /* extern */
M2C_UNK fn_8001523C();                              /* extern */
M2C_UNK fn_80015264();                              void fn_802098B4(M2C_UNK *, s32, M2C_UNK);       /* extern */
s32 fn_8020B208();                                  /* extern */
void *fn_800FC6DC();                                /* extern */
void *fn_800FC7F8(u8);                              /* extern */

extern s32 lbl_804AA67C;

s32 w3d_auto_80011a68(void) {
    return lbl_804AA67C;
}

extern s32 lbl_804AA680;

s32 w3d_auto_80011c50(void) {
    return lbl_804AA680;
}

extern s32 lbl_804AA684;

s32 w3d_auto_80011f28(void) {
    return lbl_804AA684;
}

extern s32 lbl_804AA688;

s32 w3d_auto_80012010(void) {
    return lbl_804AA688;
}

extern s32 lbl_804AA68C;

s32 w3d_auto_80012104(void) {
    return lbl_804AA68C;
}

extern s32 lbl_804AA5B8;
extern s32 lbl_804AC850;
extern s32 lbl_804AC860;
extern s32 lbl_804AC858;
extern s32 lbl_804AC85C;
extern s32 lbl_804AC870;
extern s32 lbl_804AC864;
extern s32 lbl_804AC868;
extern s32 lbl_804AC86C;
extern s32 lbl_804AC854;

void w3d_auto_800122b4(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        lbl_804AC850 = lbl_804AA5B8 + 0x4000;
        lbl_804AC858 = lbl_804AA5B8 + 0x2E0;
        lbl_804AC85C = lbl_804AA5B8 + 0x3070;
        lbl_804AC864 = lbl_804AA5B8 + 0x3FF0;
        lbl_804AC868 = lbl_804AA5B8 + 0x3FB0;
        lbl_804AC86C = lbl_804AA5B8 + 0x3F30;
        lbl_804AC854 = lbl_804AA5B8;
        lbl_804AC860 = lbl_804AA5B8;
        lbl_804AC870 = lbl_804AA5B8;
    }
}

extern s32 lbl_804AA6B4;

s32 w3d_auto_80015228(void) {
    return lbl_804AA6B4;
}

extern M2C_UNK lbl_804AC898;

void w3d_auto_8001523c(s32 arg0) {
    fn_802098D8(&lbl_804AC898, arg0);
}

extern M2C_UNK lbl_804AC898;

void w3d_auto_80015264(s32 arg0) {
    fn_80209920(&lbl_804AC898, arg0);
}

void w3d_auto_8001528c(void) {
    fn_8001523C();
}

void w3d_auto_800152ac(void) {
    fn_80015264();
}

extern M2C_UNK lbl_804AC898;

void w3d_auto_800152cc(void) {
    fn_802098B4(&lbl_804AC898, fn_8020B208(), 0);
}

s32 w3d_auto_800153dc(void) {
    return M2C_FIELD(fn_800FC6DC(), s32 *, 0xDC);
}

s32 w3d_auto_80015488(void) {
    return M2C_FIELD(fn_800FC7F8(M2C_FIELD(fn_800FC6DC(), u8 *, 0xD5)), s32 *, 0x34);
}

u8 w3d_auto_800154b4(void) {
    return M2C_FIELD(fn_800FC7F8(M2C_FIELD(fn_800FC6DC(), u8 *, 0xD5)), u8 *, 0x3C);
}
