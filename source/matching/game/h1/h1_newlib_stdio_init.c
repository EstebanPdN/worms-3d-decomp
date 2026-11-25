/* SN versions of newlib 1.10.0 __sflags (flags.c) and __sinit (findfp.c)
 * (session b169b320). SN's __sflags has no 'b'/'t' handling and its own
 * O_* values; SN's __sinit chains a static block of 10 more FILEs after
 * the three standard streams. */

typedef struct W3dFile
{
    unsigned char unknown_00[96];
} W3dFile;

typedef struct W3dGlue W3dGlue;
struct W3dGlue
{
    W3dGlue *next;
    int count;
    W3dFile *files;
};

typedef struct W3dReent W3dReent;
struct W3dReent
{
    int errno_value;                     /* 0x000 _errno */
    unsigned char unknown_004[52];
    int did_init;                        /* 0x038 __sdidinit */
    void (*cleanup)(W3dReent *ptr);      /* 0x03c __cleanup */
    unsigned char unknown_040[408];
    W3dGlue glue;                        /* 0x1d8 __sglue */
    W3dFile standard_files[3];           /* 0x1e4 __sf */
};

#define W3D_SRD 0x0004
#define W3D_SWR 0x0008
#define W3D_SAPP 0x0100
#define W3D_SRW 0x0010
#define W3D_SLBF 0x0001
#define W3D_SNBF 0x0002
#define W3D_EINVAL 22

extern W3dGlue w3d_extra_glue_8047db90;
extern W3dFile w3d_extra_files_8047d7d0[10];

void w3d_stream_walk_all_802eb4e4(W3dReent *ptr);
void w3d_newlib_std_802eb178(W3dFile *ptr, int flags, int file, W3dReent *data);

int __sflags(W3dReent *ptr, const char *mode, int *optr)
{
    int ret, m, o;
    switch ((signed char)mode[0]) {
    case 'r':
        ret = W3D_SRD;
        m = 0;
        o = 0;
        break;
    case 'w':
        ret = W3D_SWR;
        m = 1;
        o = 0x600;
        break;
    case 'a':
        ret = W3D_SWR | W3D_SAPP;
        m = 1;
        o = 0x208;
        break;
    default:
        ptr->errno_value = W3D_EINVAL;
        return 0;
    }
    if (mode[1] == '+' || mode[2] == '+') {
        ret = W3D_SRW;
        m = 2;
    }
    *optr = m | o;
    return ret;
}

void __sinit(W3dReent *s)
{
    s->cleanup = w3d_stream_walk_all_802eb4e4;
    s->did_init = 1;
    w3d_newlib_std_802eb178(s->standard_files + 0, W3D_SRD, 0, s);
    w3d_newlib_std_802eb178(s->standard_files + 1, W3D_SWR | W3D_SLBF, 1, s);
    w3d_newlib_std_802eb178(s->standard_files + 2, W3D_SWR | W3D_SNBF, 2, s);
    s->glue.next = &w3d_extra_glue_8047db90;
    s->glue.count = 3;
    s->glue.files = &s->standard_files[0];
    w3d_extra_glue_8047db90.next = 0;
    w3d_extra_glue_8047db90.count = 10;
    w3d_extra_glue_8047db90.files = w3d_extra_files_8047d7d0;
}
