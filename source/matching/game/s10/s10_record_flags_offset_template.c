typedef struct S10Record16 { unsigned int words[4]; } S10Record16;
void w3d_s10_set_record_flags_801d0da0(void *object, const S10Record16 *value)
{
    unsigned char *flags = (unsigned char *)object + 4;
    *(S10Record16 *)((char *)object + 72) = *value;
    flags[7] |= 2;
}
