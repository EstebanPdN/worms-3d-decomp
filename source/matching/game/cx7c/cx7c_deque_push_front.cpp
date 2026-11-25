/* Inferred pointer-deque push_front auxiliary, original 0x8035f0cc.
 * Two 16-byte iterators occupy +0/+16. Allocator/map pointer/map size are +32/+36/+40.
 * A node contains 32 pointers (128 bytes). Value construction is placement
 * new with throw(), retaining the original null check before the store.
 */
inline void *operator new(unsigned int, void *p) throw() {return p;}
extern "C" {
void *cx7c_allocate_80212fd4(unsigned int);
void *cx7c_allocation_fallback_803413d8(unsigned int);
void cx7c_reallocate_map_8035ef1c(void *,unsigned int,bool);
}
struct Cx7cFrontIterator {
    void **current,**first,**last; void ***node;
    void set_node(void ***next) {node=next;first=*next;last=first+32;}
};
struct Cx7cFrontDeque {Cx7cFrontIterator start,finish;unsigned int allocator;void ***map;unsigned int map_size;
    void reserve_front(unsigned int count) {
        if (count>(unsigned int)(start.node-map)) cx7c_reallocate_map_8035ef1c(this,count,true);
    }};
extern "C" void w3d_cx7c_deque_push_front_aux_8035f0cc(Cx7cFrontDeque *self,void *const &value)
{
    void *copy=value;
    self->reserve_front(1);
    void **node=(void **)cx7c_allocate_80212fd4(128);
    if (!node) node=(void **)cx7c_allocation_fallback_803413d8(128);
    *(self->start.node-1)=node;
    self->start.set_node(self->start.node-1);
    self->start.current=self->start.last-1;
    new (self->start.current) void *(copy);
}
