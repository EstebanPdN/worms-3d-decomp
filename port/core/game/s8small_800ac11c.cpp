#include "w3d_ptr.h"
#line 1 "s8small_800ac11c.cpp"
struct s8_PropertyOwner { char pad0[128]; Ptr32<void> property; };
extern "C" Ptr32<void> fn_803426b4(Ptr32<void>);
extern "C" int fn_80178c54(Ptr32<void>,Ptr32<int>);
extern "C" void s8_set_member_property_800ac11c(Ptr32<s8_PropertyOwner> self,int value) { fn_80178c54(fn_803426b4(self->property),&value); }


