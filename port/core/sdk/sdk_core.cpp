// SDK de GameCube sobre la plataforma: OS, DVD, VI, PAD, ARAM y matrices.
// Cada función lleva el nombre del SDK en el comentario y su dirección original en el símbolo.
// Nombres y firmas: port/docs-data/sdk-boundary.json.
#ifdef __3DS__
#include "../../platform/3ds/zones_3ds.h"
#endif
#include "../../platform/platform.h"
#include "../../platform/common/arena.h"
#include "w3d_ptr.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
unsigned w3d_retrace_count(void);
#ifdef __3DS__
extern "C" bool w3d_frame_pace(double frame_seconds);   // platform_3ds.cpp (v34)
#endif

using namespace w3d;
typedef w3d_u32 GA;

extern "C" int w3d_vprintf_game(const char *fmt, va_list ap);
extern "C" char w3d_low_image[];

static char *g_arena_lo, *g_arena_hi;
extern "C" void w3d_sdk_init(void) {
#if defined(__3DS__)
    // New 3DS: la arena sale de lo que deja el modo de memoria; ver platform/3ds.
    const char *mb = getenv("W3D_ARENA_MB");
    const unsigned long size = (unsigned long)(mb ? atoi(mb) : 60) << 20;
#else
    const unsigned long size = 96ul << 20;
#endif
    g_arena_lo = (char *)arena_alloc(size);
    g_arena_hi = g_arena_lo + size;
    // Valores que el juego lee de la memoria baja.
    *(uint32_t *)(w3d_low_image + 0xf8) = 162000000;  // Reloj de bus.
    *(uint32_t *)(w3d_low_image + 0xfc) = 486000000;  // Reloj de CPU.
}

// Variables del SDK que el juego lee directamente: hay que ponerlas después de cargar los datos del DOL.
extern "C" w3d_u32 A804ac668, A804b11e0;  // __OSArenaLo, __OSArenaHi
extern "C" void w3d_sdk_after_load(void) {
    A804ac668 = h2g(g_arena_lo);
    A804b11e0 = h2g(g_arena_hi);
}

extern "C" void w3d_dvd_poll(void);
extern "C" void w3d_audio_tick(void);

extern "C" {
// --- OS ---
void A802f96d4(void) {}                                // OSInit
GA A802fa668(void) { return h2g(g_arena_hi); }          // OSGetArenaHi
GA A802fa670(void) { return h2g(g_arena_lo); }          // OSGetArenaLo
#if defined(__3DS__)
// Lo que el juego vacía de la caché es lo que acaba de cambiar para la GPU: la geometría residente lo usa para no comparar contenido.
void w3d_mem_touch(GA a, unsigned n);
void A802fa95c(GA a, unsigned n) { w3d_mem_touch(a, n); }  // DCInvalidateRange
void A802fa988(GA a, unsigned n) { w3d_mem_touch(a, n); }  // DCFlushRange
#else
void A802fa95c(GA, unsigned) {}                         // DCInvalidateRange
void A802fa988(GA, unsigned) {}                         // DCFlushRange
#endif
void A802fab90(void) {}                                // LCEnable
void A802fabc8(void) {}                                // LCDisable
void A802fb7ac(GA fmt, ...) {                           // OSReport
    va_list ap; va_start(ap, fmt);
    w3d_vprintf_game((const char *)g2h(fmt), ap);
    va_end(ap);
}
void A802fb82c(GA file, int line, GA fmt, ...) {         // OSPanic
    fflush(stdout);
    fprintf(stderr, "[OSPanic] %s:%d: ", (const char *)g2h(file), line);
    va_list ap; va_start(ap, fmt);
    w3d_vprintf_game((const char *)g2h(fmt), ap);
    va_end(ap);
    fprintf(stderr, "\n");
    abort();
}
int A802fdb6c(void) { return 1; }                      // OSDisableInterrupts
int A802fdb80(void) { return 1; }                      // OSEnableInterrupts
int A802fdb94(int level) { return level; }             // OSRestoreInterrupts
void A802fe898(int a, unsigned b, int c) { fprintf(stderr, "[OS] OSResetSystem %d %u %d\n", a, b, c); fflush(nullptr); _exit(0); }  // OSResetSystem: sin destructores globales, ver VIWaitForRetrace
unsigned A802feb50(void) { return 0; }                 // OSGetResetCode
int A802fec74(void) { return 0; }                      // OSGetResetButtonState
unsigned A802ff730(void) { return 1; }                 // OSGetSoundMode: estéreo
void A802ff7b0(unsigned) {}                            // OSSetSoundMode
unsigned A802ff854(void) { return 0; }                 // OSGetLanguage: inglés
// W3D_FIXED_CLOCK: el reloj avanza 20 ms por retrazo, como en Dolphin, para repetir una partida igual.
// w3d_paused_seconds: tiempo que el juego estuvo parado por un volcado (platform/3ds/diag.cpp). No cuenta para el reloj
// del juego: un volcado de 20 s no se come el turno ni mueve las animaciones.
extern "C" { volatile double w3d_paused_seconds = 0; }
static double w3d_game_now(void) {
    static const bool fixed = getenv("W3D_FIXED_CLOCK") != 0;
    if (!fixed) return plat::now_seconds() - w3d_paused_seconds;
    // Una espera activa dentro de un retrazo (arranque, tarjeta) tiene que terminar: tras muchas lecturas seguidas el reloj avanza por su cuenta.
    static unsigned last, reads; static double extra;
    unsigned r = ::w3d_retrace_count();
    if (r != last) { last = r; reads = 0; } else if (++reads > 5000) extra += 1e-4;
    return r * (1.0 / 50.0) + extra;
}
extern "C" double w3d_game_seconds(void) { return w3d_game_now(); }
long long A80300aa0(void) { w3d_dvd_poll(); return (long long)(w3d_game_now() * 40500000.0); }  // OSGetTime
unsigned A80300ab8(void) { w3d_dvd_poll(); return (unsigned)(long long)(w3d_game_now() * 40500000.0); }  // OSGetTick
void A8030cefc(void) {}                                // DBInit
}

