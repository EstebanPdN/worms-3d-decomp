#include "w3d_ptr.h"
#line 1 "d27f_create_barracks_team_80297f7c.cpp"
// GWMP8P rev0 0x80297f7c. Creates a new team named by the by-value string in
// DATA.TeamBarracks. Mode 1 reads the name through a property first. Refuses
// a full list of 20 teams or a duplicate name, otherwise fills language-
// dependent flag and speech defaults, optionally overrides the flag from
// User.Skill, appends the team and stores MCa.Team, then selects it if
// asked. The zero local read by the append call has no direct witness: it
// reproduces the zero kept across the first lookup. Field names are
// inferred; the unit owns no data.
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
struct Key { Ptr32<const char> text; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *p) : text(p) {} };
struct Entry { char pad[60]; Ptr32<const char> name; };
struct List { char pad[24]; unsigned count; char pad2[4]; Ptr32<Entry> items[1]; };
struct Data { char pad[24]; Ptr32<List> list; };
struct Team { char pad[24]; String speech; String flag; int pad2[2]; int skill; int custom; char pad3[12]; String name; };
extern char lbl_803d097c[], lbl_803d0ab8[], lbl_803d0a54[], lbl_803d0a00[], lbl_803d0b18[], lbl_803d0ac8[], lbl_803d0acc[], lbl_803d0ad4[], lbl_803d0ad8[], lbl_803d0adc[], lbl_803d0ae4[], lbl_803d0ae8[], lbl_803d0af0[], lbl_803d0af4[], lbl_803d0afc[], lbl_803d0b00[], lbl_803d0b04[], lbl_803d0b08[], lbl_803d0b0c[], lbl_803d0b14[], lbl_80419eb8[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Ptr32<Obj> w3d_empty_80341584(Ptr32<Obj>);
extern "C" Ptr32<Obj> w3d_auto_80179598(Ptr32<Obj>, Ptr32<Descriptor_80178474>);
extern "C" int w3d_auto_800fc2b0(const Key &, Ptr32<Ptr32<const char>>);
extern "C" int w3d_auto_800fc230(const Key &, Ptr32<int>);
extern "C" int s8_property_read_800fc550(const Key &, Ptr32<const char>);
extern "C" void w3d_string_format(Ptr32<String>, Ptr32<const char>, ...);
extern "C" void w3d_string_assign(Ptr32<String>, Ptr32<const char>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" Ptr32<Team> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern "C" void w3d_k5b_iface_array_field_801ef174(Ptr32<Obj>, int, int, Ptr32<Team>);
extern "C" void fn_80297620(Ptr32<void>, String);
extern "C" void d27f_create_barracks_team_80297f7c(Ptr32<void> self, String name, int mode, int select) {
    if (name.Length() == 0)
        return;
    if (mode == 1) {
        Ptr32<const char> text;
        if (w3d_auto_800fc2b0(name.text, &text) < 0) {
            DebugNote(name);
            return;
        }
        w3d_string_assign(&name, text);
        if (name.Length() == 0)
            return;
    }
    Handle data;
    int none = 0;
    if (w3d_constructor_lookup_name(lbl_803d097c, data) < 0)
        return;
    {
        Descriptor_80178474 descriptor;
        Handle result;
        result = Handle(w3d_auto_80179598(w3d_empty_80341584(data.p), &descriptor));
        Ptr32<List> list = ((Ptr32<Data>)result.p)->list;
        unsigned count = list->count;
        Ptr32<Ptr32<Entry>> items = list->items;
        if (count > 19)
            return;
        if (count != 0)
            for (unsigned i = 0; i < count; i++) {
                if (strcmp(items[i]->name, name.text) == 0) {
                    DebugNote(name);
                    return;
                }
            }
        Ptr32<Team> team = w3d_s10_service_forward_8020b680(lbl_80419eb8);
        team->name = String(name.text);
        int custom = 0;
        if (mode) custom = 1;
        team->custom = custom;
        int language;
        w3d_auto_800fc230(lbl_803d0ab8, &language);
        switch (language) {
    case 0:
        team->flag = String(lbl_803d0ac8);
        team->speech = String(lbl_803d0acc);
        break;
    case 1:
        team->flag = String(lbl_803d0ad4);
        team->speech = String(lbl_803d0acc);
        break;
    case 3:
        team->flag = String(lbl_803d0ad8);
        team->speech = String(lbl_803d0adc);
        break;
    case 4:
        team->flag = String(lbl_803d0ae4);
        team->speech = String(lbl_803d0ae8);
        break;
    case 5:
        team->flag = String(lbl_803d0af0);
        team->speech = String(lbl_803d0af4);
        break;
    case 6:
        team->flag = String(lbl_803d0afc);
        team->speech = String(lbl_803d0acc);
        break;
    case 7:
        team->flag = String(lbl_803d0b00);
        team->speech = String(lbl_803d0acc);
        break;
    case 8:
        team->flag = String(lbl_803d0b04);
        team->speech = String(lbl_803d0acc);
        break;
    case 9:
        team->flag = String(lbl_803d0b08);
        team->speech = String(lbl_803d0b0c);
        break;
    case 2:
        team->flag = String(lbl_803d0b14);
        team->speech = String(lbl_803d0acc);
        break;
        }
        int skill;
        w3d_auto_800fc230(lbl_803d0a54, &skill);
        if (skill != 0) {
            String flag;
            w3d_string_format(&flag, lbl_803d0b18, skill + 114);
            team->flag = String(flag.text);
        }
        team->skill = skill;
        none = 0;
        w3d_k5b_iface_array_field_801ef174(result.p, 24, none, team);
        s8_property_read_800fc550(lbl_803d0a00, name.text);
    }
    if (select)
        fn_80297620(self, name);
}


