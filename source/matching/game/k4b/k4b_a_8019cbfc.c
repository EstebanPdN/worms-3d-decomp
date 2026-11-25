struct K4bPair { int first; int second; };
struct K4bLink { void *node; int count; };
struct K4bDualComponent {
    void **vtable;
    char base[36];
    int state;
    char pad44[8];
    struct K4bPair range_a;
    struct K4bLink link_a;
    struct K4bPair range_b;
    struct K4bLink link_b;
};
extern void *lbl_804136c0[];
extern void *lbl_80413680[];
extern void * fn_801e81c8(void *member);
static inline void k4b_pair_init(struct K4bPair *p)
{
    p->first = 0;
    p->second = 0;
}
static inline void k4b_link_init(struct K4bLink *l)
{
    l->count = 0;
}
struct K4bDualComponent *w3d_k4b_dual_component_construct_8019cbfc(struct K4bDualComponent *self)
{
    volatile char pad[16];
    self->vtable = lbl_804136c0;
    fn_801e81c8(self->base);
    self->vtable = lbl_80413680;
    self->state = 0;
    k4b_pair_init(&self->range_a);
    k4b_link_init(&self->link_a);
    k4b_pair_init(&self->range_b);
    k4b_link_init(&self->link_b);
    return self;
}
// desc: w3d_k4b_dual_component_construct_8019cbfc: Appears to construct a component with two range/link member pairs: base vtable, member at +4 via 0x801e81c8, derived vtable 0x80413680, then zeroed fields.
