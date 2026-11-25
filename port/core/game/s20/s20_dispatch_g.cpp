#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_dispatch_g.c"
/* Record dispatch followed by two fixed targets. */
typedef Ptr32<int (Ptr32<char>, Ptr32<char>)> S20HandlerA;

int w3d_s20_dispatch_record_two_targets_801a3cc4(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<Ptr32<void>> table = *(Ptr32<Ptr32<Ptr32<void>>>)(self + 24);
    Ptr32<char> record = *(Ptr32<Ptr32<char>>)(item + 28);
    Ptr32<Ptr32<char>> cursor = (Ptr32<Ptr32<char>>)(record + 32);
    Ptr32<Ptr32<char>> end = cursor + *(Ptr32<unsigned int>)(record + 24);
    Ptr32<Ptr32<void>> later;
    Ptr32<char> target;
    int status;
    for (; cursor != end; cursor++) {
        Ptr32<char> entry = *cursor;
        status = ((S20HandlerA)table[*(Ptr32<unsigned short>)(entry + 6)])(self, entry);
        if (status < 0)
            return status;
    }
    target = *(Ptr32<Ptr32<char>>)(item + 36);
    later = *(Ptr32<Ptr32<Ptr32<void>>>)(self + 24);
    status = ((S20HandlerA)later[*(Ptr32<unsigned short>)(target + 6)])(self, target);
    if (status < 0)
        return status;
    target = *(Ptr32<Ptr32<char>>)(item + 32);
    status = ((S20HandlerA)later[*(Ptr32<unsigned short>)(target + 6)])(self, target);
    if (status < 0)
        return status;
    return 0;
}

}
