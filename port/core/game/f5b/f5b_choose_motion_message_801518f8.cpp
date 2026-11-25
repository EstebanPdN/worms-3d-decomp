#include "w3d_ptr.h"
#line 1 "f5b_choose_motion_message_801518f8.cpp"
// All names, types, layouts and roles are inferred. 
extern const float zero_803a1938[],distance_803a193c[],height_803a1940[];
struct Vec3{float x,y,z;Vec3(){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}Vec3 operator-(const Vec3&o)const{Vec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}float norm2()const{return x*x+y*y+z*z;}};
struct Owner{char gap[312];Vec3 position;char gap2[236];Vec3 previous;};
struct Message{unsigned short id,pad;Ptr32<void> value;};extern Ptr32<void> queue_804b1754;extern int name_804afc90;extern char value_8040db38[];extern "C" Ptr32<void> allocate_801613f0(Ptr32<void>,int);extern "C" unsigned int name_8015f5a0(Ptr32<int>,int);extern "C" int post_8016239c(Ptr32<void>);extern "C" void reset_8015286c(Ptr32<Owner>);extern "C" Ptr32<void> construct_80131b50(Ptr32<void>,int);
extern "C" void f5b_choose_motion_message_801518f8(Ptr32<Owner> s,Ptr32<Vec3> out){Vec3 delta=s->position-s->previous;float y=__builtin_fabsf(delta.y);delta.y=zero_803a1938[0];if(delta.norm2()<distance_803a193c[0]){if(y<height_803a1940[0]){reset_8015286c(s);post_8016239c(construct_80131b50(allocate_801613f0(queue_804b1754,12),5));}else{Ptr32<Message> m=(Ptr32<Message>)allocate_801613f0(queue_804b1754,8);m->id=name_8015f5a0(&name_804afc90,1);m->value=value_8040db38;post_8016239c(m);}}else *out=delta;}


