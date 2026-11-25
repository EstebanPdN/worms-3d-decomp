#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_80220afc.c"
struct K6bString { Ptr32<char> text; };
struct K6bRgba { unsigned char r, g, b, a; };
struct K6bFontLabel {
    Ptr32<Ptr32<void>> vtable;
    char base[112];
    float scale;
    struct K6bRgba colour;
    struct K6bString name;
    struct K6bString font;
    int visible;
    int enabled;
};
extern Ptr32<char> lbl_804b06a0[];
extern Ptr32<void> lbl_8041a550[];
extern float lbl_803b6654[];
extern char lbl_803b6408[];
extern int fn_8021ef08(Ptr32<struct K6bFontLabel> self, Ptr32<void>);
extern void w3d_string_base_init(Ptr32<struct K6bString> string);
extern Ptr32<unsigned short> w3d_string_header(Ptr32<struct K6bString> string);
extern Ptr32<struct K6bString> w3d_string_from_text(Ptr32<struct K6bString> string, Ptr32<const char> text);
static inline void k6b_rgba_set(Ptr32<struct K6bRgba> colour, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    colour->r = r;
    colour->g = g;
    colour->b = b;
    colour->a = a;
}
Ptr32<struct K6bFontLabel> w3d_k6b_font_label_construct_80220afc(Ptr32<struct K6bFontLabel> self, Ptr32<void> arg_r4)
{
    Ptr32<struct K6bString> name = &self->name;
    Ptr32<Ptr32<char>> empty = lbl_804b06a0;
    fn_8021ef08(self, arg_r4);
    {
        float scale = lbl_803b6654[0];
        self->vtable = lbl_8041a550;
        self->scale = scale;
    }
    k6b_rgba_set(&self->colour, 255, 255, 255, 255);
    w3d_string_base_init(name);
    self->name.text = *empty;
    ++*w3d_string_header(name);
    w3d_string_from_text(&self->font, lbl_803b6408);
    self->visible = 1;
    self->enabled = 1;
    return self;
}
// desc: w3d_k6b_font_label_construct_80220afc: Appears to construct a label over base 0x8021ef08: vtable 0x8041a550, scale from 0x803b6654, white colour, empty name and font string FE.Font, flags at +132/+136 set.

}
