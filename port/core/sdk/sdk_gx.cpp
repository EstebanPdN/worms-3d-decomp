// GX sobre Metal: las 85 funciones que el juego llama, con su dirección original en el símbolo.
// Nombres y firmas: port/docs-data/sdk-boundary.json. El estado y el backend están en platform/gx/.
//
// ABI: un puntero del invitado llega como 32 bits en un registro. GXColor llega de dos formas según la unidad
// que llama: por valor (r en el byte bajo de x0/x1, arm64 lo pasa así por ser agregado pequeño) o como puntero a
// una variable local, que es lo que hacía PPC (d30j_begin_frame_8016743c, autof_80160038, d27l_movie_gx_setup).
// Ambas declaraciones dan i64 en el IR, así que color_arg lo distingue: un puntero así apunta a la pila del
// llamador, justo por encima de este marco, y ningún color cae en esa ventana salvo por una coincidencia exacta.
#include "../../platform/gx/gx_internal.h"
#include "../../platform/gx/gx_mt.h"
#include "w3d_ptr.h"
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace w3d;
using namespace w3d::gx;
typedef w3d_u32 GA;

namespace {

#if W3D_POINTER_64
typedef uint64_t ColorArg;
struct S10Arg { uint64_t raw; };
inline bool is_stack_ptr(uint64_t raw) {
    uintptr_t p = kWindow | (u32)raw;
    uintptr_t fp = (uintptr_t)__builtin_frame_address(0);
    // Un puntero a una local siempre está alineado; un color como 0x6cffffff (blanco, alfa animada) cae en la ventana.
    return (p & 3) == 0 && p >= fp && p - fp < (256u << 10);
}

inline void color_arg(uint64_t raw, u8 *rgba) {
    if (is_stack_ptr(raw)) memcpy(rgba, g2h((u32)raw), 4);
    else { u32 v = (u32)raw; memcpy(rgba, &v, 4); }
}

inline void color_s10_arg(S10Arg a, s16 *rgba) {
    uint64_t raw = a.raw;
    if (is_stack_ptr(raw)) memcpy(rgba, g2h((u32)raw), 8);
    else memcpy(rgba, &raw, 8);
}
#else
// ARM: GXColor por valor es una palabra en un registro; GXColorS10, dos. El puntero a una local llega en la primera.
typedef u32 ColorArg;
struct S10Arg { u32 a, b; };
inline bool is_stack_ptr(u32 p) {
    uintptr_t fp = (uintptr_t)__builtin_frame_address(0);
    return (p & 3) == 0 && p >= fp && p - fp < (256u << 10);
}
inline void color_arg(u32 raw, u8 *rgba) {
    if (is_stack_ptr(raw)) memcpy(rgba, g2h(raw), 4);
    else memcpy(rgba, &raw, 4);
}
inline void color_s10_arg(S10Arg v, s16 *rgba) {
    if (is_stack_ptr(v.a)) memcpy(rgba, g2h(v.a), 8);
    else memcpy(rgba, &v, 8);
}
#endif

struct GFifoObj { u32 words[32]; } g_fifo_obj;

// v34: las funciones de estado que el juego repite en cada dibujo con los mismos valores (unas 16 por dibujo, vistas con
// W3D_TOUCH_LOG: TEV, canales, paleta, textura, formato de vértices, matrices) ya no hacen nada si el valor no cambia: ni
// vacían el lote ni suben la generación del estado (g_state_gen). Con la generación igual, draw3ds (gx_pica.cpp) se salta
// el trabajo del estado. Las de matrices, arrays y formato de vértices usan touch_keep(): vacían el lote pero no suben la
// generación (draw3ds no las lee en una lista residente: las matrices se rehacen en cada dibujo, y el formato y los arrays
// van en la clave de la lista).
template <class T> inline bool same(const T &a, const T &b) { return !memcmp(&a, &b, sizeof(T)); }

// v36, GX en otro núcleo (platform/gx/gx_mt.h). En este archivo `g` es el estado que escribe el hilo del juego
// (mt::front): el mismo objeto que lee el backend con la cola apagada, y una copia propia con la cola activa. Con la
// cola activa cada función compara con esa copia, como antes, y manda solo lo que cambia: TOUCH/TOUCH_KEEP no hacen
// nada aquí (el touch lo hace el otro hilo antes de copiar) y SENT* graban los bytes del campo.
#define g (*w3d::gx::mt::front)
#define TOUCH() do { if (!mt::on) touch(); } while (0)
#define TOUCH_KEEP() do { if (!mt::on) touch_keep(); } while (0)
#define SENT(f) do { if (mt::on) mt::patch(&(f), sizeof(f), 1); } while (0)
#define SENT_KEEP(f) do { if (mt::on) mt::patch(&(f), sizeof(f), 2); } while (0)
#define SENT_RAW(f) do { if (mt::on) mt::patch(&(f), sizeof(f), 0); } while (0)
#define SENT_N(p, n, k) do { if (mt::on) mt::patch((p), (n), (k)); } while (0)

// Valores de __GXInitGX (0x80305b0c), en el mismo orden en que los pone el original.
void gx_defaults(u32 width, u32 efb_height, u32 xfb_height);

}  // namespace

