#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_801ec224.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair templates (third session of the day). */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
/* A g++ pointer to member function with vtable thunks (see families_u.c). */
#define PMF_FN(m, o, T) (FIELD(m, short, 2) >= 0 ? (w3d::slot_t<T>)(*(void ***)w3d::AG((o) + FIELD(m, short, 4)))[FIELD(m, short, 2) - 1] : (w3d::slot_t<T>)FIELD(m, void *, 4))
typedef Ptr32<void (Ptr32<void>, long long)> W3dSetLong;
typedef Ptr32<int (Ptr32<void>, Ptr32<long long>, Ptr32<void>, int)> W3dGetLong;
typedef struct W3dArg20 { int words[5]; } W3dArg20;
typedef Ptr32<int (Ptr32<void>, Ptr32<void>, Ptr32<W3dArg20>)> W3dForward;
int fn_801f9fbc(Ptr32<void>, int, int);

int w3d_apply_long_property_801ec224(Ptr32<char> self, Ptr32<void> argument, Ptr32<char> target)
{
    long long value;
    Ptr32<void> source = FIELD(*(Ptr32<Ptr32<char>>)self, void *, 8);
    int result = (*(Ptr32<W3dGetLong>)(*(Ptr32<Ptr32<char>>)source + 72))(source, &value, argument, 0);
    if (result >= 0) {
        W3dSetLong setter = PMF_FN(self + 24, target, W3dSetLong);
        setter(target + FIELD(self, short, 24), value);
    }
    return result;
}

int w3d_apply_long_property_801ec360(Ptr32<char> self, Ptr32<void> argument, Ptr32<char> target)
{
    long long value;
    Ptr32<void> source = FIELD(*(Ptr32<Ptr32<char>>)self, void *, 8);
    int result = (*(Ptr32<W3dGetLong>)(*(Ptr32<Ptr32<char>>)source + 72))(source, &value, argument, 0);
    if (result >= 0) {
        W3dSetLong setter = PMF_FN(self + 24, target, W3dSetLong);
        setter(target + FIELD(self, short, 24), value);
    }
    return result;
}

int w3d_forward_indexed_801fb824(Ptr32<char> self, Ptr32<void> argument, Ptr32<W3dArg20> request)
{
    int index = fn_801f9fbc(self + 36, request->words[0], request->words[2]);
    W3dArg20 copy = *request;
    Ptr32<void> entry;
    copy.words[2] = index;
    entry = *(Ptr32<Ptr32<void>>)(FIELD(self, char *, 36) + (index << 2));
    return (*(Ptr32<W3dForward>)(*(Ptr32<Ptr32<char>>)entry + 28))(entry, argument, &copy);
}

int w3d_forward_indexed_801fb8b8(Ptr32<char> self, Ptr32<void> argument, Ptr32<W3dArg20> request)
{
    int index = fn_801f9fbc(self + 36, request->words[0], request->words[2]);
    W3dArg20 copy = *request;
    Ptr32<void> entry;
    copy.words[2] = index;
    entry = *(Ptr32<Ptr32<void>>)(FIELD(self, char *, 36) + (index << 2));
    return (*(Ptr32<W3dForward>)(*(Ptr32<Ptr32<char>>)entry + 32))(entry, argument, &copy);
}

}
