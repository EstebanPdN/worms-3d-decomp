struct K4bString { char *text; };
struct K4bIface { void **vtable; };
struct K4bColor { float r, g, b, a; };
struct K4bVec3 { float x, y, z; };
struct K4bNamedColor {
    void **vtable;
    char base[16];
    struct K4bColor color;
    struct K4bString name;
    int enabled;
};
struct K4bLight {
    struct K4bNamedColor named;
    struct K4bIface *target;
    struct K4bVec3 offset;
    struct K4bIface *source;
};
extern struct K4bIface *lbl_804b05a8;
extern void *lbl_80414ce0[];
extern struct K4bNamedColor *w3d_k4b_named_color_construct_801b4bcc(struct K4bNamedColor *self, void *);
static inline void k4b_ref_init(struct K4bIface **slot, struct K4bIface *iface)
{
    *slot = iface;
    if (iface != 0)
        ((void (*)(struct K4bIface *))iface->vtable[3])(iface);
}
struct K4bLight *w3d_k4b_light_construct_801c3338(struct K4bLight *self, void * arg_r4)
{
    w3d_k4b_named_color_construct_801b4bcc(&self->named, arg_r4);
    self->named.vtable = lbl_80414ce0;
    k4b_ref_init(&self->target, lbl_804b05a8);
    self->offset.x = 0.0f;
    self->offset.y = 0.0f;
    self->offset.z = 0.0f;
    k4b_ref_init(&self->source, lbl_804b05a8);
    return self;
}
// desc: w3d_k4b_light_construct_801c3338: Appears to construct a derived named colour object over 0x801b4bcc: vtable 0x80414ce0, two retained shared interfaces and a zero offset vector.
