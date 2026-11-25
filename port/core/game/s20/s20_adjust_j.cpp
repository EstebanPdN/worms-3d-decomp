#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_adjust_j.c"
/* Method on the secondary base subobject (this - 4, null-checked). */
typedef Ptr32<void (Ptr32<char>, Ptr32<char>)> S20HandlerJ;
extern Ptr32<int> fn_801d0858(Ptr32<char>, Ptr32<int>);
extern int fn_801a2bf4(Ptr32<void>, Ptr32<char>, int);
extern void fn_8030ae60(int);
extern void fn_8016c014(Ptr32<char>, int);
extern void fn_803080a4(int);
extern void fn_8016c1f4(Ptr32<char>);
extern void fn_8030ae84(int);
extern void fn_8030b648(int);

int w3d_s20_apply_record_8016c240(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    Ptr32<char> record = *(Ptr32<Ptr32<char>>)(item + 28);
    int count;
    Ptr32<char> range;
    Ptr32<char> target = 0;
    int found;
    Ptr32<int> result;
    count = *(Ptr32<int>)(record + 24);
    range = record + 32;
    result = fn_801d0858(item, &found);
    if (found != 0)
        target = *(Ptr32<Ptr32<char>>)result;
    fn_801a2bf4(w3d::G(*(Ptr32<int>)(base + 116)), range, count);
    {
        int zero = 0;
        *(Ptr32<int>)(base + 216) = zero;
        *(Ptr32<unsigned char>)(base + 220) = zero;
        fn_8030ae60(zero);
    }
    if (target != 0) {
        Ptr32<char> sub;
        fn_8016c014(base, 0);
        sub = base + 4;
        ((S20HandlerJ)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(target + 6)])(sub, target);
        fn_803080a4(*(Ptr32<unsigned char>)(base + 216));
    } else {
        fn_8016c1f4(base);
    }
    fn_8030ae84(0);
    fn_8030b648(1);
    return 0;
}

}
