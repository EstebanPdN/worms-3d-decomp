#include "w3d_ptr.h"
#line 1 "cc37b_callbacks_801fb94c.cpp"
// Observed views only: no original declaration or complete sizeof claim.
// Callback implementations and the objects in the collection remain unowned.
// Partial callback collection. Mode two probes four nullable fixed slots;
// mode three visits the current vector length and returns the last error.
struct cc37b_Callback;
struct cc37b_CallbackTable {Ptr32<void> unknown[9]; Ptr32<int (Ptr32<cc37b_Callback>, Ptr32<void>)> invoke;};
struct cc37b_Callback {Ptr32<cc37b_CallbackTable> vtable;};
struct cc37b_CallbackVector {
 Ptr32<Ptr32<cc37b_Callback>> begin; Ptr32<Ptr32<cc37b_Callback>> end; Ptr32<Ptr32<cc37b_Callback>> capacity;
 inline unsigned size() const {return end-begin;}
};
struct cc37b_CallbackOwner {unsigned char unknown00[0x24]; cc37b_CallbackVector callbacks;};
extern "C" int w3d_cc37b_callbacks_801fb94c(Ptr32<cc37b_CallbackOwner> self,Ptr32<void> context,int mode) {
 switch(mode) {
 case 2:
  for(unsigned i=0;i<4;++i) {
   Ptr32<cc37b_Callback> item=*(Ptr32<Ptr32<cc37b_Callback>>)((Ptr32<char>)self->callbacks.begin+(i<<2));
   if(item) item->vtable->invoke(item,context);
  }
  return 0;
 case 3: {
  unsigned i=0; int result=0;
  for(;i<self->callbacks.size();++i) {
   Ptr32<cc37b_Callback> item=*(Ptr32<Ptr32<cc37b_Callback>>)((Ptr32<char>)self->callbacks.begin+(i<<2));
   int error=item->vtable->invoke(item,context);
   if(error<0) result=error;
  }
  return result;
 }
 case 0: case 1: default:return (int)0x80004005u;
 }
}


