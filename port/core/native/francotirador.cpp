// Fusil francotirador de Worms Ultimate Mayhem (hecho en la build separada variantes/francotirador el 2026-11-06; en
// port/ desde el 2026-11-07). Decompilación y datos de UM: mods/armas-um/decomp/francotirador/ (ficha.md,
// codigo_anotado.c). Fontanería de W3D: mods/armas-um/francotirador/plumbing_arma.md; estado: ESTADO.md de esa carpeta.
//
// - Número: 28 (kWeaponMagicBullet), un hueco sin contenedor, texto ni munición en el original. Ya tiene casilla en el
//   panel de armas (fila 0, icono 24).
// - Datos: WeapTwk.xom parcheado (parche 4, entero en memoria) con un GunWeaponPropertiesContainer kWeaponMagicBullet
//   copiado de la escopeta con los valores de UM (mods/armas-um/francotirador/tools/hacer_weaptwk.py ->
//   francotirador_weaptwk.inc). d29d_worm_fire_801496f0 crea con él una GunWeaponLogicEntity (case 28), como UM.
// - Munición: Scripts/stdvs.lua pone "inventory.MagicBullet = 0" en cada partida; el parche 5 lo cambia por 3 balas
//   (W3D_FRANCO_BALAS=<n>, -1 infinito) sin cambiar el tamaño del archivo.
// - Malla: SniperRifle (en la mano), bundle 0x5F = Bundles/Bundle95.xom (solo el fusil: ver w3d_francotirador_register)
//   incrustado (mods/armas-um/francotirador/hacer_bundle_sniper.py -> francotirador_bundle.inc), dados de alta como los
//   gorros (hat_militar.cpp).
// - Texto: textos_es.cpp (Text.kWeaponMagicBullet = «Fusil francotirador» / «Sniper Rifle», y en francés, alemán e
//   italiano el nombre de UM).
// W3D_FRANCOTIRADOR=0 en debug.ini lo apaga entero (el 28 vuelve a no tener munición).
#include "w3d_ptr.h"
#include <stdlib.h>
#include <string.h>

#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
static int g_weaptwk_servido;


extern "C" void w3d_dbg(const char *, ...);

#ifdef W3D_PUBLIC
extern "C" int w3d_francotirador_on() { return 0; }
extern "C" int w3d_francotirador_file(const char *, const unsigned char **, unsigned *) { return 0; }
extern "C" int w3d_franco_weaptwk_quiere(const char *) { return 0; }
extern "C" int w3d_franco_weaptwk_parchea(const unsigned char *, unsigned, const unsigned char **, unsigned *) { return 0; }
extern "C" int w3d_franco_lua_quiere(const char *) { return 0; }
extern "C" int w3d_franco_lua_parchea(const unsigned char *, unsigned, const unsigned char **, unsigned *) { return 0; }
extern "C" void w3d_francotirador_register() {}
#else
static const unsigned char kBundle[] = {
#include "francotirador_bundle.inc"
};
static const unsigned char kWeapTwk[] = {
#include "francotirador_weaptwk.inc"
};
static const unsigned kWeapTwkOriginal = 20288;   // tamaño de files/WeapTwk.xom del disco (GWMP8P)

static int g_on = -1;

extern "C" int w3d_francotirador_on(void) {
    if (g_on < 0) { const char *e = getenv("W3D_FRANCOTIRADOR"); g_on = e ? atoi(e) != 0 : 1; }
    return g_on;
}

static bool ends_with(const char *s, const char *suffix) {
    size_t a = strlen(s), b = strlen(suffix);
    if (a < b) return false;
    s += a - b;
    for (size_t i = 0; i < b; i++) {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') c += 32;
        if (c == '\\') c = '/';
        if (c != suffix[i]) return false;
    }
    return a == b || s[-1] == '/' || s[-1] == '\\';
}

// Bundles/Bundle95.xom no existe en el disco: lo sirve w3d_builtin_file (hat_militar.cpp) a través de
// w3d_mapa_um_file (mapa_um.cpp).
extern "C" int w3d_francotirador_file(const char *path, const unsigned char **data, unsigned *size) {
    if (!path || !ends_with(path, "bundles/bundle95.xom")) return 0;
    *data = kBundle; *size = sizeof kBundle;
    return 1;
}

