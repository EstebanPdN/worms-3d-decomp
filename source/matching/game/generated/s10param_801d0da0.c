/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10Record16 { unsigned int words[4]; } S10Record16;
typedef struct S10RecordOwner { char reserved[4]; unsigned char flags[8]; char reserved12[60]; S10Record16 value; } S10RecordOwner;

void w3d_s10_set_record_flags_801d0da0(S10RecordOwner *object, const S10Record16 *value)
{
    unsigned char *flags = object->flags;
    object->value = *value;
    flags[7] |= 2;
}
