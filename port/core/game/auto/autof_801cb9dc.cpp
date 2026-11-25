#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autof_801cb9dc.c"
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
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)(w3d::bytes(expr) + (offset)))

/* Bitwise (reinterpret) cast */
#define M2C_BITWISE(type, expr) ((w3d::slot_t<type>)(expr))

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

M2C_UNK fn_801E8D9C(s32);                           /* extern */
M2C_UNK fn_801EB674(s32, Ptr32<M2C_UNK>);                     /* extern */
M2C_UNK fn_801EC52C(s32, Ptr32<M2C_UNK>);                /* extern */
M2C_UNK fn_801ECE2C(s32, Ptr32<M2C_UNK>);                /* extern */
M2C_UNK fn_801CB41C();                              /* extern */
M2C_UNK fn_801EBF38(s32, Ptr32<M2C_UNK>);                     /* extern */
M2C_UNK fn_801EB834(s32, Ptr32<M2C_UNK>);                /* extern */
M2C_UNK fn_801EB674(s32, Ptr32<M2C_UNK>);                /* extern */
M2C_UNK fn_801ECE2C(s32, Ptr32<M2C_UNK>);                     /* extern */
M2C_UNK fn_801EC52C(s32, Ptr32<M2C_UNK>);                     /* extern */
M2C_UNK fn_801CD65C();                              /* extern */
M2C_UNK fn_801EBBB8(s32, Ptr32<M2C_UNK>);                     /* extern */
M2C_UNK fn_801CDFEC();                              /* extern */
M2C_UNK fn_801ECC6C(s32, Ptr32<M2C_UNK>);                     /* extern */
M2C_UNK fn_801ECC6C(s32, Ptr32<M2C_UNK>);                /* extern */
M2C_UNK fn_801EF174(s32, M2C_UNK, M2C_UNK, Ptr32<void>);         /* extern */
M2C_UNK fn_801EF2EC(s32, M2C_UNK, M2C_UNK, Ptr32<void>, s32);    /* extern */
M2C_UNK fn_8020FBD0(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>, Ptr32<M2C_UNK>, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 fn_801E6DCC();                                  /* extern */
M2C_UNK fn_8020EE9C(Ptr32<M2C_UNK>);                     /* extern */
M2C_UNK fn_8020DDC0(s32, s32);                      /* extern */
s32 fn_802ED89C(s32);                               /* extern */
M2C_UNK fn_801FE52C(Ptr32<Ptr32<M2C_UNK>>);                    /* extern */
M2C_UNK fn_801E7E24(Ptr32<M2C_UNK>);                     /* extern */
M2C_UNK fn_801F3CCC();                              /* extern */
M2C_UNK fn_80356A04(Ptr32<M2C_UNK>, M2C_UNK);            /* extern */
s32 fn_801EAF7C();                                  /* extern */
M2C_UNK fn_801FE1F8();                              /* extern */
M2C_UNK fn_801EB058();                              /* extern */
M2C_UNK fn_803426B8(Ptr32<void>);                           /* extern */

extern M2C_UNK lbl_803ADF6C[];
extern M2C_UNK lbl_803ADF94[];
extern M2C_UNK lbl_803ADFC8[];

s32 w3d_auto_801cb9dc(s32 arg0) {
    fn_801EB674(arg0, &(*lbl_803ADF6C));
    fn_801ECE2C(arg0, &(*lbl_803ADF94));
    fn_801EC52C(arg0, &(*lbl_803ADFC8));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_804161B8[];

Ptr32<void> w3d_auto_801cbaf4(Ptr32<void> arg0) {
    fn_801CB41C();
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_804161B8);
    return arg0;
}

extern M2C_UNK lbl_803AE004[];

s32 w3d_auto_801cbb88(s32 arg0) {
    fn_801EB674(arg0, &(*lbl_803AE004));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_80416190[];

Ptr32<void> w3d_auto_801cbc80(Ptr32<void> arg0) {
    fn_801CB41C();
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_80416190);
    return arg0;
}

extern M2C_UNK lbl_803AE040[];

s32 w3d_auto_801cbd14(s32 arg0) {
    fn_801EB674(arg0, &(*lbl_803AE040));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_80416168[];

Ptr32<void> w3d_auto_801cbe0c(Ptr32<void> arg0) {
    fn_801CB41C();
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_80416168);
    return arg0;
}

extern M2C_UNK lbl_803AE07C[];

s32 w3d_auto_801cbea0(s32 arg0) {
    fn_801EBF38(arg0, &(*lbl_803AE07C));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_803AE0B4[];
extern M2C_UNK lbl_803AE0DC[];
extern M2C_UNK lbl_803AE10C[];
extern M2C_UNK lbl_803AE140[];
extern M2C_UNK lbl_803AE174[];
extern M2C_UNK lbl_803AE19C[];
extern M2C_UNK lbl_803AE1D0[];

s32 w3d_auto_801cc04c(s32 arg0) {
    fn_801EB674(arg0, &(*lbl_803AE0B4));
    fn_801ECE2C(arg0, &(*lbl_803AE0DC));
    fn_801ECE2C(arg0, &(*lbl_803AE10C));
    fn_801ECE2C(arg0, &(*lbl_803AE140));
    fn_801ECE2C(arg0, &(*lbl_803AE174));
    fn_801EB834(arg0, &(*lbl_803AE19C));
    fn_801EB834(arg0, &(*lbl_803AE1D0));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_80416118[];

Ptr32<void> w3d_auto_801cc1a4(Ptr32<void> arg0) {
    fn_801CB41C();
    M2C_FIELD(arg0, s32 *, 0x18) = 1;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_80416118);
    return arg0;
}

extern M2C_UNK lbl_803AE20C[];

s32 w3d_auto_801cc238(s32 arg0) {
    fn_801EB674(arg0, &(*lbl_803AE20C));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_803AE248[];
extern M2C_UNK lbl_803AE270[];
extern M2C_UNK lbl_803AE2A0[];
extern M2C_UNK lbl_803AE2D0[];

s32 w3d_auto_801cc3e4(s32 arg0) {
    fn_801ECE2C(arg0, &(*lbl_803AE248));
    fn_801EB674(arg0, &(*lbl_803AE270));
    fn_801EC52C(arg0, &(*lbl_803AE2A0));
    fn_801EC52C(arg0, &(*lbl_803AE2D0));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_804160C8[];

Ptr32<void> w3d_auto_801cc50c(Ptr32<void> arg0) {
    fn_801CB41C();
    M2C_FIELD(arg0, s32 *, 0x18) = 2;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_804160C8);
    return arg0;
}

extern M2C_UNK lbl_803AE304[];

s32 w3d_auto_801cc5a0(s32 arg0) {
    fn_801ECE2C(arg0, &(*lbl_803AE304));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_804160A0[];

Ptr32<void> w3d_auto_801cc698(Ptr32<void> arg0) {
    fn_801CB41C();
    M2C_FIELD(arg0, s32 *, 0x18) = 2;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_804160A0);
    return arg0;
}

extern M2C_UNK lbl_803AE338[];

s32 w3d_auto_801cc72c(s32 arg0) {
    fn_801ECE2C(arg0, &(*lbl_803AE338));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_80416078[];

Ptr32<void> w3d_auto_801cc824(Ptr32<void> arg0) {
    fn_801CB41C();
    M2C_FIELD(arg0, s32 *, 0x18) = 3;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_80416078);
    return arg0;
}

extern M2C_UNK lbl_803AE36C[];

s32 w3d_auto_801cc8b8(s32 arg0) {
    fn_801ECE2C(arg0, &(*lbl_803AE36C));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_803AE3B0[];

s32 w3d_auto_801cca48(s32 arg0) {
    fn_801EC52C(arg0, &(*lbl_803AE3B0));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_803AE3F4[];

s32 w3d_auto_801ccbd8(s32 arg0) {
    fn_801EC52C(arg0, &(*lbl_803AE3F4));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_80416000[];

Ptr32<void> w3d_auto_801cccd0(Ptr32<void> arg0) {
    fn_801CB41C();
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_80416000);
    M2C_FIELD(arg0, s16 *, 0x18) = -1;
    M2C_FIELD(arg0, s16 *, 0x1A) = 1;
    return arg0;
}

extern M2C_UNK lbl_80415F60[];

Ptr32<void> w3d_auto_801cd4b8(Ptr32<void> arg0) {
    fn_801CB41C();
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_80415F60);
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 1;
    return arg0;
}

extern M2C_UNK lbl_80415F10[];

Ptr32<void> w3d_auto_801cdbbc(Ptr32<void> arg0) {
    fn_801CD65C();
    M2C_FIELD(arg0, s16 *, 0x3C) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_80415F10);
    return arg0;
}

extern M2C_UNK lbl_803AE92C[];

s32 w3d_auto_801cdc50(s32 arg0) {
    fn_801EBBB8(arg0, &(*lbl_803AE92C));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_80415DD0[];

Ptr32<void> w3d_auto_801cec1c(Ptr32<void> arg0) {
    fn_801CDFEC();
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_80415DD0);
    return arg0;
}

extern M2C_UNK lbl_803AEDB0[];

s32 w3d_auto_801cecd0(s32 arg0) {
    fn_801ECC6C(arg0, &(*lbl_803AEDB0));
    fn_801E8D9C(arg0);
    return 0;
}

extern M2C_UNK lbl_803AEE64[];
extern M2C_UNK lbl_803AEE94[];
extern M2C_UNK lbl_803AEEC0[];
extern M2C_UNK lbl_803AEEE8[];
extern M2C_UNK lbl_803AEF14[];
extern M2C_UNK lbl_803AEF40[];
extern M2C_UNK lbl_803AEF6C[];

s32 w3d_auto_801cf130(s32 arg0) {
    fn_801ECE2C(arg0, &(*lbl_803AEE64));
    fn_801ECC6C(arg0, &(*lbl_803AEE94));
    fn_801ECC6C(arg0, &(*lbl_803AEEC0));
    fn_801ECC6C(arg0, &(*lbl_803AEEE8));
    fn_801ECC6C(arg0, &(*lbl_803AEF14));
    fn_801ECC6C(arg0, &(*lbl_803AEF40));
    fn_801ECC6C(arg0, &(*lbl_803AEF6C));
    fn_801E8D9C(arg0);
    return 0;
}

void w3d_auto_801d086c(s32 arg0, s32 arg1) {
    fn_801EF174(arg0, 0x20, 2, w3d::G(arg1));
    return;
}

void w3d_auto_801d0898(s32 arg0, s32 arg1, s32 arg2) {
    fn_801EF2EC(arg0, 0x20, 2, w3d::G(arg1), arg2);
    return;
}

extern f32 lbl_803AF620[];
extern f32 lbl_803AF624[];
extern f32 lbl_803AF628[];

f32 w3d_auto_801d6998(f32 farg0) {
    f32 var_f13;

    var_f13 = farg0;
    if (!(var_f13 < (*lbl_803AF620))) {
        goto block_2;
    }
    var_f13 = -var_f13;
block_2:
    if (!(var_f13 < (*lbl_803AF624))) {
        goto block_5;
    }
    return (((2.0f * var_f13) - (*lbl_803AF628)) * var_f13 * var_f13) + (*lbl_803AF624);
block_5:
    return (*lbl_803AF620);
}

extern M2C_UNK lbl_803655EC[];
extern M2C_UNK lbl_803E9FC4[];

void w3d_auto_801de620(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020FBD0(&(*lbl_803655EC), &(*lbl_803E9FC4), &(*lbl_803655EC), 0, 0, 0);
block_3:
    return;
}

extern f32 lbl_803B06EC[];

f32 w3d_auto_801e50bc(void) {
    return (*lbl_803B06EC);
}

extern M2C_UNK lbl_8045DFC8[];
extern s32 lbl_804B0574;

void w3d_auto_801e6e34(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_8045DFC8));
    lbl_804B0574 = fn_801E6DCC();
block_3:
    return;
}

void w3d_auto_801e6f60(s32 arg0, s32 arg1, Ptr32<s32> arg2) {
    fn_8020DDC0(arg1, *arg2);
    return;
}

s32 w3d_auto_801e6f94(s32 arg0, Ptr32<s32> arg1, s32 arg2) {
    *arg1 = fn_802ED89C(arg2);
    return 0;
}

extern M2C_UNK lbl_80416FA0[];
extern Ptr32<M2C_UNK> lbl_8045E004[];

void w3d_auto_801e70ec(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_801FE52C(&(*lbl_8045E004));
    (*lbl_8045E004) = &(*lbl_80416FA0);
block_3:
    return;
}

extern M2C_UNK lbl_8036573C[];
extern s32 lbl_804AB894;

void w3d_auto_801e80f0(void) {
    fn_801F3CCC();
    if ((s32) lbl_804AB894 == 0) {
        goto block_2;
    }
    fn_801E7E24(&(*lbl_8036573C));
block_2:
    return;
}

extern M2C_UNK lbl_8045E06C[];

void w3d_auto_801e8d70(void) {
    fn_80356A04(&(*lbl_8045E06C), 2);
    return;
}

extern M2C_UNK lbl_8045E110[];
extern s32 lbl_804B058C;

void w3d_auto_801eafe4(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8020EE9C(&(*lbl_8045E110));
    lbl_804B058C = fn_801EAF7C();
block_3:
    return;
}

extern M2C_UNK lbl_80417630[];

void w3d_auto_801eb074(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 4) = &(*lbl_80417630);
    if (!(arg1 & 1)) {
        goto block_2;
    }
    fn_801FE1F8();
block_2:
    return;
}

extern M2C_UNK lbl_804172A0[];

Ptr32<void> w3d_auto_801ed16c(Ptr32<void> arg0) {
    fn_801EB058();
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 4) = &(*lbl_804172A0);
    fn_803426B8(arg0 + 8);
    return arg0;
}

}
