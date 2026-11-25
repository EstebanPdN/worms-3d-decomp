struct K4bVec3 { float x, y, z; };
struct K4bIface { void **vtable; };
struct K4bBox {
    void **vtable;
    char base[16];
    struct K4bVec3 min;
    struct K4bVec3 max;
    int valid;
    int slots[4];
};
struct K4bTexturedBox {
    struct K4bBox box;
    struct K4bIface *texture;
    struct K4bIface *mask;
    struct K4bIface *shader;
    int flags;
    struct K4bIface *detail;
};
extern struct K4bIface *lbl_804b05a8;
extern struct K4bIface *lbl_804b05b0;
extern void *lbl_80415a78[];
extern struct K4bBox *w3d_k4b_box_construct_801b5b30(struct K4bBox *self, void *);
static inline void k4b_ref_init(struct K4bIface **slot, struct K4bIface *iface)
{
    *slot = iface;
    if (iface != 0)
        ((void (*)(struct K4bIface *))iface->vtable[3])(iface);
}
struct K4bTexturedBox *w3d_k4b_textured_box_construct_801b6308(struct K4bTexturedBox *self, void * arg_r4)
{
    w3d_k4b_box_construct_801b5b30(&self->box, arg_r4);
    self->box.vtable = lbl_80415a78;
    k4b_ref_init(&self->texture, lbl_804b05a8);
    k4b_ref_init(&self->mask, lbl_804b05a8);
    k4b_ref_init(&self->shader, lbl_804b05b0);
    self->flags = 0;
    k4b_ref_init(&self->detail, lbl_804b05a8);
    return self;
}
// desc: w3d_k4b_textured_box_construct_801b6308: Appears to construct a derived bounds object over 0x801b5b30 that retains three shared default interfaces (and one more) into +64..+80.
