#include "w3d_ptr.h"
#line 1 "d30i_scheme_two_pass_list_fill_8011307c.cpp"
// d30i: 0x8011307c. Fills the scheme list from DATA.Schemes and DATA.LockedSchemes, translating names on the second pass and adding the current GM.SchemeData scheme when no entry matched it.
struct Type { unsigned char unknown00[20]; Ptr32<const Type> parent; };
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;       // +12
    Ptr32<void (Ptr32<Object>)> release;      // +16
    Ptr32<Ptr32<const Type> (Ptr32<Object>)> type;  // +20
    Ptr32<int (Ptr32<Object>)> kind;          // +24
    Ptr32<void> unknown1c;
    Ptr32<Ptr32<const char> (Ptr32<Object>)> name;  // +32
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Key { Ptr32<const char> name; };
// Owned type descriptor released through 0x80178474 (two written words).
struct Descriptor_80178474 {
    Ptr32<void> value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Handle {
    Ptr32<Object> value;
    Handle() : value(0) {}
    template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((Object *)w3d_p.get()) {}
 Handle(Object *next) : value(next) { if (value) value->vtable->retain(value); }
    Handle(const Handle &);
    ~Handle() { if (value) value->vtable->release(value); }
    void assign(Ptr32<Object> next) {
        if (next) {
            next->vtable->retain(next);
            if (value) value->vtable->release(value);
            value = next;
        }
    }
};
struct ArrayHeader {
    unsigned char unknown00[4];
    unsigned short kind;   // +4
    unsigned char unknown06[18];
    int count;             // +24
    unsigned short locks;  // +28
    unsigned char unknown1e[2];
    Ptr32<char> data[1];         // +32
};
struct ArrayRef { Ptr32<ArrayHeader> header; };
struct Field { unsigned char unknown00[24]; int count; };
struct List {
    unsigned char unknown00[28];
    ArrayRef values;    // +28
    Ptr32<Field> field;       // +32
};
struct Labels {
    unsigned char unknown00[24];
    ArrayRef names;     // +24
    unsigned char unknown1c[8];
    float width;        // +36
    Ptr32<char> title;        // +40
    unsigned char unknown2c[4];
    ArrayRef ids;       // +48
};
struct String {
    Ptr32<char> text;
    String();
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
extern "C" Ptr32<void> as_table_80341584(Ptr32<Object>);
extern "C" Ptr32<Object> table_get_80179598(Ptr32<void>, Ptr32<Descriptor_80178474>);
extern "C" void list_begin_801ef380(Ptr32<Object>, int, int, int, int);
extern "C" Ptr32<Ptr32<char>> array_lock_801ef048(Ptr32<ArrayRef>, int, int, int);
extern "C" Ptr32<Object> create_8020b680(Ptr32<const void>);
extern "C" void string_release_8020bb2c(Ptr32<void>);
extern "C" Ptr32<Ptr32<char>> string_assign_8020bd38(Ptr32<Ptr32<char>>, Ptr32<const char>);
extern "C" void string_format_8020c510(Ptr32<String>, Ptr32<const char>, ...);
extern "C" void list_append_801ef174(Ptr32<Object>, int, int, Ptr32<Object>);
static inline Ptr32<Ptr32<char>> grow(Ptr32<ArrayRef> array, int count) {
    Ptr32<ArrayHeader> header = array->header;
    if (header->kind == 1 && count == header->count) {
        ++header->locks;
        return header->data;
    }
    return array_lock_801ef048(array, count, 4, 2);
}
static inline void clear(Ptr32<ArrayRef> array) {
    Ptr32<ArrayHeader> header = array->header;
    if (header->kind == 1 && header->count == 0)
        ++header->locks;
    else
        array_lock_801ef048(array, 0, 4, 0);
}
struct Pair { Ptr32<const char> key; Ptr32<const char> value; };
struct PairTable { Pair pairs[7]; };
extern "C" int read_key_800fc2b0(Ptr32<Pair>, Ptr32<Key>);
static inline Ptr32<Ptr32<char>> size_to(Ptr32<ArrayRef> array, int count) {
    Ptr32<ArrayHeader> header = array->header;
    if (header->kind == 1 && count == header->count) {
        ++header->locks;
        return header->data;
    }
    return array_lock_801ef048(array, count, 4, 0);
}
static inline void set(Handle &h, Ptr32<Object> next) {
    if (next) next->vtable->retain(next);
    if (h.value) h.value->vtable->release(h.value);
    h.value = next;
}
static inline void store(int index, Ptr32<Ptr32<char>> slot, const String &s) {
    Ptr32<char> text = s.text;
    ++*(Ptr32<unsigned short>)(text - 6);
    Ptr32<char> old = *(Ptr32<Ptr32<char>>)w3d::G((index + (int)w3d::H(slot)));
    Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
    unsigned short n = --*header;
    if (n == 0) string_release_8020bb2c(header);
    *(Ptr32<Ptr32<char>>)w3d::G((index + (int)w3d::H(slot))) = s.text;
}
struct Owner { unsigned char unknown00[28]; int id_a; int id_b; unsigned char unknown20[8]; int id_new; unsigned char unknown30[24]; Ptr32<Object> source; };
struct Scheme {
    unsigned char unknown00[20];
    String name;     // +20
    unsigned char unknown18[60];
    String title;    // +84
    unsigned char unknown58[244];
    int kind;        // +332
};
struct SchemeList { unsigned char unknown00[24]; unsigned count; unsigned char unknown1c[4]; Ptr32<Scheme> items[1]; };
struct Definition { unsigned char unknown00[20]; Ptr32<SchemeList> list; String name() ; };
extern const char class_80419e68[], n_8039a5f0[], n_8039a604[], n_8039a614[], n_8039a620[];
extern "C" int read_setting_800fc1b0(Ptr32<Key>, Ptr32<Handle>);
extern "C" int read_setting2_800fc1b0(Ptr32<String>, Ptr32<Handle>);
extern "C" Ptr32<Definition> definition_801797b4(Ptr32<void>);
extern "C" int read_key2_800fc2b0(Ptr32<Key>, Ptr32<Key>);
extern "C" void string_init_8020c5c0(Ptr32<String>);
extern "C" Ptr32<unsigned short> string_header_80341884(Ptr32<String>);
extern "C" int locked_8028496c(Ptr32<void>, String);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern Ptr32<void> lbl_804abbac;
inline String::String(const String &o) {
    string_init_8020c5c0(this);
    text = o.text;
    struct H { unsigned short refs, length, capacity; }; Ptr32<struct H> h = (Ptr32<H>)string_header_80341884(this);
    ++h->refs;
}
static inline void clear0(Ptr32<ArrayRef> array, int n) {
    Ptr32<ArrayHeader> header = array->header;
    if (header->kind == 1 && n == header->count)
        ++header->locks;
    else
        array_lock_801ef048(array, n, 4, 0);
}
static inline void copy(String &to, const String &from) {
    Ptr32<char> text = from.text;
    ++*(Ptr32<unsigned short>)(text - 6);
    Ptr32<char> old = to.text;
    Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
    unsigned short n = --*header;
    if (n == 0) string_release_8020bb2c(header);
    to.text = from.text;
}
static inline Ptr32<char> name_of(const String &p) { return p.text; }
extern "C" void d30i_scheme_two_pass_list_fill_8011307c(Ptr32<Owner> self) {
    Descriptor_80178474 descriptor;
    Handle list;
    {
        Handle value(table_get_80179598(as_table_80341584(self->source), &descriptor));
        list.assign(value.value);
    }
    Descriptor_80178474 descriptor2;
    Ptr32<List> l = (Ptr32<List>)list.value;
    list_begin_801ef380(list.value, 32, 0, 0, l->field->count);
    clear0(&((Ptr32<List>)list.value)->values, 0);
    Handle lookup;
    String paths[2];
    string_assign_8020bd38(&paths[1].text, n_8039a5f0);
    string_assign_8020bd38(&paths[0].text, n_8039a604);
    Handle table(create_8020b680(class_80419e68));
    {
        Ptr32<Labels> t = (Ptr32<Labels>)table.value;
        String name(n_8039a614);
        Ptr32<char> text = name.text;
        ++*(Ptr32<unsigned short>)(text - 6);
        Ptr32<char> old = t->title;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    bool found = false;
    String current;
    Handle data;
    {
        Key key;
        key.name = n_8039a620;
        if (read_setting_800fc1b0(&key, &data) >= 0) {
            Ptr32<Scheme> s = (Ptr32<Scheme>)definition_801797b4(as_table_80341584(data.value));
            copy(current, s->name);
        }
    }
    String display;
    for (unsigned pass = 0; pass <= 1; pass++) {
        Key key;
        key.name = name_of(paths[pass]);
        if (read_setting_800fc1b0(&key, &lookup) < 0) continue;
        Ptr32<Definition> def = definition_801797b4(as_table_80341584(lookup.value));
        Ptr32<SchemeList> h = def->list;
        unsigned count = h->count;
        Ptr32<Ptr32<Scheme>> items = h->items;
        if (count == 0) continue;
        for (unsigned i = 0; i < count; i++) {
            if (locked_8028496c(lbl_804abbac, String(items[i]->title)) == 1) continue;
            Ptr32<ArrayRef> names = &((Ptr32<Labels>)table.value)->names;
            int c1 = names->header->count;
            Ptr32<Ptr32<char>> s0 = grow(names, c1 + 1);
            Ptr32<Ptr32<char>> sa = s0;
            s0 = 0;
            copy(display, items[i]->name);
            if (strcmp(current.text, display.text) == 0) found = true;
            if (pass == 1) {
                Key k;
                k.name = items[i]->name.text;
                Key out;
                read_key2_800fc2b0(&k, &out);
                string_assign_8020bd38(&display.text, out.name);
            }
            int k1 = c1 << 2;
            store(k1, sa, display);
            Ptr32<ArrayRef> values = &((Ptr32<List>)list.value)->values;
            int c2 = values->header->count;
            Ptr32<Ptr32<char>> sv = grow(values, c2 + 1);
            c2 <<= 2;
            store(c2, sv, items[i]->name);
            Ptr32<ArrayRef> idr = &((Ptr32<Labels>)table.value)->ids;
            int c3 = idr->header->count;
            Ptr32<int> ids = (Ptr32<int>)grow(idr, c3 + 1);
            int value;
            if (items[i]->kind == 0) value = self->id_a; else value = self->id_b;
            ids[c3] = value;
        }
    }
    if (!found) {
        Ptr32<ArrayRef> names = &((Ptr32<Labels>)table.value)->names;
        int c1 = names->header->count;
        Ptr32<Ptr32<char>> s0 = grow(names, c1 + 1);
        Ptr32<Ptr32<char>> sa = s0;
        s0 = 0;
        c1 <<= 2;
        store(c1, sa, current);
        Ptr32<ArrayRef> values = &((Ptr32<List>)list.value)->values;
        int c2 = values->header->count;
        Ptr32<Ptr32<char>> sv = grow(values, c2 + 1);
        c2 <<= 2;
        store(c2, sv, current);
        Ptr32<ArrayRef> idr = &((Ptr32<Labels>)table.value)->ids;
        int c3 = idr->header->count;
        Ptr32<int> ids = (Ptr32<int>)grow(idr, c3 + 1);
        ids[c3] = self->id_new;
    }
    list_append_801ef174(list.value, 32, 0, table.value);
}


