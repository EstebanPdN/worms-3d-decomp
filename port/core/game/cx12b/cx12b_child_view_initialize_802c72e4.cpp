#include "w3d_ptr.h"
#line 1 "cx12b_child_view_initialize_802c72e4.cpp"
// Observed PPC32 interface layout; names are inferred from call patterns.
struct Service;struct Vtable {Ptr32<void> s0[3];Ptr32<void (Ptr32<Service>)> retain;Ptr32<void (Ptr32<Service>)> release;Ptr32<void> s1[17];Ptr32<void (Ptr32<Service>, int)> visible;Ptr32<void (Ptr32<Service>, Ptr32<Service>, int)> attach;Ptr32<void (Ptr32<Service>, Ptr32<void>)> remove;Ptr32<void> s2[4];Ptr32<Ptr32<void> (Ptr32<Service>, int)> item;Ptr32<int (Ptr32<Service>)> count;};struct Service {Ptr32<Vtable> vtable;};
struct Owner {unsigned char opaque[28];Ptr32<Service> children;int state;unsigned char opaque2[4];Ptr32<Service> s40; Ptr32<Service> s44; Ptr32<Service> s48; Ptr32<Service> s52; Ptr32<Service> s56; Ptr32<Service> s60; Ptr32<Service> s64;unsigned char rest[36];int enabled;template<unsigned int Offset>void clear(Ptr32<Service> zero){Ptr32<Ptr32<Service>> slot=(Ptr32<Ptr32<Service>>)((Ptr32<unsigned char>)this+Offset);(*slot)->vtable->release(*slot);*slot=zero;}};
extern "C" void setup_802c73a4(Ptr32<Owner>);
extern "C" void setup_802c76e8(Ptr32<Owner>);
extern "C" void setup_802c7c1c(Ptr32<Owner>);
extern "C" void setup_802c7a98(Ptr32<Owner>);
extern "C" void setup_802c7e20(Ptr32<Owner>);

extern "C" Ptr32<Ptr32<Service>> w3d_cx12b_child_view_initialize_802c72e4(Ptr32<Ptr32<Service>> out,Ptr32<Owner> self,Ptr32<Ptr32<Service>> parent){
 Ptr32<Service> p=*parent;p->vtable->attach(p,self->children,0);
setup_802c73a4(self);
setup_802c76e8(self);
setup_802c7c1c(self);
setup_802c7a98(self);
setup_802c7e20(self);

 self->state=1;*out=self->children;if(*out)(*out)->vtable->retain(*out);if(*parent)(*parent)->vtable->release(*parent);return out;
}



