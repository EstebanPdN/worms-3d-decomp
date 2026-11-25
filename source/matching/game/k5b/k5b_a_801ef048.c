struct K5bArrayAllocator { void **vtable; };
struct K5bArray {
    void **vtable;
    unsigned short references;
    char pad6[14];
    unsigned int capacity;
    unsigned int count;
    unsigned short locks;
    char pad30[2];
    unsigned char data[1];
};
typedef struct K5bArray *(*K5bArrayResize)(struct K5bArray *, unsigned int, unsigned int, int);
typedef void (*K5bArraySetCount)(struct K5bArray *, unsigned int, int);
typedef void (*K5bArrayRef)(struct K5bArray *);
void *w3d_k5b_array_ref_lock_801ef048(struct K5bArray **ref, unsigned int count, unsigned int element_size,
    unsigned int flags)
{
    struct K5bArray *array = *ref;
    struct K5bArrayAllocator *allocator = ((struct K5bArrayAllocator *(*)(struct K5bArray *))array->vtable[9])(array);
    struct K5bArray *empty = ((struct K5bArray *(*)(struct K5bArrayAllocator *))allocator->vtable[4])(allocator);
    if (array->references > 1 || array->capacity < count * element_size) {
        struct K5bArray *resized = ((K5bArrayResize)array->vtable[7])(array, count, element_size, (flags & 1) == 0);
        ((K5bArrayRef)resized->vtable[3])(resized);
        array = resized;
        *ref = array;
    } else {
        ((K5bArraySetCount)array->vtable[8])(array, count, 0);
        if (count == 0 && (flags & 8) != 0) {
            ((K5bArrayRef)array->vtable[4])(array);
            ((K5bArrayRef)empty->vtable[3])(empty);
            *ref = empty;
            array = empty;
        }
    }
    ++array->locks;
    return array->data;
}
// desc: w3d_k5b_array_ref_lock_801ef048: Appears to make a referenced array writable for count elements (resize or copy-on-write, empty shared array when cleared), bump its lock count and return its data.
