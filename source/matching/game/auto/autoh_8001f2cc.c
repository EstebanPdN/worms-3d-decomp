/* Decompiled automatically by m2c; statement order, callee return width or a
 * guarded call argument adjusted by tools/m2c_reorder.py and verified identical
 * to the original after linking. Types and names are m2c placeholders pending
 * review. */
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

M2C_UNK fn_8001F25C(void *, s32);                              /* extern */
extern s32 lbl_804AA6C0;
extern s32 lbl_804B17A8;
extern s32 lbl_804B17AC;
M2C_UNK fn_8016803C(void *, M2C_UNK);                  /* extern */
M2C_UNK fn_8016804C(void *, M2C_UNK);                  /* extern */
extern s32 lbl_804B1884;
M2C_UNK fn_80168744(void *, void *);                           /* extern */
M2C_UNK fn_8016CD38(void *, void *);                           /* extern */
M2C_UNK fn_801AD168(void *, void *, M2C_UNK);          /* extern */
M2C_UNK fn_801B529C();                              /* extern */
extern f32 lbl_803ABB34[];
extern M2C_UNK lbl_804151B8[];
M2C_UNK fn_801BFE64();                              /* extern */
extern f32 lbl_803AC284[];
extern f32 lbl_803AC288[];
extern M2C_UNK lbl_80414EC0[];
extern f32 lbl_803AC300[];
extern f32 lbl_803AC304[];
extern f32 lbl_803AC308[];
extern M2C_UNK lbl_80414E98[];
M2C_UNK fn_801CB41C();                              /* extern */
extern f32 lbl_803ADF60[];
extern M2C_UNK lbl_804161E0[];
extern f32 lbl_803AE240[];
extern f32 lbl_803AE244[];
extern M2C_UNK lbl_804160F0[];
M2C_UNK fn_801D4544(void *, void *);                      /* extern */
M2C_UNK fn_801D60CC(s32, M2C_UNK, void *);             /* extern */
M2C_UNK fn_801D6220(s32, M2C_UNK, void *);             /* extern */
extern void *lbl_804B178C;

void w3d_auto_8001f2cc(void *arg0) {
    if ((s32) lbl_804AA6C0 == -1) {
        goto block_2;
    }
    fn_8001F25C(arg0, lbl_804AA6C0);
block_2:
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    return;
}

void w3d_auto_8004b8f4(void *arg0) {
    {
        __typeof__((s32) lbl_804B17AC) h0 = (s32) lbl_804B17AC;
        __typeof__((s32) lbl_804B17A8) h1 = (s32) lbl_804B17A8;
        M2C_FIELD(arg0, s32 *, 0xC0) = h0;
        M2C_FIELD(arg0, s32 *, 0xBC) = h1;
    }
    return;
}

s32 w3d_auto_80168dcc(s32 arg0, void *arg1) {
    void *temp_r0;
    void *temp_r9;
    void *temp_r9_2;
    void *var_r11;

    var_r11 = arg0 ? arg0 - 4 : NULL;
block_2:
    temp_r9 = M2C_FIELD(arg1, void **, 0x18);
    temp_r0 = M2C_FIELD(temp_r9, void **, 0x18);
    temp_r9_2 = temp_r9 + 0x20;
    if (temp_r9_2 != NULL) {
        goto block_4;
    }
    return 0;
block_4:
    M2C_FIELD(var_r11, void **, 0xBC) = temp_r0;
    if (temp_r0 == NULL) {
        goto block_6;
    }
    M2C_FIELD(var_r11, void **, 0xA0) = temp_r9_2;
    goto block_7;
block_6:
    M2C_FIELD(var_r11, void **, 0xA0) = temp_r0;
block_7:
    M2C_FIELD(var_r11, s32 *, 0x124) = 0;
    M2C_FIELD(var_r11, s32 *, 0xB4) = (s32) (M2C_FIELD(var_r11, s32 *, 0xB4) & 0x3FFFFFFF);
    return 0;
}

s32 w3d_auto_80169060(s32 arg0, void *arg1) {
    void *temp_r0;
    void *var_r11;

    var_r11 = arg0 ? arg0 - 4 : NULL;
block_2:
    temp_r0 = M2C_FIELD(M2C_FIELD(arg1, void **, 0x14), void **, 0x18);
    if (temp_r0 == NULL) {
        goto block_4;
    }
    M2C_FIELD(var_r11, void **, 0x7C) = arg1;
    goto block_5;
block_4:
    M2C_FIELD(var_r11, void **, 0x7C) = temp_r0;
block_5:
    return 0;
}

