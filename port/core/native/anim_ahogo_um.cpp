#include "parches_vfs.h"
extern "C" {
int w3d_anim_um_quiere(const char *) { return 0; }
int w3d_anim_um_tramos(W3dLeer, void *, unsigned, const W3dTramo **, int *) { return 0; }
const char *w3d_anim_um_clip(int) { return ""; }
int w3d_anim_um_entra(int) { return 0; }
int w3d_anim_um_activo(int) { return 0; }
int w3d_anim_um_sale(int) { return 0; }
float w3d_anim_um_peso(int) { return 0; }
float w3d_anim_um_tiempo(float) { return 0; }
}
