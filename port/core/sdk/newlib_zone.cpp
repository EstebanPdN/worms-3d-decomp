// newlib por dirección original: lo que core/libc no da con el mismo nombre.
#include "w3d_ptr.h"
#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
using namespace w3d;
typedef w3d_u32 GA;
extern "C" {
int w3d_vsprintf(GA d, GA f, va_list ap);
int w3d_vprintf_game(const char *f, va_list ap);
static int g_errno;
GA A802eafc4(void) { return h2g(&g_errno); }                 // __errno
int A802ed63c(GA d, unsigned n, GA f, va_list ap) {          // vsnprintf: sobre vsprintf con un búfer holgado.
    static char big[1 << 16];
    int r = w3d_vsprintf(h2g(big), f, ap);
    if (n) { size_t c = (unsigned)r < n - 1 ? (unsigned)r : n - 1; memcpy(g2h(d), big, c); ((char *)g2h(d))[c] = 0; }
    return r;
}
void A802ed7b0(GA file, int line, GA expr) {                 // __assert
    fflush(stdout);
    fprintf(stderr, "[assert] %s:%d: %s\n", (char *)g2h(file), line, (char *)g2h(expr));
    abort();
}
int A802ed7e0(GA) { return 0; }                              // atexit: el juego no llega a salir por esta vía.
int A802ed8c4(GA s) { return atoi((char *)g2h(s)); }         // atol
GA A802ed8ec(GA key, GA base, unsigned n, unsigned size, GA cmp) {  // bsearch
    int (*c)(GA, GA) = (int (*)(GA, GA))g2h(cmp);
    unsigned lo = 0, hi = n;
    while (lo < hi) {
        unsigned m = (lo + hi) / 2;
        GA e = base + m * size;
        int r = c(key, e);
        if (r == 0) return e;
        if (r < 0) hi = m; else lo = m + 1;
    }
    return 0;
}
int A802ef074(GA a, GA b) { return strcasecmp((char *)g2h(a), (char *)g2h(b)); }  // strcasecmp
GA A802ef3f0(int) { static char m[] = "error"; return h2g(m); }   // strerror
GA A802efa2c(GA s) { for (char *p = (char *)g2h(s); *p; p++) *p = (char)tolower((unsigned char)*p); return s; }  // strlwr
GA A802efd7c(GA s, GA d) {                                   // strtok
    static char *save;
    char *r = strtok_r(s ? (char *)g2h(s) : nullptr, (char *)g2h(d), &save);
    return r ? h2g(r) : 0;
}
int A802f06c8(GA, GA f, va_list ap) { return w3d_vprintf_game((char *)g2h(f), ap); }  // vfprintf: consola.
}
