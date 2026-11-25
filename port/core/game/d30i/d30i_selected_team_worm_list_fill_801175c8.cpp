#include "w3d_ptr.h"
#line 1 "d30i_selected_team_worm_list_fill_801175c8.cpp"
// d30i: 0x801175c8. Fills the worm list for FE.SelectedTeam by finding its team in GM.GameInitData, listing the six worm names and colouring those in play with the team colour.
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
struct Owner { unsigned char unknown00[76]; Ptr32<Object> source; };
struct GameInit {
    unsigned char unknown0[32];
    String t0_worm5;  // +32
    String t0_worm4;  // +36
    String t0_worm3;  // +40
    String t0_worm2;  // +44
    String t0_worm1;  // +48
    String t3_worm4;  // +52
    int t0_worms;  // +56
    unsigned char unknown3c[4];
    String t0_name;  // +64
    unsigned char unknown44[24];
    unsigned count;  // +92
    unsigned char unknown60[16];
    String t1_worm5;  // +112
    String t1_worm4;  // +116
    String t1_worm3;  // +120
    String t2_worm3;  // +124
    String t1_worm1;  // +128
    String t1_worm0;  // +132
    int t1_worms;  // +136
    unsigned char unknown8c[4];
    String t1_name;  // +144
    unsigned char unknown94[4];
    int t0_team;  // +152
    unsigned char unknown9c[8];
    String t1_worm2;  // +164
    unsigned char unknowna8[16];
    String t2_worm5;  // +184
    String t2_worm4;  // +188
    unsigned char unknownc0[4];
    String t2_worm2;  // +196
    String t2_worm1;  // +200
    String t2_worm0;  // +204
    int t2_worms;  // +208
    unsigned char unknownd4[4];
    String t2_name;  // +216
    unsigned char unknowndc[4];
    int t1_team;  // +224
    int t2_team;  // +228
    unsigned char unknowne8[4];
    int t3_team;  // +236
    unsigned char unknownf0[20];
    String t3_worm5;  // +260
    String t0_worm0;  // +264
    String t3_worm3;  // +268
    String t3_worm2;  // +272
    String t3_worm1;  // +276
    String t3_worm0;  // +280
    int t3_worms;  // +284
    unsigned char unknown120[4];
    String t3_name;  // +292
};
extern int colours_8044d254[];
extern const char class_80419e68[], n_8039a478[], n_8039a98c[], n_8039a750[];
extern "C" int read_setting_800fc1b0(Ptr32<Key>, Ptr32<Handle>);
extern "C" Ptr32<GameInit> definition_801797b4(Ptr32<void>);
extern "C" int read_key2_800fc2b0(Ptr32<Key>, Ptr32<Key>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
struct Colour { unsigned char b0, b1, b2, b3; void set(unsigned char v, unsigned char a) { b0 = v; b1 = v; b2 = v; b3 = a; } };
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
extern "C" void d30i_selected_team_worm_list_fill_801175c8(Ptr32<Owner> self) {
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
    Ptr32<GameInit> g = definition_801797b4(as_table_80341584(lookup.value));
    unsigned count = g->count;
    if (count == 0) return;
    Handle a(create_8020b680(class_80419e68));
    {
        Ptr32<Labels> t = (Ptr32<Labels>)a.value;
        String name(n_8039a98c);
        Ptr32<char> text = name.text;
        ++*(Ptr32<unsigned short>)(text - 6);
        Ptr32<char> old = t->title;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short n = --*header;
        if (n == 0) string_release_8020bb2c(header);
        t->title = name.text;
    }
    *(Ptr32<int>)((Ptr32<char>)a.value + 28) = 4;
    ((Ptr32<Labels>)a.value)->width = 100.0f;
    Key selected;
    selected.name = n_8039a750;
    Key out;
    read_key2_800fc2b0(&selected, &out);
    String worms[6];
    unsigned worm_count = 1;
    bool found = false;
    int team = 0;
    if (count > 0 && strcmp(out.name, g->t0_name.text) == 0) {
        copy(worms[0], g->t0_worm0);
        copy(worms[1], g->t0_worm1);
        copy(worms[2], g->t0_worm2);
        copy(worms[3], g->t0_worm3);
        copy(worms[4], g->t0_worm4);
        copy(worms[5], g->t0_worm5);
        found = true;
        worm_count = g->t0_worms;
        team = g->t0_team;
    }
    if (count > 1 && !found && strcmp(out.name, g->t1_name.text) == 0) {
        copy(worms[0], g->t1_worm0);
        copy(worms[1], g->t1_worm1);
        copy(worms[2], g->t1_worm2);
        copy(worms[3], g->t1_worm3);
        copy(worms[4], g->t1_worm4);
        copy(worms[5], g->t1_worm5);
        found = true;
        worm_count = g->t1_worms;
        team = g->t1_team;
    }
    if (count > 2 && !found && strcmp(out.name, g->t2_name.text) == 0) {
        copy(worms[0], g->t2_worm0);
        copy(worms[1], g->t2_worm1);
        copy(worms[2], g->t2_worm2);
        copy(worms[3], g->t2_worm3);
        copy(worms[4], g->t2_worm4);
        copy(worms[5], g->t2_worm5);
        found = true;
        worm_count = g->t2_worms;
        team = g->t2_team;
    }
    if (count > 3 && !found && strcmp(out.name, g->t3_name.text) == 0) {
        copy(worms[0], g->t3_worm0);
        copy(worms[1], g->t3_worm1);
        copy(worms[2], g->t3_worm2);
        copy(worms[3], g->t3_worm3);
        copy(worms[4], g->t3_worm4);
        copy(worms[5], g->t3_worm5);
        found = true;
        worm_count = g->t3_worms;
        team = g->t3_team;
    }
    if (!found) return;
    Ptr32<ArrayRef> r1 = &((Ptr32<Labels>)a.value)->names;
    Ptr32<Ptr32<char>> sa = grow(r1, r1->header->count + 6);
    Ptr32<ArrayRef> r2 = &((Ptr32<Labels>)a.value)->ids;
    Ptr32<Colour> ids = (Ptr32<Colour>)grow(r2, r2->header->count + 6);
    Colour grey;
    grey.set(128, 255);
    for (unsigned i = 0; i <= 5; i++) {
        store(i << 2, sa, worms[i]);
        if (i < worm_count) *(Ptr32<int>)&ids[i] = *(Ptr32<int>)((team << 2) + (Ptr32<char>)colours_8044d254); else ids[i] = grey;
    }
    list_append_801ef174(list.value, 32, 0, a.value);
}


