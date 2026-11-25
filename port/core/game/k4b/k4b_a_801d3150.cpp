#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801d3150.c"
struct K4bPair { int first; int second; };
struct K4bLink { Ptr32<void> node; int count; };
struct K4bString { Ptr32<char> text; int length; };
struct K4bNamedComponent {
    Ptr32<Ptr32<void>> vtable;
    char base[36];
    struct K4bString name;
    int field_30;
    int field_34;
    struct K4bLink link_a;
    int field_40;
    char pad44[4];
    struct K4bPair range;
    struct K4bLink link_b;
};
extern Ptr32<void> lbl_80416518[];
extern Ptr32<void> lbl_804164d0[];
extern Ptr32<void> fn_801e81c8(Ptr32<void> member);
extern Ptr32<void> w3d_string_default(Ptr32<struct K4bString> string);
static inline void k4b_pair_init(Ptr32<struct K4bPair> p)
{
    p->first = 0;
    p->second = 0;
}
static inline void k4b_link_init(Ptr32<struct K4bLink> l)
{
    l->count = 0;
}
Ptr32<struct K4bNamedComponent> w3d_k4b_named_component_construct_801d3150(Ptr32<struct K4bNamedComponent> self)
{
    volatile char pad[16];
    self->vtable = lbl_80416518;
    fn_801e81c8(self->base);
    self->vtable = lbl_804164d0;
    w3d_string_default(&self->name);
    self->field_30 = 0;
    self->field_34 = 0;
    k4b_link_init(&self->link_a);
    k4b_pair_init(&self->range);
    k4b_link_init(&self->link_b);
    self->field_40 = 0;
    return self;
}
// desc: w3d_k4b_named_component_construct_801d3150: Appears to construct a named component: base vtable, member at +4 via 0x801e81c8, derived vtable 0x804164d0, default name string at +40 and zeroed fields.

}
