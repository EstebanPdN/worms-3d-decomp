#include "w3d_ptr.h"
#line 1 "f2b_motion_segment_80153cf0.cpp"
// Observed partial layouts; vector and state roles are inferred. Volatile accesses retain the observed store/load order; original qualifier intent is unknown.
struct Vec3 {float x,y,z;Vec3(){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}Vec3 plus(const Vec3&o)const{Vec3 v;v.x=x+o.x;v.y=y+o.y;v.z=z+o.z;return v;}void scale(float t){x*=t;y*=t;z*=t;}};
struct Owner {char pad[560];Vec3 p;char gap[104];Vec3 v;char gap2[28];volatile int flag;char gap3[40];int state;};
extern "C" void apply_80153f80(Ptr32<Owner>,const Vec3&,const Vec3&);
extern "C" void set_801492ec(Ptr32<Owner>,int);
extern volatile int service_804afdec;
extern "C" float elapsed_80178df0(Ptr32<void>);
extern "C" void f2b_motion_segment_80153cf0(Ptr32<Owner> s,Ptr32<const Vec3> v){apply_80153f80(s,s->p,s->p.plus(*v));s->state=6;set_801492ec(s,32);s->flag=0;s->v.scale(elapsed_80178df0((Ptr32<void>)w3d::G(service_804afdec)));}


