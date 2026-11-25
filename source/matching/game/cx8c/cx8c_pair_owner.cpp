/* Observed: two allocations of 20 and 16 bytes, three pointer stores each,
 * allocator slots left untouched, and an owner word at +8. Names inferred.
 * The original frame is 32 bytes, with an eight-byte gap below saved GPRs.
 * The local reservation reproducing that gap is inferred. */
extern "C" void *cx8c_allocate_801fe1d8(unsigned int);
struct Cx8cVectorTail {unsigned int allocator;void *capacity;
 void initialize(void *zero) {capacity=zero;}};
struct Cx8cVector {void *begin,*end;Cx8cVectorTail tail;
 void initialize(void *zero) {begin=zero;end=zero;tail.initialize(zero);}};
struct Cx8cLargeVector: Cx8cVector {unsigned int unknown;};
struct Cx8cOwner {Cx8cLargeVector *first;Cx8cVector *second;unsigned int value;};
extern "C" void w3d_cx8c_pair_owner_8034ae84(Cx8cOwner *self,unsigned int value) {
 volatile unsigned char reservation[8];
 Cx8cLargeVector *first=(Cx8cLargeVector *)cx8c_allocate_801fe1d8(20);first->initialize(0);self->first=first;
 Cx8cVector *second=(Cx8cVector *)cx8c_allocate_801fe1d8(16);self->value=value;second->initialize(0);self->second=second;
}
