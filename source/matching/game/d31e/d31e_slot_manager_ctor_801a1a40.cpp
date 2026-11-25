// (Worms 3D GameCube PAL, 0x801a1a40).
//
// Constructs the singleton that registers two sigslot-style connections:
// base table 0x804139e0, tagged link at +4 cleared with kind 2, final table
// 0x804139c0, stores itself in the global at 0x804ab74c, appends itself to
// the global service list, then connects the global slot holder 0x8045ce2c
// to both signals of the local static 0x801ea954 (0x803a9b84 and 0x803a9b8c
// are the member-function constants). Each connect locks the signal,
// allocates a 16-byte connection, pushes it on the signal's STLport list,
// and records the signal in the slot holder's STLport set under the holder's
// lock. Shape follows the public sigslot library; names are inferred.

#pragma interface
#include "compat/stlport_sn_oom.h"
#include <list>
#include <set>

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
    void signal_connect(SignalBase *sender) { LockBlock lock(this); senders.insert(sender); }
};
struct Dest : HasSlots { void onA(); void onB(void *); };
extern Dest gDest;
struct ConnBase { virtual ~ConnBase() = 0; virtual void a() = 0; virtual void b() = 0; virtual void c() = 0; };
struct ConnA : ConnBase {
    typedef void (Dest::*Fn)();
    Dest *obj; Fn fn;
    ConnA(Dest *o, Fn f) { obj = o; fn = f; }
    virtual ~ConnA(); virtual void a(); virtual void b(); virtual void c();
};
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
struct Dual { Signal<ConnA> a; Signal<ConnB> b; };
static inline void bindA(Signal<ConnA> &s) { s.connect(&gDest, &Dest::onA); }
static inline void bindB(Signal<ConnB> &s) { s.connect(&gDest, &Dest::onB); }
extern "C" Dual *w3d_local_static_801ea954();
struct Service;
extern "C" void w3d_cx10b_global_service_append_8021008c(Service *);

struct Iface { virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0; virtual void v4() = 0; };
struct Pair { int a, b; void clear() { a = 0; b = 0; } };
struct Link {
    short a, b;
    unsigned int pointer : 24;
    unsigned int kind : 8;
    Pair s;
    Link(unsigned char tag) { kind = tag; pointer = 0; s.clear(); a = 0; b = 0; }
};
struct Top : Iface { Link link; Top() : link(2) {} };
struct Sub { int x; int y; int z; Sub() { z = 0; y = 0; x = 0; } };
struct SessionManager : Top {
    Sub sub;
    int x32;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    SessionManager();
};
extern SessionManager *gManager;
SessionManager::SessionManager() {
    x32 = 0;
    gManager = this;
    w3d_cx10b_global_service_append_8021008c((Service *)this);
    bindA(w3d_local_static_801ea954()->a);
    bindB(w3d_local_static_801ea954()->b);
}
