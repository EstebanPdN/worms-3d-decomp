// Partial layout and structural names inferred from original instructions.
// The original frame reserves 24 additional bytes; their purpose is unknown.
extern unsigned char lbl_80418eb8[],lbl_80418df0[];
struct Pair { unsigned first,second; inline void init(){second=0;} };
struct Tag {unsigned short a,b;union {unsigned value;volatile unsigned char byte[4];} u;};
struct Thing {void **vtable;Tag tag;Pair pair;unsigned tail[34];};
extern "C" Thing *f2c_tag_init_80200db4(Thing *self){volatile unsigned char reserved_frame[24];Tag *tag=&self->tag;
self->vtable=(void **)lbl_80418eb8;
tag->u.byte[3]=2;
tag->u.value=tag->u.byte[3];
self->pair.first=0;
self->pair.init();
tag->a=0;
tag->b=0;
self->vtable=(void **)lbl_80418df0;
*(unsigned *)((char *)self+20)=0;
*(unsigned *)((char *)self+24)=0;
*(unsigned *)((char *)self+36)=0;
*(unsigned *)((char *)self+40)=0;
*(unsigned *)((char *)self+44)=0;
((Pair *)((char *)self+44))->init();
((Pair *)((char *)self+52))->init();
*(unsigned *)((char *)self+124)=0;
((Pair *)((char *)self+124))->init();
((Pair *)((char *)self+132))->init();
*(unsigned *)((char *)self+140)=0;
((Pair *)((char *)self+140))->init();
((Pair *)((char *)self+148))->init();return self;}
