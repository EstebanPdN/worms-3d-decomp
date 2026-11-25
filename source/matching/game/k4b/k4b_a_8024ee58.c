struct K4bString { char *text; };
struct K4bIface { void **vtable; };
struct K4bBoundLabel {
    void **vtable;
    char base[16];
    struct K4bIface *owner;
    struct K4bString name;
};
extern struct K4bIface *lbl_804b05a8;
extern char *lbl_804b06a0[];
extern void *lbl_8041b780[];
extern void *w3d_tagged_construct_801ea0ec(void *object, int);
extern void w3d_string_base_init(struct K4bString *string);
extern unsigned short *w3d_string_header(struct K4bString *string);
static inline void k4b_ref_init(struct K4bIface **slot, struct K4bIface *iface)
{
    *slot = iface;
    if (iface != 0)
        ((void (*)(struct K4bIface *))iface->vtable[3])(iface);
}
struct K4bBoundLabel *w3d_k4b_bound_label_construct_8024ee58(struct K4bBoundLabel *self, void * arg_r4)
{
    struct K4bString *name;
    char **empty;
    w3d_tagged_construct_801ea0ec(self, arg_r4);
    self->vtable = lbl_8041b780;
    k4b_ref_init(&self->owner, lbl_804b05a8);
    name = &self->name;
    empty = lbl_804b06a0;
    w3d_string_base_init(name);
    self->name.text = *empty;
    ++*w3d_string_header(name);
    return self;
}
// desc: w3d_k4b_bound_label_construct_8024ee58: Appears to construct an object over 0x801ea0ec: vtable 0x8041b780, retained shared interface at +20 and an empty shared name string at +24.
