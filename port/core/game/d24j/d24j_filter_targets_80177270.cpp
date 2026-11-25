#include "w3d_ptr.h"
#line 1 "d24j_filter_targets_80177270.cpp"
// Filtered collections of scene items (Worms 3D GameCube PAL, 0x80177270, 0x8017768c).
//
// Both functions iterate a source (virtual slot 29), keep the items of one
// kind or flag mask, and sort each item's target by its run-time type into a
// new shared list (0x8020b680, named by 0x80413088) with one adder per type.
// Types form a chain through the parent pointer at +20 whose root is its own
// parent. The list is then given to the sink (virtual slot 8).
//
// The source call is written directly through the table: an inline wrapper
// copies its arguments into pseudos and the loop pass hoists both addresses,
// while the original hoists only the iterator key.

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
    Ptr32<Item> p; // the two handles sit at sp+8 and sp+16 in the original
    Handle() { p = 0; }
    template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((Item *)w3d_p.get()) {}
 Handle(Item *v) { p = v; if (v) v->retain(); }
    ~Handle() { if (p) p->release(); }
};
struct Sink { Ptr32<Ptr32<void>> vtable; void add(Ptr32<Item> v, int z) { ((Ptr32<void (Ptr32<Sink>, Ptr32<Item>, int)>)vtable[8])(this, v, z); } };
struct Key { int index; Key() { index = 0; } };
struct Source { Ptr32<Ptr32<void>> vtable; };
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
extern "C" int d24j_filter_targets_by_kind_80177270(Ptr32<Source> self, Ptr32<Sink> sink, int kind)
{
    Key key;
    Handle item;
    Handle list(fn_8020b680(name_80413088));
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
    sink->add(list.p, 0);
    return 0;
}

extern "C" int d24j_filter_targets_by_flags_8017768c(Ptr32<Source> self, Ptr32<Sink> sink, int mask)
{
    Key key;
    Handle item;
    Handle list(fn_8020b680(name_80413088));
    while (((Ptr32<int (Ptr32<Source>, Ptr32<Key>, Ptr32<Handle>)>)self->vtable[29])(self, &key, &item)) {
        if (!(item.p->flags() & mask)) continue;
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
    sink->add(list.p, 0);
    return 0;
}


