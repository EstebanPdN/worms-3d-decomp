struct K2bVec3 { float x, y, z; };
struct K2bRegion { void **vtable; unsigned char pad4[16]; struct K2bVec3 min; struct K2bVec3 max; unsigned short a; unsigned short b; unsigned short c; unsigned short d; };
extern void *w3d_vtable_80414c68[];
extern void * w3d_region_base_init_801ea0ec(struct K2bRegion *self, int);
static inline void k2b_vec3_fill(struct K2bVec3 *v, float value)
{
    v->x = value;
    v->y = value;
    v->z = value;
}
struct K2bRegion *w3d_k2b_region_construct_801c3ce0(struct K2bRegion *self, void * arg_r4)
{
    float zero;
    w3d_region_base_init_801ea0ec(self, arg_r4);
    self->vtable = w3d_vtable_80414c68;
    zero = 0.0f;
    k2b_vec3_fill(&self->min, zero);
    k2b_vec3_fill(&self->max, zero);
    self->a = 0;
    self->b = 0;
    self->c = 0;
    self->d = 0;
    return self;
}
// desc: Appears to construct a region on its base constructor, install its vtable and zero two vectors and four counters.
