/* newlib 1.10.0 exit and fiprintf, SN's abort-style exit helpers and SN's
 * buffered console writers (session b169b320). vfprintf.c and vfiprintf.c
 * each carry their own copy of the console writer with its own 128-byte
 * buffer, fill count, flush size and write pointer. */
#include <stdarg.h>
#include <sn-inline-stdarg.h>

typedef struct W3dAtexit W3dAtexit;
struct W3dAtexit
{
    W3dAtexit *next;                     /* 0x00 */
    int count;                           /* 0x04 _ind */
    void (*functions[32])(void);         /* 0x08 _fns */
};

typedef struct W3dReent W3dReent;
struct W3dReent
{
    unsigned char unknown_000[60];
    void (*cleanup)(W3dReent *ptr);      /* 0x03c __cleanup */
    unsigned char unknown_040[264];
    W3dAtexit *atexit_list;              /* 0x148 _atexit */
};

typedef struct W3dFile W3dFile;

extern W3dReent *w3d_sda_impure_ptr_804ac570;

extern unsigned char w3d_vfprintf_console_buffer_8047dc1c[];
extern int w3d_sda_vfprintf_console_count_804ac580;
extern int w3d_sda_vfprintf_console_size_804ac584;
extern unsigned char *w3d_sda_vfprintf_console_next_804ac588;

extern unsigned char w3d_vfiprintf_console_buffer_8047dc9c[];
extern int w3d_sda_vfiprintf_console_count_804ac58c;
extern int w3d_sda_vfiprintf_console_size_804ac590;
extern unsigned char *w3d_sda_vfiprintf_console_next_804ac594;

/* abort calls _exit without a prototype in scope (crclr); exit has one. */
void _exit() __attribute__((noreturn));
int w3d_auto_802e3294(int fd, const void *buf, unsigned int cnt);
int vfiprintf(W3dFile *fp, const char *fmt, va_list ap);

void abort(void)
{
    _exit(1);
}

void w3d_abort_forward_802f4ddc(void)
{
    abort();
}

void _exit(int code) __attribute__((noreturn));

void exit(int code)
{
    W3dAtexit *p;
    int n;
    for (p = w3d_sda_impure_ptr_804ac570->atexit_list; p; p = p->next)
        for (n = p->count; --n >= 0;)
            (*p->functions[n])();
    if (w3d_sda_impure_ptr_804ac570->cleanup)
        (*w3d_sda_impure_ptr_804ac570->cleanup)(w3d_sda_impure_ptr_804ac570);
    _exit(code);
}

int fiprintf(W3dFile *fp, const char *fmt, ...)
{
    int ret;
    va_list ap;
    va_start(ap, fmt);
    ret = vfiprintf(fp, fmt, ap);
    va_end(ap);
    return ret;
}

unsigned int w3d_vfprintf_console_write_802f05f0(int fd, const unsigned char *data, unsigned int length, int flush)
{
    unsigned int i;
    int written;
    if (flush == 1) {
        written = w3d_auto_802e3294(fd, w3d_vfprintf_console_buffer_8047dc1c,
                                    w3d_sda_vfprintf_console_count_804ac580);
        w3d_sda_vfprintf_console_count_804ac580 = 0;
        w3d_sda_vfprintf_console_next_804ac588 = w3d_vfprintf_console_buffer_8047dc1c;
        return written;
    }
    for (i = 0; i < length; i++) {
        *w3d_sda_vfprintf_console_next_804ac588 = data[i];
        w3d_sda_vfprintf_console_next_804ac588++;
        w3d_sda_vfprintf_console_count_804ac580++;
        if (w3d_sda_vfprintf_console_count_804ac580 > w3d_sda_vfprintf_console_size_804ac584) {
            written = w3d_auto_802e3294(fd, w3d_vfprintf_console_buffer_8047dc1c,
                                        w3d_sda_vfprintf_console_size_804ac584);
            w3d_sda_vfprintf_console_next_804ac588 = w3d_vfprintf_console_buffer_8047dc1c;
            w3d_sda_vfprintf_console_count_804ac580 = 0;
            if (written == 0)
                return 0;
        }
    }
    return i;
}

unsigned int w3d_vfiprintf_console_write_802f1be0(int fd, const unsigned char *data, unsigned int length, int flush)
{
    unsigned int i;
    int written;
    if (flush == 1) {
        written = w3d_auto_802e3294(fd, w3d_vfiprintf_console_buffer_8047dc9c,
                                    w3d_sda_vfiprintf_console_count_804ac58c);
        w3d_sda_vfiprintf_console_count_804ac58c = 0;
        w3d_sda_vfiprintf_console_next_804ac594 = w3d_vfiprintf_console_buffer_8047dc9c;
        return written;
    }
    for (i = 0; i < length; i++) {
        *w3d_sda_vfiprintf_console_next_804ac594 = data[i];
        w3d_sda_vfiprintf_console_next_804ac594++;
        w3d_sda_vfiprintf_console_count_804ac58c++;
        if (w3d_sda_vfiprintf_console_count_804ac58c > w3d_sda_vfiprintf_console_size_804ac590) {
            written = w3d_auto_802e3294(fd, w3d_vfiprintf_console_buffer_8047dc9c,
                                        w3d_sda_vfiprintf_console_size_804ac590);
            w3d_sda_vfiprintf_console_next_804ac594 = w3d_vfiprintf_console_buffer_8047dc9c;
            w3d_sda_vfiprintf_console_count_804ac58c = 0;
            if (written == 0)
                return 0;
        }
    }
    return i;
}
