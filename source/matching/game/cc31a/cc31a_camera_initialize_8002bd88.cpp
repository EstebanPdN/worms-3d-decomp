// Original 8002bd88. Observed camera fields, event subscriptions and arena-message lifetime.
struct cc31a_Record_8002bd88 {unsigned words[7];};
struct cc31a_Service_8002bd88;
struct cc31a_VTable_8002bd88 {char gap[36];cc31a_Record_8002bd88*(*read)(cc31a_Service_8002bd88*);};
struct cc31a_Service_8002bd88 {cc31a_VTable_8002bd88*vt;};
struct cc31a_Global_8002bd88 {char gap[48];cc31a_Service_8002bd88*first;char gap34[88];cc31a_Service_8002bd88*second;};
struct cc31a_Owner_8002bd88 {char gap[20];unsigned id;char gap18[40];unsigned slot40,slot44,slot48,slot4c,slot50,slot54;unsigned active,unknown,mode;cc31a_Record_8002bd88 first,second;};
struct cc31a_Message_8002bd88 {unsigned short id,unknown;void*type;};
extern void*cc31a_arena_804b1754;extern cc31a_Global_8002bd88*cc31a_global_804b1788;
extern char cc31a_type_8040db38[];
extern char cc31a_text_803725f4[],cc31a_text_8037260c[],cc31a_text_80372620[];
extern float cc31a_float_80372634[],cc31a_float_80372638[];
extern unsigned cc31a_cache_804acc78,cc31a_cache_804accb8,cc31a_cache_804acca8,cc31a_cache_804accb0,cc31a_cache_804acc80,cc31a_cache_804acc98,cc31a_cache_804acca0,cc31a_cache_804acc88;
struct cc31a_Event_8002bd88 {unsigned short id;};
extern "C" {
int cc31a_call_800fc230(char**,int*);unsigned cc31a_call_8015f5a0(unsigned*,int);int cc31a_call_80162024(void*,unsigned short*,unsigned*);int cc31a_call_800fc4c8(float,char**);void*cc31a_call_801613f0(void*,unsigned);int cc31a_call_8016239c(void*);void*cc31a_call_801190b4(void*,unsigned short,unsigned);void*cc31a_call_800c1620(void*,unsigned*);
void cc31a_camera_initialize_8002bd88(cc31a_Owner_8002bd88*self) {
 char*key=cc31a_text_803725f4;int mode;cc31a_call_800fc230(&key,&mode);self->active=0;self->mode=(mode==1);
 cc31a_Event_8002bd88 event0;event0.id=cc31a_call_8015f5a0(&cc31a_cache_804acc78,1);cc31a_call_80162024(self,&event0.id,&self->slot40);
 cc31a_Event_8002bd88 event1;event1.id=cc31a_call_8015f5a0(&cc31a_cache_804accb8,1);cc31a_call_80162024(self,&event1.id,&self->slot48);
 cc31a_Event_8002bd88 event2;event2.id=cc31a_call_8015f5a0(&cc31a_cache_804acca8,1);cc31a_call_80162024(self,&event2.id,&self->slot4c);
 cc31a_Event_8002bd88 event3;event3.id=cc31a_call_8015f5a0(&cc31a_cache_804accb0,1);cc31a_call_80162024(self,&event3.id,&self->slot50);
 cc31a_Event_8002bd88 event4;event4.id=cc31a_call_8015f5a0(&cc31a_cache_804acc80,1);cc31a_call_80162024(self,&event4.id,&self->slot54);
 char*minimum=cc31a_text_8037260c;cc31a_call_800fc4c8(*cc31a_float_80372634,&minimum);
 char*maximum=cc31a_text_80372620;cc31a_call_800fc4c8(*cc31a_float_80372638,&maximum);
 {cc31a_Message_8002bd88*m=(cc31a_Message_8002bd88*)cc31a_call_801613f0(cc31a_arena_804b1754,8);m->id=cc31a_call_8015f5a0(&cc31a_cache_804acc98,1);m->type=cc31a_type_8040db38;cc31a_call_8016239c(m);}
 void*target=cc31a_call_801613f0(cc31a_arena_804b1754,12);cc31a_call_8016239c(cc31a_call_801190b4(target,cc31a_call_8015f5a0(&cc31a_cache_804acca0,1),self->id));
 self->first=*cc31a_global_804b1788->first->vt->read(cc31a_global_804b1788->first);
 self->second=*cc31a_global_804b1788->second->vt->read(cc31a_global_804b1788->second);
 void*created=cc31a_call_801613f0(cc31a_arena_804b1754,12);unsigned id=self->id;cc31a_call_8016239c(cc31a_call_800c1620(created,&id));
 cc31a_Message_8002bd88*m=(cc31a_Message_8002bd88*)cc31a_call_801613f0(cc31a_arena_804b1754,8);m->id=cc31a_call_8015f5a0(&cc31a_cache_804acc88,1);m->type=cc31a_type_8040db38;cc31a_call_8016239c(m);
}}
