#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_el_801df5f0.c"
// desc: Appears to regenerate the sample buffer: it fails with 0x80004005 when no count is set, releases the old buffer and fills a request record with the count, size, argument and constants 120 and 60 for a builder helper.
struct S21Request { int count; int size; int argument; int rate_a; int rate_b; Ptr32<void> buffer; int length; };
struct S21Object { char pad[20]; int size; int count; Ptr32<void> buffer; int length; };
extern void fn_801fe240(Ptr32<void>);
extern int fn_801e39bc(Ptr32<struct S21Request>);
int w3d_s21_rebuild_801df5f0(Ptr32<struct S21Object> self, int argument)
{
    struct S21Request request;
    int status;
    if (self->count == 0)
        return 0x80004005;
    if (self->buffer)
        fn_801fe240(self->buffer);
    request.count = self->count;
    request.size = self->size;
    request.argument = argument;
    request.rate_a = 120;
    request.rate_b = 60;
    status = fn_801e39bc(&request);
    if (status < 0)
        return status;
    self->buffer = request.buffer;
    self->length = request.length;
    return 0;
}

}
