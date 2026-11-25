#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k5b_a_801ee338.c"
struct K5bArrayAllocator { Ptr32<Ptr32<void>> vtable; };
struct K5bByteArray {
    Ptr32<Ptr32<void>> vtable;
    unsigned short references;
    char pad6[14];
    unsigned int capacity;
    unsigned int count;
    char pad28[4];
    unsigned char data[1];
};
extern unsigned int w3d_s21_power_of_two_801ee2f8(unsigned int value);
extern Ptr32<void> w3d_memcpy_802eee50(Ptr32<void> target, Ptr32<const void> source, unsigned int size);
Ptr32<struct K5bByteArray> w3d_k5b_byte_array_resized_801ee338(Ptr32<struct K5bByteArray> self, unsigned int count,
    unsigned int element_size, int keep)
{
    unsigned int slots;
    unsigned int bytes;
    Ptr32<struct K5bArrayAllocator> allocator;
    Ptr32<struct K5bByteArray> copy;
    if (self->capacity == 0 || self->references > 1)
        slots = count;
    else
        slots = w3d_s21_power_of_two_801ee2f8(count);
    bytes = slots * element_size;
    allocator = ((Ptr32<Ptr32<struct K5bArrayAllocator> (Ptr32<struct K5bByteArray>)>)self->vtable[9])(self);
    copy = ((Ptr32<Ptr32<struct K5bByteArray> (Ptr32<struct K5bArrayAllocator>, unsigned int, int)>)allocator->vtable[3])(allocator, bytes, 0);
    if (keep != 0) {
        if (bytes > self->capacity)
            w3d_memcpy_802eee50(copy->data, self->data, self->capacity);
        else
            w3d_memcpy_802eee50(copy->data, self->data, bytes);
    }
    copy->count = count;
    return copy;
}
// desc: w3d_k5b_byte_array_resized_801ee338: Appears to allocate a resized plain array (power-of-two growth when owned), copy the old bytes up to the smaller size when asked and set the count.

}
