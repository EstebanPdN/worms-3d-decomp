#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801c9f2c.c"
struct K4bString { Ptr32<char> text; };
struct K4bIface { Ptr32<Ptr32<void>> vtable; };
struct K4bNamed {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    struct K4bString name;
    int value;
};
struct K4bNamedRange {
    struct K4bNamed named;
    float params[5];
    Ptr32<struct K4bIface> source;
    int first;
    int second;
};
extern Ptr32<struct K4bIface> lbl_804b05ac;
extern Ptr32<void> lbl_804162f8[];
extern Ptr32<struct K4bNamed> w3d_k4b_named_construct_801c90c0(Ptr32<struct K4bNamed> self, Ptr32<void>);
Ptr32<struct K4bNamedRange> w3d_k4b_named_range_construct_801c9f2c(Ptr32<struct K4bNamedRange> self, Ptr32<void> arg_r4)
{
    Ptr32<struct K4bIface> source;
    w3d_k4b_named_construct_801c90c0(&self->named, arg_r4);
    source = lbl_804b05ac;
    self->source = source;
    self->named.vtable = lbl_804162f8;
    self->params[0] = 0.0f;
    self->params[1] = 0.0f;
    self->params[2] = 0.0f;
    self->params[3] = 0.0f;
    self->params[4] = 0.0f;
    if (source != 0)
        ((Ptr32<void (Ptr32<struct K4bIface>)>)source->vtable[3])(source);
    self->first = 0;
    self->second = 0;
    return self;
}
// desc: w3d_k4b_named_range_construct_801c9f2c: Appears to construct a derived named object over 0x801c90c0: vtable 0x804162f8, five zero floats, a retained shared interface at +48 and two cleared words.

}
