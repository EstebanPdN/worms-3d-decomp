#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_adjust_g.c"
/* Method on the secondary base subobject (this - 4, null-checked). */
int w3d_s20_remap_item_indices_801ab98c(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    if (*(Ptr32<int>)(base + 88) != 0) {
        Ptr32<char> t32 = base + 264;
        Ptr32<char> t28 = base + 248;
        Ptr32<char> t24 = base + 280;
        int o32 = *(Ptr32<int>)(item + 32) * 4;
        int o28 = *(Ptr32<int>)(item + 28) * 4;
        int o24 = *(Ptr32<int>)(item + 24) * 4;
        *(Ptr32<int>)(item + 32) = *(Ptr32<int>)(t32 + o32);
        *(Ptr32<int>)(item + 28) = *(Ptr32<int>)(t28 + o28);
        *(Ptr32<int>)(item + 24) = *(Ptr32<int>)(t24 + o24);
    }
    if (*(Ptr32<int>)(base + 112) != 0)
        *(Ptr32<float>)(item + 44) = *(Ptr32<float>)(base + 116);
    return 0;
}

}
