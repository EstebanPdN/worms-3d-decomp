#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cp_801e6bbc.c"
// desc: Appears to reset an object: it runs optional cleanup, releases the held interface, clears two flag fields and sets two handles to minus one.
struct S21Ref;
struct S21RefMethods
{
  Ptr32<void (void)> reserved[4];
  Ptr32<void (Ptr32<struct S21Ref>)> release;
};
struct S21Ref
{
  Ptr32<struct S21RefMethods> methods;
};
struct S21Object
{
  char pad[8];
  unsigned flags;
  char pad1[32];
  Ptr32<struct S21Ref> held;
  char pad2[20];
  int handle;
  char pad3[44];
  int slot;
  char pad4[44];
  int cleared;
};
extern void fn_801e5e74(Ptr32<struct S21Object>);
extern void fn_801e6d30(Ptr32<struct S21Object>, int);
void w3d_s21_reset_801e6bbc(Ptr32<struct S21Object> self)
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
  self->held = (Ptr32<struct S21Ref>) w3d::G(zero);
  self->handle = none;
}

}
