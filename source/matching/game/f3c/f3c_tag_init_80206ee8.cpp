// Structural names, partial layouts, and volatile access qualifiers inferred.
extern unsigned char lbl_80419200[],lbl_804191c0[];
extern void *lbl_804b18f0;
extern "C" void fn_802109dc(void *);
extern "C" char *fn_80212fd4(unsigned);
extern "C" void fn_802eee50(...);
extern "C" void fn_802134fc(void *);
extern "C" unsigned fn_80207490();
struct Pair {unsigned first,second;inline void init(){second=0;}};
struct Tag {unsigned short a,b;union{unsigned value;volatile unsigned char byte[4];}u;};
struct Vec {char *begin;unsigned end,capacity;inline void init(){capacity=0;end=0;begin=0;}};
struct Thing{void **vtable;Tag tag;Pair pair;unsigned member[3];unsigned a;Vec vec;unsigned b;};
inline const unsigned &minimum(const unsigned &a,const unsigned &b){return b<a?b:a;}
inline const int &maximum(const int &a,const int &b){return b>a?b:a;}
extern "C" Thing *f3c_tag_init_80206ee8(Thing *self){Tag *tag=&self->tag;self->vtable=(void **)lbl_80419200;tag->u.byte[3]=2;tag->u.value=tag->u.byte[3];self->pair.first=0;self->pair.init();tag->a=0;tag->b=0;self->vtable=(void **)lbl_804191c0;
fn_802109dc((char *)self+20);Vec *v=&self->vec;v->init();
unsigned cap=v->capacity;int a=cap+1,b=cap+(cap>>1);unsigned old=v->end;unsigned size=maximum(a,b)<<2;
char *buffer=fn_80212fd4(size);if(v->begin){fn_802eee50(buffer,v->begin,minimum(size,old));fn_802134fc(v->begin);}
char *end=buffer+old;v->begin=buffer;*(volatile unsigned *)&v->end=(unsigned)end;v->end=(unsigned)(end+=4);v->capacity=(unsigned)(buffer+*(volatile unsigned *)&size);
self->a=0;unsigned *slot=(unsigned *)self->vec.begin;*slot=fn_80207490();lbl_804b18f0=self;self->b=0;return self;}