#include "w3d_ptr.h"
#line 1 "cx9c_actor_array_80344a68.cpp"
/* Observed 184-byte element stride and context pointer at +108. The array
 * allocation has the reference compiler's eight-byte cookie; its first
 * word holds the element count. Element/owner names are inferred. */
extern "C" Ptr32<void> cx9c_array_allocate_800dc5bc(unsigned int);
struct Cx9cRecord_800de6c4 {
 unsigned char opaque[108];Ptr32<void> context;unsigned char tail[72];
 Cx9cRecord_800de6c4();~Cx9cRecord_800de6c4(){}
 static void *operator new[](__SIZE_TYPE__ bytes){return cx9c_array_allocate_800dc5bc(bytes);}
};
struct Cx9cOwner {unsigned int opaque;Ptr32<Cx9cRecord_800de6c4> begin;Ptr32<void> context;};
extern "C" void w3d_cx9c_actor_array_80344a68(Ptr32<Cx9cOwner> self,unsigned int count) {
 self->begin=w3d::new_array<Cx9cRecord_800de6c4>(count);
 for(unsigned int i=0;i<count;++i)self->begin[i].context=self->context;
}


