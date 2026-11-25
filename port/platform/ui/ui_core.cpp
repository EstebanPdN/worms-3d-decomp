// Interfaz de dos pantallas de la v28 (pedido del dueño, 2026-11-05; prototipo en docs/ui-3ds/simulator).
// - Arriba, encima de la imagen del juego: arranque (Licensed by Nintendo, SEGA, Team17, "Ported by Esteban PdN") sobre la
//   licencia del juego (3 s, modo 0), pantalla de carga y fundidos. El título es el original del juego (modo 5: planeta y
//   logo); sin las películas de logos (fe_bridge.cpp) el juego llega a él solo. Su "Press START" pasa abajo, con la
//   nebulosa del propio título (Objects/noplanet.xom) y el copyright. START, A o un toque lo pasan al menú.
// - Idioma: el de la consola, si el juego lo tiene (inglés, francés, alemán, italiano, español); si no, inglés. Se elige
//   solo en FE.LanguageSelect con la misma orden que la bandera. En Opciones se puede cambiar después.
// - Abajo: la pantalla táctil, una página por menú del juego (ui_pages.cpp), con los recursos originales del disco.
// - El dibujo lo hacen las primitivas de gx_pica.cpp (gx_ui_*), al final de cada cuadro y en el hilo del juego.
// - Las imágenes del juego salen de assets.worms (TGA originales, igual en 3DSX y CIA). El arte propio del arranque y del
//   título está en romfs:/ui/*.w3ui (tools/build3ds/ui/hacer_arte_ui.py), con copia en <datos>/ui/ por si falta el romfs.
// - La consola de desarrollador de diag.cpp sigue existiendo: con el overlay abierto (Developer, L+R+SELECT desde la v29) o durante
//   un volcado, la pantalla de abajo es suya y aquí no se dibuja.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <deque>
#include "ui.h"
#if defined(__3DS__)
extern "C" const char *diag_quick_notice(void);
#endif
namespace ui { bool hud_panel_preload(); void pages_cut(); }   // hud_panel.cpp, ui_pages.cpp
#include "../platform.h"
#if defined(__3DS__)
#include "../3ds/version.h"
#endif


