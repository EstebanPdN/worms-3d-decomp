/* More GCC 2.95 libgcc2 routines (session b169b320): 64-bit logical shift,
 * double <-> 64-bit conversions, and the single-threaded exception-context
 * and terminate hooks used by the C++ runtime. Written in the shape of
 * libgcc2.c. */

typedef int w3d_word_type;
typedef int w3d_si;
typedef unsigned int w3d_usi;
typedef long long w3d_di;
typedef unsigned long long w3d_udi;

struct w3d_di_struct
{
    w3d_si high, low;                    /* big-endian */
};

typedef union
{
    struct w3d_di_struct s;
    w3d_di ll;
} w3d_di_union;

#define W3D_WORD_SIZE 32
#define W3D_HIGH_HALFWORD_COEFF (((w3d_udi)1) << (W3D_WORD_SIZE / 2))
#define W3D_HIGH_WORD_COEFF (((w3d_udi)1) << W3D_WORD_SIZE)

/* struct eh_context (libgcc2.c); only the handler chain is named. */
typedef struct W3dEhContext
{
    void *handler_label;
    void **dynamic_handler_chain;
    void *info;
    void *table_index;
} W3dEhContext;

/* SN's libgcc build compares against a single-precision 0.0 pool entry. */
extern const float w3d_float_zero_803e7010[];
extern void (*w3d_terminate_func_80404b70[])(void);
extern W3dEhContext *(*w3d_get_eh_context_80404b74[])(void);
extern W3dEhContext w3d_eh_static_8047dd20[];
extern int w3d_eh_initialized_8047dd30[];
extern void *w3d_eh_top_elt_8047dd34[];   /* void *top_elt[2], in .bss */

void *memset();

w3d_di __lshrdi3(w3d_di u, w3d_word_type b)
{
    w3d_di_union w;
    w3d_word_type bm;
    w3d_di_union uu;

    if (b == 0)
        return u;

    uu.ll = u;

    bm = (sizeof(w3d_si) * 8) - b;
    if (bm <= 0) {
        w.s.high = 0;
        w.s.low = (w3d_usi)uu.s.high >> -bm;
    } else {
        w3d_usi carries = (w3d_usi)uu.s.high << bm;
        w.s.high = (w3d_usi)uu.s.high >> b;
        w.s.low = ((w3d_usi)uu.s.low >> b) | carries;
    }

    return w.ll;
}

w3d_udi __fixunsdfdi(double a)
{
    double b;
    w3d_udi v;
    if (a < 0)
        return 0;
    b = (a / W3D_HIGH_WORD_COEFF);
    v = (w3d_usi)b;
    v <<= W3D_WORD_SIZE;
    a -= (double)v;
    if (a < 0)
        v -= (w3d_usi)(-a);
    else
        v += (w3d_usi)a;
    return v;
}

w3d_di __fixdfdi(double a)
{
    if (a < w3d_float_zero_803e7010[0])
        return -__fixunsdfdi(-a);
    return __fixunsdfdi(a);
}

double __floatdidf(w3d_di u)
{
    double d;

    d = (w3d_si)(u >> W3D_WORD_SIZE);
    d *= W3D_HIGH_HALFWORD_COEFF;
    d *= W3D_HIGH_HALFWORD_COEFF;
    d += (w3d_usi)(u & (W3D_HIGH_WORD_COEFF - 1));

    return d;
}

void __terminate(void)
{
    (*w3d_terminate_func_80404b70[0])();
}

void w3d_terminate_forward_802f4440(void)
{
    __terminate();
}

W3dEhContext *w3d_eh_context_static_802f4e4c(void)
{
    if (!w3d_eh_initialized_8047dd30[0]) {
        w3d_eh_initialized_8047dd30[0] = 1;
        memset(w3d_eh_static_8047dd20, 0, sizeof(W3dEhContext));
        w3d_eh_static_8047dd20[0].dynamic_handler_chain = w3d_eh_top_elt_8047dd34;
    }
    return w3d_eh_static_8047dd20;
}

W3dEhContext *w3d_eh_context_initialize_802f4e18(void)
{
    w3d_get_eh_context_80404b74[0] = w3d_eh_context_static_802f4e4c;
    return (*w3d_get_eh_context_80404b74[0])();
}
