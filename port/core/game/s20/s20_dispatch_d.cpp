#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_dispatch_d.c"
/* Handler-table dispatch variants. */
typedef Ptr32<int (Ptr32<char>, Ptr32<char>)> S20HandlerX;

static inline int s20_dispatch_all(Ptr32<char> sub, Ptr32<char> record) {
    Ptr32<Ptr32<char>> cursor = (Ptr32<Ptr32<char>>)(record + 32);
    Ptr32<Ptr32<char>> end = cursor + *(Ptr32<unsigned int>)(record + 24);
    for (; cursor != end; cursor++) {
        Ptr32<char> entry = *cursor;
        Ptr32<Ptr32<void>> table = *(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24);
        int status = ((S20HandlerX)table[*(Ptr32<unsigned short>)(entry + 6)])(sub, entry);
        if (status < 0)
            return status;
    }
    return 0;
}

int w3d_s20_dispatch_two_results_801ac41c(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> target = *(Ptr32<Ptr32<char>>)(item + 52);
    int result = 0;
    if (target != 0)
        result = ((S20HandlerX)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(target + 6)])(self, target);
    target = *(Ptr32<Ptr32<char>>)(item + 48);
    if (target != 0)
        result = ((S20HandlerX)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(target + 6)])(self, target);
    return result;
}

int w3d_s20_dispatch_masked_801a3a44(Ptr32<char> self, Ptr32<char> item) {
    unsigned int mask = *(Ptr32<unsigned int>)(item + 20);
    unsigned int flags = *(Ptr32<unsigned int>)(self + 32);
    Ptr32<char> owner = *(Ptr32<Ptr32<char>>)(self + 20);
    if ((flags & mask) != 0)
        return s20_dispatch_all(self, *(Ptr32<Ptr32<char>>)(owner + 44));
    return 0;
}

int w3d_s20_dispatch_target_or_record_801a381c(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> target = *(Ptr32<Ptr32<char>>)(item + 48);
    if (target != 0) {
        *(Ptr32<Ptr32<char>>)(self + 20) = item;
        return ((S20HandlerX)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(target + 6)])(self, target);
    }
    return s20_dispatch_all(self, *(Ptr32<Ptr32<char>>)(item + 44));
}

}
