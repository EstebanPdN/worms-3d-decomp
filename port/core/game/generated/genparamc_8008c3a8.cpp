#include "w3d_ptr.h"
#line 1 "genparamc_8008c3a8.cpp"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Inlined STL-style vector erase-by-value. The original calls memcpy through
 * a variadic declaration (cr1 cleared) and folds copy()'s size to
 * (end - 1) - position; the vector is addressed afresh at each use. */
#define VEC(p, o) (*(W3dIntVector *)w3d::AG((char *)w3d::AG(p) + (o)))
extern "C" Ptr32<void> memcpy(...);
struct W3dIntVector {
    Ptr32<int> first;
    Ptr32<int> last;
    Ptr32<int> begin() { return first; }
    Ptr32<int> end() { return last; }
    void erase(Ptr32<int> position)
    {
        if (position + 1 != last)
            memcpy(w3d::VA(position), w3d::VA(position + 1), (last - (position + 1)) * 4);
        --last;
    }
};
extern "C" int fn_801190d0(Ptr32<void>);

extern "C" void w3d_remove_value_8008c3a8(Ptr32<void> self, Ptr32<void> object)
{
    int key = fn_801190d0(object);
    for (Ptr32<int> it = VEC(self, 296).begin(); it != VEC(self, 296).end(); ++it)
        if (*it == key) { VEC(self, 296).erase(it); return; }
}

extern "C" void w3d_remove_value_8008c49c(Ptr32<void> self, Ptr32<void> object)
{
    int key = fn_801190d0(object);
    for (Ptr32<int> it = VEC(self, 308).begin(); it != VEC(self, 308).end(); ++it)
        if (*it == key) { VEC(self, 308).erase(it); return; }
}

extern "C" void w3d_remove_value_8008c590(Ptr32<void> self, Ptr32<void> object)
{
    int key = fn_801190d0(object);
    for (Ptr32<int> it = VEC(self, 320).begin(); it != VEC(self, 320).end(); ++it)
        if (*it == key) { VEC(self, 320).erase(it); return; }
}

extern "C" void w3d_remove_value_8008c628(Ptr32<void> self, Ptr32<void> object)
{
    int key = fn_801190d0(object);
    for (Ptr32<int> it = VEC(self, 332).begin(); it != VEC(self, 332).end(); ++it)
        if (*it == key) { VEC(self, 332).erase(it); return; }
}


