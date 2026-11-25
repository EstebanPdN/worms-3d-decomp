// desc: Appears to deserialize the object from a reader: it reads the element count, resizes the array, reads each element in place and then an embedded block through virtual slots, returning zero.
struct S21Reader;
struct S21ReaderMethods { void (*reserved[8])(void); void (*read_item)(struct S21Reader *, void *, int); void (*reserved1[28])(void); void (*read_block)(struct S21Reader *, void *, int); void (*reserved2[4])(void); void (*read_count)(struct S21Reader *, unsigned *, int); };
struct S21Reader { struct S21ReaderMethods *methods; };
struct S21Array { unsigned count; int reserved; int *items; };
struct S21Object { char pad[20]; struct S21Array array; char block[4]; };
extern void fn_80210b90(struct S21Array *, unsigned);
int w3d_s21_read_array_801de218(struct S21Object *self, struct S21Reader *reader)
{
    unsigned count;
    unsigned i = 0;
    struct S21Array *array = &self->array;
    reader->methods->read_count(reader, &count, 0);
    fn_80210b90(array, count);
    if (i < count) {
        unsigned offset;
        struct S21Array *vector = array;
        offset = 0;
        do {
            reader->methods->read_item(reader, (void *)(offset + (unsigned)vector->items), 0);
            i++;
            offset += 4;
        } while (i < count);
    }
    reader->methods->read_block(reader, self->block, 0);
    return 0;
}
