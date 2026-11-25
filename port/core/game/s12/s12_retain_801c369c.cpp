#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s12_retain_801c369c.c"
typedef struct S12HeldInterface S12HeldInterface;
typedef struct S12HeldMethods { Ptr32<void (void)> reserved[3]; Ptr32<void (Ptr32<S12HeldInterface>)> retain; } S12HeldMethods;
struct S12HeldInterface { Ptr32<S12HeldMethods> methods; };
typedef struct S12RetainedMembers {
    Ptr32<void> vtable;
    char reserved_0004[16];
    Ptr32<S12HeldInterface> member_0014;
    Ptr32<S12HeldInterface> member_0018;
    Ptr32<S12HeldInterface> member_001c;
} S12RetainedMembers;
extern Ptr32<S12HeldInterface> lbl_804b05a8;
extern Ptr32<S12HeldInterface> lbl_804b05ac;
extern char lbl_80414cb8[];
extern Ptr32<void> fn_801ea0ec(Ptr32<S12RetainedMembers>, int);
Ptr32<S12RetainedMembers> w3d_s12_initialize_interfaces_801c369c(Ptr32<S12RetainedMembers> object, Ptr32<void> arg_r4)
{
    Ptr32<S12HeldInterface> initial;
    fn_801ea0ec(object, w3d::H(arg_r4));
    initial = lbl_804b05a8;
    object->vtable = lbl_80414cb8;
    object->member_0014 = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05ac;
    object->member_0018 = initial;
    if (initial) initial->methods->retain(initial);
    initial = lbl_804b05a8;
    object->member_001c = initial;
    if (initial) initial->methods->retain(initial);
    return object;
}

}
