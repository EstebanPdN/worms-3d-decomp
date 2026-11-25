#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cw_802e0c20.c"
// desc: Appears to return minus one when a field of the linked record is zero, else the float at offset 208 of the record converted to an integer.
struct S21Record { char pad[160]; int valid; char pad1[44]; float value; };
struct S21Object { char pad[4]; Ptr32<struct S21Record> record; };
int w3d_s21_value_int_802e0c20(Ptr32<struct S21Object> self)
{
    Ptr32<struct S21Record> record = self->record;
    if (record->valid != 0)
        return (int)record->value;
    return -1;
}

}
