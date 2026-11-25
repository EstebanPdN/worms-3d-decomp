#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k1d_a_8018b260.c"
struct K1dTable { char pad[68]; Ptr32<void> entries; int count; };
extern int bsearch(Ptr32<const void> key, Ptr32<const void> base, int n, int size, Ptr32<int (Ptr32<const void>, Ptr32<const void>)> cmp);
extern int fn_8018b628(Ptr32<const void>, Ptr32<const void>);
unsigned short w3d_k1d_lookup_entry_8018b260(Ptr32<struct K1dTable> t, unsigned short key)
{
    unsigned short k = key;
    Ptr32<char> r = (Ptr32<char>)w3d::G(bsearch(&k, t->entries, t->count, 6, fn_8018b628));
    if (r) return *(Ptr32<unsigned short>)(r + 4);
    return 0;
}
// k1d: w3d_k1d_lookup_entry_8018b260|0x8018b260|Appears to binary-search a table of six-byte entries by a 16-bit key and return the entry value or zero.

}
