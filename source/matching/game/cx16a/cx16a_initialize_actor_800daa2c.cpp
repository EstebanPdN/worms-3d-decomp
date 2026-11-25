// Observed actor layout; meanings of the cleared words remain inferred.
#define FIELD(p,T,o) (*(T*)((char*)(p)+(o)))
extern "C" int base_80161014(void*);
extern int vtable_8040fe40[];
extern const float zero_803897fc[];
extern "C" void *w3d_cx16a_initialize_actor_800daa2c(void*self){ base_80161014(self);
FIELD(self,void*,0)=vtable_8040fe40;FIELD(self,int,68)=1;FIELD(self,int,28)=0;FIELD(self,int,32)=0;FIELD(self,int,36)=0;FIELD(self,int,40)=0;FIELD(self,int,44)=0;FIELD(self,int,48)=0;FIELD(self,int,52)=0;FIELD(self,int,56)=0;FIELD(self,int,60)=0;FIELD(self,int,64)=0;FIELD(self,int,156)=0;FIELD(self,int,72)=0;FIELD(self,float,132)=zero_803897fc[0];FIELD(self,float,136)=zero_803897fc[0];FIELD(self,float,140)=zero_803897fc[0];FIELD(self,float,144)=zero_803897fc[0];FIELD(self,int,152)=0;FIELD(self,int,164)=-1;FIELD(self,int,148)=0;FIELD(self,int,160)=0;FIELD(self,int,76)=0;FIELD(self,int,80)=0;return self;}
