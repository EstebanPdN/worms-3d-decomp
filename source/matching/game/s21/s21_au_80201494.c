// desc: Appears to read two bytes from the inner stream directly into the output halfword and byte-swap it in place.
struct S21Stream;
struct S21StreamMethods { void (*reserved[5])(void); int (*read)(struct S21Stream *, void *, int, int); };
struct S21Stream { struct S21StreamMethods *methods; };
struct S21Reader { char pad[20]; struct S21Stream *stream; };
void w3d_s21_read_u16_inplace_80201494(struct S21Reader *self, unsigned short *out)
{
    self->stream->methods->read(self->stream, out, 2, 0);
    *out = ((*out & 0xff) << 8) | ((*out >> 8) & 0xff);
}
