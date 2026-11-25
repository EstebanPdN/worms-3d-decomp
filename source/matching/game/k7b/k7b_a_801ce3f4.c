struct K7bSettingsBlock { int words[16]; };
struct K7bSettingsObject { const void *vtable; char pad04[16]; struct K7bSettingsBlock settings; };
extern int w3d_ctor_801ce28c(struct K7bSettingsObject *self, void *);
extern const char lbl_80415e70[];
extern struct K7bSettingsBlock lbl_8045e708[];
struct K7bSettingsObject *w3d_k7b_settings_object_ctor_801ce3f4(struct K7bSettingsObject *self, void * arg_r4)
{
    w3d_ctor_801ce28c(self, arg_r4);
    self->vtable = lbl_80415e70;
    self->settings = lbl_8045e708[0];
    return self;
}
