#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_8020b574.c"
struct K6bFieldAccessor {
    int offset;
    Ptr32<Ptr32<void> (void)> read;
};
extern int fn_8020b460(Ptr32<void> field, Ptr32<void> value, Ptr32<void> context, Ptr32<void> extra);
void w3d_k6b_accessor_apply_8020b574(Ptr32<char> owner, Ptr32<void> context, Ptr32<void> extra, Ptr32<struct K6bFieldAccessor> accessor)
{
    Ptr32<char> field = owner + accessor->offset;
    fn_8020b460(field, accessor->read(), context, extra);
}
// desc: w3d_k6b_accessor_apply_8020b574: Appears to read a value through the accessor callback at +4 and pass it with the field at owner plus the accessor offset to 0x8020b460.

}
