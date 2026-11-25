#include "w3d_ptr.h"
#line 1 "d31e_slot_manager_ctor_801a1a40.cpp"
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

struct Policy { ~Policy(); void w3d_r_lock() __asm__(W3D_SYM("_ZN6Policy4lockEv")); void w3d_r_unlock() __asm__(W3D_SYM("_ZN6Policy6unlockEv"));  __attribute__((always_inline)) inline void w3d_vdt(int w3d_in) const { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Policy, 2))(w3d::h2g(this), w3d_in); }  __attribute__((always_inline)) inline void lock() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Policy, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void unlock() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Policy, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Policy; };
struct LockBlock {
    Ptr32<Policy> m;
    template <class W3dU> LockBlock(Ptr32<W3dU> w3d_p) : LockBlock((Policy *)w3d_p.get()) {}
 LockBlock(Policy *p) : m(p) { m->lock(); }
    ~LockBlock() { m->unlock(); }
};
struct SignalBase : Policy { };
typedef _STL::set <Ptr32<SignalBase> > Senders;
template <> std::pair<Senders::_Rep_type::iterator, bool> Senders::_Rep_type::insert_unique(Ptr32<SignalBase> const &);
struct HasSlots : Policy {
    Senders senders __attribute__((aligned(__alignof__(Policy))));
    void signal_connect(Ptr32<SignalBase> sender) { LockBlock lock(this); senders.insert(sender); }
};
struct Dest : HasSlots { void onA(); void onB(Ptr32<void>); };
extern Dest gDest;
struct ConnBase { ~ConnBase() ; void w3d_r_a()  __asm__(W3D_SYM("_ZN8ConnBase1aEv")); void w3d_r_b()  __asm__(W3D_SYM("_ZN8ConnBase1bEv")); void w3d_r_c()  __asm__(W3D_SYM("_ZN8ConnBase1cEv"));  __attribute__((always_inline)) inline void w3d_vdt(int w3d_in) const { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_ConnBase, 2))(w3d::h2g(this), w3d_in); }  __attribute__((always_inline)) inline void a() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ConnBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void b() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ConnBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void c() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ConnBase, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_ConnBase;  ConnBase() { W3D_SET_VPTR(this->w3d_vptr_ConnBase, w3d_vt___vt_8ConnBase, "__vt_8ConnBase"); } };
struct ConnA : ConnBase {
    typedef w3d::Pmf<Dest, void()> Fn;
    Ptr32<Dest> obj __attribute__((aligned(__alignof__(ConnBase)))); Fn fn;
    ConnA(Ptr32<Dest> o, Fn f) { W3D_SET_VPTR(this->ConnBase::w3d_vptr_ConnBase, w3d_vt___vt_5ConnA, "__vt_5ConnA");  obj = o; fn = f; }
    ~ConnA(); void w3d_r_a() __asm__(W3D_SYM("_ZN5ConnA1aEv")); void w3d_r_b() __asm__(W3D_SYM("_ZN5ConnA1bEv")); void w3d_r_c() __asm__(W3D_SYM("_ZN5ConnA1cEv"));
 __attribute__((always_inline)) inline void a() { this->ConnBase::a(); }  __attribute__((always_inline)) inline void b() { this->ConnBase::b(); }  __attribute__((always_inline)) inline void c() { this->ConnBase::c(); } };
struct ConnB : ConnBase {
    typedef w3d::Pmf<Dest, void(Ptr32<void>)> Fn;
    Ptr32<Dest> obj __attribute__((aligned(__alignof__(ConnBase)))); Fn fn;
    ConnB(Ptr32<Dest> o, Fn f) { W3D_SET_VPTR(this->ConnBase::w3d_vptr_ConnBase, w3d_vt___vt_5ConnB, "__vt_5ConnB");  obj = o; fn = f; }
    ~ConnB(); void w3d_r_a() __asm__(W3D_SYM("_ZN5ConnB1aEv")); void w3d_r_b() __asm__(W3D_SYM("_ZN5ConnB1bEv")); void w3d_r_c() __asm__(W3D_SYM("_ZN5ConnB1cEv"));
 __attribute__((always_inline)) inline void a() { this->ConnBase::a(); }  __attribute__((always_inline)) inline void b() { this->ConnBase::b(); }  __attribute__((always_inline)) inline void c() { this->ConnBase::c(); } };
