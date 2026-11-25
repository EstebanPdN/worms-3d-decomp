#include "w3d_ptr.h"
#line 1 "f7b_target_position_8015324c.cpp"
// All semantic roles and layouts inferred. Independent vector/matrix types.
struct F7TargetVec{float x,y,z;F7TargetVec(){}F7TargetVec(float a,float b,float c){x=a;y=b;z=c;}F7TargetVec(const F7TargetVec&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}void add(const F7TargetVec&o){x+=o.x;y+=o.y;z+=o.z;}Ptr32<const float> data()const{return &x;}float norm2()const{return x*x+y*y+z*z;}void scale(float k){x*=k;y*=k;z*=k;}};
struct F7TargetBasis{float m[9];F7TargetBasis(){}F7TargetBasis(float,float,float,float);};struct F7TargetTranslation{float x,y,z;F7TargetTranslation();};
struct F7TargetMatrix{F7TargetBasis basis;F7TargetTranslation translation;};inline void*operator new(__SIZE_TYPE__,void*p){return p;}
extern const float zero_803a1b48[],axis_803a1b50[];extern const float rise_803a1b4c[];
struct F7TargetOwner{char p[556];Ptr32<void> distance;F7TargetVec position;char p2[4];float angle;char p3[564];int target;};
extern "C" void rotate_801f7538(Ptr32<F7TargetBasis>,float,float,float,float);
extern "C" int gate_80153f38(Ptr32<F7TargetOwner>);extern "C" Ptr32<void> cast_80342a74(Ptr32<void>);extern "C" float get_80178df0(Ptr32<void>);extern "C" int write_801262c0(Ptr32<int>,Ptr32<const F7TargetVec>);
extern "C" void f7b_target_position_8015324c(Ptr32<F7TargetOwner> s){if(!gate_80153f38(s)){float length=get_80178df0(cast_80342a74(s->distance));float zero=zero_803a1b48[0],rise=rise_803a1b4c[0];F7TargetVec v(zero,rise,length);F7TargetVec q;F7TargetMatrix m;rotate_801f7538(&m.basis,zero,axis_803a1b50[0],zero,s->angle);Ptr32<const float> e=v.data(); Ptr32<const float> a=m.basis.m; Ptr32<const float> b=m.basis.m+3; Ptr32<const float> c=m.basis.m+6; Ptr32<const float> d=&m.translation.x;q.x=e[0]*a[0]+e[1]*b[0]+e[2]*c[0]+d[0];q.y=e[0]*a[1]+e[1]*b[1]+e[2]*c[1]+d[1];q.z=e[0]*a[2]+e[1]*b[2]+e[2]*c[2]+d[2];q.add(s->position);write_801262c0(&s->target,&q);}}


