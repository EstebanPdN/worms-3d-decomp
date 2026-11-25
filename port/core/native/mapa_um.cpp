// Mapas de Worms Ultimate Mayhem en la partida rápida (v26-v27, port; no está en el original).
// Convertidos por mods/mapas-um/tools: paisaje de UM con su terreno de alturas horneado en bloques de W3D, sus
// materiales y las texturas de su tema. Sin decorados: los de UM no existen en W3D. Informe: docs/mapas-ultimate-mayhem.md.
//
// - Lista de mapas y texturas: mapas_um_lista.inc (generada por mods/mapas-um/tools; nombre en pantalla, archivos,
//   tema y hora de W3D para el cielo, el agua y la música; texturas con su bundle).
// - Datos (v27): Maps/<mapa>.xom, Maps/<mapa>.txt y los bundles de texturas Bundles/BundleNN.xom van en el paquete
//   mapas-um.worms. En 3DS está en el romfs del CIA (platform/3ds/vfs_3ds.cpp lo monta), que se lee del disco: en la
//   v26 iban dentro del ejecutable (0,95 MB fuera del montón, que en la consola va casi lleno). En Mac, W3D_MODS.
// - w3d_mapa_um_register (al final de cx12a_register_catalogs_80127544) da de alta las texturas en la tabla de imágenes
//   (la de 0x803f7a6c: fila de 20 bytes, sección 4, flags 0x0001 0x0001 0x00a0 como las texturas de los temas) y los
//   bundles como el bucle del original hace con 0x00-0x58.
// - Selector: w3d_mapa_um_get/set (0 el mapa original de la partida rápida; k el mapa k de la lista). Lo cambia el menú
//   MAPA de la pantalla de abajo (3DS, platform/3ds/diag.cpp); W3D_MAPA_UM=<k> en debug.ini o en el entorno.
// - Con un mapa de UM elegido, la partida rápida (d32f, modo QuickStart) va siempre a la entrada "FE.Unlocked.Pegasus" en
//   lugar de la sorteada. La partida rápida sortea entre entradas de desbloqueo (FE.Unlocked.<nivel>), no nombres de
//   nivel, y Pegasus está siempre desbloqueado (con una partida guardada nueva solo salen Pegasus, Please, Submission y
//   Driving). Ese mismo nombre llega a d21a_level_load en Game.NextLevel, y ahí se cambian Land.File, Land.Materials,
//   el tema y la hora por los del mapa. Cualquier otro modo de juego borra la marca (w3d_mapa_um_modo), así que Pegasus
//   elegido a mano en multijugador sigue siendo Pegasus.
// - Los textos que recibe el juego son cadenas String del juego, hechas una vez con A8020bb54 (cabecera con referencias
//   en -6 y longitud en -4): el juego suma y resta referencias a lo que se le pasa, y con una cadena C cualquiera
//   corrompía el montón al liberarla (prueba de Mac del 2026-11-05).
#include "w3d_ptr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef W3D_PUBLIC
#include "../../platform/platform.h"
#endif

#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))

extern "C" void w3d_dbg(const char *, ...);
extern "C" void A8020bb54(void *string, const char *text);   // String del juego a partir de un texto (copia)

