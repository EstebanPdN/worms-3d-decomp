// macOS: ventana y entrada con SDL3, presentación con Metal.
extern "C" long w3d_test_since_init();
#include <sys/stat.h>
#include "../platform.h"
#include <SDL3/SDL.h>
#include "controller_input.h"
#include "dual_layout.h"
#import <Metal/Metal.h>
#import <QuartzCore/CAMetalLayer.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

namespace w3d {
namespace plat {

void vfs_mount(const char *data_root);

static SDL_Window *g_window;
static SDL_MetalView g_view;
static CAMetalLayer *g_layer;
static id<MTLDevice> g_device;
static id<MTLCommandQueue> g_queue;
static id<MTLTexture> g_last;
static bool g_hidden;
static SDL_Gamepad *g_pads[4];

static void open_controller(SDL_JoystickID id) {
    for (auto p : g_pads) if (p && SDL_GetGamepadID(p) == id) return;
    for (auto &p : g_pads) if (!p) {
        p = SDL_OpenGamepad(id);
        if (p) fprintf(stderr, "[controller] connected: %s (id %u, %04x:%04x), layout=%s\n",
            SDL_GetGamepadName(p), id, SDL_GetGamepadVendor(p), SDL_GetGamepadProduct(p),
            getenv("W3D_DUAL") ? "3DS physical positions" : "desktop");
        else fprintf(stderr, "[controller] open failed: %s\n", SDL_GetError());
        break;
    }
}
static void load_controls(const char *dir);
bool init(const Config &cfg) {
    vfs_mount(cfg.data_root);
    g_hidden = cfg.hidden;
    // Pruebas automáticas: sin icono en el Dock ni ventana que robe el foco.
    // Bajo lldb este modo no llega a arrancar: W3D_DEBUG lo evita.
    if (getenv("W3D_HIDDEN") && !getenv("W3D_DEBUG")) SDL_SetHint(SDL_HINT_MAC_BACKGROUND_APP, "1");
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD)) { fprintf(stderr, "SDL_Init: %s\n", SDL_GetError()); return false; }
    SDL_WindowFlags fl = SDL_WINDOW_METAL | SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_RESIZABLE;
    if (cfg.hidden) fl |= SDL_WINDOW_HIDDEN;
    // W3D_DUAL=1: las dos pantallas de la 3DS, al doble (prueba de la UI de dos pantallas, platform/ui).
    const bool dual = getenv("W3D_DUAL") != nullptr;
    int ww = cfg.width, wh = cfg.height;
    if (dual) {
        SDL_Rect bounds = {0, 0, 1000, 900};
        SDL_GetDisplayUsableBounds(SDL_GetPrimaryDisplay(), &bounds);
        double scale = fmin(2.0, fmin((bounds.w - 80) / 400.0, (bounds.h - 80) / 480.0));
        ww = (int)(400 * scale); wh = (int)(480 * scale);
    }
    g_window = SDL_CreateWindow(dual ? "Worms 3D — 3DS UI Review" : cfg.title, ww, wh, fl);
    if (!g_window) { fprintf(stderr, "ventana: %s\n", SDL_GetError()); return false; }
    g_view = SDL_Metal_CreateView(g_window);
    g_layer = (__bridge CAMetalLayer *)SDL_Metal_GetLayer(g_view);
    g_device = MTLCreateSystemDefaultDevice();
    if (!g_device) { fprintf(stderr, "sin dispositivo Metal\n"); return false; }
    g_layer.device = g_device;
    g_layer.pixelFormat = MTLPixelFormatBGRA8Unorm;
    g_layer.framebufferOnly = NO;
    g_queue = [g_device newCommandQueue];
    { int pw = 0, ph = 0; SDL_GetWindowSizeInPixels(g_window, &pw, &ph); if (pw > 0) g_layer.drawableSize = CGSizeMake(pw, ph); }
    load_controls(cfg.save_root);
    int count = 0;
    SDL_JoystickID *ids = SDL_GetGamepads(&count);
    for (int i = 0; i < count; ++i) open_controller(ids[i]);
    SDL_free(ids);
    return true;
}

void shutdown() {
    for (auto &p : g_pads) if (p) { SDL_CloseGamepad(p); p = nullptr; }
    g_last = nil; g_queue = nil; g_device = nil;
    if (g_view) SDL_Metal_DestroyView(g_view);
    if (g_window) SDL_DestroyWindow(g_window);
    SDL_Quit();
}

