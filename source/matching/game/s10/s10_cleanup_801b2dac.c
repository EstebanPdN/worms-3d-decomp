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
M2C_UNK fn_801FE1F8(void *);                        void fn_8020C5C4(s32);                           /* extern */
M2C_UNK fn_80210990(void *, M2C_UNK);               /* extern */
M2C_UNK fn_80210ABC(void *, M2C_UNK);               /* extern */
M2C_UNK fn_802134FC(void *);                              /* extern */
M2C_UNK fn_80341588(void *);                           /* extern */
extern M2C_UNK lbl_804143F0[];
extern M2C_UNK lbl_80414430[];

void w3d_s10_cleanup_801b2dac(void *arg0, s32 arg1) {
    s32 temp_r30;
    s32 temp_r30_2;
    s32 temp_r30_3;
    s32 temp_r30_4;
    s32 var_r31_3;
    s32 var_r31_4;
    void ***var_r31;
    void ***var_r31_2;
    void **temp_r3;
    void **temp_r3_2;
    void **temp_r3_3;
    void **temp_r3_4;
    void *temp_r26;
    void *temp_r27;
    void *temp_r28;

    temp_r30 = M2C_FIELD(arg0, s32 *, 0x30);
    var_r31 = M2C_FIELD(arg0, void ****, 0x2C);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_804143F0);
    if (var_r31 != temp_r30) {
        do {
            temp_r3 = *var_r31;
            var_r31 = (void *)((char *)((void *)((char *)var_r31 + 4)));
            M2C_FIELD(*temp_r3, M2C_UNK (**)(void **), 0x10)(temp_r3);
        } while (var_r31 != temp_r30);
    }
    var_r31_2 = M2C_FIELD(arg0, void ****, 0x58);
    temp_r28 = arg0 + 0x48;
    temp_r30_2 = M2C_FIELD(arg0, s32 *, 0x5C);
    temp_r27 = arg0 + 0x3C;
    temp_r26 = arg0 + 0x1C;
    if (var_r31_2 != temp_r30_2) {
        do {
            temp_r3_2 = *var_r31_2;
            var_r31_2 = (void *)((char *)((void *)((char *)var_r31_2 + 4)));
            M2C_FIELD(*temp_r3_2, M2C_UNK (**)(void **), 0x10)(temp_r3_2);
        } while (var_r31_2 != temp_r30_2);
    }
    if ((void ***) M2C_FIELD(arg0, void ****, 0x58) != NULL) {
        fn_802134FC((void *)M2C_FIELD(arg0, void ****, 0x58));
    }
    temp_r30_3 = M2C_FIELD(temp_r28, s32 *, 4);
    var_r31_3 = M2C_FIELD(arg0, s32 *, 0x48);
    if (var_r31_3 != temp_r30_3) {
        do {
            fn_8020C5C4(var_r31_3);
            fn_80341588(var_r31_3);
            var_r31_3 += 4;
        } while (var_r31_3 != temp_r30_3);
    }
    if ((s32) M2C_FIELD(temp_r28, s32 *, 0) != 0) {
        fn_802134FC((void *)M2C_FIELD(temp_r28, s32 *, 0));
    }
    fn_80210ABC(temp_r27, 2);
    if ((void ***) M2C_FIELD(arg0, void ****, 0x2C) != NULL) {
        fn_802134FC((void *)M2C_FIELD(arg0, void ****, 0x2C));
    }
    temp_r30_4 = M2C_FIELD(temp_r26, s32 *, 4);
    var_r31_4 = M2C_FIELD(arg0, s32 *, 0x1C);
    if (var_r31_4 != temp_r30_4) {
        do {
            fn_8020C5C4(var_r31_4);
            fn_80341588(var_r31_4);
            var_r31_4 += 4;
        } while (var_r31_4 != temp_r30_4);
    }
    if ((s32) M2C_FIELD(temp_r26, s32 *, 0) != 0) {
        fn_802134FC((void *)M2C_FIELD(temp_r26, s32 *, 0));
    }
    temp_r3_3 = M2C_FIELD(arg0, void ***, 0x18);
    if (temp_r3_3 != NULL) {
        M2C_FIELD(*temp_r3_3, M2C_UNK (**)(void *), 0x10)(temp_r3_3);
    }
    temp_r3_4 = M2C_FIELD(arg0, void ***, 0x14);
    if (temp_r3_4 != NULL) {
        M2C_FIELD(*temp_r3_4, M2C_UNK (**)(void *), 0x10)(temp_r3_4);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_80414430);
    fn_80210990(arg0 + 4, 0);
    if (arg1 & 1) {
        fn_801FE1F8(arg0);
    }
}
