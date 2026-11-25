
// Original 800c6698: movie start state with failure notification.
// All object views are partial and field names inferred from observed use.
struct cc36a_Player;
struct cc36a_PlayerTable {void* unknown[3];int (*ready)(cc36a_Player*);void (*stop)(cc36a_Player*);int (*open)(cc36a_Player*,const char*);void* unknown18;int (*start)(cc36a_Player*,int);};
struct cc36a_Player {cc36a_PlayerTable* vtable;};
struct cc36a_Movie {unsigned char unknown[64];cc36a_Player* player;int state;};
union cc36a_Flags {unsigned int value;struct {unsigned int reserved0:1;unsigned int movie:1;unsigned int reserved2:2;unsigned int paused:1;unsigned int reserved5:27;} bits;};
struct cc36a_System {unsigned char prefix[76];cc36a_Flags flags;unsigned char gap50[108];unsigned int options;};
struct cc36a_Message {unsigned short key;unsigned short reserved;void* type;};
extern cc36a_System* cc36a_system_804b1788;
extern void* cc36a_service_804b1754;
extern unsigned int cc36a_cache_804ae7e4[2];
extern unsigned char cc36a_type_8040db38[];
extern "C" const char* cc36a_choose_800c61d8(cc36a_Movie*,int);
extern "C" cc36a_Message* cc36a_allocate_801613f0(void*,unsigned int);
extern "C" unsigned short cc36a_key_8015f5a0(void*,int);
extern "C" int cc36a_post_8016239c(cc36a_Message*);
inline int cc36a_notify(){cc36a_Message* message=cc36a_allocate_801613f0(cc36a_service_804b1754,8);message->key=cc36a_key_8015f5a0(cc36a_cache_804ae7e4,1);message->type=cc36a_type_8040db38;cc36a_post_8016239c(message);return 0;}
extern "C" int cc36a_movie_start_800c6698(cc36a_Movie* self,int kind){
 cc36a_System* system=cc36a_system_804b1788;
 unsigned int options=system->options;
 system->flags.bits.movie=1;system->flags.bits.paused=1;
 if(!(options&64)){system->flags.bits.movie=0;system->flags.bits.paused=0;return cc36a_notify();}
 else {
  if(!self->player)goto result;
  if(self->state==1)return 1;
  if(self->player->vtable->ready(self->player)){
   const char* path=cc36a_choose_800c61d8(self,kind);
   if(self->player->vtable->open(self->player,path) && self->player->vtable->start(self->player,0))goto success;
   self->player->vtable->stop(self->player);
  }
  cc36a_system_804b1788->flags.bits.movie=0;cc36a_system_804b1788->flags.bits.paused=0;
  return cc36a_notify();
 }
 success:self->state=1;
 result:return self->state;
}
