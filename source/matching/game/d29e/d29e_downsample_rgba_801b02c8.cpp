// (Worms 3D GameCube PAL, 0x801b02c8).
//
// Halves a four-component image by averaging 2x2 blocks when the destination
// is exactly half the source; otherwise fills two pixel descriptors and
// calls the generic filter at 0x801d7750 once per component with mode 4.
// Names are inferred.

struct PixelDesc { int width, height; unsigned char *data; int pitch; int comps; };
extern "C" void sol11b_filter_select_801d7750(PixelDesc *, PixelDesc *, int);
extern "C" void w3d_d29e_downsample_rgba_801b02c8(unsigned char *src, int pitch, int w, int h, unsigned char *dst, int dpitch, int dw, int dh) {
  if (h == dh + dh && w == dw + dw) {
    if (dh != 0) {
      int row = w * 4;
      int skip = dw * 4 - dpitch;
      do {
        unsigned char *end = src + row;
        int next = dh - 1;
        while (src != end) {
          dst[0] = (src[0] + src[4] + src[pitch + 0] + src[pitch + 4]) / 4;
          dst[1] = (src[1] + src[5] + src[pitch + 1] + src[pitch + 5]) / 4;
          dst[2] = (src[2] + src[6] + src[pitch + 2] + src[pitch + 6]) / 4;
          dst[3] = (src[3] + src[7] + src[pitch + 3] + src[pitch + 7]) / 4;
          src += 8;
          dst += 4;
        }
        src += w * 4;
        dst += skip;
        dh = next;
      } while (dh != 0);
    }
  } else {
    PixelDesc s, d;
    s.width = w; s.height = h; s.pitch = pitch;
    d.width = dw; d.height = dh; d.pitch = dpitch;
    s.comps = 4; d.comps = 4;
    for (unsigned k = 0; k < 4; k++) {
      d.data = dst + k;
      s.data = src + k;
      sol11b_filter_select_801d7750(&d, &s, 4);
    }
  }
}
