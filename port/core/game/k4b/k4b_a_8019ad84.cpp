#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_8019ad84.c"
struct K4bString { Ptr32<char> text; };
struct K4bIface { Ptr32<Ptr32<void>> vtable; };
struct K4bBoundName {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    Ptr32<struct K4bIface> owner;
    int index;
    struct K4bString name;
};
extern Ptr32<struct K4bIface> lbl_804b05ac;
extern Ptr32<char> lbl_804b06a0[];
extern Ptr32<void> lbl_804135a8[];
extern Ptr32<void> w3d_tagged_construct_801ea0ec(Ptr32<void> object, int);
extern void w3d_string_base_init(Ptr32<struct K4bString> string);
extern Ptr32<unsigned short> w3d_string_header(Ptr32<struct K4bString> string);
static inline void k4b_ref_init(Ptr32<Ptr32<struct K4bIface>> slot, Ptr32<struct K4bIface> iface)
{
    *slot = iface;
    if (iface != 0)
        ((Ptr32<void (Ptr32<struct K4bIface>)>)iface->vtable[3])(iface);
}
Ptr32<struct K4bBoundName> w3d_k4b_bound_name_construct_8019ad84(Ptr32<struct K4bBoundName> self, Ptr32<void> arg_r4)
{
    Ptr32<struct K4bString> name;
    w3d_tagged_construct_801ea0ec(self, w3d::H(arg_r4));
    self->vtable = lbl_804135a8;
    k4b_ref_init(&self->owner, lbl_804b05ac);
    self->index = 0;
    name = &self->name;
    w3d_string_base_init(name);
    self->name.text = lbl_804b06a0[0];
    ++*w3d_string_header(name);
    return self;
}
// desc: w3d_k4b_bound_name_construct_8019ad84: Appears to construct an object over 0x801ea0ec: vtable 0x804135a8, retained shared interface at +20, cleared index and an empty shared name string at +28.

}
