/* Queries and messages associated with worm turn services. */
typedef struct S3List { int *begin,*end,*capacity; } S3List;
typedef struct S3Turns {
 unsigned char pad00[20]; int owner; unsigned char pad18[48-24]; void *active_value;
 S3List worms[4],alliances[4]; int current[4],unused[4],counts[4],worm_count;
 unsigned char padc8[296-200]; void *selected_worm; int pad12c; void *selected_team,*first_team;
 int actors[16],mode_a,mode_b,alliance_mode; int pad184; float last_position[3]; unsigned int position_count;
} S3Turns;
typedef struct S3Entity { unsigned char pad00[188]; int eligible; unsigned char padc0[213-192]; unsigned char team; unsigned char padd6[220-214]; int state; } S3Entity;
typedef struct S3Team { unsigned char pad00[44]; int excluded; unsigned char pad30[60-48]; unsigned char alliance; } S3Team;
typedef struct S3Handle { int object; unsigned int tag; } S3Handle;
typedef struct S3Cache {int id;const char *name;} S3Cache;
typedef struct S3Message {unsigned short id,pad02;void *type;} S3Message;
typedef struct S3Actor {unsigned char pad00[584];unsigned int entity;} S3Actor;
extern S3Entity *w3d_fn_800fc6dc(unsigned int);
extern S3Team *w3d_fn_800fc7f8(unsigned int),*w3d_fn_800fc82c(unsigned int,S3Handle *);
extern int w3d_fn_800fc1f0(const char **,int *);
extern int w3d_fn_800fc43c(const char **,int);
extern const char w3d_str_803a27ac[],w3d_str_803a2a14[],w3d_str_803a2a20[],w3d_str_803a2a6c[];
extern void w3d_fn_80178474(S3Handle *,int);
extern int w3d_fn_8015668c(S3Turns *,int),w3d_fn_801558dc(S3Turns *,int);
extern void *w3d_empty_803426b4(void *);
extern void w3d_fn_80178c54(void *,int *);
extern S3Message *w3d_fn_801613f0(void *,int);
extern short w3d_cached_message_id(S3Cache *,int);
extern void *w3d_global_804b1754,*w3d_type_8040db38[];
extern S3Cache w3d_cache_804afe70;
extern void w3d_auto_8015fc58(S3Turns *,S3Message *),w3d_empty_8015884c(S3Turns *);
extern void *w3d_factory_80410ef0[],*w3d_global_804b178c;
extern S3Actor *w3d_fn_8020b680(void *);
extern int w3d_fn_80164514(void *,S3Actor *,int);
void w3d_turns_remove_team(S3Turns *,int);
int w3d_turns_team_has_eligible(S3Turns *,unsigned int);


typedef struct S3Vec {float x,y,z;} S3Vec;
typedef struct S3VecLocal {S3Vec value;int unused;} S3VecLocal;
typedef struct S3EntityQuery {unsigned char pad00[80];S3Vec position; unsigned char pad5c[164-92];int health;unsigned short padA8,maximum_health;unsigned char padac[213-172];unsigned char team;unsigned char padd6[220-214];int state;} S3EntityQuery;
typedef struct S3ActorLinks {unsigned char pad00[800];int links[3];} S3ActorLinks;
extern unsigned int w3d_auto_80178c48(void *);
extern S3ActorLinks *w3d_fn_80164fc8(int);
extern void w3d_fn_80149f18(S3ActorLinks *);
extern S3Turns *w3d_turns_804ab400;
extern void *w3d_scene_804b1788,*w3d_type_803f04e8[];
extern void w3d_fn_80129424(void *,const char **,void *);
extern S3Vec *w3d_vec_message_value_80126034(void *),*w3d_motion_get_position_80066894(S3Vec *,void *);
extern const float w3d_f32_803a2cb8[];
extern const char w3d_str_803a2cbc[];
extern int w3d_fn_800fc230(const char **,int *);
extern S3EntityQuery *w3d_fn_800fc710(unsigned int,S3Handle *);
extern S3Cache w3d_cache_804afec8,w3d_cache_804afee8;
extern S3Message *w3d_message_int_init(S3Message *,unsigned short,int);
extern int w3d_message_post_current(S3Message *);
static __inline__ float s3_distance_squared(const S3Vec *a,const S3Vec *b) {float x=a->x-b->x,y=a->y-b->y,z=a->z-b->z;return x*x+y*y+z*z;}
static __inline__ void s3_vec_set(S3Vec *out,float x,float y,float z) {out->x=x;out->y=y;out->z=z;}
static __inline__ void s3_vec_make(S3Vec *out,const S3Vec *v) {s3_vec_set(out,v->x,v->y,v->z);}
typedef struct S3VecWide {S3Vec value;int unused[3];} S3VecWide;
static __inline__ void s3_post_int(S3Cache *cache,int value) {S3Message *m=w3d_fn_801613f0(w3d_global_804b1754,12);w3d_message_post_current(w3d_message_int_init(m,w3d_cached_message_id(cache,1),value));}
void w3d_turns_reset_actor_motion(S3Turns *);

