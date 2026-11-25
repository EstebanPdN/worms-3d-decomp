/* Opens one of three array references of a mesh-like record for writing and
   falls back to the length of a second array when the first is empty.

   The store layout is observed: reference count (halfword at +4), element
   count (+24), lock count (halfword at +28) and data (+32). The shared body
   mirrors the copy-on-write open used elsewhere: flag 2 appends to the
   current count (here zero elements), the previous count is reported through
   a pointer, and an unshared store of the right size is locked in place;
   otherwise the external reserve call (0x801ef048) runs with the element
   unit. When the first array held no elements, its result is discarded and
   the array is reopened with the length of the array at +96, or null if that
   is zero. The three functions differ in which array reference they open
   (+88, +68, +84) and in the element unit (4, 8, 4). Offsets are observed;
   names and meanings are inferred. */
typedef struct B37Store { char pad[4]; unsigned short references; char gap[18]; unsigned int count; unsigned short locks; char gap2[2]; char data[1]; } B37Store;
typedef struct B37Ref { B37Store *store; } B37Ref;
typedef struct B37Mesh { char pad[68]; B37Ref a68; char gap0[12]; B37Ref a84; B37Ref a88; char gap1[4]; B37Ref a96; } B37Mesh;
typedef struct B37Storage { char pad[48]; B37Mesh *mesh; } B37Storage;
typedef struct B37Owner { char pad[168]; B37Storage *storage; } B37Owner;
extern void *fn_801ef048(B37Ref *, unsigned int, unsigned int, unsigned int);
static inline void *b37_open(B37Ref *array, unsigned int count, unsigned int flags, unsigned int *previous, unsigned int unit)
{
    B37Store *store = array->store;
    unsigned int size;
    if (previous) *previous = store->count;
    if (flags & 2) size = store->count + count;
    else size = count;
    if (store->references == 1 && size == store->count) { store->locks++; return store->data; }
    return fn_801ef048(array, size, unit, flags);
}
void *tsonnet_b37_open_80189574(B37Owner *self)
{
    B37Mesh *m = self->storage->mesh;
    unsigned int previous;
    void *r = b37_open(&m->a88, 0, 2, &previous, 4);
    if (previous == 0) {
        unsigned int k = m->a96.store->count;
        if (k == 0) return 0;
        previous = k;
        return b37_open(&m->a88, previous, 0, 0, 4);
    }
    return r;
}
void *tsonnet_b37_open_8018963c(B37Owner *self)
{
    B37Mesh *m = self->storage->mesh;
    unsigned int previous;
    void *r = b37_open(&m->a68, 0, 2, &previous, 8);
    if (previous == 0) {
        unsigned int k = m->a96.store->count;
        if (k == 0) return 0;
        previous = k;
        return b37_open(&m->a68, previous, 0, 0, 8);
    }
    return r;
}
void *tsonnet_b37_open_80189760(B37Owner *self)
{
    B37Mesh *m = self->storage->mesh;
    unsigned int previous;
    void *r = b37_open(&m->a84, 0, 2, &previous, 4);
    if (previous == 0) {
        unsigned int k = m->a96.store->count;
        if (k == 0) return 0;
        previous = k;
        return b37_open(&m->a84, previous, 0, 0, 4);
    }
    return r;
}
