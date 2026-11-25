#include "w3d_ptr.h"
#line 1 "sol35b10_retreat_finish_800ee934.cpp"
// Original GWMP8P rev0 operand reconstruction. Native GC32 partial layouts;
// names and complete classes/APIs remain inferred. The integer property
// reader must initialize index before use; no fabricated default is supplied.
// Message allocations, callbacks and registry lifetime/effects are external.
// Live valid storage and native wrapping unsigned delay arithmetic required.
namespace sol35b10_finish {
struct Owner {char h[20];unsigned handle;char a[4];Ptr32<void> sync;char b[24];unsigned count;};
struct Config {char h[56];unsigned delay;char a[404];int task;char b[16];int multiple;};
struct Worm {char h[104];unsigned count;};
struct Message {unsigned short id;unsigned short unobserved;Ptr32<void> type;};
struct Key {Ptr32<const char> text;}; struct Cache {unsigned words[2];};
struct Context {char h[52];unsigned stamp;};
extern "C" {
Ptr32<void> fn_80341584(Ptr32<void>); Ptr32<Config> fn_801797b4(Ptr32<void>);
int fn_80164cec(Ptr32<void>,unsigned);
int fn_800fc1f0(Ptr32<const Key>,Ptr32<unsigned int>);Ptr32<Worm> fn_800fc6dc(unsigned);
Ptr32<Message> fn_801613f0(Ptr32<void>,unsigned);unsigned fn_8015f5a0(Ptr32<Cache>,int);
int fn_8016239c(Ptr32<Message>);Ptr32<Context> fn_80165254();int fn_800c53a0(Ptr32<Message>,unsigned);
extern Ptr32<void> lbl_804b178c;extern Ptr32<void> lbl_804b1754;
extern Cache lbl_804aefcc,lbl_804aef74,lbl_804aefe4,lbl_804aefdc,lbl_804aefac;
extern char lbl_8040db38[];extern const char lbl_8038bd9c[];
}
}
extern "C" void sol35b10_retreat_finish_800ee934(Ptr32<sol35b10_finish::Owner> self) {
 using namespace sol35b10_finish;
 Ptr32<Config> config=fn_801797b4(fn_80341584(self->sync));
 fn_80164cec(lbl_804b178c,self->handle);
 if (config->multiple) {Key key={lbl_8038bd9c};unsigned index;fn_800fc1f0(&key,&index);self->count=fn_800fc6dc(index)->count;}
 else self->count=1;
 for(unsigned i=0;i<self->count;++i){Ptr32<Message> m=fn_801613f0(lbl_804b1754,8);m->id=fn_8015f5a0(&lbl_804aefcc,1);m->type=lbl_8040db38;fn_8016239c(m);}
 Ptr32<Message> m=fn_801613f0(lbl_804b1754,8);m->id=fn_8015f5a0(&lbl_804aef74,1);m->type=lbl_8040db38;fn_8016239c(m);
 if(!config->task){Ptr32<Message> m=fn_801613f0(lbl_804b1754,8);m->id=fn_8015f5a0(&lbl_804aefe4,1);m->type=lbl_8040db38;fn_8016239c(m);}
 m=fn_801613f0(lbl_804b1754,8);m->id=fn_8015f5a0(&lbl_804aefdc,1);m->type=lbl_8040db38;fn_8016239c(m);
 m=fn_801613f0(lbl_804b1754,8);m->id=fn_8015f5a0(&lbl_804aefac,1);m->type=lbl_8040db38;fn_800c53a0(m,fn_80165254()->stamp+config->delay);
}

typedef char sol35b10_finish_owner_size[(sizeof(sol35b10_finish::Owner)==60)?1:-1];
typedef char sol35b10_finish_config_size[(sizeof(sol35b10_finish::Config)==488)?1:-1];
typedef char sol35b10_finish_worm_size[(sizeof(sol35b10_finish::Worm)==108)?1:-1];
typedef char sol35b10_finish_message_size[(sizeof(sol35b10_finish::Message)==8)?1:-1];
typedef char sol35b10_finish_key_size[(sizeof(sol35b10_finish::Key)==4)?1:-1];
typedef char sol35b10_finish_cache_size[(sizeof(sol35b10_finish::Cache)==8)?1:-1];
typedef char sol35b10_finish_context_size[(sizeof(sol35b10_finish::Context)==56)?1:-1];


