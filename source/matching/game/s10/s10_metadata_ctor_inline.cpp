typedef struct S10Metadata {
    unsigned short first, second;
    union {
        unsigned int value;
        struct { unsigned int reserved:24; unsigned int kind:8; } bits;
    } volatile flags;
} S10Metadata;
typedef struct S10Tail { unsigned int first, second; } S10Tail;
typedef struct S10MetadataObject { void *volatile vtable; S10Metadata metadata; S10Tail tail; } S10MetadataObject;
extern char lbl_80413730[], lbl_80413710[];
static __inline__ void s10_init_tail(S10Tail *tail) { tail->first = 0; tail->second = 0; }
extern "C" S10MetadataObject *w3d_s10_metadata_ctor_8019d78c(S10MetadataObject *object)
{
    S10Metadata *metadata = &object->metadata;
    S10Tail *tail = &object->tail;
    object->vtable = lbl_80413730;
    metadata->flags.bits.kind = 2;
    metadata->flags.value = metadata->flags.bits.kind;
    s10_init_tail(tail);
    metadata->first = 0;
    metadata->second = 0;
    object->vtable = lbl_80413710;
    return object;
}
