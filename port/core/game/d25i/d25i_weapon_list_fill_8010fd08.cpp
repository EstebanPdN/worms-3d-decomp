#include "w3d_ptr.h"
#line 1 "d25i_weapon_list_fill_8010fd08.cpp"
// d25i: 0x8010fd08. Fill a settings list: resolves the list object from the
// table at +60 through a descriptor, clears its value array, creates the label
// table, then walks all settings; for each object setting whose definition has
// type 0x803667a8 and group 2, it appends the setting's name and the
// definition's text (or the key it names). Finally attaches the table to the
// list. Descriptor_80178474 has two written words.
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
    unsigned char unknown00[24];
    ArrayRef labels;    // +24
    ArrayRef values;    // +28
    Ptr32<Field> field;       // +32
};
struct Definition { unsigned char unknown00[44]; int group; unsigned char unknown30[24]; Ptr32<char> text; };
struct Owner { unsigned char unknown00[60]; Ptr32<Object> source; };
extern "C" Ptr32<void> as_table_80341584(Ptr32<Object>);
extern "C" Ptr32<Object> table_get_80179598(Ptr32<void>, Ptr32<Descriptor_80178474>);
extern "C" void list_begin_801ef380(Ptr32<Object>, int, int, int, int);
extern "C" Ptr32<Ptr32<char>> array_lock_801ef048(Ptr32<ArrayRef>, int, int, int);
extern "C" Ptr32<Object> create_8020b680(Ptr32<const void>);
extern "C" Ptr32<Definition> definition_801797b4(Ptr32<void>);
extern "C" int next_setting_800fc69c(Ptr32<int>, Ptr32<Handle>);
extern "C" void string_release_8020bb2c(Ptr32<void>);
extern "C" void string_assign_8020bd38(Ptr32<Ptr32<char>>, Ptr32<const char>);
extern "C" int read_key_800fc2b0(Ptr32<Key>, Ptr32<Key>);
extern "C" void list_append_801ef174(Ptr32<Object>, int, int, Ptr32<Object>);
extern const char class_80419e68[];
extern const Type type_803667a8[];

inline bool is_a(Ptr32<const Type> t, Ptr32<const Type> target) {
    while (t != target) {
        if (t == t->parent) return false;
        t = t->parent;
    }
    return true;
}
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
extern "C" void d25i_weapon_list_fill_8010fd08(Ptr32<Owner> self) {
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
    int cursor = 0;
    Handle entry;
    while (next_setting_800fc69c(&cursor, &entry)) {
        if (entry.value->vtable->kind(entry.value) != 5) continue;
        {
            Ptr32<Object> o = (Ptr32<Object>)definition_801797b4(as_table_80341584(entry.value));
            if (!is_a(o->vtable->type(o), type_803667a8)) continue;
        }
        Ptr32<Definition> def = definition_801797b4(as_table_80341584(entry.value));
        if (def->group != 2) continue;
        Ptr32<ArrayRef> labels = &((Ptr32<List>)table.value)->labels;
        int index = labels->header->count;
        Ptr32<Ptr32<char>> label = grow(labels, index + 1);
        Ptr32<ArrayRef> values = &((Ptr32<List>)list.value)->values;
        int count = values->header->count;
        Ptr32<Ptr32<char>> value = grow(values, count + 1);
        {
            Ptr32<char> text = def->text;
            ++*(Ptr32<unsigned short>)(text - 6);
            index <<= 2;
            Ptr32<char> old = *(Ptr32<Ptr32<char>>)w3d::G((index + (int)w3d::H(label)));
            Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
            unsigned short n = --*header;
            if (n == 0) string_release_8020bb2c(header);
            *(Ptr32<Ptr32<char>>)w3d::G((index + (int)w3d::H(label))) = def->text;
        }
        string_assign_8020bd38((Ptr32<Ptr32<char>>)w3d::G(((int)w3d::H(value) + index)), entry.value->vtable->name(entry.value));
        Key key;
        key.name = def->text;
        Key out;
        if (read_key_800fc2b0(&key, &out) >= 0)
            string_assign_8020bd38((Ptr32<Ptr32<char>>)w3d::G(((int)w3d::H(label) + index)), out.name);
    }
    list_append_801ef174(list.value, 32, 0, table.value);
}