template <class C> struct Signal : SignalBase {
    _STL::list <Ptr32<ConnBase> > slots;
    void connect(Ptr32<Dest> o, typename C::Fn f) {
        LockBlock lock(this);
        Ptr32<C> conn = new C(o, f);
        slots.push_back(conn);
        o->signal_connect(this);
    }
};
struct Dual { Signal<ConnA> a; Signal<ConnB> b; };
static inline void bindA(Signal<ConnA> &s) { s.connect(&gDest, &Dest::onA); }
static inline void bindB(Signal<ConnB> &s) { s.connect(&gDest, &Dest::onB); }
extern "C" Ptr32<Dual> w3d_local_static_801ea954();
struct Service;
extern "C" void w3d_cx10b_global_service_append_8021008c(Ptr32<Service>);

struct Iface { void w3d_r_v0()  __asm__(W3D_SYM("_ZN5Iface2v0Ev")); void w3d_r_v1()  __asm__(W3D_SYM("_ZN5Iface2v1Ev")); void w3d_r_v2()  __asm__(W3D_SYM("_ZN5Iface2v2Ev")); void w3d_r_v3()  __asm__(W3D_SYM("_ZN5Iface2v3Ev")); void w3d_r_v4()  __asm__(W3D_SYM("_ZN5Iface2v4Ev"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface;  Iface() { W3D_SET_VPTR(this->w3d_vptr_Iface, w3d_vt___vt_5Iface, "__vt_5Iface"); } };
struct Pair { int a, b; void clear() { a = 0; b = 0; } };
struct Link {
    short a, b;
    unsigned int kind:8; unsigned int pointer:24;
    Pair s;
    Link(unsigned char tag) { kind = tag; pointer = 0; s.clear(); a = 0; b = 0; }
};
struct Top : Iface { Link link __attribute__((aligned(__alignof__(Iface)))); Top() : link(2) { W3D_SET_VPTR(this->Iface::w3d_vptr_Iface, w3d_vt___vt_3Top, "__vt_3Top"); } };
struct Sub { int x; int y; int z; Sub() { z = 0; y = 0; x = 0; } };
struct SessionManager : Top {
    Sub sub __attribute__((aligned(__alignof__(Top))));
    int x32;
    void w3d_r_v0() __asm__(W3D_SYM("_ZN14SessionManager2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN14SessionManager2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN14SessionManager2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN14SessionManager2v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN14SessionManager2v4Ev"));
    SessionManager();
 __attribute__((always_inline)) inline void v0() { this->Top::v0(); }  __attribute__((always_inline)) inline void v1() { this->Top::v1(); }  __attribute__((always_inline)) inline void v2() { this->Top::v2(); }  __attribute__((always_inline)) inline void v3() { this->Top::v3(); }  __attribute__((always_inline)) inline void v4() { this->Top::v4(); } };
extern Ptr32<SessionManager> gManager;
SessionManager::SessionManager() { W3D_SET_VPTR(this->Top::w3d_vptr_Iface, w3d_vt___vt_14SessionManager, "__vt_14SessionManager"); 
    x32 = 0;
    gManager = this;
    w3d_cx10b_global_service_append_8021008c((Ptr32<Service>)this);
    bindA(w3d_local_static_801ea954()->a);
    bindB(w3d_local_static_801ea954()->b);
}

W3D_DT_THUNK("_ZN8ConnBaseD1Ev", 2, "_._8ConnBase");
W3D_DT_THUNK("_ZN8ConnBaseD2Ev", 0, "_._8ConnBase");
