struct K4bIface { void **vtable; };
struct K4bCounterSet {
    void **vtable;
    char base[16];
    int head[6];
    struct K4bIface *owner;
    int tail[7];
};
extern struct K4bIface *lbl_804b05ac;
extern void *lbl_8041ae00[];
extern void *w3d_tagged_construct_801ea0ec(void *object, int);
extern void w3d_props_set_i32_80240b9c(struct K4bCounterSet *self, int value);
static inline void k4b_ref_init(struct K4bIface **slot, struct K4bIface *iface)
{
    *slot = iface;
    if (iface != 0)
        ((void (*)(struct K4bIface *))iface->vtable[3])(iface);
}
struct K4bCounterSet *w3d_k4b_counter_set_construct_8023af50(struct K4bCounterSet *self, void * arg_r4)
{
    w3d_tagged_construct_801ea0ec(self, arg_r4);
    self->vtable = lbl_8041ae00;
    self->head[0] = 0;
    self->head[1] = 0;
    self->head[2] = 0;
    self->head[3] = 0;
    self->head[4] = 0;
    self->head[5] = 0;
    k4b_ref_init(&self->owner, lbl_804b05ac);
    self->tail[0] = 0;
    self->tail[1] = 0;
    self->tail[2] = 0;
    self->tail[3] = 0;
    self->tail[4] = 0;
    self->tail[5] = 0;
    self->tail[6] = 0;
    w3d_props_set_i32_80240b9c(self, 0);
    return self;
}
// desc: w3d_k4b_counter_set_construct_8023af50: Appears to construct an object over 0x801ea0ec: vtable 0x8041ae00, thirteen cleared words around a retained shared interface at +44, then sets property zero.
