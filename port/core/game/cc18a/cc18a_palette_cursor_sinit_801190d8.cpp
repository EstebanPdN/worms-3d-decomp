#include "w3d_ptr.h"
#line 1 "cc18a_palette_cursor_sinit_801190d8.cpp"
// Four-byte colors are built through the observed byte-wise constructor.
struct Cc18aColor { unsigned char r,g,b,a;
 Cc18aColor(int red,int green,int blue,int alpha) {r=red;g=green;b=blue;a=alpha;}
};
extern "C" Cc18aColor lbl_8044d254[];
extern "C" void w3d_cc18a_palette_cursor_sinit_801190d8(int init,int priority) {
 if(priority==0xffff && init) {
  Ptr32<Cc18aColor> p=lbl_8044d254;
  *p=Cc18aColor(255,78,60,255);
  *++p=Cc18aColor(108,127,255,255);
  *++p=Cc18aColor(59,244,123,255);
  p[1]=Cc18aColor(255,218,77,255);
 }
}


