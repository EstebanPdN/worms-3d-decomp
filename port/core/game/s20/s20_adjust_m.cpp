#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_adjust_m.c"
/* Method on the secondary base subobject (this - 4, null-checked). */
typedef Ptr32<void (Ptr32<char>, Ptr32<char>)> S20HandlerM;

int w3d_s20_collect_item_modes_801d58d0(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    int zero = 0;
    int first;
    int second;
    int mode;
    Ptr32<char> target;
    *(Ptr32<int>)(base + 44) = zero;
    target = *(Ptr32<Ptr32<char>>)(item + 52);
    if (target != 0) {
        Ptr32<char> sub = base + 4;
        ((S20HandlerM)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
    }
    first = *(Ptr32<int>)(base + 44);
    *(Ptr32<int>)(base + 44) = zero;
    target = *(Ptr32<Ptr32<char>>)(item + 48);
    if (target != 0) {
        Ptr32<char> sub = base + 4;
        ((S20HandlerM)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
    }
    second = *(Ptr32<int>)(base + 44);
    mode = 0;
    if (first == 1 || second == 1)
        mode = 1;
    else if (first == 2 || second == 2)
        mode = 2;
    if (*(Ptr32<int>)(base + 48) != 0)
        *(Ptr32<unsigned int>)(item + 56) = (*(Ptr32<unsigned int>)(item + 56) & ~6u) | 2;
    else
        *(Ptr32<unsigned int>)(item + 56) = (*(Ptr32<unsigned int>)(item + 56) & ~6u) | (mode << 1);
    return 0;
}

}
