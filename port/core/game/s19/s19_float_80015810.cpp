#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_float_80015810.c"
extern unsigned fn_80162BA8(void);

float s19_random_unit_80015810(void) {
    unsigned r = fn_80162BA8() & 0x7fff;
    return (float)r * 3.0518509e-05f;
}

}
