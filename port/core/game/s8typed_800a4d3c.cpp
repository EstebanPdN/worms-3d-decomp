#include "w3d_ptr.h"
#line 1 "s8typed_800a4d3c.cpp"
struct s8_Interface { Ptr32<Ptr32<void>> vtable; };
struct s8_MeshOwner { char pad0[32]; Ptr32<s8_Interface> mesh; };
extern "C" void s8_virtual_forward_800a4d3c(Ptr32<s8_MeshOwner> self,Ptr32<void> child) {
    Ptr32<s8_Interface> mesh=self->mesh;
    ((Ptr32<void (Ptr32<s8_Interface>, Ptr32<void>, int)>)mesh->vtable[19])(mesh,child,0);
}


