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
extern "C" {
void **fn_8020B648();                               /* extern */
void **fn_8020B680(M2C_UNK *);                      /* extern */
void **fn_8020B884();                               /* extern */
M2C_UNK fn_8020B960(void **);                       /* extern */
M2C_UNK fn_8020BB54(M2C_UNK *, M2C_UNK *);          /* extern */
M2C_UNK fn_8020BD38(s32, M2C_UNK *);                /* extern */
M2C_UNK fn_8020C5C4(M2C_UNK *);                     /* extern */
M2C_UNK fn_80210958(M2C_UNK *);                     /* extern */
M2C_UNK fn_80341588(M2C_UNK *);                     /* extern */
extern M2C_UNK lbl_803A435C[];
extern M2C_UNK lbl_80419378[];

}
struct S9LifetimeString {
 int text; int unknown;
 S9LifetimeString(char *s){fn_8020BB54(&text,(int *)s);}
 S9LifetimeString(){fn_80210958(&text);}
 ~S9LifetimeString(){fn_8020C5C4(&text);fn_80341588(&text);}
};
extern "C" void s9_lifetime_probe_8015bf74(void *arg0, M2C_UNK *arg1) {
    void **temp_r29;
    void **temp_r30_2;
    void **temp_r3;
    void **temp_r3_2;
    void **temp_r3_3;
    void **temp_r3_4;
    void *temp_r29_2;
    void *temp_r29_3;
    void *temp_r30;

    temp_r29 = fn_8020B648();
    temp_r30 = *temp_r29;
    M2C_FIELD(temp_r30, void (**)(void **, const S9LifetimeString &), 0x4C)(temp_r29, S9LifetimeString((char *)arg1));
    fn_8020BD38((int)arg0 + 0xC, arg1);
    temp_r3 = fn_8020B680(&(*lbl_80419378));
    if (temp_r3 == NULL) {
        goto block_2;
    }
    M2C_FIELD(*temp_r3, M2C_UNK (**)(void **), 0xC)(temp_r3);
block_2:
    temp_r3_2 = M2C_FIELD(arg0, void ***, 0x10);
    if (temp_r3_2 == NULL) {
        goto block_4;
    }
    M2C_FIELD(*temp_r3_2, M2C_UNK (**)(void *), 0x10)(temp_r3_2);
block_4:
    M2C_FIELD(arg0, void ***, 0x10) = temp_r3;
    temp_r3_3 = fn_8020B884();
    if (temp_r3_3 == NULL) {
        goto block_6;
    }
    M2C_FIELD(*temp_r3_3, M2C_UNK (**)(void **), 0xC)(temp_r3_3);
block_6:
    temp_r3_4 = M2C_FIELD(arg0, void ***, 0x14);
    if (temp_r3_4 == NULL) {
        goto block_8;
    }
    M2C_FIELD(*temp_r3_4, M2C_UNK (**)(void *), 0x10)(temp_r3_4);
block_8:
    M2C_FIELD(arg0, void ***, 0x14) = temp_r3_3;
    const S9LifetimeString &persistent=S9LifetimeString();
    fn_8020B960(M2C_FIELD(arg0, void ***, 0x10));
    temp_r29_2 = M2C_FIELD(arg0, void **, 0);
    M2C_FIELD(temp_r29_2, void (**)(void *, const S9LifetimeString &), 0x14)(arg0, S9LifetimeString((char *)lbl_803A435C));
    temp_r30_2 = M2C_FIELD(arg0, void ***, 0x10);
    temp_r29_3 = *temp_r30_2;
    M2C_FIELD(temp_r29_3, M2C_UNK (**)(void **, s32), 0x34)(temp_r30_2, M2C_FIELD(temp_r29_3, s32 (**)(void **, M2C_UNK), 0x3C)(temp_r30_2, 0));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), M2C_UNK (**)(void *), 0x28)(arg0);

    return;
}
