#include "w3d_ptr.h"
#line 1 "d40m_mesh_slots_clear_800c04a4.cpp"
// GWMP8P rev0 0x800c04a4. Releases every mesh slot, then clears the slot
// vector with the standard vector erase: its empty copy loop folds away and
// leaves the loop notes that fix the order of the first loads. The word
// vector is erased the same way through memcpy. Slot, Ref and vector types
// are partial views inferred from the original instructions.
typedef unsigned int size_t;
extern "C" Ptr32<void> memcpy(Ptr32<void>, Ptr32<const void>, size_t);
struct Object;
struct ObjectVt { Ptr32<void> u[4]; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVt> vt; };
struct Ref {
    Ptr32<Object> p;
    ~Ref() { if (p) p->vt->release(p); }
    void assign(Ptr32<Object> n) { if (p) p->vt->release(p); p = n; }
};
struct Slot {
    char u0[12];
    Ref mesh;      // +12
    Ref instance;  // +16
    char u20[4];
    unsigned char key; char w3d_tag_rest[3];  // +27
    unsigned char used; // +28
    char u29[31];
    Slot &operator=(const Slot &o);
};

extern "C" int reset_resources_80182450(Ptr32<Object>);
inline void Distance(Ptr32<Slot> first, Ptr32<Slot> last, int &n) { n += last - first; }
inline Ptr32<Slot> CopyRange(Ptr32<Slot> first, Ptr32<Slot> last, Ptr32<Slot> result)
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
struct FalseType { char w3d_empty; };
inline void DestroyAux(Ptr32<Slot> first, Ptr32<Slot> last, const FalseType &) { for (; first != last; ++first) first->~Slot(); }
inline void DestroyValue(Ptr32<Slot> first, Ptr32<Slot> last, Ptr32<Slot>) { DestroyAux(first, last, FalseType()); }
inline void DestroyRange(Ptr32<Slot> first, Ptr32<Slot> last) { DestroyValue(first, last, first); }
struct SlotVector {
    Ptr32<Slot> start; Ptr32<Slot> finish; Ptr32<Slot> eos;
    Ptr32<Slot> erase(Ptr32<Slot> from, Ptr32<Slot> to)
    {
        Ptr32<Slot> end = CopyRange(to, finish, from);
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
struct WordVector { Ptr32<Word> start; Ptr32<Word> finish; Ptr32<Word> eos; };
extern WordVector g_words_8043c394;
extern int g_804aada8;
struct Sink;
struct SinkVt { Ptr32<void> u[49]; Ptr32<void (Ptr32<Sink>, Ptr32<const char>, int)> set; };
struct Sink { Ptr32<SinkVt> vt; };
struct Renderer { char u[116]; Ptr32<Sink> sink; };
extern Ptr32<Renderer> g_renderer_804b17ec;
extern "C" int format_803442b4(Ptr32<char>, Ptr32<const char>, ...);
extern const char text_80382f88[];
extern "C" void d40m_mesh_slots_clear_800c04a4() {
    g_804aada8 = 0;
    for (unsigned i = 0; i < g_slots_8043c384.size(); i++) {
        if (g_slots_8043c384[i].instance.p) reset_resources_80182450(g_slots_8043c384[i].instance.p);
        if (g_slots_8043c384[i].mesh.p) {
            Ptr32<Sink> s = g_renderer_804b17ec->sink;
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
        Ptr32<char> e = (Ptr32<char>)w.finish;
        Ptr32<char> b = (Ptr32<char>)w.start;
        int n = e - b;
        memcpy(b, e, (Ptr32<char>)w.finish - e);
        w.finish = (Ptr32<Word>)((Ptr32<char>)w.finish - n);
    }
}


