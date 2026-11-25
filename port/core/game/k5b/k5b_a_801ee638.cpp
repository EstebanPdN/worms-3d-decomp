#include "w3d_ptr.h"
#line 1 "k5b_a_801ee638.cpp"
struct K5bArrayAllocator { Ptr32<Ptr32<void>> vtable; };
struct K5bIface { Ptr32<Ptr32<void>> vtable; };
struct K5bIfaceArray {
    Ptr32<Ptr32<void>> vtable;
    unsigned short references;
    char pad6[14];
    unsigned int capacity;
    unsigned int count;
    char pad28[4];
    Ptr32<K5bIface> items[1];
};
template <class T> inline const T &k5b_min(const T &a, const T &b)
{
    return b < a ? b : a;
}
extern "C" Ptr32<K5bIfaceArray> w3d_h1_result_then_finish_801ee410(Ptr32<K5bIfaceArray> self, unsigned int count,
    unsigned int element_size, int keep);
extern "C" Ptr32<K5bIfaceArray> w3d_k5b_iface_array_resize_owned_801ee638(Ptr32<K5bIfaceArray> self, unsigned int count,
    unsigned int element_size, int keep)
{
    unsigned int bytes;
    Ptr32<K5bArrayAllocator> allocator;
    Ptr32<K5bIfaceArray> copy;
    Ptr32<Ptr32<K5bIface>> source;
    Ptr32<Ptr32<K5bIface>> target;
    unsigned int n;
    unsigned int i;
    if (keep == 0 || self->references != 1)
        return w3d_h1_result_then_finish_801ee410(self, count, element_size, keep);
    bytes = count * element_size;
    if (self->capacity >= bytes)
        return ((Ptr32<Ptr32<K5bIfaceArray> (Ptr32<K5bIfaceArray>, unsigned int, int)>)self->vtable[8])(self, count, 0);
    allocator = ((Ptr32<Ptr32<K5bArrayAllocator> (Ptr32<K5bIfaceArray>)>)self->vtable[9])(self);
    copy = ((Ptr32<Ptr32<K5bIfaceArray> (Ptr32<K5bArrayAllocator>, unsigned int, int)>)allocator->vtable[3])(allocator, bytes, 0);
    source = self->items;
    target = copy->items;
    n = k5b_min((unsigned int)self->count, count);
    for (i = 0; i < n; i++)
        target[i] = source[i];
    for (; i < count; i++)
        target[i] = 0;
    copy->count = count;
    self->count = 0;
    ((Ptr32<void (Ptr32<K5bIfaceArray>)>)self->vtable[4])(self);
    return copy;
}
// desc: w3d_k5b_iface_array_resize_owned_801ee638: Appears to resize a solely owned interface array: in place when capacity allows, else move entries into a new allocation, null the rest and release the old one.


