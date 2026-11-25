// Dual-screen review: shared touch controls plus native FE nodes reflowed by
// core/native/fe_layout.cpp. Original resources, selection and animations stay
// owned by the game. Metal routes the native battle HUD to the lower screen.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "ui.h"
#include "../../core/native/hud_state.h"
#include "hud_panel.h"
#include "../../core/native/card_ui.h"

extern "C" {
static int map_tex=-1; static float map_u=1,map_v=1;
static int hud_team_rows=2;
int w3d_ui_map_texture(float *u,float *v) {*u=map_u;*v=map_v;return map_tex;}
int w3d_ui_hud_team_rows() {return hud_team_rows;}
int w3d_fe_weapon_cell(int,int *);
void w3d_fe_wormpot_action(int);
int w3d_hud_read(W3dHud *o);                 // core/native/hud_abajo.cpp
// Ropa (core/native/hat_militar.cpp): 0 sin gorro, k el gorro k; nombres en español y en inglés.
extern volatile int w3d_hat_mode;
int w3d_hat_count(void);
const char *w3d_hat_label(int);
const char *w3d_hat_label_en(int);
}

namespace ui {
namespace {
const char *const kBackdrop = "Logos/FE_Backdrop.tga";
const char *const kBorderBlue = "Frontend/Mechanics/Text_Border_Blue.tga";
const char *const kBorderYellow = "Frontend/Mechanics/Text_Border_Yellow.tga";
const char *const kRingGreen = "Frontend/Mechanics/Icon_Border_Green.tga";
const char *const kRingHi = "Frontend/Mechanics/Icon_Border_HiLight.tga";
const char *const kArrow = "Frontend/Mechanics/Arrow_On.tga";        // flecha amarilla hacia la izquierda
const char *const kBack = "Frontend/Mechanics/Prev_On.tga";          // flecha curva de volver
const char *const kStart = "Frontend/Mechanics/Game_ON.tga";         // granada de empezar / aceptar
const char *const kOval = "Frontend/Mechanics/Icon_Alt_Blue.tga";    // botón ovalado (No / Yes)
const char *const kOvalHi = "Frontend/Mechanics/Icon_Alt_HiLight.tga";
const char *const kTitleLine = "Frontend/Mechanics/Title_Line.tga";
// Arte propio (tools/build3ds/ui/hacer_arte_ui.py), con los colores del juego y sin escalar las esquinas.
const char *const kPanel = "panel_blue_hd.w3ui", *const kButton = "button_blue_hd.w3ui", *const kButtonHi = "button_gold_hd.w3ui";
const char *const kFrameGold = "marco_oro.w3ui", *const kArrowOwn = "flecha.w3ui";
// Márgenes iguales a los dos lados en todas las páginas de abajo (Back a la izquierda, Start a la derecha).
const float kMargin = 8;

// --- Piezas comunes -------------------------------------------------------------------------------------------
void backdrop(float dim = 0) {
    // v39 (el dueño: «le di a START y el fondo estaba negro; me gustaría que fuera el azul, el mismo del HUD de abajo»):
    // en la partida, la pausa y sus diálogos van sobre el fondo del panel (hud35_face), sin oscurecer.
    if (w3d_fe_game_mode() == 7 && w3d_fe_native_layout()) {
        const Img *face = img("hud35_face.w3ui", 2);
        if (face->tex >= 0) sprite(face, 0, 0, 320, 240); else rect(0, 0, 320, 240, 0x0b2a50ff);
        return;
    }
    // Con el lienzo alto el fondo es el mundo 3D del juego que sigue bajo la pantalla de arriba.
    if (!w3d_ui_tall()) sprite(img(kBackdrop, 2), 0, 0, 320, 240);
    if (dim > 0) rect(0, 0, 320, 240, (unsigned)(dim * 255.f) | 0x00000a00);
}
// Título arriba a la izquierda con la línea amarilla del juego, como "Main Menu".
void title(const char *t) {
    float w = text_width(t, 18);
    text_shadow(14, 8, t, 18, 0xffffffff, 0);
    // La línea amarilla del juego (Title_Line, 32x16) en tres trozos: los extremos redondos sin estirar.
    const Img *ln = img(kTitleLine, 0);
    const float h = 6, cap = 3, x = 12, y = 28, lw = w + 6;
    sprite(ln, x, y, cap, h, 0xffffffff, 0, 0, 8, 16);
    sprite(ln, x + cap, y, lw - 2 * cap, h, 0xffffffff, 8, 0, 16, 16);
    sprite(ln, x + lw - cap, y, cap, h, 0xffffffff, 24, 0, 8, 16);
}
// Botón de volver (flecha curva) abajo a la izquierda; true si se toca.
// Prev_On (128x128) solo tiene dibujo en (6,24)-(118,104): se usa ese trozo, sin achatar.
void eat_b();
bool back_button(const char *label = nullptr) {
    const float h = 32, w = h * 112.f / 80.f, x = kMargin, y = 240 - kMargin - h;
    sprite(img(kBack,0), x, y, w, h, 0xffffffff, 6,24,112,80);
    text_shadow(x + w + 6, y + h / 2 - 7, label ? label : tr(T_BACK), 14, nav_focus() ? 0xffdc48ff : 0xffffffff, 0);
    if (hit(0, y - 8, x + w + 70, h + 16)) return true;
    // Con B: la misma B no le llega al juego hasta que se suelta. Si no, al cerrarse la ventana del equipo con B el
    // menú de debajo la veía todavía pulsada y Multijugador volvía al menú principal (Azahar ui_multi y Mac k2_popb).
    if (pages_capture() == 2 && key_down(UI_K_B)) { eat_b(); return true; }
    return false;
}
// Empezar o aceptar: la granada del juego (Game_ON, dibujo en (9,7)-(55,56)) abajo a la derecha, con el mismo margen.
bool start_button(const char *label) {
    const float h = 36, w = h * 46.f / 49.f, x = 320 - kMargin - w, y = 240 - kMargin - h;
    sprite(img(kStart, 1), x, y, w, h, 0xffffffff, 9, 7, 46, 49);
    text_shadow(x - 6, y + h / 2 - 7, label, 14, nav_focus() ? 0xffdc48ff : 0xffffffff, 2);
    return hit(x - 70, y - 8, 320 - (x - 70), h + 16);
}
// Flecha propia: dir -1 a la izquierda, +1 a la derecha (la misma imagen, al revés).
void arrow(float x, float y, int dir, float w = 28, float h = 32) {
    const Img *a = img(kArrow, 0);
    if (a->tex < 0) return;
    const float u1 = (float)a->w / a->pw, v1 = (float)a->h / a->ph;
    if (dir < 0) quad(a->tex, x, y, x + w, y + h, 0, 0, u1, v1, 0xffffffff);
    else quad(a->tex, x, y, x + w, y + h, u1, 0, 0, v1, 0xffffffff);
}
// The game's pill button (Text_Border_Blue/Yellow, 40x16 at (2,109)), redrawn at 4x from the original
// (docs/ui-3ds/arte-hd/PROCEDENCIA.md): stretched to 34-44 px the original showed its pixels. Three slices: the round
// caps at their ratio, the middle (identical columns) stretched. The original strip stays as a fallback.
const char *const kPill = "pill_blue_hd.w3ui", *const kPillHi = "pill_gold_hd.w3ui";
void native_button(float x,float y,float w,float h,bool selected=false,unsigned tint=0xffffffff) {
    float cap=fminf(h*.5f,w*.25f);
    const Img *hd=img(selected?kPillHi:kPill,0);
    if(!hd->failed) {
        const float sc=hd->h*.5f;
        sprite(hd,x,y,cap,h,tint,0,0,sc,hd->h);
        sprite(hd,x+cap,y,w-2*cap,h,tint,sc,0,hd->w-2*sc,hd->h);
        sprite(hd,x+w-cap,y,cap,h,tint,hd->w-sc,0,sc,hd->h);
        return;
    }
    const Img *a=img(selected?kBorderYellow:kBorderBlue,0);
    sprite(a,x,y,cap,h,tint,2,109,8,16);
    sprite(a,x+cap,y,w-2*cap,h,tint,10,109,24,16);
    sprite(a,x+w-cap,y,cap,h,tint,34,109,8,16);
}
// Botón con texto sobre un panel del juego.
bool text_button(float x, float y, float w, float h, const char *label, bool on = false, float size = 15, const char *icon = nullptr) {
    native_button(x,y,w,h,on || nav_focus());
    if (icon) sprite_fit(img(icon, 1), x + 8, y + 4, h - 8, h - 8);
    text_fit(x + w / 2 + (icon ? (h - 8) / 2 : 0), y + h / 2 - size / 2, label, size, w - 20 - (icon ? h : 0), 0xffffffff, 1);
    return hit(x, y, w, h);
}
// Icono del juego dentro de su aro (verde, o dorado si está resaltado).
void ring_icon(const char *icon, float cx, float cy, float d, bool hi, unsigned tint = 0xffffffff) {
    sprite(img(hi ? kRingHi : kRingGreen, 1), cx - d / 2, cy - d / 2, d, d, tint);
    float a = d * 0.86f;
    sprite(img(icon, 1), cx - a / 2, cy - a / 2, a, a, tint);
}
// Etiqueta de un consejo del juego: lo que va antes de " - " ("Quick Start - Press this button..." -> "Quick Start").
const char *tip_label(const char *key, const char *fallback) {
    // Spanish tips are sentences (often with ':'), not stable menu labels.
    if (lang() == 4 && key) {
        static const struct { const char *key, *label; } labels[] = {
            {"FE.Tip.QuickStart", "Inicio rápido"}, {"FE.Tip.SinglePlayerMenu", "Un Jugador"},
            {"FE.Tip.MultiplayerMenu", "Multijugador"}, {"FE.Tip.OptionsMenu", "Opciones"},
            {"FE.Tip.TutorialMenu", "Entrenamiento"}, {"FE.Tip.CampaignMenu", "Campaña"},
            {"FE.Tip.ChallengeMenu", "Desafíos"}, {"FE.Tip.OptionsSoundOptions", "Sonido"},
            {"FE.Tip.OptionsWormapedia", "Gusaciclopedia"}, {"FE.Tip.OptionsWeaponOptions", "Opciones de armas"},
            {"FE.Tip.OptionsGameOptions", "Reglas de partida"}, {"FE.Screen.Language", "Idioma"}
        };
        for (const auto &l : labels) if (!strcmp(key, l.key)) return l.label;
    }
    const char *t = key ? key_text(key, nullptr) : nullptr;
    if (!t) return fallback;
    static char buf[4][64]; static int k; char *o = buf[k = (k + 1) & 3];
    const char *d = strstr(t, " - ");
    size_t n = d ? (size_t)(d - t) : strlen(t);
    if (n > 40) return fallback;
    memcpy(o, t, n); o[n] = 0;
    return o;
}

// --- Carrusel -------------------------------------------------------------------------------------------------
// Continuo (da la vuelta), con deslizamiento suave hacia el elegido y arrastre con el dedo. El del centro es el
// resaltado del juego: aro dorado y el latido del Select_Loop del juego; los demás, con el aro de su color.
// own: botón del juego que dibuja la UI (el suyo se oculta y se sigue pulsando por su nombre): el de idiomas de Opciones,
// que en el juego es de los ovalados inclinados y en el carrusel no se veía redondo como los demás (el dueño, 2026-11-07).
struct Item { const char *name, *icon, *tip, *label, *ring; bool own; };
// prev_pos/prev_sel: la posición y la elección con las que entró el cuadro anterior (ver carousel()).
struct Carousel { int sel = 0; float pos = 0, prev_pos = 0; int prev_sel = 0; double last_t = 0; bool drag = false, moved = false, fresh = false; float x0 = 0, pos0 = 0; const char *menu = nullptr; char last_hl[48] = ""; };
Carousel g_main, g_single, g_opts;   // el del menú principal respira (slot_geom)
const char *ring_of(const char *colour) {
    static char b[4][64]; static int k;
    char *o = b[k = (k + 1) & 3];
    snprintf(o, 64, "Frontend/Mechanics/Icon_Border_%s.tga", colour ? colour : "Green");
    return o;
}
// Sitio de un puesto a d puestos del centro (con decimales), el mismo para los botones del juego (w3d_ui_carousel_layout,
// que fe_layout.cpp coloca) y para los de la UI (carousel_slot): centro de su caja y su lado. En el menú principal el del
// centro respira un 1 % (dos segundos por ciclo). Más allá de 2,4 puestos no se ve. (Los de la UI iban 12 px más abajo,
// con el icono al 86 % y otro latido: el dueño, 2026-11-07, «que estén todos iguales».)
bool slot_geom(float d, bool breathe, float *x, float *y, float *side) {
    const float ad = fabsf(d);
    if (ad > 2.4f) return false;
    *x = 160 + d * 96.f - (d > 0 ? 1 : -1) * (ad > 1 ? (ad - 1) * 28.f : 0);
    *y = 92 + ad * 6.f;
    *side = 116.f * (ad < 1 ? 1.f - 0.42f * ad : 0.58f - 0.12f * (ad - 1));
    if (breathe && ad < .05f) *side *= 1.f + .01f * sinf((float)now() * 3.14159265f);
    return true;
}
// Un puesto dibujado por la UI (los que no son botones del juego, o todos sin la colocación nativa): como el juego, el aro
// y el icono llenan la misma caja (el aro ocupa el 84 % central de su imagen y los iconos casi toda la suya, así que
// asoman por fuera del aro). hi: el elegido, con el aro dorado.
void carousel_slot(const Item &it, float d, bool hi, bool breathe) {
    if(w3d_fe_native_layout() && it.name && !it.own) return;
    float x, y, s;
    if (!slot_geom(d, breathe, &x, &y, &s)) return;
    sprite(img(hi ? kRingHi : ring_of(it.ring), 1), x - s / 2, y - s / 2, s, s);
    sprite(img(it.icon, 1), x - s / 2, y - s / 2, s, s);
}
// Devuelve el índice pulsado (el del centro) o -1. park: un botón del juego oculto en ese menú donde dejar su resaltado
// mientras está elegido uno de la UI (si no, el anterior seguía con el aro dorado y había dos).
int carousel(Carousel &c, const Item *items, int n, const char *menu_title, bool *special_pick = nullptr, const char *park = nullptr) {
    if (c.menu != menu_title) {
        c.menu = menu_title; c.last_hl[0] = 0; c.pos = (float)c.sel; c.fresh = true; c.last_t = 0;
        c.prev_pos = c.pos; c.prev_sel = c.sel;
    }
    // v39 (el dueño, con la v38 en la consola: «le voy dando a la derecha y la animación no es del todo fluida, va como a
    // trompicones de rato, y no es falta de rendimiento, es algo raro»). Medido cuadro a cuadro en Azahar
    // (W3D_SHOT_DPAD): los botones que dibuja el juego salen en pantalla dos cuadros después de lo que dibuja la UI en
    // ese mismo cuadro (uno porque el juego lee la posición al actualizar, antes de que la UI calcule la siguiente; otro
    // porque su imagen llega a la pantalla un cuadro más tarde que la capa de la UI). Los puestos que dibuja la propia UI
    // (Team Creator en el menú principal, Developer en Opciones) iban por eso dos cuadros por delante de sus vecinos:
    // hasta 37 px al empezar a moverse, y con el aro dorado antes de que el anterior lo soltara. Solo se notaba con uno
    // de esos puestos a la vista («de rato»). Ahora la UI dibuja los suyos con la posición y la elección de hace dos
    // cuadros, las mismas que están en pantalla en los del juego: al entrar en el cuadro N, c.pos es la que se calculó en
    // el N-1 (la que el juego lee ahora y enseñará en el N+1) y prev_pos la del N-2 (la que el juego enseña en este).
    const float lag_pos = c.prev_pos; const int lag_sel = c.prev_sel;
    c.prev_pos = c.pos; c.prev_sel = c.sel;
    img(kRingHi, 1);   // el aro dorado de la UI, subido antes de hacer falta (salía un cuadro sin aro al elegir)
    if (const char *h = w3d_fe_highlighted()) {
        if (strcmp(h, c.last_hl)) {
            snprintf(c.last_hl, sizeof c.last_hl, "%s", h);
            bool found = false;
            for (int i = 0; i < n; i++) if (items[i].name && !strcmp(items[i].name, h)) {
                // Por el camino corto: el carrusel da la vuelta.
                float d = fmodf((float)i - c.pos, (float)n); if (d > n / 2.f) d -= n; if (d < -n / 2.f) d += n;
                c.sel = i; c.pos = (float)i - d; found = true;   // la misma posición, contada desde el elegido
            }
            // Al entrar en el menú el juego puede resaltar algo que no está en el carrusel (en Opciones, su botón oculto
            // Team Options): vale lo elegido aquí y su resaltado vuelve a donde toca. Solo al entrar: después, los otros
            // botones de la página (los de esquemas de Opciones) se resaltan ellos mismos antes de su A.
            if (!found && c.fresh) {
                if (items[c.sel].name) w3d_fe_highlight(items[c.sel].name);
                else if (park && strcmp(h, park)) w3d_fe_highlight(park);
            }
            c.fresh = false;
        }
    }
    const Input &in = input();
    int picked = -1;
    auto select = [&](int i) {
        i = ((i % n) + n) % n; c.sel = i;
        if (items[i].name) w3d_fe_highlight(items[i].name); else if (park) w3d_fe_highlight(park);
    };
    if (key_down(UI_K_LEFT)) select(c.sel - 1);
    if (key_down(UI_K_RIGHT)) select(c.sel + 1);
    if (key_down(UI_K_A)) {
        picked = c.sel;
        if (items[c.sel].name) activate(items[c.sel].name);
        else if (special_pick) *special_pick = true;
    }
    // Las flechas tienen su propio toque (abajo): ahí no empieza un arrastre del carrusel.
    const bool on_arrow = in.ty >= 140 && in.ty < 190 && (in.tx < 74 || in.tx >= 246);
    if (touch_down() && in.ty >= 40 && in.ty < 190 && !on_arrow) { c.drag = true; c.moved = false; c.x0 = (float)in.tx; c.pos0 = c.pos; }
    if (c.drag && in.touch) {
        float dx = in.tx - c.x0;
        if (fabsf(dx) > 8) c.moved = true;
        if (c.moved) c.pos = c.pos0 - dx / 96.f;
    }
    if (c.drag && !in.touch) {
        c.drag = false;
        if (c.moved) select((int)floorf(c.pos + 0.5f));
        else {
            // Un toque: en el del centro lo pulsa; en uno de los lados lo trae al centro.
            float d = (c.x0 - 160.f) / 96.f;
            int k = (int)floorf(d + 0.5f);
            if (k == 0 && fabsf(c.x0 - 160) < 60) {
                picked = c.sel;
                if (items[c.sel].name) activate(items[c.sel].name);
                else if (special_pick) *special_pick = true;
            } else if (k) select(c.sel + (k > 0 ? 1 : -1));
        }
    }
    if (!c.drag) {
        float target = (float)c.sel;
        float d = fmodf(target - c.pos, (float)n); if (d > n / 2.f) d -= n; if (d < -n / 2.f) d += n;
        // El 22 % de lo que falta por cuadro a 30 FPS, contado por tiempo: un cuadro largo avanza lo que le toca.
        const double tn = now();
        float dt = c.last_t > 0 ? (float)(tn - c.last_t) : 1.f / 30;
        if (dt < 1.f / 120) dt = 1.f / 120; if (dt > 0.1f) dt = 0.1f;
        c.pos += d * (1.f - expf(-7.4538f * dt));
        if (fabsf(d) < 0.002f) c.pos = target;
    }
    c.last_t = now();
    // Lo que dibuja la UI en este cuadro: si el juego dibuja sus botones, lo mismo que se ve en ellos; si todo lo dibuja
    // la UI, lo nuevo.
    const bool lagged = w3d_fe_native_layout() != 0;
    const float draw_pos = lagged ? lag_pos : c.pos;
    const int draw_sel = lagged ? lag_sel : c.sel;
    { static const bool log = getenv("W3D_CAROUSEL_LOG") != nullptr; static float last = -99;   // pruebas: la posición, cuadro a cuadro
      if (log && c.pos != last) { last = c.pos; uib_log("[carrusel] ui pos %.4f sel %d\n", c.pos, c.sel); } }
    backdrop();
    title(menu_title);
    // Del más lejano al centro, para que el del centro quede encima. El dorado va con la elección, como en los botones del
    // juego (su resaltado cambia al elegir, no al llegar al centro).
    const int base = (int)floorf(draw_pos + 0.5f);
    for (int ring = 2; ring >= 0; ring--)
        for (int sgn = -1; sgn <= 1; sgn += 2) {
            if (ring == 0 && sgn > 0) continue;
            int k = ring * sgn, i = ((base + k) % n + n) % n;
            float d = (float)(base + k) - draw_pos;
            carousel_slot(items[i], d, i == draw_sel, &c == &g_main);
        }
    // Flechas en los márgenes, con un pequeño vaivén.
    float wob = 2.f * sinf((float)now() * 4.f);
    arrow(kMargin + 2 - wob, 150, -1);
    arrow(320 - kMargin - 30 + wob, 150, 1);
    if (hit(0, 140, 74, 50)) select(c.sel - 1);
    if (hit(246, 140, 74, 50)) select(c.sel + 1);
    const Item &cur = items[((int)floorf(draw_pos + 0.5f) % n + n) % n];
    text_shadow(160, 174, tip_label(cur.tip, cur.label), 18, 0xffffffff, 1);
    return picked;
}

void animated_logo(float cx, float cy, float) {
    text_shadow(cx, cy, "Worms 3D", 28, 0xffffffff, 1);
}
// Lo que se oculta arriba en un menú del carrusel: sus iconos y aros, y el texto con su marco (pasan abajo).
void hide_menu_pieces(const Item *items, int n) {
    for (int i = 0; i < n; i++) if (items[i].icon) hide_top(items[i].icon);
    static const char *const kRings[] = {"Red", "Blue", "Green", "Grey", "Purple", "HiLight"};
    for (const char *r : kRings) hide_top(ring_of(r));
    hide_top("Frontend/Mechanics/Text_Border_Blue.tga");
    hide_top("Frontend/Mechanics/Title_Line.tga");
    hide_top("Frontend/Mechanics/Prev_On.tga"); hide_top("Frontend/Mechanics/Prev_Off.tga");
    hide_top("Frontend/Mechanics/back.tga"); hide_top("Frontend/Mechanics/back_highlight.tga");
}

// Todo el "cromo" de los menús del juego (marcos, botones de volver y empezar, flechas, combos, texto), para las
// pantallas cuya parte de arriba se rehace entera.
void hide_fe_chrome() {
    static const char *const k[] = {"Frontend/Mechanics/Text_Border_Blue.tga", "Frontend/Mechanics/Text_Border_Yellow.tga",
        "Frontend/Mechanics/Text_Border_Green.tga", "Frontend/Mechanics/Text_Border_Purple.tga", "Frontend/Mechanics/Text_Border_Red.tga",
        "Frontend/Mechanics/Text_border_Grey.tga", "Frontend/Mechanics/Title_Line.tga", "Frontend/Mechanics/Arrow_On.tga",
        "Frontend/Mechanics/Arrow_Off.tga", "Frontend/Mechanics/Arrow_Disabled.tga", "Frontend/Mechanics/Prev_On.tga",
        "Frontend/Mechanics/Prev_Off.tga", "Frontend/Mechanics/Prev_Disabled.tga", "Frontend/Mechanics/Game_ON.tga",
        "Frontend/Mechanics/Game_OFF.tga", "Frontend/Mechanics/Game_Disabled.tga", "Frontend/Mechanics/ComboButton.tga",
        "Frontend/Mechanics/TextBoxBack.tga", "Frontend/Mechanics/Icon_Border_Red.tga", "Frontend/Mechanics/Icon_Border_Blue.tga",
        "Frontend/Mechanics/Icon_Border_Green.tga", "Frontend/Mechanics/Icon_Border_Grey.tga", "Frontend/Mechanics/Icon_Border_Purple.tga",
        "Frontend/Mechanics/Icon_Border_HiLight.tga", "Frontend/Mechanics/Icon_Alt_Blue.tga",
        "Frontend/Mechanics/Icon_Alt_Green.tga", "Frontend/Mechanics/Icon_Alt_Grey.tga", "Frontend/Mechanics/Icon_Alt_Purple.tga",
        "Frontend/Mechanics/Icon_Alt_Red.tga", "Frontend/Mechanics/Icon_Alt_HiLight.tga", "Frontend/Mechanics/Icon_Alt_Border.tga",
        "Frontend/Mechanics/Icon_Alt2_Border.tga", "Frontend/Mechanics/Icon_Alt2_HiLight.tga", "Frontend/Mechanics/Icon_Alt3_Border.tga",
        "fuente0.w3ui", "fuente1.w3ui"};
    for (const char *n : k) hide_top(n);
}
// Panel de información de arriba (como el prototipo): icono grande en su aro, nombre y descripción.
void top_info_panel(const char *menu_title, const char *icon, const char *ring, const char *name, const char *desc) {
    begin(0);
    if (menu_title && *menu_title) title(menu_title);
    panel(img(kBorderBlue,0), 12, 40, 376, 188, 6, 0x183b78ff);
    ring_icon(icon, 90, 134, 120, true);
    text_fit(166, 58, name, 21, 206, 0xffffffff, 0);
    text_scroll(166, 88, 206, 128, desc, 15, 0xe6eeffff);
    (void)ring;
    begin(1);
}
// Consejo completo (lo de después de " - ").
const char *tip_desc(const char *key) {
    const char *t = key ? key_text(key, nullptr) : nullptr;
    if (!t) return "";
    const char *d = strstr(t, " - ");
    return d ? d + 3 : t;
}

// --- Menús con página propia ----------------------------------------------------------------------------------
// Team Creator (antes Team Setup Screen, el nombre de su consejo) sale en el menú principal y ya no en Opciones (el
// dueño, 2026-11-07). El menú principal del juego no tiene ese botón: el del carrusel es de la UI (sin nombre) y manda las
// mismas órdenes que el de Opciones (MenuTwk.xom). Crear equipo vuelve con FE.PreviousMenu, así que vuelve al menú
// principal. Mientras está elegido, el resaltado del juego se deja en su título (si no, el botón anterior seguía dorado).
const char *const kTeamSetup = "FE.CheckTeams\\FE.PopulateTable$Barracks\\FE.LoadTeam$\\FE.ChangeMenu$FE.Create Edit Team";
const int kMainCount = 5;
const Item kMainItems[kMainCount] = {
    {"QuickStart", "Frontend/Icons/Icon_Quick.tga", "FE.Tip.QuickStart", "Quick Start", "Purple"},
    {"SinglePlayer", "Frontend/Icons/Icon_Single.tga", "FE.Tip.SinglePlayerMenu", "Single Player", "Red"},
    {"Multiplayer", "Frontend/Icons/Icon_Multi.tga", "FE.Tip.MultiplayerMenu", "Multiplayer", "Blue"},
    {nullptr, "Frontend/Icons/Icon_Team_Options.tga", nullptr, "Team Creator", "Green"},
    {"Options", "Frontend/Icons/Icon_Options.tga", "FE.Tip.OptionsMenu", "Options", "Green"},
};
const Item kSingleItems[] = {
    {"Tutorial", "Frontend/Icons/Icon_Training.tga", "FE.Tip.TutorialMenu", "Tutorial", "Blue"},
    {"Campaign", "Frontend/Icons/Icon_Campaign.tga", "FE.Tip.CampaignMenu", "Campaign", "Red"},
    {"ChallengeMode", "Frontend/Icons/Icon_Challenge.tga", "FE.Tip.ChallengeMenu", "Challenge", "Purple"},
};
// El último no es del juego: abre la página Developer de abajo. (Team Options pasó al menú principal: kTeamSetup.)
const int kOptCount = 6;
const Item kOptItems[kOptCount] = {
    {"Sound Video Options", "Frontend/Icons/Icon_Sound.tga", "FE.Tip.OptionsSoundOptions", "Sound", "Green"},
    {"Wormapedia", "Frontend/Icons/Icon_Wormopaedia.tga", "FE.Tip.OptionsWormapedia", "Wormapedia", "Green"},
    {"Weapon Options", "Frontend/Icons/Icon_Options_Weapon.tga", "FE.Tip.OptionsWeaponOptions", "Weapon Options", "Green"},
    {"Game Options", "Frontend/Icons/Icon_Options_Game.tga", "FE.Tip.OptionsGameOptions", "Game Options", "Green"},
    {"Language", "icono_idiomas.w3ui", "FE.Screen.Language", "Language", "Green", true},   // redondo (tools/build3ds/ui/icono_idiomas.py)
    {nullptr, "icon_developer.w3ui", nullptr, nullptr, "Grey"},
};
bool g_developer;   // página Developer abierta (desde Opciones)
// Tras cerrar Developer con B, el juego no debe ver ese mismo B (volvería de Opciones al menú principal): se le tapa
// hasta que se suelta.
bool g_eat_b; double g_eat_b_at;
void eat_b() { g_eat_b = true; g_eat_b_at = uib_seconds(); }
char g_prev_menu[48];   // el menú anterior al actual (Idiomas solo tiene vuelta si se entró desde Opciones)

void page_main() {
    // Arriba: el mar del juego y el logo animado; los botones originales pasan abajo.
    hide_menu_pieces(kMainItems, kMainCount);
    hide_top("fuente0.w3ui"); hide_top("fuente1.w3ui");   // el texto del juego (título y consejo)
    begin(0);
    animated_logo(200, 112, 325);   // el mismo sitio y ancho que tenía la imagen fija del logo
    begin(1);
    static Item items[kMainCount];
    memcpy(items, kMainItems, sizeof items);
    { static const char *const k[5] = {"Team Creator", "Créateur d'équipe", "Team-Editor", "Crea squadra", "Creador de equipos"};
      int l = lang(); if (l < 0 || l > 4) l = 0; items[3].label = k[l]; }
    bool team = false;
    carousel(g_main, items, kMainCount, key_text("Lang.MainMenu", "Main Menu"), &team, "Title");
    if (team) w3d_fe_run(kTeamSetup);
}
void page_single() {
    hide_menu_pieces(kSingleItems, 3); hide_fe_chrome();
    const Item &cur = kSingleItems[g_single.sel % 3];
    top_info_panel(key_text("Lang.SinglePlayer", "Single Player"), cur.icon, cur.ring, tip_label(cur.tip, cur.label), tip_desc(cur.tip));
    carousel(g_single, kSingleItems, 3, key_text("Lang.SinglePlayer", "Single Player"));
    if (back_button()) press(0x200);
}
void page_developer();
void page_options() {
    if (g_developer) { page_developer(); return; }
    static Item items[kOptCount];
    memcpy(items, kOptItems, sizeof items);
    items[kOptCount - 1].label = tr(T_DEVELOPER);
    hide_menu_pieces(kOptItems, kOptCount - 1); hide_fe_chrome();
    hide_top("Frontend/Icons/Icon_GCVibON.tga"); hide_top("Frontend/Icons/Icon_GCVibOFF.tga");   // la 3DS no vibra
    hide_top("Frontend/Icons/Icon_Team_Options.tga");   // su botón sigue en el menú del juego, oculto
    hide_top("Frontend/Icons/Icon_LangSelect.tga");      // el original (la UI dibuja el redondo)
    const Item &cur = items[g_opts.sel % kOptCount];
    top_info_panel(key_text("Lang.Options", "Options"), cur.icon, cur.ring, cur.name ? tip_label(cur.tip, cur.label) : cur.label,
                   cur.name ? tip_desc(cur.tip) : tr(T_DUMP_HELP));
    bool dev = false;
    carousel(g_opts, items, kOptCount, key_text("Lang.Options", "Options"), &dev, "Team Options");   // el resaltado, en el oculto
    if (dev) { g_developer = true; return; }
    // Esquemas abajo, con sus iconos del juego: crear, borrar, guardar y cargar.
    static const struct { const char *name, *icon; } kRow[] = {
        {"Create Scheme", "Frontend/Icons/Icon_Add.tga"}, {"Delete Scheme", "Frontend/Icons/Icon_Delete.tga"},
        {"SAVE", "Frontend/Icons/Icon_Save.tga"}, {"Load Game", "Frontend/Icons/Icon_Load.tga"}};
    for (int i = 0; i < 4; i++) {
        float x = 320 - kMargin - 192 + i * 50, y = 240 - kMargin - 42;
        ring_icon(kRow[i].icon, x + 20, y + 20, 40, nav_focus());
        if (hit(x, y, 42, 42)) activate(kRow[i].name);
    }
    if (back_button()) press(0x200);
}
// SD dialogs use a different native screen from FE menus. Its original record
// supplies the text keys, choices, selection, progress and error state.
const char *card_text(const char *key) {
    const bool es=lang()==4;
    static const struct {const char *key,*es,*en;} text[]={
        {"NGC.MC.ReadyAccess","Todo listo para acceder a los datos de la tarjeta SD.","Ready to access the data on the SD card."},
        {"NGC.MC.DontTouch","Accediendo a los datos. No retires la tarjeta SD ni apagues la consola.","Accessing data. Do not remove the SD card or turn off the console."},
        {"NGC.MC.OverWrite","¿Quieres sobrescribir los datos guardados de Worms 3D?","Overwrite the saved Worms 3D data?"},
        {"NGC.MC.SaveComplete","Datos guardados correctamente.","Data saved successfully."},
        {"NGC.MC.ReadComplete","Datos cargados correctamente.","Data loaded successfully."},
        {"NGC.MC.SaveFailed","No se pudieron guardar los datos. Comprueba la tarjeta SD e inténtalo de nuevo.","Could not save the data. Check the SD card and try again."},
        {"NGC.MC.ReadFailed","No se pudieron leer los datos guardados.","Could not read the saved data."},
        {"NGC.MC.NoFile","Todavía no hay datos guardados de Worms 3D.","There is no Worms 3D save data yet."},
        {"NGC.MC.NoSpace","No hay espacio suficiente para guardar los datos en la tarjeta SD.","There is not enough space to save data on the SD card."},
        {"NGC.MC.NoCard","No se puede acceder a la tarjeta SD.","The SD card is not accessible."},
        {"NGC.MC.Damaged","No se puede leer el almacenamiento de datos guardados.","The save storage could not be read."},
        {"NGC.MC.WrongDevice","El almacenamiento seleccionado no está disponible.","The selected storage is not available."},
        {"NGC.MC.NoSupport","Los datos guardados no son compatibles con este juego.","The saved data is not compatible with this game."},
        {"NGC.MC.Corrupt","El almacenamiento de partidas contiene datos dañados.","The save storage contains damaged data."},
        {"NGC.MC.FormatFailed","No se pudo inicializar el almacenamiento de partidas.","Could not initialize the save storage."},
        {"NGC.MC.FormatSure","Se borrarán los datos del almacenamiento de partidas. ¿Quieres continuar?","The data in the save storage will be erased. Continue?"},
        {"NGC.MC.Delete","Los datos guardados están dañados. ¿Quieres borrarlos?","The saved data is damaged. Delete it?"},
        {"NGC.MC.Manage","Gestionar datos guardados","Manage save data"},
        {"NGC.MC.ManageLost","Gestionar datos (se perderán los cambios sin guardar)","Manage data (unsaved changes will be lost)"},
        {"NGC.MC.Continue","Continuar sin guardar/cargar","Continue without saving/loading"},
        {"NGC.MC.Format","Inicializar datos","Initialize data"},
        {"NGC.MC.Okay","Aceptar","OK"}, {"NGC.MC.Yes","Sí","Yes"}, {"NGC.MC.No","No","No"},
        {"NGC.MC.Retry","Reintentar","Retry"}, {"NGC.MC.Saving","Guardar","Save"}, {"NGC.MC.Loading","Cargar","Load"}
    };
    if(es || lang()==0) for(const auto &t:text) if(!strcmp(key,t.key)) return es?t.es:t.en;
    const char *value=w3d_fe_text(key);
    return value?game_text(value):key;
}
void page_card(const W3dCardUi &card) {
    set_fade(1);
    hide_top_big("Frontend/Mechanics/Text_Border_Keyboard.tga",90);
    begin(0);
    title(lang()==4?"Datos guardados":"Save data");
    panel(img(kBorderBlue,0),18,54,364,166,7,0x193d78ff);
    text_scroll(38,80,324,116,card_text(card.title),18,0xffffffff);
    begin(1);
    // This panel is opaque: a second native modal can never leak through it.
    panel(img(kBorderBlue,0),12,12,296,216,7,0x193d78ff);
    if(!card.count) {
        text_fit(160,104,tr(T_LOADING),22,264,0xffdc48ff,1);
        return;
    }
    float h=card.count>3?34:44, gap=8, y=(240-card.count*h-(card.count-1)*gap)*.5f;
    for(int i=0;i<card.count;++i) {
        const bool selected=i==card.selected;
        if(text_button(30,y+i*(h+gap),260,h,card_text(card.options[i]),selected,16) && card.ready) w3d_card_ui_choose(i);
    }
}

// --- Ropa (v29) -------------------------------------------------------------------------------------------------
// Los gorros de Worms Ultimate Mayhem que lleva puestos cada worm (core/native/hat_militar.cpp: los 76 de UM en Mac y en
// 3DS). Miniaturas en 10 columnas, la 0 sin gorro y la k el gorro k:
// - Mac: el atlas ropa_76.w3ui.mac (mods/gorra/tools/atlas_ropa.py), casillas de 128 px, con mipmaps.
// - 3DS: ropa_76_3ds.w3ui, casillas de 50 px (el tamaño de la rejilla; 1 MB de VRAM en lugar de 8) y, para la vista
//   grande de arriba, la casilla de 128 px de cada gorro en su archivo (ropa/NN.w3ui): solo está en memoria la que se
//   ve. Las dos salen de las de Mac (tools/build3ds/ui/ropa_3ds.py).
bool g_ropa;   // página Ropa abierta (desde Developer)
#if defined(__3DS__)
const char *const kRopaAtlas = "ropa_76_3ds.w3ui";
const float kRopaCell = 50;
#else
const char *const kRopaAtlas = "ropa_76.w3ui.mac";
const float kRopaCell = 128;
#endif
const char *ropa_text(int which) {   // 0 "Ropa", 1 "Elegir", 2 "Sin gorro", 3 descripción
    static const char *const k[4][5] = {
        {"Outfit", "Tenue", "Outfit", "Abito", "Ropa"},
        {"Choose", "Choisir", "Wählen", "Scegli", "Elegir"},
        {"No hat", "Sans chapeau", "Kein Hut", "Nessun cappello", "Sin gorro"},
        {"Hats from Worms Ultimate Mayhem for every worm.", "Chapeaux de Worms Ultimate Mayhem pour tous les vers.",
         "Hüte aus Worms Ultimate Mayhem für alle Würmer.", "Cappelli di Worms Ultimate Mayhem per tutti i vermi.",
         "Gorros de Worms Ultimate Mayhem para todos los worms."}};
    int l = lang(); if (l < 0 || l > 4) l = 0;
    return k[which][l];
}
const char *ropa_name(int k) {
    if (k <= 0) return ropa_text(2);
    return lang() == 4 ? w3d_hat_label(k) : w3d_hat_label_en(k);
}
// Miniatura de la casilla k del atlas (se dibuja de 40 a 128 px; en Mac con mipmaps).
bool ropa_thumb(int k, float x, float y, float s, unsigned tint = 0xffffffff) {
    if (!kRopaAtlas) return false;
#if defined(__3DS__)
    if (s > kRopaCell + 8) {   // la vista grande: la de 128 px de ese gorro (mientras se sube, la pequeña ampliada)
        char name[24]; snprintf(name, sizeof name, "ropa/%02d.w3ui", k);
        const Img *b = img(name, 0);
        if (b->tex >= 0) { sprite(b, x, y, s, s, tint); return true; }
    }
#endif
    const Img *a = img(kRopaAtlas, 8);
    if (a->failed || a->tex < 0) return false;
    sprite(a, x, y, s, s, tint, (k % 10) * kRopaCell, (k / 10) * kRopaCell, kRopaCell, kRopaCell);
    return true;
}
// Fila de Developer: el gorro puesto y el botón Elegir.
bool ropa_row(float y) {
    panel(img(kBorderBlue,0), kMargin, y, 320 - 2 * kMargin, 44, 6, 0x183b78ff);
    if (!ropa_thumb(w3d_hat_mode, kMargin + 8, y + 2, 40)) ring_icon("icon_developer.w3ui", kMargin + 28, y + 22, 34, false);
    text_shadow(kMargin + 56, y + 4, ropa_text(0), 16, 0xffffffff, 0);
    text_fit(kMargin + 56, y + 24, ropa_name(w3d_hat_mode), 12, 150, 0xd8e4ffff, 0);
    return text_button(320 - kMargin - 12 - 76, y + 5, 76, 34, ropa_text(1), false, 15);
}
float ropa_scroll, ropa_target, ropa_velocity; double ropa_last; int ropa_focus = -1;
bool ropa_drag, ropa_moved; int ropa_start_y, ropa_last_y;
// Rejilla de sombreros (la de Developer y la de Outfit de Crear equipo): 5 columnas en el panel (fx, fy, fw, fh), se
// desliza con el lápiz o se recorre con el mando (la cruceta mueve el foco, A elige). Devuelve el elegido (toque o A) o
// -1; worn es el puesto, que lleva el marco amarillo del juego.
int hat_grid(float fx, float fy, float fw, float fh, int worn) {
    const int n = w3d_hat_count() + 1;   // + «sin gorro»
    if (ropa_focus < 0 || ropa_focus >= n) ropa_focus = worn >= 0 && worn < n ? worn : 0;
    int chosen = -1;
    const int cols = 5;
    static unsigned held = 0; static double repeat = 0;
    const unsigned dir = input().held & (UI_K_LEFT | UI_K_RIGHT | UI_K_UP | UI_K_DOWN);
    const double t = now();
    bool pad_moved = false;
    if (dir && (dir != held || t >= repeat)) {
        const int step = dir & UI_K_LEFT ? -1 : dir & UI_K_RIGHT ? 1 : dir & UI_K_UP ? -cols : cols;
        ropa_focus = ((ropa_focus + step) % n + n) % n;
        repeat = t + (dir != held ? .35 : .12); pad_moved = true;
    }
    held = dir;
    if (key_down(UI_K_A)) chosen = ropa_focus;
    // Cuadrícula con desplazamiento suave, como el inventario de armas.
    const float rim = 14, pitch = 58, cell = 54;
    const float gx = fx + (fw - cols * pitch) / 2, top = fy + rim + 2, bottom = fy + fh - rim - 2, view = bottom - top;
    const float max_scroll = fmaxf(0, ((n + cols - 1) / cols) * pitch + 2 - view);
    if (pad_moved && !ropa_drag) {
        const int row = ropa_focus / cols;
        if (row * pitch < ropa_target) ropa_target = row * pitch;
        if (row * pitch + pitch > ropa_target + view) ropa_target = row * pitch + pitch - view;
        ropa_velocity = 0;
    }
    float dt = ropa_last ? fminf(.05f, (float)(t - ropa_last)) : 1.f / 60;
    ropa_last = t;
    if (touch_down() && input().ty >= top && input().ty < bottom && input().tx >= fx && input().tx < fx + fw) {
        ropa_drag = true; ropa_moved = false; ropa_velocity = 0;
        ropa_start_y = ropa_last_y = input().ty; ropa_target = ropa_scroll;
    }
    if (ropa_drag && input().touch) {
        int delta = ropa_last_y - input().ty; ropa_last_y = input().ty;
        if (abs(input().ty - ropa_start_y) > 7) ropa_moved = true;
        if (ropa_moved) { ropa_target += delta; ropa_velocity = delta / fmaxf(dt, .001f); }
    }
    if (ropa_drag && touch_up()) {
        int c = (int)floorf((input().tx - gx) / pitch), r = (int)floorf((input().ty - top + ropa_scroll) / pitch);
        if (!ropa_moved && c >= 0 && c < cols && r >= 0 && r * cols + c < n) { ropa_focus = r * cols + c; chosen = ropa_focus; }
        ropa_drag = false;
    }
    if (!ropa_drag) { ropa_target += ropa_velocity * dt; ropa_velocity *= expf(-10 * dt); }
    ropa_target = fmaxf(0, fminf(max_scroll, ropa_target));
    ropa_scroll = ropa_drag ? ropa_target : ropa_scroll + (ropa_target - ropa_scroll) * (1 - expf(-18 * dt));
    panel(img(kBorderBlue,0), fx, fy, fw, fh, rim, 0x10285aee);
    // Fondo y marco amarillo de las casillas del panel de armas, en la versión HD (smallicons_hd, fila 7, 64 px).
    const Img *cells = img("smallicons_hd.w3ui", 0);
    clip(fx + rim, top, fw - 2 * rim, view);
    for (int i = 0; i < n; i++) {
        const float x = gx + (i % cols) * pitch + (pitch - cell) / 2, y = top + 1 + (i / cols) * pitch - ropa_scroll;
        if (y + cell <= top || y >= bottom) continue;
        sprite(cells, x, y, cell, cell, 0xffffffff, i == worn ? 384 : 0, 448, 64, 64);
        if (!ropa_thumb(i, x + 2, y + 2, cell - 4)) text_fit(x + cell / 2, y + cell / 2 - 6, ropa_name(i), 10, cell - 6, 0xffffffff, 1);
        // El elegido con el mando, con el borde blanco que late (el puesto ya lleva el amarillo).
        if (i == ropa_focus && nav_active()) {
            const float a = 0.55f + 0.45f * sinf((float)t * 6.f);
            const unsigned c = 0xffffff00 | (unsigned)(a * 255.f);
            rect(x - 2, y - 2, cell + 4, 2, c); rect(x - 2, y + cell, cell + 4, 2, c);
            rect(x - 2, y, 2, cell, c); rect(x + cell, y, 2, cell, c);
        }
    }
    clip_off();
    return chosen;
}
// Página Ropa de Developer: arriba, el gorro elegido en grande con su nombre; abajo, la cuadrícula de todos. Tocar una
// casilla o pulsar A lo pone a todos los worms que no tengan uno de su equipo (Outfit de Crear equipo).
void page_ropa() {
    const int n = w3d_hat_count() + 1;
    if (ropa_focus < 0 || ropa_focus >= n) ropa_focus = w3d_hat_mode >= 0 && w3d_hat_mode < n ? w3d_hat_mode : 0;
    // Arriba.
    begin(0);
    title(ropa_text(0));
    panel(img(kBorderBlue,0), 12, 40, 376, 188, 6, 0x183b78ff);
    if (!ropa_thumb(ropa_focus, 26, 70, 128)) ring_icon("icon_developer.w3ui", 90, 134, 120, true);
    text_fit(166, 58, ropa_name(ropa_focus), 21, 206, 0xffffffff, 0);
    { static char d[200]; snprintf(d, sizeof d, "%d / %d\n%s", ropa_focus, n - 1, ropa_text(3));
      text_scroll(166, 88, 206, 128, d, 15, 0xe6eeffff); }
    begin(1);
    backdrop(0.15f);
    const int k = hat_grid(4, 4, 312, 192, w3d_hat_mode);
    if (k >= 0) w3d_hat_mode = k;
    if (back_button() || key_down(UI_K_B)) { g_ropa = false; eat_b(); }
}
// Developer: Overlay (L+R+SELECT abre la consola de siempre; START+SELECT lanza la prueba desde la v29) y Dump (SELECT guarda un volcado completo).
void page_developer() {
    // Arriba, como las demás opciones: el menú original se oculta y va el panel de información de Developer.
    hide_menu_pieces(kOptItems, kOptCount - 1); hide_fe_chrome();
    hide_top("Frontend/Icons/Icon_GCVibON.tga"); hide_top("Frontend/Icons/Icon_GCVibOFF.tga"); hide_top("Frontend/Icons/Icon_Team_Options.tga");
    hide_top("Frontend/Icons/Icon_LangSelect.tga");
    hide_top("Frontend/Icons/Icon_Add.tga"); hide_top("Frontend/Icons/Icon_Delete.tga"); hide_top("Frontend/Icons/Icon_Save.tga"); hide_top("Frontend/Icons/Icon_Load.tga");
    if (g_ropa) { page_ropa(); return; }
    { static char d[300]; snprintf(d, sizeof d, "%s\n%s", tr(T_DUMP_HELP), tr(T_OVERLAY_HELP));
      top_info_panel(key_text("Lang.Options", "Options"), "icon_developer.w3ui", "Grey", tr(T_DEVELOPER), d); }
    backdrop(0.15f);
    title(tr(T_DEVELOPER));
    // v39: una sola fila, «Botones de depuración»: SELECT (volcado), R+SELECT (consola) y START+SELECT (prueba). Apagada,
    // ninguna de las tres hace nada. (Antes había dos: Overlay y Dump.)
    {
        const float y = 40;
        panel(img(kBorderBlue,0), kMargin, y, 320 - 2 * kMargin, 70, 6, 0x183b78ff);
        // Icono propio en el estilo del juego (docs/ui-3ds/arte-hd/PROCEDENCIA.md).
        ring_icon("icon_dump.w3ui", kMargin + 28, y + 35, 40, false);
        text_shadow(kMargin + 56, y + 5, tr(T_DUMP), 16, 0xffffffff, 0);
        text_box(kMargin + 56, y + 25, 152, tr(T_DUMP_HELP), 11, 0xd8e4ffff, 0, 3);
        const bool on = uib_dev_get(1) != 0;
        // On/Off lo dice el texto; el dorado es solo la selección con el mando, como en los demás botones.
        if (text_button(320 - kMargin - 12 - 76, y + 18, 76, 34, tr(on ? T_ON : T_OFF), false, 15)) uib_dev_set(1, !on);
    }
    if (ropa_row(118)) { g_ropa = true; return; }
    if (back_button() || key_down(UI_K_B)) { g_developer = false; g_ropa = false; eat_b(); }
}
// Idiomas (variante A del prototipo): carrusel con las banderas del juego; arriba, la bandera y el nombre. Tocar la del
// centro pulsa su botón.
Carousel g_lang;
const Item kLangItems[] = {
    {"English", "Frontend/Icons/Flag_UK.tga", nullptr, "English", "Green"}, {"French", "Frontend/Icons/Flag_France.tga", nullptr, "Français", "Green"},
    {"German", "Frontend/Icons/Flag_German.tga", nullptr, "Deutsch", "Green"}, {"Italian", "Frontend/Icons/Flag_Italy.tga", nullptr, "Italiano", "Green"},
    {"Spanish", "Frontend/Icons/Flag_Spain.tga", nullptr, "Español", "Green"}};
void page_language() {
    hide_menu_pieces(kLangItems, 5); hide_fe_chrome();
    const Item &cur = kLangItems[g_lang.sel % 5];
    const char *t = key_text("Lang.Language", "Language");
    top_info_panel(t, cur.icon, cur.ring, cur.label, tip_desc("FE.Screen.Language"));
    carousel(g_lang, kLangItems, 5, t);
    // El menú de idiomas del juego no tiene botón de volver (al arrancar hay que elegir). Entrado desde Opciones, B o
    // Back vuelven como en los demás menús, con la orden del propio FE.
    if (!strcmp(g_prev_menu, "FE.Options")) {
        if (back_button() || key_down(UI_K_B)) { w3d_fe_run("FE.PreviousMenu"); eat_b(); }
    }
}

// Native popup borders are separate scenes from their controls. Remove that
// window only, leaving the original animated world behind the modal intact.
void modal_top(const char *heading,const char *message) {
    set_fade(1);
    hide_top_big("Frontend/Mechanics/Text_Border_Keyboard.tga",90);
    hide_top_big(kBorderBlue,90);
    begin(0);
    title(heading);
    panel(img(kBorderBlue,0),18,54,364,166,7,0x193d78ff);
    text_scroll(38,80,324,116,message,18,0xffffffff);
    begin(1);
}
// Confirmation keeps the native actions and controller navigation.
void page_confirm(const char *popup) {
    if(w3d_fe_native_layout() && w3d_fe_game_mode()!=7) {
        const bool discard=!strcmp(popup,"FE.LeaveOptions") || !strcmp(popup,"FE.LeaveMultiplayer");
        const char *question=discard?key_text("FE.Discard",tr(T_ARE_YOU_SURE)):
            !strcmp(popup,"FE.QuitConfirmPopUp")?key_text("FE.Tip.QuitConfirm",tr(T_ARE_YOU_SURE)):key_text("FE.Tip.Sure",tr(T_ARE_YOU_SURE));
        modal_top(lang()==4?"Confirmar":"Confirm",question);
        if(touch_down()) if(const char *item=w3d_fe_native_hit(popup,input().tx,input().ty)) activate(item);
        return;
    }
    if (key_down(UI_K_B)) activate("Cancel");
    backdrop(0.45f);
    const bool discard = !strcmp(popup, "FE.LeaveOptions") || !strcmp(popup, "FE.LeaveMultiplayer");
    const char *q = discard ? key_text("FE.Discard", tr(T_ARE_YOU_SURE)) : !strcmp(popup, "FE.QuitConfirmPopUp") ? key_text("FE.Tip.QuitConfirm", tr(T_ARE_YOU_SURE)) : key_text("FE.Tip.Sure", tr(T_ARE_YOU_SURE));
    panel(img(kBorderBlue,0),24,30,272,176,8,0x203c78dd);
    text_box(44, discard ? 50 : 64, 232, q, discard ? 14 : 20, 0xffffffff, 1, 4);
    const char *h = w3d_fe_highlighted();
    const bool yes_hi = h && !strcmp(h, "Accept");
    const char *labels[2] = {key_text("FE.Tip.No", tr(T_NO)), key_text("FE.Tip.Yes", tr(T_YES))};
    for (int i = 0; i < 2; i++) {
        float x = i ? 188 : 64, y = 112, w = 68, h2 = 68;
        bool hi = nav_active() ? nav_focus() : i ? yes_hi : !yes_hi;
        const float pulse=hi?1.f+.025f*sinf(now()*6):1.f;
        const float d=w*pulse;
        sprite(img(hi?kRingHi:"Frontend/Mechanics/Icon_Border_Blue.tga",0),
               x+(w-d)/2,y+(h2-d)/2,d,d);
        text_shadow(x + w / 2, y + h2 / 2 - 11, labels[i], 22, 0xffffffff, 1);
        if (hit(x, y, w, h2)) activate(i ? "Accept" : "Cancel");
    }
}
// Pausa: las mismas órdenes que las filas de FE.PauseMenu (estudio del HUD, §4).
enum { kPContinue, kPQuit, kPDraw };
void page_pause(bool can_draw) {
    if (key_down(UI_K_B) || key_down(UI_K_START)) {
        if(key_down(UI_K_B)) eat_b();
        w3d_fe_run("FE.KillPopUp\\App.Resume");
    }
    backdrop(0.35f);
    title(tr(T_PAUSE));
    const char *labels[3] = {tr(T_CONTINUE), tr(T_QUIT), tr(T_DRAW)};
    int n = can_draw ? 3 : 2;
    for (int i = 0; i < n; i++) {
        float y = 50 + i * 56;
        // Gold: the row chosen with the pad; Continue until the pad moves.
        if (text_button(50, y, 220, 46, labels[i], !nav_active() && i == 0, 18)) {
            if (i == kPContinue) w3d_fe_run("FE.KillPopUp\\App.Resume");
            else if (i == kPQuit) w3d_fe_run("FE.KillPopUp\\FE.CreatePopUp$FE.InGameQuitConfirm");
            else w3d_fe_run("FE.KillPopUp\\FE.CreatePopUp$FE.InGameDrawConfirm");
        }
    }
}
// Original briefing text and scene, with the text box fitted to the touch screen.
void page_brief() {
    begin(1); set_fade(1); backdrop();
    const char *raw=w3d_fe_prop_str("Game.BriefingText");
    const char *resolved=raw?w3d_fe_text(raw):nullptr;
    text_scroll(28,26,264,146,game_text(resolved?resolved:raw),16,0xffffffff);
    if(text_button(40,182,240,34,tr(T_CONTINUE),true,17) || key_down(UI_K_A))
        w3d_fe_run("FE.KillPopUp\\Game.BriefingDialogOkPressed");
}
// Six native columns, four visible rows. Keep the original weapon actions,
// availability, yellow highlight and pad neighbours; scroll the layout only.
float weapon_scroll=0,weapon_target=0,weapon_velocity=0;
bool weapon_drag=false,weapon_moved=false;
int weapon_start_y=0,weapon_last_y=0;
double weapon_last_time=0;
char weapon_highlight[64];
extern "C" int w3d_ui_weapon_layout(const char *,float *,float *,float *) {return -1;}
// v39: returns false while the game has not filled its cells yet (the first frames after the panel opens); the caller
// keeps drawing the match panel then. It used to draw nothing: one or two black frames each time the panel opened.
bool page_inventory() {
    // Every cell of the game's panel at its own place (6 columns, 9 rows, by row as in the original); empty cells keep
    // their background, unavailable weapons are dimmed.
    int slots[54],icons[54],locked[54],count=54,weapons=0;
    for(int i=0;i<54;++i) {
        int lock=0,icon=w3d_fe_weapon_cell(i,&lock);
        slots[i]=i; icons[i]=icon>=0 && icon<64?icon:-1; locked[i]=lock; weapons+=icons[i]>=0;
    }
    if(!weapons) return false;
    const char *selected=w3d_fe_highlighted();
    int col=0,row=0,selection=0;
    if(selected && sscanf(selected,"WeaponPanel-%d,%d",&col,&row)==2)
        for(int i=0;i<count;++i) if(slots[i]==row*6+col) selection=i;
    auto choose=[&](int i,bool accept) {
        i=(i%count+count)%count;
        if(icons[i]<0) return;
        char item[40];snprintf(item,sizeof item,"WeaponPanel-%02d,%02d",slots[i]%6,slots[i]/6);
        if(accept && !locked[i]) activate(item); else w3d_fe_highlight(item);
        selection=i;
    };
    static unsigned held=0;static double repeat=0;
    unsigned direction=input().held&(UI_K_LEFT|UI_K_RIGHT|UI_K_UP|UI_K_DOWN);
    double t=now();
    if(direction && (direction!=held || t>=repeat)) {
        // Step over empty cells in that direction.
        const int step=direction&UI_K_LEFT?-1:direction&UI_K_RIGHT?1:direction&UI_K_UP?-6:6;
        int k=selection;
        for(int n=0;n<54;++n) { k=((k+step)%count+count)%count; if(icons[k]>=0) break; }
        choose(k,false);
        repeat=t+(direction!=held?.35:.12);
    }
    held=direction;
    if(key_down(UI_K_A)) choose(selection,true);
    // Like the game's own panel (FE.WeaponPanel): a thick-rimmed frame and its cells packed edge to edge, 6 columns,
    // the chosen one with the yellow frame. Here it fills the
    // lower screen with bigger cells and HD icons, and scrolls; the tool tip and the count go to the upper screen.
    const float fx=4,fy=4,fw=312,fh=232,rim=17,pitch=46,cell=44;
    const float gx=fx+(fw-6*pitch)/2, top=fy+rim+2, bottom=fy+fh-rim-2, view=bottom-top;
    float max_scroll=fmaxf(0,((count+5)/6)*pitch+2-view);
    if(selected && strcmp(selected,weapon_highlight)) {
        snprintf(weapon_highlight,sizeof weapon_highlight,"%s",selected);
        row=selection/6;
        if(!weapon_drag) {
            if(row*pitch<weapon_target) weapon_target=row*pitch;
            if(row*pitch+pitch>weapon_target+view) weapon_target=row*pitch+pitch-view;
            weapon_velocity=0;
        }
    }
    float dt=weapon_last_time?fminf(.05f,t-weapon_last_time):1.f/60;
    weapon_last_time=t;
    if(touch_down() && input().ty>=top && input().ty<bottom) {
        weapon_drag=true;weapon_moved=false;weapon_velocity=0;
        weapon_start_y=weapon_last_y=input().ty;weapon_target=weapon_scroll;
    }
    if(weapon_drag && input().touch) {
        int delta=weapon_last_y-input().ty;weapon_last_y=input().ty;
        if(abs(input().ty-weapon_start_y)>7) weapon_moved=true;
        if(weapon_moved) {weapon_target+=delta;weapon_velocity=delta/fmaxf(dt,.001f);}
    }
    if(weapon_drag && touch_up()) {
        int c=(int)floorf((input().tx-gx)/pitch),r=(int)floorf((input().ty-top+weapon_scroll)/pitch);
        if(!weapon_moved && c>=0 && c<6 && r>=0 && r*6+c<count && icons[r*6+c]>=0) choose(r*6+c,true);
        weapon_drag=false;
    }
    if(!weapon_drag) {weapon_target+=weapon_velocity*dt;weapon_velocity*=expf(-10*dt);}
    weapon_target=fmaxf(0,fminf(max_scroll,weapon_target));
    weapon_scroll=weapon_drag?weapon_target:weapon_scroll+(weapon_target-weapon_scroll)*(1-expf(-18*dt));
    const Img *atlas=img("weapons_hd.w3ui",0);
    const Img *original=img("HUD/smallicons.tga",0);
    backdrop();   // v39: el azul del panel de la partida detrás del marco (antes, negro en las esquinas)
    panel(img(kBorderBlue,0),fx,fy,fw,fh,rim,0x10285aee);
    clip(fx+rim,top,fw-2*rim,view);
    float sel_x=-1,sel_y=0;
    for(int i=0;i<count;++i) {
        const float x=gx+(i%6)*pitch+(pitch-cell)/2, y=top+1+(i/6)*pitch-weapon_scroll;
        if(y+cell<=top || y>=bottom) continue;
        // The chosen cell's yellow frame replaces its background, under the icon, so the weapon stays clearly visible.
        sprite(original,x,y,cell,cell,0xffffffff,i==selection?192:0,224,32,32);
        if(i==selection) { sel_x=x; sel_y=y; }
        const float m=cell*.06f;
        // One texel inside the atlas cell, so the neighbour above never bleeds in.
        if(icons[i]>=0) sprite(atlas,x+m,y+m,cell-2*m,cell-2*m,locked[i]?0x999999aa:0xffffffff,(icons[i]%8)*64+1,(icons[i]/8)*64+1,62,62);
    }
    (void)sel_x; (void)sel_y;   // the original's pointer is left out (owner): the yellow frame marks the choice
    clip_off();
    if(key_down(UI_K_B)) w3d_fe_run("Input.ClosePanelPressed");
    begin(0);
    const char *tip=w3d_fe_prop_str("FE.ToolTip");
    text_shadow(12,214,tip && *tip?game_text(tip):tr(T_WEAPONS),16,0xffffffff,0);
    text_shadow(388,214,key_text("FE.WeaponCount",""),16,0xffdb47ff,2);
    begin(1);
    return true;
}
// The team health bars are the game's own HUD, routed to the top of this screen (gx_metal.mm, position_battle_ui);
// only the number of teams is needed here, for the indicators' layout.
void page_health(const W3dHud &h) {
    int count=0;
    for(const auto &t:h.teams) if(t.used) ++count;
    hud_team_rows=count;
}
// Battle controls surround the four larger native indicators. The backdrop is
// original interface artwork, independent of the upper gameplay camera.
void page_match(const W3dHud &h) {
    if(w3d_fe_native_layout()) {
        if(!w3d_ui_panel_active()) {
            const Img *bg=img(kBackdrop,2);
            map_tex=bg->tex;map_u=bg->w?(float)bg->w/bg->pw:1;map_v=bg->h?(float)bg->h/bg->ph:1;
        } else { img_drop(kBackdrop);map_tex=-1; }
        // Dispatch the same original action as the game's Start binding. If
        // the engine already opened its popup, pages_frame visits page_pause.
        if(key_down(UI_K_START)) w3d_fe_run("App.Pause");
        const bool inventory=w3d_fe_prop_uint("WeaponPanel.Open",0)!=0;
        // v40: las texturas del panel de armas, subidas antes de abrirlo (el primer cuadro salía sin marco ni casillas).
        img("weapons_hd.w3ui",1); img("HUD/smallicons.tga",0); img(kBorderBlue,0);   // el formato del HUD (hud_panel.cpp)
        // v42: y las de la pausa (fuente de la UI, botones, línea del título). Con el panel, las armas y las dos hojas
        // de la veleta, la fuente se liberaba en la partida y la primera pausa salía un cuadro vacía.
        font_keep(); img(kPill,0); img(kPillHi,0); img(kTitleLine,0);
        if(key_down(UI_K_X)) w3d_fe_run(inventory?"Input.ClosePanelPressed":"Input.OpenPanelPressed");
        if(inventory && page_inventory()) return;
        weapon_last_time=0;weapon_drag=false;weapon_velocity=0;
        // v39: mientras suben las texturas del panel, su azul; el HUD original solo si el panel no se puede cargar.
        if(!hud_panel(h)) { if(w3d_ui_panel_active()) rect(0,0,320,240,0x0b2a50ff); else page_health(h); }
        if(hit(w3d_ui_panel_active()?8:220,w3d_ui_panel_active()?148:58,w3d_ui_panel_active()?68:90,w3d_ui_panel_active()?86:85)) w3d_fe_run("Input.OpenPanelPressed");
        return;
    }
    backdrop(0.2f);
    static const char *const kBars[6] = {"HUD/TeamHealth_Red.tga", "HUD/TeamHealth_Blue.tga", "HUD/TeamHealth_Green.tga",
                                         "HUD/TeamHealth_Yellow.tga", "HUD/TeamHealth_Cyan.tga", "HUD/TeamHealth_pink.tga"};
    int maxv = 1;
    for (const W3dHudTeam &t : h.teams) if (t.used && t.total > maxv) maxv = t.total;
    float y = 12;
    for (int g = 0; g < 4; g++) {
        const W3dHudTeam &t = h.teams[g];
        if (!t.used) continue;
        const Img *bar = img(kBars[(unsigned)t.colour % 6], 1);
        rect(14, y, 200, 18, 0x00000080);
        float w = 196.f * (float)t.total / (float)(maxv > 0 ? maxv : 1);
        if (w > 0) sprite(bar, 16, y + 2, w, 14);
        char n[16]; snprintf(n, sizeof n, "%d", t.total);
        text_shadow(220, y + 1, n, 15, g == h.active_team ? 0xffe060ff : 0xffffffff, 0);
        y += 24;
    }
    // Reloj de turno (grande) y de ronda, como TimerBack.
    const Img *tb = img("HUD/TimerBack.tga", 1);
    sprite(tb, 254, 8, 60, 60);
    char s[16];
    int turn = (h.clock_mode == 1 ? h.hotseat_ms : h.turn_ms) / 1000;
    snprintf(s, sizeof s, "%d", turn < 0 ? 0 : turn);
    text_shadow(284, 26, s, 22, h.clock_mode == 2 && turn <= 5 ? 0xff5050ff : 0xffffffff, 1);
    int r = h.round_ms / 1000;
    snprintf(s, sizeof s, "%d:%02d", r / 60, r % 60);
    text_shadow(284, 70, s, 13, 0xd8e4ffff, 1);
    // Viento: el fondo del indicador del juego y una barra hacia el lado del viento con el número del juego.
    const Img *wb = img("HUD/Wind_Backing01.tga", 1);
    sprite(wb, 14, 112, 160, 32);
    float k = h.wind_max > 0 ? h.wind_speed / h.wind_max : 0; if (k > 1) k = 1;
    float dir = cosf(h.wind_dir) >= 0 ? 1.f : -1.f;
    rect(94, 122, dir * 70.f * k, 12, 0x60c0ffd0);
    snprintf(s, sizeof s, "%d", (int)(k * 10 + 0.5f));
    text_shadow(184, 118, s, 17, 0xffffffff, 0);
    // Botones: armas (X) y pausa (START).
    if (text_button(14, 166, 150, 56, tr(T_WEAPONS), true, 18)) w3d_fe_run("Input.OpenPanelPressed");
    if (text_button(176, 166, 130, 56, tr(T_PAUSE), false, 18)) press(0x1000, 3);
}
// Cualquier otro menú: cruceta, A y B táctiles con el nombre del elemento resaltado.
bool keyboard_page(const char *);
void page_generic(const char *menu) {
    if(w3d_fe_native_layout() && menu && !strcmp(menu,"FE.NewScheme"))
        hide_top_big("Frontend/Mechanics/Text_Border_Keyboard.tga",90);
    // Un teclado del juego abierto (nombre de esquema, de equipo...): sus teclas se tocan abajo.
    if (w3d_fe_native_layout() && keyboard_page(nullptr)) return;
    // These popups keep their original lower controls, with one clear upper
    // explanation instead of an empty native window over the previous menu.
    if (w3d_fe_native_layout() && w3d_fe_popup_depth() > 0) {
        if(!strcmp(menu,"FE.NewScheme")) modal_top(lang()==4?"Nuevo esquema":"New scheme",
            lang()==4?"Toca el nombre para escribirlo. Acepta para crear el esquema con los ajustes actuales.":"Tap the name to edit it. Accept to create a scheme with the current settings.");
        else if(!strcmp(menu,"FE.PopUnlocked")) modal_top(lang()==4?"Desbloqueables":"Unlockables",
            lang()==4?"Completa los entrenamientos, las misiones y los desafíos para desbloquear más contenido.":"Complete tutorials, missions and challenges to unlock more content.");
        begin(1);
        if(touch_down()) if(const char *item=w3d_fe_native_hit(menu,input().tx,input().ty)) activate(item);
        return;
    }
    char t[48];
    const char *m = menu && !strncmp(menu, "FE.", 3) ? menu + 3 : menu ? menu : "";
    // "GameSettings" -> "Game Settings"
    int n = 0; for (const char *p = m; *p && n < 44; p++) { if (n && *p >= 'A' && *p <= 'Z' && p[-1] >= 'a' && p[-1] <= 'z') t[n++] = ' '; t[n++] = *p; } t[n] = 0;
    if(w3d_fe_native_layout()) {
        if(!strncmp(menu,"FE.PostTutorial",15) || !strncmp(menu,"FE.PostCampaign",15) || !strncmp(menu,"FE.PostChallenge",16)) {
            begin(1);
            const char *tip=key_text("FE.ToolTip","");
            text_scroll(24,28,272,126,tip,18,0xffffffff);
            if(touch_down()) if(const char *item=w3d_fe_native_hit(menu,input().tx,input().ty)) activate(item);
            return;
        }
        if(!strcmp(menu,"FE.Wormpot")) {
            begin(1);
            for(int reel=0;reel<3;++reel) {
                float x=24+reel*64;
                for(int dir=0;dir<2;++dir) {
                    float y=65+dir*66;
                    sprite(img(kRingGreen,0),x,y,42,42);
                    sprite_rot(img(kArrow,0),x+21,y+21,25,28,dir?-1.5708f:1.5708f);
                    if(hit(x,y,42,42)) w3d_fe_wormpot_action(2+reel*3+dir);
                }
            }
            ring_icon("Frontend/Icons/Icon_WormPot.tga",267,116,58,false);
            if(hit(232,78,70,80)) w3d_fe_wormpot_action(10);

            if(touch_down()) if(const char *item=w3d_fe_native_hit(menu,input().tx,input().ty)) activate(item);
            return;
        }
        if(!strcmp(menu,"FE.Wormapedia")) {
            begin(1);   // el título del juego ya va arriba (fe_layout.cpp): abajo no se repite
            const char *article=w3d_fe_prop_str("Ped.Title");
            if(article) text_fit(160,44,game_text(article),19,285,0xffffffff,1);
            if(touch_down()) if(const char *item=w3d_fe_native_hit(menu,input().tx,input().ty)) activate(item);
            return;
        }
        if(!strcmp(menu,"FE.WeaponOptions")) {
            begin(0);   // título: el del juego, que fe_layout.cpp sube arriba
            const char *tip=w3d_fe_prop_str("FE.ToolTip");
            weapon_preview();
            text_fit(200,208,tip&&*tip?game_text(tip):tr(T_WEAPONS),20,350,0xffffffff,1);
            begin(1);
            if(touch_down()) if(const char *item=w3d_fe_native_hit(menu,input().tx,input().ty)) activate(item);
            return;
        }
        // Arriba, el título del juego (fe_layout.cpp lo sube; abajo ya no va) y la ayuda del elemento resaltado.
        begin(0);
        panel(img(kBorderBlue,0),18,56,364,156,7,0x193d78ff);
        const char *tip=key_text("FE.ToolTip", "");
        // Internal item IDs ("Dud Mines", "SAVE"...) are not user-facing titles.
        // Read once: heading and body must describe the same selection this frame.
        const char *split=strstr(tip," - ");
        if (!split) split=strstr(tip,": ");
        if (split && split-tip < 64) {
            char heading[64]; memcpy(heading,tip,split-tip); heading[split-tip]=0;
            text_fit(36,74,heading,22,328,0xffdc48ff,0);
            text_scroll(36,110,328,86,split+(split[0]==':'?2:3),16,0xffffffff);
        } else text_scroll(36,78,328,116,tip,17,0xffffffff);
        begin(1);
        if(touch_down()) if(const char *item=w3d_fe_native_hit(menu,input().tx,input().ty)) activate(item);
        return;
    }
    backdrop(); title(t);
    if (back_button()) press(0x200);
    if (start_button(tr(T_ACCEPT))) press(0x100);
}

void page_sound() {
    const bool es=lang()==4;
    begin(0); title(key_text("Lang.SoundOptions","Sound Options"));
    begin(1);
    const char *props[]={"Audio.Vol.Music","Audio.Vol.Sfx","Audio.Vol.Ambient"};
    const char *names[]={"Toggle Music","Toggle sfx","Environment"};
    const char *labels[]={tr(T_MUSIC),tr(T_SFX),es?"Ambiente":"Ambience"};
    static int dragging=-1;
    if(!input().touch) dragging=-1;
    for(int i=0;i<3;++i) {
        float y=16+i*49, v=w3d_fe_prop_float(props[i],1); v=fmaxf(0,fminf(1,v));
        const bool selected=nav_focus();
        text_shadow(18,y,labels[i],15,selected?0xffdc48ff:0xffffffff,0);
        char pct[12]; snprintf(pct,sizeof pct,"%d%%",(int)(v*100+.5f));
        text_shadow(302,y,pct,14,0xffdc48ff,2);
        native_button(18,y+22,284,14,false);
        rect(27,y+26,266*v,6,0xffce35ff);
        sprite(img(kRingHi,0),18+266*v,y+19,18,20);
        int action=hit_row(14,y,292,43);
        if(tap(14,y+17,292,27)) dragging=i;
        bool changed=false;
        if(dragging==i) {v=fmaxf(0,fminf(1,(input().tx-27)/266.f));changed=true;}
        else if(action==1 || action==-1) {v=fmaxf(0,fminf(1,v+action*.05f));changed=true;}
        if(changed) {w3d_fe_set_float(props[i],v);w3d_fe_highlight(names[i]);}
    }
    const char *modes[]={"Mono",es?"Estéreo":"Stereo",es?"Envolvente":"Surround"};
    unsigned mode=w3d_fe_prop_uint("SAVE.SoundMode",1)%3;
    if(text_button(60,171,200,28,modes[mode],false,15)) activate("Sound");
    if(back_button()) activate("Cancel");
}

// Tutorial, Campaña y Desafíos (FE.TutorialMenu, FE.CampaignMenu, FE.Challenge Menu): sus datos son propiedades del
// FE (MCa.Title, MCa.Desc, MCa.Level, MCa.Team) y sus botones se llaman Previous, Next, Start, Back y Create Team; el
// equipo es el combo Barracks.
// Arriba (prototipo "misiones"): la miniatura original, el nombre, el objetivo y el equipo. Abajo: misión con flechas,
// equipo, crear equipo, volver y empezar.
const char *level_image(const char *lvl) {
    static char b[96];
    if (!lvl || !*lvl) return nullptr;
    // MCa.Level es el archivo de la miniatura ("Tutorial_ATF.tga"), en Frontend/Levels.
    snprintf(b, sizeof b, "Frontend/Levels/%s", lvl);
    return b;
}
// Fila con una etiqueta pequeña y un valor, y flechas a los lados. Devuelve -1/+1 si se toca una flecha, 2 el centro.
// Geometría común: flechas en los márgenes, la fila entre ellas.
const float kRowX = kMargin + 28 + 6, kRowW = 320 - 2 * kRowX, kRowH = 44;
// Con el mando la fila entera es un solo destino: arriba/abajo la eligen e izquierda/derecha hacen lo de sus flechas.
// Una flecha sin a dónde ir sale apagada (Arrow_Disabled, como en el juego) y no hace nada.
void arrow_disabled(float x, float y, int dir, float w = 28, float h = 32) {
    const Img *a = img("Frontend/Mechanics/Arrow_Disabled.tga", 0);
    if (a->tex < 0) return;
    const float u1 = (float)a->w / a->pw, v1 = (float)a->h / a->ph;
    if (dir < 0) quad(a->tex, x, y, x + w, y + h, 0, 0, u1, v1, 0xffffffff);
    else quad(a->tex, x, y, x + w, y + h, u1, 0, 0, v1, 0xffffffff);
}
int value_row(float y, const char *label, const char *value, const char *icon, bool can_prev = true, bool can_next = true) {
    const float ay = y + (kRowH - 32) / 2;
    if (can_prev) arrow(kMargin, ay, -1); else arrow_disabled(kMargin, ay, -1);
    if (can_next) arrow(320 - kMargin - 28, ay, 1); else arrow_disabled(320 - kMargin - 28, ay, 1);
    native_button(kRowX,y,kRowW,kRowH,nav_focus(0));
    float x = kRowX + 12;
    if (icon) { sprite_fit(img(icon, 1), kRowX + 8, y + 6, 32, 32); x = kRowX + 46; }
    text_shadow(x, y + 5, label, 11, 0xbcd0ffff, 0);
    text_fit(x, y + 19, value, 16, kRowX + kRowW - 10 - x, 0xffffffff, 0);
    int r = hit_row(kRowX, y, kRowW, kRowH);
    if (tap(0, y, kRowX, kRowH)) r = -1;
    if (tap(kRowX + kRowW, y, 320 - kRowX - kRowW, kRowH)) r = 1;
    if ((r == -1 && !can_prev) || (r == 1 && !can_next)) r = 0;
    return r;
}
// Elegir otro equipo en el combo Barracks como lo haría el jugador: A lo abre, la cruceta baja o sube, A lo cierra.
void barracks_step(const char *current, int dir) {
    if (pressing()) return;
    char rows[16][64];
    int n = w3d_fe_table("FE.Barracks", rows, 16);
    if (n <= 1) return;
    int cur = 0;
    for (int i = 0; i < n; i++) if (current && !strcmp(rows[i], current)) cur = i;
    const int target = (cur + dir + n) % n, delta = target - cur;
    activate("Barracks");
    for (int i = 0; i < (delta < 0 ? -delta : delta); i++) press(delta > 0 ? 0x4 : 0x8, 3);
    press(0x100, 6);
}
void page_mission(const char *menu) {
    const bool tut = !strcmp(menu, "FE.TutorialMenu"), camp = !strcmp(menu, "FE.CampaignMenu");
    const char *mtitle = tut ? key_text("Lang.Tutorial", "Tutorial") : camp ? key_text("Lang.Campaign", "Campaign") : key_text("Lang.Challenge", "Challenge");
    // Medal rows also convert text; keep these outside game_text's ring buffer.
    char name[256],desc[1400],team[128];
    snprintf(name,sizeof name,"%s",game_text(w3d_fe_prop_str("MCa.Title")));
    snprintf(desc,sizeof desc,"%s",game_text(w3d_fe_prop_str("MCa.Desc")));
    snprintf(team,sizeof team,"%s",game_text(w3d_fe_prop_str("MCa.Team")));
    const char *lvl_raw = w3d_fe_prop_str("MCa.Level");
    { static char last[64]; if (lvl_raw && strcmp(last, lvl_raw)) { snprintf(last, sizeof last, "%s", lvl_raw); uib_log("[ui] MCa.Level = %s\n", lvl_raw); } }
    const char *lvl = tut || camp ? level_image(lvl_raw) : nullptr;
    hide_fe_chrome();
    hide_top("Frontend/Icons/Icon_Add.tga"); hide_top("Frontend/Icons/Icon_Wormopaedia2.tga"); hide_top("Frontend/Icons/Icon_Padlock.tga");
    if (lvl) hide_top(lvl);
    // Arriba.
    // Panel con 14 px de aire por dentro. La miniatura (256x256) solo tiene dibujo en (3,12)-(253,244), ya con su borde
    // negro redondeado: se usa ese trozo sin deformar y el marco dorado propio la rodea con el mismo radio.
    begin(0);
    title(mtitle);
    const float px = 12, py = 40, pw = 376, ph = 188, pad = 14;
    panel(img(kBorderBlue,0), px, py, pw, ph, 6, 0x183b78ff);
    const float tw = 136, th = tw * 232.f / 250.f, tx = px + pad + 2, ty = py + pad + 2;
    if (lvl) {
        sprite(img(lvl, 1), tx, ty, tw, th, 0xffffffff, 3, 12, 250, 232);
        nine(img(kFrameGold, 0), tx - 4, ty - 4, tw + 8, th + 8, 14);
    } else if(!tut && !camp) {
        // Challenges have a medal table, not a level thumbnail. FE.TempMission
        // is a native placeholder resource, never a filename in Frontend/Levels.
        const char *names[]={"MCa.GoldName","MCa.SilverName","MCa.BronzeName"};
        const char *times[]={"MCa.GoldTime","MCa.SilverTime","MCa.BronzeTime"};
        const char *labels[2][3]={{"Gold","Silver","Bronze"},{"Oro","Plata","Bronce"}};
        const unsigned colors[]={0xffdc48ff,0xd8e4ffff,0xe6aa70ff};
        panel(img(kBorderBlue,0),tx,ty,tw,th,6,0x102e60ff);
        for(int i=0;i<3;++i) {
            const float y=ty+8+i*39;
            const char *record=w3d_fe_prop_str(names[i]), *time=w3d_fe_prop_str(times[i]);
            text_shadow(tx+8,y,labels[lang()==4][i],13,colors[i],0);
            text_fit(tx+tw-8,y,time&&*time?game_text(time):"--:--",13,64,0xffffffff,2);
            text_fit(tx+8,y+17,record&&*record?game_text(record):"—",11,tw-16,0xd8e4ffff,0);
        }
    }
    text_fit(tx + tw / 2, ty + th + 10, team, 15, tw + 8, 0xffe060ff, 1);
    // Columna de la derecha: el nombre (hasta dos líneas) y debajo la descripción, que baja sola si no cabe.
    const float cx = tx + tw + pad + 4, cw = px + pw - pad - cx;
    float nh = text_box_height(cw, name, 19, 2);
    text_box(cx, ty, cw, name, 19, 0xffffffff, 0, 2);
    const float dy = ty + nh + 6;
    text_scroll(cx, dy, cw, py + ph - pad - dy, desc, 15, 0xe6eeffff);
    // Abajo.
    begin(1);
    backdrop();
    title(mtitle);
    static const TextId kNone = T_COUNT; (void)kNone;
    // MCa.Previous / MCa.Next: hay otra misión desbloqueada antes o después (con una partida nueva, ninguna).
    const bool can_prev = w3d_fe_prop_int("MCa.Previous", 0) != 0, can_next = w3d_fe_prop_int("MCa.Next", 0) != 0;
    int r = value_row(42, lang()==4?(tut?"Entrenamiento":"Misión"):(tut?"Tutorial":"Mission"), name, "Frontend/Icons/Icon_Campaign.tga", can_prev, can_next);
    if (r == -1 && !pressing()) activate("Previous");
    if (r == 1 && !pressing()) activate("Next");
    char teams[16][64]; const bool many = w3d_fe_table("FE.Barracks", teams, 16) > 1;
    const char *team_raw = w3d_fe_prop_str("MCa.Team");
    int t = value_row(94, lang()==4?"Equipo":"Team", team, "Frontend/Icons/Icon_Team_Options.tga", many, many);
    if (t == -1 || t == 1) barracks_step(team_raw, t);
    // Crear equipo, con su icono del juego: del mismo ancho que las filas.
    if(tut) {
        if(text_button(kRowX,146,kRowW,38,lang()==4?"Crear equipo":"Create Team",false,15,"Frontend/Icons/Icon_Add.tga")) activate("Create Team");
    } else {
        if(text_button(kRowX,146,(kRowW-8)/2,38,lang()==4?"Crear equipo":"Create Team",false,13)) activate("Create Team");
        if(text_button(kRowX+(kRowW+8)/2,146,(kRowW-8)/2,38,lang()==4?"Desbloqueables":"Unlockables",false,12)) activate("Medal Cabinet");
    }
    if (back_button()) activate("Back");
    // v42: también con START (en la prueba, START no empezaba el tutorial: solo el toque o A con el foco en Start).
    if (start_button(lang()==4?"Empezar":"Start") || (key_down(UI_K_START) && !pressing())) activate("Start");
}

// --- Estados de los botones del juego (MultiStateButtonDesc) -------------------------------------------------
// Imagen del juego -> archivo (Bundles/Bundle01.xom), solo las que usan las páginas.
const char *fe_icon(const char *res) {
    static const char *const k[][2] = {
        {"FE.B.WH.100", "Icon_WormHealth100"}, {"FE.B.WH.150", "Icon_WormHealth150"}, {"FE.B.WH.200", "Icon_WormHealth200"},
        {"FE.B.TT.15", "Icon_TurnTime15"}, {"FE.B.TT.20", "Icon_TurnTime20"}, {"FE.B.TT.30", "Icon_TurnTime30"}, {"FE.B.TT.45", "Icon_TurnTime45"},
        {"FE.B.TT.60", "Icon_TurnTime60"}, {"FE.B.TT.90", "Icon_TurnTime90"},
        {"FE.B.RT.0", "Icon_RoundTime00"}, {"FE.B.RT.5", "Icon_RoundTime05"}, {"FE.B.RT.10", "Icon_RoundTime10"}, {"FE.B.RT.15", "Icon_RoundTime15"},
        {"FE.B.RT.20", "Icon_RoundTime20"}, {"FE.B.RT.25", "Icon_RoundTime25"}, {"FE.B.RT.30", "Icon_RoundTime30"},
        {"FE.B.Vic.1", "Icon_Victorys01"}, {"FE.B.Vic.2", "Icon_Victorys02"}, {"FE.B.Vic.3", "Icon_Victorys03"}, {"FE.B.Vic.5", "Icon_Victorys05"},
        {"FE.B.Vic.7", "Icon_Victorys07"}, {"FE.B.Vic.9", "Icon_Victorys09"},
        {"FE.B.WS.Off", "Icon_WormSelectOn"}, {"FE.B.WS.On", "Icon_WormSelectOff"},
        {"FE.B.TelIn.Off", "Icon_PositioningOff"}, {"FE.B.TelIn.On", "Icon_PositioningOn"},
        {"FE.B.CPU.No", "Icon_Human"}, {"FE.B.CPU.1", "Icon_CPU01"}, {"FE.B.CPU.2", "Icon_CPU02"}, {"FE.B.CPU.3", "Icon_CPU03"},
        {"FE.B.CPU.4", "Icon_CPU04"}, {"FE.B.CPU.5", "Icon_CPU05"},
    };
    static char b[4][64]; static int r; char *o = b[r = (r + 1) & 3];
    for (auto &e : k) if (!strcmp(e[0], res)) { snprintf(o, 64, "Frontend/Icons/%s.tga", e[1]); return o; }
    return "Frontend/Icons/Icon_Options_Game.tga";
}
// Un ajuste del esquema con sus estados ("imagen:valor:consejo,..." del menú del juego), su propiedad y la orden que
// el control ejecuta tras cambiarla. Tocarlo pasa al estado siguiente (el dueño: nada de ventanas para elegir).
struct Setting { const char *prop, *states, *cmd; };
const Setting kHealth = {"Q.WHealth", "FE.B.WH.100:100:FE.Tip.Health,FE.B.WH.150:150:FE.Tip.Health,FE.B.WH.200:200:FE.Tip.Health", "FE.UpdateScheme$Health"};
const Setting kTurn = {"Q.TTime", "FE.B.TT.15:15000:FE.Tip.TT15,FE.B.TT.20:20000:FE.Tip.TT20,FE.B.TT.30:30000:FE.Tip.TT30,FE.B.TT.45:45000:FE.Tip.TT45,FE.B.TT.60:60000:FE.Tip.TT60,FE.B.TT.90:90000:FE.Tip.TT90", "FE.UpdateScheme$TurnTime"};
const Setting kRound = {"Q.RTime", "FE.B.RT.0:0:FE.Tip.RT0,FE.B.RT.5:300000:FE.Tip.RT5,FE.B.RT.10:600000:FE.Tip.RT10,FE.B.RT.15:900000:FE.Tip.RT15,FE.B.RT.20:1200000:FE.Tip.RT20,FE.B.RT.25:1500000:FE.Tip.RT25,FE.B.RT.30:1800000:FE.Tip.RT30", "FE.UpdateScheme$RoundTime"};
const Setting kWins = {"Q.Wins", "FE.B.Vic.1:1:FE.Tip.Victory1,FE.B.Vic.2:2:FE.Tip.Victory2,FE.B.Vic.3:3:FE.Tip.Victory3,FE.B.Vic.5:5:FE.Tip.Victory5,FE.B.Vic.7:7:FE.Tip.Victory7,FE.B.Vic.9:9:FE.Tip.Victory9", "FE.UpdateScheme$Wins"};
const Setting kWormSel = {"Q.WSel", "FE.B.WS.On:0:FE.Tip.WormSelectOff,FE.B.WS.Off:1:FE.Tip.WormSelectOn", "FE.UpdateScheme$WormSelect"};
const Setting kTeleport = {"Q.TelIn", "FE.B.TelIn.Off:0:FE.Tip.TeleportInOff,FE.B.TelIn.On:1:FE.Tip.TeleportInOn", "FE.UpdateScheme$TeleportIn"};
struct StateInfo { char img[32]; int value; char tip[40]; };
int parse_states(const char *s, StateInfo *out, int max) {
    int n = 0;
    while (*s && n < max) {
        const char *e = strchr(s, ','); size_t len = e ? (size_t)(e - s) : strlen(s);
        char part[96]; if (len >= sizeof part) len = sizeof part - 1; memcpy(part, s, len); part[len] = 0;
        char *a = strchr(part, ':'); char *b = a ? strchr(a + 1, ':') : nullptr;
        if (a && b) { *a = 0; *b = 0; snprintf(out[n].img, 32, "%s", part); out[n].value = atoi(a + 1); snprintf(out[n].tip, 40, "%s", b + 1); n++; }
        s = e ? e + 1 : s + len;
    }
    return n;
}
int setting_index(const Setting &st, StateInfo *states, int *n) {
    *n = parse_states(st.states, states, 12);
    const int v = w3d_fe_prop_int(st.prop, states[0].value);
    for (int i = 0; i < *n; i++) if (states[i].value == v) return i;
    return 0;
}
const char *setting_icon(const Setting &st) { StateInfo s[12]; int n; int i = setting_index(st, s, &n); return fe_icon(s[i].img); }
const char *setting_tip(const Setting &st) { StateInfo s[12]; int n; int i = setting_index(st, s, &n); return tip_desc(s[i].tip); }
// Icono en su aro; al tocarlo pasa al estado siguiente. Devuelve true si cambió.
bool setting_button(const Setting &st, float cx, float cy, float d) {
    StateInfo s[12]; int n; int i = setting_index(st, s, &n);
    ring_icon(fe_icon(s[i].img), cx, cy, d, nav_focus());
    if (hit(cx - d / 2, cy - d / 2, d, d) && n > 0) {
        const int k = (i + 1) % n;
        w3d_fe_set_int(st.prop, s[k].value);
        w3d_fe_run(st.cmd);
        w3d_fe_run("FE.CompareScheme$Q.Changed");
        return true;
    }
    return false;
}
void hide_icons(const char *const *names, int n) { char b[80]; for (int i = 0; i < n; i++) { snprintf(b, sizeof b, "Frontend/Icons/%s.tga", names[i]); hide_top(b); } }
void hide_setting_icons() {
    static const char *const k[] = {"Icon_WormHealth100", "Icon_WormHealth150", "Icon_WormHealth200", "Icon_TurnTime15", "Icon_TurnTime20", "Icon_TurnTime30",
        "Icon_TurnTime45", "Icon_TurnTime60", "Icon_TurnTime90", "Icon_RoundTime00", "Icon_RoundTime05", "Icon_RoundTime10", "Icon_RoundTime15",
        "Icon_RoundTime20", "Icon_RoundTime25", "Icon_RoundTime30", "Icon_Victorys01", "Icon_Victorys02", "Icon_Victorys03", "Icon_Victorys05",
        "Icon_Victorys07", "Icon_Victorys09", "Icon_WormSelectOn", "Icon_WormSelectOff", "Icon_PositioningOff", "Icon_PositioningOn", "Icon_Human",
        "Icon_CPU01", "Icon_CPU02", "Icon_CPU03", "Icon_CPU04", "Icon_CPU05", "Icon_WormPot", "Icon_Options_Game", "Icon_Options_Weapon", "Icon_Add",
        "Icon_LandscapeMenu", "Icon_Team_Options", "Icon_DeleteTeam"};
    hide_icons(k, (int)(sizeof k / sizeof k[0]));
}
const char *team_icon(const char *team) {
    static char b[4][64]; static int r; char *o = b[r = (r + 1) & 3];
    const int sk = w3d_fe_team_skill(team);
    if (sk > 0 && sk <= 5) snprintf(o, 64, "Frontend/Icons/Icon_CPU0%d.tga", sk); else snprintf(o, 64, "Frontend/Icons/Icon_Human.tga");
    return o;
}

// --- Multijugador (FE.MultiplayerMenu) --------------------------------------------------------------------------
// The game's own controls, placed by core/native/fe_layout.cpp: game settings, preview and help above; the Teams panel
// (Barracks with its scroll bar and "+", Team Roster), Landscape, Wormpot, rules, weapons, Back and Start below. Only
// the button names are drawn here. The stylus works through the presses a player would make, so navigation, selection,
// scrolling and every action stay the game's own.
// Native lists: A enters the list, the cross moves its orange selection (the list scrolls itself), A runs the row's
// command (Barracks: FE.AddLTeamToGame$@; Team Roster: FE.SelectTeam$@ and FE.PopTeamAdjust).
struct ListShape { const char *name, *table; int rows; float first, pitch, left, right, bar; };
// Rows measured on the native rendering, in original FE units from the control's centre (y up): first row top,
// row pitch, text columns and the right edge of the scroll bar (0: no bar).
const ListShape kLists[] = {
    {"Barracks", "FE.Barracks", 3, 31.2f, 22.9f, -84.4f, 77.3f, 94.4f},
    {"Team Roster", "FE.TeamsInLocalGame", 4, 54.9f, 29.5f, -118.f, 114.4f, 0},
};
struct ListGoal { const ListShape *list = nullptr; int target = 0; bool accept = false; double since = 0; };
ListGoal g_list_goal;
struct ListState { int entered, selected; float top, x, y, k; };
bool list_state(const char *menu, const ListShape &l, ListState &s) {
    return w3d_fe_native_list(menu, l.name, &s.entered, &s.selected, &s.top, &s.x, &s.y, &s.k) != 0;
}
// The list and its visible row (or scroll-bar half: -1 up, -2 down) under a lower-screen point.
const ListShape *list_at(const char *menu, float tx, float ty, int *row, ListState &s) {
    for (const ListShape &l : kLists) {
        if (!list_state(menu, l, s)) continue;
        const float u = (tx - s.x) / s.k, r = (l.first - (s.y - ty) / s.k) / l.pitch;
        if (u < l.left || u > (l.bar > 0 ? l.bar : l.right) || r < 0 || r >= l.rows) continue;
        *row = l.bar > 0 && u > l.right ? (r < l.rows / 2.f ? -1 : -2) : (int)r;
        return &l;
    }
    return nullptr;
}
void list_goal(const ListShape *l, int target, bool accept) {
    static char rows[16][64];
    const int n = w3d_fe_table(l->table, rows, 16);
    if (n <= 0 || (accept && (target < 0 || target >= n))) return;
    g_list_goal.list = l; g_list_goal.target = target < 0 ? 0 : target >= n ? n - 1 : target;
    g_list_goal.accept = accept; g_list_goal.since = now();
}
void list_step(const char *menu) {
    ListGoal &g = g_list_goal;
    ListState s;
    if (!g.list) return;
    if (now() - g.since > 3 || !list_state(menu, *g.list, s)) { g.list = nullptr; return; }
    if (pressing()) return;
    if (!s.entered) { activate(g.list->name); return; }   // highlight the list, then A: the player's way in
    if (s.selected < g.target) { press(0x4); return; }     // cross down
    if (s.selected > g.target) { press(0x8); return; }     // cross up
    if (g.accept) press(0x100);
    g.list = nullptr;
}
void multi_touch() {
    static const ListShape *drag_list; static int drag_row, drag_from; static float drag_y; static bool dragged;
    const char *menu = "FE.MultiplayerMenu";
    const Input &in = input();
    ListState s;
    if (touch_down()) {
        drag_list = list_at(menu, (float)in.tx, (float)in.ty, &drag_row, s);
        dragged = false; drag_y = (float)in.ty; drag_from = drag_list ? s.selected : 0;
        if (drag_list) return;
        if (const char *item = w3d_fe_native_hit(menu, (float)in.tx, (float)in.ty)) { activate(item); return; }
        // v42 (el dueño, con la v41: «en el menú multijugador no me dejaba darle start con la pantalla táctil»): Start y
        // Back también por su nombre, que la UI escribe junto al icono (page_multi): antes solo contaba el icono del juego
        // (42 px), y tocar la palabra no hacía nada. Solo si el control del juego se puede tocar en ese momento (Start
        // está apagado hasta que hay dos equipos, como en el original).
        if (in.ty >= 192) {
            const bool right = in.tx >= 222, left = in.tx < 110;
            if (right || left) if (const char *item = w3d_fe_native_hit(menu, right ? 291.f : 29.f, 216.f)) activate(item);
        }
        return;
    }
    if (!drag_list) return;
    if (in.touch) {
        // Dragging scrolls the list the way the cross does: finger up, later rows.
        if (!list_state(menu, *drag_list, s)) { drag_list = nullptr; return; }
        const int rows = (int)lroundf((drag_y - (float)in.ty) / (drag_list->pitch * s.k));
        if (rows) dragged = true;
        if (dragged && drag_row >= 0) list_goal(drag_list, drag_from + rows, false);
        return;
    }
    if (touch_up()) {
        if (!dragged && list_state(menu, *drag_list, s)) {
            const int first = (int)lroundf(s.top);
            if (drag_row == -1) list_goal(drag_list, first - 1, false);
            else if (drag_row == -2) list_goal(drag_list, first + drag_list->rows, false);
            else {
                // Tocar un equipo hace directamente lo que hace su fila con A (sin entrar en la lista ni moverla, que
                // con el lápiz se veía como un desplazamiento raro): Barracks lo añade a la partida, Team Roster abre su
                // ajuste. Mismas órdenes que la lista del juego, con el nombre del equipo en lugar de @.
                static char rows[24][64];
                const int n = w3d_fe_table(drag_list->table, rows, 24), r = first + drag_row;
                if (r >= 0 && r < n) {
                    char cmd[200];
                    if (!strcmp(drag_list->name, "Barracks")) snprintf(cmd, sizeof cmd, "FE.AddLTeamToGame$%s\\FE.CheckGameStart$LocalGame\\FE.PopulateTable$Barracks\\FE.PopulateTable$TeamsInLocalGame", rows[r]);
                    else snprintf(cmd, sizeof cmd, "FE.SelectTeam$%s\\FE.CreatePopUp$FE.PopTeamAdjust", rows[r]);
                    w3d_fe_run(cmd);
                }
            }
        }
        drag_list = nullptr;
    }
}
void page_multi() {
    // Names under the four ring buttons and beside Back/Start, in the game's font (fe_layout.cpp places the
    // buttons at these centres: rings 44 px at (213|279, 62|132), Back and Start 42 px at (29|291, 216)).
    static const struct { float x, y; TextId label; } kLabels[] = {
        {213, 86, T_LANDSCAPE}, {279, 86, T_WORMPOT}, {213, 156, T_RULES}, {279, 156, T_WEAPONS}};
    for (const auto &l : kLabels) text_shadow(l.x, l.y, tr(l.label), 11, 0xffffffff, 1);
    text_shadow(54, 209, tr(T_BACK), 13, 0xffffffff, 0);
    text_shadow(266, 209, tr(T_START), 13, 0xffffffff, 2);
    multi_touch();
    list_step("FE.MultiplayerMenu");
    // El mando solo recorre lo de arriba (fe_layout.cpp corta los enlaces hacia abajo): al entrar, el foco va al
    // esquema; si estaba abajo (lo eligió el lápiz), la cruceta lo devuelve arriba.
    static double last_seen, entered;
    if (now() - last_seen > 0.5) entered = now();
    last_seen = now();
    const char *h = w3d_fe_highlighted();
    const bool below = h && w3d_fe_place_screen("FE.MultiplayerMenu", h) == 1;
    const bool cross = key_down(UI_K_UP) || key_down(UI_K_DOWN) || key_down(UI_K_LEFT) || key_down(UI_K_RIGHT);
    if (below && !pressing() && (now() - entered < 0.6 || cross)) w3d_fe_highlight("Scheme");
}
// Land Select (FE.LandSelect), con los controles del juego colocados por fe_layout.cpp: arriba la vista previa 3D del
// mapa; abajo todo se toca. Los dos desplegables (lista de paisajes y tema) pasan al valor siguiente con un toque, sin
// abrir ventana (como hace el jugador: A los abre, cruceta abajo, A).
// Fondos bajo los controles del juego en la pantalla de abajo (modo de menús): la página los pide en cada cuadro y el
// backend (gx_metal.mm) los dibuja en la imagen del juego antes que los controles del FE, al cuadro siguiente.
struct Underlay { int tex; float u1, v1, x, y, w, h; int screen; };
Underlay g_underlays[4]; int g_underlay_count;
Underlay g_last_under[4], g_out_under[4]; int g_last_count, g_out_count; double g_out_since = -1;
double g_page_since;   // cuándo empezó la página en curso (pages_frame)
float g_page_fade = 1;  // el fundido de entrada de la página en curso (pages_frame), para las partes que llevan el suyo
// Escala de entrada de los controles del juego al abrir un menú (fe_layout.cpp, transition): espera 0,1 s y crece en
// 0,28 s con un rebote del 8 %. Los fondos y las imágenes de la página la siguen para entrar con ellos.
float pop_since(double since) {
    const float t = (float)((now() - since - 0.1) / 0.28);
    if (t <= 0) return 0;
    if (t >= 1) return 1;
    const float c = 1.4f, u = t - 1;
    return 1 + (c + 1) * u * u * u + c * u * u;
}
float page_pop() { return pop_since(g_page_since); }
// Fundido de entrada de una parte de la página que cambia sola (Outfit dentro de Crear equipo): como el de las páginas.
float fade_since(double since) { const float t = (float)((now() - since - 0.1) / 0.15); return t < 0 ? 0 : t > 1 ? 1 : t; }
void menu_underlay(int screen, const Img *i, float x, float y, float w, float h, float scale = 1) {
    if (!i || i->tex < 0 || g_underlay_count >= 4 || scale <= 0) return;
    const float cx = x + w / 2, cy = y + h / 2; w *= scale; h *= scale;
    g_underlays[g_underlay_count++] = {i->tex, (float)i->w / i->pw, (float)i->h / i->ph, cx - w / 2, cy - h / 2, w, h, screen};
}
// Triángulos 3D bajo los controles del juego (tris_under, el worm de Crear equipo): se guardan para el cuadro siguiente,
// como los fondos (gx_metal.mm; en 3DS gx_pica.cpp, menu_underlay), o en 3DS van a la capa de la UI si no hay lienzo alto.
struct TriRun { int tex, screen; size_t first; int count; };
std::vector<float> g_tri_v; std::vector<unsigned> g_tri_c; std::vector<TriRun> g_tri_runs;
// Miniaturas de Frontend/Levels: la que el juego enseña al elegir un mapa predefinido se oculta y en su lugar va su
// versión ancha (docs/ui-3ds/arte-hd/niveles_anchos, de Codex), que llena el marco.
const char *const kLevelPics[] = {
    "Challenge_JP1", "Challenge_JP3", "Challenge_SG3", "Challenge_SS3", "Level_PNMI", "Mission_ACI", "Mission_ACU",
    "Mission_AJS", "Mission_AQF", "Mission_BB", "Mission_BBB", "Mission_Balloon", "Mission_Beanstalk", "Mission_Breakfast",
    "Mission_CB", "Mission_CC", "Mission_CDD", "Mission_DD", "Mission_EYC", "Mission_FFY", "Mission_GD", "Mission_GNS",
    "Mission_HLS", "Mission_HP", "Mission_HS", "Mission_HUR", "Mission_HelterSkelter", "Mission_ISNCHYC", "Mission_Ice",
    "Mission_LVP", "Mission_MM", "Mission_NRFF", "Mission_OSS", "Mission_PH", "Mission_RD", "Mission_RR", "Mission_SFS",
    "Mission_SMT", "Mission_SOCR", "Mission_Schools", "Mission_TBG", "Mission_TC", "Mission_TD", "Mission_TMC",
    "Mission_TreeVillage", "Mission_WAC", "Tutorial_ATF", "Tutorial_CA", "Tutorial_DITD", "Tutorial_DR", "Tutorial_TMK",
    "Tutorial_TT"};
// Land Select (FE.LandSelect), según el segundo boceto del dueño: los controles del juego los coloca fe_layout.cpp;
// aquí van los fondos (marco de la vista previa arriba, panel de los anillos y bandeja abajo, todos de Codex y debajo
// de los controles), la imagen ancha del mapa predefinido, y los toques. Todo entra con el rebote de los controles.
extern "C" { float w3d_kb_scale(void); int w3d_kb_open(void); const char *w3d_kb_text(int *cursor); void w3d_kb_action(int ch); void w3d_kb_forget(void); int w3d_kb_selected(void); void w3d_kb_clear(void); int w3d_kb_empty(void); }
// Teclado del juego (código del paisaje): es el del juego, con su ventana, su difuminado y sus teclas; sus letras van
// en orden QWERTY (textos_es.cpp) y fe_bridge.cpp baja la ventana a la pantalla de abajo y deja el texto en el centro de
// la de arriba. Aquí solo los toques: cada tecla bajo el lápiz se pulsa como la pulsa el jugador.
// Geometría (d43l_keyboard_layout_build_802c2dc4), en unidades del FE desde el centro de la ventana, que está en el
// centro de la pantalla de abajo: teclas de 40 en filas de 10 desde (-180, 125 - t/2 - 26); espacio y borrar en la
// cuarta fila; abajo (y = -125 + t/2 + 32) mayúsculas -140, cursor -30 y 30, aceptar 140. t: borde de la ventana.
// g_kb_result: cómo se cerró el último teclado (1 aceptado, 2 cancelado); lo usa la ventana de equipo nuevo.
int g_kb_result;
bool keyboard_page(const char *) {
    if (!w3d_kb_open()) return false;
    if (key_down(UI_K_START)) { w3d_kb_action(-134); g_kb_result = 1; g_kb_start_at = uib_seconds(); }
    // Con el mando el juego cierra su teclado él solo (B cancela; A sobre el visto acepta): la UI lo olvida a la vez.
    // (Con el texto vacío, A sobre aceptar no le llega al juego: fe_bridge.cpp recupera el texto y acepta él, y olvida.)
    if (key_down(UI_K_B) || (key_down(UI_K_A) && w3d_kb_selected() == 34)) {
        g_kb_result = key_down(UI_K_B) ? 2 : 1;
        if (key_down(UI_K_B) || !w3d_kb_empty()) w3d_kb_forget();
        return true;
    }
    if (!touch_down() || pressing()) return true;
    // v42: la ventana va escalada (w3d_kb_scale, fe_bridge.cpp) alrededor del centro de la pantalla de abajo.
    const float ks = w3d_kb_scale(), t = 10, fx = (input().tx - 160) / (.475f * ks), fy = (120 - input().ty) / (.475f * ks);
    const float row0 = 125 - t / 2 - 26, bottom = -125 + t / 2 + 32;
    int key = -1;
    for (int i = 0; i < 30 && key < 0; i++) {
        const float kx = -180 + 40 * (i % 10), ky = row0 - 40 * (i / 10);
        if (fabsf(fx - kx) <= 20 && fabsf(fy - ky) <= 20) key = i;
    }
    const float r3 = row0 - 120;
    if (key < 0 && fabsf(fy - r3) <= 20) key = fx < 120 ? 30 : 31;           // espacio | borrar
    if (key < 0 && fabsf(fy - bottom) <= 30) {
        if (fx < -95) key = 33; else if (fx < 0) key = 32; else if (fx < 85) key = 35; else key = 34;
    }
    if (key >= 0) w3d_kb_action(-100 - key);
    if (key == 34) g_kb_result = 1;
    return true;
}
void page_land() {
    const char *menu = "FE.LandSelect";
    if (keyboard_page(key_text("Lang.LandSelect", "Landscape Selection"))) return;
    const float pop = page_pop();
    // Marco de la vista previa: 364x188 bajo el título; el mapa 3D del juego va dentro.
    const float fx = 18, fy = 40, fw = 364, fh = 188;
    menu_underlay(0, img("marco_preview.w3ui", 8), fx, fy, fw, fh, pop);
    menu_underlay(1, img("panel_anillos2.w3ui", 8), 10, 53, 300, 120, pop);
    // Sin bandeja detrás del código, el dado, el sol y el cubo (el dueño la quitó): van sobre el fondo del menú.
    // Mapa predefinido: qué miniatura usa el juego (se oculta arriba) y su versión ancha, con fundido al cambiar.
    static int cur = -1, prev = -1; static double cur_at;
    int seen = -1;
    char path[64];
    for (int i = 0; i < (int)(sizeof kLevelPics / sizeof *kLevelPics); i++) {
        snprintf(path, sizeof path, "Frontend/Levels/%s.tga", kLevelPics[i]);
        hide_top_force(path);
        if (seen < 0 && top_drawn(path)) seen = i;
    }
    if (seen != cur) { prev = cur; cur = seen; cur_at = now(); }
    const float mix = (float)((now() - cur_at) / 0.2); 
    begin(0);
    auto picture = [&](int k, float a) {
        if (k < 0 || a <= 0) return;
        snprintf(path, sizeof path, "nivel_%s.w3ui", kLevelPics[k]);
        const Img *im = img(path, 8);
        // Dentro del contorno del marco (3 px); las esquinas ya vienen redondeadas en la imagen.
        const float w = (fw - 6) * pop, h = (fh - 6) * pop, x = fx + fw / 2 - w / 2, y = fy + fh / 2 - h / 2;
        sprite(im, x, y, w, h, 0xffffff00u | (unsigned)(255.f * (a > 1 ? 1 : a)));
    };
    if (mix < 1) picture(prev, 1 - mix);
    picture(cur, mix);
    begin(1);
    // (El recuadro del código ya trae su marco: lo perdía porque la cámara del FE lo descartaba fuera de la pantalla de
    // arriba, d32e_frustum_test_sphere_801a9cbc; el borde que se le dibujaba aquí ya no hace falta.)
    // Desplegables (lista de paisajes y tema): un toque los abre y se quedan abiertos; tocar una fila la elige (como el
    // jugador: la cruceta sube al principio de la lista, baja hasta esa fila y A) y tocar fuera los cierra (B).
    // Filas de la lista abierta, medidas en el juego: 17,6 px desde y = 44, bajo su caja.
    static const struct { const char *name, *table; int extra; float x0, x1; } kCombos[] = {
        {"User Landscapes", "FE.MultiLevels", 1, 8, 112}, {"Types", "FE.LandscapeTypes", 0, 166, 304}};
    if (!touch_down() || pressing()) return;
    const float tx = (float)input().tx, ty = (float)input().ty;
    for (const auto &cb : kCombos) {
        int entered = 0, sel; float top, x, y, k;
        if (!w3d_fe_native_list(menu, cb.name, &entered, &sel, &top, &x, &y, &k) || !entered) continue;
        char rows[24][64]; const int n = w3d_fe_table(cb.table, rows, 24) + cb.extra;
        const int r = (int)floorf((ty - 44) / 17.6f);
        if (tx >= cb.x0 && tx < cb.x1 && ty >= 44 && r < n) {
            for (int i = 0; i < n; i++) press(0x8, 3);
            for (int i = 0; i < r; i++) press(0x4, 3);
            press(0x100, 6);
        } else press(0x200, 6);
        return;
    }
    const char *item = w3d_fe_native_hit(menu, tx, ty);
    if (!item) return;
    activate(item);

}

// --- Crear o editar equipo (FE.Create Edit Team), pedido del dueño (2026-11-07) ----------------------------------------
// Arriba: el título del juego (fe_layout.cpp lo sube), el worm del juego en 3D a la izquierda, centrado en vertical, con
// el sombrero del equipo (gusano3d.cpp), y a la derecha el equipo: su nombre y sus seis worms. Abajo: los controles del
// juego (fe_layout.cpp: el arreglo original sin título, un 12 % mayor) y el botón Outfit entre Cancelar y Aceptar, que
// abre la ropa del equipo: Sombreros, Gafas, Cara y Manos (de momento solo hay sombreros, los de Ultimate Mayhem de
// core/native/hat_militar.cpp; las otras categorías ya están, vacías). El sombrero elegido es solo de ese equipo
// (core/native/ropa_equipos.cpp, como en Ultimate Mayhem); Cancelar lo deja como estaba al empezar a editarlo.
extern "C" { int w3d_team_hat_get(const char *team); void w3d_team_hat_set(const char *team, int hat); }
const char *const kCet = "FE.Create Edit Team";
bool g_outfit;            // página Outfit abierta
int g_outfit_cat;         // 0 sombreros, 1 gafas, 2 cara, 3 manos
char g_cet_team[64];      // el equipo que se edita (User.HumanTeamName)
int g_cet_orig = -2;      // su sombrero propio al empezar a editarlo (-1: ninguno propio), para Cancelar
const char *const kOutfitIcons[4] = {"icon_ropa_sombreros.w3ui", "icon_ropa_gafas.w3ui", "icon_ropa_cara.w3ui", "icon_ropa_manos.w3ui"};
const char *outfit_text(int which) {   // 0-3 categorías, 4 «próximamente», 5 «ninguno»
    static const char *const k[6][5] = {
        {"Hats", "Chapeaux", "Hüte", "Cappelli", "Sombreros"},
        {"Glasses", "Lunettes", "Brillen", "Occhiali", "Gafas"},
        {"Face", "Visage", "Gesicht", "Viso", "Cara"},
        {"Hands", "Mains", "Hände", "Mani", "Manos"},
        {"Coming soon", "Bientôt", "Demnächst", "Presto", "Próximamente"},
        {"None", "Aucun", "Keine", "Nessuno", "Ninguno"}};
    int l = lang(); if (l < 0 || l > 4) l = 0;
    return k[which][l];
}
double g_outfit_since;    // cuándo se abrió o se cerró Outfit (su parte de abajo entra sola; la de arriba no cambia)
// El sombrero que lleva un equipo: el suyo, o el de Developer si no tiene.
int team_hat(const char *team) { const int h = w3d_team_hat_get(team); return h >= 0 ? h : w3d_hat_mode; }
int cet_hat() { return team_hat(g_cet_team); }
void cet_cancel() { if (g_cet_orig != -2) w3d_team_hat_set(g_cet_team, g_cet_orig); }
// Icono de categoría (arte de Codex, docs/ui-3ds/arte-hd); sin él, el de Developer.
const char *outfit_icon(int cat) { const Img *i = img(kOutfitIcons[cat], 8); return i->failed ? "icon_developer.w3ui" : kOutfitIcons[cat]; }
// L/R giran el worm de arriba (gusano3d.cpp): R hacia la derecha, L hacia la izquierda, mientras se mantienen.
void turn_with_lr() {
    const u32 h = input().held;
    gusano_turn(((h & UI_K_R) ? 1 : 0) - ((h & UI_K_L) ? 1 : 0));
}
// Arriba, en Crear equipo y en la ventana del equipo de Multijugador: el worm en 3D a la izquierda, centrado en vertical,
// con el sombrero del equipo, y a la derecha el equipo: su nombre y sus seis worms (los que no juegan, apagados: active).
void team_top(const char *team, const char *const names[6], int active, int hat, float pop) {
    begin(0);
    gusano_draw(0, 106, 132, 176, hat, pop);
    const float x = 214, y = 42, w = 174, h = 186, cx = x + w / 2, cy = y + h / 2;
    if (pop > 0.02f) panel(img(kBorderBlue, 0), cx - w * pop / 2, cy - h * pop / 2, w * pop, h * pop, 6 * pop, 0x183b78ff);
    if (pop >= 0.9f) {
        text_fit(cx, y + 10, game_text(team), 19, w - 22, 0xffffffff, 1);
        text_shadow(cx, y + 38, key_text("FE.Header.TeamMembers", "Team Members"), 12, 0xffdc48ff, 1);
        for (int i = 0; i < 6; i++) {
            const float ry = y + 56 + i * 21;
            const bool on = i < active;
            rect(x + 12, ry, w - 24, 18, on ? 0x0b2147a8 : 0x0b214750);
            text_fit(cx, ry + 2, names[i] ? game_text(names[i]) : "", 13, w - 34, on ? 0xffffffff : 0xffffff70, 1);
        }
    }
    begin(1);
}
// Crear equipo: los nombres son los del equipo que se edita (sus campos, User.HumanWorm1-6).
void cet_top(float pop) {
    const char *names[6];
    for (int i = 0; i < 6; i++) { char key[24]; snprintf(key, sizeof key, "User.HumanWorm%d", i + 1); names[i] = w3d_fe_prop_str(key); }
    team_top(g_cet_team, names, 6, cet_hat(), pop);
}
// Desplegables de abajo: un toque los abre y se quedan abiertos; tocar una fila la elige (desde la fila elegida, con la
// cruceta, y A, como el jugador), arrastrar sobre la lista la recorre (las largas, como las voces o las banderas, siguen
// por debajo de la pantalla) y tocar fuera la cierra (B). Filas medidas en el juego (prueba t3_combo): la primera
// empieza 25,6 unidades del FE bajo el centro del control y cada una mide 32,2; el texto ocupa el 90 % de su ancho.
struct CetCombo { const char *name; float half; };
const CetCombo kCetCombos[] = {{"Speech", 100}, {"Flag", 56}, {"Special Weapon2", 130}, {"Barracks", 110}};
struct ComboDrag { const CetCombo *cb = nullptr; float y0 = 0; int sel0 = 0; bool moved = false; };
ComboDrag g_cdrag;
// v42 (el dueño, con la v41: «en las listas desplegables es horrible elegir cosas con la pantalla táctil: las abres pero
// no puedes hacer scroll ni agarrar la barra deslizadora; está diseñada para el mando, pero tiene que funcionar bien con
// la pantalla táctil en todos los menús»). Cualquier desplegable del juego abierto abajo (w3d_fe_open_combo, fe_layout.cpp:
// todos son ComboControl) se queda el lápiz, en todos los menús:
// - arrastrar sobre las filas las recorre (dedo arriba, filas de más abajo), como la cruceta;
// - tocar una fila sin arrastrar la elige (desde la elegida, con la cruceta, y A, como el jugador);
// - la barra de la derecha se agarra: la posición del dedo en su alto es la de la fila en toda la lista (sus filas salen de
//   la tabla del FE a la que está atado el desplegable); al soltar, la elegida queda marcada y se acepta con un toque;
// - tocar fuera lo cierra (B).
// Geometría medida en el juego (prueba t3_combo): la primera fila empieza 25,6 unidades del FE bajo el centro del control,
// cada una mide 32,2, se ven nueve, y el texto ocupa el 90 % del ancho del control; la barra va pegada a su derecha.
struct W3dCombo { const char *name; float x, y, k, half; int selected; float top; int count; };
extern "C" int w3d_fe_open_combo(const char *menu, W3dCombo *o);
extern "C" int w3d_fe_combo_set(const char *menu, const char *name, int selected, float top);
struct AnyComboDrag { bool on = false, bar = false, moved = false; float y0 = 0, top0 = 0; int sel0 = 0; const char *name = nullptr; };
AnyComboDrag g_acd;
bool combo_touch_any(const char *menu) {
    W3dCombo c;
    if (!menu || !w3d_fe_open_combo(menu, &c)) { g_acd.on = false; return false; }
    const Input &in = raw_input();
    const float tx = (float)in.tx, ty = (float)in.ty;
    const float first = c.y + 25.6f * c.k, pitch = 32.2f * c.k, shown = 9;
    const float x0 = c.x - c.half, x1 = c.x + c.half, bar0 = x1 - 10, bar1 = x1 + 16;
    const bool rows = ty >= first && ty < first + shown * pitch && tx >= x0 && tx < bar1;
    const bool known = c.count > 0;
    const float last_top = known ? fmaxf(0.f, (float)c.count - shown) : 0.f;
    touch_eat();
    if (raw_touch_down()) {
        if (rows) {
            g_acd.on = true; g_acd.bar = known && c.count > shown && tx >= bar0; g_acd.moved = g_acd.bar;
            g_acd.y0 = ty; g_acd.top0 = c.top; g_acd.sel0 = c.selected; g_acd.name = c.name;
        } else { g_acd.on = false; if (!pressing()) press(0x200, 6); }   // fuera: cerrar
    }
    if (!g_acd.on || g_acd.name != c.name) return true;
    if (in.touch) {
        if (known) {
            // La vista sigue al dedo (con la lista conocida): arrastrar mueve las filas como en un móvil; la barra lleva la
            // vista al punto de toda la lista que marca el dedo.
            float top;
            // La barra: de media fila bajo su borde de arriba a media fila sobre el de abajo, o el de la pantalla si la lista
            // sigue por debajo (las largas de Crear equipo).
            if (g_acd.bar) {
                const float b0 = first + pitch * .5f, b1 = fminf(first + shown * pitch, 240.f) - pitch * .5f;
                top = fminf(1.f, fmaxf(0.f, (ty - b0) / fmaxf(1.f, b1 - b0))) * last_top;
            }
            else {
                if (fabsf(ty - g_acd.y0) > 6) g_acd.moved = true;
                top = g_acd.top0 + (g_acd.y0 - ty) / pitch;
            }
            top = fminf(last_top, fmaxf(0.f, top));
            if (g_acd.moved) w3d_fe_combo_set(menu, c.name, -1, top);
        } else {
            // Sin saber cuántas filas tiene: como la cruceta, de una en una.
            const int r = (int)lroundf((g_acd.y0 - ty) / pitch);
            if (r) g_acd.moved = true;
            const int target = g_acd.sel0 + r;
            if (g_acd.moved && !pressing()) { if (c.selected < target) press(0x4, 2); else if (c.selected > target) press(0x8, 2); }
        }
        return true;
    }
    if (raw_touch_up()) {
        if (!g_acd.moved && !pressing()) {
            // Un toque sin arrastrar: esa fila, y aceptar (A), como el jugador.
            int target = (int)floorf(c.top + (g_acd.y0 - first) / pitch);
            if (known) target = target < 0 ? 0 : target >= c.count ? c.count - 1 : target;
            if (known && w3d_fe_combo_set(menu, c.name, target, -1)) press(0x100, 6);
            else {
                for (int i = c.selected; i < target; i++) press(0x4, 3);
                for (int i = c.selected; i > target; i--) press(0x8, 3);
                press(0x100, 6);
            }
        }
        g_acd.on = false;
    }
    return true;
}
// true si hay una lista abierta (y entonces el lápiz es suyo).
bool cet_combo_touch() {
    const Input &in = input();
    const float tx = (float)in.tx, ty = (float)in.ty;
    for (const CetCombo &cb : kCetCombos) {
        int entered = 0, sel; float top, x, y, k;
        if (!w3d_fe_native_combo(kCet, cb.name, &entered, &sel, &top, &x, &y, &k) || !entered) continue;
        const float first = y + 25.6f * k, pitch = 32.2f * k;
        if (touch_down()) {
            if (fabsf(tx - x) <= cb.half * 0.9f * k && ty >= first && ty < first + 9 * pitch) g_cdrag = {&cb, ty, sel, false};
            else if (!pressing()) press(0x200, 6);   // fuera: cerrar
            return true;
        }
        if (g_cdrag.cb != &cb) return true;
        if (in.touch) {
            const int rows = (int)lroundf((g_cdrag.y0 - ty) / pitch);   // dedo arriba: filas de más abajo
            if (rows) g_cdrag.moved = true;
            const int target = g_cdrag.sel0 + rows;
            if (g_cdrag.moved && !pressing()) { if (sel < target) press(0x4, 2); else if (sel > target) press(0x8, 2); }
            return true;
        }
        if (touch_up()) {
            if (!g_cdrag.moved && !pressing()) {
                const int target = (int)lroundf(top) + (int)floorf((g_cdrag.y0 - first) / pitch);
                for (int i = sel; i < target; i++) press(0x4, 3);
                for (int i = sel; i > target; i--) press(0x8, 3);
                press(0x100, 6);
            }
            g_cdrag.cb = nullptr;
        }
        return true;
    }
    g_cdrag.cb = nullptr;
    return false;
}
void cet_touch() {
    if (cet_combo_touch()) return;
    if (!touch_down() || pressing()) return;
    const float tx = (float)input().tx, ty = (float)input().ty;
    const char *item = w3d_fe_native_hit(kCet, tx, ty);
    if (!item) return;
    if (!strcmp(item, "Cancel")) cet_cancel();
    activate(item);
}
// Página Outfit (abajo): las cuatro categorías arriba (se tocan; L/R giran el worm de arriba para ver el sombrero por
// todos lados) y la rejilla de la elegida; Volver regresa al equipo.
void page_outfit() {
    for (int i = 0; i < 4; i++) {
        const float cx = 40 + i * 80, cy = 21;
        const bool on = g_outfit_cat == i;
        ring_icon(outfit_icon(i), cx, cy, 32, on || nav_focus());
        text_shadow(cx, 39, outfit_text(i), 11, on ? 0xffdc48ff : 0xffffffff, 1);
        if (tap(cx - 38, 0, 76, 54) && !on) { g_outfit_cat = i; ropa_focus = -1; }
    }
    const float gy = 56, gh = 142;
    if (g_outfit_cat == 0) {
        const int k = hat_grid(4, gy, 312, gh, cet_hat());
        if (k >= 0 && k != cet_hat()) { w3d_team_hat_set(g_cet_team, k); gusano_react(); }
        text_fit(316 - kMargin, 214, ropa_name(cet_hat()), 13, 170, 0xd8e4ffff, 2);
    } else {
        // Sin modelos todavía (gafas, cara y manos): la casilla «ninguno», puesta, y el aviso.
        panel(img(kBorderBlue, 0), 4, gy, 312, gh, 14, 0x10285aee);
        const Img *cells = img("smallicons_hd.w3ui", 0);
        sprite(cells, 24, gy + 18, 54, 54, 0xffffffff, 384, 448, 64, 64);
        text_fit(51, gy + 18 + 21, outfit_text(5), 10, 48, 0xffffffff, 1);
        text_shadow(190, gy + 56, outfit_text(4), 17, 0xffdc48ff, 1);
    }
    if (back_button() || key_down(UI_K_B)) { g_outfit = false; g_outfit_since = now(); eat_b(); }
}
void page_cet() {
    // El teclado del juego (nombre de un worm): sus teclas abajo; arriba, el texto en el centro (fe_bridge.cpp).
    if (keyboard_page(nullptr)) return;
    const char *team = w3d_fe_prop_str("User.HumanTeamName");
    if (!team) team = "";
    if (strcmp(team, g_cet_team)) { snprintf(g_cet_team, sizeof g_cet_team, "%s", team); g_cet_orig = w3d_team_hat_get(g_cet_team); }
    // Arriba no cambia al abrir o cerrar Outfit (el dueño, 2026-11-07: el worm desaparecía y volvía a salir): entra solo
    // con la página. Abajo, Outfit entra con su fundido y, al volver, los controles del juego y el botón Outfit con el suyo.
    const float pop = page_pop();
    turn_with_lr();
    cet_top(pop);
    begin(1);
    if (g_outfit) { set_fade(fminf(g_page_fade, fade_since(g_outfit_since))); page_outfit(); return; }
    // Outfit, entre Cancelar y Aceptar: el aro del juego con el sombrero (Codex) y su nombre.
    float bpop = fminf(pop, pop_since(g_outfit_since));
    // v43: con un desplegable abierto que llega hasta él (el del arma especial), el botón no se dibuja: la UI va encima
    // del juego y tapaba las filas de la lista. Su borde visible: el del control menos 4 px; el botón empieza en x 114.
    { W3dCombo oc; if (w3d_fe_open_combo(kCet, &oc) && oc.x + oc.half / 0.9f - 4 > 112 && oc.y + 25.6f * oc.k + 9 * 32.2f * oc.k > 196) bpop = 0; }
    if (bpop > 0.02f) {
        const float d = 38 * bpop;
        ring_icon(outfit_icon(0), 133, 215, d, false);
        if (bpop > 0.9f) text_shadow(157, 207, ropa_text(0), 15, 0xffffffff, 0);
    }
    if (bpop > 0.02f && tap(106, 192, 112, 48)) { g_outfit = true; g_outfit_since = now(); g_outfit_cat = 0; ropa_focus = -1; return; }
    if (key_down(UI_K_B)) cet_cancel();   // el juego cancela con B (FE.RevertTeam)
    cet_touch();
}

// Equipo nuevo (FE.NewTeam, el «+» de Crear equipo). La ventana del juego pide el nombre con su campo, Cancelar y
// Aceptar; con dos pantallas salía rara (el dueño, 2026-11-07): arriba la ayuda dos veces y la ventana del juego detrás
// de la de la UI («yo quitaría el cuadro ese de atrás»), y abajo sus controles encima de los de Crear equipo. Ahora va
// directa al teclado del juego (abajo; arriba el nombre en el centro con la ayuda encima) y el teclado decide por la
// ventana: aceptar el nombre crea el equipo (Accept: FE.CreateTeam) y cancelarlo la cierra (Cancel: FE.RevertTeam). Sin
// el teclado abierto, la ventana es de la UI: la ayuda arriba; abajo el nombre (tocarlo abre el teclado), Volver y
// Aceptar. Los controles del juego van ocultos (fe_layout.cpp) y su ventana de arriba también: solo ella, que el
// teclado usa la misma textura para su ventana (abajo) y el recuadro del texto (arriba, 43 px; la ventana mide 132).
void page_new_team() {
    hide_top_big("Frontend/Mechanics/Text_Border_Keyboard.tga", 90);
    // La ventana no atiende mientras entra (~0,4 s) ni justo después de cerrarse el teclado (tras cancelar con B, hasta
    // ~1 s): abrir se repite cada 0,8 s (resaltar y A tarda 0,25 s), hasta tres veces; cerrar, cada 0,4 s, hasta cinco,
    // con la orden del FE que pulsa su botón por el nombre (Input.Menu.ForceSelect: va al momento y no deja una A
    // pendiente que pudiera caer en el Aceptar de Crear equipo), y solo mientras la ventana siga abierta.
    static double instance = -1, tried_at, kb_closed_at; static int tries; static bool opened;
    if (instance != g_page_since) { instance = g_page_since; opened = false; tries = 0; tried_at = 0; kb_closed_at = -1; g_kb_result = 0; }
    const char *help = key_text("FE.Tip.NewTeamName", "Enter a name for your team here.");
    if (keyboard_page(nullptr)) {
        if (!opened) {
            opened = true; tries = 0; tried_at = 0;
            // La caja empieza vacía (el dueño, 2026-11-07). Si se acepta sin escribir nada, el teclado recupera el nombre
            // que proponía el juego («Team 1»): con el texto vacío el juego se cae (fe_bridge.cpp).
            w3d_kb_clear();
        }
        begin(0); text_shadow(200, 76, help, 16, 0xffffffff, 1); begin(1);
        return;
    }
    const double t = now();
    if (!opened) {   // el campo, como lo pulsaría el jugador (resaltarlo y A)
        if (tries < 3 && t - g_page_since > 0.45 && t - tried_at > 0.8 && !pressing()) { activate("Team Name"); tries++; tried_at = t; }
        if (tries < 3 || t - tried_at < 0.8) return;
    } else if (g_kb_result) {   // el teclado se cerró: la ventana con él
        if (kb_closed_at < 0) kb_closed_at = t;
        const char *p = w3d_fe_popup_depth() > 0 ? w3d_fe_last_popup() : nullptr;
        const bool here = p && !strcmp(p, "FE.NewTeam");
        if (here && tries < 5 && t - kb_closed_at > 0.3 && t - tried_at > 0.4) { w3d_fe_activate(g_kb_result == 1 ? "Accept" : "Cancel"); tries++; tried_at = t; }
        if (tries < 5 || t - tried_at < 0.4) return;
        g_kb_result = 0;   // no se cerró: la ventana de la UI
    }
    begin(0);
    panel(img(kBorderBlue, 0), 40, 74, 320, 92, 6, 0x183b78ff);
    text_box(60, 106, 280, help, 17, 0xffffffff, 1, 3);
    begin(1);
    const char *nm = w3d_fe_prop_str("User.HumanTeamName");
    if (text_button(50, 86, 220, 48, nm ? game_text(nm) : "", false, 18)) activate("Team Name");
    if (back_button()) w3d_fe_activate("Cancel");
    if (start_button(tr(T_ACCEPT))) w3d_fe_activate("Accept");
}

// Fila con flechas dentro de un panel (de x0 a x1): las flechas en sus bordes y la fila entre ellas; como value_row.
int panel_row(float x0, float x1, float y, const char *label, const char *value, const char *icon) {
    const float aw = 26, ah = 30, h = 44, rx = x0 + aw + 4, rw = x1 - x0 - 2 * (aw + 4);
    arrow(x0, y + (h - ah) / 2, -1, aw, ah);
    arrow(x1 - aw, y + (h - ah) / 2, 1, aw, ah);
    native_button(rx, y, rw, h, nav_focus(0));
    float tx = rx + 12;
    if (icon) { sprite_fit(img(icon, 1), rx + 8, y + 6, 32, 32); tx = rx + 46; }
    text_shadow(tx, y + 5, label, 11, 0xbcd0ffff, 0);
    text_fit(tx, y + 19, value, 16, rx + rw - 10 - tx, 0xffffffff, 0);
    int r = hit_row(rx, y, rw, h);
    if (tap(x0 - 6, y, rx - x0 + 6, h)) r = -1;
    if (tap(rx + rw, y, x1 + 6 - rx - rw, h)) r = 1;
    return r;
}
// Ventana del equipo (FE.PopTeamAdjust: tocar un equipo de la partida en Multijugador), con las propiedades y órdenes de
// la ventana original, sin selectores anidados. Como Crear equipo (el dueño, 2026-11-07): arriba el worm del equipo en 3D
// con su sombrero, que L/R giran, y sus seis worms (los que no van a jugar, apagados); los controles de Multijugador se
// apartan mientras está abierta (fe_layout.cpp) y el juego no oscurece (gx_metal.mm, w3d_ui_popup_veil). Abajo, en un
// panel y sin repetir el nombre de arriba: el color (alianza), quién lo lleva y cuántos worms juegan; debajo, como en
// las demás páginas, Volver y Aceptar en las esquinas y Borrar en medio (la papelera del juego en su aro, como Outfit).
// La ventana del propio juego (FE.TextBoxBackground, atlas Text_Border_Keyboard) se oculta: quedaba detrás como un
// segundo cuadro.
void page_team_adjust() {
    const char *raw = w3d_fe_prop_str("FE.SelectedTeam");
    const char *name = raw ? raw : "";
    const int skill = w3d_fe_team_skill(name);
    hide_fe_chrome(); hide_setting_icons();
    hide_top_force("Frontend/Mechanics/Text_Border_Keyboard.tga");
    const char *count = w3d_fe_prop_str("FE.WormsInTeam");
    char worms[16]; snprintf(worms, sizeof worms, "%s", count ? count : "4");
    turn_with_lr();
    { const char *names[6];
      for (int i = 0; i < 6; i++) names[i] = w3d_fe_team_worm(name, i);
      team_top(name, names, atoi(worms), team_hat(name), page_pop()); }
    panel(img(kBorderBlue, 0), 6, 6, 308, 180, 7, 0x10285ae0);
    // Alianza: cuadraditos de esquinas redondeadas con los colores de equipo del juego (tools/build3ds/ui/
    // cuadros_color.py); el elegido lleva el marco de oro, que entra con un pequeño rebote al cambiar.
    static const char *const kSquares[4] = {"cuadro_rojo.w3ui", "cuadro_azul.w3ui", "cuadro_verde.w3ui", "cuadro_amarillo.w3ui"};
    text_shadow(24, 30, tr(T_COLOUR), 15, 0xffffffff, 0);
    const char *allied = w3d_fe_prop_str("FE.AlliedNumber");
    const int alliance = allied ? atoi(allied) : 0;
    static int shown = -1; static double shown_at;
    if (alliance != shown) { shown = alliance; shown_at = now(); }
    for (int i = 0; i < 4; ++i) {
        const float s = 32, x = 134 + i * 44, y = 22;
        const bool focus = nav_focus();
        sprite(img(kSquares[i], 8), x, y, s, s);
        if (alliance == i || focus) {
            float k = 1;
            if (alliance == i) { const float t = (float)((now() - shown_at) / 0.22); if (t < 1) { const float u = t - 1; k = 1 + 2.4f * u * u * u + 1.4f * u * u; } }
            const float f = 44 * (k < 0.2f ? 0.2f : k);
            sprite(img("cuadro_marco_oro.w3ui", 8), x + s / 2 - f / 2, y + s / 2 - f / 2, f, f, alliance == i ? 0xffffffff : 0xffffffa0);
        }
        if (hit(x - 5, y - 5, s + 10, s + 10)) {
            char cmd[96]; snprintf(cmd, sizeof cmd, "FE.ChangeAllie$%d\\FE.Prepare$TeamAdjust", i);
            w3d_fe_run(cmd);
        }
    }
    char control[48];
    if (skill > 0) snprintf(control, sizeof control, "%s %d", tr(T_CPU), skill);
    else snprintf(control, sizeof control, "%s", tr(T_HUMAN));
    const int c = panel_row(16, 304, 66, tr(T_CONTROL), control, team_icon(name));
    if (c) { w3d_fe_team_set_skill(name, (skill + (c < 0 ? 5 : 1)) % 6); }
    const int d = panel_row(16, 304, 122, tr(T_WORMS), worms, "Frontend/Icons/Icon_Team_Options.tga");
    if (d) {
        int value = atoi(worms) + (d < 0 ? -1 : 1); if (value < 1) value = 6; if (value > 6) value = 1;
        char cmd[100]; snprintf(cmd, sizeof cmd, "FE.ChangeWorms$%d\\FE.Prepare$TeamAdjust", value); w3d_fe_run(cmd);
    }
    // (Su toque, entre los de Volver, que llega hasta x = 123, y Aceptar, que empieza en 208.)
    { const bool focus = nav_focus();
      ring_icon("Frontend/Icons/Icon_DeleteTeam.tga", 137, 216, 36, focus);
      text_shadow(159, 208, tr(T_DELETE), 15, focus ? 0xffdc48ff : 0xffffffff, 0);
      if (hit(123, 194, 84, 44)) activate("Delete Team"); }
    if (back_button() || start_button(tr(T_ACCEPT))) activate("Accept");
}

bool is_confirm(const char *m) {
    static const char *const k[] = {"FE.InGameQuitConfirm", "FE.InGameDrawConfirm", "FE.SchemeConfirm", "FE.TeamConfirm",
                                    "FE.QuitConfirmPopUp", "FE.LeaveOptions", "FE.LeaveMultiplayer"};
    for (const char *s : k) if (m && !strcmp(m, s)) return true;
    return false;
}
}  // namespace

#if defined(__3DS__)
extern "C" int gx_ui_menu_under_on(void);   // platform/3ds/gx_pica.cpp
#endif
void tris_under(int screen, int tex, const float *xyzuv, const unsigned *rgba, int n) {
    if (n < 3) return;
#if defined(__3DS__)
    // Sin lienzo alto, sin dos pantallas o con W3D_NO_UNDERLAY: ya, en la capa de la UI (sin z, en el orden dado).
    if (!gx_ui_menu_under_on()) {
        static std::vector<float> v; v.resize((size_t)n * 4);
        for (int i = 0; i < n; i++) { v[i * 4] = xyzuv[i * 5]; v[i * 4 + 1] = xyzuv[i * 5 + 1]; v[i * 4 + 2] = xyzuv[i * 5 + 3]; v[i * 4 + 3] = xyzuv[i * 5 + 4]; }
        (void)screen;
        uib_tris(tex, v.data(), (const uint32_t *)rgba, n);
        return;
    }
#endif
    g_tri_runs.push_back({tex, screen, g_tri_c.size(), n});
    g_tri_v.insert(g_tri_v.end(), xyzuv, xyzuv + (size_t)n * 5);
    g_tri_c.insert(g_tri_c.end(), rgba, rgba + n);
}
// gx_metal.mm: los triángulos del cuadro anterior (textura, pantalla, x y z u v por vértice y su color).
extern "C" int w3d_ui_menu_tris(int i, int *tex, int *screen, const float **xyzuv, const unsigned **rgba) {
    if (i < 0 || i >= (int)g_tri_runs.size()) return 0;
    const TriRun &r = g_tri_runs[i];
    *tex = r.tex; *screen = r.screen; *xyzuv = &g_tri_v[r.first * 5]; *rgba = &g_tri_c[r.first];
    return r.count;
}
// fe_layout.cpp: Crear equipo tiene abierta su página Outfit (sus controles se ocultan).
extern "C" int w3d_ui_outfit_open(void) {
    const char *m = w3d_test_fe_menu();
    return g_outfit && m && !strcmp(m, kCet) && w3d_fe_popup_depth() == 0;
}
// gx_metal.mm: los fondos pedidos por la página (textura, uv máximo, rectángulo en píxeles de la pantalla de abajo).
extern "C" int w3d_ui_menu_underlay(int i, int *tex, float *uv, float *rect) {
    if (i < 0 || i >= g_underlay_count) return 0;
    const Underlay &u = g_underlays[i];
    *tex = u.tex; uv[0] = u.u1; uv[1] = u.v1; rect[0] = u.x; rect[1] = u.y; rect[2] = u.w; rect[3] = u.h; rect[4] = (float)u.screen;
    return 1;
}

// gx_metal.mm: 0 si el juego no debe oscurecer con su ventana: la del equipo es una página de la UI (con el worm arriba,
// que el velo, dibujado encima, apagaba) y los controles de Multijugador se apartan.
extern "C" int w3d_ui_popup_veil(void) {
    const char *p = w3d_fe_popup_depth() > 0 ? w3d_fe_last_popup() : nullptr;
    return !(p && !strcmp(p, "FE.PopTeamAdjust"));
}
// En pad_read: L y R giran el worm en Crear equipo y en la ventana del equipo (con el teclado abierto son del teclado).
bool pages_eat_lr() {
    if (!w3d_fe_native_layout() || w3d_fe_game_mode() != 6 || w3d_kb_open()) return false;
    const char *m = w3d_test_fe_menu();
    const char *p = w3d_fe_popup_depth() > 0 ? w3d_fe_last_popup() : nullptr;
    if (p) return !strcmp(p, "FE.PopTeamAdjust");
    return m && (!strcmp(m, kCet) || !strcmp(m, "FE.PopTeamAdjust"));
}
// En pad_read: la B que cerró una página propia no llega al juego hasta que el mando la suelta (y al menos 0,3 s).
bool pages_eat_b(bool held) {
    if (g_eat_b && !held && uib_seconds() - g_eat_b_at > 0.3) g_eat_b = false;
    return g_eat_b;
}
int pages_capture() {
    const int mode=w3d_fe_game_mode();
    if(mode!=6 && mode!=7) return 0; // Award/unlock scenes keep their original input.
    if(w3d_card_ui_read(nullptr)) return 0;
    if(w3d_fe_native_layout() && w3d_fe_game_mode()==7 && w3d_fe_prop_uint("WeaponPanel.Open",0)) return 1;
    const char *m = w3d_test_fe_menu();
    const char *p = w3d_fe_popup_depth() > 0 ? w3d_fe_last_popup() : nullptr;
    if(p && !strcmp(p,"Game.BriefDialog")) return 2;
    if(w3d_fe_native_layout() && (is_confirm(m) || is_confirm(p))) return 0;
    // FE.CurrentMenu may still name MainMenu during a match. It must never
    // capture firing, walking or aiming after the title has been left.
    if(w3d_fe_native_layout() && w3d_fe_game_mode()==7)
        return (m && !strcmp(m,"FE.PauseMenu")) || (p && !strcmp(p,"FE.PauseMenu")) ? 2 : 0;
    if(m && !strcmp(m,"FE.SoundOptions")) return 2;
    if (is_confirm(m) || is_confirm(p) || (p && (!strcmp(p, "FE.PauseMenu") || !strcmp(p, "FE.PopTeamAdjust"))) || (m && !strcmp(m, "FE.PopTeamAdjust"))) return 2;
    if (!m || p) return 0; // Unported popups keep native controller navigation.
    if (g_eat_b || (!strcmp(m, "FE.Options") && g_developer)) return 2;
    if (!strcmp(m, "FE.MainMenu") || !strcmp(m, "FE.SinglePlayerMenu") || !strcmp(m, "FE.Options") || !strcmp(m, "FE.LanguageSelect")) return 1;
    if (!strcmp(m, "FE.TutorialMenu") || !strcmp(m, "FE.CampaignMenu") || !strcmp(m, "FE.Challenge Menu")) return 2;
    if (!strcmp(m, kCet) && g_outfit) return 2;
    return 0;
}

// Una vez por cuadro, dentro de begin(1).
static bool g_pages_cut, g_panel_was;
void pages_cut() { g_pages_cut = true; }
void pages_frame() {
    // Los fondos del cuadro anterior: si cambia la página, se encogen 0,14 s con los controles del juego que se van.
    memcpy(g_last_under, g_underlays, sizeof g_underlays); g_last_count = g_underlay_count;
    g_underlay_count = 0;
    g_tri_runs.clear(); g_tri_v.clear(); g_tri_c.clear();
    const char *weapon_menu=w3d_test_fe_menu();
    if(w3d_fe_game_mode()!=6 || !weapon_menu || strcmp(weapon_menu,"FE.WeaponOptions") || w3d_fe_popup_depth()>0)
        weapon_preview_clear();
    // FE.CurrentMenu retains the previous selection during award movies (mode 8)
    // and unlock scenes (9). It must not draw a stale mission/menu over them.
    const int mode=w3d_fe_game_mode();
    if(mode!=6 && mode!=7) {g_out_count=g_last_count=0;navigation_begin("original-scene",false);return;}
    if(w3d_fe_game_mode()!=7) {map_tex=-1;map_u=map_v=1;}
    const char *menu = w3d_test_fe_menu();
    const char *popup = w3d_fe_popup_depth() > 0 ? w3d_fe_last_popup() : nullptr;
    if (!menu || strcmp(menu, kCet)) g_outfit = false;   // Outfit es de Crear equipo
    char scope[128]; snprintf(scope, sizeof scope, "%s/%s/%d", menu ? menu : "", popup ? popup : "", g_developer + 2 * g_ropa + 4 * g_outfit);
    navigation_begin(scope, pages_capture() == 2);
    W3dCardUi card;
    if(w3d_card_ui_read(&card)) {g_out_count=0;page_card(card);return;}
    // An unnamed native modal still owns input and drawing; do not draw its
    // parent carousel/help while its native window is on screen.
    if(w3d_fe_popup_depth()>0 && !popup) {g_out_count=0;return;}
    // Al cambiar de menú, la página nueva espera a que el menú anterior se encoja (0,1 s, como los controles del juego en
    // fe_layout.cpp) y entra con un fundido de 0,15 s: nunca se pinta encima de lo que se está yendo. Outfit no es otra
    // página: es la parte de abajo de Crear equipo (la de arriba sigue igual) y entra con su propio fundido (page_cet).
    char page[128]; snprintf(page, sizeof page, "%s/%s/%d", menu ? menu : "", popup ? popup : "", g_developer + 2 * g_ropa);
    { static char last[128]; static double changed;
      if (strcmp(last, page)) {
          changed = now(); g_page_since = changed;
          // v39: al quitarse la pantalla de carga la página sale entera, sin su fundido (el corte que pidió el dueño).
          // v40: lo mismo al abrir y cerrar el panel de armas (X) en la partida: «se abre de una y se cierra de una».
          // v42: y todo cambio de página en la partida (pausa, «¿Seguro?»...): el fundido de entrada dejaba 0,1 s la pantalla
          // de abajo en negro antes de la pausa (el dueño, con la v41).
          const bool panel = w3d_fe_game_mode() == 7;
          if (getenv("W3D_CAROUSEL_LOG")) uib_log("[ui] página %s -> %s%s\n", last, page, panel || g_pages_cut ? " (sin fundido)" : "");
          if (g_pages_cut || panel || g_panel_was) changed -= 1.0;
          memcpy(g_out_under, g_last_under, sizeof g_last_under); g_out_count = g_last_count; g_out_since = changed;
          gusano_turn_reset();   // cada página enseña el worm de frente
          snprintf(last, sizeof last, "%s", page);
      }
      g_panel_was = w3d_fe_game_mode() == 7 && w3d_fe_prop_uint("WeaponPanel.Open", 0);
      { const float t = (float)((now() - g_out_since) / 0.14);
        for (int i = 0; t < 1 && i < g_out_count && g_underlay_count < 4; i++) {
            Underlay u = g_out_under[i]; const float k = 1 - t * t, cx = u.x + u.w / 2, cy = u.y + u.h / 2;
            u.w *= k; u.h *= k; u.x = cx - u.w / 2; u.y = cy - u.h / 2; g_underlays[g_underlay_count++] = u;
        } }
      g_page_fade = (float)((now() - changed - 0.1) / 0.15);
      g_pages_cut = false;
      set_fade(g_page_fade); }
    // v42: un desplegable abierto del juego se queda el lápiz en cualquier menú (combo_touch_any); la página se dibuja igual.
    if (w3d_fe_native_layout() && w3d_fe_game_mode() == 6) {
        W3dCombo probe;   // los de una ventana (popup) van con el nombre de la ventana
        combo_touch_any(popup && w3d_fe_open_combo(popup, &probe) ? popup : menu);
    }
    // Diálogos de confirmación (FE.CurrentMenu puede tomar el nombre del popup, o no: se miran los dos).
    if (is_confirm(menu)) { page_confirm(menu); return; }
    if (is_confirm(popup)) { page_confirm(popup); return; }
    if(popup && !strcmp(popup,"Game.BriefDialog")) {page_brief();return;}
    if ((popup && !strcmp(popup, "FE.PopTeamAdjust")) || (menu && !strcmp(menu, "FE.PopTeamAdjust"))) { page_team_adjust(); return; }
    if (w3d_fe_native_layout() && ((popup && !strcmp(popup, "FE.NewTeam")) || (menu && !strcmp(menu, "FE.NewTeam")))) { page_new_team(); return; }
    W3dHud h;
    const bool match = w3d_hud_read(&h) != 0;
    if (match) {
        if ((menu && !strcmp(menu, "FE.PauseMenu")) || (popup && !strcmp(popup, "FE.PauseMenu"))) {
            const char *gt = w3d_fe_prop_str("GameOver.GameType");
            page_pause(gt && (!strcmp(gt, "Multiplayer") || !strcmp(gt, "Network")));
            return;
        }
        page_match(h);
        return;
    }
    if (popup && !is_confirm(popup)) { page_generic(popup); return; }
    if (!menu || !*menu) { rect(0, 0, 320, 240, 0x000000ff); return; }   // cargando o entre pantallas: negro
    { static char last[48];   // registro: las tablas del FE al cambiar de menú (para las páginas que las muestran)
      if (strcmp(last, menu)) { snprintf(last, sizeof last, "%s", menu);
        static const char *const kT[] = {"FE.Barracks", "FE.TeamsInLocalGame", "FE.SchemeList", "FE.MultiLevels", "FE.LandscapeTypes", "FE.WormsList", "FE.AlliesList", "FE.FlagsList", "FE.SoundBanks", "FE.PauseOptions"};
        for (const char *t : kT) { static char rows[16][64]; int n = w3d_fe_table(t, rows, 16); uib_log("[ui] %s tabla %s: %d", menu, t, n); for (int i = 0; i < n && i < 16; i++) uib_log(" | %s", rows[i]); uib_log("\n"); } } }
    { static char cur[48]; if (strcmp(cur, menu)) { snprintf(g_prev_menu, sizeof g_prev_menu, "%s", cur); snprintf(cur, sizeof cur, "%s", menu); } }
    if (strcmp(menu, "FE.Options")) g_developer = g_ropa = false;
    // El teclado (código de Land Select, nombres de Crear equipo) ya no existe fuera de su menú.
    if (strcmp(menu, "FE.LandSelect") && strcmp(menu, kCet)) w3d_kb_forget();
    { static bool in_cet; const bool now_cet = !strcmp(menu, kCet);
      if (now_cet && !in_cet) { w3d_kb_forget(); g_cet_team[0] = 0; g_cet_orig = -2; g_outfit_since = 0; }   // al entrar, de nuevo
      in_cet = now_cet; }
    if (!strcmp(menu, "FE.MainMenu")) page_main();
    else if (!strcmp(menu, "FE.SinglePlayerMenu")) page_single();
    else if (!strcmp(menu, "FE.Options")) page_options();
    else if (!strcmp(menu, "FE.LanguageSelect")) page_language();
    else if (!strcmp(menu, "FE.MultiplayerMenu")) page_multi();
    else if (!strcmp(menu, "FE.TutorialMenu") || !strcmp(menu, "FE.CampaignMenu") || !strcmp(menu, "FE.Challenge Menu")) page_mission(menu);
    else if (!strcmp(menu,"FE.SoundOptions") && w3d_fe_native_layout()) page_sound();
    else if (!strcmp(menu,"FE.LandSelect") && w3d_fe_native_layout()) page_land();
    else if (!strcmp(menu, kCet) && w3d_fe_native_layout()) page_cet();
    else page_generic(menu);
}
// Placement only: native FE owns icon artwork, highlight and animation.
extern "C" int w3d_ui_carousel_layout(const char *menu,const char *name,float *x,float *y,float *diameter) {
    const Item *items=nullptr; Carousel *c=nullptr; int n=0;
    if(!strcmp(menu,"FE.MainMenu")) {items=kMainItems;c=&g_main;n=kMainCount;}
    else if(!strcmp(menu,"FE.SinglePlayerMenu")) {items=kSingleItems;c=&g_single;n=3;}
    else if(!strcmp(menu,"FE.Options")) {items=kOptItems;c=&g_opts;n=kOptCount;if(g_developer)return -1;}
    else if(!strcmp(menu,"FE.LanguageSelect")) {items=kLangItems;c=&g_lang;n=5;}
    else return 0;
    int i=0;while(i<n && (!items[i].name || strcmp(items[i].name,name)))++i;
    if(i==n || items[i].own)return -1;   // los que dibuja la UI: el del juego, oculto
    float d=fmodf(i-c->pos,(float)n);if(d>n/2.f)d-=n;if(d<-n/2.f)d+=n;
    { static const bool log = getenv("W3D_CAROUSEL_LOG") != nullptr; static float last = -99;   // pruebas: cuándo lo lee el juego
      if (log && i == 0 && c->pos != last) { last = c->pos; uib_log("[carrusel] juego lee pos %.4f (%s)\n", c->pos, name); } }
    // The same place as the UI's own items (slot_geom), with the main menu's 1% breathing.
    return slot_geom(d,c==&g_main,x,y,diameter)?1:-1;
}
}  // namespace ui
