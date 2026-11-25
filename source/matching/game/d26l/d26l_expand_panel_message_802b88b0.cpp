// GWMP8P rev0 0x802b88b0. Message placeholder expansion, sibling of
// w3d_d24k_expand_message_8026fc98 that builds the result by appending.
// Expander and its source are partial views; field roles are inferred.
// Strings are one word with a user copy constructor.
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
struct MessageList { char u[24]; unsigned count; };
struct MessageData { char u[28]; MessageList *list; };
struct Base_802b222c { void fn_802b222c(); };
struct Expander {
    char u0[28]; Base_802b222c base;
    char u29[11];
    char *source;          // +40
    char u44[96];
    int enabled;           // +140
    char u144[136];
    void *holder;          // +280
    char u284[12];
    int index;             // +296
};
extern "C" void *fn_80341584(void *), *fn_801797b4(void *);
extern "C" unsigned fn_802ef380(const char *, const char *);
extern "C" void fn_8020c3a0(void *, unsigned), fn_802b1258(const char *);
extern "C" void * fn_8020bf2c(void *, const char *);
extern "C" void fn_8020bd38(void *, const char *);
extern const char empty_803d80d8[], marker_803d80dc[];
extern "C" void d26l_expand_panel_message_802b88b0(Expander *self, int alternate) {
    char *context = self->source;
    MessageDefault_803426b8 message;
    MessageFrom_8020bb54 result(empty_803d80d8);
    if (alternate) {
        message.assign(*(MessageString *)(context + 156));
    }
    else {
        message.assign(*(MessageString *)(context + 160));
    }
    if (alternate) self->base.fn_802b222c();
    if (message.length() && (((unsigned char)self->source[11] ^ 4) & 4) && self->holder
        && self->index >= 0 && self->enabled) {
        MessageFrom_8020bb54 selected(empty_803d80d8);
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
