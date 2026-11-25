// Partial layout and structural names inferred from original instructions.
// The original frame reserves 48 additional bytes; their purpose is unknown.
extern unsigned char lbl_804133c8[],lbl_80413378[];
extern const float lbl_803a82b4[];
struct Pair { unsigned first,second; inline void init(){second=0;} };
struct Tag {unsigned short a,b;union {unsigned value;volatile unsigned char byte[4];} u;};
struct Thing {void **vtable;Tag tag;Pair pair;unsigned tail[27];};
extern "C" Thing *f2c_tag_init_80194234(Thing *self){volatile unsigned char reserved_frame[48];Tag *tag=&self->tag;
self->vtable=(void **)lbl_804133c8;
tag->u.byte[3]=2;
tag->u.value=tag->u.byte[3];
self->pair.first=0;
self->pair.init();
tag->a=0;
tag->b=0;
self->vtable=(void **)lbl_80413378;
*(unsigned *)((char *)self+24)=0;
((Pair *)((char *)self+24))->init();
((Pair *)((char *)self+32))->init();
*(unsigned *)((char *)self+40)=0;
((Pair *)((char *)self+40))->init();
((Pair *)((char *)self+48))->init();
*(unsigned *)((char *)self+56)=0;
((Pair *)((char *)self+56))->init();
((Pair *)((char *)self+64))->init();
*(unsigned *)((char *)self+72)=0;
*(unsigned *)((char *)self+76)=0;
*(unsigned *)((char *)self+80)=0;
((Pair *)((char *)self+80))->init();
((Pair *)((char *)self+88))->init();
*(unsigned *)((char *)self+96)=0;
((Pair *)((char *)self+96))->init();
*(unsigned *)((char *)self+104)=0;
((Pair *)((char *)self+104))->init();
float f=lbl_803a82b4[0];((Pair *)((char *)self+112))->init();
*(unsigned *)((char *)self+124)=0;
*(float *)((char *)self+20)=f;return self;}
