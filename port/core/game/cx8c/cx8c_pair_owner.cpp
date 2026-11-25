#include "w3d_ptr.h"
#line 1 "cx8c_pair_owner.cpp"
/* Observed: two allocations of 20 and 16 bytes, three pointer stores each,
 * allocator slots left untouched, and an owner word at +8. Names inferred.
 * The original frame is 32 bytes, with an eight-byte gap below saved GPRs.
 * The local reservation reproducing that gap is inferred. */
extern "C" Ptr32<void> cx8c_allocate_801fe1d8(unsigned int);
struct Cx8cVectorTail {unsigned int allocator;Ptr32<void> capacity;
 void initialize(Ptr32<void> zero) {capacity=zero;}};
struct Cx8cVector {Ptr32<void> begin; Ptr32<void> end;Cx8cVectorTail tail;
 void initialize(Ptr32<void> zero) {begin=zero;end=zero;tail.initialize(zero);}};
struct Cx8cLargeVector: Cx8cVector {unsigned int unknown __attribute__((aligned(__alignof__(Cx8cVector))));};
struct Cx8cOwner {Ptr32<Cx8cLargeVector> first;Ptr32<Cx8cVector> second;unsigned int value;};
extern "C" void w3d_cx8c_pair_owner_8034ae84(Ptr32<Cx8cOwner> self,unsigned int value) {
 volatile unsigned char reservation[8];
 Ptr32<Cx8cLargeVector> first=(Ptr32<Cx8cLargeVector>)cx8c_allocate_801fe1d8(20);first->initialize(0);self->first=first;
 Ptr32<Cx8cVector> second=(Ptr32<Cx8cVector>)cx8c_allocate_801fe1d8(16);self->value=value;second->initialize(0);self->second=second;
}