extern "C" {
// --- Vértices ---
void A80306cd0(int attr, int type);
void A80307558(void);
void A80307590(int fmt, int attr, int cnt, int type, int frac);
void A80307d88(int attr, GA base, int stride);
void A80307e24(int dst, int func, int src, unsigned mtx, int normalize, unsigned post);
void A803080a4(int n);
void A8030c094(unsigned id);
void A8030bff4(GA m, unsigned id);
void A8030c044(GA m, unsigned id);
void A8030c0c8(GA m, unsigned id, int type);
void A8030c264(float l, float t, float w, float h, float n, float f);
void A80308be8(int mode);
void A8030c2ac(unsigned l, unsigned t, unsigned w, unsigned h);
void A8030990c(int n);
void A80309948(int chan, int enable, int amb, int mat, unsigned mask, int diff, int attn);
void A8030972c(int chan, ColorArg c);
void A8030981c(int chan, ColorArg c);
void A80309c88(GA o, GA img, unsigned w, unsigned h, unsigned fmt, unsigned s, unsigned t, int mip);
void A8030a21c(GA o, int id);
void A8030a46c(void);
void A8030b4ac(int s, int coord, int map, int color);
void A8030b648(int n);
void A8030af88(int s, int mode);
void A8030b3dc(int c0, int r0, int op, int c1, int r1);
void A8030b25c(int s, int sel);
void A8030b2b8(int s, int sel);
void A8030b314(int s, int ras, int tex);
void A8030b35c(int t, int r, int g_, int b, int a);
void A8030ae84(int s);
void A8030ae60(int n);
void A8030ac30(int s, int ss, int st);
void A8030b9b8(int t, int src, int dst, int op);
void A8030ba0c(int en);
void A8030ba38(int en);
void A8030ba64(int cmp, unsigned func, int upd);
void A8030ba98(int before);
void A8030bacc(int pix, int z);
void A80308fc0(ColorArg c, unsigned z);
void A80308dc8(unsigned l, unsigned t, unsigned w, unsigned h);
void A80308e44(unsigned w, unsigned h);
unsigned A80308ef4(float vscale);
void A80309038(int aa, GA sample, int vf, GA vfilter);
void A80309240(int gamma);
}

namespace {

void gx_defaults(u32 width, u32 efb_height, u32 xfb_height) {
    memset(&g, 0, sizeof g);
    u8 clear[4] = {0x40, 0x40, 0x40, 0xff};
    ColorArg rawc;
    { u32 v; memcpy(&v, clear, 4); rawc = v; }
    A80308fc0(rawc, 0xffffff);
    for (int i = 0; i < 8; i++) A80307e24(i, 1, 4 + i, 0x3c, 0, 0x7d);
    A803080a4(1);
    A80307558();
    for (int a = 9; a < 25; a++) A80307d88(a, 0, 0);
    for (int f = 0; f < 8; f++) {
        // Tabla 0x80407ba0: posición, normal y demás con los valores nulos de __GXSetVAT.
        A80307590(f, VA_POS, 1, 4, 0);
        A80307590(f, VA_NRM, 0, 4, 0);
        A80307590(f, VA_CLR0, 1, 5, 0);
        A80307590(f, VA_CLR1, 1, 5, 0);
        for (int t = 0; t < 8; t++) A80307590(f, VA_TEX0 + t, 1, 4, 0);
    }
    float id[12] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0};
    A8030bff4(h2g(id), 0);
    A8030c044(h2g(id), 0);
    A8030c094(0);
    A8030c0c8(h2g(id), 0x3c, 0);
    A8030c0c8(h2g(id), 0x7d, 0);
    A8030c264(0, 0, (float)width, (float)xfb_height, 0, 1);
    // Proyección por defecto de __GXData (0x80407c70): identidad ortográfica no tiene efecto práctico: el juego la fija.
    g.proj[0] = 1; g.proj[2] = 1; g.proj[4] = 1; g.proj_type = 1;
    A80308be8(2);
    A8030c2ac(0, 0, width, efb_height);
    A8030990c(0);
    A80309948(4, 0, 0, 1, 0, 0, 2);
    { u32 black = 0; A8030972c(4, black); u32 white = 0xffffffffu; A8030981c(4, white); }
    A80309948(5, 0, 0, 1, 0, 0, 2);
    { u32 black = 0; A8030972c(5, black); u32 white = 0xffffffffu; A8030981c(5, white); }
    A8030a46c();
    static const int orders[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 8; i++) A8030b4ac(i, orders[i], orders[i], 4);
    for (int i = 8; i < 16; i++) A8030b4ac(i, 0xff, 0xff, 0xff);
    A8030b648(1);
    A8030af88(0, 3);
    A8030b3dc(7, 0, 0, 7, 0);
    for (int i = 0; i < 16; i++) { A8030b25c(i, 6); A8030b2b8(i, 0); A8030b314(i, 0, 0); }
    A8030b35c(0, 0, 1, 2, 3);
    A8030b35c(1, 0, 0, 0, 3);
    A8030b35c(2, 1, 1, 1, 3);
    A8030b35c(3, 2, 2, 2, 3);
    for (int i = 0; i < 16; i++) A8030ae84(i);
    A8030ae60(0);
    for (int i = 0; i < 4; i++) A8030ac30(i, 0, 0);
    A8030b9b8(0, 4, 5, 0);
    A8030ba0c(1);
    A8030ba38(1);
    A8030ba64(1, 3, 1);
    A8030ba98(1);
    A8030bacc(0, 0);
    A80308dc8(0, 0, width, efb_height);
    A80308e44(width, efb_height);
    A80308ef4((float)xfb_height / (float)efb_height);
    static const u8 vf_identity[7] = {0, 0, 21, 22, 21, 0, 0};
    memcpy(g.vfilter, vf_identity, 7);
    A80309240(0);
}

}  // namespace

