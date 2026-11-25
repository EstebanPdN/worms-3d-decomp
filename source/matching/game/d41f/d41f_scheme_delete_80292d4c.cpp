// GWMP8P rev0 0x80292d4c. Deletes the scheme named by the current property:
// looks up the scheme list, finds the entry with that name and erases it
// unless it is locked. Handle, string and list views are observed; roles are
// inferred. The search is a label loop. The do/while forms wrap real code;
// see the caveat in d41f.json.
struct Obj { void **table; };
inline void retain(Obj *p) { if (p) ((void (*)(Obj *))p->table[3])(p); }
inline void release(Obj *p) { if (p) ((void (*)(Obj *))p->table[4])(p); }
struct Handle {
    Obj *p;
    Handle() : p(0) {}
    Handle(Obj *x) : p(x) { retain(p); }
    Handle(const Handle &o) : p(o.p) { retain(p); }
    ~Handle() { release(p); }
    Handle &operator=(const Handle &o) { Obj *next = o.p; if (next) { retain(next); release(p); p = next; } return *this; }
};
struct Descriptor_80178474 { int zero; unsigned type; Descriptor_80178474() : zero(0), type(58280) {} ~Descriptor_80178474(); };
extern "C" void w3d_string_base_finish(void *), w3d_string_release(void *);
struct String_803426b8 {
    char *text;
    String_803426b8();
    String_803426b8(const String_803426b8 &);
    unsigned Length() const { return ((unsigned short *)text)[-2]; }
    ~String_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
};
typedef String_803426b8 String;
extern "C" void w3d_string_base_init(String *);
extern "C" unsigned short *w3d_string_header(String *);
inline String_803426b8::String_803426b8(const String_803426b8 &other) {
    w3d_string_base_init(this);
    text = other.text;
    ++*w3d_string_header(this);
}
inline void DebugNote(String) {}
struct Key { const char *text; Key(const char *p) : text(p) {} };
struct Entry { char pad[20]; const char *name; char pad2[308]; int locked; };
struct List { char pad[24]; unsigned count; char pad2[4]; Entry *items[1]; };
struct Holder { int a; List *list; Entry **Items() { return list->items; } };
struct Data { char pad[16]; Holder sub; };
extern char lbl_803d0164[], lbl_803d02ac[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" int w3d_auto_800fc2b0(const Key &, const char **);
extern "C" void w3d_string_assign(String *, const char *);
extern "C" int strcmp(const char *, const char *);
extern "C" Obj *w3d_auto_80179598(Obj *, Descriptor_80178474 *);
extern "C" void d22b_array_erase_801ef380(Obj *, int, int, unsigned, int);
extern "C" void w3d_d41f_scheme_delete_80292d4c(void *) {
    String name;
    const char *text;
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
        count = ((Data *)list.p)->sub.list->count;
        Entry **items = ((Data *)list.p)->sub.Items();
        if (count != 0) {
            unsigned i = 0;
            if (i < count) {
                int off = 0;
            next:
                if (strcmp((*(Entry **)(off + (int)items))->name, name.text) == 0) {
                    Entry *e;
                    do { e = *(Entry **)(off + (int)items); } while (0);
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
