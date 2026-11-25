#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801ca578.c"
struct K4bString { Ptr32<char> text; };
struct K4bIface { Ptr32<Ptr32<void>> vtable; };
struct K4bNamed {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    struct K4bString name;
    int value;
};
struct K4bNamedRefs {
    struct K4bNamed named;
    Ptr32<struct K4bIface> first;
    Ptr32<struct K4bIface> second;
    int flags;
    Ptr32<struct K4bIface> third;
    Ptr32<struct K4bIface> fourth;
    Ptr32<struct K4bIface> fifth;
};
extern Ptr32<struct K4bIface> lbl_804b05a8;
extern Ptr32<void> lbl_804162a8[];
extern Ptr32<struct K4bNamed> w3d_k4b_named_construct_801c90c0(Ptr32<struct K4bNamed> self, Ptr32<void>);
static inline void k4b_ref_init(Ptr32<Ptr32<struct K4bIface>> slot, Ptr32<struct K4bIface> iface)
{
    *slot = iface;
    if (iface != 0)
        ((Ptr32<void (Ptr32<struct K4bIface>)>)iface->vtable[3])(iface);
}
Ptr32<struct K4bNamedRefs> w3d_k4b_named_refs_construct_801ca578(Ptr32<struct K4bNamedRefs> self, Ptr32<void> arg_r4)
{
    w3d_k4b_named_construct_801c90c0(&self->named, arg_r4);
    self->named.vtable = lbl_804162a8;
    k4b_ref_init(&self->first, lbl_804b05a8);
    k4b_ref_init(&self->second, lbl_804b05a8);
    self->flags = 0;
    k4b_ref_init(&self->third, lbl_804b05a8);
    k4b_ref_init(&self->fourth, lbl_804b05a8);
    k4b_ref_init(&self->fifth, lbl_804b05a8);
    return self;
}
// desc: w3d_k4b_named_refs_construct_801ca578: Appears to construct a derived named object over 0x801c90c0: vtable 0x804162a8, five retained shared default interfaces and a cleared word at +36.

}
