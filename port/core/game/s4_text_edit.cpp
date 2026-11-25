#include "w3d_ptr.h"
#line 1 "s4_text_edit.cpp"
/* Observed text-entry widget lifetime and cursor setup. */
extern "C" {
struct EditObject { Ptr32<Ptr32<void (Ptr32<EditObject>)>> vtable; };
struct EditString { Ptr32<char> text; };
struct EditRef { Ptr32<EditObject> object; int reserved; };
struct EditConfig { char unknown00[156]; Ptr32<char> cursorSound; char unknowna0[24]; int password; };
struct EditWidget { Ptr32<void> vtable; char unknown04[36]; Ptr32<EditConfig> config; char unknown2c[164]; Ptr32<Ptr32<void (Ptr32<void>)>> secondary; char unknownd4[176]; Ptr32<EditObject> members[4]; int length, unknown198; EditString value, oldValue, sound; int pending, state; };
extern const unsigned char w3d_vtable_8041c348[], w3d_vtable_8041c398[];
extern unsigned char w3d_message_804b0e70[8];
extern const char w3d_str_803d1ef0[], w3d_str_803d1f04[];
int w3d_text_list_ctor_8029dd4c(Ptr32<EditWidget>);
void w3d_text_list_dtor_8029de6c(Ptr32<EditWidget>, int);
Ptr32<void> w3d_string_default(Ptr32<EditString>);
void w3d_string_base_finish(Ptr32<EditString>);
void w3d_string_release(Ptr32<EditString>);
void w3d_string_assign(Ptr32<EditString>, Ptr32<const char>);
void w3d_string_assign_range(Ptr32<EditString>, Ptr32<const char>, unsigned int);
void w3d_string_release_header(Ptr32<void>);
unsigned int w3d_cached_message_id(Ptr32<void>, int);
int w3d_subscribe_80162024(Ptr32<EditWidget>, Ptr32<unsigned short>, Ptr32<Ptr32<EditObject>>);
int w3d_constructor_lookup_name(Ptr32<Ptr32<const char>>, Ptr32<EditRef>);
Ptr32<EditObject> w3d_constructor_native_cast(Ptr32<EditObject>);
void w3d_cursor_update_802a2524(Ptr32<EditWidget>);
void w3d_text_list_set_text_8029ec80(Ptr32<EditWidget>, Ptr32<const char>);
void w3d_edit_refresh_802a21ec(Ptr32<EditWidget>);
Ptr32<EditWidget> w3d_s4_text_edit_construct(Ptr32<EditWidget> self)
{
    w3d_text_list_ctor_8029dd4c(self);
    self->secondary = (Ptr32<Ptr32<void (Ptr32<void>)>>)w3d_vtable_8041c348;
    self->vtable = (Ptr32<void>)w3d_vtable_8041c398;
    self->members[0] = 0;
    self->members[1] = 0;
    self->members[2] = 0;
    self->members[3] = 0;
    w3d_string_default(&self->value);
    w3d_string_default(&self->oldValue);
    w3d_string_default(&self->sound);
    return self;
}
void w3d_s4_text_edit_destroy(Ptr32<EditWidget> self, int flags)
{
    self->secondary = (Ptr32<Ptr32<void (Ptr32<void>)>>)w3d_vtable_8041c348;
    self->vtable = (Ptr32<void>)w3d_vtable_8041c398;
    w3d_string_base_finish(&self->sound);
    w3d_string_release(&self->sound);
    w3d_string_base_finish(&self->oldValue);
    w3d_string_release(&self->oldValue);
    w3d_string_base_finish(&self->value);
    w3d_string_release(&self->value);
    if (self->members[3]) self->members[3]->vtable[4](self->members[3]);
    if (self->members[2]) self->members[2]->vtable[4](self->members[2]);
    if (self->members[1]) self->members[1]->vtable[4](self->members[1]);
    if (self->members[0]) self->members[0]->vtable[4](self->members[0]);
    w3d_text_list_dtor_8029de6c(self, flags);
}
void w3d_s4_text_edit_initialize_cursor(Ptr32<EditWidget> self)
{
    struct { EditRef ref; unsigned short id; unsigned short reserved; Ptr32<const char> query; } local;
    register int zero = 0;
    local.id = w3d_cached_message_id(w3d_message_804b0e70, 1);
    w3d_subscribe_80162024(self, &local.id, &self->members[2]);
    self->length = *(Ptr32<unsigned short>)(self->value.text - 4);
    self->pending = zero;
    ((Ptr32<void (Ptr32<void>, int)>)self->secondary[13])((Ptr32<char>)self + 28, 0);
    self->state = zero;
    local.ref.object = 0;
    local.query = w3d_str_803d1ef0;
    w3d_constructor_lookup_name(&local.query, &local.ref);
    Ptr32<EditObject> cursor = w3d_constructor_native_cast(local.ref.object);
    if (cursor) cursor->vtable[3](cursor);
    if (self->members[0]) self->members[0]->vtable[4](self->members[0]);
    self->members[0] = cursor;
    Ptr32<EditConfig> config = self->config;
    Ptr32<char> incoming = config->cursorSound;
    ++*(Ptr32<unsigned short>)(incoming - 6);
    Ptr32<char> old = self->sound.text;
    Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
    unsigned int remaining = *(Ptr32<unsigned short>)(old - 6) - 1;
    *(Ptr32<unsigned short>)(old - 6) = remaining;
    if (!(unsigned short)remaining) w3d_string_release_header(header);
    self->sound.text = config->cursorSound;
    w3d_cursor_update_802a2524(self);
    if (local.ref.object) local.ref.object->vtable[4](local.ref.object);
}
#if 0 /* Temporary-string argument setup order differs in four words. */
void w3d_s4_text_edit_set_text(EditWidget *self, const char *text)
{
    EditConfig *config = self->config;
    w3d_string_assign(&self->value, text);
    if (config->password == 1) {
        struct { EditString text; int reserved; } local;
        w3d_string_default(&local.text);
        register EditString *temporary = &local.text;
        w3d_string_assign_range(&local.text, w3d_str_803d1f04, *(unsigned short *)(self->value.text - 4));
        w3d_text_list_set_text_8029ec80(self, local.text.text);
        w3d_string_base_finish(temporary);
        w3d_string_release(temporary);
    } else w3d_text_list_set_text_8029ec80(self, text);
    w3d_edit_refresh_802a21ec(self);
}
#endif

}


