/*
 * 0x80157490: announce the worm selected for the next turn.
 *
 * Scans the 16 worm records (0x800fc6dc) for the active one with the highest
 * score. With a positive best score the selection is posted: when it is the
 * current worm, a plain message (key 0x804aff08, table 0x8040db38) and the
 * current team (key 0x804aff58); otherwise the current worm (key 0x804aff20)
 * if a selection is pending, else the selected worm (key 0x804afe88); the
 * pending flag is cleared. With no selection and a new sequence number, the
 * nearest worm of another team to the stored position is found (squared
 * distance) and its index, its team and the current team are posted (keys
 * 0x804afef0, 0x804aff60, 0x804aff58). The sequence is then remembered.
 *
 * Messages come from the arena allocator (0x801613f0) and the integer message
 * initializer (0x800a82f0), with ids from the cached-name lookup. Structures
 * are partial views; field names are inferred.
 */
struct D20dTurnVec { float x,y,z; };
struct D20dTurnEntity { char prefix[80]; D20dTurnVec position; char to_score[72]; int score; char to_team[45]; unsigned char team; char to_active[6]; int active; };
struct D20dTurnState { char prefix[296]; void *context; char to_pending[76]; int pending; char to_position[12]; D20dTurnVec position; unsigned sequence, previous; };
struct D20dTurnMessage { unsigned short id; unsigned short flags; void *table; };
extern "C" D20dTurnEntity *s8_index_query_800fc6dc(int index);
extern "C" void *w3d_empty_803426b4(void *object);
extern "C" int w3d_auto_80178c48(void *game);
extern void *w3d_arena_804b1754;
extern "C" void *tsonnet_b33_arena_801613f0(void *arena, int bytes);
extern "C" unsigned int w3d_cached_message_id(void *name, int force);
struct D20dTurnMessageKey { unsigned words[2]; };
extern D20dTurnMessageKey w3d_message_key_804aff08,w3d_message_key_804aff58,w3d_message_key_804aff20,w3d_message_key_804afe88,w3d_message_key_804afef0,w3d_message_key_804aff60;
extern char w3d_message_table_8040db38[];
extern "C" D20dTurnMessage *w3d_message_int_init(void *message, unsigned short id, int integer);
extern "C" int w3d_message_post_current(void *message);
inline void d20d_post_int(void *key,int value) {
 void *m=tsonnet_b33_arena_801613f0(w3d_arena_804b1754,12);
 unsigned short id=w3d_cached_message_id(key,1);
 w3d_message_post_current(w3d_message_int_init(m,id,value));
}
extern "C" void d20d_turn_notify_80157490(D20dTurnState *self) {
 int best=0,selected=16; int i;
 for(i=0;i<16;++i) { D20dTurnEntity *e=s8_index_query_800fc6dc(i); if(e->active && e->score>best) { best=e->score; selected=i; } }
 int current=w3d_auto_80178c48(w3d_empty_803426b4(self->context));
 if(selected<=15 && best>0) {
  if(selected==current) {
   D20dTurnMessage *m=(D20dTurnMessage *)tsonnet_b33_arena_801613f0(w3d_arena_804b1754,8);
   m->id=w3d_cached_message_id(&w3d_message_key_804aff08,1); m->table=w3d_message_table_8040db38; w3d_message_post_current(m);
   void *n=tsonnet_b33_arena_801613f0(w3d_arena_804b1754,12);
   unsigned short id=w3d_cached_message_id(&w3d_message_key_804aff58,1);
   w3d_message_post_current(w3d_message_int_init(n,id,s8_index_query_800fc6dc(current)->team));
  } else if(self->pending) d20d_post_int(&w3d_message_key_804aff20,current);
  else d20d_post_int(&w3d_message_key_804afe88,selected);
  self->pending=0;
 } else if(selected==16 && self->sequence>self->previous) {
  int nearest=-1;float nearest_distance;
  for(i=0;i<16;++i) {
   unsigned team=s8_index_query_800fc6dc(current)->team;
   if(team != s8_index_query_800fc6dc(i)->team) {
    D20dTurnEntity *e=s8_index_query_800fc6dc(i);
    D20dTurnVec *a=&e->position;
    D20dTurnVec *b=&self->position;
    float dy=a->y-b->y;
    float dx=a->x-b->x;
    float dz=a->z-b->z;
    float distance=dx*dx+dy*dy+dz*dz;
    if(nearest==-1 || distance<nearest_distance) { nearest_distance=distance; nearest=i; }
   }
  }
  if(nearest!=-1) {
   d20d_post_int(&w3d_message_key_804afef0,nearest);
   unsigned team=s8_index_query_800fc6dc(nearest)->team;
   d20d_post_int(&w3d_message_key_804aff60,team);
   team=s8_index_query_800fc6dc(current)->team;
   d20d_post_int(&w3d_message_key_804aff58,team);
  }
 }
 self->previous=self->sequence;
}
