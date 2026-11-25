struct K4bString { char *text; };
struct K4bIface { void **vtable; };
struct K4bNamed {
    void **vtable;
    char base[16];
    struct K4bString name;
    int value;
};
struct K4bNamedRefs {
    struct K4bNamed named;
    struct K4bIface *first;
    struct K4bIface *second;
    int flags;
    struct K4bIface *third;
    struct K4bIface *fourth;
    struct K4bIface *fifth;
};
extern struct K4bIface *lbl_804b05a8;
extern void *lbl_804162a8[];
extern struct K4bNamed *w3d_k4b_named_construct_801c90c0(struct K4bNamed *self, void *);
static inline void k4b_ref_init(struct K4bIface **slot, struct K4bIface *iface)
{
    *slot = iface;
    if (iface != 0)
        ((void (*)(struct K4bIface *))iface->vtable[3])(iface);
}
struct K4bNamedRefs *w3d_k4b_named_refs_construct_801ca578(struct K4bNamedRefs *self, void * arg_r4)
{
    w3d_k4b_named_construct_801c90c0(&self->named, arg_r4);
    self->named.vtable = lbl_804162a8;
    k4b_ref_init(&self->first, lbl_804b05a8);
    k4b_ref_init(&self->second, lbl_804b05a8);
    self->flags = 0;
    k4b_ref_init(&self->third, lbl_804b05a8);
    k4b_ref_init(&self->fourth, lbl_804b05a8);
    k4b_ref_init(&self->fifth, lbl_804b05a8);
    return self;
}
// desc: w3d_k4b_named_refs_construct_801ca578: Appears to construct a derived named object over 0x801c90c0: vtable 0x804162a8, five retained shared default interfaces and a cleared word at +36.
