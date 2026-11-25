#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_801bfc38.c"
struct K2bVec3 { float x, y, z; };
struct K2bShape { Ptr32<Ptr32<void>> vtable; unsigned char pad4[152]; struct K2bVec3 origin; float a; float b; float c; float d; };
extern Ptr32<void> w3d_vtable_80414f10[];
extern int w3d_shape_base_init_801bf6a4(Ptr32<struct K2bShape> self, Ptr32<void>);
static inline void k2b_vec3_fill(Ptr32<struct K2bVec3> v, float value)
{
    v->x = value;
    v->y = value;
    v->z = value;
}
Ptr32<struct K2bShape> w3d_k2b_shape_construct_801bfc38(Ptr32<struct K2bShape> self, Ptr32<void> arg_r4)
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

}
