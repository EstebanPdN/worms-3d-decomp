// Ocultar arriba piezas del menú original (v28): la página de abajo de cada menú dice qué imágenes del disco no deben
// verse arriba (por ejemplo los iconos del menú principal, que pasan al carrusel de abajo), y el backend de GX no dibuja
// lo que use esas texturas. Una textura se reconoce por su contenido: el mismo tamaño y 16 píxeles de muestra parecidos
// (la paleta de GameCube redondea los colores del TGA, así que se compara con tolerancia). Común a 3DS y Mac.
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <utility>
#include <vector>
#include "ui.h"

namespace ui {
bool read_game_file(const char *path, std::vector<u8> &out);
bool decode_tga_public(const std::vector<u8> &b, std::vector<u8> &rgba, u32 &w, u32 &h);
bool read_own_public(const char *name, std::vector<u8> &rgba, u32 &w, u32 &h);
}

extern "C" {
struct W3dUiSig { unsigned short w, h; unsigned char px[16][4]; };
void w3d_ui_sig_make(const unsigned char *rgba, unsigned w, unsigned h, W3dUiSig *s) {
    s->w = (unsigned short)w; s->h = (unsigned short)h;
    for (int i = 0; i < 16; i++) {
        unsigned x = (unsigned)(((i & 3) + 0.5f) / 4.f * w), y = (unsigned)(((i >> 2) + 0.5f) / 4.f * h);
        memcpy(s->px[i], rgba + ((size_t)y * w + x) * 4, 4);
    }
}
}

namespace {
// seen: último cuadro en que se usó (oculta). min_h: 0 se oculta entera; si no, solo en las piezas de al menos min_h
// píxeles de alto que caen enteras en la pantalla de arriba (hide_top_big); next_min_h, lo pedido en este cuadro.
struct Entry { char name[64]; W3dUiSig sig; bool ok; unsigned seen; float min_h, next_min_h; };
std::vector<Entry> g_known;          // firmas ya calculadas por nombre
std::vector<int> g_set, g_next;      // índices en g_known: el conjunto en vigor y el que se arma en este cuadro
unsigned g_gen = 1;
unsigned g_commits = 10;   // cuadros de la UI (hide_commit)
const W3dUiSig *sig_of(const char *name, int *index) {
    for (size_t i = 0; i < g_known.size(); i++) if (!strcmp(g_known[i].name, name)) { *index = (int)i; return g_known[i].ok ? &g_known[i].sig : nullptr; }
    Entry e; memset(&e, 0, sizeof e); strncpy(e.name, name, sizeof e.name - 1);
    std::vector<ui::u8> file, rgba; ui::u32 w = 0, h = 0;
    // "x.w3ui" es arte propio (romfs:/ui). Las texturas de GameCube están boca abajo respecto a la imagen (el
    // decodificador de GX empieza por la fila de abajo), así que la firma se hace sobre la imagen invertida.
    char nm[64]; snprintf(nm, sizeof nm, "%s", name);
    char *flip = strstr(nm, "!flip"); if (flip) *flip = 0;
    flip = nm;
    if (strstr(nm, ".w3ui")) e.ok = ui::read_own_public(nm, rgba, w, h);
    else e.ok = ui::read_game_file(nm, file) && ui::decode_tga_public(file, rgba, w, h);
    if (e.ok && flip) for (ui::u32 y = 0; y < h / 2; y++) for (ui::u32 x = 0; x < w * 4; x++) std::swap(rgba[(size_t)y * w * 4 + x], rgba[(size_t)(h - 1 - y) * w * 4 + x]);
    if (e.ok) w3d_ui_sig_make(rgba.data(), w, h, &e.sig);
    else uib_log("[ui] ocultar: no se pudo leer %s\n", name);
    g_known.push_back(e);
    *index = (int)g_known.size() - 1;
    return e.ok ? &g_known.back().sig : nullptr;
}
bool close(const W3dUiSig &a, const W3dUiSig &b) {
    if (a.w != b.w || a.h != b.h) return false;
    for (int i = 0; i < 16; i++) {
        const unsigned char *p = a.px[i], *q = b.px[i];
        int da = abs(p[3] - q[3]);
        if (da > 48) return false;
        if (p[3] < 24 && q[3] < 24) continue;   // casi transparente: el color no cuenta
        for (int c = 0; c < 3; c++) if (abs(p[c] - q[c]) > 40) return false;
    }
    return true;
}
}

