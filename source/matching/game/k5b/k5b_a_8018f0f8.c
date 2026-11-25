struct K5bIface { void **vtable; };
struct K5bLinkSet {
    void **vtable;
    char base[16];
    struct K5bIface *links[8];
    unsigned char active;
};
extern struct K5bIface *lbl_804b05ac;
extern void *lbl_80413098[];
extern void *w3d_tagged_construct_801ea0ec(void *object, int);
static inline void k5b_ref_init(struct K5bIface **slot, struct K5bIface *iface)
{
    *slot = iface;
    if (iface != 0)
        ((void (*)(struct K5bIface *))iface->vtable[3])(iface);
}
struct K5bLinkSet *w3d_k5b_link_set_construct_8018f0f8(struct K5bLinkSet *self, void * arg_r4)
{
    w3d_tagged_construct_801ea0ec(self, arg_r4);
    self->vtable = lbl_80413098;
    k5b_ref_init(&self->links[0], lbl_804b05ac);
    k5b_ref_init(&self->links[1], lbl_804b05ac);
    k5b_ref_init(&self->links[2], lbl_804b05ac);
    k5b_ref_init(&self->links[3], lbl_804b05ac);
    k5b_ref_init(&self->links[4], lbl_804b05ac);
    k5b_ref_init(&self->links[5], lbl_804b05ac);
    k5b_ref_init(&self->links[6], lbl_804b05ac);
    k5b_ref_init(&self->links[7], lbl_804b05ac);
    self->active = 0;
    return self;
}
// desc: w3d_k5b_link_set_construct_8018f0f8: Appears to construct an object over 0x801ea0ec: vtable 0x80413098, eight retained shared default interfaces at +20..+48 and a cleared byte flag at +52.
