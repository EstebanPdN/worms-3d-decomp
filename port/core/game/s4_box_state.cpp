#include "w3d_ptr.h"
#line 1 "s4_box_state.cpp"
/* Observed box widget state, border selection and retained interfaces. */
extern "C" {
struct BoxInterface { Ptr32<Ptr32<void (Ptr32<BoxInterface>)>> vtable; int unknown04[3]; int value; };
struct BoxString { Ptr32<char> text; };
struct BoxVector { int x, y, z; };
struct BoxWidget {
    Ptr32<void> vtable; char unknown04[28]; BoxVector position; char unknown2c[12];
    int ready, active, unknown40, editing, highlighted, enabled;
    char unknown50[40]; Ptr32<BoxInterface> interfaces[10]; char unknowna0[12];
    int style; BoxString border; int sound; Ptr32<BoxInterface> properties[9];
};
struct BoxRef { Ptr32<BoxInterface> object; int reserved; };
struct BoxInput { char unknown00[96]; unsigned int low:24; unsigned int capture:1; unsigned int high:7; };
extern Ptr32<BoxInput> w3d_global_804aac54;
extern const unsigned char w3d_vtable_8041c230[];
extern const char w3d_str_803d0814[], w3d_str_803d0828[], w3d_str_803d07a0[];
extern const float w3d_f32_803d0810[], w3d_f32_803d0838[];
extern BoxString w3d_global_804b06a0[];
void w3d_string_base_init(Ptr32<BoxString>);
Ptr32<unsigned short> w3d_string_header(Ptr32<BoxString>);
void w3d_string_base_finish(Ptr32<BoxString>);
void w3d_string_release(Ptr32<BoxString>);
void w3d_base_destroy_8015ff2c(Ptr32<BoxWidget>, int);
void w3d_string_assign(Ptr32<BoxString>, Ptr32<const char>);
Ptr32<const char> w3d_border_name_80263bb8(int);
int w3d_sound_stop_80263cfc(Ptr32<BoxString>, int, float);
int w3d_constructor_lookup_name(Ptr32<Ptr32<const char>>, Ptr32<BoxRef>);
Ptr32<BoxInterface> w3d_empty_80342a74(Ptr32<BoxInterface>);
float w3d_auto_80178df0(Ptr32<BoxInterface>);
void w3d_s4_box_destroy(Ptr32<BoxWidget> self, int flags)
{
    self->vtable = (Ptr32<void>)w3d_vtable_8041c230;
    if (self->properties[7]) self->properties[7]->vtable[4](self->properties[7]);
    if (self->properties[6]) self->properties[6]->vtable[4](self->properties[6]);
    if (self->properties[5]) self->properties[5]->vtable[4](self->properties[5]);
    if (self->properties[4]) self->properties[4]->vtable[4](self->properties[4]);
    if (self->properties[3]) self->properties[3]->vtable[4](self->properties[3]);
    if (self->properties[2]) self->properties[2]->vtable[4](self->properties[2]);
    if (self->properties[1]) self->properties[1]->vtable[4](self->properties[1]);
    if (self->properties[0]) self->properties[0]->vtable[4](self->properties[0]);
    w3d_string_base_finish(&self->border);
    w3d_string_release(&self->border);
    if (self->interfaces[9]) self->interfaces[9]->vtable[4](self->interfaces[9]);
    if (self->interfaces[8]) self->interfaces[8]->vtable[4](self->interfaces[8]);
    if (self->interfaces[7]) self->interfaces[7]->vtable[4](self->interfaces[7]);
    if (self->interfaces[6]) self->interfaces[6]->vtable[4](self->interfaces[6]);
    if (self->interfaces[5]) self->interfaces[5]->vtable[4](self->interfaces[5]);
    if (self->interfaces[4]) self->interfaces[4]->vtable[4](self->interfaces[4]);
    if (self->interfaces[3]) self->interfaces[3]->vtable[4](self->interfaces[3]);
    if (self->interfaces[2]) self->interfaces[2]->vtable[4](self->interfaces[2]);
    if (self->interfaces[1]) self->interfaces[1]->vtable[4](self->interfaces[1]);
    if (self->interfaces[0]) self->interfaces[0]->vtable[4](self->interfaces[0]);
    w3d_base_destroy_8015ff2c(self, flags);
}
void w3d_s4_box_stop_sound(Ptr32<BoxWidget> self)
{
    if (self->sound != -1) {
        struct { BoxString name; int reserved; } local;
        register Ptr32<BoxString> soundName = w3d_global_804b06a0;
        w3d_string_base_init(&local.name);
        local.name.text = soundName->text;
        ++*w3d_string_header(&local.name);
        w3d_sound_stop_80263cfc(&local.name, self->sound, w3d_f32_803d0810[0]);
        self->sound = -1;
    }
}
void w3d_s4_box_reset(Ptr32<BoxWidget> self)
{
    w3d_s4_box_stop_sound(self);
    self->editing = 0;
    w3d_global_804aac54->capture = self->editing;
    if (self->interfaces[0])
        ((Ptr32<void (Ptr32<BoxInterface>, Ptr32<BoxInterface>)>)self->interfaces[0]->vtable[24])(self->interfaces[0], self->interfaces[1]);
}
void w3d_s4_box_set_position(Ptr32<BoxWidget> self, Ptr32<const BoxVector> value)
{
    Ptr32<const BoxVector> current = &self->position;
    int equal = 0;
    if (current->x == value->x && current->y == value->y)
        equal = current->z == value->z;
    if (!equal) {
        self->position = *value;
        if (self->ready == 1) {
            Ptr32<BoxInterface> object = self->interfaces[1];
            ((Ptr32<void (Ptr32<BoxInterface>, Ptr32<BoxVector>, int)>)object->vtable[19])(object, &self->position, 0);
        }
    }
}
void w3d_s4_box_update_border(Ptr32<BoxWidget> self)
{
    if (self->highlighted) w3d_string_assign(&self->border, w3d_str_803d0814);
    else if (!self->enabled) w3d_string_assign(&self->border, w3d_str_803d0828);
    else w3d_string_assign(&self->border, w3d_border_name_80263bb8(self->style));
}
void w3d_s4_box_update_properties(Ptr32<BoxWidget> self)
{
    int editing = self->editing;
    int highlight = self->highlighted;
    register int cachedHighlight = highlight;
    int selected = 1;
    if (!editing) selected = 0;
    int marked = 1;
    if (!highlight) marked = 0;
    int both = selected & marked;
    int available = 1;
    if (!((editing ^ 1) & cachedHighlight & self->enabled)) available = 0;
    self->properties[0]->value = 0;
    self->properties[2]->value = available;
    self->properties[3]->value = both;
    self->properties[4]->value = available;
    self->properties[5]->value = available;
    self->properties[1]->value = both;
    self->properties[6]->value = available;
    self->properties[7]->value = available;
}
float w3d_s4_box_border_thickness()
{
    struct { BoxRef ref; Ptr32<const char> name; int reserved[3]; } local;
    local.ref.object = 0;
    local.name = w3d_str_803d07a0;
    w3d_constructor_lookup_name(&local.name, &local.ref);
    struct { float value; int reserved; } result;
    result.value = w3d_auto_80178df0(w3d_empty_80342a74(local.ref.object)) * w3d_f32_803d0838[0];
    if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
    return result.value;
}
}


