#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s12_retain_801cab48.c"
typedef struct S12HeldInterface S12HeldInterface;
typedef struct S12HeldMethods { Ptr32<void (void)> reserved[3]; Ptr32<void (Ptr32<S12HeldInterface>)> retain; } S12HeldMethods;
struct S12HeldInterface { Ptr32<S12HeldMethods> methods; };
typedef struct S12RetainedMembers {
    Ptr32<void> vtable;
    char reserved_0004[24];
    Ptr32<S12HeldInterface> member_001c;
    Ptr32<S12HeldInterface> member_0020;
    Ptr32<S12HeldInterface> member_0024;
    Ptr32<S12HeldInterface> member_0028;
} S12RetainedMembers;
extern Ptr32<S12HeldInterface> lbl_804b05a8;
extern Ptr32<S12HeldInterface> lbl_804b05ac;
extern char lbl_80416280[];
extern int fn_801c90c0(Ptr32<S12RetainedMembers>, Ptr32<void>);
Ptr32<S12RetainedMembers> w3d_s12_initialize_interfaces_801cab48(Ptr32<S12RetainedMembers> object, Ptr32<void> arg_r4)
{
    Ptr32<S12HeldInterface> initial;
    fn_801c90c0(object, arg_r4);
    initial = lbl_804b05ac;
    object->vtable = lbl_80416280;
    object->member_001c = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05ac;
    object->member_0020 = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->member_0024 = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->member_0028 = initial;
    if (initial) initial->methods->retain(initial);
    return object;
}

}
