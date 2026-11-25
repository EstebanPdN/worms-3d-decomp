#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20param_80172088.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Small forwarding wrappers. */
extern Ptr32<char> fn_8019a2a8(Ptr32<char>, int);
extern void fn_800fde98(Ptr32<void>, int);
extern void fn_800fdf58(Ptr32<void>, int);
extern Ptr32<void> lbl_804aaf64;
extern void fn_8016f650(int);
extern int lbl_803a54e4[];
extern int fn_801720fc(Ptr32<char>, int);

int w3d_s20_get_selected_80172088(Ptr32<char> self, Ptr32<void> arg_r4) {
    int index = fn_801720fc(self, w3d::H(arg_r4));
    return *(Ptr32<int>)(*(Ptr32<Ptr32<char>>)(self + 72) + index * 4);
}

}
