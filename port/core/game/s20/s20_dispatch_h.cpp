#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_dispatch_h.c"
/* Record and fixed-target dispatch through the handler table. */
typedef Ptr32<int (Ptr32<char>, Ptr32<char>)> S20HandlerB;

int w3d_s20_dispatch_two_records_801a3d90(Ptr32<char> self, Ptr32<char> item) {
    {
        Ptr32<Ptr32<void>> table = *(Ptr32<Ptr32<Ptr32<void>>>)(self + 24);
        Ptr32<char> record = *(Ptr32<Ptr32<char>>)(item + 32);
        Ptr32<Ptr32<char>> cursor = (Ptr32<Ptr32<char>>)(record + 32);
        Ptr32<Ptr32<char>> end = cursor + *(Ptr32<unsigned int>)(record + 24);
        for (; cursor != end; cursor++) {
            Ptr32<char> entry = *cursor;
            int status = ((S20HandlerB)table[*(Ptr32<unsigned short>)(entry + 6)])(self, entry);
            if (status < 0)
                return status;
        }
    }
    {
        Ptr32<Ptr32<void>> table = *(Ptr32<Ptr32<Ptr32<void>>>)(self + 24);
        Ptr32<char> record = *(Ptr32<Ptr32<char>>)(item + 28);
        Ptr32<Ptr32<char>> cursor = (Ptr32<Ptr32<char>>)(record + 32);
        Ptr32<Ptr32<char>> end = cursor + *(Ptr32<unsigned int>)(record + 24);
        for (; cursor != end; cursor++) {
            Ptr32<char> entry = *cursor;
            int status = ((S20HandlerB)table[*(Ptr32<unsigned short>)(entry + 6)])(self, entry);
            if (status < 0)
                return status;
        }
    }
    return 0;
}

int w3d_s20_dispatch_five_targets_801a4874(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> target;
    target = *(Ptr32<Ptr32<char>>)(item + 80);
    if (target != 0)
        ((S20HandlerB)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(target + 6)])(self, target);
    target = *(Ptr32<Ptr32<char>>)(item + 72);
    if (target != 0)
        ((S20HandlerB)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(target + 6)])(self, target);
    target = *(Ptr32<Ptr32<char>>)(item + 76);
    if (target != 0)
        ((S20HandlerB)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(target + 6)])(self, target);
    target = *(Ptr32<Ptr32<char>>)(item + 68);
    if (target != 0)
        ((S20HandlerB)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(target + 6)])(self, target);
    target = *(Ptr32<Ptr32<char>>)(item + 64);
    if (target != 0)
        ((S20HandlerB)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(target + 6)])(self, target);
    return 0;
}

}
