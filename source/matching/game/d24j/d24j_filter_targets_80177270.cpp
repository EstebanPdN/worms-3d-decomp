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

struct TypeInfo { char u[20]; TypeInfo *parent; };
extern TypeInfo type_80361cd8[], type_80361d28[], type_80361d78[], type_80361dc8[], type_80361e18[], type_80361e68[], type_80361eb8[], type_80364964[];
inline bool type_is(TypeInfo *type, TypeInfo *want)
{
    while (type != want) {
        if (type == type->parent) return false;
        type = type->parent;
    }
    return true;
}
struct Target { void **vtable; TypeInfo *type() { return ((TypeInfo *(*)(Target *))vtable[5])(this); } };
struct Item {
    void **vtable;
    void retain() { ((void (*)(Item *))vtable[3])(this); }
    void release() { ((void (*)(Item *))vtable[4])(this); }
    int kind() { return ((int (*)(Item *))vtable[9])(this); }
    int flags() { return ((int (*)(Item *))vtable[10])(this); }
    Target *target() { return ((Target *(*)(Item *))vtable[17])(this); }
};
struct Handle {
 Handle(const Handle &);
    Item *p; // the two handles sit at sp+8 and sp+16 in the original
    Handle() { p = 0; }
    Handle(Item *v) { p = v; if (v) v->retain(); }
    ~Handle() { if (p) p->release(); }
};
struct Sink { void **vtable; void add(Item *v, int z) { ((void (*)(Sink *, Item *, int))vtable[8])(this, v, z); } };
struct Key { int index; Key() { index = 0; } };
struct Source { void **vtable; };
extern "C" Item *fn_8020b680(char *);
extern char name_80413088[];
extern "C" Target *fn_8018ff84(Target *);
extern "C" void fn_8018ffb0(Item *, Target *);
extern "C" void fn_8018ffdc(Item *, Target *);
extern "C" void fn_80190008(Item *, Target *);
extern "C" void fn_80190034(Item *, Target *);
extern "C" void fn_80190060(Item *, Target *);
extern "C" void fn_8019008c(Item *, Target *);
extern "C" void fn_801900b8(Item *, Target *);
extern "C" void fn_801900e4(Item *, Target *);
extern "C" int d24j_filter_targets_by_kind_80177270(Source *self, Sink *sink, int kind)
{
    Key key;
    Handle item;
    Handle list(fn_8020b680(name_80413088));
    while (((int (*)(Source *, Key *, Handle *))self->vtable[29])(self, &key, &item)) {
        if (item.p->kind() != kind) continue;
        Item *l = list.p;
        Target *t = item.p->target();
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

extern "C" int d24j_filter_targets_by_flags_8017768c(Source *self, Sink *sink, int mask)
{
    Key key;
    Handle item;
    Handle list(fn_8020b680(name_80413088));
    while (((int (*)(Source *, Key *, Handle *))self->vtable[29])(self, &key, &item)) {
        if (!(item.p->flags() & mask)) continue;
        Item *l = list.p;
        Target *t = item.p->target();
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
