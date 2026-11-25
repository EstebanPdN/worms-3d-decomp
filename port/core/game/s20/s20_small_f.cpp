#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_f.c"
/* Small handlers touching small-data globals. */
extern int fn_8016ee10(Ptr32<void>, Ptr32<int>);
extern Ptr32<void> lbl_804b1888;
extern Ptr32<void> lbl_804b1884;

int w3d_s20_publish_current_801673f0(Ptr32<char> self) {
    int value = *(Ptr32<int>)(self + 40);
    lbl_804b1884 = self;
    fn_8016ee10(lbl_804b1888, &value);
    return 0;
}

int w3d_s20_dispatch_target_801a3b58(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> target = *(Ptr32<Ptr32<char>>)(item + 60);
    if (target != 0)
        ((Ptr32<void (Ptr32<char>, Ptr32<char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(target + 6)])(self, target);
    return 0;
}

}