namespace ui {
// Durante el cuadro: esta imagen no se ve arriba (vale hasta el cuadro siguiente).
void hide_top_force(const char *name);
void hide_top(const char *name) {
    if(w3d_fe_native_layout() && w3d_fe_game_mode()==6) return;
    hide_top_force(name);
}
// Igual, también en los menús con los controles del juego recolocados (Land Select: la miniatura del mapa).
void hide_top_force(const char *name) { hide_top_big(name, 0); }
// Solo sus piezas grandes de la pantalla de arriba (min_px de alto o más; 0: entera). Con dos pantallas el backend
// oculta una textura en todas partes, y la ventana de un popup comparte la suya con el teclado del juego (su ventana,
// abajo, y el recuadro del texto, arriba): Equipo nuevo quita solo la ventana.
void hide_top_big(const char *name, float min_px) {
    int idx;
    if (!sig_of(name, &idx)) return;
    for (int i : g_next) if (i == idx) { if (min_px < g_known[idx].next_min_h) g_known[idx].next_min_h = min_px; return; }
    g_next.push_back(idx);
    g_known[idx].next_min_h = min_px;
}
// Al terminar el cuadro de la UI: si el conjunto cambió, el backend vuelve a mirar sus texturas.
// Si el juego dibujó (y se ocultó) esta imagen en los últimos cuadros: sirve para saber qué enseña el juego.
bool top_drawn(const char *name) {
    int idx;
    if (!sig_of(name, &idx)) return false;
    return g_known[idx].seen + 3 >= g_commits;
}
void hide_commit() {
    g_commits++;
    bool same = g_next.size() == g_set.size();
    if (same) for (size_t i = 0; i < g_next.size(); i++) if (g_next[i] != g_set[i]) { same = false; break; }
    if (!same) { g_set = g_next; g_gen++; }
    for (int i : g_next) g_known[i].min_h = g_known[i].next_min_h;   // se mira en cada dibujo: no hace falta otra vuelta
    g_next.clear();
}
}

