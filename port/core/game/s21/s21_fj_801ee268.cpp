#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_fj_801ee268.c"
// desc: Appears to drop a reference of a counted object: at zero it queries a key through virtual slot 9, destroys the object through slot 5 and unregisters the key, returning the new count.
struct S21Object;
struct S21Methods { Ptr32<void (void)> reserved[5]; Ptr32<void (Ptr32<struct S21Object>, int)> destroy; Ptr32<void (void)> reserved1[3]; Ptr32<int (Ptr32<struct S21Object>)> key; };
struct S21Object { Ptr32<struct S21Methods> methods; unsigned short references; };
extern void fn_801edf00(int, Ptr32<struct S21Object>);
unsigned short w3d_s21_release_counted_801ee268(Ptr32<struct S21Object> self)
{
    unsigned short remaining = --self->references;
    if (remaining == 0) {
        int key = self->methods->key(self);
        if (self)
            self->methods->destroy(self, 3);
        fn_801edf00(key, self);
        return 0;
    }
    return remaining;
}

}
