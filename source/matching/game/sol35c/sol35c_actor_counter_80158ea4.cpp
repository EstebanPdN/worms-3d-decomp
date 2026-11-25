#define SOL35C_FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
struct Sol35cHandle { unsigned value,type; Sol35cHandle():value(0),type(58280){} ~Sol35cHandle(); };
extern "C" void fn_80178474(void *,int);
inline Sol35cHandle::~Sol35cHandle(){fn_80178474(this,2);}
extern "C" void *fn_800fc710(int,void *);
struct Sol35cActorRange { int *begin,*end,*capacity; };
struct Sol35cActorGroups { unsigned char unknown[52]; Sol35cActorRange group[5]; };
extern "C" void sol35c_actor_counter_80158ea4(Sol35cActorGroups *self,unsigned group,int count) {
 Sol35cHandle handle;
 if(group>4)return;
 Sol35cActorRange *range=&self->group[group];
 for(int *p=range->begin;p!=range->end;++p){
  void *actor=fn_800fc710(*p,&handle);
  SOL35C_FIELD(actor,int,164)=(int)SOL35C_FIELD(actor,unsigned short,170)-SOL35C_FIELD(actor,int,164)-count;
 }
}
