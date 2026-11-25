// (Worms 3D GameCube PAL, 0x801a81c4).
//
// Constructs the renderer state object: base table 0x80413d30 with tag at
// +4, final table 0x80413cc0, two item pools, three layer arrays of 64 slots
// with flags 2, 0 and 1, and a function-local static slot holder (table
// 0x80413ca8) connected once to the second signal of 0x801ea954. Allocates
// 512 items of class 0x80363bf4 and 32 of class 0x80363c44, stores them in
// the pools and takes a reference to a new 0x80363b54 object at +176. Names
// are inferred; connection shape follows the public sigslot library.

#pragma interface
#include "compat/stlport_sn_oom.h"
#include <list>
#include <set>
#include <vector>
extern "C" void *alloc_80212fd4(unsigned);
extern "C" void free_802134fc(void *);
extern "C" void *memcpy_802eee50(void *, const void *, unsigned, ...);
inline const int &v_max(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &v_min(const unsigned &a, const unsigned &b) { return b < a ? b : a; }

struct Policy { virtual ~Policy(); virtual void lock(); virtual void unlock(); };
struct LockBlock {
    Policy *m;
    LockBlock(Policy *p) : m(p) { m->lock(); }
    ~LockBlock() { m->unlock(); }
};
struct SignalBase : Policy { };
typedef std::set<SignalBase *> Senders;
template <> std::pair<Senders::_Rep_type::iterator, bool> Senders::_Rep_type::insert_unique(SignalBase *const &);
struct HasSlots : Policy {
    Senders senders;
    HasSlots() { }
    void signal_connect(SignalBase *sender) { LockBlock lock(this); senders.insert(sender); }
};
struct Dest : HasSlots { Dest(); virtual ~Dest(); void onB(void *); };
struct ConnBase { virtual ~ConnBase() = 0; virtual void a() = 0; virtual void b() = 0; virtual void c() = 0; };
struct ConnB : ConnBase {
    typedef void (Dest::*Fn)(void *);
    Dest *obj; Fn fn;
    ConnB(Dest *o, Fn f) { obj = o; fn = f; }
    virtual ~ConnB(); virtual void a(); virtual void b(); virtual void c();
};
template <class C> struct Signal : SignalBase {
    std::list<ConnBase *> slots;
    void connect(Dest *o, typename C::Fn f) {
        LockBlock lock(this);
        C *conn = new C(o, f);
        slots.push_back(conn);
        o->signal_connect(this);
    }
};
struct Dual { Signal<ConnB> a; Signal<ConnB> b; };
extern "C" Dual *w3d_local_static_801ea954();
inline Dest::Dest() { w3d_local_static_801ea954()->b.connect(this, &Dest::onB); }

struct FullTag { int w[9]; FullTag(); };
struct Iface { virtual ~Iface() = 0; };
struct Base : Iface { FullTag tag; Base() { } };
struct Obj { virtual void v0(); virtual void AddRef(); virtual void Release(); };
struct Ref {
    Obj *p;
    Ref() : p(0) { }
    Ref &operator=(Obj *q) { if (q) q->AddRef(); if (p) p->Release(); p = q; return *this; }
};
struct Klass { char u[32]; unsigned bits; };
extern Klass k_80363b54, k_80363bf4, k_80363c44;
extern "C" Klass *w3d_d26k_initialise_class_80210370(Klass *);
extern "C" Obj *w3d_r24b_invoke_ready_callback_8020fcb4(Klass *);
struct ItemA { char d[84]; ItemA(int n = k_80363bf4.bits >> 22); void *operator new[](size_t n) { return ::operator new(n); } };
struct ItemB { char d[84]; ItemB(int n = k_80363c44.bits >> 22); void *operator new[](size_t n) { return ::operator new(n); } };
template <class T> struct Pool {
    std::vector<T *> v;
    T **cur;
    int idx;
    Pool() { cur = v.begin(); idx = 0; }
    void Add(T *p) { v.push_back(p); idx = 0; cur = v.begin(); }
};
struct Row { char d[16]; Row() { } };
struct Svc { int x; Svc(); };
struct Arr3 { char *a, *b, *c; Arr3() { c = 0; b = 0; a = 0; } };
struct Arr {
    char *begin, *end, *cap;
    int flag;
    Arr() { cap = 0; end = 0; begin = 0; flag = 0; }
    Arr(const Arr &o) {
        unsigned n = o.end - o.begin;
        begin = (char *)alloc_80212fd4(n);
        cap = end = begin + n;
        memcpy_802eee50(begin, o.begin, n);
        flag = o.flag;
    }
    ~Arr() { if (begin) free_802134fc(begin); }
    void Reserve(unsigned n) {
        unsigned have = (int *)cap - (int *)begin;
        if (n > have) {
            unsigned total = cap - begin;
            int a = total + (n - have);
            int b = total + (total >> 1);
            unsigned used = end - begin;
            unsigned bytes = v_max(a, b) * 4;
            char *data = (char *)alloc_80212fd4(bytes);
            if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; cap = data + bytes;
        }
    }
};
struct Other { int x; };
extern float f_803aa0ec[];
struct Renderer : Base {
    float x40; int x44; int x48;
    Row rows[6];
    char u148[12]; int x160; int x164;
    int x168, x172; Ref r176;
    Pool<ItemA> a;
    Pool<ItemB> b;
    int x228;
    Svc svc;
    int x236;
    Arr3 a240, a252; int x264; Arr3 a268; int x280; int x284;
    std::vector<Arr> layers;
    unsigned char x304, x305; short x306;
    std::vector<Other> others;
    virtual ~Renderer();
    Renderer();
};
Renderer::Renderer() : x168(0), x172(0), layers(3)
{
    static Dest dest;
    x40 = f_803aa0ec[0];
    x48 = 0;
    x284 = 0;
    x304 = 1;
    x305 = 2;
    layers[0].flag = 2;
    layers[1].flag = 0;
    layers[2].flag = 1;
    layers[0].Reserve(64);
    layers[1].Reserve(64);
    layers[2].Reserve(64);
    w3d_d26k_initialise_class_80210370(&k_80363b54);
    w3d_d26k_initialise_class_80210370(&k_80363bf4);
    w3d_d26k_initialise_class_80210370(&k_80363c44);
    a.Add(new ItemA[512]);
    b.Add(new ItemB[32]);
    r176 = w3d_r24b_invoke_ready_callback_8020fcb4(&k_80363b54);
    x160 = 0;
}
