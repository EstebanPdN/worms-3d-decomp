#include "w3d_ptr.h"
#line 1 "cx15a_adjust_motion_800cfe68.cpp"
// PPC32 observations: pointer words are four bytes; names and member roles are inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
inline void release(Ptr32<void> p){if(p)VCALL(p,void(*)(void*),16)(p);}
struct Vec3 {float x,y,z;Vec3(){} Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}};

extern "C" void prepare_800d1130(Ptr32<void>,Ptr32<Vec3>,Ptr32<void>,Ptr32<Vec3>),correct_800d0710(Ptr32<void>,Ptr32<Vec3>,Ptr32<Vec3>,Ptr32<Vec3>),finish_800d13d0(Ptr32<void>,Ptr32<Vec3>,Ptr32<Vec3>),dispatch_800d0c88(Ptr32<void>,Ptr32<void>,Ptr32<Vec3>,Ptr32<Vec3>);extern "C" Vec3 solve_800d0108(Ptr32<void>,Ptr32<Vec3>,Ptr32<Vec3>);
extern "C" void w3d_cx15a_adjust_motion_800cfe68(Ptr32<void> self,Ptr32<Vec3> position,Ptr32<void> key,Ptr32<Vec3> velocity){Vec3 local_position(*position),local_velocity(*velocity);prepare_800d1130(self,&local_position,key,&local_velocity);local_position=solve_800d0108(self,&local_position,&local_velocity);FIELD(self,int,40)=0;correct_800d0710(self,&local_position,position,&local_velocity);finish_800d13d0(self,&local_position,&local_velocity);dispatch_800d0c88(self,key,position,&local_position);*position=local_position;FIELD(self,Vec3,76)=local_position;*velocity=local_velocity;FIELD(self,Vec3,276)=local_velocity;}