s32 w3d_auto_8016a5dc(s32 arg0, void *arg1) {
    s32 var_r0;
    void *var_r31;

    var_r31 = arg0 ? arg0 - 4 : NULL;
block_2:
    if ((s32) M2C_FIELD(arg1, s32 *, 0x34) == 0) {
        goto block_4;
    }
    fn_8016803C(lbl_804B1884, 4);
    var_r0 = M2C_FIELD(var_r31, s32 *, 0xB4) | 0x02000000;
    goto block_5;
block_4:
    fn_8016804C(lbl_804B1884, 4);
    var_r0 = M2C_FIELD(var_r31, s32 *, 0xB4) & 0xFDFFFFFF;
block_5:
    M2C_FIELD(var_r31, s32 *, 0xB4) = var_r0;
    return 0;
}

s32 w3d_auto_8016c4bc(s32 arg0, void *arg1) {
    s32 var_r0;

    var_r0 = arg0 ? arg0 - 4 : 0;
block_2:
    fn_80168744(var_r0, arg1);
    return 0;
}

s32 w3d_auto_8016d464(s32 arg0, void *arg1) {
    s32 var_r0;

    var_r0 = arg0 ? arg0 - 4 : 0;
block_2:
    fn_8016CD38(var_r0, arg1);
    return 0;
}

s32 w3d_auto_801aacc0(s32 arg0, void *arg1) {
    void *var_r9;

    var_r9 = arg0 ? arg0 - 4 : NULL;
block_2:
    M2C_FIELD(var_r9, u16 *, 0xE4) = (u16) M2C_FIELD(arg1, u16 *, 0x38);
    return 0;
}

void w3d_auto_801ad8c0(s32 arg0) {
    void *var_r0;

    var_r0 = arg0 ? arg0 - 4 : NULL;
block_2:
    fn_801AD168(var_r0, M2C_FIELD(var_r0, s32 *, 0x18), 0);
    return;
}

s32 w3d_auto_801b1420(s32 arg0, void *arg1) {
    void *var_r9;

    var_r9 = arg0 ? arg0 - 4 : NULL;
block_2:
    M2C_FIELD(var_r9, s32 *, 0x2C) = (s32) (((u16) M2C_FIELD(arg1, u16 *, 0x28) >> 1U) & 3);
    return 0;
}

void *w3d_auto_801bd510(void *arg0) {
    fn_801B529C();
    {
        __typeof__(&(*lbl_804151B8)) h0 = &(*lbl_804151B8);
        __typeof__(0) h1 = 0;
        __typeof__((f32) (*lbl_803ABB34)) h2 = (f32) (*lbl_803ABB34);
        M2C_FIELD(arg0, M2C_UNK **, 0) = h0;
        M2C_FIELD(arg0, s32 *, 0x14) = h1;
        M2C_FIELD(arg0, f32 *, 0x18) = h2;
    }
    return arg0;
}

void *w3d_auto_801c0048(void *arg0) {
    fn_801BFE64();
    {
        __typeof__(&(*lbl_80414EC0)) h0 = &(*lbl_80414EC0);
        __typeof__((f32) (*lbl_803AC284)) h1 = (f32) (*lbl_803AC284);
        __typeof__((f32) (*lbl_803AC288)) h2 = (f32) (*lbl_803AC288);
        M2C_FIELD(arg0, M2C_UNK **, 0) = h0;
        M2C_FIELD(arg0, f32 *, 0xC4) = h1;
        M2C_FIELD(arg0, f32 *, 0xC8) = h2;
    }
    return arg0;
}

void *w3d_auto_801c01f4(void *arg0) {
    fn_801BFE64();
    {
        __typeof__(&(*lbl_80414E98)) h0 = &(*lbl_80414E98);
        __typeof__((f32) (*lbl_803AC300)) h1 = (f32) (*lbl_803AC300);
        __typeof__((f32) (*lbl_803AC304)) h2 = (f32) (*lbl_803AC304);
        __typeof__((f32) (*lbl_803AC308)) h3 = (f32) (*lbl_803AC308);
        M2C_FIELD(arg0, M2C_UNK **, 0) = h0;
        M2C_FIELD(arg0, f32 *, 0xC4) = h1;
        M2C_FIELD(arg0, f32 *, 0xC8) = h2;
        M2C_FIELD(arg0, f32 *, 0xCC) = h3;
    }
    return arg0;
}

