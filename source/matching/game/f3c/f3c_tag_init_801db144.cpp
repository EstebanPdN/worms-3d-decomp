// Structural names, partial layout, and floating temporary type inferred.
// Original frame reserves an additional 16 bytes; their purpose is unknown.
extern unsigned char lbl_80416970[],lbl_804168c0[],lbl_80416ae8[];
extern void *lbl_804ab80c;
extern const float lbl_803afe38[];
extern "C" void fn_802109dc(void *);
extern "C" void fn_801de524(void *);
extern "C" void *fn_8020b680(void *);
extern "C" void fn_802ee7d0(unsigned);
struct Pair {unsigned first,second;inline void init(){second=0;}};
struct Tag {unsigned short a,b;union{unsigned value;volatile unsigned char byte[4];}u;};
struct Thing{void **vtable;Tag tag;Pair pair;unsigned tail[45];};
extern "C" Thing *f3c_tag_init_801db144(Thing *self){volatile unsigned char reserved_frame[16];Tag *tag=&self->tag;self->vtable=(void **)lbl_80416970;tag->u.byte[3]=2;tag->u.value=tag->u.byte[3];self->pair.first=0;self->pair.init();tag->a=0;tag->b=0;self->vtable=(void **)lbl_804168c0;
fn_802109dc((char *)self+36);fn_802109dc((char *)self+48);*(unsigned *)((char *)self+60)=0;((Pair *)((char *)self+60))->init();((Pair *)((char *)self+68))->init();fn_802109dc((char *)self+76);*(unsigned *)((char *)self+104)=1;fn_801de524((char *)self+124);*(void **)((char *)self+172)=0;lbl_804ab80c=self;
void *got=fn_8020b680(lbl_80416ae8);if(got)(*(void (***)(void *))got)[3](got);void *old=*(void **)((char *)self+172);if(old)(*(void (***)(void *))old)[4](old);*(void **)((char *)self+172)=got;
double f=lbl_803afe38[0];
*(float *)((char *)self+92)=f;*(unsigned *)((char *)self+96)=0;*(unsigned *)((char *)self+104)=1;*(unsigned *)((char *)self+108)=1;*(unsigned *)((char *)self+112)=1;*(unsigned *)((char *)self+116)=0;fn_802ee7d0(203);*(unsigned *)((char *)self+184)=0;*(unsigned *)((char *)self+188)=0;*(unsigned *)((char *)self+192)=0;*(unsigned *)((char *)self+196)=0;*(unsigned *)((char *)self+180)=0;for(int i=3;i>=0;--i)((float *)((char *)self+20))[i]=f;*(unsigned *)((char *)self+176)=0;return self;}