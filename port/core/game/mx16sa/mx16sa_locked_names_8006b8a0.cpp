#include "w3d_ptr.h"
#line 1 "mx16sa_locked_names_8006b8a0.cpp"
// Inferred locked-name initialization, original entry 0x8006b8a0.
// External GC32 partial views; complete runtime/owner allocation is not claimed.
// The message has observed size eight: 16-bit ID at zero and table pointer at four.
// The key and table below are external binary objects, not text strings.
struct Mx16saLockedOwner {
 unsigned char unknown_00_13[20]; int handle;
 unsigned char unknown_18_cf[184]; int state;
 unsigned char unknown_d4_ef[28]; unsigned int flags;
};
struct Mx16saRuntime { unsigned char unknown_00_bb[188]; unsigned int flags; };
struct Mx16saMessage { unsigned short id; Ptr32<const void> table; };
extern "C" int query_text_800fc2b0(Ptr32<Ptr32<const char>>,Ptr32<Ptr32<const char>>);
extern "C" Ptr32<void> service_8020b680(Ptr32<const void>);
extern "C" int attach_80164514(Ptr32<void>,Ptr32<void>,int);
extern "C" Ptr32<Mx16saMessage> allocate_801613f0(Ptr32<void>,unsigned int);
extern "C" unsigned int message_id_8015f5a0(Ptr32<unsigned int>,int);
extern "C" int post_8016239c(Ptr32<Mx16saMessage>);
extern "C" void set_mode_8006ab48(Ptr32<Mx16saLockedOwner>,int,int,int,int);
extern const char locked_name_8037bb04[],locked_name2_8037bb18[],locked_name3_8037bb28[];
extern const unsigned char service_key_8040fa58[];
extern Ptr32<const void> message_table_8040db38[];
extern Ptr32<Mx16saRuntime> runtime_804b1788;
extern Ptr32<void> manager_804b178c; extern Ptr32<void> pool_804b1754;
extern unsigned int cached_id_804ad7ac;
extern "C" void mx16sa_locked_names_8006b8a0(Ptr32<Mx16saLockedOwner> self) {
 Ptr32<const char> name=locked_name_8037bb04;
 int locked=0;
 Ptr32<const char> value=0;
 query_text_800fc2b0(&name,&value);
 if(value && value[0]) locked=1;
 Ptr32<const char> name2=locked_name2_8037bb18;
 query_text_800fc2b0(&name2,&value);
 if(value && value[0]) locked=1;
 Ptr32<const char> name3=locked_name3_8037bb28;
 query_text_800fc2b0(&name3,&value);
 if(value && value[0]) locked=1;
 if((runtime_804b1788->flags & 64) && locked) {
  self->flags|=0x02000000;
  Ptr32<void> service=service_8020b680(service_key_8040fa58);
  attach_80164514(manager_804b178c,service,self->handle);
  Ptr32<Mx16saMessage> message=allocate_801613f0(pool_804b1754,8);
  message->id=message_id_8015f5a0(&cached_id_804ad7ac,1);
  message->table=message_table_8040db38;
  post_8016239c(message);
 } else set_mode_8006ab48(self,6,1,0,0);
 self->state=9;
}


