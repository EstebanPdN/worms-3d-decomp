#include "w3d_ptr.h"
#line 1 "f2c_tag_init_801a25c8.cpp"
// Partial layout, structural names and access qualifiers inferred from original instructions.
extern unsigned char lbl_80411ac0[],lbl_80413a00[];
struct Pair { unsigned first,second; inline void init(){second=0;} };
struct Tag {unsigned short a,b;union {unsigned value;w3d::be_array<volatile unsigned char, 4> byte;} u;};
struct Thing {Ptr32<Ptr32<void>> vtable;Tag tag;Pair pair;unsigned tail[16];};
extern Ptr32<Thing> lbl_804ab750;
struct Triple {unsigned first,second,third;inline void init(){third=0;second=0;first=0;}};
extern "C" Ptr32<Thing> f2c_tag_init_801a25c8(Ptr32<Thing> self){Ptr32<Tag> tag=&self->tag;
self->vtable=(Ptr32<Ptr32<void>>)lbl_80411ac0;
tag->u.byte[3]=2;
tag->u.value=tag->u.byte[3];
self->pair.first=0;
self->pair.init();
tag->a=0;
tag->b=0;
self->vtable=(Ptr32<Ptr32<void>>)lbl_80413a00;
((Ptr32<Triple>)((Ptr32<char>)self+36))->init();
((Ptr32<Triple>)((Ptr32<char>)self+48))->init();
((Ptr32<Triple>)((Ptr32<char>)self+60))->init();
Ptr32<Thing> previous=lbl_804ab750;
((Ptr32<Triple>)((Ptr32<char>)self+72))->init();
*(Ptr32<unsigned int>)((Ptr32<char>)self+20)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+28)=0;
*(Ptr32<Ptr32<Thing>>)((Ptr32<char>)self+32)=previous;
lbl_804ab750=self;return self;}


