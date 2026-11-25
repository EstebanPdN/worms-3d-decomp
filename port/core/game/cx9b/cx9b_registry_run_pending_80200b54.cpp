#include "w3d_ptr.h"
#line 1 "cx9b_registry_run_pending_80200b54.cpp"

struct Descriptor;
struct Listener;
struct ListenerVtable { Ptr32<void> reserved[2]; Ptr32<int (Ptr32<Listener>, Ptr32<Descriptor>)> initialize; };
struct Listener { Ptr32<ListenerVtable> vtable; };
struct Callback { Ptr32<Callback> next; unsigned int unknown; Ptr32<int (void)> run; };
// Inferred PPC32: callbacks +8, next +12, listener +24, initialized +28.
struct Descriptor { unsigned char prefix[8]; Ptr32<Callback> callbacks; Ptr32<Descriptor> next; unsigned char middle[8]; Ptr32<Listener> listener; int initialized; };
extern Ptr32<Descriptor> registry_804b18e8;
extern "C" int w3d_cx9b_registry_run_pending_80200b54() {
 for(Ptr32<Descriptor> entry=registry_804b18e8;entry;entry=entry->next) {
  if(!entry->initialized) {
   if(entry->listener) entry->listener->vtable->initialize(entry->listener,entry);
   for(Ptr32<Callback> callback=entry->callbacks;callback;callback=callback->next) {
    if(callback->run) { int status=callback->run(); if(status<0) return status; }
   }
   entry->initialized=1;
  }
 }
 return 0;
}



