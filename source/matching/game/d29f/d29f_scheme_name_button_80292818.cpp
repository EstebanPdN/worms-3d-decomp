// GWMP8P rev0 0x80292818. Handles the scheme name buttons. 'Find New' builds
// the first unused numbered scheme name from Lang.Scheme and stores it in
// Q.Name. Any other name validates the current Q.Name text (rejects empty,
// leading space, a duplicate in DATA.LockedSchemes or DATA.Schemes including
// translated locked names, the user-defined tip text or a leading asterisk)
// and writes the result to the named property as int or native value. Field
// names are inferred; the unit owns no data.
// Observed handle, descriptor, string and team record views; roles inferred.
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
extern "C" void w3d_string_base_finish(void *), w3d_string_release(void *), w3d_string_release_header(void *);
struct String_803426b8 {
    char *text;
    String_803426b8();
    String_803426b8(const char *);
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
struct Key { const char *text; Key(const char *p) : text(p) {} Key(const String_803426b8 &s) : text(s.text) {} };
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" int w3d_auto_800fc2b0(const Key &, const char **);
extern "C" int s8_property_read_800fc550(const Key &, const char *);
extern "C" void w3d_string_format(String *, const char *, ...);
extern "C" void w3d_string_assign(String *, const char *);
extern "C" int strcmp(const char *, const char *);
inline int Same(const char *a, const char *b) { return strcmp(a, b) == 0; }
extern char lbl_803d05ac[], lbl_803d0164[], lbl_803d05b8[], lbl_803d05c4[], lbl_803d02ac[], lbl_803d0150[], lbl_803d04a4[];
struct Entry { char pad[20]; const char *name; };
struct List { char pad[24]; unsigned count; char pad2[4]; Entry *items[1]; };
struct Data { char pad[20]; List *list; };
extern "C" Data *w3d_auto_801797b4(Obj *);
extern "C" void *w3d_empty_803426b4(Obj *);
extern "C" void *w3d_constructor_native_cast(Obj *);
extern "C" int s9_update_value_80178c54(void *, const int *);
extern "C" int s9_update_value_80178d28(void *, const int *);
extern "C" void d29f_scheme_name_button_80292818(void *self, String name) {
    if (name.Length() == 0)
        return;
    if (Same(name.text, lbl_803d05ac)) {
        Handle data;
        if (w3d_constructor_lookup_name(lbl_803d0164, data) < 0)
            return;
        List *list = w3d_auto_801797b4(w3d_empty_80341584(data.p))->list;
        unsigned count = list->count;
        Entry **items = list->items;
        int number = 0;
        String tip;
        const char *text;
        w3d_auto_800fc2b0(lbl_803d05b8, &text);
        int unique;
        do {
            number++;
            unsigned i = 0;
            w3d_string_format(&tip, lbl_803d05c4, text, number);
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
        s8_property_read_800fc550(lbl_803d02ac, tip.text);
        return;
    }
    const char *text;
    w3d_auto_800fc2b0(lbl_803d02ac, &text);
    String current(text);
    Handle store;
    String names[2];
    w3d_string_assign(&names[0], lbl_803d0150);
    int invalid = 0;
    w3d_string_assign(&names[1], lbl_803d0164);
    if (current.Length() == 0 || text[0] == ' ')
        invalid = 1;
    else {
        unsigned i;
        for (i = 0; i <= 1; i++) {
            if (w3d_constructor_lookup_name(names[i], store) < 0) {
                DebugNote(names[i]);
                continue;
            }
            List *list = w3d_auto_801797b4(w3d_empty_80341584(store.p))->list;
            unsigned count = list->count;
            Entry **items = list->items;
            if (count == 0)
                continue;
            unsigned j = 0;
            if (j < count)
                do {
                    if (i == 0) {
                        const char *display;
                        w3d_auto_800fc2b0(items[j]->name, &display);
                        if (strcmp(display, current.text) == 0) {
                            invalid = 1;
                            break;
                        }
                    }
                    if (strcmp(items[j]->name, current.text) == 0) {
                        invalid = 1;
                        break;
                    }
                    j++;
                } while (j < count);
            if (invalid == 1)
                break;
        }
        if (invalid == 0) {
            const char *s;
            w3d_auto_800fc2b0(lbl_803d04a4, &s);
            if (strcmp(s, current.text) == 0)
                invalid = 1;
            s = current.text;
            if (*s == '*')
                invalid = 1;
        }
    }
    {
        Handle target;
        if (w3d_constructor_lookup_name(name.text, target) < 0) {
            DebugNote(name);
            return;
        }
        int value = 1;
        if (invalid == 0)
            value = 0;
        switch (((int (*)(Obj *))target.p->table[6])(target.p)) {
        case 0:
            s9_update_value_80178c54(w3d_empty_803426b4(target.p), &value);
            break;
        case 1:
            s9_update_value_80178d28(w3d_constructor_native_cast(target.p), &value);
            break;
        }
    }
}
