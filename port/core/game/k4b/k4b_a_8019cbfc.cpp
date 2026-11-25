#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_8019cbfc.c"
struct K4bPair { int first; int second; };
struct K4bLink { Ptr32<void> node; int count; };
struct K4bDualComponent {
    Ptr32<Ptr32<void>> vtable;
    char base[36];
    int state;
    char pad44[8];
    struct K4bPair range_a;
    struct K4bLink link_a;
    struct K4bPair range_b;
    struct K4bLink link_b;
};
extern Ptr32<void> lbl_804136c0[];
extern Ptr32<void> lbl_80413680[];
extern Ptr32<void> fn_801e81c8(Ptr32<void> member);
static inline void k4b_pair_init(Ptr32<struct K4bPair> p)
{
    p->first = 0;
    p->second = 0;
}
static inline void k4b_link_init(Ptr32<struct K4bLink> l)
{
    l->count = 0;
}
Ptr32<struct K4bDualComponent> w3d_k4b_dual_component_construct_8019cbfc(Ptr32<struct K4bDualComponent> self)
{
    volatile char pad[16];
    self->vtable = lbl_804136c0;
    fn_801e81c8(self->base);
    self->vtable = lbl_80413680;
    self->state = 0;
    k4b_pair_init(&self->range_a);
    k4b_link_init(&self->link_a);
    k4b_pair_init(&self->range_b);
    k4b_link_init(&self->link_b);
    return self;
}
// desc: w3d_k4b_dual_component_construct_8019cbfc: Appears to construct a component with two range/link member pairs: base vtable, member at +4 via 0x801e81c8, derived vtable 0x80413680, then zeroed fields.

}
