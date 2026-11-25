struct K4bVec3 { float x, y, z; };
struct K4bIface { void **vtable; };
struct K4bSegment {
    void **vtable;
    char base[16];
    struct K4bVec3 start;
    struct K4bVec3 end;
    struct K4bIface *owner;
    int counts[3];
};
extern struct K4bIface *lbl_804b05a8;
extern void *lbl_80414bf0[];
extern void *w3d_tagged_construct_801ea0ec(void *object, int);
static inline void k4b_vec3_set(struct K4bVec3 *v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}
static inline void k4b_ref_init(struct K4bIface **slot, struct K4bIface *iface)
{
    *slot = iface;
    if (iface != 0)
        ((void (*)(struct K4bIface *))iface->vtable[3])(iface);
}
struct K4bSegment *w3d_k4b_segment_construct_801c482c(struct K4bSegment *self, void * arg_r4)
{
    w3d_tagged_construct_801ea0ec(self, arg_r4);
    self->vtable = lbl_80414bf0;
    k4b_vec3_set(&self->start, 0.0f, 0.0f, 0.0f);
    k4b_vec3_set(&self->end, 0.0f, 0.0f, 0.0f);
    k4b_ref_init(&self->owner, lbl_804b05a8);
    self->counts[0] = 0;
    self->counts[1] = 0;
    self->counts[2] = 0;
    return self;
}
// desc: w3d_k4b_segment_construct_801c482c: Appears to construct an object over 0x801ea0ec: vtable 0x80414bf0, two zero vectors, a retained shared interface at +44 and three cleared counters.
