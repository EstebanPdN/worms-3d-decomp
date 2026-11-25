#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10param_80218d78.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10Interface S10Interface;
typedef Ptr32<void (Ptr32<S10Interface>)> S10InterfaceMethod;
struct S10Interface { Ptr32<S10InterfaceMethod> vtable; };
typedef struct S10InterfaceOwner { char reserved[20]; Ptr32<S10Interface> value; } S10InterfaceOwner;

void w3d_s10_assign_interface_80218d78(Ptr32<S10InterfaceOwner> object, Ptr32<S10Interface> value)
{
    if (value)
        value->vtable[3](value);
    if (object->value)
        object->value->vtable[4](object->value);
    object->value = value;
}

}
