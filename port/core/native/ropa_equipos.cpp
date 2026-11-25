// Sombrero por equipo (port, pedido del dueño, 2026-11-07: «como en Ultimate Mayhem, que elijo un sombrero para cada
// equipo»). El de Developer (w3d_hat_mode, core/native/hat_militar.cpp) sigue valiendo para los equipos que no tienen
// uno propio; el de la página Outfit de Crear equipo (platform/ui/ui_pages.cpp) manda sobre él, también «sin sombrero».
// - Se guarda por nombre de equipo en ropa_equipos.txt, en la carpeta de ajustes del port (Mac: ~/Library/Application
//   Support/Worms3D; 3DS: la de la SD), una línea «<sombrero> <nombre>» por equipo, el nombre tal cual (Latin-1).
// - En la partida, d28d_worm_attach_weapon_mesh_801394ac.cpp pregunta por cada worm: su gráfico lleva el índice del worm
//   en +112 (f9b_weapon_voice_8013bbc8), la ficha del worm (0x800fc6dc) su equipo en +0xd5 (hud_abajo.cpp) y la del
//   equipo (0x800fc7f8) su nombre en +0x1c (s1_commentary.cpp).
#include "native_game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
w3d_u32 A800fc6dc(void *worm);
w3d_u32 A800fc7f8(void *group);
extern volatile int w3d_hat_mode;
int w3d_hat_count(void);
#if defined(__3DS__)
const char *w3d_sd_root(void);
#endif
}

namespace {
struct TeamHat { char name[48]; int hat; };
TeamHat g_teams[64]; int g_count; bool g_loaded;
const char *path() {
    static char p[1100];
    if (!p[0]) {
#if defined(__3DS__)
        snprintf(p, sizeof p, "%s/ropa_equipos.txt", w3d_sd_root());
#else
        snprintf(p, sizeof p, "%s/Library/Application Support/Worms3D/ropa_equipos.txt", getenv("HOME") ? getenv("HOME") : "/tmp");
#endif
    }
    return p;
}
void load() {
    if (g_loaded) return;
    g_loaded = true;
    FILE *f = fopen(path(), "r");
    if (!f) return;
    char line[128];
    while (g_count < 64 && fgets(line, sizeof line, f)) {
        line[strcspn(line, "\r\n")] = 0;
        char *sp = strchr(line, ' ');
        if (!sp || !sp[1]) continue;
        *sp = 0;
        TeamHat &t = g_teams[g_count++];
        t.hat = atoi(line);
        snprintf(t.name, sizeof t.name, "%s", sp + 1);
    }
    fclose(f);
}
void save() {
    FILE *f = fopen(path(), "w");
    if (!f) return;
    for (int i = 0; i < g_count; i++) fprintf(f, "%d %s\n", g_teams[i].hat, g_teams[i].name);
    fclose(f);
}
int find(const char *team) {
    for (int i = 0; i < g_count; i++) if (!strcmp(g_teams[i].name, team)) return i;
    return -1;
}
}  // namespace

// Sombrero propio del equipo (0 ninguno), o -1 si no tiene (vale el de Developer).
extern "C" int w3d_team_hat_get(const char *team) {
    load();
    const int i = team && *team ? find(team) : -1;
    return i < 0 ? -1 : g_teams[i].hat;
}
// hat -1: quita el propio.
extern "C" void w3d_team_hat_set(const char *team, int hat) {
    if (!team || !*team) return;
    load();
    int i = find(team);
    if (hat < 0) {
        if (i < 0) return;
        g_teams[i] = g_teams[--g_count];
    } else {
        if (hat > w3d_hat_count()) hat = 0;
        if (i < 0) {
            if (g_count >= 64) return;
            i = g_count++;
            snprintf(g_teams[i].name, sizeof g_teams[i].name, "%s", team);
        } else if (g_teams[i].hat == hat) return;
        g_teams[i].hat = hat;
    }
    save();
}
// El sombrero que lleva el worm de este gráfico en la partida.
extern "C" int w3d_hat_for_worm(Ptr32<char> graphic) {
    const int global = w3d_hat_mode;
    if (!graphic) return global;
    load();
    if (!g_count) return global;
    const int index = *(int *)(graphic.get() + 112);
    if (index < 0 || index > 15) return global;
    const w3d_u32 info = A800fc6dc(arg((w3d_u32)index));
    if (!info) return global;
    const unsigned team = *at<uint8_t>(info + 0xd5);
    if (team > 15) return global;
    const w3d_u32 group = A800fc7f8(arg((w3d_u32)team));
    if (!group) return global;
    const w3d_u32 text = *at<w3d_u32>(group + 0x1c);
    if (!text) return global;
    const int i = find(at<const char>(text));
    const int hat = i < 0 ? global : g_teams[i].hat;
    // W3D_ROPA_LOG: la primera vez de cada worm, qué equipo y qué sombrero (pruebas).
    static const bool log = getenv("W3D_ROPA_LOG") != nullptr; static unsigned seen;
    if (log && !(seen >> index & 1)) { seen |= 1u << index; fprintf(stderr, "[ropa] worm %d equipo %u '%s' sombrero %d\n", index, team, at<const char>(text), hat); }
    return hat;
}
