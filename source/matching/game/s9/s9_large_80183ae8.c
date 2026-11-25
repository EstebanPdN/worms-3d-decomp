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
M2C_UNK fn_80190384(void *, s32);                   /* extern */
extern M2C_UNK lbl_80412BC8[];
extern s32 lbl_804AB660;
extern void **lbl_804B01D4;
extern void **lbl_804B01D8;
extern void **lbl_804B01DC;
extern void **lbl_804B01E0;
extern void **lbl_804B01E4;
extern void **lbl_804B01E8;
extern void **lbl_804B01EC;
extern void **lbl_804B01F0;
extern void **lbl_804B01F4;
extern void **lbl_804B01F8;
extern void **lbl_804B01FC;
extern void **lbl_804B0200;

void w3d_auto_80183ae8(void *arg0, s32 arg1) {
    s32 temp_r31;
    void **temp_r3;
    void **temp_r3_2;
    void **temp_r3_3;
    void **temp_r3_4;
    void *temp_r9;

    temp_r3 = M2C_FIELD(arg0, void ***, 0x30);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_80412BC8);
    if (temp_r3 == NULL) {
        goto block_2;
    }
    temp_r9 = *temp_r3;
    M2C_FIELD(temp_r9, M2C_UNK (**)(void *), 0x10)(temp_r3);
block_2:
    temp_r3_2 = M2C_FIELD(arg0, void ***, 0x2C);
    M2C_FIELD(arg0, void ***, 0x30) = NULL;
    if (temp_r3_2 == NULL) {
        goto block_4;
    }
    M2C_FIELD(*temp_r3_2, M2C_UNK (**)(void *), 0x10)(temp_r3_2);
block_4:
    M2C_FIELD(arg0, void ***, 0x2C) = NULL;
    temp_r31 = lbl_804AB660 - 1;
    lbl_804AB660 = temp_r31;
    if (temp_r31 != 0) {
        goto block_30;
    }
    if ((void **) lbl_804B01D4 == NULL) {
        goto block_7;
    }
    M2C_FIELD(*lbl_804B01D4, M2C_UNK (**)(void *), 0x10)(lbl_804B01D4);
block_7:
    lbl_804B01D4 = (void **)temp_r31;
    if ((void **) lbl_804B01D8 == NULL) {
        goto block_9;
    }
    M2C_FIELD(*lbl_804B01D8, M2C_UNK (**)(void *), 0x10)(lbl_804B01D8);
block_9:
    lbl_804B01D8 = NULL;
    if ((void **) lbl_804B01DC == NULL) {
        goto block_11;
    }
    M2C_FIELD(*lbl_804B01DC, M2C_UNK (**)(void *), 0x10)(lbl_804B01DC);
block_11:
    lbl_804B01DC = NULL;
    if ((void **) lbl_804B01E0 == NULL) {
        goto block_13;
    }
    M2C_FIELD(*lbl_804B01E0, M2C_UNK (**)(void *), 0x10)(lbl_804B01E0);
block_13:
    lbl_804B01E0 = NULL;
    if ((void **) lbl_804B01E4 == NULL) {
        goto block_15;
    }
    M2C_FIELD(*lbl_804B01E4, M2C_UNK (**)(void *), 0x10)(lbl_804B01E4);
block_15:
    lbl_804B01E4 = NULL;
    if ((void **) lbl_804B01E8 == NULL) {
        goto block_17;
    }
    M2C_FIELD(*lbl_804B01E8, M2C_UNK (**)(void *), 0x10)(lbl_804B01E8);
block_17:
    lbl_804B01E8 = NULL;
    if ((void **) lbl_804B01EC == NULL) {
        goto block_19;
    }
    M2C_FIELD(*lbl_804B01EC, M2C_UNK (**)(void *), 0x10)(lbl_804B01EC);
block_19:
    lbl_804B01EC = NULL;
    if ((void **) lbl_804B01F0 == NULL) {
        goto block_21;
    }
    M2C_FIELD(*lbl_804B01F0, M2C_UNK (**)(void *), 0x10)(lbl_804B01F0);
block_21:
    lbl_804B01F0 = NULL;
    if ((void **) lbl_804B01F4 == NULL) {
        goto block_23;
    }
    M2C_FIELD(*lbl_804B01F4, M2C_UNK (**)(void *), 0x10)(lbl_804B01F4);
block_23:
    lbl_804B01F4 = NULL;
    if ((void **) lbl_804B01F8 == NULL) {
        goto block_25;
    }
    M2C_FIELD(*lbl_804B01F8, M2C_UNK (**)(void *), 0x10)(lbl_804B01F8);
block_25:
    lbl_804B01F8 = NULL;
    if ((void **) lbl_804B01FC == NULL) {
        goto block_27;
    }
    M2C_FIELD(*lbl_804B01FC, M2C_UNK (**)(void *), 0x10)(lbl_804B01FC);
block_27:
    lbl_804B01FC = NULL;
    if ((void **) lbl_804B0200 == NULL) {
        goto block_29;
    }
    M2C_FIELD(*lbl_804B0200, M2C_UNK (**)(void *), 0x10)(lbl_804B0200);
block_29:
    lbl_804B0200 = NULL;
block_30:
    temp_r3_3 = M2C_FIELD(arg0, void ***, 0x30);
    if (temp_r3_3 == NULL) {
        goto block_32;
    }
    M2C_FIELD(*temp_r3_3, M2C_UNK (**)(void *), 0x10)(temp_r3_3);
block_32:
    temp_r3_4 = M2C_FIELD(arg0, void ***, 0x2C);
    if (temp_r3_4 == NULL) {
        goto block_34;
    }
    M2C_FIELD(*temp_r3_4, M2C_UNK (**)(void *), 0x10)(temp_r3_4);
block_34:
    fn_80190384(arg0, arg1);
    return;
}