namespace {
struct MapaUM { const char *nombre, *xom, *txt, *tema, *hora; };
struct TexturaUM { const char *nombre; unsigned char bundle; };
#include "mapas_um_lista.inc"
const int kMapas = (int)(sizeof kMapasUM / sizeof kMapasUM[0]);
const int kTex = (int)(sizeof kTexturasUM / sizeof kTexturasUM[0]);
const int kBundles = (int)(sizeof kBundlesUM / sizeof kBundlesUM[0]);

// Niveles de W3D de la partida rápida (v29, prueba automática): las 34 entradas FE.Unlocked.<nivel> del juego. La
// partida rápida sortea solo entre las desbloqueadas, pero cualquiera carga si se manda por su nombre.
// w3d_nivel_set(i) (test_3ds.cpp) o W3D_NIVEL=<nombre> (Mac, pruebas) fuerzan una; -1 ninguna.
const char *const kNiveles[] = {
    "Alien", "Apple", "Atlantis", "Chateau", "Cherry", "Collide", "Cooped", "Counting", "CrateBritain", "Cratefun",
    "Crop", "Crust", "DDay", "Driving", "Funfair", "Graveyard", "Helter", "High", "Holiday", "Ice", "Kong", "Landing",
    "Leek", "Pegasus", "Plaice", "Please", "Ragna", "Schools", "Showdown", "Submission", "Timbers", "Tree", "Tubes",
};
const int kNumNiveles = (int)(sizeof kNiveles / sizeof kNiveles[0]);
int g_nivel = -2;                     // -2 sin leer W3D_NIVEL; -1 ninguno; i el nivel i de kNiveles
char g_nivel_txt[40];
const char kEntrada[] = "FE.Unlocked.Pegasus";   // lo que manda la partida rápida (FE.SetLevel) y llega a d21a (Game.NextLevel)
int g_sel = -1;                       // 0 original, k el mapa k; -1 sin leer W3D_MAPA_UM
#ifdef W3D_PUBLIC
int g_available;
#else
constexpr int g_available = kMapas;
#endif
int g_pend;                           // mapa de la partida rápida en curso (0: ninguno)

int sel() {
    if (g_sel < 0) {
        const char *e = getenv("W3D_MAPA_UM");
        int k = e ? atoi(e) : 0;
        g_sel = k >= 1 && k <= g_available ? k : 0;
        if (g_sel) w3d_dbg("[mapa_um] W3D_MAPA_UM: partida rápida con %s\n", kMapasUM[g_sel - 1].nombre);
    }
    return g_sel;
}

// Cadenas String del juego; se hacen la primera vez y no se liberan nunca (una referencia propia).
struct GameText { Ptr32<char> text; };
GameText g_nivel_str[40];
GameText g_entrada, g_tierra[32], g_materiales[32], g_tema[32], g_hora[32];
static_assert(kMapas <= 32, "como mucho 32 mapas");
const char *texto(GameText &t, const char *from) {
    if (!t.text) A8020bb54(&t, from);
    return t.text.get();
}
// El mapa de UM de esta partida rápida si el nivel que llega es la entrada anfitriona.
const MapaUM *toca(const char *level) {
    return g_pend && level && !strcmp(level, kEntrada) ? &kMapasUM[g_pend - 1] : nullptr;
}

// Fila de recurso: nombre, bytes {bundle, sección, 0, 0}, archivo y cuatro u16 (como ResourceRow de hat_militar.cpp).
struct ResourceRow { Ptr32<const char> name; unsigned char bundle, type, pad[2]; Ptr32<const char> file; unsigned short flags, flags_lo, extra[2]; };
static_assert(sizeof(ResourceRow) == 20, "fila de 20 bytes como en 0x803f7a6c");
char g_files[kTex][28];
ResourceRow g_rows[kTex];
}

