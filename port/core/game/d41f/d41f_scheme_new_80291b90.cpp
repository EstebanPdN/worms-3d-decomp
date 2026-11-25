#include "w3d_ptr.h"
#line 1 "d41f_scheme_new_80291b90.cpp"
// GWMP8P rev0 0x80291b90. Creates a new game scheme: looks up the scheme
// list and the current scheme data, rejects a name already in use, then
// resets the fields of the new scheme and of its copy. Handle, string, list
// and scheme views are observed; roles are inferred. The search is a label
// loop. The do/while forms wrap real code; see the caveat in d41f.json.
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
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 Handle &operator=(Obj *next) { retain(next); release(p); p = next; return *this; }
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
struct Slot { char pad[20]; int v20; char pad2[4]; int v28; int v32; };
struct Named { char pad[20]; Ptr32<const char> name; };
struct List { char pad[24]; unsigned count; char pad2[4]; Ptr32<Named> items[1]; };
struct Data { char pad[20]; Ptr32<List> list; };
struct Scheme {
    char pad0[20];
    String name;
    Ptr32<Slot> slot24;
    Ptr32<Slot> slot28;
    Ptr32<Slot> slot32;
    Ptr32<Slot> slot36;
    Ptr32<Slot> slot40;
    Ptr32<Slot> slot44;
    char pad48[12];
    Ptr32<Slot> slot60;
    char pad64[20];
    String title;
    char pad88[20];
    Ptr32<Slot> slot108;
    Ptr32<Slot> slot112;
    char pad116[4];
    Ptr32<Slot> slot120;
    Ptr32<Slot> slot124;
    Ptr32<Slot> slot128;
    char pad132[32];
    Ptr32<Slot> slot164;
    char pad168[16];
    Ptr32<Slot> slot184;
    char pad188[16];
    Ptr32<Slot> slot204;
    Ptr32<Slot> slot208;
    char pad212[4];
    Ptr32<Slot> slot216;
    char pad220[8];
    Ptr32<Slot> slot228;
    Ptr32<Slot> slot232;
    char pad236[56];
    Ptr32<Slot> slot292;
    char pad296[36];
    int locked;
};
extern char lbl_803d02ac[], lbl_803d0164[], lbl_803d0174[], lbl_803d0588[], lbl_803d02b4[], lbl_80413b28[];
extern "C" int w3d_constructor_lookup_name(Ptr32<const char> const &, Handle &);
extern "C" Ptr32<Obj> w3d_empty_80341584(Ptr32<Obj>);
extern "C" Ptr32<Obj> w3d_auto_80179598(Ptr32<Obj>, Ptr32<Descriptor_80178474>);
extern "C" int w3d_auto_800fc2b0(Ptr32<const char> const &, Ptr32<Ptr32<const char>>);
extern "C" int s8_property_write_800fc3b0(Ptr32<const char> const &, int);
extern "C" void w3d_string_assign(Ptr32<String>, Ptr32<const char>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" Ptr32<Obj> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern "C" void w3d_k5b_iface_array_field_801ef174(Ptr32<Obj>, int, int, Ptr32<Obj>);
extern "C" void w3d_export_scheme_8028fb10(Ptr32<void>);
extern "C" void w3d_empty_8029301c(Ptr32<void>);
inline Ptr32<Obj> Create(Ptr32<void> type) { return w3d_s10_service_forward_8020b680(type); }
inline Ptr32<Obj> Clone(const Handle &s, const Handle &from) {
    ((Ptr32<void (Ptr32<Obj>, int)>)s.p->table[14])(s.p, 2);
    ((Ptr32<void (Ptr32<Obj>, Ptr32<Obj>)>)s.p->table[6])(s.p, from.p);
    return ((Ptr32<Ptr32<Obj> (Ptr32<Obj>)>)s.p->table[16])(s.p);
}
extern "C" void w3d_d41f_scheme_new_80291b90(Ptr32<void> self) {
    Handle data;
    Handle store;
    Descriptor_80178474 first;
    Descriptor_80178474 second;
    Handle copy;
    String name;
    Ptr32<const char> text;
    w3d_auto_800fc2b0(lbl_803d02ac, &text);
    w3d_string_assign(&name, text);
    if (w3d_constructor_lookup_name(lbl_803d0164, data) < 0)
        return;
    do { int r = w3d_constructor_lookup_name(lbl_803d0174, store); if (r >= 0) break; return; } while (0);
    Handle schemes;
    schemes = Handle(w3d_auto_80179598(w3d_empty_80341584(data.p), &first));
    Handle current;
    current = Handle(w3d_auto_80179598(w3d_empty_80341584(store.p), &second));
    Ptr32<List> list = ((Ptr32<Data>)schemes.p)->list;
    unsigned count = list->count;
    Ptr32<Ptr32<Named>> items = list->items;
    unsigned i = 0;
    Ptr32<Ptr32<Named>> p;
    do { if (i >= count) goto done; p = items; } while (0);
next:
        if (strcmp((*p++)->name, name.text) == 0) {
            DebugNote(((Ptr32<Scheme>)current.p)->name);
            return;
        }
        do {
            i++;
            if (i < count) goto next;
        } while (0);
done:
    { Ptr32<Scheme> t = (Ptr32<Scheme>)current.p; t->name = name; }
    int zero = 0;
    ((Ptr32<Scheme>)current.p)->locked = zero;
    { Ptr32<Scheme> t = (Ptr32<Scheme>)current.p; t->title = String(lbl_803d0588); }
    ((Ptr32<Scheme>)current.p)->slot60->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot60->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot60->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot292->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot292->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot292->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot44->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot44->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot44->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot40->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot40->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot40->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot36->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot36->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot36->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot32->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot32->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot32->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot28->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot28->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot28->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot24->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot24->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot24->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot164->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot164->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot164->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot216->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot216->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot216->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot124->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot124->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot124->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot120->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot120->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot120->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot112->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot112->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot112->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot108->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot108->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot108->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot232->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot232->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot232->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot184->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot184->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot184->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot228->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot228->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot228->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot128->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot128->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot128->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot208->v32 = -1;
    ((Ptr32<Scheme>)current.p)->slot208->v28 = zero;
    ((Ptr32<Scheme>)current.p)->slot208->v20 = zero;
    ((Ptr32<Scheme>)current.p)->slot204->v32 = zero;
    ((Ptr32<Scheme>)current.p)->slot204->v28 = 1;
    ((Ptr32<Scheme>)current.p)->slot204->v20 = zero;
    {
        Descriptor_80178474 tag;
        copy = Clone(Handle(Create(lbl_80413b28)), current);
    }
    ((Ptr32<Scheme>)copy.p)->locked = zero;
    { Ptr32<Scheme> t = (Ptr32<Scheme>)copy.p; t->title = String(lbl_803d0588); }
    { Ptr32<Scheme> t = (Ptr32<Scheme>)copy.p; t->name = name; }
    s8_property_write_800fc3b0(lbl_803d02b4, 0);
    w3d_k5b_iface_array_field_801ef174(schemes.p, 20, 0, copy.p);
    w3d_export_scheme_8028fb10(self);
    w3d_empty_8029301c(self);
}


