/* Observed editor activation and property refresh. */
extern "C" {
struct EditorObject { void (**vtable)(EditorObject *); };
struct EditorConfig { char unknown00[11]; unsigned char flags; char unknown0c[168]; char *activateSound; };
struct EditorWidget { char unknown00[40]; EditorConfig *config; char unknown2c[96]; int enabled; char unknown90[64]; void (**secondary)(void *); char unknownd4[180]; EditorObject *cursor; char unknown18c[16]; char *text; char unknown1a0[8]; int pending, state; };
void w3d_list_activate_8029fc08(EditorWidget *, int);
void w3d_editor_refresh_802a21ec(EditorWidget *);
void w3d_sound_play_802b1258(const char *);
int w3d_list_refresh_8029fbb8(EditorWidget *);
void w3d_s4_text_edit_set_active(EditorWidget *self, int active)
{
    w3d_list_activate_8029fc08(self, active);
    if (active) {
        w3d_editor_refresh_802a21ec(self);
        EditorConfig *config = self->config;
        const char *sound = config->activateSound;
        if (*(unsigned short *)(sound - 4) && ((config->flags ^ 4) & 4) && self->enabled)
            w3d_sound_play_802b1258(sound);
    } else {
        if (self->cursor) ((void (*)(EditorObject *, int))self->cursor->vtable[22])(self->cursor, 0);
        self->pending = active;
        ((void (*)(void *, int))self->secondary[13])((char *)self + 28, 0);
    }
}
int w3d_s4_text_edit_refresh_value(EditorWidget *self)
{
    int state = self->state;
    if (state) return 0;
    int result = w3d_list_refresh_8029fbb8(self);
    if (self->cursor) ((void (*)(EditorObject *, int))self->cursor->vtable[22])(self->cursor, 0);
    self->pending = state;
    ((void (*)(void *, int))self->secondary[13])((char *)self + 28, 0);
    *(int *)((char *)self + 404) = *(unsigned short *)(self->text - 4);
    return result;
}
}
