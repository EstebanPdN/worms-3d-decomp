// desc: Appears to call a virtual slot of a stream for each element of an array, advancing a non-null element pointer, stopping at the first negative status and returning zero otherwise.
struct S21Stream;
struct S21StreamMethods { void (*reserved[8])(void); int (*read_item)(struct S21Stream *, int *, int); };
struct S21Stream { struct S21StreamMethods *methods; };
int w3d_s21_read_items_80201848(struct S21Stream *stream, int *items, unsigned count, int context)
{
    unsigned i = 0;
    if (i < count) {
        do {
            int status = stream->methods->read_item(stream, items, context);
            if (status < 0)
                return status;
            if (items)
                items++;
            i++;
        } while (i < count);
    }
    return 0;
}
