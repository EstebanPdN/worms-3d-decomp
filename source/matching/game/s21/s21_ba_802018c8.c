// desc: Appears to read single bytes from the inner stream into an array of booleans, stopping at the first negative status and returning zero otherwise.
struct S21Stream;
struct S21StreamMethods { void (*reserved[5])(void); int (*read)(struct S21Stream *, void *, int, int); };
struct S21Stream { struct S21StreamMethods *methods; };
struct S21Reader { char pad[20]; struct S21Stream *stream; };
int w3d_s21_read_bools_802018c8(struct S21Reader *self, int *out, unsigned count)
{
    unsigned i = 0;
    while (i < count) {
        unsigned char value;
        int status = self->stream->methods->read(self->stream, &value, 1, 0);
        if (status < 0)
            return status;
        if (out)
            *out++ = value ? 1 : 0;
        i++;
    }
    return 0;
}
