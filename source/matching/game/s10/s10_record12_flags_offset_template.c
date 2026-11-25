typedef struct S10Record12 { unsigned int words[3]; } S10Record12;
void w3d_s10_set_record_flags_801c84c0(void *object, const S10Record12 *value)
{
    unsigned char *flags = (unsigned char *)object + 4;
    *(S10Record12 *)((char *)object + 96) = *value;
    flags[7] |= 2;
}
