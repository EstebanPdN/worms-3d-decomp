#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_adjust_i.c"
/* Method on the secondary base subobject (this - 4, null-checked). */
typedef struct S20Block24 { int words[6]; } S20Block24;
typedef Ptr32<void (Ptr32<char>, Ptr32<char>)> S20HandlerI;

int w3d_s20_refresh_item_block_801a5b60(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    if (*(Ptr32<int>)(item + 44) == 0) {
        ((Ptr32<void (Ptr32<char>, Ptr32<char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)base)[19])(base, item + 20);
        return 0;
    }
    {
        Ptr32<char> target = *(Ptr32<Ptr32<char>>)(item + 80);
        Ptr32<S20Block24> block;
        if (target != 0) {
            Ptr32<char> sub = base + 4;
            ((S20HandlerI)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
        }
        block = ((Ptr32<Ptr32<S20Block24> (Ptr32<char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)base)[18])(base);
        *(Ptr32<S20Block24>)(item + 20) = *block;
        if (*(Ptr32<unsigned int>)(base + 88) & 1)
            *(Ptr32<int>)(item + 44) = 0;
    }
    return 0;
}

}
