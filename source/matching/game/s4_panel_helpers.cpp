/* Observed panel scale, registration and selection cleanup operations. */
extern "C" {
struct HelperObject { void (**vtable)(HelperObject *); char unknown04[12]; int value; };
struct HelperConfig { char unknown00[11]; unsigned char flags; char unknown0c[108]; char *activateSound; char *unknown7c; HelperObject *font; };
struct HelperWidget { char unknown00[40]; HelperConfig *config; char unknown2c[68]; HelperObject *owner; char unknown74[24]; int enabled; char unknown90[32]; int active; char unknownb4[44]; HelperObject *container; int unknowne4; float width; char unknownec[140]; HelperObject *members[3]; char unknown184[8]; HelperObject *properties[2]; };
struct HelperRegistry { const char *name; int flags; int unknown08; int value; const void *descriptor; int unknown14; void *storage; int unknown1c; int unknown20; int state; };
struct HelperContext { char unknown00[52]; void *screen; };
extern HelperRegistry w3d_registry_80471144[];
extern const char w3d_str_803d2e60[];
extern const unsigned char w3d_descriptor_8040e5c8[], w3d_storage_80471140[];
extern const float w3d_f32_803d2e38[];
HelperObject *w3d_font_handle_8015ae3c(HelperObject **);
HelperObject *w3d_empty_8034435c(HelperObject *);
float w3d_text_width_8018b4cc(HelperObject *, const char *);
void w3d_register_80200a70(HelperRegistry *);
void w3d_control_reset_802b0fec(void *);
void w3d_sound_play_802b1258(const char *);
void w3d_control_activate_802b0990(void *, int);
void w3d_panel_refresh_802a520c(HelperWidget *);
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
    HelperRegistry *registry = w3d_registry_80471144;
    registry->name = w3d_str_803d2e60;
    registry->descriptor = w3d_descriptor_8040e5c8;
    registry->storage = (void *)w3d_storage_80471140;
    registry->flags = 0;
    registry->value = 0;
    registry->state = 0;
    w3d_register_80200a70(registry);
    return 0;
}
void w3d_s4_panel_clear_container(HelperWidget *self)
{
    register unsigned int count = 0;
    if (self->members[0]) self->members[0]->vtable[4](self->members[0]);
    self->members[0] = (HelperObject *)count;
    if (self->members[1]) self->members[1]->vtable[4](self->members[1]);
    self->members[1] = (HelperObject *)count;
    if (self->members[2]) self->members[2]->vtable[4](self->members[2]);
    self->members[2] = (HelperObject *)count;
    register void *control = (char *)self + 28;
    if (self->container) {
        while ((count = ((unsigned int (*)(HelperObject *))self->container->vtable[30])(self->container)) != 0) {
            HelperObject *container = self->container;
            void (**vtable)(HelperObject *) = container->vtable;
            HelperObject *child = ((HelperObject *(*)(HelperObject *, int))vtable[29])(container, 0);
            ((void (*)(HelperObject *, HelperObject *))vtable[24])(container, child);
        }
        ((void (*)(HelperObject *, HelperObject *))self->owner->vtable[24])(self->owner, self->container);
        if (self->container) self->container->vtable[4](self->container);
        self->container = (HelperObject *)count;
    }
    w3d_control_reset_802b0fec(control);
}
void w3d_s4_panel_set_active(HelperWidget *self, int active)
{
    if (self->active != active) {
        if (active) {
            HelperConfig *config = self->config;
            const char *sound = config->activateSound;
            if (*(unsigned short *)(sound - 4) && ((config->flags ^ 4) & 4) && self->enabled)
                w3d_sound_play_802b1258(sound);
            self->properties[0]->value = 1;
            self->properties[1]->value = 1;
        } else {
            self->properties[0]->value = active;
            self->properties[1]->value = active;
        }
    }
    w3d_control_activate_802b0990((char *)self + 28, active);
    w3d_panel_refresh_802a520c(self);
}
}
