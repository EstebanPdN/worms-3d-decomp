#include "w3d_ptr.h"
#line 1 "f3c_tag_init_801db144.cpp"
// Structural names, partial layout, and floating temporary type inferred.
// Original frame reserves an additional 16 bytes; their purpose is unknown.
extern unsigned char lbl_80416970[],lbl_804168c0[],lbl_80416ae8[];
extern Ptr32<void> lbl_804ab80c;
extern const float lbl_803afe38[];
extern "C" void fn_802109dc(Ptr32<void>);
extern "C" void fn_801de524(Ptr32<void>);
extern "C" Ptr32<void> fn_8020b680(Ptr32<void>);
extern "C" void fn_802ee7d0(unsigned);
struct Pair {unsigned first,second;inline void init(){second=0;}};
struct Tag {unsigned short a,b;union{unsigned value;w3d::be_array<volatile unsigned char, 4> byte;}u;};
struct Thing{Ptr32<Ptr32<void>> vtable;Tag tag;Pair pair;unsigned tail[45];};
extern "C" Ptr32<Thing> f3c_tag_init_801db144(Ptr32<Thing> self){volatile unsigned char reserved_frame[16];Ptr32<Tag> tag=&self->tag;self->vtable=(Ptr32<Ptr32<void>>)lbl_80416970;tag->u.byte[3]=2;tag->u.value=tag->u.byte[3];self->pair.first=0;self->pair.init();tag->a=0;tag->b=0;self->vtable=(Ptr32<Ptr32<void>>)lbl_804168c0;
fn_802109dc((Ptr32<char>)self+36);fn_802109dc((Ptr32<char>)self+48);*(Ptr32<unsigned int>)((Ptr32<char>)self+60)=0;((Ptr32<Pair>)((Ptr32<char>)self+60))->init();((Ptr32<Pair>)((Ptr32<char>)self+68))->init();fn_802109dc((Ptr32<char>)self+76);*(Ptr32<unsigned int>)((Ptr32<char>)self+104)=1;fn_801de524((Ptr32<char>)self+124);*(Ptr32<Ptr32<void>>)((Ptr32<char>)self+172)=0;lbl_804ab80c=self;
Ptr32<void> got=fn_8020b680(lbl_80416ae8);if(got)(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)got)[3](got);Ptr32<void> old=*(Ptr32<Ptr32<void>>)((Ptr32<char>)self+172);if(old)(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)old)[4](old);*(Ptr32<Ptr32<void>>)((Ptr32<char>)self+172)=got;
double f=lbl_803afe38[0];
*(Ptr32<float>)((Ptr32<char>)self+92)=f;*(Ptr32<unsigned int>)((Ptr32<char>)self+96)=0;*(Ptr32<unsigned int>)((Ptr32<char>)self+104)=1;*(Ptr32<unsigned int>)((Ptr32<char>)self+108)=1;*(Ptr32<unsigned int>)((Ptr32<char>)self+112)=1;*(Ptr32<unsigned int>)((Ptr32<char>)self+116)=0;fn_802ee7d0(203);*(Ptr32<unsigned int>)((Ptr32<char>)self+184)=0;*(Ptr32<unsigned int>)((Ptr32<char>)self+188)=0;*(Ptr32<unsigned int>)((Ptr32<char>)self+192)=0;*(Ptr32<unsigned int>)((Ptr32<char>)self+196)=0;*(Ptr32<unsigned int>)((Ptr32<char>)self+180)=0;for(int i=3;i>=0;--i)((Ptr32<float>)((Ptr32<char>)self+20))[i]=f;*(Ptr32<unsigned int>)((Ptr32<char>)self+176)=0;return self;}

