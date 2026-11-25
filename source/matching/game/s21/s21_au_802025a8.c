// desc: Appears to forward two arguments to the read slot of the inner stream with a trailing zero and return its result.
struct S21Stream;
struct S21StreamMethods { void (*reserved[5])(void); int (*read)(struct S21Stream *, void *, int, int); };
struct S21Stream { struct S21StreamMethods *methods; };
struct S21Reader { char pad[20]; struct S21Stream *stream; };
int w3d_s21_read_forward_802025a8(struct S21Reader *self, void *buffer, int size)
{
    return self->stream->methods->read(self->stream, buffer, size, 0);
}
