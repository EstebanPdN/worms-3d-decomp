#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ai_801ed550.c"
// desc: Appears to call a virtual slot of the second argument passing the first word read through this and two zero arguments.
struct S21Target;
struct S21TargetMethods { Ptr32<void (void)> reserved[21]; Ptr32<void (Ptr32<struct S21Target>, int, int, int)> apply; };
struct S21Target { Ptr32<struct S21TargetMethods> methods; };
struct S21Source { Ptr32<int> value; };
void w3d_s21_apply_801ed550(Ptr32<struct S21Source> self, Ptr32<struct S21Target> target)
{
    target->methods->apply(target, 0, *self->value, 0);
}

}
