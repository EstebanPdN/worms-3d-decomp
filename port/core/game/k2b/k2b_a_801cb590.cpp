#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_801cb590.c"
struct K2bVec4 { float x, y, z, w; };
struct K2bLight { Ptr32<Ptr32<void>> vtable; unsigned char pad4[20]; struct K2bVec4 ambient; struct K2bVec4 emissive; struct K2bVec4 diffuse; struct K2bVec4 specular; float shininess; int a; int b; int c; int d; };
extern Ptr32<void> w3d_vtable_80416208[];
extern int w3d_light_base_init_801cb41c(Ptr32<struct K2bLight> self, Ptr32<void>);
static inline void k2b_vec4_set(Ptr32<struct K2bVec4> v, float x, float y, float z, float w)
{
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}
Ptr32<struct K2bLight> w3d_k2b_light_construct_801cb590(Ptr32<struct K2bLight> self, Ptr32<void> arg_r4)
{
    w3d_light_base_init_801cb41c(self, arg_r4);
    self->vtable = w3d_vtable_80416208;
    k2b_vec4_set(&self->ambient, 0.0f, 0.0f, 0.0f, 0.0f);
    k2b_vec4_set(&self->emissive, 0.0f, 0.0f, 0.0f, 0.0f);
    k2b_vec4_set(&self->diffuse, 0.8f, 0.8f, 0.8f, 1.0f);
    k2b_vec4_set(&self->specular, 0.2f, 0.2f, 0.2f, 1.0f);
    self->shininess = 0.0f;
    self->a = 0;
    self->b = 0;
    self->c = 0;
    self->d = 0;
    return self;
}
// desc: Appears to construct a light on its base constructor, install its vtable and set four color vectors, a shininess and zeroed fields.

}