extern "C" {

// --- Inicio, FIFO y sincronización ---
GA A80305374(GA, unsigned) {  // GXInit: sin FIFO real, devuelve un objeto opaco.
    backend::init();
    // El juego fija el modo de vídeo después; PAL 640x528 es el mayor que usa.
    mt::drain();
    gx_defaults(640, 528, 528);
    TOUCH();   // v34: generación nueva (gx_defaults borra el estado entero)
    SENT_N(&g, sizeof(State), 1);   // v36: el estado entero
    return h2g(&g_fifo_obj);
}
void A803069fc(GA overhi, GA underlow, GA read_idle, GA cmd_idle, GA brkpt) {  // GXGetGPStatus: siempre inactivo.
    if (overhi) *(u8 *)g2h(overhi) = 0;
    if (underlow) *(u8 *)g2h(underlow) = 1;
    if (read_idle) *(u8 *)g2h(read_idle) = 1;
    if (cmd_idle) *(u8 *)g2h(cmd_idle) = 1;
    if (brkpt) *(u8 *)g2h(brkpt) = 0;
}
unsigned A80306cc8(void) { return 0; }                      // GXGetOverflowCount
void A803080e0(int, unsigned) {}                            // GXSetMisc
void A803081d0(void) {}                                     // GXResetWriteGatherPipe
void A803084e0(unsigned token) { g.draw_token = (u16)token; }  // GXSetDrawSync: el dibujo es inmediato.
unsigned A80308594(void) { return g.draw_token; }           // GXReadDrawSync
void A803085a0(void) { flush_any(); }                     // GXDrawDone
void A8030c410(int, int) {}                                 // GXSetGPMetric
void A8030ce00(void) {}                                     // GXClearGPMetric
void A8030ce10(GA a, GA b, GA c, GA d) {                    // GXReadXfRasMetric
    const GA ps[4] = {a, b, c, d};
    for (GA p : ps) if (p) *(u32 *)g2h(p) = 0;
}
void A8030bba0(int) {}                                      // GXSetDither: sin tramado.

// --- Vértices ---
void A80306cd0(int attr, int type) {                        // GXSetVtxDesc
    if (attr == VA_NBT) attr = VA_NRM;
    if ((unsigned)attr >= VA_COUNT || g.vcd[attr] == (u8)type) return;
    TOUCH_KEEP();
    g.vcd[attr] = (u8)type; SENT_KEEP(g.vcd[attr]);
}
void A80307558(void) {                                      // GXClearVtxDesc: deja posición directa, como el original.
    u8 n[sizeof g.vcd];
    memset(n, 0, sizeof n);
    n[VA_POS] = ATTR_DIRECT;
    if (!memcmp(g.vcd, n, sizeof n)) return;
    TOUCH_KEEP();
    memcpy(g.vcd, n, sizeof n); SENT_KEEP(g.vcd);
}
void A80307590(int fmt, int attr, int cnt, int type, int frac) {  // GXSetVtxAttrFmt
    if (attr == VA_NBT) attr = VA_NRM;
    if ((unsigned)attr >= VA_COUNT || (unsigned)fmt >= 8) return;
    VtxAttr &a = g.vat[fmt][attr];
    if (a.cnt == (u8)cnt && a.type == (u8)type && a.frac == (u8)(frac & 31)) return;
    TOUCH_KEEP();
    a.cnt = (u8)cnt; a.type = (u8)type; a.frac = (u8)(frac & 31); SENT_KEEP(a);
}
void A80307d88(int attr, GA base, int stride) {             // GXSetArray
    if (attr == VA_NBT) attr = VA_NRM;
    if ((unsigned)attr >= VA_COUNT || (g.array_base[attr] == base && g.array_stride[attr] == (u8)stride)) return;
    TOUCH_KEEP();
    g.array_base[attr] = base; g.array_stride[attr] = (u8)stride; SENT_KEEP(g.array_base[attr]); SENT_KEEP(g.array_stride[attr]);
}
void A80307e14(void) {}                                     // GXInvalidateVtxCache: sin caché, se lee al decodificar.
void A803089c8(int prim, int fmt, int n) { begin((u32)prim, (u32)fmt, (u32)n); }  // GXBegin

// --- Generación de coordenadas ---
void A80307e24(int dst, int func, int src, unsigned mtx, int normalize, unsigned post) {  // GXSetTexCoordGen2
    if ((unsigned)dst >= 8) return;
    TexGen &t = g.texgen[dst];
    if (t.func == (u8)func && t.src == (u8)src && t.mtx == mtx && t.normalize == (u8)(normalize & 1) && t.post == post) return;
    TOUCH();
    t.func = (u8)func; t.src = (u8)src; t.mtx = mtx; t.normalize = (u8)(normalize & 1); t.post = post; SENT(t);
}
void A803080a4(int n) { if (g.num_texgens == (u8)n) return; TOUCH(); g.num_texgens = (u8)n; SENT(g.num_texgens); }   // GXSetNumTexGens

// --- Matrices ---
#if defined(__3DS__)
extern "C" void diag_log(const char *, ...);
extern "C" void diag_stack_trace(const char *);
#endif
void A8030bff4(GA m, unsigned id) {                         // GXLoadPosMtxImm
    census.pos_mtx_loads++;
    if (id >= 64 || !memcmp(g.xf + id * 4, g2h(m), 48)) return;
    TOUCH_KEEP();
    memcpy(g.xf + id * 4, g2h(m), 48); SENT_N(g.xf + id * 4, 48, 2);
#if defined(__3DS__)
    // W3D_HUGE_MTX=<n>: registra las n primeras matrices de posición no finitas o enormes, con su dirección y la pila.
    static int left = -2; if (left == -2) { const char *e = getenv("W3D_HUGE_MTX"); left = e ? atoi(e) : 0; }
    if (left > 0 && id < 64) {
        const float *f = g.xf + id * 4; bool bad = false;
        for (int i = 0; i < 12; i++) if (!(fabsf(f[i]) < 1e12f)) bad = true;
        if (bad) {
            left--;
            diag_log("[matriz] %08x id %u: %g %g %g %g | %g %g %g %g | %g %g %g %g\n", (unsigned)m, id, f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9], f[10], f[11]);
            diag_stack_trace("matriz enorme");
        }
    }
#endif
}
void A8030c044(GA gm, unsigned id) {                        // GXLoadNrmMtxImm: 3x3 de una 3x4.
    census.nrm_mtx_loads++;
    if (id >= 32) return;
    const float *m = (const float *)g2h(gm);
    float n[9];
    for (int r = 0; r < 3; r++) for (int c = 0; c < 3; c++) n[r * 3 + c] = m[r * 4 + c];
    if (!memcmp(g.nrm + id * 3, n, sizeof n)) return;
    TOUCH_KEEP();
    memcpy(g.nrm + id * 3, n, sizeof n); SENT_N(g.nrm + id * 3, sizeof n, 2);
}
void A8030c094(unsigned id) { u32 v = id < 64 ? id : 0; if (g.cur_pos == v) return; TOUCH_KEEP(); g.cur_pos = v; SENT_KEEP(g.cur_pos); }  // GXSetCurrentMtx
void A8030c0c8(GA m, unsigned id, int type) {               // GXLoadTexMtxImm: id>=64 es memoria de posmatrices.
    census.tex_mtx_loads++;
    size_t bytes = type == 1 ? 32 : 48;
    float *dst = id < 64 ? g.xf + id * 4 : id < 128 ? g.post + (id - 64) * 4 : nullptr;
    if (!dst || !memcmp(dst, g2h(m), bytes)) return;
    TOUCH_KEEP();
    memcpy(dst, g2h(m), bytes); SENT_N(dst, (u32)bytes, 2);
}
void A8030bec4(GA gm, int type) {                           // GXSetProjection: se conservan los seis parámetros de XF.
    const float *m = (const float *)g2h(gm);
    float p[6] = {m[0], type == 1 ? m[3] : m[2], m[5], type == 1 ? m[7] : m[6], m[10], m[11]};
    if (g.proj_type == (u32)type && !memcmp(g.proj, p, sizeof p)) return;
    TOUCH();
    g.proj_type = (u32)type;
    memcpy(g.proj, p, sizeof p); SENT(g.proj); SENT(g.proj_type);
}
void A8030c264(float l, float t, float w, float h, float n, float f) {  // GXSetViewport
    float v[6] = {l, t, w, h, n, f};
    if (!memcmp(g.vp, v, sizeof v)) return;
    TOUCH();
    memcpy(g.vp, v, sizeof v); SENT(g.vp);
}
void A8030c20c(float l, float t, float w, float h, float n, float f, unsigned field) {  // GXSetViewportJitter
    if (field == 0) t -= 0.5f;
    A8030c264(l, t, w, h, n, f);
}
void A8030c2ac(unsigned l, unsigned t, unsigned w, unsigned h) {  // GXSetScissor
    if (g.scissor[0] == l && g.scissor[1] == t && g.scissor[2] == w && g.scissor[3] == h) return;
    TOUCH();
    g.scissor[0] = l; g.scissor[1] = t; g.scissor[2] = w; g.scissor[3] = h; SENT(g.scissor);
}
void A80308be8(int mode) { if (g.cull == (u8)mode) return; TOUCH(); g.cull = (u8)mode; SENT(g.cull); }    // GXSetCullMode

