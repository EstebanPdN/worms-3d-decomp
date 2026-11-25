#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_aw_802067bc.c"
// desc: Appears to optionally store an entry of one indexed table through an output pointer and return the entry of a second indexed table.
struct S21Tables { char pad[44]; Ptr32<int> primary; Ptr32<int> secondary; };
int w3d_s21_lookup_pair_802067bc(Ptr32<struct S21Tables> self, int index, Ptr32<int> out)
{
    if (out)
        *out = *(Ptr32<int>)((Ptr32<char>)self->secondary + (index << 2));
    return self->primary[index];
}

}
