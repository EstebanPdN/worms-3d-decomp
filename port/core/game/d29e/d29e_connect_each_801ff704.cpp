#include "w3d_ptr.h"
#line 1 "d29e_connect_each_801ff704.cpp"
// (Worms 3D GameCube PAL, 0x801ff704).
//
// Queries each of n interface references for the interface id at 0x8040c970
// and passes the result to the target's virtual slot 6 with arg, releasing
// it after each call; stops and returns the first negative result, otherwise
// returns 0. Names are inferred.

struct Iface {
    int w3d_r_query(Ptr32<const void> iid, Ptr32<void> out) __asm__(W3D_SYM("_ZN5Iface5queryEPKvPv"));
    void w3d_r_v1() __asm__(W3D_SYM("_ZN5Iface2v1Ev"));
    void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));
 __attribute__((always_inline)) inline int query(Ptr32<const void> w3d_a0, Ptr32<void> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<const void>, Ptr32<void>))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
struct Target {
    void w3d_r_v0() __asm__(W3D_SYM("_ZN6Target2v0Ev"));
    void w3d_r_v1() __asm__(W3D_SYM("_ZN6Target2v1Ev"));
    void w3d_r_v2() __asm__(W3D_SYM("_ZN6Target2v2Ev"));
    void w3d_r_v3() __asm__(W3D_SYM("_ZN6Target2v3Ev"));
    void w3d_r_v4() __asm__(W3D_SYM("_ZN6Target2v4Ev"));
    void w3d_r_v5() __asm__(W3D_SYM("_ZN6Target2v5Ev"));
    int w3d_r_connect(Ptr32<Iface>, int) __asm__(W3D_SYM("_ZN6Target7connectEP5Ifacei"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int connect(Ptr32<Iface> w3d_a0, int w3d_a1) { return ((int (*)(w3d_u32, Ptr32<Iface>, int))w3d::vfn(this->w3d_vptr_Target, 8))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_Target; };
extern char lbl_8040c970[];
struct Ref {
    Ptr32<Iface> p;
    Ref() {}
    Ref(const Ref &);
    void clear() { if (p) p->release(); }
};
extern "C" int w3d_d29e_connect_each_801ff704(Ptr32<void> self, Ptr32<Target> target, Ptr32<Ref> list, int arg, unsigned n)
{
    Ptr32<Ref> src = list;
    Ref r;
    unsigned i = 0;
    if (i < n) {
        Ptr32<Ref> out = &r;
        do {
            r.p = 0;
            Ptr32<Iface> q = src->p;
            if (q) q->query(lbl_8040c970, out);
            else r.p = q;
            int hr = target->connect(r.p, arg);
            if (hr < 0) {
                r.clear();
                return hr;
            }
            src++;
            r.clear();
            i++;
        } while (i < n);
    }
    return 0;
}


