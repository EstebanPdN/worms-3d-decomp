
struct Dispatcher;
struct DispatcherVtable { void *reserved[2]; int (*dispatch)(Dispatcher *,unsigned int,const unsigned char *,unsigned int); };
struct Dispatcher { DispatcherVtable *vtable; };
struct QueueEnd { unsigned char *end; };
extern unsigned char *queue_cursor_8045ee64[];
extern Dispatcher *dispatcher_804b0660;
extern int queue_state_804b0664;
extern "C" void w3d_cx9b_queued_record_dispatch_80207a58(QueueEnd *queue) {
 unsigned char *cursor=queue_cursor_8045ee64[0];
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


