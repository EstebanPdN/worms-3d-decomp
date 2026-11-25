#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8mnospill_8009dd10.c"
/* s8 range recovery: ordinary C, compiled against the reference ProDG route. */
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
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)(w3d::bytes(expr) + (offset)))

/* Bitwise (reinterpret) cast */
#define M2C_BITWISE(type, expr) ((w3d::slot_t<type>)(expr))

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

M2C_UNK fn_80165254();                              /* extern */
M2C_UNK fn_80209920(Ptr32<M2C_UNK>, Ptr32<void>);             /* extern */
extern M2C_UNK lbl_804AF5BC;
M2C_UNK fn_800A7E14(u32, Ptr32<M2C_UNK>);                /* extern */
extern M2C_UNK lbl_803814DC[];
M2C_UNK fn_8015F518(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);          /* extern */
M2C_UNK fn_80160038(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>, Ptr32<M2C_UNK>, Ptr32<M2C_UNK>, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK lbl_80360EA0[];
extern M2C_UNK lbl_803617D0[];
extern M2C_UNK lbl_8038C230[];
extern M2C_UNK lbl_8038C23C[];
extern M2C_UNK lbl_8038C248[];
extern M2C_UNK lbl_8038C260[];
extern M2C_UNK lbl_8038C278[];
extern M2C_UNK lbl_8038C294[];
extern M2C_UNK lbl_8038C2AC[];
extern M2C_UNK lbl_803E8290[];
extern s8 lbl_804AF025;
extern s8 lbl_804AF026;
extern s8 lbl_804AF027;
extern s8 lbl_804AF024;
extern M2C_UNK lbl_804AF028;
extern M2C_UNK lbl_804AF030;
extern M2C_UNK lbl_804AF038;
extern M2C_UNK lbl_804AF040;
extern M2C_UNK lbl_804AF048;
extern M2C_UNK lbl_804AF050;
extern M2C_UNK lbl_804AF058;
M2C_UNK fn_800F339C(Ptr32<void>);                        /* extern */
M2C_UNK fn_800F342C(Ptr32<void>);                        /* extern */
M2C_UNK fn_800F34A0(Ptr32<void>);                        /* extern */
M2C_UNK fn_800F6AFC();                              /* extern */
extern s32 lbl_804B184C;
M2C_UNK fn_801629F8(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>, Ptr32<M2C_UNK>, Ptr32<M2C_UNK>, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK lbl_80360F60[];
extern M2C_UNK lbl_803618F0[];
extern M2C_UNK lbl_803E8300[];

void s8_recovered_8009dd10(Ptr32<void> arg0, s32 arg1) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<Ptr32<void>> temp_r3_2;
    Ptr32<Ptr32<void>> temp_r3_3;
    Ptr32<Ptr32<void>> temp_r3_4;

    fn_80165254();
    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x80);
    if (temp_r3 != NULL) {
        M2C_FIELD(*temp_r3, Ptr32<M2C_UNK (Ptr32<void>)> *, 0x10)(temp_r3);
    }
    temp_r3_2 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x10);
    if (temp_r3_2 != NULL) {
        M2C_FIELD(*temp_r3_2, Ptr32<M2C_UNK (Ptr32<void>)> *, 0x10)(temp_r3_2);
    }
    temp_r3_3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0xC);
    if (temp_r3_3 != NULL) {
        M2C_FIELD(*temp_r3_3, Ptr32<M2C_UNK (Ptr32<void>)> *, 0x10)(temp_r3_3);
    }
    temp_r3_4 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 8);
    if (temp_r3_4 != NULL) {
        M2C_FIELD(*temp_r3_4, Ptr32<M2C_UNK (Ptr32<void>)> *, 0x10)(temp_r3_4);
    }
    if (arg1 & 1) {
        fn_80209920(&lbl_804AF5BC, arg0);
    }
}

void s8_recovered_800a7ea0(void) {
    u32 var_r31;

    var_r31 = 0U;
    do {
        fn_800A7E14(var_r31, &(*lbl_803814DC));
        var_r31 += 1;
    } while (var_r31 <= 7U);
}

Ptr32<void> fn_800EFD60(void);

void s8_recovered_800f0c6c(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        fn_80160038(&(*lbl_80360EA0), &(*lbl_803E8290), &(*lbl_803617D0), &fn_800EFD60, 9, 0);
        lbl_804AF024 = -1;
        lbl_804AF025 = -1;
        lbl_804AF026 = -1;
        lbl_804AF027 = -1;
        fn_8015F518(&lbl_804AF028, &(*lbl_8038C230));
        fn_8015F518(&lbl_804AF030, &(*lbl_8038C23C));
        fn_8015F518(&lbl_804AF038, &(*lbl_8038C248));
        fn_8015F518(&lbl_804AF040, &(*lbl_8038C260));
        fn_8015F518(&lbl_804AF048, &(*lbl_8038C278));
        fn_8015F518(&lbl_804AF050, &(*lbl_8038C294));
        fn_8015F518(&lbl_804AF058, &(*lbl_8038C2AC));
    }
}

void s8_recovered_800f2f28(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;

    fn_800F6AFC();
    fn_800F34A0(arg0);
    fn_800F342C(arg0);
    fn_800F339C(arg0);
    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x20);
    lbl_804B184C = 0;
    if (temp_r3 != NULL) {
        M2C_FIELD(*temp_r3, Ptr32<M2C_UNK (Ptr32<void>)> *, 0x10)(temp_r3);
    }
    M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x20) = NULL;
}

Ptr32<void> fn_800F29FC(void);

void s8_recovered_800f6e28(s32 arg0, s32 arg1) {
    s32 var_ctr;

    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        fn_801629F8(&(*lbl_80360F60), &(*lbl_803E8300), &(*lbl_803618F0), &fn_800F29FC, 0xA, 0);
        var_ctr = 3;
        do {
            var_ctr -= 1;
        } while (var_ctr != 0);
    }
}

}
