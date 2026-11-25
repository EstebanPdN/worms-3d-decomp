/* Inferred STL-style deque clear, original 0x8035ee24.
 * start/finish are 16-byte iterators: current +0, first +4, last +8,
 * map-node +12. Releases intermediate buffers and the finish buffer when
 * distinct, retains the start buffer, then resets finish to start.
 */
extern "C" void cx7c_deallocate_802134fc(void *);
struct Cx7cDequeIterator {void **current,**first,**last;void ***node;};
struct Cx7cDeque {Cx7cDequeIterator start,finish;};
extern "C" void w3d_cx7c_deque_clear_8035ee24(Cx7cDeque *self)
{
    for (void ***node=self->start.node+1;node<self->finish.node;++node)
        if (*node) cx7c_deallocate_802134fc(*node);
    if (self->start.node!=self->finish.node)
        if (self->finish.first) cx7c_deallocate_802134fc(self->finish.first);
    self->finish=self->start;
}
