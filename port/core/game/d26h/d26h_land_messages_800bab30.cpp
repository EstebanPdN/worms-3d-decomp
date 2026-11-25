#include "w3d_ptr.h"
#line 1 "d26h_land_messages_800bab30.cpp"
// GWMP8P rev0 0x800bab30. Land message handler. Names are inferred. A String
// passed by value is destroyed by the callee in this compiler: 0x800bc5d0
// ends by finishing its own parameter, so the caller has no destructor call
// for it.
struct String;
extern "C" Ptr32<String> string_default_803426b8(Ptr32<String>);
extern "C" Ptr32<String> string_from_text_8020bb54(Ptr32<String>, Ptr32<const char>);
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
extern "C" int strcmp_802ef234(Ptr32<const char>, Ptr32<const char>);
struct String {
    Ptr32<char> text;
    bool operator==(const char *o) const { return strcmp_802ef234(text, o) == 0; }
    String();
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
};
struct Msg { unsigned short id; unsigned char u2[2]; Ptr32<void> table; Ptr32<const char> Text(); };
extern "C" Ptr32<const char> msg_text_8010a8fc(Ptr32<Msg>);
extern "C" int base_handler_8015fb34(Ptr32<void>, Ptr32<Msg>);
extern "C" void start_800bb114(Ptr32<void>);
extern "C" void shutdown_800be980(Ptr32<void>);
extern "C" int cache_equals_8015f620(Ptr32<void>, unsigned short);
extern "C" void a_800bd954(Ptr32<void>);
extern "C" void b_800bd9d0(Ptr32<void>);
extern "C" void c_800bd920();
extern "C" Ptr32<String> string_suffix_8020c0fc(Ptr32<String>, const String &, int);
extern "C" void string_upper_8020c2e8(Ptr32<String>);
extern "C" int strcmp_802ef234(Ptr32<const char>, Ptr32<const char>);
extern "C" int load_xom_800bc5d0(Ptr32<void>, String);
extern "C" int load_other_800bc350(Ptr32<void>, String);
extern "C" Ptr32<Msg> arena_alloc_801613f0(Ptr32<void>, int);
extern "C" unsigned message_id_8015f5a0(Ptr32<void>, int);
extern "C" int message_post_8016239c(Ptr32<Msg>);
extern "C" Ptr32<void> held_get_800f34f0(Ptr32<void>);
extern "C" void held_release_800f34a0(Ptr32<void>);
extern "C" int load_held_800bc7c4(Ptr32<void>, Ptr32<void>, int, Ptr32<void>, int);
extern "C" void collide_800bda28(Ptr32<void>, Ptr32<Msg>);
extern "C" int clear_800bb3a0(Ptr32<void>);
extern "C" void broadcast_800bdc44(Ptr32<void>, String);
extern "C" void grid_800be3a0(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void>);
extern Ptr32<void> g_arena_804b1754; extern Ptr32<void> g_804b184c; extern Ptr32<void> g_804b1850;
extern unsigned char c_804ae590[8], c_804ae5a0[8], c_804ae5c0[8], c_804ae580[8], c_804ae5b0[8], c_804ae5a8[8], c_804ae588[8], c_804ae5c8[8], c_804ae5d0[8];
extern unsigned char t_8040db38[], g_8044becc[], g_8044bec0[];
inline void PostLoaded() {
    Ptr32<Msg> m = arena_alloc_801613f0(g_arena_804b1754, 8);
    m->id = message_id_8015f5a0(c_804ae5b0, 1);
    m->table = t_8040db38;
    message_post_8016239c(m);
}
extern "C" int d26h_land_messages_800bab30(Ptr32<void> self, Ptr32<Msg> m) {
    switch (m->id) {
    case 64:
        if (base_handler_8015fb34(self, m) >= 0) {
            start_800bb114(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        shutdown_800be980(self);
        break;
    default:
        if (cache_equals_8015f620(c_804ae590, m->id)) a_800bd954(self);
        else if (cache_equals_8015f620(c_804ae5a0, m->id)) b_800bd9d0(self);
        else if (cache_equals_8015f620(c_804ae5c0, m->id)) c_800bd920();
        else if (cache_equals_8015f620(c_804ae580, m->id)) {
            if (msg_text_8010a8fc(m) && *msg_text_8010a8fc(m)) {
                String name;
                string_suffix_8020c0fc(&name, String(msg_text_8010a8fc(m)), 3);
                string_upper_8020c2e8(&name);
                if (name == "XOM") load_xom_800bc5d0(self, String(msg_text_8010a8fc(m)));
                else load_other_800bc350(self, String(msg_text_8010a8fc(m)));
                PostLoaded();
            } else {
                load_held_800bc7c4(self, held_get_800f34f0(g_804b184c), 1, 0, 0);
                held_release_800f34a0(g_804b184c);
                PostLoaded();
            }
        }
        else if (cache_equals_8015f620(c_804ae5a8, m->id)) collide_800bda28(self, m);
        else if (cache_equals_8015f620(c_804ae588, m->id)) clear_800bb3a0(self);
        else if (cache_equals_8015f620(c_804ae5c8, m->id)) broadcast_800bdc44(self, String(msg_text_8010a8fc(m)));
        else if (cache_equals_8015f620(c_804ae5d0, m->id)) grid_800be3a0(self, g_804b1850, g_8044becc, g_8044bec0);
    }
    return base_handler_8015fb34(self, m);
}


