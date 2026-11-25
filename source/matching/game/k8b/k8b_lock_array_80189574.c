struct K8bArray {
    void **vtable;
    unsigned short references;
    char pad6[18];
    unsigned int count;
    unsigned short locks;
    char pad30[2];
    unsigned int data[1];
};
struct K8bArrayRef { struct K8bArray *store; };
struct K8bArrayOwner {
    char pad0[88];
    struct K8bArrayRef primary;
    char pad92[4];
    struct K8bArrayRef fallback;
};
extern void *w3d_k5b_array_ref_lock_801ef048(struct K8bArrayRef *ref, unsigned int count, unsigned int element_size, unsigned int flags);

static inline unsigned int *k8b_max_count(unsigned int *a, unsigned int *b)
{
    return *a < *b ? b : a;
}

static inline void *k8b_array_open(struct K8bArrayRef *array, unsigned int count, unsigned int flags, unsigned int *previous)
{
    struct K8bArray *store = array->store;
    unsigned int size;
    if (flags & 2)
        size = store->count + count;
    else
        size = count;
    if (previous)
        *previous = store->count;
    if (flags & 4) {
        unsigned int current = store->count;
        size = *k8b_max_count(&size, &current);
    }
    if (store->references == 1 && size == store->count) {
        store->locks++;
        return store->data;
    }
    return w3d_k5b_array_ref_lock_801ef048(array, size, 4, flags);
}

void *w3d_k8b_lock_array_80189574(char *self)
{
    struct K8bArrayOwner *owner = *(struct K8bArrayOwner **)(*(char **)(self + 168) + 48);
    unsigned int previous;
    void *result = k8b_array_open(&owner->primary, 0, 2, &previous);
    if (previous == 0) {
        unsigned int count = owner->fallback.store->count;
        if (count == 0)
            result = 0;
        else
            result = k8b_array_open(&owner->primary, count, 0, 0);
    }
    return result;
}
