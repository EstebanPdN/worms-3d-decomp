#include "w3d_ptr.h"
#line 1 "d25c_spawn_group_800e61b8.cpp"
// d25c: 0x800e61b8. Read a record by name (0x800fc330); a record of the list type 0x803678d8 spawns one object per
// name, any other one object. Each spawn takes a type chosen by the record's +414 flag, joins a new group
// id (counter 0x804aaec8), gets its position when given and is registered with 0x80164514. Names are inferred.
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
inline void set_pos(Ptr32<Spawn> s, Ptr32<const Words> pos) { if (pos) s->pos = *pos; }
inline Ptr32<Spawn> make(Ptr32<const void> k) { Ptr32<Spawn> s = 0; Ptr32<void> m = forward_8020b680(k); if (m) s = (Ptr32<Spawn>)((Ptr32<char>)m + 28); return s; }
// 0x800e61b8: spawn one object per name of a record, or one for a plain record.
extern "C" int d25c_spawn_group_800e61b8(Ptr32<Owner> self, int a, int b, Ptr32<const char> name, Ptr32<Words> pos) {
    Ptr32<Ptr32<const char>> list = 0;
    Ptr32<Record> record;
    record = 0;
    int group = ++counter_804aaec8;
    int status = read_800fc330(&name, &record);
    unsigned count = 1;
    if (status < 0) return 0;
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
        Ptr32<Spawn> s;
        if (r->kind) s = make(key_80410048);
        else s = make(key_8040ffa8);
        if (list) load_800df6a4(s, list[i]);
        else load_800df6a4(s, name);
        init_800dfddc(s, a, b);
        s->group = group;
        set_pos(s, pos);
        Ptr32<void> o = s->vtable->owner(s);
        fn_80164514(service_804b178c, o, self->id);
    }
    return group;
}


