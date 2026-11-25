struct K6bString { char *text; };
struct K6bEntrySource {
    char *name;
    unsigned char kind;
    unsigned char group;
    char pad6[2];
    int value;
    unsigned short count;
    char pad14[2];
    int extra;
};
struct K6bEntryFlags {
    unsigned int kind : 8;
    unsigned int group : 8;
    unsigned int dirty : 1;
    unsigned int rest : 15;
};
struct K6bEntry {
    char head[20];
    struct K6bString name;
    struct K6bEntryFlags flags;
    char pad28[4];
    int value;
    unsigned short count;
    char pad38[6];
    int extra;
    char pad48[64];
    int cached;
};
extern void w3d_string_assign(struct K6bString *string, const char *text);
int w3d_k6b_entry_assign_8017f000(struct K6bEntry *self, struct K6bEntrySource *source)
{
    w3d_string_assign(&self->name, source->name);
    self->flags.kind = source->kind;
    self->flags.group = source->group;
    self->value = source->value;
    self->count = source->count;
    self->flags.dirty = 0;
    self->extra = source->extra;
    self->cached = 0;
    return 0;
}
// desc: w3d_k6b_entry_assign_8017f000: Appears to copy a name, two bytes, a word, a half and a word from a source record, clear flag bit 0x8000 of the word at +24, zero +112 and return 0.
