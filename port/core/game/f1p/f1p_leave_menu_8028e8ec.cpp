#include "w3d_ptr.h"
#line 1 "f1p_leave_menu_8028e8ec.cpp"
// Partial cache and owner layouts inferred from observed offsets.
struct String {
 String(const String &); String() {}Ptr32<char> text;};
extern "C" void fn_8020c5c4(Ptr32<String>),fn_80341588(Ptr32<String>);
struct Cache_8015f704 {int prefix[2];String name;template <class W3dU> Cache_8015f704(Ptr32<W3dU> w3d_p) : Cache_8015f704((const char *)w3d_p.get()) {}
 Cache_8015f704(const char*);~Cache_8015f704();};
extern "C" void fn_8015f558(Ptr32<Cache_8015f704>,int);
inline Cache_8015f704::~Cache_8015f704(){fn_8020c5c4(&name);fn_80341588(&name);fn_8015f558(this,2);}
struct Message{unsigned short id,pad;Ptr32<void> payload;};
struct Owner{char pad[64];int held;};struct Global{char pad[208];int mode;};
extern Ptr32<void> queue_804b1754; extern Ptr32<void> app_804b1788;extern Ptr32<Global> global_804aaabc;extern int depth_804abb5c,count_804abb60;
extern const char name_803d0008[];extern char value_8040db38[];
extern "C" Ptr32<Message> fn_801613f0(Ptr32<void>,int);
extern "C" unsigned fn_8015f5a0(Ptr32<Cache_8015f704>,int);
extern "C" void fn_800a7e14(int,int),fn_801298cc(Ptr32<void>);
extern "C" int fn_8016239c(Ptr32<Message>);
inline void post(Ptr32<Cache_8015f704> cache){Ptr32<Message> m=fn_801613f0(queue_804b1754,8);m->id=fn_8015f5a0(cache,1);m->payload=value_8040db38;fn_8016239c(m);}
extern "C" void w3d_leave_menu_8028e8ec(Ptr32<Owner> self){Cache_8015f704 cache(name_803d0008);post(&cache);--depth_804abb5c;count_804abb60-=6;self->held=0;if(global_804aaabc->mode==7){fn_800a7e14(6,0);fn_801298cc(app_804b1788);}}


