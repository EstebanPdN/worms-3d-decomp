#include "w3d_ptr.h"
#line 1 "d27f_team_name_button_802991b0.cpp"
// GWMP8P rev0 0x802991b0. Handles the team name buttons. 'Find New' builds
// the first unused numbered name from the FE.Tip text and stores it in
// User.HumanTeam. Any other name validates the current User.HumanTeam text
// (rejects empty, leading space, only digits and punctuation, or a duplicate
// in the barracks) and forwards the result to 0x80299b48. Field names are
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
extern char lbl_803d097c[], lbl_803d09ec[], lbl_803d0b64[], lbl_803d0b70[], lbl_803d0b80[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Ptr32<Obj> w3d_empty_80341584(Ptr32<Obj>);
extern "C" Ptr32<Data> w3d_auto_801797b4(Ptr32<Obj>);
extern "C" int w3d_auto_800fc2b0(const Key &, Ptr32<Ptr32<const char>>);
extern "C" int s8_property_read_800fc550(const Key &, Ptr32<const char>);
extern "C" void w3d_string_format(Ptr32<String>, Ptr32<const char>, ...);
extern "C" void w3d_string_assign(Ptr32<String>, Ptr32<const char>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" unsigned strlen(Ptr32<const char>);
extern "C" void w3d_f6a_set_flag_80299b48(Ptr32<void>, String, int);
inline int Same(Ptr32<const char> a, Ptr32<const char> b) { return strcmp(a, b) == 0; }
extern "C" void d27f_team_name_button_802991b0(Ptr32<void> self, String name) {
    if (name.Length() == 0)
        return;
    if (Same(name.text, lbl_803d0b64)) {
        Handle data;
        if (w3d_constructor_lookup_name(lbl_803d097c, data) < 0)
            return;
        Ptr32<List> list = w3d_auto_801797b4(w3d_empty_80341584(data.p))->list;
        unsigned count = list->count;
        Ptr32<Ptr32<Entry>> items = list->items;
        int number = 0;
        String tip;
        Ptr32<const char> text;
        w3d_auto_800fc2b0(lbl_803d0b70, &text);
        int unique;
        do {
            number++;
            unsigned i = 0;
            w3d_string_format(&tip, lbl_803d0b80, w3d::VA(text), number);
            unique = 1;
            if (i < count)
                do {
                    if (strcmp(items[i]->name, tip.text) == 0) {
                        unique = 0;
                        break;
                    }
                    i++;
                } while (i < count);
        } while (!unique);
        s8_property_read_800fc550(lbl_803d09ec, tip.text);
        return;
    }
    String current;
    int invalid = 0;
    Ptr32<const char> text;
    w3d_auto_800fc2b0(lbl_803d09ec, &text);
    w3d_string_assign(&current, text);
    if (current.Length() == 0 || text[0] == ' ')
        invalid = 1;
    unsigned i = 0;
    goto test;
    do {
        {
        unsigned char c = text[i];
        if (!(c - '0' <= 9u || (char)c == '-' || (char)c == '%' || (char)c == '+' || (char)c == '.' || (char)c == ' '))
            break;
        }
        i++;
    test:;
    } while (i < strlen(text));
    if (i == strlen(text))
        invalid = 1;
    Handle data;
    if (w3d_constructor_lookup_name(lbl_803d097c, data) < 0)
        return;
    if (!invalid) {
        unsigned j = 0;
        Ptr32<List> list = w3d_auto_801797b4(w3d_empty_80341584(data.p))->list;
        unsigned count = list->count;
        Ptr32<Ptr32<Entry>> items = list->items;
        if (j < count)
            do {
                if (strcmp(items[j]->name, current.text) == 0) {
                    invalid = 1;
                    break;
                }
                j++;
            } while (j < count);
    }
    w3d_f6a_set_flag_80299b48(self, name, invalid);
}


