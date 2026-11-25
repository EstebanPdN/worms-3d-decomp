#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_80221b68.c"
struct K6bString { Ptr32<char> text; };
struct K6bLabelPair {
    Ptr32<Ptr32<void>> vtable;
    char base[112];
    int enabled;
    struct K6bString title;
    struct K6bString caption;
};
extern Ptr32<char> lbl_804b06a0[];
extern Ptr32<void> lbl_8041a4d8[];
extern int fn_8021ef08(Ptr32<struct K6bLabelPair> self, Ptr32<void>);
extern void w3d_string_base_init(Ptr32<struct K6bString> string);
extern Ptr32<unsigned short> w3d_string_header(Ptr32<struct K6bString> string);
Ptr32<struct K6bLabelPair> w3d_k6b_label_pair_construct_80221b68(Ptr32<struct K6bLabelPair> self, Ptr32<void> arg_r4)
{
    Ptr32<struct K6bString> title = &self->title;
    Ptr32<Ptr32<char>> empty = lbl_804b06a0;
    Ptr32<struct K6bString> caption;
    fn_8021ef08(self, arg_r4);
    caption = &self->caption;
    self->vtable = lbl_8041a4d8;
    self->enabled = 1;
    w3d_string_base_init(title);
    self->title.text = *empty;
    ++*w3d_string_header(title);
    w3d_string_base_init(caption);
    self->caption.text = *empty;
    ++*w3d_string_header(caption);
    return self;
}
// desc: w3d_k6b_label_pair_construct_80221b68: Appears to construct an object over base 0x8021ef08 with vtable 0x8041a4d8, 1 at +116 and empty shared strings at +120 and +124.

}
