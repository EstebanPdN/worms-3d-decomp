// d24i: 0x801037a8 (372 bytes). Walk the zero-terminated message-name table
// 0x803fcd58. For each name build a cached message name (0x8015f518), allocate a
// zero-initialized 4-byte receiver slot (0x801fe1d8), append it to the owner's
// pointer vector at +372 with the byte-addressed growth shape
// (d24i_build_entries_8010391c), subscribe the owner to the message with that
// slot (0x80162024), and destroy the name (0x8015f558 with the deleting flag 2).
inline void *operator new(unsigned int, void *place) { return place; }
extern "C" void *allocate_80212fd4(unsigned int);
extern "C" void free_802134fc(void *);
extern "C" void *copy_802eee50(void *, const void *, unsigned int, ...);
static inline const int &maximum(const int &a, const int &b) { return a < b ? b : a; }
static inline const unsigned int &minimum(const unsigned int &a, const unsigned int &b) { return b < a ? b : a; }
struct d24i_Slot {
    void *value;
    d24i_Slot() { value = 0; }
};
struct d24i_Slots {
    unsigned char *begin, *end, *capacity;
    void push(d24i_Slot *const &value) {
        if (end == capacity) {
            unsigned int used = end - begin;
            unsigned int bytes = maximum((int)used + 1, (int)(used + (used >> 1))) << 2;
            unsigned char *data = (unsigned char *)allocate_80212fd4(bytes);
            if (begin) { copy_802eee50(data, begin, minimum(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; capacity = data + bytes;
        }
        *(d24i_Slot **)end = value; end += 4;
    }
};
struct d24i_MessageName {
    unsigned words[2];
    d24i_MessageName(const char *);
    ~d24i_MessageName();
};
extern "C" unsigned short d24i_cached_id_8015f5a0(d24i_MessageName *, int);
struct d24i_MessageId {
    unsigned short value;
    d24i_MessageId() {}
};
static inline unsigned short d24i_message_id(d24i_MessageName &name) { return d24i_cached_id_8015f5a0(&name, 1); }
struct d24i_Owner {
    unsigned char unknown00[372];
    d24i_Slots slots;                    // +372
};
extern "C" void *d24i_entry_allocate_801fe1d8(unsigned int);
extern "C" int d24i_subscribe_80162024(d24i_Owner *, d24i_MessageId *, d24i_Slot *);
extern const char *d24i_names_803fcd58[];
extern "C" void d24i_subscribe_messages_801037a8(d24i_Owner *self) {
    for (int i = 0; d24i_names_803fcd58[i]; ++i) {
        d24i_MessageName name(d24i_names_803fcd58[i]);
        d24i_Slot *slot = new (d24i_entry_allocate_801fe1d8(4)) d24i_Slot;
        self->slots.push(slot);
        d24i_MessageId id;
        id.value = d24i_message_id(name);
        d24i_subscribe_80162024(self, &id, slot);
    }
}
