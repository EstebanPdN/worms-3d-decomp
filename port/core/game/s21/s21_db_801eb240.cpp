#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_db_801eb240.c"
// desc: Appears to return one when the described object's kind is not two, else call virtual slot 8 of the described object.
// desc: Appears to return one when the described object's kind is not two, else call virtual slot 8 of the described object.
struct S21Target;
struct S21TargetMethods { Ptr32<void (void)> reserved[8]; Ptr32<int (Ptr32<struct S21Target>)> apply; };
struct S21Target { Ptr32<struct S21TargetMethods> methods; };
struct S21Info { char pad[8]; Ptr32<struct S21Target> target; };
struct S21Object { Ptr32<struct S21Info> info; };
extern int fn_801fff94(Ptr32<struct S21Target>);
int w3d_s21_apply_unless_two_801eb240(Ptr32<struct S21Object> self)
{
    if (fn_801fff94(self->info->target) != 0)
        return self->info->target->methods->apply(self->info->target);
    return 1;
}

}
