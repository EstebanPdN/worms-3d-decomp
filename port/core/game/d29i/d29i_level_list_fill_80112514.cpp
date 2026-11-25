#include "w3d_ptr.h"
#line 1 "d29i_level_list_fill_80112514.cpp"
// d29i: 0x80112514. Sorted level list fill for one group: walks settings of
// kind 5 deriving from type 0x803667a8, keeps those whose group matches, skips
// names 0x8028496c rejects, inserts the translated name, setting name and id
// in sorted order. Group 5 also gets a first row FE.Tip.UserDefined /
// FE.Level.RandomLand with id +44.
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
struct Owner { unsigned char unknown00[32]; int id; unsigned char unknown24[8]; int random_id; };
struct Definition {
    unsigned char unknown00[28];
    String title;   // +28
    unsigned char unknown20[12];
    int group;      // +44
    unsigned char unknown30[24];
    String name;    // +72
};
extern "C" Ptr32<Definition> definition_801797b4(Ptr32<void>);
extern "C" int next_setting_800fc69c(Ptr32<int>, Ptr32<Handle>);
extern "C" int read_key2_800fc2b0(Ptr32<Key>, Ptr32<Key>);
extern "C" void string_init_8020c5c0(Ptr32<String>);
extern "C" Ptr32<unsigned short> string_header_80341884(Ptr32<String>);
extern "C" Ptr32<Ptr32<char>> name_find_80347194(Ptr32<Ptr32<char>>, int, Ptr32<String>);
extern "C" int locked_8028496c(Ptr32<void>, String);
extern Ptr32<void> lbl_804abbac;
extern const char class_80419e68[], n_8039a4d8[], f_8039a4ec[], n_8039a4f0[];
extern const Type type_803667a8[];
inline String::String(const String &o) {
    string_init_8020c5c0(this);
    text = o.text;
    struct H { unsigned short refs, length, capacity; }; Ptr32<struct H> h = (Ptr32<H>)string_header_80341884(this);
    ++h->refs;
}
inline bool is_a(Ptr32<const Type> t, Ptr32<const Type> target) {
    while (t != target) {
        if (t == t->parent) return false;
        t = t->parent;
    }
    return true;
}
static inline void move_up(Ptr32<Ptr32<char>> p) {
    Ptr32<char> text = p[-1];
    ++*(Ptr32<unsigned short>)(text - 6);
    Ptr32<char> old = p[0];
    Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
    unsigned short n = --*header;
    if (n == 0) string_release_8020bb2c(header);
    p[0] = p[-1];
}
extern "C" void d29i_level_list_fill_80112514(Ptr32<Owner> self, Ptr32<Object> source, int group) {
    Descriptor_80178474 descriptor;
    Handle list;
    {
        Handle value(table_get_80179598(as_table_80341584(source), &descriptor));
        list.assign(value.value);
    }
    Ptr32<List> l = (Ptr32<List>)list.value;
    list_begin_801ef380(list.value, 32, 0, 0, l->field->count);
    clear(&((Ptr32<List>)list.value)->values);
    Handle table(create_8020b680(class_80419e68));
    int cursor = 0;
    Handle entry;
    while (next_setting_800fc69c(&cursor, &entry)) {
        if (entry.value->vtable->kind(entry.value) != 5) continue;
        {
            Ptr32<Object> o = (Ptr32<Object>)definition_801797b4(as_table_80341584(entry.value));
            if (!is_a(o->vtable->type(o), type_803667a8)) continue;
        }
        Ptr32<Definition> def = definition_801797b4(as_table_80341584(entry.value));
        if (def->group != group) continue;
        if (locked_8028496c(lbl_804abbac, String(def->title))) continue;
        Ptr32<ArrayRef> labels = &((Ptr32<Labels>)table.value)->names;
        int count = labels->header->count;
        Ptr32<Ptr32<char>> sa = grow(labels, count + 1);
        Ptr32<ArrayRef> values = &((Ptr32<List>)list.value)->values;
        Ptr32<Ptr32<char>> sv = grow(values, values->header->count + 1);
        Ptr32<ArrayRef> idr = &((Ptr32<Labels>)table.value)->ids;
        Ptr32<int> ids = (Ptr32<int>)grow(idr, idr->header->count + 1);
        String name(def->name);
        Key key;
        key.name = name.text;
        Key out;
        if (read_key2_800fc2b0(&key, &out) >= 0)
            string_assign_8020bd38(&name.text, out.name);
        int pos = name_find_80347194(sa, count, &name) - sa;
        for (int j = count; j > pos; j--) {
            move_up(&sa[j]);
            move_up(&sv[j]);
            ids[j] = ids[j - 1];
        }
        int k = pos << 2;
        store(k, sa, name);
        string_assign_8020bd38((Ptr32<Ptr32<char>>)w3d::G(((int)w3d::H(sv) + k)), entry.value->vtable->name(entry.value));
        *(Ptr32<int>)w3d::G((k + (int)w3d::H(ids))) = self->id;
    }
    if (group == 5) {
        Ptr32<ArrayRef> labels = &((Ptr32<Labels>)table.value)->names;
        int count = labels->header->count;
        Ptr32<Ptr32<char>> sa = grow(labels, count + 1);
        Ptr32<ArrayRef> values = &((Ptr32<List>)list.value)->values;
        Ptr32<Ptr32<char>> sv = grow(values, values->header->count + 1);
        Ptr32<ArrayRef> idr = &((Ptr32<Labels>)table.value)->ids;
        Ptr32<int> ids = (Ptr32<int>)grow(idr, idr->header->count + 1);
        for (int j = count; j > 0; j--) {
            move_up(&sa[j]);
            move_up(&sv[j]);
            ids[j] = ids[j - 1];
        }
        Key key;
        key.name = n_8039a4d8;
        Key out;
        read_key2_800fc2b0(&key, &out);
        String t;
        string_format_8020c510(&t, f_8039a4ec, w3d::VA(out.name));
        store(0, sa, t);
        string_assign_8020bd38(sv, n_8039a4f0);
        ids[0] = self->random_id;
    }
    list_append_801ef174(list.value, 32, 0, table.value);
}


