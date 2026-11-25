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


void *fn_800FC6DC(s32);                             /* extern */
void *fn_800FC7F8(u8);                              /* extern */
M2C_UNK fn_801492EC(void *, M2C_UNK);               /* extern */
s32 fn_80153F58();                                  /* extern */
M2C_UNK fn_80157A30();                              /* extern */

s32 w3d_auto_8013f4dc(void *arg0) {
    return M2C_FIELD(fn_800FC7F8(M2C_FIELD(fn_800FC6DC(M2C_FIELD(arg0, s32 *, 0x70)), u8 *, 0xD5)), s32 *, 0x2C);
}

void w3d_auto_8014e960(void *arg0) {
    if ((fn_80153F58() != 0) && ((s32) M2C_FIELD(arg0, s32 *, 0x2F8) == 0)) {
        M2C_FIELD(arg0, s32 *, 0x2F8) = 0x18;
        fn_801492EC(arg0, 0x2B);
    }
}

void w3d_auto_8014f8c0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x290) = 1;
}

void w3d_auto_8014fedc(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x2E0) = 0;
}

s32 w3d_auto_80151128(void *arg0) {
    if (((s32) M2C_FIELD(arg0, s32 *, 0x314) != -1) || ((s32) M2C_FIELD(arg0, s32 *, 0x310) != -1) || ((s32) M2C_FIELD(arg0, s32 *, 0x318) != -1)) {
        return 1;
    }
    return 0;
}

s32 w3d_auto_80153f58(void *arg0) {
    return M2C_FIELD(fn_800FC6DC(M2C_FIELD(arg0, s32 *, 0x248)), s32 *, 0x100);
}

extern u32 lbl_804AB3B0;

s32 w3d_auto_80155760(void) {
    u32 temp_r9;

    temp_r9 = lbl_804AB3B0 + 1;
    lbl_804AB3B0 = temp_r9;
    if (temp_r9 > 0xFU) {
        lbl_804AB3B0 = 0U;
    }
    return 0x14;
}

void w3d_auto_80156f68(void) {
    fn_80157A30();
}
