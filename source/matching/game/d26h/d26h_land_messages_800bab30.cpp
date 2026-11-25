// GWMP8P rev0 0x800bab30. Land message handler. Names are inferred. A String
// passed by value is destroyed by the callee in this compiler: 0x800bc5d0
// ends by finishing its own parameter, so the caller has no destructor call
// for it.
struct String;
extern "C" String *string_default_803426b8(String *);
extern "C" String *string_from_text_8020bb54(String *, const char *);
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
extern "C" int strcmp_802ef234(const char *, const char *);
struct String {
    char *text;
    bool operator==(const char *o) const { return strcmp_802ef234(text, o) == 0; }
    String();
    String(const char *);
    String(const String &);
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
};
struct Msg { unsigned short id; unsigned char u2[2]; void *table; const char *Text(); };
extern "C" const char *msg_text_8010a8fc(Msg *);
extern "C" int base_handler_8015fb34(void *, Msg *);
extern "C" void start_800bb114(void *);
extern "C" void shutdown_800be980(void *);
extern "C" int cache_equals_8015f620(void *, unsigned short);
extern "C" void a_800bd954(void *);
extern "C" void b_800bd9d0(void *);
extern "C" void c_800bd920();
extern "C" String *string_suffix_8020c0fc(String *, const String &, int);
extern "C" void string_upper_8020c2e8(String *);
extern "C" int strcmp_802ef234(const char *, const char *);
extern "C" int load_xom_800bc5d0(void *, String);
extern "C" int load_other_800bc350(void *, String);
extern "C" Msg *arena_alloc_801613f0(void *, int);
extern "C" unsigned message_id_8015f5a0(void *, int);
extern "C" int message_post_8016239c(Msg *);
extern "C" void *held_get_800f34f0(void *);
extern "C" void held_release_800f34a0(void *);
extern "C" int load_held_800bc7c4(void *, void *, int, void *, int);
extern "C" void collide_800bda28(void *, Msg *);
extern "C" int clear_800bb3a0(void *);
extern "C" void broadcast_800bdc44(void *, String);
extern "C" void grid_800be3a0(void *, void *, void *, void *);
extern void *g_arena_804b1754, *g_804b184c, *g_804b1850;
extern unsigned char c_804ae590[8], c_804ae5a0[8], c_804ae5c0[8], c_804ae580[8], c_804ae5b0[8], c_804ae5a8[8], c_804ae588[8], c_804ae5c8[8], c_804ae5d0[8];
extern unsigned char t_8040db38[], g_8044becc[], g_8044bec0[];
inline void PostLoaded() {
    Msg *m = arena_alloc_801613f0(g_arena_804b1754, 8);
    m->id = message_id_8015f5a0(c_804ae5b0, 1);
    m->table = t_8040db38;
    message_post_8016239c(m);
}
extern "C" int d26h_land_messages_800bab30(void *self, Msg *m) {
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
