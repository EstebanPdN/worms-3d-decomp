#include "w3d_ptr.h"
#line 1 "cx9c_release_owner_80343588.cpp"
/* Inferred owner teardown, original 0x80343588: held interfaces at
 * observed offsets 172,168,164,160,156,152,148,144,140,136,132,128,124. Virtual release is slot+16;
 * complete-object deletion uses flag bit0 and the original small-data heap.
 * Calls are explicit in member order, matching observed unrolled destruction.
 */
struct Cx9cInterface{Ptr32<Ptr32<void>> vtable;};
struct Cx9cHeap{unsigned int opaque[2];};
struct Cx9cOwner{unsigned char opaque[124];Ptr32<Cx9cInterface> held[13];};
extern "C" Cx9cHeap cx9c_heap_804b0044;
extern "C" void cx9c_base_destroy_8015a39c(Ptr32<Cx9cOwner>,int);
extern "C" void cx9c_heap_release_80209920(Ptr32<Cx9cHeap>,Ptr32<void>);
static inline void cx9c_release(Ptr32<Cx9cInterface> p){if(p)((Ptr32<void (Ptr32<Cx9cInterface>)>)p->vtable[4])(p);}
extern "C" void w3d_cx9c_release_owner_80343588(Ptr32<Cx9cOwner> self,unsigned int flags){
 cx9c_release(self->held[12]);
 cx9c_release(self->held[11]);
 cx9c_release(self->held[10]);
 cx9c_release(self->held[9]);
 cx9c_release(self->held[8]);
 cx9c_release(self->held[7]);
 cx9c_release(self->held[6]);
 cx9c_release(self->held[5]);
 cx9c_release(self->held[4]);
 cx9c_release(self->held[3]);
 cx9c_release(self->held[2]);
 cx9c_release(self->held[1]);
 cx9c_release(self->held[0]);
 cx9c_base_destroy_8015a39c(self,0);
 if(flags&1)cx9c_heap_release_80209920(&cx9c_heap_804b0044,self);
}


