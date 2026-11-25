#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_801db984.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair template (later batch): typed child walk. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<int (Ptr32<void>)> W3dGetInt;
typedef Ptr32<void (Ptr32<void>, Ptr32<void>)> W3dMethodP;
#define ITEM(self, i) (FIELD(items, Ptr32<void> *, 8)[i])

int w3d_update_typed_children_801db984(Ptr32<void> self, Ptr32<void> argument)
{
    unsigned int i;
    for (i = 0; i < FIELD(self, unsigned int, 48); i++) {
        Ptr32<char> items = (Ptr32<char>)self + 48;
        if ((*(Ptr32<W3dGetInt>)(*(char **)ITEM(self, i) + 28))(ITEM(self, i)) == 1
            || (*(Ptr32<W3dGetInt>)(*(char **)ITEM(self, i) + 28))(ITEM(self, i)) == 2)
            (*(Ptr32<W3dMethodP>)(*(char **)ITEM(self, i) + 64))(ITEM(self, i), argument);
    }
    return 0;
}

int w3d_update_typed_children_801dbadc(Ptr32<void> self, Ptr32<void> argument)
{
    unsigned int i;
    for (i = 0; i < FIELD(self, unsigned int, 48); i++) {
        Ptr32<char> items = (Ptr32<char>)self + 48;
        if ((*(Ptr32<W3dGetInt>)(*(char **)ITEM(self, i) + 28))(ITEM(self, i)) == 1
            || (*(Ptr32<W3dGetInt>)(*(char **)ITEM(self, i) + 28))(ITEM(self, i)) == 2)
            (*(Ptr32<W3dMethodP>)(*(char **)ITEM(self, i) + 68))(ITEM(self, i), argument);
    }
    return 0;
}

}
