#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s3_actor_command_core.c"
/* Observed actor command state and message dispatch, round 2. */
typedef struct S3Vec { float x,y,z; } S3Vec;
typedef struct S3VecLocal { S3Vec value; int unused; } S3VecLocal;
typedef struct S3Actor {
 unsigned char pad00[300]; int command_enabled, command_active, command;
 S3Vec target; unsigned char pad144[332-324];
 unsigned int command_time, position_time; S3Vec previous;
 unsigned char pad160[560-352]; S3Vec position;
 unsigned char pad23c[584-572]; unsigned int entity;
 unsigned char pad24c[676-588]; S3Vec velocity;
 unsigned char pad2b0[716-688]; int airborne;
 unsigned char pad2d0[760-720]; int mode;
 unsigned char pad2fc[824-764]; unsigned int flags;
 unsigned char pad33c[1124-828]; Ptr32<void> owner_value;
 unsigned char pad468[1152-1128]; unsigned char motion[128];
 int entries[16]; Ptr32<int> begin; Ptr32<int> end;
} S3Actor;
typedef struct S3Message { unsigned short id,pad02; Ptr32<void> type; } S3Message;
typedef struct S3Cache { int id; Ptr32<const char> name; } S3Cache;
typedef struct S3Context { unsigned char pad00[52]; unsigned int time; } S3Context;
typedef struct S3Entity { unsigned char pad00[132]; int state; unsigned char pad88[164-136]; int active; unsigned char pada8[213-168]; unsigned char team; } S3Entity;
typedef struct S3Team { unsigned char pad00[52]; int command_enabled; int pad38; unsigned char alliance; } S3Team;
extern Ptr32<void> w3d_global_804b1754; extern Ptr32<void> w3d_global_804b1760;
extern int w3d_flag_804aaefc, w3d_flag_804aaef8;
extern S3Cache w3d_cache_804afdfc, w3d_cache_804afc90, w3d_cache_804afb40;
extern Ptr32<void> w3d_type_8040db38[];
extern short w3d_cached_message_id(Ptr32<S3Cache>,int);
extern Ptr32<S3Message> w3d_fn_801613f0(Ptr32<void>,int);
extern Ptr32<S3Message> w3d_fn_80131b50(Ptr32<S3Message>,int);
extern int w3d_message_post_current(Ptr32<S3Message>);
extern void w3d_actor_start_jump(Ptr32<S3Actor>), w3d_auto_8014fedc(Ptr32<S3Actor>);
extern void w3d_actor_reset_construction_words(Ptr32<S3Actor>);
extern void w3d_auto_80020b20(Ptr32<void>);
extern Ptr32<void> w3d_empty_803426b4(Ptr32<void>);
extern unsigned int w3d_auto_80178c48(Ptr32<void>);
extern Ptr32<S3Entity> w3d_fn_800fc6dc(unsigned int);
extern Ptr32<S3Team> w3d_fn_800fc7f8(unsigned int);
extern Ptr32<S3Context> w3d_engine_get_context(void);
static __inline__ void s3_post_empty(Ptr32<S3Cache> cache) {
 Ptr32<S3Message> m=w3d_fn_801613f0(w3d_global_804b1754,8);
 m->id=w3d_cached_message_id(cache,1); m->type=w3d_type_8040db38;
 w3d_message_post_current(m);
}

void w3d_actor_command_jump(Ptr32<S3Actor> self)
{
 int complete=0;
 if(self->mode!=2 && self->mode!=6) w3d_actor_start_jump(self);
 else switch(self->command) {
 case 8: w3d_auto_8014fedc(self); complete=1; break;
 case 9: w3d_auto_8014fedc(self); complete=1; w3d_actor_start_jump(self); w3d_auto_8014fedc(self); break;
 case 10: if(self->mode!=6) w3d_actor_start_jump(self); else {w3d_auto_8014fedc(self); complete=1;} break;
 }
 if(complete) {w3d_actor_reset_construction_words(self); w3d_message_post_current(w3d_fn_80131b50(w3d_fn_801613f0(w3d_global_804b1754,12),5));}
}

void w3d_actor_command_finish_flag(Ptr32<S3Actor> self) {
 if(w3d_flag_804aaefc) {
  w3d_flag_804aaef8=0; w3d_flag_804aaefc=0;
  s3_post_empty(&w3d_cache_804afdfc);
  w3d_actor_reset_construction_words(self);
  w3d_message_post_current(w3d_fn_80131b50(w3d_fn_801613f0(w3d_global_804b1754,12),17));
  w3d_auto_80020b20(w3d_global_804b1760);
 }
}

