#include "w3d_ptr.h"
#line 1 "cx14a_initialize_index_801192ec.cpp"
// PPC32 offsets and interface slots are observed; descriptive names are inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))

extern "C" Ptr32<void> base_80161014(Ptr32<void>); Ptr32<void> cast_803426b4(Ptr32<void>);extern "C" int query_800fc1b0(Ptr32<Ptr32<const char>>,Ptr32<Ptr32<void>>);
extern unsigned char vtable_80410950[];extern const char key_8039aacc[];
extern "C" Ptr32<void> w3d_cx14a_initialize_index_801192ec(Ptr32<void> self){base_80161014(self);FIELD(self,void *,0)=vtable_80410950;
 struct QueryWorkspace{Ptr32<void> property;unsigned reserved;Ptr32<const char> key;unsigned reserved2;};QueryWorkspace q;
 FIELD(self,unsigned,28)=0;FIELD(self,unsigned,32)=0;FIELD(self,unsigned,40)=0;FIELD(self,unsigned,44)=0;FIELD(self,unsigned,36)=0;
 q.key=key_8039aacc;q.property=0;query_800fc1b0(&q.key,&q.property);Ptr32<void> typed=cast_803426b4(q.property);if(typed)VCALL(typed,void (*)(void *),12)(typed);if(FIELD(self,void *,44))VCALL(FIELD(self,void *,44),void (*)(void *),16)(FIELD(self,void *,44));FIELD(self,void *,44)=typed;if(q.property)VCALL(q.property,void (*)(void *),16)(q.property);return self;}