void w3d_auto_801c89c0(void *arg0, void *arg1) {
    {
        __typeof__((s32) M2C_FIELD(arg1, s32 *, 0)) h0 = (s32) M2C_FIELD(arg1, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0x30) = (s32) M2C_FIELD(arg1, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x2C) = h0;
    }
    return;
}

void *w3d_auto_801cb934(void *arg0) {
    fn_801CB41C();
    {
        __typeof__(&(*lbl_804161E0)) h0 = &(*lbl_804161E0);
        __typeof__((f32) (*lbl_803ADF60)) h1 = (f32) (*lbl_803ADF60);
        __typeof__(7) h2 = 7;
        __typeof__(0) h3 = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0) = h0;
        M2C_FIELD(arg0, f32 *, 0x18) = h1;
        M2C_FIELD(arg0, s32 *, 0x1C) = h2;
        M2C_FIELD(arg0, s32 *, 0x20) = h3;
    }
    return arg0;
}

void *w3d_auto_801cc330(void *arg0) {
    fn_801CB41C();
    {
        __typeof__(&(*lbl_804160F0)) h0 = &(*lbl_804160F0);
        __typeof__((f32) (*lbl_803AE240)) h1 = (f32) (*lbl_803AE240);
        __typeof__((f32) (*lbl_803AE244)) h2 = (f32) (*lbl_803AE244);
        __typeof__(3) h3 = 3;
        __typeof__(1) h4 = 1;
        M2C_FIELD(arg0, M2C_UNK **, 0) = h0;
        M2C_FIELD(arg0, f32 *, 0x18) = h1;
        M2C_FIELD(arg0, f32 *, 0x1C) = h2;
        M2C_FIELD(arg0, s32 *, 0x20) = h3;
        M2C_FIELD(arg0, s32 *, 0x24) = h4;
    }
    return arg0;
}

void w3d_auto_801d176c(void *arg0, void *arg1) {
    void *temp_r11;

    {
        __typeof__((s32) M2C_FIELD(arg1, s32 *, 0)) h0 = (s32) M2C_FIELD(arg1, s32 *, 0);
        temp_r11 = arg0 + 4;
        M2C_FIELD(arg0, s32 *, 0x60) = (s32) M2C_FIELD(arg1, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x5C) = h0;
        M2C_FIELD(temp_r11, u8 *, 7) = (u8) (M2C_FIELD(temp_r11, u8 *, 7) | 2);
    }
    return;
}

void w3d_auto_801d1798(void *arg0, void *arg1) {
    void *temp_r11;

    {
        __typeof__((s32) M2C_FIELD(arg1, s32 *, 0)) h0 = (s32) M2C_FIELD(arg1, s32 *, 0);
        temp_r11 = arg0 + 4;
        M2C_FIELD(arg0, s32 *, 0x58) = (s32) M2C_FIELD(arg1, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x54) = h0;
        M2C_FIELD(temp_r11, u8 *, 7) = (u8) (M2C_FIELD(temp_r11, u8 *, 7) | 2);
    }
    return;
}

s32 w3d_auto_801d445c(s32 arg0, s32 arg1) {
    void *var_r9;

    var_r9 = arg0 ? arg0 - 4 : NULL;
block_2:
    fn_801D4544(arg1, M2C_FIELD(var_r9, s32 *, 0x28));
    return 0;
}

s32 w3d_auto_801d5af0(s32 arg0, void *arg1) {
    void *var_r9;

    var_r9 = arg0 ? arg0 - 4 : NULL;
block_2:
    if ((s32) M2C_FIELD(var_r9, s32 *, 0x30) == 0) {
        goto block_4;
    }
    M2C_FIELD(var_r9, s32 *, 0x2C) = 1;
    return 0;
block_4:
    if ((s32) M2C_FIELD(arg1, s32 *, 0x18) == 1) {
        goto block_6;
    }
    if ((s32) M2C_FIELD(arg1, s32 *, 0x1C) != 1) {
        goto block_7;
    }
block_6:
    M2C_FIELD(var_r9, s32 *, 0x2C) = 1;
block_7:
    return 0;
}

