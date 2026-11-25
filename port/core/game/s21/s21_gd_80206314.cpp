#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_gd_80206314.c"
// desc: Appears to read fields of a twelve-byte record selected by index: it stores the second and third words through optional output pointers and returns the first word.
struct S21Object
{
  char pad[20];
  Ptr32<char> records;
};
int w3d_s21_get_record_80206314(Ptr32<struct S21Object> self, int index, Ptr32<int> second, Ptr32<int> third)
{
  int offset;
  int new_var;
  if (second)
  {
    *second = *((Ptr32<int>) ((self->records + (index * 12)) + (new_var = 4)));
  }
  offset = index * 12;
  if (third)
  {
    *third = *((Ptr32<int>) ((self->records + offset) + 8));
  }
  return *((Ptr32<int>) (self->records + offset));
}

}
