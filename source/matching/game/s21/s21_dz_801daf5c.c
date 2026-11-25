// desc: Appears to be a deleting destructor that releases the held interface through virtual slot 4, clears the pointer and deletes the object when the low flag bit is set.
struct S21Ref;
struct S21RefMethods
{
  void (*reserved[4])(void);
  void (*release)(struct S21Ref *);
};
struct S21Ref
{
  struct S21RefMethods *methods;
};
struct S21Object
{
  struct S21Ref *held;
};
extern void fn_801fe1f8(struct S21Object *);
void w3d_s21_destroy_clearing_801daf5c(struct S21Object *self, int flags)
{
  struct S21Ref *held = self->held;
  int new_var;
  new_var = 0;
  if (held)
  {
    held->methods->release(held);
  }
  self->held = new_var;
  if (flags & 1)
  {
    fn_801fe1f8(self);
  }
}
