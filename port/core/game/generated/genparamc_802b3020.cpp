#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_802b3020.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-22 (third session), ninth batch. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dTriple { int a; int b; int c; } W3dTriple;
typedef Ptr32<void (Ptr32<void>, Ptr32<void>, int)> W3dNotify;

void w3d_set_triple_802b3020(Ptr32<void> self, Ptr32<const W3dTriple> value)
{
    Ptr32<W3dTriple> current = &FIELD(self, W3dTriple, 68);
    int same = current->a == value->a && current->b == value->b && current->c == value->c;
    if (!same) {
        Ptr32<void> listener;
        FIELD(self, W3dTriple, 68) = *value;
        listener = FIELD(self, void *, 28);
        if (listener)
            (*(Ptr32<W3dNotify>)(*(Ptr32<Ptr32<char>>)listener + 76))(listener, &FIELD(self, W3dTriple, 68), 0);
    }
}

void w3d_set_triple_802c61fc(Ptr32<void> self, Ptr32<const W3dTriple> value)
{
    Ptr32<W3dTriple> current = &FIELD(self, W3dTriple, 60);
    int same = current->a == value->a && current->b == value->b && current->c == value->c;
    if (!same) {
        Ptr32<void> listener;
        FIELD(self, W3dTriple, 60) = *value;
        listener = FIELD(self, void *, 28);
        if (listener)
            (*(Ptr32<W3dNotify>)(*(Ptr32<Ptr32<char>>)listener + 76))(listener, &FIELD(self, W3dTriple, 60), 0);
    }
}

void w3d_set_triple_802c71d8(Ptr32<void> self, Ptr32<const W3dTriple> value)
{
    Ptr32<W3dTriple> current = &FIELD(self, W3dTriple, 112);
    int same = current->a == value->a && current->b == value->b && current->c == value->c;
    if (!same) {
        Ptr32<void> listener;
        FIELD(self, W3dTriple, 112) = *value;
        listener = FIELD(self, void *, 28);
        if (listener)
            (*(Ptr32<W3dNotify>)(*(Ptr32<Ptr32<char>>)listener + 76))(listener, &FIELD(self, W3dTriple, 112), 0);
    }
}

}
