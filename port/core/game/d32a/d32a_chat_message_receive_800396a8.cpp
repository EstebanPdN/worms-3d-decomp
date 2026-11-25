#include "w3d_ptr.h"
#line 1 "d32a_chat_message_receive_800396a8.cpp"
// GWMP8P rev0 0x800396a8. Handles an incoming chat message: opens the chat
// page if needed, finds the active worm and its team, reads the mailbox and
// login nick settings, picks the sender and text according to the message
// class (all, team when the team or sender matches, private when the nick
// matches), appends both strings and an item to the chat screen's arrays,
// and announces ChatMessages. Names are inferred from the original strings
// and instructions.
struct Object;
struct ObjectVtable { Ptr32<void> unknown00[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct Descriptor_80178474 {
    Ptr32<void> value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct String;
extern "C" void w3d_string_base_finish(Ptr32<String>);
extern "C" void w3d_string_release(Ptr32<String>);
extern "C" void w3d_string_release_header(Ptr32<void>);
extern "C" Ptr32<String> w3d_string_assign(Ptr32<String>, Ptr32<const char>);
extern "C" void w3d_k6b_string_from_int_8020bcc0(Ptr32<String>, int);
struct String {
    Ptr32<const char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(int);
    String(const String &o);
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
    String &operator=(const String &o) {
        ++*(Ptr32<unsigned short>)(o.text - 6);
        Ptr32<unsigned short> h = (Ptr32<unsigned short>)(text - 6);
        if (--*h == 0) w3d_string_release_header(h);
        text = o.text;
        return *this;
    }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((const char *)w3d_p.get()); }
 String &operator=(const char *s) { w3d_string_assign(this, s); return *this; }
};
struct ArrayHeader { char pad[4]; unsigned short kind; char pad2[18]; int count; unsigned short locks; char pad3[2]; String data[1]; };
struct ArrayRef { Ptr32<ArrayHeader> header; };
extern "C" Ptr32<String> w3d_k5b_array_ref_lock_801ef048(Ptr32<ArrayRef>, int, int, int);
inline Ptr32<String> Lock(Ptr32<ArrayRef> array, int size) {
    Ptr32<ArrayHeader> header = array->header;
    if (header->kind == 1 && size == header->count) {
        ++header->locks;
        return header->data;
    }
    return w3d_k5b_array_ref_lock_801ef048(array, size, 4, 2);
}
struct Screen : Object { char pad[16] __attribute__((aligned(__alignof__(Object)))); ArrayRef third; ArrayRef names; ArrayRef texts; };
struct Handle {
    Ptr32<Screen> value;
    Handle() : value(0) {}
    template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((Screen *)w3d_p.get()) {}
 Handle(Screen *next) : value(next) { if (value) value->vtable->retain(value); }
    Handle(const Handle &);
    ~Handle() { if (value) value->vtable->release(value); }
    void assign(Ptr32<Screen> next) {
        if (next) {
            next->vtable->retain(next);
            if (value) value->vtable->release(value);
            value = next;
        }
    }
};
struct Team { char pad[60]; unsigned char id; };
struct Worm { char pad[213]; unsigned char team; };
struct Self;
struct SelfTable { char pad[48]; Ptr32<void (Ptr32<Self>, int, Ptr32<String>)> add; };
struct Self { Ptr32<SelfTable> t; char pad[28]; Ptr32<void> owner; int open; char pad2[16]; Ptr32<Worm> worm; Ptr32<Team> team; };
struct Id { int words[2]; };
struct Msg { unsigned short id; Ptr32<Ptr32<void>> table; };
extern Ptr32<void> g_arena_804b1754;
extern Id g_id_804ad0c8, g_id_804ad0b8;
extern Ptr32<void> g_msg_table_8040db38[];
extern char s_80374060[], s_80374064[];
extern "C" Ptr32<void> tsonnet_b33_arena_801613f0(Ptr32<void>, int);
extern "C" int w3d_cached_message_id(Ptr32<Id>, int);
extern "C" int w3d_message_post_current(Ptr32<void>);
extern "C" Ptr32<void> w3d_message_string_init(Ptr32<void>, unsigned short, Ptr32<const char>);
extern "C" int w3d_auto_800fc1f0(Ptr32<Ptr32<const char>>, Ptr32<int>);
extern "C" int w3d_auto_800fc2b0(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<const char>>);
extern "C" Ptr32<Worm> s8_index_query_800fc6dc(int);
extern "C" Ptr32<Team> s8_index_query_800fc7f8(int);
extern "C" int w3d_get_800a4f4c(Ptr32<void>);
extern "C" Ptr32<const char> w3d_get_800a4f5c(Ptr32<void>);
extern "C" Ptr32<const char> w3d_get_800a4f6c(Ptr32<void>);
extern "C" Ptr32<const char> w3d_get_800a4f7c(Ptr32<void>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" Ptr32<void> w3d_empty_80341584(Ptr32<void>);
extern "C" Ptr32<Screen> w3d_auto_80179598(Ptr32<void>, Ptr32<Descriptor_80178474>);
extern "C" void w3d_d32a_chat_message_receive_800396a8(Ptr32<Self> self, Ptr32<void> msg)
{
    if (!self->open) {
        Ptr32<Msg> m = (Ptr32<Msg>)tsonnet_b33_arena_801613f0(g_arena_804b1754, 8);
        m->id = w3d_cached_message_id(&g_id_804ad0c8, 1);
        m->table = g_msg_table_8040db38;
        w3d_message_post_current(m);
    }
    Ptr32<const char> n1 = "ActiveWormIndex";
    int idx = 0;
    w3d_auto_800fc1f0(&n1, &idx);
    self->worm = s8_index_query_800fc6dc(idx);
    self->team = s8_index_query_800fc7f8(self->worm->team);
    w3d_get_800a4f4c(msg);
    Ptr32<const char> n2 = s_80374064;
    Ptr32<const char> box;
    w3d_auto_800fc2b0(&n2, &box);
    Ptr32<const char> teamText = String(self->team->id).text;
    Ptr32<const char> n3 = "GS.Login.Nick";
    Ptr32<const char> nick;
    w3d_auto_800fc2b0(&n3, &nick);
    String text(s_80374060);
    String who(s_80374060);
    String &rw = who;
    switch (w3d_get_800a4f4c(msg)) {
    case 3:
        rw = s_80374060;
        text = w3d_get_800a4f7c(msg);
        break;
    case 2:
        if (strcmp(w3d_get_800a4f6c(msg), teamText) != 0 && strcmp(w3d_get_800a4f5c(msg), nick) != 0) break;
    case 0:
        rw = w3d_get_800a4f5c(msg);
        text = w3d_get_800a4f7c(msg);
        break;
    case 1:
        if (strcmp(w3d_get_800a4f6c(msg), nick) != 0 && strcmp(w3d_get_800a4f5c(msg), nick) != 0) break;
        rw = w3d_get_800a4f5c(msg);
        text = w3d_get_800a4f7c(msg);
        break;
    }
    Descriptor_80178474 d;
    Handle h;
    {
        Handle t(w3d_auto_80179598(w3d_empty_80341584(self->owner), &d));
        h.assign(t.value);
    }
    {
        int n = h.value->names.header->count;
        Ptr32<String> d = Lock(&h.value->names, n + 1);
        d[n] = text;
    }
    {
        int n = h.value->texts.header->count;
        Ptr32<String> d = Lock(&h.value->texts, n + 1);
        d[n] = who;
    }
    {
        int n = h.value->third.header->count;
        Ptr32<String> p = Lock(&h.value->third, n + 1);
        self->t->add(self, w3d_get_800a4f4c(msg), &p[n]);
    }
    Ptr32<void> m = tsonnet_b33_arena_801613f0(g_arena_804b1754, 12);
    unsigned short mid = w3d_cached_message_id(&g_id_804ad0b8, 1);
    w3d_message_post_current(w3d_message_string_init(m, mid, "ChatMessages"));
}


