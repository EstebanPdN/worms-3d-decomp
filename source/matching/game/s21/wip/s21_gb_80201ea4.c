// desc: Appears to read an array of 32-bit words from the inner stream and byte-swap each in place, or skip the bytes through virtual slot 7 when no buffer is given, returning the status.
struct S21Stream;
struct S21StreamMethods { void (*reserved[5])(void); int (*read)(struct S21Stream *, void *, int, int); void (*reserved1)(void); int (*skip)(struct S21Stream *, int, int, int); };
struct S21Stream { struct S21StreamMethods *methods; };
struct S21Reader { char pad[20]; struct S21Stream *stream; };
int w3d_s21_read_u32_array_80201ea4(struct S21Reader *self, unsigned *out, unsigned count)
{
    int status;
    unsigned i;
    if (out == 0)
        return self->stream->methods->skip(self->stream, count << 2, 1, 0);
    status = self->stream->methods->read(self->stream, out, count << 2, 0);
    i = 0;
    if (i < count) {
        unsigned *word = out;
        do {
            unsigned value;
            word++;
            i++;
            value = word[-1];
            word[-1] = (value << 24) | ((value << 8) & 0xff0000) | ((value >> 8) & 0xff00) | (value >> 24);
        } while (i < count);
    }
    return status;
}
