#include "w3d_ptr.h"
#line 1 "cx12b_resource_stop_802629bc.cpp"

struct Interface; struct Vtable { Ptr32<void (Ptr32<Interface>)> slot[7]; }; struct Interface { Ptr32<Vtable> vtable; };
struct ManagerVtable { Ptr32<void (void)> unused[25]; Ptr32<void (Ptr32<Interface>, Ptr32<void>, int)> detach; };
struct Manager { Ptr32<ManagerVtable> vtable; };
struct Context { unsigned char opaque[108]; Ptr32<Manager> manager; };
extern "C" Ptr32<Context> context_804b1788;
struct Resource { unsigned char opaque[200]; unsigned int handle; Ptr32<Interface> held; int state; };
inline void detach(Ptr32<unsigned int> handle,Ptr32<Resource> self) {
 if(*handle) { Ptr32<Manager> m=context_804b1788->manager; m->vtable->detach((Ptr32<Interface>)m,handle,200); self->state=3; }
}
inline void release(Ptr32<Interface> p){if(p)p->vtable->slot[4](p);}
extern "C" void w3d_cx12b_resource_stop_802629bc(Ptr32<Resource> self) {
 detach(&self->handle,self);
 if(self->held) self->held->vtable->slot[6](self->held);
 release(self->held);
 self->held=0;
}




