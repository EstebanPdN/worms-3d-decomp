#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_801cce74.c"
struct K2bVec4 { float x, y, z, w; };
struct K2bEmitter { Ptr32<Ptr32<void>> vtable; unsigned char pad4[20]; struct K2bVec4 color; int a; int b; int c; int d; };
extern Ptr32<void> w3d_vtable_80415fd8[];
extern int w3d_emitter_base_init_801cb41c(Ptr32<struct K2bEmitter> self, Ptr32<void>);
static inline void k2b_vec4_set(Ptr32<struct K2bVec4> v, float x, float y, float z, float w)
{
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}
Ptr32<struct K2bEmitter> w3d_k2b_emitter_construct_801cce74(Ptr32<struct K2bEmitter> self, Ptr32<void> arg_r4)
{
    w3d_emitter_base_init_801cb41c(self, arg_r4);
    self->vtable = w3d_vtable_80415fd8;
    k2b_vec4_set(&self->color, 0.0f, 0.0f, 0.0f, 1.0f);
    self->a = 0;
    self->b = 0;
    self->c = 0;
    self->d = 0;
    return self;
}
// desc: Appears to construct an emitter on its base constructor, install its vtable and set a zero color vector with unit w and four zeroed fields.

}
