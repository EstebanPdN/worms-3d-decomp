// Puente entre la UI de la pantalla de abajo (v28, platform/3ds/ui_3ds.cpp) y el frontend del juego. Estudio en
// /tmp/w3d-v28/research/fe.md (copiado en docs/ui-3ds-v28.md):
// - Todo el FE habla por órdenes de texto: d40l_console_commands_802b1258 ("FE.ChangeMenu$FE.Options\FE.X#3") hace lo
//   mismo que un botón. Un botón se pulsa por su nombre con "Input.Menu.ForceSelect$<nombre>" y se resalta con
//   "FE.HighlightItem$<nombre>".
// - Los valores de los menús son propiedades por nombre (A800fc1f0 entero, A800fc230 sin signo, A800fc2b0 texto;
//   A800fc3b0, A800fc43c y A800fc550 para escribirlas).
// - Ningún dato dice qué elemento está resaltado: se apunta el último "FE.HighlightItem$X" que pasa por
//   w3d_message_post_current (engine/message_registry.cpp).
// - Arranque: d24g_mode_start_8006af38 avisa de cada modo (0 licencia, 1 y 2 películas, 5 título, 6 menú, 7 partida).
//   Al empezar el modo 0 se quita el bit 0x80 de app+0xbc: las películas de SEGA y Team17 no se ponen y el juego pasa
//   de la licencia al título original (el planeta, modo 5). W3D_PELICULAS=1 las deja.
// En 3DS las direcciones del juego son las del proceso (h2g es la identidad): las cadenas se pasan tal cual.
#include "native_game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

