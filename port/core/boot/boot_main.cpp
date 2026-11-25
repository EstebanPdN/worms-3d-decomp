#include <execinfo.h>
#include <CommonCrypto/CommonDigest.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <sys/mman.h>
// Arranque del port en macOS: carga los datos fijos del DOL del usuario y entra en el main del juego.
#include "../../platform/platform.h"
#include "../../platform/common/arena.h"
#include "w3d_ptr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern "C" {
extern char w3d_dol_image[], w3d_low_image[];
struct FnEntry { uint32_t addr, pad; void *fn; };
extern const FnEntry w3d_fn_table[];
extern const uint32_t w3d_fn_table_count;
struct LayoutRun { uint32_t addr, size, kind; };
extern const LayoutRun w3d_layout[];
extern const uint32_t w3d_layout_count;
extern const char w3d_unresolved_names[];
void w3d_libc_init(void);
void w3d_sdk_init(void);
void w3d_sdk_after_load(void);
int A8015ad40(int argc, w3d_u32 argv);
}

enum { RAW, WORD, HALF, DBL, FLT };
static const uint32_t DATA_LO = 0x8035f3e0, DATA_HI = 0x804b3280, TEXT_LO = 0x80003100;

static inline uint32_t be32(const uint8_t *p) { return (uint32_t)p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3]; }

static void *fn_for(uint32_t addr) {
    uint32_t lo = 0, hi = w3d_fn_table_count;
    while (lo < hi) {
        uint32_t m = (lo + hi) / 2;
        if (w3d_fn_table[m].addr < addr) lo = m + 1; else hi = m;
    }
    return lo < w3d_fn_table_count && w3d_fn_table[lo].addr == addr ? w3d_fn_table[lo].fn : nullptr;
}

// Copia .ctors, .rodata, .data y .sdata del DOL, convierte el orden de bytes y traduce los punteros.
static bool load_dol(const char *data_root) {
    char path[1024]; snprintf(path, sizeof path, "%s/sys/main.dol", data_root);
    FILE *f = fopen(path, "rb");
    if (!f) { fprintf(stderr, "no encuentro %s\n", path); return false; }
    fseek(f, 0, SEEK_END); long n = ftell(f); fseek(f, 0, SEEK_SET);
    if (n != 4315040) { fclose(f); return false; }
    uint8_t *dol = (uint8_t *)malloc(n);
    if (!dol) { fclose(f); return false; }
    if (fread(dol, 1, n, f) != (size_t)n) { free(dol); fclose(f); return false; }
    fclose(f);
    static const unsigned char expected[] = {0xbb, 0x1b, 0x36, 0xb9, 0xbb, 0xb8, 0x06, 0x68, 0x8e, 0x61, 0x62, 0x08, 0x25, 0x49, 0x07, 0xae, 0x2a, 0xf5, 0x9d, 0x2e, 0x19, 0x1f, 0xf8, 0x39, 0xb3, 0xa0, 0x46, 0xa6, 0xc2, 0xc6, 0xf5, 0x14};
    unsigned char digest[CC_SHA256_DIGEST_LENGTH];
    CC_SHA256(dol, (CC_LONG)n, digest);
    if (memcmp(expected, digest, sizeof expected)) {
        fprintf(stderr, "Expected the European GWMP8P revision 0 DOL.\n");
        free(dol);
        return false;
    }
    uint8_t *img = (uint8_t *)w3d_dol_image;
    memset(img, 0, DATA_HI - DATA_LO);
    for (int i = 0; i < 18; i++) {
        uint32_t off = be32(dol + i * 4), addr = be32(dol + 0x48 + i * 4), size = be32(dol + 0x90 + i * 4);
        if (size && addr >= DATA_LO && addr < DATA_HI) memcpy(img + (addr - DATA_LO), dol + off, size);
    }
    free(dol);
    uint32_t ptr_data = 0, ptr_fn = 0, ptr_lost = 0;
    for (uint32_t r = 0; r < w3d_layout_count; r++) {
        const LayoutRun &run = w3d_layout[r];
        uint8_t *p = img + (run.addr - DATA_LO);
        uint32_t lead = run.kind == RAW ? 0 : (4 - (run.addr & 3)) & 3;
        if (run.kind == WORD || run.kind == FLT) {
            for (uint32_t o = lead; o + 4 <= run.size; o += 4) {
                uint32_t v = be32(p + o);
                if (run.kind == WORD && v >= DATA_LO && v < DATA_HI) { v = w3d::h2g(img + (v - DATA_LO)); ptr_data++; }
                else if (run.kind == WORD && v >= TEXT_LO && v < DATA_LO) {
                    void *fn = fn_for(v);
                    if (fn) { v = w3d::h2g(fn); ptr_fn++; } else ptr_lost++;
                }
                memcpy(p + o, &v, 4);
            }
        } else if (run.kind == HALF) {
            for (uint32_t o = 0; o + 2 <= run.size; o += 2) { uint8_t t = p[o]; p[o] = p[o + 1]; p[o + 1] = t; }
        } else if (run.kind == DBL) {
            for (uint32_t o = 0; o + 8 <= run.size; o += 8) for (int k = 0; k < 4; k++) { uint8_t t = p[o + k]; p[o + k] = p[o + 7 - k]; p[o + 7 - k] = t; }
        }
    }
    printf("[arranque] datos del DOL: %u punteros a datos, %u a funciones, %u a direcciones de texto sin función\n", ptr_data, ptr_fn, ptr_lost);
    return true;
}

