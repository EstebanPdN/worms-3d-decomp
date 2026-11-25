#include "w3d_ptr.h"
#line 1 "f2b_vector_probe_800d066c.cpp"
// Partial observed layout; point and container roles are inferred. Inline accessors preserve the original count/index operations.
struct Vec3 {float x,y,z;Vec3(){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;} Vec3 minus(const Vec3&o)const{Vec3 v;v.x=x-o.x;v.y=y-o.y;v.z=z-o.z;return v;}};
struct Item {Vec3 point;char tail[16];};
struct Owner {char pad[28];Ptr32<Item> begin; Ptr32<Item> end;unsigned size()const{return end-begin;} Item &at(unsigned i){return begin[i];}};
extern "C" int probe_800cffa0(Ptr32<Owner>,Ptr32<const Vec3>,const Vec3&);
extern "C" void f2b_vector_probe_800d066c(Ptr32<Owner> s,Ptr32<const Vec3> v){Vec3 last(s->at(s->size()-1).point);probe_800cffa0(s,v,last.minus(*v));}


