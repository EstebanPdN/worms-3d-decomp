#include "w3d_ptr.h"
#line 1 "f8b_record_nearest_hit_800d8fdc.cpp"
// Inferred nearest-hit state and callback signatures; helper writes one float; twelve following reserved bytes have unknown original purpose.
struct F8HitVec{float x,y,z;F8HitVec(){}F8HitVec(float a,float b,float c):x(a),y(b),z(c){}void set(float a,float b,float c){x=a;y=b;z=c;}};
struct F8HitOwner{Ptr32<Ptr32<void>> vtable;char p[32];F8HitVec first,second,third;char p2[296];int base;};
extern "C" int intersect_800419cc(Ptr32<float>,Ptr32<const F8HitVec>,Ptr32<const F8HitVec>,Ptr32<const F8HitVec>,float);extern "C" float ceil_802e85fc(float);
extern const float zero_80389524[],one_80389530[];
extern "C" void f8b_record_nearest_hit_800d8fdc(Ptr32<F8HitOwner> s,unsigned short id,Ptr32<unsigned short> outId,Ptr32<int> best,Ptr32<void> a,Ptr32<void> b,Ptr32<F8HitVec> normal,float level){F8HitVec newNormal;struct {float value;char unknown_reservation[12];} hit;if(intersect_800419cc(&hit.value,&s->first,&s->second,&s->third,level)){float zero=zero_80389524[0];if(hit.value>=zero){if(*best!=-1&&!(hit.value<(float)*best))return;*outId=id;*best=(int)ceil_802e85fc(hit.value);((Ptr32<void (Ptr32<F8HitOwner>, int, Ptr32<void>)>)s->vtable[11])(s,s->base+*best,a);((Ptr32<void (Ptr32<F8HitOwner>, int, Ptr32<void>)>)s->vtable[12])(s,s->base+*best,b);newNormal.set(zero,one_80389530[0],zero);*normal=newNormal;}}}


