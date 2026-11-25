#include "w3d_ptr.h"
#line 1 "cx12b_paired_visibility_apply_802c7c1c.cpp"
// Observed PPC32 interface layout; names are inferred from call patterns.
struct Service;struct Vtable {Ptr32<void> s0[3];Ptr32<void (Ptr32<Service>)> retain;Ptr32<void (Ptr32<Service>)> release;Ptr32<void> s1[17];Ptr32<void (Ptr32<Service>, int)> visible;Ptr32<void (Ptr32<Service>, Ptr32<Service>, int)> attach;Ptr32<void (Ptr32<Service>, Ptr32<void>)> remove;Ptr32<void> s2[4];Ptr32<Ptr32<void> (Ptr32<Service>, int)> item;Ptr32<int (Ptr32<Service>)> count;};struct Service {Ptr32<Vtable> vtable;};
struct Owner {unsigned char opaque[28];Ptr32<Service> children;int state;unsigned char opaque2[4];Ptr32<Service> s40; Ptr32<Service> s44; Ptr32<Service> s48; Ptr32<Service> s52; Ptr32<Service> s56; Ptr32<Service> s60; Ptr32<Service> s64;unsigned char rest[40];int enabled;template<unsigned int Offset>void clear(Ptr32<Service> zero){Ptr32<Ptr32<Service>> slot=(Ptr32<Ptr32<Service>>)((Ptr32<unsigned char>)this+Offset);(*slot)->vtable->release(*slot);*slot=zero;}};

extern "C" void w3d_cx12b_paired_visibility_apply_802c7c1c(Ptr32<Owner> self){if(self->enabled){
 Ptr32<int> flag=(Ptr32<int>)((Ptr32<unsigned char>)self+104);
 self->s40->vtable->visible(self->s40,*flag^1);self->s48->vtable->visible(self->s48,*flag^1);self->s56->vtable->visible(self->s56,*flag^1);
 self->s44->vtable->visible(self->s44,*flag);self->s52->vtable->visible(self->s52,*flag);self->s60->vtable->visible(self->s60,*flag);
}}




