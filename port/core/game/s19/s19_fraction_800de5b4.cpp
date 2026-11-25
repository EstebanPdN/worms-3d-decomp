#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_fraction_800de5b4.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
float s19_time_fraction_800de5b4(Ptr32<void> self, unsigned t)
{
    return (float)(t - FIELD(self, unsigned, 100)) / (float)(FIELD(self, unsigned, 100) + FIELD(self, unsigned, 92));
}

}
