#include "w3d_ptr.h"
#line 1 "cx12b_flagged_property_dispatch_8021c294.cpp"

struct Service;struct Vtable{Ptr32<void> p[3];Ptr32<void (Ptr32<Service>)> retain;Ptr32<void (Ptr32<Service>)> release;};struct Service{Ptr32<Vtable> vtable;unsigned char opaque[20];int value;};
struct Inner{unsigned char opaque[24];Ptr32<void> properties;};struct Owner{unsigned char opaque[36];Ptr32<Inner> inner;};
extern "C" unsigned int flags_80240b84(Ptr32<void>);extern "C" Ptr32<Service> lookup_8020b680(Ptr32<void>);extern "C" unsigned char descriptor_8041aac8[];extern "C" int dispatch_8021e930(Ptr32<void>,Ptr32<Service>);
struct Handle{Ptr32<Service> p;template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((Service *)w3d_p.get()) {}
 inline Handle(Service*x){p=x;if(p)p->vtable->retain(p);}inline ~Handle(){if(p)p->vtable->release(p);}};
extern "C" void w3d_cx12b_flagged_property_dispatch_8021c294(Ptr32<Owner> self,int value){Ptr32<void> p=self->inner->properties;if(flags_80240b84(p)&64){Handle h(lookup_8020b680(descriptor_8041aac8));h.p->value=value;dispatch_8021e930(p,h.p);}}




