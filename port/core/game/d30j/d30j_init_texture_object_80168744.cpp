#include "w3d_ptr.h"
#line 1 "d30j_init_texture_object_80168744.cpp"
// Create the GX texture object for an image: map its format to a GX format, or
// to a colour-indexed format, ignoring unsupported formats; drop wrap and
// mipmaps for non-power-of-two sizes; flush the texels; initialise the object.
// GWMP8P rev0 0x80168744.

struct Image { char p0[20]; Ptr32<void> palette; int format; char p1c[14]; unsigned short levels; unsigned short height; unsigned short width; struct Buf { char p[32]; char data[1]; }; Ptr32<struct Buf> buf; };
struct TexObj { char p0[32]; int mode; };
struct Slot { char p0[296]; int wrapS; int wrapT; char p130[8]; Ptr32<TexObj> obj; };
extern Ptr32<void> lbl_804b1884;
extern "C" {
Ptr32<TexObj> s9_forward_global_80166fd0(Ptr32<void>, int);
unsigned int fn_80309a64(unsigned short, unsigned short, int, int, int);
void fn_802fa988(Ptr32<void>, unsigned int);
void fn_80309ed4(Ptr32<TexObj>, Ptr32<void>, unsigned short, unsigned short, int, int, int, int, int);
void fn_80309c88(Ptr32<TexObj>, Ptr32<void>, unsigned short, unsigned short, int, int, int, int);
int fn_8016c4f4(Ptr32<void>, Ptr32<void>);
}
extern "C" void d30j_init_texture_object_80168744(Ptr32<Slot> self, Ptr32<Image> t) {
  bool ci = false;
  int fmt, cfmt;
  int w = t->width, h = t->height;
  switch (t->format) {
    case 11: fmt = 6; break;
    case 13: fmt = 4; break;
    case 12: fmt = 5; break;
    case 21: fmt = 14; break;
    case 19: ci = true; cfmt = 9; break;
    case 20: ci = true; cfmt = 8; break;
    case 14: case 22: fmt = 3; break;
    case 9: case 10: case 15: case 16: case 17: case 18: return;
    default: return;
  }
  Ptr32<void> data = t->buf->data;
  int mips = t->levels > 1;
  bool np = false;
  unsigned int p = 1024;
  {
    while ((unsigned int)w <= p) p >>= 1;
    if ((int)(p << 1) != w) np = true;
  }
  if (!np) {
    p = 1024;
    while ((unsigned int)h <= p) p >>= 1;
    if ((int)(p << 1) != h) np = true;
  }
  if (np) {
    self->wrapS = 0;
    self->wrapT = 0;
    if (mips) mips = 0;
  }
  self->obj = s9_forward_global_80166fd0(lbl_804b1884, 36);
  if (ci) {
    fn_802fa988(data, fn_80309a64(w, h, cfmt, mips, mips ? 100 : 0));
    Ptr32<void> pal = t->palette;
    fn_80309ed4(self->obj, data, w, h, cfmt, self->wrapS, self->wrapT, mips, 0);
    fn_8016c4f4((Ptr32<char>)self + 4, pal);
  } else {
    fn_802fa988(data, fn_80309a64(w, h, fmt, mips, mips ? 100 : 0));
    fn_80309c88(self->obj, data, w, h, fmt, self->wrapS, self->wrapT, mips);
  }
  self->obj->mode = 2;
}


