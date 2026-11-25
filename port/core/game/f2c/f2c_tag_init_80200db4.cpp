#include "w3d_ptr.h"
#line 1 "f2c_tag_init_80200db4.cpp"
// Partial layout and structural names inferred from original instructions.
// The original frame reserves 24 additional bytes; their purpose is unknown.
extern unsigned char lbl_80418eb8[],lbl_80418df0[];
struct Pair { unsigned first,second; inline void init(){second=0;} };
struct Tag {unsigned short a,b;union {unsigned value;w3d::be_array<volatile unsigned char, 4> byte;} u;};
struct Thing {Ptr32<Ptr32<void>> vtable;Tag tag;Pair pair;unsigned tail[34];};
extern "C" Ptr32<Thing> f2c_tag_init_80200db4(Ptr32<Thing> self){volatile unsigned char reserved_frame[24];Ptr32<Tag> tag=&self->tag;
self->vtable=(Ptr32<Ptr32<void>>)lbl_80418eb8;
tag->u.byte[3]=2;
tag->u.value=tag->u.byte[3];
self->pair.first=0;
self->pair.init();
tag->a=0;
tag->b=0;
self->vtable=(Ptr32<Ptr32<void>>)lbl_80418df0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+20)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+24)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+36)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+40)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+44)=0;
((Ptr32<Pair>)((Ptr32<char>)self+44))->init();
((Ptr32<Pair>)((Ptr32<char>)self+52))->init();
*(Ptr32<unsigned int>)((Ptr32<char>)self+124)=0;
((Ptr32<Pair>)((Ptr32<char>)self+124))->init();
((Ptr32<Pair>)((Ptr32<char>)self+132))->init();
*(Ptr32<unsigned int>)((Ptr32<char>)self+140)=0;
((Ptr32<Pair>)((Ptr32<char>)self+140))->init();
((Ptr32<Pair>)((Ptr32<char>)self+148))->init();return self;}


