#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s11assign_8026da58.c"
/* Range-isolated m2c recovery by worker s11. Types and names are provisional. */
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

M2C_UNK fn_800F339C(Ptr32<void>);                           /* extern */
M2C_UNK fn_800F342C(Ptr32<void>);                              /* extern */
M2C_UNK fn_80162C18(s32);                              /* extern */
M2C_UNK fn_8020BD38(Ptr32<void>, Ptr32<M2C_UNK>);             /* extern */
extern M2C_UNK lbl_803CBD18[];
extern M2C_UNK lbl_803CBD7C[];
extern Ptr32<void> lbl_804B1788;
extern Ptr32<void> lbl_804B17EC;

static inline void s11_assign_slot(Ptr32<Ptr32<Ptr32<void>>> slot, Ptr32<Ptr32<void>> next) {
    Ptr32<Ptr32<void>> old=*slot;
    if(old) M2C_FIELD(*old, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *,0x10)(old);
    *slot=next;
}

void w3d_auto_8026da58(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r30;
    Ptr32<Ptr32<void>> temp_r30_2;
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<Ptr32<void>> temp_r3_2;
    Ptr32<Ptr32<void>> temp_r3_3;
    Ptr32<Ptr32<void>> temp_r3_4;
    Ptr32<Ptr32<void>> temp_r3_5;
    Ptr32<void> temp_r29;
    Ptr32<void> global;
    Ptr32<void> temp_r29_2;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x44) == 0) {
        goto block_2;
    }
    fn_800F342C(w3d::G(M2C_FIELD(arg0, s32 *, 0x44)));
    fn_800F339C(w3d::G(M2C_FIELD(arg0, s32 *, 0x44)));
block_2:
    if ((void **) M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x4C) == NULL) {
        goto block_6;
    }
    temp_r3 = M2C_FIELD(lbl_804B17EC, Ptr32<Ptr32<void>> *, 0x74);
    M2C_FIELD(*temp_r3, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, Ptr32<M2C_UNK>, M2C_UNK)> *, 0xC4)(temp_r3, &(*lbl_803CBD18), 4);
    goto loop_5;
block_4:
    temp_r30 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x4C);
    temp_r29 = *temp_r30;
    M2C_FIELD(temp_r29, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32)> *, 0x60)(temp_r30, M2C_FIELD(temp_r29, Ptr32<s32 (Ptr32<Ptr32<void>>, M2C_UNK)> *, 0x74)(temp_r30, 0));
loop_5:
    temp_r3_2 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x4C);
    if (M2C_FIELD(*temp_r3_2, Ptr32<s32 (Ptr32<Ptr32<void>>)> *, 0x78)(temp_r3_2) != 0) {
        goto block_4;
    }
block_6:
    if ((void **) M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x48) == NULL) {
        goto block_10;
    }
    goto loop_9;
block_8:
    temp_r30_2 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x48);
    temp_r29_2 = *temp_r30_2;
    M2C_FIELD(temp_r29_2, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32)> *, 0x60)(temp_r30_2, M2C_FIELD(temp_r29_2, Ptr32<s32 (Ptr32<Ptr32<void>>, M2C_UNK)> *, 0x74)(temp_r30_2, 0));
loop_9:
    temp_r3_3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x48);
    if (M2C_FIELD(*temp_r3_3, Ptr32<s32 (Ptr32<Ptr32<void>>)> *, 0x78)(temp_r3_3) != 0) {
        goto block_8;
    }
block_10:
    s11_assign_slot((Ptr32<Ptr32<Ptr32<void>>>)((Ptr32<char>)arg0+0x48), NULL);
    s11_assign_slot((Ptr32<Ptr32<Ptr32<void>>>)((Ptr32<char>)arg0+0x4c), NULL);
    fn_8020BD38(arg0 + 0x38, &(*lbl_803CBD7C));
    global=lbl_804B1788;
    M2C_FIELD(arg0, s32 *, 0x50) = 1;
    if ((s32) M2C_FIELD(global, s32 *, 0xA8) == 0) {
        goto block_16;
    }
    fn_80162C18(M2C_FIELD(global, s32 *, 0xA8));
block_16:
    return;
}

}