// --- Copia a pantalla ---
void A80308c84(GA gr, GA go, unsigned hor, unsigned ver) {  // GXAdjustForOverscan, en C como el original.
    u8 *r = (u8 *)g2h(gr), *o = (u8 *)g2h(go);
    hor &= 0xffff;
    ver &= 0xffff;
    if (r != o) memcpy(o, r, 60);
    auto R16 = [&](int off) { u16 v; memcpy(&v, r + off, 2); return v; };
    auto W16 = [&](int off, u32 v) { u16 x = (u16)v; memcpy(o + off, &x, 2); };
    u32 tv; memcpy(&tv, r, 4);
    u32 xfb_mode; memcpy(&xfb_mode, r + 20, 4);
    u32 v2 = (ver & 0x7fff) * 2, h2 = (hor & 0x7fff) * 2;
    W16(4, R16(4) - h2);
    W16(6, R16(6) - (v2 * R16(6)) / R16(8));
    if (xfb_mode == 0 && (tv & 3) == 0) W16(8, R16(8) - (v2 >> 1));
    else W16(8, R16(8) - v2);
    W16(14, R16(14) - h2);
    if ((tv & 3) == 1) W16(16, R16(16) - ((ver & 0x7fff) << 2));
    else W16(16, R16(16) - v2);
    W16(10, R16(10) + hor);
    W16(12, R16(12) + ver);
}
void A80308dc8(unsigned l, unsigned t, unsigned w, unsigned h) {  // GXSetDispCopySrc
    g.copy_src[0] = (u16)l; g.copy_src[1] = (u16)t; g.copy_src[2] = (u16)w; g.copy_src[3] = (u16)h; SENT_RAW(g.copy_src);
}
void A80308e44(unsigned w, unsigned h) { g.copy_dst[0] = (u16)w; g.copy_dst[1] = (u16)h; SENT_RAW(g.copy_dst); }  // GXSetDispCopyDst
unsigned A80308ef4(float vscale) {                          // GXSetDispCopyYScale: recuento de líneas del original.
    u32 scale = (u32)(256.0f / vscale) & 0x1ff;
    if (!scale) scale = 256;
    u32 src_h = g.copy_src[3] ? g.copy_src[3] : 1;
    u32 base = ((src_h - 1) << 8) / scale;
    u32 lines = base + 1;
    if (scale > 0x80 && scale < 0x100) {
        u32 odd = scale;
        while (!(odd & 1)) odd >>= 1;
        if (src_h % odd == 0) lines = base + 2;
    }
    if (lines > 0x400) lines = 0x400;
    g.copy_y_scale = scale;
    g.xfb_height = (u16)lines; SENT_RAW(g.copy_y_scale); SENT_RAW(g.xfb_height);
    return lines;
}
void A80308fc0(ColorArg c, unsigned z) {                    // GXSetCopyClear
    color_arg(c, g.clear_color);
    g.clear_z = z & 0xffffff; SENT_RAW(g.clear_color); SENT_RAW(g.clear_z);
}
void A80309038(int, GA, int vf, GA vfilter) {               // GXSetCopyFilter: el antialias no se emula.
    static const u8 identity[7] = {0, 0, 21, 22, 21, 0, 0};
    if (vf && vfilter) memcpy(g.vfilter, g2h(vfilter), 7);
    else memcpy(g.vfilter, identity, 7);
    SENT_RAW(g.vfilter);
}
void A80309240(int gamma) { g.gamma = (u8)gamma; SENT_RAW(g.gamma); }          // GXSetDispCopyGamma
void A80309254(GA, int clear) { copy_display((clear & 0xff) != 0); }  // GXCopyDisp: la imagen va a la ventana.

