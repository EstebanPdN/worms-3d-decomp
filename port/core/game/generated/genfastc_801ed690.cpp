#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genfastc_801ed690.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Quantized conversions built with -mfast-cast (psq_st/psq_l through the GQRs):
 * float arrays to and from small integer types, a float field read as a byte,
 * and pointer-to-member setters taking small integers. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
#define PMF_FN(m, o, T) (FIELD(m, short, 2) >= 0 ? (w3d::slot_t<T>)(*(void ***)w3d::AG((o) + FIELD(m, short, 4)))[FIELD(m, short, 2) - 1] : (w3d::slot_t<T>)FIELD(m, void *, 4))
typedef Ptr32<void (Ptr32<void>, signed char)> W3dSetS8;
typedef Ptr32<void (Ptr32<void>, unsigned short)> W3dSetU16;
typedef Ptr32<void (Ptr32<void>, short)> W3dSetS16;

void w3d_set_s8_from_float_801ed690(Ptr32<char> self, Ptr32<char> target, Ptr32<void> unused, Ptr32<const float> value)
{
    W3dSetS8 setter = PMF_FN(self + 20, target, W3dSetS8);
    setter(target + FIELD(self, short, 20), (signed char)*value);
}

void w3d_set_u16_from_float_801ed6f4(Ptr32<char> self, Ptr32<char> target, Ptr32<void> unused, Ptr32<const float> value)
{
    W3dSetU16 setter = PMF_FN(self + 20, target, W3dSetU16);
    setter(target + FIELD(self, short, 20), (unsigned short)*value);
}

void w3d_set_s16_from_float_801ed758(Ptr32<char> self, Ptr32<char> target, Ptr32<void> unused, Ptr32<const float> value)
{
    W3dSetS16 setter = PMF_FN(self + 20, target, W3dSetS16);
    setter(target + FIELD(self, short, 20), (short)*value);
}

int w3d_floats_to_u8_8020e6c0(Ptr32<const float> source, int source_stride, Ptr32<unsigned char> target, int target_stride, int count)
{
    while (count--)
        *target++ = (unsigned char)*source++;
    return 0;
}

int w3d_u8_to_floats_8020e700(Ptr32<const unsigned char> source, int source_stride, Ptr32<float> target, int target_stride, int count)
{
    while (count--)
        *target++ = (float)*source++;
    return 0;
}

int w3d_floats_to_u16_8020e740(Ptr32<const float> source, int source_stride, Ptr32<unsigned short> target, int target_stride, int count)
{
    while (count--)
        *target++ = (unsigned short)*source++;
    return 0;
}

int w3d_u16_to_floats_8020e780(Ptr32<const unsigned short> source, int source_stride, Ptr32<float> target, int target_stride, int count)
{
    while (count--)
        *target++ = (float)*source++;
    return 0;
}

int w3d_floats_to_s8_8020e88c(Ptr32<const float> source, int source_stride, Ptr32<signed char> target, int target_stride, int count)
{
    while (count--)
        *target++ = (signed char)*source++;
    return 0;
}

int w3d_s8_to_floats_8020e8cc(Ptr32<const signed char> source, int source_stride, Ptr32<float> target, int target_stride, int count)
{
    while (count--)
        *target++ = (float)*source++;
    return 0;
}

int w3d_floats_to_s16_8020e90c(Ptr32<const float> source, int source_stride, Ptr32<short> target, int target_stride, int count)
{
    while (count--)
        *target++ = (short)*source++;
    return 0;
}

int w3d_s16_to_floats_8020e94c(Ptr32<const short> source, int source_stride, Ptr32<float> target, int target_stride, int count)
{
    while (count--)
        *target++ = (float)*source++;
    return 0;
}

unsigned char w3d_get_field_as_u8_802bfc48(Ptr32<void> self)
{
    return (unsigned char)FIELD(self, float, 28);
}

}
