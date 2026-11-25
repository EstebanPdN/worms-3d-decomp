#include "w3d_ptr.h"
#line 1 "s4_choice_widget.cpp"
/* Observed choice-widget text segments, navigation and property notifications. */
extern "C" {
struct ChoiceObject { Ptr32<Ptr32<void (Ptr32<ChoiceObject>)>> vtable; };
struct ChoiceString { Ptr32<char> text; int reserved; };
struct ChoiceConfig { char unknown00[152]; Ptr32<char> segments; };
struct ChoiceWidget { char unknown00[40]; Ptr32<ChoiceConfig> config; char unknown2c[196]; int cursorId; char unknownf4[128]; int busy; char unknown178[12]; Ptr32<ChoiceObject> properties[2]; int unknown18c, unknown190; float current, target; int unknown19c; float otherTarget; Ptr32<char> parts[20]; Ptr32<char> cursorNames[20]; int partCount; unsigned int rows; int unknown24c, unknown250; int changed; unsigned int limit; int cursor, selection; unsigned int kind; int index; };
extern const char w3d_str_803d611c[];
extern const float w3d_f32_803d6180[], w3d_f32_803d6184[];
extern Ptr32<void> w3d_global_804abbac;
void w3d_string_base_init(Ptr32<ChoiceString>);
Ptr32<unsigned short> w3d_string_header(Ptr32<ChoiceString>);
void w3d_string_base_finish(Ptr32<ChoiceString>);
void w3d_string_release(Ptr32<ChoiceString>);
void w3d_string_release_header(Ptr32<void>);
void w3d_string_assign(Ptr32<ChoiceString>, Ptr32<const char>);
void w3d_string_trim_8020c3a0(Ptr32<Ptr32<char>>, unsigned int);
unsigned int w3d_span_802ef380(Ptr32<const char>, Ptr32<const char>);
void w3d_choice_edge_802b22b0(Ptr32<void>);
void w3d_choice_apply_802a70fc(Ptr32<ChoiceWidget>, int);
Ptr32<ChoiceObject> w3d_empty_803426b4(Ptr32<ChoiceObject>);
Ptr32<ChoiceObject> w3d_constructor_native_cast(Ptr32<ChoiceObject>);
int w3d_auto_80178c48(Ptr32<ChoiceObject>);
int w3d_auto_80178d1c(Ptr32<ChoiceObject>);
int w3d_cursor_find_8028496c(Ptr32<void>, Ptr32<ChoiceString>);
void w3d_choice_cursor_802a73d4(Ptr32<ChoiceWidget>);
void w3d_choice_refresh_802a77a4(Ptr32<ChoiceWidget>);
void w3d_choice_update_802a6ce8(Ptr32<ChoiceWidget>);
#if 0 /* String slot addressing and temporary-pointer register allocation differ. */
void w3d_s4_choice_split_text(ChoiceWidget *self)
{
    self->partCount = 0;
    ChoiceConfig *config = self->config;
    if (*(unsigned short *)(config->segments - 4)) {
        ChoiceString text;
        register ChoiceString *remaining = &text;
        w3d_string_base_init(&text);
        text.text = config->segments;
        ++*w3d_string_header(&text);
        while (*(unsigned short *)(text.text - 4)) {
            char *incoming = text.text;
            ++*(unsigned short *)(incoming - 6);
            char **slot = &self->parts[self->partCount];
            char *old = *slot;
            unsigned short *header = (unsigned short *)(old - 6);
            unsigned int count = *(unsigned short *)(old - 6) - 1;
            *(unsigned short *)(old - 6) = count;
            if (!(unsigned short)count) w3d_string_release_header(header);
            *slot = text.text;
            if (self->partCount == 10) break;
            ++self->partCount;
            char *part = self->parts[self->partCount - 1];
            unsigned int length = w3d_span_802ef380(part, w3d_str_803d611c);
            if (part[length] == '\\') {
                w3d_string_trim_8020c3a0(&self->parts[self->partCount - 1], length);
                ++length;
            }
            w3d_string_assign(remaining, text.text + length);
        }
        self->changed = 1;
        w3d_string_base_finish(remaining);
        w3d_string_release(remaining);
    }
}

#endif
void w3d_s4_choice_next(Ptr32<ChoiceWidget> self)
{
    int index = self->index;
    if (self->current != self->target) return;
    if (self->rows <= self->limit) {
        w3d_choice_edge_802b22b0((Ptr32<char>)self + 28);
        return;
    }
    switch (self->kind) {
    case 0: if (index == 7) index = -1; else ++index; break;
    case 2: if (index == 8) index = 0; else ++index; break;
    case 1:
    default: if (index == 4) index = 0; else ++index; break;
    }
    if (index != self->index) w3d_choice_apply_802a70fc(self, index);
}
void w3d_s4_choice_previous(Ptr32<ChoiceWidget> self)
{
    int index = self->index;
    if (self->current != self->target) return;
    if (self->rows <= self->limit) {
        w3d_choice_edge_802b22b0((Ptr32<char>)self + 28);
        return;
    }
    switch (self->kind) {
    case 0:
        if (index == -1) index = 7;
        else if (index > 0) --index;
        else index = -1;
        break;
    case 2: if (index > 0) --index; else index = 8; break;
    case 1:
    default: if (index > 0) --index; else index = 4; break;
    }
    if (index != self->index) w3d_choice_apply_802a70fc(self, index);
}
#if 0 /* Cursor-name slot address and retained-string register allocation differ. */
void w3d_choice_cursor_802a73d4(ChoiceWidget *self)
{
    int kind = ((int (*)(ChoiceObject *))self->properties[0]->vtable[6])(self->properties[0]);
    switch (kind) {
    case 0: self->cursor = w3d_auto_80178c48(w3d_empty_803426b4(self->properties[0])); break;
    case 1: self->cursor = w3d_auto_80178d1c(w3d_constructor_native_cast(self->properties[0])); break;
    }
    struct { ChoiceString text; } local;
    struct CursorNameSlot { char unknown00[500]; char *name; };
    register CursorNameSlot *slot = (CursorNameSlot *)((char *)self + self->cursor * 4);
    w3d_string_base_init(&local.text);
    register char **name = &slot->name;
    local.text.text = *name;
    register unsigned short *header = w3d_string_header(&local.text);
    ++*header;
    self->cursorId = w3d_cursor_find_8028496c(w3d_global_804abbac, &local.text);
}

#endif
void w3d_s4_choice_update_selection(Ptr32<ChoiceWidget> self)
{
    int kind = ((Ptr32<int (Ptr32<ChoiceObject>)>)self->properties[1]->vtable[6])(self->properties[1]);
    switch (kind) {
    case 0: self->selection = w3d_auto_80178c48(w3d_empty_803426b4(self->properties[1])); break;
    case 1: self->selection = w3d_auto_80178d1c(w3d_constructor_native_cast(self->properties[1])); break;
    }
}
int w3d_s4_choice_cursor_changed(Ptr32<void>, Ptr32<ChoiceWidget> self)
{
    if (self->busy) return 0;
    w3d_choice_cursor_802a73d4(self);
    self->target = w3d_f32_803d6180[0];
    return 0;
}
int w3d_s4_choice_selection_changed(Ptr32<void>, Ptr32<ChoiceWidget> self)
{
    if (self->busy) return 0;
    w3d_s4_choice_update_selection(self);
    self->otherTarget = w3d_f32_803d6184[0];
    return 0;
}
int w3d_s4_choice_refresh_changed(Ptr32<void>, Ptr32<ChoiceWidget> self)
{
    if (self->busy) return 0;
    w3d_choice_refresh_802a77a4(self);
    w3d_choice_update_802a6ce8(self);
    return 0;
}
}


