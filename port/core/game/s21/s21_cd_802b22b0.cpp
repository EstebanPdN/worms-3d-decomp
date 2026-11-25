#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cd_802b22b0.c"
// desc: Appears to call the error callback of the owner with this object and a global message literal.
struct S21Callbacks { char pad[28]; Ptr32<void (Ptr32<void>, Ptr32<const char>)> report; };
struct S21Object { char pad[180]; Ptr32<struct S21Callbacks> callbacks; };
extern const char lbl_803d7afc[];
void w3d_s21_report_error_802b22b0(Ptr32<struct S21Object> self)
{
    self->callbacks->report(self, lbl_803d7afc);
}

}
