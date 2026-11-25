/* Observed text-list cleanup, refresh and activation operations. */
extern "C" {
struct TextListObject { void (**vtable)(TextListObject *); };
struct TextListString { char *text; int reserved; };
struct TextListEntry { TextListObject *object; int reserved; TextListString name; };
struct TextListRange { TextListEntry **begin, **end; };
struct TextListWidget {
    void (**vtable)(TextListObject *); char unknown04[24]; int context;
    char unknown20[144]; int active; char unknownb4[12]; int busy;
    char unknownc4[60]; int pending; TextListObject *first, *second;
    char unknown10c[36]; TextListObject *resource; int unknown134; TextListObject *textValue;
    char unknown13c[20]; TextListRange entries; char unknown158[32]; TextListObject *box;
};
extern int w3d_global_804abb5c;
void w3d_string_base_finish(TextListString *);
void w3d_string_release(TextListString *);
void w3d_actor_member_delete_backend(void *);
void w3d_auto_8015fd1c(TextListObject *);
void w3d_list_flags_802a0e20(TextListWidget *, int, int);
void w3d_list_reset_802b0fec(void *);
TextListObject *w3d_empty_80343744(TextListObject *);
TextListString *w3d_auto_80179170(TextListObject *);
void w3d_list_set_active_802b0990(void *, int);
void w3d_list_apply_active_8029fc78(TextListWidget *);
void w3d_auto_80296518(TextListObject *, int);
void w3d_text_list_clear_8029f48c(TextListWidget *);
#if 0 /* Range-pointer and loop register allocation differ. */
void w3d_text_list_clear_8029f48c(TextListWidget *self)
{
    TextListRange *base = &self->entries;
    TextListEntry **entry = base->begin;
    if (entry != base->end) {
        register TextListRange *range = base;
        do {
            TextListEntry *item = *entry;
            if (item) {
                if (item->object) {
                    if (((TextListObject *(*)(TextListObject *))item->object->vtable[6])(item->object)) {
                        TextListObject *parent = ((TextListObject *(*)(TextListObject *))item->object->vtable[6])(item->object);
                        ((void (*)(TextListObject *, TextListObject *))parent->vtable[24])(parent, item->object);
                    }
                    register TextListObject *empty = 0;
                    if (item->object) item->object->vtable[4](item->object);
                    item->object = empty;
                }
                w3d_string_base_finish(&item->name);
                w3d_string_release(&item->name);
                if (item->object) item->object->vtable[4](item->object);
                w3d_actor_member_delete_backend(item);
            }
            ++entry;
        } while (entry != range->end);
    }
    self->entries.end = self->entries.begin;
}
#endif
void w3d_s4_text_list_reset(TextListWidget *self)
{
    register TextListObject *empty = 0;
    if (self->first) self->first->vtable[4](self->first);
    self->first = empty;
    if (self->second) self->second->vtable[4](self->second);
    self->second = empty;
    w3d_text_list_clear_8029f48c(self);
    if (self->resource) {
        w3d_auto_8015fd1c(self->resource);
        self->resource = empty;
    }
    w3d_list_flags_802a0e20(self, 1, 1);
    w3d_list_reset_802b0fec(&self->context);
}
#if 0 /* Refresh branch ordering and result register allocation differ. */
int w3d_s4_text_list_request_refresh(void *, TextListWidget *self)
{
    if (self->busy == 1) return 0;
    int result;
    if (self->context == w3d_global_804abb5c)
        result = ((int (*)(TextListWidget *))self->vtable[12])(self);
    else { self->pending = 1; result = 0; }
    return result;
}
#endif
int w3d_s4_text_list_refresh_value(TextListWidget *self)
{
    struct { TextListString *value; int reserved; } local;
    local.value = w3d_auto_80179170(w3d_empty_80343744(self->textValue));
    ((void (*)(TextListWidget *, const char *))self->vtable[11])(self, local.value->text);
    return 0;
}
void w3d_s4_text_list_set_active(TextListWidget *self, int active)
{
    int changed = 1;
    if (active == self->active) changed = 0;
    w3d_list_set_active_802b0990(&self->context, active);
    if (changed) {
        w3d_list_apply_active_8029fc78(self);
        if (self->box) w3d_auto_80296518(self->box, active);
    }
}
}
