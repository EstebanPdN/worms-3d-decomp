#include "w3d_ptr.h"
#line 1 "s8hand_800da818.cpp"
struct s8_Interface { Ptr32<Ptr32<void (void)>> vtable; };
struct s8_Context { char pad0[32]; Ptr32<void> mesh; };
extern "C" Ptr32<s8_Interface> fn_80343584(Ptr32<void>);
extern "C" void s8_mesh_forward_800da818(Ptr32<s8_Context> context,int value) {
    Ptr32<s8_Interface> mesh=fn_80343584(context->mesh);
    ((Ptr32<void (Ptr32<s8_Interface>, int)>)mesh->vtable[22])(mesh,value);
}


