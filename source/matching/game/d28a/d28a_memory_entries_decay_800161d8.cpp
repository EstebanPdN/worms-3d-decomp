// GWMP8P rev0 0x800161d8. Decays the value of each remembered entry, zeroes
// it when the worm's state or position has changed, and removes and destroys
// entries that fall below 0.1. Names are inferred from the original
// instructions.
extern "C" void *memcpy(void *, const void *, ...);
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
    Worm *worm;      /* +16 */
    Words where;     /* +20 */
    int state;       /* +32 */
};
struct EntryList {
    Entry **start, **finish;
    int size() const { return finish - start; }
    Entry *&operator[](int i) { return start[i]; }
    void erase(Entry **p) {
        Entry **next = p + 1;
        if (next != finish) { char *last = (char *)finish - 4; memcpy(p, next, last - (char *)p); }
        finish--;
    }
};
extern EntryList *g_entries_804aa6f8;
extern "C" int w3d_auto_800155ac(Worm *);
extern "C" const Words *w3d_auto_80015588(Worm *);
extern "C" void w3d_auto_80015d18(Entry *, int);
extern "C" void w3d_d28a_memory_entries_decay_800161d8()
{
    for (int i = 0; i < g_entries_804aa6f8->size(); i++) {
        Entry *e = (*g_entries_804aa6f8)[i];
        e->value *= 0.99f;
        Worm *w = e->worm;
        if (e->state != w3d_auto_800155ac(w) || !(e->where == *w3d_auto_80015588(w))) e->value = 0.0f;
        if (e->value < 0.1f) {
            if (e) w3d_auto_80015d18(e, 3);
            g_entries_804aa6f8->erase(g_entries_804aa6f8->start + i);
            i--;
        }
    }
}
