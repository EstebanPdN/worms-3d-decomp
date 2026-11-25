#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801cd65c.c"
struct K4bString { Ptr32<char> text; };
struct K4bIface { Ptr32<Ptr32<void>> vtable; };
struct K4bSequenced {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    int first;
    int second;
    Ptr32<struct K4bIface> style;
    Ptr32<struct K4bIface> font;
    struct K4bString label;
    unsigned short range_start;
    unsigned short visible;
    unsigned short range_end;
    unsigned short cursor;
    Ptr32<struct K4bIface> owner;
    Ptr32<unsigned short> header;
};
extern Ptr32<struct K4bIface> lbl_804b05a8;
extern Ptr32<char> lbl_804b06a0[];
extern Ptr32<void> lbl_80415f38[];
extern Ptr32<void> w3d_tagged_construct_801ea0ec(Ptr32<void> object, int);
extern void w3d_string_base_init(Ptr32<struct K4bString> string);
extern Ptr32<unsigned short> w3d_string_header(Ptr32<struct K4bString> string);
extern void w3d_s20_stamp_sequence_801afaa4(Ptr32<struct K4bSequenced> self);
static inline void k4b_ref_init(Ptr32<Ptr32<struct K4bIface>> slot, Ptr32<struct K4bIface> iface)
{
    *slot = iface;
    if (iface != 0)
        ((Ptr32<void (Ptr32<struct K4bIface>)>)iface->vtable[3])(iface);
}
Ptr32<struct K4bSequenced> w3d_k4b_sequenced_construct_801cd65c(Ptr32<struct K4bSequenced> self, Ptr32<void> arg_r4)
{
    Ptr32<struct K4bString> label;
    Ptr32<Ptr32<char>> empty;
    Ptr32<struct K4bIface> owner;
    Ptr32<unsigned short> header;
    w3d_tagged_construct_801ea0ec(self, w3d::H(arg_r4));
    self->vtable = lbl_80415f38;
    self->first = 0;
    self->second = 0;
    k4b_ref_init(&self->style, lbl_804b05a8);
    k4b_ref_init(&self->font, lbl_804b05a8);
    label = &self->label;
    empty = lbl_804b06a0;
    w3d_string_base_init(label);
    self->label.text = *empty;
    header = w3d_string_header(label);
    owner = lbl_804b05a8;
    ++*header;
    self->range_start = 0;
    self->visible = 1;
    self->range_end = 0;
    self->cursor = 0;
    k4b_ref_init(&self->owner, owner);
    w3d_s20_stamp_sequence_801afaa4(self);
    return self;
}
// desc: w3d_k4b_sequenced_construct_801cd65c: Appears to construct an object over 0x801ea0ec with retained shared interfaces, an empty label string and cleared 16-bit fields, then stamps its sequence through 0x801afaa4.

}
