// desc: Appears to read an array of 32-bit words from the inner stream and byte-swap each in place, stopping on a negative status, or skip the bytes when no buffer is given, returning zero on success.
struct S21Stream;
struct S21StreamMethods { void (*reserved[5])(void); int (*read)(struct S21Stream *, void *, int, int); void (*reserved1)(void); int (*skip)(struct S21Stream *, int, int, int); };
struct S21Stream { struct S21StreamMethods *methods; };
struct S21Reader { char pad[20]; struct S21Stream *stream; };
int w3d_s21_read_u32_array_checked_802021dc(struct S21Reader *self, unsigned *out, unsigned count)
{
    int status;
    unsigned i;
    if (out == 0)
        return self->stream->methods->skip(self->stream, count << 2, 1, 0);
    status = self->stream->methods->read(self->stream, out, count << 2, 0);
    if (status < 0)
        return status;
    i = 0;
    if (i < count) {
        do {
            unsigned value = *out;
            i++;
            *out = (value << 24) | ((value << 8) & 0xff0000) | ((value >> 8) & 0xff00) | (value >> 24);
            out++;
        } while (i < count);
    }
    return 0;
}
