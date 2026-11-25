#include "w3d_ptr.h"
#line 1 "d24k_expand_message_8026fc98.cpp"
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
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020c5c0(Ptr32<void>), fn_8020bb2c(Ptr32<void>);
extern "C" Ptr32<unsigned short> fn_80341884(Ptr32<void>);
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
    Ptr32<char> p;
    ~MessageString() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned length() const { return *(Ptr32<unsigned short>)(p - 4); }
    void assign(const MessageString &other) {
        ++((Ptr32<MessageHeader>)(other.p - 6))->refs;
        ((Ptr32<MessageHeader>)(p - 6))->release();
        p = other.p;
    }
};
struct MessageDefault_803426b8 : MessageString { MessageDefault_803426b8(); };
struct MessageFrom_8020bb54 : MessageString { template <class W3dU> MessageFrom_8020bb54(Ptr32<W3dU> w3d_p) : MessageFrom_8020bb54((const char *)w3d_p.get()) {}
 MessageFrom_8020bb54(const char *); };
struct MessageCopy : MessageString {
    MessageCopy(const MessageString &s) {
        fn_8020c5c0(this);
        p = s.p;
        Ptr32<unsigned short> h = fn_80341884(this);
        ++*h;
    }
};
struct MessageSource {
    char unknown00[8];
    unsigned char flags; char w3d_tag_rest[3];   // +11
    char unknown12[120];
    MessageString first;   // +132 (entries are pointer-sized views)
};
struct MessageList {
    char unknown00[24];
    unsigned count;        // +24
};
struct MessageData {
    char unknown00[28];
    Ptr32<MessageList> list;     // +28
};
struct Expander {
    char unknown00[40];
    Ptr32<char> source;          // +40
    char unknown44[96];
    int enabled;           // +140
    char unknown144[140];
    Ptr32<void> holder;          // +284
    char unknown288[12];
    int index;             // +300
};
extern "C" Ptr32<void> fn_80341584(Ptr32<void>); Ptr32<void> fn_801797b4(Ptr32<void>);
extern "C" unsigned fn_802ef380(Ptr32<const char>, Ptr32<const char>);
extern "C" void fn_8020c3a0(Ptr32<void>, unsigned), fn_8020c510(Ptr32<void>, Ptr32<const char>, ...), fn_802b1258(Ptr32<const char>);
extern const char empty_803cbf34[], marker_803cbf38[], format_803cbf3c[];
extern "C" void w3d_d24k_expand_message_8026fc98(Ptr32<Expander> self, int alternate) {
    Ptr32<char> context = self->source;
    MessageDefault_803426b8 message;
    if (alternate) {
        message.assign(*(Ptr32<MessageString>)(context + 132));
    }
    else {
        message.assign(*(Ptr32<MessageString>)(context + 136));
    }
    if (message.length() && ((((Ptr32<MessageSource>)self->source)->flags ^ 4) & 4) && self->holder
        && self->index >= 0 && self->enabled) {
        MessageFrom_8020bb54 selected(empty_803cbf34);
        Ptr32<MessageData> data = (Ptr32<MessageData>)fn_801797b4(fn_80341584(self->holder));
        Ptr32<MessageList> items;
        int index;
        index = self->index;
        items = data->list;
        if (items->count > (unsigned)index) {
            unsigned offset = index * 4;
            Ptr32<char> values = (Ptr32<char>)items + 32;
            const MessageString &item = *(Ptr32<const MessageString>)w3d::G((offset + (unsigned)w3d::H(values)));
            selected.assign(item);
        }
        else {
            return;
        }
        MessageCopy expanded(message);
        MessageDefault_803426b8 prefix;
        while (expanded.length()) {
            prefix.assign(expanded);
            Ptr32<char> start = expanded.p;
            unsigned split = fn_802ef380(start, marker_803cbf38);
            if (start[split] != '@') {
                break;
            }
            fn_8020c3a0(&prefix, split);
            ++split;
            fn_8020c510(&expanded, format_803cbf3c, w3d::VA(prefix.p), w3d::VA(selected.p), w3d::VA(expanded.p + split));
        }
        fn_802b1258(expanded.p);
    }
}


