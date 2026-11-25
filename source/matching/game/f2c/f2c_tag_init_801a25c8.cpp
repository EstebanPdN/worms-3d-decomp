// Partial layout, structural names and access qualifiers inferred from original instructions.
extern unsigned char lbl_80411ac0[],lbl_80413a00[];
struct Pair { unsigned first,second; inline void init(){second=0;} };
struct Tag {unsigned short a,b;union {unsigned value;volatile unsigned char byte[4];} u;};
struct Thing {void **vtable;Tag tag;Pair pair;unsigned tail[16];};
extern Thing *lbl_804ab750;
struct Triple {unsigned first,second,third;inline void init(){third=0;second=0;first=0;}};
extern "C" Thing *f2c_tag_init_801a25c8(Thing *self){Tag *tag=&self->tag;
self->vtable=(void **)lbl_80411ac0;
tag->u.byte[3]=2;
tag->u.value=tag->u.byte[3];
self->pair.first=0;
self->pair.init();
tag->a=0;
tag->b=0;
self->vtable=(void **)lbl_80413a00;
((Triple *)((char *)self+36))->init();
((Triple *)((char *)self+48))->init();
((Triple *)((char *)self+60))->init();
Thing *previous=lbl_804ab750;
((Triple *)((char *)self+72))->init();
*(unsigned *)((char *)self+20)=0;
*(unsigned *)((char *)self+28)=0;
*(Thing **)((char *)self+32)=previous;
lbl_804ab750=self;return self;}
