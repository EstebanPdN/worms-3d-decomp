#include "w3d_ptr.h"
#line 1 "f2c_tag_init_801dec90.cpp"
// Partial layout and structural names inferred from original instructions.
extern unsigned char lbl_80416bf8[],lbl_80416bb0[];
extern const char lbl_803b0364[];
extern const float lbl_803b036c[],lbl_803b0370[],lbl_803b0374[];
extern "C" Ptr32<void> fn_803426b8(Ptr32<void>);
extern "C" void fn_8020bd38(Ptr32<void>,Ptr32<const char>);
struct Pair { unsigned first,second; inline void init(){second=0;} };
struct Tag {unsigned short a,b;union {unsigned value;w3d::be_array<volatile unsigned char, 4> byte;} u;};
struct Thing {Ptr32<Ptr32<void>> vtable;Tag tag;Pair pair;unsigned tail[17];};
extern "C" Ptr32<Thing> f2c_tag_init_801dec90(Ptr32<Thing> self){Ptr32<Tag> tag=&self->tag;
self->vtable=(Ptr32<Ptr32<void>>)lbl_80416bf8;
tag->u.byte[3]=2;
tag->u.value=tag->u.byte[3];
self->pair.first=0;
self->pair.init();
tag->a=0;
tag->b=0;
self->vtable=(Ptr32<Ptr32<void>>)lbl_80416bb0;
fn_803426b8((Ptr32<char>)self+24);
*(Ptr32<unsigned int>)((Ptr32<char>)self+28)=0;
fn_803426b8((Ptr32<char>)self+80);
*(Ptr32<unsigned int>)((Ptr32<char>)self+64)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+20)=20;
fn_8020bd38((Ptr32<char>)self+24,lbl_803b0364);float a=lbl_803b036c[0],b=lbl_803b0370[0],c=lbl_803b0374[0];*(Ptr32<unsigned char>)((Ptr32<char>)self+68)=1;
*(Ptr32<unsigned char>)((Ptr32<char>)self+69)=2;
*(Ptr32<float>)((Ptr32<char>)self+60)=a;
*(Ptr32<float>)((Ptr32<char>)self+56)=b;
*(Ptr32<float>)((Ptr32<char>)self+48)=b;
*(Ptr32<unsigned int>)((Ptr32<char>)self+44)=0;
*(Ptr32<float>)((Ptr32<char>)self+72)=c;
*(Ptr32<float>)((Ptr32<char>)self+76)=c;
*(Ptr32<float>)((Ptr32<char>)self+52)=c;
Ptr32<void> held=*(Ptr32<Ptr32<void>>)((Ptr32<char>)self+28);if(held)(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)held)[4](held);
*(Ptr32<unsigned int>)((Ptr32<char>)self+28)=0;*(Ptr32<unsigned int>)((Ptr32<char>)self+32)=0;*(Ptr32<unsigned int>)((Ptr32<char>)self+84)=0;return self;}


