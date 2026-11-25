#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ar_801fff60.c"
// desc: Appears to report whether bits 3 to 5 of a halfword in the looked-up object equal three.
struct S21Info { char pad[4]; unsigned short bits; };
extern Ptr32<struct S21Info> fn_802001a8(Ptr32<void>);
int w3d_s21_kind_is_three_801fff60(Ptr32<void> self)
{
    return ((fn_802001a8(self)->bits >> 3) & 7) == 3;
}

}
