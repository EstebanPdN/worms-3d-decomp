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
void * fn_8009EF38(void);
extern M2C_UNK lbl_80360690[];
extern M2C_UNK lbl_80360E10[];
extern M2C_UNK lbl_8038079C[];
extern M2C_UNK lbl_803807B0[];
extern M2C_UNK lbl_803807C4[];
extern M2C_UNK lbl_803807DC[];
extern M2C_UNK lbl_803E7DDC[];
extern s32 lbl_804AAC0C;
extern s32 lbl_804AE0E4;
extern s32 lbl_804AE0F4;
extern s32 lbl_804AE0EC;
extern s32 lbl_804AE0F0;
extern s32 lbl_804AE104;
extern s32 lbl_804AE0F8;
extern s32 lbl_804AE0FC;
extern s32 lbl_804AE100;
extern s32 lbl_804AE0E8;
extern M2C_UNK lbl_804AE108;
extern M2C_UNK lbl_804AE110;
extern M2C_UNK lbl_804AE118;
extern M2C_UNK lbl_804AE120;

void s8_initialize_8009fd54(s32 arg0, s32 arg1) {
    s32 temp_r10;

    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    { s32 base=lbl_804AAC0C;
    s32 maskEnd=base+0x4000;
    s32 offset736=base+0x2e0;
    s32 offset12400=base+0x3070;
    s32 offset16368=base+0x3ff0;
    s32 offset16304=base+0x3fb0;
    s32 offset16176=base+0x3f30;
    lbl_804AE0E4 = maskEnd;
    lbl_804AE0EC = offset736;
    lbl_804AE0F0 = offset12400;
    lbl_804AE0E8 = base;
    lbl_804AE0F4 = base;
    lbl_804AE104 = base;
    lbl_804AE0F8 = offset16368;
    lbl_804AE0FC = offset16304;
    lbl_804AE100 = offset16176;
    }
    fn_8016115C(&(*lbl_80360690), &(*lbl_803E7DDC), &(*lbl_80360E10), &fn_8009EF38, 0xB, 0);
    fn_8015F518(&lbl_804AE108, &(*lbl_8038079C));
    fn_8015F518(&lbl_804AE110, &(*lbl_803807B0));
    fn_8015F518(&lbl_804AE118, &(*lbl_803807C4));
    fn_8015F518(&lbl_804AE120, &(*lbl_803807DC));
block_3:
    return;
}
