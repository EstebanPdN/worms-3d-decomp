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


M2C_UNK fn_80022634();                              /* extern */
s32 fn_80023010();                                  /* extern */
M2C_UNK fn_80209920(M2C_UNK *, s32);                /* extern */
M2C_UNK fn_800243A8(void *, M2C_UNK);               /* extern */
M2C_UNK fn_80024448(void *);                        /* extern */
M2C_UNK fn_80024844(void *, M2C_UNK, M2C_UNK);      /* extern */
s32 fn_8006E71C();                                  /* extern */
s32 fn_80178C48(void *);                               /* extern */
s32 fn_80178D1C(void *);                               /* extern */
M2C_UNK fn_80024990(void *, s32, s32);              /* extern */
void *fn_800FC6DC(u32);                             /* extern */
s32 fn_800FCEA0();                                  /* extern */
s8 fn_8012F954(s32);                                /* extern */
M2C_UNK fn_80173F88(void *, s8 *);                     /* extern */
s32 fn_8034357C(s32);                               /* extern */

void w3d_auto_800229ec(void) {
    fn_80022634();
}

extern M2C_UNK lbl_804ACA40;

s32 w3d_auto_80022bec(s32 arg0) {
    s32 temp_r29;

    temp_r29 = fn_80023010();
    fn_80209920(&lbl_804ACA40, arg0);
    return temp_r29;
}

extern void *lbl_804AAABC;

s32 w3d_auto_800242e0(void *arg0) {
    s32 temp_r3;

    temp_r3 = fn_80178C48(M2C_FIELD(arg0, s32 *, 0x30));
    if (temp_r3 != (s32) M2C_FIELD(arg0, s32 *, 0x88)) {
        M2C_FIELD(arg0, s32 *, 0x88) = temp_r3;
        fn_80024448(arg0);
        fn_80024844(arg0, 0, 0);
    }
    if ((fn_80178D1C(M2C_FIELD(arg0, s32 *, 0x54)) != 0) || (fn_80178D1C(M2C_FIELD(arg0, s32 *, 0x58)) != 0) || (fn_80178D1C(M2C_FIELD(arg0, s32 *, 0x5C)) != 0) || (M2C_FIELD(lbl_804AAABC, s32 *, 0xF0) & 0x800000) || (fn_8006E71C() != 0)) {
        fn_800243A8(arg0, 0);
    } else {
        fn_800243A8(arg0, 1);
    }
    return 0;
}

void w3d_auto_80024844(void *arg0, s32 arg1, s32 arg2) {
    s8 sp8;
    s8 sp9;
    s32 temp_r29;
    s32 temp_r30;
    s32 var_r27;

    var_r27 = 0;
    temp_r29 = fn_8034357C(M2C_FIELD(arg0, s32 *, 0x28));
    if (((u32) M2C_FIELD(arg0, u32 *, 0x88) <= 0xFU) && (fn_800FCEA0() != 0) && (arg2 == 0)) {
        var_r27 = 1;
        temp_r30 = M2C_FIELD(fn_800FC6DC(M2C_FIELD(arg0, u32 *, 0x88)), s32 *, 0x84);
        sp8 = fn_8012F954(temp_r30);
        fn_80173F88(temp_r29, &sp8);
        fn_80024990(arg0, temp_r30, arg1);
    }
    if (var_r27 == 0) {
        sp9 = 0x3F;
        fn_80173F88(temp_r29, &sp9);
    }
}
