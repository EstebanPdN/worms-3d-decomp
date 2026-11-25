#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_gd_80208ebc.c"
// desc: Appears to grow a buffer: when the requested size exceeds the capacity it rounds the capacity up to 16 KiB, allocates or reallocates through one of two helpers and records the size, returning zero.
struct S21Object { char pad[20]; Ptr32<char> buffer; unsigned capacity; char pad1[4]; unsigned size; char pad2[4]; int external; };
extern Ptr32<char> fn_801fe0b8(unsigned);
extern Ptr32<char> fn_80213750(Ptr32<char>, unsigned);
int w3d_s21_reserve_80208ebc(Ptr32<struct S21Object> self, unsigned size)
{
    if (size > self->capacity) {
        unsigned capacity = (size + 16384) & ~16383u;
        self->capacity = capacity;
        if (self->external)
            self->buffer = fn_801fe0b8(capacity);
        else
            self->buffer = fn_80213750(self->buffer, capacity);
    }
    self->size = size;
    return 0;
}

}