void w3d_turns_apply_named_scene_value(S3Turns *self,const char **value) {
 if(*(unsigned short *)(*value-4)) w3d_fn_80129424(w3d_scene_804b1788,value,w3d_type_803f04e8);
}

void w3d_turns_select_near_message_position(S3Turns *self,void *message) {
 S3VecWide local; int selected=-1,i=0,current; float nearest;
 s3_vec_make(&local.value,w3d_vec_message_value_80126034(message));
 current=w3d_auto_80178c48(w3d_empty_803426b4(self->selected_worm));
 nearest=w3d_f32_803a2cb8[0];
 do {
  if(current!=i) {S3EntityQuery *entity=(S3EntityQuery *)w3d_fn_800fc6dc(i);if(entity->state) {float distance=s3_distance_squared(&local.value,&entity->position);if(distance<nearest) {nearest=distance;selected=i;}}}
 } while(++i<=15);
 if(selected!=-1) s3_post_int(&w3d_cache_804afec8,selected);
}

void w3d_turns_record_message_position(S3Turns *self,void *message) {
 S3VecLocal local;
 w3d_motion_get_position_80066894(&local.value,message);
 *(S3Vec *)self->last_position=local.value;
 self->position_count++;
}

void w3d_turns_select_nearest_opponent(S3Turns *self) {
 S3VecWide local; int selected=-1,i=0,current,team;float nearest;
 current=w3d_auto_80178c48(w3d_empty_803426b4(self->selected_worm));
 team=w3d_fn_800fc6dc(current)->team;
 s3_vec_make(&local.value,&((S3EntityQuery *)w3d_fn_800fc6dc(current))->position);
 do {
  S3EntityQuery *entity=(S3EntityQuery *)w3d_fn_800fc6dc(i);
  if(entity->state && entity->team!=team) {
   float distance=s3_distance_squared(&local.value,&entity->position);
   if(selected==-1 || distance<nearest) {nearest=distance;selected=i;}
  }
 } while(++i<=15);
 if(selected!=-1) s3_post_int(&w3d_cache_804afee8,selected);
}

int w3d_turns_disable_movement_retain(void) {
 const char *key=w3d_str_803a2cbc;int value=0;const char *set_key;
 w3d_fn_800fc230(&key,&value);
 set_key=w3d_str_803a2cbc;w3d_fn_800fc43c(&set_key,value+1);return value;
}

int w3d_turns_disable_movement_release(void) {
 const char *key=w3d_str_803a2cbc;int value=0;const char *set_key;
 w3d_fn_800fc230(&key,&value);
 if(value) {set_key=w3d_str_803a2cbc;w3d_fn_800fc43c(&set_key,value-1);}return value;
}

#if 0 /* 0x80158dd4: return register allocation differs after two revisions. */
int w3d_turns_selected_actor_has_links(S3Turns *self) {
 int entity=w3d_auto_80178c48(w3d_empty_803426b4(self->selected_worm));
 if(entity==-1) return 0;
 {int result=0; int handle=self->actors[entity];
 if(handle!=-1) {S3ActorLinks *actor=w3d_fn_80164fc8(handle); result=(actor->links[0] || actor->links[1] || actor->links[2])!=0;}
 return result;}
}
#endif

static __inline__ unsigned int s3_list_size(S3List *list) {return list->end-list->begin;}
unsigned int w3d_turns_team_list_size(S3Turns *self,unsigned int team) {
 if(team>4) return 0;
 return s3_list_size(&self->worms[team]);
}

#if 0 /* 0x80158ea4: handle and indexed-list temporary allocation differs after one revision. */
void w3d_turns_adjust_team_health(S3Turns *self,unsigned int team,int adjustment) {
 S3Handle handle; S3List *list; int *p;
 handle.object=0;handle.tag=0xe3a8;
 if(team>4) {w3d_fn_80178474(&handle,2);return;}
 list=&self->worms[team];
 for(p=list->begin;p!=list->end;p++) {S3EntityQuery *entity=w3d_fn_800fc710(*p,&handle);entity->health=entity->maximum_health-entity->health-adjustment;}
 w3d_fn_80178474(&handle,2);
}
#endif

int w3d_turns_reset_global_actor_motion(void) {
 if(w3d_turns_804ab400) w3d_turns_reset_actor_motion(w3d_turns_804ab400);
 return 0;
}

void w3d_turns_reset_actor_motion(S3Turns *self) {
 unsigned int i;
 for(i=0;i<=15;i++) {S3ActorLinks *actor=w3d_fn_80164fc8(self->actors[i]);if(actor) w3d_fn_80149f18(actor);}
}
