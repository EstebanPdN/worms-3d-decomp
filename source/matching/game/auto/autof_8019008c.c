/* Decompiled automatically by m2c with mechanical corrections (tools/m2c_fixups.py:
 * far globals as unknown-size arrays, dropped leading parameters, forwarded
 * arguments); verified identical to the original after linking. Types and
 * names are m2c placeholders pending review. */
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

M2C_UNK fn_801EF174(s32, M2C_UNK, M2C_UNK, void *);         /* extern */
s32 fn_8019ABF0();                                  /* extern */
M2C_UNK fn_8020EE9C(M2C_UNK *);                     /* extern */
s32 fn_8019D538();                                  /* extern */
void ***fn_802CDE08(s32, M2C_UNK);                       /* extern */
M2C_UNK fn_8019EED4(void *, M2C_UNK *, M2C_UNK);       /* extern */
M2C_UNK fn_802CD99C(void *, M2C_UNK);                       /* extern */
M2C_UNK fn_802CE264(void *, M2C_UNK);                  /* extern */
M2C_UNK fn_802CDFD4(s32, s32, s32);                              /* extern */
M2C_UNK fn_802CE148(void *, s32, M2C_UNK);             /* extern */
M2C_UNK fn_802CE4D8(void *, M2C_UNK);                  /* extern */
s32 fn_801A04A8();                                  /* extern */
M2C_UNK fn_8020FCB4(M2C_UNK *);                     /* extern */
M2C_UNK fn_801EA470(void *);                           /* extern */
M2C_UNK fn_80355484(M2C_UNK *, M2C_UNK);            /* extern */
s32 fn_801B4A38();                                  /* extern */
M2C_UNK fn_801B4E94();                              /* extern */
M2C_UNK fn_801E8D9C(s32);                           /* extern */
M2C_UNK fn_801ECC6C(s32, M2C_UNK *);                     /* extern */
M2C_UNK fn_801B6804();                              /* extern */
M2C_UNK fn_801B9110();                              /* extern */
M2C_UNK fn_801EB834(s32, M2C_UNK *);                     /* extern */
M2C_UNK fn_801B9C2C();                              /* extern */
M2C_UNK fn_801EA0EC();                              /* extern */
M2C_UNK fn_801EBF38(s32, M2C_UNK *);                     /* extern */
M2C_UNK fn_801B529C();                              /* extern */
M2C_UNK fn_801BC6C4();                              /* extern */
s32 fn_801F12EC(s32, M2C_UNK *);                         /* extern */
M2C_UNK fn_801F79AC(void *, M2C_UNK *);                /* extern */
M2C_UNK fn_801EC52C(s32, M2C_UNK *);                     /* extern */
M2C_UNK fn_801ECE2C(s32, M2C_UNK *);                /* extern */
M2C_UNK fn_801B5404();                              /* extern */
s16 fn_801A3628(u16);                               /* extern */

void w3d_auto_8019008c(s32 arg0, s32 arg1) {
    fn_801EF174(arg0, 0x1C, 6, arg1);
    return;
}

void w3d_auto_801900b8(s32 arg0, s32 arg1) {
    fn_801EF174(arg0, 0x18, 7, arg1);
    return;
}

void w3d_auto_801900e4(s32 arg0, s32 arg1) {
    fn_801EF174(arg0, 0x14, 8, arg1);
    return;
}

s32 w3d_auto_801904b0(s32 arg0, s32 *arg1) {
    *arg1 = -1;
    return 0;
}

extern M2C_UNK lbl_8045CCBC[];
extern s32 lbl_804B02F0;

void w3d_auto_8019ac58(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_8045CCBC));
    lbl_804B02F0 = fn_8019ABF0();
block_3:
    return;
}

extern M2C_UNK lbl_8045CD84[];
extern s32 lbl_804B0318;

void w3d_auto_8019d5a0(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_8045CD84));
    lbl_804B0318 = fn_8019D538();
block_3:
    return;
}

s32 w3d_auto_8019e7ac(s32 arg0) {
    void **temp_r3;

    temp_r3 = *fn_802CDE08(arg0, 1);
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void **), 0x10)(temp_r3);
    return 0;
}

extern M2C_UNK lbl_803A9A10[];

void w3d_auto_8019f8a0(s32 arg0) {
    fn_802CD99C(arg0, 2);
    fn_802CE264(arg0, -0x2712);
    fn_8019EED4(arg0, &(*lbl_803A9A10), 1);
    return;
}

void w3d_auto_801a0338(s32 arg0, s32 arg1, s32 arg2) {
    fn_802CDFD4(arg0, arg1, arg2);
    fn_802CE148(arg0, arg2, 0);
    fn_802CE4D8(arg0, -3);
    return;
}

extern M2C_UNK lbl_8045CDC0[];
extern s32 lbl_804B0324;

void w3d_auto_801a0510(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_8045CDC0));
    lbl_804B0324 = fn_801A04A8();
block_3:
    return;
}

extern M2C_UNK lbl_80362330[];

void w3d_auto_801a25a0(void) {
    fn_8020FCB4(&(*lbl_80362330));
    return;
}

void w3d_auto_801a6908(s32 arg0, s32 arg1) {
    fn_801EA470(arg1);
    return;
}

extern M2C_UNK lbl_8045CE4C[];

void w3d_auto_801a8198(void) {
    fn_80355484(&(*lbl_8045CE4C), 2);
    return;
}

extern M2C_UNK lbl_8045CE60[];

void w3d_auto_801b2b48(void) {
    fn_8020FCB4(&(*lbl_8045CE60));
    return;
}

s32 w3d_auto_801b4910(s32 arg0, s32 arg1, s32 *arg2) {
    *arg2 = 0;
    return 0x80004005;
}

