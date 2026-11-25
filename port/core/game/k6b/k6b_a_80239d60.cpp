#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_80239d60.c"
struct K6bString { Ptr32<char> text; };
struct K6bNamedRange {
    Ptr32<Ptr32<void>> vtable;
    char base[20];
    int first;
    int second;
    struct K6bString name;
    int value;
};
extern Ptr32<char> lbl_804b06a0[];
extern Ptr32<void> lbl_8041af40[];
extern int w3d_auto_80238d88(Ptr32<struct K6bNamedRange> self, Ptr32<void>);
extern void w3d_string_base_init(Ptr32<struct K6bString> string);
extern Ptr32<unsigned short> w3d_string_header(Ptr32<struct K6bString> string);
Ptr32<struct K6bNamedRange> w3d_k6b_named_range_construct_80239d60(Ptr32<struct K6bNamedRange> self, Ptr32<void> arg_r4)
{
    int zero = 0;
    Ptr32<struct K6bString> name = &self->name;
    w3d_auto_80238d88(self, arg_r4);
    self->vtable = lbl_8041af40;
    self->first = zero;
    self->second = zero;
    w3d_string_base_init(name);
    self->name.text = lbl_804b06a0[0];
    ++*w3d_string_header(name);
    self->value = zero;
    return self;
}
// desc: w3d_k6b_named_range_construct_80239d60: Appears to construct an object over base 0x80238d88 with vtable 0x8041af40, zeroed +24 and +28, an empty shared string at +32 and 0 at +36.

}
