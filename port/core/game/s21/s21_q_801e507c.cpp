#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_q_801e507c.c"
// desc: Appears to forward a held object pointer to a helper, or return zero when none is held.
struct S21Holder
{
  int pad;
  Ptr32<void> held;
};
extern int fn_801df1ac(Ptr32<void>);
int w3d_s21_query_held_801e507c(Ptr32<struct S21Holder> self)
{
  if (self->held)
  {
    if (self || self->held)
    {
      return fn_801df1ac(self->held);
    }
    else
    {
      return fn_801df1ac(self->held);
    }
  }
  return 0;
}

}
