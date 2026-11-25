#include "w3d_ptr.h"
#line 1 "cx16c_child_value_802bcd18.cpp"

// Observed child pointer range at +56/+60; changed cached value at +96.
struct Cx16cRange { Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end; Ptr32<Ptr32<void>> capacity; };
struct Cx16cPanel { char reserved[56]; Cx16cRange children; char gap[96-68]; int value; };
extern "C" void cx16c_apply_802c0cb4(Ptr32<void>,int);
static inline Ptr32<Ptr32<void>> cx16c_end(Ptr32<Cx16cRange> range) { return range->end; }
extern "C" void w3d_cx16c_child_value_802bcd18(Ptr32<Cx16cPanel> self,int value) {
 if(self->value!=value) {
  self->value=value;
  for(Ptr32<Ptr32<void>> it=self->children.begin; it!=cx16c_end(&self->children);) {
   Ptr32<void> child=*it++;
   cx16c_apply_802c0cb4(child,value);
  }
 }
}