extern "C" {
int w3d_mapa_um_cuantos(void) { return g_available; }
// Nombre del mapa k (1..kMapas), o "original" con 0.
const char *w3d_mapa_um_nombre_de(int k) { return k >= 1 && k <= kMapas ? kMapasUM[k - 1].nombre : "original"; }
int w3d_mapa_um_get(void) { return sel(); }
void w3d_mapa_um_set(int k) { sel(); g_sel = k >= 1 && k <= g_available ? k : 0; }
const char *w3d_mapa_um_nombre(void) { return w3d_mapa_um_nombre_de(sel()); }

// Ya no hay archivos de mapas dentro del ejecutable: van en mapas-um.worms (v27). w3d_builtin_file (hat_militar.cpp)
// pregunta aquí primero, así que de paso se sirve el bundle del francotirador de UM (Bundles/Bundle95.xom,
// francotirador.cpp) sin tocar hat_militar.cpp.
int w3d_francotirador_file(const char *path, const unsigned char **data, unsigned *size);
int w3d_mapa_um_file(const char *path, const unsigned char **data, unsigned *size) { return w3d_francotirador_file(path, data, size); }

// 1 mientras dura la partida rápida con un mapa de UM (land_theme.cpp quita la lluvia y la nieve del tema anfitrión).
int w3d_mapa_um_activo(void) { return g_pend != 0; }

// Al empezar cualquier modo de juego (d32f_start_game_mode_80281ff0).
void w3d_mapa_um_modo(void) { g_pend = 0; }

int w3d_nivel_cuantos(void) { return kNumNiveles; }
const char *w3d_nivel_nombre(int i) { return i >= 0 && i < kNumNiveles ? kNiveles[i] : "?"; }
static int nivel() {
    if (g_nivel == -2) {
        g_nivel = -1;
        if (const char *e = getenv("W3D_NIVEL"))
            for (int i = 0; i < kNumNiveles; i++) if (!strcmp(e, kNiveles[i])) g_nivel = i;
        if (g_nivel >= 0) w3d_dbg("[nivel] W3D_NIVEL: partida rápida en %s\n", kNiveles[g_nivel]);
    }
    return g_nivel;
}
void w3d_nivel_set(int i) { nivel(); g_nivel = i >= 0 && i < kNumNiveles ? i : -1; }

// Partida rápida: devuelve la entrada anfitriona si hay un mapa de UM elegido, o la del nivel de W3D forzado (v29); si
// no, nullptr (se queda la sorteada).
const char *w3d_mapa_um_partida_rapida(const char *sorteado) {
    if (const int n = nivel(); n >= 0 && !sel()) {
        g_pend = 0;
        snprintf(g_nivel_txt, sizeof g_nivel_txt, "FE.Unlocked.%s", kNiveles[n]);
        w3d_dbg("[nivel] partida rápida: %s (en lugar de %s)\n", g_nivel_txt, sorteado ? sorteado : "?");
        return texto(g_nivel_str[n], g_nivel_txt);
    }
    g_pend = sel();
    if (g_pend) w3d_dbg("[mapa_um] partida rápida: %s (en lugar de %s)\n", kMapasUM[g_pend - 1].nombre, sorteado ? sorteado : "?");
    return g_pend ? texto(g_entrada, kEntrada) : nullptr;
}

// d21a_level_load_8006d610: Land.File, Land.Materials, tema y hora del mapa de UM, o nullptr.
const char *w3d_mapa_um_tierra(const char *level) {
    const MapaUM *m = toca(level);
    if (!m) {
        if (g_pend) w3d_dbg("[mapa_um] el nivel que llega es %s, no %s: se queda el original\n", level ? level : "(nada)", kEntrada);
        return nullptr;
    }
    w3d_dbg("[mapa_um] cargando %s con %s, tema %s, %s\n", m->xom, m->txt, m->tema, m->hora);
    return texto(g_tierra[g_pend - 1], m->xom);
}
const char *w3d_mapa_um_materiales(const char *level) { const MapaUM *m = toca(level); return m ? texto(g_materiales[g_pend - 1], m->txt) : nullptr; }
const char *w3d_mapa_um_tema(const char *level) { const MapaUM *m = toca(level); return m ? texto(g_tema[g_pend - 1], m->tema) : nullptr; }
const char *w3d_mapa_um_hora(const char *level) { const MapaUM *m = toca(level); return m ? texto(g_hora[g_pend - 1], m->hora) : nullptr; }

extern Ptr32<void> A804b17ec;  // mismo global que service_804b17ec de cx12a
void w3d_mapa_um_register(void) {
#ifdef W3D_PUBLIC
    auto has_asset = [](const char *path) {
        auto *file = w3d::plat::file_open(path);
        if (!file) return false;
        w3d::plat::file_close(file);
        return true;
    };
    char path[48];
    for (const auto &map : kMapasUM) {
        snprintf(path, sizeof path, "Maps/%s", map.xom);
        if (!has_asset(path)) return;
        snprintf(path, sizeof path, "Maps/%s", map.txt);
        if (!has_asset(path)) return;
    }
    for (const auto bundle : kBundlesUM) {
        snprintf(path, sizeof path, "Bundles/Bundle%02u.xom", unsigned(bundle));
        if (!has_asset(path)) return;
    }
    g_available = kMapas;
    g_sel = -1;
#endif
    for (int i = 0; i < kTex; i++) {
        snprintf(g_files[i], sizeof g_files[i], "ThemeUM\\%s.tga", kTexturasUM[i].nombre);
        ResourceRow &r = g_rows[i];
        r.name = kTexturasUM[i].nombre; r.bundle = kTexturasUM[i].bundle; r.type = 4; r.file = g_files[i];
        r.flags = 0x0001; r.flags_lo = 0x0001; r.extra[0] = 0x00a0; r.extra[1] = 0;
    }
    Ptr32<void> svc = FIELD(A804b17ec, void *, 0x74);
    VCALL(svc, void (*)(void *, void *, unsigned), 0x24)(svc, g_rows, kTex);
    for (int b = 0; b < kBundles; b++) {
        unsigned char index = kBundlesUM[b];
        svc = FIELD(A804b17ec, void *, 0x74);
        VCALL(svc, void (*)(void *, unsigned char *, int), 0x48)(svc, &index, 0);
        svc = FIELD(A804b17ec, void *, 0x74);
        VCALL(svc, void (*)(void *, unsigned char *, int), 0x54)(svc, &index, 1);
    }
    w3d_dbg("[mapa_um] %d mapas, %d texturas en %d bundles\n", kMapas, kTex, kBundles);
}
}
