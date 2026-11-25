#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s12_retain_801bea98.c"
typedef struct S12HeldInterface S12HeldInterface;
typedef struct S12HeldMethods { Ptr32<void (void)> reserved[3]; Ptr32<void (Ptr32<S12HeldInterface>)> retain; } S12HeldMethods;
struct S12HeldInterface { Ptr32<S12HeldMethods> methods; };
typedef struct S12RetainedMembers {
    Ptr32<void> vtable;
    char reserved_0004[40];
    Ptr32<S12HeldInterface> member_002c;
    Ptr32<S12HeldInterface> member_0030;
    Ptr32<S12HeldInterface> member_0034;
    Ptr32<S12HeldInterface> member_0038;
    Ptr32<S12HeldInterface> member_003c;
} S12RetainedMembers;
extern Ptr32<S12HeldInterface> lbl_804b05a8;
extern Ptr32<S12HeldInterface> lbl_804b05b0;
extern char lbl_80415028[];
extern int fn_801b4bcc(Ptr32<S12RetainedMembers>, Ptr32<void>);
Ptr32<S12RetainedMembers> w3d_s12_initialize_interfaces_801bea98(Ptr32<S12RetainedMembers> object, Ptr32<void> arg_r4)
{
    Ptr32<S12HeldInterface> initial;
    fn_801b4bcc(object, arg_r4);
    initial = lbl_804b05a8;
    object->vtable = lbl_80415028;
    object->member_002c = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->member_0030 = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->member_0034 = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05b0;
    object->member_0038 = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->member_003c = initial;
    if (initial) initial->methods->retain(initial);
    return object;
}

}
