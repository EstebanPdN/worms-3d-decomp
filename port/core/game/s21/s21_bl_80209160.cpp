#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bl_80209160.c"
// desc: Appears to initialize an object by storing a handle argument, the value sixteen and zeroing seven other words.
struct S21Object
{
  int w[14];
};
void w3d_s21_init_80209160(Ptr32<struct S21Object> self, int handle)
{
  self->w[0] = 0;
  self->w[1] = 0;
  self->w[3] = 0;
  self->w[4] = 0;
  self->w[10] = 0;
  self->w[11] = 0;
  self->w[13] = handle;
  self->w[5] = 0;
  self->w[9] = 16;
}

}
