#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_af_801e4c14.c"
// desc: Appears to construct an object by zeroing four words, setting two fields to minus one and installing a vtable pointer.
struct S21Object
{
  int a;
  int b;
  int c;
  int d;
  int e;
  int f;
  int g;
  Ptr32<void> vtable;
};
extern char lbl_80416f38[];
Ptr32<struct S21Object> w3d_s21_construct_801e4c14(Ptr32<struct S21Object> self)
{
  self->d = 0;
  self->vtable = lbl_80416f38;
  self->e = -1;
  self->a = 0;
  self->c = 0;
  self++;
  self--;
  self->b = 0;
  (*self).f = -1;
  return self;
}

}
