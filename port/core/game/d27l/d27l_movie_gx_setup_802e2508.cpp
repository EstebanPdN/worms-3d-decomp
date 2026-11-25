#include "w3d_ptr.h"
#line 1 "d27l_movie_gx_setup_802e2508.cpp"
// GWMP8P rev0 0x802e2508. Movie player graphics setup: 2D projection and
// viewport for the given size, identity modelview, vertex and texture state,
// three TEV stages combining the Y, U and V planes, with the signed colour
// constant of the YUV conversion read from the original data at 0x803db3bc
// (-90, 0, -114, 135). Callee names are not recovered.
extern "C" void fn_8030c094(int);
extern "C" void fn_8030ba64(int, int, int);
extern "C" void fn_8030b9b8(int, int, int, int);
extern "C" void fn_8030ba0c(int);
extern "C" void fn_8030ba38(int);
extern "C" void fn_8030990c(int);
extern "C" void fn_803080a4(int);
extern "C" void fn_80307e24(int, int, int, int, int, int);
extern "C" void fn_8030a46c();
extern "C" void fn_80307558();
extern "C" void fn_80306cd0(int, int);
extern "C" void fn_80307590(int, int, int, int, int);
extern "C" void fn_8030b648(int);
extern "C" void fn_8030b4ac(int, int, int, int);
extern "C" void fn_8030b014(int, int, int, int, int);
extern "C" void fn_8030b09c(int, int, int, int, int, int);
extern "C" void fn_8030b058(int, int, int, int, int);
extern "C" void fn_8030b104(int, int, int, int, int, int);
extern "C" void fn_8030b25c(int, int);
extern "C" void fn_8030b2b8(int, int);
extern "C" void fn_8030b314(int, int, int);
extern "C" void fn_8030b3dc(int, int, int, int, int);
extern "C" void fn_8030ba98(int);
extern "C" void fn_8030bacc(int, int);
extern "C" void fn_80302ec4(Ptr32<float>, float, float, float, float, float, float);
extern "C" void fn_8030bec4(Ptr32<float>, int);
extern "C" void fn_8030c264(float, float, float, float, float, float);
extern "C" void fn_8030c2ac(int, int, int, int);
extern "C" void fn_80302b60(Ptr32<float>);
extern "C" void fn_8030bff4(Ptr32<float>, int);
extern "C" void fn_8030b16c(int, Ptr32<void>);
extern "C" void fn_8030b1e8(int, Ptr32<void>);
extern "C" void fn_8030b35c(int, int, int, int, int);
struct ColorS10 { short r, g, b, a; };
extern const ColorS10 colour_803db3bc[];
extern "C" void d27l_movie_gx_setup_802e2508(Ptr32<void> self, int w, int h) {
    float mo[16], mi[12];
    fn_8030b3dc(7, 0, 0, 7, 0);
    fn_8030ba98(1);
    fn_8030bacc(0, 0);
    float fh = h;
    float fw = w;
    fn_80302ec4(mo, 0.0f, fh, 0.0f, fw, 0.0f, -1.0f);
    fn_8030bec4(mo, 1);
    fn_8030c264(0.0f, 0.0f, fw, fh, 0.0f, 1.0f);
    fn_8030c2ac(0, 0, w, h);
    fn_80302b60(mi);
    fn_8030bff4(mi, 0);
    fn_8030c094(0);
    fn_8030ba64(1, 7, 0);
    fn_8030b9b8(0, 1, 0, 0);
    fn_8030ba0c(1);
    fn_8030ba38(0);
    fn_8030990c(0);
    fn_803080a4(2);
    fn_80307e24(0, 1, 4, 60, 0, 125);
    fn_80307e24(1, 1, 4, 60, 0, 125);
    fn_8030a46c();
    fn_80307558();
    fn_80306cd0(9, 1);
    fn_80306cd0(13, 1);
    fn_80307590(7, 9, 1, 3, 0);
    fn_80307590(7, 13, 1, 2, 0);
    fn_8030b648(4);
    fn_8030b4ac(0, 1, 1, 255);
    fn_8030b014(0, 15, 8, 14, 2);
    fn_8030b09c(0, 0, 0, 0, 0, 0);
    fn_8030b058(0, 7, 4, 6, 1);
    fn_8030b104(0, 1, 0, 0, 0, 0);
    fn_8030b25c(0, 12);
    fn_8030b2b8(0, 28);
    fn_8030b314(0, 0, 0);
    fn_8030b4ac(1, 1, 2, 255);
    fn_8030b014(1, 15, 8, 14, 0);
    fn_8030b09c(1, 0, 0, 1, 0, 0);
    fn_8030b058(1, 7, 4, 6, 0);
    fn_8030b104(1, 1, 0, 0, 0, 0);
    fn_8030b25c(1, 13);
    fn_8030b2b8(1, 29);
    fn_8030b314(1, 0, 0);
    fn_8030b4ac(2, 0, 0, 255);
    fn_8030b014(2, 15, 8, 12, 0);
    fn_8030b09c(2, 0, 0, 0, 1, 0);
    fn_8030b058(2, 4, 7, 7, 0);
    fn_8030b104(2, 0, 0, 0, 1, 0);
    fn_8030b314(2, 0, 0);
    fn_8030b4ac(3, 255, 255, 255);
    fn_8030b014(3, 1, 0, 14, 15);
    fn_8030b09c(3, 0, 0, 0, 1, 0);
    fn_8030b058(3, 7, 7, 7, 7);
    fn_8030b104(3, 0, 0, 0, 1, 0);
    fn_8030b314(3, 0, 0);
    fn_8030b25c(3, 14);
    ColorS10 t = colour_803db3bc[0];
    fn_8030b16c(1, &t);
    int c = 0xe258;
    fn_8030b1e8(0, &c);
    c = 0xb30000b6;
    fn_8030b1e8(1, &c);
    c = 0xff00ff80;
    fn_8030b1e8(2, &c);
    fn_8030b35c(0, 0, 1, 2, 3);
}


