#include "w3d_ptr.h"
#line 1 "d30i_pair_table_list_fill_80112cb0.cpp"
// d30i: 0x80112cb0. Fills an option list from a seven-entry key and value table, translating each key for the label column.
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
struct Pair { Ptr32<const char> key; Ptr32<const char> value; };
struct PairTable { Pair pairs[7]; };
struct Field { unsigned char unknown00[24]; int count; };
struct List {
    unsigned char unknown00[28];
    ArrayRef values;    // +28
    Ptr32<Field> field;       // +32
};
struct Labels {
    unsigned char unknown00[24];
    ArrayRef names;     // +24
    unsigned char unknown1c[12];
    Ptr32<char> title;        // +40
    unsigned char unknown2c[4];
    ArrayRef ids;       // +48
};
struct String {
    Ptr32<char> text;
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
struct Owner {
    unsigned char unknown00[32];
    int id;             // +32
    unsigned char unknown24[48];
    Ptr32<Object> source;     // +84
};
extern "C" Ptr32<void> as_table_80341584(Ptr32<Object>);
extern "C" Ptr32<Object> table_get_80179598(Ptr32<void>, Ptr32<Descriptor_80178474>);
extern "C" void list_begin_801ef380(Ptr32<Object>, int, int, int, int);
extern "C" Ptr32<Ptr32<char>> array_lock_801ef048(Ptr32<ArrayRef>, int, int, int);
extern "C" Ptr32<Object> create_8020b680(Ptr32<const void>);
extern "C" void string_release_8020bb2c(Ptr32<void>);
extern "C" void string_assign_8020bd38(Ptr32<Ptr32<char>>, Ptr32<const char>);
extern "C" int read_key_800fc2b0(Ptr32<Pair>, Ptr32<Key>);
extern "C" void list_append_801ef174(Ptr32<Object>, int, int, Ptr32<Object>);
extern const char class_80419e68[], n_8039a448[];
extern const PairTable table_8039a5b8;
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
extern "C" void d30i_pair_table_list_fill_80112cb0(Ptr32<Owner> self) {
    Descriptor_80178474 descriptor;
    PairTable table = table_8039a5b8; Ptr32<Pair> pp = table.pairs;
    Handle list;
    {
        Handle value(table_get_80179598(as_table_80341584(self->source), &descriptor));
        list.assign(value.value);
    }
    Ptr32<List> l = (Ptr32<List>)list.value;
    list_begin_801ef380(list.value, 32, 0, 0, l->field->count);
    clear(&((Ptr32<List>)list.value)->values);
    Handle entry;
    Handle labels(create_8020b680(class_80419e68));
    {
        Ptr32<Labels> t = (Ptr32<Labels>)labels.value;
        String name(n_8039a448);
        Ptr32<char> text = name.text;
        ++*(Ptr32<unsigned short>)(text - 6);
        Ptr32<char> old = t->title;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    for (int i = 0; pp[i].key; i++) {
        Ptr32<ArrayRef> names = &((Ptr32<Labels>)labels.value)->names;
        int count = names->header->count;
        Ptr32<Ptr32<char>> s0 = grow(names, count + 1);
        Ptr32<Ptr32<char>> slot = s0;
        s0 = 0;
        Key out;
        read_key_800fc2b0(&pp[i], &out);
        string_assign_8020bd38(slot + count, out.name);
        Ptr32<ArrayRef> values = &((Ptr32<List>)list.value)->values;
        int count2 = values->header->count;
        Ptr32<Ptr32<char>> vslot = grow(values, count2 + 1);
        string_assign_8020bd38(vslot + count2, pp[i].value);
        Ptr32<ArrayRef> ids = &((Ptr32<Labels>)labels.value)->ids;
        int count3 = ids->header->count;
        Ptr32<int> idslot = (Ptr32<int>)grow(ids, count3 + 1);
        idslot[count3] = self->id;
    }
    list_append_801ef174(list.value, 32, 0, labels.value);
}


