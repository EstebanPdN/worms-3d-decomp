#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_adjust_l.c"
/* Method on the secondary base subobject (this - 4, null-checked). */
typedef Ptr32<int (Ptr32<char>, Ptr32<char>)> S20HandlerL;
extern void fn_801a9b10(Ptr32<char>);
extern void fn_801a9c9c(Ptr32<char>);

int w3d_s20_dispatch_with_guard_801aace0(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    int saved = *(Ptr32<int>)(base + 324);
    int result;
    if (saved == 0) {
        unsigned char first;
        unsigned char second;
        Ptr32<char> entry;
        fn_801a9b10(base);
        second = *(Ptr32<unsigned char>)(item + 25);
        first = *(Ptr32<unsigned char>)(item + 24);
        *(Ptr32<unsigned char>)(base + 305) = first;
        *(Ptr32<unsigned char>)(base + 304) = second;
        entry = *(Ptr32<Ptr32<char>>)(base + 288) + second * 16;
        if (*(Ptr32<int>)(entry + 12) == 3) {
            Ptr32<char> sub;
            Ptr32<char> target;
            *(Ptr32<int>)(base + 324) = 1;
            sub = base + 4;
            target = *(Ptr32<Ptr32<char>>)(item + 20);
            result = ((S20HandlerL)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
            *(Ptr32<int>)(base + 324) = saved;
        } else {
            Ptr32<char> target = *(Ptr32<Ptr32<char>>)(item + 20);
            Ptr32<char> sub = base + 4;
            result = ((S20HandlerL)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
        }
        fn_801a9c9c(base);
    } else {
        Ptr32<char> target = *(Ptr32<Ptr32<char>>)(item + 20);
        Ptr32<char> sub = base + 4;
        result = ((S20HandlerL)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
    }
    return result;
}

}