// Controles de teclado. Se leen de <carpeta de guardado>/controles.txt, una línea "ACCION=Tecla" con nombres de tecla de SDL.
enum Action { K_START, K_A, K_B, K_X, K_Y, K_Z, K_L, K_R, K_UP, K_DOWN, K_LEFT, K_RIGHT, K_SU, K_SD, K_SL, K_SR, K_CU, K_CD, K_CL, K_CR, K_COUNT };
static const struct { const char *name; SDL_Scancode key; } kDefaultKeys[K_COUNT] = {
    {"START", SDL_SCANCODE_RETURN}, {"A", SDL_SCANCODE_SPACE}, {"B", SDL_SCANCODE_LSHIFT}, {"X", SDL_SCANCODE_F}, {"Y", SDL_SCANCODE_G},
    {"Z", SDL_SCANCODE_Z}, {"L", SDL_SCANCODE_Q}, {"R", SDL_SCANCODE_E},
    {"ARRIBA", SDL_SCANCODE_UP}, {"ABAJO", SDL_SCANCODE_DOWN}, {"IZQUIERDA", SDL_SCANCODE_LEFT}, {"DERECHA", SDL_SCANCODE_RIGHT},
    {"STICK_ARRIBA", SDL_SCANCODE_W}, {"STICK_ABAJO", SDL_SCANCODE_S}, {"STICK_IZQUIERDA", SDL_SCANCODE_A}, {"STICK_DERECHA", SDL_SCANCODE_D},
    {"C_ARRIBA", SDL_SCANCODE_I}, {"C_ABAJO", SDL_SCANCODE_K}, {"C_IZQUIERDA", SDL_SCANCODE_J}, {"C_DERECHA", SDL_SCANCODE_L},
};
static SDL_Scancode g_keys[K_COUNT];
static void load_controls(const char *dir) {
    for (int i = 0; i < K_COUNT; i++) g_keys[i] = kDefaultKeys[i].key;
    char path[1200];
    snprintf(path, sizeof path, "%s/controles.txt", dir);
    FILE *f = fopen(path, "r");
    if (!f) {
        mkdir(dir, 0755);
        if ((f = fopen(path, "w"))) {
            for (int i = 0; i < K_COUNT; i++) fprintf(f, "%s=%s\n", kDefaultKeys[i].name, SDL_GetScancodeName(kDefaultKeys[i].key));
            fclose(f);
        }
        return;
    }
    char line[128];
    while (fgets(line, sizeof line, f)) {
        line[strcspn(line, "\r\n")] = 0;
        char *eq = strchr(line, '=');
        if (!eq) continue;
        *eq = 0;
        for (int i = 0; i < K_COUNT; i++) {
            if (strcmp(line, kDefaultKeys[i].name)) continue;
            SDL_Scancode sc = SDL_GetScancodeFromName(eq + 1);
            if (sc != SDL_SCANCODE_UNKNOWN) g_keys[i] = sc;
            else fprintf(stderr, "controles.txt: tecla desconocida '%s'\n", eq + 1);
        }
    }
    fclose(f);
}

