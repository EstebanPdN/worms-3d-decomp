#include "w3d_ptr.h"
#line 1 "cx11b_child_services_clear_802c7014.cpp"
// PPC32 owner slots and interface methods; names inferred from the observed drain/release operations.
struct Service;struct Vtable {Ptr32<void> p0[4];Ptr32<int (Ptr32<Service>)> release;Ptr32<void> p1[19];Ptr32<void (Ptr32<Service>, Ptr32<void>)> remove;Ptr32<void> p2[4];Ptr32<Ptr32<void> (Ptr32<Service>, int)> item;Ptr32<int (Ptr32<Service>)> count;};struct Service {Ptr32<Vtable> vtable;};
struct Owner {unsigned char p[28];Ptr32<Service> children;unsigned char p2[8];Ptr32<Service> s40; Ptr32<Service> s44; Ptr32<Service> s48; Ptr32<Service> s52; Ptr32<Service> s56; Ptr32<Service> s60; Ptr32<Service> s64;unsigned char p3[24];Ptr32<Service> s92;template<unsigned int Offset>void clear(Ptr32<Service> zero){Ptr32<Ptr32<Service>> slot=(Ptr32<Ptr32<Service>>)((Ptr32<unsigned char>)this+Offset);(*slot)->vtable->release(*slot);*slot=zero;}};
extern "C" void w3d_cx11b_child_services_clear_802c7014(Ptr32<Owner> self){if(self->children){while(self->children->vtable->count(self->children)){Ptr32<Service> s=self->children;Ptr32<Vtable> v=s->vtable;Ptr32<void> child=v->item(s,0);v->remove(s,child);}if(self->children)self->children->vtable->release(self->children);self->children=0;}
 if(self->s92)self->clear<92>(0);
 if(self->s40)self->clear<40>(0);
 if(self->s48)self->clear<48>(0);
 if(self->s56)self->clear<56>(0);
 if(self->s44)self->clear<44>(0);
 if(self->s52)self->clear<52>(0);
 if(self->s60)self->clear<60>(0);
 if(self->s64)self->clear<64>(0);
}




