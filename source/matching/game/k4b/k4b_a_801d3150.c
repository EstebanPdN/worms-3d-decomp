struct K4bPair { int first; int second; };
struct K4bLink { void *node; int count; };
struct K4bString { char *text; int length; };
struct K4bNamedComponent {
    void **vtable;
    char base[36];
    struct K4bString name;
    int field_30;
    int field_34;
    struct K4bLink link_a;
    int field_40;
    char pad44[4];
    struct K4bPair range;
    struct K4bLink link_b;
};
extern void *lbl_80416518[];
extern void *lbl_804164d0[];
extern void * fn_801e81c8(void *member);
extern void * w3d_string_default(struct K4bString *string);
static inline void k4b_pair_init(struct K4bPair *p)
{
    p->first = 0;
    p->second = 0;
}
static inline void k4b_link_init(struct K4bLink *l)
{
    l->count = 0;
}
struct K4bNamedComponent *w3d_k4b_named_component_construct_801d3150(struct K4bNamedComponent *self)
{
    volatile char pad[16];
    self->vtable = lbl_80416518;
    fn_801e81c8(self->base);
    self->vtable = lbl_804164d0;
    w3d_string_default(&self->name);
    self->field_30 = 0;
    self->field_34 = 0;
    k4b_link_init(&self->link_a);
    k4b_pair_init(&self->range);
    k4b_link_init(&self->link_b);
    self->field_40 = 0;
    return self;
}
// desc: w3d_k4b_named_component_construct_801d3150: Appears to construct a named component: base vtable, member at +4 via 0x801e81c8, derived vtable 0x804164d0, default name string at +40 and zeroed fields.