// --- Luces: rellenos de GXLightObj ---
void A803093f4(GA lt, float k0, float k1, float k2) {       // GXInitLightAttnK
    LightObj *o = (LightObj *)g2h(lt); o->k0 = k0; o->k1 = k1; o->k2 = k2;
}
void A80309404(GA lt, float cutoff, int fn) {               // GXInitLightSpot
    LightObj *o = (LightObj *)g2h(lt);
    if (cutoff <= 0.f || cutoff > 90.f) fn = 0;
    float r = (float)(3.141592653589793 * cutoff) / 180.f, cr = cosf(r), a0, a1, a2;
    switch (fn) {
        case 1: a1 = 1000.f; a0 = -1000.f * cr; a2 = 0.f; break;
        case 2: a2 = 0.f; a1 = 1.f / (1.f - cr); a0 = -cr * a1; break;
        case 3: a2 = 1.f / (1.f - cr); a1 = -cr * a2; a0 = 0.f; break;
        case 4: { float d = 1.f - cr; float i = 1.f / (d * d); a0 = i * (cr * (cr - 2.f)); a1 = 2.f * i; a2 = -i; break; }
        case 5: { float d = 1.f - cr; float i = 1.f / (d * d); a2 = -4.f * i; a1 = 4.f * (1.f + cr) * i; a0 = a2 * cr; break; }
        case 6: { float d = 1.f - cr; float i = 1.f / (d * d); a1 = 4.f * cr * i; a2 = -2.f * i; a0 = 1.f - i * (2.f * cr * cr); break; }
        default: a2 = 0.f; a1 = 0.f; a0 = 1.f; break;
    }
    o->a0 = a0; o->a1 = a1; o->a2 = a2;
}
void A80309594(GA lt, float x, float y, float z) {          // GXInitLightPos
    LightObj *o = (LightObj *)g2h(lt); o->px = x; o->py = y; o->pz = z;
}
void A803095a4(GA lt, float x, float y, float z) {          // GXInitLightDir: se guarda negada.
    LightObj *o = (LightObj *)g2h(lt); o->nx = -x; o->ny = -y; o->nz = -z;
}
void A803095c0(GA lt, float x, float y, float z) {          // GXInitSpecularDir
    LightObj *o = (LightObj *)g2h(lt);
    float hx = -x, hy = -y, hz = 1.f - z, m = hx * hx + hy * hy + hz * hz;
    if (m != 0.f) m = 1.f / sqrtf(m);
    o->nx = hx * m; o->ny = hy * m; o->nz = hz * m;
    o->px = -1048576.f * x; o->py = -1048576.f * y; o->pz = -1048576.f * z;
}
void A803096a4(GA lt, ColorArg c) { color_arg(c, ((LightObj *)g2h(lt))->color); }  // GXInitLightColor
void A803096b0(GA lt, unsigned id) {                        // GXLoadLightObjImm: id es una máscara de un bit.
    int n = 0;
    for (; n < 8; n++) if (id & (1u << n)) break;
    if (n >= 8 || !memcmp(&g.lights[n], g2h(lt), sizeof(LightObj))) return;
    TOUCH();
    memcpy(&g.lights[n], g2h(lt), sizeof(LightObj)); SENT(g.lights[n]);
}
// Color de ambiente o de material de un canal: color (0-1), alfa (2-3) o los dos (4-5).
inline void set_chan_color(u8 (*dst)[4], int chan, ColorArg c) {
    u8 v[4]; color_arg(c, v);
    u8 n[2][4]; memcpy(n, dst, sizeof n);
    switch (chan) {
        case 0: case 1: memcpy(n[chan], v, 3); break;
        case 2: case 3: n[chan - 2][3] = v[3]; break;
        case 4: case 5: memcpy(n[chan - 4], v, 4); break;
        default: return;
    }
    if (!memcmp(n, dst, sizeof n)) return;
    TOUCH();
    memcpy(dst, n, sizeof n); SENT_N(dst, sizeof n, 1);
}
void A8030972c(int chan, ColorArg c) { set_chan_color(g.amb, chan, c); }   // GXSetChanAmbColor
void A8030981c(int chan, ColorArg c) { set_chan_color(g.mat, chan, c); }   // GXSetChanMatColor
void A8030990c(int n) { if (g.num_chans == (u8)n) return; TOUCH(); g.num_chans = (u8)n; SENT(g.num_chans); }     // GXSetNumChans
void A80309948(int chan, int enable, int amb, int mat, unsigned mask, int diff, int attn) {  // GXSetChanCtrl
    if (attn == 0) diff = 0;  // GX_AF_SPEC anula la difusa, como el original.
    ChanCtrl c = {(u8)(enable & 1), (u8)(amb & 1), (u8)(mat & 1), (u8)diff, (u8)attn, (u8)mask};
    ChanCtrl n[4]; memcpy(n, g.chan, sizeof n);
    switch (chan) {
        case 0: case 1: case 2: case 3: n[chan] = c; break;
        case 4: n[0] = c; n[2] = c; break;
        case 5: n[1] = c; n[3] = c; break;
        default: return;
    }
    if (!memcmp(n, g.chan, sizeof n)) return;
    TOUCH();
    memcpy(g.chan, n, sizeof n); SENT(g.chan);
}

