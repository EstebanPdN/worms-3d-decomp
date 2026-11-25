#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cq_802080a0.c"
// desc: Appears to clear an existing value, ask the service object through virtual slot 6 to fill the field at offset 20 and return its negative status or zero.
struct S21Service;
struct S21ServiceMethods { Ptr32<void (void)> reserved[6]; Ptr32<int (Ptr32<struct S21Service>, int, int, Ptr32<void>)> fill; };
struct S21Service { Ptr32<struct S21ServiceMethods> methods; };
struct S21Object { char pad[20]; int value; };
extern int fn_8020810c(Ptr32<struct S21Object>);
extern Ptr32<struct S21Service> fn_8020b884(void);
int w3d_s21_refill_802080a0(Ptr32<struct S21Object> self, int a, int b)
{
    Ptr32<struct S21Service> service;
    int status;
    if (self->value)
        fn_8020810c(self);
    service = fn_8020b884();
    status = service->methods->fill(service, a, b, &self->value);
    if (status >= 0)
        status = 0;
    return status;
}

}
