#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_800bcd6c.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair templates (later batch): destructor with a member array of
 * interface references, and a masked walk over a global vector. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dPtrVector { Ptr32<Ptr32<void>> first; Ptr32<Ptr32<void>> last; Ptr32<Ptr32<void>> end_of_storage; } W3dPtrVector;
extern W3dPtrVector lbl_8043bb64;
void fn_800b5f2c(Ptr32<void>, Ptr32<void>);
int fn_800b5fc0(Ptr32<void>, Ptr32<void>);

void w3d_collect_selected_800bcd6c(Ptr32<void> self)
{
    unsigned int bit = 1;
    Ptr32<Ptr32<void>> it = lbl_8043bb64.first;
    Ptr32<Ptr32<void>> end = lbl_8043bb64.last;
    Ptr32<char> out = (Ptr32<char>)self + 256;
    if (it != end) {
        Ptr32<unsigned int> mask = (Ptr32<unsigned int>)((Ptr32<char>)self + 128);
        do {
            if (*mask & bit) {
                fn_800b5f2c(*it, out);
                out += 12;
            }
            bit <<= 1;
            if (bit == 0) {
                bit = 1;
                mask++;
            }
            it++;
        } while (it != end);
    }
}

void w3d_collect_selected_800bd8a0(Ptr32<void> self)
{
    unsigned int bit = 1;
    Ptr32<Ptr32<void>> it = lbl_8043bb64.first;
    Ptr32<Ptr32<void>> end = lbl_8043bb64.last;
    Ptr32<char> out = (Ptr32<char>)self + 256;
    if (it != end) {
        Ptr32<unsigned int> mask = (Ptr32<unsigned int>)((Ptr32<char>)self + 128);
        do {
            if (*mask & bit) {
                fn_800b5fc0(*it, out);
                out += 12;
            }
            bit <<= 1;
            if (bit == 0) {
                bit = 1;
                mask++;
            }
            it++;
        } while (it != end);
    }
}

}
