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

M2C_UNK fn_801FE1F8(void *);                        /* extern */
M2C_UNK fn_80210990(void *, M2C_UNK);               /* extern */
M2C_UNK fn_802134FC(void *);                              /* extern */
extern M2C_UNK lbl_80418080[];
extern M2C_UNK lbl_804180A8[];
M2C_UNK fn_801FE240(s32);                              /* extern */
M2C_UNK fn_800F339C(void *);                           /* extern */
M2C_UNK fn_800F6AFC(void *);                              /* extern */
M2C_UNK fn_802B16C4(void *, void *);                        /* extern */
M2C_UNK fn_802BCC40(void *, s32);                           /* extern */
M2C_UNK fn_8015FD1C(void *);                              /* extern */
M2C_UNK fn_8026ED00(void *);                        /* extern */
M2C_UNK fn_802B6EFC(void *);                        /* extern */
M2C_UNK fn_802BAEB8(void *, M2C_UNK);                       /* extern */
M2C_UNK fn_802CD0C8(void *);                              /* extern */
extern M2C_UNK lbl_80473724[];
extern s32 lbl_804ABCE4;
M2C_UNK fn_802CD198(s32);                              /* extern */

void w3d_auto_801f7d54(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_80418080);
    if ((s32) M2C_FIELD(arg0, s32 *, 0x14) == 0) {
        goto block_2;
    }
    fn_802134FC(M2C_FIELD(arg0, s32 *, 0x14));
block_2:
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_804180A8);
    fn_80210990(arg0 + 4, 0);
    if (!(arg1 & 1)) {
        goto block_4;
    }
    fn_801FE1F8(arg0);
block_4:
    return;
}

void w3d_auto_80209e64(void *arg0) {
    void *temp_r30;
    void *var_r31;

    var_r31 = M2C_FIELD(arg0, void **, 4);
    if (var_r31 == NULL) {
        goto block_4;
    }
loop_1:
    temp_r30 = M2C_FIELD(var_r31, void **, 0);
    if ((s32) M2C_FIELD(var_r31, s32 *, 4) == 0) {
        goto block_3;
    }
    fn_801FE240(M2C_FIELD(var_r31, s32 *, 4));
block_3:
    fn_801FE1F8(var_r31);
    var_r31 = temp_r30;
    if (var_r31 != NULL) {
        goto loop_1;
    }
block_4:
    M2C_FIELD(arg0, void **, 4) = NULL;
    return;
}

void w3d_auto_8026d8a0(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x44) == 0) {
        goto block_2;
    }
    fn_800F6AFC(M2C_FIELD(arg0, s32 *, 0x44));
    fn_800F339C(M2C_FIELD(arg0, s32 *, 0x44));
    M2C_FIELD(arg0, s32 *, 0x3C) = 0x14;
block_2:
    return;
}

void w3d_auto_8026fa2c(void *arg0, s32 arg1) {
    if (arg1 == (s32) M2C_FIELD(arg0, s32 *, 0xBC)) {
        goto block_3;
    }
    fn_802B16C4(arg0 + 0x1C, (void *)arg1);
    if ((s32) M2C_FIELD(arg0, s32 *, 0x120) == 0) {
        goto block_3;
    }
    fn_802BCC40(M2C_FIELD(arg0, s32 *, 0x120), M2C_FIELD(arg0, s32 *, 0xBC));
block_3:
    return;
}

void w3d_auto_8026fa7c(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x124) == 0) {
        goto block_2;
    }
    fn_8015FD1C(M2C_FIELD(arg0, s32 *, 0x124));
    M2C_FIELD(arg0, s32 *, 0x124) = 0;
    fn_8026ED00(arg0);
block_2:
    return;
}

void w3d_auto_802b8754(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x120) == 0) {
        goto block_2;
    }
    fn_8015FD1C(M2C_FIELD(arg0, s32 *, 0x120));
    M2C_FIELD(arg0, s32 *, 0x120) = 0;
    fn_802B6EFC(arg0);
block_2:
    return;
}

void w3d_auto_802bacc8(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0xDC) == 0) {
        goto block_2;
    }
    fn_802BAEB8(M2C_FIELD(arg0, s32 *, 0xDC), 3);
    M2C_FIELD(arg0, s32 *, 0xDC) = 0;
block_2:
    return;
}

void w3d_auto_802cd07c(u32 arg0) {
    if ((s32) lbl_804ABCE4 == 0) {
        goto block_4;
    }
    if (arg0 > 0xFU) {
        goto block_4;
    }
    if ((s32) *(&(*lbl_80473724) + (arg0)) == 0) {
        goto block_4;
    }
    fn_802CD0C8(*(&(*lbl_80473724) + (arg0)));
block_4:
    return;
}