// --- DVD ---
// Las lecturas terminan más tarde, como en el disco real: el juego marca "leyendo" después de pedirlas.
// THP y DSP guardan enteros big-endian que el juego lee directamente: se convierten al cargar.
namespace {
struct FileInfo {  // DVDFileInfo: 0x3c B en GameCube.
    uint32_t next, prev, command; int32_t state; uint32_t offset, length, addr, curr, transferred, id, cb, user;
    uint32_t start_addr, size, callback;
};
static_assert(sizeof(FileInfo) == 0x3c, "disposición de DVDFileInfo");
std::vector<std::string> g_entries;
int entry_of(const char *path) {
    plat::File *f = plat::file_open(path);
    if (!f) return -1;
    plat::file_close(f);
    for (size_t i = 0; i < g_entries.size(); i++) if (g_entries[i] == path) return (int)i;
    g_entries.push_back(path);
    return (int)g_entries.size() - 1;
}
int fast_open(int entry, FileInfo *fi) {
    if (entry < 0 || (size_t)entry >= g_entries.size()) return 0;
    plat::File *f = plat::file_open(g_entries[entry].c_str());
    if (!f) return 0;
    memset(fi, 0, sizeof *fi);
    fi->start_addr = (uint32_t)entry;
    fi->size = (uint32_t)plat::file_size(f);
    plat::file_close(f);
    return 1;
}
typedef void (*DvdCallback)(int, GA);
inline uint32_t swap32(uint32_t v) { return __builtin_bswap32(v); }
inline void swap_words(uint8_t *p, int n) { uint32_t *w = (uint32_t *)p; for (int i = 0; i < n; i++) w[i] = swap32(w[i]); }
inline void swap_halves(uint8_t *p, int n) { uint16_t *w = (uint16_t *)p; for (int i = 0; i < n; i++) w[i] = __builtin_bswap16(w[i]); }
bool has_suffix(const std::string &s, const char *suf) {
    size_t n = strlen(suf);
    if (s.size() < n) return false;
    for (size_t i = 0; i < n; i++) if (tolower((unsigned char)s[s.size() - n + i]) != suf[i]) return false;
    return true;
}
// W3D_VOICE_BANK=<carpeta>: todas las voces salen de NGCSpeech/<carpeta>/, para oír un banco nuevo sin elegirlo en el menú.
std::string voice_path(const char *p) {
    static const char *bank = getenv("W3D_VOICE_BANK");
    const char *k = bank && *bank ? strstr(p, "NGCSpeech/") : nullptr;
    const char *rest = k ? strchr(k + 10, '/') : nullptr;
    return rest ? std::string(p, k + 10 - p) + bank + rest : std::string(p);
}
// Disposición del THP: cabecera de 48 B; en +0x20 el desplazamiento de los componentes, en +0x28 el primer cuadro.
struct ThpInfo { uint32_t comp_offset, first_frame, components; };
std::vector<ThpInfo> g_thp;
void convert_thp(int entry, uint8_t *data, int off, int done) {
    if ((size_t)entry >= g_thp.size()) g_thp.resize(entry + 1);
    ThpInfo &t = g_thp[entry];
    if (off == 0 && done >= 48) {
        swap_words(data + 4, 11);      // La firma "THP\0" se compara como cadena.
        t.comp_offset = ((uint32_t *)data)[8];
        t.first_frame = ((uint32_t *)data)[10];
        return;
    }
    if ((uint32_t)off == t.comp_offset && done >= 4) {
        swap_words(data, 1);
        t.components = *(uint32_t *)data;
        return;
    }
    if (t.first_frame && (uint32_t)off >= t.first_frame) {
        int words = 2 + (int)t.components;
        if (done >= words * 4) swap_words(data, words);
        return;
    }
    // Cabeceras de componente: solo enteros de 32 bits.
    if (done >= 4 && (done % 4) == 0) swap_words(data, done / 4);
}
void convert_dsp(uint8_t *data, int off, int done) {
    if (off != 0 || done < 96) return;
    swap_words(data, 3);          // Muestras, nibbles, frecuencia.
    swap_halves(data + 12, 2);    // Bucle, formato.
    swap_words(data + 16, 3);     // Inicio y fin de bucle, posición.
    swap_halves(data + 28, 34);   // Coeficientes, ganancia, estado inicial y de bucle, relleno.
}
struct Pending { GA fi, addr; int len, off; GA cb; unsigned id; };   // v34: id != 0, lectura en segundo plano (plat::aio_read)
FILE *dvd_log() { static FILE *l = getenv("W3D_SND_LOG") ? fopen((std::string(getenv("W3D_SND_LOG")) + ".rd").c_str(), "w") : nullptr; return l; }
#define DVDLOG(...) do { if (FILE *l_ = dvd_log()) { fprintf(l_, __VA_ARGS__); fflush(l_); } } while (0)
#ifdef __3DS__
#define DVDCON(...) do { fprintf(stderr, "[dvd] retrazo %u ", w3d_retrace_count()); fprintf(stderr, __VA_ARGS__); } while (0)
#else
#define DVDCON(...) do {} while (0)
#endif
std::vector<Pending> g_reads;
bool g_polling;
#ifdef __3DS__
// v34: la música y las voces (.dsp) se leen en segundo plano (platform/3ds/vfs_3ds.cpp, aio_*): en la consola cada lectura
// en el hilo del juego costaba 15-28 ms (zona 14), un tirón cada medio segundo. W3D_DVD_SINCRONO=1 vuelve a lo de antes.
unsigned g_aio_next = 1;
bool aio_ok(const std::string &path) { return has_suffix(path, ".dsp"); }
#endif
// Lectura terminada (hilo del juego): conversión, estado y aviso del juego.
void dvd_finish(const Pending &r, int done) {
    FileInfo *fi = (FileInfo *)g2h(r.fi);
    const std::string &path = g_entries[fi->start_addr];
    if (done > 0 && has_suffix(path, ".thp")) convert_thp((int)fi->start_addr, (uint8_t *)g2h(r.addr), r.off, done);
    else if (done > 0 && has_suffix(path, ".dsp")) convert_dsp((uint8_t *)g2h(r.addr), r.off, done);
    fi->state = done < 0 ? -1 : 0;
    if (done != r.len && has_suffix(path, ".dsp")) DVDCON("lectura corta %s off %d len %d -> %d\n", path.c_str(), r.off, r.len, done);
    DVDLOG("hecho fi %08x %s off %d len %d -> %d cb %08x\n", r.fi, path.c_str(), r.off, r.len, done, r.cb);
    if (r.cb) ((DvdCallback)g2h(r.cb))(done, r.fi);
}
}
extern "C" void w3d_dvd_poll(void) {
    if (g_polling) return;
    g_polling = true;
#ifdef __3DS__
    struct ZoneGuard { ZoneGuard() { w3d_zone_begin(W3D_Z_DVD); } ~ZoneGuard() { w3d_zone_end(W3D_Z_DVD); } } zone_;
    { unsigned id; long res;
      while (plat::aio_done(&id, &res)) {
          for (size_t i = 0; i < g_reads.size(); i++) if (g_reads[i].id == id) { Pending r = g_reads[i]; g_reads.erase(g_reads.begin() + i); dvd_finish(r, (int)res); break; }
      } }
#endif
    // Las del momento, en orden (las que añadan los avisos también).
    for (size_t i = 0; i < g_reads.size();) {
        if (g_reads[i].id) { i++; continue; }
        Pending r = g_reads[i];
        g_reads.erase(g_reads.begin() + i);
        FileInfo *fi = (FileInfo *)g2h(r.fi);
        int done = -1;
        const std::string &path = g_entries[fi->start_addr];
        plat::File *f = plat::file_open(path.c_str());
        if (f) {
            done = (int)plat::file_read(f, g2h(r.addr), r.off, r.len);
            plat::file_close(f);
        }
        dvd_finish(r, done);
        i = 0;
    }
    g_polling = false;
}
extern "C" {
int A802f4ef0(GA path) {                                                    // DVDConvertPathToEntrynum
    const char *p = (const char *)g2h(path);
    int e = entry_of(voice_path(p).c_str());
    // v33: también la música (en la consola su pista no llegaba a abrirse y no quedaba rastro de por qué).
    if (e < 0 && (strstr(p, "NGCSpeech") || strstr(p, "NGCmusic"))) DVDCON("no existe %s\n", p);
    else if (strstr(p, "NGCmusic")) DVDCON("entrada %d %s\n", e, p);
    return e;
}
int A802f51e4(int entry, GA fi) {                                            // DVDFastOpen
    static FILE *log = getenv("W3D_SND_LOG") ? fopen((std::string(getenv("W3D_SND_LOG")) + ".dvd").c_str(), "w") : nullptr;
    if (log && entry >= 0 && (size_t)entry < g_entries.size()) { fprintf(log, "%s\n", g_entries[entry].c_str()); fflush(log); }
    // Prueba (v32): W3D_MUSICA_FALLA=<n> hace fallar las n primeras aperturas de la música (NGCmusic), como en la consola
    // cuando el título se quedaba mudo; core/native/fe_bridge.cpp (music_watchdog) la vuelve a pedir.
    { static int left = -2; if (left == -2) { const char *e = getenv("W3D_MUSICA_FALLA"); left = e ? atoi(e) : 0; }
      if (left > 0 && entry >= 0 && (size_t)entry < g_entries.size() && g_entries[entry].find("NGCmusic") != std::string::npos) { left--; DVDCON("(prueba) apertura de música fallida\n"); return 0; } }
    if (entry >= 0 && (size_t)entry < g_entries.size() && has_suffix(g_entries[entry], ".dsp")) DVDCON("abre %s\n", g_entries[entry].c_str());
    else if (entry < 0 || (size_t)entry >= g_entries.size()) DVDCON("abre entrada %d no válida\n", entry);
    return fast_open(entry, (FileInfo *)g2h(fi));
}
int A802f5258(GA path, GA fi) { return fast_open(entry_of(voice_path((const char *)g2h(path)).c_str()), (FileInfo *)g2h(fi)); }  // DVDOpen
int A802f5320(GA fi) { DVDLOG("cerrar fi %08x\n", fi); return 1; }                                             // DVDClose
int A802f5568(GA gfi, GA addr, int len, int off, GA cb, int) {              // DVDReadAsyncPrio
    FileInfo *fi = (FileInfo *)g2h(gfi);
    DVDLOG("leer fi %08x entrada %d len %d off %d cb %08x\n", gfi, (int)fi->start_addr, len, off, cb);
    if ((size_t)fi->start_addr >= g_entries.size()) return 0;
    fi->state = 1;
    Pending p{gfi, addr, len, off, cb, 0};
#ifdef __3DS__
    const std::string &path = g_entries[fi->start_addr];
    if (aio_ok(path)) {
        p.id = g_aio_next++;
        if (!g_aio_next) g_aio_next = 1;
        if (!plat::aio_read(path.c_str(), g2h(addr), off, len, p.id)) p.id = 0;
    }
#endif
    g_reads.push_back(p);
    return 1;
}
void A802f565c(void) {}                                                     // DVDInit
int A802f7694(GA block) {                                                   // DVDGetCommandBlockStatus
    w3d_dvd_poll();
    DVDLOG("estado fi %08x -> %d\n", block, ((FileInfo *)g2h(block))->state);
    if (((FileInfo *)g2h(block))->state < 0) DVDCON("estado %08x -> %d\n", block, ((FileInfo *)g2h(block))->state);
    return ((FileInfo *)g2h(block))->state;
}
int A802f76e0(void) { w3d_dvd_poll(); return 0; }                           // DVDGetDriveStatus: listo
int A802f7a68(GA block) {                                                   // DVDCancel
    DVDLOG("cancelar fi %08x\n", block);
    for (size_t i = 0; i < g_reads.size(); i++) {
        if (g_reads[i].fi == block) {
#ifdef __3DS__
            if (g_reads[i].id) plat::aio_cancel(g_reads[i].id);   // fuera de la cola, o espera a la que se está leyendo
#endif
            g_reads.erase(g_reads.begin() + i); break;
        }
    }
    ((FileInfo *)g2h(block))->state = 0;
    return 0;
}
int A802f7b40(void) { return 1; }                                           // DVDCheckDisk
}

