#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s3_team_turns.c"
/* Team and worm turn selection. Layouts record observed offsets. */
typedef struct S3List { Ptr32<int> begin; Ptr32<int> end; Ptr32<int> capacity; } S3List;
typedef struct S3Turns {
 unsigned char pad00[20]; int owner; unsigned char pad18[48-24]; Ptr32<void> active_value;
 S3List worms[4],alliances[4]; int current[4],unused[4],counts[4],worm_count;
 unsigned char padc8[296-200]; Ptr32<void> selected_worm; int pad12c; Ptr32<void> selected_team; Ptr32<void> first_team;
 int actors[16],mode_a,mode_b,alliance_mode;
} S3Turns;
typedef struct S3Entity { unsigned char pad00[188]; int eligible; unsigned char padc0[213-192]; unsigned char team; unsigned char padd6[220-214]; int state; } S3Entity;
typedef struct S3Team { unsigned char pad00[44]; int excluded; unsigned char pad30[60-48]; unsigned char alliance; } S3Team;
typedef struct S3Handle { int object; unsigned int tag; } S3Handle;
typedef struct S3Cache {int id;Ptr32<const char> name;} S3Cache;
typedef struct S3Message {unsigned short id,pad02;Ptr32<void> type;} S3Message;
typedef struct S3Actor {unsigned char pad00[584];unsigned int entity;} S3Actor;
extern Ptr32<S3Entity> w3d_fn_800fc6dc(unsigned int);
extern Ptr32<S3Team> w3d_fn_800fc7f8(unsigned int); extern Ptr32<S3Team> w3d_fn_800fc82c(unsigned int,Ptr32<S3Handle>);
extern int w3d_fn_800fc1f0(Ptr32<Ptr32<const char>>,Ptr32<int>);
extern int w3d_fn_800fc43c(Ptr32<Ptr32<const char>>,int);
extern const char w3d_str_803a27ac[],w3d_str_803a2a14[],w3d_str_803a2a20[],w3d_str_803a2a6c[];
extern void w3d_fn_80178474(Ptr32<S3Handle>,int);
extern int w3d_fn_8015668c(Ptr32<S3Turns>,int),w3d_fn_801558dc(Ptr32<S3Turns>,int);
extern Ptr32<void> w3d_empty_803426b4(Ptr32<void>);
extern void w3d_fn_80178c54(Ptr32<void>,Ptr32<int>);
extern Ptr32<S3Message> w3d_fn_801613f0(Ptr32<void>,int);
extern short w3d_cached_message_id(Ptr32<S3Cache>,int);
extern Ptr32<void> w3d_global_804b1754; extern Ptr32<void> w3d_type_8040db38[];
extern S3Cache w3d_cache_804afe70;
extern void w3d_auto_8015fc58(Ptr32<S3Turns>,Ptr32<S3Message>),w3d_empty_8015884c(Ptr32<S3Turns>);
extern Ptr32<void> w3d_factory_80410ef0[]; extern Ptr32<void> w3d_global_804b178c;
extern Ptr32<S3Actor> w3d_fn_8020b680(Ptr32<void>);
extern int w3d_fn_80164514(Ptr32<void>,Ptr32<S3Actor>,int);
extern Ptr32<void> memcpy(Ptr32<void>,Ptr32<const void>,...);
void w3d_turns_remove_team(Ptr32<S3Turns>,int);
int w3d_turns_team_has_eligible(Ptr32<S3Turns>,unsigned int);

#if 0 /* 0x801554dc: stack-local placement differs after three revisions. */
void w3d_turns_exclude_active_team(S3Turns *self) {
 const char *key=w3d_str_803a27ac; int active; S3Handle handle;
 w3d_fn_800fc1f0(&key,&active);
 if(active!=-1) {
  int team=w3d_fn_800fc6dc(active)->team;
  handle.object=0; handle.tag=0xe3a8;
  w3d_fn_800fc82c(team,&handle)->excluded=1;
  w3d_turns_remove_team(self,team);
  w3d_fn_80178474(&handle,2);
 }
}
#endif

void w3d_turns_publish_team_worm_count(Ptr32<S3Turns> self,unsigned int team) {
 if(team<=4) {
  unsigned int i; int count=0; Ptr32<const char> key;
  for(i=0;i<=15;i++) {Ptr32<S3Entity> entity=w3d_fn_800fc6dc(i); if(entity->state==1 && entity->team==team) count++;}
  key=w3d_str_803a2a14; w3d_fn_800fc43c(&key,count);
 }
}

void w3d_turns_publish_worm_count(Ptr32<S3Turns> self) {
 unsigned int i; int count=0; Ptr32<const char> key;
 for(i=0;i<=15;i++) {
  if(w3d_fn_800fc6dc(i)->state==1 && w3d_fn_800fc7f8(w3d_fn_800fc6dc(i)->team)->excluded!=1) count++;
 }
 key=w3d_str_803a2a14; w3d_fn_800fc43c(&key,count); self->worm_count=count;
}

void w3d_turns_publish_team_count(Ptr32<S3Turns> self) {
 unsigned int i; int count=0; Ptr32<const char> key;
 for(i=0;i<4;i++) self->counts[i]=0;
 for(i=0;i<=15;i++) {
  Ptr32<S3Entity> entity=w3d_fn_800fc6dc(i);
  if(entity->state==1) {
   unsigned int team=entity->team;
   if(w3d_fn_800fc7f8(team)->excluded!=1) self->counts[team]++;
  }
 }
 for(i=0;i<4;i++) if(self->counts[i]) count++;
 key=w3d_str_803a2a20; w3d_fn_800fc43c(&key,count);
}

