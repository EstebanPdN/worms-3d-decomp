// Message placeholder expansion (Worms 3D GameCube PAL, 0x8026fc98).
//
// Picks the message at +132 or +136 of the object at +40. If it is non-empty,
// flag 4 of byte +11 of that object is clear, the list holder at +284 and the
// value at +140 are set and the index at +300 is not negative, it reads the
// indexed entry from the list (0x80341584, 0x801797b4; +28 list, +24 count,
// +32 entries); an index past the count returns. It then repeatedly replaces
// each '@' placeholder (0x802ef380 with marker 0x803cbf38 finds it, 0x8020c3a0
// truncates the prefix, 0x8020c510 re-formats with 0x803cbf3c from prefix,
// entry and tail) and passes the result to 0x802b1258.
//
// Entries are four-byte pointers viewed as strings. The string is one word
// with a user copy constructor: the original's string slots are sp+8 and sp+16
// with sp+12 never written, as in d23a_worm_aim_start_80026e74. The list and index
// locals are declared before the index is read, which gives the original's
// register choice; the scaled index is the first address operand. Field roles
// are inferred.
extern "C" void fn_8020c5c4(void *), fn_80341588(void *), fn_8020c5c0(void *), fn_8020bb2c(void *);
extern "C" unsigned short *fn_80341884(void *);
struct MessageHeader {
    unsigned short refs, length, capacity;
    void release() {
        if (!--refs) {
            fn_8020bb2c(this);
        }
    }
};
struct MessageString {
 MessageString(const MessageString &); MessageString() {}
    char *p;
    ~MessageString() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned length() const { return *(unsigned short *)(p - 4); }
    void assign(const MessageString &other) {
        ++((MessageHeader *)(other.p - 6))->refs;
        ((MessageHeader *)(p - 6))->release();
        p = other.p;
    }
};
struct MessageDefault_803426b8 : MessageString { MessageDefault_803426b8(); };
struct MessageFrom_8020bb54 : MessageString { MessageFrom_8020bb54(const char *); };
struct MessageCopy : MessageString {
    MessageCopy(const MessageString &s) {
        fn_8020c5c0(this);
        p = s.p;
        unsigned short *h = fn_80341884(this);
        ++*h;
    }
};
struct MessageSource {
    char unknown00[11];
    unsigned char flags;   // +11
    char unknown12[120];
    MessageString first;   // +132 (entries are pointer-sized views)
};
struct MessageList {
    char unknown00[24];
    unsigned count;        // +24
};
struct MessageData {
    char unknown00[28];
    MessageList *list;     // +28
};
struct Expander {
    char unknown00[40];
    char *source;          // +40
    char unknown44[96];
    int enabled;           // +140
    char unknown144[140];
    void *holder;          // +284
    char unknown288[12];
    int index;             // +300
};
extern "C" void *fn_80341584(void *), *fn_801797b4(void *);
extern "C" unsigned fn_802ef380(const char *, const char *);
extern "C" void fn_8020c3a0(void *, unsigned), fn_8020c510(void *, const char *, ...), fn_802b1258(const char *);
extern const char empty_803cbf34[], marker_803cbf38[], format_803cbf3c[];
extern "C" void w3d_d24k_expand_message_8026fc98(Expander *self, int alternate) {
    char *context = self->source;
    MessageDefault_803426b8 message;
    if (alternate) {
        message.assign(*(MessageString *)(context + 132));
    }
    else {
        message.assign(*(MessageString *)(context + 136));
    }
    if (message.length() && ((((MessageSource *)self->source)->flags ^ 4) & 4) && self->holder
        && self->index >= 0 && self->enabled) {
        MessageFrom_8020bb54 selected(empty_803cbf34);
        MessageData *data = (MessageData *)fn_801797b4(fn_80341584(self->holder));
        MessageList *items;
        int index;
        index = self->index;
        items = data->list;
        if (items->count > (unsigned)index) {
            unsigned offset = index * 4;
            char *values = (char *)items + 32;
            const MessageString &item = *(const MessageString *)(offset + (unsigned)values);
            selected.assign(item);
        }
        else {
            return;
        }
        MessageCopy expanded(message);
        MessageDefault_803426b8 prefix;
        while (expanded.length()) {
            prefix.assign(expanded);
            char *start = expanded.p;
            unsigned split = fn_802ef380(start, marker_803cbf38);
            if (start[split] != '@') {
                break;
            }
            fn_8020c3a0(&prefix, split);
            ++split;
            fn_8020c510(&expanded, format_803cbf3c, prefix.p, selected.p, expanded.p + split);
        }
        fn_802b1258(expanded.p);
    }
}
