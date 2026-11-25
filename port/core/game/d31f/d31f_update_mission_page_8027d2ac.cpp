#include "w3d_ptr.h"
#line 1 "d31f_update_mission_page_8027d2ac.cpp"
// GWMP8P rev0 0x8027d2ac. Fills the mission page properties for the current
// category and mission: title, description, level, previous and next flags,
// and for category four the gold, silver and bronze names and best times
// from the team barracks scores, then posts FE.SetLevel with the chosen
// string. Times are shown as minutes and seconds.
// Observed handle, descriptor, string and team record views; roles inferred.
struct Obj { Ptr32<Ptr32<void>> table; };
inline void retain(Ptr32<Obj> p) { if (p) ((Ptr32<void (Ptr32<Obj>)>)p->table[3])(p); }
inline void release(Ptr32<Obj> p) { if (p) ((Ptr32<void (Ptr32<Obj>)>)p->table[4])(p); }
struct Handle {
    Ptr32<Obj> p;
    Handle() : p(0) {}
    template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((Obj *)w3d_p.get()) {}
 Handle(Obj *x) : p(x) { retain(p); }
    Handle(const Handle &o) : p(o.p) { retain(p); }
    ~Handle() { release(p); }
    Handle &operator=(const Handle &o) { Ptr32<Obj> next = o.p; if (next) { retain(next); release(p); p = next; } return *this; }
};
struct Descriptor_80178474 { int zero; unsigned type; Descriptor_80178474() : zero(0), type(58280) {} ~Descriptor_80178474(); };
extern "C" void w3d_string_base_finish(Ptr32<void>), w3d_string_release(Ptr32<void>), w3d_string_release_header(Ptr32<void>);
struct String_803426b8 {
    Ptr32<char> text;
    String_803426b8();
    template <class W3dU> String_803426b8(Ptr32<W3dU> w3d_p) : String_803426b8((const char *)w3d_p.get()) {}
 String_803426b8(const char *);
    String_803426b8(const String_803426b8 &);
    unsigned Length() const { return ((Ptr32<unsigned short>)text)[-2]; }
    ~String_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
    String_803426b8 &operator=(const String_803426b8 &other) {
        ++*(Ptr32<unsigned short>)(other.text - 6);
        Ptr32<char> old = text;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short references = --*header;
        if (!references)
            w3d_string_release_header(header);
        text = other.text;
        return *this;
    }
};
typedef String_803426b8 String;
extern "C" void w3d_string_base_init(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<String>);
inline String_803426b8::String_803426b8(const String_803426b8 &other) {
    w3d_string_base_init(this);
    text = other.text;
    ++*w3d_string_header(this);
}
inline void DebugNote(String) {}
extern "C" void w3d_auto_8015f558(Ptr32<void>, int);
struct CacheBase { int prefix[2]; ~CacheBase() { w3d_auto_8015f558(this, 2); } };
struct Cache_8015f704 : CacheBase { String name __attribute__((aligned(__alignof__(CacheBase)))); template <class W3dU> Cache_8015f704(Ptr32<W3dU> w3d_p) : Cache_8015f704((const char *)w3d_p.get()) {}
 Cache_8015f704(const char *); };
