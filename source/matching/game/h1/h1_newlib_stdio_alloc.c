/* SN versions of newlib 1.10.0 __sfp (findfp.c) and __smakebuf (makebuf.c)
 * (session b169b320). SN's stdio never mallocs stream buffers: __sfp takes
 * a preallocated buffer from a table of {base, size} slots in small data
 * (indexed by the slot's position in the 10-entry static glue block) or
 * falls back to the one-byte unbuffered buffer, and __smakebuf only
 * classifies the file and makes the stream unbuffered. */

struct W3dReent;

typedef struct W3dBuf
{
    unsigned char *base;
    int size;
} W3dBuf;

typedef struct W3dFile
{
    unsigned char *p;                    /* 0x00 */
    int r;                               /* 0x04 */
    int w;                               /* 0x08 */
    short flags;                         /* 0x0c */
    short file;                          /* 0x0e */
    W3dBuf bf;                           /* 0x10 */
    int lbfsize;                         /* 0x18 */
    void *cookie;                        /* 0x1c */
    void *read;                          /* 0x20 */
    void *write;                         /* 0x24 */
    long (*seek)(void *cookie, long offset, int whence); /* 0x28 */
    void *close;                         /* 0x2c */
    W3dBuf ub;                           /* 0x30 ungetc buffer */
    unsigned char unknown_38[18];
    unsigned char nbuf[1];               /* 0x4a unbuffered byte */
    unsigned char unknown_4b[1];
    W3dBuf lb;                           /* 0x4c line buffer */
    int blksize;                         /* 0x54 */
    long offset;                         /* 0x58 */
    struct W3dReent *data;               /* 0x5c */
} W3dFile;

typedef struct W3dGlue W3dGlue;
struct W3dGlue
{
    W3dGlue *next;
    int count;
    W3dFile *files;
};

typedef struct W3dReent
{
    int errno_value;                     /* 0x000 */
    unsigned char unknown_004[52];
    int did_init;                        /* 0x038 __sdidinit */
    void *cleanup;                       /* 0x03c */
    unsigned char unknown_040[408];
    W3dGlue glue;                        /* 0x1d8 __sglue */
} W3dReent;

typedef struct W3dStat
{
    short dev;
    unsigned short ino;
    unsigned int mode;                   /* 0x04 st_mode */
    unsigned char unknown_08[52];
} W3dStat;

#define W3D_SNBF 0x0002
#define W3D_SMBF 0x0080
#define W3D_SOPT 0x0400
#define W3D_SNPT 0x0800
#define W3D_S_IFMT 0xf000
#define W3D_S_IFREG 0x8000

extern W3dGlue w3d_extra_glue_8047db90;
extern W3dFile w3d_extra_files_8047d7d0[10];
extern W3dBuf *w3d_sda_stream_buffers_804ac578;

void __sinit(W3dReent *s);
int _fstat_r(W3dReent *ptr, int fd, W3dStat *st);
long __sseek(void *cookie, long offset, int whence);

W3dFile *__sfp(W3dReent *d)
{
    W3dFile *fp;
    int n;
    W3dGlue *g;
    int i;

    if (!d->did_init)
        __sinit(d);
    if (d->glue.next == 0) {
        w3d_extra_glue_8047db90.next = 0;
        w3d_extra_glue_8047db90.count = 10;
        w3d_extra_glue_8047db90.files = w3d_extra_files_8047d7d0;
        d->glue.next = &w3d_extra_glue_8047db90;
    }
    for (g = &d->glue;; g = g->next)
        for (fp = g->files, n = g->count; --n >= 0; fp++)
            if (fp->flags == 0)
                goto found;
found:
    i = 9 - n;
    fp->flags = 1;
    fp->w = 0;
    fp->r = 0;
    if (w3d_sda_stream_buffers_804ac578[i].size > 0 && w3d_sda_stream_buffers_804ac578[i].base != 0) {
        fp->bf = w3d_sda_stream_buffers_804ac578[i];
        fp->p = w3d_sda_stream_buffers_804ac578[i].base;
        fp->flags = W3D_SMBF | 1;
    } else {
        fp->flags |= W3D_SNBF;
        fp->bf.base = fp->p = fp->nbuf;
        fp->bf.size = 1;
    }
    fp->lbfsize = 0;
    fp->file = -1;
    fp->ub.base = 0;
    fp->ub.size = 0;
    fp->lb.base = 0;
    fp->lb.size = 0;
    fp->data = d;
    return fp;
}

void __smakebuf(W3dFile *fp)
{
    W3dStat st;

    if (fp->flags & W3D_SNBF) {
        fp->bf.base = fp->p = fp->nbuf;
        fp->bf.size = 1;
        return;
    }
    if (fp->file < 0 || _fstat_r(fp->data, fp->file, &st) < 0)
        fp->flags |= W3D_SNPT;
    else if ((st.mode & W3D_S_IFMT) == W3D_S_IFREG && fp->seek == __sseek) {
        fp->flags |= W3D_SOPT;
        fp->blksize = 1024;
    } else
        fp->flags |= W3D_SNPT;
    fp->flags |= W3D_SNBF;
    fp->bf.base = fp->p = fp->nbuf;
    fp->bf.size = 1;
}
