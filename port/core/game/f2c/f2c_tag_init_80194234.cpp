#include "w3d_ptr.h"
#line 1 "f2c_tag_init_80194234.cpp"
// Partial layout and structural names inferred from original instructions.
// The original frame reserves 48 additional bytes; their purpose is unknown.
extern unsigned char lbl_804133c8[],lbl_80413378[];
extern const float lbl_803a82b4[];
struct Pair { unsigned first,second; inline void init(){second=0;} };
struct Tag {unsigned short a,b;union {unsigned value;w3d::be_array<volatile unsigned char, 4> byte;} u;};
struct Thing {Ptr32<Ptr32<void>> vtable;Tag tag;Pair pair;unsigned tail[27];};
extern "C" Ptr32<Thing> f2c_tag_init_80194234(Ptr32<Thing> self){volatile unsigned char reserved_frame[48];Ptr32<Tag> tag=&self->tag;
self->vtable=(Ptr32<Ptr32<void>>)lbl_804133c8;
tag->u.byte[3]=2;
tag->u.value=tag->u.byte[3];
self->pair.first=0;
self->pair.init();
tag->a=0;
tag->b=0;
self->vtable=(Ptr32<Ptr32<void>>)lbl_80413378;
*(Ptr32<unsigned int>)((Ptr32<char>)self+24)=0;
((Ptr32<Pair>)((Ptr32<char>)self+24))->init();
((Ptr32<Pair>)((Ptr32<char>)self+32))->init();
*(Ptr32<unsigned int>)((Ptr32<char>)self+40)=0;
((Ptr32<Pair>)((Ptr32<char>)self+40))->init();
((Ptr32<Pair>)((Ptr32<char>)self+48))->init();
*(Ptr32<unsigned int>)((Ptr32<char>)self+56)=0;
((Ptr32<Pair>)((Ptr32<char>)self+56))->init();
((Ptr32<Pair>)((Ptr32<char>)self+64))->init();
*(Ptr32<unsigned int>)((Ptr32<char>)self+72)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+76)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+80)=0;
((Ptr32<Pair>)((Ptr32<char>)self+80))->init();
((Ptr32<Pair>)((Ptr32<char>)self+88))->init();
*(Ptr32<unsigned int>)((Ptr32<char>)self+96)=0;
((Ptr32<Pair>)((Ptr32<char>)self+96))->init();
*(Ptr32<unsigned int>)((Ptr32<char>)self+104)=0;
((Ptr32<Pair>)((Ptr32<char>)self+104))->init();
float f=lbl_803a82b4[0];((Ptr32<Pair>)((Ptr32<char>)self+112))->init();
*(Ptr32<unsigned int>)((Ptr32<char>)self+124)=0;
*(Ptr32<float>)((Ptr32<char>)self+20)=f;return self;}


