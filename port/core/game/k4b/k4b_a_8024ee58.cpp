#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_8024ee58.c"
struct K4bString { Ptr32<char> text; };
struct K4bIface { Ptr32<Ptr32<void>> vtable; };
struct K4bBoundLabel {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    Ptr32<struct K4bIface> owner;
    struct K4bString name;
};
extern Ptr32<struct K4bIface> lbl_804b05a8;
extern Ptr32<char> lbl_804b06a0[];
extern Ptr32<void> lbl_8041b780[];
extern Ptr32<void> w3d_tagged_construct_801ea0ec(Ptr32<void> object, int);
extern void w3d_string_base_init(Ptr32<struct K4bString> string);
extern Ptr32<unsigned short> w3d_string_header(Ptr32<struct K4bString> string);
static inline void k4b_ref_init(Ptr32<Ptr32<struct K4bIface>> slot, Ptr32<struct K4bIface> iface)
{
    *slot = iface;
    if (iface != 0)
        ((Ptr32<void (Ptr32<struct K4bIface>)>)iface->vtable[3])(iface);
}
Ptr32<struct K4bBoundLabel> w3d_k4b_bound_label_construct_8024ee58(Ptr32<struct K4bBoundLabel> self, Ptr32<void> arg_r4)
{
    Ptr32<struct K4bString> name;
    Ptr32<Ptr32<char>> empty;
    w3d_tagged_construct_801ea0ec(self, w3d::H(arg_r4));
    self->vtable = lbl_8041b780;
    k4b_ref_init(&self->owner, lbl_804b05a8);
    name = &self->name;
    empty = lbl_804b06a0;
    w3d_string_base_init(name);
    self->name.text = *empty;
    ++*w3d_string_header(name);
    return self;
}
// desc: w3d_k4b_bound_label_construct_8024ee58: Appears to construct an object over 0x801ea0ec: vtable 0x8041b780, retained shared interface at +20 and an empty shared name string at +24.

}
