#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_adjust_f.c"
/* Methods on the secondary base subobject (this - 4, null-checked). */
typedef Ptr32<void (Ptr32<char>, Ptr32<char>)> S20Handler;

int w3d_s20_dispatch_two_targets_80166a70(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    if (*(Ptr32<int>)(base + 52) != 0) {
        Ptr32<char> target = *(Ptr32<Ptr32<char>>)(item + 52);
        if (target != 0) {
            Ptr32<char> sub = base + 4;
            ((S20Handler)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
        }
    }
    if (*(Ptr32<int>)(base + 56) != 0) {
        Ptr32<char> target = *(Ptr32<Ptr32<char>>)(item + 48);
        if (target != 0) {
            Ptr32<char> sub = base + 4;
            ((S20Handler)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
        }
    }
    return 0;
}

}
