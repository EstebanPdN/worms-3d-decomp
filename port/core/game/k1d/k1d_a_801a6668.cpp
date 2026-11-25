#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k1d_a_801a6668.c"
struct K1dRange { Ptr32<char> begin; Ptr32<char> end; };
struct K1dBuf { char pad[60]; struct K1dRange range; };
extern Ptr32<void> fn_802eee50(Ptr32<char>, Ptr32<char>, int);
int w3d_k1d_compact_buffer_801a6668(Ptr32<struct K1dBuf> b)
{
    Ptr32<struct K1dRange> r = &b->range;
    Ptr32<char> begin = r->begin;
    int n = r->end - begin;
    fn_802eee50(begin, r->end, 0);
    r->end = r->end - n;
    return 0;
}
// k1d: w3d_k1d_compact_buffer_801a6668|0x801a6668|Appears to move a pointer range back by its length after a zero-length copy and return zero.

}
