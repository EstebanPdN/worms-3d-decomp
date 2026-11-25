#include "w3d_ptr.h"
#line 1 "d31e_render_state_ctor_801b0d38.cpp"
// (Worms 3D GameCube PAL, 0x801b0d38).
//
// Constructs a render state holder: base table 0x804136c0 with tag at +4,
// final table 0x80414220. Takes the shared state store through 0x8020b648
// slot 21 (class record 0x804143e0), creates a rasterizer state (values 6
// and 7), a material-like state at +60 (1, 0.5, 4) and a depth state at +52
// (0), each deduplicated through the store's share slot, and a further
// service object at +56. Names are inferred.

#pragma interface
struct Tag { char u[4]; unsigned char flags; char w3d_tag_rest[3]; int w[3]; void Mark() { flags |= 2; } };
struct FullTag { int w[9]; FullTag(); };
struct ObjV { void w3d_r_v0() __asm__(W3D_SYM("_ZN4ObjV2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN4ObjV6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN4ObjV7ReleaseEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjV, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjV, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjV, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_ObjV; };
struct Obj : ObjV {
    Tag tag __attribute__((aligned(__alignof__(ObjV))));
    int a;
    int b;
    int c;
    void SetA(int v) { a = v; tag.Mark(); }
    void SetB(int v) { b = v; tag.Mark(); }
    void SetC(int v) { c = v; tag.Mark(); }
    void SetAf(float v) { *(Ptr32<float>)&a = v; tag.Mark(); }
};
struct Ref {
    Ptr32<Obj> p;
    Ref() : p(0) { }
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Obj *)w3d_p.get()) {}
 Ref(Obj *o) { p = o; if (p) p->AddRef(); }
    Ref(const Ref &);
    ~Ref() { if (p) p->Release(); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 Ref &operator=(Obj *q) {
        if (q) q->AddRef();
        if (p) p->Release();
        p = q;
        return *this;
    }
    Ptr32<Obj> operator->() const { return p; }
};
struct Store {
    void w3d_r_a0() __asm__(W3D_SYM("_ZN5Store2a0Ev")),w3d_r_a1() __asm__(W3D_SYM("_ZN5Store2a1Ev")),w3d_r_a2() __asm__(W3D_SYM("_ZN5Store2a2Ev")),w3d_r_a3() __asm__(W3D_SYM("_ZN5Store2a3Ev")),w3d_r_a4() __asm__(W3D_SYM("_ZN5Store2a4Ev")),w3d_r_a5() __asm__(W3D_SYM("_ZN5Store2a5Ev")),w3d_r_a6() __asm__(W3D_SYM("_ZN5Store2a6Ev")),w3d_r_a7() __asm__(W3D_SYM("_ZN5Store2a7Ev")),w3d_r_a8() __asm__(W3D_SYM("_ZN5Store2a8Ev"));
    Ptr32<Obj> w3d_r_Share(Ptr32<Obj>) __asm__(W3D_SYM("_ZN5Store5ShareEP3Obj"));
    void w3d_r_b0() __asm__(W3D_SYM("_ZN5Store2b0Ev")),w3d_r_b1() __asm__(W3D_SYM("_ZN5Store2b1Ev")),w3d_r_b2() __asm__(W3D_SYM("_ZN5Store2b2Ev")),w3d_r_b3() __asm__(W3D_SYM("_ZN5Store2b3Ev")),w3d_r_b4() __asm__(W3D_SYM("_ZN5Store2b4Ev")),w3d_r_b5() __asm__(W3D_SYM("_ZN5Store2b5Ev")),w3d_r_b6() __asm__(W3D_SYM("_ZN5Store2b6Ev")),w3d_r_b7() __asm__(W3D_SYM("_ZN5Store2b7Ev")),w3d_r_b8() __asm__(W3D_SYM("_ZN5Store2b8Ev")),w3d_r_b9() __asm__(W3D_SYM("_ZN5Store2b9Ev")),w3d_r_b10() __asm__(W3D_SYM("_ZN5Store3b10Ev"));
    Ptr32<Store> w3d_r_Get(Ptr32<void>) __asm__(W3D_SYM("_ZN5Store3GetEPv"));
 __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Obj> Share(Ptr32<Obj> w3d_a0) { return ((Ptr32<Obj> (*)(w3d_u32, Ptr32<Obj>))w3d::vfn(this->w3d_vptr_Store, 11))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void b0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void b1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void b2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void b3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void b4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void b5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void b6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void b7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void b8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void b9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void b10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Store, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Store> Get(Ptr32<void> w3d_a0) { return ((Ptr32<Store> (*)(w3d_u32, Ptr32<void>))w3d::vfn(this->w3d_vptr_Store, 23))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Store; };
struct StoreObj : ObjV { };
struct StoreRef {
    Ptr32<Store> p;
    template <class W3dU> StoreRef(Ptr32<W3dU> w3d_p) : StoreRef((Store *)w3d_p.get()) {}
 StoreRef(Store *o) { p = o; if (p) ((Ptr32<ObjV>)p)->AddRef(); }
    StoreRef(const StoreRef &);
    ~StoreRef() { if (p) ((Ptr32<ObjV>)p)->Release(); }
};
struct ClassRecord;
extern ClassRecord k_804143e0[], k_80415cb0[], k_80415bb0[], k_80415c00[], k_804166b0[];
extern float f_803aa838[];
extern "C" Ptr32<Store> w3d_auto_8020b648();
extern "C" Ptr32<Obj> w3d_s10_service_forward_8020b680(Ptr32<ClassRecord>);
struct Iface { void w3d_r_x0()  __asm__(W3D_SYM("_ZN5Iface2x0Ev"));  __attribute__((always_inline)) inline void x0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface;  Iface() { W3D_SET_VPTR(this->w3d_vptr_Iface, w3d_vt___vt_5Iface, "__vt_5Iface"); } };
struct Base : Iface { FullTag tag __attribute__((aligned(__alignof__(Iface)))); Base() { W3D_SET_VPTR(this->Iface::w3d_vptr_Iface, w3d_vt___vt_4Base, "__vt_4Base");  } };
struct Render : Base {
    int x40 __attribute__((aligned(__alignof__(Base))));
    int x44;
    Ref rs;
    Ref ds;
    Ref bs;
    Ref ms;
    void w3d_r_x0() __asm__(W3D_SYM("_ZN6Render2x0Ev"));
    Render();
 __attribute__((always_inline)) inline void x0() { this->Base::x0(); } };
Render::Render() : x40(0)
{ W3D_SET_VPTR(this->Base::w3d_vptr_Iface, w3d_vt___vt_6Render, "__vt_6Render"); 
    Ptr32<ClassRecord> k = k_804143e0;
    StoreRef store(w3d_auto_8020b648()->Get(k));
    rs = w3d_s10_service_forward_8020b680(k_80415cb0);
    rs->SetB(6);
    rs->SetA(7);
    rs = store.p->Share(rs.p);
    ms = w3d_s10_service_forward_8020b680(k_80415bb0);
    ms->SetC(1);
    ms->SetAf(0.5f);
    ms->SetB(4);
    ms = store.p->Share(ms.p);
    ds = w3d_s10_service_forward_8020b680(k_80415c00);
    ds->SetA(0);
    ds = store.p->Share(ds.p);
    bs = w3d_s10_service_forward_8020b680(k_804166b0);
}


