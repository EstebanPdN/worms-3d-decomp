#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_adjust_t.c"
/* Render-state method on the secondary base subobject (this - 4, null-checked). */
typedef Ptr32<int (Ptr32<char>, Ptr32<char>)> S20HandlerT;
extern int fn_801a2bf4(Ptr32<void>, Ptr32<char>, int);
extern void fn_8030af88(int, int);
extern void fn_8016c014(Ptr32<char>, int);
extern void fn_8016c130(Ptr32<char>, int, int, float, float, float);
extern void fn_803080a4(int);
extern void fn_8030b648(int);
extern void fn_8030b4ac(int, int, int, int);
extern void fn_8016c1f4(Ptr32<char>);
extern float lbl_803a5568[];

int w3d_s20_apply_two_ranges_8016ab0c(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    Ptr32<char> record = *(Ptr32<Ptr32<char>>)(item + 48);
    Ptr32<char> first = *(Ptr32<Ptr32<char>>)(item + 52);
    Ptr32<char> second = *(Ptr32<Ptr32<char>>)(item + 56);
    fn_801a2bf4(w3d::G(*(Ptr32<int>)(base + 116)), record + 32, *(Ptr32<int>)(record + 24));
    *(Ptr32<int>)(base + 216) = 0;
    if (first != 0) {
        Ptr32<char> sub = base + 4;
        ((S20HandlerT)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(first + 6)])(sub, first);
        ((S20HandlerT)(*(Ptr32<Ptr32<Ptr32<void>>>)(sub + 24))[*(Ptr32<unsigned short>)(second + 6)])(sub, second);
        fn_8030af88(1, 0);
        fn_8016c014(base, 0);
        fn_8016c130(base, 0, 4, lbl_803a5568[0], *(Ptr32<float>)(item + 44), *(Ptr32<float>)(item + 40));
        fn_8016c130(base, 1, 4, *(Ptr32<float>)(item + 28), *(Ptr32<float>)(item + 36), *(Ptr32<float>)(item + 32));
        fn_803080a4(*(Ptr32<unsigned char>)(base + 216));
        fn_8030b648(*(Ptr32<unsigned char>)(base + 216));
        fn_8030b4ac(1, 1, 0, 255);
    } else {
        fn_8016c1f4(base);
    }
    return 0;
}

}
