#include "w3d_ptr.h"
#line 1 "d26l_panel_ctor_b_802b5524.cpp"
// GWMP8P rev0 0x802b5524. Constructor of a panel with bases at +0
// (0x8015fef0) and +28 (0x802afb20), written as a plain function over a
// partial view. Field names only record offsets. Word and CW are element
// views chosen because the original's per-array clearing loops show those
// element counts.
inline void*operator new(__SIZE_TYPE__,void*p){return p;}
struct Word{int v;Word(){v=0;}};
struct Obj;struct ObjVt{Ptr32<void> s[4];Ptr32<void (Ptr32<Obj>)> release;};struct Obj{Ptr32<ObjVt> vt;};
struct Held{Ptr32<Obj> value;Held(){value=0;}void assign(int n){if(value)value->vt->release(value);value=(Ptr32<Obj>)w3d::G(n);}};
struct CW{int n;Word w[2];};
extern Ptr32<void> vt_8041c740[]; extern Ptr32<void> vt_8041c790[];
extern "C" int fn_8015fef0(Ptr32<void>);
extern "C" Ptr32<void> fn_802afb20(Ptr32<void>);
struct S{Ptr32<Ptr32<void>> vt;char u4[204];Ptr32<Ptr32<void>> vt2;int w212,w216;float f220;int w224,w228,w232,w236,w240,w244,w248,w252,w256,w260,w264,w268,w272,w276;Held h280;int w284,w288,w292,w296,w300;float f304,f308,f312;Word a[2];Word b[3];Word c[3];Word d[3];CW e;CW g;Word h[2];Word i[2];int w400,w404,w408;float f412,f416;};
extern "C" Ptr32<S> d26l_panel_ctor_b_802b5524(Ptr32<S> s){
 fn_8015fef0(s);
 fn_802afb20((Ptr32<char>)s+28);
 s->vt2=vt_8041c740;
 s->vt=vt_8041c790;
 s->w212=0;s->w216=0;s->w236=0;s->w240=0;s->w268=0;s->w272=0;s->w276=0;
 new(&s->h280)Held;
 {Ptr32<Word> p=s->a;int i=1;do{new(p)Word;++p;}while(i--!=0);}
 {Ptr32<Word> p=s->b;for(int i=3;i;--i){new(p)Word;++p;}}
 {Ptr32<Word> p=s->c;for(int i=3;i;--i){new(p)Word;++p;}}
 {Ptr32<Word> p=s->d;for(int i=3;i;--i){new(p)Word;++p;}}
 s->e.n=0;
 {Ptr32<Word> p=s->e.w;int i=1;do{new(p)Word;++p;}while(i--!=0);}
 s->g.n=0;
 {Ptr32<Word> p=s->g.w;int i=1;do{new(p)Word;++p;}while(i--!=0);}
 {Ptr32<Word> p=s->h;int i=1;do{new(p)Word;++p;}while(i--!=0);}
 {Ptr32<Word> p=s->i;int i=1;do{new(p)Word;++p;}while(i--!=0);}
 float z=0.0f;
 int zero=0;
 s->w400=zero; s->w284=zero; s->w288=zero; s->w292=zero; s->w296=zero; s->w300=zero; s->w260=zero; s->w264=zero; s->f304=z; s->f308=z; s->w252=zero; s->w244=zero;
 s->h280.assign(zero);
 s->w256=zero; s->w404=zero; s->f312=100.0f; s->f412=z; s->f416=z; s->w408=zero; s->f220=z; s->w224=zero; s->w228=zero; s->w232=zero;
 return s;
}


