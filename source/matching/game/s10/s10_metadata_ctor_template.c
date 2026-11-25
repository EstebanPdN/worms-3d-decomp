typedef struct S10Metadata {
    unsigned short first, second;
    union {
        unsigned int value;
        struct { unsigned int reserved:24; unsigned int kind:8; } bits;
    } flags;
} S10Metadata;
typedef struct S10Tail { unsigned int first, second; } S10Tail;
typedef struct S10MetadataObject { void *vtable; S10Metadata metadata; S10Tail tail; } S10MetadataObject;
extern char lbl_80413730[], lbl_80413710[];
S10MetadataObject *w3d_s10_metadata_ctor_8019d78c(S10MetadataObject *object)
{
    object->vtable = lbl_80413730;
    object->metadata.flags.bits.kind = 2;
    object->metadata.flags.value = object->metadata.flags.bits.kind;
    object->tail.first = 0;
    object->tail.second = 0;
    object->metadata.first = 0;
    object->metadata.second = 0;
    object->vtable = lbl_80413710;
    return object;
}
