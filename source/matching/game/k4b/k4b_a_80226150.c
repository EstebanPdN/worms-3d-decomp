struct K4bString { char *text; };
struct K4bIface { void **vtable; };
struct K4bSlider {
    void **vtable;
    char base[16];
    struct K4bIface *style;
    struct K4bIface *font;
    int mode;
    float minimum;
    float maximum;
    struct K4bString label;
    int value;
};
extern struct K4bIface *lbl_804b05a8;
extern struct K4bIface *lbl_804b05b0;
extern char *lbl_804b06a0[];
extern void *lbl_8041a280[];
extern void *w3d_tagged_construct_801ea0ec(void *object, int);
extern void w3d_string_base_init(struct K4bString *string);
extern unsigned short *w3d_string_header(struct K4bString *string);
static inline void k4b_ref_init(struct K4bIface **slot, struct K4bIface *iface)
{
    *slot = iface;
    if (iface != 0)
        ((void (*)(struct K4bIface *))iface->vtable[3])(iface);
}
struct K4bSlider *w3d_k4b_slider_construct_80226150(struct K4bSlider *self, void * arg_r4)
{
    struct K4bString *label;
    char **empty;
    w3d_tagged_construct_801ea0ec(self, arg_r4);
    self->vtable = lbl_8041a280;
    k4b_ref_init(&self->style, lbl_804b05a8);
    k4b_ref_init(&self->font, lbl_804b05b0);
    self->mode = 3;
    self->minimum = 0.0f;
    self->maximum = 100.0f;
    label = &self->label;
    empty = lbl_804b06a0;
    w3d_string_base_init(label);
    self->label.text = *empty;
    ++*w3d_string_header(label);
    self->value = 0;
    return self;
}
// desc: w3d_k4b_slider_construct_80226150: Appears to construct a slider-like object over 0x801ea0ec: two retained shared interfaces, mode 3, range 0 to 100, empty label string and zero value.