// Pruebas: W3D_FRANCO_SIN=<letras> apaga piezas sueltas (w WeapTwk, l stdvs.lua, r recurso del bundle 0x5F).
static bool franco_sin(char c) { const char *e = getenv("W3D_FRANCO_SIN"); return e && strchr(e, c); }

// Parche 4: WeapTwk.xom. Se sirve entero el archivo ya hecho, si el del disco es el esperado.
extern "C" int w3d_franco_weaptwk_quiere(const char *path) {
    return w3d_francotirador_on() && !franco_sin('w') && path && ends_with(path, "weaptwk.xom");
}
extern "C" int w3d_franco_weaptwk_parchea(const unsigned char *in, unsigned size, const unsigned char **out, unsigned *out_size) {
    if (!in) {
        if (!g_weaptwk_servido) return 0;
    } else if (size != kWeapTwkOriginal || memcmp(in, kWeapTwk, 24)) {   // cabecera MOIK hasta las cuentas
        w3d_dbg("[francotirador] WeapTwk.xom de %u bytes, no es el esperado: sin francotirador\n", size);
        return 0;
    }
    if (!g_weaptwk_servido) w3d_dbg("[francotirador] WeapTwk.xom con kWeaponMagicBullet (%u bytes)\n", (unsigned)sizeof kWeapTwk);
    g_weaptwk_servido = 1;
    *out = kWeapTwk; *out_size = sizeof kWeapTwk;
    return 1;
}

// Parche 5: Scripts/stdvs.lua. "inventory.MagicBullet = 0" -> " 3" o "-1", mismo tamaño.
static unsigned char *g_lua;
static unsigned g_lua_size;
extern "C" int w3d_franco_lua_quiere(const char *path) {
    return w3d_francotirador_on() && !franco_sin('l') && path && ends_with(path, "scripts/stdvs.lua");
}
extern "C" int w3d_franco_lua_parchea(const unsigned char *in, unsigned size, const unsigned char **out, unsigned *out_size) {
    if (!in) {
        if (!g_lua) return 0;
        *out = g_lua; *out_size = g_lua_size;
        return 1;
    }
    if (!g_weaptwk_servido) { w3d_dbg("[francotirador] stdvs.lua sin WeapTwk parcheado: el 28 sigue sin munición\n"); return 0; }
    static const char kAntes[] = "inventory.MagicBullet = 0";
    const unsigned la = sizeof kAntes - 1;
    unsigned at = size;
    for (unsigned i = 0; i + la <= size; i++) if (!memcmp(in + i, kAntes, la)) { at = i; break; }
    if (at == size) { w3d_dbg("[francotirador] stdvs.lua sin la línea de MagicBullet\n"); return 0; }
    int balas = 3;
    if (const char *e = getenv("W3D_FRANCO_BALAS")) balas = atoi(e);
    if (balas < -1 || balas > 9) balas = 3;
    free(g_lua);
    g_lua = (unsigned char *)malloc(size);
    if (!g_lua) return 0;
    memcpy(g_lua, in, size); g_lua_size = size;
    // "= 0" ocupa 3 bytes: "= 3" o "=-1".
    if (balas < 0) memcpy(g_lua + at + la - 3, "=-1", 3);
    else g_lua[at + la - 1] = (unsigned char)('0' + balas);
    w3d_dbg("[francotirador] stdvs.lua: %d balas de francotirador por equipo\n", balas);
    *out = g_lua; *out_size = g_lua_size;
    return 1;
}

// Fila de recurso: nombre, bytes {bundle, tipo, 0, 0}, archivo, dos u16 (flags) y dos u16 más (0); ver hat_militar.cpp.
struct ResourceRow { Ptr32<const char> name; unsigned char bundle, type, pad[2]; Ptr32<const char> file; unsigned short flags, flags_lo, extra[2]; };
static_assert(sizeof(ResourceRow) == 20, "fila de 20 bytes como en 0x803f5e60");
static ResourceRow g_rows[1];

