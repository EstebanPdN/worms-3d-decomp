/* Combined implicit-argument/byte-offset and statement-order corrections; exact matches only. */
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

M2C_UNK fn_801E199C(void *);                        /* extern */
s32 fn_801E4C14();                                  /* extern */
M2C_UNK fn_801E6F04(void *, M2C_UNK);               /* extern */
M2C_UNK fn_801FE1D8(M2C_UNK);                       /* extern */
void **fn_8020FCB4(M2C_UNK *);                      /* extern */
extern M2C_UNK lbl_8036561C[];
extern void *lbl_804AB864;
M2C_UNK fn_80209890(void *);                              /* extern */
M2C_UNK fn_80209968(void *);                              /* extern */
s32 *fn_80209A70();                                 /* extern */
M2C_UNK fn_801FE1F8(void *);                        /* extern */
M2C_UNK fn_80210990(void *, M2C_UNK);               /* extern */
M2C_UNK fn_802134FC(void *);                              /* extern */
extern M2C_UNK lbl_80419388[];
extern M2C_UNK lbl_804193D8[];

s32 w3d_auto_801dfdac(void *arg0) {
    s32 *var_r31;
    void **temp_r3;
    void **temp_r3_2;
    void *temp_r28;

    if ((void **) M2C_FIELD(arg0, void ***, 0x14) == NULL) {
        goto block_2;
    }
    return 0x80004005;
block_2:
    temp_r3 = fn_8020FCB4(&(*lbl_8036561C));
    if (temp_r3 == NULL) {
        goto block_4;
    }
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void **), 0xC)(temp_r3);
block_4:
    temp_r3_2 = M2C_FIELD(arg0, void ***, 0x14);
    if (temp_r3_2 == NULL) {
        goto block_6;
    }
    M2C_FIELD(*temp_r3_2, M2C_UNK (**)(void *), 0x10)(temp_r3_2);
block_6:
    M2C_FIELD(arg0, void ***, 0x14) = temp_r3;
    temp_r28 = arg0 + 0xB0;
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void **), 0x48)(temp_r3);
    var_r31 = arg0 + 0x30;
loop_7:
    fn_801FE1D8(0x20);
    *var_r31 = fn_801E4C14();
    var_r31 = (void *)((char *)((void *)((char *)var_r31 + 4)));
    if (var_r31 <= (void *) (arg0 + 0xAC)) {
        goto loop_7;
    }
    lbl_804AB864 = temp_r28;
    fn_801E6F04(temp_r28, 0x64);
    fn_801E199C(arg0);
    return 0;
}

s32 w3d_auto_80209b2c(s32 *arg0) {
    s32 *var_r31;
    s32 temp_r3;
    u32 temp_r30;

    var_r31 = arg0;
    temp_r30 = ((void *)((char *)var_r31 + 0x3FC));
loop_1:
    temp_r3 = *var_r31;
    var_r31 = (void *)((char *)((void *)((char *)var_r31 + 4)));
    if (temp_r3 == 0) {
        goto block_3;
    }
    fn_80209890(temp_r3);
block_3:
    if (var_r31 <= temp_r30) {
        goto loop_1;
    }
    return 0;
}

s32 w3d_auto_80209b78(void) {
    s32 *temp_r30;
    s32 *var_r31;
    s32 temp_r3;

    var_r31 = fn_80209A70();
    temp_r30 = ((void *)((char *)var_r31 + 0x3FC));
loop_1:
    temp_r3 = *var_r31;
    var_r31 = (void *)((char *)((void *)((char *)var_r31 + 4)));
    if (temp_r3 == 0) {
        goto block_3;
    }
    fn_80209968(temp_r3);
block_3:
    if (var_r31 <= temp_r30) {
        goto loop_1;
    }
    return 0;
}

void w3d_auto_8020a09c(void *arg0, s32 arg1) {
    s32 temp_r29;
    void ***var_r31;
    void **temp_r3;
    void **temp_r3_2;

    temp_r29 = M2C_FIELD(arg0, s32 *, 0x18);
    var_r31 = M2C_FIELD(arg0, void ****, 0x14);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_80419388);
    if (var_r31 == temp_r29) {
        goto block_2;
    }
loop_1:
    temp_r3 = *var_r31;
    var_r31 = (void *)((char *)((void *)((char *)var_r31 + 4)));
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void **), 0x10)(temp_r3);
    if (var_r31 != temp_r29) {
        goto loop_1;
    }
block_2:
    temp_r3_2 = M2C_FIELD(arg0, void ***, 0x20);
    if (temp_r3_2 == NULL) {
        goto block_4;
    }
    M2C_FIELD(*temp_r3_2, M2C_UNK (**)(void *), 0x10)(temp_r3_2);
block_4:
    if ((void ***) M2C_FIELD(arg0, void ****, 0x14) == NULL) {
        goto block_6;
    }
    fn_802134FC((void ***) M2C_FIELD(arg0, void ****, 0x14));
block_6:
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_804193D8);
    fn_80210990(arg0 + 4, 0);
    if (!(arg1 & 1)) {
        goto block_8;
    }
    fn_801FE1F8(arg0);
block_8:
    return;
}
