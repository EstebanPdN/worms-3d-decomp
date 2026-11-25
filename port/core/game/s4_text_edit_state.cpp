#include "w3d_ptr.h"
#line 1 "s4_text_edit_state.cpp"
/* Observed editor activation and property refresh. */
extern "C" {
struct EditorObject { Ptr32<Ptr32<void (Ptr32<EditorObject>)>> vtable; };
struct EditorConfig { char unknown00[8]; unsigned char flags; char w3d_tag_rest[3]; char unknown0c[168]; Ptr32<char> activateSound; };
struct EditorWidget { char unknown00[40]; Ptr32<EditorConfig> config; char unknown2c[96]; int enabled; char unknown90[64]; Ptr32<Ptr32<void (Ptr32<void>)>> secondary; char unknownd4[180]; Ptr32<EditorObject> cursor; char unknown18c[16]; Ptr32<char> text; char unknown1a0[8]; int pending, state; };
void w3d_list_activate_8029fc08(Ptr32<EditorWidget>, int);
void w3d_editor_refresh_802a21ec(Ptr32<EditorWidget>);
void w3d_sound_play_802b1258(Ptr32<const char>);
int w3d_list_refresh_8029fbb8(Ptr32<EditorWidget>);
void w3d_s4_text_edit_set_active(Ptr32<EditorWidget> self, int active)
{
    w3d_list_activate_8029fc08(self, active);
    if (active) {
        w3d_editor_refresh_802a21ec(self);
        Ptr32<EditorConfig> config = self->config;
        Ptr32<const char> sound = config->activateSound;
        if (*(Ptr32<unsigned short>)(sound - 4) && ((config->flags ^ 4) & 4) && self->enabled)
            w3d_sound_play_802b1258(sound);
    } else {
        if (self->cursor) ((Ptr32<void (Ptr32<EditorObject>, int)>)self->cursor->vtable[22])(self->cursor, 0);
        self->pending = active;
        ((Ptr32<void (Ptr32<void>, int)>)self->secondary[13])((Ptr32<char>)self + 28, 0);
    }
}
int w3d_s4_text_edit_refresh_value(Ptr32<EditorWidget> self)
{
    int state = self->state;
    if (state) return 0;
    int result = w3d_list_refresh_8029fbb8(self);
    if (self->cursor) ((Ptr32<void (Ptr32<EditorObject>, int)>)self->cursor->vtable[22])(self->cursor, 0);
    self->pending = state;
    ((Ptr32<void (Ptr32<void>, int)>)self->secondary[13])((Ptr32<char>)self + 28, 0);
    *(Ptr32<int>)((Ptr32<char>)self + 404) = *(Ptr32<unsigned short>)(self->text - 4);
    return result;
}
}


