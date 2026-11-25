/* The owner of the 0x80165924 family; see d31s_param_item.h. */
#ifndef D31S_PARAM_OWNER_H
#define D31S_PARAM_OWNER_H
#include "d31s_param_item.h"
struct D31sPair { int first; int second; D31sPair() { first = 0; second = 0; } };
struct D31sFullTag : D31sTagBase {
    D31sPair pair __attribute__((aligned(__alignof__(D31sTagBase))));
    D31sFullTag() { a = 0; b = 0; }
};
struct D31sOwnerRoot {
    int w3d_r_query(Ptr32<const void> id, Ptr32<Ptr32<void>> out)  __asm__(W3D_SYM("_ZN13D31sOwnerRoot5queryEPKvPPv"));
    int w3d_r_retain()  __asm__(W3D_SYM("_ZN13D31sOwnerRoot6retainEv"));
    int w3d_r_release()  __asm__(W3D_SYM("_ZN13D31sOwnerRoot7releaseEv"));
    int w3d_r_set_scalar(Ptr32<D31sTarget> target, int v)  __asm__(W3D_SYM("_ZN13D31sOwnerRoot10set_scalarEP10D31sTargeti"));
    int w3d_r_remove_a(Ptr32<D31sTarget> target)  __asm__(W3D_SYM("_ZN13D31sOwnerRoot8remove_aEP10D31sTarget"));
    int w3d_r_set_float(Ptr32<D31sTarget> target, int v)  __asm__(W3D_SYM("_ZN13D31sOwnerRoot9set_floatEP10D31sTargeti"));
    int w3d_r_remove_b(Ptr32<D31sTarget> target)  __asm__(W3D_SYM("_ZN13D31sOwnerRoot8remove_bEP10D31sTarget"));
    int w3d_r_set_element(Ptr32<D31sTarget> target, int v, int index)  __asm__(W3D_SYM("_ZN13D31sOwnerRoot11set_elementEP10D31sTargetii"));
    int w3d_r_remove_c(Ptr32<D31sTarget> target)  __asm__(W3D_SYM("_ZN13D31sOwnerRoot8remove_cEP10D31sTarget"));
    int w3d_r_drain()  __asm__(W3D_SYM("_ZN13D31sOwnerRoot5drainEv"));
    int w3d_r_lookup()  __asm__(W3D_SYM("_ZN13D31sOwnerRoot6lookupEv"));
 __attribute__((always_inline)) inline int query(Ptr32<const void> w3d_a0, Ptr32<Ptr32<void>> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<const void>, Ptr32<Ptr32<void>>))w3d::vfn(this->w3d_vptr_D31sOwnerRoot, 2))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline int retain() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sOwnerRoot, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int release() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sOwnerRoot, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int set_scalar(Ptr32<D31sTarget> w3d_a0, int w3d_a1) { return ((int (*)(w3d_u32, Ptr32<D31sTarget>, int))w3d::vfn(this->w3d_vptr_D31sOwnerRoot, 5))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline int remove_a(Ptr32<D31sTarget> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<D31sTarget>))w3d::vfn(this->w3d_vptr_D31sOwnerRoot, 6))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline int set_float(Ptr32<D31sTarget> w3d_a0, int w3d_a1) { return ((int (*)(w3d_u32, Ptr32<D31sTarget>, int))w3d::vfn(this->w3d_vptr_D31sOwnerRoot, 7))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline int remove_b(Ptr32<D31sTarget> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<D31sTarget>))w3d::vfn(this->w3d_vptr_D31sOwnerRoot, 8))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline int set_element(Ptr32<D31sTarget> w3d_a0, int w3d_a1, int w3d_a2) { return ((int (*)(w3d_u32, Ptr32<D31sTarget>, int, int))w3d::vfn(this->w3d_vptr_D31sOwnerRoot, 9))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); }  __attribute__((always_inline)) inline int remove_c(Ptr32<D31sTarget> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<D31sTarget>))w3d::vfn(this->w3d_vptr_D31sOwnerRoot, 10))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline int drain() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sOwnerRoot, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int lookup() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sOwnerRoot, 12))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D31sOwnerRoot; };
