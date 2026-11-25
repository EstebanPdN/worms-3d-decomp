#include "w3d_ptr.h"
#line 1 "d28j_reset_slots_80198744.cpp"
// Reset the 80-entry source slot table, GWMP8P rev0 0x80198744. For each slot
// with a source, asks the source for the object and data of the slot's key
// through its vtable and releases the data on the object's body; then clears
// the key, source and handle fields and the top two flag bits.

struct Source;
struct Body { int x; };
struct Obj { int u[2]; Body body; };
struct SourceVtable { Ptr32<void> u0[9]; Ptr32<Ptr32<Obj> (Ptr32<Source>, unsigned int)> object; Ptr32<Ptr32<void> (Ptr32<Source>, unsigned int)> data; };
struct Source { Ptr32<SourceVtable> vtable; };
struct Slot {
    unsigned key;
    Ptr32<Source> source;
    int handle;
    unsigned int :30; unsigned int b:1; unsigned int a:1;
};
extern "C" int release_80197f98(Ptr32<Body>, Ptr32<void>);
extern "C" void d28j_reset_slots_80198744(Ptr32<Slot> table) {
    for (unsigned i = 0; i < 80; ++i) {
        Slot &s = table[i];
        if (s.source) {
            Ptr32<Obj> o = s.source->vtable->object(s.source, s.key);
            Ptr32<void> d = s.source->vtable->data(s.source, s.key);
            release_80197f98(&o->body, d);
        }
        s.key = 0;
        s.source = 0;
        s.handle = 0;
        s.a = 0; s.b = 0;
    }
}


