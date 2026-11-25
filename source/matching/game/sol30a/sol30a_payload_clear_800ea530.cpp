// UNVERIFIED draft. Original-instruction mismatch remains; not ready for admission.
struct Sol30aInterface { void **table; };
struct Sol30aHandle_80126230 { ~Sol30aHandle_80126230(); };
extern "C" void *copy_802eee50(void *,const void *,unsigned,...);
struct Sol30aRange {
 unsigned char *begin,*end,*limit;
 void erase(unsigned char *first,unsigned char *last) {
  int distance=last-first;
  copy_802eee50(first,last,end-last);
  end-=distance;
 }
 void clear() { erase(begin,end); }
};
struct Sol30aPayload {
 unsigned char unknown0[20]; unsigned id;
 unsigned char unknown24[76]; Sol30aInterface *held;
 unsigned char unknown104[148]; Sol30aHandle_80126230 *first,*second;
 Sol30aRange items;
};
struct Sol30aProperty { const char *name; };
struct Sol30aMessage;
extern "C" void detach_800edbbc(Sol30aPayload *);
extern "C" int property_800fc43c(Sol30aProperty *,unsigned);
extern "C" Sol30aMessage *allocate_801613f0(void *,unsigned);
extern "C" unsigned message_id_8015f5a0(void *,int);
extern "C" Sol30aMessage *construct_801190b4(Sol30aMessage *,unsigned short,unsigned);
extern "C" void post_8016239c(Sol30aMessage *);
extern "C" const char name_8038b3dc[];
extern "C" void *pool_804b1754;
extern "C" unsigned cache_804aef28;
extern "C" void sol30a_payload_clear_800ea530(Sol30aPayload *self) {
 detach_800edbbc(self);
 unsigned id=self->id;
 Sol30aProperty property={name_8038b3dc};
 property_800fc43c(&property,id);
 Sol30aMessage *message=allocate_801613f0(pool_804b1754,12);
 post_8016239c(construct_801190b4(message,(unsigned short)message_id_8015f5a0(&cache_804aef28,1),id));
 delete self->first;
 self->first=0;
 delete self->second;
 self->second=0;
 self->items.clear();
 if(self->held)((void (*)(Sol30aInterface *))self->held->table[4])(self->held);
 self->held=0;
}
