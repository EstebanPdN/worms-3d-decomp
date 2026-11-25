// Observed external array-header view, never a locally constructed allocation.
typedef unsigned int Word;
struct ArrayHeader {
    Word unknown00;
    unsigned short kind, unknown06;
    Word unknown08[4];
    Word count;
    unsigned short locks, unknown1e;
};
struct ArrayRef { ArrayHeader *header; };
extern "C" void *fn_801ef048(ArrayRef *, Word, Word, Word);
struct Triple { Word x,y,z; };
template<class T> inline T *lockArray(ArrayRef &ref, Word count) {
    ArrayHeader *header = ref.header;
    if (header->kind == 1 && header->count == count) {
        ++header->locks;
        return (T *)(header + 1);
    }
    return (T *)fn_801ef048(&ref,count,sizeof(T),0);
}
struct ChannelsView {
    char unknown00[11];
    unsigned char flags;
    char unknown0c[52];
    ArrayRef triples;
    ArrayRef pairs;
    char unknown48[12];
    ArrayRef words54;
    ArrayRef words58;
    char unknown5c[4];
    ArrayRef enabled;
    ArrayRef bytes;
};
struct OwnerView { char unknown00[48]; ChannelsView *channels; };
struct UserView { char unknown00[168]; OwnerView *owner; };
extern const Word default_803a7be8[];
extern "C" int g6b_resize_channels_8018920c(UserView *self, Word count) {
    ChannelsView *channels = self->owner->channels;
    if (count != channels->bytes.header->count) {
        char *bytes = lockArray<char>(channels->bytes,count);
        Triple *triples = lockArray<Triple>(channels->triples,count);
        lockArray<Word>(channels->words58,0);
        struct Pair { Word x,y; };
        lockArray<Pair>(channels->pairs,0);
        lockArray<Word>(channels->words54,0);
        char *enabled = lockArray<char>(channels->enabled,count);
        Word value = default_803a7be8[0];
        for (Word index=0; index<count; ++index) {
            bytes[index] = 0;
            triples->x = value;
            triples->y = value;
            triples->z = value;
            enabled[index] = 1;
            ++triples;
        }
        if (!count) channels->flags |= 4;
        else channels->flags &= ~4;
    }
    return 0;
}
