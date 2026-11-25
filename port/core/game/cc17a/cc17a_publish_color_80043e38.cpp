#include "w3d_ptr.h"
#line 1 "cc17a_publish_color_80043e38.cpp"
// Observed color floats at +32 and timing words at +64/+88/+92.
// Quantized byte conversion requires the original -mfast-cast option.
extern const float scale_80374e28[];
struct Cc17aColor{unsigned char r,g,b,a;template <class W3dU> Cc17aColor(Ptr32<W3dU> w3d_p) : Cc17aColor((const float *)w3d_p.get()) {}
 Cc17aColor(const float*p){r=(unsigned char)(p[0]*scale_80374e28[0]);g=(unsigned char)(p[1]*scale_80374e28[0]);b=(unsigned char)(p[2]*scale_80374e28[0]);a=(unsigned char)(p[3]*scale_80374e28[0]);}};
struct Cc17aOwner{char pad[32];float rgba[4];char pad30[16];unsigned state;Ptr32<void> handle;char pad48[16];unsigned start,duration;};
extern const float scale_80374e28[];extern unsigned text_804af3b4;
extern "C" Ptr32<void> lookup_80164fc8(Ptr32<void>);extern "C" void apply_8011adf8(Ptr32<void>,Ptr32<const Cc17aColor>,Ptr32<const void>);
extern "C" void w3d_cc17a_publish_color_80043e38(Ptr32<Cc17aOwner> self,unsigned tick){if(tick>self->start+self->duration){self->start=tick;self->state=3;}Ptr32<void> target=lookup_80164fc8(self->handle);Cc17aColor c(self->rgba);apply_8011adf8(target,&c,&text_804af3b4);}


