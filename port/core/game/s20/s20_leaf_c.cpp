#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_leaf_c.c"
extern Ptr32<char> lbl_8045ce40[];
int w3d_s20_clear_flag_for_kind_801a2324(Ptr32<char> self, Ptr32<char> item) {
    unsigned int word = *(Ptr32<unsigned int>)(item + 32);
    if (((word >> 16) & 15) == 3)
        ((Ptr32<char>)lbl_8045ce40[0])[word >> 22] = 0;
    return 0;
}

}
