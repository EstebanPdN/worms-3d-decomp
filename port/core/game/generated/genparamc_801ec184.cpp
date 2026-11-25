#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_801ec184.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair templates (later batch): counted reference array destructor, 64-bit
 * property copy through pointers to member functions, clipped block copy. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
/* A g++ pointer to member function with vtable thunks (see families_u.c). */
#define PMF_FN(m, o, T) (FIELD(m, short, 2) >= 0 ? (w3d::slot_t<T>)(*(void ***)w3d::AG((o) + FIELD(m, short, 4)))[FIELD(m, short, 2) - 1] : (w3d::slot_t<T>)FIELD(m, void *, 4))
typedef Ptr32<long long (Ptr32<void>)> W3dGetLong;
typedef Ptr32<void (Ptr32<void>, long long)> W3dSetLong;

void w3d_copy_long_property_801ec184(Ptr32<char> self, Ptr32<char> target, Ptr32<char> source, Ptr32<char> from)
{
    W3dSetLong setter = PMF_FN(self + 24, target, W3dSetLong);
    Ptr32<char> setter_this = target + FIELD(self, short, 24);
    W3dGetLong getter = PMF_FN(from + 16, source, W3dGetLong);
    setter(setter_this, getter(source + FIELD(from, short, 16)));
}

void w3d_copy_long_property_801ec2c0(Ptr32<char> self, Ptr32<char> target, Ptr32<char> source, Ptr32<char> from)
{
    W3dSetLong setter = PMF_FN(self + 24, target, W3dSetLong);
    Ptr32<char> setter_this = target + FIELD(self, short, 24);
    W3dGetLong getter = PMF_FN(from + 16, source, W3dGetLong);
    setter(setter_this, getter(source + FIELD(from, short, 16)));
}

}
