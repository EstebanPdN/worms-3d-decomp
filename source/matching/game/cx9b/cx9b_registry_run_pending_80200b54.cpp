
struct Descriptor;
struct Listener;
struct ListenerVtable { void *reserved[2]; int (*initialize)(Listener *,Descriptor *); };
struct Listener { ListenerVtable *vtable; };
struct Callback { Callback *next; unsigned int unknown; int (*run)(); };
// Inferred PPC32: callbacks +8, next +12, listener +24, initialized +28.
struct Descriptor { unsigned char prefix[8]; Callback *callbacks; Descriptor *next; unsigned char middle[8]; Listener *listener; int initialized; };
extern Descriptor *registry_804b18e8;
extern "C" int w3d_cx9b_registry_run_pending_80200b54() {
 for(Descriptor *entry=registry_804b18e8;entry;entry=entry->next) {
  if(!entry->initialized) {
   if(entry->listener) entry->listener->vtable->initialize(entry->listener,entry);
   for(Callback *callback=entry->callbacks;callback;callback=callback->next) {
    if(callback->run) { int status=callback->run(); if(status<0) return status; }
   }
   entry->initialized=1;
  }
 }
 return 0;
}