extern "C" Ptr32<void> A804b17ec;
// Al final de cx12a_register_catalogs_80127544, después de la ropa (0x59) y los mapas de UM (0x5A-0x5E).
extern "C" void w3d_francotirador_register(void) {
    if (!w3d_francotirador_on() || franco_sin('r')) return;
    g_rows[0].name = "SniperRifle";        g_rows[0].file = "SniperRifle.xom"; g_rows[0].flags = 0x0028;   // como "Shotgun"
    for (auto &r : g_rows) { r.bundle = 0x5F; r.type = 4; }
    // Solo SniperRifle. Sniper.Cursor.Mesh no se da de alta (la mira la dibuja la UI en 2D, ui_core.cpp): su nombre cae
    // en el hueco 1016 de la tabla de recursos, el de Targeting.Cursor.Mesh, y en 3DS con ella dada de alta la música
    // del título y de los menús no llegaba a abrirse (Azahar: mus_sinc con música, mus_exe sin ella; 2026-11-07).
    // Por eso el bundle ya no la lleva: con una entrada sin fila el bundle no cargaba, el fusil salía vacío y el juego
    // caía al sacarlo (d31j_add_named_target_80179b24 con la malla nula, desde d17d_worm_model_801385a4).
    Ptr32<void> svc = FIELD(A804b17ec, void *, 0x74);
    VCALL(svc, void (*)(void *, void *, unsigned), 0x28)(svc, g_rows, 1);
    unsigned char index = 0x5F;
    svc = FIELD(A804b17ec, void *, 0x74);
    VCALL(svc, void (*)(void *, unsigned char *, int), 0x48)(svc, &index, 0);
    svc = FIELD(A804b17ec, void *, 0x74);
    VCALL(svc, void (*)(void *, unsigned char *, int), 0x54)(svc, &index, 1);
    w3d_dbg("[francotirador] recurso SniperRifle, bundle 0x5F (%u bytes)\n", (unsigned)sizeof kBundle);
}

// ---------------------------------------------------------------------------------------------------------------------
#endif
// Mira y zoom (mods/armas-um/francotirador/plumbing_camara.md). UM: GunWeaponLogicEntity::Initialise (0x55cff0) pone el
// indicador «francotirador activo» (DAT_0095d9fe) y HeadCam::Update (0x528d70) divide o multiplica el zoom por 1,1 cada
// tic de 20 ms entre 0,05 y 1,0 (hasta 20 aumentos). W3D no tiene zoom en el HeadCam: se hace como sus prismáticos
// (0x8002bc14), escalando l, r, b y t del frustum de las cámaras app+0x30 y app+0x8c. La mira se dibuja en la capa de UI
// nativa (platform/ui/ui_core.cpp), solo en primera persona, como SniperCursorGraphicEntity::IsVisible (cámara Head).
// Botones: Y (o Z: ZL/ZR en New 3DS) acerca, B aleja (B ya es Input.ZoomOutPressed en primera persona); con la mira
// puesta Y y Z no llegan al juego.
#include "native_game.h"
#include <math.h>

extern "C" {
extern w3d_u32 A804b1788;                       // la aplicación (misc_game.cpp)
w3d_u32 A800fc1f0(void *key, void *out, ...);   // entero por nombre (settings_store.cpp)
w3d_u32 A800fc230(void *key, void *out, ...);   // entero sin signo
w3d_u32 A800fc3b0(void *key, w3d_u32 value);    // escribe un entero sin signo (RetreatTime en 8009c248)
w3d_u32 A800fc6dc(void *worm);                  // ficha del gusano por índice
w3d_u32 A80165254();                            // contexto del motor: +0x34 tiempo en ms
unsigned A80322938(unsigned fid, unsigned vol, unsigned pan, unsigned studio);   // sndFXStartEx (sdk_audio.cpp)
}