// --- VI ---
namespace {
GA g_pre_retrace; unsigned g_retrace; double g_next_frame;
#if defined(__3DS__)
// v27 (pedido del dueño): en 3DS cada cuadro dura como mínimo 1/30 s, 30 FPS fijos para que el juego vaya más estable
// (en la consola iba de 15 a 50). El reloj del juego sigue el tiempo real, así que el juego no va más lento: hace uno o
// dos tics de 20 ms por cuadro. W3D_FPS=<n> en debug.ini lo cambia (50 es el PAL original).
double frame_seconds() {
    static double f = 0;
    if (f == 0) { const char *e = getenv("W3D_FPS"); int n = e ? atoi(e) : 30; if (n < 10 || n > 60) n = 30; f = 1.0 / n; }
    return f;
}
#else
double frame_seconds() { return 1.0 / 50.0; }  // PAL.
#endif
}
unsigned w3d_retrace_count(void) { return g_retrace; }
extern "C" {
GA A803031d0(GA cb) { GA o = g_pre_retrace; g_pre_retrace = cb; return o; }   // VISetPreRetraceCallback
void A803034b4(void) {}                                                    // VIInit
void A80303964(void) {                                                     // VIWaitForRetrace
    // exit() correría los destructores globales del juego, y uno de ellos aborta. Las partidas ya están en disco al cerrar cada archivo.
    if (!plat::pump()) { fflush(nullptr); _exit(0); }
    w3d_dvd_poll();
#ifdef __3DS__
    w3d_zone_begin(W3D_Z_AUDIO_TICK); w3d_audio_tick(); w3d_zone_end(W3D_Z_AUDIO_TICK);
#else
    w3d_audio_tick();
#endif
    static const long fast = getenv("W3D_FAST") ? atol(getenv("W3D_FAST")) : -1;  // W3D_FAST=<retrazo>: desde ese retrazo no espera, para pruebas por lotes con W3D_FIXED_CLOCK
    bool paced = false;
#ifdef __3DS__
    // v34: en 3DS el cuadro va fijado a los retrazos de la pantalla (platform_3ds.cpp, w3d_frame_pace).
    if (fast < 0 || (long)g_retrace < fast) paced = w3d_frame_pace(frame_seconds());
#endif
    if (!paced) {
        double now = plat::now_seconds();
        if (g_next_frame == 0) g_next_frame = now;
        g_next_frame += frame_seconds();
        if (g_next_frame > now && (fast < 0 || (long)g_retrace < fast)) plat::sleep_seconds(g_next_frame - now); else g_next_frame = now;
    }
    g_retrace++;
    if (g_pre_retrace) ((void (*)(unsigned))g2h(g_pre_retrace))(g_retrace);
}
static long g_test_init = -1;  // retrazo del último Initialise de un guion de misión
extern "C" long w3d_test_since_init() { return g_test_init < 0 ? -1 : (long)g_retrace - g_test_init; }
extern "C" const char *w3d_test_lua_due(const char *name) {
    static const char *cfg = getenv("W3D_TEST_LUA");
    if (!cfg) return nullptr;
    static long since = -1;
    if (!strcmp(name, "Initialise")) { since = g_test_init = (long)g_retrace; fprintf(stderr, "[prueba] Initialise en retrazo %ld\n", since); }
    if (since < 0 || (long)g_retrace - since < atol(cfg)) return nullptr;
    since = -1;
    fprintf(stderr, "[prueba] trozo Lua en retrazo %ld\n", (long)g_retrace);
    return strchr(cfg, ':') + 1;
}
void A80303e2c(GA) {}                                                       // VIConfigure
void A803049e8(void) {}                                                    // VIFlush
void A80304b18(GA) {}                                                       // VISetNextFrameBuffer
void A80304b84(int) {}                                                     // VISetBlack
unsigned A80304c00(void) { return g_retrace; }                             // VIGetRetraceCount
unsigned A80304cac(void) { return 0; }                                     // VIGetNextField
unsigned A80304de0(void) { return 1; }                                     // VIGetTvFormat: PAL
}

