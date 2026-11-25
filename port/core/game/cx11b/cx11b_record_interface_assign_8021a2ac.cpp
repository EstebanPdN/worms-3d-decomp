#include "w3d_ptr.h"
#line 1 "cx11b_record_interface_assign_8021a2ac.cpp"
// PPC32 field offset halfword +10 and store pointer +16; interfaces retain +12 and release +16.
struct Service;struct Vtable {Ptr32<void> unused[3];Ptr32<int (Ptr32<Service>)> retain;Ptr32<int (Ptr32<Service>)> release;};struct Service {Ptr32<Vtable> vtable;};
struct Field {unsigned char opaque[10];unsigned short offset;unsigned int pad;Ptr32<void> store;};
extern "C" Ptr32<unsigned char> acquire_802078b4(Ptr32<void>,Ptr32<void>,unsigned int);
extern "C" void w3d_cx11b_record_interface_assign_8021a2ac(Ptr32<Field> self,Ptr32<void> record,Ptr32<Service> value){Ptr32<unsigned char> data=acquire_802078b4(self->store,record,self->offset+4);unsigned int offset=self->offset;Ptr32<Ptr32<Service>> slot=(Ptr32<Ptr32<Service>>)(data+offset);if(*slot)(*slot)->vtable->release(*slot);*slot=value;if(value)value->vtable->retain(value);}



