#include "w3d_ptr.h"
#line 1 "cx8b_transfer_refill_guard_802e2248.cpp"

struct Cx8bTransferRecord {unsigned int unknown00,occupied,unknown08;};
struct Cx8bTransferQueue {char unknown00[188];int pending;unsigned int unknownc0;int index;char unknownc8[28];Cx8bTransferRecord entries[8];};
struct Cx8bTransferQueueOwner {unsigned int unknown00;Ptr32<Cx8bTransferQueue> queue;};
extern "C" unsigned int fn_802fdb6c();
extern "C" int fn_802fdb94(unsigned int);
extern "C" void fn_802e128c(Ptr32<Cx8bTransferQueueOwner>);
static inline int occupied(Ptr32<Cx8bTransferQueue> queue) {return queue->entries[queue->index].occupied!=0;}
extern "C" void w3d_cx8b_transfer_refill_guard_802e2248(Ptr32<Cx8bTransferQueueOwner> self) {
 unsigned int guard=fn_802fdb6c();Ptr32<Cx8bTransferQueue> queue=self->queue;
 if(!occupied(queue) && !queue->pending) fn_802e128c(self);
 fn_802fdb94(guard);
}



