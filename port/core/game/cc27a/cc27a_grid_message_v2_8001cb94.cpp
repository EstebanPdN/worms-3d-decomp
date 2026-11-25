#include "w3d_ptr.h"
#line 1 "cc27a_grid_message_v2_8001cb94.cpp"
// Original message routing including native vector initialization at entry.
struct cc27a_VecCB94 {float x,y,z;cc27a_VecCB94(float f):x(f),y(f),z(f){} cc27a_VecCB94(const cc27a_VecCB94&v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}};
struct cc27a_MessageCB94 {unsigned short id;char unknown[6];float radius;cc27a_VecCB94 position;};
struct cc27a_CacheCB94 {unsigned int a,b;};
extern cc27a_CacheCB94 cc27a_cache_804ac93c,cc27a_cache_804ac944;
extern "C" int cc27a_base_8016293c(Ptr32<void>,Ptr32<cc27a_MessageCB94>);
extern "C" void cc27a_reset_8001ed98(Ptr32<void>);
extern "C" int cc27a_equal_8015f620(Ptr32<cc27a_CacheCB94>,unsigned int);
extern "C" void cc27a_update_8001d9ac(Ptr32<void>);
extern "C" void cc27a_rectangle_8001cc90(Ptr32<const cc27a_VecCB94>,float);
struct cc27a_BoundsCB94 {cc27a_VecCB94 first,second;cc27a_BoundsCB94():first(0.0f),second(100.0f){}};
extern "C" int cc27a_grid_message_v2_8001cb94(Ptr32<void> self,Ptr32<cc27a_MessageCB94> message){
 cc27a_BoundsCB94 bounds;
 unsigned int id=message->id;
 if(id==64){if(cc27a_base_8016293c(self,message)>=0)cc27a_reset_8001ed98(self);else return (int)0x80004005;}
 else if(cc27a_equal_8015f620(&cc27a_cache_804ac93c,id))cc27a_update_8001d9ac(self);
 else {if(!cc27a_equal_8015f620(&cc27a_cache_804ac944,id))return cc27a_base_8016293c(self,message);
 cc27a_VecCB94 position(message->position);cc27a_rectangle_8001cc90(&position,message->radius);}
 return 0;
}

