typedef struct S10Record64 { unsigned int words[16]; } S10Record64;
typedef struct S10RecordHolder { char reserved[20]; S10Record64 value; } S10RecordHolder;
void w3d_s10_copy_record_801c86c0(S10RecordHolder *object, const S10Record64 *value)
{
    object->value = *value;
}
