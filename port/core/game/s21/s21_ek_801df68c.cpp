#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ek_801df68c.c"
// desc: Appears to return the byte sample at a position converted from a tick count (value times sixty divided by 1000) scaled to a float, or a constant when there is no sample buffer or the position is out of range.
struct S21Object { char pad[28]; Ptr32<unsigned char> samples; unsigned count; };
extern float lbl_803b03ac[];
extern float lbl_803b03b8[];
float w3d_s21_sample_801df68c(Ptr32<struct S21Object> self, int ticks)
{
    unsigned index = (unsigned)(ticks * 60) / 1000;
    if (self->samples == 0 || index >= self->count)
        return lbl_803b03ac[0];
    return (float)(int)self->samples[index] / lbl_803b03b8[0];
}

}
