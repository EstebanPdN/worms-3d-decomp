/* newlib-style wrappers around SN's own (non-stock) stdio and strtod bodies
 * (session b169b320). 0x802eb3c8 is _fopen_r: it parses the mode with
 * __sflags, takes a stream with __sfp and opens the file with _open_r(0666). */

struct _reent;
typedef struct W3dFile W3dFile;

extern struct _reent *w3d_sda_impure_ptr_804ac570;

W3dFile *w3d_fopen_r_802eb3c8(struct _reent *ptr, const char *file, const char *mode);
double w3d_strtod_802ee800(const char *s, char **ptr);

W3dFile *fopen(const char *file, const char *mode)
{
    return w3d_fopen_r_802eb3c8(w3d_sda_impure_ptr_804ac570, file, mode);
}

double atof(const char *s)
{
    return w3d_strtod_802ee800(s, 0);
}
