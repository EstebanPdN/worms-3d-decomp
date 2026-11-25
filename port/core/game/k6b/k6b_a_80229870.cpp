#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_80229870.c"
struct K6bString { Ptr32<char> text; };
struct K6bTextTriple {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    int field_20;
    struct K6bString first;
    int field_28;
    struct K6bString second;
    int field_36;
    struct K6bString third;
};
extern Ptr32<char> lbl_804b06a0[];
extern Ptr32<void> lbl_8041a0f0[];
extern Ptr32<void> w3d_tagged_construct_801ea0ec(Ptr32<void> object, int);
extern void w3d_string_base_init(Ptr32<struct K6bString> string);
extern Ptr32<unsigned short> w3d_string_header(Ptr32<struct K6bString> string);
Ptr32<struct K6bTextTriple> w3d_k6b_text_triple_construct_80229870(Ptr32<struct K6bTextTriple> self, Ptr32<void> arg_r4)
{
    int zero = 0;
    Ptr32<struct K6bString> first = &self->first;
    Ptr32<Ptr32<char>> empty;
    Ptr32<struct K6bString> second;
    Ptr32<struct K6bString> third;
    w3d_tagged_construct_801ea0ec(self, w3d::H(arg_r4));
    empty = lbl_804b06a0;
    self->field_20 = zero;
    self->vtable = lbl_8041a0f0;
    second = &self->second;
    third = &self->third;
    w3d_string_base_init(first);
    self->first.text = *empty;
    ++*w3d_string_header(first);
    self->field_28 = zero;
    w3d_string_base_init(second);
    self->second.text = *empty;
    ++*w3d_string_header(second);
    self->field_36 = zero;
    w3d_string_base_init(third);
    self->third.text = *empty;
    ++*w3d_string_header(third);
    return self;
}
// desc: w3d_k6b_text_triple_construct_80229870: Appears to construct an object over 0x801ea0ec with vtable 0x8041a0f0, zeroed +20/+28/+36 and empty shared strings at +24, +32 and +40.

}
