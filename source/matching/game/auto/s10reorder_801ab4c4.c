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

void **fn_8020B680(M2C_UNK *);                      /* extern */
extern M2C_UNK lbl_804167F0[];
void **fn_8020B884();                               /* extern */
s32 fn_801E5FD4();                                  /* extern */
M2C_UNK fn_801E65A0(void *);                        /* extern */
M2C_UNK fn_80208FD8();                              /* extern */
M2C_UNK fn_80218D10();                              /* extern */
M2C_UNK fn_80219264();                              /* extern */

s32 w3d_auto_801ab4c4(void *arg0) {
    void **temp_r3;
    void **temp_r3_2;

    if ((void **) M2C_FIELD(arg0, void ***, 0x2C) != NULL) {
        goto block_7;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x54) == 0) {
        goto block_7;
    }
    temp_r3 = fn_8020B680(&(*lbl_804167F0));
    if (temp_r3 == NULL) {
        goto block_4;
    }
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void **), 0xC)(temp_r3);
block_4:
    temp_r3_2 = M2C_FIELD(arg0, void ***, 0x2C);
    if (temp_r3_2 == NULL) {
        goto block_6;
    }
    M2C_FIELD(*temp_r3_2, M2C_UNK (**)(void *), 0x10)(temp_r3_2);
block_6:
    M2C_FIELD(arg0, void ***, 0x2C) = temp_r3;
block_7:
    return 0;
}

void **w3d_auto_801b4938(void *arg0) {
    void **temp_r3;
    void **temp_r3_2;

    if ((void **) M2C_FIELD(arg0, void ***, 0x14) != NULL) {
        goto block_6;
    }
    temp_r3 = fn_8020B884();
    if (temp_r3 == NULL) {
        goto block_3;
    }
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void **), 0xC)(temp_r3);
block_3:
    temp_r3_2 = M2C_FIELD(arg0, void ***, 0x14);
    if (temp_r3_2 == NULL) {
        goto block_5;
    }
    M2C_FIELD(*temp_r3_2, M2C_UNK (**)(void *), 0x10)(temp_r3_2);
block_5:
    M2C_FIELD(arg0, void ***, 0x14) = temp_r3;
block_6:
    return M2C_FIELD(arg0, void ***, 0x14);
}

s32 w3d_auto_801e64c0(void *arg0, void **arg1) {
    void **temp_r3;

    if (fn_801E5FD4() == 0) {
        goto block_2;
    }
    fn_801E65A0(arg0);
block_2:
    M2C_FIELD(arg0, s32 *, 0xC) = M2C_FIELD(*arg1, s32 (**)(void **), 0x78)(arg1);
    M2C_FIELD(arg0, s32 *, 0x10) = M2C_FIELD(*arg1, s32 (**)(void **), 0x74)(arg1);
    M2C_FIELD(arg0, f32 *, 0x24) = M2C_FIELD(*arg1, f32 (**)(void **), 0x64)(arg1);
    M2C_FIELD(arg0, f32 *, 0x28) = M2C_FIELD(*arg1, f32 (**)(void **), 0x68)(arg1);
    if (arg1 == NULL) {
        goto block_4;
    }
    M2C_FIELD(*arg1, M2C_UNK (**)(void **), 0xC)(arg1);
block_4:
    temp_r3 = M2C_FIELD(arg0, void ***, 0x2C);
    if (temp_r3 == NULL) {
        goto block_6;
    }
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void *), 0x10)(temp_r3);
block_6:
    M2C_FIELD(arg0, void ***, 0x2C) = arg1;
    return 1;
}

void w3d_auto_80208ce0(void *arg0) {
    void **temp_r3;

    fn_80208FD8();
    temp_r3 = M2C_FIELD(arg0, void ***, 0x24);
    if (temp_r3 == NULL) {
        goto block_2;
    }
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void *), 0x10)(temp_r3);
block_2:
    M2C_FIELD(arg0, void ***, 0x24) = NULL;
    return;
}

void w3d_auto_802188f8(void *arg0) {
    void **temp_r3;

    fn_80218D10();
    temp_r3 = M2C_FIELD(arg0, void ***, 0x14);
    if (temp_r3 == NULL) {
        goto block_2;
    }
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void *), 0x10)(temp_r3);
block_2:
    M2C_FIELD(arg0, void ***, 0x14) = NULL;
    return;
}

void w3d_auto_80218f98(void *arg0) {
    void **temp_r3;

    fn_80219264();
    temp_r3 = M2C_FIELD(arg0, void ***, 0x14);
    if (temp_r3 == NULL) {
        goto block_2;
    }
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void *), 0x10)(temp_r3);
block_2:
    M2C_FIELD(arg0, void ***, 0x14) = NULL;
    return;
}