void w3d_auto_802cd14c(u32 arg0) {
    if ((s32) lbl_804ABCE4 == 0) {
        goto block_4;
    }
    if (arg0 > 0xFU) {
        goto block_4;
    }
    if ((s32) *(&(*lbl_80473724) + (arg0)) == 0) {
        goto block_4;
    }
    fn_802CD198(*(&(*lbl_80473724) + (arg0)));
block_4:
    return;
}

void w3d_auto_8035366c(void *arg0) {
    s32 temp_r9;
    void *temp_r10;
    void *temp_r11;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x14) == 0) {
        goto block_2;
    }
    fn_802134FC(M2C_FIELD(arg0, s32 *, 0x14));
block_2:
    temp_r10 = M2C_FIELD(arg0, void **, 0x1C);
    temp_r11 = arg0 + 0x10;
    M2C_FIELD(temp_r11, s32 *, 0xC) = (s32) (temp_r10 - 4);
    temp_r9 = M2C_FIELD(temp_r10, s32 *, -4);
    M2C_FIELD(temp_r11, s32 *, 4) = temp_r9;
    M2C_FIELD(temp_r11, s32 *, 8) = (s32) (temp_r9 + 0x80);
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x18) - 4);
    return;
}

void w3d_auto_80356e28(void *arg0) {
    M2C_UNK *temp_r11;
    M2C_UNK *temp_r3;
    M2C_UNK *temp_r9;
    M2C_UNK *temp_r9_2;
    M2C_UNK *var_r31;

    temp_r9 = M2C_FIELD(arg0, M2C_UNK **, 4);
    var_r31 = M2C_FIELD(temp_r9, M2C_UNK **, 0);
    if (var_r31 == temp_r9) {
        goto block_4;
    }
loop_1:
    temp_r3 = var_r31;
    var_r31 = *var_r31;
    if (temp_r3 == NULL) {
        goto block_3;
    }
    fn_802134FC(temp_r3);
block_3:
    if (var_r31 != (M2C_UNK *) M2C_FIELD(arg0, M2C_UNK **, 4)) {
        goto loop_1;
    }
block_4:
    temp_r9_2 = M2C_FIELD(arg0, M2C_UNK **, 4);
    M2C_FIELD(temp_r9_2, M2C_UNK **, 0) = temp_r9_2;
    temp_r11 = M2C_FIELD(arg0, M2C_UNK **, 4);
    M2C_FIELD(temp_r11, M2C_UNK **, 4) = temp_r11;
    return;
}

void w3d_auto_80356e90(void *arg0) {
    M2C_UNK *temp_r11;
    M2C_UNK *temp_r3;
    M2C_UNK *temp_r9;
    M2C_UNK *temp_r9_2;
    M2C_UNK *var_r31;

    temp_r9 = M2C_FIELD(arg0, M2C_UNK **, 4);
    var_r31 = M2C_FIELD(temp_r9, M2C_UNK **, 0);
    if (var_r31 == temp_r9) {
        goto block_4;
    }
loop_1:
    temp_r3 = var_r31;
    var_r31 = *var_r31;
    if (temp_r3 == NULL) {
        goto block_3;
    }
    fn_802134FC(temp_r3);
block_3:
    if (var_r31 != (M2C_UNK *) M2C_FIELD(arg0, M2C_UNK **, 4)) {
        goto loop_1;
    }
block_4:
    temp_r9_2 = M2C_FIELD(arg0, M2C_UNK **, 4);
    M2C_FIELD(temp_r9_2, M2C_UNK **, 0) = temp_r9_2;
    temp_r11 = M2C_FIELD(arg0, M2C_UNK **, 4);
    M2C_FIELD(temp_r11, M2C_UNK **, 4) = temp_r11;
    return;
}

void w3d_auto_8035d214(void *arg0) {
    M2C_UNK *temp_r11;
    M2C_UNK *temp_r3;
    M2C_UNK *temp_r9;
    M2C_UNK *temp_r9_2;
    M2C_UNK *var_r31;

    temp_r9 = M2C_FIELD(arg0, M2C_UNK **, 4);
    var_r31 = M2C_FIELD(temp_r9, M2C_UNK **, 0);
    if (var_r31 == temp_r9) {
        goto block_4;
    }
loop_1:
    temp_r3 = var_r31;
    var_r31 = *var_r31;
    if (temp_r3 == NULL) {
        goto block_3;
    }
    fn_802134FC(temp_r3);
block_3:
    if (var_r31 != (M2C_UNK *) M2C_FIELD(arg0, M2C_UNK **, 4)) {
        goto loop_1;
    }
block_4:
    temp_r9_2 = M2C_FIELD(arg0, M2C_UNK **, 4);
    M2C_FIELD(temp_r9_2, M2C_UNK **, 0) = temp_r9_2;
    temp_r11 = M2C_FIELD(arg0, M2C_UNK **, 4);
    M2C_FIELD(temp_r11, M2C_UNK **, 4) = temp_r11;
    return;
}
