// Original allocation transition at 0x802167a0, GC32 ABI views.
struct Sol30bArenaFlags { unsigned flags; };
struct Sol30bArena { unsigned observed_prefix[9]; void *saved; unsigned saved_size; unsigned observed_44; Sol30bArenaFlags *state; };
struct Sol30bArenaDispatch { void *observed[6]; void *(*allocate)(Sol30bArena *,unsigned); };
struct Sol30bArenaHooks { void *observed[5]; void (*notify)(Sol30bArena *,int,void *,unsigned); };
extern Sol30bArenaDispatch *dispatch_804aba74;
extern Sol30bArenaHooks hooks_80400768[];
extern "C" void setup_80215c58(void *,unsigned,void *,unsigned);
extern "C" void *sol30b_allocate_arena_802167a0(Sol30bArena *self,unsigned requested,int allowed) {
 void *old=self->saved;
 unsigned old_size=self->saved_size;
 Sol30bArenaFlags *state=self->state;
 self->saved=0;self->saved_size=0;
 if(!requested || !allowed) return 0;
 if(state->flags&1) goto permitted;
 if(state->flags&8192) return 0;
 state->flags|=8192;
 permitted:;
 unsigned total=((requested+7)&~7u)+32;
 if(total<=15) total=16;
 self->state->flags|=16384;
 void *result=dispatch_804aba74->allocate(self,total);
 if(result) {
  result=(char *)result+16;
  setup_80215c58(result,requested,old,old_size);
  if((state->flags&2) && hooks_80400768[0].notify) {
   self->saved=old;self->saved_size=old_size;
   hooks_80400768[0].notify(self,0,result,requested);
  }
 }
 state->flags&=~8192u;
 return result;
}
