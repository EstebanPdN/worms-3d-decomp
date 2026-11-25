#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_80226e20.c"
struct K4bString { Ptr32<char> text; };
struct K4bIface { Ptr32<Ptr32<void>> vtable; };
struct K4bFontRef {
    Ptr32<Ptr32<void>> vtable;
    char base[16];
    float size;
    struct K4bString name;
    Ptr32<struct K4bIface> font;
    Ptr32<struct K4bIface> owner;
};
extern Ptr32<struct K4bIface> lbl_804b05ac;
extern Ptr32<struct K4bIface> lbl_804b05b0;
extern Ptr32<void> lbl_8041a1b8[];
extern Ptr32<void> w3d_tagged_construct_801ea0ec(Ptr32<void> object, int);
/* The name text lives in a shared string pool, so it stays an original object. */
extern const char lbl_803b6408[];
extern Ptr32<struct K4bString> w3d_string_from_text(Ptr32<struct K4bString> string, Ptr32<const char> text);
static inline void k4b_ref_init(Ptr32<Ptr32<struct K4bIface>> slot, Ptr32<struct K4bIface> iface)
{
    *slot = iface;
    if (iface != 0)
        ((Ptr32<void (Ptr32<struct K4bIface>)>)iface->vtable[3])(iface);
}
Ptr32<struct K4bFontRef> w3d_k4b_font_ref_construct_80226e20(Ptr32<struct K4bFontRef> self, Ptr32<void> arg_r4)
{
    w3d_tagged_construct_801ea0ec(self, w3d::H(arg_r4));
    self->vtable = lbl_8041a1b8;
    self->size = 0.0f;
    w3d_string_from_text(&self->name, lbl_803b6408);
    k4b_ref_init(&self->font, lbl_804b05b0);
    k4b_ref_init(&self->owner, lbl_804b05ac);
    return self;
}
// desc: w3d_k4b_font_ref_construct_80226e20: Appears to construct a font reference over 0x801ea0ec: vtable 0x8041a1b8, zero size, name string FE.Font and two retained shared default interfaces.

}
