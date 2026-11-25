// d41x: 0x8015db40. Constructor of a scene object with a three-level class
// chain; each level installs its table and the upper two create the entry
// from descriptor 0x80412790. Names inferred. Flags: -mps-float.
#include "compat/stlport_sn_oom.h"
#include <vector>
#pragma interface
struct Entry;
struct EntryVt { char u0[12]; void (*retain)(Entry *); void (*release)(Entry *); };
struct Entry { EntryVt *vt; };
extern "C" Entry *forward_8020b680(void *);
extern unsigned char desc_80412790[];
inline Entry *service(void *d) { return forward_8020b680(d); }
struct Sub_802109dc { char u[16]; Sub_802109dc(); };
struct Link { short a, b; unsigned pointer : 24; unsigned kind : 8; Link(unsigned char t) { kind = t; pointer = 0; }
    void clear() { b = 0; } };
struct Pair { int a, b; Pair() { a = 0; b = 0; } };
struct Root { virtual void n0(); };
struct Node_80411378 : Root { Link link; Pair f12; Node_80411378() : link(2) { link.a = 0; link.clear(); } void n0(); };
struct Mid_804112e0 : Node_80411378 {
    int f20; _STL::vector<int> f24; int f40; int f44; unsigned b48; float f52; Entry *f56; int f60; int f64; int f68;
    Sub_802109dc f72; int f88; int f92; int f96; int f100; int f104; int f108; int f112;
    char u116[32]; int f148; char u152[12]; unsigned b164;
    Mid_804112e0();
    void n0();
};
inline Mid_804112e0::Mid_804112e0() : f56(0), f60(0), f64(0), f68(0), f88(0), f92(0), f96(0), f100(0), f104(0), f108(0), f112(0), f148(0) {
    f52 = 0.0f;
    Entry *e = service(desc_80412790);
    if (e) e->vt->retain(e);
    if (f56) f56->vt->release(f56);
    f40 = 0;
    f44 = 0;
    f20 = 0;
    b48 = (b48 & 0x7fffffff) | 0x40000000;
    f56 = e;
}
struct Top_80411248 : Mid_804112e0 { Top_80411248(); void n0(); };
Top_80411248::Top_80411248() {
    Entry *e = service(desc_80412790);
    if (e) e->vt->retain(e);
    if (f56) f56->vt->release(f56);
    f56 = e;
    f52 = 0.0f;
    b164 = (b164 | 0x80000000) & 0xbfffffff;
}
