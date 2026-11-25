#include "w3d_ptr.h"
#line 1 "d27f_load_team_store_80297b8c.cpp"
// GWMP8P rev0 0x80297b8c. Reads the team settings back from the user
// properties into the temporary team store: numbered team member names (an
// all-blank name gets a formatted default), flag, speech, super weapon,
// skill and grave. Field names are inferred from the property strings; the
// unit owns no data.
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
struct Key { Ptr32<const char> text; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *p) : text(p) {} };
struct ArrayHeader { char pad[4]; unsigned short kind; char pad2[18]; unsigned count; unsigned short locks; char pad3[2]; String items[1]; };
struct ArrayRef { Ptr32<ArrayHeader> header; };
struct Team { char pad[24]; String speech; String flag; int sweapon; int grave; int skill; int field44; char pad2[8]; ArrayRef names; };
extern char lbl_803d0940[], lbl_803d0a0c[], lbl_803d0a60[], lbl_803d0a6c[], lbl_803d0a20[], lbl_803d0a2c[], lbl_803d0a3c[], lbl_803d0a48[], lbl_803d0a54[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Ptr32<Obj> w3d_empty_80341584(Ptr32<Obj>);
extern "C" Ptr32<Team> w3d_auto_80179598(Ptr32<Obj>, Ptr32<Descriptor_80178474>);
extern "C" int w3d_auto_800fc2b0(const Key &, Ptr32<Ptr32<const char>>);
extern "C" int w3d_auto_800fc230(const Key &, Ptr32<int>);
extern "C" void w3d_string_format(Ptr32<String>, Ptr32<const char>, ...);
extern "C" void w3d_string_assign(Ptr32<String>, Ptr32<const char>);
extern "C" Ptr32<char> strchr(Ptr32<const char>, int);
extern "C" Ptr32<String> w3d_k5b_array_ref_lock_801ef048(Ptr32<ArrayRef>, int, int, int);
inline Ptr32<String> Lock(Ptr32<ArrayRef> array) {
    Ptr32<ArrayHeader> header = array->header;
    int count = header->count;
    if (header->kind == 1) {
        ++header->locks;
        return header->items;
    }
    return w3d_k5b_array_ref_lock_801ef048(array, count, 4, 2);
}
extern "C" void d27f_load_team_store_80297b8c(Ptr32<void>) {
    Descriptor_80178474 descriptor;
    Handle store;
    if (w3d_constructor_lookup_name(lbl_803d0940, store) < 0)
        return;
    Handle result;
    result = Handle((Ptr32<Obj>)w3d_auto_80179598(w3d_empty_80341584(store.p), &descriptor));
    Ptr32<Team> team = (Ptr32<Team>)result.p;
    unsigned count = team->names.header->count;
    Ptr32<String> names = Lock(&team->names);
    String key;
    for (unsigned i = 0; i < count; i++) {
        w3d_string_format(&key, lbl_803d0a0c, i + 1);
        Ptr32<const char> text;
        w3d_auto_800fc2b0(key.text, &text);
        Ptr32<const char> p = text;
        while (*p && strchr(lbl_803d0a60, *p))
            p++;
        if (*p == 0)
            w3d_string_format(&names[i], lbl_803d0a6c, w3d::VA(text));
        else
            w3d_string_assign(&names[i], text);
    }
    Ptr32<const char> value;
    w3d_auto_800fc2b0(lbl_803d0a3c, &value);
    { Ptr32<Team> t = (Ptr32<Team>)result.p; t->flag = String(value); }
    ((Ptr32<Team>)result.p)->field44 = 0;
    w3d_auto_800fc2b0(lbl_803d0a48, &value);
    { Ptr32<Team> t = (Ptr32<Team>)result.p; t->speech = String(value); }
    int number;
    w3d_auto_800fc230(lbl_803d0a2c, &number);
    ((Ptr32<Team>)result.p)->sweapon = number;
    w3d_auto_800fc230(lbl_803d0a54, &number);
    ((Ptr32<Team>)result.p)->skill = number;
    w3d_auto_800fc230(lbl_803d0a20, &number);
    ((Ptr32<Team>)result.p)->grave = number;
}


