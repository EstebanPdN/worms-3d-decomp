#include "w3d_ptr.h"
#line 1 "d24j_load_filtered_targets_80176d4c.cpp"
// Load a data resource and sort its items by run-time type (Worms 3D GameCube PAL, 0x80176d4c).
//
// Opens the path with a reader in mode 6, creates the writer for mode bit 0
// (other modes return 0x80004005), then sorts targets of items of the given
// kind into a new shared list as d24j_filter_targets_80177270 does, and hands
// the list to the writer with the name 0x803a6c08. Returns 0 or the reader's
// negative status.

struct TypeInfo { char u[20]; Ptr32<TypeInfo> parent; };
extern TypeInfo type_80361cd8[], type_80361d28[], type_80361d78[], type_80361dc8[], type_80361e18[], type_80361e68[], type_80361eb8[], type_80364964[];
inline bool type_is(Ptr32<TypeInfo> type, Ptr32<TypeInfo> want)
{
    while (type != want) {
        if (type == type->parent) return false;
        type = type->parent;
    }
    return true;
}
struct Target { Ptr32<Ptr32<void>> vtable; Ptr32<TypeInfo> type() { return ((Ptr32<Ptr32<TypeInfo> (Ptr32<Target>)>)vtable[5])(this); } };
struct Item {
    Ptr32<Ptr32<void>> vtable;
    void retain() { ((Ptr32<void (Ptr32<Item>)>)vtable[3])(this); }
    void release() { ((Ptr32<void (Ptr32<Item>)>)vtable[4])(this); }
    int kind() { return ((Ptr32<int (Ptr32<Item>)>)vtable[9])(this); }
    int flags() { return ((Ptr32<int (Ptr32<Item>)>)vtable[10])(this); }
    Ptr32<Target> target() { return ((Ptr32<Ptr32<Target> (Ptr32<Item>)>)vtable[17])(this); }
};
struct Handle {
 Handle(const Handle &);
    Ptr32<Item> p; // slots at sp+32, sp+40 and sp+48 in the original
    Handle() { p = 0; }
    template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((Item *)w3d_p.get()) {}
 Handle(Item *v) { p = v; if (v) v->retain(); }
    ~Handle() { if (p) p->release(); }
};
struct Key { int index; Key() { index = 0; } };
struct Source { Ptr32<Ptr32<void>> vtable; int next(Ptr32<Key> k, Ptr32<Handle> h) { return ((Ptr32<int (Ptr32<Source>, Ptr32<Key>, Ptr32<Handle>)>)vtable[29])(this, k, h); } };
extern "C" Ptr32<Item> fn_8020b680(Ptr32<char>);
extern char name_80413088[];
extern "C" Ptr32<Target> fn_8018ff84(Ptr32<Target>);
extern "C" void fn_8018ffb0(Ptr32<Item>, Ptr32<Target>);
extern "C" void fn_8018ffdc(Ptr32<Item>, Ptr32<Target>);
extern "C" void fn_80190008(Ptr32<Item>, Ptr32<Target>);
extern "C" void fn_80190034(Ptr32<Item>, Ptr32<Target>);
extern "C" void fn_80190060(Ptr32<Item>, Ptr32<Target>);
extern "C" void fn_8019008c(Ptr32<Item>, Ptr32<Target>);
extern "C" void fn_801900b8(Ptr32<Item>, Ptr32<Target>);
extern "C" void fn_801900e4(Ptr32<Item>, Ptr32<Target>);

extern "C" int fn_802080a0(Ptr32<void>, Ptr32<char>, int);
extern "C" int fn_8020810c(Ptr32<void>);
struct Doc { Ptr32<Ptr32<void>> vtable; char u[48]; unsigned char kind52;
    void retain() { ((Ptr32<void (Ptr32<Doc>)>)vtable[3])(this); }
    void release() { ((Ptr32<void (Ptr32<Doc>)>)vtable[4])(this); }
};
// Out-of-line file reader: constructor 0x80207fec, destructor 0x8020803c.
struct Reader { char u[20]; int value; Reader(); ~Reader(); };
extern char name_80418f78[];
extern char text_803a6c08[];

extern "C" int d24j_load_filtered_targets_80176d4c(Ptr32<Source> self, Ptr32<char> path, unsigned char kind, unsigned mode)
{
    Reader reader;
    int status = fn_802080a0(&reader, path, 6);
    if (status < 0) return status;
    Handle a;
    if (mode & 1) {
        Ptr32<Item> value = fn_8020b680(name_80418f78);
        if (value) value->retain();
        if (a.p) a.p->release();
        a.p = value;
    } else {
        // Both unsupported modes fail alike; the original keeps the dead test.
        if (mode & 2) return 0x80004005;
        return 0x80004005;
    }
    ((Ptr32<void (Ptr32<Item>, int)>)a.p->vtable[5])(a.p, reader.value);
    Handle list(fn_8020b680(name_80413088));
    ((Ptr32<Doc>)list.p)->kind52 = kind;
    Key key;
    Handle item;
    while (((Ptr32<int (Ptr32<Source>, Ptr32<Key>, Ptr32<Handle>)>)self->vtable[29])(self, &key, &item)) {
        if (item.p->kind() != kind) continue;
        Ptr32<Item> l = list.p;
        Ptr32<Target> t = item.p->target();
        if (type_is(t->type(), type_80361cd8)) fn_8018ffb0(l, t);
        else if (type_is(t->type(), type_80361d28)) fn_8018ffdc(l, t);
        else if (type_is(t->type(), type_80361d78)) fn_80190008(l, t);
        else if (type_is(t->type(), type_80361dc8)) fn_80190034(l, t);
        else if (type_is(t->type(), type_80361e18)) fn_80190060(l, t);
        else if (type_is(t->type(), type_80361e68)) {
            if (type_is(fn_8018ff84(t)->type(), type_80364964)) fn_801900b8(l, t);
            else fn_8019008c(l, t);
        }
        else if (type_is(t->type(), type_80361eb8)) fn_801900e4(l, t);
    }
    ((Ptr32<void (Ptr32<Item>, Ptr32<Item>, Ptr32<char>)>)a.p->vtable[8])(a.p, list.p, text_803a6c08);
    fn_8020810c(&reader);
    return 0;
}


