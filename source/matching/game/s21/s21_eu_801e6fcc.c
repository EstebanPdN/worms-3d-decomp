// desc: Appears to call virtual slot 8 of a stream for each word of an array with a shared context, stopping at the first negative status and returning zero otherwise.
struct S21Stream;
struct S21StreamMethods { void (*reserved[8])(void); int (*write)(struct S21Stream *, int, int); };
struct S21Stream { struct S21StreamMethods *methods; };
int w3d_s21_write_words_801e6fcc(int unused, struct S21Stream *stream, int *items, int context, unsigned count)
{
    unsigned i = 0;
    if (i < count) {
        int *item = items;
        do {
            int status = stream->methods->write(stream, *item, context);
            item++;
            if (status < 0)
                return status;
            i++;
        } while (i < count);
    }
    return 0;
}