// --- PAD ---
// Banco de armas: pruebas atadas al reloj de juego (motor+0x30, milisegundos), no a retrazos. port/tools/compare/armas.py hace lo mismo en Dolphin.
// W3D_CLOCK_KEYS="<ms>:<teclas>:<duración ms>,...": S A B X Y Z U D L R, l r (gatillos), h j k m (palanca: izquierda, abajo, arriba, derecha).
// W3D_CLOCK_WEAPON="<ms>:<arma>": le da munición y la elige como el panel, sin abrirlo.
// W3D_STATE_LOG="<archivo>:<cada ms>": reloj, generadores y vida y posición de 8 gusanos. W3D_CLOCK_EXIT=<ms>: termina ahí.
extern "C" {
extern w3d_u32 A804b178c, A8044a524[], A8044a5c4[], A804af684, A804b00c4, A804b00c8;
unsigned A8015f5a0(w3d_u32, int);
void A800f90e8(int, int, int);
Ptr32<void> A800fc330(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<char>>);
}
// Reloj de partida para la prueba automática de 3DS: 1 si hay partida y su
// reloj de juego en ms (vuelve a 0 al empezar cada partida).
// Cualquier gusano con vida (antes solo el 0: si moría, la prueba creía que no había partida).
extern "C" int w3d_match_clock(unsigned *ms) {
    if (!A804b178c) return 0;
    bool alive = false;
    for (int i = 0; i < 16 && !alive; i++) {
        w3d_u32 h = A8044a524[i];
        w3d_u32 *w = h ? (w3d_u32 *)g2h(*(w3d_u32 *)((char *)g2h(*(w3d_u32 *)((char *)g2h(h) + 4)) + 0x1c)) : nullptr;
        if (w && (int)w[0xa0 / 4] > 0) alive = true;
    }
    if (!alive) return 0;
    *ms = *(w3d_u32 *)((char *)g2h(A804b178c) + 0x30);
    return 1;
}
static void w3d_clock_test(uint8_t *s) {
    static const char *keys = getenv("W3D_CLOCK_KEYS"), *weapon = getenv("W3D_CLOCK_WEAPON"), *log = getenv("W3D_STATE_LOG"), *quit = getenv("W3D_CLOCK_EXIT");
    if ((!keys && !weapon && !log && !quit) || !A804b178c) return;
    const unsigned now = *(w3d_u32 *)((char *)g2h(A804b178c) + 0x30);
    w3d_u32 h0 = A8044a524[0], *w0 = h0 ? (w3d_u32 *)g2h(*(w3d_u32 *)((char *)g2h(*(w3d_u32 *)((char *)g2h(h0) + 4)) + 0x1c)) : nullptr;
    static bool started;  // solo con partida empezada: el reloj vuelve a 0 al empezarla
    if (w0 && (int)w0[0xa0 / 4] > 0) started = true;
    if (!started) return;
    for (const char *c = keys; c && *c;) {
        char *end; unsigned t = strtoul(c, &end, 10);
        const char *names = end + 1; const char *colon = strchr(names, ':');
        unsigned dur = strtoul(colon + 1, &end, 10);
        if (now >= t && now < t + dur) for (const char *n = names; n < colon; n++) {
            uint16_t &b = *(uint16_t *)s;
            switch (*n) {
            case 'S': b |= 0x1000; break; case 'A': b |= 0x100; break; case 'B': b |= 0x200; break;
            case 'X': b |= 0x400; break; case 'Y': b |= 0x800; break; case 'Z': b |= 0x10; break;
            case 'U': b |= 8; break; case 'D': b |= 4; break; case 'L': b |= 1; break; case 'R': b |= 2; break;
            case 'l': b |= 0x40; s[6] = 255; break; case 'r': b |= 0x20; s[7] = 255; break;
            case 'h': s[2] = (uint8_t)-100; break; case 'm': s[2] = 100; break; case 'k': s[3] = 100; break; case 'j': s[3] = (uint8_t)-100; break;
            }
        }
        c = strchr(end, ','); if (c) c++;
    }
    static bool chosen;
    if (weapon && !chosen && now >= strtoul(weapon, nullptr, 10)) {
        chosen = true;
        // Munición en el inventario del equipo (mismos bytes que 0x8025cbe0): si no hay, el juego devuelve el arma a la bazuca.
        char *team = (char *)g2h(*(w3d_u32 *)((char *)g2h(*(w3d_u32 *)((char *)g2h(A8044a5c4[((uint8_t *)w0)[0xd5]]) + 4)) + 0x1c));
        memset(team + 0x14, 5, 0x47 - 0x14);
        // Retraso en rondas por arma (0x800fcec8): sin esto no se pueden elegir el primer turno.
        Ptr32<const char> delays_name = "Inventory.WeaponDelays"; Ptr32<char> delays = nullptr;
        A800fc330(&delays_name, &delays);
        if (delays) memset((char *)delays.get() + 0x14, 0, 0x47 - 0x14);
        A800f90e8((unsigned short)A8015f5a0((w3d_u32)(uintptr_t)&A804af684, 1), atoi(strchr(weapon, ':') + 1), *(w3d_u32 *)((char *)g2h(A804b178c) + 0x34) + 10);
    }
    static FILE *out; static unsigned every, next;
    if (log && !out) { out = fopen(std::string(log, strrchr(log, ':') - log).c_str(), "w"); every = atoi(strrchr(log, ':') + 1); }
    if (out && now + every < next) next = 0;  // el reloj vuelve a 0 al empezar cada partida
    if (out && now >= next) {
        next = (now / every + 1) * every;
        fprintf(out, "%u r%u A%08x B%08x", now, g_retrace, A804b00c4, A804b00c8);
        for (int i = 0; i < 8; i++) {
            w3d_u32 h = A8044a524[i], *w = h ? (w3d_u32 *)g2h(*(w3d_u32 *)((char *)g2h(*(w3d_u32 *)((char *)g2h(h) + 4)) + 0x1c)) : nullptr;
            if (w) fprintf(out, " %d:%08x,%08x,%08x", (int)*(short *)((char *)w + 0xaa), w[0x50 / 4], w[0x54 / 4], w[0x58 / 4]);
        }
        fprintf(out, " W%d\n", A8044a524[0] ? (int)((w3d_u32 *)g2h(*(w3d_u32 *)((char *)g2h(*(w3d_u32 *)((char *)g2h(A8044a524[0]) + 4)) + 0x1c)))[0x84 / 4] : -1);
        fflush(out);
    }
    if (quit && now >= (unsigned)atoi(quit)) { fflush(nullptr); _exit(0); }
}
extern "C" {
void A8030110c(GA) {}                                                       // PADClamp
int A80301a90(unsigned) { return 1; }                                      // PADReset
int A80301ba0(unsigned) { return 1; }                                      // PADRecalibrate
int A80301cb4(void) { return 1; }                                          // PADInit
void w3d_fe_flush_commands(void);
unsigned w3d_franco_pad(unsigned buttons);   // core/native/francotirador.cpp: Y/Z acercan y B aleja con la mira puesta
unsigned A80301e04(GA status) {
    w3d_fe_flush_commands();                                             // PADRead: 4 entradas de 12 B.
    uint8_t *s = (uint8_t *)g2h(status);
    unsigned motor = 0;
    for (int i = 0; i < 4; i++, s += 12) {
        plat::Pad p; plat::pad_read(i, &p);
        memset(s, 0, 12);
        *(uint16_t *)s = p.buttons;
        s[2] = (uint8_t)p.stick_x; s[3] = (uint8_t)p.stick_y; s[4] = (uint8_t)p.cstick_x; s[5] = (uint8_t)p.cstick_y;
        s[6] = p.trigger_l; s[7] = p.trigger_r;
        s[10] = p.connected ? 0 : (uint8_t)-1;
        if (p.connected) motor |= 0x80000000u >> i;
    }
    w3d_clock_test((uint8_t *)g2h(status));
    // Francotirador de UM: zoom con Y/Z y B; con la mira puesta Y y Z no llegan. Después de las teclas de prueba.
    { uint16_t &b0 = *(uint16_t *)g2h(status); b0 = (uint16_t)w3d_franco_pad(b0); }
    return motor;
}
void A80302104(int, unsigned) {}                                           // PADControlMotor
}

