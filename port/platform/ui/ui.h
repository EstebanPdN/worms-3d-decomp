// Interfaz de dos pantallas de la v28, común a 3DS y a la versión de Mac de dos pantallas (W3D_DUAL=1): ui_core.cpp
// (motor, arranque y título) y ui_pages.cpp (una página por menú del juego). Cada plataforma pone su ui_backend.
#pragma once
#include <stdint.h>
#include "ui_backend.h"

extern "C" {
// Puente con el frontend del juego (core/native/fe_bridge.cpp).
void w3d_fe_run(const char *commands);
void w3d_fe_runf(const char *fmt, const char *arg);
int w3d_fe_prop_int(const char *name, int def);
unsigned w3d_fe_prop_uint(const char *name, unsigned def);
const char *w3d_fe_prop_str(const char *name);
void w3d_fe_set_int(const char *name, int v);
void w3d_fe_set_uint(const char *name, unsigned v);
void w3d_fe_set_str(const char *name, const char *v);
int w3d_fe_popup_depth(void);
int w3d_fe_game_mode(void);
int w3d_fe_game_starting(void);   // v38: GameLogic.StartGame visto y el modo aún no ha cambiado (fe_bridge.cpp)
const char *w3d_fe_highlighted(void);
const char *w3d_fe_last_popup(void);
void w3d_fe_highlight(const char *item);
void w3d_fe_activate(const char *item);
void w3d_fe_confirm(int yes);
const char *w3d_fe_text(const char *key);
void w3d_fe_title_set_hide_press(int on);
void w3d_fe_choose_language(const char *lang);
void w3d_fe_set_language(const char *lang);
void w3d_fe_card_check(void);
const char *w3d_test_fe_menu(void);
// Filas de una tabla del FE (claves de cada fila, 64 bytes); devuelve cuántas hay o -1.
int w3d_fe_table(const char *name, char (*out)[64], int max);
// Equipos del cuartel: nivel (0 humano, 1..5 CPU; -1 si no existe), bandera (FE.Flag.*) y cambio de nivel.
int w3d_fe_team_skill(const char *team);
const char *w3d_fe_team_flag(const char *team);
void w3d_fe_team_set_skill(const char *team, int skill);
const char *w3d_fe_team_worm(const char *team, int i);   // nombre del worm i (0-5), texto del juego; nullptr si no hay
int w3d_ui_tall(void);
int w3d_fe_native_layout(void);
int w3d_fe_place_screen(const char *menu, const char *name);   // fe_layout.cpp: 0 arriba, 1 abajo, -1 sin sitio
const char *w3d_fe_native_hit(const char *,float,float);
// fe_layout.cpp: a native ListControl on the lower screen (entered, selected row, first visible row, centre, px/unit).
int w3d_fe_native_list(const char *,const char *,int *,int *,float *,float *,float *,float *);
// The same for a drop-down (ComboControl): open, selected row, first visible row (9 show at a time), centre and px/unit.
int w3d_fe_native_combo(const char *,const char *,int *,int *,float *,float *,float *,float *);
float w3d_fe_prop_float(const char *,float);
void w3d_fe_set_float(const char *,float);
void w3d_fe_title_music(void);   // fe_bridge.cpp: aviso de que entra el título (la música la pone el propio título)
// Teclado del juego (fe_bridge.cpp): abierto, y en pad_read si A sobre aceptar se le tapa al juego (texto vacío).
int w3d_kb_open(void);
int w3d_kb_guard_accept(int a_held);
}

