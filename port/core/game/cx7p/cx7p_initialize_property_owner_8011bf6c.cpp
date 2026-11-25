#include "w3d_ptr.h"
#line 1 "cx7p_initialize_property_owner_8011bf6c.cpp"
// Two-word addressable property/key slots observed at stack +8/+16, including one unused word each.
// PPC32 field and pointer offsets are observed; all action names are inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
extern "C" Ptr32<void> base_80161014(Ptr32<void>); Ptr32<void> cast_80342a78(Ptr32<void>);extern "C" int query_800fc1b0(Ptr32<Ptr32<const char>>,Ptr32<Ptr32<void>>);extern unsigned char vtable_80410a70[];extern const char key_8039afbc[];
extern "C" Ptr32<void> w3d_cx7p_initialize_property_owner_8011bf6c(Ptr32<void> self){
 base_80161014(self);
FIELD(self,unsigned,28)=0;
FIELD(self,unsigned,32)=0;
FIELD(self,unsigned,36)=0;
FIELD(self,unsigned,40)=0;
FIELD(self,unsigned,44)=0;
FIELD(self,unsigned,48)=0;
FIELD(self,unsigned,52)=0;
FIELD(self,unsigned,56)=0;
FIELD(self,unsigned,60)=0;
FIELD(self,unsigned,64)=0;
FIELD(self,unsigned,68)=0;
FIELD(self,unsigned,72)=0;
FIELD(self,unsigned,76)=0;
FIELD(self,unsigned,80)=0;
FIELD(self,unsigned,84)=0;
FIELD(self,unsigned,88)=0;
FIELD(self,unsigned,92)=0;
FIELD(self,unsigned,96)=0;
FIELD(self,void *,0)=vtable_80410a70;
FIELD(self,unsigned,136)=0;
FIELD(self,unsigned,140)=0;
FIELD(self,unsigned,144)=0;
FIELD(self,unsigned,148)=0;
FIELD(self,unsigned,152)=0;
FIELD(self,unsigned,156)=0;
FIELD(self,unsigned,160)=0;
FIELD(self,unsigned,164)=0;
FIELD(self,unsigned,168)=0;
FIELD(self,unsigned,172)=0;
FIELD(self,unsigned,176)=0;
FIELD(self,unsigned,180)=0;
FIELD(self,unsigned,184)=0;
FIELD(self,unsigned,188)=0;
FIELD(self,unsigned,192)=0;
struct QueryWorkspace {Ptr32<void> property;unsigned reserved04;Ptr32<const char> key;unsigned reserved0c;};QueryWorkspace workspace;workspace.key=key_8039afbc;workspace.property=0;query_800fc1b0(&workspace.key,&workspace.property);Ptr32<void> typed=cast_80342a78(workspace.property);if(typed)VCALL(typed,void (*)(void *),12)(typed);if(FIELD(self,void *,188))VCALL(FIELD(self,void *,188),void (*)(void *),16)(FIELD(self,void *,188));FIELD(self,void *,188)=typed;if(workspace.property)VCALL(workspace.property,void (*)(void *),16)(workspace.property);return self;}


