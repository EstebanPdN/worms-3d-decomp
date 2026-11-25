// Partial layout and structural names inferred from original instructions.
extern unsigned char lbl_80416a90[],lbl_80416ee0[];
extern const float lbl_803b0658[],lbl_803b065c[];
struct Pair { unsigned first,second; inline void init(){second=0;} };
struct Tag {unsigned short a,b;union {unsigned value;volatile unsigned char byte[4];} u;};
struct Thing {void **vtable;unsigned pad[9];Tag tag;Pair pair;unsigned tail[3];};
extern "C" Thing *f2c_tag_init_801e34b0(Thing *self){
float a=lbl_803b0658[0];float b=lbl_803b065c[0];
Tag *tag=&self->tag;
self->vtable=(void **)lbl_80416a90;
tag->u.byte[3]=2;
tag->u.value=tag->u.byte[3];
self->pair.first=0;
self->pair.init();
tag->a=0;
tag->b=0;
self->vtable=(void **)lbl_80416ee0;
*(unsigned *)((char *)self+64)=0;
*(unsigned *)((char *)self+36)=0;
*(unsigned *)((char *)self+56)=0;
*(unsigned *)((char *)self+60)=0;
*(unsigned *)((char *)self+32)=0;
*(float *)((char *)self+8)=a;
*(float *)((char *)self+24)=b;
return self;}

