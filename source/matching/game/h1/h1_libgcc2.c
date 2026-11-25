/* GCC 2.95 libgcc2 routines linked into the SN runtime (session b169b320):
 * global constructor startup (__do_global_ctors, __main) and 64-bit
 * shift and compare helpers. Written in the shape of libgcc2.c and
 * gbl-ctors.h; SN's __do_global_ctors registers no atexit destructor. */

typedef int w3d_word_type;
typedef int w3d_si;
typedef unsigned int w3d_usi;
typedef long long w3d_di;

struct w3d_di_struct
{
    w3d_si high, low;                    /* big-endian */
};

typedef union
{
    struct w3d_di_struct s;
    w3d_di ll;
} w3d_di_union;

typedef void (*w3d_func_ptr)(void);

extern w3d_func_ptr w3d_ctor_list_8035f3e0[];
/* __main's static flag lives in .bss, not small data. */
extern int w3d_main_initialized_8047dd1c[];

void __do_global_ctors(void)
{
    do {
        unsigned long nptrs = (unsigned long)w3d_ctor_list_8035f3e0[0];
        unsigned i;
        if (nptrs == (unsigned long)-1)
            for (nptrs = 0; w3d_ctor_list_8035f3e0[nptrs + 1] != 0; nptrs++)
                ;
        for (i = nptrs; i >= 1; i--)
            w3d_ctor_list_8035f3e0[i]();
    } while (0);
}

void __main(void)
{
    if (!w3d_main_initialized_8047dd1c[0]) {
        w3d_main_initialized_8047dd1c[0] = 1;
        __do_global_ctors();
    }
}

w3d_di __ashldi3(w3d_di u, w3d_word_type b)
{
    w3d_di_union w;
    w3d_word_type bm;
    w3d_di_union uu;

    if (b == 0)
        return u;

    uu.ll = u;

    bm = (sizeof(w3d_si) * 8) - b;
    if (bm <= 0) {
        w.s.low = 0;
        w.s.high = (w3d_usi)uu.s.low << -bm;
    } else {
        w3d_usi carries = (w3d_usi)uu.s.low >> bm;
        w.s.low = (w3d_usi)uu.s.low << b;
        w.s.high = ((w3d_usi)uu.s.high << b) | carries;
    }

    return w.ll;
}

w3d_di __ashrdi3(w3d_di u, w3d_word_type b)
{
    w3d_di_union w;
    w3d_word_type bm;
    w3d_di_union uu;

    if (b == 0)
        return u;

    uu.ll = u;

    bm = (sizeof(w3d_si) * 8) - b;
    if (bm <= 0) {
        /* w.s.high = 1..1 or 0..0 */
        w.s.high = uu.s.high >> (sizeof(w3d_si) * 8 - 1);
        w.s.low = uu.s.high >> -bm;
    } else {
        w3d_usi carries = (w3d_usi)uu.s.high << bm;
        w.s.high = uu.s.high >> b;
        w.s.low = ((w3d_usi)uu.s.low >> b) | carries;
    }

    return w.ll;
}

w3d_word_type __cmpdi2(w3d_di a, w3d_di b)
{
    w3d_di_union au, bu;

    au.ll = a, bu.ll = b;

    if (au.s.high < bu.s.high)
        return 0;
    else if (au.s.high > bu.s.high)
        return 2;
    if ((w3d_usi)au.s.low < (w3d_usi)bu.s.low)
        return 0;
    else if ((w3d_usi)au.s.low > (w3d_usi)bu.s.low)
        return 2;
    return 1;
}
