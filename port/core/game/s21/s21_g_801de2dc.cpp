#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_g_801de2dc.c"
extern int fn_8020b6e8(Ptr32<void>, Ptr32<int>);
int w3d_s21_query_value_801de2dc(Ptr32<void> self, Ptr32<int> out)
{
  int value;
  Ptr32<int> value_address;
  int status;
  int zero;
  value_address = &value;
  zero = 0;
  *out = (value = zero);
  value += zero;
  status = fn_8020b6e8(self, value_address);
  if (status >= zero)
  {
    *out = value;
  }
  return status;
}

}
