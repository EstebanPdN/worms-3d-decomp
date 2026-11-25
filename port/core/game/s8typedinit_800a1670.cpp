#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8typedinit_800a1670.c"
typedef struct { float x,y,z; } s8_Vector;
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
/* Inferred prototypes supported by existing matched callers and original register use. */
Ptr32<void> fn_80341584(Ptr32<void>);
Ptr32<void> fn_80343584(Ptr32<void>);
Ptr32<void> fn_803426B4(Ptr32<void>);
Ptr32<void> fn_80343744(Ptr32<void>);
Ptr32<void> fn_80179598(Ptr32<void>,int);
Ptr32<void> fn_801797B4(Ptr32<void>);
int fn_80178C48(Ptr32<void>);
Ptr32<void> fn_801613F0(Ptr32<void>,int);
int fn_8016239C(Ptr32<void>);
int fn_8015FC58(Ptr32<void>,Ptr32<void>);
Ptr32<void> fn_800C1620(Ptr32<void>,Ptr32<int>);
Ptr32<void> fn_80125FDC(Ptr32<void>,unsigned,int);
unsigned fn_8015F5A0(Ptr32<void>,int);
int fn_80162024(Ptr32<void>,Ptr32<unsigned short>,Ptr32<void>);
int fn_8016115C(Ptr32<void>,Ptr32<void>,Ptr32<void>,Ptr32<void (void)>,int,int);
int fn_801629F8(Ptr32<void>,Ptr32<void>,Ptr32<void>,Ptr32<void (void)>,int,int);
int fn_8015F518(Ptr32<void>,Ptr32<const char>);
int fn_802EEE50(Ptr32<void>,Ptr32<const void>,unsigned,...);
int fn_802EF234(Ptr32<const char>,Ptr32<const char>);
Ptr32<void> fn_8020BB54(Ptr32<void>,Ptr32<const char>);
int fn_8020C5C4(Ptr32<void>);
int fn_80341588(Ptr32<void>);
Ptr32<void> fn_80212FD4(unsigned);
void fn_802134FC(Ptr32<void>);
Ptr32<void> fn_80164FC8(Ptr32<void>);
int fn_80181640(Ptr32<void>,int,Ptr32<void>,int,float,float,float);
int fn_80181CCC(Ptr32<void>,int);
int fn_801817E0(Ptr32<void>,int);
extern Ptr32<void> lbl_804B1754;
extern Ptr32<void> lbl_804B1788;
extern char lbl_8040DB38[];

M2C_UNK fn_80160038(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>, Ptr32<M2C_UNK>, Ptr32<M2C_UNK>, M2C_UNK, M2C_UNK); /* extern */
Ptr32<void> fn_8009FEB8(void);
extern M2C_UNK lbl_803606C0[];
extern M2C_UNK lbl_803617D0[];
extern s8 lbl_80380930[];
extern s8 lbl_80380944[];
extern s8 lbl_8038095C[];
extern s8 lbl_80380974[];
extern s8 lbl_8038098C[];
extern s8 lbl_803809A0[];
extern s8 lbl_803809BC[];
extern s8 lbl_803809D4[];
extern s8 lbl_803809F0[];
extern f32 lbl_80380A0C[];
extern f32 lbl_80380A10[];
extern M2C_UNK lbl_803E7DF8[];
extern s8_Vector lbl_80437D24[];
extern M2C_UNK lbl_804AE12C;
extern M2C_UNK lbl_804AE134;
extern M2C_UNK lbl_804AE13C;
extern M2C_UNK lbl_804AE144;
extern M2C_UNK lbl_804AE14C;
extern M2C_UNK lbl_804AE154;
extern M2C_UNK lbl_804AE15C;
extern M2C_UNK lbl_804AE164;
extern M2C_UNK lbl_804AE16C;

void s8_initialize_mesh_messages_800a1670(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        fn_80160038(&(*lbl_803606C0), &(*lbl_803E7DF8), &(*lbl_803617D0), &fn_8009FEB8, 9, 0);
        lbl_80437D24[0].x=5.0f;
        lbl_80437D24[0].y=10.0f;
        lbl_80437D24[0].z=10.0f;
        fn_8015F518(&lbl_804AE12C, &(*lbl_80380930));
        fn_8015F518(&lbl_804AE134, &(*lbl_80380944));
        fn_8015F518(&lbl_804AE13C, &(*lbl_8038095C));
        fn_8015F518(&lbl_804AE144, &(*lbl_80380974));
        fn_8015F518(&lbl_804AE14C, &(*lbl_8038098C));
        fn_8015F518(&lbl_804AE154, &(*lbl_803809A0));
        fn_8015F518(&lbl_804AE15C, &(*lbl_803809BC));
        fn_8015F518(&lbl_804AE164, &(*lbl_803809D4));
        fn_8015F518(&lbl_804AE16C, &(*lbl_803809F0));
    }
}

}
