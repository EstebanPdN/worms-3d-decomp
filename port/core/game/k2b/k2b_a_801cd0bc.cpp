#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_801cd0bc.c"
struct K2bVec4 { float x, y, z, w; };
struct K2bEmitter { Ptr32<Ptr32<void>> vtable; unsigned char pad4[20]; struct K2bVec4 color; float size_a; float size_b; float size_c; int mode; int pad38; };
extern Ptr32<void> w3d_vtable_80415fb0[];
extern int w3d_emitter_base_init_801cb41c(Ptr32<struct K2bEmitter> self, Ptr32<void>);
static inline void k2b_vec4_set(Ptr32<struct K2bVec4> v, float x, float y, float z, float w)
{
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}
Ptr32<struct K2bEmitter> w3d_k2b_emitter_construct_801cd0bc(Ptr32<struct K2bEmitter> self, Ptr32<void> arg_r4)
{
    w3d_emitter_base_init_801cb41c(self, arg_r4);
    self->vtable = w3d_vtable_80415fb0;
    k2b_vec4_set(&self->color, 0.0f, 0.0f, 0.0f, 0.0f);
    self->size_a = 1.0f;
    self->size_b = 1.0f;
    self->size_c = 0.0f;
    self->mode = 3;
    self->pad38 = 0;
    return self;
}
// desc: Appears to construct an emitter on its base constructor, install its vtable and set a zero vector, two sizes and a mode of three.

}
