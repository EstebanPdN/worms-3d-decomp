#include "w3d_ptr.h"
#line 1 "s4_panel_helpers.cpp"
/* Observed panel scale, registration and selection cleanup operations. */
extern "C" {
struct HelperObject { Ptr32<Ptr32<void (Ptr32<HelperObject>)>> vtable; char unknown04[12]; int value; };
struct HelperConfig { char unknown00[8]; unsigned char flags; char w3d_tag_rest[3]; char unknown0c[108]; Ptr32<char> activateSound; Ptr32<char> unknown7c; Ptr32<HelperObject> font; };
struct HelperWidget { char unknown00[40]; Ptr32<HelperConfig> config; char unknown2c[68]; Ptr32<HelperObject> owner; char unknown74[24]; int enabled; char unknown90[32]; int active; char unknownb4[44]; Ptr32<HelperObject> container; int unknowne4; float width; char unknownec[140]; Ptr32<HelperObject> members[3]; char unknown184[8]; Ptr32<HelperObject> properties[2]; };
struct HelperRegistry { Ptr32<const char> name; int flags; int unknown08; int value; Ptr32<const void> descriptor; int unknown14; Ptr32<void> storage; int unknown1c; int unknown20; int state; };
struct HelperContext { char unknown00[52]; Ptr32<void> screen; };
extern HelperRegistry w3d_registry_80471144[];
extern const char w3d_str_803d2e60[];
extern const unsigned char w3d_descriptor_8040e5c8[], w3d_storage_80471140[];
extern const float w3d_f32_803d2e38[];
Ptr32<HelperObject> w3d_font_handle_8015ae3c(Ptr32<Ptr32<HelperObject>>);
Ptr32<HelperObject> w3d_empty_8034435c(Ptr32<HelperObject>);
float w3d_text_width_8018b4cc(Ptr32<HelperObject>, Ptr32<const char>);
void w3d_register_80200a70(Ptr32<HelperRegistry>);
void w3d_control_reset_802b0fec(Ptr32<void>);
void w3d_sound_play_802b1258(Ptr32<const char>);
void w3d_control_activate_802b0990(Ptr32<void>, int);
void w3d_panel_refresh_802a520c(Ptr32<HelperWidget>);
#if 0 /* All body words match, but the original has an extra 24-byte stack gap. */
float w3d_s4_panel_fit_text(HelperWidget *self, const char *text, float available, float maximumX, float maximumY)
{
    float width = w3d_text_width_8018b4cc(w3d_empty_8034435c(w3d_font_handle_8015ae3c(&self->config->font)), text);
    self->width = width;
    if (available < width) return w3d_f32_803d2e38[0];
    float scale = w3d_f32_803d2e38[0];
    if (width < scale) return scale;
    {
        scale = available / width;
        if (scale > maximumX) scale = maximumX;
        if (scale > maximumY) scale = maximumY;
        self->width = scale * width;
    }
    return scale;
}

#endif
int w3d_s4_frontend_register()
{
    Ptr32<HelperRegistry> registry = w3d_registry_80471144;
    registry->name = w3d_str_803d2e60;
    registry->descriptor = w3d_descriptor_8040e5c8;
    registry->storage = (Ptr32<void>)w3d_storage_80471140;
    registry->flags = 0;
    registry->value = 0;
    registry->state = 0;
    w3d_register_80200a70(registry);
    return 0;
}
void w3d_s4_panel_clear_container(Ptr32<HelperWidget> self)
{
    register unsigned int count = 0;
    if (self->members[0]) self->members[0]->vtable[4](self->members[0]);
    self->members[0] = (Ptr32<HelperObject>)w3d::G(count);
    if (self->members[1]) self->members[1]->vtable[4](self->members[1]);
    self->members[1] = (Ptr32<HelperObject>)w3d::G(count);
    if (self->members[2]) self->members[2]->vtable[4](self->members[2]);
    self->members[2] = (Ptr32<HelperObject>)w3d::G(count);
    register Ptr32<void> control = (Ptr32<char>)self + 28;
    if (self->container) {
        while ((count = ((Ptr32<unsigned int (Ptr32<HelperObject>)>)self->container->vtable[30])(self->container)) != 0) {
            Ptr32<HelperObject> container = self->container;
            Ptr32<Ptr32<void (Ptr32<HelperObject>)>> vtable = container->vtable;
            Ptr32<HelperObject> child = ((Ptr32<Ptr32<HelperObject> (Ptr32<HelperObject>, int)>)vtable[29])(container, 0);
            ((Ptr32<void (Ptr32<HelperObject>, Ptr32<HelperObject>)>)vtable[24])(container, child);
        }
        ((Ptr32<void (Ptr32<HelperObject>, Ptr32<HelperObject>)>)self->owner->vtable[24])(self->owner, self->container);
        if (self->container) self->container->vtable[4](self->container);
        self->container = (Ptr32<HelperObject>)w3d::G(count);
    }
    w3d_control_reset_802b0fec(control);
}
void w3d_s4_panel_set_active(Ptr32<HelperWidget> self, int active)
{
    if (self->active != active) {
        if (active) {
            Ptr32<HelperConfig> config = self->config;
            Ptr32<const char> sound = config->activateSound;
            if (*(Ptr32<unsigned short>)(sound - 4) && ((config->flags ^ 4) & 4) && self->enabled)
                w3d_sound_play_802b1258(sound);
            self->properties[0]->value = 1;
            self->properties[1]->value = 1;
        } else {
            self->properties[0]->value = active;
            self->properties[1]->value = active;
        }
    }
    w3d_control_activate_802b0990((Ptr32<char>)self + 28, active);
    w3d_panel_refresh_802a520c(self);
}
}


