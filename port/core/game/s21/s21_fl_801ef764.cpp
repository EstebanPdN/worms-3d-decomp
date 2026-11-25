#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_fl_801ef764.c"
// desc: Appears to compare the element arrays of two objects at the descriptor offset: equal lengths are required, then all element bytes are compared, reporting equality.
struct S21Info
{
  char pad[4];
  unsigned short offset;
  char pad1[2];
  int size;
};
struct S21Field
{
  Ptr32<struct S21Info> info;
};
struct S21Array
{
  char pad[24];
  int count;
  char pad2[4];
  char data[1];
};
extern int fn_80200050(int);
extern int fn_802eedc0(Ptr32<const void>, Ptr32<const void>, int);
int w3d_s21_equal_arrays_801ef764(Ptr32<struct S21Field> field, Ptr32<char> first, Ptr32<char> second)
{
  Ptr32<struct S21Info> info = field->info;
  unsigned short offset = info->offset;
  Ptr32<struct S21Array> b;
  Ptr32<char> new_var2;
  Ptr32<struct S21Array> a = *((Ptr32<Ptr32<struct S21Array>>) (first + offset));
  int other = (*((Ptr32<Ptr32<struct S21Array>>) (second + offset)))->count;
  Ptr32<char> new_var;
  int count = a->count;
  if (count != other)
  {
    return 0;
  }
  new_var2 = a->data;
  new_var = new_var2;
  return fn_802eedc0(new_var, (*((Ptr32<Ptr32<struct S21Array>>) (second + offset)))->data, count * fn_80200050(info->size)) == 0;
}

}