static unsigned g_pumps;
extern "C" void w3d_ui_input(unsigned held, int touch, int tx, int ty);   // platform/ui/ui_core.cpp
extern "C" unsigned w3d_ui_pad(Pad *o);
// Entrada de la UI de dos pantallas: teclas como botones de la 3DS (SELECT en el tabulador) y el ratón sobre la pantalla
// de abajo como táctil. W3D_UI_TOUCH="<s>:<x>;<y>,..." toca la pantalla de abajo en esos segundos (0,15 s), y
// W3D_UI_KEYS="<s>:<tecla>,..." pulsa A B X Y S(tart) E (select) L R U D I(zq) T (der) durante 0,15 s, para probar sin manos.
static void ui_input() {
    static const bool dual = getenv("W3D_DUAL") != nullptr;
    if (!dual) return;
    const bool *k = SDL_GetKeyboardState(nullptr);
    unsigned b = 0;
    if (!(SDL_GetModState() & SDL_KMOD_GUI)) {
        if (k[g_keys[K_A]]) b |= 1; if (k[g_keys[K_B]]) b |= 2; if (k[g_keys[K_X]]) b |= 4; if (k[g_keys[K_Y]]) b |= 8;
        if (k[g_keys[K_START]]) b |= 16; if (k[SDL_SCANCODE_TAB]) b |= 32; if (k[g_keys[K_L]]) b |= 64; if (k[g_keys[K_R]]) b |= 128;
        if (k[g_keys[K_UP]]) b |= 256; if (k[g_keys[K_DOWN]]) b |= 512; if (k[g_keys[K_LEFT]]) b |= 1024; if (k[g_keys[K_RIGHT]]) b |= 2048;
    }
    if (g_pads[0]) {
        b |= controller_ui(controller_read(g_pads[0], true), SDL_GetGamepadButton(g_pads[0], SDL_GAMEPAD_BUTTON_BACK));
    }
    // WASD, like the Circle Pad, navigates the review UI as well as the game.
    if (!(SDL_GetModState() & SDL_KMOD_GUI)) {
        if (k[g_keys[K_SU]]) b |= 256; if (k[g_keys[K_SD]]) b |= 512;
        if (k[g_keys[K_SL]]) b |= 1024; if (k[g_keys[K_SR]]) b |= 2048;
    }
    float mx = 0, my = 0;
    SDL_MouseButtonFlags mb = SDL_GetMouseState(&mx, &my);
    int ww, wh, pw, ph;
    SDL_GetWindowSize(g_window, &ww, &wh); SDL_GetWindowSizeInPixels(g_window, &pw, &ph);
    DualLayout layout(pw, ph);
    int tx = 0, ty = 0;
    bool inside = layout.touch(mx * pw / ww, my * ph / wh, tx, ty);
    bool touch = (mb & SDL_BUTTON_LMASK) && inside && (SDL_GetWindowFlags(g_window) & SDL_WINDOW_INPUT_FOCUS);
    static const char *script = getenv("W3D_UI_TOUCH");
    static const char *keys = getenv("W3D_UI_KEYS");
    double t = now_seconds();
    static double t0 = t;
    double el = t - t0;
    // "<s>:<x>;<y>" taps for 0.15 s; "<s>:<x>;<y>><x2>;<y2>/<dur>" drags from one point to the other over dur seconds.
    for (const char *c = script; c && *c;) {
        char *e; double at = strtod(c, &e);
        if (*e == ':') {
            const char *end = strchr(e, ',');
            int x = atoi(e + 1); const char *sc = strchr(e, ';'); int y = sc ? atoi(sc + 1) : 0;
            const char *gt = strchr(e, '>'); if (gt && end && gt > end) gt = nullptr;
            int x2 = x, y2 = y; double dur = 0.15;
            if (gt) {
                x2 = atoi(gt + 1); const char *sc2 = strchr(gt, ';'); y2 = sc2 ? atoi(sc2 + 1) : y;
                const char *sl = strchr(gt, '/'); if (sl && (!end || sl < end)) dur = strtod(sl + 1, nullptr);
            }
            if (el >= at && el < at + dur) {
                const double k = gt ? (el - at) / dur : 0;
                touch = true; tx = x + (int)((x2 - x) * k); ty = y + (int)((y2 - y) * k);
            }
        }
        c = strchr(e, ','); if (c) c++;
    }
    // "<s>:<tecla>/<dur>" la mantiene dur segundos (girar el worm de Crear equipo con L/R).
    for (const char *c = keys; c && *c;) {
        char *e; double at = strtod(c, &e);
        const double dur = *e == ':' && e[1] && e[2] == '/' ? strtod(e + 3, nullptr) : 0.15;
        if (*e == ':' && el >= at && el < at + dur) {
            switch (e[1]) { case 'A': b |= 1; break; case 'B': b |= 2; break; case 'X': b |= 4; break; case 'Y': b |= 8; break; case 'S': b |= 16; break; case 'E': b |= 32; break;
                            case 'L': b |= 64; break; case 'R': b |= 128; break; case 'U': b |= 256; break; case 'D': b |= 512; break; case 'I': b |= 1024; break; case 'T': b |= 2048; break; }
        }
        c = strchr(e, ','); if (c) c++;
    }
    if (getenv("W3D_LOG_CONTROLLER") && g_pads[0]) {
        unsigned held = controller_ui(controller_read(g_pads[0], true), SDL_GetGamepadButton(g_pads[0], SDL_GAMEPAD_BUTTON_BACK));
        static unsigned last;
        if (held != last) { fprintf(stderr, "[controller] UI buttons %04x\n", held); last = held; }
    }
    if (touch) b |= 4096;
    w3d_ui_input(b, touch, tx, ty);
}
bool pump() {
    g_pumps++;
    SDL_Event e;
    bool alive = true;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_EVENT_QUIT || e.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) alive = false;
        else if (e.type == SDL_EVENT_KEY_DOWN && !e.key.repeat && (e.key.scancode == SDL_SCANCODE_F11 || (e.key.scancode == SDL_SCANCODE_F && (e.key.mod & SDL_KMOD_GUI) && (e.key.mod & SDL_KMOD_CTRL)))) {
            SDL_SetWindowFullscreen(g_window, !(SDL_GetWindowFlags(g_window) & SDL_WINDOW_FULLSCREEN));
        }
        else if (e.type == SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED) {
            // La capa no sigue sola a la ventana: sin esto la imagen se estira y el encaje 4:3 se calcula con el tamaño viejo.
            g_layer.drawableSize = CGSizeMake(e.window.data1, e.window.data2);
        }
        else if (e.type == SDL_EVENT_GAMEPAD_ADDED) {
            open_controller(e.gdevice.which);
        } else if (e.type == SDL_EVENT_GAMEPAD_REMOVED) {
            for (auto &p : g_pads) if (p && SDL_GetGamepadID(p) == e.gdevice.which) { SDL_CloseGamepad(p); p = nullptr; }
        }
    }
    ui_input();
    return alive;
}

