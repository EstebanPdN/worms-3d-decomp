#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_801ec3fc.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair template (third session of the day). */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))




/* A g++ pointer to member function with vtable thunks: delta, index
 * (negative for non-virtual) and either the function or the vtable offset. */
typedef struct W3dPmf { short delta; short index; union { Ptr32<void> function; short vtable; } u; } W3dPmf;
typedef Ptr32<float (Ptr32<void>)> W3dGetFloat;
typedef Ptr32<void (Ptr32<void>, float)> W3dSetFloat;
#define PMF_FN(m, o, T) (FIELD(m, short, 2) >= 0 ? (w3d::slot_t<T>)(*(void ***)w3d::AG((o) + FIELD(m, short, 4)))[FIELD(m, short, 2) - 1] \
                                                 : (w3d::slot_t<T>)FIELD(m, void *, 4))


void w3d_copy_float_property_801ec3fc(Ptr32<char> self, Ptr32<char> target, Ptr32<char> source, Ptr32<char> from)
{
    W3dSetFloat setter = PMF_FN(self + 20, target, W3dSetFloat);
    Ptr32<char> setter_this = target + FIELD(self, short, 20);
    W3dGetFloat getter = PMF_FN(from + 12, source, W3dGetFloat);
    setter(setter_this, getter(source + FIELD(from, short, 12)));
}

void w3d_copy_float_property_801ec5b8(Ptr32<char> self, Ptr32<char> target, Ptr32<char> source, Ptr32<char> from)
{
    W3dSetFloat setter = PMF_FN(self + 24, target, W3dSetFloat);
    Ptr32<char> setter_this = target + FIELD(self, short, 24);
    W3dGetFloat getter = PMF_FN(from + 16, source, W3dGetFloat);
    setter(setter_this, getter(source + FIELD(from, short, 16)));
}

}
