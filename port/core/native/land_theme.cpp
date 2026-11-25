// Aplica el tema del escenario y la hora del día a los ajustes: nombres de archivo, niebla, agua y sonido ambiental.
#include "native_game.h"

namespace {
struct Vector3 { float x, y, z; };
struct LandThemeRow {
    Ptr32<const char> name;      // +0
    w3d_u32 skies[3];            // +4, por hora del día
    w3d_u32 use_first_fog[3];    // +0x10, por hora del día
    Ptr32<const char> music;     // +0x1c
    w3d_u32 pad2;
};
static_assert(sizeof(LandThemeRow) == 36, "las filas ocupan 36 B");
const int kThemeSamples = 0x59;
struct LandState {
    char pad[0xd08];
    w3d_u32 theme_index;         // +0xd08
    w3d_u32 pad2;
    GameString theme_name;       // +0xd10
};
}
extern "C" {
extern const char A8037ba40[], A8037ba44[], A8037ba4c[], A8037ba54[], A8037ba60[], A8037c1a4[], A8037c1d0[], A8037c1e4[], A8037c1f8[], A8037c20c[], A8037c218[], A8037c224[], A8037c234[], A8037c248[], A8037c254[];
extern const char A8037c268[], A8037c27c[], A8037c290[], A8037c2ac[], A8037c2c8[], A8037c2d8[], A8037c328[], A8037c33c[], A8037bbbc[], A8037c34c[], A8037c35c[], A8037c36c[], A8037c380[], A8037c390[];
extern const LandThemeRow A803f477c[];
extern const Ptr32<const char> A803f4878[], A803f45e4[kThemeSamples];
void A8020bd38(GameString *string, const char *text);
void A8020c2e8(GameString *string);
void A8020c510(GameString *string, const char *format, ...);
int A802ef234(const char *, const char *);
w3d_u32 A80162ba8();
int w3d_mapa_um_activo(void);   // mapa_um.cpp (v26): partida rápida con el mapa de Ultimate Mayhem
w3d_u32 A800fc2b0(void *key, void *out, ...);
w3d_u32 A800fc2f0(void *key, void *out, ...);
w3d_u32 A800fc230(void *key, void *out, ...);
void A800fc550(void *key, const char *text);
void A800fc3b0(void *key, w3d_u32 value);
void A800fc5dc(void *key, const Vector3 *value);
void A800fc43c(void *key, w3d_u32 value);

}
// Las lecturas de ajuste son métodos: el valor va en el destino.
template <class F, class T> static void read_setting(F reader, const char *name, T *out) {
    Ptr32<const char> key(name);
    ((w3d_u32 (*)(void *, void *))reader)(&key, out);
}
extern "C" {
static void write_text(const char *name, const char *text) {
    Ptr32<const char> key(name);
    A800fc550(&key, text);
}
static void write_int(const char *name, w3d_u32 value) {
    Ptr32<const char> key(name);
    A800fc43c(&key, value);
}
// 0x8006d854
void A8006d854(Ptr32<LandState> self) {
    Ptr32<const char> theme_setting, sky_setting;
    read_setting(A800fc2b0, A8037ba54, &theme_setting);
    read_setting(A800fc2b0, A8037ba60, &sky_setting);
    A8020bd38(&self->theme_name, theme_setting.get());
    ScopedString sky(sky_setting.get());
    A8020c2e8(&self->theme_name);
    A8020c2e8(&sky);
    if (!A802ef234(sky.text, A8037c1a4)) {
        switch (A80162ba8() % 3) {
        case 0: A8020bd38(&sky, A8037ba40); break;
        case 1: A8020bd38(&sky, A8037ba44); break;
        default: A8020bd38(&sky, A8037ba4c); break;
        }
    }
    Vector3 fog_near, fog_far;
    read_setting(A800fc2f0, A8037c1d0, &fog_near);
    read_setting(A800fc2f0, A8037c1e4, &fog_far);
    ScopedString scene, bundle, map, sound, initial_file, skybox, ambient;
    const char *theme = self->theme_name.text;
    const char *hour = sky.text;
    const char initial[2] = {theme[0], 0};
    A8020c510(&scene, A8037c1f8, hour, theme);
    A8020c510(&bundle, A8037c20c, theme, hour);
    A8020c510(&map, A8037c218, theme, hour);
    A8020c510(&sound, A8037c224, theme, hour);
    A8020c510(&initial_file, A8037c234, initial, hour);
    A8020c510(&skybox, A8037c248, theme_setting.get(), hour);
    A8020c510(&ambient, A8037c254, theme, hour);
    write_text(A8037c268, bundle.text);
    write_text(A8037c27c, map.text);
    write_text(A8037c290, sound.text);
    write_text(A8037c2ac, initial_file.text);
    write_text(A8037c2c8, skybox.text);
    write_text(A8037c2d8, ambient.text);
    const LandThemeRow *row = A803f477c;
    while (row->name && A802ef234(row->name, theme)) row++;
    if (!row->name) return;
    int hour_index = 0;
    while (A803f4878[hour_index] && A802ef234(A803f4878[hour_index], hour)) hour_index++;
    if (!A803f4878[hour_index]) return;
    {
        Ptr32<const char> key(A8037c328);
        A800fc3b0(&key, row->skies[hour_index]);
    }
    {
        Ptr32<const char> key(A8037c33c);
        A800fc5dc(&key, row->use_first_fog[hour_index] ? &fog_near : &fog_far);
    }
    write_text(A8037bbbc, row->music);
    ScopedString setting;
    w3d_u32 fog_enabled = 0;
    read_setting(A800fc230, A8037c34c, &fog_enabled);
    // Port (v26): el mapa de Ultimate Mayhem es un desierto (Lejano Oeste): sin lluvia ni nieve del tema anfitrión.
    if (fog_enabled == 1 && !w3d_mapa_um_activo()) {
        w3d_u32 value = 0;
        A8020c510(&setting, A8037c35c, row->name.get(), A803f4878[hour_index].get());
        Ptr32<char> key = setting.text;
        ((w3d_u32 (*)(void *, void *))A800fc230)(&key, &value);
        write_int(A8037c36c, value);
        A8020c510(&setting, A8037c380, row->name.get(), A803f4878[hour_index].get());
        value = 0;
        key = setting.text;
        ((w3d_u32 (*)(void *, void *))A800fc230)(&key, &value);
        write_int(A8037c390, value);
    } else {
        write_int(A8037c36c, 0);
        write_int(A8037c390, 0);
    }
    for (self->theme_index = 0; self->theme_index < kThemeSamples; self->theme_index++) {
        if (!A802ef234(scene.text, A803f45e4[self->theme_index])) break;
    }
}
}