double now_seconds() {
    timespec t; clock_gettime(CLOCK_MONOTONIC, &t);
    return (double)t.tv_sec + (double)t.tv_nsec * 1e-9;
}
void sleep_seconds(double s) { if (s > 0) usleep((useconds_t)(s * 1e6)); }

enum { BTN_LEFT = 1, BTN_RIGHT = 2, BTN_DOWN = 4, BTN_UP = 8, BTN_Z = 0x10, BTN_R = 0x20, BTN_L = 0x40, BTN_A = 0x100, BTN_B = 0x200, BTN_X = 0x400, BTN_Y = 0x800, BTN_START = 0x1000 };

void pad_read(int i, Pad *o) {
    *o = Pad();
    // Con Cmd pulsado las teclas son atajos del sistema, no del juego.
    const bool *k = i == 0 ? SDL_GetKeyboardState(nullptr) : nullptr;
    static const bool no_keys[SDL_SCANCODE_COUNT] = {};
    if (k && (SDL_GetModState() & SDL_KMOD_GUI)) k = no_keys;
    uint16_t b = 0;
    int sx = 0, sy = 0, cx = 0, cy = 0, tl = 0, tr = 0;
    if (k) {
        o->connected = true;
        static const struct { int action; uint16_t bit; } kButtons[] = {
            {K_START, BTN_START}, {K_A, BTN_A}, {K_B, BTN_B}, {K_X, BTN_X}, {K_Y, BTN_Y}, {K_Z, BTN_Z},
            {K_UP, BTN_UP}, {K_DOWN, BTN_DOWN}, {K_LEFT, BTN_LEFT}, {K_RIGHT, BTN_RIGHT},
        };
        for (const auto &m : kButtons) if (k[g_keys[m.action]]) b |= m.bit;
        if (k[g_keys[K_L]]) { b |= BTN_L; tl = 255; }
        if (k[g_keys[K_R]]) { b |= BTN_R; tr = 255; }
        // W3D_AUTOKEYS="<retrazos/60>:<botón>,...": pulsaciones de 12 retrazos para probar sin teclado. Botones: S A B X Y Z U D L R (cruceta) y l r (gatillos).
        static const char *autokeys = getenv("W3D_AUTOKEYS");
        if (autokeys) {
            // Cuenta retrazos de vídeo, no tiempo real: así la misma prueba repite exactamente la misma partida.
            double now = g_pumps / 60.0;
            for (const char *c = autokeys; c && *c;) {
                char *end; double t = strtod(c, &end);
                char name = *end == ':' ? end[1] : 0;
                if (name && now >= t && now < t + 0.2) {
                    switch (name) {
                    case 'S': b |= BTN_START; break; case 'A': b |= BTN_A; break; case 'B': b |= BTN_B; break;
                    case 'X': b |= BTN_X; break; case 'Y': b |= BTN_Y; break; case 'Z': b |= BTN_Z; break;
                    case 'U': b |= BTN_UP; break; case 'D': b |= BTN_DOWN; break; case 'L': b |= BTN_LEFT; break; case 'R': b |= BTN_RIGHT; break;
                    case 'l': b |= BTN_L; tl = 255; break; case 'r': b |= BTN_R; tr = 255; break;   // Gatillos.
                    }
                }
                c = strchr(end, ','); if (c) c++;
            }
        }
        // W3D_CHAIN_KEYS="<retrazos>:<botón>,...": como W3D_AUTOKEYS, contados desde el último Initialise; se repiten cada W3D_CHAIN_PERIOD.
        static const char *chain = getenv("W3D_CHAIN_KEYS");
        if (chain && i == 0) {
            static const long period = getenv("W3D_CHAIN_PERIOD") ? atol(getenv("W3D_CHAIN_PERIOD")) : 0;
            long since = w3d_test_since_init();
            if (since >= 0 && period) since = since < period ? since : period / 2 + (since - period) % (period / 2);
            for (const char *c = chain; c && *c && since >= 0;) {
                char *end; long t = strtol(c, &end, 10);
                char name = *end == ':' ? end[1] : 0;
                if (name && since >= t && since < t + 12) {
                    switch (name) {
                    case 'S': b |= BTN_START; break; case 'A': b |= BTN_A; break; case 'B': b |= BTN_B; break;
                    case 'X': b |= BTN_X; break; case 'Y': b |= BTN_Y; break; case 'Z': b |= BTN_Z; break;
                    case 'U': b |= BTN_UP; break; case 'D': b |= BTN_DOWN; break; case 'L': b |= BTN_LEFT; break; case 'R': b |= BTN_RIGHT; break;
                    case 'l': b |= BTN_L; tl = 255; break; case 'r': b |= BTN_R; tr = 255; break;   // Gatillos.
                    }
                }
                c = strchr(end, ','); if (c) c++;
            }
        }
        sx = (k[g_keys[K_SR]] ? 100 : 0) - (k[g_keys[K_SL]] ? 100 : 0);
        sy = (k[g_keys[K_SU]] ? 100 : 0) - (k[g_keys[K_SD]] ? 100 : 0);
        cx = (k[g_keys[K_CR]] ? 100 : 0) - (k[g_keys[K_CL]] ? 100 : 0);
        cy = (k[g_keys[K_CU]] ? 100 : 0) - (k[g_keys[K_CD]] ? 100 : 0);
    }
    if ((unsigned)i < 4 && g_pads[i]) {
        Pad gp = controller_read(g_pads[i], getenv("W3D_DUAL") != nullptr);
        o->connected |= gp.connected; b |= gp.buttons;
        if (gp.stick_x || gp.stick_y) { sx = gp.stick_x; sy = gp.stick_y; }
        if (gp.cstick_x || gp.cstick_y) { cx = gp.cstick_x; cy = gp.cstick_y; }
        if (gp.trigger_l > tl) tl = gp.trigger_l;
        if (gp.trigger_r > tr) tr = gp.trigger_r;
    }
    o->buttons = b; o->stick_x = (int8_t)sx; o->stick_y = (int8_t)sy; o->cstick_x = (int8_t)cx; o->cstick_y = (int8_t)cy;
    o->trigger_l = (uint8_t)tl; o->trigger_r = (uint8_t)tr;
    // Con las dos pantallas, la UI pulsa botones por el jugador y tapa el mando durante el arranque, como en la 3DS.
    static const bool dual = getenv("W3D_DUAL") != nullptr;
    // W3D_UI_KEYS (pruebas): esos botones también llegan al juego como en la 3DS.
    static const char *keys = getenv("W3D_UI_KEYS");
    if (dual && i == 0 && keys) {
        double el = now_seconds(); static double t0 = el; el -= t0;
        for (const char *c = keys; c && *c;) {
            char *e; double at = strtod(c, &e);
            const double dur = *e == ':' && e[1] && e[2] == '/' ? strtod(e + 3, nullptr) : 0.15;   // "<s>:<tecla>/<dur>"
            if (*e == ':' && el >= at && el < at + dur) {
                switch (e[1]) { case 'A': o->buttons |= BTN_A; break; case 'B': o->buttons |= BTN_B; break; case 'X': o->buttons |= BTN_X; break; case 'Y': o->buttons |= BTN_Y; break;
                                case 'S': o->buttons |= BTN_START; break; case 'U': o->buttons |= BTN_UP; break; case 'D': o->buttons |= BTN_DOWN; break; case 'I': o->buttons |= BTN_LEFT; break; case 'T': o->buttons |= BTN_RIGHT; break;
                                case 'l': o->buttons |= BTN_L; o->trigger_l = 255; break; case 'r': o->buttons |= BTN_R; o->trigger_r = 255; break; }   // gatillos
            }
            c = strchr(e, ','); if (c) c++;
        }
    }
    if (dual && i == 0) w3d_ui_pad(o);
}

