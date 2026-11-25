#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_80226150.c"
struct K4bString { Ptr32<char> text; };
struct K4bIface { Ptr32<Ptr32<void>> vtable; };
struct K4bSlider {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    Ptr32<struct K4bIface> style;
    Ptr32<struct K4bIface> font;
    int mode;
    float minimum;
    float maximum;
    struct K4bString label;
    int value;
};
extern Ptr32<struct K4bIface> lbl_804b05a8;
extern Ptr32<struct K4bIface> lbl_804b05b0;
extern Ptr32<char> lbl_804b06a0[];
extern Ptr32<void> lbl_8041a280[];
extern Ptr32<void> w3d_tagged_construct_801ea0ec(Ptr32<void> object, int);
extern void w3d_string_base_init(Ptr32<struct K4bString> string);
extern Ptr32<unsigned short> w3d_string_header(Ptr32<struct K4bString> string);
static inline void k4b_ref_init(Ptr32<Ptr32<struct K4bIface>> slot, Ptr32<struct K4bIface> iface)
{
    *slot = iface;
    if (iface != 0)
        ((Ptr32<void (Ptr32<struct K4bIface>)>)iface->vtable[3])(iface);
}
Ptr32<struct K4bSlider> w3d_k4b_slider_construct_80226150(Ptr32<struct K4bSlider> self, Ptr32<void> arg_r4)
{
    Ptr32<struct K4bString> label;
    Ptr32<Ptr32<char>> empty;
    w3d_tagged_construct_801ea0ec(self, w3d::H(arg_r4));
    self->vtable = lbl_8041a280;
    k4b_ref_init(&self->style, lbl_804b05a8);
    k4b_ref_init(&self->font, lbl_804b05b0);
    self->mode = 3;
    self->minimum = 0.0f;
    self->maximum = 100.0f;
    label = &self->label;
    empty = lbl_804b06a0;
    w3d_string_base_init(label);
    self->label.text = *empty;
    ++*w3d_string_header(label);
    self->value = 0;
    return self;
}
// desc: w3d_k4b_slider_construct_80226150: Appears to construct a slider-like object over 0x801ea0ec: two retained shared interfaces, mode 3, range 0 to 100, empty label string and zero value.

}
