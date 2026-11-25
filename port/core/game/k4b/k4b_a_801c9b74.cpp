#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801c9b74.c"
struct K4bString { Ptr32<char> text; };
struct K4bIface { Ptr32<Ptr32<void>> vtable; };
struct K4bNamed {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    struct K4bString name;
    int value;
};
struct K4bNamedLinks {
    struct K4bNamed named;
    float params[5];
    Ptr32<struct K4bIface> source;
    int links[4];
    int owner;
};
extern Ptr32<struct K4bIface> lbl_804b05ac;
extern Ptr32<void> lbl_80416320[];
extern Ptr32<struct K4bNamed> w3d_k4b_named_construct_801c90c0(Ptr32<struct K4bNamed> self, Ptr32<void>);
Ptr32<struct K4bNamedLinks> w3d_k4b_named_links_construct_801c9b74(Ptr32<struct K4bNamedLinks> self, Ptr32<void> arg_r4)
{
    Ptr32<struct K4bIface> source;
    w3d_k4b_named_construct_801c90c0(&self->named, arg_r4);
    source = lbl_804b05ac;
    self->source = source;
    self->named.vtable = lbl_80416320;
    self->params[0] = 0.0f;
    self->params[1] = 0.0f;
    self->params[2] = 0.0f;
    self->params[3] = 0.0f;
    self->params[4] = 0.0f;
    if (source != 0)
        ((Ptr32<void (Ptr32<struct K4bIface>)>)source->vtable[3])(source);
    self->links[0] = 0;
    self->links[1] = 0;
    self->links[2] = 0;
    self->links[3] = 0;
    self->owner = 0;
    return self;
}
// desc: w3d_k4b_named_links_construct_801c9b74: Appears to construct a derived named object over 0x801c90c0: vtable 0x80416320, five zero floats, a retained shared interface at +48 and five cleared words.

}
