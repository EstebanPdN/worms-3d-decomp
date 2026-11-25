struct K1aColor { signed char r, g, b, a; };
struct K1aPopup { char pad0[84]; int mode; };
extern unsigned int w3d_color_804af3b4;
extern void w3d_hud_properties_8011adf8(void *, struct K1aColor *, unsigned int *);

void k1a_popup_set_mode_8004eae4(struct K1aPopup *self, int mode)
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
