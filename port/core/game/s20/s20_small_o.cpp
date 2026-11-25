#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_o.c"
/* Virtual calls on the object resolved from a stored handle. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
extern Ptr32<S20Object> fn_80164fc8(int);

int w3d_s20_call_handle_object_800e95e0(Ptr32<char> self, int arg) {
    Ptr32<S20Object> object = fn_80164fc8(*(Ptr32<int>)(self + 192));
    return ((Ptr32<int (Ptr32<S20Object>, int, Ptr32<char>)>)object->vtable[12])(object, arg, self + 72);
}

int w3d_s20_call_handle_object_800e962c(Ptr32<char> self, int arg) {
    Ptr32<S20Object> object = fn_80164fc8(*(Ptr32<int>)(self + 192));
    return ((Ptr32<int (Ptr32<S20Object>, int, Ptr32<char>)>)object->vtable[13])(object, arg, self + 84);
}

}
