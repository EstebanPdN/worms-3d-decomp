#include "w3d_ptr.h"
#line 1 "f2c_tag_init_801e34b0.cpp"
// Partial layout and structural names inferred from original instructions.
extern unsigned char lbl_80416a90[],lbl_80416ee0[];
extern const float lbl_803b0658[],lbl_803b065c[];
struct Pair { unsigned first,second; inline void init(){second=0;} };
struct Tag {unsigned short a,b;union {unsigned value;w3d::be_array<volatile unsigned char, 4> byte;} u;};
struct Thing {Ptr32<Ptr32<void>> vtable;unsigned pad[9];Tag tag;Pair pair;unsigned tail[3];};
extern "C" Ptr32<Thing> f2c_tag_init_801e34b0(Ptr32<Thing> self){
float a=lbl_803b0658[0];float b=lbl_803b065c[0];
Ptr32<Tag> tag=&self->tag;
self->vtable=(Ptr32<Ptr32<void>>)lbl_80416a90;
tag->u.byte[3]=2;
tag->u.value=tag->u.byte[3];
self->pair.first=0;
self->pair.init();
tag->a=0;
tag->b=0;
self->vtable=(Ptr32<Ptr32<void>>)lbl_80416ee0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+64)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+36)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+56)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+60)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+32)=0;
*(Ptr32<float>)((Ptr32<char>)self+8)=a;
*(Ptr32<float>)((Ptr32<char>)self+24)=b;
return self;}



