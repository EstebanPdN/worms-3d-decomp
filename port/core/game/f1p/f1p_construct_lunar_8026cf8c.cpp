#include "w3d_ptr.h"
#line 1 "f1p_construct_lunar_8026cf8c.cpp"
inline void *operator new(__SIZE_TYPE__,void*p){return p;}
// Partial constructor representation. Semantic field names inferred.
extern "C" Ptr32<void> fn_8015fef0(Ptr32<void>);
struct Base {char storage[28];};
struct Vec3 {float x,y,z;void fill(float v){x=v;y=v;z=v;}};
struct String_803426b8 {Ptr32<char> text;String_803426b8();};
struct Owner:Base {int held __attribute__((aligned(__alignof__(Base))));Vec3 a,b;String_803426b8 name;int twenty,zero64,zero68,zero72,zero76,enabled;};
extern char vt_8041bd20[],name_803cbcf0[];extern const float zero_803cbcfc[],one_803cbd00[];
extern Ptr32<Owner> instance_804abb7c;
extern "C" void fn_8020bd38(Ptr32<String_803426b8>,Ptr32<const char>);
extern "C" Ptr32<Owner> w3d_construct_lunar_8026cf8c(Ptr32<Owner> self){
 fn_8015fef0(self);self->held=0;*(Ptr32<Ptr32<void>>)self=vt_8041bd20;
 // Model the observed subobject construction call.
 new (&self->name) String_803426b8;
 self->zero72=0;self->zero76=0;self->zero68=0;
 fn_8020bd38(&self->name,name_803cbcf0);
self->zero64=0;self->twenty=20;self->enabled=1;float z=zero_803cbcfc[0],o=one_803cbd00[0];instance_804abb7c=self;self->a.fill(z);self->b.fill(o);return self;
}


