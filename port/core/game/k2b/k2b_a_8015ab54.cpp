#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_8015ab54.c"
struct K2bBounds { char pad0[8]; float max_x; char pad1[8]; float max_y; char pad2[40]; Ptr32<void> source; };
extern float w3d_query_extent_80178df0(Ptr32<void> source);
void w3d_k2b_extend_bounds_8015ab54(Ptr32<struct K2bBounds> b, float dx, float dy)
{
    float v = w3d_query_extent_80178df0(b->source) + dx;
    if (b->max_x < v)
        b->max_x = v;
    v = w3d_query_extent_80178df0(b->source) + dy;
    if (b->max_y < v)
        b->max_y = v;
}
// desc: Appears to raise two stored maxima to an extent queried from the object's source plus an offset each.

}
