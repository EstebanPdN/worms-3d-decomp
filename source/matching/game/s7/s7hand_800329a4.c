/* Recovered from original instructions; inferred types and names. */
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
M2C_UNK fn_80032BB0(void *, M2C_UNK);               /* extern */
void **fn_8020B680(M2C_UNK *);                      /* extern */
extern M2C_UNK lbl_804138C0[];
extern M2C_UNK lbl_804163F8[];
extern void *lbl_804B1788;

void w3d_auto_800329a4(void *arg0, void *arg1) {
    void **temp_r28;
    void **temp_r28_2;
    void **temp_r29_4;
    void **temp_r30;
    void **temp_r30_2;
    void **temp_r30_3;
    void **temp_r3;
    void **temp_r3_2;
    void **temp_r3_3;
    void **temp_r3_4;
    void **temp_r3_5;
    void **temp_r3_6;
    void *temp_r29;
    void *temp_r29_2;
    void *temp_r29_3;
    void *temp_r30_4;

    temp_r3 = fn_8020B680(&(*lbl_804163F8));
    if (temp_r3 == NULL) {
        goto block_2;
    }
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void **), 0xC)(temp_r3);
block_2:
    temp_r3_2 = M2C_FIELD(arg0, void ***, 0x324);
    if (temp_r3_2 == NULL) {
        goto block_4;
    }
    M2C_FIELD(*temp_r3_2, M2C_UNK (**)(void *), 0x10)(temp_r3_2);
block_4:
    M2C_FIELD(arg0, void ***, 0x324) = temp_r3;
    temp_r30 = M2C_FIELD(arg1, void ***, 0xC);
    if (temp_r30 == NULL) {
        goto block_6;
    }
    M2C_FIELD(*temp_r30, M2C_UNK (**)(void **), 0xC)(temp_r30);
block_6:
    temp_r3_3 = M2C_FIELD(arg0, void ***, 0x320);
    if (temp_r3_3 == NULL) {
        goto block_8;
    }
    M2C_FIELD(*temp_r3_3, M2C_UNK (**)(void *), 0x10)(temp_r3_3);
block_8:
    M2C_FIELD(arg0, void ***, 0x320) = temp_r30;
    temp_r30_2 = M2C_FIELD(arg1, void ***, 8);
    if (temp_r30_2 == NULL) {
        goto block_10;
    }
    M2C_FIELD(*temp_r30_2, M2C_UNK (**)(void **), 0xC)(temp_r30_2);
block_10:
    temp_r3_4 = M2C_FIELD(arg0, void ***, 0x31C);
    if (temp_r3_4 == NULL) {
        goto block_12;
    }
    M2C_FIELD(*temp_r3_4, M2C_UNK (**)(void *), 0x10)(temp_r3_4);
block_12:
    M2C_FIELD(arg0, void ***, 0x31C) = temp_r30_2;
    temp_r3_5 = fn_8020B680(&(*lbl_804138C0));
    if (temp_r3_5 == NULL) {
        goto block_14;
    }
    M2C_FIELD(*temp_r3_5, M2C_UNK (**)(void **), 0xC)(temp_r3_5);
block_14:
    temp_r3_6 = M2C_FIELD(arg0, void ***, 0x318);
    if (temp_r3_6 == NULL) {
        goto block_16;
    }
    M2C_FIELD(*temp_r3_6, M2C_UNK (**)(void *), 0x10)(temp_r3_6);
block_16:
    M2C_FIELD(arg0, void ***, 0x318) = temp_r3_5;
    temp_r29 = *temp_r3_5;
    temp_r30_3 = M2C_FIELD(lbl_804B1788, void ***, 0x30);
    M2C_FIELD(temp_r29, M2C_UNK (**)(void **, s32), 0x28)(temp_r3_5, M2C_FIELD(*temp_r30_3, s32 (**)(void **), 0x24)(temp_r30_3));
    temp_r28 = M2C_FIELD(arg0, void ***, 0x318);
    temp_r29_2 = *temp_r28;
    M2C_FIELD(temp_r29_2, M2C_UNK (**)(void **, s32), 0x2C)(temp_r28, M2C_FIELD(*temp_r30_3, s32 (**)(void **), 0x38)(temp_r30_3));
    temp_r28_2 = M2C_FIELD(arg0, void ***, 0x318);
    temp_r29_3 = *temp_r28_2;
    M2C_FIELD(temp_r29_3, M2C_UNK (**)(void **, s32), 0x30)(temp_r28_2, M2C_FIELD(*temp_r30_3, s32 (**)(void **), 0x3C)(temp_r30_3));
    temp_r29_4 = M2C_FIELD(arg0, void ***, 0x318);
    temp_r30_4 = *temp_r29_4;
    M2C_FIELD(temp_r30_4, M2C_UNK (**)(void **, s32), 0x34)(temp_r29_4, M2C_FIELD(*temp_r30_3, s32 (**)(void **), 0x40)(temp_r30_3));
    fn_80032BB0(arg0, 0x14);
    return;
}
