struct K4bString { char *text; };
struct K4bIface { void **vtable; };
struct K4bColor { float r, g, b, a; };
struct K4bNamedColor {
    void **vtable;
    char base[16];
    struct K4bColor color;
    struct K4bString name;
    int enabled;
};
struct K4bMaterialSlot {
    struct K4bNamedColor named;
    struct K4bIface *texture;
    struct K4bIface *mask;
    struct K4bIface *shader;
    struct K4bIface *detail;
};
extern struct K4bIface *lbl_804b05a8;
extern struct K4bIface *lbl_804b05ac;
extern struct K4bIface *lbl_804b05b0;
extern void *lbl_8041b7a8[];
extern struct K4bNamedColor *w3d_k4b_named_color_construct_801b4bcc(struct K4bNamedColor *self, void *);
static inline void k4b_ref_init(struct K4bIface **slot, struct K4bIface *iface)
{
    *slot = iface;
    if (iface != 0)
        ((void (*)(struct K4bIface *))iface->vtable[3])(iface);
}
struct K4bMaterialSlot *w3d_k4b_material_slot_construct_8024e980(struct K4bMaterialSlot *self, void * arg_r4)
{
    w3d_k4b_named_color_construct_801b4bcc(&self->named, arg_r4);
    self->named.vtable = lbl_8041b7a8;
    k4b_ref_init(&self->texture, lbl_804b05ac);
    k4b_ref_init(&self->mask, lbl_804b05a8);
    k4b_ref_init(&self->shader, lbl_804b05b0);
    k4b_ref_init(&self->detail, lbl_804b05a8);
    return self;
}
// desc: w3d_k4b_material_slot_construct_8024e980: Appears to construct a derived named colour object over 0x801b4bcc: vtable 0x8041b7a8 and four retained shared default interfaces at +44..+56.