extern "C" w3d_u32 A804b1760;                 // el juego (w3d_game_804b1760 en d24b_weapon_projectile_start_8009c248)
extern "C" int A80020834(void *game);         // verdadero en el turno de un equipo de la IA
namespace {
const int kSniperWeapon = 28;                   // kWeaponMagicBullet
struct Frustum { float l, r, b, t; w3d_u32 near_bits, far_bits, flag; };   // XCamera vf 0x24 (leer) y 0x28 (poner)
static_assert(sizeof(Frustum) == 28, "7 palabras, como self+0x64 de los prismáticos");
const unsigned kCam[2] = {0x30, 0x8c};          // las de 0x8002bc14; ni la del HUD (+0x84) ni +0x88
const float kMinZoom = 0.05f, kMaxZoom = 1.0f;  // Camera.Head.MinZoom/MaxZoom (CAMTWK de UM)
const float kZoomSpeed = 1.1f, kTickMs = 20.0f; // Camera.Head.ZoomSpeed por tic de 20 ms
const unsigned kBtnB = 0x200, kBtnY = 0x800, kBtnZ = 0x10;
volatile bool g_active, g_fp;                   // francotirador activo; cámara Head (Camera.CurrentMode == 1)
bool g_applied;
float g_zoom = 1.0f, g_applied_zoom = 1.0f, g_aim_latched = 1.0f;
Frustum g_base[2];
int g_last_ms = -1;
unsigned g_held;
w3d_u32 g_period_prev;

int prop_int(const char *n, int d) { Ptr32<const char> k(n); int v = d; A800fc1f0(&k, &v); return v; }
unsigned prop_uint(const char *n, unsigned d) { Ptr32<const char> k(n); w3d_u32 v = d; A800fc230(&k, &v); return v; }
void *camera(int i) { return g2h(*at<w3d_u32>(A804b1788 + kCam[i])); }
int now_ms() { return *at<int>(A80165254() + 0x34); }
void save_base() { for (int i = 0; i < 2; i++) g_base[i] = *at<const Frustum>(call_virtual(camera(i), 0x24)); }
// Como 0x8002bc14: near, far y la marca de la cámara actual; l, r, b y t del frustum guardado por el zoom.
void put(float k) {
    for (int i = 0; i < 2; i++) {
        Frustum f = *at<const Frustum>(call_virtual(camera(i), 0x24));
        f.l = g_base[i].l * k; f.r = g_base[i].r * k; f.b = g_base[i].b * k; f.t = g_base[i].t * k;
        call_virtual<void>(camera(i), 0x28, &f);
    }
}
void restore() { if (g_applied) { put(1.0f); g_applied = false; g_applied_zoom = 1.0f; } }
}

