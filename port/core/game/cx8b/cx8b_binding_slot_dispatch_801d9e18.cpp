#include "w3d_ptr.h"
#line 1 "cx8b_binding_slot_dispatch_801d9e18.cpp"

struct Cx8bDispatchObject;
typedef Ptr32<void (Ptr32<Cx8bDispatchObject>)> Cx8bMethod;
struct Cx8bDispatchObject { char unknown00[24]; Ptr32<Cx8bMethod> methods; };
struct Cx8bMethodDescriptor { char unknown00[6]; unsigned short index; };
struct Cx8bBindingInput { char unknown00[52]; Ptr32<Cx8bMethodDescriptor> descriptor; };
extern "C" int w3d_cx8b_binding_slot_dispatch_801d9e18(Ptr32<char> secondary,Ptr32<Cx8bBindingInput> input) {
 Ptr32<char> base=secondary ? w3d::R(secondary-4) : 0;
 Ptr32<Cx8bDispatchObject> object=(Ptr32<Cx8bDispatchObject>)(base+4);
 Ptr32<Cx8bMethodDescriptor> descriptor=input->descriptor;
 ((Ptr32<void (Ptr32<Cx8bDispatchObject>, Ptr32<Cx8bMethodDescriptor>)>)object->methods[descriptor->index])(object,descriptor);
 return 0;
}




