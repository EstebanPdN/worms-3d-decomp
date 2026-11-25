#include "w3d_ptr.h"
#line 1 "cx9c_actor_array_803449cc.cpp"
/* Observed 176-byte element stride and context pointer at +108. The array
 * allocation has the reference compiler's eight-byte cookie; its first
 * word holds the element count. Element/owner names are inferred. */
extern "C" Ptr32<void> cx9c_array_allocate_800dc5bc(unsigned int);
struct Cx9cRecord_800e6738 {
 unsigned char opaque[108];Ptr32<void> context;unsigned char tail[64];
 Cx9cRecord_800e6738();~Cx9cRecord_800e6738(){}
 static void *operator new[](__SIZE_TYPE__ bytes){return cx9c_array_allocate_800dc5bc(bytes);}
};
struct Cx9cOwner {unsigned int opaque;Ptr32<Cx9cRecord_800e6738> begin;Ptr32<void> context;};
extern "C" void w3d_cx9c_actor_array_803449cc(Ptr32<Cx9cOwner> self,unsigned int count) {
 self->begin=w3d::new_array<Cx9cRecord_800e6738>(count);
 for(unsigned int i=0;i<count;++i)self->begin[i].context=self->context;
}


