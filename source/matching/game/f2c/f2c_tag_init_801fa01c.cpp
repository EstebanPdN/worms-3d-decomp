// Partial layout and structural names inferred from original instructions.
// The original frame reserves 40 additional bytes; their purpose is unknown.
extern unsigned char lbl_80418328[],lbl_80418470[],lbl_80418268[];
extern "C" void fn_8035a2c0(void *);
struct Pair { unsigned first,second; inline void init(){second=0;} };
struct Tag {unsigned short a,b;union {unsigned value;volatile unsigned char byte[4];} u;};
struct Thing {void **vtable;unsigned pad[2];Tag tag;Pair pair;unsigned tail[60];};
extern "C" Thing *f2c_tag_init_801fa01c(Thing *self){volatile unsigned char reserved_frame[40];Tag *tag=&self->tag;
self->vtable=(void **)lbl_80418328;
tag->u.byte[3]=2;
tag->u.value=tag->u.byte[3];
self->pair.first=0;
self->pair.init();
tag->a=0;
tag->b=0;
self->vtable=(void **)lbl_80418328;

fn_8035a2c0((char *)self+28);
*(void **)((char *)self+28)=lbl_80418470;
self->vtable=(void **)lbl_80418268;
*(unsigned *)((char *)self+96)=0;
((Pair *)((char *)self+96))->init();
((Pair *)((char *)self+104))->init();
*(unsigned *)((char *)self+112)=0;
((Pair *)((char *)self+112))->init();
((Pair *)((char *)self+120))->init();
*(unsigned *)((char *)self+208)=0;
((Pair *)((char *)self+208))->init();
((Pair *)((char *)self+216))->init();
*(unsigned *)((char *)self+224)=0;
((Pair *)((char *)self+224))->init();
((Pair *)((char *)self+232))->init();
*(unsigned *)((char *)self+240)=0;
((Pair *)((char *)self+240))->init();
((Pair *)((char *)self+248))->init();
*(unsigned *)((char *)self+256)=0;
*(unsigned *)((char *)self+260)=0;
*(unsigned *)((char *)self+264)&=0x3fffffff;return self;}
