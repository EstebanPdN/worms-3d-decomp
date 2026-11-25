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

M2C_UNK fn_801265A4(void *, M2C_UNK);                       /* extern */
M2C_UNK fn_800FC43C(M2C_UNK **, M2C_UNK);           /* extern */
M2C_UNK fn_80161014();                              /* extern */
extern M2C_UNK lbl_80380078[];
extern M2C_UNK lbl_8040F390[];
extern s32 lbl_804AABE8;
M2C_UNK fn_800AFE58(s32, M2C_UNK);                       /* extern */
M2C_UNK fn_80209920(M2C_UNK *, void *);             /* extern */
extern M2C_UNK lbl_804B0044;
M2C_UNK fn_802134FC(void *);                              /* extern */
extern M2C_UNK lbl_804ADDE4;

void s8_recovered_80097c5c(void *arg0) {
    void **temp_r3;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x44) == 0) {
        goto block_2;
    }
    fn_801265A4(M2C_FIELD(arg0, s32 *, 0x44), 3);
block_2:
    temp_r3 = M2C_FIELD(arg0, void ***, 0x1C);
    if (temp_r3 == NULL) {
        goto block_4;
    }
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void *), 0x10)(temp_r3);
block_4:
    M2C_FIELD(arg0, void ***, 0x1C) = NULL;
    return;
}

void *s8_recovered_8009b3d4(void *arg0) {
    M2C_UNK *sp8;
    void **temp_r3;
    void **temp_r3_2;
    void *temp_r11;

    fn_80161014();
    M2C_FIELD(arg0, void ***, 0x1C) = NULL;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_8040F390);
    temp_r11 = arg0 + 0x38;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(temp_r11, s32 *, 8) = 0;
    M2C_FIELD(temp_r11, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    temp_r3 = M2C_FIELD(arg0, void ***, 0x1C);
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    M2C_FIELD(arg0, void ***, 0x60) = NULL;
    M2C_FIELD(arg0, s32 *, 0x80) = 0;
    M2C_FIELD(arg0, s32 *, 0x84) = 0;
    M2C_FIELD(arg0, s32 *, 0x88) = 0;
    M2C_FIELD(arg0, s32 *, 0x8C) = 0;
    M2C_FIELD(arg0, s32 *, 0x90) = 0;
    if (temp_r3 == NULL) {
        goto block_2;
    }
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void *), 0x10)(temp_r3);
block_2:
    M2C_FIELD(arg0, void ***, 0x1C) = NULL;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = 1;
    sp8 = &(*lbl_80380078);
    fn_800FC43C(&sp8, 0);
    temp_r3_2 = M2C_FIELD(arg0, void ***, 0x60);
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    if (temp_r3_2 == NULL) {
        goto block_4;
    }
    M2C_FIELD(*temp_r3_2, M2C_UNK (**)(void *), 0x10)(temp_r3_2);
block_4:
    M2C_FIELD(arg0, void ***, 0x60) = NULL;
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
    M2C_FIELD(arg0, s32 *, 0x68) = 0;
    M2C_FIELD(arg0, s32 *, 0x70) = 0;
    M2C_FIELD(arg0, s32 *, 0x74) = 0;
    M2C_FIELD(arg0, s32 *, 0x6C) = 0;
    M2C_FIELD(arg0, s32 *, 0x78) = 0;
    lbl_804AABE8 = 0;
    M2C_FIELD(arg0, s32 *, 0x7C) = 0;
    return arg0;
}

void s8_recovered_800b0100(void *arg0, s32 arg1) {
    void **temp_r3;
    void **temp_r3_2;
    void *var_r31;
    void *var_r3;

    var_r3 = M2C_FIELD(arg0, void **, 8);
    if (var_r3 == NULL) {
        goto block_6;
    }
loop_1:
    var_r31 = M2C_FIELD(var_r3, void **, 0x18);
    if (var_r31 != (void *) M2C_FIELD(arg0, void **, 8)) {
        goto block_3;
    }
    var_r31 = NULL;
block_3:
    if (var_r3 == NULL) {
        goto block_5;
    }
    fn_800AFE58(var_r3, 3);
block_5:
    var_r3 = var_r31;
    if (var_r3 != NULL) {
        goto loop_1;
    }
block_6:
    temp_r3 = M2C_FIELD(arg0, void ***, 0x1C);
    if (temp_r3 == NULL) {
        goto block_8;
    }
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void *), 0x10)(temp_r3);
block_8:
    temp_r3_2 = M2C_FIELD(arg0, void ***, 0x18);
    if (temp_r3_2 == NULL) {
        goto block_10;
    }
    M2C_FIELD(*temp_r3_2, M2C_UNK (**)(void *), 0x10)(temp_r3_2);
block_10:
    if (!(arg1 & 1)) {
        goto block_12;
    }
    fn_80209920(&lbl_804B0044, arg0);
block_12:
    return;
}

void s8_recovered_800b12f0(void *arg0, s32 arg1) {
    void **temp_r3;
    void **temp_r3_2;
    void **temp_r3_3;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x14) == 0) {
        goto block_2;
    }
    fn_802134FC(M2C_FIELD(arg0, s32 *, 0x14));
block_2:
    temp_r3 = M2C_FIELD(arg0, void ***, 0x10);
    if (temp_r3 == NULL) {
        goto block_4;
    }
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void *), 0x10)(temp_r3);
block_4:
    temp_r3_2 = M2C_FIELD(arg0, void ***, 8);
    if (temp_r3_2 == NULL) {
        goto block_6;
    }
    M2C_FIELD(*temp_r3_2, M2C_UNK (**)(void *), 0x10)(temp_r3_2);
block_6:
    temp_r3_3 = M2C_FIELD(arg0, void ***, 4);
    if (temp_r3_3 == NULL) {
        goto block_8;
    }
    M2C_FIELD(*temp_r3_3, M2C_UNK (**)(void *), 0x10)(temp_r3_3);
block_8:
    if (!(arg1 & 1)) {
        goto block_10;
    }
    fn_80209920(&lbl_804ADDE4, arg0);
block_10:
    return;
}
