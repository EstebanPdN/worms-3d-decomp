/* Parameter owner holding a real STLport 4.5.3 list of 40-byte reference-counted items
 * (0x80165924 family). The vtables in the DOL witness the classes: 0x80411ac0 is a three-slot pure
 * interface, 0x80411a70 the item, 0x80411a88 an eleven-slot pure interface and 0x80411a30 the owner,
 * none with a destructor slot and all with a null type_info word. Without new virtuals the middle
 * class reuses its base's table. Names are inferred. */
#ifndef D31S_PARAM_ITEM_H
#define D31S_PARAM_ITEM_H
#pragma interface
#include "compat/stlport_sn_oom.h"
#include <list>
struct D31sTagBase {
    short a;
    short b;
    unsigned int kind:8; unsigned int value:24;
    D31sTagBase() { kind = 2; value = 0; }
    ~D31sTagBase();
};
struct D31sTag : D31sTagBase {
    D31sTag() { a = 0; }
};
struct D31sCounted {
    int w3d_r_query(Ptr32<const void> id, Ptr32<Ptr32<void>> out)  __asm__(W3D_SYM("_ZN11D31sCounted5queryEPKvPPv"));
    int w3d_r_retain()  __asm__(W3D_SYM("_ZN11D31sCounted6retainEv"));
    int w3d_r_release()  __asm__(W3D_SYM("_ZN11D31sCounted7releaseEv"));
 __attribute__((always_inline)) inline int query(Ptr32<const void> w3d_a0, Ptr32<Ptr32<void>> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<const void>, Ptr32<Ptr32<void>>))w3d::vfn(this->w3d_vptr_D31sCounted, 2))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline int retain() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sCounted, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int release() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sCounted, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D31sCounted;  D31sCounted() { W3D_SET_VPTR(this->w3d_vptr_D31sCounted, w3d_vt___vt_11D31sCounted, "__vt_11D31sCounted"); } };
struct D31sItemBase : D31sCounted, D31sTag { D31sItemBase() { W3D_SET_VPTR(this->D31sCounted::w3d_vptr_D31sCounted, w3d_vt___vt_12D31sItemBase, "__vt_12D31sItemBase"); } };
struct D31sItem : D31sItemBase {
    int type __attribute__((aligned(__alignof__(D31sItemBase))));
    int values[4];
    Ptr32<void> object;
    Ptr32<void> owner;
    int &value_at(int i) { Ptr32<int> p = values; return p[i]; }
    D31sItem() { W3D_SET_VPTR(this->D31sItemBase::w3d_vptr_D31sCounted, w3d_vt___vt_8D31sItem, "__vt_8D31sItem");  for (unsigned i = 0; i < 4; i++) values[i] = 0; }
    int w3d_r_query(Ptr32<const void> id, Ptr32<Ptr32<void>> out) __asm__(W3D_SYM("_ZN8D31sItem5queryEPKvPPv"));
    int w3d_r_retain() __asm__(W3D_SYM("_ZN8D31sItem6retainEv"));
    int w3d_r_release() __asm__(W3D_SYM("_ZN8D31sItem7releaseEv"));
 __attribute__((always_inline)) inline int query(Ptr32<const void> w3d_a0, Ptr32<Ptr32<void>> w3d_a1) { return this->D31sItemBase::query(w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline int retain() { return this->D31sItemBase::retain(); }  __attribute__((always_inline)) inline int release() { return this->D31sItemBase::release(); } };
struct D31sInterface { void w3d_r_iface_slot() __asm__(W3D_SYM("_ZN13D31sInterface10iface_slotEv"));  __attribute__((always_inline)) inline void iface_slot() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sInterface, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D31sInterface; };
struct D31sObject { int first_word; };
struct D31sTarget : D31sObject, D31sInterface {};
struct D31sBinder {
    void w3d_r_s0() __asm__(W3D_SYM("_ZN10D31sBinder2s0Ev")); void w3d_r_s1() __asm__(W3D_SYM("_ZN10D31sBinder2s1Ev")); void w3d_r_s2() __asm__(W3D_SYM("_ZN10D31sBinder2s2Ev")); void w3d_r_s3() __asm__(W3D_SYM("_ZN10D31sBinder2s3Ev")); void w3d_r_s4() __asm__(W3D_SYM("_ZN10D31sBinder2s4Ev"));
    void w3d_r_s5() __asm__(W3D_SYM("_ZN10D31sBinder2s5Ev")); void w3d_r_s6() __asm__(W3D_SYM("_ZN10D31sBinder2s6Ev")); void w3d_r_s7() __asm__(W3D_SYM("_ZN10D31sBinder2s7Ev")); void w3d_r_s8() __asm__(W3D_SYM("_ZN10D31sBinder2s8Ev")); void w3d_r_s9() __asm__(W3D_SYM("_ZN10D31sBinder2s9Ev"));
    void w3d_r_bind(Ptr32<D31sInterface> target, Ptr32<D31sItem> item) __asm__(W3D_SYM("_ZN10D31sBinder4bindEP13D31sInterfaceP8D31sItem"));
    Ptr32<D31sItem> w3d_r_find(Ptr32<D31sInterface> target) __asm__(W3D_SYM("_ZN10D31sBinder4findEP13D31sInterface"));
 __attribute__((always_inline)) inline void s0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sBinder, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sBinder, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sBinder, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sBinder, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sBinder, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sBinder, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sBinder, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sBinder, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sBinder, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D31sBinder, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void bind(Ptr32<D31sInterface> w3d_a0, Ptr32<D31sItem> w3d_a1) { ((void (*)(w3d_u32, Ptr32<D31sInterface>, Ptr32<D31sItem>))w3d::vfn(this->w3d_vptr_D31sBinder, 12))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline Ptr32<D31sItem> find(Ptr32<D31sInterface> w3d_a0) { return ((Ptr32<D31sItem> (*)(w3d_u32, Ptr32<D31sInterface>))w3d::vfn(this->w3d_vptr_D31sBinder, 13))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_D31sBinder; };
#endif
