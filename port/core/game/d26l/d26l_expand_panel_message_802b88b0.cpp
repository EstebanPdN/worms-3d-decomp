#include "w3d_ptr.h"
#line 1 "d26l_expand_panel_message_802b88b0.cpp"
// GWMP8P rev0 0x802b88b0. Message placeholder expansion, sibling of
// w3d_d24k_expand_message_8026fc98 that builds the result by appending.
// Expander and its source are partial views; field roles are inferred.
// Strings are one word with a user copy constructor.
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
struct MessageList { char u[24]; unsigned count; };
struct MessageData { char u[28]; Ptr32<MessageList> list; };
struct Base_802b222c { void fn_802b222c();  char w3d_empty; };
struct Expander {
    char u0[28]; Base_802b222c base;
    char u29[11];
    Ptr32<char> source;          // +40
    char u44[96];
    int enabled;           // +140
    char u144[136];
    Ptr32<void> holder;          // +280
    char u284[12];
    int index;             // +296
};
extern "C" Ptr32<void> fn_80341584(Ptr32<void>); Ptr32<void> fn_801797b4(Ptr32<void>);
extern "C" unsigned fn_802ef380(Ptr32<const char>, Ptr32<const char>);
extern "C" void fn_8020c3a0(Ptr32<void>, unsigned), fn_802b1258(Ptr32<const char>);
extern "C" Ptr32<void> fn_8020bf2c(Ptr32<void>, Ptr32<const char>);
extern "C" void fn_8020bd38(Ptr32<void>, Ptr32<const char>);
extern const char empty_803d80d8[], marker_803d80dc[];
extern "C" void d26l_expand_panel_message_802b88b0(Ptr32<Expander> self, int alternate) {
    Ptr32<char> context = self->source;
    MessageDefault_803426b8 message;
    MessageFrom_8020bb54 result(empty_803d80d8);
    if (alternate) {
        message.assign(*(Ptr32<MessageString>)(context + 156));
    }
    else {
        message.assign(*(Ptr32<MessageString>)(context + 160));
    }
    if (alternate) self->base.fn_802b222c();
    if (message.length() && (((unsigned char)self->source[8] ^ 4) & 4) && self->holder
        && self->index >= 0 && self->enabled) {
        MessageFrom_8020bb54 selected(empty_803d80d8);
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
            unsigned split = fn_802ef380(start, marker_803d80dc);
            if (start[split] != '@') {
                fn_8020bf2c(&result, expanded.p);
                break;
            }
            fn_8020c3a0(&prefix, split);
            ++split;
            fn_8020bf2c(&result, prefix.p);
            fn_8020bf2c(&result, selected.p);
            fn_8020bd38(&expanded, expanded.p + split);
        }
        fn_802b1258(result.p);
    }
}


