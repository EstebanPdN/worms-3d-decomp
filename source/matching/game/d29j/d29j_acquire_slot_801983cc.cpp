// Acquire a cache slot for a key from a source. Sizes the data from the source
// object's element count (24 bytes each, rounded up to 32), evicts to get a
// slot, then tries up to five times to load the data, evicting again after each
// failure. Fills in the slot, optionally reports the addition, and sets its
// timeout to 2000 or 12000. GWMP8P rev0 0x801983cc.
struct Body { int x; };
struct Obj { int u[2]; Body body; unsigned short count; };
struct Source;
struct SourceVtable { void *u0[9]; Obj *(*object)(Source *, unsigned); void *(*data)(Source *, unsigned); };
struct Source { SourceVtable *vtable; };
struct Slot {
    unsigned key;
    Source *source;
    int handle;
    unsigned a : 1;
    unsigned b : 1;
    unsigned c : 1;
};
struct Cache;
extern "C" Slot *fn_801984fc(Cache *, unsigned);
extern "C" int fn_8019805c(Body *, void *);
extern "C" void fn_802fb7ac(const char *, ...);
extern const char msg_803a857c[];
extern "C" Slot *d29j_acquire_slot_801983cc(Cache *self, unsigned key, Source *source, int slow, int report)
{
    unsigned bytes = (source->vtable->object(source, key)->count * 24 + 31) & ~31;
    Slot *s = fn_801984fc(self, bytes);
    Obj *o = source->vtable->object(source, key);
    void *d = source->vtable->data(source, key);
    unsigned i = 0;
    do {
    goto test;
next:
    ++i;
test:
    if (i <= 4 && !fn_8019805c(&o->body, d)) {
        fn_801984fc(self, bytes);
        goto next;
    }
    } while (0);
    s->key = key;
    s->source = source;
    s->a = 1; s->b = 1;
    if (report) {
        fn_802fb7ac(msg_803a857c);
        s->c = 1;
    }
    s->handle = 2000;
    if (slow) s->handle = 12000;
    return s;
}
