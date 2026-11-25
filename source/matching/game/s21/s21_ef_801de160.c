// desc: Appears to serialize the object through a writer: it writes the element count, each element of the counted array and an embedded block through virtual slots, returning zero.
struct S21Writer;
struct S21WriterMethods { void (*reserved[8])(void); void (*write_item)(struct S21Writer *, int, int); void (*reserved1[23])(void); void (*write_block)(struct S21Writer *, void *, int, int); void (*reserved2[7])(void); void (*write_count)(struct S21Writer *, unsigned, int); };
struct S21Writer { struct S21WriterMethods *methods; };
struct S21Array { unsigned count; int reserved; int *items; };
struct S21Object { char pad[20]; struct S21Array array; char block[4]; };
int w3d_s21_write_array_801de160(struct S21Object *self, struct S21Writer *writer)
{
    unsigned i = 0;
    writer->methods->write_count(writer, self->array.count, 0);
    if (i < self->array.count) {
        struct S21Array *array = &self->array;
        unsigned offset = 0;
        do {
            writer->methods->write_item(writer, *(int *)(offset + (unsigned)array->items), 0);
            i++;
            offset += 4;
        } while (i < self->array.count);
    }
    writer->methods->write_block(writer, self->block, 0, 0);
    return 0;
}
