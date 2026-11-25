#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801c482c.c"
struct K4bVec3 { float x, y, z; };
struct K4bIface { Ptr32<Ptr32<void>> vtable; };
struct K4bSegment {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    struct K4bVec3 start;
    struct K4bVec3 end;
    Ptr32<struct K4bIface> owner;
    int counts[3];
};
extern Ptr32<struct K4bIface> lbl_804b05a8;
extern Ptr32<void> lbl_80414bf0[];
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
Ptr32<struct K4bSegment> w3d_k4b_segment_construct_801c482c(Ptr32<struct K4bSegment> self, Ptr32<void> arg_r4)
{
    w3d_tagged_construct_801ea0ec(self, w3d::H(arg_r4));
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

}
