struct K2bVec3 { float x, y, z; };
struct K2bShape { void **vtable; unsigned char pad4[152]; struct K2bVec3 origin; float a; float b; float c; float d; };
extern void *w3d_vtable_80414f10[];
extern int w3d_shape_base_init_801bf6a4(struct K2bShape *self, void *);
static inline void k2b_vec3_fill(struct K2bVec3 *v, float value)
{
    v->x = value;
    v->y = value;
    v->z = value;
}
struct K2bShape *w3d_k2b_shape_construct_801bfc38(struct K2bShape *self, void * arg_r4)
{
    float zero;
    w3d_shape_base_init_801bf6a4(self, arg_r4);
    self->vtable = w3d_vtable_80414f10;
    zero = 0.0f;
    k2b_vec3_fill(&self->origin, zero);
    self->c = 1.0f;
    self->a = zero;
    self->b = zero;
    self->d = zero;
    return self;
}
// desc: Appears to construct a shape on its base constructor, install its vtable and set an origin, extents and a scale.
