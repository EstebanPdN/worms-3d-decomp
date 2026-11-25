#include "w3d_ptr.h"
#line 1 "cx11b_service_vector_clear_8020ad18.cpp"
// PPC32 vector at owner +20; release virtual slot +16. Empty copy is retained from the original generic erase.
struct Service;struct Vtable {Ptr32<void> unused[4];Ptr32<int (Ptr32<Service>)> release;};struct Service {Ptr32<Vtable> vtable;};
extern "C" Ptr32<void> copy_802eee50(Ptr32<void>,Ptr32<const void>,unsigned int,...);
struct Vector {Ptr32<Ptr32<Service>> begin; Ptr32<Ptr32<Service>> end; Ptr32<Ptr32<Service>> capacity;
 void clear(){Ptr32<Ptr32<Service>> first=begin; Ptr32<Ptr32<Service>> last=end;unsigned int bytes=(Ptr32<unsigned char>)last-(Ptr32<unsigned char>)first;copy_802eee50(first,last,0);end=(Ptr32<Ptr32<Service>>)((Ptr32<unsigned char>)end-bytes);}
};
struct Owner {unsigned char opaque[20];Vector values;};
extern "C" int w3d_cx11b_service_vector_clear_8020ad18(Ptr32<Owner> self){Ptr32<Ptr32<Service>> end=self->values.end;Ptr32<Ptr32<Service>> p=self->values.begin;while(p!=end){Ptr32<Service> s=*p++;s->vtable->release(s);}self->values.clear();return 0;}



