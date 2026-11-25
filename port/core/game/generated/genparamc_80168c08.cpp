#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_80168c08.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair templates (later batch): grid cell lookup, message dispatch through a
 * handler table, and a binding with a copied range. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<void (Ptr32<void>, Ptr32<void>)> W3dMethodP;
typedef Ptr32<Ptr32<void> (Ptr32<void>)> W3dGet;
typedef Ptr32<int (Ptr32<void>, Ptr32<void>)> W3dHandler2;

int w3d_dispatch_by_kind_80168c08(Ptr32<void> iface, Ptr32<void> message)
{
    Ptr32<char> self = iface ? w3d::R((Ptr32<char>)iface - 4) : 0;
    Ptr32<void> target;
    (*(Ptr32<W3dMethodP>)(*(Ptr32<Ptr32<char>>)self + 68))(self, message);
    target = (*(Ptr32<W3dGet>)(*(Ptr32<Ptr32<char>>)message + 20))(message);
    return FIELD(iface, W3dHandler2 *, 24)[(FIELD(FIELD(target, char *, 20), unsigned int, 32) >> 22) & 0x3ff](iface, message);
}

int w3d_dispatch_by_kind_801ac49c(Ptr32<void> iface, Ptr32<void> message)
{
    Ptr32<char> self = iface ? w3d::R((Ptr32<char>)iface - 4) : 0;
    Ptr32<void> target;
    (*(Ptr32<W3dMethodP>)(*(Ptr32<Ptr32<char>>)self + 68))(self, message);
    target = (*(Ptr32<W3dGet>)(*(Ptr32<Ptr32<char>>)message + 20))(message);
    return FIELD(iface, W3dHandler2 *, 24)[(FIELD(FIELD(target, char *, 20), unsigned int, 32) >> 22) & 0x3ff](iface, message);
}

}
