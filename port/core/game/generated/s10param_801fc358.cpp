#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10param_801fc358.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10PointerRange { char reserved[20]; Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end; } S10PointerRange;

Ptr32<Ptr32<void>> w3d_s10_range_data_801fc358(Ptr32<const S10PointerRange> object, Ptr32<int> count)
{
    *count = object->end - object->begin;
    if (*count == 0)
        return 0;
    return object->begin;
}

}