// --- Texturas ---
unsigned A80309a64(unsigned w, unsigned h, unsigned fmt, int mip, unsigned max_lod) {  // GXGetTexBufferSize
    return tex_buffer_size(w, h, fmt, (mip & 0xff) == 1, max_lod);
}
void A80309c88(GA go, GA img, unsigned w, unsigned h, unsigned fmt, unsigned s, unsigned t, int mip) {  // GXInitTexObj
    GTexObj *o = (GTexObj *)g2h(go);
    memset(o, 0, sizeof *o);
    o->wrap_s = (u8)(s & 3);
    o->wrap_t = (u8)(t & 3);
    o->mag_filter = 1;
    o->image = img;
    o->width = (u16)w;
    o->height = (u16)h;
    o->format = fmt;
    if (mip & 0xff) {
        o->mip = 1;
        // CI: LIN_MIP_NEAR; el resto LIN_MIP_LIN. Límite: log2 del lado mayor, como el original.
        o->min_filter = fmt >= 8 && fmt <= 10 ? 3 : 5;
        u32 m = (w & 0xffff) > (h & 0xffff) ? (w & 0xffff) : (h & 0xffff), l = 0;
        while (m > 1) { m >>= 1; l++; }
        o->max_lod16 = (u8)(l * 16);
    } else {
        o->min_filter = 1;
    }
}
void A80309ed4(GA go, GA img, unsigned w, unsigned h, unsigned fmt, unsigned s, unsigned t, int mip, unsigned tlut) {  // GXInitTexObjCI
    A80309c88(go, img, w, h, fmt, s, t, mip);
    ((GTexObj *)g2h(go))->tlut = tlut;
}
void A80309f1c(GA go, int min_f, int mag_f, float min_lod, float max_lod, float bias, int, int, int aniso) {  // GXInitTexObjLOD
    GTexObj *o = (GTexObj *)g2h(go);
    if (bias < -4.f) bias = -4.f;
    if (bias >= 3.99f) bias = 3.99f;
    if (min_lod < 0.f) min_lod = 0.f;
    if (min_lod > 10.f) min_lod = 10.f;
    if (max_lod < 0.f) max_lod = 0.f;
    if (max_lod > 10.f) max_lod = 10.f;
    o->min_filter = (u8)min_f;
    o->mag_filter = (u8)(mag_f == 1);
    o->min_lod16 = (u8)(min_lod * 16.f);
    o->max_lod16 = (u8)(max_lod * 16.f);
    o->bias32 = (s16)(bias * 32.f);
    o->aniso = (u8)(aniso & 3);
}
void A8030a21c(GA o, int id) {                              // GXLoadTexObj
    census.tex_binds++;
    if ((unsigned)id >= 8 || (g.map_valid[id] && !memcmp(&g.map[id], g2h(o), sizeof(GTexObj)))) return;
    TOUCH();
    memcpy(&g.map[id], g2h(o), sizeof(GTexObj));
    g.map_valid[id] = 1; SENT(g.map[id]); SENT(g.map_valid[id]);
}
void A8030a270(GA go, GA lut, int fmt, unsigned n) {        // GXInitTlutObj
    GTlutObj *o = (GTlutObj *)g2h(go);
    memset(o, 0, sizeof *o);
    o->lut = lut; o->format = (u8)fmt; o->count = (u16)n;
}
void A8030a2a8(GA o, unsigned name) {                       // GXLoadTlut: copia la paleta como hace la consola.
    // v34: la misma paleta ya cargada en esa ranura (misma dirección, tamaño, formato y firma, sin escrituras desde
    // entonces): nada cambia, ni la época de las texturas (antes subía en cada carga, unas 200 por cuadro, y cada textura
    // se volvía a validar en cada dibujo).
    // v36: las tablas de paletas son del hilo que ejecuta: la carga entera va a la cola.
    if (mt::on) { mt::tlut(*(const GTlutObj *)g2h(o), name); return; }
    if (tlut_same(*(const GTlutObj *)g2h(o), name)) return;
    touch();
    tlut_load(*(const GTlutObj *)g2h(o), name);
    g.tex_epoch++;
}
void A8030a46c(void) { if (mt::on) { mt::epoch(); return; } touch(); g.tex_epoch++; }            // GXInvalidateTexAll

