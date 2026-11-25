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


M2C_UNK fn_8000D004();                              /* extern */
s32 fn_8000A758();                                  /* extern */
M2C_UNK fn_8000B6BC(void *, s32);                      /* extern */
s32 fn_8000A7AC();                                  /* extern */

extern s32 lbl_804AA554;
extern s32 lbl_804AC828;
extern s32 lbl_804AC838;
extern s32 lbl_804AC830;
extern s32 lbl_804AC834;
extern s32 lbl_804AC848;
extern s32 lbl_804AC83C;
extern s32 lbl_804AC840;
extern s32 lbl_804AC844;
extern s32 lbl_804AC82C;

void w3d_auto_8000a174(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        lbl_804AC828 = lbl_804AA554 + 0x4000;
        lbl_804AC830 = lbl_804AA554 + 0x2E0;
        lbl_804AC834 = lbl_804AA554 + 0x3070;
        lbl_804AC83C = lbl_804AA554 + 0x3FF0;
        lbl_804AC840 = lbl_804AA554 + 0x3FB0;
        lbl_804AC844 = lbl_804AA554 + 0x3F30;
        lbl_804AC82C = lbl_804AA554;
        lbl_804AC838 = lbl_804AA554;
        lbl_804AC848 = lbl_804AA554;
    }
}

extern s32 lbl_804AA5BC;

s32 w3d_auto_8000a204(void) {
    return lbl_804AA5BC;
}

extern s32 lbl_804AA58C;
extern void *lbl_804AA6D8;

void w3d_auto_8000b2f8(void *arg0, s32 arg1) {
    if ((arg1 != 0) || ((s32) M2C_FIELD(arg0, s32 *, 0x4C) != 0)) {
        if ((s32) lbl_804AA58C == 0) {
            M2C_FIELD(arg0, f32 *, 4) = (f32) (M2C_FIELD(arg0, f32 *, 4) + M2C_FIELD(lbl_804AA6D8, f32 *, 0x84));
        }
        M2C_FIELD(arg0, f32 *, 4) = (f32) (M2C_FIELD(arg0, f32 *, 4) + M2C_FIELD(lbl_804AA6D8, f32 *, 0xF0));
    }
}

extern s32 lbl_804AA5C0;

s32 w3d_auto_8000b864(void) {
    return lbl_804AA5C0;
}

extern s32 lbl_804AA5C4;

s32 w3d_auto_8000c0c0(void) {
    return lbl_804AA5C4;
}

extern s32 lbl_804AA5C8;

s32 w3d_auto_8000cf10(void) {
    return lbl_804AA5C8;
}

void w3d_auto_8000cfe4(void) {
    fn_8000D004();
}

extern s32 lbl_804AA5CC;

s32 w3d_auto_8000d05c(void) {
    return lbl_804AA5CC;
}

extern s32 lbl_804AA5D0;

s32 w3d_auto_8000d0a8(void) {
    return lbl_804AA5D0;
}

extern s32 lbl_804AA5D4;

s32 w3d_auto_8000d114(void) {
    return lbl_804AA5D4;
}

extern s32 lbl_804AA5D8;

s32 w3d_auto_8000d148(void) {
    return lbl_804AA5D8;
}

void w3d_auto_8000d154(s32 arg0) {
    fn_8000B6BC(arg0, fn_8000A758());
}

extern s32 lbl_804AA5DC;

s32 w3d_auto_8000d18c(void) {
    return lbl_804AA5DC;
}

void w3d_auto_8000d198(s32 arg0) {
    fn_8000B6BC(arg0, fn_8000A758());
}

extern s32 lbl_804AA5E0;

s32 w3d_auto_8000d1d0(void) {
    return lbl_804AA5E0;
}

extern s32 lbl_804AA5E4;

s32 w3d_auto_8000d228(void) {
    return lbl_804AA5E4;
}

void w3d_auto_8000d234(s32 arg0) {
    fn_8000B6BC(arg0, fn_8000A7AC());
}

extern s32 lbl_804AA5E8;

s32 w3d_auto_8000d26c(void) {
    return lbl_804AA5E8;
}
