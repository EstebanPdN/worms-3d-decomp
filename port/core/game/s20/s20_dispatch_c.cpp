#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_dispatch_c.c"
/* Target dispatch followed by a per-kind handler. */
typedef struct S20KindSource { char pad[32]; unsigned int word; } S20KindSource;
extern Ptr32<S20KindSource> lbl_80363cf8[];

int w3d_s20_dispatch_target_then_kind_801a49d8(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> target = *(Ptr32<Ptr32<char>>)(item + 48);
    if (target != 0) {
        int result = ((Ptr32<int (Ptr32<char>, Ptr32<char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(target + 6)])(self, target);
        if (result < 0)
            return result;
    }
    return ((Ptr32<int (Ptr32<char>, Ptr32<char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[(lbl_80363cf8[0]->word >> 22) & 1023])(self, item);
}

}
