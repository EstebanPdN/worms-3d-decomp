#include "w3d_ptr.h"
#line 1 "cx13a_initialize_property_owner_8004db14.cpp"
// Two-word addressable property/key slots observed at stack +8/+16, including one unused word each.
// PPC32 field and pointer offsets are observed; all action names are inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
extern "C" Ptr32<void> base_8015fef0(Ptr32<void>); Ptr32<void> cast_80342a78(Ptr32<void>);extern "C" int query_800fc1b0(Ptr32<Ptr32<const char>>,Ptr32<Ptr32<void>>);extern "C" Ptr32<void> string_803426b8(Ptr32<void>);extern unsigned char vtable_8040e9f8[];extern const char key_80377770[];
extern "C" Ptr32<void> w3d_cx13a_initialize_property_owner_8004db14(Ptr32<void> self){
 base_8015fef0(self);
FIELD(self,unsigned,28)=0;
FIELD(self,unsigned,32)=0;
FIELD(self,unsigned,36)=0;
FIELD(self,unsigned,40)=0;
FIELD(self,unsigned,44)=0;
FIELD(self,unsigned,48)=0;
FIELD(self,unsigned,52)=0;
FIELD(self,unsigned,56)=0;
FIELD(self,void *,0)=vtable_8040e9f8;
string_803426b8((Ptr32<char>)self+60);
string_803426b8((Ptr32<char>)self+64);
string_803426b8((Ptr32<char>)self+68);
string_803426b8((Ptr32<char>)self+72);
FIELD(self,void *,88)=0;if(FIELD(self,void *,32))VCALL(FIELD(self,void *,32),void (*)(void *),16)(FIELD(self,void *,32));FIELD(self,void *,32)=0;FIELD(self,unsigned,80)=0;
struct QueryWorkspace {Ptr32<void> property;unsigned reserved04;Ptr32<const char> key;unsigned reserved0c;};QueryWorkspace workspace;workspace.property=0;workspace.key=key_80377770;query_800fc1b0(&workspace.key,&workspace.property);Ptr32<void> typed=cast_80342a78(workspace.property);if(typed)VCALL(typed,void (*)(void *),12)(typed);if(FIELD(self,void *,88))VCALL(FIELD(self,void *,88),void (*)(void *),16)(FIELD(self,void *,88));FIELD(self,void *,88)=typed;if(workspace.property)VCALL(workspace.property,void (*)(void *),16)(workspace.property);return self;}