namespace {
struct Application { char pad[0xbc]; w3d_u32 flags; };
}
extern "C" {
void A802b1258(const char *commands);
w3d_u32 A800fc1f0(void *key, void *out, ...);
w3d_u32 A800fc230(void *key, void *out, ...);
w3d_u32 A800fc2b0(void *key, void *out, ...);
void A800fc3b0(void *key, int value);
void A800fc43c(void *key, w3d_u32 value);
void A800fc550(void *key, const char *text);
w3d_u32 A800fc270(void *,void *);
w3d_u32 A800fc4c8(float,void *);
w3d_u32 A800fc1b0(void *key, void *out, ...);
w3d_u32 A801797b4(void *resource);
extern Ptr32<Application> A804b1788;
extern int A804abb5c;               // depth_804abb5c: ventanas emergentes abiertas
// Teclado en pantalla del juego (TextBox, d28l_keyboard_*): lo crea d28l_menu_item_set_mode_802a2924 al entrar en un
// campo de texto y lo configura con 802c4a60, que se sustituye aquí (mismo cuerpo) para apuntar el objeto. Abierto
// mientras su +80 (listo) vale 1. Campos: +64 tecla elegida (31 borrar, 32 cursor izquierda, 33 mayúsculas, 34 aceptar,
// 35 cursor derecha), +80 listo, +256 texto (cadena del juego), +264 cursor.
// Funciones del juego: reciben punteros de 32 bits del juego (Ptr32), no punteros del anfitrión.
void A802c4a7c(Ptr32<char> keyboard, int ch);   // escribir un carácter en el cursor (con sus comprobaciones y sonido)
void A802c40b4(Ptr32<char> keyboard);           // pulsar la tecla elegida
void A802c4744(Ptr32<char> keyboard);           // rehacer lo que enseña el recuadro (f1p_update_masked_caption)
void A802c4998(Ptr32<char> keyboard);           // recolocar el texto y el cursor (f1p_offset_item_vector)
// Posición de una vista del teclado (d43l_keyboard_layout_build): el vector tiene constructor de copia propio, así que
// va por referencia oculta, como en el juego.
struct KbVec { float x, y, z; KbVec(float a, float b, float c) : x(a), y(b), z(c) {} KbVec(const KbVec &o) : x(o.x), y(o.y), z(o.z) {} };
void A802b3020(Ptr32<char> view, KbVec v);
// engine/message_registry.cpp. El reenlace por dirección (tools/relink/link_all.py) renombra los ayudantes de una unidad
// con el prefijo U_ (en 3DS y en Mac).
int U_w3d_fe_message_id(Ptr32<const char> name, Ptr32<unsigned short> id);
static int find_id(const char *name, unsigned short *out) {
    Ptr32<unsigned short> p; p = out;
    return U_w3d_fe_message_id(Ptr32<const char>(name), p);
}
void w3d_dbg(const char *, ...);
int w3d_fe_native_layout(void);

static int g_mode = -1;
static char g_highlight[48];
static char g_last_popup[48];
static char g_popup_names[32][64];
static char g_layout_menu[64];
const char *w3d_fe_layout_menu(void) { return g_layout_menu; }
static unsigned short g_id_highlight = 0xffff, g_id_popup = 0xffff, g_id_popup_light = 0xffff, g_id_popup_clear = 0xffff, g_id_change = 0xffff;
// v38: GameLogic.StartGame (el frontend pide empezar la partida). Desde ese mensaje hasta que el modo cambia, la UI
// pone las dos pantallas en negro con el icono de carga: la carga que sigue bloquea varios segundos y antes se quedaba
// en pantalla el menú a medio desmontar (fondo negro con controles sueltos).
static unsigned short g_id_start = 0xffff;
static int g_start_pending;
// v42 (el dueño, con la v41: en la partida rápida «no queda la pantalla negra y después el fade in como yo te dije, queda
// el primer frame del fade in trancado»): tras GameLogic.StartGame el juego cambia de modo en la actualización del cuadro
// siguiente (d42i_app_frame_update_801277ec: codex_flags_8006ee18 dice si hay cambio pendiente y entonces
// d24g_mode_start_8006af38 arranca el modo 7, que carga la partida de un tirón, varios segundos sin pintar). En la partida
// rápida ese cuadro era el segundo de la carga: se quedaba en pantalla el negro con el icono a 1/8. Ahora el cambio espera
// kStartHold cuadros de la UI (uno en negro y ocho de fundido del icono; w3d_fe_hold_mode_start, que mira
// codex_flags_8006ee18 antes de su comprobación, sin consumir nada), como mucho 0,6 s. Mientras, la UI tapa el mando
// (w3d_ui_pad). Retener el mensaje no sirve: el juego cambia de modo igual. W3D_START_HOLD=0 (debug.ini) lo quita.
static const int kStartHold = 11;
static double g_start_at;      // cuándo se vio GameLogic.StartGame
static double mono_seconds() { struct timespec ts; clock_gettime(CLOCK_MONOTONIC, &ts); return ts.tv_sec + ts.tv_nsec * 1e-9; }
static bool g_ids;
static volatile int g_hide_press_start;

// UI runs inside the render pass. Scene-changing commands must wait until PADRead,
// before the next update, so the renderer never traverses a destroyed popup.
static char g_pending_commands[32][512];
static unsigned g_pending_count;
void w3d_fe_run(const char *commands) {
    if (!commands || !*commands) return;
    if (g_pending_count >= 32 || strlen(commands) >= sizeof g_pending_commands[0]) {
        w3d_dbg("[fe] command queue full/oversized: %s\n", commands); return;
    }
    snprintf(g_pending_commands[g_pending_count++], sizeof g_pending_commands[0], "%s", commands);
}
// Acciones del teclado pedidas por la UI (en el render): se hacen en PADRead, como las órdenes.
static int g_kb_actions[64]; static unsigned g_kb_count;
static Ptr32<char> g_kb;
static char g_kb_initial[64];      // el texto con que se abrió (ver w3d_kb_open)
static w3d_u32 g_kb_initial_of;
// GWMP8P 0x802c4a60 (auto_802bd360.c): fija +0x16c si el valor no es cero. Igual, y apunta el teclado.
void A802c4a60(Ptr32<char> self, int value) { g_kb = self; g_kb_initial_of = 0; if (value) *(int *)(self.get() + 0x16c) = value; }
static char *kb_object() { return g_kb ? g_kb.get() : nullptr; }
// Al aceptar o cancelar el juego libera el teclado (su +80 no vuelve a 0): la UI lo olvida entonces, y también al salir
// del menú en el que se abrió.
void w3d_kb_forget(void) { g_kb = Ptr32<char>((char *)nullptr); g_kb_count = 0; g_kb_initial_of = 0; }
int w3d_kb_selected(void) { char *k = kb_object(); return k ? *(int *)(k + 64) : -1; }
// Aceptar el teclado con el texto vacío tira el juego (2026-11-07, probado también con su propia tecla de borrar:
// validation/c9_orig, señal 10/11 en el recorrido de la escena, un nodo sin manejador). Nunca se le deja: al aceptar
// vacío, el teclado recupera el texto con que se abrió (el nombre que proponía el juego, o el de antes) y entonces acepta.
static const char *kb_text_now(char *k) { const Ptr32<char> &t = *(const Ptr32<char> *)(k + 256); return t ? t.get() : ""; }
static void kb_remember(char *k) {   // la primera vez que se ve abierto
    if (!k || g_kb_initial_of == g_kb.v) return;
    g_kb_initial_of = g_kb.v;
    snprintf(g_kb_initial, sizeof g_kb_initial, "%s", kb_text_now(k));
}
int w3d_kb_open(void) {
    char *k = kb_object();
    const int open = k && *(int *)(k + 80) ? 1 : 0;
    if (open) kb_remember(k);
    return open;
}
int w3d_kb_empty(void) { char *k = kb_object(); return k && *(int *)(k + 80) && !*kb_text_now(k); }
const char *w3d_kb_text(int *cursor) {
    char *k = kb_object(); if (!k) return nullptr;
    if (cursor) *cursor = *(int *)(k + 264);
    const Ptr32<char> &t = *(const Ptr32<char> *)(k + 256);
    return t ? t.get() : "";
}
// ch > 0: escribir ese carácter; <= -100: pulsar la tecla número -100 - ch (0-29 letras, 30 espacio, 31 borrar,
// 32 cursor izquierda, 33 mayúsculas, 34 aceptar, 35 cursor derecha), como la pulsa el jugador; -31, -32, -34, -35: borrar, cursor izquierda, aceptar, cursor derecha.
// 0: vaciar el texto; -1: si está vacío, el texto con que se abrió (va delante de cada aceptar).
void w3d_kb_action(int ch) {
    if (g_kb_count < 63 && (ch == -134 || ch == -34)) g_kb_actions[g_kb_count++] = -1;
    if (g_kb_count < 64) g_kb_actions[g_kb_count++] = ch;
}
static void kb_refill(char *k) {
    if (*kb_text_now(k) || !g_kb_initial[0]) return;
    ScopedString s(g_kb_initial);
    ((GameString *)(k + 256))->assign(s);
    *(int *)(k + 264) = (int)strlen(g_kb_initial);
    A802c4744(Ptr32<char>(k));
    A802c4998(Ptr32<char>(k));
}
// pad_read (antes de que el juego vea el mando): A sobre la tecla de aceptar con el texto vacío no le llega; se recupera
// el texto y se acepta desde aquí, y A sigue tapada hasta que se suelta. Devuelve si hay que taparla.
int w3d_kb_guard_accept(int a_held) {
    static bool eating;
    if (!a_held) { eating = false; return 0; }
    if (eating) return 1;
    char *k = kb_object();
    if (!k || !*(int *)(k + 80) || *(int *)(k + 64) != 34 || *kb_text_now(k)) return 0;
    eating = true;
    w3d_kb_action(-134);
    return 1;
}
// Vaciar el texto del teclado abierto (Equipo nuevo: la caja empieza vacía, el dueño 2026-11-07), sin pulsar teclas (cada
// borrado suena): el texto (+256) recibe la cadena vacía del juego con su recuento, el cursor (+264) vuelve a 0 y el
// recuadro se rehace como tras un borrado (d28l_keyboard_press_selected_802c40b4, tecla 31).
void w3d_kb_clear(void) { w3d_kb_action(0); }
static void kb_clear(char *k) {
    static GameString empty;
    if (!empty.text) A8020bb54(&empty, "");
    ((GameString *)(k + 256))->assign(empty);
    *(int *)(k + 264) = 0;
    A802c4744(Ptr32<char>(k));
    A802c4998(Ptr32<char>(k));
}
// Dos pantallas (dueño, 2026-11-06): la ventana del teclado (+88, 428x250 en el centro) baja a la pantalla de abajo y el
// recuadro del texto (+84, arriba en y = 150) queda en el centro de la de arriba. Las teclas cuelgan de la ventana.
static Ptr32<char> g_kb_placed;
extern "C" float w3d_kb_scale(void) { return 1.2f; }
static void kb_place(char *k) {
    if (!k || g_kb_placed.v == g_kb.v || !w3d_fe_native_layout()) return;
    Ptr32<char> field = *(Ptr32<char> *)(k + 84), window = *(Ptr32<char> *)(k + 88);
    if (!field || !window) return;
    g_kb_placed = g_kb;
    A802b3020(field, KbVec(0, 0, 0));
    A802b3020(window, KbVec(0, -2 * 120 / .475f, 0));
    // v42 (el dueño: «el teclado al escribir debería ser más grande, un 20 %»): el nodo de la ventana (su oyente, +28,
    // al que la vista manda la posición por +76) se escala por +84; las teclas cuelgan de él y crecen con ella, alrededor
    // del centro de la ventana. 428x250 unidades pasan a 514x300 (244x143 px). Los toques: keyboard_page (ui_pages.cpp).
    const Ptr32<char> node = *(const Ptr32<char> *)(window.get() + 28);
    if (node) { struct { float x, y, z; } v = {w3d_kb_scale(), w3d_kb_scale(), 1}; call_virtual<void>(node.get(), 84, &v, 0); }
}
static void kb_flush(void) {
    char *k = kb_object();
    kb_place(k);
    for (unsigned i = 0; i < g_kb_count && k; ++i) {
        const int a = g_kb_actions[i];
        if (a == 0) kb_clear(k);
        else if (a == -1) kb_refill(k);
        else if (a > 0) A802c4a7c(Ptr32<char>(k), a);
        else if (a <= -100) { *(int *)(k + 64) = -100 - a; A802c40b4(Ptr32<char>(k)); if (a == -134) { w3d_kb_forget(); break; } }
        else { *(int *)(k + 64) = -a; A802c40b4(Ptr32<char>(k)); if (a == -34) { w3d_kb_forget(); break; } }
    }
    g_kb_count = 0;
}
// --- Música del menú desde el título (el dueño, 2026-11-07: «se hace fade in el menú del inicio y arranca la música,
// desde el inicio», y al pulsar START «la música no se corta») ---
// El título pone su propia música (Coconut.Intro, la cantada) al entrar: la arranca su panel (el manejador
// d27i_panel_fade_message_8011ddb0 y su arranque 8011e4fc), desde el principio y a la vez que su animación. Al pulsar
// START el panel la fundía en 200 ms y el menú principal se quedaba sin música: su dueño (la pantalla del menú,
// e12d_select_music_802644a8) solo arranca una pista cuando FE.PlayMusic cambia de modo, y al arrancar ya está en Normal.
// Ahora, en el título (modo 5), el panel no la funde: se la da a la UI (w3d_fe_title_keep), y la versión de FE.PlayMusic
// de aquí abajo se la da al menú cuando pide Normal o Vocal: sigue sonando, sin volver a empezar. Si pide otra (Credits) o
// ninguna (al empezar una partida), se funde como en el original; al empezar una partida (modo 7) también. Y si el menú
// pide su música y no suena ninguna, la arranca aunque el modo no cambie.
// Antes (tanda 27) la UI ponía además su pista (Coconut.Instrum) al entrar el título: eran dos músicas a la vez, el sistema
// de streams dejaba muda la segunda, y en 3DS el menú adoptaba la muda (Azahar, /tmp/w3d-az/mus_fix).
// Servicio de audio del juego (app+0x6c): crear +0x5c, fundir +0x64; pista: soltar +0x10, empezar +0x14, sonando +0x24.
extern "C" const char A803caf0c[], A803cb288[], A803cb298[], A803cb2a0[], A803cb2b0[], A803cb2b8[];   // Normal, Coconut.Instrum, Vocal, Coconut.Intro, Credits, WormSong
extern "C" int A802ef074(Ptr32<const char> a, Ptr32<const char> b);   // la comparación de textos del juego
static Ptr32<char> g_title_music{(char *)nullptr};   // la música del título, mientras no sea del menú
static bool g_title_own;   // v32: g_title_music la puso la UI porque la del panel no sonaba (music_watchdog)
static char *audio_service() {
    if (!A804b1788) return nullptr;
    const w3d_u32 a = *(const w3d_u32 *)((const char *)A804b1788.get() + 0x6c);
    return a ? (char *)g2h(a) : nullptr;
}
// La UI avisa al entrar el título (ui_core.cpp, kToTitle). La música ya la pone el propio título: nada que hacer.
void w3d_fe_title_music(void) {}
static void title_music_fade(unsigned ms) {
    char *audio = audio_service();
    if (!audio || !g_title_music) return;
    call_virtual<void>(audio, 0x64, &g_title_music, ms);
    g_title_music = Ptr32<char>((char *)nullptr);
}
// El panel del título va a fundir su música (id: la pista): en el título se la queda la UI para el menú. 1 si se la quedó.
int w3d_fe_title_keep(Ptr32<int> id) {
    if (g_mode != 5 || !id || !*id) return 0;
    // v32: si la música que suena es la que puso la UI, el panel funde la suya (muda) y la de la UI sigue.
    if (g_title_own && g_title_music) { w3d_dbg("[fe] la música del título (de la UI) sigue en el menú\n"); return 0; }
    title_music_fade(200);   // (no debería haber otra)
    g_title_music = Ptr32<char>((char *)g2h((w3d_u32)*id));
    *id = 0;   // el panel ya no la toca: la referencia pasa a la UI
    w3d_dbg("[fe] la música del título sigue en el menú\n");
    return 1;
}
// Alto del panel negro del fundido del título (Particle_Intro_WhiteoutBlend; lo crea su arranque 8011e4fc con 800x600,
// en el centro, y d27i_panel_update_8011e0fc le cambia el alfa). Con dos pantallas la escena del título sigue en el lienzo
// alto, y el borde de abajo del panel caía a 165 px de la pantalla de abajo: la franja de debajo entraba sin fundido, más
// clara que el resto (el dueño, 2026-11-07: «que el fundido en negro del inicio sea de las dos pantallas»). Con 1600 llega
// hasta abajo con margen. 0: el tamaño del original.
int w3d_fe_title_fade_h(void) { return w3d_fe_native_layout() ? 1600 : 0; }
// La pantalla del frontend (d40k_frontend_messages_80260f64) que pide la música: es la dueña de la pista del menú. Vale
// mientras dura el frontend (modo 6); al salir se olvida (w3d_fe_mode_started).
static Ptr32<char> g_music_owner{(char *)nullptr};
// Las pistas del menú (Coconut.Intro y Coconut.Instrum, 146 s) no se repiten solas: al acabar, el menú se quedaba en
// silencio (Azahar, /tmp/w3d-az/mus_largo). En el frontend, si la pista de su dueña ha terminado, vuelve a empezar.
static void menu_music_loop(void) {
    if (g_mode != 6 || !g_music_owner) return;
    char *o = g_music_owner.get();
    const int owner_mode = *(int *)(o + 0xd0);
    Ptr32<char> &owner_music = *(Ptr32<char> *)(o + 0xc8);
    if (!owner_music || call_virtual<int>(owner_music.get(), 0x24)) return;   // sin pista, o sonando
    const char *track = owner_mode == 0 ? A803cb288 : owner_mode == 1 ? A803cb2a0 : owner_mode == 2 ? A803cb2b8 : nullptr;
    char *audio = audio_service();
    if (!audio || !track) return;
    call_virtual<void>(owner_music.get(), 0x10);
    owner_music = Ptr32<char>((char *)nullptr);
    call_virtual<void>(audio, 0x5c, track, &owner_music);
    if (owner_music) call_virtual<void>(owner_music.get(), 0x14);
    w3d_dbg("[fe] la música del menú vuelve a empezar\n");
}
// GWMP8P 0x802644a8, el mismo cuerpo (e12d_select_music_802644a8_v0.cpp) con el traspaso de la música del título.
void A802644a8(Ptr32<char> self, Ptr32<const char> mode) {
    g_music_owner = self;
    char *o = self.get();
    int &owner_mode = *(int *)(o + 0xd0);
    Ptr32<char> &owner_music = *(Ptr32<char> *)(o + 0xc8);
    const int old_mode = owner_mode;
    owner_mode = 3;
    const char *track = nullptr;
    if (!A802ef074(mode, A803caf0c)) { track = A803cb288; owner_mode = 0; }
    else if (!A802ef074(mode, A803cb298)) { track = A803cb2a0; owner_mode = 1; }
    else if (!A802ef074(mode, A803cb2b0)) { track = A803cb2b8; owner_mode = 2; }
    w3d_dbg("[fe] FE.PlayMusic %s en el modo %d (música del título %s)\n", mode ? mode.get() : "-", g_mode, g_title_music ? "sonando" : "no");
    if (g_title_music) {
        if ((track == A803cb288 || track == A803cb2a0) && !owner_music) { owner_music = g_title_music; g_title_music = Ptr32<char>((char *)nullptr); return; }
        title_music_fade(track ? 2000 : 200);
    }
    if (old_mode == owner_mode && (owner_music || !track)) return;
    char *audio = audio_service();
    if (!audio) return;
    if (owner_music) {
        if (call_virtual<int>(owner_music.get(), 0x24)) call_virtual<void>(audio, 0x64, &owner_music, track ? 2000u : 200u);
        else { call_virtual<void>(owner_music.get(), 0x10); owner_music = Ptr32<char>((char *)nullptr); }
    }
    if (track) {
        call_virtual<void>(audio, 0x5c, track, &owner_music);
        if (owner_music) call_virtual<void>(owner_music.get(), 0x14);
    }
}
// v32 (el dueño, 2026-11-07: «no suena la música al abrir el juego»): en la consola la pista del título se pedía pero su
// stream no llegaba a abrirse (ni un «[dvd] abre ...Coconuts» en el registro; en Azahar depende del tiempo: con el
// depurador tampoco sonaba). El juego la daba por sonando y el menú la adoptaba muda. Ahora, en el título y el menú, si
// el mezclador no tiene ningún stream activo durante unos segundos, la música se vuelve a pedir (hasta 4 veces por modo).
extern "C" int w3d_stream_active_count(void);
static void music_watchdog(void) {
    static int silent, tries, last_mode = -1;
    if (g_mode != last_mode) { last_mode = g_mode; silent = 0; tries = 0; }
    if (g_mode != 5 && g_mode != 6) return;
    if (w3d_stream_active_count() > 0) { silent = 0; return; }
    if (++silent < (g_mode == 5 ? 150 : 90) || tries >= 4) return;   // unos 5 s en el título y 3 s en el menú
    silent = 0; tries++;
    char *audio = audio_service();
    if (!audio) return;
    if (g_mode == 5) {
        if (g_title_music) { call_virtual<void>(g_title_music.get(), 0x10); g_title_music = Ptr32<char>((char *)nullptr); }
        call_virtual<void>(audio, 0x5c, A803cb2a0, &g_title_music);   // Coconut.Intro, la del título
        if (g_title_music) call_virtual<void>(g_title_music.get(), 0x14);
        g_title_own = g_title_music;
        w3d_dbg("[fe] el título sigue sin música: la pide la UI (intento %d)\n", tries);
    } else {
        Ptr32<char> *slot = g_title_music ? &g_title_music : g_music_owner ? (Ptr32<char> *)(g_music_owner.get() + 0xc8) : nullptr;
        if (!slot) return;
        const int owner_mode = g_music_owner ? *(int *)(g_music_owner.get() + 0xd0) : 0;
        const char *track = owner_mode == 0 ? A803cb288 : owner_mode == 1 ? A803cb2a0 : owner_mode == 2 ? A803cb2b8 : nullptr;
        if (!track) return;
        if (*slot) { call_virtual<void>(slot->get(), 0x10); *slot = Ptr32<char>((char *)nullptr); }
        call_virtual<void>(audio, 0x5c, track, slot);
        if (*slot) call_virtual<void>(slot->get(), 0x14);
        w3d_dbg("[fe] el menú sigue sin música: se vuelve a pedir (intento %d)\n", tries);
    }
}
void w3d_fe_wormpot_flush(void);
void w3d_fe_flush_commands(void) {
    kb_flush();
    menu_music_loop();
    music_watchdog();
    const unsigned count = g_pending_count;
    g_pending_count = 0;
    for (unsigned i = 0; i < count; ++i) {
        w3d_dbg("[fe] orden: %s\n", g_pending_commands[i]);
        A802b1258(g_pending_commands[i]);
    }
    w3d_fe_wormpot_flush();
}
void w3d_fe_runf(const char *fmt, const char *arg) {
    char b[160]; snprintf(b, sizeof b, fmt, arg); w3d_fe_run(b);
}
int w3d_fe_prop_int(const char *name, int def) {
    Ptr32<const char> key(name); int v = def;
    ((w3d_u32 (*)(void *, void *))A800fc1f0)(&key, &v);
    return v;
}
unsigned w3d_fe_prop_uint(const char *name, unsigned def) {
    Ptr32<const char> key(name); w3d_u32 v = def;
    ((w3d_u32 (*)(void *, void *))A800fc230)(&key, &v);
    return v;
}
const char *w3d_fe_prop_str(const char *name) {
    Ptr32<const char> key(name); Ptr32<const char> out{(const char *)nullptr};
    ((w3d_u32 (*)(void *, void *))A800fc2b0)(&key, &out);
    return out ? out.get() : nullptr;
}
float w3d_fe_prop_float(const char *name, float def) { Ptr32<const char> key(name); A800fc270(&key,&def); return def; }
void w3d_fe_set_float(const char *name, float v) { Ptr32<const char> key(name); A800fc4c8(v,&key); }
void w3d_fe_set_int(const char *name, int v) { Ptr32<const char> key(name); A800fc3b0(&key, v); }
void w3d_fe_set_uint(const char *name, unsigned v) { Ptr32<const char> key(name); A800fc43c(&key, v); }
// El texto tiene que estar en la memoria del juego: se hace una cadena del juego (como command_line.cpp) y se le pasa
// su contenido; con una cadena del ejecutable el juego quedaba con un puntero malo y fallaba al rato.
void w3d_fe_set_str(const char *name, const char *v) {
    ScopedString value(v ? v : "");
    Ptr32<const char> key(name); A800fc550(&key, value.text.get());
}
int w3d_fe_popup_depth(void) { return A804abb5c; }
int w3d_fe_game_mode(void) { return g_mode; }
int w3d_fe_game_start_seen(void) { return g_start_pending != 0; }   // sin contar (pruebas: diag.cpp)
// La UI lo pregunta una vez por cuadro. Si a los 90 cuadros el modo no ha cambiado (la partida no llegó a empezar), se olvida.
int w3d_fe_game_starting(void) {
    if (g_start_pending && ++g_start_pending > 90) { g_start_pending = 0; w3d_dbg("[fe] GameLogic.StartGame sin cambio de modo: se olvida\n"); }
    return g_start_pending != 0;
}
// 1 mientras el cambio al modo de partida espera al fundido del icono de carga (kStartHold).
static bool ui_target();
int w3d_fe_hold_mode_start(void) {
    static int hold = -1;
    if (hold < 0) { const char *e = getenv("W3D_START_HOLD"); hold = e ? atoi(e) : kStartHold; }
    if (!hold || !g_start_pending || g_mode != 6 || !ui_target()) return 0;
    if (g_start_pending < hold && mono_seconds() - g_start_at < 0.6) return 1;
    return 0;
}
int w3d_fe_start_holding(void) { return w3d_fe_hold_mode_start(); }
const char *w3d_fe_highlighted(void) { return g_highlight[0] ? g_highlight : nullptr; }
// The table builder is authoritative, including internally queued brief/result
// pages. Keep names by native depth so closing a child restores its parent.
void w3d_fe_building_menu(const char *name) {
    if(!name) return;
    snprintf(g_layout_menu,sizeof g_layout_menu,"%s",name);
    const int depth=A804abb5c;
    if(depth>=0 && depth<32) {
        for(int i=depth;i<32;++i) g_popup_names[i][0]=0;
        if(depth) snprintf(g_popup_names[depth],sizeof g_popup_names[depth],"%s",name);
        else g_last_popup[0]=0;
    }
    if(getenv("W3D_UI_REVIEW_LOG")) w3d_dbg("[fe] construye %s profundidad %d\n",name,depth);
}
const char *w3d_fe_last_popup(void) {
    for(int d=A804abb5c<32?A804abb5c:31;d>0;--d)
        if(g_popup_names[d][0]) return g_popup_names[d];
    return A804abb5c>0 && g_last_popup[0] ? g_last_popup : nullptr;
}
void w3d_fe_highlight(const char *item) { w3d_fe_runf("FE.HighlightItem$%s", item); }
void w3d_fe_activate(const char *item) { w3d_fe_runf("Input.Menu.ForceSelect$%s", item); }
// Sí/No de un diálogo de confirmación: sus dos botones se llaman Accept y Cancel en todos.
void w3d_fe_confirm(int yes) { w3d_fe_activate(yes ? "Accept" : "Cancel"); }
// Texto traducido de una clave del idioma cargado (FE.Tip.Sure, Lang.Options...). nullptr si no está.
const char *w3d_fe_text(const char *key) {
    const char *t = w3d_fe_prop_str(key);
    return t && *t ? t : nullptr;
}

// Título original: la pantalla de abajo dice "Press START", así que arriba el rótulo no se enciende (d27i_panel_update).
int w3d_fe_title_hide_press(void) { return g_hide_press_start; }
void w3d_fe_title_set_hide_press(int on) { g_hide_press_start = on; }

// d24g_mode_start_8006af38, al empezar cada modo del flujo de la aplicación.
// flow_flags: banderas del objeto de flujo (+240). El bit 31 es el bucle de demostración: con el juego quieto en el título
// o en el menú principal pasaba a la demo (pedido del dueño, v28: que no pase). Se apaga en cada modo, como /NOAUTOLOOP.
// En 3DS y en el Mac de dos pantallas (W3D_DUAL=1, donde se prueba la UI de 3DS); el Mac normal queda como el original.
static bool ui_target() {
#if defined(__3DS__)
    return true;
#else
    static const bool dual = getenv("W3D_DUAL") != nullptr;
    return dual;
#endif
}
void w3d_fe_mode_started(int mode, unsigned *flow_flags) {
    if (mode != g_mode) { w3d_dbg("[fe] modo %d%s\n", mode, g_start_pending ? " (tras la espera del fundido de la carga)" : ""); g_start_pending = 0; }
    g_mode = mode;
    if (mode == 7) title_music_fade(200);   // una partida: la música del título, si aún es de la UI, se va
    if (mode != 6) g_music_owner = Ptr32<char>((char *)nullptr);   // fuera del frontend su pantalla puede no existir
    if (ui_target() && flow_flags && (*flow_flags & 0x80000000u) && !getenv("W3D_DEMO")) { *flow_flags &= 0x7fffffffu; w3d_dbg("[fe] sin demostración por inactividad\n"); }
    if (ui_target() && mode == 0 && !getenv("W3D_PELICULAS") && A804b1788) {
        w3d_u32 before = A804b1788->flags;
        A804b1788->flags = before & ~0x80u;
        w3d_dbg("[fe] sin películas de logos: app+0xbc %08x -> %08x\n", (unsigned)before, (unsigned)A804b1788->flags);
    }
}

// Espía de mensajes (message_registry.cpp): solo compara el id, una vez por mensaje.
static void ids() {
    if (g_ids) return;
    g_ids = true;
    unsigned short id;
    if (!find_id("FE.HighlightItem", &id)) g_id_highlight = id;
    if (!find_id("FE.CreatePopUp", &id)) g_id_popup = id;
    if (!find_id("FE.CreatePopUpLight", &id)) g_id_popup_light = id;
    if (!find_id("FE.CreatePopUpClear", &id)) g_id_popup_clear = id;
    if (!find_id("FE.ChangeMenu", &id)) g_id_change = id;
    if (!find_id("GameLogic.StartGame", &id)) g_id_start = id;
    w3d_dbg("[fe] ids HighlightItem %04x CreatePopUp %04x ChangeMenu %04x\n", g_id_highlight, g_id_popup, g_id_change);
}
// Devuelve 1 si el mensaje no se entrega (ahora ninguno: la espera de la carga va en w3d_fe_hold_mode_start).
int w3d_fe_spy(Ptr32<void> message) {
    if (!message) return 0;
    unsigned short id = *(unsigned short *)message.get();
    if (!g_ids) { if (g_mode < 0) return 0; ids(); }
    if (id == g_id_start && g_mode == 6) {
        if (!g_start_pending) { w3d_dbg("[fe] GameLogic.StartGame\n"); g_start_at = mono_seconds(); g_start_pending = 1; }
        return 0;
    }
    if (id != g_id_highlight && id != g_id_popup && id != g_id_popup_light && id != g_id_popup_clear && id != g_id_change) return 0;
    w3d_u32 t = *(const w3d_u32 *)((const char *)message.get() + 8);   // texto de un mensaje de texto (w3d_get_8010a8fc)
    const char *s = t ? (const char *)g2h(t) : nullptr;
    if (!s) return 0;
    if (id == g_id_highlight) { strncpy(g_highlight, s, sizeof g_highlight - 1); g_highlight[sizeof g_highlight - 1] = 0; }
    else if (id == g_id_change) { g_highlight[0] = 0; snprintf(g_layout_menu, sizeof g_layout_menu, "%s", s); }
    else { strncpy(g_last_popup, s, sizeof g_last_popup - 1); g_last_popup[sizeof g_last_popup - 1] = 0; snprintf(g_layout_menu, sizeof g_layout_menu, "%s", s); }
    return 0;
}

// Idioma de la consola en FE.LanguageSelect: la misma orden que la bandera (conserva la comprobación de la tarjeta).
// lang: English, French, German, Italian o Spanish.
// v28: el idioma se fija durante el título (FE.SetLanguage: cambia el idioma y SAVE.Language), así el menú del juego no
// llega a montar FE.LanguageSelect. La comprobación de la tarjeta que hacía la bandera (FE.SaveToFile y
// FE.DoMemCardWarning$FE.MainMenu) se manda al llegar al menú principal.
// FE.SetLanguage lo atiende la pantalla del menú (d40k), que en el título aún no existe: se escribe SAVE.Language, que
// application_load_language_80127b48 lee al entrar en el menú (y entonces no mete FE.LanguageSelect). Índices del juego:
// English 0, French 3, German 4, Italian 5, Spanish 9.
void w3d_fe_set_language(const char *lang) {
    static const struct { const char *name; unsigned v; } k[] = {{"English", 0}, {"French", 3}, {"German", 4}, {"Italian", 5}, {"Spanish", 9}};
    for (auto &e : k) if (!strcmp(e.name, lang)) { w3d_fe_set_uint("SAVE.Language", e.v); w3d_dbg("[fe] SAVE.Language = %u (%s)\n", e.v, lang); }
}
void w3d_fe_card_check(void) { w3d_fe_run("FE.SaveToFile\\FE.DoMemCardWarning$FE.MainMenu"); }
void w3d_fe_choose_language(const char *lang) {
    char b[160];
    snprintf(b, sizeof b, "FE.SetLanguage$%s\\FE.SaveToFile\\FE.DoMemCardWarning$FE.MainMenu", lang);
    w3d_fe_run(b);
}

// Filas de una tabla del FE (FE.Barracks, FE.TeamsInLocalGame, FE.SchemeList, FE.MultiLevels, FE.WormsList...): la
// lista que muestra un ListControl o un combo. El objeto del recurso guarda en +28 el vector con la clave de cada fila
// (la que sustituye a '@' en la orden del control: nombre de equipo, de esquema, de mapa); cabecera del vector: número
// en +24 y punteros a texto desde +32 (d30i_barracks_team_list_fill_80114a2c). Copia hasta max filas en out (64 bytes
// cada una) y devuelve cuántas hay, o -1 si la tabla no existe.
int w3d_fe_table(const char *name, char (*out)[64], int max) {
    Ptr32<const char> key(name);
    Ptr32<void> res{(void *)nullptr};
    if ((int)((w3d_u32 (*)(void *, void *))A800fc1b0)(&key, &res) < 0 || !res) return -1;
    int n = -1;
    const w3d_u32 obj = A801797b4(res.get());
    if (obj) {
        const w3d_u32 vec = *(const w3d_u32 *)((const char *)g2h(obj) + 28);
        if (vec) {
            const char *h = (const char *)g2h(vec);
            int count = *(const int *)(h + 24);
            if (count >= 0 && count < 4096) {
                n = count;
                for (int i = 0; i < count && i < max; i++) {
                    const w3d_u32 t = *(const w3d_u32 *)(h + 32 + 4 * i);
                    const char *str = t ? (const char *)g2h(t) : "";
                    strncpy(out[i], str, 63); out[i][63] = 0;
                }
            }
        }
    }
    release_if_set(res.get());
    return n;
}

// Equipos del cuartel (DATA.TeamBarracks): lista en +24 del objeto, con el número en +24 y los equipos desde +32. Cada
// equipo: +28 bandera (texto), +36 lápida, +40 nivel (0 humano, 1..5 CPU), +60 nombre
// (d30f_create_team_from_properties_8029c4d0, d27f_select_barracks_team_80297620). El equipo se copia a la partida al
// añadirlo (d30f_add_team_to_local_game_8029a5b4): para cambiar el nivel de uno ya añadido hay que quitarlo y volver a
// añadirlo.
static const char *g2s(w3d_u32 a) { return a ? (const char *)g2h(a) : ""; }
static char *barracks_team(const char *team_name, int index, char *out_name) {
    Ptr32<const char> key("DATA.TeamBarracks");
    Ptr32<void> res{(void *)nullptr};
    if ((int)((w3d_u32 (*)(void *, void *))A800fc1b0)(&key, &res) < 0 || !res) return nullptr;
    char *found = nullptr;
    const w3d_u32 obj = A801797b4(res.get());
    if (obj) {
        const w3d_u32 list = *(const w3d_u32 *)((const char *)g2h(obj) + 24);
        if (list) {
            const char *l = (const char *)g2h(list);
            const unsigned count = *(const unsigned *)(l + 24);
            for (unsigned i = 0; i < count && i < 64; i++) {
                const w3d_u32 t = *(const w3d_u32 *)(l + 32 + 4 * i);
                if (!t) continue;
                char *team = (char *)g2h(t);
                const char *nm = g2s(*(const w3d_u32 *)(team + 60));
                if ((team_name && !strcmp(nm, team_name)) || (!team_name && (int)i == index)) {
                    if (out_name) { strncpy(out_name, nm, 63); out_name[63] = 0; }
                    found = team; break;
                }
            }
        }
    }
    release_if_set(res.get());   // el cuartel vive en la base de datos: el puntero sigue valiendo
    return found;
}
int w3d_fe_team_skill(const char *team) { char *t = barracks_team(team, 0, nullptr); return t ? *(int *)(t + 40) : -1; }
// Los seis nombres de un equipo: +56 la referencia a su lista de textos (d30f_create_team_from_properties_8029c4d0); la
// lista, de tipo 1 (en línea), con el número en +24 y los textos desde +32. Otro tipo no se lee (nullptr).
const char *w3d_fe_team_worm(const char *team, int i) {
    char *t = barracks_team(team, 0, nullptr);
    if (!t || i < 0 || i > 5) return nullptr;
    const w3d_u32 list = *(const w3d_u32 *)(t + 56);
    if (!list) return nullptr;
    const char *l = (const char *)g2h(list);
    if (*(const unsigned short *)(l + 4) != 1 || *(const unsigned *)(l + 24) <= (unsigned)i) return nullptr;
    return g2s(*(const w3d_u32 *)(l + 32 + 4 * i));
}
const char *w3d_fe_team_flag(const char *team) { char *t = barracks_team(team, 0, nullptr); return t ? g2s(*(const w3d_u32 *)(t + 28)) : nullptr; }
void w3d_fe_team_set_skill(const char *team, int skill) {
    char *t = barracks_team(team, 0, nullptr);
    if (!t) return;
    *(int *)(t + 40) = skill;
    w3d_dbg("[fe] equipo %s nivel %d\n", team, skill);
}
}
