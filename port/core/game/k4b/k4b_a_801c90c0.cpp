#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801c90c0.c"
struct K4bString { Ptr32<char> text; };
struct K4bNamed {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    struct K4bString name;
    int value;
};
extern Ptr32<char> lbl_804b06a0[];
extern Ptr32<void> lbl_804163c0[];
extern Ptr32<void> w3d_tagged_construct_801ea0ec(Ptr32<void> object, int);
extern void w3d_string_base_init(Ptr32<struct K4bString> string);
extern Ptr32<unsigned short> w3d_string_header(Ptr32<struct K4bString> string);
Ptr32<struct K4bNamed> w3d_k4b_named_construct_801c90c0(Ptr32<struct K4bNamed> self, Ptr32<void> arg_r4)
{
    Ptr32<struct K4bString> name = &self->name;
    Ptr32<Ptr32<char>> empty = lbl_804b06a0;
    w3d_tagged_construct_801ea0ec(self, w3d::H(arg_r4));
    self->vtable = lbl_804163c0;
    w3d_string_base_init(name);
    self->name.text = *empty;
    ++*w3d_string_header(name);
    self->value = 0;
    return self;
}
// desc: w3d_k4b_named_construct_801c90c0: Appears to construct a named object over 0x801ea0ec: vtable 0x804163c0, name string at +20 set to the shared empty string (reference count bumped), value cleared.

}
