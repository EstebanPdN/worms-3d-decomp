#include "w3d_ptr.h"
#line 1 "cx12b_landscape_services_clear_80269694.cpp"

struct Service;struct Vtable {Ptr32<void> p[4];Ptr32<void (Ptr32<Service>)> release;};struct Service{Ptr32<Vtable> vtable;};
struct Owner {unsigned char opaque[212];Ptr32<Service> first;unsigned char rest[268];Ptr32<Service> second;inline void clear(Ptr32<Ptr32<Service>> slot,Ptr32<Service> zero){if(*slot)(*slot)->vtable->release(*slot);*slot=zero;}};
extern "C" void reset_8026c0d0(Ptr32<Owner>,int);extern "C" void member_802b0fec(Ptr32<void>);
inline void cleanup(Ptr32<Owner> self,Ptr32<Service> zero){self->clear(&self->first,zero);reset_8026c0d0(self,0);self->clear(&self->second,zero);member_802b0fec((Ptr32<unsigned char>)self+28);}
extern "C" void w3d_cx12b_landscape_services_clear_80269694(Ptr32<Owner> self){cleanup(self,0);}



