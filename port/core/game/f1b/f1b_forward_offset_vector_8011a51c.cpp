#include "w3d_ptr.h"
#line 1 "f1b_forward_offset_vector_8011a51c.cpp"
// Partial PPC32 views; vector and field roles are inferred from the observed operations.
struct Vec3 {float x,y,z;Vec3(){}Vec3(float a,float b,float c){x=a;y=b;z=c;}Vec3(const Vec3 &o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}
Vec3 plus(const Vec3 &o)const{Vec3 v;v.x=x+o.x;v.y=y+o.y;v.z=z+o.z;return v;}};
struct I {Ptr32<Ptr32<void>> table;};
struct Owner {char unknown[28];Ptr32<I> a; Ptr32<I> b;Vec3 offset;};
extern "C" void f1b_forward_offset_vector_8011a51c(Ptr32<Owner> s,Ptr32<Vec3> v){if(s->b){((Ptr32<void (Ptr32<I>, Ptr32<Vec3>, int)>)s->b->table[19])(s->b,v,0);((Ptr32<void (Ptr32<I>, const Vec3 &, int)>)s->a->table[19])(s->a,v->plus(s->offset),0);}}


