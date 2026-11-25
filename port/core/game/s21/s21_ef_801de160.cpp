#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ef_801de160.c"
// desc: Appears to serialize the object through a writer: it writes the element count, each element of the counted array and an embedded block through virtual slots, returning zero.
struct S21Writer;
struct S21WriterMethods { Ptr32<void (void)> reserved[8]; Ptr32<void (Ptr32<struct S21Writer>, int, int)> write_item; Ptr32<void (void)> reserved1[23]; Ptr32<void (Ptr32<struct S21Writer>, Ptr32<void>, int, int)> write_block; Ptr32<void (void)> reserved2[7]; Ptr32<void (Ptr32<struct S21Writer>, unsigned int, int)> write_count; };
struct S21Writer { Ptr32<struct S21WriterMethods> methods; };
struct S21Array { unsigned count; int reserved; Ptr32<int> items; };
struct S21Object { char pad[20]; struct S21Array array; char block[4]; };
int w3d_s21_write_array_801de160(Ptr32<struct S21Object> self, Ptr32<struct S21Writer> writer)
{
    unsigned i = 0;
    writer->methods->write_count(writer, self->array.count, 0);
    if (i < self->array.count) {
        Ptr32<struct S21Array> array = &self->array;
        unsigned offset = 0;
        do {
            writer->methods->write_item(writer, *(Ptr32<int>)w3d::G((offset + (unsigned)w3d::H(array->items))), 0);
            i++;
            offset += 4;
        } while (i < self->array.count);
    }
    writer->methods->write_block(writer, self->block, 0, 0);
    return 0;
}

}
