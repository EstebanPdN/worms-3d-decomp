#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_dc_801eb398.c"
// desc: Appears to call virtual slot 15 of the described object with its arguments, the offset-adjusted second argument, descriptor fields and an optional linked value.
struct S21Target;
struct S21TargetMethods { Ptr32<void (void)> reserved[15]; Ptr32<int (Ptr32<struct S21Target>, int, int, int, int, int)> write; };
struct S21Target { Ptr32<struct S21TargetMethods> methods; };
struct S21Link { char pad[8]; int value; };
struct S21Info { int first; char pad[4]; Ptr32<struct S21Target> target; Ptr32<struct S21Link> link; };
struct S21Object { Ptr32<struct S21Info> info; };
int w3d_s21_forward_write_801eb398(Ptr32<struct S21Object> self, int a, int b)
{
    Ptr32<struct S21Info> info = self->info;
    int value = 0;
    if (info->link)
        value = info->link->value;
    return info->target->methods->write(info->target, a, b + *(Ptr32<unsigned short>)((Ptr32<char>)info + 4), info->first, 1, value);
}

}
