#include "w3d_ptr.h"
#line 1 "f2c_tag_init_801e099c.cpp"
// Partial layout and structural names inferred from original instructions.
extern unsigned char lbl_80416a90[],lbl_80416d20[];
extern const float lbl_803b048c[],lbl_803b0490[],lbl_803b0494[];
struct Pair { unsigned first,second; inline void init(){second=0;} };
struct Tag {unsigned short a,b;union {unsigned value;w3d::be_array<volatile unsigned char, 4> byte;} u;};
struct Thing {Ptr32<Ptr32<void>> vtable;unsigned pad[9];Tag tag;Pair pair;unsigned tail[9];};
struct Vector {float x,y,z;inline void init(float v) {x=v;y=v;z=v;} };
extern "C" Ptr32<Thing> f2c_tag_init_801e099c(Ptr32<Thing> self){
float a=lbl_803b048c[0],b=lbl_803b0490[0],c=lbl_803b0494[0];Ptr32<Tag> tag=&self->tag;
self->vtable=(Ptr32<Ptr32<void>>)lbl_80416a90;
tag->u.byte[3]=2;
tag->u.value=tag->u.byte[3];
self->pair.first=0;
self->pair.init();
tag->a=0;
tag->b=0;
self->vtable=(Ptr32<Ptr32<void>>)lbl_80416d20;
*(Ptr32<unsigned int>)((Ptr32<char>)self+88)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+4)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+32)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+36)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+84)=0;
*(Ptr32<float>)((Ptr32<char>)self+8)=a;
*(Ptr32<float>)((Ptr32<char>)self+24)=b;
*(Ptr32<unsigned int>)((Ptr32<char>)self+28)=10101;
((Ptr32<Vector>)((Ptr32<char>)self+12))->init(c);
((Ptr32<Vector>)((Ptr32<char>)self+60))->init(c);
((Ptr32<Vector>)((Ptr32<char>)self+72))->init(c);
*(Ptr32<int>)((Ptr32<char>)self+56)=-1;
return self;}



