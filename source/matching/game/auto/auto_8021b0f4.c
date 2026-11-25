/* Decompiled automatically by m2c (ppc-gcc-c) via tools/m2c_batch.py and verified identical
 * to the original after linking. Types and names are m2c placeholders pending review. */
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


s32 fn_8006E71C();                                  /* extern */
void *fn_80165254();                                /* extern */
M2C_UNK fn_8021B194(void *);                        /* extern */
M2C_UNK fn_8021B8C0(void *);                        /* extern */
M2C_UNK fn_8021BD4C(void *);                        /* extern */
M2C_UNK fn_8021BF14(void *);                        /* extern */
M2C_UNK fn_8021BF3C(void *);                        /* extern */
M2C_UNK fn_8021C144(void *);                        /* extern */
M2C_UNK fn_8021C48C(void *);                        /* extern */
M2C_UNK fn_8021C684(void *);                        /* extern */
s32 fn_8015CCBC(void *);                               /* extern */
M2C_UNK fn_801EF380(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK fn_8021E248(void *);                        /* extern */
M2C_UNK fn_80129878(void *);                           /* extern */
M2C_UNK fn_80162C18(s32);                           /* extern */
M2C_UNK fn_801EF174(s32, M2C_UNK, M2C_UNK, void *);    /* extern */
M2C_UNK fn_801E8D9C();                              /* extern */

s32 w3d_auto_8021b0f4(void *arg0) {
    u32 temp_r0;
    u32 temp_r9;

    temp_r0 = M2C_FIELD(arg0, u32 *, 0x60) + M2C_FIELD(fn_80165254(), s32 *, 0x34);
    temp_r9 = M2C_FIELD(arg0, u32 *, 0x64) + 1;
    M2C_FIELD(arg0, u32 *, 0x60) = temp_r0;
    M2C_FIELD(arg0, u32 *, 0x64) = temp_r9;
    M2C_FIELD(arg0, u32 *, 0x68) = (u32) (temp_r0 / temp_r9);
    fn_8021BD4C(arg0);
    fn_8021BF14(arg0);
    fn_8021B194(arg0);
    fn_8021B8C0(arg0);
    fn_8021BF3C(arg0);
    fn_8021C144(arg0);
    if (fn_8006E71C() == 0) {
        fn_8021C684(arg0);
    }
    fn_8021C48C(arg0);
    return M2C_FIELD(arg0, s32 *, 0x74);
}

extern s32 lbl_804B1788;

void w3d_auto_8021c684(void *arg0) {
    s32 temp_r30;
    void *temp_r29;
    void *temp_r31;

    if (((s32) M2C_FIELD(arg0, s32 *, 0x5C) != 0) && (fn_8015CCBC(lbl_804B1788) == 0) && (temp_r29 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), void **, 0x18), temp_r31 = M2C_FIELD(temp_r29, void **, 0x2C), (((s32) M2C_FIELD(temp_r31, s32 *, 0x18) == 0) == 0))) {
        temp_r30 = M2C_FIELD(M2C_FIELD(temp_r31, void **, 0x20), s32 *, 0x18);
        if (temp_r30 == (s32) M2C_FIELD(fn_80165254(), s32 *, 0x34)) {
            fn_8021E248(M2C_FIELD(temp_r31, void **, 0x20));
            fn_801EF380(temp_r29, 0x2C, 5, 0, 1);
            return;
        }
        if ((u32) M2C_FIELD(fn_80165254(), u32 *, 0x34) > (u32) M2C_FIELD(M2C_FIELD(temp_r31, void **, 0x20), s32 *, 0x18)) {
            fn_801EF380(temp_r29, 0x2C, 5, 0, 1);
        }
    }
}

extern s32 lbl_804B1788;

void w3d_auto_8021de98(void) {
    fn_80129878(lbl_804B1788);
}

void w3d_auto_8021dec8(void *arg0) {
    fn_80162C18(M2C_FIELD(arg0, s32 *, 0x1C));
}

void w3d_auto_8021e024(s32 arg0, s32 arg1) {
    fn_801EF174(arg1, 0x2C, 5, arg0);
}

extern void *lbl_804ABAC0;

void w3d_auto_8021e88c(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0x14) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
    if ((s32) M2C_FIELD(arg0, s32 *, 0x18) == -2) {
        M2C_FIELD(lbl_804ABAC0, s32 *, 0x9C) = 1;
    }
}

s32 w3d_auto_8021edc4(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), s32 *, 0x18);
}

s32 w3d_auto_80226d44(void) {
    fn_801E8D9C();
    return 0;
}

void w3d_auto_8022fbbc(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x78) = (s32) *arg1;
}

void w3d_auto_802306b0(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x74) = (s32) *arg1;
}

s32 w3d_auto_80239664(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_80239c84(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_8023a074(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_8023c820(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_8023d600(void) {
    fn_801E8D9C();
    return 0;
}

s32 w3d_auto_8023da74(void) {
    fn_801E8D9C();
    return 0;
}

s8 w3d_auto_8024970c(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0xEE);
}

s8 w3d_auto_80249720(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0xED);
}

s8 w3d_auto_80249734(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x110);
}

s8 w3d_auto_80249748(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0xEB);
}

s8 w3d_auto_8024975c(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0xEA);
}

s8 w3d_auto_80249770(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0xE9);
}

s8 w3d_auto_80249784(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0xE8);
}

s8 w3d_auto_80249798(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0xE7);
}

s8 w3d_auto_802497ac(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0xE6);
}

s8 w3d_auto_802497c0(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x116);
}

s8 w3d_auto_802497d4(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0xE4);
}

s8 w3d_auto_802497e8(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0xE3);
}

s8 w3d_auto_802497fc(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0xE2);
}

s8 w3d_auto_80249810(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0xE1);
}

s8 w3d_auto_80249824(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x10F);
}

s8 w3d_auto_80249838(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x11A);
}

s8 w3d_auto_8024984c(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x119);
}

s8 w3d_auto_80249860(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x118);
}

s8 w3d_auto_80249874(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x117);
}

s8 w3d_auto_80249888(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0xE5);
}

s8 w3d_auto_8024989c(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x115);
}

s8 w3d_auto_802498b0(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x114);
}

s8 w3d_auto_802498c4(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x113);
}

s8 w3d_auto_802498d8(void *arg0) {
    return (s8) M2C_FIELD(arg0, u8 *, 0x112);
}
