#include "w3d_ptr.h"
#line 1 "d29e_downsample_rgb_801b0448.cpp"
// (Worms 3D GameCube PAL, 0x801b0448).
//
// Halves a three-component image by averaging 2x2 blocks when the source
// height and pitch are twice the destination's (the original compares the
// pitch arguments here, not the widths); otherwise fills two pixel
// descriptors and calls the generic filter at 0x801d7750 once per component
// with mode 4. Names are inferred.

struct PixelDesc { int width, height; Ptr32<unsigned char> data; int pitch; int comps; };
extern "C" void sol11b_filter_select_801d7750(Ptr32<PixelDesc>, Ptr32<PixelDesc>, int);
extern "C" void w3d_d29e_downsample_rgb_801b0448(Ptr32<unsigned char> src, int pitch, int w, int h, Ptr32<unsigned char> dst, int dpitch, int dw, int dh) {
  if (h == dh + dh && pitch == dpitch + dpitch) {
    if (dh != 0) {
      int row = w * 3;
      int skip = dw * 3 - dpitch;
      do {
        Ptr32<unsigned char> end = src + row;
        int next = dh - 1;
        while (src != end) {
          dst[0] = (src[0] + src[3] + src[pitch + 0] + src[pitch + 3]) / 4;
          dst[1] = (src[1] + src[4] + src[pitch + 1] + src[pitch + 4]) / 4;
          dst[2] = (src[2] + src[5] + src[pitch + 2] + src[pitch + 5]) / 4;
          src += 6;
          dst += 3;
        }
        src += w * 3;
        dst += skip;
        dh = next;
      } while (dh != 0);
    }
  } else {
    PixelDesc s, d;
    s.width = w; s.height = h; s.pitch = pitch;
    d.width = dw; d.height = dh; d.pitch = dpitch;
    s.comps = 3; d.comps = 3;
    for (unsigned k = 0; k < 3; k++) {
      d.data = dst + k;
      s.data = src + k;
      sol11b_filter_select_801d7750(&d, &s, 4);
    }
  }
}


