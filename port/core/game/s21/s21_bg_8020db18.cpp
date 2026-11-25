#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bg_8020db18.c"
// desc: Appears to format a 64-bit integer into a stack buffer, write the text through the writer's stream slot and return the writer.
struct S21Stream;
struct S21StreamMethods
{
  Ptr32<void (void)> reserved[6];
  Ptr32<int (Ptr32<struct S21Stream>, Ptr32<const char>, unsigned int, int)> write;
};
struct S21Stream
{
  Ptr32<struct S21StreamMethods> methods;
};
struct S21Writer
{
  Ptr32<struct S21Stream> stream;
};
extern const char lbl_803b3240[];
extern int fn_80355a44(Ptr32<char>, Ptr32<const char>, ...);
extern unsigned fn_802ef9c0(Ptr32<const char>);
Ptr32<struct S21Writer> w3d_s21_write_i64_text_8020db18(Ptr32<struct S21Writer> self, long long value)
{
  char buffer[16];
  Ptr32<char> new_var3[2];
  Ptr32<struct S21Stream> stream;
  Ptr32<struct S21Stream> new_var;
  Ptr32<struct S21StreamMethods> methods;
  fn_80355a44(new_var3[0] = buffer, lbl_803b3240, value);
  stream = self->stream;
  methods = stream->methods;
  new_var = stream;
  new_var3[1] = new_var3[0];
  methods->write(new_var, new_var3[1], fn_802ef9c0(new_var3[0]), 0);
  return self;
}

}
