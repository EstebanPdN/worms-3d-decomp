/* Small newlib 1.10.0 routines (session b169b320): rand.c, strcoll.c and
 * locale.c. Only the reentrancy fields these bodies touch are laid out. */

typedef struct W3dReent
{
    unsigned char unknown_00[88];
    unsigned long next;          /* rand() state, newlib _REENT->_next */
} W3dReent;

struct lconv;

extern W3dReent *w3d_sda_impure_ptr_804ac570;
extern struct lconv w3d_lconv_803dbdb4;

int strcmp(const char *, const char *);

void srand(unsigned int seed)
{
    w3d_sda_impure_ptr_804ac570->next = seed;
}

int rand(void)
{
    return (w3d_sda_impure_ptr_804ac570->next =
            w3d_sda_impure_ptr_804ac570->next * 1103515245 + 12345) & 0x7fffffff;
}

int strcoll(const char *a, const char *b)
{
    return strcmp(a, b);
}

struct lconv *_localeconv_r(W3dReent *data)
{
    return &w3d_lconv_803dbdb4;
}

struct lconv *localeconv(void)
{
    return _localeconv_r(w3d_sda_impure_ptr_804ac570);
}
