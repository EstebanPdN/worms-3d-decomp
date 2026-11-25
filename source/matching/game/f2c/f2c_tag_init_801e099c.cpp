// Partial layout and structural names inferred from original instructions.
extern unsigned char lbl_80416a90[],lbl_80416d20[];
extern const float lbl_803b048c[],lbl_803b0490[],lbl_803b0494[];
struct Pair { unsigned first,second; inline void init(){second=0;} };
struct Tag {unsigned short a,b;union {unsigned value;volatile unsigned char byte[4];} u;};
struct Thing {void **vtable;unsigned pad[9];Tag tag;Pair pair;unsigned tail[9];};
struct Vector {float x,y,z;inline void init(float v) {x=v;y=v;z=v;} };
extern "C" Thing *f2c_tag_init_801e099c(Thing *self){
float a=lbl_803b048c[0],b=lbl_803b0490[0],c=lbl_803b0494[0];Tag *tag=&self->tag;
self->vtable=(void **)lbl_80416a90;
tag->u.byte[3]=2;
tag->u.value=tag->u.byte[3];
self->pair.first=0;
self->pair.init();
tag->a=0;
tag->b=0;
self->vtable=(void **)lbl_80416d20;
*(unsigned *)((char *)self+88)=0;
*(unsigned *)((char *)self+4)=0;
*(unsigned *)((char *)self+32)=0;
*(unsigned *)((char *)self+36)=0;
*(unsigned *)((char *)self+84)=0;
*(float *)((char *)self+8)=a;
*(float *)((char *)self+24)=b;
*(unsigned *)((char *)self+28)=10101;
((Vector *)((char *)self+12))->init(c);
((Vector *)((char *)self+60))->init(c);
((Vector *)((char *)self+72))->init(c);
*(int *)((char *)self+56)=-1;
return self;}