namespace ui {

// ---------------------------------------------------------------------------------------------------------------
// Archivos.
bool read_game_file(const char *path, std::vector<u8> &out) {
    w3d::plat::File *f = w3d::plat::file_open(path);
    if (!f) return false;
    long n = w3d::plat::file_size(f);
    if (n <= 0 || n > (8 << 20)) { w3d::plat::file_close(f); return false; }
    out.resize((size_t)n);
    long got = w3d::plat::file_read(f, out.data(), 0, n);
    w3d::plat::file_close(f);
    return got == n;
}
// Arte propio (romfs:/ui en 3DS, platform/3ds/res/ui en Mac): lo lee el backend.
static bool read_ui_file(const char *name, std::vector<u8> &out) {
    unsigned char *d = nullptr; long n = 0;
    if (!uib_read_own(name, &d, &n) || !d || n <= 0) return false;
    out.assign(d, d + n); uib_free(d);
    return true;
}

// TGA del disco: tipo 1 (índices de 8 bits con paleta BGRA o BGR), 2 (BGRA/BGR) y 3 (gris), sin RLE.
static bool decode_tga(const std::vector<u8> &b, std::vector<u8> &rgba, u32 &w, u32 &h) {
    if (b.size() < 18) return false;
    const u8 *p = b.data();
    u32 idlen = p[0], cmtype = p[1], type = p[2], cmfirst = p[3] | p[4] << 8, cmlen = p[5] | p[6] << 8, cmbits = p[7];
    w = p[12] | p[13] << 8; h = p[14] | p[15] << 8;
    u32 bpp = p[16], desc = p[17];
    if (!w || !h || w > 1024 || h > 1024) return false;
    size_t off = 18 + idlen;
    std::vector<u8> pal;
    if (cmtype == 1) {
        u32 eb = (cmbits + 7) / 8;
        if (off + (size_t)cmlen * eb > b.size()) return false;
        pal.assign((size_t)(cmfirst + cmlen) * 4, 255);
        for (u32 i = 0; i < cmlen; i++) {
            const u8 *e = p + off + i * eb; u8 *d = &pal[(cmfirst + i) * 4];
            if (eb >= 3) { d[0] = e[2]; d[1] = e[1]; d[2] = e[0]; d[3] = eb == 4 ? e[3] : 255; }
            else { u16 v = (u16)(e[0] | e[1] << 8); d[0] = (u8)((v >> 10 & 31) * 255 / 31); d[1] = (u8)((v >> 5 & 31) * 255 / 31); d[2] = (u8)((v & 31) * 255 / 31); d[3] = 255; }
        }
        off += (size_t)cmlen * eb;
    }
    const u32 pb = (bpp + 7) / 8;
    if (off + (size_t)w * h * pb > b.size()) return false;
    rgba.resize((size_t)w * h * 4);
    const bool top_first = (desc & 0x20) != 0;
    for (u32 y = 0; y < h; y++) {
        const u32 sy = top_first ? y : h - 1 - y;
        for (u32 x = 0; x < w; x++) {
            const u8 *s = p + off + ((size_t)sy * w + x) * pb;
            u8 *d = &rgba[((size_t)y * w + x) * 4];
            if (type == 1 && pb == 1) { u32 i = s[0]; if (i * 4 + 3 < pal.size()) memcpy(d, &pal[i * 4], 4); else d[0] = d[1] = d[2] = d[3] = 0; }
            else if (type == 2 && pb >= 3) { d[0] = s[2]; d[1] = s[1]; d[2] = s[0]; d[3] = pb == 4 ? s[3] : 255; }
            else if (type == 3) { d[0] = d[1] = d[2] = s[0]; d[3] = pb == 2 ? s[1] : 255; }
            else return false;
        }
    }
    return true;
}
bool decode_tga_public(const std::vector<u8> &b, std::vector<u8> &rgba, u32 &w, u32 &h) { return decode_tga(b, rgba, w, h); }
#ifdef W3D_PUBLIC
// The two 8-bit atlases in the supported GWMP8P revision 0 font XOM.
// Decode across the same vertical flip as the optional SD conversions.
static bool read_disc_font(const char *name, std::vector<u8> &rgba, u32 &w, u32 &h) {
    const int bank = !strcmp(name, "fuente0.w3ui") ? 0 : !strcmp(name, "fuente1.w3ui") ? 1 : -1;
    if (bank < 0) return false;

    std::vector<u8> file;
    if (!read_game_file("Frontend/Mechanics/W3D Font GC.xom", file) ||
        file.size() != 138846 || memcmp(file.data(), "MOIK", 4))
        return false;

    constexpr size_t imageStart[] = {5551, 71121};
    constexpr size_t paletteStart[] = {136673, 137712};
    constexpr u8 imageHeader[] = {7, 0, 0, 0, 0x80, 0x80, 4};
    constexpr u8 paletteHeader[] = {0xff, 0, 1, 0, 0, 0, 0x80, 8};
    const u8 *pixels = file.data() + imageStart[bank];
    const u8 *palette = file.data() + paletteStart[bank];
    if (memcmp(pixels - sizeof imageHeader, imageHeader, sizeof imageHeader) ||
        memcmp(palette - sizeof paletteHeader, paletteHeader, sizeof paletteHeader))
        return false;

    w = h = 256;
    rgba.resize(w * h * 4);
    for (u32 y = 0; y < h; ++y) {
        for (u32 x = 0; x < w; ++x) {
            const u8 *src = palette + 4 * pixels[(h - 1 - y) * w + x];
            u8 *dst = rgba.data() + 4 * (y * w + x);
            dst[0] = src[2];
            dst[1] = src[1];
            dst[2] = src[0];
            dst[3] = src[3];
        }
    }
    return true;
}
#endif

static bool decode_w3ui(const std::vector<u8> &b, std::vector<u8> &rgba, u32 &w, u32 &h) {
    if (b.size() < 8 || memcmp(b.data(), "W3UI", 4)) return false;
    w = b[4] | b[5] << 8; h = b[6] | b[7] << 8;
    if ((size_t)w * h * 4 + 8 > b.size()) return false;
    rgba.assign(b.begin() + 8, b.begin() + 8 + (size_t)w * h * 4);
    return true;
}

bool read_own_public(const char *name, std::vector<u8> &rgba, u32 &w, u32 &h) { std::vector<u8> f; return read_ui_file(name, f) && decode_w3ui(f, rgba, w, h); }

// ---------------------------------------------------------------------------------------------------------------
// Imágenes: se piden por nombre y se suben fuera del cuadro (w3d_ui_after_frame). Nombre con ".w3ui": arte propio;
// si no, una ruta del disco (TGA).
static std::deque<Img> g_imgs;
static u32 g_frame;
static unsigned g_vram_budget = 3u << 20;   // Lo que la UI puede ocupar de VRAM (hay unos 5,5 MB libres en partida).
static unsigned g_vram_used;

const Img *img(const char *name, int fmt) {
    for (Img &i : g_imgs) if (!strcmp(i.name, name)) { i.last = g_frame; if (i.tex < 0 && !i.failed) i.wanted = true; return &i; }
    Img n; snprintf(n.name, sizeof n.name, "%s", name); n.fmt = fmt; n.wanted = true; n.last = g_frame;
    g_imgs.push_back(n);
    return &g_imgs.back();
}
// Imágenes hechas en memoria (img_mem): sus píxeles hasta que se suben (y otra vez si se liberan).
struct MemImg { char name[64]; std::vector<u8> rgba; u32 w, h; };
static std::deque<MemImg> g_mem;
const Img *img_mem(const char *name, const u8 *rgba, u32 w, u32 h, int fmt) {
    MemImg *m = nullptr;
    for (MemImg &e : g_mem) if (!strcmp(e.name, name)) m = &e;
    if (!m) { g_mem.emplace_back(); m = &g_mem.back(); snprintf(m->name, sizeof m->name, "%s", name); m->rgba.assign(rgba, rgba + (size_t)w * h * 4); m->w = w; m->h = h; }
    return img(name, fmt);
}
void img_mem_forget(const char *name) {
    img_drop(name);
    for (auto it = g_mem.begin(); it != g_mem.end(); ++it) if (!strcmp(it->name, name)) { g_mem.erase(it); break; }
}
// v29: en 3DS el montón va muy justo (docs/optimizacion-3ds/analisis-cpu-memoria.md, apartado 5). Si no hay sitio para
// leer o subir una imagen, no se vuelve a probar hasta este cuadro (medio segundo) en lugar de tirar el juego.
static u32 g_load_hold;
static void load_hold(const char *what, const char *name, unsigned bytes) {
    static int said;
    g_load_hold = g_frame + 30;
    if (said++ < 40) uib_log("[ui] sin montón para %s %s (%u bytes): otra vez en 30 cuadros\n", what, name, bytes);
}
// Hay hueco en el montón para n bytes (se sueltan en el acto). La subida convierte en un búfer propio del backend
// (gx_ui_tex_create, un std::vector): sin memoria lanzaba bad_alloc y, sin excepciones, el juego salía.
static bool heap_room(size_t n) { void *p = malloc(n ? n : 1); if (!p) return false; free(p); return true; }
static void load_pending(int max_loads) {
    if (g_frame < g_load_hold) return;
    int done = 0;
    for (Img &i : g_imgs) {
        if (!i.wanted || i.tex >= 0 || i.failed) continue;
        if (done++ >= max_loads) break;
        i.wanted = false;
        // Sin copias de más (antes, dos o tres del tamaño de la imagen): el arte propio se sube desde el bloque que leyó el
        // backend (cabecera W3UI de 8 bytes y RGBA), lo hecho en memoria desde su copia, y solo el TGA del disco pasa por
        // un búfer decodificado.
        unsigned char *own = nullptr; long own_n = 0;
        std::vector<u8> rgba; const u8 *px = nullptr; u32 w = 0, h = 0;
        const MemImg *mem = nullptr;
        for (const MemImg &e : g_mem) if (!strcmp(e.name, i.name)) mem = &e;
        bool ok = false;
        if (mem) { px = mem->rgba.data(); w = mem->w; h = mem->h; ok = !mem->rgba.empty(); }
        else if (strstr(i.name, ".w3ui")) {
            ok = uib_read_own(i.name, &own, &own_n) && own && own_n >= 8 && !memcmp(own, "W3UI", 4);
            if (ok) { w = own[4] | own[5] << 8; h = own[6] | own[7] << 8; px = own + 8; ok = (size_t)w * h * 4 + 8 <= (size_t)own_n; }
#ifdef W3D_PUBLIC
            if (!ok && read_disc_font(i.name, rgba, w, h)) {
                px = rgba.data();
                ok = true;
            }
#endif
        } else {
            std::vector<u8> file;
            ok = read_game_file(i.name, file) && decode_tga(file, rgba, w, h);
            px = rgba.data();
        }
        if (!ok) {
            // Arte propio sin leer: el backend no distingue «falta» de «sin memoria» (malloc). Con menos de 2 MB libres
            // (más que el mayor .w3ui de 3DS) se vuelve a probar; si no, falta de verdad.
            const bool unread = !mem && !own && strstr(i.name, ".w3ui");
            if (own) uib_free(own);
            if (unread && !heap_room(2u << 20)) { load_hold("leer", i.name, 0); break; }
            i.failed = true; uib_log("[ui] no se pudo cargar %s\n", i.name); continue;
        }
        unsigned bytes = 0;
        { u32 pw = 8, ph = 8; while (pw < w) pw <<= 1; while (ph < h) ph <<= 1; bytes = pw * ph * ((i.fmt & 7) == 0 ? 4 : 2); }
        // (gx_ui_tex_create convierte directamente en el búfer lineal o en la textura: no pide montón aparte.)
        // Si no cabe en el presupuesto, se liberan las que llevan más tiempo sin usarse.
        while (g_vram_used + bytes > g_vram_budget) {
            Img *old = nullptr;
            for (Img &o : g_imgs) if (o.tex >= 0 && g_frame - o.last > 30 && (!old || o.last < old->last)) old = &o;
            if (!old) break;
            uib_tex_free(old->tex); old->tex = -1; g_vram_used -= old->pw * old->ph * ((old->fmt & 7) == 0 ? 4 : 2);
        }
        i.tex = uib_tex_create(px, w, h, i.fmt, &i.pw, &i.ph);
        if (own) uib_free(own);
        if (i.tex < 0) { i.failed = true; continue; }
        i.w = w; i.h = h;
        g_vram_used += i.pw * i.ph * ((i.fmt & 7) == 0 ? 4 : 2);
    }
}
void img_drop(const char *name) {
    for (Img &i : g_imgs) if (!strcmp(i.name, name) && i.tex >= 0) { uib_tex_free(i.tex); g_vram_used -= i.pw * i.ph * ((i.fmt & 7) == 0 ? 4 : 2); i.tex = -1; }
}

// ---------------------------------------------------------------------------------------------------------------
// Dibujo: cuadriláteros en coordenadas de pantalla. El color va como 0xRRGGBBAA y se pasa a bytes r, g, b, a.
static int g_screen = -1;
static bool g_clip; static float g_cx0, g_cy0, g_cx1, g_cy1;   // ver clip()
static inline u32 bytes_of(unsigned c) { return (c >> 24) | (c >> 8 & 0xff00) | (c << 8 & 0xff0000) | (c << 24); }
void begin(int screen) { uib_begin(screen); g_screen = screen; g_clip = false; }
void clip(float x, float y, float w, float h) { g_clip = true; g_cx0 = x; g_cy0 = y; g_cx1 = x + w; g_cy1 = y + h; }
void clip_off() { g_clip = false; }
// Fundido de entrada de una página (set_fade, desde pages_frame): multiplica el alfa de todo lo que se dibuja.
static float g_page_alpha = 1;
void set_fade(float a) { g_page_alpha = a < 0 ? 0 : a > 1 ? 1 : a; }
unsigned faded(unsigned c) { return g_page_alpha >= 1 ? c : (c & ~0xffu) | (unsigned)((c & 0xff) * g_page_alpha + 0.5f); }
void quad(int tex, float x0, float y0, float x1, float y1, float u0, float v0, float u1, float v1, unsigned c) {
    c = faded(c);
    if (g_clip) {
        if (x1 <= g_cx0 || x0 >= g_cx1 || y1 <= g_cy0 || y0 >= g_cy1 || x1 <= x0 || y1 <= y0) return;
        const float du = (u1 - u0) / (x1 - x0), dv = (v1 - v0) / (y1 - y0);
        if (x0 < g_cx0) { u0 += (g_cx0 - x0) * du; x0 = g_cx0; }
        if (x1 > g_cx1) { u1 -= (x1 - g_cx1) * du; x1 = g_cx1; }
        if (y0 < g_cy0) { v0 += (g_cy0 - y0) * dv; y0 = g_cy0; }
        if (y1 > g_cy1) { v1 -= (y1 - g_cy1) * dv; y1 = g_cy1; }
    }
    float v[16] = {x0, y0, u0, v0, x1, y0, u1, v0, x1, y1, u1, v1, x0, y1, u0, v1};
    u32 cc = bytes_of(c);
    uib_quads(tex, v, (const uint32_t *)&cc, 1);
}
void rect(float x, float y, float w, float h, unsigned c) { quad(-1, x, y, x + w, y + h, 0, 0, 0, 0, c); }
// Imagen entera (o el trozo sx, sy, sw, sh en píxeles de la imagen) en x, y con tamaño w, h.
void sprite(const Img *i, float x, float y, float w, float h, unsigned c, float sx, float sy, float sw, float sh) {
    if (!i || i->tex < 0) return;
    if (sw <= 0) { sx = 0; sy = 0; sw = (float)i->w; sh = (float)i->h; }
    quad(i->tex, x, y, x + w, y + h, sx / i->pw, sy / i->ph, (sx + sw) / i->pw, (sy + sh) / i->ph, c);
}
// Imagen girada sobre su centro (cx, cy).
void sprite_rot(const Img *i, float cx, float cy, float w, float h, float ang, unsigned c) {
    if (!i || i->tex < 0) return;
    float s = sinf(ang), k = cosf(ang), hw = w / 2, hh = h / 2;
    float px[4] = {-hw, hw, hw, -hw}, py[4] = {-hh, -hh, hh, hh};
    float u1 = (float)i->w / i->pw, v1 = (float)i->h / i->ph, uu[4] = {0, u1, u1, 0}, vv[4] = {0, 0, v1, v1};
    float v[16];
    for (int n = 0; n < 4; n++) { v[n * 4] = cx + px[n] * k - py[n] * s; v[n * 4 + 1] = cy + px[n] * s + py[n] * k; v[n * 4 + 2] = uu[n]; v[n * 4 + 3] = vv[n]; }
    u32 cc = bytes_of(faded(c));
    uib_quads(i->tex, v, (const uint32_t *)&cc, 1);
}
void nine(const Img *i, float x, float y, float w, float h, float c, unsigned col) {
    if (!i || i->tex < 0) return;
    const float iw = (float)i->w, ih = (float)i->h;
    float cw = c, ch = c;
    if (cw * 2 > w) cw = w / 2;
    if (ch * 2 > h) ch = h / 2;
    const float xs[4] = {x, x + cw, x + w - cw, x + w}, ys[4] = {y, y + ch, y + h - ch, y + h};
    const float us[4] = {0, c, iw - c, iw}, vs[4] = {0, c, ih - c, ih};
    for (int r = 0; r < 3; r++) for (int k = 0; k < 3; k++)
        if (xs[k + 1] > xs[k] && ys[r + 1] > ys[r])
            quad(i->tex, xs[k], ys[r], xs[k + 1], ys[r + 1], us[k] / i->pw, vs[r] / i->ph, us[k + 1] / i->pw, vs[r + 1] / i->ph, col);
}
void sprite_fit(const Img *i, float x, float y, float w, float h, unsigned c, float sx, float sy, float sw, float sh) {
    if (!i || i->tex < 0) return;
    if (sw <= 0) { sx = 0; sy = 0; sw = (float)i->w; sh = (float)i->h; }
    float k = w / sw; if (sh * k > h) k = h / sh;
    const float dw = sw * k, dh = sh * k;
    sprite(i, x + (w - dw) / 2, y + (h - dh) / 2, dw, dh, c, sx, sy, sw, sh);
}
// Panel de nueve trozos del atlas de bordes del juego (Text_Border_Blue/Yellow/...): esquinas del anillo (3,3)-(45,45),
// bordes de las barras (1,61)-(63,79) y (66,17)-(84,79). t: grosor del borde en pantalla. fill: relleno del interior.
void panel(const Img *atlas, float x, float y, float w, float h, float t, unsigned fill, unsigned tint) {
    if (fill & 0xff) rect(x + t * 0.5f, y + t * 0.5f, w - t, h - t, fill);
    if (!atlas || atlas->tex < 0) return;
    const float rc = 24;          // centro del anillo en el atlas
    // Esquinas: cuartos del anillo (radio 21).
    sprite(atlas, x, y, t, t, tint, 3, 3, rc - 3, rc - 3);
    sprite(atlas, x + w - t, y, t, t, tint, rc, 3, 45 - rc, rc - 3);
    sprite(atlas, x, y + h - t, t, t, tint, 3, rc, rc - 3, 45 - rc);
    sprite(atlas, x + w - t, y + h - t, t, t, tint, rc, rc, 45 - rc, 45 - rc);
    // Bordes: tramo central de las barras, estirado.
    sprite(atlas, x + t, y, w - 2 * t, t, tint, 8, 61, 48, 18);
    sprite(atlas, x + t, y + h - t, w - 2 * t, t, tint, 8, 61, 48, 18);
    sprite(atlas, x, y + t, t, h - 2 * t, tint, 66, 24, 18, 48);
    sprite(atlas, x + w - t, y + t, t, h - 2 * t, tint, 66, 24, 18, 48);
}

// ---------------------------------------------------------------------------------------------------------------
// Fuente del juego: W3DFont.TGA y W3DFont01.TGA (128x128) con sus métricas .xbd: registros de 20 bytes <ffffBBH
// (x, y, ancho, alto normalizados; dos bytes; carácter). 16 px de alto.
struct Glyph { u16 code; u8 bank; float u0, v0, u1, v1, w; };
static std::vector<Glyph> g_glyphs;
// Las páginas son las de GameCube (W3D Font GC.xom, 256x256, tools/build3ds/ui/hacer_arte_ui.py): las mismas métricas a doble resolución.
static const char *const kFontTga[2] = {"fuente0.w3ui", "fuente1.w3ui"};
// v42: la página de pausa la pide durante la partida (page_match) para que salga entera desde su primer cuadro.
void font_keep() { img(kFontTga[0], 0); img(kFontTga[1], 0); }
static bool g_font_loaded;
// v39: las métricas de verdad de esas páginas están en el propio W3D Font GC.xom (XMultiTexFontPage): por página, las
// letras (u16), sus posiciones (x, y), sus tamaños (ancho, alto) y dos bytes por letra; cada lista con su cuenta delante.
// Las de Xbox (.xbd) valen para la página 0, pero en la 1 los botones de GameCube tienen otro ancho que los de Xbox y 69
// letras quedaban corridas: ©, Â, Ã, Ê, Õ, ™... salían como trozos de dos letras vecinas (el © del título; en español,
// medio menú). Si el .xom no se puede leer, quedan las de Xbox.
static bool load_font_metrics_gc() {
    std::vector<u8> b;
    if (!read_game_file("Frontend/Mechanics/W3D Font GC.xom", b)) return false;
    std::vector<Glyph> out;
    size_t at = 0;
    for (int bank = 0; bank < 2; bank++) {
        size_t c = (size_t)-1;
        for (size_t i = at; i + 4 <= b.size(); i++) if (!memcmp(&b[i], "CTNR", 4)) { c = i; break; }
        if (c == (size_t)-1) return false;
        size_t o = c + 8;
        auto count = [&]() -> int {   // entero de 7 bits por byte
            int v = 0, sh = 0;
            while (o < b.size()) { const u8 x = b[o++]; v |= (x & 0x7f) << sh; sh += 7; if (!(x & 0x80)) break; }
            return v;
        };
        const int n = count();
        if (n <= 0 || n > 400 || o + (size_t)n * 2 > b.size()) return false;
        const size_t chars = o; o += (size_t)n * 2;
        if (count() != n || o + (size_t)n * 8 > b.size()) return false;
        const size_t xy = o; o += (size_t)n * 8;
        if (count() != n || o + (size_t)n * 8 > b.size()) return false;
        const size_t wh = o; o += (size_t)n * 8;
        for (int i = 0; i < n; i++) {
            float f[4]; memcpy(f, &b[xy + i * 8], 8); memcpy(f + 2, &b[wh + i * 8], 8);
            Glyph g; g.code = (u16)(b[chars + i * 2] | b[chars + i * 2 + 1] << 8); g.bank = (u8)bank;
            g.u0 = f[0]; g.v0 = f[1]; g.u1 = f[0] + f[2]; g.v1 = f[1] + f[3]; g.w = f[2] * 128.f;
            if (!(f[2] > 0 && f[2] < 1 && f[3] > 0 && f[3] < 1 && f[0] >= 0 && f[1] >= 0)) return false;
            out.push_back(g);
        }
        at = o;
    }
    g_glyphs = out;
    uib_log("[ui] fuente del juego: %u letras (W3D Font GC.xom)\n", (unsigned)g_glyphs.size());
    return true;
}
static void load_font_metrics() {
    if (g_font_loaded) return;
    g_font_loaded = true;
    if (load_font_metrics_gc()) return;
    static const char *const kXbd[2] = {"Frontend/Fonts/XBox Font Data/W3DFont.xbd", "Frontend/Fonts/XBox Font Data/W3DFont01.xbd"};
    for (int bank = 0; bank < 2; bank++) {
        std::vector<u8> b;
        if (!read_game_file(kXbd[bank], b)) { uib_log("[ui] sin %s\n", kXbd[bank]); continue; }
        for (size_t o = 0; o + 20 <= b.size(); o += 20) {
            float f[4]; memcpy(f, &b[o], 16);
            u16 c = (u16)(b[o + 18] | b[o + 19] << 8);
            Glyph g; g.code = c; g.bank = (u8)bank; g.u0 = f[0]; g.v0 = f[1]; g.u1 = f[0] + f[2]; g.v1 = f[1] + f[3]; g.w = f[2] * 128.f;
            g_glyphs.push_back(g);
        }
    }
    uib_log("[ui] fuente del juego: %u letras\n", (unsigned)g_glyphs.size());
}
static const Glyph *glyph(u32 c) {
    for (const Glyph &g : g_glyphs) if (g.code == c) return &g;
    return nullptr;
}
// Siguiente carácter UTF-8.
static u32 utf8_next(const char *&s) {
    u8 c = (u8)*s++;
    if (c < 0x80) return c;
    int n = c >= 0xf0 ? 3 : c >= 0xe0 ? 2 : 1;
    u32 v = c & (0x3f >> n);
    for (int i = 0; i < n && (*s & 0xc0) == 0x80; i++) v = v << 6 | ((u8)*s++ & 0x3f);
    return v;
}
static const Glyph *glyph_or_fallback(u32 c) {
    if (const Glyph *g = glyph(c)) return g;
    static const struct { u16 from; char to; } kStrip[] = {{0x2014, '-'}, {0x2013, '-'}, {0x2019, '\''}, {0x201c, '"'}, {0x201d, '"'}, {0x2026, '.'}};
    for (auto &k : kStrip) if (k.from == c) return glyph((u8)k.to);
    return glyph('?');
}
float text_width(const char *s, float size) {
    float w = 0, k = size / 16.f;
    while (*s) { u32 c = utf8_next(s); if (c == '\n') break; if (const Glyph *g = glyph_or_fallback(c)) w += g->w * k; }
    return w;
}
// align: 0 izquierda, 1 centro, 2 derecha. size: alto en píxeles (la fuente mide 16).
float text(float x, float y, const char *s, float size, unsigned c, int align) {
    const Img *f[2] = {img(kFontTga[0], 0), img(kFontTga[1], 0)};
    float w = text_width(s, size), k = size / 16.f;
    if (align == 1) x -= w / 2; else if (align == 2) x -= w;
    float cx = x;
    while (*s) {
        u32 ch = utf8_next(s);
        if (ch == '\n') break;
        const Glyph *g = glyph_or_fallback(ch);
        if (!g) continue;
        const Img *t = f[g->bank];
        if (t && t->tex >= 0 && ch != ' ')
            quad(t->tex, cx, y, cx + g->w * k, y + size, g->u0 * t->w / t->pw, g->v0 * t->h / t->ph, g->u1 * t->w / t->pw, g->v1 * t->h / t->ph, c);
        cx += g->w * k;
    }
    return w;
}
// Texto con sombra, como los rótulos del juego.
float text_shadow(float x, float y, const char *s, float size, unsigned c, int align) {
    text(x + 1, y + 1, s, size, 0x90u * (c & 0xff) / 255u, align);   // la sombra se funde con el texto
    return text(x, y, s, size, c, align);
}
// Una línea que cabe en w: baja el tamaño hasta 0,6 del pedido.
float text_fit(float x, float y, const char *s, float size, float w, unsigned c, int align) {
    float tw = text_width(s, size), sz = size;
    if (tw > w && tw > 0) sz = size * w / tw;
    if (sz < size * 0.6f) sz = size * 0.6f;
    return text_shadow(x, y + (size - sz) * 0.5f, s, sz, c, align);
}
// Varias líneas cortadas por palabras dentro de w. Devuelve el alto usado.
static float text_box_impl(float x, float y, float w, const char *s, float size, unsigned c, int align, int max_lines, bool draw);
static bool g_fade; static float g_fade_y0, g_fade_y1;   // fundido de las líneas en los bordes (text_scroll)
float text_box(float x, float y, float w, const char *s, float size, unsigned c, int align, int max_lines) { return text_box_impl(x, y, w, s, size, c, align, max_lines, true); }
float text_box_height(float w, const char *s, float size, int max_lines) { return text_box_impl(0, 0, w, s, size, 0, 0, max_lines, false); }
void text_scroll(float x, float y, float w, float h, const char *s, float size, unsigned c) {
    if (!s) return;
    static char key[96]; static double t0;
    if (strncmp(key, s, sizeof key - 1)) { snprintf(key, sizeof key, "%s", s); t0 = uib_seconds(); }
    const float th = text_box_height(w, s, size), extra = th - h + 2;
    float off = 0;
    if (extra > 0) {
        // Quieto 3 s arriba, baja a 10 px/s, quieto 3 s abajo, sube a 40 px/s, y otra vez.
        const float down = extra / 10.f, up = extra / 40.f, cyc = 3.f + down + 3.f + up;
        float t = fmodf((float)(uib_seconds() - t0), cyc);
        if (t < 3.f) off = 0;
        else if (t < 3.f + down) off = (t - 3.f) * 10.f;
        else if (t < 6.f + down) off = extra;
        else off = extra - (t - 6.f - down) * 40.f;
    }
    // Las líneas que entran o salen de la caja se funden (además del recorte).
    clip(x - 2, y, w + 4, h);
    g_fade = extra > 0; g_fade_y0 = y; g_fade_y1 = y + h;
    text_box(x, y - off, w, s, size, c, 0, 99);
    g_fade = false;
    clip_off();
}
static float text_box_impl(float x, float y, float w, const char *s, float size, unsigned c, int align, int max_lines, bool draw) {
    char line[400]; int n = 0, lines = 0; float lh = size * 1.12f;
    const char *p = s;
    while (*p && lines < max_lines) {
        // Coge palabras mientras quepan.
        const char *q = p, *last_ok = p; char trial[400]; int tn = 0;
        while (*q && *q != '\n') {
            const char *ws = q; while (*q && *q != ' ' && *q != '\n') q++;
            int add = (int)(q - ws) + (tn ? 1 : 0);
            if (tn + add >= (int)sizeof trial - 1) break;
            char tmp[400]; memcpy(tmp, trial, tn); int tl = tn; if (tn) tmp[tl++] = ' '; memcpy(tmp + tl, ws, q - ws); tl += (int)(q - ws); tmp[tl] = 0;
            if (text_width(tmp, size) > w && tn) { q = ws; break; }
            memcpy(trial, tmp, tl + 1); tn = tl; last_ok = q;
            while (*q == ' ') q++;
        }
        if (!tn) { // una palabra que no cabe: se corta
            while (*q && *q != ' ' && *q != '\n' && tn < (int)sizeof trial - 1) trial[tn++] = *q++;
            trial[tn] = 0; last_ok = q;
        }
        memcpy(line, trial, tn + 1); n = tn; (void)n;
        if (draw) {
            const float ly = y + lines * lh;
            unsigned cc = c;
            if (g_fade) {
                const float fl = size * 0.9f, mid = ly + size * 0.5f, top = (mid - g_fade_y0) / fl, bot = (g_fade_y1 - mid) / fl;
                float k = top < bot ? top : bot; k = k < 0 ? 0 : k > 1 ? 1 : k;
                cc = (c & 0xffffff00) | (unsigned)((c & 0xff) * k);
            }
            if (cc & 0xff) text_shadow(align == 1 ? x + w / 2 : align == 2 ? x + w : x, ly, line, size, cc, align);
        }
        lines++;
        p = last_ok; while (*p == ' ') p++; if (*p == '\n') p++;
    }
    return lines * lh;
}

// ---------------------------------------------------------------------------------------------------------------
// Entrada: la lee pump() (platform_3ds.cpp) en el hilo del juego, cada cuadro.
static Input g_in, g_prev_in;
static bool g_touch_eaten;   // v42: el lápiz es de un desplegable abierto este cuadro (touch_eat)
void touch_eat() { g_touch_eaten = true; }
const Input &raw_input() { return g_in; }
bool raw_touch_down() { return g_in.touch && !g_prev_in.touch; }
bool raw_touch_up() { return !g_in.touch && g_prev_in.touch; }
const Input &input() { if (!g_touch_eaten) return g_in; static Input e; e = g_in; e.touch = false; return e; }
bool touch_down() { return !g_touch_eaten && raw_touch_down(); }
bool touch_up() { return !g_touch_eaten && raw_touch_up(); }
// lr: fila con flechas (hit_row): izquierda/derecha no mueven el foco, hacen lo de sus flechas.
struct NavBox { float x, y, w, h; bool lr; };
static NavBox g_nav_boxes[64];
static int g_nav_count, g_nav_cursor, g_nav_seen, g_nav_dx;
static bool g_nav_enabled, g_nav_visible, g_nav_activate;
void navigation_begin(const char *scope, bool enabled) {
    static char last[128];
    if (strcmp(last, scope ? scope : "")) {
        snprintf(last, sizeof last, "%s", scope ? scope : "");
        g_nav_count = g_nav_cursor = 0; g_nav_visible = false;
    }
    g_nav_enabled = enabled; g_nav_seen = 0; g_nav_activate = false; g_nav_dx = 0;
    if (!enabled) return;
    if (touch_down()) g_nav_visible = false;
    int dx = key_down(UI_K_RIGHT) ? 1 : key_down(UI_K_LEFT) ? -1 : 0;
    int dy = key_down(UI_K_DOWN) ? 1 : key_down(UI_K_UP) ? -1 : 0;
    if (dx || dy) {
        // La primera pulsación solo enseña qué está elegido; las siguientes mueven el foco.
        const bool was_visible = g_nav_visible;
        g_nav_visible = true;
        if (!was_visible) return;
        if (dx && !dy && g_nav_cursor < g_nav_count && g_nav_boxes[g_nav_cursor].lr) { g_nav_dx = dx; return; }
        if (g_nav_count && g_nav_cursor < g_nav_count) {
            NavBox a = g_nav_boxes[g_nav_cursor];
            float best = 1e20f; int pick = g_nav_cursor;
            for (int i = 0; i < g_nav_count; ++i) {
                NavBox b = g_nav_boxes[i];
                float x = b.x + b.w / 2 - a.x - a.w / 2, y = b.y + b.h / 2 - a.y - a.h / 2;
                float forward = dx ? x * dx : y * dy, side = dx ? fabsf(y) : fabsf(x);
                if (forward < 1) continue;
                float score = forward + side * 3;
                if (score < best) { best = score; pick = i; }
            }
            g_nav_cursor = pick;
        }
    }
    if (key_down(UI_K_A)) { g_nav_visible = true; g_nav_activate = true; }
}
bool hit(float x, float y, float w, float h) {
    bool touch = touch_down() && g_in.tx >= x && g_in.tx < x + w && g_in.ty >= y && g_in.ty < y + h;
    if (g_nav_enabled && g_screen == 1 && g_nav_seen < 64) {
        int i = g_nav_seen++;
        g_nav_boxes[i] = {x, y, w, h, false};
        if (touch) g_nav_cursor = i;
        if (i == g_nav_cursor && g_nav_activate) { g_nav_activate = false; return true; }
    }
    return touch;
}
bool tap(float x, float y, float w, float h) {
    return touch_down() && g_in.tx >= x && g_in.tx < x + w && g_in.ty >= y && g_in.ty < y + h;
}
int hit_row(float x, float y, float w, float h) {
    const int i = g_nav_seen;
    const bool pressed = hit(x, y, w, h);
    if (i < 64 && g_nav_enabled && g_screen == 1) {
        g_nav_boxes[i].lr = true;
        if (i == g_nav_cursor && g_nav_dx) { const int d = g_nav_dx; g_nav_dx = 0; return d; }
    }
    return pressed ? 2 : 0;
}
// Con el mando, el elemento elegido se ve como en el juego: cambia de color (botón dorado, aro dorado, texto amarillo),
// sin ningún marco alrededor. Cada página lo pregunta al dibujar, antes de su hit(): nav_focus(k) es el k-ésimo hit()
// que viene a continuación.
bool nav_active() { return g_nav_enabled && g_nav_visible && g_screen == 1; }
bool nav_focus(int k) { return nav_active() && g_nav_seen + k == g_nav_cursor; }
void navigation_end() {
    if (!g_nav_enabled) return;
    g_nav_count = g_nav_seen;
    if (g_nav_cursor >= g_nav_count) g_nav_cursor = 0;
}
bool key_down(u32 k) { return (g_in.held & k) && !(g_prev_in.held & k); }

// Pulsaciones de GameCube para el juego: cola con flancos limpios (2 retrazos abajo, 2 arriba).
struct Press { u16 bits; u8 down, up; };
static Press g_queue[32]; static int g_qn;
static u16 g_hold_bits; static int g_hold_left;
void press(u16 gc_bits, int hold) { if (g_qn < 32) g_queue[g_qn++] = {gc_bits, (u8)(hold > 0 ? hold : 2), 2}; }
void press_seq(const u16 *bits, int n) { for (int i = 0; i < n; i++) press(bits[i], 2); }
bool pressing() { return g_qn > 0 || g_hold_left > 0; }
void activate(const char *item) {
    if (!item) return;
    w3d_fe_highlight(item);
    if (g_qn < 31) { g_queue[g_qn++] = {0, 0, 4}; g_queue[g_qn++] = {0x100, 8, 4}; }   // 4 retrazos para el resaltado, luego A 8 retrazos
}
// Una vez por pad_read (un retrazo).
static u16 queue_step() {
    if (g_hold_left > 0) { g_hold_left--; return g_hold_bits; }
    if (!g_qn) return 0;
    Press &p = g_queue[0];
    if (p.down) { p.down--; return p.bits; }
    if (p.up) { p.up--; return 0; }
    memmove(g_queue, g_queue + 1, sizeof(Press) * (g_qn - 1)); g_qn--;
    return 0;
}

// ---------------------------------------------------------------------------------------------------------------
// Tiempo.
static u64 g_t0;   // microsegundos del primer cuadro
double now() { return uib_seconds() - (double)g_t0 * 1e-6; }

// ---------------------------------------------------------------------------------------------------------------
// Idioma. El juego guarda el suyo en SAVE.Language (0 inglés, 3 francés, 4 alemán, 5 italiano, 9 español; 10 ninguno).
// Antes de elegirlo vale el de la consola.
static int g_console_lang = -1;   // 0..4 como lang()
static int console_lang() {
    if (g_console_lang >= 0) return g_console_lang;
    g_console_lang = uib_console_lang();
    uib_log("[ui] idioma de la consola -> %d\n", g_console_lang);
    return g_console_lang;
}
static int g_lang_cache = -1; static u32 g_lang_frame = ~0u;
int lang() {
    if (g_lang_frame == g_frame && g_lang_cache >= 0) return g_lang_cache;
    g_lang_frame = g_frame;
    unsigned v = w3d_fe_game_mode() >= 0 ? w3d_fe_prop_uint("SAVE.Language", 10) : 10;
    g_lang_cache = v == 3 ? 1 : v == 4 ? 2 : v == 5 ? 3 : v == 9 ? 4 : v == 0 ? 0 : console_lang();
    return g_lang_cache;
}
static const char *const kTr[T_COUNT][5] = {
    {"Loading...", "Chargement...", "Wird geladen...", "Caricamento...", "Cargando..."},
    {"PRESS START", "APPUYEZ SUR START", "DRÜCKE START", "PREMI START", "PULSA START"},
    {"or tap the screen", "ou touchez l'écran", "oder tippe auf den Bildschirm", "o tocca lo schermo", "o toca la pantalla"},
    {"Developer", "Développeur", "Entwickler", "Sviluppatore", "Desarrollador"},
    {"Overlay", "Overlay", "Overlay", "Overlay", "Overlay"},
    // v39: un solo interruptor para las tres combinaciones (diag.cpp, debug_keys).
    {"Debug buttons", "Boutons de débogage", "Debug-Tasten", "Tasti di debug", "Botones de depuración"},
    {"Off: none of these buttons does anything.", "Désactivé : aucun de ces boutons ne fait rien.", "Aus: Keine dieser Tasten tut etwas.", "Off: nessuno di questi tasti fa nulla.", "Desactivado: ninguno de esos botones hace nada."},
#if defined(__3DS__) && !defined(W3D_TEST)
    {"SELECT: dump. R+SELECT: console.", "SELECT : dump. R+SELECT : console.", "SELECT: Dump. R+SELECT: Konsole.", "SELECT: dump. R+SELECT: console.", "SELECT: informe rápido. R+SELECT: consola."},
#else
    {"SELECT: dump. R+SELECT: console. START+SELECT: auto test.", "SELECT : dump. R+SELECT : console. START+SELECT : test auto.", "SELECT: Dump. R+SELECT: Konsole. START+SELECT: Autotest.", "SELECT: dump. R+SELECT: console. START+SELECT: test automatico.", "SELECT: informe rápido. R+SELECT: consola. START+SELECT: prueba autom\xc3\xa1tica."},
#endif
    {"On", "Oui", "Ein", "Sì", "Sí"},
    {"Off", "Non", "Aus", "No", "No"},
    {"Back", "Retour", "Zurück", "Indietro", "Volver"},
    {"Accept", "Accepter", "Annehmen", "Accetta", "Aceptar"},
    {"Yes", "Oui", "Ja", "Sì", "Sí"},
    {"No", "Non", "Nein", "No", "No"},
    {"Are you sure?", "Êtes-vous sûr ?", "Bist du sicher?", "Sei sicuro?", "¿Estás seguro?"},
    {"Use the buttons and the top screen.", "Utilisez les boutons et l'écran du haut.", "Benutze die Tasten und den oberen Bildschirm.", "Usa i pulsanti e lo schermo superiore.", "Usa los botones y la pantalla de arriba."},
    {"Colour", "Couleur", "Farbe", "Colore", "Color"},
    {"Control", "Contrôle", "Steuerung", "Controllo", "Control"},
    {"Human", "Humain", "Mensch", "Umano", "Humano"},
    {"CPU", "CPU", "CPU", "CPU", "CPU"},
    {"Pull the lever!", "Tirez le levier !", "Zieh den Hebel!", "Tira la leva!", "¡Tira de la palanca!"},
    {"Continue", "Continuer", "Weiter", "Continua", "Continuar"},
    {"Quit", "Quitter", "Beenden", "Esci", "Salir"},
    {"Draw", "Match nul", "Unentschieden", "Pareggio", "Empate"},
    {"Weapons", "Armes", "Waffen", "Armi", "Armas"},
    {"Pause", "Pause", "Pause", "Pausa", "Pausa"},
    {"Add", "Ajouter", "Hinzufügen", "Aggiungi", "Añadir"},
    {"Create", "Créer", "Erstellen", "Crea", "Crear"},
    {"Landscape", "Paysage", "Landschaft", "Paesaggio", "Escenario"},
    {"Wormpot", "Wormpot", "Wormpot", "Wormpot", "Wormpot"},
    {"Rules", "Règles", "Regeln", "Regole", "Reglas"},
    {"Start", "Démarrer", "Start", "Inizia", "Empezar"},
    {"Add a team", "Ajouter une équipe", "Team hinzufügen", "Aggiungi una squadra", "Añadir un equipo"},
    {"All the teams are already in the match.", "Toutes les équipes sont déjà dans la partie.", "Alle Teams sind schon im Spiel.", "Tutte le squadre sono già nella partita.", "Todos los equipos ya están en la partida."},
    {"Close", "Fermer", "Schließen", "Chiudi", "Cerrar"},
    {"Worms", "Vers", "Würmer", "Vermi", "Gusanos"},
    {"Delete", "Supprimer", "Löschen", "Elimina", "Borrar"},
    {"Team", "Équipe", "Team", "Squadra", "Equipo"},
    {"Match", "Partie", "Spiel", "Partita", "Partida"},
    {"Music", "Musique", "Musik", "Musica", "Música"},
    {"Effects", "Effets", "Effekte", "Effetti", "Efectos"},
    {"Speech", "Voix", "Sprache", "Voci", "Voces"},
    {"Generate", "Générer", "Erzeugen", "Genera", "Generar"},
    {"Theme", "Thème", "Thema", "Tema", "Tema"},
    {"Time of day", "Moment", "Tageszeit", "Ora del giorno", "Hora del día"},
    {"Spin", "Lancer", "Drehen", "Gira", "Girar"},
    {"Reset", "Réinitialiser", "Zurücksetzen", "Azzera", "Reiniciar"},
    {"Edit", "Modifier", "Bearbeiten", "Modifica", "Editar"},
    {"Health", "Énergie", "Energie", "Energia", "Vida"},
    {"Turn time", "Durée du tour", "Rundenzeit", "Tempo turno", "Tiempo de turno"},
    {"Round time", "Durée de la manche", "Spielzeit", "Tempo round", "Tiempo de ronda"},
    {"Wins", "Victoires", "Siege", "Vittorie", "Victorias"},
    {"Save", "Sauvegarder", "Speichern", "Salva", "Guardar"},
    {"Load", "Charger", "Laden", "Carica", "Cargar"},
    {"OK", "OK", "OK", "OK", "Aceptar"},
    {"Members", "Membres", "Mitglieder", "Membri", "Miembros"},
    {"Cosmetics", "Cosmétiques", "Kosmetik", "Cosmetici", "Cosméticos"},
    {"Identity", "Identité", "Identität", "Identità", "Identidad"},
    {"Name", "Nom", "Name", "Nome", "Nombre"},
    {"Next", "Suivant", "Weiter", "Avanti", "Siguiente"},
    {"Retry", "Réessayer", "Wiederholen", "Riprova", "Reintentar"},
};
const char *tr(TextId id) { return id >= 0 && id < T_COUNT ? kTr[id][lang()] : ""; }
// v39: los textos del juego ya vienen en UTF-8 (Spanish.xom: «¿Estás seguro?» es c2 bf 45 73 74 c3 a1 73...). Hasta la
// v38 se tomaban siempre por Latin-1 y cada letra con acento o signo (¿, á, ñ, ©) salía como dos («Â¿EstÃ¡s seguro?»):
// lo que el dueño vio en la consola en español. En inglés casi no hay y no se notaba.
static bool valid_utf8(const char *s) {
    bool multi = false;
    for (const u8 *p = (const u8 *)s; *p;) {
        const u8 c = *p;
        int n = c < 0x80 ? 0 : (c & 0xe0) == 0xc0 && c >= 0xc2 ? 1 : (c & 0xf0) == 0xe0 ? 2 : (c & 0xf8) == 0xf0 ? 3 : -1;
        if (n < 0) return false;
        p++;
        for (int i = 0; i < n; i++, p++) if ((*p & 0xc0) != 0x80) return false;
        if (n) multi = true;
    }
    return multi;
}
// A UTF-8 en un búfer rotatorio de 8 cadenas: tal cual si ya lo es; si no, desde Latin-1 (Windows-1252).
const char *game_text(const char *s) {
    static char buf[8][1400]; static int k;
    if (!s) return "";
    if (valid_utf8(s)) { char *o = buf[k = (k + 1) & 7]; snprintf(o, sizeof buf[0], "%s", s); return o; }
    char *o = buf[k = (k + 1) & 7]; int n = 0;
    // Windows-1252: los 0x80-0x9f son comillas, guiones, ... y ™ (la fuente del juego los trae).
    static const u16 k1252[32] = {0x20ac, 0, 0x201a, 0x192, 0x201e, 0x2026, 0x2020, 0x2021, 0x2c6, 0x2030, 0x160, 0x2039, 0x152, 0, 0x17d, 0,
                                  0, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014, 0x2dc, 0x2122, 0x161, 0x203a, 0x153, 0, 0x17e, 0x178};
    for (; *s && n < 1390; s++) {
        u32 c = (u8)*s;
        if (c >= 0x80 && c < 0xa0) c = k1252[c - 0x80] ? k1252[c - 0x80] : '?';
        if (c < 0x80) o[n++] = (char)c;
        else if (c < 0x800) { o[n++] = (char)(0xc0 | c >> 6); o[n++] = (char)(0x80 | (c & 0x3f)); }
        else { o[n++] = (char)(0xe0 | c >> 12); o[n++] = (char)(0x80 | (c >> 6 & 0x3f)); o[n++] = (char)(0x80 | (c & 0x3f)); }
    }
    o[n] = 0;
    return o;
}
// Caché por clave (el mismo literal) e idioma: una clave que no existe se busca una sola vez.
const char *key_text(const char *key, const char *fallback) {
    // A property of the current control is live data, never a language-cache entry.
    if (!strcmp(key, "FE.ToolTip")) {
        const char *t = w3d_fe_text(key);
        return t ? game_text(t) : fallback;
    }
    struct Entry { const char *key; int lang; bool found; char text[200]; };
    static Entry cache[48]; static int used;
    if (w3d_fe_game_mode() < 6) return fallback;   // los textos del FE están cargados desde el menú
    const int l = lang();
    if (l == 4 && !strcmp(key, "Lang.SinglePlayer")) return "Un Jugador";
    if (l == 4 && !strcmp(key, "Lang.SoundOptions")) return "Opciones de sonido";
    for (int i = 0; i < used; i++) if (cache[i].key == key && cache[i].lang == l) return cache[i].found ? cache[i].text : fallback;
    static int victim; Entry &e = cache[used < 48 ? used++ : (victim = (victim + 1) % 48)];
    e.key = key; e.lang = l;
    const char *t = w3d_fe_text(key);
    e.found = t != nullptr;
    if (t) { snprintf(e.text, sizeof e.text, "%s", game_text(t)); uib_log("[ui] texto %s: %s\n", key, e.text); }
    else uib_log("[ui] sin texto para %s\n", key);
    return e.found ? e.text : fallback;
}

}  // namespace ui

