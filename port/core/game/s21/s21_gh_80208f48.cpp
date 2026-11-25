#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_gh_80208f48.c"
// desc: Appears to reset a memory stream and load it from a buffer: it reserves room through virtual slot 8, records the size and copies the data, or clears the fields when no data is given, then rewinds and returns zero.
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[8]; Ptr32<int (Ptr32<struct S21Stream>, unsigned int)> reserve; };
struct S21Stream { Ptr32<struct S21StreamMethods> methods; char pad[16]; Ptr32<char> buffer; int flag; unsigned position; unsigned size; };
extern int fn_80208fd8(Ptr32<struct S21Stream>);
extern Ptr32<void> fn_802eee50(Ptr32<void>, Ptr32<const void>, unsigned, ...);
int w3d_s21_load_80208f48(Ptr32<struct S21Stream> self, Ptr32<const void> data, unsigned size)
{
    fn_80208fd8(self);
    self->flag = 0;
    if (data) {
        self->methods->reserve(self, size);
        self->size = size;
        fn_802eee50(self->buffer, data, size);
    } else {
        self->buffer = (Ptr32<char>)data;
        self->flag = (int)w3d::H(data);
        self->size = (unsigned)w3d::H(data);
    }
    self->position = 0;
    return 0;
}

}
