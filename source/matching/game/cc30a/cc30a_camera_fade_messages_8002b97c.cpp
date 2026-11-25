// Original 8002b97c camera-mode and fade message dispatcher.
struct cc30a_Service_8002b97c;
struct cc30a_VTable_8002b97c {char gap[40];void(*remove)(cc30a_Service_8002b97c*,void*);};
struct cc30a_Service_8002b97c {cc30a_VTable_8002b97c*vt;};
struct cc30a_Global_8002b97c {char gap[48];cc30a_Service_8002b97c*service;char gap34[136];unsigned upper:29;unsigned active:1;unsigned lower:2;inline void set(unsigned value){active=value;}};
struct cc30a_Owner_8002b97c {char gap[88];int state;float fade;int enabled;char first[28];char second[28];};
extern cc30a_Global_8002b97c*cc30a_global_804b1788;
extern unsigned cc30a_cache_804acc78,cc30a_cache_804accb8,cc30a_cache_804acca8,cc30a_cache_804accb0,cc30a_cache_804acc80;
extern char cc30a_text_803725f4[];extern float cc30a_float_80372608[];
extern "C" {int cc30a_call_8002aa48(void*,void*);void cc30a_call_8002bd88(void*);void cc30a_call_8002c018(void*);int cc30a_call_8015f65c(unsigned short,unsigned*);int cc30a_call_800fc230(char**,int*);void cc30a_call_8002bc14(void*);int cc30a_call_800a830c(void*);void cc30a_call_8002c17c(void*);void cc30a_call_8002c118(void*);
int cc30a_camera_fade_messages_8002b97c(cc30a_Owner_8002b97c*self,unsigned short*msg){unsigned short id=*msg;
 switch(id){case 64:if(cc30a_call_8002aa48(self,msg)>=0){cc30a_call_8002bd88(self);goto handled;}return 0x80004005;
 case 66:cc30a_call_8002c018(self);break;
 default:
 if(cc30a_call_8015f65c(id,&cc30a_cache_804acc78)){
 char*key=cc30a_text_803725f4;int mode;cc30a_call_800fc230(&key,&mode);
 if(self->enabled){if(mode!=1){float zero=*cc30a_float_80372608;self->state=0;self->fade=zero;cc30a_global_804b1788->set(0);cc30a_global_804b1788->service->vt->remove(cc30a_global_804b1788->service,self->first);cc30a_global_804b1788->service->vt->remove(cc30a_global_804b1788->service,self->second);}}
 else if(mode==1)cc30a_call_8002bc14(self);
 self->enabled=(mode==1);
 }
 else if(cc30a_call_8015f65c(id,&cc30a_cache_804accb8)){if(!self->enabled)goto handled;if(self->state==1)self->state=0;}
 else if(cc30a_call_8015f65c(id,&cc30a_cache_804acca8)){if(!self->enabled)goto handled;if(!self->state)self->state=2;}
 else if(cc30a_call_8015f65c(id,&cc30a_cache_804accb0)){if(!self->enabled)goto handled;if(self->state==2)self->state=0;}
 else if(cc30a_call_8015f65c(id,&cc30a_cache_804acc80)){if(!self->enabled)goto handled;int count=cc30a_call_800a830c(msg)*2;if(count<0){count=-count;do{cc30a_call_8002c17c(self);}while(--count);}while(count>0){cc30a_call_8002c118(self);--count;}}
 }return cc30a_call_8002aa48(self,msg);handled:return 0;
}}
