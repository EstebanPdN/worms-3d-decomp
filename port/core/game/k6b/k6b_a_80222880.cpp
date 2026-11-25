#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_80222880.c"
struct K6bString { Ptr32<char> text; };
struct K6bFontBox {
    Ptr32<Ptr32<void>> vtable;
    char base[112];
    int mode;
    int enabled;
    float scale;
    int red;
    int green;
    int blue;
    struct K6bString name;
    struct K6bString font;
};
extern Ptr32<char> lbl_804b06a0[];
extern Ptr32<void> lbl_8041a460[];
extern float lbl_803b6e84[];
extern char lbl_803b6408[];
extern int fn_8021ef08(Ptr32<struct K6bFontBox> self, Ptr32<void>);
extern void w3d_string_base_init(Ptr32<struct K6bString> string);
extern Ptr32<unsigned short> w3d_string_header(Ptr32<struct K6bString> string);
extern Ptr32<struct K6bString> w3d_string_from_text(Ptr32<struct K6bString> string, Ptr32<const char> text);
Ptr32<struct K6bFontBox> w3d_k6b_font_box_construct_80222880(Ptr32<struct K6bFontBox> self, Ptr32<void> arg_r4)
{
    Ptr32<struct K6bString> name = &self->name;
    Ptr32<Ptr32<char>> empty = lbl_804b06a0;
    fn_8021ef08(self, arg_r4);
    {
        float scale = lbl_803b6e84[0];
        self->vtable = lbl_8041a460;
        self->mode = 0;
        self->enabled = 1;
        self->scale = scale;
        self->red = 255;
        self->green = 255;
        self->blue = 255;
    }
    w3d_string_base_init(name);
    self->name.text = *empty;
    ++*w3d_string_header(name);
    w3d_string_from_text(&self->font, lbl_803b6408);
    return self;
}
// desc: w3d_k6b_font_box_construct_80222880: Appears to construct a box over base 0x8021ef08: vtable 0x8041a460, 0 at +116, 1 at +120, scale from 0x803b6e84, 255 at +128..+136, empty name and font FE.Font.

}
