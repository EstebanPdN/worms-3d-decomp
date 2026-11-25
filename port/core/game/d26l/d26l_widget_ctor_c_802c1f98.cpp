#include "w3d_ptr.h"
#line 1 "d26l_widget_ctor_c_802c1f98.cpp"
// GWMP8P rev0 0x802c1f98. Constructor of a widget with base 0x8015fef0 and
// vtable 0x8041c8e0, written as a plain function over a partial view. Held
// slots at +48 and +56 are witnessed by the release calls. Field names only
// record offsets.
struct Str{Ptr32<char> p;Str();Str(const Str&);};
struct Obj;struct ObjVt{Ptr32<void> s[4];Ptr32<void (Ptr32<Obj>)> release;};struct Obj{Ptr32<ObjVt> vt;};
struct Held{Ptr32<Obj> value;void assign(int n){if(value)value->vt->release(value);value=(Ptr32<Obj>)w3d::G(n);}};
struct Vec{float x,y,z;Vec(){} Vec(float a,float b,float c){x=a;y=b;z=c;} };
struct VW{int a,b,c;};
extern Ptr32<void> vt_8041c8e0[];
extern VW ident_8045e788;
extern "C" int fn_8015fef0(Ptr32<void>);
inline void*operator new(__SIZE_TYPE__,void*p){return p;}
struct Tab{int t[32];Tab(){for(unsigned i=0;i<32;i++)t[i]=0;}};struct S{Ptr32<Ptr32<void>> vt;char u4[24];int w28,w32,w36,w40,w44;Held h48;int w52;Held h56;int w60,w64,w68,w72,w76,w80,w84,w88;Tab t;int w220,w224,w228,w232,w236,w240,w244;Str a,b,c,d;int w264;VW v268;Vec f280;VW v292;VW v304;float f316;int w320,w324,w328,w332,w336,w340,w344,w348,w352,w356,w360,w364;float f368,f372;int w376,w380;};
extern "C" Ptr32<S> d26l_widget_ctor_c_802c1f98(Ptr32<S> s){
 int zero=0;
 fn_8015fef0(s);
 s->w28=zero;s->w32=zero;s->w36=zero;s->w40=zero;s->w44=zero;s->h48.value=0;s->w52=zero;s->h56.value=0;
 s->w236=zero;s->w244=zero;s->vt=vt_8041c8e0;
 new(&s->a)Str;new(&s->b)Str;new(&s->c)Str;new(&s->d)Str;
 float k=0.0f;
 s->w364=99; s->f316=k; s->w336=zero; s->w340=zero; s->w344=zero; s->w348=zero; s->w352=zero; s->w356=zero; s->w360=zero; s->f368=k; s->f372=k; s->w376=zero; s->w80=zero; s->w84=zero; s->w88=zero; s->w220=zero; s->w224=zero;
 s->h56.assign(zero);
 s->w60=zero;
 new(&s->t)Tab;
 int zero2=0;
 s->w64=34; s->w332=6; s->w228=zero2; s->w232=zero2;
 s->h48.assign(zero2);
 s->w72=4;s->w68=zero2;s->w240=zero2;s->w264=zero2;
 s->v268=ident_8045e788;
 s->v292=ident_8045e788;
 new(&s->f280)Vec(1.0f,1.0f,1.0f);
 s->v304=ident_8045e788;
 s->w320=zero2;s->w324=zero2;s->w380=zero2;s->w328=zero2;
 return s;
}