extern "C" {
// Dos pantallas: texturas del juego que se cambian por una copia retocada al decodificarlas (gx_metal.mm,
// texture_for). Se reconocen por la misma firma que las ocultas, al derecho o al revés; la copia (.w3ui, de arriba
// abajo) se da con las filas como el TGA del disco, que empieza por la de abajo. Puede ser mayor que el original (las
// coordenadas de textura son relativas).
// - Info_Back sin el aro de la «R» (pedido del usuario; docs/ui-3ds/arte-hd/info_back_sin_r.png).
// - smallicons.tga (iconos de arma del HUD, 32 px) con los iconos HD (smallicons_hd: weapons_hd y, en su última fila,
//   las casillas originales al doble; tools/build3ds/ui/arte_hd_w3ui.py).
// La firma de 16 puntos no basta aquí: dos texturas casi vacías en esos puntos (la fuente de números del HUD y estos
// iconos) parecen iguales. Antes de cambiar se comparan 32x32 puntos con la imagen del disco.
// Puntos que coinciden (de 32x32) con la imagen del disco, leída al derecho o al revés; -1 si casi no tiene dibujo.
static int match_score(const unsigned char *rgba, unsigned w, unsigned h, const std::vector<ui::u8> &ref, bool flip) {
    int ok = 0, opaque = 0;
    for (int j = 0; j < 32; j++) for (int i = 0; i < 32; i++) {
        const unsigned x = (unsigned)((i + .5f) / 32 * w), y = (unsigned)((j + .5f) / 32 * h);
        const unsigned char *p = rgba + ((size_t)y * w + x) * 4, *q = ref.data() + ((size_t)(flip ? h - 1 - y : y) * w + x) * 4;
        if (q[3] >= 24) opaque++;
        ok += abs(p[3] - q[3]) <= 48 && (p[3] < 24 && q[3] < 24 || (abs(p[0] - q[0]) <= 40 && abs(p[1] - q[1]) <= 40 && abs(p[2] - q[2]) <= 40));
    }
    return opaque > 16 ? ok : -1;
}
const unsigned char *w3d_ui_tex_swap(const W3dUiSig *s, const unsigned char *rgba, unsigned *ow, unsigned *oh) {
    static const char *const kSwap[][2] = {{"HUD/Info_Back.tga", "info_back_sin_r.w3ui"}, {"HUD/smallicons.tga", "smallicons_hd.w3ui"}};
    enum { kN = sizeof kSwap / sizeof kSwap[0] };
    static std::vector<ui::u8> ref[kN], cache[kN][2]; static ui::u32 rw[kN], rh[kN], cw[kN], ch[kN]; static bool loaded[kN];
    for (int k = 0; k < kN; k++) {
        if (!loaded[k]) {
            loaded[k] = true;
            std::vector<ui::u8> file, img;
            if (!(ui::read_game_file(kSwap[k][0], file) && ui::decode_tga_public(file, ref[k], rw[k], rh[k]))) ref[k].clear();
            if (ui::read_own_public(kSwap[k][1], img, cw[k], ch[k]))
                for (int f = 0; f < 2; f++) {
                    cache[k][f].resize(img.size());
                    for (ui::u32 y = 0; y < ch[k]; y++) memcpy(cache[k][f].data() + (size_t)y * cw[k] * 4, img.data() + (size_t)(f ? y : ch[k] - 1 - y) * cw[k] * 4, (size_t)cw[k] * 4);
                }
        }
        if (ref[k].empty() || cache[k][0].empty() || rw[k] != s->w || rh[k] != s->h) continue;
        // La firma corta solo descarta rápido; decide la comparación de 32x32 puntos, en la orientación que mejor encaje.
        int idx; const W3dUiSig *a = sig_of(kSwap[k][0], &idx); char nm[72]; snprintf(nm, sizeof nm, "%s!flip", kSwap[k][0]);
        const W3dUiSig *b = sig_of(nm, &idx);
        if (!(a && close(*a, *s)) && !(b && close(*b, *s))) continue;
        const int s0 = match_score(rgba, rw[k], rh[k], ref[k], false), s1 = match_score(rgba, rw[k], rh[k], ref[k], true);
        const int best = s0 >= s1 ? 0 : 1;
        if ((best ? s1 : s0) < 900) continue;
        *ow = cw[k]; *oh = ch[k];
        // decode_tga_public da las filas de arriba abajo; el .w3ui también: la orientación que encaja es la de la copia.
        return cache[k][1 - best].data();
    }
    return nullptr;
}
unsigned w3d_ui_hide_gen(void) { return g_gen; }
// 0 si no está oculta; si lo está, su número (para w3d_ui_hidden_drawn).
int w3d_ui_sig_hidden(const W3dUiSig *s) {
    for (int i : g_set) if (close(g_known[i].sig, *s)) return i + 1;
    return 0;
}
// El backend la va a usar en este cuadro (y no la dibuja arriba).
void w3d_ui_hidden_drawn(int id) { if (id > 0 && id <= (int)g_known.size()) g_known[id - 1].seen = g_commits; }
// 0: la oculta se quita entera; si no, solo en las piezas de al menos estos píxeles de alto enteras arriba (hide_top_big).
float w3d_ui_hidden_min_h(int id) { return id > 0 && id <= (int)g_known.size() ? g_known[id - 1].min_h : 0; }
}
