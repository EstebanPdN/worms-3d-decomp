/* SN versions of newlib 1.10.0 stdio input and setup routines
 * (session b169b320): __srefill (refill.c), fread, ungetc, __swsetup
 * (wsetup.c) and sscanf. SN's stdio never frees or grows buffers: the
 * ungetc buffer is the 10-byte array inside the FILE and overflowing it
 * prints a message; fread copies with SN's byte-copy helper. */
#include <stdarg.h>
#include <sn-inline-stdarg.h>

typedef struct W3dReent
{
    unsigned char unknown_00[56];
    int did_init;                        /* 0x38 __sdidinit */
} W3dReent;

typedef struct W3dBuf
{
    unsigned char *base;
    int size;
} W3dBuf;

typedef struct W3dFile W3dFile;
struct W3dFile
{
    unsigned char *p;                    /* 0x00 */
    int r;                               /* 0x04 */
    int w;                               /* 0x08 */
    short flags;                         /* 0x0c */
    short file;                          /* 0x0e */
    W3dBuf bf;                           /* 0x10 */
    int lbfsize;                         /* 0x18 */
    void *cookie;                        /* 0x1c */
    int (*read)(void *cookie, char *buf, int n); /* 0x20 */
    void *write;                         /* 0x24 */
    void *seek;                          /* 0x28 */
    void *close;                         /* 0x2c */
    W3dBuf ub;                           /* 0x30 ungetc buffer */
    unsigned char *up;                   /* 0x38 saved p during ungetc */
    int ur;                              /* 0x3c saved r during ungetc */
    unsigned char ubuf[10];              /* 0x40 */
    unsigned char nbuf[1];               /* 0x4a */
    unsigned char unknown_4b[1];
    W3dBuf lb;                           /* 0x4c */
    int blksize;                         /* 0x54 */
    long offset;                         /* 0x58 */
    W3dReent *data;                      /* 0x5c */
};

#define W3D_SLBF 0x0001
#define W3D_SNBF 0x0002
#define W3D_SRD 0x0004
#define W3D_SWR 0x0008
#define W3D_SRW 0x0010
#define W3D_SEOF 0x0020
#define W3D_SERR 0x0040
#define W3D_SMOD 0x2000
#define W3D_EOF (-1)

extern W3dReent *w3d_sda_impure_ptr_804ac570;
extern const char w3d_ungetc_overflow_text_803db57c[];

#define W3D_REENT_CHECK(fp) \
    do { if ((fp)->data == 0) (fp)->data = w3d_sda_impure_ptr_804ac570; } while (0)
#define W3D_CHECK_INIT(fp) \
    do { if (!(fp)->data->did_init) __sinit((fp)->data); } while (0)

void __sinit();
int fflush(W3dFile *fp);
void __smakebuf(W3dFile *fp);
int _fwalk(W3dReent *ptr, int (*function)(W3dFile *));
unsigned int strlen(const char *);
int w3d_stream_flush_forward_802ec068(W3dFile *fp);
void w3d_copy_bytes_802eb5f8(unsigned char *dst, const unsigned char *src, int count);
int w3d_auto_802e3294(int fd, const void *buf, unsigned int cnt);
int w3d_stdio_zero_802ec32c(void *cookie, char *buf, int n);
int w3d_svfscanf_802ec708(W3dFile *fp, const char *fmt, va_list ap);

int __srefill(W3dFile *fp)
{
    W3D_REENT_CHECK(fp);
    W3D_CHECK_INIT(fp);
    fp->r = 0;
    if (fp->flags & W3D_SEOF)
        return W3D_EOF;
    if ((fp->flags & W3D_SRD) == 0) {
        if ((fp->flags & W3D_SRW) == 0)
            return W3D_EOF;
        if (fp->flags & W3D_SWR) {
            if (fflush(fp))
                return W3D_EOF;
            fp->flags &= ~W3D_SWR;
            fp->w = 0;
            fp->lbfsize = 0;
        }
        fp->flags |= W3D_SRD;
    } else {
        if (fp->ub.base != 0) {
            if ((fp->r = fp->ur) != 0) {
                fp->p = fp->up;
                return 0;
            }
        }
    }
    if (fp->bf.base == 0)
        __smakebuf(fp);
    if (fp->flags & (W3D_SLBF | W3D_SNBF))
        (void)_fwalk(fp->data, w3d_stream_flush_forward_802ec068);
    fp->p = fp->bf.base;
    fp->r = (*fp->read)(fp->cookie, (char *)fp->p, fp->bf.size);
    fp->flags &= ~W3D_SMOD;
    if (fp->r <= 0) {
        if (fp->r == 0)
            fp->flags |= W3D_SEOF;
        else {
            fp->r = 0;
            fp->flags |= W3D_SERR;
        }
        return W3D_EOF;
    }
    return 0;
}

