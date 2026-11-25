#include "w3d_ptr.h"
#line 1 "d32i_results_table_build_80111820.cpp"
// d32i: 0x80111820. Fills the end-of-game results list: reads the game init
// object, builds the label columns, then inserts each team in order of
// rounds won, colour, skill and name.
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
struct Owner { unsigned char unknown00[92]; Ptr32<Object> source; };
struct GameInit {
    unsigned char unknown00[28];
    int skill0;         // +28
    unsigned char unknown20[24];
    int worms0;         // +56
    unsigned char unknown3c[4];
    String name0;       // +64 (value at +64, sic)
    unsigned char unknown44[24];
    unsigned count;     // +92
    unsigned char unknown60[12];
    int skill1;         // +108
    unsigned char unknown70[24];
    int worms1;         // +136
    unsigned char unknown8c[4];
    String name1;       // +144
    unsigned char unknown94[4];
    int team0;          // +152
    unsigned char unknown9c[24];
    int skill2;         // +180
    unsigned char unknownb8[24];
    int worms2;         // +208
    unsigned char unknownd4[4];
    String name2;       // +216
    unsigned char unknowndc[4];
    int team1;          // +224
    int team2;          // +228
    unsigned char unknowne8[4];
    int team3;          // +236
    unsigned char unknownf0[16];
    int skill3;         // +256
    unsigned char unknown104[24];
    int worms3;         // +284
    unsigned char unknown120[4];
    String name3;       // +292
};
extern int colours_8044d254[];
extern const char class_80419e68[], class_80419e88[], n_8039a478[], n_8039a448[], n_8039a4bc[], n_8039a490[], f_8039a464[], f_8039a4c8[], n_8039a0e0[];
struct Result { unsigned char unknown00[20]; int rounds; };
extern "C" Ptr32<Result> result_800fc914(unsigned);
extern "C" Ptr32<void> string_append_8020bf2c(Ptr32<String>, Ptr32<const char>);
extern "C" void string_init_8020c5c0(Ptr32<String>);
extern "C" Ptr32<unsigned short> string_header_80341884(Ptr32<String>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
struct Colour { unsigned char b0, b1, b2, b3; };
extern "C" int read_setting_800fc1b0(Ptr32<Key>, Ptr32<Handle>);
inline String::String(const String &o) {
    string_init_8020c5c0(this);
    text = o.text;
    struct H { unsigned short refs, length, capacity; }; Ptr32<struct H> h = (Ptr32<H>)string_header_80341884(this);
    ++h->refs;
}
static inline String join_v(String a, const String &b) {
    string_append_8020bf2c(&a, b.text);
    return a;
}
static inline String join(const String &a, const String &b) {
    return join_v(a, b);
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
static inline bool same(const Colour &a, const Colour &b) { return a.b1 == b.b1; }
static inline Ptr32<Ptr32<char>> grow_by(Ptr32<ArrayRef> array, const unsigned &n) {
    Ptr32<ArrayHeader> header = array->header;
    int c = header->count;
    int size = n + c;
    if (header->kind == 1 && size == header->count) {
        ++header->locks;
        return header->data;
    }
    return array_lock_801ef048(array, size, 4, 2);
}
inline Ptr32<Ptr32<char>> GrowBy(ArrayRef &r, unsigned n) { return grow(&r, r.header->count + n); }
extern "C" void d32i_results_table_build_80111820(Ptr32<Owner> self) {
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
    Key key;
    key.name = n_8039a478;
    if (read_setting_800fc1b0(&key, &lookup) < 0) return;
    Handle init;
    {
        Handle value(table_get_80179598(as_table_80341584(lookup.value), &descriptor2));
        init.assign(value.value);
    }
    unsigned count = ((Ptr32<GameInit>)init.value)->count;
    if (count == 0) return;
    Ptr32<const char> cls_a = class_80419e68;
    Handle a(create_8020b680(cls_a));
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
    ((Ptr32<Labels>)a.value)->width = 75.0f;
    Handle b(create_8020b680(cls_a));
    {
        Ptr32<Labels> t = (Ptr32<Labels>)b.value;
        String name(n_8039a4bc);
        Ptr32<char> text = name.text;
        ++*(Ptr32<unsigned short>)(text - 6);
        Ptr32<char> old = t->title;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    ((Ptr32<Labels>)b.value)->width = 100.0f;
    Handle c(create_8020b680(class_80419e88));
    {
        Ptr32<Labels> t = (Ptr32<Labels>)c.value;
        String name(n_8039a490);
        Ptr32<char> text = name.text;
        ++*(Ptr32<unsigned short>)(text - 6);
        Ptr32<char> old = t->title;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    ((Ptr32<Labels>)c.value)->width = 32.0f;
    Ptr32<Colour> ids_a = (Ptr32<Colour>)GrowBy(((Ptr32<Labels>)a.value)->ids, count);
    Ptr32<Colour> ids_b = (Ptr32<Colour>)GrowBy(((Ptr32<Labels>)b.value)->ids, count);
    Ptr32<Ptr32<char>> sa = GrowBy(((Ptr32<Labels>)a.value)->names, count);
    Ptr32<Ptr32<char>> sb = GrowBy(((Ptr32<Labels>)b.value)->names, count);
    Ptr32<Ptr32<char>> sc = GrowBy(((Ptr32<Labels>)c.value)->names, count);
    Ptr32<Ptr32<char>> sv = GrowBy(((Ptr32<List>)list.value)->values, count);
    int team = 0;
    int skill_value;
    String skill;
    String won;
    String name;
    for (unsigned i = 0; i < count; i++) {
        switch (i) {
        case 0:
            copy(name, ((Ptr32<GameInit>)init.value)->name0);
            skill_value = ((Ptr32<GameInit>)init.value)->skill0;
            team = ((Ptr32<GameInit>)init.value)->team0;
            break;
        case 1:
            copy(name, ((Ptr32<GameInit>)init.value)->name1);
            skill_value = ((Ptr32<GameInit>)init.value)->skill1;
            team = ((Ptr32<GameInit>)init.value)->team1;
            break;
        case 2:
            copy(name, ((Ptr32<GameInit>)init.value)->name2);
            skill_value = ((Ptr32<GameInit>)init.value)->skill2;
            team = ((Ptr32<GameInit>)init.value)->team2;
            break;
        case 3:
            copy(name, ((Ptr32<GameInit>)init.value)->name3);
            skill_value = ((Ptr32<GameInit>)init.value)->skill3;
            team = ((Ptr32<GameInit>)init.value)->team3;
            break;
        }
        string_format_8020c510(&won, f_8039a4c8, result_800fc914(i)->rounds);
        string_format_8020c510(&skill, f_8039a464, skill_value);
        Colour colour = *(Ptr32<Colour>)((team << 2) + (Ptr32<char>)colours_8044d254);
        copy(name, join(String(n_8039a0e0), name));
        unsigned j;
        int cmp;
        for (j = 0; j < i && (cmp = strcmp(won.text, sb[j])) <= 0; j++) {
            if (cmp == 0) {
                if (same(colour, ids_a[j])) {
                    if (strcmp(skill.text, sc[j]) < 0) goto found;
                    if (strcmp(name.text, sa[j]) < 0) goto found;
                } else {
                    if (strcmp(skill.text, sc[j]) < 0) goto found;
                    if (strcmp(name.text, sa[j]) < 0) goto found;
                }
            }
        }
        found:
        for (int m = i; m > (int)j; m--) {
            move_up(sa, m);
            move_up(sb, m);
            move_up(sv, m);
            move_up(sc, m);
            ids_a[m] = ids_a[m - 1];
            ids_b[m] = ids_b[m - 1];
        }
        int k = j << 2;
        store(k, sc, skill);
        store(k, sb, won);
        store(k, sa, name);
        store(k, sv, name);
        *(Ptr32<int>)w3d::G((k + (int)w3d::H(ids_a))) = *(Ptr32<int>)((team << 2) + (Ptr32<char>)colours_8044d254);
        *(Ptr32<int>)w3d::G((k + (int)w3d::H(ids_b))) = *(Ptr32<int>)((team << 2) + (Ptr32<char>)colours_8044d254);
    }
    list_append_801ef174(list.value, 32, 0, c.value);
    list_append_801ef174(list.value, 32, 0, a.value);
    list_append_801ef174(list.value, 32, 0, b.value);
}


