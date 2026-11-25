/* newlib 1.10.0 stdio core and reentrant system-call wrappers
 * (session b169b320): std (findfp.c), __sread/__swrite/__sseek/__sclose
 * (stdio.c), _fwalk (fwalk.c) and _close_r/_fstat_r/_lseek_r/_read_r/
 * _write_r (reent/). The low-level calls go to SN's assembly syscall stubs
 * at 0x802e3294..0x802e3304. */

typedef struct W3dReent
{
    int errno_value;             /* 0x00 _errno */
} W3dReent;

typedef struct W3dFile W3dFile;

struct W3dFile
{
    unsigned char *p;            /* 0x00 */
    int r;                       /* 0x04 */
    int w;                       /* 0x08 */
    short flags;                 /* 0x0c */
    short file;                  /* 0x0e */
    unsigned char *buffer_base;  /* 0x10 _bf._base */
    int buffer_size;             /* 0x14 _bf._size */
    int line_buffer_size;        /* 0x18 _lbfsize */
    void *cookie;                /* 0x1c */
    int (*read)(void *cookie, char *buf, int n);
    int (*write)(void *cookie, const char *buf, int n);
    long (*seek)(void *cookie, long offset, int whence);
    int (*close)(void *cookie);
    unsigned char unknown_30[40];
    long offset;                 /* 0x58 _offset */
    W3dReent *data;              /* 0x5c */
};

typedef struct W3dGlue W3dGlue;
struct W3dGlue
{
    W3dGlue *next;
    int count;
    W3dFile *files;
};

typedef struct W3dReentGlue
{
    unsigned char unknown_00[472];
    W3dGlue glue;                /* 0x1d8 __sglue */
} W3dReentGlue;

#define W3D_SAPP 0x0100
#define W3D_SOFF 0x1000
#define W3D_SEEK_END 2

extern int w3d_sda_errno_804b1910;

int w3d_auto_802e32b4(int fd);
int w3d_auto_802e32d4();
long w3d_auto_802e32e4(int fd, long pos, int whence);
int w3d_auto_802e3304(int fd, void *buf, unsigned int cnt);
int w3d_auto_802e3294(int fd, const void *buf, unsigned int cnt);

int __sread(void *cookie, char *buf, int n);
int __swrite(void *cookie, const char *buf, int n);
long __sseek(void *cookie, long offset, int whence);
int __sclose(void *cookie);

int _close_r(W3dReent *ptr, int fd)
{
    int ret;
    w3d_sda_errno_804b1910 = 0;
    if ((ret = w3d_auto_802e32b4(fd)) == -1 && w3d_sda_errno_804b1910 != 0)
        ptr->errno_value = w3d_sda_errno_804b1910;
    return ret;
}

int _fstat_r(W3dReent *ptr, int fd, void *pstat)
{
    int ret;
    w3d_sda_errno_804b1910 = 0;
    if ((ret = w3d_auto_802e32d4(fd, pstat)) == -1 && w3d_sda_errno_804b1910 != 0)
        ptr->errno_value = w3d_sda_errno_804b1910;
    return ret;
}

long _lseek_r(W3dReent *ptr, int fd, long pos, int whence)
{
    long ret;
    w3d_sda_errno_804b1910 = 0;
    if ((ret = w3d_auto_802e32e4(fd, pos, whence)) == -1 && w3d_sda_errno_804b1910 != 0)
        ptr->errno_value = w3d_sda_errno_804b1910;
    return ret;
}

int _read_r(W3dReent *ptr, int fd, void *buf, unsigned int cnt)
{
    int ret;
    w3d_sda_errno_804b1910 = 0;
    if ((ret = w3d_auto_802e3304(fd, buf, cnt)) == -1 && w3d_sda_errno_804b1910 != 0)
        ptr->errno_value = w3d_sda_errno_804b1910;
    return ret;
}

int _write_r(W3dReent *ptr, int fd, const void *buf, unsigned int cnt)
{
    int ret;
    w3d_sda_errno_804b1910 = 0;
    if ((ret = w3d_auto_802e3294(fd, buf, cnt)) == -1 && w3d_sda_errno_804b1910 != 0)
        ptr->errno_value = w3d_sda_errno_804b1910;
    return ret;
}

int __sread(void *cookie, char *buf, int n)
{
    W3dFile *fp = (W3dFile *)cookie;
    int ret;
    ret = _read_r(fp->data, fp->file, buf, n);
    if (ret >= 0)
        fp->offset += ret;
    else
        fp->flags &= ~W3D_SOFF;
    return ret;
}

int __swrite(void *cookie, const char *buf, int n)
{
    W3dFile *fp = (W3dFile *)cookie;
    int w;
    if (fp->flags & W3D_SAPP)
        (void)_lseek_r(fp->data, fp->file, 0, W3D_SEEK_END);
    fp->flags &= ~W3D_SOFF;
    w = _write_r(fp->data, fp->file, buf, n);
    return w;
}

long __sseek(void *cookie, long offset, int whence)
{
    W3dFile *fp = (W3dFile *)cookie;
    long ret;
    ret = _lseek_r(fp->data, fp->file, offset, whence);
    if (ret == -1L)
        fp->flags &= ~W3D_SOFF;
    else {
        fp->flags |= W3D_SOFF;
        fp->offset = ret;
    }
    return ret;
}

int __sclose(void *cookie)
{
    W3dFile *fp = (W3dFile *)cookie;
    return _close_r(fp->data, fp->file);
}

int _fwalk(W3dReentGlue *ptr, int (*function)())
{
    W3dFile *fp;
    int n, ret = 0;
    W3dGlue *g;
    for (g = &ptr->glue; g != 0; g = g->next)
        for (fp = g->files, n = g->count; --n >= 0; fp++)
            if (fp->flags != 0)
                ret |= (*function)(fp);
    return ret;
}

void w3d_newlib_std_802eb178(W3dFile *ptr, int flags, int file, W3dReent *data)
{
    ptr->p = 0;
    ptr->r = 0;
    ptr->w = 0;
    ptr->flags = flags;
    ptr->file = file;
    ptr->buffer_base = 0;
    /* SN's std leaves _bf._size alone (stock newlib clears it). */
    ptr->line_buffer_size = 0;
    ptr->cookie = ptr;
    ptr->read = __sread;
    ptr->write = __swrite;
    ptr->seek = __sseek;
    ptr->close = __sclose;
    ptr->data = data;
}
