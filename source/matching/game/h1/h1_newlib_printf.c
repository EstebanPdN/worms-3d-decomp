/* newlib 1.10.0 printf family over SN's vfprintf (0x802f06c8)
 * (session b169b320): fprintf, printf, sprintf, vsprintf and SN's own
 * vsnprintf. String output uses a stack FILE in string mode. */
#include <stdarg.h>
#include <sn-inline-stdarg.h>

struct _reent;

/* newlib FILE (struct __sFILE), only the fields used here are named. */
typedef struct W3dFile
{
    unsigned char *p;            /* 0x00 current position */
    int r;                       /* 0x04 read space left */
    int w;                       /* 0x08 write space left */
    short flags;                 /* 0x0c */
    short file;                  /* 0x0e */
    unsigned char *buffer_base;  /* 0x10 _bf._base */
    int buffer_size;             /* 0x14 _bf._size */
    unsigned char unknown_18[68];
    struct _reent *data;         /* 0x5c */
} W3dFile;

typedef struct W3dReentStd
{
    unsigned char unknown_00[8];
    W3dFile *stdout_file;        /* 0x08 _stdout */
} W3dReentStd;

#define W3D_SWR 0x0008
#define W3D_SSTR 0x0200
#define W3D_INT_MAX 0x7fffffff

extern W3dReentStd *w3d_sda_impure_ptr_804ac570;

int w3d_vfprintf_802f06c8(W3dFile *fp, const char *fmt, va_list ap);

int fprintf(W3dFile *fp, const char *fmt, ...)
{
    int ret;
    va_list ap;
    va_start(ap, fmt);
    ret = w3d_vfprintf_802f06c8(fp, fmt, ap);
    va_end(ap);
    return ret;
}

int printf(const char *fmt, ...)
{
    int ret;
    va_list ap;
    va_start(ap, fmt);
    w3d_sda_impure_ptr_804ac570->stdout_file->data = (struct _reent *)w3d_sda_impure_ptr_804ac570;
    ret = w3d_vfprintf_802f06c8(w3d_sda_impure_ptr_804ac570->stdout_file, fmt, ap);
    va_end(ap);
    return ret;
}

int sprintf(char *str, const char *fmt, ...)
{
    int ret;
    va_list ap;
    W3dFile f;
    f.flags = W3D_SWR | W3D_SSTR;
    f.buffer_base = f.p = (unsigned char *)str;
    f.buffer_size = f.w = W3D_INT_MAX;
    f.data = (struct _reent *)w3d_sda_impure_ptr_804ac570;
    va_start(ap, fmt);
    ret = w3d_vfprintf_802f06c8(&f, fmt, ap);
    va_end(ap);
    *f.p = 0;
    return ret;
}

int vsprintf(char *str, const char *fmt, va_list ap)
{
    int ret;
    W3dFile f;
    f.flags = W3D_SWR | W3D_SSTR;
    f.buffer_base = f.p = (unsigned char *)str;
    f.buffer_size = f.w = W3D_INT_MAX;
    f.data = (struct _reent *)w3d_sda_impure_ptr_804ac570;
    ret = w3d_vfprintf_802f06c8(&f, fmt, ap);
    *f.p = 0;
    return ret;
}

int vsnprintf(char *str, unsigned int size, const char *fmt, va_list ap)
{
    int ret;
    W3dFile f;
    f.flags = W3D_SWR | W3D_SSTR;
    f.buffer_base = f.p = (unsigned char *)str;
    f.buffer_size = f.w = size;
    f.data = (struct _reent *)w3d_sda_impure_ptr_804ac570;
    ret = w3d_vfprintf_802f06c8(&f, fmt, ap);
    *f.p = 0;
    if ((unsigned int)ret > size)
        ret = -1;
    return ret;
}
