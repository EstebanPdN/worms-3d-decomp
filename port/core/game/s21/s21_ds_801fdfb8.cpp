#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ds_801fdfb8.c"
// desc: Appears to store the low bit of the argument into the top bit of the flag word at offset 8.
struct S21Flags { unsigned int rest:31; unsigned int top:1; };
struct S21Object { char pad[8]; struct S21Flags flags; };
void w3d_s21_set_top_bit_801fdfb8(Ptr32<struct S21Object> self, int value)
{
    self->flags.top = value;
}

}
