#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k5b_a_8018af14.c"
struct K5bIface { Ptr32<Ptr32<void>> vtable; };
struct K5bLinkedNode {
    char head[24];
    unsigned int flags;
    char pad[4];
    Ptr32<struct K5bIface> first;
    Ptr32<struct K5bIface> second;
    Ptr32<struct K5bIface> third;
};
static inline void k5b_release(Ptr32<Ptr32<struct K5bIface>> slot, Ptr32<struct K5bIface> none)
{
    if (*slot != 0)
        ((Ptr32<void (Ptr32<struct K5bIface>)>)(*slot)->vtable[4])(*slot);
    *slot = none;
}
int w3d_k5b_linked_node_detach_8018af14(Ptr32<struct K5bLinkedNode> self)
{
    Ptr32<struct K5bIface> none = 0;
    self->flags &= ~0x8000u;
    k5b_release(&self->third, none);
    k5b_release(&self->second, none);
    k5b_release(&self->first, none);
    return 0;
}
// desc: w3d_k5b_linked_node_detach_8018af14: Appears to clear flag 0x8000 at +24 and release the three held interfaces at +40, +36 and +32 through virtual slot 4, clearing each.

}
