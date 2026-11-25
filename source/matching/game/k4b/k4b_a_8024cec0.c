struct K4bIface { void **vtable; };
struct K4bWidgetBase { void **vtable; char data[48]; };
struct K4bWidget {
    struct K4bWidgetBase base;
    float rect[4];
    int field_44;
    int field_48;
    struct K4bIface *style;
    struct K4bIface *font;
    int params[3];
    struct K4bIface *cursor;
    unsigned short state_a;
    unsigned short state_b;
    unsigned short state_c;
    unsigned char enabled_a;
    unsigned char enabled_b;
    unsigned char hidden_a;
    unsigned char hidden_b;
};
extern struct K4bIface *lbl_804b05a8;
extern struct K4bIface *lbl_804b05ac;
extern void *lbl_8041b870[];
extern void *w3d_auto_8024cd0c(struct K4bWidgetBase *base, void *);
static inline void k4b_ref_init(struct K4bIface **slot, struct K4bIface *iface)
{
    *slot = iface;
    if (iface != 0)
        ((void (*)(struct K4bIface *))iface->vtable[3])(iface);
}
struct K4bWidget *w3d_k4b_widget_construct_8024cec0(struct K4bWidget *self, void * arg_r4)
{
    w3d_auto_8024cd0c(&self->base, arg_r4);
    self->base.vtable = lbl_8041b870;
    self->field_44 = 0;
    self->rect[0] = 0.0f;
    self->rect[1] = 0.0f;
    self->rect[2] = 0.0f;
    self->rect[3] = 0.0f;
    self->field_48 = 0;
    k4b_ref_init(&self->style, lbl_804b05a8);
    k4b_ref_init(&self->font, lbl_804b05ac);
    self->params[0] = 0;
    self->params[1] = 0;
    self->params[2] = 0;
    k4b_ref_init(&self->cursor, lbl_804b05a8);
    self->state_a = 0;
    self->state_b = 0;
    self->state_c = 0;
    self->enabled_a = 1;
    self->enabled_b = 1;
    self->hidden_a = 0;
    self->hidden_b = 0;
    return self;
}
// desc: w3d_k4b_widget_construct_8024cec0: Appears to construct a widget over 0x8024cd0c: vtable 0x8041b870, zero rectangle, three retained shared interfaces, cleared state words and enabled flags.
