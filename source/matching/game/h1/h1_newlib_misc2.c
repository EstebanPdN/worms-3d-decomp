/* More small newlib 1.10.0 / SN runtime routines (session b169b320):
 * the environment lock stubs and getenv,
 * vfiprintf, and a few SN stdio helpers. */

struct _reent;
typedef struct W3dStream
{
    unsigned char unknown_00[92];
    struct _reent *data;
} W3dStream;

extern struct _reent *w3d_sda_impure_ptr_804ac570;

char *_findenv_r();
int w3d_vfiprintf_r_802f1cf4();
int w3d_stream_walk_802ebe64(struct _reent *ptr, int (*function)(W3dStream *));
int w3d_stream_flush_802eb084(W3dStream *fp);
double w3d_libm_body_802e9850(double x);

void __env_lock(struct _reent *ptr)
{
}

void __env_unlock(struct _reent *ptr)
{
}

char *getenv(const char *name)
{
    int offset;
    return _findenv_r(w3d_sda_impure_ptr_804ac570, name, &offset);
}

int vfiprintf(W3dStream *fp, const char *fmt, void *ap)
{
    return w3d_vfiprintf_r_802f1cf4(fp->data, fp, fmt, ap);
}

void w3d_stream_walk_all_802eb4e4(struct _reent *ptr)
{
    w3d_stream_walk_802ebe64(ptr, w3d_stream_flush_802eb084);
}

int w3d_stream_flush_forward_802ec068(W3dStream *fp)
{
    return w3d_stream_flush_802eb084(fp);
}

void w3d_copy_bytes_802eb5f8(unsigned char *dst, const unsigned char *src, int count)
{
    while (count-- != 0)
        *dst++ = *src++;
}

int w3d_stdio_zero_802ec32c(void)
{
    return 0;
}

int w3d_stdio_zero_802efe6c(void)
{
    return 0;
}

double w3d_libm_forward_802e83cc(double x)
{
    return w3d_libm_body_802e9850(x);
}
