#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cj_8029fb54.c"
// desc: Appears to skip an object in state one, call its virtual slot 12 when its field at offset 28 equals a global value, else mark it dirty, returning zero except for that call.
struct S21Object;
struct S21Methods { Ptr32<void (void)> reserved[12]; Ptr32<int (Ptr32<struct S21Object>)> activate; };
struct S21Object { Ptr32<struct S21Methods> methods; char pad[24]; int owner; char pad1[160]; int state; char pad2[60]; int dirty; };
extern int lbl_804abb5c;
int w3d_s21_activate_8029fb54(int unused, Ptr32<struct S21Object> object)
{
    if (object->state == 1)
        return 0;
    if (object->owner != lbl_804abb5c) {
        object->dirty = 1;
        return 0;
    }
    return object->methods->activate(object);
}

}
