// Reconstructed from original GWMP8P rev0 instructions. Names, complete class
// identities and partial views are inferred. GC32 reference ABI only.
// Ancestry stops at a self-parent; repeated virtual type calls remain separate.
// The empty sync accessor preserves its incoming pointer; config consumes it.
// Live owner/config/type/message storage and compatible external lifetimes are
// required. Signed deadline addition must remain representable in this C++.
// Cyclic ancestry without a self-parent can fail to terminate in the native code.
// No behavioral, portability or whole-game claim follows from linked equality.
namespace Sol35b6Arm {
struct Type {char unknown0[20];Type *base;};
struct Owner {void **table;char unknown4[28];int delay;char unknown36[48];int deadline,armed;char unknown92[8];void *effect;char unknown104[88];void *sync;};
struct Config {char unknown0[420];int delay;};
struct Message;
extern "C" {
void *sol35b6_sync_80341584(void *);
Config *sol35b6_config_801797b4(void *);
Message *sol35b6_allocate_801613f0(void *,unsigned);
unsigned sol35b6_id_8015f5a0(unsigned *,int);
Message *sol35b6_construct_80125fdc(Message *,unsigned short,int);
void sol35b6_publish_8015fc58(Owner *,Message *);
int sol35b6_log_80022e20(const char *,const char *,int,void **);
}
extern "C" {
extern void *sol35b6_arena_804b1754;
extern unsigned sol35b6_cache_804aef00;
extern Type sol35b6_type_80361860[],sol35b6_type_803618f0[];
extern char sol35b6_text_8038b4e4[],sol35b6_file_8038b4c4[];
}
inline bool derives(Type *type,Type *target){
 while(type!=target){if(type==type->base)return false;type=type->base;}
 return true;
}
inline Type *get_type(Owner *s){return ((Type *(*)(Owner *))s->table[5])(s);}
extern "C" void sol35b6_arm_800eb910(Owner *s,int now){
 s->armed=1;
 Config *cfg=sol35b6_config_801797b4(sol35b6_sync_80341584(s->sync));
 if(s->delay==-2)s->delay=cfg->delay;
 if(s->delay==-1)s->deadline=s->delay; else s->deadline=now+s->delay;
 Message *m=sol35b6_allocate_801613f0(sol35b6_arena_804b1754,12);
 sol35b6_publish_8015fc58(s,sol35b6_construct_80125fdc(m,(unsigned short)sol35b6_id_8015f5a0(&sol35b6_cache_804aef00,1),s->deadline));
 if(derives(get_type(s),sol35b6_type_80361860)||derives(get_type(s),sol35b6_type_803618f0))
  sol35b6_log_80022e20(sol35b6_text_8038b4e4,sol35b6_file_8038b4c4,503,&s->effect);
}
}

typedef char sol35b6_arm_type_size[(sizeof(Sol35b6Arm::Type)==24)?1:-1];
typedef char sol35b6_arm_owner_size[(sizeof(Sol35b6Arm::Owner)==196)?1:-1];
typedef char sol35b6_arm_config_size[(sizeof(Sol35b6Arm::Config)==424)?1:-1];
