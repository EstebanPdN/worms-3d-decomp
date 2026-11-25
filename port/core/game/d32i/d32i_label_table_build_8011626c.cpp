#include "w3d_ptr.h"
#line 1 "d32i_label_table_build_8011626c.cpp"
// d32i: 0x8011626c. Fills a list panel's label columns from the settings
// pair table: one row per key, with the key's saved value, a numbered id
// text and the pair's default value.
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
struct Owner { unsigned char unknown00[32]; int id; unsigned char unknown24[52]; Ptr32<Object> source; };
extern const char class_80419e68[], class_80419e88[], n_8039a7a0[], n_8039a8f4[], f_8039a4c8[];
extern const PairTable table_8039a8bc;
inline void Assign(Ptr32<Ptr32<char>> d, Ptr32<const char> s) { string_assign_8020bd38(d, s); }
inline void Fmt(Ptr32<String> t, Ptr32<const char> f, unsigned i) { string_format_8020c510(t, f, i); }
extern "C" void d32i_label_table_build_8011626c(Ptr32<Owner> self) {
    PairTable table = table_8039a8bc;
    Ptr32<Pair> pp = table.pairs;
    Descriptor_80178474 descriptor;
    Handle list;
    {
        Handle value(table_get_80179598(as_table_80341584(self->source), &descriptor));
        list.assign(value.value);
    }
    Ptr32<List> l = (Ptr32<List>)list.value;
    list_begin_801ef380(list.value, 32, 0, 0, l->field->count);
    clear(&((Ptr32<List>)list.value)->values);
    Ptr32<const char> cls = class_80419e68;
    Handle a(create_8020b680(cls));
    Handle b(create_8020b680(class_80419e88));
    Handle c(create_8020b680(cls));
    unsigned n = 0;
    for (; table.pairs[n].key; n++) {}
    Ptr32<Ptr32<char>> sa = size_to(&((Ptr32<Labels>)a.value)->names, n);
    Ptr32<Ptr32<char>> sc = size_to(&((Ptr32<Labels>)c.value)->names, n);
    Ptr32<Ptr32<char>> sb = size_to(&((Ptr32<Labels>)b.value)->names, n);
    Ptr32<Ptr32<char>> sv = size_to(&((Ptr32<List>)list.value)->values, n);
    Ptr32<ArrayRef> idr = &((Ptr32<Labels>)a.value)->ids;
    Ptr32<int> ids = (Ptr32<int>)grow(idr, idr->header->count + n);
    ((Ptr32<Labels>)b.value)->width = 32.0f;
    ((Ptr32<Labels>)c.value)->width = 2.0f;
    unsigned i = 0;
    if (i < n) do {
        Key out;
        if (read_key_800fc2b0(&pp[i], &out) >= 0)
            Assign(&sa[i], out.name);
        else
            Assign(&sa[i], n_8039a7a0);
        Assign(&sc[i], n_8039a8f4);
        String t;
        Fmt(&t, f_8039a4c8, i);
        Assign(&sv[i], t.text);
        Assign(&sb[i], pp[i].value);
        ids[i] = self->id;
        i++;
    } while (i < n);
    list_append_801ef174(list.value, 32, 0, b.value);
    list_append_801ef174(list.value, 32, 0, c.value);
    list_append_801ef174(list.value, 32, 0, a.value);
}


