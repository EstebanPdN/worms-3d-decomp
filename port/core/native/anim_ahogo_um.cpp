#ifdef W3D_PUBLIC
#include "parches_vfs.h"
extern "C" {
int w3d_anim_um_quiere(const char *) { return 0; }
int w3d_anim_um_tramos(W3dLeer, void *, unsigned, const W3dTramo **, int *) { return 0; }
const char *w3d_anim_um_clip(int) { return ""; }
int w3d_anim_um_entra(int) { return 0; }
int w3d_anim_um_activo(int) { return 0; }
int w3d_anim_um_sale(int) { return 0; }
float w3d_anim_um_peso(int) { return 0; }
float w3d_anim_um_tiempo(float) { return 0; }
}
#else
// Animación de ahogo de Worms Ultimate Mayhem (UM) en el worm de Worms 3D (v26, pedido del dueño el 2026-11-05).
// Investigación y retarget: docs/ahogo-ultimate-mayhem.md, sección "v26, animación"; datos de mods/ahogo-um/tools.
// Francotirador de UM: el mismo parche lleva además DrawSniper, AimSniper y FireSniper, las animaciones del worm
// con el fusil de UM llevadas al worm de W3D (mods/armas-um/francotirador/anim/), que usa el contenedor del arma 28
// (AnimDraw, AnimAim y AnimFire de WeapTwk.xom, francotirador.cpp). Los cinco clips y las posiciones del archivo
// salen de mods/armas-um/francotirador/anim/hacer_inc.py y hacer_tramos.py (anim_ahogo_um.inc y _tramos.inc).
//
// En UM (WXWormGraphicEntity, estado gráfico 8) el clip FallDrown no se reproduce: cada cuadro se fija en el tiempo
// t = 1 + clamp(10 · v.y, -1, 1), con v.y la velocidad vertical en unidades por ms (0x5A06B0), y con un peso w que
// sube de 0 a 1 (0x47A1A0 con objetivo 1, factor 2 y paso máximo 0,3). Debajo sigue la postura Base con peso 1.
//
// 1. Datos. Al abrir Bundles/bundle04.xom, los VFS de Mac y 3DS (platform/common/vfs.cpp, platform/3ds/vfs_3ds.cpp,
//    vía core/native/parches_vfs.cpp) lo leen entero y lo sirven desde memoria con dos clips de ahogo más en la
//    biblioteca del worm (XCULLEDBoggyB; en total cinco, con los tres del francotirador detrás): FallDrownBase
//    (Neutral_pose con los ojos cerrados y las muñecas a escala 1, ocultas por la del hombro) y FallDrown (la postura
//    de UM llevada al esqueleto de W3D, t de 0 a 2). Formato del XOM:
//    cabecera de 64 B, tabla de tipos de 64 B por tipo,
//    GUID y SCHM (32 B), STRS (u32 cuenta, u32 bytes, un u32 de desplazamiento por texto y los textos) y los objetos
//    seguidos, sin direcciones absolutas. Los descriptores y las bibliotecas van sin CTNR delante del resto
//    (formato de una biblioteca en mods/ahogo-um/tools/xomlib.py). El parche añade los nombres al final de STRS,
//    suma kAnimClips a la cuenta de clips de XCULLEDBoggyB y pone los clips al final de su lista: ningún índice de clip
//    existente cambia. Si la biblioteca no es la del disco (cuenta o FNV-1a de sus enlaces, ver el .inc), o ya
//    tiene esos clips, el archivo se sirve tal cual.
//    Memoria: el archivo se sirve por tramos (w3d_anim_um_tramos): solo lo nuevo queda en memoria. El parche
//    entero (4,66 MB guardados toda la partida y un pico de unos 9 MB) no cabía en la consola. Los cuerpos de los
//    clips se sirven desde kAnimCuerpo (datos de solo lectura del ejecutable), sin copia; en memoria aparte solo van
//    las cuentas, los desplazamientos, los nombres y la cabecera de cada clip (menos de 200 bytes).
// 2. Cada cuadro, d31d_worm_graphic_state_80135c20 (estado gráfico 33, el del ahogo que flota): si al entrar
//    w3d_ahogo_um_get() (core/native/ahogo.cpp, interruptor de la pantalla de abajo) está activo y el parche se
//    aplicó, en vez de Drown_Shallow pone FallDrown con peso w en el tiempo t de la velocidad publicada del worm y
//    FallDrownBase con peso 1 - w. W3D suma los clips por su peso sin promediar (0x80195EA8): con 1 - w y w queda
//    base + w · (ahogo - base), lo que UM hace con Base + w · FallDrown. Al salir del estado, los dos a peso 0.
//    Un worm que ya flota sigue como entró aunque cambie el interruptor.
// W3D_ANIM_UM=0 (entorno o debug.ini) no parchea el bundle; entonces el estado 33 usa siempre Drown_Shallow.
// Para 3DS (ARM de 32 bits): solo enteros, float y punteros como argumentos y resultados.
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "parches_vfs.h"

