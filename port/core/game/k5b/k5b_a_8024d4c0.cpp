#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k5b_a_8024d4c0.c"
struct K5bIface { Ptr32<Ptr32<void>> vtable; };
struct K5bBufferPair {
    Ptr32<Ptr32<void>> vtable;
    char base[460];
    int count;
    unsigned short first;
    unsigned short last;
    Ptr32<struct K5bIface> links[3];
};
extern Ptr32<struct K5bIface> lbl_804b05a8;
extern Ptr32<void> lbl_8041b848[];
extern Ptr32<void> fn_8024bc08(Ptr32<void> object, Ptr32<void>);
extern Ptr32<void> w3d_array_write_802514f8(Ptr32<void> owner, unsigned int count, unsigned int flags, Ptr32<unsigned int> previous);
extern Ptr32<void> w3d_array_write_802515b4(Ptr32<void> owner, unsigned int count, unsigned int flags, Ptr32<unsigned int> previous);
static inline void k5b_ref_init(Ptr32<Ptr32<struct K5bIface>> slot, Ptr32<struct K5bIface> iface)
{
    *slot = iface;
    if (iface != 0)
        ((Ptr32<void (Ptr32<struct K5bIface>)>)iface->vtable[3])(iface);
}
Ptr32<struct K5bBufferPair> w3d_k5b_buffer_pair_construct_8024d4c0(Ptr32<struct K5bBufferPair> self, Ptr32<void> arg_r4)
{
    fn_8024bc08(self, arg_r4);
    self->vtable = lbl_8041b848;
    self->count = 0;
    self->first = 0;
    self->last = 0;
    k5b_ref_init(&self->links[0], lbl_804b05a8);
    k5b_ref_init(&self->links[1], lbl_804b05a8);
    k5b_ref_init(&self->links[2], lbl_804b05a8);
    w3d_array_write_802514f8(self, 256, 1, 0);
    w3d_array_write_802515b4(self, 256, 1, 0);
    return self;
}
// desc: w3d_k5b_buffer_pair_construct_8024d4c0: Appears to construct an object over 0x8024bc08: vtable 0x8041b848, cleared counters, three retained shared default interfaces, then opens two 256-entry arrays.

}
