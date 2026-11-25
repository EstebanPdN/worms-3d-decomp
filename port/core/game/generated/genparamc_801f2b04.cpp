#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_801f2b04.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair template (later batch): reference array assignment. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<void (Ptr32<void>)> W3dMethod;
#define VCALL(p, o) ((*(W3dMethod *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o)))(p))
void fn_801f282c(Ptr32<void>, unsigned int);
void fn_80210b90(Ptr32<void>, unsigned int);

Ptr32<void> w3d_assign_refs_801f2b04(Ptr32<void> self, Ptr32<void> other)
{
    unsigned int i;
    fn_801f282c(self, FIELD(other, unsigned int, 0));
    for (i = 0; i < FIELD(other, unsigned int, 0); i++) {
        Ptr32<Ptr32<void>> source = FIELD(other, void **, 8);
        Ptr32<Ptr32<void>> target = FIELD(self, void **, 8);
        if (source[i])
            VCALL(source[i], 12);
        if (target[i])
            VCALL(target[i], 16);
        target[i] = source[i];
    }
    return self;
}

Ptr32<void> w3d_assign_refs_80210eb4(Ptr32<void> self, Ptr32<void> other)
{
    unsigned int i;
    fn_80210b90(self, FIELD(other, unsigned int, 0));
    for (i = 0; i < FIELD(other, unsigned int, 0); i++) {
        Ptr32<Ptr32<void>> source = FIELD(other, void **, 8);
        Ptr32<Ptr32<void>> target = FIELD(self, void **, 8);
        if (source[i])
            VCALL(source[i], 12);
        if (target[i])
            VCALL(target[i], 16);
        target[i] = source[i];
    }
    return self;
}

}
