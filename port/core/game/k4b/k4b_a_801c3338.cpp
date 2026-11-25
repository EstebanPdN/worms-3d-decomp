#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801c3338.c"
struct K4bString { Ptr32<char> text; };
struct K4bIface { Ptr32<Ptr32<void>> vtable; };
struct K4bColor { float r, g, b, a; };
struct K4bVec3 { float x, y, z; };
struct K4bNamedColor {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    struct K4bColor color;
    struct K4bString name;
    int enabled;
};
struct K4bLight {
    struct K4bNamedColor named;
    Ptr32<struct K4bIface> target;
    struct K4bVec3 offset;
    Ptr32<struct K4bIface> source;
};
extern Ptr32<struct K4bIface> lbl_804b05a8;
extern Ptr32<void> lbl_80414ce0[];
extern Ptr32<struct K4bNamedColor> w3d_k4b_named_color_construct_801b4bcc(Ptr32<struct K4bNamedColor> self, Ptr32<void>);
static inline void k4b_ref_init(Ptr32<Ptr32<struct K4bIface>> slot, Ptr32<struct K4bIface> iface)
{
    *slot = iface;
    if (iface != 0)
        ((Ptr32<void (Ptr32<struct K4bIface>)>)iface->vtable[3])(iface);
}
Ptr32<struct K4bLight> w3d_k4b_light_construct_801c3338(Ptr32<struct K4bLight> self, Ptr32<void> arg_r4)
{
    w3d_k4b_named_color_construct_801b4bcc(&self->named, arg_r4);
    self->named.vtable = lbl_80414ce0;
    k4b_ref_init(&self->target, lbl_804b05a8);
    self->offset.x = 0.0f;
    self->offset.y = 0.0f;
    self->offset.z = 0.0f;
    k4b_ref_init(&self->source, lbl_804b05a8);
    return self;
}
// desc: w3d_k4b_light_construct_801c3338: Appears to construct a derived named colour object over 0x801b4bcc: vtable 0x80414ce0, two retained shared interfaces and a zero offset vector.

}
