struct K4bVec3 { float x, y, z; };
struct K4bIface { void **vtable; };
struct K4bEmitterDesc {
    void **vtable;
    char base[16];
    struct K4bVec3 origin;
    struct K4bVec3 direction;
    struct K4bVec3 spread;
    float rate;
    int kind;
    int counts[3];
    struct K4bIface *texture;
    struct K4bIface *material;
    unsigned short first;
    unsigned short last;
    int flags;
};
extern struct K4bIface *lbl_804b05ac;
extern void *lbl_8041b6b8[];
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
struct K4bEmitterDesc *w3d_k4b_emitter_desc_construct_8024fb58(struct K4bEmitterDesc *self, void * arg_r4)
{
    w3d_tagged_construct_801ea0ec(self, arg_r4);
    self->vtable = lbl_8041b6b8;
    k4b_vec3_set(&self->origin, 0.0f, 0.0f, 0.0f);
    k4b_vec3_set(&self->direction, 0.0f, 0.0f, 0.0f);
    k4b_vec3_set(&self->spread, 0.0f, 0.0f, 0.0f);
    self->rate = 0.0f;
    self->kind = 23;
    self->counts[0] = 0;
    self->counts[1] = 0;
    self->counts[2] = 0;
    k4b_ref_init(&self->texture, lbl_804b05ac);
    k4b_ref_init(&self->material, lbl_804b05ac);
    self->first = 0;
    self->last = 0;
    self->flags = 0;
    return self;
}
// desc: w3d_k4b_emitter_desc_construct_8024fb58: Appears to construct a descriptor over 0x801ea0ec: vtable 0x8041b6b8, three zero vectors, zero rate, kind 23, cleared counters, two retained shared interfaces.
