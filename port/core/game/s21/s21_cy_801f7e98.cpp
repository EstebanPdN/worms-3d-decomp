#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cy_801f7e98.c"
// desc: Appears to look up a shared object for a key: it retains the object from a global registry, initializes it, stores it in the output on success or releases it and returns the failure status.
// desc: Appears to look up a shared object for a key: it retains the object from a global registry, initializes it, stores it in the output on success or releases it and returns the failure status.
struct S21Ref;
struct S21RefMethods { Ptr32<void (void)> reserved[3]; Ptr32<void (Ptr32<struct S21Ref>)> retain; Ptr32<void (Ptr32<struct S21Ref>)> release; };
struct S21Ref { Ptr32<struct S21RefMethods> methods; };
extern char lbl_80365808[];
extern Ptr32<struct S21Ref> fn_8020fcb4(Ptr32<void>);
extern int fn_801f8754(Ptr32<struct S21Ref>, Ptr32<void>);
int w3d_s21_acquire_801f7e98(int unused, int key, Ptr32<Ptr32<struct S21Ref>> out)
{
    Ptr32<struct S21Ref> object = fn_8020fcb4(lbl_80365808);
    int status;
    object->methods->retain(object);
    status = fn_801f8754(object, w3d::G(key));
    if (status < 0) {
        object->methods->release(object);
        return status;
    }
    *out = object;
    return 0;
}

}