typedef Ptr32<const char> Text;
struct Score { char pad[20]; unsigned bronzeTime; String bronze; unsigned silverTime; String silver; unsigned goldTime; String gold; };
struct ScoreList { char pad[24]; unsigned count; char pad28[4]; Ptr32<Score> items[1]; };
struct Scores { char pad[20]; Ptr32<ScoreList> list; };
struct Message;
extern char lbl_803ce9a0[], lbl_803ceab4[], lbl_803ceb0c[], lbl_803ceb18[], lbl_803ceb24[], lbl_803ceb30[], lbl_803ceb40[], lbl_803ceb44[], lbl_803ceaa0[], lbl_803ceb50[], lbl_803ceb60[], lbl_803ceb74[], lbl_803ceb80[], lbl_803ceb8c[], lbl_803ceba4[], lbl_803cebbc[], lbl_803cebd4[], lbl_803cebe4[], lbl_803cebf4[], lbl_803cec04[], lbl_803cec14[], lbl_803cec24[], lbl_803cec34[], lbl_803cec44[], lbl_803cec54[], lbl_803cec64[];
extern Ptr32<void> lbl_804b1754;
extern "C" int w3d_constructor_lookup_name(const Text &, Handle &);
extern "C" Ptr32<Obj> w3d_empty_80341584(Ptr32<Obj>);
extern "C" Ptr32<Scores> w3d_auto_801797b4(Ptr32<Obj>);
extern "C" int w3d_auto_800fc230(const Text &, Ptr32<unsigned int>);
extern "C" int s8_property_read_800fc550(const Text &, Ptr32<const char>);
extern "C" int s8_property_write_800fc43c(const Text &, unsigned);
extern "C" Ptr32<String> w3d_string_assign(Ptr32<String>, Ptr32<const char>);
extern "C" void w3d_string_format(Ptr32<String>, Ptr32<const char>, ...);
extern "C" unsigned w3d_r25b_category_count_8027be7c(Ptr32<void>, unsigned);
extern "C" String w3d_team_description_8027c018(Ptr32<void>, unsigned, unsigned);
extern "C" String w3d_team_title_8027c24c(Ptr32<void>, unsigned, unsigned);
extern "C" String w3d_f7a_lookup_team_mission_80281924(Ptr32<void>, unsigned, unsigned);
extern "C" String sol35e2_choose_string_8027befc(Ptr32<void>, unsigned, unsigned);
extern "C" unsigned w3d_team_mission_count_8027dacc(Ptr32<void>, String);
extern "C" unsigned w3d_team_unlocked_8027dc5c(Ptr32<void>, String);
extern "C" unsigned w3d_f7a_lookup_team_skill_80281ea4(Ptr32<void>, int, unsigned);
extern "C" Ptr32<Message> tsonnet_b33_arena_801613f0(Ptr32<void>, int); Ptr32<Message> w3d_message_string_init(Ptr32<Message>, unsigned short, Ptr32<const char>);
extern "C" unsigned w3d_cached_message_id(Ptr32<Cache_8015f704>, int);
extern "C" int w3d_message_post_current(Ptr32<Message>);
extern "C" void d31f_update_mission_page_8027d2ac(Ptr32<void> self) {
    Ptr32<const char> key1 = lbl_803ce9a0;
    unsigned current;
    w3d_auto_800fc230(key1, &current);
    int category = current;
    Ptr32<const char> key2 = lbl_803ceab4;
    unsigned mission;
    w3d_auto_800fc230(key2, &mission);
    s8_property_read_800fc550(lbl_803ceb0c, w3d_team_description_8027c018(self, category, mission).text);
    s8_property_read_800fc550(lbl_803ceb18, w3d_team_title_8027c24c(self, category, mission).text);
    s8_property_read_800fc550(lbl_803ceb24, w3d_f7a_lookup_team_mission_80281924(self, category, mission).text);
    s8_property_write_800fc43c(lbl_803ceb30, mission != 0);
    unsigned last = w3d_r25b_category_count_8027be7c(self, category) - 1;
    switch (category) {
    case 0: {
        String none(lbl_803ceb40);
        unsigned count = w3d_team_mission_count_8027dacc(self, none);
        if (count > last)
            count = last;
        s8_property_write_800fc43c(lbl_803ceb44, mission < count);
        break;
    }
    case 4: {
        s8_property_write_800fc43c(lbl_803ceb44, mission < last);
        unsigned skill = w3d_f7a_lookup_team_skill_80281ea4(self, 4, mission);
        Handle teams;
        if (w3d_constructor_lookup_name(lbl_803ceaa0, teams) < 0)
            return;
        Ptr32<Scores> scores = w3d_auto_801797b4(w3d_empty_80341584(teams.p));
        String gold, goldTime, silver, silverTime, bronze, bronzeTime;
        unsigned goldMs, silverMs, bronzeMs;
        Ptr32<ScoreList> list = scores->list;
        Ptr32<Ptr32<Score>> items = list->items;
        if (list->count == 0) {
            w3d_string_assign(&gold, lbl_803ceb50);
            w3d_string_assign(&silver, lbl_803ceb50);
            w3d_string_assign(&bronze, lbl_803ceb50);
            w3d_string_assign(&goldTime, lbl_803ceb50);
            w3d_string_assign(&silverTime, lbl_803ceb50);
            w3d_string_assign(&bronzeTime, lbl_803ceb50);
            goldMs = 0;
            silverMs = 0;
            bronzeMs = 0;
        } else if (skill >= list->count) {
            w3d_string_assign(&gold, lbl_803ceb60);
            w3d_string_assign(&silver, lbl_803ceb74);
            w3d_string_assign(&bronze, lbl_803ceb60);
            w3d_string_assign(&goldTime, lbl_803ceb74);
            w3d_string_assign(&silverTime, lbl_803ceb60);
            w3d_string_assign(&bronzeTime, lbl_803ceb74);
            goldMs = 0;
            silverMs = 0;
            bronzeMs = 0;
        } else {
            gold = items[skill]->gold;
            silver = items[skill]->silver;
            bronze = items[skill]->bronze;
            goldMs = items[skill]->goldTime;
            silverMs = items[skill]->silverTime;
            bronzeMs = items[skill]->bronzeTime;
            w3d_string_format(&goldTime, lbl_803ceb80, goldMs / 60000, goldMs / 1000 - goldMs / 60000 * 60);
            w3d_string_format(&silverTime, lbl_803ceb80, silverMs / 60000, silverMs / 1000 - silverMs / 60000 * 60);
            w3d_string_format(&bronzeTime, lbl_803ceb80, bronzeMs / 60000, bronzeMs / 1000 - bronzeMs / 60000 * 60);
        }
        if (gold.Length() == 0)
            w3d_string_format(&gold, lbl_803ceb8c, skill);
        if (silver.Length() == 0)
            w3d_string_format(&silver, lbl_803ceba4, skill);
        if (bronze.Length() == 0)
            w3d_string_format(&bronze, lbl_803cebbc, skill);
        s8_property_read_800fc550(lbl_803cebd4, gold.text);
        s8_property_read_800fc550(lbl_803cebe4, silver.text);
        s8_property_read_800fc550(lbl_803cebf4, bronze.text);
        s8_property_read_800fc550(lbl_803cec04, goldTime.text);
        s8_property_read_800fc550(lbl_803cec14, silverTime.text);
        s8_property_read_800fc550(lbl_803cec24, bronzeTime.text);
        s8_property_write_800fc43c(lbl_803cec34, goldMs);
        s8_property_write_800fc43c(lbl_803cec44, silverMs);
        s8_property_write_800fc43c(lbl_803cec54, bronzeMs);
        break;
    }
    case 3: {
        String none(lbl_803ceb40);
        unsigned count = w3d_team_unlocked_8027dc5c(self, none);
        if (count > last - 1)
            count = last;
        s8_property_write_800fc43c(lbl_803ceb44, mission < count);
        break;
    }
    }
    Cache_8015f704 cache(lbl_803cec64);
    Ptr32<Message> m = tsonnet_b33_arena_801613f0(lbl_804b1754, 12);
    Ptr32<Cache_8015f704> c = &cache;
    unsigned short id = w3d_cached_message_id(c, 1);
    w3d_message_post_current(w3d_message_string_init(m, id, sol35e2_choose_string_8027befc(self, category, mission).text));
}


