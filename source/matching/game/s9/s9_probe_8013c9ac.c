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
M2C_UNK fn_801359EC(void *, void **, s32, void *, f32, f32, f32); /* extern */
M2C_UNK fn_80138DAC(void *, M2C_UNK);               /* extern */
M2C_UNK fn_80139234(void *, void **, M2C_UNK);      /* extern */
M2C_UNK fn_8013D440(void *, void **, s32);               /* extern */
void *fn_80165254();                                /* extern */
M2C_UNK fn_801817E0(void **, M2C_UNK);              /* extern */
extern f32 lbl_8039F910[];
extern f32 lbl_8039F914[];
extern f32 lbl_8039F918[];
extern s32 lbl_804AB100;
extern s32 lbl_804AB328;

void s9_probe_8013c9ac(void *arg0) {
    void **temp_r3;
    void **temp_r3_2;
    void **temp_r3_3;

    M2C_FIELD(arg0, s32 *, 0x2B8) = (s32) (M2C_FIELD(fn_80165254(), s32 *, 0x34) + 0x2328);
    if ((s32) M2C_FIELD(arg0, s32 *, 0x2B4) == 0) {
        goto block_9;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x288) == 0) {
        goto block_9;
    }
    fn_801817E0(M2C_FIELD(arg0, void ***, 0x1C), -1);
    fn_801359EC(arg0, M2C_FIELD(arg0, void ***, 0x1C), lbl_804AB100, arg0 + 0x1EC, (*lbl_8039F910), (*lbl_8039F914), (*lbl_8039F918));
    if ((s32) M2C_FIELD(arg0, s32 *, 0x1F0) != 0xA) {
        goto block_6;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x2AC) != 0) {
        goto block_5;
    }
    fn_80138DAC(arg0, 1);
    goto block_6;
block_5:
    M2C_FIELD(arg0, f32 *, 0x244) = (f32) (*lbl_8039F918);
    fn_8013D440(arg0, M2C_FIELD(arg0, void ***, 0x1C),M2C_FIELD(arg0,s32 *,0x2AC));
    fn_80139234(arg0, M2C_FIELD(arg0, void ***, 0x1C), 0);
block_6:
    if ((s32) M2C_FIELD(arg0, s32 *, 0x2AC) != 1) {
        goto block_9;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0xA4) == 0) {
        goto block_9;
    }
    temp_r3 = M2C_FIELD(arg0, void ***, 0x1C);
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void **,s32), 0x60)(temp_r3,M2C_FIELD(arg0,s32 *,0xA4));
    temp_r3_2 = M2C_FIELD(arg0, void ***, 0x1C);
    M2C_FIELD(*temp_r3_2, M2C_UNK (**)(void **, s32, s32), 0x5C)(temp_r3_2, M2C_FIELD(arg0, s32 *, 0xA4), lbl_804AB328);
block_9:
    temp_r3_3 = M2C_FIELD(arg0, void ***, 0x214);
    if (temp_r3_3 == NULL) {
        goto block_11;
    }
    M2C_FIELD(*temp_r3_3, M2C_UNK (**)(void **), 0x18)(temp_r3_3);
block_11:
    M2C_FIELD(arg0, s32 *, 0x2B0) = 0;
    M2C_FIELD(arg0, s32 *, 0x2B4) = 0;
    return;
}