// --- Indirecto ---
void A8030aab8(int id, GA off, int scale_exp) {             // GXSetIndTexMtx
    TOUCH(); SENT_N(&g, 0, 1);
    if (id >= 1 && id <= 3) {
        memcpy(g.ind_mtx[id - 1], g2h(off), 24);
        g.ind_exp[id - 1] = (s8)scale_exp; SENT_RAW(g.ind_mtx[id - 1]); SENT_RAW(g.ind_exp[id - 1]);
    } else if (id >= 5 && id <= 11) {
        static bool warned;
        if (!warned) { warned = true; fprintf(stderr, "[gx] matriz indirecta dinámica %d sin soporte\n", id); }
    }
}
void A8030ac30(int s, int ss, int st) {                     // GXSetIndTexCoordScale
    TOUCH(); SENT_N(&g, 0, 1);
    if ((unsigned)s < 4) { g.ind[s].scale_s = (u8)ss; g.ind[s].scale_t = (u8)st; SENT_RAW(g.ind[s]); }
}
void A8030ad74(int s, int coord, int map) {                 // GXSetIndTexOrder
    TOUCH(); SENT_N(&g, 0, 1);
    if ((unsigned)s < 4) { g.ind[s].coord = (u8)coord; g.ind[s].map = (u8)map; SENT_RAW(g.ind[s]); }
}
void A8030ae60(int n) { if (g.num_ind == (u8)n) return; TOUCH(); g.num_ind = (u8)n; SENT(g.num_ind); }       // GXSetNumIndStages
// Etapa de TEV: se calcula la nueva y solo si cambia se toca el estado.
// v37: sin copiar la etapa (32 B, dos llamadas a memcpy y una a memcmp por función): se comparan y se escriben solo los
// campos de la llamada. off[i] es el desplazamiento de cada campo (todos son u8) y val[i] su valor nuevo.
inline void stage_set(int s, const u8 *off, const u8 *val, int n) {
    u8 *t = (u8 *)&g.tev[s];
    int i = 0;
    while (i < n && t[off[i]] == val[i]) i++;
    if (i == n) return;
    TOUCH();
    for (; i < n; i++) t[off[i]] = val[i];
    SENT(g.tev[s]);
}
#define SOFF(f) (u8)offsetof(TevStage, f)
#define STAGE_SET(s, ...) do { static const u8 off_[] = {STAGE_OFFS}; const u8 val_[] = {__VA_ARGS__}; stage_set(s, off_, val_, (int)sizeof off_); } while (0)
void A8030ae84(int s) {                                     // GXSetTevDirect
    if ((unsigned)s >= 16) return;
#define STAGE_OFFS SOFF(ind_stage), SOFF(ind_fmt), SOFF(ind_bias), SOFF(ind_mtx), SOFF(ind_wrap_s), SOFF(ind_wrap_t)
    STAGE_SET(s, 0xff, 0, 0, 0, 0, 0);
}
void A8030aecc(int s, int ind, int signed_off, int replace, int mtx) {  // GXSetTevIndWarp
    if ((unsigned)s >= 16) return;
    u8 wrap = (replace & 0xff) ? 6 : 0;
    STAGE_SET(s, (u8)ind, 0, (u8)((signed_off & 0xff) ? 7 : 0), (u8)mtx, wrap, wrap);
#undef STAGE_OFFS
}

// --- TEV ---
void A8030af88(int s, int mode) {                           // GXSetTevOp: tablas 0x80408ae8 y siguientes.
    if ((unsigned)s >= 16) return;
    struct { u8 ca, cb, cc, cd, aa, ab, ac, ad; } t;
    u8 dc = s == 0 ? 10 : 0, da = s == 0 ? 5 : 0;
    switch (mode) {
        case 0: t.ca = 15; t.cb = 8; t.cc = dc; t.cd = 15; t.aa = 7; t.ab = 4; t.ac = da; t.ad = 7; break;
        case 1: t.ca = dc; t.cb = 8; t.cc = 9; t.cd = 15; t.aa = 7; t.ab = 7; t.ac = 7; t.ad = da; break;
        case 2: t.ca = dc; t.cb = 12; t.cc = 8; t.cd = 15; t.aa = 7; t.ab = 4; t.ac = da; t.ad = 7; break;
        case 3: t.ca = 15; t.cb = 15; t.cc = 15; t.cd = 8; t.aa = 7; t.ab = 7; t.ac = 7; t.ad = 4; break;
        default: t.ca = 15; t.cb = 15; t.cc = 15; t.cd = dc; t.aa = 7; t.ab = 7; t.ac = 7; t.ad = da; break;
    }
#define STAGE_OFFS SOFF(ca), SOFF(cb), SOFF(cc), SOFF(cd), SOFF(aa), SOFF(ab), SOFF(ac), SOFF(ad), \
                   SOFF(cop), SOFF(cbias), SOFF(cscale), SOFF(cclamp), SOFF(cout), SOFF(aop), SOFF(abias), SOFF(ascale), SOFF(aclamp), SOFF(aout)
    STAGE_SET(s, t.ca, t.cb, t.cc, t.cd, t.aa, t.ab, t.ac, t.ad, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0);
#undef STAGE_OFFS
}
void A8030b014(int s, int a, int b, int c, int d) {         // GXSetTevColorIn
    if ((unsigned)s >= 16) return;
#define STAGE_OFFS SOFF(ca), SOFF(cb), SOFF(cc), SOFF(cd)
    STAGE_SET(s, (u8)a, (u8)b, (u8)c, (u8)d);
#undef STAGE_OFFS
}
void A8030b058(int s, int a, int b, int c, int d) {         // GXSetTevAlphaIn
    if ((unsigned)s >= 16) return;
#define STAGE_OFFS SOFF(aa), SOFF(ab), SOFF(ac), SOFF(ad)
    STAGE_SET(s, (u8)a, (u8)b, (u8)c, (u8)d);
#undef STAGE_OFFS
}
void A8030b09c(int s, int op, int bias, int scale, int clamp_, int out) {  // GXSetTevColorOp
    if ((unsigned)s >= 16) return;
#define STAGE_OFFS SOFF(cop), SOFF(cbias), SOFF(cscale), SOFF(cclamp), SOFF(cout)
    STAGE_SET(s, (u8)op, (u8)bias, (u8)scale, (u8)(clamp_ & 1), (u8)out);
#undef STAGE_OFFS
}
void A8030b104(int s, int op, int bias, int scale, int clamp_, int out) {  // GXSetTevAlphaOp
    if ((unsigned)s >= 16) return;
#define STAGE_OFFS SOFF(aop), SOFF(abias), SOFF(ascale), SOFF(aclamp), SOFF(aout)
    STAGE_SET(s, (u8)op, (u8)bias, (u8)scale, (u8)(clamp_ & 1), (u8)out);
#undef STAGE_OFFS
}
void A8030b16c(int id, S10Arg c) {                        // GXSetTevColorS10
    if ((unsigned)id >= 4) return;
    s16 v[4]; color_s10_arg(c, v);
    if (!memcmp(g.reg[id], v, sizeof v)) return;
    TOUCH();
    memcpy(g.reg[id], v, sizeof v); SENT(g.reg[id]);
}
void A8030b1e8(int id, ColorArg c) {                        // GXSetTevKColor
    if ((unsigned)id >= 4) return;
    u8 v[4]; color_arg(c, v);
    if (!memcmp(g.konst[id], v, sizeof v)) return;
    TOUCH();
    memcpy(g.konst[id], v, sizeof v); SENT(g.konst[id]);
}
void A8030b25c(int s, int sel) { if ((unsigned)s >= 16) return; static const u8 o = SOFF(ksel_c); const u8 v = (u8)sel; stage_set(s, &o, &v, 1); }  // GXSetTevKColorSel
void A8030b2b8(int s, int sel) { if ((unsigned)s >= 16) return; static const u8 o = SOFF(ksel_a); const u8 v = (u8)sel; stage_set(s, &o, &v, 1); }  // GXSetTevKAlphaSel
void A8030b314(int s, int ras, int tex) {                   // GXSetTevSwapMode
    if ((unsigned)s >= 16) return;
#define STAGE_OFFS SOFF(ras_swap), SOFF(tex_swap)
    STAGE_SET(s, (u8)ras, (u8)tex);
#undef STAGE_OFFS
}
void A8030b35c(int t, int r, int g_, int b, int a) {        // GXSetTevSwapModeTable
    if ((unsigned)t >= 4) return;
    u8 v[4] = {(u8)r, (u8)g_, (u8)b, (u8)a};
    if (!memcmp(g.swap[t], v, 4)) return;
    TOUCH();
    memcpy(g.swap[t], v, 4); SENT(g.swap[t]);
}
void A8030b3dc(int c0, int r0, int op, int c1, int r1) {    // GXSetAlphaCompare
    if (g.cmp0 == (u8)(c0 & 7) && g.ref0 == (u8)r0 && g.cmp_op == (u8)(op & 3) && g.cmp1 == (u8)(c1 & 7) && g.ref1 == (u8)r1) return;
    TOUCH();
    g.cmp0 = (u8)(c0 & 7); g.ref0 = (u8)r0; g.cmp_op = (u8)(op & 3); g.cmp1 = (u8)(c1 & 7); g.ref1 = (u8)r1;
    SENT(g.cmp0); SENT_RAW(g.ref0); SENT_RAW(g.cmp_op); SENT_RAW(g.cmp1); SENT_RAW(g.ref1);
}
void A8030b4ac(int s, int coord, int map, int color) {      // GXSetTevOrder
    if ((unsigned)s >= 16) return;
#define STAGE_OFFS SOFF(coord), SOFF(map), SOFF(chan)
    STAGE_SET(s, (u8)coord, (u8)((map & 0x100) ? 0xff : (u8)map), (u8)color);
#undef STAGE_OFFS
}
void A8030b648(int n) { if (g.num_stages == (u8)n) return; TOUCH(); g.num_stages = (u8)n; SENT(g.num_stages); }    // GXSetNumTevStages

