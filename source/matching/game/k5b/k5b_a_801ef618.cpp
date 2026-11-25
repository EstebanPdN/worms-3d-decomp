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
struct K5bElementType;
struct K5bFieldDesc {
    char pad[4];
    unsigned short offset;
    char pad6[2];
    K5bElementType *element;
};
struct K5bArrayField { K5bFieldDesc *desc; };
extern "C" unsigned int w3d_auto_80200050(K5bElementType *type);
extern "C" void *w3d_k5b_array_ref_lock_801ef048(K5bArray **ref, unsigned int count, unsigned int element_size,
    unsigned int flags);
template <class T> inline const T &k5b_max(const T &a, const T &b)
{
    return a < b ? b : a;
}
static inline void *k5b_array_lock(K5bArray **ref, K5bArray *array, unsigned int count, unsigned int element_size,
    unsigned int flags)
{
    if (array->references == 1 && count == array->count) {
        ++array->locks;
        return array->data;
    }
    return w3d_k5b_array_ref_lock_801ef048(ref, count, element_size, flags);
}
extern "C" void *w3d_k5b_array_field_lock_801ef618(K5bArrayField *self, char *object, unsigned int count,
    unsigned int flags, unsigned int *previous)
{
    unsigned int offset = self->desc->offset;
    unsigned int element_size = w3d_auto_80200050(self->desc->element);
    K5bArray **ref = (K5bArray **)(object + offset);
    K5bArray *array = *ref;
    unsigned int wanted;
    if (previous != 0)
        *previous = array->count;
    if (flags & 2)
        wanted = array->count + count;
    else
        wanted = count;
    if (flags & 4)
        wanted = k5b_max(wanted, (unsigned int)array->count);
    return k5b_array_lock(ref, array, wanted, element_size, flags);
}
// desc: w3d_k5b_array_field_lock_801ef618: Appears to lock the array field of an object for writing: optional previous count, append (flag 2) or grow-only (flag 4) sizing, then the inline lock path.
