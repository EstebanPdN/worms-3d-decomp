/* SN versions of newlib 1.10.0 fflush and fclose (session b169b320).
 * Both bind a stream without a reentrancy pointer to _impure_ptr and run
 * __sinit on it (called without a prototype in scope); fclose never frees
 * buffers because SN's stdio does not allocate them. */

typedef struct W3dReent
{
    unsigned char unknown_00[56];
    int did_init;                        /* 0x38 __sdidinit */
} W3dReent;

typedef struct W3dFile W3dFile;
struct W3dFile
{
    unsigned char *p;                    /* 0x00 */
    int r;                               /* 0x04 */
    int w;                               /* 0x08 */
    short flags;                         /* 0x0c */
    short file;                          /* 0x0e */
    unsigned char *buffer_base;          /* 0x10 _bf._base */
    int buffer_size;                     /* 0x14 _bf._size */
    int lbfsize;                         /* 0x18 */
    void *cookie;                        /* 0x1c */
    int (*read)(void *cookie, char *buf, int n);
    int (*write)(void *cookie, const char *buf, int n);
    long (*seek)(void *cookie, long offset, int whence);
    int (*close)(void *cookie);          /* 0x2c */
    unsigned char unknown_30[44];
    W3dReent *data;                      /* 0x5c */
};

#define W3D_SLBF 0x0001
#define W3D_SNBF 0x0002
#define W3D_SWR 0x0008
#define W3D_SERR 0x0040
#define W3D_EOF (-1)

extern W3dReent *w3d_sda_impure_ptr_804ac570;

/* newlib-style statement macros; their do/while(0) shape affects GCC's
 * register allocation in fflush. */
#define W3D_REENT_CHECK(fp) \
    do { if ((fp)->data == 0) (fp)->data = w3d_sda_impure_ptr_804ac570; } while (0)
#define W3D_CHECK_INIT(fp) \
    do { if (!(fp)->data->did_init) __sinit((fp)->data); } while (0)

void __sinit();
int _fwalk(W3dReent *ptr, int (*function)(W3dFile *));

int fflush(W3dFile *fp)
{
    unsigned char *p;
    int n, t;

    if (fp == 0)
        return _fwalk(w3d_sda_impure_ptr_804ac570, fflush);
    W3D_REENT_CHECK(fp);
    W3D_CHECK_INIT(fp);
    t = fp->flags;
    if ((t & W3D_SWR) == 0 || (p = fp->buffer_base) == 0)
        return 0;
    n = fp->p - p;
    fp->p = p;
    fp->w = t & (W3D_SLBF | W3D_SNBF) ? 0 : fp->buffer_size;
    while (n > 0) {
        t = (*fp->write)(fp->cookie, (char *)p, n);
        if (t <= 0) {
            fp->flags |= W3D_SERR;
            return W3D_EOF;
        }
        p += t;
        n -= t;
    }
    return 0;
}

int fclose(W3dFile *fp)
{
    int r;

    if (fp == 0)
        return 0;
    W3D_REENT_CHECK(fp);
    W3D_CHECK_INIT(fp);
    if (fp->flags == 0)
        return 0;
    r = fp->flags & W3D_SWR ? fflush(fp) : 0;
    if (fp->close != 0 && (*fp->close)(fp->cookie) < 0)
        r = W3D_EOF;
    fp->flags = 0;
    return r;
}
