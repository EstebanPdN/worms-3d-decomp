struct K5bArrayAllocator { void **vtable; };
struct K5bByteArray {
    void **vtable;
    unsigned short references;
    char pad6[14];
    unsigned int capacity;
    unsigned int count;
    char pad28[4];
    unsigned char data[1];
};
extern unsigned int w3d_s21_power_of_two_801ee2f8(unsigned int value);
extern void *w3d_memcpy_802eee50(void *target, const void *source, unsigned int size);
struct K5bByteArray *w3d_k5b_byte_array_resized_801ee338(struct K5bByteArray *self, unsigned int count,
    unsigned int element_size, int keep)
{
    unsigned int slots;
    unsigned int bytes;
    struct K5bArrayAllocator *allocator;
    struct K5bByteArray *copy;
    if (self->capacity == 0 || self->references > 1)
        slots = count;
    else
        slots = w3d_s21_power_of_two_801ee2f8(count);
    bytes = slots * element_size;
    allocator = ((struct K5bArrayAllocator *(*)(struct K5bByteArray *))self->vtable[9])(self);
    copy = ((struct K5bByteArray *(*)(struct K5bArrayAllocator *, unsigned int, int))allocator->vtable[3])(allocator, bytes, 0);
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
