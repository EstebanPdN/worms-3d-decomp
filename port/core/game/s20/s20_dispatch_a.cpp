#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_dispatch_a.c"
/* Handler-table dispatch over the targets of a record. */
typedef Ptr32<int (Ptr32<char>, Ptr32<char>)> S20HandlerV;

static inline int s20_dispatch_all(Ptr32<char> sub, Ptr32<char> record) {
    Ptr32<Ptr32<char>> cursor = (Ptr32<Ptr32<char>>)(record + 32);
    Ptr32<Ptr32<char>> end = cursor + *(Ptr32<unsigned int>)(record + 24);
    for (; cursor != end; cursor++) {
        Ptr32<char> entry = *cursor;
        Ptr32<Ptr32<void>> table = *(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24);
        int status = ((S20HandlerV)table[*(Ptr32<unsigned short>)(entry + 6)])(sub, entry);
        if (status < 0)
            return status;
    }
    return 0;
}

int w3d_s20_dispatch_item_record_801a37a0(Ptr32<char> self, Ptr32<char> item) {
    return s20_dispatch_all(self, *(Ptr32<Ptr32<char>>)(item + 44));
}

int w3d_s20_dispatch_owner_record_801a3944(Ptr32<char> self) {
    return s20_dispatch_all(self, *(Ptr32<Ptr32<char>>)(*(Ptr32<Ptr32<char>>)(self + 20) + 44));
}

int w3d_s20_dispatch_owner_record_801a39c4(Ptr32<char> self) {
    return s20_dispatch_all(self, *(Ptr32<Ptr32<char>>)(*(Ptr32<Ptr32<char>>)(self + 20) + 44));
}

int w3d_s20_dispatch_two_targets_801a3adc(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> target = *(Ptr32<Ptr32<char>>)(item + 52);
    if (target != 0)
        ((Ptr32<void (Ptr32<char>, Ptr32<char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(target + 6)])(self, target);
    target = *(Ptr32<Ptr32<char>>)(item + 48);
    if (target != 0)
        ((Ptr32<void (Ptr32<char>, Ptr32<char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(target + 6)])(self, target);
    return 0;
}

}
