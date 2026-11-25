#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_dispatch_f.c"
/* Record dispatch followed by an optional looked-up target. */
typedef Ptr32<int (Ptr32<char>, Ptr32<char>)> S20HandlerZ;
extern Ptr32<int> fn_801d0858(Ptr32<char>, Ptr32<int>);

int w3d_s20_dispatch_record_then_lookup_801a3ba0(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<Ptr32<void>> table = *(Ptr32<Ptr32<Ptr32<void>>>)(self + 24);
    Ptr32<char> record = *(Ptr32<Ptr32<char>>)(item + 28);
    Ptr32<Ptr32<char>> cursor = (Ptr32<Ptr32<char>>)(record + 32);
    Ptr32<Ptr32<char>> end = cursor + *(Ptr32<unsigned int>)(record + 24);
    int found;
    Ptr32<int> slot;
    Ptr32<char> target;
    for (; cursor != end; cursor++) {
        Ptr32<char> entry = *cursor;
        int status = ((S20HandlerZ)table[*(Ptr32<unsigned short>)(entry + 6)])(self, entry);
        if (status < 0)
            return status;
    }
    slot = fn_801d0858(item, &found);
    target = 0;
    if (found != 0)
        target = *(Ptr32<Ptr32<char>>)slot;
    if (target != 0) {
        Ptr32<Ptr32<void>> later = *(Ptr32<Ptr32<Ptr32<void>>>)(self + 24);
        int status = ((S20HandlerZ)later[*(Ptr32<unsigned short>)(target + 6)])(self, target);
        if (status < 0)
            return status;
    }
    return 0;
}

}
