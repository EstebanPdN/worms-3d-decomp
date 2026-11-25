#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_8024f174.c"
struct K6bString { Ptr32<char> text; };
struct K6bTaggedLabel {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    int kind;
    struct K6bString name;
};
extern Ptr32<char> lbl_804b06a0[];
extern Ptr32<void> lbl_8041b758[];
extern Ptr32<void> w3d_tagged_construct_801ea0ec(Ptr32<void> object, int);
extern void w3d_string_base_init(Ptr32<struct K6bString> string);
extern Ptr32<unsigned short> w3d_string_header(Ptr32<struct K6bString> string);
Ptr32<struct K6bTaggedLabel> w3d_k6b_tagged_label_construct_8024f174(Ptr32<struct K6bTaggedLabel> self, Ptr32<void> arg_r4)
{
    Ptr32<struct K6bString> name = &self->name;
    Ptr32<Ptr32<char>> empty = lbl_804b06a0;
    w3d_tagged_construct_801ea0ec(self, w3d::H(arg_r4));
    self->vtable = lbl_8041b758;
    self->kind = 23;
    w3d_string_base_init(name);
    self->name.text = *empty;
    ++*w3d_string_header(name);
    return self;
}
// desc: w3d_k6b_tagged_label_construct_8024f174: Appears to construct an object over 0x801ea0ec with vtable 0x8041b758, kind 23 at +20 and an empty shared string at +24.

}
