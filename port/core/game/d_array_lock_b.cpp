#include "w3d_ptr.h"
#line 1 "d_array_lock_b.cpp"
/* Copy-on-write record arrays opened for writing (0x8024b8dc..0x80251670).
 *
 * Same store layout and logic as d_array_lock (refs +0x04, count +0x18,
 * lock count +0x1c, data +0x20); these accessors pass element unit 1 or 4
 * to the reserve call (0x801ef048). Owner records are described only by
 * the offset of their array reference.
 */
#include "d_types.h"

extern "C" {

typedef struct W3dArrayStoreB {
    unsigned char unknown_00[4];
    unsigned short references;
    unsigned char unknown_06[0x18 - 0x06];
    unsigned int count;
    unsigned short locks;
    unsigned char unknown_1e[0x20 - 0x1e];
    unsigned char data[1];
} W3dArrayStoreB;

typedef struct W3dArrayRefB {
    Ptr32<W3dArrayStoreB> store;
} W3dArrayRefB;

Ptr32<void> w3d_array_reserve_801ef048(Ptr32<W3dArrayRefB> array, unsigned int count, unsigned int unit,
    unsigned int flags);

static inline Ptr32<const unsigned int> w3d_array_max_count_b(Ptr32<const unsigned int> a, Ptr32<const unsigned int> b)
{
    return *a < *b ? w3d::R(b) : w3d::R(a);
}

/* Inline body shared by every write accessor; unit is the element unit. */
static inline Ptr32<void> w3d_array_open_b(Ptr32<W3dArrayRefB> array, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous, unsigned int unit)
{
    Ptr32<W3dArrayStoreB> store = array->store;
    unsigned int size;
    if (previous)
        *previous = store->count;
    if (flags & 2)
        size = store->count + count;
    else
        size = count;
    if (flags & 4) {
        unsigned int current = store->count;
        size = *w3d_array_max_count_b(&size, &current);
    }
    if (store->references == 1 && size == store->count) {
        store->locks++;
        return store->data;
    }
    return w3d_array_reserve_801ef048(array, size, unit, flags);
}

typedef struct W3dArrayOwnerB014 {
    unsigned char unknown_00[0x14];
    W3dArrayRefB array;
} W3dArrayOwnerB014;

typedef struct W3dArrayOwnerB018 {
    unsigned char unknown_00[0x18];
    W3dArrayRefB array;
} W3dArrayOwnerB018;

typedef struct W3dArrayOwnerB1ac {
    unsigned char unknown_00[0x1ac];
    W3dArrayRefB array;
} W3dArrayOwnerB1ac;

typedef struct W3dArrayOwnerB1dc {
    unsigned char unknown_00[0x1dc];
    W3dArrayRefB array;
} W3dArrayOwnerB1dc;

typedef struct W3dArrayOwnerB1e0 {
    unsigned char unknown_00[0x1e0];
    W3dArrayRefB array;
} W3dArrayOwnerB1e0;

Ptr32<void> w3d_array_write_8024b8dc(Ptr32<W3dArrayOwnerB018> owner, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous)
{
    return w3d_array_open_b(&owner->array, count, flags, previous, 1);
}

Ptr32<void> w3d_array_write_8024b998(Ptr32<W3dArrayOwnerB014> owner, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous)
{
    return w3d_array_open_b(&owner->array, count, flags, previous, 1);
}

Ptr32<void> w3d_array_write_80251064(Ptr32<W3dArrayOwnerB1ac> owner, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous)
{
    return w3d_array_open_b(&owner->array, count, flags, previous, 4);
}

Ptr32<void> w3d_array_write_802514f8(Ptr32<W3dArrayOwnerB1e0> owner, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous)
{
    return w3d_array_open_b(&owner->array, count, flags, previous, 1);
}

Ptr32<void> w3d_array_write_802515b4(Ptr32<W3dArrayOwnerB1dc> owner, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous)
{
    return w3d_array_open_b(&owner->array, count, flags, previous, 1);
}

}


