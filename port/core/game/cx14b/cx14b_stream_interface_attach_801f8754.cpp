#include "w3d_ptr.h"
#line 1 "cx14b_stream_interface_attach_801f8754.cpp"

// PPC32: held interface at +20. Method-table slots +12/+16 retain/release.
struct Interface{Ptr32<Ptr32<void>> table;};struct Owner{char pad[20];Ptr32<Interface> held;};
extern "C" int validate_801f8838(Ptr32<Owner>);
inline void retain(Ptr32<Interface> p){((Ptr32<void (Ptr32<Interface>)>)p->table[3])(p);}
inline void release(Ptr32<Interface> p){((Ptr32<void (Ptr32<Interface>)>)p->table[4])(p);}
extern "C" int w3d_cx14b_stream_interface_attach_801f8754(Ptr32<Owner> self,Ptr32<Interface> p){if(p)retain(p);if(self->held)release(self->held);self->held=p;int result=validate_801f8838(self);if(result){if(self->held)release(self->held);self->held=0;}return result;}