static AudioPull g_audio_pull;
static void SDLCALL audio_feed(void *, SDL_AudioStream *stream, int additional, int) {
    static int16_t block[4096 * 2];
    while (additional > 0) {
        int frames = additional / 4;
        if (frames > 4096) frames = 4096;
        if (frames <= 0) break;
        g_audio_pull(block, frames);
        SDL_PutAudioStreamData(stream, block, frames * 4);
        additional -= frames * 4;
    }
}

bool audio_start(AudioPull pull) {
    g_audio_pull = pull;
    if (!SDL_InitSubSystem(SDL_INIT_AUDIO)) { fprintf(stderr, "audio: %s\n", SDL_GetError()); return false; }
    SDL_AudioSpec spec = {SDL_AUDIO_S16, 2, 32000};  // La frecuencia de la DSP de MusyX; SDL remuestrea al dispositivo.
    SDL_AudioStream *st = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec, audio_feed, nullptr);
    if (!st) { fprintf(stderr, "audio: %s\n", SDL_GetError()); return false; }
    // Las pruebas ocultas no suenan: el mezclador sigue corriendo y W3D_WAV graba igual.
    if (getenv("W3D_HIDDEN")) SDL_SetAudioStreamGain(st, 0.0f);
    SDL_ResumeAudioStreamDevice(st);
    return true;
}

