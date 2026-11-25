#include "w3d_ptr.h"
#line 1 "d41x_scene_node_ctor_8015db40.cpp"
// d41x: 0x8015db40. Constructor of a scene object with a three-level class
// chain; each level installs its table and the upper two create the entry
// from descriptor 0x80412790. Names inferred. Flags: -mps-float.
#include "compat/stlport_sn_oom.h"
#include <vector>
#pragma interface
struct Entry;
struct EntryVt { char u0[12]; Ptr32<void (Ptr32<Entry>)> retain; Ptr32<void (Ptr32<Entry>)> release; };
struct Entry { Ptr32<EntryVt> vt; };
extern "C" Ptr32<Entry> forward_8020b680(Ptr32<void>);
extern unsigned char desc_80412790[];
inline Ptr32<Entry> service(Ptr32<void> d) { return forward_8020b680(d); }
struct Sub_802109dc { char u[16]; Sub_802109dc(); };
struct Link { short a, b; unsigned int kind:8; unsigned int pointer:24; Link(unsigned char t) { kind = t; pointer = 0; }
    void clear() { b = 0; } };
struct Pair { int a, b; Pair() { a = 0; b = 0; } };
struct Root { void w3d_r_n0() __asm__(W3D_SYM("_ZN4Root2n0Ev"));  __attribute__((always_inline)) inline void n0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Root, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Root;  Root() { W3D_SET_VPTR(this->w3d_vptr_Root, w3d_vt___vt_4Root, "__vt_4Root"); } };
struct Node_80411378 : Root { Link link __attribute__((aligned(__alignof__(Root)))); Pair f12; Node_80411378() : link(2) { W3D_SET_VPTR(this->Root::w3d_vptr_Root, w3d_vt___vt_13Node_80411378, "__vt_13Node_80411378");  link.a = 0; link.clear(); } void w3d_r_n0() __asm__(W3D_SYM("_ZN13Node_804113782n0Ev"));  __attribute__((always_inline)) inline void n0() { this->Root::n0(); } };
struct Mid_804112e0 : Node_80411378 {
    int f20 __attribute__((aligned(__alignof__(Node_80411378)))); _STL::vector<int> f24; int f40; int f44; unsigned b48; float f52; Ptr32<Entry> f56; int f60; int f64; int f68;
    Sub_802109dc f72; int f88; int f92; int f96; int f100; int f104; int f108; int f112;
    char u116[32]; int f148; char u152[12]; unsigned b164;
    Mid_804112e0();
    void w3d_r_n0() __asm__(W3D_SYM("_ZN12Mid_804112e02n0Ev"));
 __attribute__((always_inline)) inline void n0() { this->Node_80411378::n0(); } };
inline Mid_804112e0::Mid_804112e0() : f56(0), f60(0), f64(0), f68(0), f88(0), f92(0), f96(0), f100(0), f104(0), f108(0), f112(0), f148(0) { W3D_SET_VPTR(this->Node_80411378::w3d_vptr_Root, w3d_vt___vt_12Mid_804112e0, "__vt_12Mid_804112e0"); 
    f52 = 0.0f;
    Ptr32<Entry> e = service(desc_80412790);
    if (e) e->vt->retain(e);
    if (f56) f56->vt->release(f56);
    f40 = 0;
    f44 = 0;
    f20 = 0;
    b48 = (b48 & 0x7fffffff) | 0x40000000;
    f56 = e;
}
struct Top_80411248 : Mid_804112e0 { Top_80411248(); void w3d_r_n0() __asm__(W3D_SYM("_ZN12Top_804112482n0Ev"));  __attribute__((always_inline)) inline void n0() { this->Mid_804112e0::n0(); } };
Top_80411248::Top_80411248() { W3D_SET_VPTR(this->Mid_804112e0::w3d_vptr_Root, w3d_vt___vt_12Top_80411248, "__vt_12Top_80411248"); 
    Ptr32<Entry> e = service(desc_80412790);
    if (e) e->vt->retain(e);
    if (f56) f56->vt->release(f56);
    f56 = e;
    f52 = 0.0f;
    b164 = (b164 | 0x80000000) & 0xbfffffff;
}