extern "C" {
// libgcc: __main ejecuta la tabla .ctors del DOL (0x8035f3e0) de atrás hacia delante, como el original.
void A802f35fc(void) {
    static bool done;
    if (done) return;
    done = true;
    w3d_u32 *list = (w3d_u32 *)w3d_dol_image;
    int n = 0;
    while (list[n + 1]) n++;
    printf("[arranque] %d constructores globales\n", n);
    for (int i = n; i > 0; i--) {
        void (*ctor)(void) = (void (*)(void))w3d::g2h(list[i]);
        ctor();
    }
}
// W3D_SOFT=1: solo para explorar el arranque. Sigue adelante y devuelve 0; nunca es el modo del juego.
long w3d_report_missing(uint32_t addr, void *lr) {
    fflush(stdout);
    fprintf(stderr, "[FALTA] función 0x%08x llamada desde %p\n", addr, lr);
    if (getenv("W3D_SOFT") && *getenv("W3D_SOFT")) return 0;
    abort();
}
long w3d_report_unresolved(uint32_t idx, void *lr) {
    const char *s = w3d_unresolved_names;
    for (uint32_t k = 0; k < idx && *s; k++) s += strlen(s) + 1;
    fflush(stdout);
    fprintf(stderr, "[FALTA] símbolo sin dirección %s llamado desde %p\n", s, lr);
    if (getenv("W3D_SOFT") && *getenv("W3D_SOFT")) return 0;
    abort();
}
}

// El new y delete del juego. No son los globales de C++: esos los comparten los frameworks del sistema.
extern "C" {
// Van al mismo montón que el PPC (0x80212fd4 y 0x802134fc): un vector de STL puede crearse en una función traducida y
// crecer en otra compilada.
uint32_t A80212fd4(uint32_t n);
void A802134fc(uint32_t p);
void *w3d_op_new(unsigned long n) { return w3d::g2h(A80212fd4((uint32_t)n)); }
void w3d_op_delete(void *p) { if (p) A802134fc(w3d::h2g(p)); }
}

// Variables de prueba de la comparación con Dolphin (W3D_SEED, W3D_LEVEL_DRAW): solo actúan si están puestas.
extern "C" int w3d_env_int(const char *name, int *out) {
    const char *v = getenv(name);
    if (!v || !*v) return 0;
    *out = (int)strtoul(v, nullptr, 0);
    return 1;
}

