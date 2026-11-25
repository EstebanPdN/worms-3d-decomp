/* Decompiled automatically by m2c with mechanical corrections (tools/m2c_fixups.py:
 * far globals as unknown-size arrays, dropped leading parameters, forwarded
 * arguments); verified identical to the original after linking. Types and
 * names are m2c placeholders pending review. */
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

#define NULL ((void *)0)

s32 fn_800E5CF0(s32, M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK fn_8013F08C(void *);                              /* extern */
void *fn_800FC6DC(s32);                             /* extern */
s16 fn_8015F5A0(M2C_UNK *, M2C_UNK);                /* extern */
void *fn_801613F0(void *, M2C_UNK);                    /* extern */
M2C_UNK fn_8016239C(void *);                        /* extern */
M2C_UNK fn_801359EC(s32, s32, s32, s32, f32, f32, f32); /* extern */
s32 fn_80139158(void *);                               /* extern */
s32 fn_8013FECC();                                  /* extern */
s32 fn_80162C20();                                  /* extern */

extern M2C_UNK lbl_8039FD70[];
extern M2C_UNK lbl_8039FD7C[];

void w3d_auto_8013f2a4(void *arg0, s32 arg1) {
    fn_8013F08C(arg0);
    M2C_FIELD(arg0, s32 *, 0x238) = fn_800E5CF0(arg1, &(*lbl_8039FD70), &(*lbl_8039FD7C), -1, 0);
    return;
}

extern M2C_UNK lbl_8039FD54[];
extern M2C_UNK lbl_8039FDC0[];

void w3d_auto_8013f50c(void *arg0, s32 arg1) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x23C) != 0) {
        goto block_3;
    }
    if ((s32) M2C_FIELD(fn_800FC6DC(M2C_FIELD(arg0, s32 *, 0x70)), s32 *, 0xB4) == 0) {
        goto block_3;
    }
    M2C_FIELD(arg0, s32 *, 0x23C) = fn_800E5CF0(arg1, &(*lbl_8039FD54), &(*lbl_8039FDC0), -1, 0);
block_3:
    return;
}

extern M2C_UNK lbl_8040DB38[];
extern s32 lbl_804AB3BC;
extern M2C_UNK lbl_804AF9E0;
extern s32 lbl_804B1754;

s32 w3d_auto_8013f884(void) {
    void *temp_r30;

    lbl_804AB3BC = 0;
    temp_r30 = fn_801613F0(lbl_804B1754, 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AF9E0, 1);
    M2C_FIELD(temp_r30, M2C_UNK **, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    return lbl_804AB3BC;
}

extern f32 lbl_8039FDEC[];
extern f32 lbl_8039FDF0[];
extern f32 lbl_8039FDF4[];
extern s32 lbl_804AB15C;
extern s32 lbl_804AB160;
extern s32 lbl_804AB164;
extern s32 lbl_804AB168;
extern s32 lbl_804AB2DC;
extern s32 lbl_804AB2E0;

void w3d_auto_8013f8e8(s32 arg0, s32 arg1) {
    s32 temp_r3;

    if (fn_8013FECC() == 0) {
        goto block_16;
    }
    if (fn_80139158(arg0) == 0) {
        goto block_5;
    }
    if (fn_80162C20() & 1) {
        goto block_4;
    }
    fn_801359EC(arg0, arg1, lbl_804AB2DC, arg0 + 0x1D8, (*lbl_8039FDEC), (*lbl_8039FDF0), (*lbl_8039FDF4));
    return;
block_4:
    fn_801359EC(arg0, arg1, lbl_804AB2E0, arg0 + 0x1D8, (*lbl_8039FDEC), (*lbl_8039FDF0), (*lbl_8039FDF4));
    return;
block_5:
    temp_r3 = fn_80162C20() & 3;
    if (temp_r3 == 1) {
        goto block_13;
    }
    if (temp_r3 > 1) {
        goto block_9;
    }
    if (temp_r3 == 0) {
        goto block_12;
    }
    return;
block_9:
    if (temp_r3 == 2) {
        goto block_14;
    }
    if (temp_r3 == 3) {
        goto block_15;
    }
    return;
block_12:
    fn_801359EC(arg0, arg1, lbl_804AB15C, arg0 + 0x1D8, (*lbl_8039FDEC), (*lbl_8039FDF0), (*lbl_8039FDF4));
    return;
block_13:
    fn_801359EC(arg0, arg1, lbl_804AB160, arg0 + 0x1D8, (*lbl_8039FDEC), (*lbl_8039FDF0), (*lbl_8039FDF4));
    return;
block_14:
    fn_801359EC(arg0, arg1, lbl_804AB164, arg0 + 0x1D8, (*lbl_8039FDEC), (*lbl_8039FDF0), (*lbl_8039FDF4));
    return;
block_15:
    fn_801359EC(arg0, arg1, lbl_804AB168, arg0 + 0x1D8, (*lbl_8039FDEC), (*lbl_8039FDF0), (*lbl_8039FDF4));
block_16:
    return;
}
