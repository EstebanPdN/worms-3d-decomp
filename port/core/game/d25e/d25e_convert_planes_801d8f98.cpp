#include "w3d_ptr.h"
#line 1 "d25e_convert_planes_801d8f98.cpp"
// (Worms 3D GameCube PAL, 0x801d8f98).
//
// Allocates a scratch word buffer of max(8192, width*height) entries in the
// global 0x804b0554 (freeing any old one), runs the two plane conversions
// 0x801d8e20 (full size) and 0x801d8cd4 (half size) with the row count
// rounded up to 64 and shifted by 6, frees and clears the scratch, returns
// 0.

extern "C" Ptr32<void> fn_801fe220(unsigned);
extern "C" void fn_801fe240(Ptr32<void>);
extern "C" void fn_801d8e20(int, int, int, int, int, int, Ptr32<void>);
extern "C" void fn_801d8cd4(int, int, int, int, int, int, Ptr32<void>);
struct Scratch {
    Ptr32<unsigned int> data; unsigned size;
    void Free() { if (data) fn_801fe240(data); }
    void Alloc(unsigned n) { Free(); size = n; data = (Ptr32<unsigned int>)fn_801fe220(n << 2); }
    void Clear() { Free(); data = 0; size = 0; }
};
extern Scratch lbl_804b0554;
extern "C" int w3d_d25e_convert_planes_801d8f98(Ptr32<void> dst, int u1, int u2, int w, unsigned h, Ptr32<void> dst2) {
    unsigned t = w * h;
    unsigned n = 8192;
    if (t > n) n = t;
    lbl_804b0554.Alloc(n);
    fn_801d8e20(0, (w + 63) >> 6, 0, 0, w, h, dst);
    unsigned w2 = (unsigned)w >> 1;
    fn_801d8cd4(0, (int)(w2 + 63) >> 6, 0, 0, w2, h >> 1, dst2);
    lbl_804b0554.Clear();
    return 0;
}


