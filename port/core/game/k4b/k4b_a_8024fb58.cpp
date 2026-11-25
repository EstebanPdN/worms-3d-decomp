#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_8024fb58.c"
struct K4bVec3 { float x, y, z; };
struct K4bIface { Ptr32<Ptr32<void>> vtable; };
struct K4bEmitterDesc {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    struct K4bVec3 origin;
    struct K4bVec3 direction;
    struct K4bVec3 spread;
    float rate;
    int kind;
    int counts[3];
    Ptr32<struct K4bIface> texture;
    Ptr32<struct K4bIface> material;
    unsigned short first;
    unsigned short last;
    int flags;
};
extern Ptr32<struct K4bIface> lbl_804b05ac;
extern Ptr32<void> lbl_8041b6b8[];
extern Ptr32<void> w3d_tagged_construct_801ea0ec(Ptr32<void> object, int);
static inline void k4b_vec3_set(Ptr32<struct K4bVec3> v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}
static inline void k4b_ref_init(Ptr32<Ptr32<struct K4bIface>> slot, Ptr32<struct K4bIface> iface)
{
    *slot = iface;
    if (iface != 0)
        ((Ptr32<void (Ptr32<struct K4bIface>)>)iface->vtable[3])(iface);
}
Ptr32<struct K4bEmitterDesc> w3d_k4b_emitter_desc_construct_8024fb58(Ptr32<struct K4bEmitterDesc> self, Ptr32<void> arg_r4)
{
    w3d_tagged_construct_801ea0ec(self, w3d::H(arg_r4));
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

}
