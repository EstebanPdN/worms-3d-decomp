#include "w3d_ptr.h"
#line 1 "f5b_build_midpoint_step_80011b18.cpp"
// All names, types, layouts and roles are inferred.

struct Vec3{float x,y,z;Vec3(){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}Vec3 operator*(float f)const{Vec3 r;r.x=x*f;r.y=y*f;r.z=z*f;return r;}Vec3 operator+(const Vec3&o)const{Vec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}};
struct Queue_80003300{Queue_80003300();char gap[44];int count;};
extern "C" void fn_800033d8(Ptr32<Queue_80003300>);
struct Ref{void assign(Ptr32<Queue_80003300> q){value=q;}int pad;Ptr32<Queue_80003300> value;void reset(){fn_800033d8(value);value=0;}};
extern "C" void fn_800033d8(Ptr32<Queue_80003300>);

extern "C" Ptr32<const Vec3> fn_80003e78(Ptr32<void>);
extern "C" void fn_80003424(Ptr32<Queue_80003300>,Ptr32<const Vec3>,int);
extern "C" void fn_800108b8(Ptr32<void>);
struct Target{char gap[16];Vec3 p;};extern Ptr32<Ptr32<Ptr32<Target>>> table_804aa750;
extern const float half_8036a3b0[],rise_8036a3b4[];
struct Owner{char pad[16];int index;char gap[56];Ptr32<void> current;Ref queue;};
extern "C" void f5b_build_midpoint_step_80011b18(Ptr32<Owner> s){s->queue.reset();Vec3 a(*fn_80003e78(s->current));Vec3 b((*(Ptr32<Ptr32<Target>>)((Ptr32<char>)(*table_804aa750)+(s->index<<2)))->p);Ptr32<Queue_80003300> q=new Queue_80003300;s->queue.assign(q);q->count++;float half=half_8036a3b0[0],rise=rise_8036a3b4[0];Vec3 p=(a+b)*half;p.y+=rise;fn_80003424(q,&p,5);fn_800108b8(s);}