extern "C" {
// 1 si el gusano activo lleva el francotirador (ficha +0x84: arma actual, índice de 0x803eb63c).
int w3d_franco_es_francotirador(void) {
    if (!w3d_francotirador_on() || !g_weaptwk_servido) return 0;
    const int w = prop_int("ActiveWormIndex", -1);
    if (w < 0 || w > 16) return 0;
    const w3d_u32 info = A800fc6dc(arg((w3d_u32)w));
    return info && *at<int>(info + 0x84) == kSniperWeapon;
}
// Desde 0x8009c248 (inicio de la pistola), como 0x55cff0 de UM. En el turno de la IA (la misma prueba con la que
// 8009c248 no crea el temblor) solo suena el arma: UM no usa la mira ni el zoom para la IA.
void w3d_franco_start(void) {
    if (A804b1760 && A80020834(arg(A804b1760))) {
        A80322938(0x0F01, 127, 64, 0);
        w3d_dbg("[francotirador] %d ms: turno de la IA (sin mira)\n", now_ms());
        return;
    }
    g_active = true; g_zoom = 1.0f; g_applied = false; g_last_ms = -1;
    save_base();
    g_fp = prop_uint("Camera.CurrentMode", 0) == 1;
    // GunWobble.Period: 10000 en W3D, 5000 en UM (la mira se mece el doble de rápido). Se restaura al acabar.
    g_period_prev = prop_uint("GunWobble.Period", 10000);
    { Ptr32<const char> k("GunWobble.Period"); A800fc3b0(&k, 5000); }
    A80322938(0x0F01, 127, 64, 0);                // weapons/SniperEquip (UM lo pone en la animación DrawSniper)
    w3d_dbg("[francotirador] %d ms: activo (cámara %s)\n", now_ms(), g_fp ? "Head" : "otra");
}
// Parada (mensaje 66) o fin del disparo (estado 7 tras PostLaunchDelay), como 0x55d650 de UM.
void w3d_franco_stop(void) {
    if (!g_active) return;
    restore(); g_active = false; g_fp = false; g_zoom = 1.0f;
    { Ptr32<const char> k("GunWobble.Period"); A800fc3b0(&k, g_period_prev ? g_period_prev : 10000); }
    w3d_dbg("[francotirador] %d ms: fin\n", now_ms());
}
// Desde A80035714 (camera_modes.cpp) con el tipo del modo nuevo (+0x30: 1 = Head). Al salir de la primera persona se
// quita el zoom en el mismo cuadro; al volver, el tic lo pone otra vez.
void w3d_franco_camera_mode(w3d_u32 type) {
    g_fp = type == 1;
    if (!g_active) return;
    w3d_dbg("[francotirador] %d ms: cámara %s, zoom %.3f\n", now_ms(), g_fp ? "Head (mira)" : "otra", g_zoom);
    if (!g_fp) restore(); else g_last_ms = -1;
}
// Al principio de 0x8009e1cc (tic del HeadCam): el bloque de zoom de HeadCam::Update de UM, integrado con el tiempo.
void w3d_franco_headcam_tick(void) {
    if (!g_active || !g_fp) return;
    const int t = now_ms();
    float dt = g_last_ms < 0 ? 0.0f : (float)(t - g_last_ms);
    g_last_ms = t;
    if (dt < 0.0f) dt = 0.0f;
    if (dt > 100.0f) dt = 100.0f;                 // tras una pausa o un cuadro largo
    const float step = powf(kZoomSpeed, dt / kTickMs);
    if (g_held & (kBtnY | kBtnZ)) g_zoom /= step; // ZoomIn: ÷1,1 cada 20 ms
    if (g_held & kBtnB) g_zoom *= step;           // ZoomOut: ×1,1
    g_zoom = g_zoom < kMinZoom ? kMinZoom : g_zoom > kMaxZoom ? kMaxZoom : g_zoom;
    if (!g_applied || g_zoom != g_applied_zoom) {
        static float logged = 0;
        if (fabsf(g_zoom - logged) > logged * 0.25f || g_zoom == kMinZoom && logged != kMinZoom) { logged = g_zoom; w3d_dbg("[francotirador] zoom %.3f (%.1f aumentos)\n", g_zoom, 1.0f / g_zoom); }
        put(g_zoom); g_applied = true; g_applied_zoom = g_zoom;
    }
}
// Solo pruebas: W3D_FRANCO_APUNTA=1 apunta con la mira puesta al gusano enemigo vivo más cercano pulsando la cruceta
// (la misma entrada que un jugador, con su sensibilidad) y escribe en el registro el error de puntería.
// Ficha del gusano (A800fc6dc, la misma que W3D_STATE_LOG): +0x48 rumbo, +0x50 posición, +0x74 elevación, +0x84 arma,
// +0xa0 vida (int), +0xd5 equipo. Vista del HeadCam: forward = (cos e·sin h, sin e, cos e·cos h).
unsigned franco_aim_test(unsigned buttons) {
    static int on = -1;
    if (on < 0) { const char *e = getenv("W3D_FRANCO_APUNTA"); on = e && atoi(e) ? 1 : 0; }
    if (!on || !g_active || !g_fp) return buttons;
    const int w = prop_int("ActiveWormIndex", -1);
    if (w < 0 || w > 15) return buttons;
    const w3d_u32 me = A800fc6dc(arg((w3d_u32)w));
    if (!me) return buttons;
    const float *p = at<float>(me + 0x50);
    const unsigned team = *at<uint8_t>(me + 0xd5);
    float best = 1e30f, dx = 0, dy = 0, dz = 0; int target = -1;
    for (int i = 0; i < 16; i++) {
        if (i == w) continue;
        const w3d_u32 o = A800fc6dc(arg((w3d_u32)i));
        if (!o || *at<uint8_t>(o + 0xd5) == team || *at<int>(o + 0xa0) <= 0) continue;
        const float *q = at<float>(o + 0x50);
        static const float alto = getenv("W3D_FRANCO_ALTO") ? (float)atof(getenv("W3D_FRANCO_ALTO")) : 12.0f;   // sobre los pies: 12 = cabeza
        const float ax = q[0] - p[0], ay = q[1] + alto - (p[1] + 20.0f), az = q[2] - p[2];   // ojos (EyeLevelOffset 20)
        const float d = ax * ax + ay * ay + az * az;
        if (d < best) { best = d; dx = ax; dy = ay; dz = az; target = i; }
    }
    if (target < 0) return buttons;
    // Con el temblor de la mira (+0x90 rumbo, +0x94 elevación, GunWobbleObject): la bala sale por donde mira la vista.
    const float h = *at<float>(me + 0x48) + *at<float>(me + 0x90), e = *at<float>(me + 0x74) + *at<float>(me + 0x94);
    const float want_h = atan2f(dx, dz), want_e = atan2f(dy, sqrtf(dx * dx + dz * dz));
    float eh = want_h - h;
    while (eh > 3.14159265f) eh -= 6.2831853f;
    while (eh < -3.14159265f) eh += 6.2831853f;
    const float ee = want_e - e;
    static int frame;
    if (!(frame++ % 25)) w3d_dbg("[francotirador] %d ms: prueba: blanco %d a %.0f, error rumbo %.4f elevación %.4f (zoom %.3f)\n", now_ms(), target, sqrtf(best), eh, ee, g_zoom);
    const float tol = 0.002f + 0.01f * g_zoom;
    buttons &= ~0xfu;
    if (eh > tol) buttons |= 1; else if (eh < -tol) buttons |= 2;       // cruceta izquierda / derecha
    if (ee > tol) buttons |= 8; else if (ee < -tol) buttons |= 4;       // arriba / abajo
    return buttons;
}
// PADRead (sdk_core.cpp), mando 0: guarda B, Y y Z para el zoom; con la mira puesta, Y (WormSelect) y Z (Fuse) no llegan.
unsigned w3d_franco_pad(unsigned buttons) {
    buttons = franco_aim_test(buttons);
    if (g_active && (buttons & (kBtnB | kBtnY | kBtnZ)) != g_held)
        w3d_dbg("[francotirador] %d ms: botones de zoom %03x (cámara %s)\n", now_ms(), buttons & (kBtnB | kBtnY | kBtnZ), g_fp ? "Head" : "otra");
    g_held = buttons & (kBtnB | kBtnY | kBtnZ);
    return g_active && g_fp ? buttons & ~(kBtnY | kBtnZ) : buttons;
}
// Sensibilidad de la puntería proporcional al zoom (a 20 aumentos, 1/20): en UM se apunta con ratón; con mando hace falta.
float w3d_franco_aim_scale(void) { return g_active && g_fp ? g_zoom : 1.0f; }
void w3d_franco_latch_aim(void) { g_aim_latched = w3d_franco_aim_scale(); }
float w3d_franco_aim_latched(void) { return g_aim_latched; }
// Para la mira (UI): 1 si se ve, y el zoom actual.
int w3d_franco_scope(float *zoom) { if (zoom) *zoom = g_zoom; return g_active && g_fp; }
// 1 mientras el francotirador está activo (para precargar la textura de la mira).
int w3d_franco_active(void) { return g_active; }
}