// W3D_EFENCE=1, para depurar: cada bloque del montón general en sus propias páginas, pegado al final y seguido de una
// página protegida; liberar protege el bloque y no se reutiliza. Un acceso indebido falla justo en la instrucción culpable.
extern "C" {
int w3d_efence_on = -1;
static char *g_ef_next, *g_ef_low, *g_ef_free[2048];
int w3d_efence(void) { return w3d_efence_on > 0; }
// Se activa al empezar la partida: durante la carga hay demasiados bloques vivos para una página por bloque.
void w3d_efence_start(void) { if (getenv("W3D_EFENCE")) w3d_efence_on = 1; }
int w3d_efence_owns(uint32_t g) { char *p = (char *)w3d::g2h(g); return g && g_ef_low && p >= g_ef_low && p < g_ef_low + (1ull << 30); }
struct EfMeta { void *pcs[8]; char *base; uint32_t pages, size; };
uint32_t w3d_efence_memalign(uint32_t align, uint32_t n) {
    const size_t page = 16384;
    size_t body = (((size_t)n + 7) & ~(size_t)7) + sizeof(EfMeta) + (align > 8 ? align + 32 : 32);
    size_t pages = (body + page - 1) / page;
    static char *reserve_end;
    if (!reserve_end) {
        size_t total = 0; char *r = nullptr;
        for (size_t sz = 1ull << 30; sz >= (1ull << 27) && !r; sz >>= 1)
            for (uintptr_t h = 0x120000000ull; h + sz < 0x1f0000000ull && !r; h += 1ull << 26) {
                char *q = (char *)mmap((void *)h, sz, PROT_NONE, MAP_PRIVATE | MAP_ANON, -1, 0);
                if (q != MAP_FAILED && (uintptr_t)q >> 32 == 1 && (uintptr_t)(q + sz) >> 32 == 1) { r = q; total = sz; }
                else if (q != MAP_FAILED) munmap(q, sz);
            }
        if (!r) { fprintf(stderr, "[efence] sin ventana\n"); abort(); }
        fprintf(stderr, "[efence] reserva %zu MB en %p\n", total >> 20, r);
        g_ef_next = r; reserve_end = r + total;
        g_ef_low = r;
    }
    char *base = pages < 2048 ? g_ef_free[pages] : nullptr;
    if (base) { mprotect(base, pages * page, PROT_READ | PROT_WRITE); g_ef_free[pages] = *(char **)(base + 8); memset(base, 0, pages * page); }
    else {
        if (g_ef_next + (pages + 1) * page > reserve_end) { fprintf(stderr, "[efence] sin memoria\n"); abort(); }
        base = g_ef_next;
        g_ef_next += (pages + 1) * page;
    }
    mprotect(base, pages * page, PROT_READ | PROT_WRITE);
    char *p = base + pages * page - (((size_t)n + 7) & ~(size_t)7) - ((align > 8 || n >= 1024) ? 32 : 0);
    if (align > 8) p = (char *)((uintptr_t)p & ~(uintptr_t)(align - 1));
    EfMeta *m = (EfMeta *)(p - sizeof(EfMeta));
    m->base = base; m->pages = (uint32_t)pages; m->size = n;
    { uint64_t *fp = (uint64_t *)__builtin_frame_address(0); memset(m->pcs, 0, sizeof m->pcs);
      for (int i = 0; i < 8 && fp && (uintptr_t)fp > 0x1000; i++) { m->pcs[i] = (void *)fp[1]; fp = (uint64_t *)fp[0]; } }
    return w3d::h2g(p);
}
uint32_t w3d_efence_alloc(uint32_t n) { return w3d_efence_memalign(8, n); }
void w3d_efence_origin(uint32_t g) {
    EfMeta *m = (EfMeta *)((char *)w3d::g2h(g) - sizeof(EfMeta));
    for (int i = 0; i < 8 && m->pcs[i]; i++) { Dl_info inf; fprintf(stderr, "  origen %s\n", dladdr(m->pcs[i], &inf) && inf.dli_sname ? inf.dli_sname : "?"); }
}
void w3d_efence_free(uint32_t g) {
    if (!g) return;
    char *p = (char *)w3d::g2h(g);
    if (p < g_ef_low) { fprintf(stderr, "[efence] liberar puntero ajeno %x\n", g); return; }
    EfMeta *m = (EfMeta *)(p - sizeof(EfMeta));
    char *m_base = m->base; uint32_t m_pages = m->pages;
    mprotect(m_base, (size_t)m_pages * 16384, PROT_NONE);
    // Cuarentena: el espacio solo se reutiliza tras otras 2000 liberaciones.
    static struct { char *base; uint32_t pages; } ring[2000];
    static unsigned at;
    if (ring[at].base && ring[at].pages < 2048) {
        mprotect(ring[at].base, 16384, PROT_READ | PROT_WRITE);
        *(char **)(ring[at].base + 8) = g_ef_free[ring[at].pages];
        mprotect(ring[at].base, 16384, PROT_NONE);
        g_ef_free[ring[at].pages] = ring[at].base;
    }
    ring[at].base = m_base; ring[at].pages = m_pages;
    at = (at + 1) % 2000;
}
uint32_t w3d_efence_realloc(uint32_t g, uint32_t n) {
    if (!g) return w3d_efence_alloc(n);
    uint32_t old = ((EfMeta *)((char *)w3d::g2h(g) - sizeof(EfMeta)))->size;
    uint32_t q = w3d_efence_alloc(n);
    memcpy(w3d::g2h(q), w3d::g2h(g), old < n ? old : n);
    w3d_efence_free(g);
    return q;
}
}
// Volcado de fallo: registros y pila por punteros de marco. macOS limita sus informes si el fallo se repite.
#include <signal.h>
#include <sys/ucontext.h>
static void crash_handler(int sig, siginfo_t *si, void *uc_) {
    ucontext_t *uc = (ucontext_t *)uc_;
    auto &ss = uc->uc_mcontext->__ss;
    fflush(stdout);
    fprintf(stderr, "[fallo] señal %d en dirección 0x%llx\n", sig, (unsigned long long)si->si_addr);
    for (int i = 0; i < 29; i++) fprintf(stderr, "x%d=%llx%s", i, (unsigned long long)ss.__x[i], i % 8 == 7 ? "\n" : " ");
    fprintf(stderr, "\n");
    if (ss.__x[0] >= 0x110000000ull && ss.__x[0] < 0x130000000ull) {  // Memoria alrededor de x0, si está en la arena.
        uint32_t *m = (uint32_t *)(ss.__x[0] & ~3ull) - 16;
        for (int i = 0; i < 40; i++) fprintf(stderr, "%s%08x", i % 8 == 0 ? (i ? "\n  mem " : "  mem ") : " ", m[i]);
        fprintf(stderr, "\n");
    }
    uint64_t pc = (uint64_t)ss.__pc, fp = (uint64_t)ss.__fp, lr = (uint64_t)ss.__lr;
    for (int i = 0; i < 28; i++) {
        Dl_info inf; const char *name = dladdr((void *)pc, &inf) && inf.dli_sname ? inf.dli_sname : "?";
        fprintf(stderr, "  #%d %llx %s+%lld\n", i, (unsigned long long)pc, name, inf.dli_saddr ? (long long)(pc - (uint64_t)inf.dli_saddr) : 0);
        if (i == 0) { pc = lr; continue; }
        if (fp < 0x1000 || fp % 8) break;
        pc = ((uint64_t *)fp)[1]; fp = ((uint64_t *)fp)[0];
        if (!pc) break;
    }
    signal(sig, SIG_DFL); raise(sig);
}
// W3D_WATCH=<desplazamiento en la arena, en hexadecimal>: avisa con la pila del hilo principal cuando cambia esa palabra.
#include <pthread.h>
static pthread_t g_main_thread;
static void watch_signal(int, siginfo_t *, void *uc_) {
    ucontext_t *uc = (ucontext_t *)uc_;
    auto &ss = uc->uc_mcontext->__ss;
    uint64_t pc = (uint64_t)ss.__pc, fp = (uint64_t)ss.__fp, lr = (uint64_t)ss.__lr;
    for (int i = 0; i < 12; i++) {
        Dl_info inf; const char *name = dladdr((void *)pc, &inf) && inf.dli_sname ? inf.dli_sname : "?";
        fprintf(stderr, "  w#%d %s+%lld\n", i, name, inf.dli_saddr ? (long long)(pc - (uint64_t)inf.dli_saddr) : 0);
        if (i == 0) { pc = lr; continue; }
        if (fp < 0x1000 || fp % 8) break;
        pc = ((uint64_t *)fp)[1]; fp = ((uint64_t *)fp)[0];
        if (!pc) break;
    }
}
static void *watch_thread(void *arg) {
    volatile uint32_t *p = (volatile uint32_t *)arg; uint32_t last = *p;
    for (;;) {
        uint32_t v = *p;
        if (v != last) { fprintf(stderr, "[watch] %08x -> %08x\n", last, v); last = v; pthread_kill(g_main_thread, SIGUSR1); usleep(2000); }
    }
    return nullptr;
}
static void install_watch() {
    const char *w = getenv("W3D_WATCH");
    if (!w) return;
    g_main_thread = pthread_self();
    struct sigaction sa = {}; sa.sa_sigaction = watch_signal; sa.sa_flags = SA_SIGINFO | SA_ONSTACK | SA_RESTART;
    sigaction(SIGUSR1, &sa, nullptr);
    pthread_t t; pthread_create(&t, nullptr, watch_thread, (char *)w3d::arena_begin() + strtoull(w, nullptr, 16));
}
// W3D_HWWATCH=<desplazamiento en la arena>: watchpoint de hardware sobre esa palabra en el hilo principal.
// Da la instrucción exacta que escribe, cosa que W3D_WATCH no puede porque sondea desde otro hilo.
#include <mach/mach.h>
#include <mach/thread_status.h>
static thread_t g_hw_thread; static uint64_t g_hw_addr; static uint64_t g_hw_step;
static void hw_set(bool watch, uint64_t breakpoint) {
    arm_debug_state64_t st = {};
    if (watch) { st.__wvr[0] = g_hw_addr & ~7ull; st.__wcr[0] = (0xfu << (5 + (g_hw_addr & 4))) | (2u << 3) | (2u << 1) | 1u; }
    if (breakpoint) { st.__bvr[0] = breakpoint; st.__bcr[0] = (0xfu << 5) | (2u << 1) | 1u; }
    thread_set_state(g_hw_thread, ARM_DEBUG_STATE64, (thread_state_t)&st, ARM_DEBUG_STATE64_COUNT);
}
// Un acceso que dispara no se ha ejecutado: se quita el watchpoint, se para en la instrucción siguiente con un
// breakpoint y allí se vuelve a armar. Así no se pierde ninguna escritura.
static void hw_signal(int, siginfo_t *, void *uc_) {
    ucontext_t *uc = (ucontext_t *)uc_;
    auto &ss = uc->uc_mcontext->__ss;
    uint64_t pc = (uint64_t)ss.__pc, lr = (uint64_t)ss.__lr, fp = (uint64_t)ss.__fp;
    if (g_hw_step && pc == g_hw_step) {
        fprintf(stderr, "[hw] valor despues=%08x\n", *(uint32_t *)g_hw_addr);
        g_hw_step = 0; hw_set(true, 0);
        return;
    }
    // Dentro de libsystem (memmove) se vuelve a armar al retornar: thread_set_state usa esa misma memmove.
    Dl_info self_info, pc_info;
    dladdr((void *)hw_signal, &self_info);
    bool ours = dladdr((void *)pc, &pc_info) && pc_info.dli_fbase == self_info.dli_fbase;
    uint64_t next = ours ? pc + 4 : lr;
    hw_set(false, 0);
    fprintf(stderr, "[hw] valor antes=%08x\n", *(uint32_t *)g_hw_addr);
    for (int i = 0; i < 12; i++) {
        Dl_info inf; const char *name = dladdr((void *)pc, &inf) && inf.dli_sname ? inf.dli_sname : "?";
        fprintf(stderr, "  h#%d %s+%lld\n", i, name, inf.dli_saddr ? (long long)(pc - (uint64_t)inf.dli_saddr) : 0);
        if (i == 0) { pc = lr; continue; }
        if (fp < 0x1000 || fp % 8) break;
        pc = ((uint64_t *)fp)[1]; fp = ((uint64_t *)fp)[0];
        if (!pc) break;
    }
    // El breakpoint se pone al final: fprintf usa la misma memmove que puede haber disparado.
    g_hw_step = next; hw_set(false, next);
}
static void *hw_thread(void *) {
    // W3D_HWPTR=<desplazamiento hex en la arena>: arma el watchpoint solo cuando la palabra llega a ese valor.
    volatile uint32_t *p = (volatile uint32_t *)g_hw_addr;
    uint32_t want = (uint32_t)(strtoul(getenv("W3D_HWPTR"), nullptr, 16) + (uint64_t)w3d::arena_begin());
    while (*p != want) {}
    thread_suspend(g_hw_thread); hw_set(true, 0); thread_resume(g_hw_thread);
    fprintf(stderr, "[hw] armado con %08x\n", want);
    return nullptr;
}
// Para depurar: arma el watchpoint desde el propio juego, sobre una dirección conocida en ese momento.
extern "C" void *w3d_sym(const char *name) { return dlsym(RTLD_DEFAULT, name); }
extern "C" void w3d_hw_watch_host(void *p) {
    g_hw_thread = mach_thread_self();
    g_hw_addr = (uint64_t)p;
    struct sigaction sa = {}; sa.sa_sigaction = hw_signal; sa.sa_flags = SA_SIGINFO | SA_ONSTACK;
    sigaction(SIGTRAP, &sa, nullptr); sigaction(SIGBUS, &sa, nullptr);
    hw_set(true, 0);
}
static void install_hw_watch() {
    const char *w = getenv("W3D_HWWATCH");
    if (!w) return;
    g_hw_thread = mach_thread_self();
    g_hw_addr = (uint64_t)w3d::arena_begin() + strtoull(w, nullptr, 16);
    struct sigaction sa = {}; sa.sa_sigaction = hw_signal; sa.sa_flags = SA_SIGINFO | SA_ONSTACK;
    sigaction(SIGTRAP, &sa, nullptr); sigaction(SIGBUS, &sa, nullptr);
    if (getenv("W3D_HWPTR")) { pthread_t t; pthread_create(&t, nullptr, hw_thread, nullptr); }
    else hw_set(true, 0);
}
static void install_crash_handler() {
    static char alt[1 << 16];
    stack_t st = {}; st.ss_sp = alt; st.ss_size = sizeof alt; sigaltstack(&st, nullptr);
    struct sigaction sa = {}; sa.sa_sigaction = crash_handler; sa.sa_flags = SA_SIGINFO | SA_ONSTACK;
    sigaction(SIGABRT, &sa, nullptr); sigaction(SIGTRAP, &sa, nullptr); sigaction(SIGSEGV, &sa, nullptr); sigaction(SIGBUS, &sa, nullptr); sigaction(SIGILL, &sa, nullptr);
 sigaction(SIGTRAP, &sa, nullptr); sigaction(SIGILL, &sa, nullptr);
}

