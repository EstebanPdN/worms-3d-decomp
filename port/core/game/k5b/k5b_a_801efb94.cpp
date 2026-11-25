#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k5b_a_801efb94.c"
struct K5bStream { Ptr32<Ptr32<void>> vtable; };
struct K5bElementType { Ptr32<Ptr32<void>> vtable; };
struct K5bArray {
    Ptr32<Ptr32<void>> vtable;
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
    Ptr32<struct K5bElementType> element;
};
struct K5bArrayField { Ptr32<struct K5bFieldDesc> desc; };
extern unsigned int w3d_auto_80200050(Ptr32<struct K5bElementType> type);
extern Ptr32<void> w3d_k5b_array_ref_lock_801ef048(Ptr32<Ptr32<struct K5bArray>> ref, unsigned int count, unsigned int element_size,
    unsigned int flags);
static inline Ptr32<void> k5b_array_lock(Ptr32<char> object, unsigned int offset, unsigned int count, unsigned int element_size,
    unsigned int flags)
{
    Ptr32<Ptr32<struct K5bArray>> ref = (Ptr32<Ptr32<struct K5bArray>>)(object + offset);
    Ptr32<struct K5bArray> array = *ref;
    if (array->references == 1 && count == array->count) {
        ++array->locks;
        return array->data;
    }
    return w3d_k5b_array_ref_lock_801ef048(ref, count, element_size, flags);
}
int w3d_k5b_array_field_read_801efb94(Ptr32<struct K5bArrayField> self, Ptr32<struct K5bStream> stream, Ptr32<char> object)
{
    unsigned int count;
    Ptr32<unsigned char> data;
    int result;
    if (((Ptr32<int (Ptr32<struct K5bStream>, Ptr32<unsigned int>, int)>)stream->vtable[42])(stream, &count, self->desc->name) < 0
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
        result = ((Ptr32<int (Ptr32<struct K5bElementType>, Ptr32<struct K5bStream>, Ptr32<unsigned char>, int, unsigned int, int)>)
            self->desc->element->vtable[16])(self->desc->element, stream, data, self->desc->name, count, 0);
    else
        result = ((Ptr32<int (Ptr32<struct K5bStream>, Ptr32<unsigned char>, unsigned int, int)>)stream->vtable[40])(stream, data, count,
        self->desc->name);
    return result;
}
// desc: w3d_k5b_array_field_read_801efb94: Appears to read an array field from a stream: its count (slot 42), lock the object's array for that count, then raw bytes (slot 40) or per-element reads (slot 16).

}
