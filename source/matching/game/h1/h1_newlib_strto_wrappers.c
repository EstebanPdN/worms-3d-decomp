/* newlib 1.10.0 non-reentrant number-parsing wrappers (session b169b320).
 * strtoul/strtol sit directly after their admitted _r bodies, as they do in
 * newlib's stdlib/strtoul.c and stdlib/strtol.c; atoi and atol follow in
 * archive order. Each forwards to the reentrant routine with _impure_ptr. */

struct _reent;

extern struct _reent *w3d_sda_impure_ptr_804ac570;

unsigned long _strtoul_r(struct _reent *rptr, const char *s, char **ptr, int base);
long _strtol_r(struct _reent *rptr, const char *s, char **ptr, int base);

unsigned long strtoul(const char *s, char **ptr, int base)
{
    return _strtoul_r(w3d_sda_impure_ptr_804ac570, s, ptr, base);
}

long strtol(const char *s, char **ptr, int base)
{
    return _strtol_r(w3d_sda_impure_ptr_804ac570, s, ptr, base);
}

int atoi(const char *s)
{
    return (int)strtol(s, 0, 10);
}

long atol(const char *s)
{
    return strtol(s, 0, 10);
}
