/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10Record12 { unsigned int words[3]; } S10Record12;

void w3d_s10_set_record_flags_801c84c0(void *object, const S10Record12 *value)
{
    unsigned char *flags = (unsigned char *)object + 4;
    *(S10Record12 *)((char *)object + 96) = *value;
    flags[7] |= 2;
}

void w3d_s10_set_record_flags_801c84f8(void *object, const S10Record12 *value)
{
    unsigned char *flags = (unsigned char *)object + 4;
    *(S10Record12 *)((char *)object + 84) = *value;
    flags[7] |= 2;
}

void w3d_s10_set_record_flags_801c8530(void *object, const S10Record12 *value)
{
    unsigned char *flags = (unsigned char *)object + 4;
    *(S10Record12 *)((char *)object + 72) = *value;
    flags[7] |= 2;
}

void w3d_s10_set_record_flags_801c8588(void *object, const S10Record12 *value)
{
    unsigned char *flags = (unsigned char *)object + 4;
    *(S10Record12 *)((char *)object + 124) = *value;
    flags[7] |= 2;
}

void w3d_s10_set_record_flags_801c85c0(void *object, const S10Record12 *value)
{
    unsigned char *flags = (unsigned char *)object + 4;
    *(S10Record12 *)((char *)object + 112) = *value;
    flags[7] |= 2;
}

void w3d_s10_set_record_flags_801c85f8(void *object, const S10Record12 *value)
{
    unsigned char *flags = (unsigned char *)object + 4;
    *(S10Record12 *)((char *)object + 124) = *value;
    flags[7] |= 2;
}

void w3d_s10_set_record_flags_801c8630(void *object, const S10Record12 *value)
{
    unsigned char *flags = (unsigned char *)object + 4;
    *(S10Record12 *)((char *)object + 112) = *value;
    flags[7] |= 2;
}