struct D31sOwnerApi : D31sOwnerRoot, D31sFullTag {};
struct D31sOwner : D31sOwnerApi {
    Ptr32<D31sBinder> binder __attribute__((aligned(__alignof__(D31sOwnerApi))));
    _STL::list<D31sItem> items;
    D31sOwner();
    int w3d_r_query(Ptr32<const void> id, Ptr32<Ptr32<void>> out) __asm__(W3D_SYM("_ZN9D31sOwner5queryEPKvPPv"));
    int w3d_r_retain() __asm__(W3D_SYM("_ZN9D31sOwner6retainEv"));
    int w3d_r_release() __asm__(W3D_SYM("_ZN9D31sOwner7releaseEv"));
    int w3d_r_set_scalar(Ptr32<D31sTarget> target, int v) __asm__(W3D_SYM("_ZN9D31sOwner10set_scalarEP10D31sTargeti"));
    int w3d_r_remove_a(Ptr32<D31sTarget> target) __asm__(W3D_SYM("_ZN9D31sOwner8remove_aEP10D31sTarget"));
    int w3d_r_set_float(Ptr32<D31sTarget> target, int v) __asm__(W3D_SYM("_ZN9D31sOwner9set_floatEP10D31sTargeti"));
    int w3d_r_remove_b(Ptr32<D31sTarget> target) __asm__(W3D_SYM("_ZN9D31sOwner8remove_bEP10D31sTarget"));
    int w3d_r_set_element(Ptr32<D31sTarget> target, int v, int index) __asm__(W3D_SYM("_ZN9D31sOwner11set_elementEP10D31sTargetii"));
    int w3d_r_remove_c(Ptr32<D31sTarget> target) __asm__(W3D_SYM("_ZN9D31sOwner8remove_cEP10D31sTarget"));
    int w3d_r_drain() __asm__(W3D_SYM("_ZN9D31sOwner5drainEv"));
    int w3d_r_lookup() __asm__(W3D_SYM("_ZN9D31sOwner6lookupEv"));
 __attribute__((always_inline)) inline int query(Ptr32<const void> w3d_a0, Ptr32<Ptr32<void>> w3d_a1) { return this->D31sOwnerApi::query(w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline int retain() { return this->D31sOwnerApi::retain(); }  __attribute__((always_inline)) inline int release() { return this->D31sOwnerApi::release(); }  __attribute__((always_inline)) inline int set_scalar(Ptr32<D31sTarget> w3d_a0, int w3d_a1) { return this->D31sOwnerApi::set_scalar(w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline int remove_a(Ptr32<D31sTarget> w3d_a0) { return this->D31sOwnerApi::remove_a(w3d_a0); }  __attribute__((always_inline)) inline int set_float(Ptr32<D31sTarget> w3d_a0, int w3d_a1) { return this->D31sOwnerApi::set_float(w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline int remove_b(Ptr32<D31sTarget> w3d_a0) { return this->D31sOwnerApi::remove_b(w3d_a0); }  __attribute__((always_inline)) inline int set_element(Ptr32<D31sTarget> w3d_a0, int w3d_a1, int w3d_a2) { return this->D31sOwnerApi::set_element(w3d_a0, w3d_a1, w3d_a2); }  __attribute__((always_inline)) inline int remove_c(Ptr32<D31sTarget> w3d_a0) { return this->D31sOwnerApi::remove_c(w3d_a0); }  __attribute__((always_inline)) inline int drain() { return this->D31sOwnerApi::drain(); }  __attribute__((always_inline)) inline int lookup() { return this->D31sOwnerApi::lookup(); } };
#endif
