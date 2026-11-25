#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_adjust_n.c"
/* Methods on the secondary base subobject (this - 4, null-checked). */
typedef Ptr32<int (Ptr32<char>, Ptr32<char>)> S20HandlerN;
extern int fn_801a9cbc(Ptr32<char>, Ptr32<char>);

static inline int s20_dispatch_all(Ptr32<char> sub, Ptr32<char> record) {
    Ptr32<Ptr32<char>> cursor = (Ptr32<Ptr32<char>>)(record + 32);
    Ptr32<Ptr32<char>> end = cursor + *(Ptr32<unsigned int>)(record + 24);
    for (; cursor != end; cursor++) {
        Ptr32<char> entry = *cursor;
        Ptr32<Ptr32<void>> table = *(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24);
        int status = ((S20HandlerN)table[*(Ptr32<unsigned short>)(entry + 6)])(sub, entry);
        if (status < 0)
            return status;
    }
    return 0;
}

int w3d_s20_dispatch_all_targets_801aa79c(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    int saved = *(Ptr32<int>)(base + 44);
    int result;
    if (saved != 0) {
        Ptr32<char> sub;
        if (fn_801a9cbc(base, item + 20) == 0)
            return 0;
        sub = base ? w3d::R(base + 4) : 0;
        result = s20_dispatch_all(sub, *(Ptr32<Ptr32<char>>)(item + 44));
        *(Ptr32<int>)(base + 44) = saved;
        return result;
    }
    {
        Ptr32<char> sub = base ? w3d::R(base + 4) : 0;
        return s20_dispatch_all(sub, *(Ptr32<Ptr32<char>>)(item + 44));
    }
}

int w3d_s20_dispatch_item_targets_801aa8cc(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    int saved;
    int result;
    Ptr32<char> target;
    if (((*(Ptr32<unsigned char>)(item + 8) ^ 4) & 4) == 0)
        return 0;
    saved = *(Ptr32<int>)(base + 44);
    if (saved != 0) {
        if (fn_801a9cbc(base, item + 20) == 0)
            return 0;
    }
    target = *(Ptr32<Ptr32<char>>)(item + 48);
    if (target != 0) {
        Ptr32<char> sub = base + 4;
        *(Ptr32<Ptr32<char>>)(sub + 20) = item;
        result = ((S20HandlerN)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
    } else {
        Ptr32<char> sub = base ? w3d::R(base + 4) : 0;
        result = s20_dispatch_all(sub, *(Ptr32<Ptr32<char>>)(item + 44));
    }
    *(Ptr32<int>)(base + 44) = saved;
    return result;
}

}
