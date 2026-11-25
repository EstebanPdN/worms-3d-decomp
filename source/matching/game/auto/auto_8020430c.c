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


s32 fn_80203370(void *, void *);                               /* extern */
M2C_UNK fn_80204760(s32, s32);                      /* extern */
M2C_UNK fn_802047E0();                              /* extern */
M2C_UNK fn_8035BBF0();                              /* extern */
M2C_UNK fn_8035BC90();                              /* extern */
M2C_UNK fn_8035BD50();                              /* extern */
M2C_UNK fn_801299B8(M2C_UNK);                       /* extern */
M2C_UNK fn_801FD238();                              /* extern */
s32 fn_801FE45C();                                  /* extern */
M2C_UNK fn_80207B30(s32, u16, s32 *, s32, M2C_UNK); /* extern */
s32 fn_802EF9C0(s32 *);                             /* extern */

void w3d_auto_8020430c(s32 arg0, void * arg_r4) {
    fn_80204760(arg0, fn_80203370(arg0 + 0x6C, arg_r4));
}

void w3d_auto_80204428(void) {
    fn_802047E0();
}

void w3d_auto_80204448(void) {
    fn_802047E0();
}

void w3d_auto_80204468(void) {
    fn_8035BBF0();
}

void w3d_auto_80204488(void) {
    fn_8035BBF0();
}

void w3d_auto_802044a8(void) {
    fn_8035BC90();
}

void w3d_auto_802044c8(void) {
    fn_8035BC90();
}

void w3d_auto_80204530(void) {
    fn_8035BD50();
}

void w3d_auto_80204720(void) {
    fn_802047E0();
}

void w3d_auto_80204740(void) {
    fn_802047E0();
}

s32 w3d_auto_80205648(void) {
    return 0x80004001;
}

extern s32 lbl_804AB98C;

s32 w3d_auto_80205964(void) {
    return lbl_804AB98C;
}

extern s32 lbl_804AB98C;

void w3d_auto_8020596c(void) {
    lbl_804AB98C = 0;
}

s32 w3d_auto_802062f4(void *arg0) {
    return (s32) ((M2C_FIELD(arg0, s32 *, 0x18) - M2C_FIELD(arg0, s32 *, 0x14)) * 0xAAAAAAAB) >> 2;
}

void w3d_auto_802068fc(void) {
    fn_801299B8(0);
}

void w3d_auto_802069e0(void) {
    fn_801FD238();
}

extern s32 lbl_804AB998;

void w3d_auto_80206a00(s32 arg0) {
    lbl_804AB998 = arg0;
}

s32 w3d_auto_80206b94(void) {
    return 0x80004001;
}

s32 w3d_auto_80206ba0(void) {
    return 0x80004001;
}

s32 w3d_auto_80206bac(void) {
    return 0x80004001;
}

s32 w3d_auto_80206bb8(void) {
    return 0x80004001;
}

extern s32 lbl_804AB9AC;

s32 w3d_auto_80206e0c(void) {
    return lbl_804AB9AC;
}

extern s32 lbl_804AB9AC;

void w3d_auto_80206e14(void) {
    lbl_804AB9AC = 0;
}

s32 w3d_auto_802071cc(void) {
    return 0x80004001;
}

void w3d_auto_802076ac(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x20) = (s32) (((M2C_FIELD(arg0, s32 *, 0x20) + arg1) - 1) & -arg1);
}

extern s32 lbl_804AB9B4;
extern s32 lbl_804AB9B8;
extern u16 lbl_804B0658;
extern u16 lbl_804B065A;
extern s32 lbl_804B18F4;

void w3d_auto_80207ca4(s32 *arg0) {
    s32 sp8;
    s32 temp_r30;
    s32 temp_r3;
    s32 temp_r9;
    u16 temp_r29;

    if ((s32) lbl_804B18F4 != 0) {
        temp_r9 = lbl_804AB9B4 - 1;
        lbl_804AB9B4 = temp_r9;
        if (temp_r9 == 0) {
            temp_r3 = fn_801FE45C();
            sp8 = temp_r3;
            if ((u32) (temp_r3 - lbl_804AB9B8) > 2U) {
                fn_80207B30(lbl_804B18F4, lbl_804B065A, &sp8, 4, 0);
                lbl_804AB9B4 = 0x64;
                lbl_804AB9B8 = sp8;
            } else {
                lbl_804AB9B4 = 0x32;
            }
        }
        temp_r30 = lbl_804B18F4;
        temp_r29 = lbl_804B0658;
        fn_80207B30(temp_r30, temp_r29, arg0, fn_802EF9C0(arg0), 0);
    }
}

extern s32 lbl_804AB9B4;
extern s32 lbl_804AB9B8;
extern u16 lbl_804B065A;
extern u16 lbl_804B065C;
extern s32 lbl_804B18F4;

void w3d_auto_80207d60(s32 *arg0) {
    s32 sp8;
    s32 temp_r30;
    s32 temp_r3;
    s32 temp_r9;
    u16 temp_r29;

    if ((s32) lbl_804B18F4 != 0) {
        temp_r9 = lbl_804AB9B4 - 1;
        lbl_804AB9B4 = temp_r9;
        if (temp_r9 == 0) {
            temp_r3 = fn_801FE45C();
            sp8 = temp_r3;
            if ((u32) (temp_r3 - lbl_804AB9B8) > 2U) {
                fn_80207B30(lbl_804B18F4, lbl_804B065A, &sp8, 4, 0);
                lbl_804AB9B4 = 0x64;
                lbl_804AB9B8 = sp8;
            } else {
                lbl_804AB9B4 = 0x32;
            }
        }
        temp_r30 = lbl_804B18F4;
        temp_r29 = lbl_804B065C;
        fn_80207B30(temp_r30, temp_r29, arg0, fn_802EF9C0(arg0), 0);
    }
}

extern s32 lbl_804AB9B4;
extern s32 lbl_804AB9B8;
extern u16 lbl_804B065A;
extern u16 lbl_804B065E;
extern s32 lbl_804B18F4;

void w3d_auto_80207e1c(s32 *arg0) {
    s32 sp8;
    s32 temp_r30;
    s32 temp_r3;
    s32 temp_r9;
    u16 temp_r29;

    if ((s32) lbl_804B18F4 != 0) {
        temp_r9 = lbl_804AB9B4 - 1;
        lbl_804AB9B4 = temp_r9;
        if (temp_r9 == 0) {
            temp_r3 = fn_801FE45C();
            sp8 = temp_r3;
            if ((u32) (temp_r3 - lbl_804AB9B8) > 2U) {
                fn_80207B30(lbl_804B18F4, lbl_804B065A, &sp8, 4, 0);
                lbl_804AB9B4 = 0x64;
                lbl_804AB9B8 = sp8;
            } else {
                lbl_804AB9B4 = 0x32;
            }
        }
        temp_r30 = lbl_804B18F4;
        temp_r29 = lbl_804B065E;
        fn_80207B30(temp_r30, temp_r29, arg0, fn_802EF9C0(arg0), 0);
    }
}
