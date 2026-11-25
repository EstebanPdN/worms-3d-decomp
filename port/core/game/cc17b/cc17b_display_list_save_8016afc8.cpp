#include "w3d_ptr.h"
#line 1 "cc17b_display_list_save_8016afc8.cpp"
/* Original display-list byte count at +4 and storage pointer at +12.
   The allocator receives the emitted count in r4; it is not an unused move. */
struct Cc17bDisplayList { unsigned word,size; Ptr32<void> unknown; Ptr32<void> bytes; };
extern "C" {
unsigned fn_8030bd80();
extern Ptr32<void> allocator_804b1884;
Ptr32<void> fn_80166fd0(Ptr32<void>,unsigned);
Ptr32<void> fn_802eee50(Ptr32<void>,Ptr32<const void>,unsigned);
void fn_802fa988(Ptr32<void>,unsigned);
void w3d_cc17b_display_list_save_8016afc8(Ptr32<Cc17bDisplayList> self) {
 unsigned capacity=self->size;
 if(!capacity)fn_8030bd80();
 else {
  unsigned size=fn_8030bd80();self->size=size;
  if(size<=capacity) {
   Ptr32<void> destination=fn_80166fd0(allocator_804b1884,size);
   fn_802eee50(destination,self->bytes,self->size);
   unsigned count=self->size;self->bytes=destination;
   fn_802fa988(destination,count);
  }
 }
}
}