void w3d_actor_command_check_progress(Ptr32<S3Actor> self) {
 if(self->command_active) {
  if(self->command==2 && w3d_engine_get_context()->time-self->command_time>3000) s3_post_empty(&w3d_cache_804afc90);
  if(w3d_engine_get_context()->time-self->position_time>1000) {
   Ptr32<const unsigned int> b=(Ptr32<unsigned int>)&self->position;
   Ptr32<const unsigned int> a=(Ptr32<unsigned int>)&self->previous;
   int equal=0;
   if(a[0]==b[0] && a[1]==b[1] && a[2]==b[2]) equal=1;
   if(equal) {
    switch(self->command) {case 2: case 8: case 9: case 10: case 11: case 12: case 13: case 14: s3_post_empty(&w3d_cache_804afc90);}
   } else self->previous=self->position;
  }
 }
}

void w3d_actor_command_reset_owner(Ptr32<S3Actor> self,int notify) {
 w3d_actor_reset_construction_words(self);
 w3d_flag_804aaef8=0; w3d_flag_804aaefc=0;
 self->command_enabled=w3d_fn_800fc7f8(w3d_fn_800fc6dc(w3d_auto_80178c48(w3d_empty_803426b4(self->owner_value)))->team)->command_enabled;
 if(self->command_enabled) {if(notify) s3_post_empty(&w3d_cache_804afb40);}
 else w3d_engine_get_context();
}

extern Ptr32<S3Vec> w3d_fn_80152a80(Ptr32<S3Vec>,Ptr32<S3Actor>);
extern int w3d_motion_slope_allowed(Ptr32<S3Vec>), w3d_motion_owner_matches(Ptr32<S3Actor>);
extern const float w3d_f32_803a1b44[];
extern S3Cache w3d_cache_804afd18,w3d_cache_804afd20,w3d_cache_804afc70,w3d_cache_804afd58;
extern Ptr32<S3Message> w3d_message_int_init(Ptr32<S3Message>,unsigned short,int);
extern int w3d_get_800a830c(Ptr32<void>);
static __inline__ void s3_post_int(Ptr32<S3Cache> cache,int value) {
 Ptr32<S3Message> m=w3d_fn_801613f0(w3d_global_804b1754,12);
 w3d_message_post_current(w3d_message_int_init(m,w3d_cached_message_id(cache,1),value));
}
int w3d_actor_is_same_alliance(Ptr32<S3Actor>,unsigned int);

static __inline__ float s3_squared(Ptr32<const S3Vec> v) {return v->x*v->x+v->y*v->y+v->z*v->z;}
static __inline__ void s3_copy(Ptr32<S3Vec> a,Ptr32<const S3Vec> b) {*a=*b;}
int w3d_actor_probe_slope(Ptr32<S3Actor> self,Ptr32<S3Vec> out) {
 S3VecLocal local; int result; float length;
 w3d_fn_80152a80(&local.value,self);
 if(out) s3_copy(out,&local.value);
 length=s3_squared(&local.value);
 result=0;
 if(length!=w3d_f32_803a1b44[0]) result=w3d_motion_slope_allowed(&local.value)!=0;
 return result;
}

void w3d_actor_post_alliance_value(Ptr32<S3Actor> self,int value) {
 if(value>0) {
  if(w3d_actor_is_same_alliance(self,w3d_auto_80178c48(w3d_empty_803426b4(self->owner_value)))) s3_post_int(&w3d_cache_804afd18,value);
  else s3_post_int(&w3d_cache_804afd20,value);
 }
}

int w3d_actor_is_same_alliance(Ptr32<S3Actor> self,unsigned int other) {
 Ptr32<S3Entity> a; Ptr32<S3Entity> b;
 if(other==(unsigned int)-1) return 0;
 a=w3d_fn_800fc6dc(other); b=w3d_fn_800fc6dc(self->entity);
 if(a->team==b->team) return 1;
 { Ptr32<S3Team> team=w3d_fn_800fc7f8(a->team);
 return team->alliance==w3d_fn_800fc7f8(b->team)->alliance; }
}

#if 0 /* 0x801534e0: loop induction and instruction scheduling differ after four candidate revisions. */
void w3d_actor_remove_message_entity(S3Actor *self,void *message) {
 int value=w3d_get_800a830c(message);
 if(value!=self->entity && w3d_motion_owner_matches(self)) {
  int *base=self->entries; int i; int *read=base;
  i=0; do {
   int entry=*read++;
   if(entry==-1) break;
   if(entry==value) {
    int j;
    { S3Message *m=w3d_fn_801613f0(w3d_global_804b1754,12);
    unsigned short id=w3d_cached_message_id(&w3d_cache_804afc70,1);
    w3d_message_post_current(w3d_message_int_init(m,id,self->entity)); }
    for(j=i;j<=14;j++) base[j]=base[j+1];
    self->entries[15]=-1; break;
   }
  } while(++i<=15);
 }
}
#endif

