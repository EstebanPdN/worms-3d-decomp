// Reference-ABI reconstruction of the original update sequence.
// Names, partial object layouts and dynamic table identities are inferred.
// Direct argument roles are witnessed at original call sites. The pause
// helper consumes no entry argument; its original body reads shared state.
// A non-paused call always returns zero after updating and optional display
// and trail work. No portable native-vtable or runtime claim is made.
struct Sol35b2Attached {void **table;};
struct Sol35b2Update {void **table;char unknown4[24];int sync;Sol35b2Attached *attached;char unknown36[160];int trail;};
struct Sol35b2UpdateConfig {char unknown[520];int enabled;};
extern "C" {
int sol35b2_paused_8006e71c();
void * sol35b2_sync_80341584(int);
Sol35b2UpdateConfig *sol35b2_config_801797b4(void *);
void sol35b2_accumulate_800e9528(Sol35b2Update *,int);
void sol35b2_forward_800e95e0(Sol35b2Update *,int);
void sol35b2_forward_800e962c(Sol35b2Update *,int);
void sol35b2_display_800e92fc(Sol35b2Update *);
void sol35b2_notify_800e8a88(Sol35b2Update *);
void sol35b2_trail_800e9d08(Sol35b2Update *);
}
extern "C" int sol35b2_update_800e8934(Sol35b2Update *s,int tick) {
 if(sol35b2_paused_8006e71c()) return 0;Sol35b2UpdateConfig *configuration=sol35b2_config_801797b4((void *)sol35b2_sync_80341584(s->sync));
 sol35b2_accumulate_800e9528(s,tick);
 sol35b2_forward_800e95e0(s,tick);
 sol35b2_forward_800e962c(s,tick);
 ((void (*)(Sol35b2Update *,int))s->table[10])(s,tick);
 Sol35b2Attached *attached=s->attached;
 ((void (*)(Sol35b2Attached *,int))attached->table[22])(attached,1);
 if(configuration->enabled) sol35b2_display_800e92fc(s);
 sol35b2_notify_800e8a88(s);
 if(s->trail!=-1) sol35b2_trail_800e9d08(s);
 return 0;
}
