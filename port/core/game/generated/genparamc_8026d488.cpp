#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_8026d488.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair template (later batch): three-word value setter that notifies an
 * attached object unconditionally (see families_j.c for the guarded form). */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dTriple { int a; int b; int c; } W3dTriple;
typedef Ptr32<void (Ptr32<void>, Ptr32<void>, int)> W3dNotify;

void w3d_set_triple_notify_8026d488(Ptr32<void> self, Ptr32<const W3dTriple> value)
{
    Ptr32<W3dTriple> current = &FIELD(self, W3dTriple, 44);
    int same = current->a == value->a && current->b == value->b && current->c == value->c;
    if (!same) {
        Ptr32<void> listener;
        FIELD(self, W3dTriple, 44) = *value;
        listener = FIELD(self, void *, 76);
        (*(Ptr32<W3dNotify>)(*(Ptr32<Ptr32<char>>)listener + 84))(listener, &FIELD(self, W3dTriple, 44), 0);
    }
}

void w3d_set_triple_notify_8026d524(Ptr32<void> self, Ptr32<const W3dTriple> value)
{
    Ptr32<W3dTriple> current = &FIELD(self, W3dTriple, 32);
    int same = current->a == value->a && current->b == value->b && current->c == value->c;
    if (!same) {
        Ptr32<void> listener;
        FIELD(self, W3dTriple, 32) = *value;
        listener = FIELD(self, void *, 76);
        (*(Ptr32<W3dNotify>)(*(Ptr32<Ptr32<char>>)listener + 76))(listener, &FIELD(self, W3dTriple, 32), 0);
    }
}

}