int w3d_actor_has_list_entity(Ptr32<S3Actor> self,int value) {
 Ptr32<int> p; for(p=self->begin;p!=self->end;p++) if(*p==value) return 1;
 return 0;
}

void w3d_actor_post_owner_state_ten(Ptr32<S3Actor> self) {
 unsigned int owner=w3d_auto_80178c48(w3d_empty_803426b4(self->owner_value));
 if(owner<=15 && w3d_fn_800fc6dc(owner)->state==10) s3_post_empty(&w3d_cache_804afd58);
}

int w3d_actor_entity_has_positive_state(Ptr32<S3Actor> self) {
 if(self->entity>15) return 0;
 return w3d_fn_800fc6dc(self->entity)->active>0;
}

extern S3Cache w3d_cache_804afd70,w3d_cache_804afd68;
extern const char w3d_str_803a1be4[],w3d_str_803a1bec[];
extern int w3d_flag_804ab420;
extern Ptr32<S3Message> w3d_message_string_init(Ptr32<S3Message>,unsigned short,Ptr32<const char>);
static __inline__ void s3_post_string(Ptr32<S3Cache> cache,Ptr32<const char> value) {
 Ptr32<S3Message> m=w3d_fn_801613f0(w3d_global_804b1754,12);
 w3d_message_post_current(w3d_message_string_init(m,w3d_cached_message_id(cache,1),value));
}
typedef struct S3Flags { unsigned int other:30; unsigned int fire:1; unsigned int high:1; } S3Flags;
extern void w3d_fn_801418dc(Ptr32<void>,Ptr32<S3Vec>,Ptr32<S3Vec>,int);
extern S3Vec w3d_zero_8045e788[];

void w3d_actor_set_fire_mode(Ptr32<S3Actor> self,int value) {
 Ptr32<S3Flags> flags=(Ptr32<S3Flags>)&self->flags;
 int changed=1;
 if(value==flags->fire) changed=0;
 flags->fire=value;
 if(changed) {
  if(value) {
   { Ptr32<S3Message> m=w3d_fn_801613f0(w3d_global_804b1754,12);
 unsigned short id=w3d_cached_message_id(&w3d_cache_804afd70,1);
 w3d_message_post_current(w3d_message_string_init(m,id,w3d_str_803a1be4)); }
   { Ptr32<S3Message> m=w3d_fn_801613f0(w3d_global_804b1754,12);
 unsigned short id=w3d_cached_message_id(&w3d_cache_804afd68,1);
 w3d_message_post_current(w3d_message_string_init(m,id,w3d_str_803a1bec)); }
   w3d_flag_804ab420=1;
  } else {
   { Ptr32<S3Message> m=w3d_fn_801613f0(w3d_global_804b1754,12);
 unsigned short id=w3d_cached_message_id(&w3d_cache_804afd70,1);
 w3d_message_post_current(w3d_message_string_init(m,id,w3d_str_803a1bec)); }
   { Ptr32<S3Message> m=w3d_fn_801613f0(w3d_global_804b1754,12);
 unsigned short id=w3d_cached_message_id(&w3d_cache_804afd68,1);
 w3d_message_post_current(w3d_message_string_init(m,id,w3d_str_803a1be4)); }
   w3d_flag_804ab420=value;
  }
 }
}

int w3d_actor_mode_is_fourteen_to_eighteen(Ptr32<S3Actor> self) {
 switch(self->mode) {case 14:case 15:case 16:case 17:case 18: return 1; default:return 0;}
}

void w3d_actor_apply_motion_segment(Ptr32<S3Actor> self,Ptr32<S3Vec> a,Ptr32<S3Vec> b) {
 Ptr32<const unsigned int> x=(Ptr32<unsigned int>)a; Ptr32<const unsigned int> y=(Ptr32<unsigned int>)b;
 int equal;
 w3d_fn_801418dc(self->motion,a,b,w3d_motion_owner_matches(self));
 equal=0;
 if(x[0]==y[0] && x[1]==y[1] && x[2]==y[2]) equal=1;
 if(!equal) {self->airborne=1; self->velocity=w3d_zero_8045e788[0];}
}

}