// --- ARAM: 16 MB por páginas de 64 KB, que se reservan al escribirlas; copias al momento ---
// El juego coloca sus datos contando desde ARGetSize hacia abajo (en la consola, entre los 7,0 y los 8,5 MB de los 16) y
// en total escribe 1,5 MB. Reservar los 16 MB de una vez, del mismo montón que la arena y la UI, dejaba a la UI de 3DS
// sin memoria (bad_alloc), y anunciar menos tamaño mueve esos datos a direcciones negativas (se perdían). Una página que
// nunca se escribió se lee como ceros.
namespace { const unsigned kAram = 16u << 20, kAramBase = 0x4000, kAramPage = 64u << 10; uint8_t *g_aram_page[kAram / kAramPage]; unsigned g_aram_pages; }
static void aram_copy(bool to_aram, unsigned at, uint8_t *host, unsigned len) {
    while (len) {
        const unsigned i = at / kAramPage, off = at % kAramPage, n = len < kAramPage - off ? len : kAramPage - off;
        uint8_t *&page = g_aram_page[i];
        if (!page && to_aram) {
            page = (uint8_t *)arena_alloc(kAramPage);
            if (!page) { fprintf(stderr, "[aram] sin memoria para la página %u\n", i); return; }
            memset(page, 0, kAramPage); g_aram_pages++;
        }
        if (to_aram) memcpy(page + off, host, n);
        else if (page) memcpy(host, page + off, n);
        else memset(host, 0, n);
        at += n; host += n; len -= n;
    }
}
extern "C" {
unsigned A80311c44(GA, unsigned) { return kAramBase; }                     // ARInit
unsigned A80311d08(void) { return kAramBase; }                             // ARGetBaseAddress
unsigned A80311d10(void) { return kAram; }                                 // ARGetSize
void A80313754(void) {}                                                    // ARQInit
void A803137c4(GA req, unsigned, unsigned type, unsigned, unsigned src, unsigned dst, unsigned len, GA cb) {  // ARQPostRequest
    const unsigned at = type == 0 ? dst : src;
    if (at > kAram || len > kAram - at) {                 // Fuera de la ARAM: se avisa y no se copia.
        static int said; if (said++ < 4) fprintf(stderr, "[aram] fuera de rango: %08x + %u\n", at, len);
    } else {
        const unsigned before = g_aram_pages;
        aram_copy(type == 0, at, (uint8_t *)g2h(type == 0 ? src : dst), len);   // 0: memoria principal a ARAM
        if (g_aram_pages != before && (g_aram_pages & 7) == 0) fprintf(stderr, "[aram] %u KB reservados\n", g_aram_pages * (kAramPage >> 10));
    }
    if (cb) ((void (*)(GA))g2h(cb))(req);
}
}

