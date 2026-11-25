struct K5bStream { void **vtable; };
struct K5bElementType { void **vtable; };
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
struct K5bFieldDesc {
    int name;
    unsigned short offset;
    char pad6[2];
    struct K5bElementType *element;
};
struct K5bArrayField { struct K5bFieldDesc *desc; };
extern unsigned int w3d_auto_80200050(struct K5bElementType *type);
extern void *w3d_k5b_array_ref_lock_801ef048(struct K5bArray **ref, unsigned int count, unsigned int element_size,
    unsigned int flags);
static inline void *k5b_array_lock(char *object, unsigned int offset, unsigned int count, unsigned int element_size,
    unsigned int flags)
{
    struct K5bArray **ref = (struct K5bArray **)(object + offset);
    struct K5bArray *array = *ref;
    if (array->references == 1 && count == array->count) {
        ++array->locks;
        return array->data;
    }
    return w3d_k5b_array_ref_lock_801ef048(ref, count, element_size, flags);
}
int w3d_k5b_array_field_read_801efb94(struct K5bArrayField *self, struct K5bStream *stream, char *object)
{
    unsigned int count;
    unsigned char *data;
    int result;
    if (((int (*)(struct K5bStream *, unsigned int *, int))stream->vtable[42])(stream, &count, self->desc->name) < 0
        || count == 0)
        return 0;
    if (object == 0) {
        data = 0;
    } else {
        unsigned int offset = self->desc->offset;
        unsigned int element_size = w3d_auto_80200050(self->desc->element);
        data = k5b_array_lock(object, offset, count, element_size, 1);
    }
    if (w3d_auto_80200050(self->desc->element) != 1)
        result = ((int (*)(struct K5bElementType *, struct K5bStream *, unsigned char *, int, unsigned int, int))
            self->desc->element->vtable[16])(self->desc->element, stream, data, self->desc->name, count, 0);
    else
        result = ((int (*)(struct K5bStream *, unsigned char *, unsigned int, int))stream->vtable[40])(stream, data, count,
        self->desc->name);
    return result;
}
// desc: w3d_k5b_array_field_read_801efb94: Appears to read an array field from a stream: its count (slot 42), lock the object's array for that count, then raw bytes (slot 40) or per-element reads (slot 16).
