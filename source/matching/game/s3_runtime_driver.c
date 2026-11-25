/* Runtime integration: observed interface slots and owner fields. */
typedef struct Interface Interface;
typedef void (*Method)(void *);
struct Interface { Method *vtable; };
typedef struct Driver {
 Method *vtable;
 unsigned char pad04[0x1c];
 int width, height;
 unsigned int flags;
 unsigned char byte2c, pad2d[3];
 Interface *view;
 unsigned char pad34[8];
 int elapsed;
 float rate;
 Interface *service;
 int word48;
 unsigned int state;
 int quantum, remainder;
} Driver;
typedef struct Vec3 {float x,y,z;} Vec3;
typedef struct ViewConfig {float a,b,c,d,e,f;int flags;} ViewConfig;
typedef struct ServiceConfig {int a,b,c,d,e,f;unsigned int g,h;} ServiceConfig;
extern Interface *w3d_lookup_8020b680(void *);
extern unsigned char w3d_object_804138c0[], w3d_object_80411238[], w3d_object_80455170[];
extern const float w3d_f32_803a42e4[],w3d_f32_803a42e8[],w3d_f32_803a42ec[],w3d_f32_803a42f0[],w3d_f32_803a42f4[];
extern const float w3d_f32_803a42f8[],w3d_f32_803a42fc[],w3d_f32_803a4300[],w3d_f32_803a4304[],w3d_f32_803a4308[];
extern void w3d_auto_8015ce28(void *);
extern void w3d_pump_8015ce60(void *);
extern int w3d_clock_801fe45c(void);
extern unsigned long long w3d_clock_801fe4d8(void);
extern int w3d_duration_801fe508(unsigned int);
extern volatile int w3d_tick_804b0054;
#if 0 /* Vector temporary placement and floating-register scheduling differ after three attempts. */
void w3d_runtime_create_view(Driver *owner)
{
 Vec3 vector; ViewConfig config;
 float zero,one;
 Interface *view=w3d_lookup_8020b680(w3d_object_804138c0);
 if(view) view->vtable[3](view);
 if(owner->view) owner->view->vtable[4](owner->view);
 owner->view=view;
 vector.x=*w3d_f32_803a42e4;vector.y=*w3d_f32_803a42e8;vector.z=*w3d_f32_803a42ec;
 ((void (*)(void *,void *))view->vtable[11])(view,&vector);
 view=owner->view;zero=*w3d_f32_803a42f0;
 vector.x=zero;vector.y=zero;vector.z=zero;
 ((void (*)(void *,void *))view->vtable[12])(view,&vector);
 view=owner->view;one=*w3d_f32_803a42f4;
 vector.x=zero;vector.z=zero;vector.y=one;
 ((void (*)(void *,void *))view->vtable[13])(view,&vector);
 config.flags=0;config.f=*w3d_f32_803a42f8;config.e=one;
 config.a=*w3d_f32_803a42fc;config.c=*w3d_f32_803a4300;
 config.b=*w3d_f32_803a4304;config.d=*w3d_f32_803a4308;
 view=owner->view;((void (*)(void *,void *))view->vtable[10])(view,&config);
}
#endif
void w3d_runtime_create_service(Driver *owner)
{
 ServiceConfig config;
 unsigned int flags;unsigned char b2a,b2b,b2c,b29;int a,b;
 Interface *service=w3d_lookup_8020b680(w3d_object_80411238);
 if(service) service->vtable[3](service);
 if(owner->service) owner->service->vtable[4](owner->service);
 flags=owner->flags;b2a=((unsigned char*)&owner->flags)[2];a=owner->width;b=owner->height;
 b2b=((unsigned char*)&owner->flags)[3];b2c=owner->byte2c;b29=((unsigned char*)&owner->flags)[1];
 config.h=(flags>>29)&1;config.g=flags>>31;config.a=a;config.b=b;config.c=b2b;config.d=b2c;config.e=b29;config.f=b2a;
 owner->service=service;
 ((void (*)(void *,void *))service->vtable[14])(service,&config);
}
void w3d_runtime_release_service(Driver *owner)
{
 Interface *service=owner->service;
 service->vtable[7](service);
 if(owner->service) owner->service->vtable[4](owner->service);
 owner->service=0;
}
void w3d_runtime_service_toggle(Driver *owner,int enabled)
{
 Interface *service=owner->service;((void (*)(void *,int))service->vtable[8])(service,enabled);
}
#if 0 /* Clock variable allocation and store scheduling differ after three attempts. */
void w3d_runtime_run(Driver *owner)
{
 int now,previous;
 owner->vtable[15](owner);
 w3d_auto_8015ce28(w3d_object_80455170);
 w3d_tick_804b0054=w3d_clock_801fe45c();
 do {
 now=w3d_clock_801fe45c();previous=w3d_tick_804b0054;w3d_tick_804b0054=now;
 ((void (*)(void *,int))owner->vtable[16])(owner,now-previous);
 w3d_pump_8015ce60(w3d_object_80455170);
 } while ((int)owner->state<0);
}
#endif
#if 0 /* Bitfield instructions and timestamp temporary layout differ after three attempts. */
void w3d_runtime_advance(Driver *owner,unsigned int delta)
{
 union {unsigned long long ticks;unsigned int words[2];} start;
 int step,total,rounded;unsigned int state;
 Interface *service;
 if(delta>100)delta=100;
 step=(int)((float)delta*owner->rate);
 state=owner->state;
 if(state&0x04000000){
 total=step;
 if(state&0x02000000)total=step+owner->remainder;
 rounded=total/owner->quantum*owner->quantum;
 if(rounded<owner->quantum){owner->remainder=0;step=owner->quantum;}
 else {step=rounded;owner->remainder=total-rounded;}
 }
 state=owner->state;
 if(!(state&0x40000000)){
 service=owner->service;
 *(unsigned int*)((char*)service+0xa4)=(*(unsigned int*)((char*)service+0xa4)&~0x40000000)|((state&0x20000000)<<1);
 *(unsigned int*)((char*)service+0xa4)=(*(unsigned int*)((char*)service+0xa4)&~0x80000000)|((owner->state&0x10000000)<<3);
 service=owner->service;((void (*)(void *,int))service->vtable[10])(service,step);
 }else if(state&0x08000000){service=owner->service;service->vtable[11](service);}
 if(owner->state&0x10000000){
 start.ticks=w3d_clock_801fe4d8();
 ((void (*)(void *,int))owner->vtable[17])(owner,step);
 owner->elapsed=w3d_duration_801fe508((unsigned int)w3d_clock_801fe4d8()-start.words[1]);
 owner->vtable[14](owner);
 if(owner->flags&0x40000000){w3d_runtime_service_toggle(owner,(owner->flags>>31)^1);owner->flags&=~0x40000000;}
 }
}
#endif
int w3d_runtime_handle_message(Driver *owner,unsigned short *message)
{
 switch(*message){
 case 0x100:case 0x200:owner->state&=0x7fffffff;return 0;
 case 0x201:owner->flags|=0x40000000;
 }
 return 1;
}
void w3d_runtime_service_finish(Driver *owner)
{
 Interface *service=owner->service;service->vtable[9](service);
}
