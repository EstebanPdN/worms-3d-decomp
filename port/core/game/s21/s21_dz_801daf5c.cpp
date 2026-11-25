#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_dz_801daf5c.c"
// desc: Appears to be a deleting destructor that releases the held interface through virtual slot 4, clears the pointer and deletes the object when the low flag bit is set.
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
  Ptr32<struct S21Ref> held;
};
extern void fn_801fe1f8(Ptr32<struct S21Object>);
void w3d_s21_destroy_clearing_801daf5c(Ptr32<struct S21Object> self, int flags)
{
  Ptr32<struct S21Ref> held = self->held;
  int new_var;
  new_var = 0;
  if (held)
  {
    held->methods->release(held);
  }
  self->held = w3d::G(new_var);
  if (flags & 1)
  {
    fn_801fe1f8(self);
  }
}

}
