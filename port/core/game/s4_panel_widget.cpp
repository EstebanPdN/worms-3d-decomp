#include "w3d_ptr.h"
#line 1 "s4_panel_widget.cpp"
/* Observed panel-widget construction, cleanup and message routing. */
extern "C" {
struct PanelObject { Ptr32<Ptr32<void (Ptr32<PanelObject>)>> vtable; };
struct PanelString { Ptr32<char> text; int reserved; };
struct PanelVector { float x,y,z; };
struct PanelConfig { char unknown00[20]; float width,height; char unknown1c[104]; int box; };
struct PanelWidget { Ptr32<void> vtable; char unknown04[36]; Ptr32<PanelConfig> config; char unknown2c[68]; Ptr32<PanelObject> owner; char unknown74[92]; Ptr32<void> secondary; Ptr32<PanelObject> handle; Ptr32<PanelObject> label; Ptr32<PanelObject> children[3]; float value; };
struct PanelMessage { unsigned short id; };
struct PanelContext { char unknown00[52]; Ptr32<void> screen; };
extern const unsigned char w3d_vtable_8041c3e0[], w3d_vtable_8041c430[];
extern const float w3d_f32_803d2e04[], w3d_f32_803d2e24[];
extern const PanelVector w3d_vector_8045e788[];
extern const char w3d_str_803d2e08[], w3d_str_803d2e14[];
void w3d_ctor_8015fef0(Ptr32<PanelWidget>);
void w3d_control_construct_802afb20(Ptr32<void>);
void w3d_control_destroy_802afc40(Ptr32<void>, int);
void w3d_base_destroy_8015ff2c(Ptr32<PanelWidget>, int);
int w3d_auto_8015fb34(Ptr32<PanelWidget>, Ptr32<PanelMessage>);
int w3d_control_ready_802b264c(Ptr32<void>);
void w3d_control_message_802aff9c(Ptr32<void>, Ptr32<PanelMessage>);
void w3d_panel_update_802a32e0(Ptr32<PanelWidget>);
void w3d_panel_layout_802a3784(Ptr32<PanelWidget>);
Ptr32<PanelContext> w3d_engine_get_context();
void w3d_control_setup_802b0b84(Ptr32<void>, Ptr32<PanelWidget>, Ptr32<void>);
void w3d_label_destroy_8025e0c4(Ptr32<PanelObject>, int);
void w3d_control_reset_802b0fec(Ptr32<void>);
void w3d_string_from_text(Ptr32<PanelString>, Ptr32<const char>);
void w3d_string_base_finish(Ptr32<PanelString>);
void w3d_string_release(Ptr32<PanelString>);
Ptr32<void> w3d_heap_allocate_entry_a(unsigned int);
Ptr32<PanelObject> w3d_label_create_8025dffc(Ptr32<void>, Ptr32<const char>, unsigned int);
void w3d_label_bounds_8025e128(Ptr32<PanelObject>, float, float, float);
void w3d_label_position_8025ee60(Ptr32<PanelObject>, Ptr32<PanelVector>);
void w3d_label_attach_8025ee94(Ptr32<PanelObject>, Ptr32<PanelObject>);
void w3d_s4_panel_setup_box(Ptr32<PanelWidget> self);
void w3d_s4_panel_reset(Ptr32<PanelWidget> self);
void w3d_s4_panel_initialize(Ptr32<PanelWidget> self);
#if 0 /* Null-handle cleanup and constructor store scheduling differ. */
PanelWidget *w3d_s4_panel_construct(PanelWidget *self)
{
    register PanelObject *empty = 0;
    w3d_ctor_8015fef0(self);
    w3d_control_construct_802afb20((char *)self + 28);
    self->children[2] = 0;
    self->handle = 0;
    self->label = 0;
    self->children[0] = 0;
    self->children[1] = 0;
    self->secondary = (void *)w3d_vtable_8041c3e0;
    self->vtable = (void *)w3d_vtable_8041c430;
    self->value = w3d_f32_803d2e04[0];
    if (empty) empty->vtable[4](empty);
    self->children[2] = empty;
    return self;
}

#endif
void w3d_s4_panel_destroy(Ptr32<PanelWidget> self, int flags)
{
    self->secondary = (Ptr32<void>)w3d_vtable_8041c3e0;
    self->vtable = (Ptr32<void>)w3d_vtable_8041c430;
    if (self->children[2]) self->children[2]->vtable[4](self->children[2]);
    if (self->children[1]) self->children[1]->vtable[4](self->children[1]);
    if (self->children[0]) self->children[0]->vtable[4](self->children[0]);
    if (self->handle) self->handle->vtable[4](self->handle);
    w3d_control_destroy_802afc40((Ptr32<char>)self + 28, 0);
    w3d_base_destroy_8015ff2c(self, flags);
}
#if 0 /* Self, message and embedded-control register allocation differ. */
int w3d_s4_panel_message(PanelWidget *self, PanelMessage *message)
{
    switch (message->id) {
    case 64:
        if (w3d_auto_8015fb34(self, message) >= 0) {
            w3d_s4_panel_initialize(self);
            return 0;
        }
        return (int)0x80004005;
    case 66: w3d_s4_panel_reset(self); break;
    default:
        register void *control = (char *)self + 28;
        if (w3d_control_ready_802b264c(control))
            w3d_control_message_802aff9c(control, message);
    }
    return w3d_auto_8015fb34(self, message);
}

#endif
#if 0 /* Embedded-control argument setup omits the original intermediate register. */
void w3d_s4_panel_initialize(PanelWidget *self)
{
    PanelContext *context = w3d_engine_get_context();
    register void *control = (char *)self + 28;
    w3d_control_setup_802b0b84(control, self, context->screen);
    w3d_s4_panel_setup_box(self);
    w3d_panel_update_802a32e0(self);
    w3d_panel_layout_802a3784(self);
}

#endif
void w3d_s4_panel_reset(Ptr32<PanelWidget> self)
{
    if (self->label) {
        w3d_label_destroy_8025e0c4(self->label, 3);
        self->label = 0;
    }
    if (self->children[0]) {
        ((Ptr32<void (Ptr32<PanelObject>, Ptr32<PanelObject>)>)self->owner->vtable[24])(self->owner, self->children[0]);
        if (self->children[0]) self->children[0]->vtable[4](self->children[0]);
        self->children[0] = 0;
    }
    if (self->children[1]) {
        ((Ptr32<void (Ptr32<PanelObject>, Ptr32<PanelObject>)>)self->owner->vtable[24])(self->owner, self->children[1]);
        if (self->children[1]) self->children[1]->vtable[4](self->children[1]);
        self->children[1] = 0;
    }
    if (self->children[2]) {
        ((Ptr32<void (Ptr32<PanelObject>, Ptr32<PanelObject>)>)self->owner->vtable[24])(self->owner, self->children[2]);
        if (self->children[2]) self->children[2]->vtable[4](self->children[2]);
        self->children[2] = 0;
    }
    w3d_control_reset_802b0fec((Ptr32<char>)self + 28);
}
#if 0 /* Local string pointer and vector-copy instruction scheduling differ. */
void w3d_s4_panel_setup_box(PanelWidget *self)
{
    struct { PanelString name; PanelVector position; } local;
    w3d_string_from_text(&local.name, w3d_str_803d2e08);
    PanelConfig *config = self->config;
    register PanelString *name = &local.name;
    if (!config->box) {
        w3d_string_base_finish(name);
        w3d_string_release(name);
        return;
    }
    local.position.x = w3d_vector_8045e788[0].x;
    local.position.y = w3d_vector_8045e788[0].y;
    local.position.z = w3d_vector_8045e788[0].z;
    self->label = w3d_label_create_8025dffc(w3d_heap_allocate_entry_a(4), w3d_str_803d2e14,
        (unsigned char)(*((unsigned char *)self + 35) + 29));
    w3d_label_bounds_8025e128(self->label, w3d_f32_803d2e24[0], config->width, config->height);
    w3d_label_position_8025ee60(self->label, &local.position);
    w3d_label_attach_8025ee94(self->label, self->owner);
    w3d_string_base_finish(name);
    w3d_string_release(name);
}
#endif

}


