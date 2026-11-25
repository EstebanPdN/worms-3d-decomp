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
M2C_UNK fn_801359EC(void *, void **, M2C_UNK *, void *, f32, f32, f32); /* extern */
M2C_UNK fn_8015ADF4(M2C_UNK *, void ***, M2C_UNK);  /* extern */
M2C_UNK fn_80182410(void **, s32);                  /* extern */
M2C_UNK fn_8020BB54(M2C_UNK *, M2C_UNK *);          /* extern */
M2C_UNK fn_8020C5C4(M2C_UNK *);                     /* extern */
s32 fn_802EF234(s32, M2C_UNK *);                    /* extern */
M2C_UNK fn_80341588(M2C_UNK *);                     /* extern */
void **fn_80343584(void **);                        /* extern */
extern M2C_UNK lbl_8039F5A0[];
extern M2C_UNK lbl_8039FD94[];
extern M2C_UNK lbl_8039FDA4[];
extern f32 lbl_8039FDB4[];
extern f32 lbl_8039FDB8[];
extern f32 lbl_8039FDBC[];
extern M2C_UNK *lbl_804AB100;
extern s32 lbl_804AB328;

void w3d_auto_8013f348(void *arg0, void **arg1) {
    M2C_UNK sp8[2];
    void **sp10;
    void **temp_r30;
    void **temp_r3;
    void **temp_r3_2;
    void **temp_r3_3;

    temp_r30 = M2C_FIELD(arg0, void ***, 0xA4);
    if (temp_r30 != NULL) {
        goto block_10;
    }
    fn_8020BB54(&sp8, &(*lbl_8039FD94));
    sp10 = temp_r30;
    fn_8015ADF4(&sp8, &sp10, 0xFF);
    temp_r3 = fn_80343584(sp10);
    if (temp_r3 == NULL) {
        goto block_3;
    }
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void **), 0xC)(temp_r3);
block_3:
    temp_r3_2 = M2C_FIELD(arg0, void ***, 0xA4);
    if (temp_r3_2 == NULL) {
        goto block_5;
    }
    M2C_FIELD(*temp_r3_2, M2C_UNK (**)(void *), 0x10)(temp_r3_2);
block_5:
    M2C_FIELD(arg0, void ***, 0xA4) = temp_r3;
    if (sp10 == NULL) {
        goto block_7;
    }
    M2C_FIELD(*sp10, M2C_UNK (**)(void *), 0x10)(sp10);
block_7:
    fn_8020C5C4(&sp8);
    fn_80341588(&sp8);
    M2C_FIELD(*arg1, M2C_UNK (**)(void **, void **, s32), 0x5C)(arg1, M2C_FIELD(arg0, void ***, 0xA4), lbl_804AB328);
    temp_r3_3 = M2C_FIELD(arg0, void ***, 0xA4);
    if (fn_802EF234(*M2C_FIELD(*M2C_FIELD(*temp_r3_3, void **(**)(void **), 0x40)(temp_r3_3), s32 *(**)(), 0x44)(), &(*lbl_8039F5A0)) != 0) {
        goto block_9;
    }
    fn_80182410(M2C_FIELD(arg0, void ***, 0xA4), M2C_FIELD(arg0, s32 *, 0x254));
    goto block_10;
block_9:
    fn_80182410(M2C_FIELD(arg0, void ***, 0xA4), M2C_FIELD(arg0, s32 *, 0x258));
block_10:
    fn_801359EC(arg0, arg1, lbl_804AB100, arg0 + 0x1EC, (*lbl_8039FDB4), (*lbl_8039FDB8), (*lbl_8039FDB8));
    fn_801359EC(arg0, arg1, &(*lbl_8039FDA4), arg0 + 0x1D8, (*lbl_8039FDB4), (*lbl_8039FDBC), (*lbl_8039FDB8));
    return;
}
