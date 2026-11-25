// Ganchos de la prueba automática de 3DS (platform/3ds/test_3ds.cpp): qué gusano tiene el turno, si su equipo es
// humano, y elegir un arma como lo haría el panel. Mismos accesos que team_stats.cpp (ActiveWormIndex, grupo en +0xd5,
// grupo de la IA si +0x34 vale 1) y que W3D_CLOCK_WEAPON en sdk_core.cpp (munición, retrasos y Weapon.PanelChanged).
#include "native_game.h"
#include <stdio.h>
#include <string.h>

extern "C" {
w3d_u32 A800fc1f0(void *key, void *out, ...);
w3d_u32 A800fc6dc(void *worm);
w3d_u32 A800fc7f8(void *group);
w3d_u32 A800fc330(void *key, void *out, ...);
w3d_u32 A8015f5a0(void *name, w3d_u32 create);
void A800f90e8(int, int, int);
extern w3d_u32 A804b178c, A804af684, A8044a5c4[4];
int w3d_match_clock(unsigned *ms);

// 1 si hay partida y un gusano con el turno: su índice, su grupo (equipo) y si el grupo es humano.
int w3d_test_active_worm(int *worm, int *group, int *human) {
    unsigned ms;
    if (!w3d_match_clock(&ms)) return 0;
    Ptr32<const char> key("ActiveWormIndex");
    int index = -1;
    ((w3d_u32 (*)(void *, void *))A800fc1f0)(&key, &index);
    if (index < 0 || index > 15) return 0;
    w3d_u32 info = A800fc6dc(arg((w3d_u32)index));
    if (!info) return 0;
    unsigned g = *at<uint8_t>(info + 0xd5);
    if (g > 3) return 0;
    w3d_u32 ginfo = A800fc7f8(arg(g));
    // Medido en Azahar (v18): +0x34 vale 1 en el grupo de la IA y 0 en el humano (+0x2c es 0 en los dos).
    *worm = index; *group = (int)g; *human = ginfo && *at<w3d_u32>(ginfo + 0x34) == 0;
    static int last = -1;
    if (index != last) {
        last = index;
        fprintf(stderr, "[prueba] ActiveWormIndex %d grupo %u info %08x grupo_info %08x", index, g, (unsigned)info, (unsigned)ginfo);
        if (ginfo) for (int o = 0; o < 0x40; o += 4) fprintf(stderr, " %02x:%08x", o, (unsigned)*at<w3d_u32>(ginfo + o));
        fprintf(stderr, "\n");
    }
    return 1;
}

// Elige el arma <weapon> (orden de kWeapon...: 0 bazuca, 1 granada, 8 escopeta, 18 oveja...) para el equipo del
// gusano <worm>: le da munición (5 de cada) y quita los retrasos por ronda, y manda Weapon.PanelChanged.
void w3d_test_select_weapon(int worm, int weapon) {
    if (!A804b178c) return;
    w3d_u32 info = A800fc6dc(arg((w3d_u32)worm));
    if (!info) return;
    unsigned g = *at<uint8_t>(info + 0xd5);
    if (g > 3 || !A8044a5c4[g]) return;
    char *team = (char *)g2h(*at<w3d_u32>(*at<w3d_u32>(A8044a5c4[g] + 4) + 0x1c));
    memset(team + 0x14, 5, 0x47 - 0x14);
    Ptr32<const char> delays_name("Inventory.WeaponDelays"); Ptr32<char> delays{(char *)nullptr};
    ((w3d_u32 (*)(void *, void *))A800fc330)(&delays_name, &delays);
    if (delays) memset((char *)delays.get() + 0x14, 0, 0x47 - 0x14);
    A800f90e8((unsigned short)A8015f5a0(&A804af684, 1), weapon, *at<w3d_u32>(A804b178c + 0x34) + 10);
}
}

extern "C" {
w3d_u32 A800fc2b0(void *key, void *out, ...);
// Menú del frontend en curso (propiedad FE.CurrentMenu, como texto). nullptr si no hay.
const char *w3d_test_fe_menu(void) {
    Ptr32<const char> key("FE.CurrentMenu");
    Ptr32<const char> name{(const char *)nullptr};
    ((w3d_u32 (*)(void *, void *))A800fc2b0)(&key, &name);
    return name ? name.get() : nullptr;
}
}
