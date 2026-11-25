#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_key_dispatch_801aade4.c"
typedef Ptr32<int (Ptr32<char>, Ptr32<char>)> K8bHandler;
extern Ptr32<int> fn_801d0858(Ptr32<char>, Ptr32<int>);

int w3d_k8b_key_dispatch_801aade4(Ptr32<char> self, unsigned int key)
{
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    int found;
    Ptr32<int> slot;
    Ptr32<char> target;
    *(Ptr32<unsigned short>)(base + 230) = key ^ (key >> 16);
    slot = fn_801d0858((Ptr32<char>)w3d::G(key), &found);
    target = 0;
    if (found != 0)
        target = *(Ptr32<Ptr32<char>>)slot;
    if (target != 0) {
        Ptr32<Ptr32<void>> table = *(Ptr32<Ptr32<Ptr32<void>>>)(base + 28);
        return ((K8bHandler)table[*(Ptr32<unsigned short>)(target + 6)])(base ? w3d::R(base + 4) : 0, target);
    }
    return 0;
}

}