void present_clear(float r, float g, float b) {
    @autoreleasepool {
        id<CAMetalDrawable> d = [g_layer nextDrawable];
        if (!d) return;
        MTLRenderPassDescriptor *p = [MTLRenderPassDescriptor renderPassDescriptor];
        p.colorAttachments[0].texture = d.texture;
        p.colorAttachments[0].loadAction = MTLLoadActionClear;
        p.colorAttachments[0].storeAction = MTLStoreActionStore;
        p.colorAttachments[0].clearColor = MTLClearColorMake(r, g, b, 1);
        id<MTLCommandBuffer> c = [g_queue commandBuffer];
        [[c renderCommandEncoderWithDescriptor:p] endEncoding];
        [c presentDrawable:d];
        [c commit];
        [c waitUntilCompleted];
        g_last = d.texture;
    }
}

void *metal_device() { return (__bridge void *)g_device; }
void *metal_queue() { return (__bridge void *)g_queue; }
void *metal_layer() { return g_hidden ? nullptr : (__bridge void *)g_layer; }
void set_presented_texture(void *t) { g_last = (__bridge id<MTLTexture>)t; }

bool capture_frame(const char *path) {
    if (!g_last) return false;
    NSUInteger w = g_last.width, h = g_last.height, row = w * 4;
    MTLTextureDescriptor *td = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:g_last.pixelFormat width:w height:h mipmapped:NO];
    td.storageMode = MTLStorageModeShared;
    id<MTLTexture> t = [g_device newTextureWithDescriptor:td];
    id<MTLCommandBuffer> c = [g_queue commandBuffer];
    id<MTLBlitCommandEncoder> e = [c blitCommandEncoder];
    [e copyFromTexture:g_last sourceSlice:0 sourceLevel:0 sourceOrigin:MTLOriginMake(0, 0, 0) sourceSize:MTLSizeMake(w, h, 1) toTexture:t destinationSlice:0 destinationLevel:0 destinationOrigin:MTLOriginMake(0, 0, 0)];
    [e endEncoding]; [c commit]; [c waitUntilCompleted];
    uint8_t *buf = (uint8_t *)malloc(row * h);
    [t getBytes:buf bytesPerRow:row fromRegion:MTLRegionMake2D(0, 0, w, h) mipmapLevel:0];
    FILE *f = fopen(path, "wb");
    if (!f) { free(buf); return false; }
    fprintf(f, "P6\n%lu %lu\n255\n", (unsigned long)w, (unsigned long)h);
    for (NSUInteger i = 0; i < w * h; i++) { uint8_t px[3] = {buf[i * 4 + 2], buf[i * 4 + 1], buf[i * 4]}; fwrite(px, 1, 3, f); }
    fclose(f); free(buf);
    return true;
}

}  // namespace plat
}  // namespace w3d
