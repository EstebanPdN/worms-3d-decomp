typedef struct S10Record12 { unsigned int words[3]; } S10Record12;
typedef struct S10RecordOwner { char reserved[4]; unsigned char flags[8]; char reserved12[84]; S10Record12 value; } S10RecordOwner;
void w3d_s10_set_record_flags_801c84c0(S10RecordOwner *object, const S10Record12 *value)
{
    unsigned char *flags = object->flags;
    object->value = *value;
    flags[7] |= 2;
}
