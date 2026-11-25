#include "w3d_ptr.h"
#line 1 "d27f_delete_barracks_team_80298abc.cpp"
// GWMP8P rev0 0x80298abc. Deletes the current human team named by
// User.HumanTeam from DATA.TeamBarracks. With check equal to 1, a team whose
// +44 flag is not 1 is kept. After a removal, selects a default team through
// 0x80297620. The goto keeps the original's shared cleanup. Field names are
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
struct Team { char pad[44]; int custom; char pad2[12]; Ptr32<const char> name; };
struct List { char pad[24]; unsigned count; char pad2[4]; Ptr32<Team> items[1]; };
struct Data { char pad[24]; Ptr32<List> list; };
extern char lbl_803d09ec[], lbl_803d097c[], lbl_803d0b1c[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Ptr32<Obj> w3d_empty_80341584(Ptr32<Obj>);
extern "C" Ptr32<Obj> w3d_auto_80179598(Ptr32<Obj>, Ptr32<Descriptor_80178474>);
extern "C" int w3d_auto_800fc2b0(const Key &, Ptr32<Ptr32<const char>>);
extern "C" void w3d_string_assign(Ptr32<String>, Ptr32<const char>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" void fn_801ef380(Ptr32<Obj>, int, int, unsigned, int);
extern "C" void fn_80297620(Ptr32<void>, String);
extern "C" void d27f_delete_barracks_team_80298abc(Ptr32<void> self, int check) {
    String name;
    Ptr32<const char> text;
    w3d_auto_800fc2b0(lbl_803d09ec, &text);
    w3d_string_assign(&name, text);
    if (name.Length() == 0)
        return;
    int removed = 0;
    Handle data;
    if (w3d_constructor_lookup_name(lbl_803d097c, data) < 0)
        return;
    {
        Descriptor_80178474 descriptor;
        Handle result;
        result = Handle(w3d_auto_80179598(w3d_empty_80341584(data.p), &descriptor));
        Ptr32<List> list = ((Ptr32<Data>)result.p)->list;
        unsigned count = list->count;
        Ptr32<Ptr32<Team>> items = list->items;
        if (count != 0)
            for (unsigned i = 0; i < count; i++) {
                if (strcmp(items[i]->name, name.text) == 0) {
                    if (check == 1 && items[i]->custom != 1)
                        goto done;
                    fn_801ef380(result.p, 24, 0, i, 1);
                    removed = 1;
                    break;
                }
            }
    }
    if (removed == 1) {
        {
            String fallback(lbl_803d0b1c);
            fn_80297620(self, fallback);
        }
    done:
        return;
    }
    DebugNote(name);
}