// --- Matrices ---
extern "C" {
void A80302b60(GA gm) {                                                     // PSMTXIdentity
    float *m = (float *)g2h(gm); memset(m, 0, 48); m[0] = m[5] = m[10] = 1;
}
void A80302b8c(GA ga, GA gb, GA gab) {                                        // PSMTXConcat
    const float *a = (float *)g2h(ga), *b = (float *)g2h(gb); float t[12];
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 4; c++) {
            t[r * 4 + c] = a[r * 4] * b[c] + a[r * 4 + 1] * b[4 + c] + a[r * 4 + 2] * b[8 + c] + (c == 3 ? a[r * 4 + 3] : 0.f);
        }
    }
    memcpy(g2h(gab), t, 48);
}
void A80302c58(GA gs, GA gd) {                                               // PSMTXTranspose
    const float *s = (float *)g2h(gs); float t[12];
    t[0] = s[0]; t[1] = s[4]; t[2] = s[8]; t[3] = 0; t[4] = s[1]; t[5] = s[5]; t[6] = s[9]; t[7] = 0; t[8] = s[2]; t[9] = s[6]; t[10] = s[10]; t[11] = 0;
    memcpy(g2h(gd), t, 48);
}
unsigned A80302ca8(GA gs, GA gd) {                                           // PSMTXInverse
    const float *m = (float *)g2h(gs);
    float d = m[0] * (m[5] * m[10] - m[6] * m[9]) - m[1] * (m[4] * m[10] - m[6] * m[8]) + m[2] * (m[4] * m[9] - m[5] * m[8]);
    if (d == 0.f) return 0;
    float i = 1.f / d, t[12];
    t[0] = (m[5] * m[10] - m[6] * m[9]) * i; t[1] = (m[2] * m[9] - m[1] * m[10]) * i; t[2] = (m[1] * m[6] - m[2] * m[5]) * i;
    t[4] = (m[6] * m[8] - m[4] * m[10]) * i; t[5] = (m[0] * m[10] - m[2] * m[8]) * i; t[6] = (m[2] * m[4] - m[0] * m[6]) * i;
    t[8] = (m[4] * m[9] - m[5] * m[8]) * i; t[9] = (m[1] * m[8] - m[0] * m[9]) * i; t[10] = (m[0] * m[5] - m[1] * m[4]) * i;
    t[3] = -(t[0] * m[3] + t[1] * m[7] + t[2] * m[11]); t[7] = -(t[4] * m[3] + t[5] * m[7] + t[6] * m[11]); t[11] = -(t[8] * m[3] + t[9] * m[7] + t[10] * m[11]);
    memcpy(g2h(gd), t, 48);
    return 1;
}
unsigned A80302da0(GA gs, GA gd) {                                           // PSMTXInvXpose
    float inv[12];
    if (!A80302ca8(gs, h2g(inv))) return 0;
    float t[12] = {inv[0], inv[4], inv[8], 0, inv[1], inv[5], inv[9], 0, inv[2], inv[6], inv[10], 0};
    memcpy(g2h(gd), t, 48);
    return 1;
}
void A80302e68(GA gm, float x, float y, float z) {                          // PSMTXTrans
    float *m = (float *)g2h(gm); memset(m, 0, 48); m[0] = m[5] = m[10] = 1; m[3] = x; m[7] = y; m[11] = z;
}
void A80302e9c(GA gm, float x, float y, float z) {                          // PSMTXScale
    float *m = (float *)g2h(gm); memset(m, 0, 48); m[0] = x; m[5] = y; m[10] = z;
}
void A80302ec4(GA gm, float t, float b, float l, float r, float n, float f) {  // C_MTXOrtho
    float *m = (float *)g2h(gm); memset(m, 0, 64);
    m[0] = 2.f / (r - l); m[3] = -(r + l) / (r - l); m[5] = 2.f / (t - b); m[7] = -(t + b) / (t - b);
    m[10] = -1.f / (f - n); m[11] = -f / (f - n); m[15] = 1;
}
}