// ===============================================================================================================
// Arranque y título.
using namespace ui;
namespace {
// v30 (el dueño, 2026-11-07): logos → fundido a negro → título con su fundido de entrada → START → fundido a negro →
// pantalla de carga de Worms mientras se carga el menú → menú. kLoading es ahora el negro entre los logos y el título.
enum Boot { kSplash, kLoading, kToTitle, kTitle, kTitleOut, kMenuLoad, kGameIn, kGame };
Boot g_boot = kSplash;
double g_boot_t;          // Momento en que empezó el estado actual.
bool g_skip_boot;         // W3D_NO_SPLASH=1, la prueba automática o los guiones de mando: sin arranque ni título.
bool g_own_title;         // El juego no llegó a su título (modo 5): título propio con el arte de romfs:/ui.
bool g_title_sent;
float g_load_out = -1;    // kMenuLoad (y kLoading si hay icono): cuándo empezó a irse el icono de carga (-1: aún no)
double g_start_at;        // Cuándo se pulsó START en el título.
void set_boot(Boot b) {
    g_boot = b; g_boot_t = now(); uib_log("[ui] arranque: estado %d, modo del juego %d, %.2f s\n", (int)b, w3d_fe_game_mode(), now());
    // El título entra con su música desde el principio (la pone su panel), y sigue en el menú (core/native/fe_bridge.cpp).
    if (b == kToTitle && !g_own_title) w3d_fe_title_music();
}
float since() { return (float)(now() - g_boot_t); }
float clamp01(float v) { return v < 0 ? 0 : v > 1 ? 1 : v; }
unsigned black(float a) { return (unsigned)(clamp01(a) * 255.f + 0.5f); }

const char *const kSplashLicense = "Logos/License.tga";
// El icono de carga del juego: «WORMS» con la granada y el «3D» con su mira, que gira en cuatro cuadros de 64 px.
const char *const kTinyLoad = "Logos/tinyload.tga", *const kReticle = "Logos/Anim3DReticle.tga";

bool at_menu() { const char *m = w3d_test_fe_menu(); return m && !strcmp(m, "FE.MainMenu"); }
extern "C" int w3d_match_clock(unsigned *ms);   // core/sdk/sdk_core.cpp: hay partida (el gusano 0 tiene vida)

void draw_splash(float a) {
    begin(0);
    rect(0, 0, 400, 240, 0x000000ff);
    const u32 al = (u32)(a * 255.f + 0.5f);
    // Licensed By Nintendo (Logos/License.tga, blanco sobre negro), el logo de SEGA sin su fondo blanco, el de Team17 y
    // el crédito del port.
    const Img *lic = img(kSplashLicense, 1);
    if (lic->tex >= 0) { float w = 220, h = w * lic->h / lic->w; sprite(lic, 200 - w / 2, 26, w, h, 0xffffff00 | al); }
    const Img *sega = img("sega.w3ui", 0);
    if (sega->tex >= 0) sprite(sega, 200 - 92.4f / 2, 72.9f, 92.4f, 32.2f, 0xffffff00 | al);
    const Img *t17 = img("team17.w3ui", 0);
    if (t17->tex >= 0) sprite(t17, 200 - 54.6f, 134.75f, 109.2f, 31.5f, 0xffffff00 | al);
    text(200, 196, "Ported by Esteban PdN", 14, 0xdcdcdc00 | al, 1);
}
// Carga (el dueño, 2026-11-07): en negro, el icono de carga del propio juego, el que enseña pequeño (89x24 px, en el centro)
// mientras prepara el título, al doble de su tamaño: «WORMS» y el «3D» con su mira girando (10 cuadros por segundo).
// Sustituye a la pantalla de carga propia que había (el mar, el logo grande, otro icono y «Cargando...»).
// v30: sale entre el título y el menú (kMenuLoad), no antes del título.
void draw_loading_icon(float a, float black_a = 1.f) {
    begin(0);
    rect(0, 0, 400, 240, black(black_a));
    const u32 al = (u32)(clamp01(a) * 255.f + 0.5f);
    const Img *w = img(kTinyLoad, 0), *r = img(kReticle, 0);
    if (w->tex >= 0) sprite(w, 105, 90, 122, 61, 0xffffff00 | al);
    if (r->tex >= 0) { const int f = (int)(now() * 10.0) & 3; sprite(r, 227, 88, 63, 63, 0xffffff00 | al, (f & 1) * 64.f, (f >> 1) * 64.f, 64, 64); }
}
// Título propio (solo de reserva: si el juego no muestra el suyo).
void draw_own_title_top(float fade_black) {
    begin(0);
    const Img *bg = img("titulo_arriba.w3ui", 2);
    if (bg->tex >= 0) sprite(bg, 0, 0, 400, 240); else rect(0, 0, 400, 240, 0x050a1cff);
    const Img *logo = img("logo.w3ui", 0);
    float bob = sinf((float)now() * 1.6f) * 3.f;
    if (logo->tex >= 0) sprite(logo, 14, 20 + bob, 300, 101);
    if (fade_black > 0) rect(0, 0, 400, 240, black(fade_black));
}
// Arriba sobre el título del juego: solo el fundido.
void draw_title_top(float fade_black) {
    if (g_own_title) { draw_own_title_top(fade_black); return; }
    begin(0);
    if (fade_black > 0) rect(0, 0, 400, 240, black(fade_black));
}
void draw_title_bottom(float fade_black) {
    begin(1);
    // El fondo de arriba sigue abajo (el dueño, 2026-11-07: «que el fondo de arriba se expanda para la de abajo también»):
    // con el lienzo alto (w3d_ui_tall) la escena del título del juego continúa en la pantalla de abajo (la nebulosa y, más
    // abajo, el espacio con estrellas del propio cielo del título). Sin lienzo alto (título propio), el cielo de romfs:/ui.
    if (!w3d_ui_tall()) {
        const Img *bg = img("titulo_abajo.w3ui", 2);
        if (bg->tex >= 0) sprite(bg, 0, 0, 320, 240); else rect(0, 0, 320, 240, 0x050a1cff);
    }
    hide_top("fuente0.w3ui"); hide_top("fuente1.w3ui");   // el copyright del título original: va solo abajo
    float pulse = 0.55f + 0.45f * sinf((float)now() * 4.f);
    u32 a = (u32)(pulse * 255.f);
    text_shadow(160, 88, tr(T_PRESS_START), 20, 0xffd84000 | a, 1);
    text_shadow(160, 112, tr(T_TAP_SCREEN), 14, 0xffffff00 | a, 1);
    text_shadow(160, 186, "Published by SEGA Europe Limited", 12, 0xd2d2d2ff, 1);
    text_shadow(160, 201, "\xc2\xa9 2003 Team17 Software Limited", 12, 0xd2d2d2ff, 1);
    text_shadow(160, 218, "Ported by Esteban PdN", 12, 0xd2d2d2ff, 1);
#if defined(__3DS__)
    // La versión instalada, abajo a la izquierda como hasta la v27 (el dueño, 2026-11-03: «versión 3, 4, 5...»).
    { char v[24]; snprintf(v, sizeof v, "%s", W3D_RELEASE_NAME); text_shadow(6, 226, v, 10, 0x9aa8c8ff, 0); }
#endif
    if (fade_black > 0) rect(0, 0, 320, 240, black(fade_black));
}
void draw_black_bottom() { begin(1); rect(0, 0, 320, 240, 0x000000ff); }

bool any_start() { return key_down(UI_K_START) || key_down(UI_K_A) || touch_down(); }

// Arranque: devuelve true si ya dibujó la pantalla de abajo.
bool boot_frame() {
    float t = since();
    const int mode = w3d_fe_game_mode();
    // El icono pequeño del juego no sale: el de la UI, al doble, lo sustituye (y mientras entra el título aún lo pinta).
    if (g_boot <= kToTitle || g_boot == kTitleOut || g_boot == kMenuLoad) { hide_top_force(kTinyLoad); hide_top_force(kReticle); }
    switch (g_boot) {
    case kSplash: {
        // El tiempo cuenta desde que sus imágenes están en VRAM: los primeros cuadros del juego tardan en llegar.
        static bool ready;
        if (!ready) {
            ready = img(kSplashLicense, 1)->tex >= 0 && img("sega.w3ui", 0)->tex >= 0 && img("team17.w3ui", 0)->tex >= 0;
            if (!ready && t < 6.f) { begin(0); rect(0, 0, 400, 240, 0x000000ff); draw_black_bottom(); return true; }
            ready = true; g_boot_t = now(); t = 0;
        }
        const float in = 0.5f, hold = 2.2f, out = 0.5f;
        // v30: los logos siguen hasta que el título del juego (modo 5) está listo (como mucho 8 s más), así del negro se
        // pasa directo al título. START salta al fundido de salida igual que antes (y no espera al título).
        static bool skipped;
        if (key_down(UI_K_START) && t < in + hold) { skipped = true; g_boot_t = now() - (in + hold); t = in + hold; }
        static double out_at = -1;
        if (out_at < 0 && t >= in + hold && (mode >= 5 || skipped || t > in + hold + 8.f)) out_at = now();
        float a = t < in ? t / in : out_at < 0 ? 1.f : 1.f - (float)(now() - out_at) / out;
        draw_splash(clamp01(a));
        draw_black_bottom();
        if (out_at >= 0 && now() - out_at >= out) { g_load_out = -1; set_boot(kLoading); }
        return true;
    }
    case kLoading: {
        // Negro entre los logos y el título (0,3 s). Si el título del juego aún no está listo, sigue en negro; a los 2 s
        // sale el icono de carga para que no parezca colgado. Si el juego se salta el título (o tarda más de 45 s),
        // título propio en cuanto haya menú.
        const bool icon = t > 2.f;
        if (icon) {
            if (g_load_out < 0 && mode == 5) g_load_out = t;
            float a = clamp01((t - 2.f) / 0.25f);
            if (g_load_out >= 0) a = fminf(a, 1.f - (t - g_load_out) / 0.3f);
            draw_loading_icon(a);
        } else { begin(0); rect(0, 0, 400, 240, 0x000000ff); }
        draw_black_bottom();
        if (!icon && t > 0.3f && mode == 5) set_boot(kToTitle);
        else if (icon && g_load_out >= 0 && t - g_load_out >= 0.3f) set_boot(kToTitle);
        else if (t > 1.2f && (mode >= 6 || t > 45.f) && (at_menu() || t > 60.f)) { g_own_title = true; uib_log("[ui] sin título del juego: título propio\n"); set_boot(kToTitle); }
        return true;
    }
    case kToTitle: {
        // Del negro al título, en las dos pantallas a la vez (el dueño, 2026-11-07: «que el fundido en negro del inicio sea
        // de las dos pantallas»): el mismo velo negro arriba y abajo, que se va en 1,8 s. Debajo, el propio fundido del
        // título del juego cubre las dos mitades (es la misma escena en el lienzo alto). La música la pone el título.
        if (g_own_title) { float f = 1.f - clamp01((t - 0.1f) / 0.6f); draw_title_top(f); draw_title_bottom(f); }
        else { float f = 1.f - clamp01((t - 0.2f) / 1.8f); draw_title_top(f); draw_title_bottom(f); }
        if (t > (g_own_title ? 0.75f : 2.0f)) set_boot(kTitle);
        return true;
    }
    case kTitle:
        draw_title_top(0); draw_title_bottom(0);
        if (t > 0.3f && any_start()) {
            // El título del juego avanza con el mensaje Input.StartButton (d27i_panel_fade_message_8011ddb0); él mismo
            // hace su fundido y manda FCS.TitleScreenFinished.
            if (!g_own_title) w3d_fe_run("Input.StartButton");
            g_title_sent = false;
            g_start_at = now();
            set_boot(kTitleOut);
        }
        return true;
    case kTitleOut: {
        // Fundido a negro de las dos pantallas (0,4 s) y luego la pantalla de carga (kMenuLoad).
        float f = clamp01(t / 0.4f);
        draw_title_top(f); draw_title_bottom(f);
        if (t > 0.45f) { g_load_out = -1; set_boot(kMenuLoad); }
        return true;
    }
    case kMenuLoad: {
        // Pantalla de carga de Worms mientras se carga el menú: el icono entra en 0,25 s, está al menos 1,2 s y hasta que
        // el menú principal está montado, y se va en 0,3 s; luego el menú entra desde negro (kGameIn).
        // Si a los 3 s de START sigue en el título, otro Input.StartButton (nunca FCS.TitleScreenFinished a destiempo: el
        // título aún vivo hace fallar el menú, prueba t28a).
        const float ts = (float)(now() - g_start_at);
        if (!g_title_sent && ts > 3.f && mode == 5 && !g_own_title) { g_title_sent = true; w3d_fe_run("Input.StartButton"); }
        if (g_own_title && !g_title_sent && mode == 5 && ts > 0.5f) { g_title_sent = true; w3d_fe_run("Input.StartButton"); }
        if (g_load_out < 0 && t > 1.2f && (at_menu() || ts > 20.f)) g_load_out = t;
        float a = clamp01(t / 0.25f);
        if (g_load_out >= 0) a = fminf(a, 1.f - (t - g_load_out) / 0.3f);
        draw_loading_icon(a);
        draw_black_bottom();
        if (g_load_out >= 0 && t - g_load_out >= 0.3f) set_boot(kGameIn);
        return true;
    }
    case kGameIn: {
        begin(0); rect(0, 0, 400, 240, black(1.f - t / 0.5f));
        if (t > 0.5f) set_boot(kGame);
        return false;
    }
    case kGame: return false;
    }
    return false;
}
// v33 (el dueño, 2026-11-08: «al comenzar una partida se me quedan textos en la pantalla de abajo en vez de ponerse toda
// negra»; «el logo de carga entre el menú inicial y el principal está bien, con el tamaño nuevo, pero para iniciar
// partidas y hacer todas las otras cosas las cargas salen con la antigua: tienes que tener coherencia»).
// Fuera del arranque, cada carga del juego es la misma pantalla que entre el título y el menú (kMenuLoad): negro arriba
// con el icono de carga del juego al doble, y negro abajo. Empieza al pasar del menú a la partida o de la partida al
// menú (modos 6 y 7), o en cuanto el juego pinta su icono pequeño (que ya no se ve nunca). Acaba cuando el juego deja
// de pintarlo, han pasado 1,2 s y lo siguiente está listo (en la partida, su reloj: w3d_match_clock); entonces el icono
// se va en 0,3 s y el negro de arriba en 0,4 s, ya con la pantalla de abajo de la partida o del menú.
// Antes, al empezar la partida la página del menú principal seguía abajo 1-2 s (título, flechas y «Quick Start»: el
// frontend aún se llama FE.MainMenu mientras se desmonta) y arriba salía el icono pequeño del juego.
// full: carga entre el menú y la partida (abajo en negro); si no, el juego solo enseña su icono un momento (Land Select
// generando un paisaje...): arriba igual, y abajo sigue la página.
// v38 (el dueño, 2026-11-10, con la v37 en la consola: «le doy partida rápida y se pone un fondo negro y se tranca unos
// segunditos; queda fondo negro pero algunos elementos del menú se quedan ahí flotando abajo»). El juego carga la partida
// de un tirón dentro de un cuadro (5,4 s en la consola) y el cambio de modo solo se ve después: el último cuadro en
// pantalla era el menú a medio desmontar (el fondo 3D ya no se dibuja y la página sigue). Ahora la carga empieza en
// cuanto el frontend pide la partida (GameLogic.StartGame, w3d_fe_game_starting): ese mismo cuadro ya sale negro en las
// dos pantallas y con el icono entero (early: sin el fundido de entrada, porque ese cuadro es el que se queda).
// v39 (el dueño, 2026-11-10, con la v38): «que se ponga negro primero totalmente, negro de una, y después el coso de carga
// aparezca en un fade in; y después, pum, se corte: no haya fade out, aparezco dentro de la partida». El primer cuadro de
// la carga va en negro del todo; el icono entra en 8 cuadros (por cuadros y no por reloj: el juego carga varios segundos
// dentro de un solo cuadro y con el reloj el fundido no se vería); al estar lista, la carga se quita de golpe. Para que el
// corte dé con todo en su sitio, en la partida se espera también a que el panel de abajo tenga sus texturas subidas.
struct GameLoad { double t0 = -1; int last_mode = -2, quiet = 0, frames = 0; bool full = false, early = false; };
GameLoad g_load;
// 0: sin carga; 1: cargando (arriba el icono, abajo negro: no hay página); 2: el juego enseña su icono un momento (la
// página de abajo sigue y el velo de arriba va después de ella, game_load_overlay).
int game_load_frame() {
    hide_top_force(kTinyLoad); hide_top_force(kReticle);   // el icono pequeño del juego no se ve nunca
    const int mode = w3d_fe_game_mode();
    const bool icon = top_drawn(kTinyLoad) || top_drawn(kReticle);
    GameLoad &L = g_load;
    const bool idle = L.t0 < 0;
    const bool starting = mode == 6 && w3d_fe_game_starting();
    if (starting && !L.early) {
        if (idle) { L.t0 = now(); L.quiet = 0; L.frames = 0; }
        L.full = L.early = true;
        uib_log("[ui] carga: el frontend pide la partida (cuadro %u)\n", (unsigned)g_frame);
    }
    if (mode != L.last_mode) {
        if ((L.last_mode == 6 && mode == 7) || (L.last_mode == 7 && mode == 6)) {
            if (idle) { L.t0 = now(); L.quiet = 0; L.frames = 0; }
            L.full = true;
            uib_log("[ui] carga: del modo %d al %d\n", L.last_mode, mode);
        }
        L.last_mode = mode;
    }
    if (icon && L.t0 < 0) {
        uib_log("[ui] carga: el juego enseña su icono (modo %d)\n", mode);
        L.full = false; L.t0 = now(); L.quiet = 0; L.frames = 0;
    }
    if (L.t0 < 0) return 0;
    const float t = (float)(now() - L.t0);
    L.frames++;
    L.quiet = icon ? 0 : L.quiet + 1;
    unsigned ms;
    bool next_ready = mode == 7 ? w3d_match_clock(&ms) != 0 : mode == 6 ? w3d_test_fe_menu() != nullptr : true;
    if (mode == 7 && w3d_fe_native_layout() && !hud_panel_preload() && t < 30.f) next_ready = false;
    if ((t > (L.full ? 1.2f : 0.5f) && L.quiet >= 6 && next_ready && !starting) || t > 90.f) {
        uib_log("[ui] carga: lista en %.1f s (%d cuadros)\n", t, L.frames);
        L.t0 = -1; L.full = L.early = false; L.frames = 0;
        pages_cut();
        return 0;   // corte: sin fundido de salida
    }
    return L.full ? 1 : 2;
}
// Arriba: el negro y el icono. En las cargas cortas, encima de lo que haya dibujado la página.
void game_load_overlay() {
    const GameLoad &L = g_load;
    if (L.t0 < 0) return;
    set_fade(1);
    draw_loading_icon(clamp01((float)(L.frames - 1) / 8.f), 1.f);
}
// Idioma de la consola (v28): se fija durante el título (FE.SetLanguage), así el menú no monta FE.LanguageSelect, y al
// llegar al menú principal se hace la comprobación de la tarjeta que hacía la bandera. Si aun así sale la pantalla de
// idioma (por ejemplo sin título), se pulsa la bandera como el jugador.
const char *const kLangNames[5] = {"English", "French", "German", "Italian", "Spanish"};
void language_at_title() {
    static bool set, checked;
    const int mode = w3d_fe_game_mode();
    if (!set && mode == 5) { set = true; uib_log("[ui] idioma en el título: %s\n", kLangNames[console_lang()]); w3d_fe_set_language(kLangNames[console_lang()]); }
    if (set && !checked && at_menu()) { checked = true; w3d_fe_card_check(); }
}
// Idioma de la consola en FE.LanguageSelect (una vez por visita; si el jugador vuelve desde Opciones, elige él).
void auto_language() {
    static bool done; static u32 seen;
    const char *m = w3d_test_fe_menu();
    bool here = m && !strcmp(m, "FE.LanguageSelect");
    if (!here) { seen = 0; return; }
    if (done) return;
    if (++seen < 8) return;   // que el menú termine de montarse
    done = true;
    const char *l = kLangNames[console_lang()];
    uib_log("[ui] idioma automático: %s\n", l);
    activate(l);   // la bandera de ese idioma, como el jugador (sus órdenes: SetLanguage, SaveToFile, DoMemCardWarning)
}
}  // namespace

