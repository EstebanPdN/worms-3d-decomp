// Reset the 80-entry source slot table, GWMP8P rev0 0x80198744. For each slot
// with a source, asks the source for the object and data of the slot's key
// through its vtable and releases the data on the object's body; then clears
// the key, source and handle fields and the top two flag bits.

struct Source;
struct Body { int x; };
struct Obj { int u[2]; Body body; };
struct SourceVtable { void *u0[9]; Obj *(*object)(Source *, unsigned); void *(*data)(Source *, unsigned); };
struct Source { SourceVtable *vtable; };
struct Slot {
    unsigned key;
    Source *source;
    int handle;
    unsigned a : 1;
    unsigned b : 1;
};
extern "C" int release_80197f98(Body *, void *);
extern "C" void d28j_reset_slots_80198744(Slot *table) {
    for (unsigned i = 0; i < 80; ++i) {
        Slot &s = table[i];
        if (s.source) {
            Obj *o = s.source->vtable->object(s.source, s.key);
            void *d = s.source->vtable->data(s.source, s.key);
            release_80197f98(&o->body, d);
        }
        s.key = 0;
        s.source = 0;
        s.handle = 0;
        s.a = 0; s.b = 0;
    }
}
