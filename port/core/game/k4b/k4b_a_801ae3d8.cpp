#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801ae3d8.c"
struct K4bPair { int first; int second; };
struct K4bLink { Ptr32<void> node; int count; };
struct K4bComponent {
    Ptr32<Ptr32<void>> vtable;
    char base[40];
    int state;
    struct K4bPair range;
    struct K4bLink link;
};
extern Ptr32<void> lbl_80414120[];
extern Ptr32<void> lbl_804140e0[];
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
Ptr32<struct K4bComponent> w3d_k4b_component_construct_801ae3d8(Ptr32<struct K4bComponent> self)
{
    volatile char pad[8];
    self->vtable = lbl_80414120;
    fn_801e81c8(self->base);
    self->vtable = lbl_804140e0;
    self->state = 0;
    k4b_pair_init(&self->range);
    k4b_link_init(&self->link);
    return self;
}
// desc: w3d_k4b_component_construct_801ae3d8: Appears to construct a component: base vtable, member at +4 via 0x801e81c8, derived vtable 0x804140e0, then zero the state, range pair and link count.

}
