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
M2C_UNK fn_8015F518(M2C_UNK *, M2C_UNK *);          /* extern */
M2C_UNK fn_8016115C(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
void fn_800DA958(void);
extern M2C_UNK lbl_80360CC0[];
extern M2C_UNK lbl_80361860[];
extern M2C_UNK lbl_80389900[];
extern M2C_UNK lbl_80389918[];
extern M2C_UNK lbl_80389930[];
extern M2C_UNK lbl_80389948[];
extern M2C_UNK lbl_80389960[];
extern M2C_UNK lbl_80389978[];
extern M2C_UNK lbl_80389988[];
extern M2C_UNK lbl_8038999C[];
extern M2C_UNK lbl_803899B0[];
extern M2C_UNK lbl_803899C8[];
extern M2C_UNK lbl_803899E0[];
extern M2C_UNK lbl_80389A00[];
extern M2C_UNK lbl_80389A14[];
extern M2C_UNK lbl_803E8178[];
extern s32 lbl_804AAE84;
extern s32 lbl_804AEBA0;
extern s32 lbl_804AEBB0;
extern s32 lbl_804AEBA8;
extern s32 lbl_804AEBAC;
extern s32 lbl_804AEBC0;
extern s32 lbl_804AEBB4;
extern s32 lbl_804AEBB8;
extern s32 lbl_804AEBBC;
extern s32 lbl_804AEBA4;
extern M2C_UNK lbl_804AEBC4;
extern M2C_UNK lbl_804AEBCC;
extern M2C_UNK lbl_804AEBD4;
extern M2C_UNK lbl_804AEBDC;
extern M2C_UNK lbl_804AEBE4;
extern M2C_UNK lbl_804AEBEC;
extern M2C_UNK lbl_804AEBF4;
extern M2C_UNK lbl_804AEBFC;
extern M2C_UNK lbl_804AEC04;
extern M2C_UNK lbl_804AEC0C;
extern M2C_UNK lbl_804AEC14;
extern M2C_UNK lbl_804AEC1C;
extern M2C_UNK lbl_804AEC24;

void s8_bound_800dc418(s32 arg0, s32 arg1) {
    s32 temp_r10;

    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    { s32 base=lbl_804AAE84;
    s32 maskEnd=base+0x4000;
    s32 offset736=base+0x2e0;
    s32 offset12400=base+0x3070;
    s32 offset16368=base+0x3ff0;
    s32 offset16304=base+0x3fb0;
    s32 offset16176=base+0x3f30;
    lbl_804AEBA0 = maskEnd;
    lbl_804AEBA8 = offset736;
    lbl_804AEBAC = offset12400;
    lbl_804AEBA4 = base;
    lbl_804AEBB0 = base;
    lbl_804AEBC0 = base;
    lbl_804AEBB4 = offset16368;
    lbl_804AEBB8 = offset16304;
    lbl_804AEBBC = offset16176;
    }
    fn_8016115C(&(*lbl_80360CC0), &(*lbl_803E8178), &(*lbl_80361860), &fn_800DA958, 0xB, 0);
    fn_8015F518(&lbl_804AEBC4, &(*lbl_80389900));
    fn_8015F518(&lbl_804AEBCC, &(*lbl_80389918));
    fn_8015F518(&lbl_804AEBD4, &(*lbl_80389930));
    fn_8015F518(&lbl_804AEBDC, &(*lbl_80389948));
    fn_8015F518(&lbl_804AEBE4, &(*lbl_80389960));
    fn_8015F518(&lbl_804AEBEC, &(*lbl_80389978));
    fn_8015F518(&lbl_804AEBF4, &(*lbl_80389988));
    fn_8015F518(&lbl_804AEBFC, &(*lbl_8038999C));
    fn_8015F518(&lbl_804AEC04, &(*lbl_803899B0));
    fn_8015F518(&lbl_804AEC0C, &(*lbl_803899C8));
    fn_8015F518(&lbl_804AEC14, &(*lbl_803899E0));
    fn_8015F518(&lbl_804AEC1C, &(*lbl_80389A00));
    fn_8015F518(&lbl_804AEC24, &(*lbl_80389A14));
block_3:
    return;
}
