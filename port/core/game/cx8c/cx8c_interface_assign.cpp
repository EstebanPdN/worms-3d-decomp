#include "w3d_ptr.h"
#line 1 "cx8c_interface_assign.cpp"
/* Layout offsets and call addresses observed in the original. Names and object roles are inferred. */
struct Cx8cInterface {Ptr32<Ptr32<void>> vtable;};
struct Cx8cOwner {unsigned char unknown[120];Ptr32<Cx8cInterface> held;};
extern "C" unsigned int w3d_cx8c_interface_assign_8034bb44(Ptr32<Cx8cOwner> self,Ptr32<Cx8cInterface> value) {
 if (value!=self->held) {if (self->held) ((Ptr32<void (Ptr32<Cx8cInterface>)>)self->held->vtable[4])(self->held);self->held=value;if(value) ((Ptr32<void (Ptr32<Cx8cInterface>)>)value->vtable[3])(value);}
 return self->held?0:0x80070057;
}