// ---------------------------------------------------------------------------------------------------------------------
// Sonidos de UM (weapons/SniperRifleFire y weapons/SniperEquip de weapons.fsb, 32 kHz mono): PCM en el binario
// (francotirador_sonidos.inc, tools/hacer_sonidos.py), tocados por el mezclador del port con los FX 0x0F00 y 0x0F01
// (sdk_audio.cpp). La tabla de nombres de sonido del juego (0x803ebc18: filas de 0x38 bytes, fin con nombre nulo) se
// copia con dos filas más para que DischargeSoundFX = "SniperRifleFire" del contenedor se pida por nombre como
// "ShotgunFire". La cargan d41g_flow_start_8006c4a8 y s1_session_services (0x8006df98).
#include <stdint.h>
#ifndef W3D_PUBLIC
#include "francotirador_sonidos.inc"
extern "C" void w3d_audio_native(unsigned i, const int16_t *pcm, unsigned frames, unsigned rate);
extern "C" unsigned char w3d_table_803ebc18[];
namespace {
struct SfxRow { Ptr32<const char> name; w3d_u32 fx, kind; Ptr32<const char> path; w3d_u32 w4, group, loop, var, vol, w9, far_, near_, w12, w13; };
static_assert(sizeof(SfxRow) == 0x38, "fila de 0x803ebc18");
SfxRow g_sfx[160];
}
extern "C" void *w3d_franco_sfx_table(void *original) {
    static int done;   // 1 tabla propia, 2 la original (no cuadró)
    if (!done) {
        done = 2;
        const SfxRow *src = (const SfxRow *)original;
        int n = 0, shot = -1, draw = -1;
        while (n < 150 && src[n].name) {
            if (!strcmp(src[n].name.get(), "ShotgunFire")) shot = n;
            if (!strcmp(src[n].name.get(), "Draw.Shotgun")) draw = n;
            n++;
        }
        if (n < 150 && shot >= 0 && draw >= 0 && src[shot].fx == 0x30) {
            memcpy(g_sfx, src, n * sizeof(SfxRow));
            g_sfx[n] = src[shot];     g_sfx[n].name = "SniperRifleFire"; g_sfx[n].fx = 0x0F00;
            g_sfx[n + 1] = src[draw]; g_sfx[n + 1].name = "SniperEquip";     g_sfx[n + 1].fx = 0x0F01;
            memset(&g_sfx[n + 2], 0, sizeof(SfxRow));
            w3d_audio_native(0, kSniperFire, sizeof kSniperFire / 2, 32000);
            w3d_audio_native(1, kSniperEquip, sizeof kSniperEquip / 2, 32000);
            done = 1;
            w3d_dbg("[francotirador] tabla de sonidos: %d filas + SniperRifleFire y SniperEquip\n", n);
        } else {
            w3d_dbg("[francotirador] tabla de sonidos inesperada (%d filas, ShotgunFire %d): sin sonidos propios\n", n, shot);
        }
    }
    return done == 1 && w3d_francotirador_on() ? (void *)g_sfx : original;
}

