#include "w3d_ptr.h"
#line 1 "cx13b_paired_interfaces_assign_802bc098.cpp"
// PPC32 interface words and byte offsets are observed; semantic names are inferred.
struct Interface; struct Vtable {Ptr32<void (Ptr32<Interface>)> slot[25];}; struct Interface {Ptr32<Vtable> vtable;};
struct Ref {Ptr32<Interface> value;};
inline void retain(Ptr32<Interface> p){if(p)p->vtable->slot[3](p);} inline void release(Ptr32<Interface> p){if(p)p->vtable->slot[4](p);}

struct Object{unsigned char opaque[28];Ptr32<Interface> first;unsigned char gap[56];Ptr32<Interface> second;};
extern "C" void w3d_cx13b_paired_interfaces_assign_802bc098(Ptr32<Object> self,Ptr32<Ref> first,Ptr32<Ref> second){retain(first->value);release(self->first);self->first=first->value;retain(second->value);release(self->second);self->second=second->value;}



