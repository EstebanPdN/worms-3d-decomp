/* s8 range recovery: ordinary C, compiled against the reference ProDG route. */
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

extern void *lbl_804B1754;
extern void *lbl_804B1788;
extern char lbl_8040DB38[];
M2C_UNK fn_80160038(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK lbl_80361050[];
extern M2C_UNK lbl_803617D0[];
extern M2C_UNK lbl_803E838C[];
extern s8 lbl_804AF15A;
extern s8 lbl_804AF159;
extern s8 lbl_804AF158;
extern s8 lbl_804AF15B;

/* Inferred prototypes supported by existing matched callers and original register use. */
void *fn_80341584(void *);
void *fn_80343584(void *);
void *fn_803426B4(void *);
void *fn_80343744(void *);
void *fn_80179598(void *,int);
void *fn_801797B4(void *);
int fn_80178C48(void *);
void *fn_801613F0(void *,int);
int fn_8016239C(void *);
int fn_8015FC58(void *,void *);
void *fn_800C1620(void *,int *);
void *fn_80125FDC(void *,unsigned,int);
unsigned fn_8015F5A0(void *,int);
int fn_80162024(void *,unsigned short *,void *);
int fn_8016115C(void *,void *,void *,void (*)(void),int,int);
int fn_801629F8(void *,void *,void *,void (*)(void),int,int);
int fn_8015F518(void *,const char *);
int fn_802EEE50(void *,const void *,unsigned,...);
int fn_802EF234(const char *,const char *);
void *fn_8020BB54(void *,const char *);
int fn_8020C5C4(void *);
int fn_80341588(void *);
void *fn_80212FD4(unsigned);
void fn_802134FC(void *);
void *fn_80164FC8(void *);
int fn_80181640(void *,int,void *,int,float,float,float);
int fn_80181CCC(void *,int);
int fn_801817E0(void *,int);

void * fn_800FE820(void);

void s8_bound_800ffa84(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        fn_80160038(&(*lbl_80361050), &(*lbl_803E838C), &(*lbl_803617D0), &fn_800FE820, 9, 0);
        lbl_804AF158 = -1;
        lbl_804AF159 = -1;
        lbl_804AF15A = -1;
        lbl_804AF15B = -0x38;
    }
}
