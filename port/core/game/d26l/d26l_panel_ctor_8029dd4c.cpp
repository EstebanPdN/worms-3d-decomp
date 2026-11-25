#include "w3d_ptr.h"
#line 1 "d26l_panel_ctor_8029dd4c.cpp"
// GWMP8P rev0 0x8029dd4c. Constructor of a panel with bases at +0
// (0x8015fef0) and +28 (0x802afb20), written as a plain function over a
// partial view. Vec is the shape of a vector with allocator proxy at +336;
// its allocator temporary accounts for the frame slot. That reading is
// inference.
inline void*operator new(__SIZE_TYPE__,void*p){return p;}
struct Alloc{Alloc(){}Alloc(const Alloc&){} char w3d_empty; };
struct Proxy:Alloc{Ptr32<void> data __attribute__((aligned(__alignof__(Alloc))));Proxy(const Alloc&x,Ptr32<void> p):Alloc(x),data(p){}};
struct Vec{Ptr32<void> start;Ptr32<void> finish;Proxy end;Vec(const Alloc&a=Alloc()):start(0),finish(0),end(a,0){}};
struct Triple{int a,b,c;Triple(){c=0;b=0;}};
struct Word{int v;Word(){v=0;}};
extern Ptr32<void> vt_8041c2b0[]; extern Ptr32<void> vt_8041c300[];
struct Base1_8015fef0{Base1_8015fef0(); char w3d_empty; };
extern "C" int fn_8015fef0(Ptr32<void>);
extern "C" Ptr32<void> fn_802afb20(Ptr32<void>);
extern "C" void fn_802109dc(Ptr32<void>);
struct Obj{Ptr32<Ptr32<void>> vt;char u4[204];Ptr32<Ptr32<void>> vt2;int w212,w216,w220;Word pair[2];int a[3];int b[3];int w256,w260,w264,w268,w272,w276;int u280[2];int w288;int u292[3];int w304;int w308,w312,w316,w320,w324,w328,w332;Vec v;char sub[12];Triple t;int w376;float f380,f384;};
extern "C" Ptr32<Obj> d26l_panel_ctor_8029dd4c(Ptr32<Obj> s){
 fn_8015fef0(s);
 fn_802afb20((Ptr32<char>)s+28);
 s->vt2=vt_8041c2b0;
 s->vt=vt_8041c300;
 s->w220=0;
 {Ptr32<Word> p=s->pair;int i=1;do{new(p)Word;++p;}while(i--!=0);}
 s->w260=0;s->w264=0;s->w308=0;s->w312=0;s->w320=0;s->w324=0;s->w328=0;s->w332=0;
 new(&s->v)Vec;
 fn_802109dc(s->sub);
 new(&s->t)Triple;
 s->t.a=0; s->w376=0; s->w272=0; s->f380=0.0f; s->w276=0; s->f384=0.0f; s->w304=0; s->w288=0;
 for(int i=0;i<3;i++){s->a[i]=0;s->b[i]=0;}
 s->w256=0;
 s->w216=0;
 return s;
}


