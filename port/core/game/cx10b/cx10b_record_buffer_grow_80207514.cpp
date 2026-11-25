#include "w3d_ptr.h"
#line 1 "cx10b_record_buffer_grow_80207514.cpp"
// Observed PPC32 byte-buffer pointer and size at zero and four.
struct Buffer {Ptr32<unsigned char> data;unsigned int size;};
struct Heap {unsigned int opaque[2];};
extern Heap heap_804b0644;
extern "C" Ptr32<void> allocate_802098d8(Ptr32<Heap>,unsigned int,int);
extern "C" void release_80209920(Ptr32<Heap>,Ptr32<void>);
extern "C" Ptr32<void> copy_802eee50(Ptr32<void>,Ptr32<const void>,unsigned int,...);
extern "C" Ptr32<void> clear_802eefe0(Ptr32<void>,int,unsigned int);
extern "C" void w3d_cx10b_record_buffer_grow_80207514(Ptr32<Buffer> self,unsigned int size,int flags) {
 if(size>self->size) {
  Ptr32<unsigned char> old=self->data;
  self->data=(Ptr32<unsigned char>)allocate_802098d8(&heap_804b0644,size,flags);
  copy_802eee50(self->data,old,self->size);
  clear_802eefe0(self->data+self->size,0,size-self->size);
  if(old)release_80209920(&heap_804b0644,old);
  self->size=size;
 }
}



