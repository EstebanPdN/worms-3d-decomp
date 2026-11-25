#include "w3d_ptr.h"
#line 1 "d30i_unlock_list_fill_801167d4.cpp"
// d30i: 0x801167d4. Fills the unlocks list with every entry of the expected type, sorted by lock state, skill text and name, then writes the unlocked percentage to Lock.Percent.
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
struct Id { unsigned char b0, b1, b2, b3; void set(unsigned char v, unsigned char a) { b0 = v; b1 = v; b2 = v; b3 = a; } };
struct Owner { unsigned char unknown00[32]; Id id; unsigned char unknown24[76]; Ptr32<Object> source; };
struct Definition {
    Object base;
    unsigned char unknown04[16];
    int skill;      // +20
    String name;    // +24
    int state;      // +28
};
extern const char class_80419e68[], class_80419e88[], n_8039a448[], n_8039a454[], f_8039a900[], f_8039a460[], f_8039a914[], f_8039a924[], n_8039a92c[];
extern const Type type_80366208[];
extern float width_8039a93c[];
extern "C" Ptr32<Definition> definition_801797b4(Ptr32<void>);
extern "C" int next_setting_800fc69c(Ptr32<int>, Ptr32<Handle>);
extern "C" int read_key2_800fc2b0(Ptr32<Key>, Ptr32<Key>);
extern "C" int write_value_800fc550(Ptr32<Key>, Ptr32<const char>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
inline bool is_a(Ptr32<const Type> t, Ptr32<const Type> target) {
    while (t != target) {
        if (t == t->parent) return false;
        t = t->parent;
    }
    return true;
}
static inline void move_up(Ptr32<Ptr32<char>> a, int m) {
    Ptr32<char> text = a[m - 1];
    ++*(Ptr32<unsigned short>)(text - 6);
    Ptr32<char> old = a[m];
    Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
    unsigned short n = --*header;
    if (n == 0) string_release_8020bb2c(header);
    a[m] = a[m - 1];
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
static inline float ratio(const unsigned &a) { return (float)a; }
extern "C" void d30i_unlock_list_fill_801167d4(Ptr32<Owner> self) {
    unsigned total = 0;
    Descriptor_80178474 descriptor;
    unsigned unlocked = 0;
    Handle list;
    {
        Handle value(table_get_80179598(as_table_80341584(self->source), &descriptor));
        list.assign(value.value);
    }
    Ptr32<List> l = (Ptr32<List>)list.value;
    list_begin_801ef380(list.value, 32, 0, 0, l->field->count);
    clear(&((Ptr32<List>)list.value)->values);
    Handle a(create_8020b680(class_80419e68));
    {
        Ptr32<Labels> t = (Ptr32<Labels>)a.value;
        String name(n_8039a448);
        Ptr32<char> text = name.text;
        ++*(Ptr32<unsigned short>)(text - 6);
        Ptr32<char> old = t->title;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    Handle b(create_8020b680(class_80419e88));
    {
        Ptr32<Labels> t = (Ptr32<Labels>)b.value;
        String name(n_8039a454);
        Ptr32<char> text = name.text;
        ++*(Ptr32<unsigned short>)(text - 6);
        Ptr32<char> old = t->title;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    ((Ptr32<Labels>)b.value)->width = width_8039a93c[0];
    int cursor = 0;
    Handle entry;
    String skill;
    String title;
    String key_name;
    while (next_setting_800fc69c(&cursor, &entry)) {
        if (entry.value->vtable->kind(entry.value) != 5) continue;
        {
            Ptr32<Object> o = (Ptr32<Object>)definition_801797b4(as_table_80341584(entry.value));
            if (!is_a(o->vtable->type(o), type_80366208)) continue;
        }
        total++;
        Ptr32<Definition> def = definition_801797b4(as_table_80341584(entry.value));
        Ptr32<ArrayRef> n1 = &((Ptr32<Labels>)a.value)->names;
        Ptr32<Ptr32<char>> sa = grow(n1, n1->header->count + 1);
        Ptr32<ArrayRef> n2 = &((Ptr32<Labels>)b.value)->names;
        Ptr32<Ptr32<char>> sb = grow(n2, n2->header->count + 1);
        Ptr32<ArrayRef> v = &((Ptr32<List>)list.value)->values;
        Ptr32<Ptr32<char>> sv = grow(v, v->header->count + 1);
        Ptr32<ArrayRef> idr = &((Ptr32<Labels>)a.value)->ids;
        int n = idr->header->count;
        Ptr32<Id> ids = (Ptr32<Id>)grow(idr, n + 1);
        int state = def->state;
        int value = 6;
        if (state == 0) {
            value = def->skill;
            unlocked++;
        }
        string_format_8020c510(&skill, f_8039a900, value);
        Key key;
        key.name = def->name.text;
        Key out;
        if (read_key2_800fc2b0(&key, &out) >= 0)
            string_format_8020c510(&title, f_8039a460, w3d::VA(out.name));
        else
            string_format_8020c510(&title, f_8039a914, w3d::VA(entry.value->vtable->name(entry.value)));
        copy(key_name, def->name);
        int priority = 255;
        if (state == 1) priority = 128;
        Id colour;
        if (state != 0) colour.set(128, 255); else colour = self->id;
        unsigned j;
        for (j = 0; j < (unsigned)n && (unsigned)priority <= ids[j].b0; j++) {
            if (priority == ids[j].b0) {
                int c = strcmp(skill.text, sb[j]);
                if (c > 0) goto found;
                if (c == 0 && strcmp(title.text, sa[j]) < 0) goto found;
            }
        }
        found:
        int k = j << 2;
        for (int m = n; m > (int)j; m--) {
            move_up(sa, m);
            move_up(sv, m);
            move_up(sb, m);
            ids[m] = ids[m - 1];
        }
        store(k, sa, title);
        store(k, sb, skill);
        store(k, sv, key_name);
        *(Ptr32<Id>)w3d::G((k + (int)w3d::H(ids))) = colour;
    }
    list_append_801ef174(list.value, 32, 0, b.value);
    list_append_801ef174(list.value, 32, 0, a.value);
    String percent;
    string_format_8020c510(&percent, f_8039a924, (unsigned)(ratio(unlocked) / (float)total * 100.0f));
    Key lock;
    lock.name = n_8039a92c;
    write_value_800fc550(&lock, percent.text);
}


