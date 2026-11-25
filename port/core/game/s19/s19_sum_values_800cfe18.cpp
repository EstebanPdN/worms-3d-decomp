#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_sum_values_800cfe18.c"
struct S19Ent { char pad0[12]; float value; char pad16[12]; };
struct S19Owner { char pad0[28]; Ptr32<struct S19Ent> begin; Ptr32<struct S19Ent> end; };
float s19_sum_values_800cfe18(Ptr32<struct S19Owner> p)
{
    float sum = 0.0f;
    Ptr32<struct S19Ent> b = p->begin;
    unsigned n = p->end - b;
    unsigned i;
    for (i = 0; i < n; i++)
        sum += b[i].value;
    return sum;
}

}