s32 w3d_auto_801d65e8(s32 arg0, s32 arg1) {
    s32 var_r31;

    var_r31 = arg0 ? arg0 - 4 : 0;
block_2:
    fn_801D60CC(var_r31, 3, arg1);
    fn_801D6220(var_r31, 3, arg1);
    return 0;
}

void w3d_auto_80249fbc(void *arg0, void *arg1) {
    {
        __typeof__((s32) M2C_FIELD(arg1, s32 *, 0)) h0 = (s32) M2C_FIELD(arg1, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0xF8) = (s32) M2C_FIELD(arg1, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0xF4) = h0;
    }
    return;
}

void w3d_auto_8024a3e8(void *arg0, void *arg1) {
    {
        __typeof__((s32) M2C_FIELD(arg1, s32 *, 0)) h0 = (s32) M2C_FIELD(arg1, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0x100) = (s32) M2C_FIELD(arg1, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0xFC) = h0;
    }
    return;
}

void w3d_auto_8024a424(void *arg0, void *arg1) {
    {
        __typeof__((s32) M2C_FIELD(arg1, s32 *, 0)) h0 = (s32) M2C_FIELD(arg1, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0x108) = (s32) M2C_FIELD(arg1, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x104) = h0;
    }
    return;
}

void w3d_auto_8024a440(void *arg0, void *arg1) {
    {
        __typeof__((s32) M2C_FIELD(arg1, s32 *, 0)) h0 = (s32) M2C_FIELD(arg1, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0xF0) = (s32) M2C_FIELD(arg1, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0xEC) = h0;
    }
    return;
}

void w3d_auto_8024a46c(void *arg0, void *arg1) {
    {
        __typeof__((s32) M2C_FIELD(arg1, s32 *, 0)) h0 = (s32) M2C_FIELD(arg1, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0xE8) = (s32) M2C_FIELD(arg1, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0xE4) = h0;
    }
    return;
}

void w3d_auto_80251004(void *arg0, void *arg1) {
    {
        __typeof__((s32) M2C_FIELD(arg1, s32 *, 0)) h0 = (s32) M2C_FIELD(arg1, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0x1A0) = (s32) M2C_FIELD(arg1, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x19C) = h0;
    }
    return;
}

void w3d_auto_80251020(void *arg0, void *arg1) {
    {
        __typeof__((s32) M2C_FIELD(arg1, s32 *, 0)) h0 = (s32) M2C_FIELD(arg1, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0x198) = (s32) M2C_FIELD(arg1, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x194) = h0;
    }
    return;
}

void w3d_auto_802514c0(void *arg0, void *arg1) {
    {
        __typeof__((s32) M2C_FIELD(arg1, s32 *, 0)) h0 = (s32) M2C_FIELD(arg1, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0x40) = (s32) M2C_FIELD(arg1, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x3C) = h0;
    }
    return;
}

void w3d_auto_802514dc(void *arg0, void *arg1) {
    {
        __typeof__((s32) M2C_FIELD(arg1, s32 *, 0)) h0 = (s32) M2C_FIELD(arg1, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0x38) = (s32) M2C_FIELD(arg1, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x34) = h0;
    }
    return;
}

void w3d_auto_80251a14(void *arg0, void *arg1) {
    {
        __typeof__((s32) M2C_FIELD(arg1, s32 *, 0)) h0 = (s32) M2C_FIELD(arg1, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0xA4) = (s32) M2C_FIELD(arg1, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0xA0) = h0;
    }
    return;
}

void w3d_auto_80251a30(void *arg0, void *arg1) {
    {
        __typeof__((s32) M2C_FIELD(arg1, s32 *, 0)) h0 = (s32) M2C_FIELD(arg1, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0x9C) = (s32) M2C_FIELD(arg1, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x98) = h0;
    }
    return;
}

void w3d_auto_8034b3f8(void *arg0, s32 arg1) {
    {
        __typeof__(lbl_804B178C) h0 = lbl_804B178C;
        M2C_FIELD(arg0, s32 *, 0x24) = arg1;
        M2C_FIELD(h0, s32 *, 0x34) = arg1;
    }
    return;
}

void w3d_auto_8034b408(void *arg0, s32 arg1) {
    {
        __typeof__(lbl_804B178C) h0 = lbl_804B178C;
        M2C_FIELD(arg0, s32 *, 0x20) = arg1;
        M2C_FIELD(h0, s32 *, 0x30) = arg1;
    }
    return;
}
