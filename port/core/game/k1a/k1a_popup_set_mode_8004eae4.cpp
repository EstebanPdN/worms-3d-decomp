#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k1a_popup_set_mode_8004eae4.c"
struct K1aColor { signed char r, g, b, a; };
struct K1aPopup { char pad0[84]; int mode; };
extern unsigned int w3d_color_804af3b4;
extern void w3d_hud_properties_8011adf8(Ptr32<void>, Ptr32<struct K1aColor>, Ptr32<unsigned int>);

void k1a_popup_set_mode_8004eae4(Ptr32<struct K1aPopup> self, int mode)
{
    self->mode = mode;
    if (mode < 0) {
        struct { struct K1aColor color; int gap; } local;
        local.color.r = 50;
        local.color.g = -1;
        local.color.b = 50;
        local.color.a = -1;
        w3d_hud_properties_8011adf8(self, &local.color, &w3d_color_804af3b4);
    }
}

}
