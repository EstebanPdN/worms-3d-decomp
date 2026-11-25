#include "w3d_ptr.h"
#line 1 "f2a_pack_palette_8007e998.cpp"
// Original entry 0x8007e998; palette and color-channel naming is inferred.
// Unused three-float object preserves observed frame reservation.
struct Header {unsigned unused;unsigned short kind;char p[18];unsigned count;unsigned short refs;char pad[2];unsigned char bytes[1];};
struct Array {Ptr32<Header> h;};struct Input{char p[48];Array a;};struct Output {char p[372];Ptr32<unsigned short> dest;};
extern "C" Ptr32<unsigned char> fn_801ef048(Ptr32<Array>,unsigned,int,int);
inline Ptr32<unsigned char> read(Ptr32<Array> a,unsigned count){Ptr32<Header> h=a->h;if(h->kind==1){++h->refs;return h->bytes;}return fn_801ef048(a,count,1,2);}
extern "C" {
int w3d_f2a_pack_palette_8007e998(Ptr32<Output> self,Ptr32<Input> in){struct Frame{float x,y,z;Frame(){}} reservation;Ptr32<unsigned char> src=read(&in->a,in->a.h->count);for(int i=0;i<256;++i){Ptr32<unsigned char> pixel=src+i;unsigned value=(pixel[2]&0xf0)|(((src[i]&0xf0)<<8)|((pixel[1]&0xf0)<<4));self->dest[i]=value;src+=2;}return 0;}}


