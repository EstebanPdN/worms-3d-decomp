#include "w3d_ptr.h"
#line 1 "f3c_tag_init_80206ee8.cpp"
// Structural names, partial layouts, and volatile access qualifiers inferred.
extern unsigned char lbl_80419200[],lbl_804191c0[];
extern Ptr32<void> lbl_804b18f0;
extern "C" void fn_802109dc(Ptr32<void>);
extern "C" Ptr32<char> fn_80212fd4(unsigned);
extern "C" void fn_802eee50(...);
extern "C" void fn_802134fc(Ptr32<void>);
extern "C" unsigned fn_80207490();
struct Pair {unsigned first,second;inline void init(){second=0;}};
struct Tag {unsigned short a,b;union{unsigned value;w3d::be_array<volatile unsigned char, 4> byte;}u;};
struct Vec {Ptr32<char> begin;unsigned end,capacity;inline void init(){capacity=0;end=0;begin=0;}};
struct Thing{Ptr32<Ptr32<void>> vtable;Tag tag;Pair pair;unsigned member[3];unsigned a;Vec vec;unsigned b;};
inline const unsigned &minimum(const unsigned &a,const unsigned &b){return b<a?b:a;}
inline const int &maximum(const int &a,const int &b){return b>a?b:a;}
extern "C" Ptr32<Thing> f3c_tag_init_80206ee8(Ptr32<Thing> self){Ptr32<Tag> tag=&self->tag;self->vtable=(Ptr32<Ptr32<void>>)lbl_80419200;tag->u.byte[3]=2;tag->u.value=tag->u.byte[3];self->pair.first=0;self->pair.init();tag->a=0;tag->b=0;self->vtable=(Ptr32<Ptr32<void>>)lbl_804191c0;
fn_802109dc((Ptr32<char>)self+20);Ptr32<Vec> v=&self->vec;v->init();
unsigned cap=v->capacity;int a=cap+1,b=cap+(cap>>1);unsigned old=v->end;unsigned size=maximum(a,b)<<2;
Ptr32<char> buffer=fn_80212fd4(size);if(v->begin){fn_802eee50(w3d::VA(buffer),w3d::VA(v->begin),minimum(size,old));fn_802134fc(v->begin);}
Ptr32<char> end=buffer+old;v->begin=buffer;*(Ptr32<volatile unsigned int>)&v->end=(unsigned)w3d::H(end);v->end=(unsigned)w3d::H((end+=4));v->capacity=(unsigned)w3d::H((buffer+*(Ptr32<volatile unsigned int>)&size));
self->a=0;Ptr32<unsigned int> slot=(Ptr32<unsigned int>)self->vec.begin;*slot=fn_80207490();lbl_804b18f0=self;self->b=0;return self;}

