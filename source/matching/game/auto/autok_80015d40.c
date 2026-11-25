/* Decompiled automatically by m2c; statement order, callee return width or a
 * guarded call argument adjusted by tools/m2c_reorder.py and verified identical
 * to the original after linking. Types and names are m2c placeholders pending
 * review. */
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

void *fn_8001523C(M2C_UNK);                         /* extern */
extern void *lbl_804AA6F8;
extern void *lbl_804AA6FC;
extern void *lbl_804AA700;
M2C_UNK fn_803426B8(void *);                           /* extern */
M2C_UNK fn_800E5BB8(s32);                              /* extern */
M2C_UNK fn_8018E26C();                              /* extern */
extern M2C_UNK lbl_804130C0[];
void *fn_80212FD4(M2C_UNK);                         /* extern */
s32 fn_80213C30(s32, s32);                          /* extern */
M2C_UNK fn_801FE160(s32);                              /* extern */
M2C_UNK fn_802134FC();                              /* extern */
extern M2C_UNK lbl_803B3080[];
M2C_UNK fn_8015FEF0();                              /* extern */
M2C_UNK fn_802AFB20(void *);                           /* extern */
extern M2C_UNK lbl_8041C7D0[];
extern M2C_UNK lbl_8041C820[];

void w3d_auto_80015d40(void) {
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r3_3;

    temp_r3 = fn_8001523C(0x10);
    M2C_FIELD(temp_r3, s32 *, 8) = 0;
    M2C_FIELD(temp_r3, s32 *, 4) = 0;
    M2C_FIELD(temp_r3, s32 *, 0) = 0;
    lbl_804AA6F8 = temp_r3;
    temp_r3_2 = fn_8001523C(0x10);
    M2C_FIELD(temp_r3_2, s32 *, 8) = 0;
    M2C_FIELD(temp_r3_2, s32 *, 4) = 0;
    M2C_FIELD(temp_r3_2, s32 *, 0) = 0;
    lbl_804AA6FC = temp_r3_2;
    temp_r3_3 = fn_8001523C(0x10);
    M2C_FIELD(temp_r3_3, s32 *, 8) = 0;
    M2C_FIELD(temp_r3_3, s32 *, 4) = 0;
    M2C_FIELD(temp_r3_3, s32 *, 0) = 0;
    lbl_804AA700 = temp_r3_3;
    return;
}

void *w3d_auto_80060088(void *arg0) {
    fn_803426B8(arg0 + 0x3C);
    fn_803426B8(arg0 + 0x40);
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    M2C_FIELD(arg0, s32 *, 0x4C) = 0;
    M2C_FIELD(arg0, s32 *, 0x48) = 0;
    return arg0;
}

void w3d_auto_8013f57c(void *arg0, s32 arg1) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x23C) == 0) {
        goto block_3;
    }
    if (arg1 == 1) {
        goto block_3;
    }
    fn_800E5BB8(M2C_FIELD(arg0, s32 *, 0x23C));
    M2C_FIELD(arg0, s32 *, 0x23C) = 0;
block_3:
    return;
}

void w3d_auto_801626c8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = -1;
    M2C_FIELD(arg0, s16 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 1;
    return;
}

s32 w3d_auto_801676e0(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    M2C_FIELD(arg0, s16 *, 0xB0) = arg1;
    M2C_FIELD(arg0, s16 *, 0xB2) = arg2;
    M2C_FIELD(arg0, s16 *, 0xB4) = arg3;
    M2C_FIELD(arg0, s16 *, 0xB6) = arg4;
    return 0;
}

void w3d_auto_8016f8a0(void *arg0, s16 arg1, s16 arg2, s16 arg3, s8 arg4) {
    M2C_FIELD(arg0, s16 *, 0x14) = arg1;
    M2C_FIELD(arg0, s16 *, 0x16) = arg2;
    M2C_FIELD(arg0, s16 *, 0x18) = arg3;
    M2C_FIELD(arg0, s8 *, 0x1A) = arg4;
    return;
}

void w3d_auto_801788e4(void *arg0) {
    M2C_FIELD(arg0, s16 *, 8) = -1;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    return;
}

void *w3d_auto_8018ef3c(void *arg0) {
    void *temp_r11;

    fn_8018E26C();
    temp_r11 = arg0 + 0x1C;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_804130C0);
    M2C_FIELD(arg0, s8 *, 0x1C) = 0;
    M2C_FIELD(temp_r11, s8 *, 1) = 0;
    M2C_FIELD(temp_r11, s8 *, 2) = 0;
    M2C_FIELD(temp_r11, s8 *, 3) = 0;
    return arg0;
}

void *w3d_auto_801d67e4(s32 arg0, s32 arg1) {
    s32 temp_r3_2;
    void *temp_r3;

    temp_r3 = fn_80212FD4(0x14);
    if (temp_r3 == NULL) {
        goto block_3;
    }
    temp_r3_2 = fn_80213C30(arg1, arg0);
    M2C_FIELD(temp_r3, s32 *, 8) = temp_r3_2;
    if (temp_r3_2 == 0) {
        goto block_3;
    }
    M2C_FIELD(temp_r3, s32 *, 4) = arg1;
    M2C_FIELD(temp_r3, s32 *, 0) = arg0;
    M2C_FIELD(temp_r3, s32 *, 0xC) = arg0;
    M2C_FIELD(temp_r3, s32 *, 0x10) = 1;
block_3:
    return temp_r3;
}

s32 w3d_auto_80208fd8(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x14) == 0) {
        goto block_5;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x28) == 0) {
        goto block_3;
    }
    fn_801FE160(M2C_FIELD(arg0, s32 *, 0x14));
    goto block_4;
block_3:
    fn_802134FC();
block_4:
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
block_5:
    return 0;
}

s32 w3d_auto_80209030(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0x20);
    M2C_FIELD(arg1, s32 *, 4) = 0;
    M2C_FIELD(arg1, s32 *, 8) = 2;
    return 0;
}

s32 w3d_auto_8020b138(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 8) = 2;
    M2C_FIELD(arg1, s32 *, 0) = 0;
    M2C_FIELD(arg1, M2C_UNK **, 4) = &(*lbl_803B3080);
    return 0;
}

void *w3d_auto_802ba3fc(void *arg0) {
    fn_8015FEF0();
    fn_802AFB20(arg0 + 0x1C);
    M2C_FIELD(arg0, M2C_UNK **, 0xD0) = &(*lbl_8041C7D0);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_8041C820);
    M2C_FIELD(arg0, s32 *, 0xD4) = 0;
    M2C_FIELD(arg0, s32 *, 0xD8) = 0;
    M2C_FIELD(arg0, s32 *, 0xDC) = 0;
    return arg0;
}

void w3d_auto_802e0c78(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    M2C_FIELD(arg0, s16 *, 0x2C) = arg1;
    M2C_FIELD(arg0, s16 *, 0x2E) = arg2;
    M2C_FIELD(arg0, s16 *, 0x30) = arg3;
    M2C_FIELD(arg0, s16 *, 0x32) = arg4;
    return;
}

void w3d_auto_80358118(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    return;
}

void w3d_auto_80359cd8(void *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    M2C_FIELD(arg0, f32 *, 0) = farg1;
    M2C_FIELD(arg0, f32 *, 4) = farg2;
    M2C_FIELD(arg0, f32 *, 8) = farg3;
    M2C_FIELD(arg0, f32 *, 0xC) = farg0;
    return;
}
