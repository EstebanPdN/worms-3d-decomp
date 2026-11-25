#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_8022526c.c"
struct K6bString { Ptr32<char> text; };
struct K6bNamedPanel {
    Ptr32<Ptr32<void>> vtable;
    char base[148];
    struct K6bString name;
    int enabled;
};
extern Ptr32<char> lbl_804b06a0[];
extern Ptr32<void> lbl_8041a348[];
extern int fn_8021fd28(Ptr32<struct K6bNamedPanel> self, Ptr32<void>);
extern void w3d_string_base_init(Ptr32<struct K6bString> string);
extern Ptr32<unsigned short> w3d_string_header(Ptr32<struct K6bString> string);
Ptr32<struct K6bNamedPanel> w3d_k6b_named_panel_construct_8022526c(Ptr32<struct K6bNamedPanel> self, Ptr32<void> arg_r4)
{
    Ptr32<struct K6bString> name = &self->name;
    Ptr32<Ptr32<char>> empty = lbl_804b06a0;
    fn_8021fd28(self, arg_r4);
    self->vtable = lbl_8041a348;
    w3d_string_base_init(name);
    self->name.text = *empty;
    ++*w3d_string_header(name);
    self->enabled = 1;
    return self;
}
// desc: w3d_k6b_named_panel_construct_8022526c: Appears to construct an object over base 0x8021fd28 with vtable 0x8041a348, an empty shared string at +152 and 1 at +156.

}
