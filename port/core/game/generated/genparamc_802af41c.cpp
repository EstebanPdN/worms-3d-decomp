#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_802af41c.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair template (later batch): a destructor with a secondary vtable. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<void (Ptr32<void>)> W3dMethod;
#define VCALL(p, o) ((*(W3dMethod *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o)))(p))
extern char lbl_8041c590[];
extern char lbl_8041c5e0[];
void fn_802afc40(Ptr32<void>, int);
void fn_8015ff2c(Ptr32<void>, int);
extern char lbl_8041c7d0[];
extern char lbl_8041c820[];

void w3d_destroy_two_bases_802af41c(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 208) = lbl_8041c590;
    FIELD(self, void *, 0) = lbl_8041c5e0;
    if (FIELD(self, void *, 228))
        VCALL(FIELD(self, void *, 228), 16);
    if (FIELD(self, void *, 224))
        VCALL(FIELD(self, void *, 224), 16);
    fn_802afc40((Ptr32<char>)self + 28, 0);
    fn_8015ff2c(self, flags);
}

void w3d_destroy_two_bases_802ba45c(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 208) = lbl_8041c7d0;
    FIELD(self, void *, 0) = lbl_8041c820;
    if (FIELD(self, void *, 216))
        VCALL(FIELD(self, void *, 216), 16);
    if (FIELD(self, void *, 212))
        VCALL(FIELD(self, void *, 212), 16);
    fn_802afc40((Ptr32<char>)self + 28, 0);
    fn_8015ff2c(self, flags);
}

}
