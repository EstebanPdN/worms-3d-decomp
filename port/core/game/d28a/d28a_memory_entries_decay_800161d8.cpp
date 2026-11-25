#include "w3d_ptr.h"
#line 1 "d28a_memory_entries_decay_800161d8.cpp"
// GWMP8P rev0 0x800161d8. Decays the value of each remembered entry, zeroes
// it when the worm's state or position has changed, and removes and destroys
// entries that fall below 0.1. Names are inferred from the original
// instructions.
extern "C" Ptr32<void> memcpy(Ptr32<void>, Ptr32<const void>, ...);
struct Vec { float x, y, z; };
struct Worm;
struct Words {
    int a, b, c;
    bool operator==(const Words &o) const { return a == o.a && b == o.b && c == o.c; }
};
struct Entry {
    int unknown0;
    float value;     /* +4 */
    char unknown8[8];
    Ptr32<Worm> worm;      /* +16 */
    Words where;     /* +20 */
    int state;       /* +32 */
};
struct EntryList {
    Ptr32<Ptr32<Entry>> start; Ptr32<Ptr32<Entry>> finish;
    int size() const { return finish - start; }
    Ptr32<Entry> & operator[](int i) { return start[i]; }
    void erase(Ptr32<Ptr32<Entry>> p) {
        Ptr32<Ptr32<Entry>> next = p + 1;
        if (next != finish) { Ptr32<char> last = (Ptr32<char>)finish - 4; memcpy(p, next, last - (Ptr32<char>)p); }
        finish--;
    }
};
extern Ptr32<EntryList> g_entries_804aa6f8;
extern "C" int w3d_auto_800155ac(Ptr32<Worm>);
extern "C" Ptr32<const Words> w3d_auto_80015588(Ptr32<Worm>);
extern "C" void w3d_auto_80015d18(Ptr32<Entry>, int);
extern "C" void w3d_d28a_memory_entries_decay_800161d8()
{
    for (int i = 0; i < g_entries_804aa6f8->size(); i++) {
        Ptr32<Entry> e = (*g_entries_804aa6f8)[i];
        e->value *= 0.99f;
        Ptr32<Worm> w = e->worm;
        if (e->state != w3d_auto_800155ac(w) || !(e->where == *w3d_auto_80015588(w))) e->value = 0.0f;
        if (e->value < 0.1f) {
            if (e) w3d_auto_80015d18(e, 3);
            g_entries_804aa6f8->erase(g_entries_804aa6f8->start + i);
            i--;
        }
    }
}