s32 w3d_auto_801b4924(s32 arg0, s32 arg1, s32 *arg2) {
    *arg2 = 0;
    return 0x80004001;
}

extern M2C_UNK lbl_8045CE90[];
extern s32 lbl_804B035C;

void w3d_auto_801b4aa0(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_8045CE90));
    lbl_804B035C = fn_801B4A38();
block_3:
    return;
}

extern M2C_UNK lbl_80414578[];

void *w3d_auto_801b50f0(void *arg0) {
    fn_801B4E94();
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_80414578);
    return arg0;
}

extern M2C_UNK lbl_803AAD04[];

s32 w3d_auto_801b51a4(s32 arg0) {
    fn_801ECC6C(arg0, &(*lbl_803AAD04));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_804158E8[];

void *w3d_auto_801b7984(void *arg0) {
    fn_801B6804();
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_804158E8);
    return arg0;
}

extern M2C_UNK lbl_803AB388[];

s32 w3d_auto_801b7a38(s32 arg0) {
    fn_801ECC6C(arg0, &(*lbl_803AB388));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_80415668[];

void *w3d_auto_801b953c(void *arg0) {
    fn_801B9110();
    M2C_FIELD(arg0, s8 *, 0x18) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_80415668);
    return arg0;
}

extern M2C_UNK lbl_803AB4DC[];

s32 w3d_auto_801b95d0(s32 arg0) {
    fn_801EB834(arg0, &(*lbl_803AB4DC));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_804155C8[];

void *w3d_auto_801b9e74(void *arg0) {
    fn_801B9C2C();
    M2C_FIELD(arg0, s8 *, 0x18) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_804155C8);
    return arg0;
}

extern M2C_UNK lbl_803AB55C[];

s32 w3d_auto_801b9f08(s32 arg0) {
    fn_801EB834(arg0, &(*lbl_803AB55C));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_804153C0[];

void *w3d_auto_801bbb2c(void *arg0) {
    fn_801EA0EC();
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_804153C0);
    return arg0;
}

extern M2C_UNK lbl_803AB6D4[];

s32 w3d_auto_801bbbc0(s32 arg0) {
    fn_801EBF38(arg0, &(*lbl_803AB6D4));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_804152F8[];

void *w3d_auto_801bc538(void *arg0) {
    fn_801B529C();
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_804152F8);
    return arg0;
}

extern M2C_UNK lbl_803AB854[];

s32 w3d_auto_801bc5cc(s32 arg0) {
    fn_801EBF38(arg0, &(*lbl_803AB854));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_804152A8[];
extern M2C_UNK lbl_8045E778[];

void *w3d_auto_801bc944(void *arg0) {
    void *temp_r11;

    fn_801BC6C4();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_804152A8);
    temp_r11 = arg0 + 0x48;
    M2C_FIELD(arg0, f32 *, 0x48) = (f32) M2C_FIELD(&(*lbl_8045E778), f32 *, 0);
    M2C_FIELD(temp_r11, f32 *, 4) = (f32) M2C_FIELD(&(*lbl_8045E778), f32 *, 4);
    M2C_FIELD(temp_r11, f32 *, 8) = (f32) M2C_FIELD(&(*lbl_8045E778), f32 *, 8);
    M2C_FIELD(temp_r11, f32 *, 0xC) = (f32) M2C_FIELD(&(*lbl_8045E778), f32 *, 0xC);
    M2C_FIELD(arg0, s32 *, 0x58) = 1;
    return arg0;
}

extern M2C_UNK lbl_803AB8F0[];
extern M2C_UNK lbl_8045E778[];

s32 w3d_auto_801bca04(s32 arg0) {
    fn_801F79AC(fn_801F12EC(arg0, &(*lbl_803AB8F0)) + 8, &(*lbl_8045E778));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_804151E0[];

void *w3d_auto_801bd380(void *arg0) {
    fn_801B529C();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_804151E0);
    M2C_FIELD(arg0, s32 *, 0x14) = 0x7FFFFFFF;
    return arg0;
}

extern M2C_UNK lbl_803ABB04[];

s32 w3d_auto_801bd418(s32 arg0) {
    fn_801EBF38(arg0, &(*lbl_803ABB04));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_803ABB40[];
extern M2C_UNK lbl_803ABB68[];

s32 w3d_auto_801bd5b0(s32 arg0) {
    fn_801EC52C(arg0, &(*lbl_803ABB40));
    fn_801ECE2C(arg0, &(*lbl_803ABB68));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_804150C8[];

void *w3d_auto_801be14c(void *arg0) {
    fn_801EA0EC();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_804150C8);
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s8 *, 0x18) = 2;
    M2C_FIELD(arg0, s8 *, 0x19) = 1;
    return arg0;
}

extern M2C_UNK lbl_804150A0[];

void *w3d_auto_801be328(void *arg0) {
    fn_801B4E94();
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_804150A0);
    return arg0;
}

extern M2C_UNK lbl_803ABD2C[];

s32 w3d_auto_801be3dc(s32 arg0) {
    fn_801ECC6C(arg0, &(*lbl_803ABD2C));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_80414FD8[];

void *w3d_auto_801bf1a0(void *arg0) {
    fn_801B5404();
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_80414FD8);
    return arg0;
}

extern M2C_UNK lbl_803ABE68[];

s32 w3d_auto_801bf254(s32 arg0) {
    fn_801ECC6C(arg0, &(*lbl_803ABE68));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_80416230[];

void *w3d_auto_801cb41c(void *arg0) {
    fn_801EA0EC();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_80416230);
    M2C_FIELD(arg0, s16 *, 0x14) = fn_801A3628(M2C_FIELD(arg0, u16 *, 6));
    return arg0;
}
