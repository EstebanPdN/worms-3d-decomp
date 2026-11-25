/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Quantized conversions built with -mfast-cast (psq_st/psq_l through the GQRs):
 * float arrays to and from small integer types, a float field read as a byte,
 * and pointer-to-member setters taking small integers. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
#define PMF_FN(m, o, T) (FIELD(m, short, 2) >= 0 ? (T)(*(void ***)((o) + FIELD(m, short, 4)))[FIELD(m, short, 2) - 1] : (T)FIELD(m, void *, 4))
typedef void (*W3dSetS8)(void *, signed char);
typedef void (*W3dSetU16)(void *, unsigned short);
typedef void (*W3dSetS16)(void *, short);

void w3d_set_s8_from_float_801ed690(char *self, char *target, void *unused, const float *value)
{
    W3dSetS8 setter = PMF_FN(self + 20, target, W3dSetS8);
    setter(target + FIELD(self, short, 20), (signed char)*value);
}

void w3d_set_u16_from_float_801ed6f4(char *self, char *target, void *unused, const float *value)
{
    W3dSetU16 setter = PMF_FN(self + 20, target, W3dSetU16);
    setter(target + FIELD(self, short, 20), (unsigned short)*value);
}

void w3d_set_s16_from_float_801ed758(char *self, char *target, void *unused, const float *value)
{
    W3dSetS16 setter = PMF_FN(self + 20, target, W3dSetS16);
    setter(target + FIELD(self, short, 20), (short)*value);
}

int w3d_floats_to_u8_8020e6c0(const float *source, int source_stride, unsigned char *target, int target_stride, int count)
{
    while (count--)
        *target++ = (unsigned char)*source++;
    return 0;
}

int w3d_u8_to_floats_8020e700(const unsigned char *source, int source_stride, float *target, int target_stride, int count)
{
    while (count--)
        *target++ = (float)*source++;
    return 0;
}

int w3d_floats_to_u16_8020e740(const float *source, int source_stride, unsigned short *target, int target_stride, int count)
{
    while (count--)
        *target++ = (unsigned short)*source++;
    return 0;
}

int w3d_u16_to_floats_8020e780(const unsigned short *source, int source_stride, float *target, int target_stride, int count)
{
    while (count--)
        *target++ = (float)*source++;
    return 0;
}

int w3d_floats_to_s8_8020e88c(const float *source, int source_stride, signed char *target, int target_stride, int count)
{
    while (count--)
        *target++ = (signed char)*source++;
    return 0;
}

int w3d_s8_to_floats_8020e8cc(const signed char *source, int source_stride, float *target, int target_stride, int count)
{
    while (count--)
        *target++ = (float)*source++;
    return 0;
}

int w3d_floats_to_s16_8020e90c(const float *source, int source_stride, short *target, int target_stride, int count)
{
    while (count--)
        *target++ = (short)*source++;
    return 0;
}

int w3d_s16_to_floats_8020e94c(const short *source, int source_stride, float *target, int target_stride, int count)
{
    while (count--)
        *target++ = (float)*source++;
    return 0;
}

unsigned char w3d_get_field_as_u8_802bfc48(void *self)
{
    return (unsigned char)FIELD(self, float, 28);
}
