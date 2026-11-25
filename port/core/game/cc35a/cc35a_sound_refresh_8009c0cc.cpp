#include "w3d_ptr.h"
#line 1 "cc35a_sound_refresh_8009c0cc.cpp"

struct cc35a_Message_8009c0cc {unsigned short id,pad;Ptr32<void> vtable;};
struct cc35a_Actor_8009c0cc {char prefix[28];Ptr32<void> context;char gap[36];Ptr32<void> sound;char gap2[16];int active;char gap3[28];Ptr32<void> held;};
struct cc35a_Config_8009c0cc {char prefix[260];Ptr32<char> name;};
struct cc35a_Service_8009c0cc {char prefix[108];Ptr32<void> sound;};
extern "C" {extern Ptr32<void> cc35a_arena_804b1754;extern unsigned int cc35a_cache_804ae068[2];extern char cc35a_vtable_8040db38[];
extern Ptr32<cc35a_Service_8009c0cc> cc35a_service_804b1788;
Ptr32<void> cc35a_alloc_801613f0(Ptr32<void>,unsigned int);unsigned int cc35a_id_8015f5a0(Ptr32<void>,int);int cc35a_post_8016239c(Ptr32<void>);void cc35a_release_800e5bb8(Ptr32<void>);
Ptr32<void> cc35a_context_80341584(Ptr32<void>);Ptr32<cc35a_Config_8009c0cc> cc35a_config_801797b4(Ptr32<void>);Ptr32<char> cc35a_owner_8009c850(Ptr32<void>);
}
inline int cc35a_test_8009c0cc(Ptr32<void> p,int slot){return ((Ptr32<int (Ptr32<void>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)p)[slot])(p);}
inline void cc35a_call_8009c0cc(Ptr32<void> p,int slot){((Ptr32<void (Ptr32<void>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)p)[slot])(p);}
extern "C" int cc35a_sound_refresh_8009c0cc(Ptr32<cc35a_Actor_8009c0cc> self){
 Ptr32<cc35a_Message_8009c0cc> m=(Ptr32<cc35a_Message_8009c0cc>)cc35a_alloc_801613f0(cc35a_arena_804b1754,8);m->id=cc35a_id_8015f5a0(cc35a_cache_804ae068,1);m->vtable=cc35a_vtable_8040db38;cc35a_post_8016239c(m);
 if(self->held){cc35a_release_800e5bb8(self->held);self->held=0;}
 self->active=0; Ptr32<Ptr32<void>> soundSlot=&self->sound;
 if(*soundSlot && cc35a_test_8009c0cc(*soundSlot,9)){
  if(cc35a_test_8009c0cc(*soundSlot,10)){
   cc35a_call_8009c0cc(*soundSlot,6);
   if(*soundSlot)cc35a_call_8009c0cc(*soundSlot,4);
   *soundSlot=0;Ptr32<cc35a_Config_8009c0cc> config=cc35a_config_801797b4((Ptr32<void>)cc35a_context_80341584(self->context));
   if(*(Ptr32<unsigned short>)(config->name-4)==0)goto failed;
   Ptr32<char> owner=cc35a_owner_8009c850(self);Ptr32<void> service=cc35a_service_804b1788->sound;
   ((Ptr32<void (Ptr32<void>, Ptr32<const char>, Ptr32<Ptr32<void>>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)service)[23])(service,config->name,soundSlot);
   Ptr32<void> sound=*soundSlot;((Ptr32<void (Ptr32<void>, int, Ptr32<void>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)sound)[14])(sound,3,owner+80);
   cc35a_call_8009c0cc(*soundSlot,5);
  }
  return 1;
 }
 failed: return 0;
}