// ---------------------------------------------------------------------------------------------------------------------
#else
extern "C" void *w3d_franco_sfx_table(void *original) { return original; }
#endif
// Animación de entrada de la mira, como In_Sniper de UM (biblioteca XCULLEDSniper_Char de Bundl09, 1 s): escala de
// Outer1 (anillo y máscara), Inner1 (los brazos de la cruz) y dot (el punto). Cada canal tiene dos o tres claves
// (t, v) con tangentes de Hermite (mods/armas-um/francotirador/in_sniper.json, tools/hacer_mira_capas.py); en las tres
// la pendiente final es 0, así que se frenan al llegar. Escala de x = escala de y.
namespace {
struct Clave { float t, v, in, out; };
float hermite(const Clave *k, int n, float t) {
    if (t <= k[0].t) return k[0].v;
    for (int i = 0; i + 1 < n; i++) {
        if (t > k[i + 1].t) continue;
        const float dt = k[i + 1].t - k[i].t, s = (t - k[i].t) / dt, s2 = s * s, s3 = s2 * s;
        return (2 * s3 - 3 * s2 + 1) * k[i].v + (s3 - 2 * s2 + s) * dt * k[i].out + (-2 * s3 + 3 * s2) * k[i + 1].v + (s3 - s2) * dt * k[i + 1].in;
    }
    return k[n - 1].v;
}
const Clave kOuter[] = {{-0.0417f, 1.2998f, -1.5996f, -1.6572f}, {1.0f, 0.6631f, 0.0f, 0.0f}};
const Clave kInner[] = {{-0.0417f, 2.7969f, -5.168f, -5.4062f}, {0.5f, 0.6636f, -0.0349f, 0.0f}, {1.0f, 0.6636f, 0.0f, 0.0f}};
const Clave kDot[] = {{0.0f, 0.0f, 1.3467f, 1.3467f}, {0.583f, 0.4863f, 0.0f, 0.0f}};
}
extern "C" void w3d_franco_mira_escalas(float t, float *outer, float *inner, float *dot) {
    t -= 0.0417f;   // el clip empieza en t = -1/24
    *outer = hermite(kOuter, 2, t);
    *inner = hermite(kInner, 3, t);
    *dot = hermite(kDot, 2, t);
}
