// PPC32 object words are four bytes. Offsets below are observed, semantic names inferred.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
extern "C" int base_8015fef0(void *);extern unsigned char vtable_804101b0[];
extern "C" void *w3d_cx13a_initialize_trail_800e7e20(void *self){
 base_8015fef0(self);FIELD(self,void *,0)=vtable_804101b0;
 FIELD(self,unsigned,32)=0;
 FIELD(self,unsigned,100)=0;
 FIELD(self,unsigned,104)=0;
 FIELD(self,unsigned,108)=0;
 FIELD(self,unsigned,112)=0;
 FIELD(self,unsigned,116)=0;
 FIELD(self,unsigned,120)=0;
 FIELD(self,unsigned,124)=0;
 FIELD(self,unsigned,128)=0;
 FIELD(self,unsigned,132)=0;
 FIELD(self,unsigned,136)=0;
 FIELD(self,unsigned,140)=0;
 FIELD(self,unsigned,144)=0;
 FIELD(self,unsigned,148)=0;
 FIELD(self,unsigned,152)=0;
 FIELD(self,unsigned,168)=0;
 FIELD(self,unsigned,172)=0;
 FIELD(self,unsigned,176)=0;
 FIELD(self,unsigned,180)=0;
 FIELD(self,unsigned,200)=0;
 FIELD(self,unsigned,204)=0;
 FIELD(self,unsigned,208)=0;
 FIELD(self,unsigned,28)=0;
 FIELD(self,unsigned,96)=0;
 FIELD(self,unsigned,160)=0;
 FIELD(self,unsigned,184)=-1;
 FIELD(self,unsigned,188)=-1;
 FIELD(self,unsigned,196)=-1;
 FIELD(self,unsigned,212)=0;
return self;}
