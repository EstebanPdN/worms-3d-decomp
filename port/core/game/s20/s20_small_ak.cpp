#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_ak.c"
/* Sound playback helpers that bind two named resources then start a sound. */
extern int fn_800fc43c(Ptr32<Ptr32<char>>, int);
extern int fn_800fc550(Ptr32<Ptr32<char>>, int);
extern void fn_800356e0(Ptr32<void>, Ptr32<char>, float, float);
extern int fn_80035714(Ptr32<void>, Ptr32<char>, float);
extern char lbl_8038b634[];
extern char lbl_8038b640[];
extern char lbl_8038b658[];
extern char lbl_8038b664[];
extern char lbl_8038b674[];
extern float lbl_8038b660[];
extern float lbl_8038b66c[];
extern float lbl_8038b670[];
extern float lbl_8038b67c[];
extern int lbl_804aa8c8;

void w3d_s20_play_sound_pair_800edc28(Ptr32<char> self) {
    Ptr32<char> first;
    Ptr32<char> second;
    int handle;
    first = lbl_8038b634;
    handle = *(Ptr32<int>)(self + 20);
    fn_800fc550(&first, *(Ptr32<int>)(self + 304));
    second = lbl_8038b640;
    fn_800fc43c(&second, handle);
    fn_800356e0(w3d::G(lbl_804aa8c8), lbl_8038b658, lbl_8038b660[0], lbl_8038b660[0]);
}

void w3d_s20_play_sound_pair_800edca0(Ptr32<char> self) {
    Ptr32<char> first;
    Ptr32<char> second;
    int handle;
    first = lbl_8038b634;
    handle = *(Ptr32<int>)(self + 20);
    fn_800fc550(&first, *(Ptr32<int>)(self + 304));
    second = lbl_8038b640;
    fn_800fc43c(&second, handle);
    fn_800356e0(w3d::G(lbl_804aa8c8), lbl_8038b664, lbl_8038b66c[0], lbl_8038b670[0]);
}

void w3d_s20_play_sound_single_800edd1c(Ptr32<char> self) {
    Ptr32<char> first;
    Ptr32<char> second;
    int handle;
    first = lbl_8038b634;
    handle = *(Ptr32<int>)(self + 20);
    fn_800fc550(&first, *(Ptr32<int>)(self + 304));
    second = lbl_8038b640;
    fn_800fc43c(&second, handle);
    fn_80035714(w3d::G(lbl_804aa8c8), lbl_8038b674, lbl_8038b67c[0]);
}

}
