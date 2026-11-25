#include "w3d_ptr.h"
#line 1 "f2c_tag_init_801fa01c.cpp"
// Partial layout and structural names inferred from original instructions.
// The original frame reserves 40 additional bytes; their purpose is unknown.
extern unsigned char lbl_80418328[],lbl_80418470[],lbl_80418268[];
extern "C" void fn_8035a2c0(Ptr32<void>);
struct Pair { unsigned first,second; inline void init(){second=0;} };
struct Tag {unsigned short a,b;union {unsigned value;w3d::be_array<volatile unsigned char, 4> byte;} u;};
struct Thing {Ptr32<Ptr32<void>> vtable;unsigned pad[2];Tag tag;Pair pair;unsigned tail[60];};
extern "C" Ptr32<Thing> f2c_tag_init_801fa01c(Ptr32<Thing> self){volatile unsigned char reserved_frame[40];Ptr32<Tag> tag=&self->tag;
self->vtable=(Ptr32<Ptr32<void>>)lbl_80418328;
tag->u.byte[3]=2;
tag->u.value=tag->u.byte[3];
self->pair.first=0;
self->pair.init();
tag->a=0;
tag->b=0;
self->vtable=(Ptr32<Ptr32<void>>)lbl_80418328;

fn_8035a2c0((Ptr32<char>)self+28);
*(Ptr32<Ptr32<void>>)((Ptr32<char>)self+28)=lbl_80418470;
self->vtable=(Ptr32<Ptr32<void>>)lbl_80418268;
*(Ptr32<unsigned int>)((Ptr32<char>)self+96)=0;
((Ptr32<Pair>)((Ptr32<char>)self+96))->init();
((Ptr32<Pair>)((Ptr32<char>)self+104))->init();
*(Ptr32<unsigned int>)((Ptr32<char>)self+112)=0;
((Ptr32<Pair>)((Ptr32<char>)self+112))->init();
((Ptr32<Pair>)((Ptr32<char>)self+120))->init();
*(Ptr32<unsigned int>)((Ptr32<char>)self+208)=0;
((Ptr32<Pair>)((Ptr32<char>)self+208))->init();
((Ptr32<Pair>)((Ptr32<char>)self+216))->init();
*(Ptr32<unsigned int>)((Ptr32<char>)self+224)=0;
((Ptr32<Pair>)((Ptr32<char>)self+224))->init();
((Ptr32<Pair>)((Ptr32<char>)self+232))->init();
*(Ptr32<unsigned int>)((Ptr32<char>)self+240)=0;
((Ptr32<Pair>)((Ptr32<char>)self+240))->init();
((Ptr32<Pair>)((Ptr32<char>)self+248))->init();
*(Ptr32<unsigned int>)((Ptr32<char>)self+256)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+260)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+264)&=0x3fffffff;return self;}


