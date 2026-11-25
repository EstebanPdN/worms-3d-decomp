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

M2C_UNK fn_8015FD1C(void *);                              /* extern */
extern M2C_UNK lbl_804668D0[];
extern M2C_UNK lbl_804668DC[];
extern s32 lbl_804ABB60;

static inline void s11_assign_slot(void ***slot, void **next) {
    void **old=*slot;
    if(old) M2C_FIELD(*old, M2C_UNK (**)(void **),0x10)(old);
    *slot=next;
}

void w3d_auto_802c1398(void *arg0) {
    s32 total;
    f32 *temp_r0;
    f32 *temp_r10;
    f32 *temp_r6;
    f32 *temp_r7;
    f32 *temp_r8;
    f32 *var_r11;
    f32 *var_r9;
    f32 *var_r9_2;
    f32 *var_r9_3;
    f32 *var_r9_4;
    f32 *var_r9_5;
    void **temp_r3;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x30) == 0) {
        goto block_2;
    }
    fn_8015FD1C(M2C_FIELD(arg0, s32 *, 0x30));
    total=lbl_804ABB60;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    lbl_804ABB60=total-2;
block_2:
    s11_assign_slot((void ***)((char *)arg0+0x24),NULL);
    if ((s32) M2C_FIELD(arg0, s32 *, 0x6C) == 0) {
        goto block_18;
    }
    temp_r10 = arg0 + 0x54;
    temp_r6 = arg0 + 0x60;
    M2C_FIELD(arg0, s32 *, 0x6C) = 0;
    var_r9 = temp_r10;
    if (!(M2C_FIELD(arg0, f32 *, 0x60) < M2C_FIELD(arg0, f32 *, 0x54))) {
        goto block_7;
    }
    var_r9 = temp_r6;
block_7:
    var_r11 = arg0 + 0x58;
    temp_r7 = arg0 + 0x64;
    M2C_FIELD(&(*lbl_804668D0), f32 *, 0) = (f32) *var_r9;
    var_r9_2 = var_r11;
    if (!(M2C_FIELD(arg0, f32 *, 0x64) < M2C_FIELD(arg0, f32 *, 0x58))) {
        goto block_9;
    }
    var_r9_2 = temp_r7;
block_9:
    temp_r0 = arg0 + 0x5C;
    temp_r8 = arg0 + 0x68;
    var_r9_3 = temp_r0;
    M2C_FIELD(&(*lbl_804668D0), f32 *, 4) = (f32) *var_r9_2;
    if (!(M2C_FIELD(arg0, f32 *, 0x68) < M2C_FIELD(arg0, f32 *, 0x5C))) {
        goto block_11;
    }
    var_r9_3 = temp_r8;
block_11:
    var_r9_4 = temp_r10;
    M2C_FIELD(&(*lbl_804668D0), f32 *, 8) = (f32) *var_r9_3;
    if (!(M2C_FIELD(arg0, f32 *, 0x54) < M2C_FIELD(arg0, f32 *, 0x60))) {
        goto block_13;
    }
    var_r9_4 = temp_r6;
block_13:
    M2C_FIELD(&(*lbl_804668DC), f32 *, 0) = (f32) *var_r9_4;
    if (!(M2C_FIELD(arg0, f32 *, 0x58) < M2C_FIELD(arg0, f32 *, 0x64))) {
        goto block_15;
    }
    var_r11 = temp_r7;
block_15:
    var_r9_5 = temp_r0;
    M2C_FIELD(&(*lbl_804668DC), f32 *, 4) = (f32) *var_r11;
    if (!(M2C_FIELD(arg0, f32 *, 0x5C) < M2C_FIELD(arg0, f32 *, 0x68))) {
        goto block_17;
    }
    var_r9_5 = temp_r8;
block_17:
    M2C_FIELD(&(*lbl_804668DC), f32 *, 8) = (f32) *var_r9_5;
block_18:
    return;
}
