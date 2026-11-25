#include "w3d_ptr.h"
#line 1 "d31e_select_mode_801a92c8.cpp"
// (Worms 3D GameCube PAL, 0x801a92c8).
//
// Selects a rendering mode on an object: when the mode differs from +160,
// creates an instance of class record 0x80363b54 (mode 0) or 0x80363ba4
// (otherwise) through 0x8020fcb4 and assigns it to the reference at +176
// (add new, release old, store). Stores the mode and returns 0. Names are
// inferred.

struct Obj { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Obj2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN3Obj6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN3Obj7ReleaseEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Obj; };
struct ClassInfo;
extern ClassInfo k_80363b54[], k_80363ba4[];
extern "C" Ptr32<Obj> w3d_r24b_invoke_ready_callback_8020fcb4(Ptr32<const ClassInfo>);
struct Ref {
    Ptr32<Obj> p;
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 Ref &operator=(Obj *q) {
        if (q) q->AddRef();
        if (p) p->Release();
        p = q;
        return *this;
    }
};
struct Self { char pad[160]; int mode; char pad2[12]; Ref ref; };
extern "C" int w3d_d31e_select_mode_801a92c8(Ptr32<Self> self, int mode)
{
    if (mode != self->mode) {
        if (mode == 0) self->ref = w3d_r24b_invoke_ready_callback_8020fcb4(k_80363b54);
        else self->ref = w3d_r24b_invoke_ready_callback_8020fcb4(k_80363ba4);
    }
    self->mode = mode;
    return 0;
}


