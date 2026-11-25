#include "w3d_ptr.h"
#line 1 "cx16a_apply_selected_800a1608.cpp"
// Observed PPC32 fields. The helper returns a three-word property value.
struct Cx16aValue { int x,y; };
struct Cx16aOwner { char pad[36]; Ptr32<void> target; Ptr32<void> selector; };
extern "C" unsigned select_80178c48(Ptr32<void>);
extern "C" Ptr32<void> cast_8034357c(Ptr32<void>);
extern "C" Ptr32<void> read_800fd388(Ptr32<void>,...);
extern "C" int apply_80173df0(Ptr32<void>,Ptr32<void>);
extern "C" void w3d_cx16a_apply_selected_800a1608(Ptr32<Cx16aOwner> self) {
 unsigned index=select_80178c48(self->selector);
 if(index<16) { Cx16aValue value; Ptr32<Cx16aValue> vp=&value; Ptr32<void> target=cast_8034357c(self->target); read_800fd388(vp,index); apply_80173df0(target,vp); }
}


