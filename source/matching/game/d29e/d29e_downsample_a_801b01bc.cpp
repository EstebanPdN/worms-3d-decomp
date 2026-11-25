// (Worms 3D GameCube PAL, 0x801b01bc).
//
// Halves a one-component image by averaging 2x2 blocks when the destination
// is exactly half the source; otherwise fills two pixel descriptors and
// calls the generic filter at 0x801d7750 with mode 4. The row step
// arithmetic is reproduced from the original. Names are inferred.

struct PixelDesc { int width, height; unsigned char *data; int pitch; int comps; };
extern "C" void sol11b_filter_select_801d7750(PixelDesc *, PixelDesc *, int);
extern "C" void w3d_d29e_downsample_a_801b01bc(unsigned char *src, int pitch, int w, int h, unsigned char *dst, int dpitch, int dw, int dh) {
  if (h == dh + dh && w == dw + dw) {
    if (dh != 0) {
      int row = w;
      int skip = dw - dpitch;
      w <<= 2;
      do {
        unsigned char *end = src + w;
        int next = dh - 1;
        while (src != end) {
          *dst = (src[0] + src[1] + src[pitch] + src[pitch + 1]) / 4;
          src += 2;
          dst++;
        }
        src += row;
        dst += skip;
        dh = next;
      } while (dh != 0);
    }
  } else {
    PixelDesc s, d;
    s.width = w; s.height = h; s.pitch = pitch;
    d.width = dw; d.height = dh; d.pitch = dpitch;
    s.comps = 1; d.comps = 1;
    for (unsigned k = 0; k < 1; k++) {
      d.data = dst + k;
      s.data = src + k;
      sol11b_filter_select_801d7750(&d, &s, 4);
    }
  }
}
