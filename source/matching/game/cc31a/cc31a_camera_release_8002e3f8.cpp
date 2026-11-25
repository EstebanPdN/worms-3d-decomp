// Original 8002e3f8. Ordered message publication and handle release.
struct cc31a_Interface_8002e3f8;
struct cc31a_VTable_8002e3f8 {char gap[16];void(*release)(cc31a_Interface_8002e3f8*);};
struct cc31a_Interface_8002e3f8 {cc31a_VTable_8002e3f8*vt;};
struct cc31a_Service_8002e3f8;
struct cc31a_ServiceTable_8002e3f8 {char gap[100];void(*defer)(cc31a_Service_8002e3f8*,cc31a_Interface_8002e3f8**,int);};
struct cc31a_Service_8002e3f8 {cc31a_ServiceTable_8002e3f8*vt;};
struct cc31a_Global_8002e3f8 {char gap[108];cc31a_Service_8002e3f8*service;};
struct cc31a_Owner_8002e3f8 {char gap[80];int firstId,secondId;cc31a_Interface_8002e3f8*first,*second;void*owned;};
struct cc31a_Message_8002e3f8 {unsigned short id,unknown;void*type;};
extern void*cc31a_arena_804b1754;extern cc31a_Global_8002e3f8*cc31a_global_804b1788;extern unsigned cc31a_cache_804acd18,cc31a_cache_804acd20;extern char cc31a_type_8040db38[];
extern "C" {void*cc31a_call_801613f0(void*,unsigned);unsigned cc31a_call_8015f5a0(unsigned*,int);int cc31a_call_8016239c(void*);void*cc31a_call_80125fdc(void*,unsigned short,int);void cc31a_call_801265a4(void*,int);
inline void cc31a_clear_8002e3f8(cc31a_Interface_8002e3f8*&slot,cc31a_Interface_8002e3f8*replacement){if(slot)slot->vt->release(slot);slot=replacement;}
void cc31a_camera_release_8002e3f8(cc31a_Owner_8002e3f8*self) {
 {cc31a_Message_8002e3f8*m=(cc31a_Message_8002e3f8*)cc31a_call_801613f0(cc31a_arena_804b1754,8);m->id=cc31a_call_8015f5a0(&cc31a_cache_804acd18,1);m->type=cc31a_type_8040db38;cc31a_call_8016239c(m);}
 {void*m=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_80125fdc(m,cc31a_call_8015f5a0(&cc31a_cache_804acd20,1),self->firstId));}
 {void*m=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_80125fdc(m,cc31a_call_8015f5a0(&cc31a_cache_804acd20,1),self->secondId));}
 if(cc31a_global_804b1788->service) {cc31a_global_804b1788->service->vt->defer(cc31a_global_804b1788->service,&self->first,3000);cc31a_global_804b1788->service->vt->defer(cc31a_global_804b1788->service,&self->second,3000);}
 cc31a_clear_8002e3f8(self->first,0);
 cc31a_clear_8002e3f8(self->second,0);
 if(self->owned){cc31a_call_801265a4(self->owned,3);self->owned=0;}
}}
