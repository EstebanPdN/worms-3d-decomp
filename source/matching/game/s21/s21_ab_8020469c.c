// desc: Appears to call a virtual write slot on a stream for each word of an array with two shared arguments, stopping at the first negative status.
struct S21Stream;
struct S21StreamMethods { void (*reserved[36])(void); int (*write_item)(struct S21Stream *, int, int, int, int); };
struct S21Stream { struct S21StreamMethods *methods; };
int w3d_s21_write_items_8020469c(struct S21Stream *stream, int *items, unsigned count, int a, int b)
{
    unsigned i = 0;
    if (i < count) {
        do {
            int status = stream->methods->write_item(stream, *items, a, b, 0);
            items++;
            if (status < 0)
                return status;
            i++;
        } while (i < count);
    }
    return 0;
}
