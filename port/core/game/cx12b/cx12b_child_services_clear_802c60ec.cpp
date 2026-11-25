#include "w3d_ptr.h"
#line 1 "cx12b_child_services_clear_802c60ec.cpp"
// Observed PPC32 interface layout; names are inferred from call patterns.
struct Service;struct Vtable {Ptr32<void> s0[3];Ptr32<void (Ptr32<Service>)> retain;Ptr32<void (Ptr32<Service>)> release;Ptr32<void> s1[17];Ptr32<void (Ptr32<Service>, int)> visible;Ptr32<void (Ptr32<Service>, Ptr32<Service>, int)> attach;Ptr32<void (Ptr32<Service>, Ptr32<void>)> remove;Ptr32<void> s2[4];Ptr32<Ptr32<void> (Ptr32<Service>, int)> item;Ptr32<int (Ptr32<Service>)> count;};struct Service {Ptr32<Vtable> vtable;};
struct Owner {unsigned char opaque[28];Ptr32<Service> children;int state;unsigned char opaque2[4];Ptr32<Service> s40; Ptr32<Service> s44; Ptr32<Service> s48; Ptr32<Service> s52; Ptr32<Service> s56; Ptr32<Service> s60; Ptr32<Service> s64;unsigned char rest[36];int enabled;template<unsigned int Offset>void clear(Ptr32<Service> zero){Ptr32<Ptr32<Service>> slot=(Ptr32<Ptr32<Service>>)((Ptr32<unsigned char>)this+Offset);(*slot)->vtable->release(*slot);*slot=zero;}};

extern "C" void w3d_cx12b_child_services_clear_802c60ec(Ptr32<Owner> self){if(self->children){while(self->children->vtable->count(self->children)){Ptr32<Service> s=self->children;Ptr32<Vtable> v=s->vtable;Ptr32<void> child=v->item(s,0);v->remove(s,child);}if(self->children)self->children->vtable->release(self->children);self->children=0;}
 if(self->s48)self->clear<48>(0);if(self->s52)self->clear<52>(0);if(self->s56)self->clear<56>(0);
}



