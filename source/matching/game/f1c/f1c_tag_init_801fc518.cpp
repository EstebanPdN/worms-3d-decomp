// Partial views inferred from observed offsets. Type names and qualifiers are recovery hypotheses.
extern unsigned char lbl_804182d0[],lbl_804183b0[];
struct Tag {
 unsigned short a,b;
 union {unsigned value; struct {unsigned char unused[3];volatile unsigned char type;} bytes; };
 unsigned x,y;
 inline void initialize(unsigned char type) {
  bytes.type=type;
  x=0;
  value=bytes.type;
  unsigned *p=&x;
  p[1]=0;
a=0;
b=0;
 }
};
struct Thing { void * volatile vtable;unsigned unused;Tag tag;};
extern "C" Thing *f1c_tag_init_801fc518(Thing *self) {
 self->vtable=lbl_804182d0;
 self->tag.initialize(2);

 self->vtable=lbl_804183b0;
 return self;
}