namespace ui {
typedef uint8_t u8; typedef uint16_t u16; typedef unsigned u32; typedef unsigned long long u64;
// Botones para la UI (los traduce cada plataforma).
enum { UI_K_A = 1, UI_K_B = 2, UI_K_X = 4, UI_K_Y = 8, UI_K_START = 16, UI_K_SELECT = 32, UI_K_L = 64, UI_K_R = 128,
       UI_K_UP = 256, UI_K_DOWN = 512, UI_K_LEFT = 1024, UI_K_RIGHT = 2048, UI_K_TOUCH = 4096 };
struct Img { char name[64]; int tex = -1; u32 w = 0, h = 0, pw = 1, ph = 1; bool failed = false, wanted = false; u32 last = 0; int fmt = 1; };
// fmt: 0 RGBA8, 1 RGBA4, 2 RGB565; + 8: con mipmaps, para lo que se dibuja reducido (en 3DS todavía sin ellos).
// Nombre con ".w3ui": arte propio (romfs:/ui); si no, ruta del disco (TGA).
const Img *img(const char *name, int fmt = 1);
void font_keep();   // v42: la fuente de la UI sigue subida (la pausa la pide en la partida)
void img_drop(const char *name);
// Imagen hecha en memoria (RGBA, filas de arriba abajo; se copia): se sube como las del disco, fuera del cuadro.
const Img *img_mem(const char *name, const u8 *rgba, u32 w, u32 h, int fmt);
void img_mem_forget(const char *name);   // la suelta: textura y copia de los píxeles

void begin(int screen);   // 0 arriba (400x240), 1 abajo (320x240)
void quad(int tex, float x0, float y0, float x1, float y1, float u0, float v0, float u1, float v1, unsigned c);
void rect(float x, float y, float w, float h, unsigned rgba);
void sprite(const Img *i, float x, float y, float w, float h, unsigned rgba = 0xffffffff, float sx = 0, float sy = 0, float sw = 0, float sh = 0);
// Alfa común de lo que se dibuja (0..1), para el fundido de entrada de las páginas; faded() lo aplica a un 0xRRGGBBAA.
void set_fade(float a);
unsigned faded(unsigned rgba);
void sprite_rot(const Img *i, float cx, float cy, float w, float h, float ang, unsigned rgba = 0xffffffff);
// Triángulos de un modelo 3D en una pantalla (el worm de Crear equipo): por vértice x, y (píxeles), z (0 cerca, 1 lejos),
// u, v y un color (bytes r, g, b, a en memoria). En Mac van a la imagen del juego, a su resolución y con z-buffer, al
// cuadro siguiente y debajo de los controles del FE (gx_metal.mm, menu_underlay); en 3DS se dibujan ya, en la capa de la
// UI y en el orden dado (del fondo hacia delante).
void tris_under(int screen, int tex, const float *xyzuv, const unsigned *rgba, int nverts);
// platform/ui/gusano3d.cpp: el worm del juego en 3D, de pie y con sus animaciones de espera, centrado en (cx, cy) con h
// píxeles de alto, con el sombrero hat (0 ninguno) y la escala de entrada pop.
void gusano_draw(int screen, float cx, float cy, float h, int hat, float pop);
void gusano_react();   // celebra algo (un sombrero nuevo): saluda o se alegra
// L/R: girarlo, una vez por cuadro (+1 el frente hacia la derecha, -1 hacia la izquierda, 0 suelto: frena); reset de frente.
void gusano_turn(int dir);
void gusano_turn_reset();
void weapon_preview();
void weapon_preview_clear();
void panel(const Img *atlas, float x, float y, float w, float h, float t, unsigned fill, unsigned tint = 0xffffffff);
// Nueve trozos de un arte propio cuadrado (panel_azul, boton_azul, boton_oro, marco_oro: 48x48): esquinas de c píxeles
// de la imagen dibujadas a tamaño 1:1, bordes y centro estirados.
void nine(const Img *i, float x, float y, float w, float h, float c = 16, unsigned rgba = 0xffffffff);
// Imagen dentro de la caja, sin deformar (centrada), usando solo el trozo sx, sy, sw, sh de la imagen si se da.
void sprite_fit(const Img *i, float x, float y, float w, float h, unsigned rgba = 0xffffffff, float sx = 0, float sy = 0, float sw = 0, float sh = 0);
// Recorte de lo que se dibuja con quad() (sprites y texto) a un rectángulo de la pantalla; clip_off lo quita.
void clip(float x, float y, float w, float h);
void clip_off();
float text_width(const char *utf8, float size);
float text(float x, float y, const char *utf8, float size, unsigned rgba, int align = 0);
float text_shadow(float x, float y, const char *utf8, float size, unsigned rgba, int align = 0);
float text_fit(float x, float y, const char *utf8, float size, float w, unsigned rgba, int align = 0);
float text_box(float x, float y, float w, const char *utf8, float size, unsigned rgba, int align, int max_lines);
// Alto que ocuparía text_box (sin dibujar).
float text_box_height(float w, const char *utf8, float size, int max_lines = 99);
// Texto largo en una caja: si no cabe, baja solo despacio, espera, vuelve arriba y repite. key: cambia el texto -> empieza.
void text_scroll(float x, float y, float w, float h, const char *utf8, float size, unsigned rgba);
// Texto del juego (Latin-1) pasado a UTF-8 en un búfer rotatorio.
const char *game_text(const char *latin1);
// Texto traducido de una clave del juego, o el de reserva si la clave no existe.
const char *key_text(const char *key, const char *fallback);

struct Input { u32 held = 0; bool touch = false; int tx = 0, ty = 0; };
const Input &input();
bool touch_down();
bool touch_up();
// v42: un desplegable abierto se queda el lápiz (combo_touch_any, ui_pages.cpp): desde entonces y hasta el cuadro siguiente,
// input().touch, touch_down() y touch_up() dicen que no hay toque. raw_*: los de verdad.
void touch_eat();
const Input &raw_input();
bool raw_touch_down();
bool raw_touch_up();
bool hit(float x, float y, float w, float h);
// Solo el lápiz (no es un destino del mando): las flechas de una fila.
bool tap(float x, float y, float w, float h);
// Fila con flechas para el mando: arriba/abajo la eligen; con ella elegida, izquierda/derecha devuelven -1/+1. A o un
// toque en la fila devuelven 2.
int hit_row(float x, float y, float w, float h);
bool key_down(u32 k);
double now();

// Pulsaciones de GameCube para el juego (A 0x100, B 0x200, X 0x400, Y 0x800, START 0x1000, cruceta I1 D2 B4 A8).
void press(u16 gc_bits, int hold = 2);
bool pressing();
// Pulsar un botón del menú como lo haría el jugador: resaltarlo (FE.HighlightItem) y pulsar A. Input.Menu.ForceSelect
// ejecuta sus órdenes sin la animación de salida del menú y la partida rápida fallaba después (prueba t28c).
void activate(const char *item);

// Textos propios en los cinco idiomas del juego, según el idioma en curso.
enum TextId { T_LOADING, T_PRESS_START, T_TAP_SCREEN, T_DEVELOPER, T_OVERLAY, T_DUMP, T_OVERLAY_HELP, T_DUMP_HELP, T_ON, T_OFF,
              T_BACK, T_ACCEPT, T_YES, T_NO, T_ARE_YOU_SURE, T_USE_BUTTONS, T_COLOUR, T_CONTROL, T_HUMAN, T_CPU, T_PULL_LEVER,
              T_CONTINUE, T_QUIT, T_DRAW, T_WEAPONS, T_PAUSE,
              T_ADD, T_CREATE, T_LANDSCAPE, T_WORMPOT, T_RULES, T_START, T_ADD_TEAM, T_NO_TEAMS, T_CLOSE, T_WORMS, T_DELETE, T_TEAM, T_MATCH, T_MUSIC, T_SFX, T_SPEECH, T_GENERATE, T_THEME, T_TIME, T_SPIN, T_RESET, T_EDIT, T_HEALTH, T_TURN, T_ROUND, T_WINS, T_SAVE, T_LOAD, T_ACCEPT_ALT, T_MEMBERS, T_COSMETICS, T_IDENTITY, T_NAME, T_NEXT, T_RETRY, T_COUNT };
const char *tr(TextId id);
int lang();   // 0 inglés, 1 francés, 2 alemán, 3 italiano, 4 español

// Esta imagen del disco no se ve arriba durante el cuadro (ui_hide.cpp); hide_commit lo pasa al backend.
void hide_top(const char *name);
void hide_commit();
void hide_top_force(const char *name);   // también en menús con controles recolocados
// Solo sus piezas de al menos min_px de alto que caen enteras arriba (la ventana de un popup y no el teclado del juego,
// que usa la misma textura). Con dos pantallas, hide_top_force la quita en las dos.
void hide_top_big(const char *name, float min_px);
bool top_drawn(const char *name);         // el juego la usó (oculta) en los últimos cuadros

int pages_capture();  // 0: original game controls; 1: carousel; 2: spatial button navigation
bool pages_eat_b(bool held);  // B que cerró una página propia: no llega al juego hasta soltarla
bool pages_eat_lr();          // L y R son de la página (girar el worm): no llegan al juego
extern double g_kb_start_at;   // ui_core.cpp: cuándo aceptó la UI un teclado con START (pad_read se lo tapa al juego)
void navigation_begin(const char *scope, bool enabled);
bool nav_active();          // la navegación con el mando está a la vista
bool nav_focus(int k = 0);  // el k-ésimo hit() siguiente es el elegido con el mando (se dibuja en dorado)
void navigation_end();
void pages_frame();   // ui_pages.cpp: la página de abajo del menú en curso (dentro de begin(1)).
}