int w3d_turns_next_team(Ptr32<S3Turns> self,int team) {
 unsigned int i; int next;
 if(self->alliance_mode==1) return w3d_fn_8015668c(self,team);
 next=(team+1)%4;
 for(i=0;i<=3;i++) {
  if(self->counts[next] && w3d_fn_800fc7f8(next)->excluded!=1 && w3d_turns_team_has_eligible(self,next)==1) return next;
  next=(next+1)%4;
 }
 return -1;
}

int w3d_turns_team_has_eligible(Ptr32<S3Turns> self,unsigned int team) {
 unsigned int i; int count;
 if(team>4) return 0;
 count=0;
 for(i=0;i<=15;i++) {Ptr32<S3Entity> entity=w3d_fn_800fc6dc(i); if(entity->state==1 && entity->eligible==1 && entity->team==team) count++;}
 return count!=0;
}

static __inline__ Ptr32<int> s3_list_begin(Ptr32<S3List> list) {return list->begin;}
static __inline__ Ptr32<int> s3_list_end(Ptr32<S3List> list) {return list->end;}
void w3d_turns_publish_alliance_count(Ptr32<S3Turns> self) {
 unsigned int i; int count=0; Ptr32<const char> key;
 for(i=0;i<4;i++) if(s3_list_begin(&self->alliances[i])!=s3_list_end(&self->alliances[i])) count++;
 key=w3d_str_803a2a6c; w3d_fn_800fc43c(&key,count);
}

#if 0 /* 0x80155ff0: indexed list access allocation differs after one revision. */
void w3d_turns_advance_active_worm(S3Turns *self) {
 const char *key=w3d_str_803a27ac; int active=0; unsigned int team;
 w3d_fn_800fc1f0(&key,&active);
 team=w3d_fn_800fc6dc(active)->team;
 if(self->worms[team].begin!=self->worms[team].end) {
  int selected;
  self->current[team]++;
  if(self->current[team]>=(unsigned int)(self->worms[team].end-self->worms[team].begin)) self->current[team]=0;
  selected=self->worms[team].begin[self->current[team]];
  if((unsigned int)selected<=16) w3d_fn_80178c54(w3d_empty_803426b4(self->selected_worm),&selected);
  w3d_fn_801558dc(self,team);
 }
}
#endif

#if 0 /* 0x801560d8: handle temporary lifetime and loop layout differ after two revisions. */
void w3d_turns_set_first_team(S3Turns *self) {
 struct {S3Handle handle; int value;} local; int selected=0; unsigned int i;
 i=0; do {
  S3Entity *entity=w3d_fn_800fc6dc(i); S3Team *team;
  local.handle.object=0;local.handle.tag=0xe3a8;
  team=w3d_fn_800fc7f8(entity->team);
  if(entity->state==1 && team->excluded==0) {selected=entity->team; w3d_fn_80178474(&local.handle,2); break;}
  w3d_fn_80178474(&local.handle,2);
 } while(++i<=15);
 {void *target=w3d_empty_803426b4(self->first_team);local.value=selected;w3d_fn_80178c54(target,&local.value);}
}
#endif

static __inline__ Ptr32<S3Message> s3_init_empty(Ptr32<S3Message> message,unsigned short id) {message->id=id;message->type=w3d_type_8040db38;return message;}
#if 0 /* 0x80156190: two argument setup instructions differ after two revisions. */
void w3d_turns_reset_actor_slots(S3Turns *self) {
 unsigned int i;
 S3Message *message=w3d_fn_801613f0(w3d_global_804b1754,8);
 w3d_auto_8015fc58(self,s3_init_empty(message,w3d_cached_message_id(&w3d_cache_804afe70,1))); w3d_empty_8015884c(self);
 for(i=0;i<16;i++) self->actors[i]=-1;
}
#endif

#if 0 /* 0x801565e4: list iteration and erase instruction allocation differ after three revisions. */
void w3d_turns_remove_team(S3Turns *self,int team) {
 if(self->alliance_mode) {
  unsigned int i; S3List *list=self->alliances;
  for(i=0;i<4;i++,list++) {
   int *p; for(p=list->begin;p!=list->end;p++) {
    if(*p==team) {
     int *next=p+1;
     if(next!=list->end) memcpy(p,next,((unsigned int)list->end-4)-(unsigned int)p);
     list->end--; return;
    }
   }
  }
 }
}
#endif

void w3d_turns_create_actor_for_entity(Ptr32<S3Turns> self,unsigned int entity) {
 Ptr32<S3Actor> actor;
 w3d_fn_800fc6dc(entity);
 actor=w3d_fn_8020b680(w3d_factory_80410ef0);
 actor->entity=entity;
 self->actors[entity]=w3d_fn_80164514(w3d_global_804b178c,actor,self->owner);
}

int w3d_turns_get_active_actor(Ptr32<S3Turns> self) {
 Ptr32<const char> key; unsigned int active=0;
 key=w3d_str_803a27ac; w3d_fn_800fc1f0(&key,(Ptr32<int>)&active);
 if(active<=16) return self->actors[active];
 return -1;
}

}
