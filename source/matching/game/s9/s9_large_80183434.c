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
M2C_UNK fn_801902E8(void *);                              /* extern */
void **fn_8020B680(M2C_UNK *);                      /* extern */
extern f32 lbl_803A7998[];
extern M2C_UNK lbl_80412BC8[];
extern M2C_UNK lbl_80414210[];
extern M2C_UNK lbl_80415BB0[];
extern M2C_UNK lbl_80415C00[];
extern M2C_UNK lbl_80415C10[];
extern M2C_UNK lbl_80415C30[];
extern M2C_UNK lbl_80415C80[];
extern M2C_UNK lbl_80415CB0[];
extern M2C_UNK lbl_804166B0[];
extern M2C_UNK lbl_80416750[];
extern s32 lbl_804AB660;
extern void **lbl_804B01D4;
extern void **lbl_804B01D8;
extern void **lbl_804B01DC;
extern void **lbl_804B01E0;
extern void **lbl_804B01E4;
extern void **lbl_804B01E8;
extern void **lbl_804B01EC;
extern void **lbl_804B01F0;
extern void **lbl_804B01F4;
extern void **lbl_804B01F8;
extern void **lbl_804B01FC;
extern void **lbl_804B0200;

void *w3d_auto_80183434(void *arg0) {
    void **temp_r10;
    void **temp_r10_2;
    void **temp_r10_3;
    void **temp_r11;
    void **temp_r11_10;
    void **temp_r11_2;
    void **temp_r11_3;
    void **temp_r11_4;
    void **temp_r11_5;
    void **temp_r11_6;
    void **temp_r11_7;
    void **temp_r11_8;
    void **temp_r11_9;
    void **temp_r3;
    void **temp_r3_10;
    void **temp_r3_11;
    void **temp_r3_12;
    void **temp_r3_2;
    void **temp_r3_3;
    void **temp_r3_4;
    void **temp_r3_5;
    void **temp_r3_6;
    void **temp_r3_7;
    void **temp_r3_8;
    void **temp_r3_9;
    void **temp_r9;
    void **temp_r9_10;
    void **temp_r9_11;
    void **temp_r9_2;
    void **temp_r9_3;
    void **temp_r9_4;
    void **temp_r9_5;
    void **temp_r9_6;
    void **temp_r9_7;
    void **temp_r9_8;
    void **temp_r9_9;

    fn_801902E8(arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_80412BC8);
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    if ((s32) lbl_804AB660 == 0) {
        temp_r3 = fn_8020B680(&(*lbl_80415C10));
        if (temp_r3 != NULL) {
            M2C_FIELD(*temp_r3, M2C_UNK (**)(void **), 0xC)(temp_r3);
        }
        if ((void **) lbl_804B01D4 != NULL) {
            M2C_FIELD(M2C_FIELD(lbl_804B01D4, void **, 0), M2C_UNK (**)(void *), 0x10)(lbl_804B01D4);
        }
        lbl_804B01D4 = temp_r3;
        temp_r3_2 = fn_8020B680(&(*lbl_80415C10));
        if (temp_r3_2 != NULL) {
            M2C_FIELD(*temp_r3_2, M2C_UNK (**)(void **), 0xC)(temp_r3_2);
        }
        if ((void **) lbl_804B01D8 != NULL) {
            M2C_FIELD(M2C_FIELD(lbl_804B01D8, void **, 0), M2C_UNK (**)(void *), 0x10)(lbl_804B01D8);
        }
        lbl_804B01D8 = temp_r3_2;
        temp_r3_3 = fn_8020B680(&(*lbl_80415C80));
        if (temp_r3_3 != NULL) {
            M2C_FIELD(*temp_r3_3, M2C_UNK (**)(void **), 0xC)(temp_r3_3);
        }
        if ((void **) lbl_804B01DC != NULL) {
            M2C_FIELD(M2C_FIELD(lbl_804B01DC, void **, 0), M2C_UNK (**)(void *), 0x10)(lbl_804B01DC);
        }
        lbl_804B01DC = temp_r3_3;
        temp_r3_4 = fn_8020B680(&(*lbl_80415BB0));
        if (temp_r3_4 != NULL) {
            M2C_FIELD(*temp_r3_4, M2C_UNK (**)(void **), 0xC)(temp_r3_4);
        }
        if ((void **) lbl_804B01E0 != NULL) {
            M2C_FIELD(M2C_FIELD(lbl_804B01E0, void **, 0), M2C_UNK (**)(void *), 0x10)(lbl_804B01E0);
        }
        lbl_804B01E0 = temp_r3_4;
        temp_r3_5 = fn_8020B680(&(*lbl_80415CB0));
        if (temp_r3_5 != NULL) {
            M2C_FIELD(*temp_r3_5, M2C_UNK (**)(void **), 0xC)(temp_r3_5);
        }
        if ((void **) lbl_804B01E4 != NULL) {
            M2C_FIELD(M2C_FIELD(lbl_804B01E4, void **, 0), M2C_UNK (**)(void *), 0x10)(lbl_804B01E4);
        }
        lbl_804B01E4 = temp_r3_5;
        temp_r3_6 = fn_8020B680(&(*lbl_80415CB0));
        if (temp_r3_6 != NULL) {
            M2C_FIELD(*temp_r3_6, M2C_UNK (**)(void **), 0xC)(temp_r3_6);
        }
        if ((void **) lbl_804B01E8 != NULL) {
            M2C_FIELD(M2C_FIELD(lbl_804B01E8, void **, 0), M2C_UNK (**)(void *), 0x10)(lbl_804B01E8);
        }
        lbl_804B01E8 = temp_r3_6;
        temp_r3_7 = fn_8020B680(&(*lbl_80415C30));
        if (temp_r3_7 != NULL) {
            M2C_FIELD(*temp_r3_7, M2C_UNK (**)(void **), 0xC)(temp_r3_7);
        }
        if ((void **) lbl_804B01EC != NULL) {
            M2C_FIELD(M2C_FIELD(lbl_804B01EC, void **, 0), M2C_UNK (**)(void *), 0x10)(lbl_804B01EC);
        }
        lbl_804B01EC = temp_r3_7;
        temp_r3_8 = fn_8020B680(&(*lbl_80415C00));
        if (temp_r3_8 != NULL) {
            M2C_FIELD(*temp_r3_8, M2C_UNK (**)(void **), 0xC)(temp_r3_8);
        }
        if ((void **) lbl_804B01F0 != NULL) {
            M2C_FIELD(M2C_FIELD(lbl_804B01F0, void **, 0), M2C_UNK (**)(void *), 0x10)(lbl_804B01F0);
        }
        lbl_804B01F0 = temp_r3_8;
        temp_r3_9 = fn_8020B680(&(*lbl_80415C00));
        if (temp_r3_9 != NULL) {
            M2C_FIELD(*temp_r3_9, M2C_UNK (**)(void **), 0xC)(temp_r3_9);
        }
        if ((void **) lbl_804B01F4 != NULL) {
            M2C_FIELD(M2C_FIELD(lbl_804B01F4, void **, 0), M2C_UNK (**)(void *), 0x10)(lbl_804B01F4);
        }
        lbl_804B01F4 = temp_r3_9;
        temp_r3_10 = fn_8020B680(&(*lbl_804166B0));
        if (temp_r3_10 != NULL) {
            M2C_FIELD(*temp_r3_10, M2C_UNK (**)(void **), 0xC)(temp_r3_10);
        }
        if ((void **) lbl_804B01F8 != NULL) {
            M2C_FIELD(*lbl_804B01F8, M2C_UNK (**)(void *), 0x10)(lbl_804B01F8);
        }
        lbl_804B01F8 = temp_r3_10;
        temp_r3_11 = fn_8020B680(&(*lbl_80414210));
        if (temp_r3_11 != NULL) {
            M2C_FIELD(*temp_r3_11, M2C_UNK (**)(void **), 0xC)(temp_r3_11);
        }
        if ((void **) lbl_804B01FC != NULL) {
            M2C_FIELD(*lbl_804B01FC, M2C_UNK (**)(void *), 0x10)(lbl_804B01FC);
        }
        lbl_804B01FC = temp_r3_11;
        temp_r3_12 = fn_8020B680(&(*lbl_80416750));
        if (temp_r3_12 != NULL) {
            M2C_FIELD(*temp_r3_12, M2C_UNK (**)(void **), 0xC)(temp_r3_12);
        }
        if ((void **) lbl_804B0200 != NULL) {
            M2C_FIELD(*lbl_804B0200, M2C_UNK (**)(void *), 0x10)(lbl_804B0200);
        }
        lbl_804B0200 = temp_r3_12;
        M2C_FIELD(lbl_804B01D4, s32 *, 0x20) = 3;
        temp_r9 = (void **)((char *)lbl_804B01D4 + 4);
        M2C_FIELD(temp_r9, u8 *, 7) = (u8) (M2C_FIELD(temp_r9, u8 *, 7) | 2);
        M2C_FIELD(lbl_804B01D4, s32 *, 0x24) = 1;
        temp_r11 = (void **)((char *)lbl_804B01D4 + 4);
        M2C_FIELD(temp_r11, u8 *, 7) = (u8) (M2C_FIELD(temp_r11, u8 *, 7) | 2);
        temp_r9_2 = (void **)((char *)lbl_804B01D4 + 4);
        M2C_FIELD(temp_r9_2, u8 *, 7) = (u8) (M2C_FIELD(temp_r9_2, u8 *, 7) | 1);
        M2C_FIELD(lbl_804B01D8, s32 *, 0x20) = 7;
        temp_r11_2 = (void **)((char *)lbl_804B01D8 + 4);
        M2C_FIELD(temp_r11_2, u8 *, 7) = (u8) (M2C_FIELD(temp_r11_2, u8 *, 7) | 2);
        M2C_FIELD(lbl_804B01D8, s32 *, 0x24) = 1;
        temp_r10 = (void **)((char *)lbl_804B01D8 + 4);
        M2C_FIELD(temp_r10, u8 *, 7) = (u8) (M2C_FIELD(temp_r10, u8 *, 7) | 2);
        temp_r9_3 = (void **)((char *)lbl_804B01D8 + 4);
        M2C_FIELD(temp_r9_3, u8 *, 7) = (u8) (M2C_FIELD(temp_r9_3, u8 *, 7) | 1);
        M2C_FIELD(lbl_804B01DC, s32 *, 0x34) = 0;
        temp_r11_3 = (void **)((char *)lbl_804B01DC + 4);
        M2C_FIELD(temp_r11_3, u8 *, 7) = (u8) (M2C_FIELD(temp_r11_3, u8 *, 7) | 2);
        temp_r9_4 = (void **)((char *)lbl_804B01DC + 4);
        M2C_FIELD(temp_r9_4, u8 *, 7) = (u8) (M2C_FIELD(temp_r9_4, u8 *, 7) | 1);
        M2C_FIELD(lbl_804B01E0, s32 *, 0x1C) = 4;
        temp_r11_4 = (void **)((char *)lbl_804B01E0 + 4);
        M2C_FIELD(temp_r11_4, u8 *, 7) = (u8) (M2C_FIELD(temp_r11_4, u8 *, 7) | 2);
        M2C_FIELD(lbl_804B01E0, s32 *, 0x20) = 1;
        temp_r10_2 = (void **)((char *)lbl_804B01E0 + 4);
        M2C_FIELD(temp_r10_2, u8 *, 7) = (u8) (M2C_FIELD(temp_r10_2, u8 *, 7) | 2);
        temp_r9_5 = (void **)((char *)lbl_804B01E0 + 4);
        M2C_FIELD(temp_r9_5, u8 *, 7) = (u8) (M2C_FIELD(temp_r9_5, u8 *, 7) | 1);
        M2C_FIELD(lbl_804B01E0, f32 *, 0x18) = (f32) (*lbl_803A7998);
        temp_r11_5 = (void **)((char *)lbl_804B01E0 + 4);
        M2C_FIELD(temp_r11_5, u8 *, 7) = (u8) (M2C_FIELD(temp_r11_5, u8 *, 7) | 2);
        M2C_FIELD(lbl_804B01E4, s32 *, 0x1C) = 6;
        temp_r9_6 = (void **)((char *)lbl_804B01E4 + 4);
        M2C_FIELD(temp_r9_6, u8 *, 7) = (u8) (M2C_FIELD(temp_r9_6, u8 *, 7) | 2);
        M2C_FIELD(lbl_804B01E4, s32 *, 0x18) = 7;
        temp_r11_6 = (void **)((char *)lbl_804B01E4 + 4);
        M2C_FIELD(temp_r11_6, u8 *, 7) = (u8) (M2C_FIELD(temp_r11_6, u8 *, 7) | 2);
        temp_r9_7 = (void **)((char *)lbl_804B01E4 + 4);
        M2C_FIELD(temp_r9_7, u8 *, 7) = (u8) (M2C_FIELD(temp_r9_7, u8 *, 7) | 1);
        M2C_FIELD(lbl_804B01E8, s32 *, 0x1C) = 6;
        temp_r11_7 = (void **)((char *)lbl_804B01E8 + 4);
        M2C_FIELD(temp_r11_7, u8 *, 7) = (u8) (M2C_FIELD(temp_r11_7, u8 *, 7) | 2);
        M2C_FIELD(lbl_804B01E8, s32 *, 0x18) = 1;
        temp_r10_3 = (void **)((char *)lbl_804B01E8 + 4);
        M2C_FIELD(temp_r10_3, u8 *, 7) = (u8) (M2C_FIELD(temp_r10_3, u8 *, 7) | 2);
        temp_r9_8 = (void **)((char *)lbl_804B01E8 + 4);
        M2C_FIELD(temp_r9_8, u8 *, 7) = (u8) (M2C_FIELD(temp_r9_8, u8 *, 7) | 1);
        M2C_FIELD(lbl_804B01EC, s32 *, 0x18) = 0;
        temp_r11_8 = (void **)((char *)lbl_804B01EC + 4);
        M2C_FIELD(temp_r11_8, u8 *, 7) = (u8) (M2C_FIELD(temp_r11_8, u8 *, 7) | 2);
        temp_r9_9 = (void **)((char *)lbl_804B01EC + 4);
        M2C_FIELD(temp_r9_9, u8 *, 7) = (u8) (M2C_FIELD(temp_r9_9, u8 *, 7) | 1);
        M2C_FIELD(lbl_804B01F0, s32 *, 0x18) = 0;
        temp_r11_9 = (void **)((char *)lbl_804B01F0 + 4);
        M2C_FIELD(temp_r11_9, u8 *, 7) = (u8) (M2C_FIELD(temp_r11_9, u8 *, 7) | 2);
        temp_r9_10 = (void **)((char *)lbl_804B01F0 + 4);
        M2C_FIELD(temp_r9_10, u8 *, 7) = (u8) (M2C_FIELD(temp_r9_10, u8 *, 7) | 1);
        M2C_FIELD(lbl_804B01F4, s32 *, 0x18) = 1;
        temp_r11_10 = (void **)((char *)lbl_804B01F4 + 4);
        M2C_FIELD(temp_r11_10, u8 *, 7) = (u8) (M2C_FIELD(temp_r11_10, u8 *, 7) | 2);
        temp_r9_11 = (void **)((char *)lbl_804B01F4 + 4);
        M2C_FIELD(temp_r9_11, u8 *, 7) = (u8) (M2C_FIELD(temp_r9_11, u8 *, 7) | 1);
    }
    lbl_804AB660 += 1;
    return arg0;
}
