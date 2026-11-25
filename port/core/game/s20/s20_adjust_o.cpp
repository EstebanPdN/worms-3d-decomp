#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_adjust_o.c"
/* Method on the secondary base subobject (this - 4, null-checked). */
typedef Ptr32<void (Ptr32<char>, Ptr32<char>)> S20HandlerP;

int w3d_s20_dispatch_item_fields_8016b488(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    Ptr32<char> target;
    *(Ptr32<int>)(base + 284) = 0;
    *(Ptr32<int>)(base + 288) = 0;
    target = *(Ptr32<Ptr32<char>>)(item + 64);
    if (target != 0) {
        Ptr32<char> sub = base + 4;
        ((S20HandlerP)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
    } else {
        *(Ptr32<Ptr32<char>>)(base + 124) = target;
    }
    target = *(Ptr32<Ptr32<char>>)(item + 80);
    if (target != 0) {
        Ptr32<char> sub = base + 4;
        ((S20HandlerP)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
    }
    target = *(Ptr32<Ptr32<char>>)(item + 72);
    if (target != 0) {
        Ptr32<char> sub = base + 4;
        ((S20HandlerP)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
    }
    target = *(Ptr32<Ptr32<char>>)(item + 68);
    if (target != 0) {
        Ptr32<char> sub = base + 4;
        ((S20HandlerP)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
    }
    target = *(Ptr32<Ptr32<char>>)(item + 76);
    if (target != 0) {
        Ptr32<char> sub = base + 4;
        ((S20HandlerP)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
    }
    return 0;
}

}
