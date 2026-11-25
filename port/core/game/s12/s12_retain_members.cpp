#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s12_retain_members.c"
/* Observed constructor: install a table and retain five initial interfaces. */
typedef struct S12HeldInterface S12HeldInterface;
typedef struct S12HeldMethods {
    Ptr32<void (void)> reserved[3];
    Ptr32<void (Ptr32<S12HeldInterface>)> retain;
} S12HeldMethods;
struct S12HeldInterface { Ptr32<S12HeldMethods> methods; };
typedef struct S12FiveMemberObject { Ptr32<void> vtable; char baseState[60]; Ptr32<S12HeldInterface> members[5]; } S12FiveMemberObject;
extern Ptr32<S12HeldInterface> lbl_804b05a8;
extern char lbl_80415aa0[];
extern int fn_801b5b30(Ptr32<S12FiveMemberObject>, Ptr32<void>);
Ptr32<S12FiveMemberObject> w3d_s12_retain_members_801b5d68(Ptr32<S12FiveMemberObject> object, Ptr32<void> arg_r4)
{
    Ptr32<S12HeldInterface> initial;
    fn_801b5b30(object, arg_r4);
    initial = lbl_804b05a8;
    object->vtable = lbl_80415aa0;
    object->members[0] = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->members[1] = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->members[2] = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->members[3] = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->members[4] = initial;
    if (initial) initial->methods->retain(initial);
    return object;
}

}