// --- Píxeles ---
void A8030b9b8(int t, int src, int dst, int op) {           // GXSetBlendMode
    if (g.blend_type == (u8)t && g.blend_src == (u8)src && g.blend_dst == (u8)dst && g.logic_op == (u8)op) return;
    TOUCH();
    g.blend_type = (u8)t; g.blend_src = (u8)src; g.blend_dst = (u8)dst; g.logic_op = (u8)op;
    SENT(g.blend_type); SENT_RAW(g.blend_src); SENT_RAW(g.blend_dst); SENT_RAW(g.logic_op);
}
void A8030ba0c(int en) { if (g.color_update == (u8)(en & 1)) return; TOUCH(); g.color_update = (u8)(en & 1); SENT(g.color_update); }   // GXSetColorUpdate
void A8030ba38(int en) { if (g.alpha_update == (u8)(en & 1)) return; TOUCH(); g.alpha_update = (u8)(en & 1); SENT(g.alpha_update); }   // GXSetAlphaUpdate
void A8030ba64(int cmp, unsigned func, int upd) {           // GXSetZMode
    if (g.z_enable == (u8)(cmp & 1) && g.z_func == (u8)(func & 7) && g.z_update == (u8)(upd & 1)) return;
    TOUCH();
    g.z_enable = (u8)(cmp & 1); g.z_func = (u8)(func & 7); g.z_update = (u8)(upd & 1);
    SENT(g.z_enable); SENT_RAW(g.z_func); SENT_RAW(g.z_update);
}
void A8030ba98(int before) { if (g.z_before_tex == (u8)(before & 1)) return; TOUCH(); g.z_before_tex = (u8)(before & 1); SENT(g.z_before_tex); }  // GXSetZCompLoc
void A8030bacc(int pix, int z) { if (g.pixel_fmt == (u8)pix && g.z_fmt == (u8)z) return; TOUCH(); g.pixel_fmt = (u8)pix; g.z_fmt = (u8)z; SENT(g.pixel_fmt); SENT_RAW(g.z_fmt); }  // GXSetPixelFmt

// --- Listas de visualización: bytes reales en el búfer del juego ---
void A8030bcb8(GA list, unsigned size) { dl_begin(list, size); }  // GXBeginDisplayList
unsigned A8030bd80(void) { return dl_end(); }               // GXEndDisplayList
void A8030be54(GA list, unsigned n) { dl_call(list, n); }   // GXCallDisplayList
}
