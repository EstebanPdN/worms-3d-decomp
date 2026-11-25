struct K4bString { char *text; };
struct K4bIface { void **vtable; };
struct K4bBoundName {
    void **vtable;
    char base[16];
    struct K4bIface *owner;
    int index;
    struct K4bString name;
};
extern struct K4bIface *lbl_804b05ac;
extern char *lbl_804b06a0[];
extern void *lbl_804135a8[];
extern void *w3d_tagged_construct_801ea0ec(void *object, int);
extern void w3d_string_base_init(struct K4bString *string);
extern unsigned short *w3d_string_header(struct K4bString *string);
static inline void k4b_ref_init(struct K4bIface **slot, struct K4bIface *iface)
{
    *slot = iface;
    if (iface != 0)
        ((void (*)(struct K4bIface *))iface->vtable[3])(iface);
}
struct K4bBoundName *w3d_k4b_bound_name_construct_8019ad84(struct K4bBoundName *self, void * arg_r4)
{
    struct K4bString *name;
    w3d_tagged_construct_801ea0ec(self, arg_r4);
    self->vtable = lbl_804135a8;
    k4b_ref_init(&self->owner, lbl_804b05ac);
    self->index = 0;
    name = &self->name;
    w3d_string_base_init(name);
    self->name.text = lbl_804b06a0[0];
    ++*w3d_string_header(name);
    return self;
}
// desc: w3d_k4b_bound_name_construct_8019ad84: Appears to construct an object over 0x801ea0ec: vtable 0x804135a8, retained shared interface at +20, cleared index and an empty shared name string at +28.
