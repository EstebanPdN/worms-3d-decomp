#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cf_802bbfc8.c"
// desc: Appears to call a helper on every pointer of the embedded vector at offset 56 and return zero.
struct S21Vector
{
  Ptr32<Ptr32<void>> begin;
  Ptr32<Ptr32<void>> end;
};
struct S21Object
{
  char pad[56];
  struct S21Vector items;
};
extern void fn_802c0064(Ptr32<void>);
int w3d_s21_each_item_802bbfc8(Ptr32<struct S21Object> self)
{
  Ptr32<struct S21Vector> items = &self->items;
  Ptr32<Ptr32<void>> item = items->begin;
  Ptr32<struct S21Vector> new_var;
  if (item != items->end)
  {
 do { } while (0);
    new_var = &self->items;
    do
    {
      Ptr32<void> current = *item;
      item++;
      fn_802c0064(current);
    }
    while (item != new_var->end);
  }
  return 0;
}

}
