#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k5b_a_801efacc.c"
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
int w3d_k5b_array_field_write_801efacc(Ptr32<struct K5bArrayField> self, Ptr32<struct K5bStream> stream, Ptr32<char> object)
{
    Ptr32<struct K5bArray> array = *(Ptr32<Ptr32<struct K5bArray>>)(object + self->desc->offset);
    unsigned int count = array->count;
    Ptr32<unsigned char> data = array->data;
    unsigned int element_size = w3d_auto_80200050(self->desc->element);
    int result;
    ((Ptr32<int (Ptr32<struct K5bStream>, unsigned int, int)>)stream->vtable[40])(stream, array->count, self->desc->name);
    if (element_size == 1)
        result = ((Ptr32<int (Ptr32<struct K5bStream>, Ptr32<unsigned char>, unsigned int, int)>)stream->vtable[38])(stream, data, count,
            self->desc->name);
    else
        result = ((Ptr32<int (Ptr32<struct K5bElementType>, Ptr32<struct K5bStream>, Ptr32<unsigned char>, int, unsigned int, int)>)
        self->desc->element->vtable[15])(self->desc->element, stream, data, self->desc->name, count, 0);
    return result;
}
// desc: w3d_k5b_array_field_write_801efacc: Appears to write an array field to a stream: its count (stream slot 40), then raw bytes (slot 38) for byte elements or per-element writes through the element type (slot 15).

}
