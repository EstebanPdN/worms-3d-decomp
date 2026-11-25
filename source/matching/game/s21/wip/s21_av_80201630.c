// desc: Appears to read four bytes from the inner stream directly into the output word and byte-swap it in place.
struct S21Stream;
struct S21StreamMethods
{
  void (*reserved[5])(void);
  int (*read)(struct S21Stream *, void *, int, int);
};
struct S21Stream
{
  struct S21StreamMethods *methods;
};
struct S21Reader
{
  char pad[20];
  struct S21Stream *stream;
};
void w3d_s21_read_u32_inplace_80201630(struct S21Reader *self, unsigned *out)
{
  int new_var;
  self->stream->methods->read(self->stream, out, 4, 0);
  new_var = (((*out) << 8) & 0xff0000) | ((*out) << 24);
  *out = (*out) >> 24;
  *out = (new_var | (((*out) >> 8) & 0xff00)) | (*out);
}
