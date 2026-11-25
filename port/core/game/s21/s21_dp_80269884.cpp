#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_dp_80269884.c"
// desc: Appears to set a mode on the embedded component and, when it changed, refresh the object and notify a text-bearing owner under flag conditions, then update the component again.
struct S21Info
{
  char pad[8];
  unsigned char flags; char w3d_tag_rest[3];
  char pad1[140];
  Ptr32<char> text;
};
struct S21Object
{
  char pad[28];
  char component[12];
  Ptr32<struct S21Info> info;
  char pad1[96];
  int armed;
  char pad2[32];
  int mode;
};
extern void fn_802b0990(Ptr32<void>, int);
extern void fn_8026a16c(Ptr32<struct S21Object>);
extern void fn_802b1258(Ptr32<char>);
void w3d_s21_set_mode_80269884(Ptr32<struct S21Object> self, int mode)
{
  int changed = 1;
  Ptr32<void> component;
  if (mode == self->mode)
  {
    changed = 0;
  }
  fn_802b0990(component = (*self).component, mode);
  if (changed)
  {
    fn_8026a16c(self);
    if (mode)
    {
      Ptr32<struct S21Info> info = self->info;
      Ptr32<char> text = info->text;
      if (((*((Ptr32<unsigned short>) (text - 4))) && ((info->flags ^ 4) & 4)) && self->armed)
      {
        fn_802b1258(text);
      }
    }
  }
  fn_802b0990((*self).component, mode);
}

}
