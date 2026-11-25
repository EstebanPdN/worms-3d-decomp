#include "w3d_ptr.h"
#line 1 "mx16sa_camera_event_800d9de4.cpp"
// Inferred camera event dispatch, original entry 0x800d9de4.
// External GC32 partial views, not portable complete allocation types.
// Names and semantic roles are inferred from strings and observed accesses;
// descriptor and object ownership remains external.
struct Mx16saType {
 Ptr32<const char> name; unsigned int unknown_04_13[4]; Ptr32<Mx16saType> parent;
 bool derives_from(Ptr32<const Mx16saType> target) const {
  Ptr32<const Mx16saType> cursor=this;
  while(cursor!=target) {
   Ptr32<const Mx16saType> next=cursor->parent;
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
 Ptr32<const char> event_name;
 unsigned char unknown_134_17b[72]; int elapsed;
};
struct Mx16saEntry { Ptr32<Ptr32<void>> table; };
extern "C" int compare_802ef234(Ptr32<const char>,Ptr32<const char>);
extern "C" Ptr32<void> lookup_80164fc8(int);
extern "C" int query_entry_800fc330(Ptr32<Ptr32<const char>>,Ptr32<Ptr32<Mx16saEntry>>);
extern "C" int query_uint_800fc230(Ptr32<Ptr32<const char>>,Ptr32<unsigned int>);
extern "C" int point_visible_80121330(Ptr32<const float>);
extern "C" void play_first_800edc28(Ptr32<Mx16saCamera>);
extern "C" void play_second_800edca0(Ptr32<Mx16saCamera>);
extern const char empty_8038956c[];
extern const char min_event_time_8038958c[];
extern const Mx16saType first_type_80367b08[];
extern const Mx16saType second_type_80367b58[];
extern "C" void mx16sa_camera_event_800d9de4(Ptr32<Mx16saCamera> self) {
 if(compare_802ef234(self->event_name,empty_8038956c)!=0 && lookup_80164fc8(self->target)!=0) {
  Ptr32<const char> name=self->event_name;
  Ptr32<Mx16saEntry> entry;
  query_entry_800fc330(&name,&entry);
  Ptr32<Mx16saType> type=((Ptr32<Ptr32<Mx16saType> (Ptr32<Mx16saEntry>)>)entry->table[5])(entry);
  if(self->elapsed>0) {
   if(type->derives_from(first_type_80367b08)) {
    Ptr32<const char> key=min_event_time_8038958c;
    unsigned int minimum;
    query_uint_800fc230(&key,&minimum);
    if(!point_visible_80121330(self->position) || (unsigned int)self->elapsed>minimum)
     play_first_800edc28(self);
   } else if(type->derives_from(second_type_80367b58)) play_second_800edca0(self);
  }
 }
}


