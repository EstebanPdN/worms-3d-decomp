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
struct K4bMappedBox {
    struct K4bBox box;
    struct K4bIface *maps[5];
    unsigned char two_sided;
    char pad55[3];
    struct K4bIface *alpha;
    int enabled;
};
extern struct K4bIface *lbl_804b05a8;
extern void *lbl_80414da8[];
extern struct K4bBox *w3d_k4b_box_construct_801b5b30(struct K4bBox *self, void *);
static inline void k4b_ref_init(struct K4bIface **slot, struct K4bIface *iface)
{
    *slot = iface;
    if (iface != 0)
        ((void (*)(struct K4bIface *))iface->vtable[3])(iface);
}
struct K4bMappedBox *w3d_k4b_mapped_box_construct_801c1864(struct K4bMappedBox *self, void * arg_r4)
{
    w3d_k4b_box_construct_801b5b30(&self->box, arg_r4);
    self->box.vtable = lbl_80414da8;
    k4b_ref_init(&self->maps[0], lbl_804b05a8);
    k4b_ref_init(&self->maps[1], lbl_804b05a8);
    k4b_ref_init(&self->maps[2], lbl_804b05a8);
    k4b_ref_init(&self->maps[3], lbl_804b05a8);
    k4b_ref_init(&self->maps[4], lbl_804b05a8);
    self->two_sided = 0;
    k4b_ref_init(&self->alpha, lbl_804b05a8);
    self->enabled = 1;
    return self;
}
// desc: w3d_k4b_mapped_box_construct_801c1864: Appears to construct a derived bounds object over 0x801b5b30: vtable 0x80414da8, six retained shared default interfaces, a cleared flag byte, enabled set.
