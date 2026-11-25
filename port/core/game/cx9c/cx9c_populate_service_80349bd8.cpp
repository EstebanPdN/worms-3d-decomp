#include "w3d_ptr.h"
#line 1 "cx9c_populate_service_80349bd8.cpp"
/* Observed owner fields: driver +56, signed count +84, target +108 and
 * service +112. Callback takes the address of a byte iterator; the live
 * stack byte, service names and callback meanings remain inferred. */
struct Cx9cInterface {Ptr32<Ptr32<void>> vtable;};
struct Cx9cDescriptor;
extern "C" Ptr32<Cx9cInterface> cx9c_lookup_8020b680(Ptr32<Cx9cDescriptor>);
struct Cx9cDescriptor {unsigned int opaque[4];Ptr32<Cx9cInterface> get(){return cx9c_lookup_8020b680(this);}};
extern "C" Cx9cDescriptor cx9c_descriptor_804163f8,cx9c_descriptor_804140d0;
struct Cx9cOwner {unsigned char opaque[56];Ptr32<Cx9cInterface> driver;unsigned char unknown_3c[24];int count;unsigned char unknown_58[20];Ptr32<Cx9cInterface> target; Ptr32<Cx9cInterface> service;};
static inline void cx9c_assign(Ptr32<Cx9cInterface> &field,Ptr32<Cx9cInterface> value) {
 if(value)((Ptr32<void (Ptr32<Cx9cInterface>)>)value->vtable[3])(value);
 if(field)((Ptr32<void (Ptr32<Cx9cInterface>)>)field->vtable[4])(field);
 field=value;
}
extern "C" int w3d_cx9c_populate_service_80349bd8(Ptr32<Cx9cOwner> self) {
 if(!self->service)cx9c_assign(self->service,cx9c_descriptor_804163f8.get());
 else ((Ptr32<void (Ptr32<Cx9cInterface>)>)self->service->vtable[20])(self->service);
 if(!self->target)cx9c_assign(self->target,cx9c_descriptor_804140d0.get());
 unsigned char index=0;
 while((int)index<self->count) {
  Ptr32<Cx9cInterface> entry=((Ptr32<Ptr32<Cx9cInterface> (Ptr32<Cx9cInterface>, Ptr32<unsigned char>)>)self->driver->vtable[29])(self->driver,&index);
  ((Ptr32<void (Ptr32<Cx9cInterface>, Ptr32<Cx9cInterface>)>)self->target->vtable[12])(self->target,self->service);
  ((Ptr32<void (Ptr32<Cx9cInterface>, Ptr32<Cx9cInterface>)>)self->target->vtable[6])(self->target,entry);
  ++index;
 }
 return 0;
}


