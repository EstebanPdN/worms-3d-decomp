/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10Record16 { unsigned int words[4]; } S10Record16;

void w3d_s10_set_record_flags_801d0de0(void *object, const S10Record16 *value)
{
    unsigned char *flags = (unsigned char *)object + 4;
    *(S10Record16 *)((char *)object + 56) = *value;
    flags[7] |= 2;
}

void w3d_s10_set_record_flags_801d0e20(void *object, const S10Record16 *value)
{
    unsigned char *flags = (unsigned char *)object + 4;
    *(S10Record16 *)((char *)object + 40) = *value;
    flags[7] |= 2;
}

void w3d_s10_set_record_flags_801d0e60(void *object, const S10Record16 *value)
{
    unsigned char *flags = (unsigned char *)object + 4;
    *(S10Record16 *)((char *)object + 24) = *value;
    flags[7] |= 2;
}

void w3d_s10_set_record_flags_801d12e0(void *object, const S10Record16 *value)
{
    unsigned char *flags = (unsigned char *)object + 4;
    *(S10Record16 *)((char *)object + 24) = *value;
    flags[7] |= 2;
}

void w3d_s10_set_record_flags_801d1360(void *object, const S10Record16 *value)
{
    unsigned char *flags = (unsigned char *)object + 4;
    *(S10Record16 *)((char *)object + 24) = *value;
    flags[7] |= 2;
}
