#include "w3d_ptr.h"
#line 1 "d41f_scheme_delete_80292d4c.cpp"
// GWMP8P rev0 0x80292d4c. Deletes the scheme named by the current property:
// looks up the scheme list, finds the entry with that name and erases it
// unless it is locked. Handle, string and list views are observed; roles are
// inferred. The search is a label loop. The do/while forms wrap real code;
// see the caveat in d41f.json.
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
extern "C" void w3d_string_base_finish(Ptr32<void>), w3d_string_release(Ptr32<void>);
struct String_803426b8 {
    Ptr32<char> text;
    String_803426b8();
    String_803426b8(const String_803426b8 &);
    unsigned Length() const { return ((Ptr32<unsigned short>)text)[-2]; }
    ~String_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
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
struct Entry { char pad[20]; Ptr32<const char> name; char pad2[308]; int locked; };
struct List { char pad[24]; unsigned count; char pad2[4]; Ptr32<Entry> items[1]; };
struct Holder { int a; Ptr32<List> list; Ptr32<Ptr32<Entry>> Items() { return list->items; } };
struct Data { char pad[16]; Holder sub; };
extern char lbl_803d0164[], lbl_803d02ac[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Ptr32<Obj> w3d_empty_80341584(Ptr32<Obj>);
extern "C" int w3d_auto_800fc2b0(const Key &, Ptr32<Ptr32<const char>>);
extern "C" void w3d_string_assign(Ptr32<String>, Ptr32<const char>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" Ptr32<Obj> w3d_auto_80179598(Ptr32<Obj>, Ptr32<Descriptor_80178474>);
extern "C" void d22b_array_erase_801ef380(Ptr32<Obj>, int, int, unsigned, int);
extern "C" void w3d_d41f_scheme_delete_80292d4c(Ptr32<void>) {
    String name;
    Ptr32<const char> text;
    w3d_auto_800fc2b0(lbl_803d02ac, &text);
    w3d_string_assign(&name, text);
    if (name.Length() == 0)
        return;
    Handle data;
    unsigned count = 0;
    if (w3d_constructor_lookup_name(lbl_803d0164, data) < 0)
        return;
    {
        Descriptor_80178474 tag;
        Handle list;
        list = Handle(w3d_auto_80179598(w3d_empty_80341584(data.p), &tag));
        count = ((Ptr32<Data>)list.p)->sub.list->count;
        Ptr32<Ptr32<Entry>> items = ((Ptr32<Data>)list.p)->sub.Items();
        if (count != 0) {
            unsigned i = 0;
            if (i < count) {
                int off = 0;
            next:
                if (strcmp((*(Ptr32<Ptr32<Entry>>)w3d::G((off + (int)w3d::H(items))))->name, name.text) == 0) {
                    Ptr32<Entry> e;
                    do { e = *(Ptr32<Ptr32<Entry>>)w3d::G((off + (int)w3d::H(items))); } while (0);
                    if (e->locked == 1)
                        DebugNote(name);
                    else
                        d22b_array_erase_801ef380(list.p, 20, 0, i, 1);
                    return;
                }
                do {
                    i++;
                    off += 4;
                    if (i < count) goto next;
                } while (0);
            }
        }
    }
    DebugNote(name);
}


