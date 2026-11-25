#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9perm_80178dfc.c"
/* Observed float field at offset 28 of the inner object. */
typedef struct S9FloatValue { char unknown0[28]; float value; } S9FloatValue;
typedef struct S9FloatOwner { Ptr32<void> unknown0; Ptr32<S9FloatValue> inner; } S9FloatOwner;
extern int fn_80178b5c(Ptr32<void>);
int s9_permute_80178dfc(Ptr32<S9FloatOwner> self,Ptr32<const float> value)
{
    float next=*value;
    if(self->inner->value==next)return 1;
    self->inner->value=next;
    fn_80178b5c(self);
    return 0;
}

}
