#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_eh_801df57c.c"
// desc: Appears to set a byte buffer: it stores the size, releases the old buffer, then allocates a copy of the data of that size or clears the pointer when no data is given, returning zero.
struct S21Object { char pad[20]; unsigned size; Ptr32<void> buffer; };
extern void fn_801fe240(Ptr32<void>);
extern Ptr32<void> fn_801fe220(unsigned);
extern Ptr32<void> fn_802eee50(Ptr32<void>, Ptr32<const void>, unsigned, ...);
int w3d_s21_set_buffer_801df57c(Ptr32<struct S21Object> self, unsigned size, Ptr32<const void> data)
{
    self->size = size;
    if (self->buffer)
        fn_801fe240(self->buffer);
    if (data) {
        Ptr32<void> copy = fn_801fe220(self->size);
        self->buffer = copy;
        fn_802eee50(copy, data, self->size);
    } else
        self->buffer = (Ptr32<void>)data;
    return 0;
}

}
