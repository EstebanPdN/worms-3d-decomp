// GWMP8P rev0 0x8003f400. Hands out a trigger slot: reuses the last free
// index, resetting that entry's owner and two timers and showing its object,
// or appends a new 32-byte entry to the vector with unmodified STLport
// push_back and, when ball debugging is on, attaches a Trigger.Ball object.
// Returns the index. Names are inferred from the original strings and
// instructions.
#include "compat/stlport_sn_oom.h"
#include <vector>
struct String;
extern "C" void w3d_string_base_finish(String *);
extern "C" void w3d_string_release(String *);
struct String {
    const char *text;
    String(const char *);
    String(const String &o);
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct Vec {
    float x, y, z;
    Vec() {}
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Obj;
struct ObjTable { char pad[12]; void (*add)(Obj *); void (*release)(Obj *); char pad2[68]; int (*vis)(Obj *, int); };
struct Obj { ObjTable *t; };
struct Ref {
    Obj *p;
    Ref() { p = 0; }
    Ref(const Ref &o) { p = o.p; if (p) p->t->add(p); }
    ~Ref() { if (p) p->t->release(p); }
    Ref &operator=(Obj *q) { if (p) p->t->release(p); p = q; return *this; }
};
struct Trigger {
    Vec pos;
    float a, b;
    int owner;
    int id;
    Ref ref;
    Trigger() {}
    Trigger &operator=(const Trigger &);
};
extern std::vector<Trigger> g_items_804273ec;
extern std::vector<unsigned short> g_free_804273fc;
extern int g_named_804aa968;
extern "C" int w3d_handle_set_name(const String &, Ref *, int);
extern "C" unsigned short w3d_d32a_trigger_pool_allocate_8003f400(int owner)
{
    unsigned int n = g_free_804273fc.size();
    if (n) {
        unsigned short i = g_free_804273fc[n - 1];
        g_items_804273ec[i].owner = owner;
        g_items_804273ec[i].a = 0.0f;
        g_items_804273ec[i].b = 0.0f;
        if (g_items_804273ec[i].ref.p) g_items_804273ec[i].ref.p->t->vis(g_items_804273ec[i].ref.p, 1);
        g_free_804273fc.pop_back();
        return i;
    }
    Trigger t;
    t.owner = owner;
    t.a = 0.0f;
    t.b = 0.0f;
    t.pos.Set(0.0f, 0.0f, 0.0f);
    t.id = -1;
    t.ref = 0;
    g_items_804273ec.push_back(t);
    if (g_named_804aa968) w3d_handle_set_name(String("Trigger.Ball"), &g_items_804273ec.back().ref, 255);
    return g_items_804273ec.size() - 1;
}
