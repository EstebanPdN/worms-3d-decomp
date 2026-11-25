#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_adjust_k.c"
/* Methods on the secondary base subobject (this - 4, null-checked). */
typedef struct S20Block16 { int words[4]; } S20Block16;
typedef Ptr32<void (Ptr32<char>, Ptr32<char>)> S20HandlerK;
extern char lbl_8045e63c[];
extern int fn_801a572c(Ptr32<char>, Ptr32<char>);

int w3d_s20_refresh_item_block_801a5a6c(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    if (*(Ptr32<int>)(item + 40) == 0) {
        ((Ptr32<void (Ptr32<char>, Ptr32<char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)base)[17])(base, item + 20);
        return 0;
    }
    {
        Ptr32<char> target;
        Ptr32<S20Block16> block;
        ((Ptr32<void (Ptr32<char>, Ptr32<char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)base)[17])(base, lbl_8045e63c);
        target = *(Ptr32<Ptr32<char>>)(item + 48);
        if (target != 0) {
            Ptr32<char> sub = base + 4;
            ((S20HandlerK)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
        }
        block = ((Ptr32<Ptr32<S20Block16> (Ptr32<char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)base)[16])(base);
        *(Ptr32<S20Block16>)(item + 20) = *block;
        if (*(Ptr32<unsigned int>)(base + 88) & 2)
            *(Ptr32<int>)(item + 40) = 0;
    }
    return 0;
}

int w3d_s20_refresh_item_block_801a58d0(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    if (*(Ptr32<int>)(item + 40) == 0) {
        ((Ptr32<void (Ptr32<char>, Ptr32<char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)base)[17])(base, item + 20);
        return 0;
    }
    {
        Ptr32<char> target = *(Ptr32<Ptr32<char>>)(item + 48);
        Ptr32<char> sub;
        Ptr32<S20Block16> block;
        if (target == 0)
            return fn_801a572c(self, item);
        sub = base + 4;
        *(Ptr32<Ptr32<char>>)(sub + 20) = item;
        ((S20HandlerK)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
        block = ((Ptr32<Ptr32<S20Block16> (Ptr32<char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)base)[16])(base);
        *(Ptr32<S20Block16>)(item + 20) = *block;
        if (*(Ptr32<unsigned int>)(base + 88) & 8)
            *(Ptr32<int>)(item + 40) = 0;
    }
    return 0;
}

}
