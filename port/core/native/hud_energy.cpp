// Barras de vida de los equipos en la UI de dos pantallas: siempre a la vista, fijas arriba de la pantalla de abajo
// (gx_metal.mm, position_battle_ui). El HUD original las retira bajo la pantalla durante el turno con 0x80066010 (las
// cuatro hacia HUD.Energy.OffScreen, 0x800647cc) y allí las apila sin separación; aquí esa retirada se da por hecha sin
// moverlas. Sin las dos pantallas hace lo del original (source/matching/game/s7/s7hand_80066010.c).
#include "native_game.h"
#include <stdlib.h>
extern "C" {
int w3d_fe_native_layout(void);   // fe_layout.cpp
w3d_u32 A80164fc8(w3d_u32);
w3d_u32 A800647cc(w3d_u32);
w3d_u32 A80066010(w3d_u32 self) {
    if (w3d_fe_native_layout()) return 1;   // dos pantallas (Mac con W3D_DUAL, 3DS): fijas arriba de la de abajo
    w3d_u32 done = 1;
    for (int i = 0; i < 4; ++i) {
        const w3d_u32 bar = *(const w3d_u32 *)g2h(self + 0x1c + 4 * i);
        if (!A800647cc(A80164fc8(bar))) done = 0;
    }
    return done;
}
}
