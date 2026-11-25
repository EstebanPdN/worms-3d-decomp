#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_801ed62c.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural.
 * Hand correction: 0x801ed900 converts to unsigned long long (it calls the
 * unsigned conversion helper), so its cast and setter type differ. */

/* Typed setters reached through a pointer to member function (third session of the day). */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
/* A g++ pointer to member function with vtable thunks (see families_u.c). */
#define PMF_FN(m, o, T) (FIELD(m, short, 2) >= 0 ? (w3d::slot_t<T>)(*(void ***)w3d::AG((o) + FIELD(m, short, 4)))[FIELD(m, short, 2) - 1] : (w3d::slot_t<T>)FIELD(m, void *, 4))
typedef Ptr32<void (Ptr32<void>, float)> W3dSetFloat;
typedef Ptr32<void (Ptr32<void>, unsigned char)> W3dSetByte;
typedef Ptr32<void (Ptr32<void>, long long)> W3dSetLong;
typedef Ptr32<void (Ptr32<void>, unsigned long long)> W3dSetULong;

void w3d_set_byte_from_float_801ed62c(Ptr32<char> self, Ptr32<char> target, Ptr32<void> unused, Ptr32<const float> value)
{
    W3dSetByte setter = PMF_FN(self + 20, target, W3dSetByte);
    setter(target + FIELD(self, short, 20), (unsigned char)*value);
}

void w3d_set_long_from_float_801ed88c(Ptr32<char> self, Ptr32<char> target, Ptr32<void> unused, Ptr32<const float> value)
{
    W3dSetLong setter = PMF_FN(self + 24, target, W3dSetLong);
    setter(target + FIELD(self, short, 24), (long long)*value);
}

void w3d_set_ulong_from_float_801ed900(Ptr32<char> self, Ptr32<char> target, Ptr32<void> unused, Ptr32<const float> value)
{
    W3dSetULong setter = PMF_FN(self + 24, target, W3dSetULong);
    setter(target + FIELD(self, short, 24), (unsigned long long)*value);
}

void w3d_set_float_member_801ed974(Ptr32<char> self, Ptr32<char> target, Ptr32<void> unused, Ptr32<const float> value)
{
    W3dSetFloat setter = PMF_FN(self + 20, target, W3dSetFloat);
    setter(target + FIELD(self, short, 20), *value);
}

void w3d_set_float_member_801ed9cc(Ptr32<char> self, Ptr32<char> target, Ptr32<void> unused, Ptr32<const float> value)
{
    W3dSetFloat setter = PMF_FN(self + 24, target, W3dSetFloat);
    setter(target + FIELD(self, short, 24), *value);
}

}