extern "C" void w3d_dbg(const char *, ...);
extern "C" int w3d_ahogo_um_get(void);

namespace {
#include "anim_ahogo_um.inc"
#include "anim_ahogo_um_tramos.inc"

uint32_t rd32(const unsigned char *p) { return (uint32_t)p[0] | (uint32_t)p[1] << 8 | (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24; }
void wr32(unsigned char *p, uint32_t v) { p[0] = (unsigned char)v; p[1] = (unsigned char)(v >> 8); p[2] = (unsigned char)(v >> 16); p[3] = (unsigned char)(v >> 24); }

// Lector con límites: al salirse, ok queda en false y todo devuelve 0.
struct Lector {
    const unsigned char *p, *fin;
    bool ok;
    bool hay(uint32_t n) { if (!ok || (uint32_t)(fin - p) < n) ok = false; return ok; }
    void saltar(uint32_t n) { if (hay(n)) p += n; }
    uint32_t u8() { if (!hay(1)) return 0; return *p++; }
    uint32_t u32() { if (!hay(4)) return 0; uint32_t v = rd32(p); p += 4; return v; }
    uint32_t var() {
        uint32_t v = 0;
        for (int i = 0; i < 5; i++) {
            uint32_t c = u8();
            v |= (c & 127u) << (7 * i);
            if (!(c & 128u)) return v;
        }
        ok = false;
        return 0;
    }
};

bool termina_en(const char *s, const char *sufijo) {
    size_t a = strlen(s), b = strlen(sufijo);
    if (a < b) return false;
    s += a - b;
    for (size_t i = 0; i < b; i++) {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') c += 32;
        if (c == '\\') c = '/';
        if (c != sufijo[i]) return false;
    }
    return a == b || s[-1] == '/' || s[-1] == '\\';
}

uint32_t fnv1a(const unsigned char *p, uint32_t n) {
    uint32_t h = 2166136261u;
    for (uint32_t i = 0; i < n; i++) h = (h ^ p[i]) * 16777619u;
    return h;
}

int var_bytes(uint32_t v, unsigned char *out) {
    int n = 0;
    do { unsigned char b = v & 127u; v >>= 7; if (v) b |= 128u; out[n++] = b; } while (v);
    return n;
}

// Tabla de cadenas del archivo de entrada.
struct Cadenas {
    const unsigned char *offs, *blob;
    uint32_t n, len;
    // Texto i, o nullptr si se sale de la tabla.
    const char *texto(uint32_t i) const {
        if (i >= n) return nullptr;
        uint32_t o = rd32(offs + 4 * i);
        if (o >= len) return nullptr;
        const void *z = memchr(blob + o, 0, len - o);
        return z ? (const char *)(blob + o) : nullptr;
    }
};

bool igual_tipo(const unsigned char *t, const char *nombre) {
    size_t n = strlen(nombre);
    return n < 32 && !memcmp(t + 32, nombre, n) && t[32 + n] == 0;
}

// Salta los descriptores de un bundle de W3D (van sin CTNR); deja r en la primera biblioteca y devuelve cuántas hay,
// o -1 si aparece un tipo que no se sabe saltar.
int saltar_descriptores(Lector &r, const unsigned char *tipos, uint32_t nt) {
    for (uint32_t i = 0; i < nt && r.ok; i++) {
        const unsigned char *t = tipos + 64 * i;
        uint32_t n = rd32(t + 8);
        if (igual_tipo(t, "XBitmapDescriptor")) { for (uint32_t k = 0; k < n; k++) { r.var(); r.u8(); r.var(); r.saltar(4); } }
        else if (igual_tipo(t, "XCustomDescriptor")) { for (uint32_t k = 0; k < n; k++) { r.var(); r.u8(); r.saltar(2); } }
        else if (igual_tipo(t, "XMeshDescriptor")) { for (uint32_t k = 0; k < n; k++) { r.var(); r.u8(); r.var(); r.saltar(2); } }
        else if (igual_tipo(t, "XSpriteSetDescriptor")) { for (uint32_t k = 0; k < n; k++) { r.var(); r.u8(); r.var(); } }
        else if (igual_tipo(t, "XBaseResourceDescriptor")) { if (n) return -1; }
        else if (igual_tipo(t, "XAnimClipLibrary")) return (int)n;
        else return -1;
    }
    return -1;
}

bool g_parcheado;   // bundle04 servido con los clips de UM
bool g_init, g_activo = true;

struct Worm { int activo; float w; };
Worm g_worm[32];
Worm *worm(int i) { return (unsigned)i < 32u ? &g_worm[i] : nullptr; }

void init() {
    if (g_init) return;
    g_init = true;
    if (const char *e = getenv("W3D_ANIM_UM")) g_activo = atoi(e) != 0;
}
}

extern "C" {
// Interruptor del parche: W3D_ANIM_UM=0 lo apaga.
int w3d_anim_um_quiere(const char *path) {
    init();
    return g_activo && path && termina_en(path, "bundles/bundle04.xom");
}

// Sirve bundle04.xom por tramos (forma 2 de parches_vfs.h): lo que no cambia se lee del archivo del disco y solo lo
// nuevo (cuentas de STRS, los desplazamientos y los nombres nuevos, la cuenta de clips y los clips) se sirve desde
// memoria: la cabecera de cada clip (duración e índice del nombre) de un búfer pequeño y su cuerpo directamente de
// kAnimCuerpo. Las posiciones son las del archivo del disco (anim_ahogo_um_tramos.inc,
// mods/armas-um/francotirador/anim/hacer_tramos.py, que comprueba que estos tramos dan el mismo archivo que el parche
// entero). Antes de servirlo se reconoce con lecturas pequeñas: tamaño, FNV-1a de la cabecera hasta la de STRS, FNV
// de los enlaces de XCULLEDBoggyB y su cuenta de clips. Si algo no coincide (otro disco, un mod), el archivo se sirve
// tal cual. Devuelve 1 con los tramos.
int w3d_anim_um_tramos(W3dLeer leer, void *ctx, unsigned size, const W3dTramo **tramos, int *n) {
    enum { kTramos = 10 + 2 * kAnimClips };
    static W3dTramo t[kTramos];
    static unsigned char cuentas[8], desp[4 * kAnimClips], nombres[32 * kAnimClips], cuenta[4], cab[12 * kAnimClips];
    if (g_parcheado) { *tramos = t; *n = kTramos; return 1; }
    if (size != kB04Tam) { w3d_dbg("[anim-um] bundle04: %u bytes, no %u: sin parche\n", size, kB04Tam); return 0; }
    static unsigned char ini[kB04Strs + 12], enl[kAnimEnlacesBytes + 4];
    static_assert(kB04Enlaces + kAnimEnlacesBytes == kB04Cuenta, "los enlaces acaban en la cuenta de clips");
    if (!leer(ctx, 0, ini, sizeof ini) || fnv1a(ini, sizeof ini) != kB04CabFnv || memcmp(ini, "MOIK\0\0\0\2", 8) ||
        memcmp(ini + kB04Strs, "STRS", 4) || rd32(ini + kB04Strs + 4) != kB04Textos || rd32(ini + kB04Strs + 8) != kB04TextosBytes) {
        w3d_dbg("[anim-um] bundle04: la cabecera no es la del disco, sin parche\n");
        return 0;
    }
    if (!leer(ctx, kB04Enlaces, enl, sizeof enl) || fnv1a(enl, kAnimEnlacesBytes) != kAnimEnlacesFnv ||
        rd32(enl + kAnimEnlacesBytes) != kB04Clips) {
        w3d_dbg("[anim-um] bundle04: %s no es la del disco, sin parche\n", kAnimLib);
        return 0;
    }
    // Lo nuevo, como el parche entero: los nombres al final de STRS, la cuenta de clips + kAnimClips y los clips al
    // final de la biblioteca (duración, índice del nombre y cuerpo).
    uint32_t texto = 0;
    for (int k = 0; k < kAnimClips; k++) {
        size_t l = strlen(kAnimNombre[k]) + 1;
        if (texto + l > sizeof nombres) return 0;
        wr32(desp + 4 * k, kB04TextosBytes + texto);
        memcpy(nombres + texto, kAnimNombre[k], l);
        texto += (uint32_t)l;
    }
    wr32(cuentas, kB04Textos + kAnimClips); wr32(cuentas + 4, kB04TextosBytes + texto);
    wr32(cuenta, kB04Clips + kAnimClips);
    W3dTramo lista[kTramos] = {
        {nullptr, 0, kB04Strs + 4},
        {cuentas, 0, 8},
        {nullptr, kB04Strs + 12, kB04FinDesp - (kB04Strs + 12)},
        {desp, 0, 4u * kAnimClips},
        {nullptr, kB04FinDesp, kB04FinTextos - kB04FinDesp},
        {nombres, 0, texto},
        {nullptr, kB04FinTextos, kB04Cuenta - kB04FinTextos},
        {cuenta, 0, 4},
        {nullptr, kB04Cuenta + 4, kB04FinLib - (kB04Cuenta + 4)},
    };
    const unsigned char *cuerpo = kAnimCuerpo;
    uint32_t en_memoria = 8 + 4 * kAnimClips + texto + 4;
    for (int k = 0; k < kAnimClips; k++) {
        unsigned char *c = cab + 12 * k;
        uint32_t d;
        memcpy(&d, &kAnimDuracion[k], 4);
        wr32(c, d);
        int nc = 4 + var_bytes(kB04Textos + k, c + 4);
        lista[9 + 2 * k] = {c, 0, (unsigned)nc};
        lista[10 + 2 * k] = {cuerpo, 0, kAnimCuerpoTam[k]};
        cuerpo += kAnimCuerpoTam[k];
        en_memoria += (uint32_t)nc;
    }
    lista[kTramos - 1] = {nullptr, kB04FinLib, kB04Tam - kB04FinLib};
    uint32_t total = 0;
    for (int i = 0; i < kTramos; i++) { t[i] = lista[i]; total += lista[i].bytes; }
    if (total != kB04Parcheado) { w3d_dbg("[anim-um] bundle04: %u bytes por tramos, no %u: sin parche\n", total, kB04Parcheado); return 0; }
    g_parcheado = true;
    w3d_dbg("[anim-um] bundle04: %d clips añadidos a %s (%s...%s), servido por tramos (%u bytes en memoria, %u de clips "
            "en el ejecutable)\n", kAnimClips, kAnimLib, kAnimNombre[0], kAnimNombre[kAnimClips - 1],
            (unsigned)en_memoria, (unsigned)sizeof kAnimCuerpo);
    *tramos = t; *n = kTramos;
    return 1;
}

// Nombre del clip k: 0 la base (peso 1 - w), 1 el ahogo de UM (peso w, tiempo t).
const char *w3d_anim_um_clip(int k) { return k == 1 ? kAnimNombre[1] : kAnimNombre[0]; }

// d31d, al entrar en el estado gráfico 33: 1 si este worm hace la animación de UM (interruptor activo y clips en el
// bundle). Lo apunta para todo el ahogo.
int w3d_anim_um_entra(int n) {
    init();
    Worm *m = worm(n);
    if (!m) return 0;
    m->activo = g_parcheado && w3d_ahogo_um_get();
    m->w = 0.0f;                     // 0x5A3620, animación 21: peso de FallDrown a 0
    if (m->activo) w3d_dbg("[anim-um] worm %d: postura de ahogo de UM\n", n);
    return m->activo;
}
int w3d_anim_um_activo(int n) { Worm *m = worm(n); return m && m->activo; }
// Al salir del estado 33: 1 si el worm tenía la animación de UM (hay que poner sus clips a peso 0).
int w3d_anim_um_sale(int n) {
    Worm *m = worm(n);
    if (!m || !m->activo) return 0;
    m->activo = 0;
    return 1;
}
// Peso de FallDrown en este cuadro; deja preparado el del siguiente como 0x47A1A0(w, 1, 2, 0,3).
float w3d_anim_um_peso(int n) {
    Worm *m = worm(n);
    if (!m) return 0.0f;
    float w = m->w;
    float nuevo = (1.0f + 2.0f * w) / 3.0f;
    if (0.3f < nuevo - w) m->w = w + 0.3f;
    else if (0.3f < w - nuevo) m->w = w - 0.3f;
    else m->w = nuevo;
    return w;
}
// Tiempo de FallDrown para la velocidad vertical vy (unidades por ms), como 0x5A06B0.
float w3d_anim_um_tiempo(float vy) {
    float x = vy * 10.0f;
    if (!(x < 1.0f)) x = 1.0f;
    if (x < -1.0f) x = -1.0f;
    return x + 1.0f;
}
}

#endif
