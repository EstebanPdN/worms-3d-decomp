// GWMP8P rev0 0x800c04a4. Releases every mesh slot, then clears the slot
// vector with the standard vector erase: its empty copy loop folds away and
// leaves the loop notes that fix the order of the first loads. The word
// vector is erased the same way through memcpy. Slot, Ref and vector types
// are partial views inferred from the original instructions.
typedef unsigned long size_t;
extern "C" void *memcpy(void *, const void *, size_t);
struct Object;
struct ObjectVt { void *u[4]; void (*release)(Object *); };
struct Object { ObjectVt *vt; };
struct Ref {
    Object *p;
    ~Ref() { if (p) p->vt->release(p); }
    void assign(Object *n) { if (p) p->vt->release(p); p = n; }
};
struct Slot {
    char u0[12];
    Ref mesh;      // +12
    Ref instance;  // +16
    char u20[7];
    unsigned char key;  // +27
    unsigned char used; // +28
    char u29[31];
    Slot &operator=(const Slot &o);
};

extern "C" int reset_resources_80182450(Object *);
inline void Distance(Slot *first, Slot *last, int &n) { n += last - first; }
inline Slot *CopyRange(Slot *first, Slot *last, Slot *result)
{
    int n = 0;
    Distance(first, last, n);
    for (; n > 0; --n) {
        *result = *first;
        ++first;
        ++result;
    }
    return result;
}
struct FalseType {};
inline void DestroyAux(Slot *first, Slot *last, const FalseType &) { for (; first != last; ++first) first->~Slot(); }
inline void DestroyValue(Slot *first, Slot *last, Slot *) { DestroyAux(first, last, FalseType()); }
inline void DestroyRange(Slot *first, Slot *last) { DestroyValue(first, last, first); }
struct SlotVector {
    Slot *start, *finish, *eos;
    Slot *erase(Slot *from, Slot *to)
    {
        Slot *end = CopyRange(to, finish, from);
        DestroyRange(end, finish);
        finish = end;
        return from;
    }
    void clear() { erase(start, finish); }
    unsigned size() const { return finish - start; }
    Slot &operator[](unsigned i) { return start[i]; }
};
extern SlotVector g_slots_8043c384;
struct Word { int v; };
struct WordVector { Word *start, *finish, *eos; };
extern WordVector g_words_8043c394;
extern int g_804aada8;
struct Sink;
struct SinkVt { void *u[49]; void (*set)(Sink *, const char *, int); };
struct Sink { SinkVt *vt; };
struct Renderer { char u[116]; Sink *sink; };
extern Renderer *g_renderer_804b17ec;
extern "C" int format_803442b4(char *, const char *, ...);
extern const char text_80382f88[];
extern "C" void d40m_mesh_slots_clear_800c04a4() {
    g_804aada8 = 0;
    for (unsigned i = 0; i < g_slots_8043c384.size(); i++) {
        if (g_slots_8043c384[i].instance.p) reset_resources_80182450(g_slots_8043c384[i].instance.p);
        if (g_slots_8043c384[i].mesh.p) {
            Sink *s = g_renderer_804b17ec->sink;
            char name[32];
            s->vt->set(s, (format_803442b4(name, text_80382f88, i), name), g_slots_8043c384[i].key);
        }
        g_slots_8043c384[i].instance.assign(0);
        g_slots_8043c384[i].mesh.assign(0);
        g_slots_8043c384[i].used = 0;
    }
    g_slots_8043c384.clear();
    {
        WordVector &w = g_words_8043c394;
        char *e = (char *)w.finish;
        char *b = (char *)w.start;
        int n = e - b;
        memcpy(b, e, (char *)w.finish - e);
        w.finish = (Word *)((char *)w.finish - n);
    }
}
