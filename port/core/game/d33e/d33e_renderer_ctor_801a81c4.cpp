#include "w3d_ptr.h"
#line 1 "d33e_renderer_ctor_801a81c4.cpp"
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
extern "C" Ptr32<void> alloc_80212fd4(unsigned);
extern "C" void free_802134fc(Ptr32<void>);
extern "C" Ptr32<void> memcpy_802eee50(Ptr32<void>, Ptr32<const void>, unsigned, ...);
inline const int &v_max(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &v_min(const unsigned &a, const unsigned &b) { return b < a ? b : a; }

struct Policy { ~Policy(); void w3d_r_lock() __asm__(W3D_SYM("_ZN6Policy4lockEv")); void w3d_r_unlock() __asm__(W3D_SYM("_ZN6Policy6unlockEv"));  __attribute__((always_inline)) inline void w3d_vdt(int w3d_in) const { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Policy, 2))(w3d::h2g(this), w3d_in); }  __attribute__((always_inline)) inline void lock() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Policy, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void unlock() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Policy, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Policy;  Policy() { W3D_SET_VPTR(this->w3d_vptr_Policy, w3d_vt___vt_6Policy, "__vt_6Policy"); } };
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
    HasSlots() { W3D_SET_VPTR(this->Policy::w3d_vptr_Policy, w3d_vt___vt_8HasSlots, "__vt_8HasSlots");  }
    void signal_connect(Ptr32<SignalBase> sender) { LockBlock lock(this); senders.insert(sender); }
};
struct Dest : HasSlots { Dest(); ~Dest(); void onB(Ptr32<void>); };
struct ConnBase { ~ConnBase() ; void w3d_r_a()  __asm__(W3D_SYM("_ZN8ConnBase1aEv")); void w3d_r_b()  __asm__(W3D_SYM("_ZN8ConnBase1bEv")); void w3d_r_c()  __asm__(W3D_SYM("_ZN8ConnBase1cEv"));  __attribute__((always_inline)) inline void w3d_vdt(int w3d_in) const { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_ConnBase, 2))(w3d::h2g(this), w3d_in); }  __attribute__((always_inline)) inline void a() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ConnBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void b() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ConnBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void c() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ConnBase, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_ConnBase;  ConnBase() { W3D_SET_VPTR(this->w3d_vptr_ConnBase, w3d_vt___vt_8ConnBase, "__vt_8ConnBase"); } };
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
struct Dual { Signal<ConnB> a; Signal<ConnB> b; };
extern "C" Ptr32<Dual> w3d_local_static_801ea954();
inline Dest::Dest() { W3D_SET_VPTR(this->HasSlots::w3d_vptr_Policy, w3d_vt___vt_4Dest, "__vt_4Dest");  w3d_local_static_801ea954()->b.connect(this, &Dest::onB); }

struct FullTag { int w[9]; FullTag(); };
struct Iface { ~Iface() ;  __attribute__((always_inline)) inline void w3d_vdt(int w3d_in) const { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this), w3d_in); }  Ptr32<void> w3d_vptr_Iface;  Iface() { W3D_SET_VPTR(this->w3d_vptr_Iface, w3d_vt___vt_5Iface, "__vt_5Iface"); } };
struct Base : Iface { FullTag tag __attribute__((aligned(__alignof__(Iface)))); Base() { W3D_SET_VPTR(this->Iface::w3d_vptr_Iface, w3d_vt___vt_4Base, "__vt_4Base");  } };
struct Obj { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Obj2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN3Obj6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN3Obj7ReleaseEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Obj; };
struct Ref {
    Ptr32<Obj> p;
    Ref() : p(0) { }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 Ref &operator=(Obj *q) { if (q) q->AddRef(); if (p) p->Release(); p = q; return *this; }
};
struct Klass { char u[32]; unsigned bits; };
extern Klass k_80363b54, k_80363bf4, k_80363c44;
extern "C" Ptr32<Klass> w3d_d26k_initialise_class_80210370(Ptr32<Klass>);
extern "C" Ptr32<Obj> w3d_r24b_invoke_ready_callback_8020fcb4(Ptr32<Klass>);
struct ItemA { char d[84]; ItemA(int n = k_80363bf4.bits >> 22); void *operator new[](__SIZE_TYPE__ n) { return ::operator new(n); } };
struct ItemB { char d[84]; ItemB(int n = k_80363c44.bits >> 22); void *operator new[](__SIZE_TYPE__ n) { return ::operator new(n); } };
template <class T> struct Pool {
    _STL::vector <Ptr32<T> > v;
    Ptr32<Ptr32<T>> cur;
    int idx;
    Pool() { cur = v.begin(); idx = 0; }
    void Add(Ptr32<T> p) { v.push_back(p); idx = 0; cur = v.begin(); }
};
struct Row { char d[16]; Row() { } };
struct Svc { int x; Svc(); };
struct Arr3 { Ptr32<char> a; Ptr32<char> b; Ptr32<char> c; Arr3() { c = 0; b = 0; a = 0; } };
struct Arr {
    Ptr32<char> begin; Ptr32<char> end; Ptr32<char> cap;
    int flag;
    Arr() { cap = 0; end = 0; begin = 0; flag = 0; }
    Arr(const Arr &o) {
        unsigned n = o.end - o.begin;
        begin = (Ptr32<char>)alloc_80212fd4(n);
        cap = end = begin + n;
        memcpy_802eee50(begin, o.begin, n);
        flag = o.flag;
    }
    ~Arr() { if (begin) free_802134fc(begin); }
    void Reserve(unsigned n) {
        unsigned have = (Ptr32<int>)cap - (Ptr32<int>)begin;
        if (n > have) {
            unsigned total = cap - begin;
            int a = total + (n - have);
            int b = total + (total >> 1);
            unsigned used = end - begin;
            unsigned bytes = v_max(a, b) * 4;
            Ptr32<char> data = (Ptr32<char>)alloc_80212fd4(bytes);
            if (begin) { memcpy_802eee50(data, begin, v_min(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; cap = data + bytes;
        }
    }
};
struct Other { int x; };
extern float f_803aa0ec[];
struct Renderer : Base {
    float x40 __attribute__((aligned(__alignof__(Base)))); int x44; int x48;
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
    ~Renderer();
    Renderer();
};
Renderer::Renderer() : x168(0), x172(0), layers(3)
{ W3D_SET_VPTR(this->Base::w3d_vptr_Iface, w3d_vt___vt_8Renderer, "__vt_8Renderer"); 
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
    a.Add(w3d::new_array<ItemA>(512));
    b.Add(w3d::new_array<ItemB>(32));
    r176 = w3d_r24b_invoke_ready_callback_8020fcb4(&k_80363b54);
    x160 = 0;
}

W3D_DT_THUNK("_ZN6PolicyD1Ev", 2, "_._6Policy");
W3D_DT_THUNK("_ZN6PolicyD2Ev", 0, "_._6Policy");
W3D_DT_THUNK("_ZN4DestD1Ev", 2, "_._4Dest");
W3D_DT_THUNK("_ZN4DestD2Ev", 0, "_._4Dest");
W3D_DT_THUNK("_ZN8ConnBaseD1Ev", 2, "_._8ConnBase");
W3D_DT_THUNK("_ZN8ConnBaseD2Ev", 0, "_._8ConnBase");
W3D_DT_THUNK("_ZN5IfaceD1Ev", 2, "_._5Iface");
W3D_DT_THUNK("_ZN5IfaceD2Ev", 0, "_._5Iface");
