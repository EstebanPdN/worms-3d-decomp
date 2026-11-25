#include "w3d_ptr.h"
#line 1 "f2c_tag_init_801de524.cpp"
// Partial layout and structural names inferred from original instructions.
extern unsigned char lbl_80416a90[],lbl_80416a38[];
extern const float lbl_803b02fc[];
struct Tag {unsigned short a,b;union {unsigned value;w3d::be_array<volatile unsigned char, 4> byte;} u;};
struct Thing {Ptr32<Ptr32<void>> vtable;unsigned pad[9];Tag tag;};
extern "C" Ptr32<Thing> f2c_tag_init_801de524(Ptr32<Thing> self){float v=lbl_803b02fc[0];Ptr32<Tag> tag=&self->tag; self->vtable=(Ptr32<Ptr32<void>>)lbl_80416a90;tag->u.byte[3]=2;tag->u.value=tag->u.byte[3];self->vtable=(Ptr32<Ptr32<void>>)lbl_80416a38;*(Ptr32<float>)((Ptr32<char>)self+24)=v;
*(Ptr32<unsigned int>)((Ptr32<char>)self+32)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+28)=0;
*(Ptr32<unsigned int>)((Ptr32<char>)self+36)=0;return self;}


