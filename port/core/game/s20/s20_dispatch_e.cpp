#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_dispatch_e.c"
/* Repeated target dispatch on the secondary base subobject (this - 4, null-checked). */
typedef Ptr32<int (Ptr32<char>, Ptr32<char>)> S20HandlerY;
extern void fn_8016a0a4(Ptr32<char>);

int w3d_s20_dispatch_until_done_801689e4(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    int result;
    *(Ptr32<int>)(base + 152) = 0;
    result = 0;
    do {
        Ptr32<char> target = *(Ptr32<Ptr32<char>>)(item + 52);
        if (target != 0)
            result = ((S20HandlerY)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(target + 6)])(self, target);
        fn_8016a0a4(base);
        target = *(Ptr32<Ptr32<char>>)(item + 48);
        if (target != 0)
            ((S20HandlerY)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(target + 6)])(self, target);
        *(Ptr32<int>)(base + 152) += 1;
    } while (result == 1);
    return 0;
}

}
