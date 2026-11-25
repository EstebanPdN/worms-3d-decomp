#include "w3d_ptr.h"
#line 1 "cx7c_deque_push_front.cpp"
/* Inferred pointer-deque push_front auxiliary, original 0x8035f0cc.
 * Two 16-byte iterators occupy +0/+16. Allocator/map pointer/map size are +32/+36/+40.
 * A node contains 32 pointers (128 bytes). Value construction is placement
 * new with throw(), retaining the original null check before the store.
 */
inline void *operator new(__SIZE_TYPE__, void *p) throw() {return p;}
extern "C" {
Ptr32<void> cx7c_allocate_80212fd4(unsigned int);
Ptr32<void> cx7c_allocation_fallback_803413d8(unsigned int);
void cx7c_reallocate_map_8035ef1c(Ptr32<void>,unsigned int,bool);
}
struct Cx7cFrontIterator {
    Ptr32<Ptr32<void>> current; Ptr32<Ptr32<void>> first; Ptr32<Ptr32<void>> last; Ptr32<Ptr32<Ptr32<void>>> node;
    void set_node(Ptr32<Ptr32<Ptr32<void>>> next) {node=next;first=*next;last=first+32;}
};
struct Cx7cFrontDeque {Cx7cFrontIterator start,finish;unsigned int allocator;Ptr32<Ptr32<Ptr32<void>>> map;unsigned int map_size;
    void reserve_front(unsigned int count) {
        if (count>(unsigned int)(start.node-map)) cx7c_reallocate_map_8035ef1c(this,count,true);
    }};
extern "C" void w3d_cx7c_deque_push_front_aux_8035f0cc(Ptr32<Cx7cFrontDeque> self,Ptr32<void> const &value)
{
    Ptr32<void> copy=value;
    self->reserve_front(1);
    Ptr32<Ptr32<void>> node=(Ptr32<Ptr32<void>>)cx7c_allocate_80212fd4(128);
    if (!node) node=(Ptr32<Ptr32<void>>)cx7c_allocation_fallback_803413d8(128);
    *(self->start.node-1)=node;
    self->start.set_node(self->start.node-1);
    self->start.current=self->start.last-1;
    *(Ptr32<void> *)w3d::w3d_any_host(self->start.current) = Ptr32<void>(copy);
}


