#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801b4bcc.c"
struct K4bString { Ptr32<char> text; };
struct K4bColor { float r, g, b, a; };
struct K4bNamedColor {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    struct K4bColor color;
    struct K4bString name;
    int enabled;
};
extern Ptr32<char> lbl_804b06a0[];
extern Ptr32<void> lbl_804145c8[];
extern struct K4bColor lbl_8045e63c[];
extern Ptr32<void> w3d_tagged_construct_801ea0ec(Ptr32<void> object, int);
extern void w3d_string_base_init(Ptr32<struct K4bString> string);
extern Ptr32<unsigned short> w3d_string_header(Ptr32<struct K4bString> string);
static inline void k4b_color_copy(Ptr32<struct K4bColor> d, Ptr32<const struct K4bColor> s)
{
    float r = s->r;
    float g = s->g;
    float b = s->b;
    d->r = r;
    d->g = g;
    d->b = b;
    d->a = s->a;
}
Ptr32<struct K4bNamedColor> w3d_k4b_named_color_construct_801b4bcc(Ptr32<struct K4bNamedColor> self, Ptr32<void> arg_r4)
{
    Ptr32<struct K4bString> name = &self->name;
    Ptr32<Ptr32<char>> empty = lbl_804b06a0;
    w3d_tagged_construct_801ea0ec(self, w3d::H(arg_r4));
    self->vtable = lbl_804145c8;
    k4b_color_copy(&self->color, &lbl_8045e63c[0]);
    w3d_string_base_init(name);
    self->name.text = *empty;
    ++*w3d_string_header(name);
    self->enabled = 1;
    return self;
}
// desc: w3d_k4b_named_color_construct_801b4bcc: Appears to construct a named colour object over 0x801ea0ec: vtable 0x804145c8, colour copied from global 0x8045e63c, empty shared name string, enabled flag set.

}
