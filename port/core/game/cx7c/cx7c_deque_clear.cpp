#include "w3d_ptr.h"
#line 1 "cx7c_deque_clear.cpp"
/* Inferred STL-style deque clear, original 0x8035ee24.
 * start/finish are 16-byte iterators: current +0, first +4, last +8,
 * map-node +12. Releases intermediate buffers and the finish buffer when
 * distinct, retains the start buffer, then resets finish to start.
 */
extern "C" void cx7c_deallocate_802134fc(Ptr32<void>);
struct Cx7cDequeIterator {Ptr32<Ptr32<void>> current; Ptr32<Ptr32<void>> first; Ptr32<Ptr32<void>> last;Ptr32<Ptr32<Ptr32<void>>> node;};
struct Cx7cDeque {Cx7cDequeIterator start,finish;};
extern "C" void w3d_cx7c_deque_clear_8035ee24(Ptr32<Cx7cDeque> self)
{
    for (Ptr32<Ptr32<Ptr32<void>>> node=self->start.node+1;node<self->finish.node;++node)
        if (*node) cx7c_deallocate_802134fc(*node);
    if (self->start.node!=self->finish.node)
        if (self->finish.first) cx7c_deallocate_802134fc(self->finish.first);
    self->finish=self->start;
}


