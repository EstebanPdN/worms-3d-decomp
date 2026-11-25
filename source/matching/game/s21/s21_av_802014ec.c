// desc: Appears to read four bytes from the inner stream into a stack word, byte-swap it and store it through the output pointer.
struct S21Stream;
struct S21StreamMethods { void (*reserved[5])(void); int (*read)(struct S21Stream *, void *, int, int); };
struct S21Stream { struct S21StreamMethods *methods; };
struct S21Reader { char pad[20]; struct S21Stream *stream; };
void w3d_s21_read_u32_swapped_802014ec(struct S21Reader *self, unsigned *out)
{
  unsigned value;
  self->stream->methods->read(self->stream, &value, 4, 0);
 do { *out = (((value << 24) | ((value << 8) & 0xff0000)) | ((value >> 8) & 0xff00)) | (value >> 24); } while (0);
}
