#include "w3d_ptr.h"
#line 1 "d_array_lock.cpp"
/* Copy-on-write arrays of 4-byte elements held by engine records (0x80240be4..).
 *
 * The record keeps a pointer to a shared array store. Observed store layout:
 *   +0x04 u16 reference count, +0x18 element count, +0x1c u16 lock count,
 *   +0x20 first element.
 * Each pair reads the current elements, or opens them for writing: flag 2
 * appends to the current count, flag 4 never shrinks below it. A store that is
 * unshared and already the right size is locked in place; otherwise the
 * external reserve call (element size 4) reallocates it.
 */
#include "d_types.h"

extern "C" {

typedef struct W3dArrayStore {
    unsigned char unknown_00[4];
    unsigned short references;
    unsigned char unknown_06[0x18 - 0x06];
    unsigned int count;
    unsigned short locks;
    unsigned char unknown_1e[0x20 - 0x1e];
    unsigned int data[1];
} W3dArrayStore;

typedef struct W3dArrayRef {
    Ptr32<W3dArrayStore> store;
} W3dArrayRef;

Ptr32<void> w3d_array_reserve_801ef048(Ptr32<W3dArrayRef> array, unsigned int count, unsigned int element_size,
    unsigned int flags);

static inline Ptr32<const unsigned int> w3d_array_max_count(Ptr32<const unsigned int> a, Ptr32<const unsigned int> b)
{
    return *a < *b ? w3d::R(b) : w3d::R(a);
}

/* Inline body shared by every record-specific write accessor below. */
static inline Ptr32<void> w3d_array_open(Ptr32<W3dArrayRef> array, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous)
{
    Ptr32<W3dArrayStore> store = array->store;
    unsigned int size;
    if (previous)
        *previous = store->count;
    if (flags & 2)
        size = store->count + count;
    else
        size = count;
    if (flags & 4) {
        unsigned int current = store->count;
        size = *w3d_array_max_count(&size, &current);
    }
    if (store->references == 1 && size == store->count) {
        store->locks++;
        return store->data;
    }
    return w3d_array_reserve_801ef048(array, size, 4, flags);
}

typedef struct W3dArrayOwner20 {
    unsigned char unknown_00[0x20];
    W3dArrayRef array;
} W3dArrayOwner20;

Ptr32<unsigned int> w3d_array_read_80240be4(Ptr32<W3dArrayOwner20> owner, Ptr32<unsigned int> count)
{
    Ptr32<W3dArrayStore> store = owner->array.store;
    *count = store->count;
    return store->data;
}

Ptr32<void> w3d_array_write_80240bf8(Ptr32<W3dArrayOwner20> owner, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous)
{
    return w3d_array_open(&owner->array, count, flags, previous);
}

typedef struct W3dArrayOwner1c {
    unsigned char unknown_00[0x1c];
    W3dArrayRef array;
} W3dArrayOwner1c;

typedef struct W3dArrayOwner24 {
    unsigned char unknown_00[0x24];
    W3dArrayRef array;
} W3dArrayOwner24;

typedef struct W3dArrayOwner28 {
    unsigned char unknown_00[0x28];
    W3dArrayRef array;
} W3dArrayOwner28;

Ptr32<unsigned int> w3d_array_read_80240cb4(Ptr32<W3dArrayOwner1c> owner, Ptr32<unsigned int> count)
{
    Ptr32<W3dArrayStore> store = owner->array.store;
    *count = store->count;
    return store->data;
}

Ptr32<void> w3d_array_write_80240cc8(Ptr32<W3dArrayOwner1c> owner, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous)
{
    return w3d_array_open(&owner->array, count, flags, previous);
}

Ptr32<unsigned int> w3d_array_read_80240d84(Ptr32<W3dArrayOwner24> owner, Ptr32<unsigned int> count)
{
    Ptr32<W3dArrayStore> store = owner->array.store;
    *count = store->count;
    return store->data;
}

Ptr32<void> w3d_array_write_80240d98(Ptr32<W3dArrayOwner24> owner, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous)
{
    return w3d_array_open(&owner->array, count, flags, previous);
}

Ptr32<unsigned int> w3d_array_read_80240e54(Ptr32<W3dArrayOwner24> owner, Ptr32<unsigned int> count)
{
    Ptr32<W3dArrayStore> store = owner->array.store;
    *count = store->count;
    return store->data;
}

Ptr32<void> w3d_array_write_80240e68(Ptr32<W3dArrayOwner24> owner, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous)
{
    return w3d_array_open(&owner->array, count, flags, previous);
}

Ptr32<unsigned int> w3d_array_read_80240f24(Ptr32<W3dArrayOwner28> owner, Ptr32<unsigned int> count)
{
    Ptr32<W3dArrayStore> store = owner->array.store;
    *count = store->count;
    return store->data;
}

Ptr32<void> w3d_array_write_80240f38(Ptr32<W3dArrayOwner28> owner, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous)
{
    return w3d_array_open(&owner->array, count, flags, previous);
}

Ptr32<unsigned int> w3d_array_read_80240ff4(Ptr32<W3dArrayOwner24> owner, Ptr32<unsigned int> count)
{
    Ptr32<W3dArrayStore> store = owner->array.store;
    *count = store->count;
    return store->data;
}

Ptr32<void> w3d_array_write_80241008(Ptr32<W3dArrayOwner24> owner, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous)
{
    return w3d_array_open(&owner->array, count, flags, previous);
}

Ptr32<unsigned int> w3d_array_read_802410c4(Ptr32<W3dArrayOwner24> owner, Ptr32<unsigned int> count)
{
    Ptr32<W3dArrayStore> store = owner->array.store;
    *count = store->count;
    return store->data;
}

Ptr32<void> w3d_array_write_802410d8(Ptr32<W3dArrayOwner24> owner, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous)
{
    return w3d_array_open(&owner->array, count, flags, previous);
}

Ptr32<unsigned int> w3d_array_read_80241194(Ptr32<W3dArrayOwner28> owner, Ptr32<unsigned int> count)
{
    Ptr32<W3dArrayStore> store = owner->array.store;
    *count = store->count;
    return store->data;
}

Ptr32<void> w3d_array_write_802411a8(Ptr32<W3dArrayOwner28> owner, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous)
{
    return w3d_array_open(&owner->array, count, flags, previous);
}

Ptr32<unsigned int> w3d_array_read_80241264(Ptr32<W3dArrayOwner24> owner, Ptr32<unsigned int> count)
{
    Ptr32<W3dArrayStore> store = owner->array.store;
    *count = store->count;
    return store->data;
}

Ptr32<void> w3d_array_write_80241278(Ptr32<W3dArrayOwner24> owner, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous)
{
    return w3d_array_open(&owner->array, count, flags, previous);
}

}


