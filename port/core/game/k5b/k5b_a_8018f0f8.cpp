#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k5b_a_8018f0f8.c"
struct K5bIface { Ptr32<Ptr32<void>> vtable; };
struct K5bLinkSet {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    Ptr32<struct K5bIface> links[8];
    unsigned char active;
};
extern Ptr32<struct K5bIface> lbl_804b05ac;
extern Ptr32<void> lbl_80413098[];
extern Ptr32<void> w3d_tagged_construct_801ea0ec(Ptr32<void> object, int);
static inline void k5b_ref_init(Ptr32<Ptr32<struct K5bIface>> slot, Ptr32<struct K5bIface> iface)
{
    *slot = iface;
    if (iface != 0)
        ((Ptr32<void (Ptr32<struct K5bIface>)>)iface->vtable[3])(iface);
}
Ptr32<struct K5bLinkSet> w3d_k5b_link_set_construct_8018f0f8(Ptr32<struct K5bLinkSet> self, Ptr32<void> arg_r4)
{
    w3d_tagged_construct_801ea0ec(self, w3d::H(arg_r4));
    self->vtable = lbl_80413098;
    k5b_ref_init(&self->links[0], lbl_804b05ac);
    k5b_ref_init(&self->links[1], lbl_804b05ac);
    k5b_ref_init(&self->links[2], lbl_804b05ac);
    k5b_ref_init(&self->links[3], lbl_804b05ac);
    k5b_ref_init(&self->links[4], lbl_804b05ac);
    k5b_ref_init(&self->links[5], lbl_804b05ac);
    k5b_ref_init(&self->links[6], lbl_804b05ac);
    k5b_ref_init(&self->links[7], lbl_804b05ac);
    self->active = 0;
    return self;
}
// desc: w3d_k5b_link_set_construct_8018f0f8: Appears to construct an object over 0x801ea0ec: vtable 0x80413098, eight retained shared default interfaces at +20..+48 and a cleared byte flag at +52.

}
