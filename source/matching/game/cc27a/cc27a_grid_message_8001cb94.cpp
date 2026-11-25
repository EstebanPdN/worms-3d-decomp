// Original message routing including native vector initialization at entry.
struct cc27a_VecCB94 {float x,y,z;cc27a_VecCB94(float f):x(f),y(f),z(f){} cc27a_VecCB94(const cc27a_VecCB94&v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}};
struct cc27a_MessageCB94 {unsigned short id;char unknown[6];float radius;cc27a_VecCB94 position;};
struct cc27a_CacheCB94 {unsigned int a,b;};
extern cc27a_CacheCB94 cc27a_cache_804ac93c,cc27a_cache_804ac944;
extern "C" int cc27a_base_8016293c(void*,cc27a_MessageCB94*);
extern "C" void cc27a_reset_8001ed98(void*);
extern "C" int cc27a_equal_8015f620(cc27a_CacheCB94*,unsigned int);
extern "C" void cc27a_update_8001d9ac(void*);
extern "C" void cc27a_rectangle_8001cc90(const cc27a_VecCB94*,float);
extern "C" int cc27a_grid_message_8001cb94(void*self,cc27a_MessageCB94*message){
 struct cc27a_BoundsCB94 {cc27a_VecCB94 first,second;cc27a_BoundsCB94():first(0.0f),second(100.0f){}} bounds;
 unsigned int id=message->id;
 if(id==64){if(cc27a_base_8016293c(self,message)>=0)cc27a_reset_8001ed98(self);else return (int)0x80004005;}
 else if(cc27a_equal_8015f620(&cc27a_cache_804ac93c,id))cc27a_update_8001d9ac(self);
 else {if(!cc27a_equal_8015f620(&cc27a_cache_804ac944,id))return cc27a_base_8016293c(self,message);
 cc27a_VecCB94 position(message->position);cc27a_rectangle_8001cc90(&position,message->radius);}
 return 0;
}