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
int w3d_k5b_array_field_write_801efacc(struct K5bArrayField *self, struct K5bStream *stream, char *object)
{
    struct K5bArray *array = *(struct K5bArray **)(object + self->desc->offset);
    unsigned int count = array->count;
    unsigned char *data = array->data;
    unsigned int element_size = w3d_auto_80200050(self->desc->element);
    int result;
    ((int (*)(struct K5bStream *, unsigned int, int))stream->vtable[40])(stream, array->count, self->desc->name);
    if (element_size == 1)
        result = ((int (*)(struct K5bStream *, unsigned char *, unsigned int, int))stream->vtable[38])(stream, data, count,
            self->desc->name);
    else
        result = ((int (*)(struct K5bElementType *, struct K5bStream *, unsigned char *, int, unsigned int, int))
        self->desc->element->vtable[15])(self->desc->element, stream, data, self->desc->name, count, 0);
    return result;
}
// desc: w3d_k5b_array_field_write_801efacc: Appears to write an array field to a stream: its count (stream slot 40), then raw bytes (slot 38) for byte elements or per-element writes through the element type (slot 15).
