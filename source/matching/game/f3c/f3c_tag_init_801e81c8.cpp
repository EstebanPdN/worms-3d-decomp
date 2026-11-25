// Structural names, qualifiers, and partial layout inferred from original instructions.
extern unsigned char lbl_803657d8[];
extern "C" void *fn_8020fcb4(void *);
struct Pair {unsigned first,second;inline void init(){second=0;}};
struct Tag {unsigned short a,b;union{unsigned value;volatile unsigned char byte[4];}u;};
struct Thing{Tag tag;Pair pair;unsigned a,b,c;void *held;unsigned flags;};
extern "C" Thing *f3c_tag_init_801e81c8(Thing *self){Tag *tag=&self->tag;tag->u.byte[3]=2;self->pair.first=0;tag->u.value=tag->u.byte[3];self->pair.init();tag->a=0;tag->b=0;self->held=0;self->a=0;self->b=0;self->c=0;self->flags=1;void *got=fn_8020fcb4(lbl_803657d8);if(got)(*(void (***)(void *))got)[3](got);void *old=self->held;if(old)(*(void (***)(void *))old)[4](old);self->held=got;*(Thing **)((char *)got+64)=self;*(unsigned *)((char *)got+32)&=0xbfffffff;return self;}