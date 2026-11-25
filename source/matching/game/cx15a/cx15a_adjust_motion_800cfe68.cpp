// PPC32 observations: pointer words are four bytes; names and member roles are inferred.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
inline void release(void*p){if(p)VCALL(p,void(*)(void*),16)(p);}
struct Vec3 {float x,y,z;Vec3(){} Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}};

extern "C" void prepare_800d1130(void*,Vec3*,void*,Vec3*),correct_800d0710(void*,Vec3*,Vec3*,Vec3*),finish_800d13d0(void*,Vec3*,Vec3*),dispatch_800d0c88(void*,void*,Vec3*,Vec3*);extern "C" Vec3 solve_800d0108(void*,Vec3*,Vec3*);
extern "C" void w3d_cx15a_adjust_motion_800cfe68(void*self,Vec3*position,void*key,Vec3*velocity){Vec3 local_position(*position),local_velocity(*velocity);prepare_800d1130(self,&local_position,key,&local_velocity);local_position=solve_800d0108(self,&local_position,&local_velocity);FIELD(self,int,40)=0;correct_800d0710(self,&local_position,position,&local_velocity);finish_800d13d0(self,&local_position,&local_velocity);dispatch_800d0c88(self,key,position,&local_position);*position=local_position;FIELD(self,Vec3,76)=local_position;*velocity=local_velocity;FIELD(self,Vec3,276)=local_velocity;}
