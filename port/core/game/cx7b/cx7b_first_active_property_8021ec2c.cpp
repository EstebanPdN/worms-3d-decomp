#include "w3d_ptr.h"
#line 1 "cx7b_first_active_property_8021ec2c.cpp"
struct Cx7bPropertyCollection { char unknown00[24]; unsigned int count; int unknown1c; Ptr32<void> entries[1]; };
struct Cx7bPropertyOwner { char unknown00[20]; Ptr32<Cx7bPropertyCollection> collection; };
extern "C" Ptr32<void> fn_80240994(Ptr32<void>);
extern "C" int fn_8021ed0c(Ptr32<void>);
extern "C" Ptr32<void> w3d_cx7b_first_active_property_8021ec2c(Ptr32<Cx7bPropertyOwner> self) {
 Ptr32<Cx7bPropertyCollection> collection=self->collection; unsigned int count=collection->count; Ptr32<Ptr32<void>> entries=collection->entries;
 for(unsigned int i=0;i<count;++i) if(fn_8021ed0c(fn_80240994(entries[i]))) return entries[i];
 return 0;
}