// ===============================================================================================================
// Ganchos de la plataforma.
namespace ui { double g_kb_start_at = -10; }   // cuándo aceptó la UI un teclado con START (ui_pages.cpp)
static int g_ui_tall;   // ver w3d_ui_tall
extern "C" int w3d_ui_load_state(void) { return g_load.t0 >= 0 ? 1 : 0; }   // pruebas (diag.cpp, W3D_SHOT_LOADEND)
extern "C" {
// La plataforma, cada cuadro: botones (UI_K_*), y si hay toque, su posición en la pantalla de abajo (320x240).
void w3d_ui_input(unsigned held, int touch, int tx, int ty) {
    using namespace ui;
    g_touch_eaten = false;
    g_prev_in = g_in;
    g_in.held = held;
    g_in.touch = touch != 0;
    if (touch) { g_in.tx = tx; g_in.ty = ty; }
}
// En pad_read: botones de GameCube que la UI pulsa por el jugador, y la máscara del arranque y del título.
extern "C" int w3d_fe_start_holding(void);
unsigned w3d_ui_pad(w3d::plat::Pad *o) {
    u16 extra = queue_step();
    // v42: ni mientras se retiene el arranque de la partida (fe_bridge.cpp, kStartHold): el menú sigue vivo por debajo.
    if ((!g_skip_boot && g_boot < kGameIn) || w3d_fe_start_holding()) {
        // Mientras dura el arranque el juego no ve el mando (START no salta nada por debajo del título).
        o->buttons = 0; o->stick_x = o->stick_y = o->cstick_x = o->cstick_y = 0; o->trigger_l = o->trigger_r = 0;
    }
    if (ui::pages_eat_b(o->buttons & 0x200)) o->buttons &= ~0x200;
    // Teclado del juego abierto: aceptarlo con el texto vacío tira el juego (fe_bridge.cpp). START acepta por la UI (que
    // antes recupera el texto) y A sobre la tecla de aceptar, con el texto vacío, tampoco le llega.
    // Las dos se siguen tapando hasta que se sueltan: si no, al cerrarse el teclado el juego las veía en el campo de texto
    // y lo volvía a abrir.
    // START: también si la UI lo acaba de usar para aceptar (el juego puede ver la misma pulsación un cuadro más tarde, con
    // el teclado ya cerrado, y la tomaba por un toque en el campo; validation/f5_start).
    { static bool eat_start;
      if (!(o->buttons & 0x1000)) eat_start = false;
      else if (w3d_kb_open() || uib_seconds() - ui::g_kb_start_at < 0.5) eat_start = true;
      if (eat_start) o->buttons &= ~0x1000; }
    if (w3d_kb_guard_accept((o->buttons & 0x100) != 0)) o->buttons &= ~0x100;
    // L y R (gatillos de GameCube 0x40 y 0x20) giran el worm de Crear equipo y de la ventana del equipo.
    if (ui::pages_eat_lr()) { o->buttons &= ~0x60; o->trigger_l = o->trigger_r = 0; }
    if (ui::pages_capture()) {
        o->buttons &= ~(0x100 | 0x0f);
        if (ui::pages_capture() == 2) o->buttons &= ~0x200;
        o->stick_x = o->stick_y = 0;
    }
    if(w3d_fe_game_mode()==7 && w3d_fe_native_layout()) {
        // Start is dispatched by page_match/page_pause once per UI press.
        // Keeping it held in the engine could reopen the popup on Resume.
        o->buttons &= ~(0x400 | 0x1000);
        if(w3d_fe_prop_uint("WeaponPanel.Open",0)) o->buttons &= ~0x200;
    }
    o->buttons |= extra;
    return extra;
}
bool w3d_ui_booting(void) { return !g_skip_boot && g_boot < kGame; }
// Francotirador de UM: mira del Fusil francotirador encima de la imagen del juego, en la pantalla de arriba, solo en
// primera persona (SniperCursorGraphicEntity::IsVisible de UM: cámara Head). Tres capas de Sniper.Cursor.Mesh a escala 1
// (mods/armas-um/francotirador/tools/hacer_mira_capas.py): anillo con cristal y máscara (±300 unidades del HUD de UM),
// cruz (±342,5) y punto (±9,04); cada cuadro se escalan con In_Sniper (w3d_franco_mira_escalas). El HUD de UM mide
// 1280x720; en los 400x240 de arriba caben ±600 x ±360 unidades (1/3 de píxel por unidad), como mira.png.
// Fuera del anillo, la máscara es color liso. Debajo, una línea de ayuda con los botones y los aumentos (HelpText de UM:
// «Apunta usando 1stPerson, acerca el zoom con ZoomIn/ZoomOut y pulsa Fire»). W3D_FRANCO_AYUDA=0 la quita.
extern "C" int w3d_franco_scope(float *zoom);
extern "C" int w3d_franco_active(void);
extern "C" void w3d_franco_mira_escalas(float t, float *outer, float *inner, float *dot);
static void franco_scope_frame(void) {
    using namespace ui;
    static bool was;
    static double t0;
    if (!w3d_franco_active()) { was = false; return; }
    const Img *anillo = img("mira_anillo.w3ui", 0), *cruz = img("mira_cruz.w3ui", 0), *punto = img("mira_punto.w3ui", 0);
    float z;
    static int ayuda = -1;
    if (ayuda < 0) { const char *e = getenv("W3D_FRANCO_AYUDA"); ayuda = e ? atoi(e) != 0 : 1; }
    if (!w3d_franco_scope(&z)) {
        was = false;
        if (ayuda) { begin(0); text_shadow(200, 222, lang() == 4 ? "Mant\xc3\xa9n R para apuntar con la mira" : "Hold R to aim through the scope", 13, 0xd8e4ffff, 1); }
        return;
    }
    if (!was) { was = true; t0 = uib_seconds(); }
    float so, si, sd;
    w3d_franco_mira_escalas((float)(uib_seconds() - t0), &so, &si, &sd);
    // v40 (el dueño, tras la v39: la cruz creció pero el hueco por el que se mira seguía igual de chico; la cruz, solo un
    // 15 % más que la original): cruz y punto a 1,15/3; el anillo con su hueco a 1,55/3, así queda más escenario
    // alrededor de los brazos de la cruz. El anillo (300 de medio lado, 0,66 al parar) mide 206 de los 240 de alto.
    // v43 (el dueño): la cruz (rayas y punto) un 5 % más, 1,15 × 1,05; el anillo con su hueco igual. Y la cruz va
    // detrás: primero la cruz, luego el anillo (su cristal del hueco la deja ver, su borde oscuro tapa los brazos de los
    // lados) y al final la máscara lisa de fuera, que tapa lo que la cruz saca del cuadrado del anillo al entrar.
    const float k = 1.2075f / 3.0f, kr = 1.55f / 3.0f, cx = 200, cy = 120;
    const unsigned mascara = 0x001631ff;
    begin(0);
    const float ro = 300.0f * so * kr;   // medio lado del anillo en píxeles
    if (anillo->tex >= 0) {
        const float ri = 342.525f * si * k, rd = 9.0446f * sd * k;
        if (cruz->tex >= 0 && ri > 0.5f) sprite(cruz, cx - ri, cy - ri, 2 * ri, 2 * ri);
        if (punto->tex >= 0 && rd > 0.25f) sprite(punto, cx - rd, cy - rd, 2 * rd, 2 * rd);
        sprite(anillo, cx - ro, cy - ro, 2 * ro, 2 * ro);
        // máscara lisa alrededor del cuadrado del anillo
        if (cy - ro > 0) rect(0, 0, 400, cy - ro, mascara);
        if (cy + ro < 240) rect(0, cy + ro, 400, 240 - (cy + ro), mascara);
        if (cx - ro > 0) rect(0, cy - ro, cx - ro, 2 * ro, mascara);
        if (cx + ro < 400) rect(cx + ro, cy - ro, 400 - (cx + ro), 2 * ro, mascara);
    } else {
        rect(0, 0, 400, 240, mascara);   // el primer cuadro, antes de subir las texturas
    }
    if (ayuda) {
        char t[96];
        const bool es = lang() == 4;
        snprintf(t, sizeof t, es ? "Y: acercar    B: alejar    A: disparar     x%.1f" : "Y: zoom in    B: zoom out    A: fire     x%.1f", 1.0f / (z > 0 ? z : 1));
        text_shadow(cx, 222, t, 13, 0xd8e4ffff, 1);
    }
}
void w3d_ui_frame(void) {
    using namespace ui;
    static bool first = true;
    if (first) {
        first = false;
        g_t0 = (u64)(uib_seconds() * 1e6);
        // La prueba automática se la salta salvo en su etapa de arranque (W3D_SPLASH, test_3ds.cpp).
        g_skip_boot = getenv("W3D_NO_SPLASH") || ((getenv("W3D_VPAD") || getenv("W3D_AUTOKEYS") || uib_test_running()) && !getenv("W3D_SPLASH"));
        if (g_skip_boot) g_boot = kGame;
        set_boot(g_boot);
        w3d_fe_title_set_hide_press(1);
    }
    g_frame++;
    { const int m = w3d_fe_game_mode(); g_ui_tall = (m == 5 || m == 6 || m == 7) && (g_skip_boot || g_boot >= kToTitle) && !g_own_title; }
    // También en la prueba automática (v29: sus menús los recorre el mando virtual, como un jugador).
    if (w3d_fe_game_mode() >= 0 && !getenv("W3D_NO_AUTOLANG")) { language_at_title(); auto_language(); }
    bool bottom_done = false;
    set_fade(1);
    if (g_skip_boot || g_boot == kGame) franco_scope_frame();   // francotirador de UM: la mira, arriba (con alfa 1)
    if (!g_skip_boot && g_boot != kGame) bottom_done = boot_frame();
    // v38: el icono de carga siempre subido (son dos texturas pequeñas): el cuadro en que el frontend pide la partida es
    // el que se queda en pantalla durante la carga, y ahí ya tiene que salir.
    if (g_skip_boot || g_boot == kGame) { img(kTinyLoad, 0); img(kReticle, 0); }
    const int load = !bottom_done && (g_skip_boot || g_boot == kGame) ? game_load_frame() : 0;   // v33: cargas del juego
    if (load == 1) { draw_black_bottom(); bottom_done = true; }
    if (!bottom_done && !uib_console_busy()) {
        begin(1);
        pages_frame();
        navigation_end();
    }
#if defined(__3DS__)
    if (const char *notice=diag_quick_notice()) {
        begin(1); set_fade(1); rect(48,218,224,22,0x0b2a50f0);
        text_fit(160,222,notice,12,212,0xffdc48ff,1);
    }
#endif
    if (load) game_load_overlay();
    uib_end();
    g_screen = -1;
    hide_commit();
}
// El fondo 3D del juego sigue en la pantalla de abajo (lienzo alto) en el título y los menús, no en la partida ni
// durante el arranque (ahí abajo va negro). En 3DS de momento no se usa.
int w3d_ui_tall(void) { return g_ui_tall; }
void w3d_ui_after_frame(void) {
    using namespace ui;
    uib_tex_gc();
    load_font_metrics();
    load_pending(4);
}
}
