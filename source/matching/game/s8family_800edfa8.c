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
void * fn_800EA0AC(void);
extern M2C_UNK lbl_80360E10[];
extern M2C_UNK lbl_80361860[];
extern M2C_UNK lbl_8038b6a0[];
extern M2C_UNK lbl_8038b6b0[];
extern M2C_UNK lbl_8038b6c0[];
extern M2C_UNK lbl_8038b6cc[];
extern M2C_UNK lbl_8038b6dc[];
extern M2C_UNK lbl_8038b6ec[];
extern M2C_UNK lbl_8038b6fc[];
extern M2C_UNK lbl_8038B710[];
extern M2C_UNK lbl_8038B720[];
extern M2C_UNK lbl_8038B738[];
extern M2C_UNK lbl_8038B748[];
extern M2C_UNK lbl_8038B760[];
extern M2C_UNK lbl_8038B77C[];
extern M2C_UNK lbl_803E823C[];
extern s32 lbl_804AAEF4;
extern s32 lbl_804AEECC;
extern s32 lbl_804AEEDC;
extern s32 lbl_804AEED4;
extern s32 lbl_804AEED8;
extern s32 lbl_804AEEEC;
extern s32 lbl_804AEEE0;
extern s32 lbl_804AEEE4;
extern s32 lbl_804AEEE8;
extern s32 lbl_804AEED0;
extern M2C_UNK lbl_804AEEF0;
extern M2C_UNK lbl_804AEEF8;
extern M2C_UNK lbl_804AEF00;
extern M2C_UNK lbl_804AEF08;
extern M2C_UNK lbl_804AEF10;
extern M2C_UNK lbl_804AEF18;
extern M2C_UNK lbl_804AEF20;
extern M2C_UNK lbl_804AEF28;
extern M2C_UNK lbl_804AEF30;
extern M2C_UNK lbl_804AEF38;
extern M2C_UNK lbl_804AEF40;
extern M2C_UNK lbl_804AEF48;
extern M2C_UNK lbl_804AEF50;

void s8_initialize_800edfa8(s32 arg0, s32 arg1) {
    s32 temp_r10;

    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    { s32 base=lbl_804AAEF4;
    s32 maskEnd=base+0x4000;
    s32 offset736=base+0x2e0;
    s32 offset12400=base+0x3070;
    s32 offset16368=base+0x3ff0;
    s32 offset16304=base+0x3fb0;
    s32 offset16176=base+0x3f30;
    lbl_804AEECC = maskEnd;
    lbl_804AEED4 = offset736;
    lbl_804AEED8 = offset12400;
    lbl_804AEED0 = base;
    lbl_804AEEDC = base;
    lbl_804AEEEC = base;
    lbl_804AEEE0 = offset16368;
    lbl_804AEEE4 = offset16304;
    lbl_804AEEE8 = offset16176;
    }
    fn_8016115C(&(*lbl_80360E10), &(*lbl_803E823C), &(*lbl_80361860), &fn_800EA0AC, 0xB, 0);
    fn_8015F518(&lbl_804AEEF0, &(*lbl_8038b6a0));
    fn_8015F518(&lbl_804AEEF8, &(*lbl_8038b6b0));
    fn_8015F518(&lbl_804AEF00, &(*lbl_8038b6c0));
    fn_8015F518(&lbl_804AEF08, &(*lbl_8038b6cc));
    fn_8015F518(&lbl_804AEF10, &(*lbl_8038b6dc));
    fn_8015F518(&lbl_804AEF18, &(*lbl_8038b6ec));
    fn_8015F518(&lbl_804AEF20, &(*lbl_8038b6fc));
    fn_8015F518(&lbl_804AEF28, &(*lbl_8038B710));
    fn_8015F518(&lbl_804AEF30, &(*lbl_8038B720));
    fn_8015F518(&lbl_804AEF38, &(*lbl_8038B738));
    fn_8015F518(&lbl_804AEF40, &(*lbl_8038B748));
    fn_8015F518(&lbl_804AEF48, &(*lbl_8038B760));
    fn_8015F518(&lbl_804AEF50, &(*lbl_8038B77C));
block_3:
    return;
}
