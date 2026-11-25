// desc: Appears to format a unsigned 64-bit integer into a stack buffer, write the text through the writer's stream slot and return the writer.
struct S21Stream;
struct S21StreamMethods
{
  void (*reserved[6])(void);
  int (*write)(struct S21Stream *, const char *, unsigned, int);
};
struct S21Stream
{
  struct S21StreamMethods *methods;
};
struct S21Writer
{
  struct S21Stream *stream;
};
extern const char lbl_803b3248[];
extern int fn_80355a44(char *, const char *, ...);
extern unsigned fn_802ef9c0(const char *);
struct S21Writer *w3d_s21_write_u64_text_8020db88(struct S21Writer *self, long long value)
{
  char buffer[16];
  char *new_var3[2];
  struct S21Stream *stream;
  struct S21Stream *new_var;
  struct S21StreamMethods *methods;
  fn_80355a44(new_var3[0] = buffer, lbl_803b3248, value);
  stream = self->stream;
  methods = stream->methods;
  new_var = stream;
  new_var3[1] = new_var3[0];
  methods->write(new_var, new_var3[1], fn_802ef9c0(new_var3[0]), 0);
  return self;
}
