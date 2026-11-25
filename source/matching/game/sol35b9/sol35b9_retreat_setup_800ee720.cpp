// Reconstructed from original GWMP8P rev0 operands. Complete class names,
// service and callback return types remain inferred. Native GC32 ABI only.
// Service lookup completes before the mutable registry pointer is read.
// The disabled task branch stores its observed zero configuration value.
// The property reader must initialize time, unless config+400 overrides it;
// otherwise reading that local is outside this source's defined-input contract.
// Native allocation/registration/message ownership and external effects remain
// obligations. No portable, runtime, whole-source or hardware claim.
// Inferred native GC32 views, based on original operand offsets.
namespace sol35b9_retreat_setup {
struct Owner {char u0[20];unsigned handle;char u24[4];void*sync;char u32[20];int state;};
struct Config {char u0[400];int time;char u404[60];int task464;char u468[16];int task484;char u488[12];int target500,notify504;char u508[4];int mode512;char u516[20];int task536;};
struct Message {unsigned short id;unsigned short u2;void*type;};
struct Cache {unsigned words[2];};
struct Key {const char*text;};
extern "C" {
void* sol35b9_retreat_sync_80341584(void*);
Config* sol35b9_retreat_config_801797b4(void*);
Message* sol35b9_retreat_allocate_801613f0(void*,unsigned);
unsigned sol35b9_retreat_id_8015f5a0(Cache*,int);
Message* sol35b9_retreat_construct_801190b4(Message*,unsigned short,unsigned);
int sol35b9_retreat_post_8016239c(Message*);
void* sol35b9_retreat_service_8020b680(void*);
int sol35b9_retreat_register_80164514(void*,void*,unsigned);
int sol35b9_retreat_read_800fc1f0(const Key*,int*);
int sol35b9_retreat_write_800fc3b0(const Key*,int);
extern void* sol35b9_retreat_arena_804b1754;
extern void* sol35b9_retreat_registry_804b178c;
extern Cache sol35b9_retreat_cache_804aef8c,sol35b9_retreat_cache_804aef94,sol35b9_retreat_cache_804aef9c,sol35b9_retreat_cache_804aefa4;
extern char sol35b9_retreat_type_8040db38[],sol35b9_retreat_task_8040def8[],sol35b9_retreat_task_8040df38[],sol35b9_retreat_task_80410318[];
extern const char sol35b9_retreat_text_8038bd7c[],sol35b9_retreat_text_8038bd90[];
}
extern "C" void sol35b9_retreat_setup_800ee720(Owner*s){
 Config*c=sol35b9_retreat_config_801797b4(sol35b9_retreat_sync_80341584(s->sync));
 if(c->notify504){
  Message*m=sol35b9_retreat_allocate_801613f0(sol35b9_retreat_arena_804b1754,8);
  m->id=sol35b9_retreat_id_8015f5a0(&sol35b9_retreat_cache_804aef8c,1);m->type=sol35b9_retreat_type_8040db38;sol35b9_retreat_post_8016239c(m);
  if(!c->mode512){
   Message*m=sol35b9_retreat_allocate_801613f0(sol35b9_retreat_arena_804b1754,12);
   sol35b9_retreat_post_8016239c(sol35b9_retreat_construct_801190b4(m,sol35b9_retreat_id_8015f5a0(&sol35b9_retreat_cache_804aef94,1),s->handle));
  }
 }
 if(c->task536){void*task=sol35b9_retreat_service_8020b680(sol35b9_retreat_task_8040def8);sol35b9_retreat_register_80164514(sol35b9_retreat_registry_804b178c,task,s->handle);}
 if(c->task484){void*task=sol35b9_retreat_service_8020b680(sol35b9_retreat_task_8040df38);sol35b9_retreat_register_80164514(sol35b9_retreat_registry_804b178c,task,s->handle);}
 if(c->mode512){
  s->state=1;
  if(c->target500){
   Message*m=sol35b9_retreat_allocate_801613f0(sol35b9_retreat_arena_804b1754,12);
   sol35b9_retreat_post_8016239c(sol35b9_retreat_construct_801190b4(m,sol35b9_retreat_id_8015f5a0(&sol35b9_retreat_cache_804aef9c,1),s->handle));
  }else{
   Message*m=sol35b9_retreat_allocate_801613f0(sol35b9_retreat_arena_804b1754,12);
   sol35b9_retreat_post_8016239c(sol35b9_retreat_construct_801190b4(m,sol35b9_retreat_id_8015f5a0(&sol35b9_retreat_cache_804aefa4,1),s->handle));
  }
 }else{
  if(c->task464){void*task=sol35b9_retreat_service_8020b680(sol35b9_retreat_task_80410318);sol35b9_retreat_register_80164514(sol35b9_retreat_registry_804b178c,task,s->handle);s->state=2;}else s->state=c->task464;
 }
 Key key={sol35b9_retreat_text_8038bd7c};int time;
 sol35b9_retreat_read_800fc1f0(&key,&time);
 if(c->time)time=c->time;
 Key output={sol35b9_retreat_text_8038bd90};sol35b9_retreat_write_800fc3b0(&output,time);
}
}

typedef char sol35b9_retreat_owner_size[(sizeof(sol35b9_retreat_setup::Owner)==56)?1:-1];
typedef char sol35b9_retreat_config_size[(sizeof(sol35b9_retreat_setup::Config)==540)?1:-1];
typedef char sol35b9_retreat_message_size[(sizeof(sol35b9_retreat_setup::Message)==8)?1:-1];
typedef char sol35b9_retreat_key_size[(sizeof(sol35b9_retreat_setup::Key)==4)?1:-1];
