#include "w3d_ptr.h"
#line 1 "sol35b_motion_prepare_800ec5c8.cpp"
// Native layout views inferred from the original instructions.
// Entry 800ec5c8 forwards the configuration result in r3 to 800ec400;
// the other incoming arguments remain in r4..r7. No hidden first argument
// is dropped. Type and member meanings are provisional.
// Ignored callee returns are represented as void; 800ed9c8 must be void
// to retain the observed setup schedule. Address identities are link-checked.
struct Sol35bVec {float x,y,z;};
struct Sol35bConfig {char unknown[444];Sol35bVec impulse;};
struct Sol35bMotion {char unknown[192];int sync;};
struct Sol35bMessage {unsigned short identifier;unsigned short unknown;Ptr32<void> type;};
extern "C" {
Ptr32<void> sol35b_sync_80341584(int);
Ptr32<Sol35bConfig> sol35b_config_801797b4(Ptr32<void>);
void sol35b_prepare_800ec400(Ptr32<Sol35bConfig>,int,int,Ptr32<Sol35bVec>,int);
void sol35b_reset_800eb6e4(Ptr32<Sol35bMotion>);
void sol35b_apply_800ed9c8(Ptr32<Sol35bMotion>,int,Ptr32<Sol35bVec>);
Ptr32<Sol35bMessage> sol35b_allocate_801613f0(Ptr32<void>,int);
int sol35b_message_id_8015f5a0(Ptr32<void>,int);
void sol35b_publish_8015fc58(Ptr32<Sol35bMotion>,Ptr32<Sol35bMessage>);
void sol35b_speed_800ecf54(Ptr32<Sol35bMotion>,Ptr32<Sol35bVec>);
}
extern const float sol35b_threshold_8038b564[];
extern char sol35b_type_8040db38[];
extern int sol35b_cached_id_804aef10;
extern Ptr32<void> sol35b_arena_804b1754;
extern "C" void sol35b_motion_prepare_800ec5c8(Ptr32<Sol35bMotion> s,int a,int b,Ptr32<Sol35bVec> v,int c) {Ptr32<Sol35bConfig> config=sol35b_config_801797b4((Ptr32<void>)sol35b_sync_80341584(s->sync));
 sol35b_prepare_800ec400(config,a,b,v,c);
 if(v->z*v->z+(v->x*v->x+v->y*v->y)>sol35b_threshold_8038b564[0]) {
  sol35b_reset_800eb6e4(s);
  sol35b_apply_800ed9c8(s,0,&config->impulse);
  Ptr32<Sol35bMessage> m=sol35b_allocate_801613f0(sol35b_arena_804b1754,8);
  m->identifier=sol35b_message_id_8015f5a0(&sol35b_cached_id_804aef10,1);
  m->type=sol35b_type_8040db38;
  sol35b_publish_8015fc58(s,m);
 }
 sol35b_speed_800ecf54(s,v);
}


