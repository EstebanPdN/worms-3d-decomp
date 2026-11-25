#include "w3d_ptr.h"
#line 1 "d29i_team_flags_list_fill_8011711c.cpp"
// d29i: 0x8011711c. Team flag list fill: resolves the list from +116, builds a
// label table titled Flags sized 30.0 by 36.0, reads User.Skill and picks flag
// range 115..119 when the skill is set, or 0..109 otherwise, keeping User.Flag
// valid, then adds FE.TeamFlags:%d rows with %d values.
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
extern "C" void string_assign_8020bd38(Ptr32<Ptr32<char>>, Ptr32<const char>);
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
struct Owner { unsigned char unknown00[116]; Ptr32<Object> source; };
extern const char class_80419e88[], n_8039a188[], n_8039a958[], n_8039a964[], n_8039a970[], f_8039a974[], f_8039a4c8[];
extern "C" int read_int_800fc230(Ptr32<Key>, Ptr32<int>);
extern "C" int write_800fc550(Ptr32<Key>, Ptr32<const char>);
extern "C" int read_key2_800fc2b0(Ptr32<Key>, Ptr32<Key>);
extern "C" int atoi_802ed89c(Ptr32<const char>);
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
extern "C" void d29i_team_flags_list_fill_8011711c(Ptr32<Owner> self) {
    Descriptor_80178474 descriptor;
    Handle list;
    {
        Handle value(table_get_80179598(as_table_80341584(self->source), &descriptor));
        list.assign(value.value);
    }
    Ptr32<List> l = (Ptr32<List>)list.value;
    list_begin_801ef380(list.value, 32, 0, 0, l->field->count);
    clear(&((Ptr32<List>)list.value)->values);
    String text;
    Handle a;
    set(a, create_8020b680(class_80419e88));
    {
        Ptr32<Labels> t = (Ptr32<Labels>)a.value;
        String name(n_8039a188);
        Ptr32<char> text = name.text;
        ++*(Ptr32<unsigned short>)(text - 6);
        Ptr32<char> old = t->title;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    unsigned last = 110, first = 0;
    ((Ptr32<Labels>)a.value)->width = 30.0f;
    *(Ptr32<float>)((Ptr32<char>)a.value + 32) = 36.0f;
    Key skill_key;
    skill_key.name = n_8039a958;
    int skill;
    read_int_800fc230(&skill_key, &skill);
    if (skill) {
        String t;
        last = 120;
        first = 115;
        string_format_8020c510(&t, f_8039a4c8, skill + 114);
        Key flag_key;
        flag_key.name = n_8039a964;
        write_800fc550(&flag_key, t.text);
    } else {
        Ptr32<const char> flag = n_8039a964;
        Key flag_key;
        flag_key.name = flag;
        Key out;
        read_key2_800fc2b0(&flag_key, &out);
        if (atoi_802ed89c(out.name) > 114) {
            Key flag_key2;
            flag_key2.name = flag;
            write_800fc550(&flag_key2, n_8039a970);
        }
    }
    Ptr32<ArrayRef> names = &((Ptr32<Labels>)a.value)->names;
    Ptr32<Ptr32<char>> s1 = grow(names, names->header->count + (last - first));
    Ptr32<ArrayRef> values = &((Ptr32<List>)list.value)->values;
    Ptr32<Ptr32<char>> s2 = grow(values, values->header->count + (last - first));
    for (unsigned i = first; i < last; i++) {
        string_format_8020c510(&text, f_8039a974, i);
        int k = (i - first) * 4;
        store(k, s1, text);
        String t;
        string_format_8020c510(&t, f_8039a4c8, i);
        store(k, s2, t);
    }
    list_append_801ef174(list.value, 32, 0, a.value);
}


