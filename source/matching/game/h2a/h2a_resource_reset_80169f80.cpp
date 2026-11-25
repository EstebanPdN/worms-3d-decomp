// Partial external object views; only referenced, never instantiated locally.
struct InterfaceView { void **table; };
struct ResourceStateView {
 char unknown0[148]; InterfaceView *service;
 char unknown152[48]; unsigned word200,word204,unknown208; unsigned char byte212; char unknown213[7];unsigned char byte220;char unknown221[3];unsigned word224;void *buffer;unsigned capacity;
 char unknown236[48];unsigned word284,word288,word292;char unknown296[8];unsigned word304,word308;char unknown312[8];unsigned word320,word324,slots[8];
};
extern "C" {
void reset_8016a1e8(ResourceStateView*,unsigned);
InterfaceView *manager_8020b648();
extern unsigned char descriptor_80411a20[];
void *aligned_801fe2a8(unsigned,unsigned);
extern void *global_804b1884;
void finish_8016808c(void*);
inline InterfaceView *lookupService(unsigned char *descriptor) {
 InterfaceView *manager=manager_8020b648();
 return ((InterfaceView*(*)(InterfaceView*,unsigned char*))manager->table[23])(manager,descriptor);
}
int h2a_resource_reset_80169f80(ResourceStateView *s) {
 s->word320=0;s->word324=0;s->word304=0;s->word308=0;
 reset_8016a1e8(s,0);
 if(!s->service){
  InterfaceView *service=lookupService(descriptor_80411a20);
  if(service)((void(*)(InterfaceView*))service->table[3])(service);
  if(s->service)((void(*)(InterfaceView*))s->service->table[4])(s->service);
  s->service=service;
 }
 if(!s->buffer)s->buffer=aligned_801fe2a8(s->capacity,128);
 s->word224=0;s->word288=0;s->word292=0;s->word284=0;s->byte212=0;s->byte220=0;s->word200=0;s->word204=0;
 for(unsigned i=0;i<8;++i)s->slots[i]=0;
 finish_8016808c(global_804b1884);
 return 0;
}
}
