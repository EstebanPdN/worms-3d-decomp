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
M2C_UNK fn_801E828C(void *, M2C_UNK);               /* extern */
M2C_UNK fn_801F2758(s32, M2C_UNK);                  /* extern */
M2C_UNK fn_801FE1F8(void *);                        /* extern */
M2C_UNK fn_802134FC(void *);                              /* extern */
extern M2C_UNK lbl_80413680[];
extern M2C_UNK lbl_804136C0[];

void w3d_s10_cleanup_8019cc78(void *arg0, s32 arg1) {
    s32 temp_r29;
    void **temp_r3;
    void **temp_r3_2;
    void **temp_r3_3;
    void **temp_r3_4;
    void *temp_r28;
    void *var_r31;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_80413680);
    if ((s32) M2C_FIELD(arg0, s32 *, 0x44) == 0) {
        goto block_2;
    }
    fn_802134FC(M2C_FIELD(arg0, s32 *, 0x44));
block_2:
    temp_r28 = arg0 + 0x34;
    var_r31 = M2C_FIELD(arg0, void **, 0x34);
    temp_r29 = M2C_FIELD(temp_r28, s32 *, 4);
    if (var_r31 == temp_r29) {
        goto block_10;
    }
loop_3:
    fn_801F2758(var_r31 + 0x10, 2);
    temp_r3 = M2C_FIELD(var_r31, void ***, 8);
    if (temp_r3 == NULL) {
        goto block_5;
    }
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void *), 0x10)(temp_r3);
block_5:
    temp_r3_2 = M2C_FIELD(var_r31, void ***, 4);
    if (temp_r3_2 == NULL) {
        goto block_7;
    }
    M2C_FIELD(*temp_r3_2, M2C_UNK (**)(void *), 0x10)(temp_r3_2);
block_7:
    temp_r3_3 = M2C_FIELD(var_r31, void ***, 0);
    if (temp_r3_3 == NULL) {
        goto block_9;
    }
    M2C_FIELD(*temp_r3_3, M2C_UNK (**)(void *), 0x10)(temp_r3_3);
block_9:
    var_r31 += 0x1C;
    if (var_r31 != temp_r29) {
        goto loop_3;
    }
block_10:
    if ((s32) M2C_FIELD(temp_r28, s32 *, 0) == 0) {
        goto block_12;
    }
    fn_802134FC(M2C_FIELD(temp_r28, s32 *, 0));
block_12:
    temp_r3_4 = M2C_FIELD(arg0, void ***, 0x28);
    if (temp_r3_4 == NULL) {
        goto block_14;
    }
    M2C_FIELD(*temp_r3_4, M2C_UNK (**)(void *), 0x10)(temp_r3_4);
block_14:
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_804136C0);
    fn_801E828C(arg0 + 4, 0);
    if (!(arg1 & 1)) {
        goto block_16;
    }
    fn_801FE1F8(arg0);
block_16:
    return;
}
