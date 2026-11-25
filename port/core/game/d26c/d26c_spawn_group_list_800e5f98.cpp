#include "w3d_ptr.h"
#line 1 "d26c_spawn_group_list_800e5f98.cpp"
// d26c: 0x800e5f98. Spawn one object per name of a resource record (or one for a plain record), tag them with a new
// group id and register each with the owner. Names are inferred; String is one word; same family as d25c 0x800e61b8
// and 0x800e5da0.
struct Type { unsigned char unknown00[20]; Ptr32<const Type> parent; };
struct Words { int a, b, c; };
struct Key { Ptr32<const char> text; };
struct Names { unsigned char u[24]; unsigned count; unsigned char u28[4]; Ptr32<const char> names[1]; };
struct Record {
    struct V { Ptr32<void> u[5]; Ptr32<Ptr32<const Type> (Ptr32<Record>)> type; }; Ptr32<struct V> vtable;
    unsigned char u4[16];
    Ptr32<Names> names;       // +20
    unsigned char u24[390];
    unsigned short kind; // +414
};
struct Spawn {
    unsigned char u0[68];
    Words pos;          // +68
    unsigned char u80[24];
    int group;          // +104
    unsigned char u108[120];
    struct V { Ptr32<void> u[5]; Ptr32<Ptr32<void> (Ptr32<Spawn>)> owner; }; Ptr32<struct V> vtable;  // +228
};
struct Owner { unsigned char u[20]; int id; };
extern "C" int read_800fc330(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<Record>>);
extern "C" Ptr32<void> forward_8020b680(Ptr32<const void>);
extern "C" void load_800df6a4(Ptr32<Spawn>, Ptr32<const char>);
extern "C" void init_800dfddc(Ptr32<Spawn>, int, int);
struct String {
    Ptr32<char> text;
    String(const String &);
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    ~String();
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
extern "C" void attach_800e2118(Ptr32<void>, Ptr32<void>, Ptr32<String>, int);
extern "C" int fn_80164514(Ptr32<void>, Ptr32<void>, int);
extern Ptr32<void> service_804b178c;
extern int counter_804aaec8;
extern const Type type_803678d8[];
extern const unsigned char key_80410048[], key_8040ffa8[];
inline bool is_a(Ptr32<const Type> t, Ptr32<const Type> target) {
    while (t != target) {
        if (t == t->parent) return false;
        t = t->parent;
    }
    return true;
}
inline void make(Ptr32<Spawn> &s, Ptr32<const void> k) { s = 0; Ptr32<void> m = forward_8020b680(k); if (m) s = (Ptr32<Spawn>)((Ptr32<char>)m + 28); }
extern "C" int d26c_spawn_group_list_800e5f98(Ptr32<Owner> self, int attach, Ptr32<const char> text, Ptr32<const char> name, int arg, int extra) {
    Ptr32<Spawn> s = 0;
    int group = ++counter_804aaec8;
    Ptr32<Record> record;
    record = (Ptr32<Record>)s;
    unsigned count = 1;
    int status = read_800fc330(&name, &record);
    Ptr32<Ptr32<const char>> list = 0;
    if (status < 0 || attach == 0) return 0;
    if (is_a(record->vtable->type(record), type_803678d8)) {
        count = record->names->count;
        list = record->names->names;
    }
    for (unsigned i = 0; i < count; i++) {
        Ptr32<Record> r;
        if (list) {
            Ptr32<const char> k2 = list[i];
            Ptr32<Record> found;
            read_800fc330(&k2, &found);
            r = found;
        } else {
            r = record;
        }
        if (r->kind || attach == 0) {
            make(s, key_80410048);
            init_800dfddc(s, arg, 0);
        } else {
            make(s, key_8040ffa8);
            Ptr32<void> owner = s ? w3d::R((Ptr32<char>)s - 28) : 0;
            String label(text);
            attach_800e2118(owner, (Ptr32<void>)w3d::G(attach), &label, extra);
        }
        if (list) load_800df6a4(s, list[i]);
        else load_800df6a4(s, name);
        s->group = group;
        Ptr32<void> o = s->vtable->owner(s);
        fn_80164514(service_804b178c, o, self->id);
    }
    return group;
}


