#include "w3d_ptr.h"
#line 1 "cx13b_changed_interface_assign_802bdc88.cpp"
// PPC32 interface words and byte offsets are observed; semantic names are inferred.
struct Interface; struct Vtable {Ptr32<void (Ptr32<Interface>)> slot[25];}; struct Interface {Ptr32<Vtable> vtable;};
struct Ref {Ptr32<Interface> value;};
inline void retain(Ptr32<Interface> p){if(p)p->vtable->slot[3](p);} inline void release(Ptr32<Interface> p){if(p)p->vtable->slot[4](p);}

struct Object{unsigned char opaque[104];Ptr32<Interface> held;};extern "C" void changed_802bdd24(Ptr32<Object>);
extern "C" void w3d_cx13b_changed_interface_assign_802bdc88(Ptr32<Object> self,Ptr32<Ref> value){if(self->held!=value->value){retain(value->value);release(self->held);self->held=value->value;changed_802bdd24(self);}}



