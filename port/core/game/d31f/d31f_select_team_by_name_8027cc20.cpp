#include "w3d_ptr.h"
#line 1 "d31f_select_team_by_name_8027cc20.cpp"
// GWMP8P rev0 0x8027cc20. Selects a barracks team by name for the current
// game: resolves the first-team request, marks the chosen team, copies its
// name, flag, stats, weapons and speech fields into the game init data,
// stores its name in the MCa.Team property and refreshes the page.
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
    Ptr32<const char> c_str() const { return text; }
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
struct Key { Ptr32<const char> text; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *p) : text(p) {} };
struct NameList { char pad[24]; unsigned count; };
struct Fort { char pad[32]; String s32; String s36; String s40; String s44; String s48; String s52; };
struct Team {
    char pad[24]; String s24; String s28; int v32; int v36; int v40; char pad2[4]; unsigned v48; Ptr32<NameList> names; Ptr32<Fort> fort; String name; int selected;
};
struct TeamList { char pad[24]; unsigned count; char pad2[4]; Ptr32<Team> items[1]; };
struct Data { char pad[24]; Ptr32<TeamList> list; };
struct Info {
    char pad[20]; int v20; int v24; int v28; String s32; String s36; String s40; String s44; String s48; char pad2[4]; int v56; char pad3[4]; String s64;
    char pad4[24]; int v92; String s96; char pad5[60]; String s160; char pad6[100]; String s264;
};
extern char lbl_803cea38[], lbl_803ceaf0[], lbl_803cea5c[], lbl_803cea68[], lbl_803ceaa0[], lbl_803ceab4[], lbl_803ceac8[], lbl_803cecd0[];
extern Ptr32<void> lbl_804b1754;
struct Message;
extern "C" int w3d_constructor_lookup_name(Ptr32<const char> const &, Handle &);
extern "C" Ptr32<Obj> w3d_empty_80341584(Ptr32<Obj>);
extern "C" Ptr32<Obj> w3d_auto_80179598(Ptr32<Obj>, Ptr32<Descriptor_80178474>);
extern "C" Ptr32<Data> w3d_auto_801797b4(Ptr32<Obj>);
extern "C" int w3d_auto_800fc230(Ptr32<const char> const &, Ptr32<unsigned int>);
extern "C" int w3d_auto_800fc2b0(Ptr32<const char> const &, Ptr32<Ptr32<const char>>);
extern "C" int s8_property_read_800fc550(Ptr32<const char> const &, Ptr32<const char>);
extern "C" int s8_property_write_800fc43c(Ptr32<const char> const &, unsigned);
extern "C" void w3d_string_assign(Ptr32<String>, Ptr32<const char>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" int w3d_barracks_team_available_80281c04(Ptr32<void>, Ptr32<const char>);
extern "C" unsigned w3d_r25b_category_count_8027be7c(Ptr32<void>, int);
extern "C" void fn_8027d2ac(Ptr32<void>);
extern "C" Ptr32<Message> tsonnet_b33_arena_801613f0(Ptr32<void>, int); Ptr32<Message> w3d_message_string_init(Ptr32<Message>, unsigned short, Ptr32<const char>);
extern "C" unsigned w3d_cached_message_id(Ptr32<Cache_8015f704>, int);
extern "C" void w3d_message_post_current(Ptr32<Message>);
extern "C" void d31f_select_team_by_name_8027cc20(Ptr32<void> self, Ptr32<const char> text) {
    Descriptor_80178474 descriptor;
    Handle game;
    Handle teams;
    s8_property_write_800fc43c(lbl_803cea38, 0);
    if (strcmp(text, lbl_803ceaf0) == 0) {
        Ptr32<const char> current;
        w3d_auto_800fc2b0(lbl_803cea5c, &current);
        if (w3d_barracks_team_available_80281c04(self, current) == 1)
            text = current;
    }
    String name(text);
    if (w3d_constructor_lookup_name(lbl_803cea68, game) < 0)
        return;
    Handle info;
    Ptr32<Obj> converted;
    converted = w3d_auto_80179598(w3d_empty_80341584(game.p), &descriptor);
    info = Handle(converted);
    if (w3d_constructor_lookup_name(lbl_803ceaa0, teams) < 0)
        return;
    Ptr32<Data> data = w3d_auto_801797b4(w3d_empty_80341584(teams.p));
    unsigned count = data->list->count;
    if (name.Length() == 0) {
        Ptr32<const char> current;
        w3d_auto_800fc2b0(lbl_803cea5c, &current);
        w3d_string_assign(&name, current);
    }
    Ptr32<Ptr32<Team>> items = data->list->items;
    if (strcmp(name.text, lbl_803ceaf0) == 0 || name.Length() == 0) {
        for (unsigned j = 0; j < count; j++) {
            Ptr32<Team> team = items[j];
            if (team->v40 == 0) {
                name = team->name;
                break;
            }
        }
    }
    unsigned i = 0;
    unsigned index = 0;
    for (; i < count; i++) {
        items[i]->selected = 0;
        if (strcmp(name.text, items[i]->name.c_str()) == 0) {
            index = i;
            items[i]->selected = 1;
        }
    }
    ((Ptr32<Info>)info.p)->v92 = 1;
    i = index;
    { Ptr32<Team> t = items[i]; Ptr32<Info> g = (Ptr32<Info>)info.p; g->s64 = t->name; }
    { Ptr32<Team> t = items[i]; Ptr32<Info> g = (Ptr32<Info>)info.p; g->s96 = t->s28; }
    ((Ptr32<Info>)info.p)->v24 = items[i]->v36;
    ((Ptr32<Info>)info.p)->v28 = items[i]->v40;
    { Ptr32<Team> t = items[i]; Ptr32<Info> g = (Ptr32<Info>)info.p; g->s160 = t->s24; }
    ((Ptr32<Info>)info.p)->v20 = items[i]->v32;
    ((Ptr32<Info>)info.p)->v56 = 4;
    {
        Ptr32<Fort> f = items[i]->fort;
        { Ptr32<Info> g = (Ptr32<Info>)info.p; g->s264 = *(Ptr32<String>)&f->s32; }
        { Ptr32<Info> g = (Ptr32<Info>)info.p; g->s48 = f->s36; }
        { Ptr32<Info> g = (Ptr32<Info>)info.p; g->s44 = f->s40; }
        { Ptr32<Info> g = (Ptr32<Info>)info.p; g->s40 = f->s44; }
        { Ptr32<Info> g = (Ptr32<Info>)info.p; g->s36 = f->s48; }
        { Ptr32<Info> g = (Ptr32<Info>)info.p; g->s32 = f->s52; }
    }
    s8_property_read_800fc550(lbl_803cea5c, items[i]->name.c_str());
    fn_8027d2ac(self);
}


