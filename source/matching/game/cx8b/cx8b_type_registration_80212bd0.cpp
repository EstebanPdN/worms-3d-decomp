
struct Cx8bRegistration {unsigned int unknown00;const char *name;int state;void (*callback)();int priority;void *base;};
extern "C" Cx8bRegistration descriptor_80463c34[];
extern "C" char name_803b3670[],base_80463308[];
extern "C" int fn_802110c4();
extern "C" void fn_80200af8(Cx8bRegistration *);

static inline void initializeDescriptor(Cx8bRegistration *descriptor,const char *name,void (*callback)(),void *base,int priority) {
 descriptor->name=name;descriptor->state=0;descriptor->callback=callback;descriptor->priority=priority;descriptor->base=base;
}
extern "C" void w3d_cx8b_type_registration_80212bd0(int initialize,int priority) {
 if(priority==0xffff && initialize) {
 Cx8bRegistration *descriptor=descriptor_80463c34;
 initializeDescriptor(descriptor,name_803b3670,(void (*)())fn_802110c4,base_80463308,-100);
 
 fn_80200af8(descriptor);
 }
}



