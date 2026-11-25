// desc: Appears to call a virtual write slot on a stream for each entry of an integer array, passing a shared argument, and return zero.
struct S21Stream;
struct S21StreamMethods { void (*reserved[8])(void); int (*write)(struct S21Stream *, int, int); };
struct S21Stream { struct S21StreamMethods *methods; };
int w3d_s21_write_each_80204348(struct S21Stream *stream, int *items, unsigned count, int context)
{
    unsigned i = 0;
    if (i < count) {
        int *item = items;
        do {
            stream->methods->write(stream, *item, context);
            i++;
            item++;
        } while (i < count);
    }
    return 0;
}
