#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ct_802067e4.c"
// desc: Appears to destroy every string held in the embedded vector at offset 48, empty the vector, clear the task list at offset 36 and return zero.
struct S21Text
{
  Ptr32<char> data;
};
struct S21Vector
{
  Ptr32<struct S21Text> begin;
  Ptr32<struct S21Text> end;
};
struct S21Object
{
  char pad[36];
  char tasks[12];
  struct S21Vector texts;
};
extern void fn_8020c5c4(Ptr32<struct S21Text>);
extern void fn_80341588(Ptr32<struct S21Text>);
extern void fn_80210afc(Ptr32<void>);
int w3d_s21_clear_texts_802067e4(Ptr32<struct S21Object> self)
{
  Ptr32<struct S21Text> begin = self->texts.begin;
  Ptr32<struct S21Vector> new_var;
  Ptr32<struct S21Vector> texts = &self->texts;
  Ptr32<struct S21Text> end = texts->end;
  Ptr32<void> tasks = self->tasks;
  Ptr32<struct S21Text> item = begin;
 do { new_var = texts; for (; item != end; item++) { fn_8020c5c4(item); fn_80341588(item); } new_var->end = begin; } while (0);
  fn_80210afc(tasks);
  return 0;
}

}