// --- Resto de OS, depurador y UART ---
extern "C" {
void A802f9420(void) {}                                                     // __OSFPRInit
void A802f9e78(void) {}                                                     // __OSPSInit
void A802faecc(void) {}                                                     // __OSCacheInit
void A80300b24(void) {}                                                     // __init_user
void A802fc330(GA, GA, GA msg) {                                            // OSFatal
    fflush(stdout);
    fprintf(stderr, "[OSFatal] %s\n", msg ? (const char *)g2h(msg) : "");
    exit(4);
}
// Fuente de la ROM de la consola: no existe aquí. Solo la usa el texto de depuración, que avanza sin dibujar.
unsigned A802fce18(void) { return 0; }                                      // OSGetFontEncode: ANSI
int A802fd8e4(GA) { return 1; }                                             // OSInitFont
GA A802fd9c4(GA s, GA image, GA x, GA y, GA width) {                        // OSGetFontTexture
    if (image) *(w3d_u32 *)g2h(image) = 0;
    if (x) *(int *)g2h(x) = 0;
    if (y) *(int *)g2h(y) = 0;
    if (width) *(int *)g2h(width) = 12;
    return s + 1;
}
int A802e34f4(int) { return 0; }                                            // Inicio del depurador SN: no hay depurador.
int A802e4cd4(void) { return 0; }                                           // PCinit
int A802e4cdc(GA, int) { return -1; }                                       // PCcreat
int A802e4ce4(GA, int, int) { return -1; }                                  // PCopen
int A802e4cec(int) { return -1; }                                           // PCclose
int A802e4cf4(int, GA, int) { return -1; }                                  // PCread
int A802e4cfc(int, GA, int) { return -1; }                                  // PCwrite
int A802e4d04(int, int, int) { return -1; }                                 // PClseek
unsigned A8030f78c(unsigned) { return 0; }                                  // InitializeUART
unsigned A8030f7fc(GA, unsigned) { return 0; }                              // WriteUARTN
}