// Traza de depuración para las unidades del juego, que no ven stdio del anfitrión.
extern "C" void w3d_bt(void) { void *b[24]; int n = backtrace(b, 24); backtrace_symbols_fd(b, n, 2); }
extern "C" void w3d_dbg(const char *f, ...) { va_list a; va_start(a, f); vfprintf(stderr, f, a); va_end(a); }
extern "C" char *w3d_choose_data_folder();
int main(int argc, char **argv) {
    const char *data_root = argc > 1 ? argv[1] : w3d_choose_data_folder();
    if (!data_root) return 2;
    setenv("W3D_DUAL", "1", 0);
    setvbuf(stdout, nullptr, _IOLBF, 0);
    if (!w3d::arena_init(512ul << 20)) return 90;
    // Globales del sistema en la memoria baja de la consola (0x80000000): el juego lee el reloj de bus en +0xf8.
    void *low = mmap((void *)0x180000000ull, 0x4000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON | MAP_FIXED, -1, 0);
    if (low == MAP_FAILED) return 91;
    ((unsigned *)low)[0xf8 / 4] = 162000000; ((unsigned *)low)[0xfc / 4] = 486000000;
    int probe;
    if (!w3d::in_window(&probe) || !w3d::in_window((void *)&main) || !w3d::in_window(w3d_dol_image)) {
        fprintf(stderr, "el proceso no cabe en la ventana de punteros\n"); return 91;
    }
    install_crash_handler();
    static char save_dir[1024]; snprintf(save_dir, sizeof save_dir, "%s/Library/Application Support/Worms3D", getenv("HOME") ? getenv("HOME") : "/tmp");
    w3d::plat::Config cfg = {data_root, save_dir, getenv("W3D_HIDDEN") ? 640 : 1280, getenv("W3D_HIDDEN") ? 480 : 960, "Worms 3D (port)", getenv("W3D_HIDDEN") != nullptr};
    if (!w3d::plat::init(cfg)) return 92;
    install_watch();
    install_hw_watch();
    w3d_libc_init();
    w3d_sdk_init();
    if (!load_dol(data_root)) return 93;
    w3d_sdk_after_load();
    printf("[arranque] arena %p-%p, datos %p, entrando en el main del juego\n", w3d::arena_begin(), w3d::arena_end(), w3d_dol_image);
    Ptr32<char> *args = (Ptr32<char> *)w3d::arena_alloc(8);
    args[0] = (char *)"worms3d"; args[1] = (char *)nullptr;
    int r = A8015ad40(1, w3d::h2g(args));
    printf("[arranque] el juego devolvió %d\n", r);
    w3d::plat::shutdown();
    return r;
}



#include <dlfcn.h>
extern "C" const char *w3d_symname(unsigned v) { Dl_info i; if (v>0x10000 && dladdr((void*)(0x100000000ul|v),&i)&&i.dli_sname) return i.dli_sname; return ""; }
