#include "w3d_ptr.h"
#line 1 "cx9c_release_actor_record.cpp"
/* Observed held interfaces +88/+152/+156/+160/+164 and an eight-byte
 * embedded object +144. Flag bit zero releases the complete object using
 * the original small-data heap object. Names are inferred. */
struct Cx9cInterface {Ptr32<Ptr32<void>> vtable;};
struct Cx9cMember {unsigned int opaque[2];};
struct Cx9cHeap {unsigned int opaque[2];};
struct Cx9cOwner {unsigned char opaque[88];Ptr32<Cx9cInterface> first;unsigned char unknown_5c[52];Cx9cMember member;Ptr32<Cx9cInterface> a; Ptr32<Cx9cInterface> b; Ptr32<Cx9cInterface> c; Ptr32<Cx9cInterface> d;};
extern "C" Cx9cHeap cx9c_heap_804b0044;
extern "C" void cx9c_member_destroy_80126230(Ptr32<Cx9cMember>,int);
extern "C" void cx9c_base_destroy_8015a39c(Ptr32<Cx9cOwner>,int);
extern "C" void cx9c_heap_release_80209920(Ptr32<Cx9cHeap>,Ptr32<void>);
static inline void cx9c_release(Ptr32<Cx9cInterface> value) {if(value)((Ptr32<void (Ptr32<Cx9cInterface>)>)value->vtable[4])(value);}
extern "C" void w3d_cx9c_release_actor_record_80347240(Ptr32<Cx9cOwner> self,unsigned int flags) {
 cx9c_release(self->d);cx9c_release(self->c);cx9c_release(self->b);cx9c_release(self->a);
 cx9c_member_destroy_80126230(&self->member,2);cx9c_release(self->first);
 cx9c_base_destroy_8015a39c(self,0);
 if(flags&1)cx9c_heap_release_80209920(&cx9c_heap_804b0044,self);
}


