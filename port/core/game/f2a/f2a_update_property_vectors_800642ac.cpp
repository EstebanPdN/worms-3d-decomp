#include "w3d_ptr.h"
#line 1 "f2a_update_property_vectors_800642ac.cpp"
// Original entry 0x800642ac; property and field names are inferred.
// The unused six-float frame object accounts for the observed 24-byte reservation.
struct Vec{float x,y,z;Vec(){}void set(float a,float b,float c){x=a;y=b;z=c;}};
struct Obj{char p[28];Ptr32<void> prop;char q[12];float scale;char r[36];float value;char s[56];Ptr32<void> sample;};
struct DataA{char p[8];float scale,sample;};struct DataB{char p[12];Vec a,b;};
extern "C" {Ptr32<void> fn_8034380c(Ptr32<void>);float fn_80178df0(Ptr32<void>);Ptr32<DataA> fn_8018963c(Ptr32<void>);Ptr32<DataB> fn_80189518(Ptr32<void>);extern float lbl_80379d30[],lbl_80379d34[],lbl_80379d38[],lbl_80379d3c[];
void w3d_f2a_update_property_vectors_800642ac(Ptr32<Obj> p){struct Frame{float a,b,c,d,e,f;Frame(){}} reserve;Ptr32<void> prop=fn_8034380c(p->prop);float value=p->value*p->scale;float sample=fn_80178df0(p->sample);Ptr32<DataA> a=fn_8018963c(prop);float scaled=value*lbl_80379d30[0];a->sample=sample;a->scale=scaled;Ptr32<DataB> b=fn_80189518(prop);float zero=lbl_80379d38[0];b->a.set(scaled+lbl_80379d34[0],zero,zero);Ptr32<DataB> c=fn_80189518(prop);c->b.set(value+lbl_80379d3c[0],zero,zero);}}


