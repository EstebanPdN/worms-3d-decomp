#include "w3d_ptr.h"
#line 1 "cx15a_refresh_follow_800f02a8.cpp"
// Inferred names. PPC32 vector fields are floats at +0/+4/+8; pointer words are four bytes.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c){x=a;y=b;z=c;}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}Vec3 scaled(float k)const{Vec3 r;r.x=x*k;r.y=y*k;r.z=z*k;return r;}void scale(float k){x*=k;y*=k;z*=k;}float length2()const{return x*x+y*y+z*z;}};


extern "C" void fade_800f09d0(Ptr32<void>, Ptr32<void>),step_800f0a70(Ptr32<void>,int);extern "C" int integer_80178c48(Ptr32<void>);extern "C" Ptr32<void> index_800fc6dc(int);
extern "C" int w3d_cx15a_refresh_follow_800f02a8(Ptr32<void> self,int tick){fade_800f09d0(self, (Ptr32<void>)w3d::G(tick));step_800f0a70(self,tick);FIELD(self,int,76)=tick;if(FIELD(self,int,72)){Ptr32<void> info=index_800fc6dc(integer_80178c48(FIELD(self,void*,92)));Vec3 position(FIELD(info,Vec3,80));Ptr32<void> object=FIELD(self,void*,88);if(object)VCALL(object,void(*)(void*,int,Vec3*),56)(object,3,&position);}else{Ptr32<void> object=FIELD(self,void*,88);if(object&&VCALL(object,int(*)(void*),36)(object)){object=FIELD(self,void*,88);VCALL(object,void(*)(void*),24)(object);}}Ptr32<void> object=FIELD(self,void*,28);VCALL(object,void(*)(void*,Vec3*,int),76)(object,&FIELD(self,Vec3,32),0);return 0;}


