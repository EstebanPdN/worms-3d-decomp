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

s32 fn_800A830C(void *);                               /* extern */
M2C_UNK fn_801359EC(void *, s32, s32, void *, f32, f32, f32); /* extern */
M2C_UNK fn_8013BD0C(void *, M2C_UNK *);             /* extern */
s32 fn_8013FECC(void *);                            /* extern */
s32 fn_80162C20();                                  /* extern */
s32 fn_80343584(s32);                               /* extern */
M2C_UNK fn_8015CDEC(M2C_UNK *);                     /* extern */
M2C_UNK fn_8020FBD0(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 fn_8015C384();                                  /* extern */
M2C_UNK fn_8020EE9C(M2C_UNK *);                     /* extern */
s32 fn_8015EA78();                                  /* extern */
M2C_UNK fn_8015F4CC(void *);                              void fn_8020C5C0(s32);                           /* extern */
u16 *fn_80341884(void *);                              /* extern */

extern M2C_UNK lbl_8039EEC4[];
extern M2C_UNK lbl_8039EECC[];
extern f32 lbl_8039FE2C[];
extern f32 lbl_8039FE30[];
extern f32 lbl_8039FE34[];
extern s32 lbl_804AB304;
extern s32 lbl_804AB308;

void w3d_auto_8013fdec(void *arg0, s32 arg1) {
    s32 temp_r30;

    if (fn_800A830C(arg1) != (s32) M2C_FIELD(arg0, s32 *, 0x70)) {
        goto block_5;
    }
    if (fn_8013FECC(arg0) == 0) {
        goto block_5;
    }
    temp_r30 = fn_80343584(M2C_FIELD(arg0, s32 *, 0x1C));
    if (fn_80162C20() & 1) {
        goto block_4;
    }
    fn_801359EC(arg0, temp_r30, lbl_804AB304, arg0 + 0x1D8, (*lbl_8039FE2C), (*lbl_8039FE30), (*lbl_8039FE34));
    fn_8013BD0C(arg0, &(*lbl_8039EEC4));
    return;
block_4:
    fn_801359EC(arg0, temp_r30, lbl_804AB308, arg0 + 0x1D8, (*lbl_8039FE2C), (*lbl_8039FE30), (*lbl_8039FE34));
    fn_8013BD0C(arg0, &(*lbl_8039EECC));
block_5:
    return;
}

extern M2C_UNK lbl_803616B0[];
extern M2C_UNK lbl_803616E0[];
extern M2C_UNK lbl_803E8744[];
extern M2C_UNK lbl_80455170[];

void w3d_auto_8015bd38(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015CDEC(&(*lbl_80455170));
    fn_8020FBD0(&(*lbl_803616B0), &(*lbl_803E8744), &(*lbl_803616E0), 0, 0, 0);
block_3:
    return;
}

extern M2C_UNK lbl_803616E0[];
extern M2C_UNK lbl_803E8760[];

void w3d_auto_8015c300(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020FBD0(&(*lbl_803616E0), &(*lbl_803E8760), &(*lbl_803616E0), 0, 0, 0);
block_3:
    return;
}

extern M2C_UNK lbl_80455190[];
extern s32 lbl_804B0058;

void w3d_auto_8015c3fc(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_80455190));
    lbl_804B0058 = fn_8015C384();
block_3:
    return;
}

extern M2C_UNK lbl_803616B0[];
extern M2C_UNK lbl_80361710[];
extern M2C_UNK lbl_803E877C[];

void w3d_auto_8015cd64(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020FBD0(&(*lbl_80361710), &(*lbl_803E877C), &(*lbl_803616B0), 0, 0, 0);
block_3:
    return;
}

extern M2C_UNK lbl_804551D8[];
extern s32 lbl_804B00C0;

void w3d_auto_8015eae0(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_804551D8));
    lbl_804B00C0 = fn_8015EA78();
block_3:
    return;
}

void *w3d_auto_8015f69c(void *arg0, s32 *arg1) {
    s32 temp_r29;
    u16 *temp_r3;

    temp_r29 = arg0 + 8;
    fn_8015F4CC(arg0);
    fn_8020C5C0(temp_r29);
    M2C_FIELD(arg0, s32 *, 8) = (s32) *arg1;
    temp_r3 = fn_80341884(temp_r29);
    *temp_r3 += 1;
    M2C_FIELD(arg0, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 8);
    return arg0;
}
