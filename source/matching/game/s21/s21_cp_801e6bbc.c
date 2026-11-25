// desc: Appears to reset an object: it runs optional cleanup, releases the held interface, clears two flag fields and sets two handles to minus one.
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
  char pad[8];
  unsigned flags;
  char pad1[32];
  struct S21Ref *held;
  char pad2[20];
  int handle;
  char pad3[44];
  int slot;
  char pad4[44];
  int cleared;
};
extern void fn_801e5e74(struct S21Object *);
extern void fn_801e6d30(struct S21Object *, int);
void w3d_s21_reset_801e6bbc(struct S21Object *self)
{
  int none;
  int zero;
  if (self->flags & 0x200000)
  {
    fn_801e5e74(self);
  }
  none = -1;
  if ((-1) != self->handle)
  {
    fn_801e6d30(self, self->handle);
  }
  zero = 0;
  self->cleared = zero;
  if (self->held)
  {
    self->held->methods->release(self->held);
  }
  self->slot = none;
  self->flags = self->flags;
  self->flags = self->flags & (~0x800000);
  self->held = (struct S21Ref *) zero;
  self->held->methods->release += 0;
  self->handle = none;
}