unsigned int fread(void *buf, unsigned int size, unsigned int count, W3dFile *fp)
{
    unsigned int resid;
    unsigned char *p;
    int r;
    unsigned int total;

    if ((resid = count * size) == 0)
        return 0;
    if (fp->r < 0)
        fp->r = 0;
    total = resid;
    p = (unsigned char *)buf;
    while (resid > (r = fp->r)) {
        w3d_copy_bytes_802eb5f8(p, fp->p, r);
        fp->p += r;
        p += r;
        resid -= r;
        if (__srefill(fp))
            return (total - resid) / size;
    }
    w3d_copy_bytes_802eb5f8(p, fp->p, resid);
    fp->r -= resid;
    fp->p += resid;
    return count;
}

int ungetc(int c, W3dFile *fp)
{
    if (c == W3D_EOF)
        return W3D_EOF;
    W3D_REENT_CHECK(fp);
    W3D_CHECK_INIT(fp);
    fp->flags &= ~W3D_SEOF;
    if ((fp->flags & W3D_SRD) == 0) {
        if ((fp->flags & W3D_SRW) == 0)
            return W3D_EOF;
        if (fp->flags & W3D_SWR) {
            if (fflush(fp))
                return W3D_EOF;
            fp->flags &= ~W3D_SWR;
            fp->w = 0;
            fp->lbfsize = 0;
        }
        fp->flags |= W3D_SRD;
    }
    c = (unsigned char)c;
    if (fp->ub.base != 0) {
        if (fp->r >= fp->ub.size) {
            w3d_auto_802e3294(1, w3d_ungetc_overflow_text_803db57c, 68);
            return W3D_EOF;
        }
        *--fp->p = c;
        fp->r++;
        return c;
    }
    if (fp->bf.base != 0 && fp->p > fp->bf.base && fp->p[-1] == c) {
        fp->p--;
        fp->r++;
        return c;
    }
    fp->ur = fp->r;
    fp->up = fp->p;
    fp->ub.base = fp->ubuf;
    fp->ub.size = sizeof(fp->ubuf);
    fp->ubuf[sizeof(fp->ubuf) - 1] = c;
    fp->p = &fp->ubuf[sizeof(fp->ubuf) - 1];
    fp->r = 1;
    return c;
}

int __swsetup(W3dFile *fp)
{
    W3D_REENT_CHECK(fp);
    W3D_CHECK_INIT(fp);
    if ((fp->flags & W3D_SWR) == 0) {
        if ((fp->flags & W3D_SRW) == 0)
            return W3D_EOF;
        if (fp->flags & W3D_SRD) {
            fp->flags &= ~(W3D_SRD | W3D_SEOF);
            fp->r = 0;
            fp->p = fp->bf.base;
        }
        fp->flags |= W3D_SWR;
    }
    if (fp->bf.base == 0)
        __smakebuf(fp);
    if (fp->flags & W3D_SLBF) {
        fp->w = 0;
        fp->lbfsize = -fp->bf.size;
    } else
        fp->w = fp->flags & W3D_SNBF ? 0 : fp->bf.size;
    return 0;
}

int sscanf(const char *str, const char *fmt, ...)
{
    int ret;
    va_list ap;
    W3dFile f;

    f.flags = W3D_SRD;
    f.bf.base = f.p = (unsigned char *)str;
    f.bf.size = f.r = strlen(str);
    f.read = w3d_stdio_zero_802ec32c;
    f.ub.base = 0;
    f.lb.base = 0;
    f.data = w3d_sda_impure_ptr_804ac570;
    va_start(ap, fmt);
    ret = w3d_svfscanf_802ec708(&f, fmt, ap);
    va_end(ap);
    return ret;
}
