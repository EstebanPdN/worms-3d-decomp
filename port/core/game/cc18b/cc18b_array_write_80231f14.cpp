#include "w3d_ptr.h"
#line 1 "cc18b_array_write_80231f14.cpp"
// Observed copy-on-write array accessor: owner member +56, word elements.
extern "C" {
typedef struct Cc18bArrayStore {
    unsigned char unknown_00[4];
    unsigned short references;
    unsigned char unknown_06[0x18 - 0x06];
    unsigned int count;
    unsigned short locks;
    unsigned char unknown_1e[0x20 - 0x1e];
    unsigned int data[1];
} Cc18bArrayStore;

typedef struct Cc18bArrayRef {
    Ptr32<Cc18bArrayStore> store;
} Cc18bArrayRef;

Ptr32<void> w3d_array_reserve_801ef048(Ptr32<Cc18bArrayRef> array, unsigned int count, unsigned int element_size,
    unsigned int flags);

static inline Ptr32<const unsigned int> cc18b_array_max_count(Ptr32<const unsigned int> a, Ptr32<const unsigned int> b)
{
    return *a < *b ? w3d::R(b) : w3d::R(a);
}

/* Inline body shared by every record-specific write accessor below. */
static inline Ptr32<void> cc18b_array_open(Ptr32<Cc18bArrayRef> array, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous)
{
    Ptr32<Cc18bArrayStore> store = array->store;
    unsigned int size;
    if (previous)
        *previous = store->count;
    if (flags & 2)
        size = store->count + count;
    else
        size = count;
    if (flags & 4) {
        unsigned int current = store->count;
        size = *cc18b_array_max_count(&size, &current);
    }
    if (store->references == 1 && size == store->count) {
        store->locks++;
        return store->data;
    }
    return w3d_array_reserve_801ef048(array, size, 4, flags);
}

struct Cc18bArrayOwner { unsigned char unknown[56]; Cc18bArrayRef array; };
Ptr32<void> w3d_cc18b_array_write_80231f14(Ptr32<Cc18bArrayOwner> owner, unsigned int count, unsigned int flags, Ptr32<unsigned int> previous)
{ return cc18b_array_open(&owner->array, count, flags, previous); }
}


