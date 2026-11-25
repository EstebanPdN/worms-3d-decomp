#include "w3d_ptr.h"
#line 1 "f6b_aim_delta_80151784.cpp"
// All types, names and roles are inferred from the original instructions.
struct Vec3{float x,y,z;Vec3(){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}Vec3 operator-(const Vec3&o)const{Vec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}};
struct Owner{char pad[6];unsigned short kind;char pad1[304];Vec3 target;char pad2[236];Vec3 position;int gap;float angle;};
extern const float zero_803a1920[],one_803a1924[],low_803a1928[],period_803a192c[],high_803a1930[],threshold_803a1934[];
extern "C" float atan_802e7e5c(float,float);extern "C" double fabs(double);extern "C" int mode_800154e0(unsigned short);
extern Ptr32<void> queue_804b1754;extern "C" void reset_8015286c(Ptr32<Owner>);extern "C" Ptr32<void> allocate_801613f0(Ptr32<void>,int); Ptr32<void> construct_80131b50(Ptr32<void>,int);extern "C" int post_8016239c(Ptr32<void>);
extern "C" void f6b_aim_delta_80151784(Ptr32<Owner> s,Ptr32<Vec3> out){Vec3 d=s->target-s->position;if(d.x==zero_803a1920[0]&&d.z==zero_803a1920[0])d.x=one_803a1924[0];float angle=atan_802e7e5c(d.x,d.z);float difference=angle-s->angle;while(difference<low_803a1928[0])difference+=period_803a192c[0];while(difference>high_803a1930[0])difference-=period_803a192c[0];difference=fabs(difference);bool close=difference<threshold_803a1934[0];if(close){reset_8015286c(s);post_8016239c(construct_80131b50(allocate_801613f0(queue_804b1754,12),11));}else{*out=d;if(!mode_800154e0(s->kind))s->angle=angle;}// Eight original frame bytes remain of unknown purpose.
}


