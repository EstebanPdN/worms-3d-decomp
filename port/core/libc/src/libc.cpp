// Implementación de la libc del juego sobre la libc de la plataforma.
//
// Las firmas usan w3d_u32 en lugar de Ptr32<T> para enlazar con las declaraciones de
// core/libc/include: Ptr32<T> y un entero de 32 bits usan el mismo registro. La
// asignación de memoria sale siempre de la arena del juego para que cada dirección
// quepa en 32 bits.
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <errno.h>
#include "w3d_ptr.h"
#include "../../../platform/common/arena.h"

using w3d::g2h;
using w3d::h2g;
typedef w3d_u32 G;
static inline char *S(G v) { return (char *)g2h(v); }

extern "C" {
int w3d_errno_ = 0;
G w3d_memcpy(G d, G s, w3d_u32 n) { memmove(g2h(d), g2h(s), n); return d; }
G w3d_memmove(G d, G s, w3d_u32 n) { memmove(g2h(d), g2h(s), n); return d; }
G w3d_memset(G d, int c, w3d_u32 n) { memset(g2h(d), c, n); return d; }
int w3d_memcmp(G a, G b, w3d_u32 n) { return memcmp(g2h(a), g2h(b), n); }
G w3d_memchr(G a, int c, w3d_u32 n) { return h2g(memchr(g2h(a), c, n)); }
w3d_u32 w3d_strlen(G a) { return (w3d_u32)strlen(S(a)); }
int w3d_strcmp(G a, G b) { return strcmp(S(a), S(b)); }
int w3d_strncmp(G a, G b, w3d_u32 n) { return strncmp(S(a), S(b), n); }
int w3d_strcoll(G a, G b) { return strcmp(S(a), S(b)); }
G w3d_strcpy(G d, G s) { strcpy(S(d), S(s)); return d; }
G w3d_strncpy(G d, G s, w3d_u32 n) { strncpy(S(d), S(s), n); return d; }
G w3d_strcat(G d, G s) { strcat(S(d), S(s)); return d; }
G w3d_strncat(G d, G s, w3d_u32 n) { strncat(S(d), S(s), n); return d; }
G w3d_strchr(G a, int c) { return h2g(strchr(S(a), c)); }
G w3d_strrchr(G a, int c) { return h2g(strrchr(S(a), c)); }
G w3d_strstr(G a, G b) { return h2g(strstr(S(a), S(b))); }
G w3d_strpbrk(G a, G b) { return h2g(strpbrk(S(a), S(b))); }
w3d_u32 w3d_strspn(G a, G b) { return (w3d_u32)strspn(S(a), S(b)); }
w3d_u32 w3d_strcspn(G a, G b) { return (w3d_u32)strcspn(S(a), S(b)); }
G w3d_strerror(int e) {
    static G cached = 0;
    const char *m = strerror(e); size_t n = strlen(m) + 1;
    if (cached) w3d::arena_free(g2h(cached));
    void *p = w3d::arena_alloc(n); memcpy(p, m, n); cached = h2g(p);
    return cached;
}

// malloc del juego: en el original es su propio montón (0x80212fd4, 0x802134fc), y un bloque puede pedirse desde código
// compilado y liberarse desde código traducido.
extern "C" G A80212fd4(w3d_u32 n);
extern "C" void A802134fc(G p);
extern "C" G A80213750(G p, w3d_u32 n);
G w3d_malloc(w3d_u32 n) { return A80212fd4(n); }
G w3d_calloc(w3d_u32 a, w3d_u32 b) { G p = A80212fd4(a * b); if (p) memset(g2h(p), 0, a * b); return p; }
G w3d_realloc(G p, w3d_u32 n) { return A80213750(p, n); }
void w3d_free(G p) { A802134fc(p); }
void w3d_exit(int c) { exit(c); }
void w3d_abort(void) { abort(); }
int w3d_atoi(G s) { return atoi(S(s)); }
double w3d_atof(G s) { return atof(S(s)); }
double w3d_strtod(G s, G e) { char *end = 0; double v = strtod(S(s), &end); if (e) *(w3d_u32 *)g2h(e) = h2g(end); return v; }
int w3d_strtol(G s, G e, int b) { char *end = 0; long v = strtol(S(s), &end, b); if (e) *(w3d_u32 *)g2h(e) = h2g(end); return (int)v; }
w3d_u32 w3d_strtoul(G s, G e, int b) { char *end = 0; unsigned long v = strtoul(S(s), &end, b); if (e) *(w3d_u32 *)g2h(e) = h2g(end); return (w3d_u32)v; }
// rand de newlib en 0x802ee7dc: los dos generadores del juego se siembran con él al arrancar (0x801651e8) y deciden el nivel natural.
w3d_u32 w3d_rand_next = 1;   // Visible: la prueba en sombra lo restaura entre las dos versiones.
int w3d_rand(void) { w3d_rand_next = w3d_rand_next * 0x41c64e6dU + 0x3039U; return w3d_rand_next & 0x7fffffff; }
void w3d_srand(w3d_u32 s) { w3d_rand_next = s; }
int w3d_abs(int a) { return a < 0 ? -a : a; }
G w3d_getenv(G) { return 0; }
int w3d_system(G) { return -1; }
double w3d_frexp(double x, G e) { int v; double r = frexp(x, &v); *(int *)g2h(e) = v; return r; }
double w3d_modf(double x, G i) { double v; double r = modf(x, &v); *(double *)g2h(i) = v; return r; }
float w3d_frexpf(float x, G e) { int v; float r = frexpf(x, &v); *(int *)g2h(e) = v; return r; }
float w3d_modff(float x, G i) { float v; float r = modff(x, &v); *(float *)g2h(i) = v; return r; }
int w3d_time(G t) { int v = (int)time(0); if (t) *(int *)g2h(t) = v; return v; }
int w3d_clock(void) { return (int)(clock() / (CLOCKS_PER_SEC / 1000)); }

// FILE del juego: registro en la arena que envuelve un FILE* anfitrión.
struct GameFile { FILE *host; };
static G make_file(FILE *f) {
    if (!f) return 0;
    GameFile *g = (GameFile *)w3d::arena_alloc(sizeof(GameFile));
    g->host = f;
    return h2g(g);
}
static inline FILE *F(G v) { return ((GameFile *)g2h(v))->host; }
G w3d_stdin_ = 0, w3d_stdout_ = 0, w3d_stderr_ = 0;
void w3d_libc_init(void) {
    w3d_stdin_ = make_file(stdin); w3d_stdout_ = make_file(stdout); w3d_stderr_ = make_file(stderr);
}
G w3d_fopen(G n, G m) { return make_file(fopen(S(n), S(m))); }
G w3d_freopen(G n, G m, G f) { FILE *r = freopen(S(n), S(m), F(f)); if (!r) return 0; ((GameFile *)g2h(f))->host = r; return f; }
int w3d_fclose(G f) { int r = fclose(F(f)); w3d::arena_free(g2h(f)); return r; }
w3d_u32 w3d_fread(G p, w3d_u32 a, w3d_u32 b, G f) { return (w3d_u32)fread(g2h(p), a, b, F(f)); }
w3d_u32 w3d_fwrite(G p, w3d_u32 a, w3d_u32 b, G f) { return (w3d_u32)fwrite(g2h(p), a, b, F(f)); }
int w3d_fseek(G f, int o, int w) { return fseek(F(f), o, w); }
int w3d_ftell(G f) { return (int)ftell(F(f)); }
int w3d_feof(G f) { return feof(F(f)); }
int w3d_ferror(G f) { return ferror(F(f)); }
int w3d_fflush(G f) { return fflush(f ? F(f) : 0); }
int w3d_getc(G f) { return getc(F(f)); }
int w3d_ungetc(int c, G f) { return ungetc(c, F(f)); }
G w3d_fgets(G s, int n, G f) { return fgets(S(s), n, F(f)) ? s : 0; }
int w3d_fputs(G s, G f) { return fputs(S(s), F(f)); }

// printf del juego: los %s y %p llegan como Ptr32<T> (4 B) en la lista variable.
typedef void (*Sink)(void *, const char *, size_t);
static int format_core(Sink sink, void *ud, const char *f, va_list ap) {
    int total = 0; char out[512]; char spec[64];
    while (*f) {
        const char *pc = strchr(f, '%');
        if (!pc) { size_t n = strlen(f); sink(ud, f, n); total += (int)n; break; }
        if (pc != f) { sink(ud, f, (size_t)(pc - f)); total += (int)(pc - f); }
        const char *q = pc + 1; int si = 0; spec[si++] = '%';
        int star[2], ns = 0, l = 0;
        while (*q && strchr("-+ #0123456789.*", *q)) {
            if (*q == '*') { if (ns < 2) star[ns++] = va_arg(ap, int); }
            if (si < 50) spec[si++] = *q;
            q++;
        }
        while (*q == 'l' || *q == 'h' || *q == 'L' || *q == 'z') { if (*q == 'l') l++; q++; }
        char c = *q; if (c) q++;
        int n = 0;
#define EMIT(val) (ns == 2 ? snprintf(out, sizeof out, spec, star[0], star[1], val) : ns == 1 ? snprintf(out, sizeof out, spec, star[0], val) : snprintf(out, sizeof out, spec, val))
        switch (c) {
        case 'd': case 'i': case 'u': case 'x': case 'X': case 'o': case 'c':
            if (l >= 2) { spec[si++] = 'l'; spec[si++] = 'l'; spec[si++] = c; spec[si] = 0; long long v = va_arg(ap, long long); n = EMIT(v); }
            else { spec[si++] = c; spec[si] = 0; int v = va_arg(ap, int); n = EMIT(v); }
            break;
        case 'f': case 'g': case 'e': case 'E': case 'G': case 'F': {
            spec[si++] = c; spec[si] = 0; double v = va_arg(ap, double); n = EMIT(v); break; }
        case 's': {
            spec[si++] = 's'; spec[si] = 0; Ptr32<const char> v = va_arg(ap, Ptr32<const char>);
            const char *hs = v.v ? v.get() : "(null)";
            if (ns == 0 && si == 2) { size_t m = strlen(hs); sink(ud, hs, m); total += (int)m; n = -1; }
            else n = EMIT(hs);
            break; }
        case 'p': { Ptr32<const void> v = va_arg(ap, Ptr32<const void>); n = snprintf(out, sizeof out, "0x%08x", v.v); break; }
        case '%': out[0] = '%'; n = 1; break;
        default: n = 0; break;
        }
        if (n > 0) { size_t m = (size_t)n < sizeof out ? (size_t)n : sizeof out - 1; sink(ud, out, m); total += (int)m; }
        f = q;
    }
    return total;
}
struct Buf { char *p; size_t left; };
static void buf_sink(void *ud, const char *s, size_t n) { Buf *b = (Buf *)ud; size_t m = n < b->left ? n : b->left; memcpy(b->p, s, m); b->p += m; b->left -= m; }
static void file_sink(void *ud, const char *s, size_t n) { fwrite(s, 1, n, (FILE *)ud); }
int w3d_vsprintf(G d, G f, va_list ap) { Buf b = {S(d), (size_t)1 << 30}; int r = format_core(buf_sink, &b, S(f), ap); *b.p = 0; return r; }
int w3d_sprintf(G d, G f, ...) { va_list ap; va_start(ap, f); int r = w3d_vsprintf(d, f, ap); va_end(ap); return r; }
int w3d_snprintf(G d, w3d_u32 n, G f, ...) { va_list ap; va_start(ap, f); Buf b = {S(d), n ? n - 1 : 0}; int r = format_core(buf_sink, &b, S(f), ap); if (n) *b.p = 0; va_end(ap); return r; }
int w3d_puts(G s) { return puts(S(s)); }
int w3d_vprintf_game(const char *f, va_list ap) { return format_core(file_sink, stdout, f, ap); }
int w3d_printf(G f, ...) { va_list ap; va_start(ap, f); int r = format_core(file_sink, stdout, S(f), ap); va_end(ap); return r; }
int w3d_fprintf(G o, G f, ...) { va_list ap; va_start(ap, f); int r = format_core(file_sink, F(o), S(f), ap); va_end(ap); return r; }
int w3d_sscanf(G s, G f, ...) {
    // Solo los formatos numéricos sencillos que usan los módulos portados.
    va_list ap; va_start(ap, f); const char *fmt = S(f); const char *in = S(s); int done = 0;
    while (*fmt) {
        if (*fmt != '%') { if (isspace((unsigned char)*fmt)) { while (isspace((unsigned char)*in)) in++; fmt++; continue; } if (*in != *fmt) break; in++; fmt++; continue; }
        fmt++; char c = *fmt++; char *e = 0; Ptr32<void> t = va_arg(ap, Ptr32<void>);
        if (c == 'd') { long v = strtol(in, &e, 10); if (e == in) break; *(int *)t.get() = (int)v; }
        else if (c == 'x') { long v = strtol(in, &e, 16); if (e == in) break; *(int *)t.get() = (int)v; }
        else if (c == 'f') { float v = strtof(in, &e); if (e == in) break; *(float *)t.get() = v; }
        else if (c == 'n') { *(int *)t.get() = (int)(in - S(s)); done--; e = (char *)in; }
        else break;
        in = e; done++;
    }
    va_end(ap); return done;
}
static Ptr32<int (Ptr32<const void>, Ptr32<const void>)> qsort_cmp;
static int qsort_tramp(const void *a, const void *b) { return qsort_cmp.get()(Ptr32<const void>(a), Ptr32<const void>(b)); }
void w3d_qsort(G b, w3d_u32 n, w3d_u32 s, G c) { qsort_cmp.v = c; qsort(g2h(b), n, s, qsort_tramp); }
}
