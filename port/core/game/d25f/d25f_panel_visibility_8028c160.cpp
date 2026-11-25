#include "w3d_ptr.h"
#line 1 "d25f_panel_visibility_8028c160.cpp"
// GWMP8P rev0 0x8028c160. Panel state refresh: shows or hides three icons
// and three widgets from two flags, then copies a mesh colour. bool is 4
// bytes on this target, which gives the lwz and xori forms; the nested if
// with both arms assigning gives the compare and two li forms.
struct D25fIface;
struct D25fIfaceTable { char pad[88]; Ptr32<void (Ptr32<D25fIface>, bool)> set_visible; };
struct D25fIface { Ptr32<D25fIfaceTable> vt; };
struct D25fColour { unsigned char r, g, b, a; };
struct D25fWidget;
extern "C" void w3d_auto_8025f064(Ptr32<D25fWidget> widget, bool visible);
extern "C" Ptr32<D25fColour> w3d_auto_80178f54(Ptr32<void> mesh);
extern "C" int w3d_mesh_set_colour_80173df0(Ptr32<void> mesh, Ptr32<D25fColour> colour);
struct D25fPanel {
    char pad0[140];
    bool enabled; char w3d_tag_rest141[3];
    char pad144[32];
    bool selected; char w3d_tag_rest177[3];
    char pad180[32];
    Ptr32<D25fWidget> widget_a; Ptr32<D25fWidget> widget_b; Ptr32<D25fWidget> widget_c;
    Ptr32<void> mesh;
    Ptr32<void> colour_mesh;
    Ptr32<D25fIface> icon_a; Ptr32<D25fIface> icon_b; Ptr32<D25fIface> icon_c;
};
extern "C" void d25f_panel_visibility_8028c160(Ptr32<D25fPanel> self) {
    bool a = !self->selected;
    bool b = self->selected;
    bool c = !self->enabled;
    if (!self->enabled) {
        if (self->icon_c) {
            a = false;
            b = false;
        } else {
            a = true;
            b = false;
        }
    }
    if (self->icon_a) self->icon_a->vt->set_visible(self->icon_a, a);
    if (self->icon_b) self->icon_b->vt->set_visible(self->icon_b, b);
    if (self->icon_c) self->icon_c->vt->set_visible(self->icon_c, c);
    if (self->widget_a) w3d_auto_8025f064(self->widget_a, a);
    if (self->widget_b) w3d_auto_8025f064(self->widget_b, b);
    if (self->widget_c) w3d_auto_8025f064(self->widget_c, c);
    D25fColour colour = *w3d_auto_80178f54(self->colour_mesh);
    if (self->selected) colour.a = 255;
    if (self->mesh) w3d_mesh_set_colour_80173df0(self->mesh, &colour);
}


