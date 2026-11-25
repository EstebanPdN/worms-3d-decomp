#include "w3d_ptr.h"
#line 1 "d41i_team_list_rebuild_sorted_80115cd0.cpp"
// d41i: 0x80115cd0. Rebuilds a sorted name list from a settings bank: skips
// locked entries, inserts each new entry by id then name, shifting the
// parallel name, value and id arrays.
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

struct Id { unsigned char b0, b1, b2, b3; };
struct Owner { unsigned char unknown00[32]; Id a; Id b; unsigned char unknown28[80]; Ptr32<Object> source; };
struct Item {
    unsigned char unknown00[20];
    String title;  // +20
    String name;   // +24
    String key;    // +28
    int flag;      // +32
};
struct ItemList { unsigned char unknown00[24]; unsigned count; unsigned char unknown1c[4]; Ptr32<Item> items[1]; };
struct Holder { int unknown00; Ptr32<ItemList> list; Ptr32<Ptr32<Item>> Items() { return list->items; } };
struct Definition { unsigned char unknown00[16]; Holder sub; };
extern const char class_80419e68[], n_8039a78c[], s_8039a7a0[];
extern "C" int read_setting_800fc1b0(Ptr32<Key>, Ptr32<Handle>);
extern "C" Ptr32<Definition> definition_801797b4(Ptr32<void>);
extern "C" int read_key_800fc2b0(Ptr32<Key>, Ptr32<Key>);
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
static inline void move_up(Ptr32<Ptr32<char>> p) {
    Ptr32<char> text = p[-1];
    ++*(Ptr32<unsigned short>)(text - 6);
    Ptr32<char> old = p[0];
    Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
    unsigned short n = --*header;
    if (n == 0) string_release_8020bb2c(header);
    p[0] = p[-1];
}
static inline bool greater(const Id &a, const Id &b) { return a.b2 > b.b2; }
static inline bool same(const Id &a, const Id &b) { return a.b2 == b.b2; }
extern "C" void d41i_team_list_rebuild_sorted_80115cd0(Ptr32<Owner> self) {
    Descriptor_80178474 descriptor;
    Handle list;
    {
        Handle value(table_get_80179598(as_table_80341584(self->source), &descriptor));
        list.assign(value.value);
    }
    Ptr32<List> l = (Ptr32<List>)list.value;
    list_begin_801ef380(list.value, 32, 0, 0, l->field->count);
    clear(&((Ptr32<List>)list.value)->values);
    Handle table(create_8020b680(class_80419e68));
    unsigned count = 0;
    Handle bank;
    Key bank_key;
    bank_key.name = n_8039a78c;
    if (read_setting_800fc1b0(&bank_key, &bank) < 0) return;
    Ptr32<Definition> def = definition_801797b4(as_table_80341584(bank.value));
    count = def->sub.list->count;
    Ptr32<Ptr32<Item>> items = def->sub.Items();
    if (count == 0) return;
    for (unsigned i = 0; i < count; i++) {
        if (locked_8028496c(lbl_804abbac, String(items[i]->title))) continue;
        Ptr32<ArrayRef> labels = &((Ptr32<Labels>)table.value)->names;
        Ptr32<Ptr32<char>> sa = grow(labels, labels->header->count + 1);
        Ptr32<ArrayRef> values = &((Ptr32<List>)list.value)->values;
        Ptr32<Ptr32<char>> sv = grow(values, values->header->count + 1);
        Ptr32<ArrayRef> idr = &((Ptr32<Labels>)table.value)->ids;
        int n = idr->header->count;
        Ptr32<Id> ids = (Ptr32<Id>)grow(idr, n + 1);
        Key key;
        key.name = items[i]->key.text;
        Key out;
        if (read_key_800fc2b0(&key, &out) >= 0)
            string_assign_8020bd38(&sa[n], out.name);
        else
            out.name = s_8039a7a0;
        Id v;
        if (items[i]->flag) v = self->b; else v = self->a;
        unsigned j;
        j = 0;
        if (j < (unsigned)n && !greater(v, ids[j])) {
            int off = 0;
            for (; ; ) {
                if (same(v, ids[j]) && strcmp(out.name, *(Ptr32<Ptr32<char>>)w3d::G((off + (int)w3d::H(sa)))) < 0) goto done;
                off += 4;
                j++;
                if (j >= (unsigned)n) goto done;
                if (greater(v, ids[j])) goto done;
            }
        }
        done:
        int k = j << 2;
        for (; n > (int)j; n--) {
            move_up(&sa[n]);
            move_up(&sv[n]);
            ids[n] = ids[n - 1];
        }
        string_assign_8020bd38((Ptr32<Ptr32<char>>)w3d::G(((int)w3d::H(sa) + k)), out.name);
        *(Ptr32<Id>)w3d::G((k + (int)w3d::H(ids))) = v;
        store(k, sv, items[i]->name);
    }
    list_append_801ef174(list.value, 32, 0, table.value);
}


