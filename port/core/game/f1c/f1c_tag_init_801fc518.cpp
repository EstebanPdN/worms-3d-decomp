#include "w3d_ptr.h"
#line 1 "f1c_tag_init_801fc518.cpp"
// Partial views inferred from observed offsets. Type names and qualifiers are recovery hypotheses.
extern unsigned char lbl_804182d0[],lbl_804183b0[];
struct Tag {
 unsigned short a,b;
 union {unsigned value; struct { volatile unsigned char type; unsigned char unused[3]; } bytes; };
 unsigned x,y;
 inline void initialize(unsigned char type) {
  bytes.type=type;
  x=0;
  value=bytes.type;
  Ptr32<unsigned int> p=&x;
  p[1]=0;
a=0;
b=0;
 }
};
struct Thing { Ptr32<void> volatile vtable;unsigned unused;Tag tag;};
extern "C" Ptr32<Thing> f1c_tag_init_801fc518(Ptr32<Thing> self) {
 self->vtable=lbl_804182d0;
 self->tag.initialize(2);

 self->vtable=lbl_804183b0;
 return self;
}


