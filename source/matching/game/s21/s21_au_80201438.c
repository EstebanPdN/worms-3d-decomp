// desc: Appears to read two bytes from the inner stream into a stack halfword, byte-swap it and store it through the output pointer.
struct S21Stream;
struct S21StreamMethods { void (*reserved[5])(void); int (*read)(struct S21Stream *, void *, int, int); };
struct S21Stream { struct S21StreamMethods *methods; };
struct S21Reader { char pad[20]; struct S21Stream *stream; };
void w3d_s21_read_u16_swapped_80201438(struct S21Reader *self, unsigned short *out)
{
    unsigned short value;
    self->stream->methods->read(self->stream, &value, 2, 0);
    *out = ((value & 0xff) << 8) | ((value >> 8) & 0xff);
}
