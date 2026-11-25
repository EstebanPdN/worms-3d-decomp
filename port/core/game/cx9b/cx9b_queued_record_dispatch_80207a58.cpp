#include "w3d_ptr.h"
#line 1 "cx9b_queued_record_dispatch_80207a58.cpp"

struct Dispatcher;
struct DispatcherVtable { Ptr32<void> reserved[2]; Ptr32<int (Ptr32<Dispatcher>, unsigned int, Ptr32<const unsigned char>, unsigned int)> dispatch; };
struct Dispatcher { Ptr32<DispatcherVtable> vtable; };
struct QueueEnd { Ptr32<unsigned char> end; };
extern Ptr32<unsigned char> queue_cursor_8045ee64[];
extern Ptr32<Dispatcher> dispatcher_804b0660;
extern int queue_state_804b0664;
extern "C" void w3d_cx9b_queued_record_dispatch_80207a58(Ptr32<QueueEnd> queue) {
 Ptr32<unsigned char> cursor=queue_cursor_8045ee64[0];
 while(cursor!=queue->end) {
  unsigned int id=cursor[0] | (cursor[1]<<8); cursor+=2;
  if(id&0x8000) {
   unsigned int length=*cursor;
   if(length==255) { length=cursor[1] | (cursor[2]<<8);cursor+=3; }
   else ++cursor;
   dispatcher_804b0660->vtable->dispatch(dispatcher_804b0660,id&0x7fff,cursor,length);
   cursor+=length;
  } else dispatcher_804b0660->vtable->dispatch(dispatcher_804b0660,id,0,0);
 }
 queue_state_804b0664=0; queue_cursor_8045ee64[0]=cursor;
}




