// Inferred camera event dispatch, original entry 0x800d9de4.
// External GC32 partial views, not portable complete allocation types.
// Names and semantic roles are inferred from strings and observed accesses;
// descriptor and object ownership remains external.
struct Mx16saType {
 const char *name; unsigned int unknown_04_13[4]; Mx16saType *parent;
 bool derives_from(const Mx16saType *target) const {
  const Mx16saType *cursor=this;
  while(cursor!=target) {
   const Mx16saType *next=cursor->parent;
   if(cursor==next) return false;
   cursor=next;
  }
  return true;
 }
};
struct Mx16saCamera {
 unsigned int unknown_00_13[5]; int target;
 unsigned char unknown_18_113[252];
 float position[3];
 unsigned char unknown_120_12f[16];
 const char *event_name;
 unsigned char unknown_134_17b[72]; int elapsed;
};
struct Mx16saEntry { void **table; };
extern "C" int compare_802ef234(const char *,const char *);
extern "C" void *lookup_80164fc8(int);
extern "C" int query_entry_800fc330(const char **,Mx16saEntry **);
extern "C" int query_uint_800fc230(const char **,unsigned int *);
extern "C" int point_visible_80121330(const float *);
extern "C" void play_first_800edc28(Mx16saCamera *);
extern "C" void play_second_800edca0(Mx16saCamera *);
extern const char empty_8038956c[];
extern const char min_event_time_8038958c[];
extern const Mx16saType first_type_80367b08[];
extern const Mx16saType second_type_80367b58[];
extern "C" void mx16sa_camera_event_800d9de4(Mx16saCamera *self) {
 if(compare_802ef234(self->event_name,empty_8038956c)!=0 && lookup_80164fc8(self->target)!=0) {
  const char *name=self->event_name;
  Mx16saEntry *entry;
  query_entry_800fc330(&name,&entry);
  Mx16saType *type=((Mx16saType *(*)(Mx16saEntry *))entry->table[5])(entry);
  if(self->elapsed>0) {
   if(type->derives_from(first_type_80367b08)) {
    const char *key=min_event_time_8038958c;
    unsigned int minimum;
    query_uint_800fc230(&key,&minimum);
    if(!point_visible_80121330(self->position) || (unsigned int)self->elapsed>minimum)
     play_first_800edc28(self);
   } else if(type->derives_from(second_type_80367b58)) play_second_800edca0(self);
  }
 }
}
