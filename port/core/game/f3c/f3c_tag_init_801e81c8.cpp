#include "w3d_ptr.h"
#line 1 "f3c_tag_init_801e81c8.cpp"
// Structural names, qualifiers, and partial layout inferred from original instructions.
extern unsigned char lbl_803657d8[];
extern "C" Ptr32<void> fn_8020fcb4(Ptr32<void>);
struct Pair {unsigned first,second;inline void init(){second=0;}};
struct Tag {unsigned short a,b;union{unsigned value;w3d::be_array<volatile unsigned char, 4> byte;}u;};
struct Thing{Tag tag;Pair pair;unsigned a,b,c;Ptr32<void> held;unsigned flags;};
extern "C" Ptr32<Thing> f3c_tag_init_801e81c8(Ptr32<Thing> self){Ptr32<Tag> tag=&self->tag;tag->u.byte[3]=2;self->pair.first=0;tag->u.value=tag->u.byte[3];self->pair.init();tag->a=0;tag->b=0;self->held=0;self->a=0;self->b=0;self->c=0;self->flags=1;Ptr32<void> got=fn_8020fcb4(lbl_803657d8);if(got)(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)got)[3](got);Ptr32<void> old=self->held;if(old)(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)old)[4](old);self->held=got;*(Ptr32<Ptr32<Thing>>)((Ptr32<char>)got+64)=self;*(Ptr32<unsigned int>)((Ptr32<char>)got+32)&=0xbfffffff;return self;}

