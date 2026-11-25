// desc: Appears to read four bytes from the inner stream directly into the output word and store its byte-swapped value. Same bytes as its sibling.
struct S21Stream;
struct S21StreamMethods { void (*reserved[5])(void); int (*read)(struct S21Stream *, void *, int, int); };
struct S21Stream { struct S21StreamMethods *methods; };
struct S21Reader { char pad[20]; struct S21Stream *stream; };
void w3d_s21_read_u32_direct_b_80201768(struct S21Reader *self, unsigned *out)
{
  unsigned value;
  unsigned *new_var;
  self->stream->methods->read(self->stream, out, 4, 0);
 do { new_var = out; value = *new_var; *out = (((value << 24) | ((value << 8) & 0xff0000)) | ((value >> 8) & 0xff00)) | (value >> 24); } while (0);
}
