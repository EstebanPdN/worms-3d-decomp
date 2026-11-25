#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_adjust_e.c"
/* Methods on the secondary base subobject (this - 4, null-checked). */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
typedef Ptr32<void (Ptr32<char>, Ptr32<char>)> S20Handler;
typedef Ptr32<void (Ptr32<S20Object>, Ptr32<char>)> S20Notify;
extern int fn_801ab98c(Ptr32<char>, Ptr32<char>);

int w3d_s20_remap_and_dispatch_801aba00(Ptr32<char> self, Ptr32<char> item) {
    int result = fn_801ab98c(self, item);
    if (result < 0)
        return result;
    {
        Ptr32<char> base = self ? w3d::R(self - 4) : 0;
        Ptr32<char> target = *(Ptr32<Ptr32<char>>)(item + 60);
        if (target != 0) {
            Ptr32<char> sub = base + 4;
            ((S20Handler)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
        }
        if (*(Ptr32<int>)(base + 80) != 0) {
            Ptr32<S20Object> owner = *(Ptr32<Ptr32<S20Object>>)(base + 44);
            ((S20Notify)owner->vtable[6])(owner, item);
        }
    }
    return 0;
}

extern int fn_8016b488(Ptr32<char>, Ptr32<char>);

int w3d_s20_apply_link_8016b5a0(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    Ptr32<char> record = *(Ptr32<Ptr32<char>>)(item + 92);
    Ptr32<char> link = *(Ptr32<Ptr32<char>>)(record + 20);
    if (link != 0) {
        *(Ptr32<int>)(base + 292) = *(Ptr32<int>)(link + 8);
        if (*(Ptr32<int>)(link + 8) != 0)
            *(Ptr32<unsigned int>)(base + 180) |= 0x80000000;
    } else {
        Ptr32<char> sub = base + 4;
        ((S20Handler)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(record + 6)])(sub, record);
    }
    return fn_8016b488(base ? w3d::R(base + 4) : 0, item);
}

}
